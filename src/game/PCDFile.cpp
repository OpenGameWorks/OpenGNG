// FLAGS: -str readonly
#include "types.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
extern "C" int printf(const char *fmt, ...);
extern "C" int sceCdSync(int mode);
extern "C" void __dl__FPv(void *pMem);
extern "C" int sceCdGetError();
extern "C" int sceCdStatus(int *pStatus);
extern "C" int sceCdRead(unsigned int lsn, unsigned int sectors, void *buf, void *mode);
extern "C" int sceCdSearchFile(void *, const char *);
extern "C" int sprintf(char *buf, const char *fmt, ...);
extern "C" void memcpy(void *, const void *, unsigned int);
void CdsAssert(char *pFile, int nLine, char *pExpr);

// Byte-offset access to the parts of the file object that have no member yet.
#define PCD_U32(off) (*(unsigned int *)((char *)this + (off)))
#define PCD_PTR(off) (*(char **)((char *)this + (off)))
#define CDS_ASSERT(line, cond, expr) ((cond) ? (void)0 : CdsAssert("PCDFile.cpp", line, expr))

class Interface {
public:
    void LoadingDisplay(unsigned int arg0, int arg1);

private:
    char _pad[0x10];
};
extern Interface gInterface;

class FileUtils {
public:
    static void LoadingHangCheckInit();
};

// FUNCTION: 0x0012BE90 GetSize__7PCDFileFv
int PCDFile::GetSize() {
    if (m_size == 0) {
        printf("Read failed, no file open\n");
        return 0;
    }
    printf("Size = %u\n", m_size);
    return m_size;
}

// DRAFT: 0x0012BF00 ErrorCheck__7PCDFileFv
// note: 81 words differ; early-return if-chain is best (switch with breaks 82, shared return 1 chain 82); shared epilogue and hoisted lui of 0x250000 status arg unresolved.
int PCDFile::ErrorCheck() {
    int err = sceCdGetError();
    int status;

    if (err == 0x12) {
        printf("No Disk\n");
        m_unk10054 = 4;
        return 1;
    }
    if (err == 0x11 || err == 0x31) {
        printf("Tray Open\n");
        m_unk10054 = 3;
        return 1;
    }
    if (err == 0x30) {
        printf("Read Error\n");
        m_unk10054 = 2;
        return 1;
    }
    if (err == 0x13) {
        return 0;
    }
    if (err == 0) {
        status = sceCdStatus((int *)0x250000);
        if (status == 0) {
            m_unk10054 = 4;
            return 1;
        }
        if (status == 0x20) {
            m_unk10054 = 2;
            return 1;
        }
        if (status == 1) {
            m_unk10054 = 3;
            return 1;
        }
        m_unk10054 = 0;
        return 0;
    }
    printf("Read error 0x%x\n", err);
    m_unk10054 = 2;
    return 1;
}

// FUNCTION: 0x0012C060 ReadData__7PCDFileFi
int PCDFile::ReadData(int arg0) {
    bool flag;

    m_unk10054 = 0;
    do {
        flag = false;
        while (sceCdRead(*(unsigned int *)((char *)this + 0x10040 + arg0 * 4),
                         *(unsigned int *)((char *)this + 0x10048 + arg0 * 4),
                         *(void **)((char *)this + 0x10024 + arg0 * 4),
                         &m_unk1002C) != 1) {
            if (!flag) {
                printf("The precache operation failed %d\n", arg0);
                flag = true;
            }
            ErrorCheck();
            gInterface.LoadingDisplay(m_unk10050++, m_unk10054);
        }
        if (sceCdSync(1) != 0) {
            do {
                gInterface.LoadingDisplay(m_unk10050++, m_unk10054);
            } while (sceCdSync(1) != 0);
        }
    } while (ErrorCheck() != 0);
    return 1;
}

// DRAFT: 0x0012C1C0 ReadEx__7PCDFileFPvUi
// note: 371 words differ; ours has a 0xA0 frame with s0-s7 and fp, original 0x60 with s0-s4 and ra (code 0x490 vs 0x5E4). Tried unsigned sector count, block-scoped count, dropping dst, clamp 0x11: 371, 371, 372, 371.
int PCDFile::ReadEx(void *buf, unsigned int size) {
    unsigned int done;
    unsigned int n;
    unsigned int s0;
    int idx;
    char *dst;

    CDS_ASSERT(0xB2, m_size, "CDFileDescriptor.size");
    if (m_unk10038 >= m_size) {
        printf("Read %s failed, no data left\n", (char *)this + 0x10008);
        return 0;
    }
    idx = m_unk10030;
    if (PCD_U32(0x10048 + idx * 4) == 0) {
        CDS_ASSERT(0xCC, idx == 0, "nCurrentBuffer == 0");
        s0 = ((m_size - m_unk10038) + 0x7FF) >> 11;
        PCD_U32(0x10048 + idx * 4) = (s0 < 0x10) ? s0 : 0x10;
        if (s0 >= 0x21) {
            s0 = 0x20;
        }
        PCD_U32(0x10040 + idx * 4) = PCD_U32(0x10000) + m_unk1003C;
        if (sceCdSync(1) != 0) {
            do {
                gInterface.LoadingDisplay(m_unk10050++, m_unk10054);
            } while (sceCdSync(1) != 0);
        }
        ReadData(idx);
        m_unk1003C += PCD_U32(0x10048 + idx * 4);
        PCD_U32(0x10040 + (1 - idx) * 4) = PCD_U32(0x10000) + m_unk1003C;
        PCD_U32(0x10048 + (1 - idx) * 4) = s0 - PCD_U32(0x10048 + idx * 4);
        CDS_ASSERT(0xF2, PCD_U32(0x10048 + (1 - idx) * 4) <= PCD_U32(0x10048 + idx * 4), "nNumberOfSectors[1 - nCurrentBuffer] <= nNumberOfSectors[nCurrentBuffer]");
        if (PCD_U32(0x10048 + (1 - idx) * 4) != 0) {
            ReadData(1 - idx);
            m_unk1003C += PCD_U32(0x10048 + (1 - idx) * 4);
        }
    }
    if ((unsigned int)(m_size - m_unk10038) < size) {
        size = m_size - m_unk10038;
    }
    if (size == 0) {
        return 0;
    }
    dst = (char *)buf;
    done = 0;
    do {
        n = 0x8000 - m_unk10034;
        if (size - done < n) {
            n = size - done;
        }
        memcpy(dst, PCD_PTR(0x10024 + idx * 4) + m_unk10034, n);
        done += n;
        m_unk10038 += n;
        m_unk10034 += n;
        dst += n;
        if (m_unk10034 >= 0x8000) {
            PCD_U32(0x10048 + idx * 4) = ((m_size + 0x7FF) >> 11) - m_unk1003C;
            PCD_U32(0x10040 + idx * 4) = PCD_U32(0x10000) + m_unk1003C;
            if (PCD_U32(0x10048 + idx * 4) != 0) {
                if (PCD_U32(0x10048 + idx * 4) >= 0x11) {
                    PCD_U32(0x10048 + idx * 4) = 0x10;
                }
                ReadData(idx);
                m_unk1003C += PCD_U32(0x10048 + idx * 4);
            }
            idx = 1 - idx;
            m_unk10034 = 0;
        }
    } while (done < size);
    return done;
}

// FUNCTION: 0x0012C7B0 Read__7PCDFileFPvUi
int PCDFile::Read(void *buf, unsigned int size) {
    int r;

    FileUtils::LoadingHangCheckInit();
    r = ReadEx(buf, size);
    if (r != size) {
        do {
            r = ReadEx(buf, size);
            if (r == 0) {
                return 0;
            }
        } while (r != size);
    }
    return r;
}

// FUNCTION: 0x0012C830 Close__7PCDFileFv
int PCDFile::Close() {
    if (m_size == 0) {
        return 1;
    }
    for (;;) {
        if (sceCdSync(1) == 0) {
            break;
        }
        gInterface.LoadingDisplay(m_unk10050++, m_unk10054);
    }
    m_size = 0;
    return 1;
}

// DRAFT: 0x0012C8D0 OpenEx__7PCDFileFPCc
// note: 8 words differ; branch at 0xB8 is bne (orig beq) and lui is hoisted above the store. Tried else-form (37), single return (37), early return (33).
int PCDFile::OpenEx(const char *arg0) {
    if (sceCdSync(1) != 0) {
        do {
            gInterface.LoadingDisplay(m_unk10050++, m_unk10054);
        } while (sceCdSync(1) != 0);
    }
    if (sceCdSearchFile((char *)this + 0x10000, arg0) != 1) {
        printf("Cannot open %s\n", arg0);
        ErrorCheck();
        if (m_unk10054 == 2) {
            m_unk10054 = 1;
            return 0;
        }
        return 0;
    }
    m_unk10054 = 0;
    m_unk1003C = 0;
    m_unk10034 = 0;
    m_unk10038 = 0;
    m_unk10030 = 0;
    m_unk10048 = 0;
    m_unk1004C = 0;
    return 1;
}

// DRAFT: 0x0012CA20 Open__7PCDFileFPCc9OPEN_TYPE
// note: 68 words differ; from the first m_size test on, the original materializes the condition with sltu/xori and the arg setup differs; if-else form tried (68).
int PCDFile::Open(const char *arg0, OPEN_TYPE type) {
    char buf[0x100];

    if (m_size != 0) {
        printf("File %s not closed\n", (char *)this + 0x10008);
    }
    if (m_size != 0) {
        CdsAssert("PCDFile.cpp", 0x37, "!CDFileDescriptor.size");
    }
    if (arg0 == 0) {
        CdsAssert("PCDFile.cpp", 0x38, "pFileName");
    }
    if (type != 1) {
        CdsAssert("PCDFile.cpp", 0x39, "nMode == OPEN_READ");
    }
    sprintf(buf, "\\%s;1", arg0);
    m_unk10050 = 0;
    m_unk10054 = 0;
    FileUtils::LoadingHangCheckInit();
    if (OpenEx(buf) == 0) {
        do {
            gInterface.LoadingDisplay(m_unk10050++, m_unk10054);
        } while (OpenEx(buf) == 0);
    }
    return 1;
}

// FUNCTION: 0x0012CB90 __dt__7PCDFileFv
PCDFile::~PCDFile() {
    if (m_size != 0) {
        Close();
    }
}

// FUNCTION: 0x0012CC00 __ct__7PCDFileFv
PCDFile::PCDFile() {
    m_size = 0;
    m_unk1002C = 0;
    m_unk1002D = 1;
    m_unk1002E = 0;
    m_unk10024 = this;
    m_unk10028 = (char *)this + 0x8000;
}
