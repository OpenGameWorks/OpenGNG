#include "types.h"
#include "Debug.h"
#include "PParticleElectricity.h"
#include "PRandom.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, int nCount, int nSize);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__20PParticleElectricity[];
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" float sqrtf(float x);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int rand();
extern char gGfxEng[1504384];
struct tagVuFxLine;
struct tagVuParticle;
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, PMat4 *pMat);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void BeginFxLines__10PGfxEngineFv(void *pThis);
extern "C" void DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(void *pThis, tagVuFxLine *pLines, int nCount, float fA, float fB, bool bFlag);
extern "C" void EndFxLines__10PGfxEngineFv(void *pThis);
extern "C" void BeginParticles__10PGfxEngineF13eBoxIntersect(void *pThis, int eBox);
extern "C" void DrawParticles__10PGfxEngineFP13tagVuParticleiffb(void *pThis, tagVuParticle *pParticles, int nCount, float fA, float fB, bool bFlag);
extern "C" void EndParticles__10PGfxEngineFv(void *pThis);

// DRAFT: 0x001F46B0 CreateBranch__20PParticleElectricityFPQ220PParticleElectricity20tagElectricityBranch
// note: 119 words; loop-setup registers differ (orig i=a0 off=a1, ours i=v1 off=a0), orig hoists m_unk188 load into f7; tried inline jitter (121), off declared before i (119)
void PParticleElectricity::CreateBranch(tagElectricityBranch *pBranch) {
    void *pBuf = AllocParticles__12PDisplayListFii(*(void **)&gGfxEng[0x154C80], pBranch->m_unk34, 2);
    if (pBuf == 0) {
        CdsAssert("PParticleElectricity.cpp", 0xEB, "apVuParticles");
    }
    pBranch->m_unk00 = pBuf;
    float fSeg = pBranch->m_unk30 / (float)pBranch->m_unk34;
    float *pHead = (float *)pBuf;
    pHead[0] = pBranch->m_unk10;
    pHead[1] = pBranch->m_unk14;
    pHead[2] = pBranch->m_unk18;
    pHead[3] = fSeg;
    pHead[7] = 1.0f;
    for (unsigned int i = 1, off = 0x20; i < pBranch->m_unk34; i++, off += 0x20) {
        float *pDst = (float *)((char *)pBuf + off);
        float t = (float)i * fSeg;
        float fDx = pBranch->m_unk20 * t;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        float r = 3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF);
        float fJ2 = m_unk188 + m_unk188;
        float fJit = -m_unk188 + fJ2 * r;
        pDst[0] = (pBranch->m_unk10 + fDx) + fJit;

        float fDy = pBranch->m_unk24 * t;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r = 3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF);
        fJ2 = m_unk188 + m_unk188;
        fJit = -m_unk188 + fJ2 * r;
        pDst[1] = (pBranch->m_unk14 + fDy) + fJit;

        float fDz = pBranch->m_unk28 * t;
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        r = 3.0517578125e-5f * (float)((m_unkD0 >> 16) & 0x7FFF);
        fJ2 = m_unk188 + m_unk188;
        fJit = -m_unk188 + fJ2 * r;
        pDst[2] = (pBranch->m_unk18 + fDz) + fJit;
        pDst[7] = 1.0f;
    }
    float v[4];
    for (unsigned int i = 0, off = 0; i < pBranch->m_unk34 - 1; i++, off += 0x20) {
        float *pCur = (float *)((char *)pBuf + off);
        float *pNext = (float *)((char *)pBuf + ((i + 1) << 5));
        v[0] = pNext[0] - pCur[0];
        v[1] = pNext[1] - pCur[1];
        v[2] = pNext[2] - pCur[2];
        v[3] = 1.0f;
        float len = sqrtf(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        pCur[3] = len;
        sceVu0Normalize(v, v);
        pCur[4] = v[0];
        pCur[5] = v[1];
        pCur[6] = v[2];
    }
    float *pLast = (float *)((char *)pBuf + ((pBranch->m_unk34 - 1) << 5));
    v[0] = (pBranch->m_unk10 + pBranch->m_unk30 * pBranch->m_unk20) - pLast[0];
    v[1] = (pBranch->m_unk14 + pBranch->m_unk30 * pBranch->m_unk24) - pLast[1];
    v[2] = (pBranch->m_unk18 + pBranch->m_unk30 * pBranch->m_unk28) - pLast[2];
    sceVu0Normalize(v, v);
    pLast[4] = v[0];
    pLast[5] = v[1];
    pLast[6] = v[2];
    SetupGlowParticles(pBranch);
}

// FUNCTION: 0x001F4A80 SetupGlowParticles__20PParticleElectricityFPQ220PParticleElectricity20tagElectricityBranch
void PParticleElectricity::SetupGlowParticles(tagElectricityBranch *pBranch) {
    void *pBuf = AllocParticles__12PDisplayListFii(*(void **)&gGfxEng[0x154C80], m_unk04, 2);
    if (pBuf == 0) {
        CdsAssert("PParticleElectricity.cpp", 0xCA, "apVuParticles");
    }
    pBranch->m_unk04 = pBuf;
    for (unsigned int i = 0, off = 0; i < pBranch->m_unk34; i++, off += 0x20) {
        float *pSrc = (float *)((char *)pBranch->m_unk00 + off);
        float *pDst = (float *)((char *)pBuf + off);
        pDst[0] = pSrc[0];
        pDst[1] = pSrc[1];
        pDst[2] = pSrc[2];
        pDst[3] = m_unk134;
        pDst[4] = 128.0f;
        pDst[5] = 128.0f;
        pDst[6] = 128.0f;
        pDst[7] = 85.0f + 10.0f * ParticleRand01(m_unkD0);
    }
}

// DRAFT: 0x001F4BB0 Render__20PParticleElectricityFv
// note: 86 words; guard shape differs (orig bnez m14 + b to exit with ld ra in delay slot; ours beqz m14 direct, exit 3 words earlier); tried nested if, positive if, else-empty, early returns, combined && positive if
void PParticleElectricity::Render() {
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk14 == 0) {
        return;
    }
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)&m_unk40);
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, 0, &m_unkC0, true, m_unk30, 0x50000);
    BeginFxLines__10PGfxEngineFv(gGfxEng);
    for (int i = 0, off = 0; i < m_unk130; i++, off += 0x40) {
        char *pElem = (char *)m_unkE0 + off;
        DrawFxLines__10PGfxEngineFP11tagVuFxLineiffb(gGfxEng, *(tagVuFxLine **)pElem, *(int *)(pElem + 0x34), 128.0f, 128.0f, true);
    }
    EndFxLines__10PGfxEngineFv(gGfxEng);
    SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, &m_unkC0, true, m_unk30, 0x50000);
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (PMat4 *)&m_unk40);
    BeginParticles__10PGfxEngineF13eBoxIntersect(gGfxEng, m_unkA4);
    for (int i = 0, off = 0; i < m_unk130; i++, off += 0x40) {
        char *pElem = (char *)m_unkE0 + off;
        DrawParticles__10PGfxEngineFP13tagVuParticleiffb(gGfxEng, *(tagVuParticle **)(pElem + 4), *(int *)(pElem + 0x34), m_unkB8, m_unkBC, false);
    }
    EndParticles__10PGfxEngineFv(gGfxEng);
}

// DRAFT: 0x001F5230 Create__20PParticleElectricityFP28tagParticleElectricityParamsfff
// note: 68 words; early 0.5f/255.0f literals in f2/f3 swapped (orig f3=0.5f); late 0x118-0x128 v0/v1 order and 0xA0 store order differ; VU0 block loads fLen via lw not lwc1+mfc1; tail 0.5f constant loads after orig. Tried: pDir/fLen reorder (68), mean swap (68), 0.3f store moved after divides (91, reverted)
int PParticleElectricity::Create(tagParticleElectricityParams *pParams, float fA, float fB, float fC) {
    float tmp[4];
    float *pDir;
    float *pFrom;
    float *pTmp;
    float fLen;
    int nLenBits;

    memcpy(m_unkF0, pParams, 0x70);
    m_unk184 = 0x89A9;
    m_unkF0[0] += fA;
    m_unkF0[1] += fB;
    m_unkF0[2] += fC;
    m_unk14 = 1;
    m_unk30 = 0x48;
    m_unk04 = m_unk120;
    m_unk188 = 0.3f * m_unk128;
    m_unkC0 = m_unk110 / 255.0f;
    m_unkC4 = m_unk114 / 255.0f;
    m_unkC8 = m_unk118 / 255.0f;
    m_unkCC = m_unk11C / 128.0f;
    m_unkE0 = __nwa__FUi(m_unk130 << 6);
    if (m_unkE0 == 0) {
        CdsAssert("PParticleElectricity.cpp", 0x2F, "mpBranches");
    }
    memset(m_unkE0, 0, m_unk130 << 6);
    m_unk18C = 2;
    m_unkA0 = 1.0f;

    fLen = m_unk124;
    asm { mfc1 nLenBits, fLen }
    pDir = m_unk100;
    pFrom = m_unkF0;
    pTmp = tmp;
    asm {
        lqc2 vf1, 0x0(pDir)
        lqc2 vf2, 0x0(pFrom)
        qmtc2.i nLenBits, vf3
        vmulx.xyzw vf4, vf1, vf3x
        vnop
        vnop
        vnop
        vadd.xyzw vf5, vf4, vf2
        vnop
        vnop
        vnop
        sqc2 vf5, 0x0(pTmp)
    }

    m_unk80 = (tmp[0] + m_unkF0[0]) * 0.5f;
    m_unk84 = (tmp[1] + m_unkF0[1]) * 0.5f;
    m_unk88 = (tmp[2] + m_unkF0[2]) * 0.5f;
    *(float *)&m_unk8C = 1.0f;
    m_unk90 = m_unk124 * 0.5f;
    m_unk94 = m_unk124 * 0.5f;
    m_unk98 = m_unk124 * 0.5f;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001F4D30 SetPosition__20PParticleElectricityFPfPf
void PParticleElectricity::SetPosition(float *pFrom, float *pTo) {
    float vec[4];

    sceVu0CopyVector(m_unkF0, pFrom);
    sceVu0CopyVector(vec, pTo);
    sceVu0SubVector(m_unk100, vec, m_unkF0);
    m_unk124 = sqrtf(sceVu0InnerProduct(m_unk100, m_unk100));
    sceVu0Normalize(m_unk100, m_unk100);
    m_unk80 = (vec[0] + m_unkF0[0]) * 0.5f;
    m_unk84 = (vec[1] + m_unkF0[1]) * 0.5f;
    m_unk88 = (vec[2] + m_unkF0[2]) * 0.5f;
    *(float *)&m_unk8C = 1.0f;
    m_unk90 = m_unk124 * 0.5f;
    m_unk94 = m_unk124 * 0.5f;
    m_unk98 = m_unk124 * 0.5f;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
}

// DRAFT: 0x001F4E40 Animate__20PParticleElectricityFf
// note: 236 words, size 0x378 vs 0x3E8; loop shape and reloads differ; tried early-return restructure, m_unk34 clamp flip, per-access buffer reloads (238), none below 236
void PParticleElectricity::Animate(float fA) {
    if (m_unk15 != 0) {
        if (m_unk16 != 0) {
            return;
        }
        if (m_unk18 == 0 || m_unk17 != 0) {
            m_unk15 = 0;
            m_unk16 = m_unk17;
        }
        if (fA != 0.0f) {
            m_unk18C -= 1;
            if (m_unk18C <= 0) {
                m_unk184 = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
                m_unk18C = 2;
            }
        }
        m_unkD0 = m_unk184;
        sceVu0CopyVector(&((tagElectricityBranch *)m_unkE0)->m_unk10, m_unkF0);
        sceVu0CopyVector(&((tagElectricityBranch *)m_unkE0)->m_unk20, m_unk100);
        ((tagElectricityBranch *)m_unkE0)->m_unk30 = m_unk124;
        ((tagElectricityBranch *)m_unkE0)->m_unk34 = m_unk120;
        CreateBranch((tagElectricityBranch *)m_unkE0);

        int nBranch = 1;
        int nByte = 0x40;
        while (nBranch < m_unk130) {
            char *pBase = (char *)m_unkE0;
            float fCount = (float)(((tagElectricityBranch *)m_unkE0)->m_unk34 - 1);
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            int nIdx = (int)(1.0f + (fCount - 1.0f) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF))) << 5;
            tagElectricityBranch *pElem = (tagElectricityBranch *)(pBase + nByte);
            char *pSrc = (char *)((tagElectricityBranch *)m_unkE0)->m_unk00;
            pElem->m_unk10 = *(float *)(pSrc + nIdx);
            pElem->m_unk14 = *(float *)(pSrc + nIdx + 4);
            pElem->m_unk18 = *(float *)(pSrc + nIdx + 8);
            pElem->m_unk20 = m_unk100[0] + (-0.5f + 1.0f * ParticleRand01(m_unkD0));
            pElem->m_unk24 = m_unk100[1] + (-0.5f + 1.0f * ParticleRand01(m_unkD0));
            pElem->m_unk28 = m_unk100[2] + (-0.5f + 1.0f * ParticleRand01(m_unkD0));
            pElem->m_unk30 = m_unk124 * (0.15f + 0.099999994f * ParticleRand01(m_unkD0));
            unsigned int nCount = m_unk04 >> 2;
            if (nCount < 9U) {
                nCount = 8;
            }
            pElem->m_unk34 = nCount;
            CreateBranch(pElem);
            nByte += 0x40;
            nBranch += 1;
        }
    }
}

// FUNCTION: 0x001F5450 __dt__20PParticleElectricityFv
extern "C" void *__dt__20PParticleElectricityFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleElectricity *pSelf = (PParticleElectricity *)pThis;
        *(void **)pThis = __vt__20PParticleElectricity;
        if (pSelf->m_unkE0 != 0) {
            __dla__FPv(pSelf->m_unkE0);
            pSelf->m_unkE0 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F54D0 __ct__20PParticleElectricityFv
PParticleElectricity::PParticleElectricity() {
    *(void **)this = __vt__20PParticleElectricity;
}
