// FLAGS: -str readonly
#include "types.h"
#include "MaxEngine.h"

// TODO(header): foreign declarations
class PResourceManager;
// PScrollingTrees size is unknown; only its constructor, Init, Create and CreateFloor are used here.
class PScrollingTrees {
public:
    void Init(float *pA, float *pB, float fC, PResourceManager *pD);
    void Create(int nA, int nB, int nC);
    void CreateFloor();
};
// PGfxEngine size is unknown; the placeholder member only keeps gGfxEng a complete object.
class PGfxEngine {
public:
    void InitGlobalsForNtscMode();
    void RefreshDisplay();
    void Reset();
    void SetScreenMatrix(class PMat4 *pMat);
    void SetViewMatrix(class PMat4 *pMat);
    void SetClipMatrix(class PMat4 *pMat);
    void RenderParticleSystems(ePSLayer eLayer, class PZBufferFog *pFog);
    void RenderFullScreenMotionBlur(float fTime);
    char _pad000[0x10];
};
extern PGfxEngine gGfxEng;
// PDisplayList, PShadowBuffer, PMat4, PFrustrum and PZBufferFog sizes are unknown; only the methods and pointers named here are used.
class PDisplayList {
public:
    void SetScreenMatrix(class PMat4 *pMat);
    void SetViewMatrix(class PMat4 *pMat);
    void SetClipMatrix(class PMat4 *pMat);
};
class PShadowBuffer {
public:
    void Render();
};
class PMat4;
class PFrustrum;
class PZBufferFog;
class PWorld {
public:
    void Init();
    void Animate();
    void CullMainWorld();
    void Render();
    void Destroy();
    void InitRenderFrame();
};
// Debug size is unknown; the placeholder member only keeps gDebug a complete object.
class Debug {
public:
    void StartTimer(unsigned int nId);
    void StopTimer(unsigned int nId);
    void DebugClear();
    char _pad000[0x10];
};
extern Debug gDebug;
// Pad size is unknown; the placeholder member only keeps gPad and gPad2 complete objects.
class Pad {
public:
    void UpdatePad();
    char _pad000[0x10];
};
extern Pad gPad;
extern Pad gPad2;
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
    void InitFrame();
};
extern unsigned char gInterface[2656];
// Interface size is unknown; gInterface is addressed through a cast at offset 0x1710.
class Interface {
public:
    void SoundGainEEControl();
};
extern "C" int sceCdStatus(void);
extern "C" int sceGsSyncPath(int nA, int nB);
void FastMath_Setup();
void DmaWaitForCompletion(int nA, bool bB);
// Movie size is unknown; PlayMovie is called through its mangled name with the fifth argument left unset, as the original does.
extern "C" int PlayMovie__5MovieFiiUib(void *pThis, int nA, int nB, unsigned int nC);
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    int PSoundInit(unsigned int nFlag);
    void OneFrameHasElapsed_R(float *pA, float fB, int &nA, int &nB);
    void StopMusic();
    void PSoundLevelClear();
    void ReturnControlOfIOPToMjln();
    char _pad000[0x10];
};
extern PSound gSound;
extern "C" void __dt__15PScrollingTreesFv(void *pThis, short nFlag);
extern "C" PScrollingTrees *__ct__15PScrollingTreesFv(void *pThis);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
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

// FUNCTION: 0x00131DF0 PlayMovie__9MaxEngineFiiUi
int MaxEngine::PlayMovie(int nA, int nB, unsigned int nC) {
    int nResult;

    gSound.StopMusic();
    gSound.PSoundLevelClear();
    ((Interface *)(gInterface + 0x1710))->SoundGainEEControl();
    InitRenderFrame(false, 0);
    DmaWaitForCompletion(1, false);
    sceGsSyncPath(0, 0);
    nResult = PlayMovie__5MovieFiiUib((void *)nA, nB, nC, 0U);
    ((PGfxEngine *)((char *)&gGfxEng + 0x6680))->Reset();
    FastMath_Setup();
    InitRenderFrame(false, 0);
    gSound.ReturnControlOfIOPToMjln();
    return nResult;
}

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

// FUNCTION: 0x00132300 CreateScrollingTrees__9MaxEngineFv
void MaxEngine::CreateScrollingTrees() {
    PScrollingTrees *pTrees;

    if (m_unk137DC == 0) {
        pTrees = (PScrollingTrees *)__nw__FUi(0x680);
        if (pTrees != 0) {
            pTrees = __ct__15PScrollingTreesFv(pTrees);
        }
        m_unk137DC = pTrees;
        if (m_unk137DC == 0) {
            CdsAssert__FPciPc("MaxEngine.cpp", 0x1B6, "mpScrollingTrees");
        }
        {
            float afA[4] = {-300.0f, -135.0f, -600.0f, 1.0f};
            float afB[4] = {300.0f, -135.0f, 220.0f, 1.0f};
            m_unk137DC->Init(afA, afB, 3.4166667f, (PResourceManager *)((char *)&gEng + 0x188A4));
        }
        m_unk137DC->Create(6, 5, 0);
        m_unk137DC->Create(3, 5, 1);
        m_unk137DC->Create(4, 7, 2);
        m_unk137DC->CreateFloor();
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

// FUNCTION: 0x00132B80 InitRenderFrame__9MaxEngineFbUi
void MaxEngine::InitRenderFrame(bool bFlag, unsigned int nTimeout) {
    int nA;
    int nB;

    SoundOneFrameHasElapsed_R(nA, nB);
    gPad.UpdatePad();
    gPad2.UpdatePad();
    ((PWorld *)this)->InitRenderFrame();
    IncrementSecondarySyncCounts();
    gDebug.DebugClear();
    ((FontManager *)(gInterface + 0x1790))->InitFrame();
    if (bFlag) {
        CheckCDTrayDuringLoading(nTimeout);
    } else {
        CheckCDTrayDuringGamePlay();
    }
    m_unk137CC = -1;
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
