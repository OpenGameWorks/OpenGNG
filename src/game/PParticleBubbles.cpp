// FLAGS: -str readonly
#include "types.h"
#include "PParticleBubbles.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" int rand();
extern "C" float sqrtf(float x);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
extern "C" void *GetResource__16PParticleManagerFUi(void *pThis, unsigned int nId);
extern char gGfxEng[1504384];
extern unsigned char __vt__16PParticleBubbles[];
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, float *pMat);
extern "C" void Render__7PShaderFibPb(void *pThis, int nArg, bool bFlag, bool *pbOut);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *pThis, void *pData, int nSize, bool bFlag);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *pThis, void *pData, int nCount, bool bFlag);
extern "C" void FastMath_ComputeMatrixLite__FPA4_A4_fPA4_fPA4_fPA4_fPA4_A4_f(void *pOut, void *pA, void *pB, void *pC, int nFlag);
extern float gUnitMatrix[16];

// DRAFT: 0x002020E0 Render__16PParticleBubblesFv
// note: DIFF 156 words, size 0x2a0 vs 0x2b8: nBatches magic-divide order, spill at 0xA0 and vConst copy from 0x4D18B0 (zero-fill, value guessed) differ; tried vConst before/after nBatches (172/158), signed counters (172), hoisted k-loop bounds (156).
void PParticleBubbles::Render() {
    static float sRenderConst[4];
    if (m_unk15 == 0) {
        return;
    }
    if (m_unkA4 == 0) {
        return;
    }
    float vPos[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    u_long128 vConst = *(u_long128 *)sRenderConst;
    int nBatches = m_unk04 / 80;
    if (m_unk04 % 80) {
        nBatches++;
    }
    if (m_unk168 != 0) {
        ((float *)&vConst)[1] = -*(float *)&m_unk114;
    }
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng + 0x6680, gUnitMatrix);
    Render__7PShaderFibPb(*(void **)m_unk184, 0x80, true, 0);
    if (nBatches > 0) {
        unsigned int nRemain = m_unk04;
        int nBubbleOff = 0;
        for (int fp = 0; fp < nBatches; fp++) {
            unsigned int nCount = (nRemain < 0x50) ? nRemain : 0x50;
            nRemain -= nCount;
            ((nCount * 0x60 < 0x2000) ? (void)0 : CdsAssert__FPciPc("PParticleBubbles.cpp", 0xC3, "aiNumBubblesPerBatch * sizeof(VuFxInstance) < SPAD_TEMP_BUFFER_SIZE"));
            int nScratch = 0;
            if (nCount > 0) {
                for (unsigned int i = 0; i < nCount; i++) {
                    tagBubble *pBubble = (tagBubble *)((char *)m_unk188 + nBubbleOff);
                    vPos[0] = pBubble->m_unk24;
                    vPos[1] = pBubble->m_unk24;
                    vPos[2] = pBubble->m_unk24;
                    FastMath_ComputeMatrixLite__FPA4_A4_fPA4_fPA4_fPA4_fPA4_A4_f((void *)(0x70001000 + nScratch), vPos, &vConst, pBubble, 0);
                    *(u_long128 *)((char *)0x70001000 + nScratch + 0x40) = *(u_long128 *)m_unk140;
                    nScratch += 0x60;
                    nBubbleOff += 0x30;
                }
            }
            int nCnt = *(int *)(m_unk184 + 8);
            char *pArr = *(char **)(m_unk184 + 0xC);
            for (int k = 0; k < nCnt; k++) {
                int w0 = (k < nCnt) ? *(int *)(pArr + k * 8) : 0;
                int w4 = (k < nCnt) ? *(int *)(pArr + k * 8 + 4) : 0;
                BeginFxInstances__10PGfxEngineFPvib(gGfxEng + 0x6680, (void *)w4, w0, false);
                DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)(gGfxEng + 0x15B300), (void *)0x70001000, nCount, true);
            }
        }
    }
}

// FUNCTION: 0x00202520 Create__16PParticleBubblesFP24tagParticleBubblesParamsfff
int PParticleBubbles::Create(tagParticleBubblesParams *pParams, float fX, float fY, float fZ) {
    ((pParams != 0) ? (void)0 : CdsAssert__FPciPc("PParticleBubbles.cpp", 0x27, "pParams"));
    if (PParticleSystem::Create(pParams->m_unk30, 0) == 0) {
        return 0;
    }
    memcpy(m_unk120, pParams, 0x60);
    m_unk120[0] += fX;
    m_unk120[1] += fY;
    m_unk120[2] += fZ;
    sceVu0ScaleVectorXYZ(m_unk140, m_unk140, 0.003921569f);
    m_unk140[3] = 0.0078125f * m_unk140[3];
    sceVu0SubVector((float *)&m_unkE0, m_unk120, m_unk130);
    sceVu0AddVector(m_unkF0, m_unk120, m_unk130);
    m_unk188 = (tagBubble *)__nwa__FUi(m_unk04 * 0x30);
    if (m_unk188 == 0) {
        return 0;
    }
    for (unsigned int i = 0; i < m_unk04; i++) {
        tagBubble *pBubble = (tagBubble *)((char *)m_unk188 + i * 0x30);
        sceVu0CopyVector((float *)pBubble, m_unk120);
        pBubble->m_unk24 = 0.0f;
        pBubble->m_unk20 = 0.0f;
        pBubble->m_unk28 = (float)(unsigned int)(m_unk04 * 0x14);
        pBubble->m_unk1C = 0;
    }
    m_unk0C = 0x18;
    sceVu0CopyVector((float *)&m_unk80, m_unk120);
    sceVu0CopyVector((float *)&m_unk90, m_unk130);
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    m_unkD0 = (int)(0.5f + (41235.0f + (-5823.0f * ((float)rand() / 2147483648.0f))));
    m_unk184 = (int)GetResource__16PParticleManagerFUi(gGfxEng + 0x154F00, pParams->m_unk44);
    if (m_unk184 == 0) {
        return 0;
    }
    SpawnBubble(m_unk188);
    m_unk18C = 1;
    m_unk190 = 0x14;
    return 1;
}

// FUNCTION: 0x002023A0 Animate__16PParticleBubblesFf
void PParticleBubbles::Animate(float fDelta) {
    if (m_unk15 == 0 || m_unk16 != 0) {
        return;
    }
    if (m_unk18C < m_unk04 && fDelta) {
        m_unk190 -= 1;
        if (m_unk190 <= 0) {
            SpawnBubble(m_unk188 + m_unk18C);
            m_unk18C += 1;
            m_unk190 = 0x14;
        }
    }
    unsigned int nAlive = m_unk04;
    unsigned int i = 0;
    int offset = 0;
    while (i < m_unk04) {
        tagBubble *pBubble = (tagBubble *)((char *)m_unk188 + offset);
        pBubble->m_unk24 += fDelta * pBubble->m_unk20;
        float fLife = pBubble->m_unk28 - fDelta;
        pBubble->m_unk28 = fLife;
        if (fLife <= 0.0f && m_unk18 != 0) {
            nAlive -= 1;
            if ((int)nAlive <= 0) {
                m_unk16 = m_unk17;
            }
            if (m_unk18 != 0) {
                SpawnBubble(pBubble);
            } else {
                pBubble->m_unk24 = 0.0f;
            }
        }
        offset += 0x30;
        i += 1;
    }
}

// FUNCTION: 0x002027E0 __dt__16PParticleBubblesFv
extern "C" void *__dt__16PParticleBubblesFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleBubbles *pSelf = (PParticleBubbles *)pThis;
        *(void **)pThis = __vt__16PParticleBubbles;
        pSelf->m_unk184 = 0;
        if (pSelf->m_unk188 != 0) {
            __dla__FPv(pSelf->m_unk188);
            pSelf->m_unk188 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00202860 __ct__16PParticleBubblesFv
PParticleBubbles::PParticleBubbles() {
    *(void **)this = __vt__16PParticleBubbles;
    memset(m_unk120, 0, 0x60);
    m_unk184 = 0;
    m_unk188 = 0;
    m_unk118 = 0;
    m_unk114 = 0;
    m_unk110 = 0;
    m_unk11C = 1.0f;
    m_unk108 = 0;
    m_unk104 = 0;
    m_unk100 = 0;
    m_unk10C = 1.0f;
}
