// FLAGS: -str readonly
#include "types.h"
#include "MaxEngine.h"

// TODO(header): foreign declarations
class PScrollingTrees;
// PGfxEngine size is unknown; the placeholder member only keeps gGfxEng a complete object.
class PGfxEngine {
public:
    void InitGlobalsForNtscMode();
    void RefreshDisplay();
    char _pad000[0x10];
};
extern PGfxEngine gGfxEng;
class PWorld {
public:
    void Init();
    void Animate();
    void CullMainWorld();
    void Render();
    void Destroy();
};
// Debug size is unknown; the placeholder member only keeps gDebug a complete object.
class Debug {
public:
    void StartTimer(unsigned int nId);
    void StopTimer(unsigned int nId);
    char _pad000[0x10];
};
extern Debug gDebug;
// PArray size is unknown; the placeholder member only keeps mBGAnimList__7Physics a complete object.
// PArray size is unknown; m_unk0, m_unk4 and m_unk8 are the fields Destroy reads and writes.
class PArray {
public:
    void Allocate(unsigned int nCount);
    int m_unk0;
    int m_unk4;
    int m_unk8;
    char _pad00C[4];
};
extern PArray mBGAnimList__7Physics;
// BGCollision size is unknown; the placeholder member only keeps mBGCollision__15EntityBaseClass a complete object.
class BGCollision {
public:
    void Destroy();
    char _pad000[0x10];
};
extern BGCollision mBGCollision__15EntityBaseClass;
class PParticleManager {
public:
    void RemoveAllFogObjects();
};
class FontManager {
public:
    void ResetWarning();
    void RenderWarning(int nId);
};
extern unsigned char gInterface[2656];
extern "C" int sceCdStatus(void);
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
extern "C" void __dt__6PWorldFv(void *pThis, short nFlag);
extern "C" void __ct__6PWorldFv(void *pThis);
extern "C" void __dl__FPv(void *pMem);
// Pointee of m_unk137A8; only its virtual destructor (vtable slot 8) is used here.
class MaxEngineSlot {
public:
    virtual ~MaxEngineSlot();
};

extern MaxEngine gEng;

// FUNCTION: 0x00131ED0 EngGenerateUniqueID__9MaxEngineFv
int MaxEngine::EngGenerateUniqueID() {
    int temp_v0;

    temp_v0 = m_unk137D4;
    m_unk137D4 += 1;
    return temp_v0;
}

// FUNCTION: 0x00132080 RenderWorld__9MaxEngineFib
void MaxEngine::RenderWorld(int nFrame, bool bFlag) {
    gDebug.StartTimer(5);
    if (!(nFrame & 7)) {
        ((PWorld *)this)->Animate();
    }
    if (!bFlag) {
        ((PWorld *)this)->CullMainWorld();
    }
    gDebug.StopTimer(5);
    gDebug.StartTimer(8);
    ((PWorld *)this)->Render();
    gDebug.StopTimer(8);
}

// FUNCTION: 0x001322B0 DestroyScrollingTrees__9MaxEngineFv
void MaxEngine::DestroyScrollingTrees() {
    if (m_unk137DC != 0) {
        __dt__15PScrollingTreesFv(m_unk137DC, 1);
        m_unk137DC = 0;
    }
}

// FUNCTION: 0x00132430 Destroy__9MaxEngineFv
void MaxEngine::Destroy() {
    if (m_unk137A8 != 0) {
        delete m_unk137A8;
        m_unk137A8 = 0;
        m_unk137AC = 0;
    }
    ((PWorld *)this)->Destroy();
    mBGCollision__15EntityBaseClass.Destroy();
    if (mBGAnimList__7Physics.m_unk8 != 0) {
        mBGAnimList__7Physics.m_unk0 = 0;
        mBGAnimList__7Physics.m_unk4 = 0;
    }
    ((PParticleManager *)((char *)&gGfxEng + 0x154F00))->RemoveAllFogObjects();
}

// FUNCTION: 0x00132870 CheckCDTrayDuringLoading__9MaxEngineFUi
void MaxEngine::CheckCDTrayDuringLoading(unsigned int nTimeout) {
    if (sceCdStatus() == 1 || nTimeout > 0x2710) {
        ((FontManager *)(gInterface + 0x80))->ResetWarning();
        for (;;) {
            ((FontManager *)(gInterface + 0x80))->RenderWarning(0x28E);
            gGfxEng.RefreshDisplay();
        }
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

// FUNCTION: 0x00132D10 __dt__9MaxEngineFv
MaxEngine::~MaxEngine() {
    if (m_unk137A8 != 0) {
        delete m_unk137A8;
        m_unk137A8 = 0;
    }
    DestroyScrollingTrees();
    __dt__6PWorldFv(this, 0);
}

// FUNCTION: 0x00132DB0 __ct__9MaxEngineFv
MaxEngine::MaxEngine() {
    __ct__6PWorldFv(this);
    m_unk137A0 = 0;
    m_unk137A4 = 0;
    m_unk137AC = 0;
    m_unk137D4 = 1;
    m_unk137D8 = 0;
    m_unk137DC = 0;
}
