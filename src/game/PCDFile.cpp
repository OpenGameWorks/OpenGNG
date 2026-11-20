#include "types.h"
#include "PCDFile.h"

// TODO(header): foreign declarations
extern "C" int printf(const char *fmt, ...);
extern "C" int sceCdSync(int mode);
extern "C" void __dl__FPv(void *pMem);

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

// DRAFT: 0x0012C830 Close__7PCDFileFv
// note: 23 words differ; gInterface lui is emitted after the m_unk10050 load (original does it first), loop exit lands one nop early; while, do-while, post-increment and local-pointer forms tried.
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
