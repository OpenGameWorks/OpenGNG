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
void CdsAssert(char *pFile, int nLine, char *pExpr);

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

// DRAFT: 0x0012C060 ReadData__7PCDFileFi
// note: 1 word differs: flag = 1 is daddiu, original addiu; while-retry loop, bool flag (74 words) and goto variants tried, int is closest.
int PCDFile::ReadData(int arg0) {
    int flag;

    m_unk10054 = 0;
    do {
        flag = 0;
        while (sceCdRead(*(unsigned int *)((char *)this + 0x10040 + arg0 * 4),
                         *(unsigned int *)((char *)this + 0x10048 + arg0 * 4),
                         *(void **)((char *)this + 0x10024 + arg0 * 4),
                         &m_unk1002C) != 1) {
            if (flag == 0) {
                printf("The precache operation failed %d\n", arg0);
                flag = 1;
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

// DRAFT: 0x0012C7B0 Read__7PCDFileFPvUi
// note: 8 words differ; original has an extra nop before the shared epilogue and a b-to-epilogue delay shape; do-while, early-return and label variants tried, none closer.
int PCDFile::Read(void *buf, unsigned int size) {
    int r;

    FileUtils::LoadingHangCheckInit();
    r = ReadEx(buf, size);
    if (r != size) {
        do {
            r = ReadEx(buf, size);
            if (r == 0) {
                r = 0;
                goto done;
            }
        } while (r != size);
    }
done:
    ;
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
