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
    void Animate(float fTime);
    int Render();
};
// PGfxEngine size is unknown; the placeholder member only keeps gGfxEng a complete object.
class PDisplayList;
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
    void RenderBlendedFragments(float *pVec);
    char _pad000[0x154C80];
    PDisplayList *m_unk154C80;
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
    void PauseVibrate(bool pause);
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
    void Update(float fTime, Camera *pCam, PFrustrum *pFrustrum, ePSLayer eLayer);
};
extern "C" void sceVu0CopyVector(float *dst, float *src);
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
    void GetTrayRelated(int *pA, int *pB, int *pC, int *pD);
    char _pad000[0x10];
};
extern PSound gSound;
extern float GAME_FPS;
extern "C" void scePcStart(int nMode, int nA, int nB);
extern "C" void scePcStop(void);
extern "C" void __dt__15PScrollingTreesFv(void *pThis, short nFlag);
extern "C" PScrollingTrees *__ct__15PScrollingTreesFv(void *pThis);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int printf(const char *fmt, ...);
extern "C" void __dt__6PWorldFv(void *pThis, short nFlag);
extern "C" void __ct__6PWorldFv(void *pThis);
extern "C" void __dl__FPv(void *pMem);
extern "C" void vu1SetViewMatrix__FP5PMat4(void *pMat);
extern "C" void vu1SetClipMatrix__FP5PMat4(void *pMat);
extern "C" void vu1ClearZBuffer__Fv(void);
extern float gUnitMatrix[16];
// Pointee of m_unk137A8; the virtual destructor is slot 0 (0x08), VFunc1 slot 0x0C and VFunc4 slot 0x18.
class MaxEngineSlot {
public:
    virtual ~MaxEngineSlot();
    virtual int VFunc1(int nA, int nB, int nC);
    virtual void VFunc2();
    virtual void VFunc3();
    virtual void VFunc4(int nA, int nB, int nC, float fA, float fB);
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

// FUNCTION: 0x00131F00 RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer
void MaxEngine::RenderParticleFx(Camera *pCam, int nFlag, ePSLayer eLayer) {
    float fTime;

    gDebug.StartTimer(10);
    if (nFlag != 0) {
        fTime = 0.0f;
    } else {
        fTime = m_unk1E8;
    }
    ((PParticleManager *)((char *)&gGfxEng + 0x154F00))->Update(fTime, pCam, (PFrustrum *)((char *)this + 0xF0), eLayer);
    sceVu0CopyVector((float *)((char *)&gGfxEng + 0x16D330), (float *)pCam);
    gGfxEng.RenderParticleSystems(eLayer, (PZBufferFog *)((char *)this + 0x8750));
    gGfxEng.SetScreenMatrix((PMat4 *)((char *)this + 0x10));
    gGfxEng.SetViewMatrix((PMat4 *)((char *)this + 0x90));
    gGfxEng.SetClipMatrix((PMat4 *)((char *)this + 0x50));
    if ((int)eLayer == ePSLayer_2) {
        if (*(unsigned char *)((char *)&gGfxEng + 0x158E26) != 0) {
            ((PShadowBuffer *)((char *)&gGfxEng + 0x157000))->Render();
            gGfxEng.m_unk154C80->SetScreenMatrix((PMat4 *)((char *)&gGfxEng + 0x16D3C0));
            gGfxEng.m_unk154C80->SetViewMatrix((PMat4 *)((char *)&gGfxEng + 0x16D380));
            gGfxEng.m_unk154C80->SetClipMatrix((PMat4 *)((char *)&gGfxEng + 0x16D340));
        }
        gGfxEng.RenderFullScreenMotionBlur(fTime);
    }
    gDebug.StopTimer(10);
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

// FUNCTION: 0x00132130 RenderSkybox__9MaxEngineFi
// MaxEngine.h has no RenderSkybox member, so the mangled name is defined as a free function; the bytes match a member with this in a0.
extern "C" int RenderSkybox__9MaxEngineFi(MaxEngine *pThis, int nFlag) {
    int nRet = 0;
    if (pThis->m_unk137A8 != 0) {
        gDebug.StartTimer(12);
        float aMat[16];
        sceVu0CopyMatrix((float (*)[4])aMat, (float (*)[4])((char *)pThis + 0x90));
        *(u_long128 *)((char *)aMat + 0x30) = *(u_long128 *)gUnitMatrix;
        vu1SetViewMatrix__FP5PMat4(aMat);
        vu1SetClipMatrix__FP5PMat4((char *)pThis + 0x50);
        if ((nFlag & 7) == 0) {
            pThis->m_unk137A8->VFunc4(0, 0, 0, 0.0f, pThis->m_unk1E8);
        }
        nRet += pThis->m_unk137A8->VFunc1(0, 0x80, 0);
        if (pThis->m_unk137DC != 0) {
            if ((nFlag & 7) == 0) {
                pThis->m_unk137DC->Animate(pThis->m_unk1E8);
            }
            nRet += pThis->m_unk137DC->Render();
        }
        gGfxEng.RenderBlendedFragments(gUnitMatrix);
        if (*((unsigned char *)pThis + 0x9EF9) == 0 || *((unsigned char *)pThis + 0x9EFA) != 0) {
            vu1ClearZBuffer__Fv();
        }
        gDebug.StopTimer(12);
    }
    return nRet;
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

// DRAFT: 0x001328E0 CheckCDTrayDuringGamePlay__9MaxEngineFv
// note: DIFF 149 words; GetTrayRelated slots now match (nA 0x30, nC 0x34, nD 0x38, nB 0x3C), but the countdown address at 0x137D0 is CSE'd into s1 with this in s2 (frame 0x50, s2 saved) where the original rematerializes lui/addu per access in s1=this with frame 0x40; tried local order and goto shape only.
void MaxEngine::CheckCDTrayDuringGamePlay() {
    int nA;
    int nC;
    int nD;
    int nB;
    int nS;

    gSound.GetTrayRelated(&nA, &nB, &nC, &nD);
    if (nA == 0) {
        return;
    }
    ((FontManager *)(gInterface + 0x1790))->ResetWarning();
    *(int *)((char *)this + 0x137D0) = (int)GAME_FPS * 2;
    gPad.PauseVibrate(true);
    goto check;

l960:
    if (*(int *)((char *)this + 0x137D0) > 0) {
        goto refresh;
    }
    if (nD != 0 || nB == 1) {
        ((FontManager *)(gInterface + 0x1790))->RenderWarning(0x28B);
    } else {
        ((FontManager *)(gInterface + 0x1790))->RenderWarning(0x290);
    }
refresh:
    gGfxEng.RefreshDisplay();
    scePcStart(0x8008003E, 0, 0);
    scePcStop();
    m_unk1E8 = 1.0f;
    if (*(int *)((char *)this + 0x137D0) > 0) {
        *(int *)((char *)this + 0x137D0) = *(int *)((char *)this + 0x137D0) - 1;
    }
after:
    SoundOneFrameHasElapsed_R(nA, nB);
    gSound.GetTrayRelated(&nA, &nB, &nC, &nD);
check:
    if (nB == 1) {
        goto l960;
    }
    if (nD < 2) {
        goto l960;
    }
    *(int *)((char *)this + 0x137D0) = 0;
    gSound.GetTrayRelated(&nA, &nB, &nC, &nD);
    if (nD == 0) {
        goto check;
    }
    if (nD == 1) {
        goto check;
    }
    nS = (int)GAME_FPS * 30;
    goto tail;

warn:
    ((FontManager *)(gInterface + 0x1790))->RenderWarning(0x28F);
    nS = nS - 1;
    gGfxEng.RefreshDisplay();
    scePcStart(0x8008003E, 0, 0);
    scePcStop();
    m_unk1E8 = 1.0f;
    SoundOneFrameHasElapsed_R(nA, nB);
    gSound.GetTrayRelated(&nA, &nB, &nC, &nD);
    if (nA == 0) {
        goto check;
    }
    if (nD == 0) {
        goto check;
    }
    if (nD == 1) {
        goto check;
    }
tail:
    if (nS == 0) {
        goto unpause;
    }
    if (nC != 2) {
        goto warn;
    }
unpause:
    gPad.PauseVibrate(false);
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
