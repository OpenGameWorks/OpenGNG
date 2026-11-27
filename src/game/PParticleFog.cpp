// FLAGS: -str readonly
#include "types.h"
#include "PParticleFog.h"

// TODO(header): foreign declarations
class PFrustrum;
class PMat4;
extern "C" void __dla__FPv(void *pBlock);
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, PMat4 *pMat);
extern "C" void BeginFogParticles__10PGfxEngineF13eBoxIntersect(void *pThis, int eBox);
extern "C" void DrawFogParticles__10PGfxEngineFPA4_fifffPf(void *pThis, float (*pParticles)[4], int nCount, float fA, float fB, float fC, float *pVec);
extern "C" void EndFogParticles__10PGfxEngineFv(void *pThis);
extern "C" int IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(void *pThis, float (*pBox)[2][4], PMat4 *pMat);
extern "C" void MulVector__5PMat4FPfPf(void *pThis, float *pA, float *pB);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pA);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pA, float fScale);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" int rand(void);

// DRAFT: 0x001BDDA0 FrustrumTest__12PParticleFogFP9PFrustrumPfffP5PMat4
// note: 60 words differ; register map is the cause (original saves pPos in s2, pMat in s1, this in s0; ours this=s2, pPos=s1, pMat=s0). Flipping the fDist arm to test fDist > fFar first gave 60 (was 64); pFrustum-first, ternary pMat, and !(fDist<=fFar) variants gave 60-92.
void PParticleFog::FrustrumTest(PFrustrum *pFrustum, float *pPos, float fNear, float fFar, PMat4 *pMat) {
    if (pFrustum != 0) {
        float vec[4];
        if (pMat != 0) {
            m_unk50 = IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(pFrustum, &m_unk30, pMat);
        } else {
            m_unk50 = IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(pFrustum, &m_unk30, (PMat4 *)gUnitMatrix);
        }
        if (m_unk50 != 0) {
            if (pMat != 0) {
                MulVector__5PMat4FPfPf(pMat, vec, m_unk30[0]);
            } else {
                MulVector__5PMat4FPfPf((PMat4 *)gUnitMatrix, vec, m_unk30[0]);
            }
            sceVu0SubVector(vec, pPos, vec);
            float fDist = vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
            if (fDist > fFar) {
                float fAlpha = 1.0f - ((fDist - fFar) / (fNear - fFar));
                m_unk20 = fAlpha;
                if (fAlpha <= 0.0f) {
                    fAlpha = 0.0f;
                } else if (!(fAlpha < 1.0f)) {
                    fAlpha = 1.0f;
                }
                m_unk20 = fAlpha;
                if (fAlpha == 0.0f) {
                    m_unk50 = 0;
                }
            } else {
                m_unk20 = 1.0f;
            }
        }
    }
}

// FUNCTION: 0x001BDF40 Render__12PParticleFogFP5PMat4
void PParticleFog::Render(PMat4 *pMat) {
    if (m_unk50 != 0) {
        float vec[4] = {1.0f, 1.0f, 1.0f, 1.0f};
        vec[3] = m_unk20;
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk54, vec, true, *(unsigned long *)((char *)this + 0x58), 0x50000);
        if (pMat != 0) {
            SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, pMat);
        } else {
            SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)gUnitMatrix);
        }
        BeginFogParticles__10PGfxEngineF13eBoxIntersect(gGfxEng, m_unk50);
        DrawFogParticles__10PGfxEngineFPA4_fifffPf(gGfxEng, m_unk00, (unsigned int)m_unk04, m_unk08, m_unk0C, 1.5f, m_unk10);
        EndFogParticles__10PGfxEngineFv(gGfxEng);
    }
}

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("PParticleFog.cpp", line, #cond))

// DRAFT: 0x001BE020 Create__12PParticleFogFP18tagParticleFogDatai
// note: 379 words differ, size 0x694 vs 0x6C0; the inline sqrt.s before Normalize (sqrtf + scale form gave 404 words), the count-clamp float order and the missing 0x2C bytes are unresolved.
int PParticleFog::Create(tagParticleFogData *pData, int nMode) {
    CDS_ASSERT(0x2D, pData);
    long long tab[5] = {0, 0x44, 0x48, 0x800000A1LL, 0x46};
    float fCountX = 0.5f + ((2.0f * pData->unk10) / (1.5f * pData->unk34));
    if (fCountX <= 1.0f) {
        fCountX = 1.0f;
    }
    float fCountY = 0.5f + ((2.0f * pData->unk14) / (1.5f * pData->unk38));
    if (fCountY <= 1.0f) {
        fCountY = 1.0f;
    }
    float fCountZ = 0.5f + ((2.0f * pData->unk18) / (1.5f * pData->unk34));
    if (fCountZ <= 1.0f) {
        fCountZ = 1.0f;
    }
    unsigned int nX = (unsigned int)fCountX;
    unsigned int nY = (unsigned int)fCountY;
    unsigned int nZ = (unsigned int)fCountZ;
    unsigned int nCount = nZ * (nX * nY);
    if (nCount < 0x10U) {
        nCount = 0xF;
    }
    m_unk04 = nCount;

    unsigned int nLimit = pData->unk40;
    if (nLimit != 0) {
        m_unk04 = (nLimit >= (unsigned int)m_unk04) ? m_unk04 : (int)nLimit;
    } else {
        if ((unsigned int)m_unk04 >= 0x3D1U) {
            m_unk04 = 0x3D0;
        }
    }

    m_unk00 = (float (*)[4])__nwa__FUi(m_unk04 * 0x10);
    if (m_unk00 == 0) {
        return 0;
    }

    float fH = pData->unk1C;
    float fSize = 128.0f * (0.5f * pData->unk30);
    float fH2 = fH * fH;

    float minX = pData->unk0 - pData->unk10;
    float maxX = pData->unk0 + pData->unk10;
    float minY = pData->unk4 - pData->unk14;
    float maxY = pData->unk4 + pData->unk14;
    float minZ = pData->unk8 - pData->unk14;
    float maxZ = pData->unk8 + pData->unk18;

    float vSeed[4];
    if (pData->unk44 != 0) {
        vSeed[0] = minX + ((maxX - minX) * ((float)rand() / 2.1474836e9f));
        vSeed[1] = minY + ((maxY - minY) * ((float)rand() / 2.1474836e9f));
        vSeed[2] = minZ + ((maxZ - minZ) * ((float)rand() / 2.1474836e9f));
    }

    unsigned int i;
    for (i = 0; i < (unsigned int)m_unk04; i++) {
        m_unk00[i][0] = minX + ((maxX - minX) * ((float)rand() / 2.1474836e9f));
        m_unk00[i][1] = minY + ((maxY - minY) * ((float)rand() / 2.1474836e9f));
        m_unk00[i][2] = minZ + ((maxZ - minZ) * ((float)rand() / 2.1474836e9f));
        if (pData->unk44 != 0) {
            float fN = (float)(unsigned int)m_unk04;
            float fI = (float)i;
            float vDir[4];
            sceVu0SubVector(vDir, vSeed, m_unk00[i]);
            sceVu0InnerProduct(vDir, vDir);
            sceVu0Normalize(vDir, vDir);
            sceVu0ScaleVectorXYZ(vDir, vDir, fH * (fI / fN));
            sceVu0AddVector(m_unk00[i], m_unk00[i], vDir);
        }
        float dx = m_unk00[i][0] - pData->unk0;
        float dy = m_unk00[i][1] - pData->unk4;
        float dz = m_unk00[i][2] - pData->unk8;
        float fVal = fSize * (1.0f - ((dx * dx + dy * dy + dz * dz) / fH2));
        float fClamp = 64.0f;
        if (fVal < 64.0f) {
            fClamp = fVal;
        }
        if (fClamp <= 3.0f) {
            fVal = 3.0f;
        } else if (!(fVal < 64.0f)) {
            fVal = 64.0f;
        }
        m_unk00[i][3] = fVal;
    }

    m_unk08 = pData->unk34;
    m_unk0C = pData->unk38;
    *(u_long128 *)m_unk10 = pData->unk20;
    m_unk58 = tab[pData->unk3C];
    m_unk54 = nMode;
    m_unk20 = 1.0f;
    *(u_long128 *)&m_unk30[0][0] = *(u_long128 *)&pData->unk0;
    *(u_long128 *)&m_unk30[1][0] = *(u_long128 *)&pData->unk10;
    return 1;
}

// FUNCTION: 0x001BE6E0 __dt__12PParticleFogFv
PParticleFog::~PParticleFog() {
    if (m_unk00) {
        __dla__FPv(m_unk00);
        m_unk00 = 0;
    }
    m_unk04 = 0;
}

// FUNCTION: 0x001BE750 __ct__12PParticleFogFv
PParticleFog::PParticleFog() {
    m_unk00 = 0;
    m_unk04 = 0;
    m_unk54 = 0;
    m_unk50 = 1;
}
