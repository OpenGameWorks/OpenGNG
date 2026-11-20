// FLAGS: -str readonly
#include "types.h"
#include "PParticleManager.h"

// TODO(header): foreign declarations
struct tagParticleRainParams;
class PFlashScreen;
extern "C" void *__dt__16PResourceManagerFv(void *pThis, short nFlags);
extern "C" void *__dt__13PFireDamageFxFv(void *pThis, short nFlags);
extern "C" void *__dt__6PArrayFv(void *pThis, short nFlags);
extern "C" void *__dt__16PParticleRipplesFv(void *pThis, short nFlags);
extern "C" void *__dt__12PFlashScreenFv(void *pThis, short nFlags);
extern "C" void __dl__FPv(void *p);
extern "C" void *__nwa__FUi(unsigned int nSize);
void QwordCopy(u_long128 *pDst, u_long128 *pSrc, unsigned int nQwords);
struct tagParticleMovingFogParams;
class PParticleMovingFog {
public:
    PParticleMovingFog();
    virtual ~PParticleMovingFog();
    void Create(tagParticleMovingFogParams *pParams);
    char _pad004[0x4B0 - 4];
};
struct tagParticleFogData {
    char _pad000[0x45];
    unsigned char m_unk45;      // 0x45
    char _pad046[0x60 - 0x46];
};
class PCDFile {
public:
    int Read(void *pBuf, unsigned int nSize);
};

extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" PParticleRain *__ct__13PParticleRainFv(PParticleRain *pThis);
extern "C" void *__dt__12PParticleFogFv(PParticleFog *pThis, short nFlags);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void SetMaterial__10PGfxEngineFPfbUlUl(void *, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *, void *, int, bool);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *, void *, int, bool);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *, float *);
extern "C" void BeginParticles__10PGfxEngineF13eBoxIntersect(void *, int);
extern "C" void DrawParticles__10PGfxEngineFP13tagVuParticleiffb(void *, void *, int, float, float, bool);
extern "C" void EndParticles__10PGfxEngineFv(void *);
extern u_long128 lit_002487F0;
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
extern "C" void __dla__FPv(void *pMem);
extern "C" void UnloadGlobalResource__16PResourceManagerFv(void *pThis);
extern "C" void DestroyRenderedTexture__15PTextureManagerFi(void *pThis, int hTexture);
extern "C" int CreateRenderedTexture__15PTextureManagerFsssss13eTextureGroupb(void *pThis, short nW, short nH, short nA, short nB, short nC, int eGroup, bool bFlag);
extern "C" void *GetTexEnv__15PTextureManagerFi(void *pThis, int nHandle);
extern "C" void GsSetTCC__FP23tagGsTextureEnvironmentb(void *pEnv, bool bFlag);
extern "C" void GsInitFrameBufferCopyInfo__FP20tagGsFrameBufferCopyiiiiiiiiiis(void *pCopy, int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, short a11);
class PParticleLiteExplosion;
struct tagParticleLiteExplosionParams;
extern "C" PParticleLiteExplosion *__ct__22PParticleLiteExplosionFv(PParticleLiteExplosion *pThis);
class PParticleGas;
struct tagParticleGasParams;
extern "C" PParticleGas *__ct__12PParticleGasFv(PParticleGas *pThis);
extern "C" void Create__12PParticleGasFP20tagParticleGasParamsfff(PParticleGas *pThis, tagParticleGasParams *pParams, float fA, float fB, float fC);
extern "C" int AllocRenderedTexture__15PTextureManagerFiiRbb(void *pThis, int nW, int nH, bool &bOut, bool bFlag);
extern "C" void NextBatch__16PTextureDmaChainFv(void *pThis);
extern "C" void SetTexSyncPacket__12PDisplayListFv(void *pThis);
extern "C" void GsSetFrameBufferCopyInfo__FP20tagGsFrameBufferCopyii(void *pCopy, int a1, int a2);
extern "C" void SetVifCodes__12PDisplayListFUiUi(void *pThis, unsigned int a1, unsigned int a2);
extern "C" void SendGsPacket__12PDisplayListFPvib(void *pThis, void *pData, int nSize, bool bFlag);
extern "C" void SetGsRegisters__12PDisplayListFP1i(void *pThis, u_long128 *pRegs, int nCount);
class PFrozenFx;
extern u_long128 lit_002487E0;
extern "C" PFrozenFx *__ct__9PFrozenFxFv(PFrozenFx *pThis);
extern "C" int Create__9PFrozenFxFP6PMNodePffff(PFrozenFx *pThis, PMNode *pNode, float *pVec, float fA, float fB, float fC);
extern "C" PParticleFog *__ct__12PParticleFogFv(PParticleFog *pThis);
extern "C" int Create__12PParticleFogFP18tagParticleFogDatai(PParticleFog *pThis, tagParticleFogData *pData, int nTex);
extern "C" PParticleBlowingLeaves *__ct__22PParticleBlowingLeavesFv(PParticleBlowingLeaves *pThis);
extern "C" void Create__22PParticleBlowingLeavesFPfPfPfifb(PParticleBlowingLeaves *pThis, float *pA, float *pB, float *pC, int nA, float fF, bool bFlag);
extern "C" int LoadGlobalResource__16PResourceManagerFPCcb(void *pThis, const char *pName, bool bFlag);
extern "C" void Init__16PParticleRipplesFibb(void *pThis, int nCount, bool bA, bool bB);
extern "C" int sceCdReadClock(void *pClock);
extern "C" void srand(unsigned int nSeed);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
float FastMath_Sin180__Ff(float fAngle);
float FastMath_Cos180__Ff(float fAngle);
extern "C" void *__ct__6PArrayFv(void *pThis);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nCount);
extern "C" void *__ct__12PFlashScreenFv(void *pThis);
extern "C" void *__ct__16PParticleRipplesFv(void *pThis);
extern "C" void *__ct__13PFireDamageFxFv(void *pThis);
extern "C" void *__ct__16PResourceManagerFv(void *pThis);
extern char DEF_FX_RESOURCE_PRS_FILE_NAME[0x18];
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void SetCameraPosRot__13PParticleRainFPA4_fPA4_f(PParticleRain *pThis, float (*pA)[4], float (*pB)[4]);
extern "C" void SetCameraPosRot__22PParticleBlowingLeavesFPA4_fPA4_f(PParticleBlowingLeaves *pThis, float (*pA)[4], float (*pB)[4]);
extern "C" void Animate__18PParticleMovingFogFf(PParticleMovingFog *pThis, float fDt);
extern "C" void FrustrumTest__18PParticleMovingFogFP9PFrustrumPfff(PParticleMovingFog *pThis, PFrustrum *pFrustrum, float *pVec, float fA, float fB);
extern "C" void FrustrumTest__12PParticleFogFP9PFrustrumPfffP5PMat4(PParticleFog *pThis, PFrustrum *pFrustrum, float *pVec, float fA, float fB, void *pMat);
extern "C" void Animate__12PFlashScreenFv(void *pThis);
extern "C" void RenderRefractionMappedFragments__10PGfxEngineFv(void *pThis);
extern "C" void SetTexture__10PGfxEngineFi(void *pThis, int hTexture);
extern "C" void SetZBufferUpdate__10PGfxEngineFb10eGsContext(void *pThis, bool bFlag, int eContext);
extern "C" void Render__12PFlashScreenFv(void *pThis);
extern "C" void Render__12PParticleFogFP5PMat4(void *pThis, void *pMat);
extern "C" void Render__18PParticleMovingFogFv(void *pThis);

class PParticleRain {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    void SetLightningDensity(float fDensity);
    void SetDensity(float fDensity, bool bFlag);
    void Create(tagParticleRainParams *pParams, float (*pA)[4], float (*pB)[4], PFlashScreen *pScreen);
    int m_unk4;                 // 0x04
    char _pad008[0x4];
    int m_unkC;                 // 0x0C
    char _pad010[0x9];
    unsigned char m_unk19;      // 0x19
    char _pad01A[0xD4 - 0x1A];
    int m_unkD4;                // 0xD4
};

class PArray {
public:
    int Find(void *pItem);
    void Add(void *pItem);
    void InsertBefore(void *pItem);
    void Remove(void *pItem);
};

class PMovingFog {
public:
    virtual void Slot00(int bFlag);
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
};

class PParticleSystem {
public:
    virtual void Slot00(int bFlag);
    virtual void Slot01(float fDt);
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09(bool bFlag);
};

class PEweedFx {
public:
    virtual void Slot00();
    virtual void Slot01(float fDt);
    virtual int Slot02();
    virtual void Slot03();
    virtual void Slot04(PFrustrum *pFrustrum, float *pVec, float fA, float fB);
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08(float *pA, float *pB);
    virtual void Slot09();
    char _pad004[0x11];
    unsigned char m_unk15;      // 0x15
};

class PParticleOneShot {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05(int bFlag);
    virtual void Slot06();
};

class PFrozenFx {
public:
    virtual void Slot00(int nFlags);
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
};

class PParticleBlowingLeaves {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    char _pad004[0x0C];
    int m_unk10;                // 0x10
};

class PParticleLiteExplosion {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08(float *pA, float *pB);
    void Start(float fScale);
    char _pad004[0x0C];
    int m_unk10;                // 0x10
    char _pad014[0x01];
    unsigned char m_unk15;      // 0x15
    char _pad016[0x1A];
    long long m_unk30;          // 0x30
    void Create(tagParticleLiteExplosionParams *pParams, float fA, float fB, float fC);
};

class PStaticInstanceGroup {
public:
    void RenderParticleInstances(bool bFlag);
};

struct tagGroundDustParams {
    char _pad000[0x80];
    float m_unk80;              // 0x80
};

extern tagGroundDustParams gGroundDustParams;

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" int printf(const char *fmt, ...);

struct tagVuParticle {
    char _pad000[0xC];
    int m_unkC;                 // 0x0C
    char _pad010[0xC];
    int m_unk1C;                // 0x1C
};

// DRAFT: 0x001B75D0 InitHeatHazeBuffer__16PParticleManagerFv
// note: DIFF 33: nHandle branch polarity and block order, m_unk670 reload and tail store order differ; tried m_unk670 ternary, pGfx for both calls (34), pGfx first call only (33)
void PParticleManager::InitHeatHazeBuffer() {
    if (m_unk670 == 0) {
        char *pGfx = gGfxEng;
        m_unk670 = CreateRenderedTexture__15PTextureManagerFsssss13eTextureGroupb(pGfx + 0x154C90, 0x100, 0x80, 8, 7, 0, 0x69, false);
        int nHandle = *(int *)(gGfxEng + 0x16D408);
        if (nHandle == 0) {
            nHandle = m_unk670;
        }
        void *pEnv = GetTexEnv__15PTextureManagerFi((char *)gGfxEng + 0x154C90, nHandle);
        if (pEnv != 0) {
            GsSetTCC__FP23tagGsTextureEnvironmentb(pEnv, false);
        }
        m_unkEE0 = m_unk670;
    }
    GsInitFrameBufferCopyInfo__FP20tagGsFrameBufferCopyiiiiiiiiiis((char *)this + 0x50, 0, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, 0, 0x100, 0x80, 0);
}

// DRAFT: 0x001B76B0 UpdateHeatHazeBuffer__16PParticleManagerFv
// note: DIFF 6 words in GS block: 0x18/0x1B load into swapped v0/v1, sp+0x50 base and 1 load order; tried entry reorders, direct aGs[2] stores (worse, 18)
void PParticleManager::UpdateHeatHazeBuffer() {
    bool bFlag = false;
    int nTex = AllocRenderedTexture__15PTextureManagerFiiRbb(gGfxEng + 0x154C90, m_unk670, 0x2000, bFlag, false);
    if (bFlag) {
        NextBatch__16PTextureDmaChainFv((char *)*(void **)(gGfxEng + 0x154C80) + 0xA3380);
        SetTexSyncPacket__12PDisplayListFv(*(void **)(gGfxEng + 0x154C80));
    }
    GsSetFrameBufferCopyInfo__FP20tagGsFrameBufferCopyii(m_unk50, *(int *)(gGfxEng + 0x158DF0), nTex);
    SetVifCodes__12PDisplayListFUiUi(*(void **)(gGfxEng + 0x154C80), 0x11000000, 0);
    SendGsPacket__12PDisplayListFPvib(*(void **)(gGfxEng + 0x154C80), m_unk50, 0x620, true);
    SetVifCodes__12PDisplayListFUiUi(*(void **)(gGfxEng + 0x154C80), 0x11000000, 0);
    struct GsEntry {
        long long data;
        long long reg;
    };
    GsEntry aGs[3];
    aGs[0].data = 0;
    aGs[0].reg = 0x1A;
    GsEntry *pEnt = &aGs[1];
    pEnt->data = 0x18;
    pEnt->reg = 0x1B;
    pEnt = &aGs[2];
    pEnt->data = 1;
    pEnt->reg = 0x46;

    SetGsRegisters__12PDisplayListFP1i(*(void **)(gGfxEng + 0x154C80), (u_long128 *)aGs, 3);
}

// DRAFT: 0x001B77F0 RenderAuraParticles__16PParticleManagerFv
// note: 37 words differ; literal 0x2487F0 loaded via lui/lq off $at (orig lui/addiu/lq via v0), early-return beqz one insn short; tried local pointer and if-block forms.
void PParticleManager::RenderAuraParticles() {
    if (m_unkEC0 != 0) {
        u_long128 sp20 = lit_002487F0;
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unkEC4, (float *)&sp20, true, 0x48, 0x50000);
        SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, gUnitMatrix);
        BeginParticles__10PGfxEngineF13eBoxIntersect(gGfxEng, 1);
        DrawParticles__10PGfxEngineFP13tagVuParticleiffb(gGfxEng, (char *)this + 0x9C0, 0x28, 1.0f, 1.0f, true);
        EndParticles__10PGfxEngineFv(gGfxEng);
    }
}

// DRAFT: 0x001B78A0 InitRingMeshPacket__16PParticleManagerFRiibffii
// note: DIFF 93; if-branch 8 bytes short (beqz target 0x21 vs 0x1F), -0.2f built before the nA*16 pointer math, join layout differs; tried sum-of-calls and precomputed pointer locals (95).
void *PParticleManager::InitRingMeshPacket(int &nOut, int nCount, bool bFlag, float fA, float fB, int nC, int nD) {
    float aA[50][4];
    float aB[50][4];
    float aC[50][4];
    int nA;
    int nTotal;
    int *pPacket;

    if (bFlag) {
        nA = CreateRingTriStrip(nCount, fA, fB, 0.0f, 0.2f, nC, nD, aA, aB, aC);
        nTotal = nA + CreateRingTriStrip(nCount, fA, fB, 0.0f, -0.2f, nC, nD, aA + nA, aB + nA, aC + nA);
    } else {
        nA = CreateRingTriStrip(nCount, fA, fB, 0.0f, 0.3f, nC, nD, aA, aB, aC);
        nTotal = nA;
    }
    if (nTotal >= 50) {
        CdsAssert("PParticleManager.cpp", 0x654, "iNumVerts < fx_i_instance_max_vertices");
    }
    *(int *)&aA[nA][3] |= 0x8000;
    *(int *)&aA[nA + 1][3] |= 0x8000;
    pPacket = (int *)__nwa__FUi(0x970);
    if (pPacket == 0) {
        CdsAssert("PParticleManager.cpp", 0x65C, "apPacket");
    }
    pPacket[0] = nTotal;
    pPacket[1] = 0;
    pPacket[2] = 0;
    pPacket[3] = 0;
    QwordCopy((u_long128 *)((char *)pPacket + 0x10), (u_long128 *)aB, 0x32);
    QwordCopy((u_long128 *)((char *)pPacket + 0x330), (u_long128 *)aC, 0x32);
    QwordCopy((u_long128 *)((char *)pPacket + 0x650), (u_long128 *)aA, 0x32);
    nOut = 0x970;
    return pPacket;
}

// DRAFT: 0x001B7A90 CreateRingTriStrip__16PParticleManagerFiffffiiPA4_fPA4_fPA4_f
// note: DIFF 48; loop body order differs (pA stores before the fA/fB division, beqz target one word off), jal relocations; tried angle-first decl, nVerts before fStep, 0 < nVerts, inline ratio.
int PParticleManager::CreateRingTriStrip(int nCount, float fA, float fB, float fC, float fD, int nE, int nF, float (*pA)[4], float (*pB)[4], float (*pC)[4]) {
    float fAngle;
    int nVerts = nCount * 2 + 2;
    float fStep = 360.0f / (float)nCount;
    fAngle = 0.0f;
    int nIdx = 0;
    if (0 < nVerts) {
        do {
            float fSin = FastMath_Sin180__Ff(fAngle - 180.0f);
            float fCos = FastMath_Cos180__Ff(fAngle - 180.0f);
            pA[nIdx][0] = fA * fCos;
            pA[nIdx][2] = fA * fSin;
            pA[nIdx][1] = fD;
            *(int *)&pA[nIdx][3] = 0x3F800000;
            pB[nIdx][0] = 0.5f + fCos * (0.5f * (fA / fB));
            pB[nIdx][1] = 0.5f + fSin * (0.5f * (fA / fB));
            *(int *)&pC[nIdx][0] = 0x80;
            *(int *)&pC[nIdx][1] = 0x80;
            *(int *)&pC[nIdx][2] = 0x80;
            *(int *)&pC[nIdx][3] = nE;
            *(int *)&pC[nIdx + 1][0] = 0x80;
            *(int *)&pC[nIdx + 1][1] = 0x80;
            *(int *)&pC[nIdx + 1][2] = 0x80;
            *(int *)&pC[nIdx + 1][3] = nF;
            pA[nIdx + 1][0] = fB * fCos;
            pA[nIdx + 1][2] = fB * fSin;
            pA[nIdx + 1][1] = fC;
            *(int *)&pA[nIdx + 1][3] = 0x3F800000;
            pB[nIdx + 1][0] = 0.5f + 0.5f * fCos;
            pB[nIdx + 1][1] = 0.5f + 0.5f * fSin;
            fAngle += fStep;
            nIdx += 2;
        } while (nIdx < nVerts);
    }
    return nVerts;
}

// DRAFT: 0x001B7C70 RenderShockwaveRings__16PParticleManagerFv
// note: 78 differing words. Still differs: prologue saves and this/nCount register allocation (original keeps this in s4, nCount in s0), and the copy-store address hoisting (original recomputes lui 0x7000 + addu before each store). Tried: local reorder (141), gGfxEng offset for DrawFx (141 -> lower), in-place m_unk4 index (79), zeroing after first load (78), nOff/nCount swap (79).
void PParticleManager::RenderShockwaveRings() {
    float fCol[4];
    int nCount;
    unsigned int nOff;
    char *pElem;
    u_long128 q;

    m_unk4 = 0;
    pElem = (m_unk0 != 0) ? (char *)m_unk8[0] : 0;
    nCount = 0;
    nOff = 0;
    while (pElem != 0) {
        if (*(int *)(pElem + 0xC) == 0x13 && *(unsigned char *)(pElem + 0x15) != 0) {
            *(u_long128 *)(0x70001000 + nOff) = *(u_long128 *)(pElem + 0xE0);
            *(u_long128 *)(0x70000000 + nOff + 0x1010) = *(u_long128 *)(pElem + 0xF0);
            *(u_long128 *)(0x70000000 + nOff + 0x1020) = *(u_long128 *)(pElem + 0x100);
            *(u_long128 *)(0x70000000 + nOff + 0x1030) = *(u_long128 *)(pElem + 0x110);
            *(u_long128 *)(0x70000000 + nOff + 0x1040) = *(u_long128 *)(pElem + 0x120);
            *(u_long128 *)(0x70000000 + nOff + 0x1050) = *(u_long128 *)(pElem + 0x130);
            nCount++;
            nOff += 0x60;
            if (nCount >= 0x21) {
                break;
            }
        }
        m_unk4++;
        pElem = (m_unk4 < m_unk0) ? (char *)m_unk8[m_unk4] : 0;
    }
    if (nCount != 0) {
        fCol[0] = 1.1f;
        fCol[1] = 1.1f;
        fCol[2] = 1.1f;
        fCol[3] = 1.0f;
        SetMaterial__10PGfxEngineFPfbUlUl(gGfxEng, fCol, true, 0x44, 0x50000);
        BeginFxInstances__10PGfxEngineFPvib(gGfxEng, m_unk2050, m_unk2054, true);
        DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)(gGfxEng + 0x154C80), (void *)0x70001000, nCount, true);
        fCol[0] = 1.0f;
        fCol[1] = 1.0f;
        fCol[2] = 1.0f;
        fCol[3] = 0.8f;
        int nTex = GetFxTexture(0x8400000DU);
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, nTex, fCol, true, 0x48, 0x50000);
        BeginFxInstances__10PGfxEngineFPvib(gGfxEng, m_unk2058, m_unk205C, false);
        DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)(gGfxEng + 0x154C80), (void *)0x70001000, nCount, true);
    }
}

// FUNCTION: 0x001B7EC0 InitShockwaveRings__16PParticleManagerFv
void PParticleManager::InitShockwaveRings() {
    m_unk2050 = (void *)InitRingMeshPacket(*(int *)&m_unk2054, 0xC, false, 0.3f, 0.5f, 0, 0xFF);
    if (m_unk2050 == 0) {
        CdsAssert("PParticleManager.cpp", 0x5D9, "mpDistortionShockwaveMesh");
    }
    m_unk2058 = (void *)InitRingMeshPacket(*(int *)&m_unk205C, 0xC, false, 0.3f, 0.5f, 0xFF, 0xFF);
    if (m_unk2058 == 0) {
        CdsAssert("PParticleManager.cpp", 0x5DF, "mpHilightShockwaveMesh");
    }
}

// FUNCTION: 0x001B7F90 RenderEweedReactionFx__16PParticleManagerFv
void PParticleManager::RenderEweedReactionFx() {
    for (int i = 0, off = 0; i < 8; i++) {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20DC);
        if (pFx->m_unk15 != 0) {
            pFx->Slot02();
        }
        off += 4;
    }
}

// FUNCTION: 0x001B8000 AnimateEweedReactionFx__16PParticleManagerFP9PFrustrumf
void PParticleManager::AnimateEweedReactionFx(PFrustrum *pFrustrum, float fDt) {
    for (int i = 0, off = 0; i < 8; i++, off += 4) {
        PEweedFx **pp = (PEweedFx **)((char *)this + off + 0x20DC);
        PEweedFx *pFx = *pp;
        if (pFx->m_unk15 != 0) {
            pFx->Slot04(pFrustrum, (float *)((char *)this + 0x680), *(float *)((char *)this + 0x6A0), *(float *)((char *)this + 0x6A4));
            (*pp)->Slot01(fDt);
        }
    }
}

// FUNCTION: 0x001B80C0 DestroyEweedReactionFx__16PParticleManagerFv
void PParticleManager::DestroyEweedReactionFx() {
    int i = 0;
    int off = 0;
    do {
        PMovingFog *pFx = *(PMovingFog **)((char *)this + off + 0x20DC);
        if (pFx != 0 && pFx != 0) {
            pFx->Slot00(1);
        }
        i++;
        off += 4;
    } while (i < 8);
}

// FUNCTION: 0x001B8130 InitEweedReactionFx__16PParticleManagerFv
void PParticleManager::InitEweedReactionFx() {
    int i = 0;
    PParticleOneShot *pFx;
    int off = 0;
    do {
        pFx = Create(0x83000346, 0.0f, 0.0f, 0.0f, 0, false);
        if (pFx == 0) {
            CdsAssert("PParticleManager.cpp", 0x5A1, "apFx");
        }
        *(PParticleOneShot **)((char *)this + off + 0x20DC) = pFx;
        i++;
        off += 4;
    } while (i < 8);
}

// FUNCTION: 0x001B81D0 RenderSulphurReactionFx__16PParticleManagerFv
void PParticleManager::RenderSulphurReactionFx() {
    for (int i = 0, off = 0; i < 8; i++) {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20BC);
        if (pFx->m_unk15 != 0) {
            pFx->Slot02();
        }
        off += 4;
    }
}

// FUNCTION: 0x001B8240 AnimateSulphurReactionFx__16PParticleManagerFP9PFrustrumf
void PParticleManager::AnimateSulphurReactionFx(PFrustrum *pFrustrum, float fDt) {
    for (int i = 0, off = 0; i < 8; i++, off += 4) {
        PEweedFx **pp = (PEweedFx **)((char *)this + off + 0x20BC);
        PEweedFx *pFx = *pp;
        if (pFx->m_unk15 != 0) {
            pFx->Slot04(pFrustrum, (float *)((char *)this + 0x680), *(float *)((char *)this + 0x6A0), *(float *)((char *)this + 0x6A4));
            (*pp)->Slot01(fDt);
        }
    }
}

// FUNCTION: 0x001B8300 DestroySulphurReactionFx__16PParticleManagerFv
void PParticleManager::DestroySulphurReactionFx() {
    int i = 0;
    int off = 0;
    do {
        PMovingFog *pFx = *(PMovingFog **)((char *)this + off + 0x20BC);
        if (pFx != 0 && pFx != 0) {
            pFx->Slot00(1);
        }
        i++;
        off += 4;
    } while (i < 8);
}

// FUNCTION: 0x001B8370 InitSulphurReactionFx__16PParticleManagerFv
void PParticleManager::InitSulphurReactionFx() {
    int i = 0;
    PParticleOneShot *pFx;
    int off = 0;
    do {
        pFx = Create(0x8300025A, 0.0f, 0.0f, 0.0f, 0, false);
        if (pFx == 0) {
            CdsAssert("PParticleManager.cpp", 0x572, "apFx");
        }
        *(PParticleOneShot **)((char *)this + off + 0x20BC) = pFx;
        i++;
        off += 4;
    } while (i < 8);
}

// FUNCTION: 0x001B8410 RenderGroundDustFx__16PParticleManagerFv
void PParticleManager::RenderGroundDustFx() {
    for (int i = 0, off = 0; i < 12; i++) {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x208C);
        if (pFx->m_unk15 != 0) {
            pFx->Slot02();
        }
        off += 4;
    }
}

// FUNCTION: 0x001B8480 AnimateGroundDustFx__16PParticleManagerFP9PFrustrumf
void PParticleManager::AnimateGroundDustFx(PFrustrum *pFrustrum, float fDt) {
    int i = 0;
    int off = 0;
    do {
        PEweedFx **pp = (PEweedFx **)((char *)this + off + 0x208C);
        PEweedFx *pFx = *pp;
        if (pFx->m_unk15 != 0) {
            pFx->Slot04(pFrustrum, (float *)((char *)this + 0x680), *(float *)((char *)this + 0x6A0), *(float *)((char *)this + 0x6A4));
            (*pp)->Slot01(fDt);
        }
        i++;
        off += 4;
    } while (i < 12);
}

// FUNCTION: 0x001B8540 DestroyGroundDustFx__16PParticleManagerFv
void PParticleManager::DestroyGroundDustFx() {
    int i = 0;
    int off = 0;
    do {
        PMovingFog *pFx = *(PMovingFog **)((char *)this + off + 0x208C);
        if (pFx != 0 && pFx != 0) {
            pFx->Slot00(1);
        }
        i++;
        off += 4;
    } while (i < 12);
}

// DRAFT: 0x001B85B0 InitGroundDustFx__16PParticleManagerFv
// note: DIFF 5: this/off registers swapped (ours s1=off s0=this, original s1=this s0=off); tried pSelf copy, counter-first order
void PParticleManager::InitGroundDustFx() {
    int off = 0;
    int i = 0;
    do {
        PParticleLiteExplosion *pFx;
        pFx = (PParticleLiteExplosion *)__nw__FUi(0x1D0);
        if (pFx != 0) {
            pFx = __ct__22PParticleLiteExplosionFv(pFx);
        }
        if (pFx == 0) {
            CdsAssert("PParticleManager.cpp", 0x53E, "apFx");
        }
        pFx->Create((tagParticleLiteExplosionParams *)&gGroundDustParams, 0.0f, 0.0f, 0.0f);
        pFx->m_unk10 = GetFxTexture(0x84000006);
        pFx->m_unk30 = 0x44;
        *(PParticleLiteExplosion **)((char *)this + off + 0x208C) = pFx;
        off += 4;
        i++;
    } while (i < 12);
}

// DRAFT: 0x001B8690 EnableFxByType__16PParticleManagerF7ePSTypeb
// note: DIFF 6: exit beqz target +0x17 vs +0x18, index temp a0 vs a1, loop-bottom bnez and nop placement; tried loop-tail reload, m_unk4++, nIdx forms, swapped declarations, for-loop.
void PParticleManager::EnableFxByType(ePSType eType, bool bFlag) {
    unsigned int nIdx;
    PParticleSystem *pFx;
    m_unk4 = 0;
    if (m_unk0 != 0) {
        pFx = (PParticleSystem *)m_unk8[0];
    } else {
        pFx = 0;
    }
    while (pFx != 0) {
        if ((int)eType == *(int *)((char *)pFx + 0xC)) {
            pFx->Slot09(bFlag);
        }
        nIdx = ++m_unk4;
        pFx = 0;
        if (nIdx < m_unk0) {
            pFx = (PParticleSystem *)m_unk8[m_unk4];
        }
    }
}

// FUNCTION: 0x001B8750 CreateEweedReaction__16PParticleManagerFPf
int PParticleManager::CreateEweedReaction(float *pPos) {
    int i = 0;
    int off = 0;
    do {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20DC);
        if (pFx->m_unk15 == 0) {
            pFx->Slot08(pPos, pPos);
            pFx->Slot06();
            return 1;
        }
        i++;
        off += 4;
    } while (i < 8);
    return 0;
}

// FUNCTION: 0x001B87D0 CreateSulphurReaction__16PParticleManagerFPff
int PParticleManager::CreateSulphurReaction(float *pPos, float fUnused) {
    int i = 0;
    int off = 0;
    do {
        PEweedFx *pFx = *(PEweedFx **)((char *)this + off + 0x20BC);
        if (pFx->m_unk15 == 0) {
            pFx->Slot08(pPos, pPos);
            pFx->Slot06();
            return 1;
        }
        i++;
        off += 4;
    } while (i < 8);
    return 0;
}

// FUNCTION: 0x001B8850 CreateGroundDust__16PParticleManagerFPff
int PParticleManager::CreateGroundDust(float *pPos, float fScale) {
    int i = 0;
    int off = 0;
    do {
        PParticleLiteExplosion *pFx = *(PParticleLiteExplosion **)((char *)this + off + 0x208C);
        if (pFx->m_unk15 == 0) {
            pFx->Slot08(pPos, pPos);
            pFx->Start(gGroundDustParams.m_unk80 * fScale);
            return 1;
        }
        i++;
        off += 4;
    } while (i < 12);
    return 0;
}

// DRAFT: 0x001B88F0 CreateFrozenFx__16PParticleManagerFP6PMNodeff
// note: DIFF 57, size 0x100 vs 0x10c; diverges from about 0x50 at assert string addressing and 0.3f literal order against the aVec lq copy.
PFrozenFx *PParticleManager::CreateFrozenFx(PMNode *pNode, float fA, float fB) {
    PFrozenFx *pFx;
    PFrozenFx *pNew;
    u_long128 aVec;

    if ((pNew = (PFrozenFx *)__nw__FUi(0x210)) != 0) {
        pFx = __ct__9PFrozenFxFv(pNew);
    } else {
        pFx = pNew;
    }
    if (pFx == 0) {
        CdsAssert("PParticleManager.cpp", 0x4CB, "apFx");
    }
    aVec = lit_002487E0;
    if (Create__9PFrozenFxFP6PMNodePffff(pFx, pNode, (float *)&aVec, 0.3f, fA, fB) != 0) {
        Add((PParticleSystem *)pFx);
        pFx->Slot06();
        return pFx;
    }
    if (pFx != 0) {
        pFx->Slot00(1);
    }
    return 0;
}

// DRAFT: 0x001B8A00 FreeAuraParticle__16PParticleManagerFP13tagVuParticle
// note: the zero path stores $zero directly (sw) where the original does daddu v1,zero,zero then sw v1; branch offset of the b differs by one word.
void PParticleManager::FreeAuraParticle(tagVuParticle *pParticle) {
    if (pParticle != 0) {
        pParticle->m_unkC = 0;
        pParticle->m_unk1C = 0;
        int n = m_unkEC0 - 1;
        if (n > 0) {
            m_unkEC0 = n;
            return;
        }
        n = 0;
        m_unkEC0 = n;
    }
}

// FUNCTION: 0x001B8A40 AllocAuraParticle__16PParticleManagerFv
void *PParticleManager::AllocAuraParticle() {
    int i = 0;
    int off = 0;
    do {
        if (*(float *)((char *)this + off + 0x9CC) == 0.0f && *(float *)((char *)this + off + 0x9DC) == 0.0f) {
            m_unkEC0++;
            return (char *)this + (i << 5) + 0x9C0;
        }
        i++;
        off += 0x20;
    } while (i < 0x28);
    printf("\n**Too many Aura Particles! Ask Vn to increase array size!\n", off);
    return 0;
}

// DRAFT: 0x001B8AD0 DestroyMovingFog__16PParticleManagerFv
// note: the original has one null check with the vtable call and store inside; ours emits an extra beqz before the vtable load (variants: local pointer, early return, store outside guard).
void PParticleManager::DestroyMovingFog() {
    if (m_unk9B4 != 0) {
        m_unk9B4->Slot00(1);
        m_unk9B4 = 0;
    }
}

// FUNCTION: 0x001B8B20 CreateMovingFog__16PParticleManagerFP26tagParticleMovingFogParams
void PParticleManager::CreateMovingFog(tagParticleMovingFogParams *pParams) {
    if (pParams == 0) {
        CdsAssert("PParticleManager.cpp", 0x47A, "pParams");
    }
    if (m_unk9B4 != 0) {
        if (m_unk9B4 != 0) {
            m_unk9B4->Slot00(1);
        }
        m_unk9B4 = 0;
    }
    m_unk9B4 = (PMovingFog *)new PParticleMovingFog;
    if (m_unk9B4 == 0) {
        CdsAssert("PParticleManager.cpp", 0x483, "mpMovingFog");
    }
    ((PParticleMovingFog *)m_unk9B4)->Create(pParams);
}

// FUNCTION: 0x001B8BE0 CreateBlowingLeaves__16PParticleManagerFPfPfPfifb
PParticleBlowingLeaves *PParticleManager::CreateBlowingLeaves(float *pA, float *pB, float *pC, int nA, float fF, bool bFlag) {
    PParticleBlowingLeaves *pObj;

    pObj = (PParticleBlowingLeaves *)__nw__FUi(0xA60);
    if (pObj != 0) {
        pObj = __ct__22PParticleBlowingLeavesFv(pObj);
    }
    if (pObj == 0) {
        CdsAssert("PParticleManager.cpp", 0x45F, "apFx");
    }
    Create__22PParticleBlowingLeavesFPfPfPfifb(pObj, pA, pB, pC, nA, fF, bFlag);
    pObj->Slot06();
    pObj->m_unk10 = GetFxTexture(0x84000012);
    Add((PParticleSystem *)pObj);
    m_unk20FC = (PParticleSystem *)pObj;
    return pObj;
}

// FUNCTION: 0x001B8CF0 SetLightningDensity__16PParticleManagerFf
void PParticleManager::SetLightningDensity(float fDensity) {
    if (m_pRain != 0) {
        m_pRain->SetLightningDensity(fDensity);
    }
}

// FUNCTION: 0x001B8D20 SetRainDensity__16PParticleManagerFfb
void PParticleManager::SetRainDensity(float fDensity, bool bFlag) {
    if (m_pRain != 0) {
        SetRainDensity((unsigned int)m_pRain, fDensity / 100.0f, bFlag);
    }
}

// FUNCTION: 0x001B8D70 DestroyRain__16PParticleManagerFv
void PParticleManager::DestroyRain() {
    if (m_pRain != 0) {
        Remove((PParticleSystem *)m_pRain);
        m_pRain = 0;
    }
}

// FUNCTION: 0x001B8DB0 CreateRain__16PParticleManagerFf
void PParticleManager::CreateRain(float fDensity) {
    struct {
        float fA;
        float fB;
        float fC;
        float fD;
        int nE;
        float fF;
        float fG;
        float fH;
    } params;

    if (IsValid((PParticleSystem *)m_pRain) == 0) {
        m_pRain = 0;
    }
    if (m_pRain != 0) {
        SetRainDensity((unsigned int)m_pRain, fDensity / 100.0f, false);
        return;
    }
    params.fA = -0.2f;
    params.fB = -1.0f;
    params.fC = 0.2f;
    params.fD = 1.0f;
    params.fF = 1.5f;
    params.fG = 4.0f;
    params.fH = 30.0f;
    params.nE = 0xF5;
    m_pRain = (PParticleRain *)CreateRain((tagParticleRainParams *)&params);
    SetRainDensity((unsigned int)m_pRain, fDensity / 100.0f, false);
    m_unk9B0 = 1;
}

// DRAFT: 0x001B8EB0 SetRainDensity__16PParticleManagerFUifb
// note: 1 word differs at 0x1C; ours beqz $s0 (local pRain) vs original beqz $a1 (hRain). Tried nested if (6 words), and no local (6 words).
void PParticleManager::SetRainDensity(unsigned int hRain, float fDensity, bool bFlag) {
    PParticleRain *pRain = (PParticleRain *)hRain;
    if (hRain != 0 && IsValid((PParticleSystem *)hRain) && pRain->m_unkC == 8) {
        pRain->SetDensity(fDensity, bFlag);
    }
}

// FUNCTION: 0x001B8F20 CreateRain__16PParticleManagerFP21tagParticleRainParams
PParticleRain *PParticleManager::CreateRain(tagParticleRainParams *pParams) {
    PParticleRain *pRain = (PParticleRain *)__nw__FUi(0x2C0);
    if (pRain != 0) {
        pRain = __ct__13PParticleRainFv(pRain);
    }
    PParticleRain *pResult = 0;
    if (pRain != 0) {
        pRain->Create(pParams, (float (*)[4])((char *)this + 0x680), (float (*)[4])((char *)this + 0x690), (PFlashScreen *)((char *)this + 0x6B0));
        pRain->m_unkD4 = 2;
        pRain->Slot06();
        Add((PParticleSystem *)pRain);
        pResult = pRain;
    }
    return pResult;
}

// DRAFT: 0x001B8FE0 LoadFogObjects__16PParticleManagerFP8PPakFile16ePsx2FileVersion
// note: DIFF 32; original keeps this in s2, pFile in s1, index in s0 (ours this s1, pFile s0, index s2); prologue saves and frame -0xB0 vs -0xC0 differ. Tried: header struct instead of count, header/record/index declaration orders.
int PParticleManager::LoadFogObjects(PPakFile *pFile, ePsx2FileVersion nVersion) {
    struct {
        unsigned int nCount;
        char _pad[0x1C];
    } hdr;
    tagParticleFogData rec;
    unsigned int nIndex;

    if (pFile == 0) {
        CdsAssert("PParticleManager.cpp", 0x3DF, "poFile");
    }
    nIndex = 0;
    if (((PCDFile *)pFile)->Read(&hdr, 0x20) != 0x20) {
        return 0;
    }
    while (nIndex < hdr.nCount) {
        if (((PCDFile *)pFile)->Read(&rec, 0x60) != 0x60) {
            return 0;
        }
        if (CreateFog(&rec) == 0) {
            return 0;
        }
        nIndex++;
    }
    return 1;
}

// DRAFT: 0x001B90B0 CreateFog__16PParticleManagerFP18tagParticleFogData
// note: DIFF 6; original shares one GetFxTexture call with a0 set in both arms; tried if/else, inverted test, short-circuit ||, empty-then (DIFF 47-52).
int PParticleManager::CreateFog(tagParticleFogData *pData) {
    PParticleFog *pObj;
    int nTex;

    if (pData == 0) {
        CdsAssert("PParticleManager.cpp", 0x3BE, "pData");
    }
    if (m_unk40 == 0) {
        CdsAssert("PParticleManager.cpp", 0x3BF, "mpFxResMgr");
    }
    if (m_unk20 >= 0x100) {
        CdsAssert("PParticleManager.cpp", 0x3C0, "moFogList.GetCount() < MAX_FOGS");
    }
    nTex = 0;
    if (pData->m_unk45 != 0) {
        nTex = m_unk2060;
    }
    if (nTex == 0) {
        nTex = GetFxTexture(0x84000002);
    }
    pObj = (PParticleFog *)__nw__FUi(0x60);
    if (pObj != 0) {
        pObj = __ct__12PParticleFogFv(pObj);
    }
    if (pObj == 0) {
        CdsAssert("PParticleManager.cpp", 0x3CC, "apFog");
    }
    if (Create__12PParticleFogFP18tagParticleFogDatai(pObj, pData, nTex) == 0) {
        __dt__12PParticleFogFv(pObj, 1);
        return 0;
    }
    ((PArray *)((char *)this + 0x20))->Add(pObj);
    return 1;
}

// FUNCTION: 0x001B9200 CreateGasFx__16PParticleManagerFP20tagParticleGasParamsfff
PParticleGas *PParticleManager::CreateGasFx(tagParticleGasParams *pParams, float fA, float fB, float fC) {
    PParticleGas *pGas;
    PParticleGas *pNew;

    if (pParams == 0) {
        CdsAssert("PParticleManager.cpp", 0x3AB, "pParams");
    }
    if ((pNew = (PParticleGas *)__nw__FUi(0x170)) != 0) {
        pGas = __ct__12PParticleGasFv(pNew);
    } else {
        pGas = pNew;
    }
    if (pGas == 0) {
        CdsAssert("PParticleManager.cpp", 0x3B1, "apFx");
    }
    Create__12PParticleGasFP20tagParticleGasParamsfff(pGas, pParams, fA, fB, fC);
    Add((PParticleSystem *)pGas);
    return pGas;
}

// FUNCTION: 0x001B92E0 CreateOneShot__16PParticleManagerFUifff
PParticleOneShot *PParticleManager::CreateOneShot(unsigned int hFx, float fA, float fB, float fC) {
    PParticleOneShot *pFx = Create(hFx, fA, fB, fC, 0, true);
    if (pFx != 0) {
        pFx->Slot06();
        pFx->Slot05(0);
    }
    return pFx;
}

// FUNCTION: 0x001B9B50 IsValid__16PParticleManagerFP15PParticleSystem
int PParticleManager::IsValid(PParticleSystem *pSystem) {
    if ((pSystem != 0) && (((PArray *)this)->Find(pSystem) >= 0)) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x001B9B90 Render__16PParticleManagerF8ePSLayerb
// note: DIFF 150 words, size 0x450 vs 0x448. Missing andi on the m_unk0 arm before loop B; loop B branch shape; element-select b around lw a0,0(v1); index register; trailing SetZBufferUpdate reloc at 0x0404. Tried: while and do-while loop A, int/bool bFound (bool form 159 words), && form (152), break form (150).
int PParticleManager::Render(ePSLayer eLayer, bool bFlag) {
    int nSum = 0;
    unsigned int nIdx;
    PParticleRain *pFx;
    PParticleFog *pFog;
    int bFound;

    SetZBufferUpdate__10PGfxEngineFb10eGsContext(&gGfxEng, 0, 0);
    m_unk4 = 0;
    pFx = (m_unk0 != 0) ? (PParticleRain *)m_unk8[0] : 0;
    if (pFx != 0) {
        do {
            if ((eLayer == pFx->m_unkD4) && (pFx->m_unk19 == 0)) {
                pFx->Slot02();
                nSum += pFx->m_unk4;
            }
            nIdx = m_unk4 + 1;
            m_unk4 = nIdx;
            pFx = (nIdx < m_unk0) ? (PParticleRain *)m_unk8[m_unk4] : 0;
        } while (pFx != 0);
    }

    if (eLayer == ePSLayer_2) {
        RenderParticleInstanceGroups(false);
        RenderAuraParticles();
        RenderGroundDustFx();
        RenderSulphurReactionFx();
        RenderEweedReactionFx();
        m_unk24 = 0;
        pFog = (m_unk20 != 0) ? m_unk28[0] : 0;
        while (pFog != 0) {
            Render__12PParticleFogFP5PMat4(pFog, 0);
            nIdx = m_unk24 + 1;
            m_unk24 = nIdx;
            pFog = (nIdx < m_unk20) ? m_unk28[m_unk24] : 0;
        }
        if (m_unk9B4 != 0) {
            Render__18PParticleMovingFogFv(m_unk9B4);
        }
    }

    bFound = (m_unk1730 > 0);
    if (bFound != 0) {
        bFound = (eLayer == ePSLayer_2);
    }
    m_unk4 = 0;
    pFx = (m_unk0 != 0) ? (PParticleRain *)m_unk8[0] : 0;
    while ((pFx != 0) && (bFound == 0)) {
        if ((eLayer == pFx->m_unkD4) && (pFx->m_unk19 != 0)) {
            bFound = 1;
            break;
        }
        nIdx = m_unk4 + 1;
        m_unk4 = nIdx;
        pFx = (nIdx < m_unk0) ? (PParticleRain *)m_unk8[m_unk4] : 0;
    }

    if (eLayer == ePSLayer_2) {
        m_unk207C = 0;
        pFx = (m_unk2078 != 0) ? (PParticleRain *)m_unk2080[0] : 0;
        while ((pFx != 0) && (bFound == 0)) {
            if (pFx->m_unk19 != 0) {
                bFound = 1;
            } else {
                nIdx = m_unk207C + 1;
                m_unk207C = nIdx;
                pFx = (nIdx < m_unk2078) ? (PParticleRain *)m_unk2080[m_unk207C] : 0;
            }
        }
    }

    if ((bFound != 0) || bFlag) {
        UpdateHeatHazeBuffer();
        SetTexture__10PGfxEngineFi(&gGfxEng, m_unk670);
        m_unk4 = 0;
        pFx = (m_unk0 != 0) ? (PParticleRain *)m_unk8[0] : 0;
        while (pFx != 0) {
            if ((eLayer == pFx->m_unkD4) && (pFx->m_unk19 != 0)) {
                pFx->Slot02();
                nSum += pFx->m_unk4;
            }
            nIdx = m_unk4 + 1;
            m_unk4 = nIdx;
            pFx = (nIdx < m_unk0) ? (PParticleRain *)m_unk8[m_unk4] : 0;
        }
        if (eLayer == ePSLayer_2) {
            RenderParticleInstanceGroups(true);
        }
        RenderRefractionMappedFragments__10PGfxEngineFv(&gGfxEng);
        if (eLayer == ePSLayer_2) {
            ((PParticleRain *)m_unkED0)->Slot02();
            RenderShockwaveRings();
            ((PParticleRain *)m_unk1790)->Slot02();
        }
    }
    if ((eLayer == ePSLayer_2) && (m_unk9B0 != 0)) {
        Render__12PFlashScreenFv((char *)this + 0x6B0);
    }
    SetZBufferUpdate__10PGfxEngineFb10eGsContext(&gGfxEng, 1, 0);
    if (eLayer == ePSLayer_2) {
        if (m_unk2070 != 0) {
            m_unk2068 = 0;
            m_unk206C = 0;
        }
    }
    return nSum;
}

// FUNCTION: 0x001B9FE0 Update__16PParticleManagerFfP6CameraP9PFrustrum8ePSLayer
void PParticleManager::Update(float fDt, Camera *pCamera, PFrustrum *pFrustrum, ePSLayer eLayer) {
    PParticleRain *pFx;
    unsigned int nIdx;

    if (pCamera) {
        sceVu0CopyVector((float *)((char *)this + 0x680), (float *)pCamera);
        sceVu0CopyVector((float *)((char *)this + 0x690), (float *)((char *)pCamera + 0x20));
        m_unk4 = 0;
    } else {
        *(int *)((char *)this + 0x688) = 0;
        *(int *)((char *)this + 0x684) = 0;
        *(int *)((char *)this + 0x680) = 0;
        *(float *)((char *)this + 0x68C) = 1.0f;
        m_unk4 = 0;
    }
    pFx = (m_unk0 != 0) ? (PParticleRain *)m_unk8[0] : 0;
    while (pFx) {
        if (eLayer == pFx->m_unkD4) {
            if (pFx->m_unkC == 8) {
                SetCameraPosRot__13PParticleRainFPA4_fPA4_f(pFx, (float (*)[4])((char *)this + 0x680), (float (*)[4])((char *)this + 0x690));
            } else if (pFx->m_unkC == 0x15) {
                SetCameraPosRot__22PParticleBlowingLeavesFPA4_fPA4_f((PParticleBlowingLeaves *)pFx, (float (*)[4])((char *)this + 0x680), (float (*)[4])((char *)this + 0x690));
            } else if (pFx->m_unkC == 0x18) {
                *(u_long128 *)((char *)pFx + 0x100) = *(u_long128 *)((char *)this + 0x680);
                *(u_long128 *)((char *)pFx + 0x110) = *(u_long128 *)((char *)this + 0x690);
            }
            ((PEweedFx *)pFx)->Slot04(pFrustrum, (float *)((char *)this + 0x680), *(float *)((char *)this + 0x6A0), *(float *)((char *)this + 0x6A4));
            ((PParticleSystem *)pFx)->Slot01(fDt);
        }
        nIdx = m_unk4 + 1;
        m_unk4 = nIdx;
        pFx = (nIdx < m_unk0) ? (PParticleRain *)m_unk8[m_unk4] : 0;
    }
    if (eLayer == 2) {
        AnimateGroundDustFx(pFrustrum, fDt);
        AnimateSulphurReactionFx(pFrustrum, fDt);
        AnimateEweedReactionFx(pFrustrum, fDt);
        m_unk24 = 0;
        pFx = (m_unk20 != 0) ? (PParticleRain *)m_unk28[0] : 0;
        while (pFx) {
            FrustrumTest__12PParticleFogFP9PFrustrumPfffP5PMat4((PParticleFog *)pFx, pFrustrum, m_unk680, *(float *)&m_unk6A0, *(float *)&m_unk6A4, 0);
            nIdx = m_unk24 + 1;
            m_unk24 = nIdx;
            pFx = (nIdx < m_unk20) ? (PParticleRain *)m_unk28[m_unk24] : 0;
        }
        if (m_unk9B4) {
            Animate__18PParticleMovingFogFf((PParticleMovingFog *)m_unk9B4, fDt);
            FrustrumTest__18PParticleMovingFogFP9PFrustrumPfff((PParticleMovingFog *)m_unk9B4, pFrustrum, m_unk680, *(float *)&m_unk6A0, *(float *)&m_unk6A4);
        }
        ((PEweedFx *)m_unkED0)->Slot04(pFrustrum, m_unk680, *(float *)&m_unk6A0, *(float *)&m_unk6A4);
        ((PParticleSystem *)m_unkED0)->Slot01(fDt);
        ((PEweedFx *)m_unk1790)->Slot04(pFrustrum, m_unk680, *(float *)&m_unk6A0, *(float *)&m_unk6A4);
        ((PParticleSystem *)m_unk1790)->Slot01(fDt);
        UpdateMasterParticleInstances(fDt, pFrustrum);
    }
    if (eLayer == 2) {
        Animate__12PFlashScreenFv((char *)this + 0x6B0);
    }
    m_unk4 = 0;
    pFx = (m_unk0 != 0) ? (PParticleRain *)m_unk8[0] : 0;
    while (pFx) {
        if (*((unsigned char *)pFx + 0x16) != 0) {
            Remove((PParticleSystem *)pFx);
        }
        nIdx = m_unk4 + 1;
        m_unk4 = nIdx;
        pFx = (nIdx < m_unk0) ? (PParticleRain *)m_unk8[m_unk4] : 0;
    }
    m_unk14 = 0;
    pFx = (m_unk10 != 0) ? (PParticleRain *)m_unk18[0] : 0;
    while (pFx) {
        if (pFx) {
            ((PParticleSystem *)pFx)->Slot00(1);
        }
        nIdx = m_unk14 + 1;
        m_unk14 = nIdx;
        pFx = (nIdx < m_unk10) ? (PParticleRain *)m_unk18[m_unk14] : 0;
    }
    if (m_unk18) {
        m_unk10 = 0;
        m_unk14 = 0;
    }
}

// DRAFT: 0x001BA3F0 UpdateMasterParticleInstances__16PParticleManagerFfP9PFrustrum
// note: 10 lines: original reloads 0x207C after the store and keeps fDt copy in the branch delay slot; tried if/else tail (worse, 14)
void PParticleManager::UpdateMasterParticleInstances(float fDt, PFrustrum *pFrustrum) {
    PParticleSystem *pSystem;
    m_unk207C = 0;
    if (m_unk2078 != 0) {
        pSystem = m_unk2080[0];
    } else {
        pSystem = 0;
    }
    if (pSystem != 0) {
        do {
            pSystem->Slot01(fDt);
            ++m_unk207C;
            pSystem = 0;
            if (m_unk207C < m_unk2078) {
                pSystem = m_unk2080[m_unk207C];
            }
        } while (pSystem != 0);
    }
}

// FUNCTION: 0x001BA490 RenderParticleInstanceGroups__16PParticleManagerFb
void PParticleManager::RenderParticleInstanceGroups(bool bFlag) {
    PStaticInstanceGroup *pGroup;
    unsigned int idx;
    m_unk206C = 0;
    if (m_unk2068 != 0) {
        pGroup = m_unk2070[0];
    } else {
        pGroup = 0;
    }
    if (pGroup != 0) {
        do {
            pGroup->RenderParticleInstances(bFlag);
            idx = m_unk206C + 1;
            m_unk206C = idx;
            pGroup = (idx < m_unk2068) ? m_unk2070[m_unk206C] : 0;
        } while (pGroup != 0);
    }
}

// FUNCTION: 0x001BA530 AddParticleInstanceGroup__16PParticleManagerFP20PStaticInstanceGroup
void PParticleManager::AddParticleInstanceGroup(PStaticInstanceGroup *pGroup) {
    if (pGroup == 0) {
        CdsAssert("PParticleManager.cpp", 0x1B2, "pGroup");
    }
    ((PArray *)((char *)this + 0x2068))->Add(pGroup);
}

// FUNCTION: 0x001BA590 AddMasterParticleInstance__16PParticleManagerFP15PParticleSystem
void PParticleManager::AddMasterParticleInstance(PParticleSystem *pFx) {
    if (pFx == 0) {
        CdsAssert("PParticleManager.cpp", 0x1AA, "pFx");
    }
    ((PArray *)((char *)this + 0x2078))->Add(pFx);
}

// DRAFT: 0x001BA5F0 RemoveAllFogObjects__16PParticleManagerFv
// note: 8 lines: original reloads 0x24 after the store (sw v1 then lw a1); ours reuses the register; postfix ++ same count
void PParticleManager::RemoveAllFogObjects() {
    PParticleFog *pFog;
    m_unk24 = 0;
    if (m_unk20 != 0) {
        pFog = m_unk28[0];
    } else {
        pFog = 0;
    }
    if (pFog != 0) {
        do {
            __dt__12PParticleFogFv(pFog, 1);
            ++m_unk24;
            pFog = 0;
            if (m_unk24 < m_unk20) {
                pFog = m_unk28[m_unk24];
            }
        } while (pFog != 0);
    }
    if (m_unk28 != 0) {
        m_unk20 = 0;
        m_unk24 = 0;
    }
}

// FUNCTION: 0x001BA800 RemoveAllParticleSystems__16PParticleManagerFv
void PParticleManager::RemoveAllParticleSystems() {
    PParticleSystem *pSystem;
    unsigned int nIdx;
    m_unk4 = 0;
    if (m_unk0 != 0) {
        pSystem = (PParticleSystem *)m_unk8[0];
    } else {
        pSystem = 0;
    }
    if (pSystem != 0) {
        do {
            if (pSystem != 0) {
                pSystem->Slot00(1);
            }
            nIdx = m_unk4 + 1;
            m_unk4 = nIdx;
            pSystem = (nIdx < m_unk0) ? (PParticleSystem *)m_unk8[m_unk4] : 0;
        } while (pSystem != 0);
    }
    m_unk14 = 0;
    void *pEntry = 0;
    if (m_unk10 != 0) {
        pEntry = *m_unk18;
    }
    if (pEntry != 0) {
        do {
            if (pEntry != 0) {
                ((PParticleSystem *)pEntry)->Slot00(1);
            }
            unsigned int nSlot = m_unk14 + 1;
            m_unk14 = nSlot;
            pEntry = (nSlot < m_unk10) ? m_unk18[m_unk14] : 0;
        } while (pEntry != 0);
    }
    if (m_unk8 != 0) {
        m_unk0 = 0;
        m_unk4 = 0;
    }
    if (m_unk18 != 0) {
        m_unk10 = 0;
        m_unk14 = 0;
    }
    if (m_unk9B4 != 0) {
        if (m_unk9B4 != 0) {
            m_unk9B4->Slot00(1);
        }
        m_unk9B4 = 0;
    }
    memset(m_unk9C0, 0, 0x500);
    m_unkEC0 = 0;
    if (m_unk2070 != 0) {
        m_unk2068 = 0;
        m_unk206C = 0;
    }
    if (m_unk2080 != 0) {
        m_unk2078 = 0;
        m_unk207C = 0;
    }
    m_unk20FC = 0;
}

// FUNCTION: 0x001BA690 RemoveAllParticleSystems__16PParticleManagerF8ePSLayer
void PParticleManager::RemoveAllParticleSystems(ePSLayer eLayer) {
    PParticleSystem *pSystem;
    unsigned int nIdx;
    m_unk4 = 0;
    if (m_unk0 != 0) {
        pSystem = (PParticleSystem *)m_unk8[0];
    } else {
        pSystem = 0;
    }
    if (pSystem != 0) {
        do {
            if ((int)eLayer == *(int *)((char *)pSystem + 0xD4)) {
                ((PArray *)this)->Remove(pSystem);
                if (pSystem != 0) {
                    pSystem->Slot00(1);
                }
                if (pSystem == m_unk20FC) {
                    m_unk20FC = 0;
                }
            }
            nIdx = m_unk4 + 1;
            m_unk4 = nIdx;
            pSystem = (nIdx < m_unk0) ? (PParticleSystem *)m_unk8[m_unk4] : 0;
        } while (pSystem != 0);
    }
    m_unk14 = 0;
    void *pEntry = 0;
    if (m_unk10 != 0) {
        pEntry = *m_unk18;
    }
    if (pEntry != 0) {
        do {
            if (pEntry != 0) {
                ((PParticleSystem *)pEntry)->Slot00(1);
            }
            unsigned int nSlot = m_unk14 + 1;
            m_unk14 = nSlot;
            pEntry = (nSlot < m_unk10) ? m_unk18[m_unk14] : 0;
        } while (pEntry != 0);
    }
    if (m_unk18 != 0) {
        m_unk10 = 0;
        m_unk14 = 0;
    }
}

// FUNCTION: 0x001BA9B0 RemoveAll__16PParticleManagerFv
void PParticleManager::RemoveAll() {
    RemoveAllParticleSystems();
    RemoveAllFogObjects();
}

// FUNCTION: 0x001BA9E0 Stop__16PParticleManagerFUi
void PParticleManager::Stop(unsigned int hSystem) {
    PParticleSystem *pSystem = (PParticleSystem *)hSystem;
    if (pSystem != 0 && IsValid(pSystem)) {
        pSystem->Slot07();
    }
}

// FUNCTION: 0x001BAA30 StopFx__16PParticleManagerFUi
void PParticleManager::StopFx(unsigned int hSystem) {
    PParticleSystem *pSystem = (PParticleSystem *)hSystem;
    if (pSystem != 0 && IsValid(pSystem)) {
        pSystem->Slot07();
    }
}

// FUNCTION: 0x001BAA80 Destroy__16PParticleManagerFUi
void PParticleManager::Destroy(unsigned int hSystem) {
    PParticleSystem *pSystem = (PParticleSystem *)hSystem;
    if (pSystem != 0 && IsValid(pSystem)) {
        pSystem->Slot07();
        Remove(pSystem);
    }
}

// FUNCTION: 0x001BAAE0 Remove__16PParticleManagerFP15PParticleSystem
void PParticleManager::Remove(PParticleSystem *pSystem) {
    if (pSystem == 0) {
        CdsAssert("PParticleManager.cpp", 0xF6, "pSystem");
    }
    if (IsValid(pSystem)) {
        ((PArray *)this)->Remove(pSystem);
        if (pSystem != 0) {
            pSystem->Slot00(1);
        }
    }
    if (pSystem == (PParticleSystem *)m_pRain) {
        m_pRain = 0;
    }
    if (pSystem == m_unk20FC) {
        m_unk20FC = 0;
    }
}

// FUNCTION: 0x001BAB80 Add__16PParticleManagerFP15PParticleSystem
void PParticleManager::Add(PParticleSystem *pSystem) {
    PParticleSystem *pCur;
    unsigned int nIdx;
    int nKey;
    if (pSystem == 0) {
        CdsAssert("PParticleManager.cpp", 0xE0, "pSystem");
    }
    if (m_unk0 >= 0x12C) {
        CdsAssert("PParticleManager.cpp", 0xE2, "moList.GetCount() < MAX_PARTICLES");
    }
    nKey = *(int *)((char *)pSystem + 0xC);
    m_unk4 = 0;
    pCur = (m_unk0 != 0) ? (PParticleSystem *)m_unk8[0] : 0;
    while (pCur != 0) {
        if (nKey == *(int *)((char *)pCur + 0xC)) {
            ((PArray *)this)->InsertBefore(pSystem);
            return;
        }
        nIdx = m_unk4 + 1;
        m_unk4 = nIdx;
        pCur = (nIdx < m_unk0) ? (PParticleSystem *)m_unk8[m_unk4] : 0;
    }
    ((PArray *)this)->Add(pSystem);
}

// FUNCTION: 0x001BAC80 Shutdown__16PParticleManagerFv
void PParticleManager::Shutdown() {
    RemoveAll();
    UnloadGlobalResource__16PResourceManagerFv(m_unk40);
    m_unk2060 = 0;
    m_unk2064 = 0;
    if (m_unk2050 != 0) {
        __dla__FPv(m_unk2050);
        m_unk2050 = 0;
        m_unk2054 = 0;
    }
    if (m_unk2058 != 0) {
        __dla__FPv(m_unk2058);
        m_unk2058 = 0;
        m_unk205C = 0;
    }
    DestroyGroundDustFx();
    DestroySulphurReactionFx();
    DestroyEweedReactionFx();
    if (m_unk670 != 0) {
        DestroyRenderedTexture__15PTextureManagerFi(gGfxEng + 0x154C90, m_unk670);
        m_unk670 = 0;
    }
}

// FUNCTION: 0x001BAD20 Init__16PParticleManagerFv
int PParticleManager::Init() {
    unsigned char aClock[8];
    if (m_unk40 == 0) {
        return 0;
    }
    if (LoadGlobalResource__16PResourceManagerFPCcb(m_unk40, DEF_FX_RESOURCE_PRS_FILE_NAME, 0) == 0) {
        printf("\n\nFailed to load particle fx resource files!\n");
        CdsAssert("PParticleManager.cpp", 0x94, "0");
        return 0;
    }
    Init__16PParticleRipplesFibb(m_unk1790, 6, 0, 0);
    m_unk17A0 = GetFxTexture(0x8400000DU);
    Init__16PParticleRipplesFibb(m_unkED0, 6, 1, 1);
    m_unkEE0 = m_unk670;
    InitShockwaveRings();
    sceCdReadClock(aClock);
    srand(aClock[1] + aClock[2] * 60 + aClock[3] * 3600);
    memset(m_unk30, 0, 0x10);
    m_unk6A0 = 0x461C4000;
    m_unk6A4 = 0x45FD2000;
    memset(m_unk9C0, 0, 0x500);
    m_unkEC4 = GetFxTexture(0x84000004U);
    m_unk2060 = 0;
    m_unk2064 = 0;
    m_unk20FC = 0;
    InitGroundDustFx();
    InitSulphurReactionFx();
    InitEweedReactionFx();
    return 1;
}

// FUNCTION: 0x001BAE90 __dt__16PParticleManagerFv
PParticleManager::~PParticleManager() {
    Shutdown();
    if (m_unk40 != 0) {
        __dt__16PResourceManagerFv(m_unk40, 1);
        m_unk40 = 0;
    }
    __dt__13PFireDamageFxFv((char *)this + 0x2088, -1);
    __dt__6PArrayFv((char *)this + 0x2078, -1);
    __dt__6PArrayFv((char *)this + 0x2068, -1);
    __dt__16PParticleRipplesFv((char *)this + 0x1790, -1);
    __dt__16PParticleRipplesFv((char *)this + 0xED0, -1);
    __dt__12PFlashScreenFv((char *)this + 0x6B0, -1);
    __dt__6PArrayFv((char *)this + 0x20, -1);
    __dt__6PArrayFv((char *)this + 0x10, -1);
    __dt__6PArrayFv(this, -1);
}

// DRAFT: 0x001BAF70 __ct__16PParticleManagerFv
// note: original spills this to 0x1C(sp) and reloads per call (embedded dtor-bearing members PArray/PParticleRipples/PFlashScreen/PFireDamageFx at 0x00..0x2088); header keeps raw fields, so we get s0..s4 saves, 0x60 frame, DIFF 91 words. Tried: 1 variant (cast-based calls).
PParticleManager::PParticleManager() {
    __ct__6PArrayFv(this);
    __ct__6PArrayFv((char *)this + 0x10);
    __ct__6PArrayFv((char *)this + 0x20);
    __ct__12PFlashScreenFv((char *)this + 0x6B0);
    __ct__16PParticleRipplesFv((char *)this + 0xED0);
    __ct__16PParticleRipplesFv((char *)this + 0x1790);
    __ct__6PArrayFv((char *)this + 0x2068);
    __ct__6PArrayFv((char *)this + 0x2078);
    __ct__13PFireDamageFxFv((char *)this + 0x2088);
    void *pRes = __nw__FUi(0xD0);
    if (pRes != 0) {
        pRes = __ct__16PResourceManagerFv(pRes);
    }
    m_unk40 = pRes;
    if (m_unk40 == 0) {
        CdsAssert("PParticleManager.cpp", 0x5F, "mpFxResMgr");
    }
    Allocate__6PArrayFUi(this, 0x12C);
    Allocate__6PArrayFUi((char *)this + 0x10, 0x12C);
    Allocate__6PArrayFUi((char *)this + 0x20, 0x100);
    Allocate__6PArrayFUi((char *)this + 0x2068, 0x40);
    Allocate__6PArrayFUi((char *)this + 0x2078, 0x20);
    *(int *)((char *)this + 0x44) = 0;
    m_unk9B4 = 0;
    m_pRain = 0;
    m_unk9B0 = 0;
    m_unkEC0 = 0;
    m_unk2060 = 0;
    m_unk2064 = 0;
    memset((char *)this + 0x208C, 0, 0x30);
    memset((char *)this + 0x20BC, 0, 0x20);
    memset((char *)this + 0x20DC, 0, 0x20);
    m_unk670 = 0;
}
