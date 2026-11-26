#include "types.h"
#include "PParticleRain.h"
#include "PSound.h"
#include "PMat4.h"

// TODO(header): foreign declarations
// Symbols at PGfxEngine's member addresses; gGfxEng is the engine block at 0x306680.
extern "C" void DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(void *pThis, void *pLines, int nCount, float fA, float fB, bool bFlag);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nIdx, float *pVals, bool bFlag, unsigned long nA, unsigned long nB);
extern "C" void BeginFxLines__10PGfxEngineFv(void *pThis);
extern "C" void EndFxLines__10PGfxEngineFv(void *pThis);
extern char gGfxEng[1504384];
extern PSound gSound;
extern "C" char __vt__13PParticleRain[0x40];
extern "C" void __ct__13PRainSplatterFv(void *pThis);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" int rand(void);
extern "C" int GetFxTexture__16PParticleManagerFUi(void *pThis, unsigned int nId);
extern "C" int GetGroundPos__11BGCollisionFPA4_f(void *pThis, float (*pPos)[4]);
extern "C" void GetGroundPos__7PhysicsFv(void *pRet);
extern "C" void Init__12PFlashScreenFffffUiUiUii(void *pThis, float fA, float fB, float fC, float fD, unsigned int nA, unsigned int nB, unsigned int nC, int nD);
extern char mBGCollision__15EntityBaseClass[0x10];
extern char mPlayerAPI__13EntityManager[0x10];
float FastMath_Fabs(float f);

// One quadrant of the rain volume, 0x50 bytes apart from 0x120: the box spawns particles [m_nStart, m_nEnd).
struct PRainBox {
    char _pad000[0x120];
    float m_fMin[4];            // 0x120
    float m_fMax[4];            // 0x130
    unsigned int m_nStart;      // 0x140
    unsigned int m_nEnd;        // 0x144
};

#define m_pParts ((PRainParticle *)m_unk248)
struct PRainParticle {
    float m_fPos[4];
    float m_fVel[4];
};
#define PR_STEP() (m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3)
#define PR_RND() (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF))

// FUNCTION: 0x001CC100 FrustrumTest__13PParticleRainFP9PFrustrumPfff
void PParticleRain::FrustrumTest(PFrustrum *, float *, float, float) {
    *(int *)((char *)this + 0xA4) = 1;
}

// DRAFT: 0x001CC110 RenderQuadrant__13PParticleRainFUi
// note: 14 words differ; this+0x140 is folded into the load offset (original keeps the 0x140 pointer in a register), the a3=1 and float-constant lui/mtc1 are scheduled after the loads, and gGfxEng lui/addiu order differs.
void PParticleRain::RenderQuadrant(unsigned int nIndex) {
    unsigned int nOff = nIndex * 0x50;
    unsigned int nStart = *(unsigned int *)((char *)this + 0x140 + nOff);
    void *pBuf = m_unk248;
    unsigned int nCount = *(unsigned int *)((char *)this + 0x148 + nOff);
    DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(gGfxEng, (char *)pBuf + (nStart << 5), nCount, 0.0f, 128.0f, 1);
}

// DRAFT: 0x001CC160 AnimateQuadrant__13PParticleRainFUi
// note: 141 words differ, prologue register choice (original keeps nOff in t0 and computes pVel early, ours keeps nOff in v1); pBase, pVel-first and loop-entry forms tried; the loop's pre-test beqz differs.
void PParticleRain::AnimateQuadrant(unsigned int nIndex) {
    unsigned int nOff = nIndex * 0x50;
    char *pBase = (char *)this + 0x140;
    PRainQuadrant *pQuad = (PRainQuadrant *)(pBase + nOff);
    float *pBox = (float *)((char *)this + nOff + 0x100);
    unsigned int i = pQuad->m_unk00;
    unsigned int nEnd = i + pQuad->m_unk08;
    float *pVel = (float *)m_unkE0;
    float fScale;
    int sb;
    float *pPos;

    for (; i < nEnd; i++) {
        pPos = (float *)&m_pParts[i];
        PR_STEP();
        fScale = 1.0f + 2.0f * PR_RND();
        asm {
            lqc2 vf1, 0x0(pVel)
            lqc2 vf2, 0x0(pPos)
            vmove.xyzw vf5, vf2
        }
        asm { mfc1 sb, fScale }
        asm {
            qmtc2.i sb, vf3
            vmulx.xyz vf4, vf1, vf3x
            vnop
            vnop
            vnop
            vadd.xyz vf5, vf4, vf2
            vnop
            vnop
            vnop
            sqc2 vf5, 0x0(pPos)
        }
        if (pPos[1] < pBox[9]) {
            float fLo = pBox[8];
            PR_STEP();
            pPos[0] = fLo + (pBox[12] - fLo) * PR_RND();
            pPos[1] = pBox[13];
            fLo = pBox[10];
            PR_STEP();
            pPos[2] = fLo + (pBox[14] - fLo) * PR_RND();
        } else if (!(pPos[1] <= pBox[13])) {
            float fLo = pBox[8];
            PR_STEP();
            pPos[0] = fLo + (pBox[12] - fLo) * PR_RND();
            pPos[1] = pBox[13];
            fLo = pBox[10];
            PR_STEP();
            pPos[2] = fLo + (pBox[14] - fLo) * PR_RND();
        }
    }
}

// DRAFT: 0x001CC3B0 InitParticles__13PParticleRainFv
// note: order matches; FP and saved-register numbering differ (constant in f0 and box pointers in s3..s5 in the original). Tried macro, inline RNG, hi/lo/range temporaries.
void PParticleRain::InitParticles() {
    unsigned int q;
    for (q = 0; q < 4; q++) {
        PRainBox *pBox = (PRainBox *)((char *)this + q * 0x50);
        float &fMaxZ = pBox->m_fMax[2];
        float &fMinZ = pBox->m_fMin[2];
        FastMath_Fabs(fMaxZ - fMinZ);
        unsigned int i;
        for (i = pBox->m_nStart; i < pBox->m_nEnd; i++) {
            float fHi = pBox->m_fMax[0];
            float fLo = pBox->m_fMin[0];
            float fRange = fHi - fLo;
            PR_STEP();
            m_pParts[i].m_fPos[0] = fLo + fRange * PR_RND();
            m_pParts[i].m_fPos[1] = pBox->m_fMax[1];
            fHi = fMaxZ;
            fLo = fMinZ;
            fRange = fHi - fLo;
            PR_STEP();
            m_pParts[i].m_fPos[2] = fLo + fRange * PR_RND();
            fHi = ((float *)m_unkE0)[6];
            fLo = ((float *)m_unkE0)[5];
            fRange = fHi - fLo;
            PR_STEP();
            m_pParts[i].m_fPos[3] = fLo + fRange * PR_RND();
            m_pParts[i].m_fVel[0] = ((float *)m_unkE0)[0];
            m_pParts[i].m_fVel[1] = ((float *)m_unkE0)[1];
            m_pParts[i].m_fVel[2] = ((float *)m_unkE0)[2];
            PR_STEP();
            m_pParts[i].m_fVel[3] = 0.3f + 0.14999998f * PR_RND();
        }
    }
}

// DRAFT: 0x001CC5F0 SetNumRainParticles__13PParticleRainFUi
// note: 7 words differ, all in the loop: ours keeps the stride offset in t0 and nMax in a3, original keeps offset in a3 and nMax in t0 (declaration order and loop forms tried).
void PParticleRain::SetNumRainParticles(unsigned int nNum) {
    unsigned int nRem;
    unsigned int k;
    unsigned int nMax;

    nNum = (nNum < 4) ? 4 : nNum;
    if (nNum > 0x28) {
        nRem = nNum % 0x28;
        if (nRem != 0 && nRem < 4) {
            nNum += 4 - nRem;
        }
    }
    for (k = 0; k < 4; k++) {
        nMax = m_unk04 >> 2;
        *(unsigned int *)(m_unk100 + 0x48 + k * 0x50) = (nNum < nMax) ? nNum : nMax;
    }
}

// FUNCTION: 0x001CC680 SetLightningDensity__13PParticleRainFf
void PParticleRain::SetLightningDensity(float fDensity) {
    int nBase;
    float fLo;
    float fHi;
    float fScaled;
    float fRand;
    float fDiff;

    m_unk260 = (unsigned int)fDensity;
    if (m_unk260 != 0) {
        nBase = (unsigned int)(2100.0f - (1800.0f * (fDensity / 100.0f)));
        m_unk264 = nBase - 0xF0;
        m_unk268 = nBase + 0xF0;
        fHi = (float)(unsigned int)m_unk268;
        fLo = (float)(unsigned int)m_unk264;
        m_unkD0 = (m_unkD0 * 0x343FD) + 0x269EC3;
        fRand = 0.000030517578f * (float)(((int)m_unkD0 >> 0x10) & 0x7FFF);
        fDiff = fHi - fLo;
        fScaled = fLo + (fDiff * fRand);
        m_unk26C = (unsigned int)fScaled;
    }
}

// DRAFT: 0x001CC850 SetDensity__13PParticleRainFfb
// note: 23 words differ; the zero clamp is laid out before the 1.0 body and the inner empty then-branch has no second jump (sd_a to sd_i: ternary, single if, outer-first and fMin-else forms; best 23).
void PParticleRain::SetDensity(float fDensity, bool bFlag) {
    float fMin = 1.0f;

    if (fDensity < 1.0f) {
        fMin = fDensity;
    }
    if (!(fMin <= 0.0f)) {
        if (fDensity < 1.0f) {
        } else {
            fDensity = 1.0f;
        }
    } else {
        fDensity = 0.0f;
    }
    if (bFlag) {
        m_unk254 = fDensity;
        m_unk258 = (fDensity - m_unk250) / 600.0f;
    } else {
        m_unk254 = fDensity;
        m_unk250 = fDensity;
        m_unk258 = 0.0f;
    }
}

// FUNCTION: 0x001CC900 SetCameraPosRot__13PParticleRainFPA4_fPA4_f
void PParticleRain::SetCameraPosRot(float (*arg0)[4], float (*arg1)[4]) {
    float mat[4][4];
    float fAngle;
    unsigned int i;
    unsigned int off;

    sceVu0UnitMatrix(&mat[0][0]);
    ((PMat4 *)mat)->Translate(arg0[0][0], arg0[0][1], arg0[0][2]);
    i = 0;
    off = 0;
    do {
        char *p = (char *)this + off;
        ((PMat4 *)mat)->MulVector((float *)(p + 0x120), (float *)(p + 0x100));
        ((PMat4 *)mat)->MulVector((float *)(p + 0x130), (float *)(p + 0x110));
        i += 1;
        off += 0x50;
    } while (i < 4);
    fAngle = 180.0f + arg1[0][1];
    if (!(fAngle <= 45.0f)) {
        if (fAngle <= 135.0f) {
            m_unk240 = 0;
            m_unk244 = 2;
            return;
        }
    }
    if (!(fAngle <= 135.0f)) {
        if (fAngle <= 225.0f) {
            m_unk240 = 2;
            m_unk244 = 3;
            return;
        }
    }
    if (!(fAngle <= 225.0f)) {
        if (fAngle <= 315.0f) {
            m_unk240 = 1;
            m_unk244 = 3;
            return;
        }
    }
    if (!(fAngle <= 315.0f) || (fAngle <= 45.0f)) {
        m_unk240 = 0;
        m_unk244 = 1;
    }
}

// FUNCTION: 0x001CCAD0 Render__13PParticleRainFv
void PParticleRain::Render() {
    if (!m_unk15 || !m_unk14) {
        return;
    }
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (char *)this + 0x40);
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, (float *)((char *)this + 0xC0), true, m_unk30, 0x50000);
    BeginFxLines__10PGfxEngineFv(gGfxEng);
    RenderQuadrant(m_unk240);
    RenderQuadrant(m_unk244);
    EndFxLines__10PGfxEngineFv(gGfxEng);
    m_unk270.Render();
}

// DRAFT: 0x001CCB80 Animate__13PParticleRainFf
// note: 277 words differ, size 0x4E4 vs 0x524; unsigned-to-float second cvt.s.w in f2 (original f3), lightning ladder compares c.lt.s where original has c.le.s, constant lui/ori hoisting and LCG mult/addu placement differ.
void PParticleRain::Animate(float fDt)
{
    if (fDt != 0.0f) {
        m_unkD0 = m_unk24C;
        if (m_unk25C != 0 && m_unk260 != 0) {
            m_unk26C -= 1;
            if (m_unk26C == 0) {
                float fHi = (float)(unsigned int)m_unk268;
                float fLo = (float)(unsigned int)m_unk264;
                PR_STEP();
                float fRnd = fLo + (fHi - fLo) * PR_RND();
                if (!(fRnd >= 2.1474836e9f)) {
                    m_unk26C = (int)fRnd;
                } else {
                    m_unk26C = (int)(fRnd - 2.1474836e9f) | 0x80000000;
                }
                PR_STEP();
                int nSeed = m_unkD0;
                PR_STEP();
                float fLevel = 2.0f + (2.0f * (0.000030517578f * (float)((nSeed >> 16) & 0x7FFF)));
                int nFlash;
                if (!(fLevel >= 2.1474836e9f)) {
                    nFlash = (int)fLevel;
                } else {
                    nFlash = (int)(fLevel - 2.1474836e9f) | 0x80000000;
                }
                Init__12PFlashScreenFffffUiUiUii((void *)m_unk25C, 200.0f, 200.0f, 255.0f, 75.0f + (40.0f * PR_RND()), 2U, 6U, (unsigned int)nFlash, 0x4E3B);
            }
        }
        float fCur = m_unk250;
        if (m_unk254 != fCur) {
            float fNew = fCur + m_unk258;
            m_unk250 = fNew;
            if (fNew <= 0.0f) {
                m_unk250 = 0.0f;
            } else if (fNew >= 1.0f) {
                m_unk250 = 1.0f;
            }
        }
        float fScaled = 0.5f + (((float)(unsigned int)m_unk04 / 4.0f) * m_unk250);
        int nNum;
        if (!(fScaled >= 2.1474836e9f)) {
            nNum = (int)fScaled;
        } else {
            nNum = (int)(fScaled - 2.1474836e9f) | 0x80000000;
        }
        SetNumRainParticles((unsigned int)nNum);
        if (m_unk250 != 0.0f) {
            if (m_unk2B0 == 0) {
                m_unk2B0 = gSound.PlaySoundUbiquitous(0x159);
            }
        } else {
            if (m_unk2B0 != 0) {
                gSound.StopSoundBySoundRef(m_unk2B0);
                m_unk2B0 = 0;
            }
        }
        m_unk15 = (nNum != 0);
        if (m_unk15 != 0) {
            AnimateQuadrant(m_unk240);
            AnimateQuadrant(m_unk244);
            if (!(m_unk250 <= 0.25f)) {
                void *pPlayer = *(void **)mPlayerAPI__13EntityManager;
                if (pPlayer != 0 && *(int *)((char *)pPlayer + 0x38) != 0) {
                    u_long128 sp40;
                    GetGroundPos__7PhysicsFv(&sp40);
                    float vPos[4];
                    *(u_long128 *)vPos = sp40;
                    vPos[0] += -15.0f + (30.0f * ((float)rand() / 2.1474836e9f));
                    vPos[2] += -15.0f + (30.0f * ((float)rand() / 2.1474836e9f));
                    vPos[1] += 5.0f;
                    if (GetGroundPos__11BGCollisionFPA4_f(mBGCollision__15EntityBaseClass, &vPos) != 0) {
                        m_unk270.Splatter(vPos);
                    }
                }
            }
            m_unk270.Animate(1.0f);
        }
    }
}

struct tagParticleRainParams {
    char _pad00[0x10];
    int m_nCount;               // 0x10 particle count
    char _pad14[0xC];
};

// FUNCTION: 0x001CD0B0 Create__13PParticleRainFP21tagParticleRainParamsPA4_fPA4_fP12PFlashScreen
#define PR_INT(off) (*(int *)((char *)this + (off)))
#define PR_UINT(off) (*(unsigned int *)((char *)this + (off)))
#define PR_FLT(off) (*(float *)((char *)this + (off)))
int PParticleRain::Create(tagParticleRainParams *arg0, float (*arg1)[4], float (*arg2)[4], PFlashScreen *arg3) {
    m_unk0C = 8;
    m_unk30 = 0x44;
    m_unk04 = arg0->m_nCount * 4;
    m_unk14 = 1;
    m_unk248 = __nwa__FUi(m_unk04 << 5);
    if (m_unk248 == 0) {
        Cleanup();
        return 0;
    }
    memcpy(m_unkE0, arg0, 0x20);
    PR_INT(0x100) = 0;
    PR_INT(0x104) = 0xC1480000;
    PR_INT(0x108) = 0;
    PR_INT(0x10C) = 0x3F800000;
    PR_FLT(0x110) = m_unkFC;
    PR_INT(0x114) = 0x41C80000;
    PR_FLT(0x118) = m_unkFC;
    PR_INT(0x11C) = 0x3F800000;
    PR_INT(0x140) = 0;
    PR_UINT(0x144) = m_unk04 >> 2;
    PR_INT(0x148) = arg0->m_nCount;
    PR_FLT(0x150) = -m_unkFC;
    PR_INT(0x154) = 0xC1480000;
    PR_INT(0x158) = 0;
    PR_INT(0x15C) = 0x3F800000;
    PR_INT(0x160) = 0;
    PR_INT(0x164) = 0x41C80000;
    PR_FLT(0x168) = m_unkFC;
    PR_INT(0x16C) = 0x3F800000;
    PR_UINT(0x190) = PR_UINT(0x144);
    PR_INT(0x194) = PR_INT(0x190) + (int)arg0->m_nCount;
    PR_INT(0x198) = arg0->m_nCount;
    PR_INT(0x1A0) = 0;
    PR_INT(0x1A4) = 0xC1480000;
    PR_FLT(0x1A8) = -m_unkFC;
    PR_INT(0x1AC) = 0x3F800000;
    PR_FLT(0x1B0) = m_unkFC;
    PR_INT(0x1B4) = 0x41C80000;
    PR_INT(0x1B8) = 0;
    PR_INT(0x1BC) = 0x3F800000;
    PR_INT(0x1E0) = PR_INT(0x194);
    PR_INT(0x1E4) = PR_INT(0x1E0) + (int)arg0->m_nCount;
    PR_INT(0x1E8) = arg0->m_nCount;
    PR_FLT(0x1F0) = -m_unkFC;
    PR_INT(0x1F4) = 0xC1480000;
    PR_FLT(0x1F8) = -m_unkFC;
    PR_INT(0x1FC) = 0x3F800000;
    PR_INT(0x200) = 0;
    PR_INT(0x204) = 0x41C80000;
    PR_INT(0x208) = 0;
    PR_INT(0x20C) = 0x3F800000;
    PR_INT(0x230) = PR_INT(0x1E4);
    PR_INT(0x234) = PR_INT(0x230) + (int)arg0->m_nCount;
    PR_INT(0x238) = arg0->m_nCount;
    PR_INT(0xA0) = 0;
    SetCameraPosRot(arg1, arg2);
    InitParticles();
    PR_INT(0x24C) = (int)(0.5f + (46352.0f + (38180.0f * ((float)rand() / 2.1474836e9f))));
    SetDensity(1.0f, false);
    PR_INT(0x25C) = (int)arg3;
    {
        float vec[4] = {90.0f, 90.0f, 90.0f, 80.0f};
        m_unk270.Create(0x1E, vec);
    }
    PR_INT(0x2A0) = GetFxTexture__16PParticleManagerFUi(gGfxEng + 0x154F00, 0x84000003U);
    return 1;
}
#undef PR_INT
#undef PR_UINT
#undef PR_FLT

// FUNCTION: 0x001CD360 __dt__13PParticleRainFv
PParticleRain::~PParticleRain() {
    *(void **)this = __vt__13PParticleRain;
    if (m_unk248 != 0) {
        __dla__FPv(m_unk248);
        m_unk248 = 0;
    }
    if (m_unk2B0 != 0) {
        gSound.StopSoundBySoundRef(m_unk2B0);
        m_unk2B0 = 0;
    }
}

// FUNCTION: 0x001CD410 __ct__13PParticleRainFv
PParticleRain::PParticleRain() : PParticleSystem() {
    *(void **)this = __vt__13PParticleRain;
    __ct__13PRainSplatterFv(&m_unk270);
    memset(m_unkE0, 0, 0x20);
    memset(m_unk100, 0, 0x140);
    m_unk240 = 0;
    m_unk244 = 0;
    m_unk248 = 0;
    m_unk25C = 0;
    SetLightningDensity(0.0f);
    m_unk2B0 = 0;
}
