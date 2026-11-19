// FLAGS: -str readonly
#include "types.h"
#include "MaxEngine.h"

// TODO(header): foreign declarations
class PScrollingTrees;
class PGfxEngine {
public:
    void InitGlobalsForNtscMode();
};
class PWorld {
public:
    void Init();
};
// PArray size is unknown; the placeholder member only keeps mBGAnimList__7Physics a complete object.
class PArray {
public:
    void Allocate(unsigned int nCount);
    char _pad000[0x10];
};
extern PArray mBGAnimList__7Physics;
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    int PSoundInit(unsigned int nFlag);
    void OneFrameHasElapsed_R(float *pA, float fB, int &nA, int &nB);
    char _pad000[0x10];
};
extern PSound gSound;
extern "C" void __dt__15PScrollingTreesFv(void *pThis, short nFlag);
extern "C" int printf(const char *fmt, ...);

extern MaxEngine gEng;

// FUNCTION: 0x00131ED0 EngGenerateUniqueID__9MaxEngineFv
int MaxEngine::EngGenerateUniqueID() {
    int temp_v0;

    temp_v0 = m_unk137D4;
    m_unk137D4 += 1;
    return temp_v0;
}

// FUNCTION: 0x001322B0 DestroyScrollingTrees__9MaxEngineFv
void MaxEngine::DestroyScrollingTrees() {
    if (m_unk137DC != 0) {
        __dt__15PScrollingTreesFv(m_unk137DC, 1);
        m_unk137DC = 0;
    }
}

// FUNCTION: 0x00132C40 IncrementSecondarySyncCounts__9MaxEngineFv
void MaxEngine::IncrementSecondarySyncCounts() {
    m_unk137A0 += 1;
    m_unk137A4 += 1;
}

// FUNCTION: 0x00132C80 SoundOneFrameHasElapsed_R__9MaxEngineFRiRi
void MaxEngine::SoundOneFrameHasElapsed_R(int &nA, int &nB) {
    gSound.OneFrameHasElapsed_R(&m_unkD0, gEng.m_unk19784, nA, nB);
}

// FUNCTION: 0x00132CB0 EngineInit__9MaxEngineFv
void MaxEngine::EngineInit() {
    ((PGfxEngine *)this)->InitGlobalsForNtscMode();
    ((PWorld *)this)->Init();
    mBGAnimList__7Physics.Allocate(0x40);
    if (!(gSound.PSoundInit(1) & 0xFF)) {
        printf("initialization of sound failed\n");
    }
}
