#include "types.h"
#include "PParticleGas.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" int rand(void);
extern "C" void sceVu0SubVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0AddVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0ScaleVectorXYZ(void *pDst, void *pSrc, float fScale);
extern "C" float sqrtf(float fValue);
extern u_long128 lit_0024CCE0;
extern u_long128 lit_0024CCF0;
extern unsigned char __vt__12PParticleGas[];

// Parameter block passed to PParticleGas::Create (0x70 bytes, copied into the object at 0xE0).
struct tagParticleGasParams {
    int m_unk0;
    int m_unk4;
    int m_unk8;
    float m_unkC;
    float m_unk10;
    float m_unk14;
    float m_unk18;
    float m_unk1C;
    float m_unk20;
    float m_unk24;
    float m_unk28;
    float m_unk2C;
    float m_unk30;
    float m_unk34;
    float m_unk38;
    float m_unk3C;
    float m_unk40;
    int m_unk44;
    float m_unk48;
    float m_unk4C;
    char _pad50[0x20];
};

// FUNCTION: 0x001EC810 FadeOut__12PParticleGasFf
void PParticleGas::FadeOut(float fFade) {
    m_unk138 = fFade;
    m_unk164 = fFade;
    m_unk168 = 1;
}

// FUNCTION: 0x001EC830 Stop__12PParticleGasFv
void PParticleGas::Stop() {
    if (m_unk138) {
        FadeOut(m_unk138);
    } else {
        m_unk18 = 0;
    }
}

// FUNCTION: 0x001EC870 Start__12PParticleGasFv
void PParticleGas::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    *(float *)&m_unk160 = m_unk12C;
    m_unk168 = 0;
}

// FUNCTION: 0x001EC890 FadeAndDie__12PParticleGasFUi
void PParticleGas::FadeAndDie(unsigned int nUnused) {
    PParticleSystem::FadeAndDie(nUnused);
    if (!m_unk138) {
        return;
    }
    FadeOut(m_unk138);
}

// DRAFT: 0x001ED110 Create__12PParticleGasFP20tagParticleGasParamsfff
// note: 322 words differ; original frame 0xE0 saves s0-s7 with this in s0 and pParams in s1, ours frame 0x90 with this in s2, so the prologue and every line after it shift. Tried: loop base hoisted to pBase (332 -> 322, kept as v2), others not kept.
int PParticleGas::Create(tagParticleGasParams *pParams, float fA, float fB, float fC) {
    u_long128 vLo;
    u_long128 vHi;
    u_long128 vSub;
    u_long128 vAdd;
    u_long128 *pLo;
    u_long128 *pHi;
    u_long128 *pSub;
    u_long128 *pAdd;
    void *pV;
    char *pElem;
    char *pBase;
    unsigned int i;

    if (!PParticleSystem::Create(pParams->m_unk44, false)) {
        return 0;
    }
    m_unk0C = 12;
    *(long long *)&m_unk30 = 0x48;
    memcpy(&m_unkE0, pParams, 0x70);
    m_unkE0 += fA;
    m_unkE4 += fB;
    m_unkE8 += fC;
    *(float *)&m_unk154 = 30.0f + 570.0f * (1.0f - m_unk114);
    m_unk158 = (int)(0.5f + (24536.0f + 39006.0f * ((float)rand() / 2147483648.0f)));
    *(float *)&m_unk160 = pParams->m_unk4C;
    m_unk130 = (4.0f <= m_unk130) ? m_unk130 : 4.0f;
    m_unk134 = (1.0f <= m_unk134) ? m_unk134 : 1.0f;
    m_unk150 = __nwa__FUi(m_unk04 << 5);
    if (!m_unk150) {
        return 0;
    }
    vLo = lit_0024CCE0;
    vHi = lit_0024CCF0;
    sceVu0SubVector(&vSub, &m_unkE0, &m_unkF0[0]);
    sceVu0AddVector(&vAdd, &m_unkE0, &m_unkF0[0]);
    pLo = &vLo;
    pHi = &vHi;
    pSub = &vSub;
    pAdd = &vAdd;
    pBase = (char *)m_unk150;

    for (i = 0; i < m_unk04; i++) {
        pElem = pBase + (i << 5);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x10) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x14) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x18) = (float)((m_unkD0 >> 16) & 0x7FFF);
        sceVu0ScaleVectorXYZ(pElem + 0x10, pElem + 0x10, 3.0517578125e-05f);

        pV = pElem + 0x10;
        asm {
            lqc2 vf1, 0x0(pLo)
            lqc2 vf2, 0x0(pHi)
            lqc2 vf3, 0x0(pV)
            vsub.xyz vf4, vf2, vf1
            vmul.xyz vf5, vf4, vf3
            vadd.xyz vf3, vf5, vf1
            sqc2 vf3, 0x0(pV)
        }

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x0) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x4) = (float)((m_unkD0 >> 16) & 0x7FFF);
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x8) = (float)((m_unkD0 >> 16) & 0x7FFF);
        sceVu0ScaleVectorXYZ(pElem, pElem, 3.0517578125e-05f);

        pV = pElem;
        asm {
            lqc2 vf1, 0x0(pSub)
            lqc2 vf2, 0x0(pAdd)
            lqc2 vf3, 0x0(pV)
            vsub.xyz vf4, vf2, vf1
            vmul.xyz vf5, vf4, vf3
            vadd.xyz vf3, vf5, vf1
            sqc2 vf3, 0x0(pV)
        }

        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0xC) = 0.0f + (*(float *)&m_unk154 - 0.0f) * (3.0517578125e-05f * (float)((m_unkD0 >> 16) & 0x7FFF));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pElem + 0x1C) = 1.0f + (m_unk110 - 1.0f) * (3.0517578125e-05f * (float)((m_unkD0 >> 16) & 0x7FFF));
    }

    m_unkA0 = (m_unk11C <= m_unk120) ? m_unk120 : m_unk11C;
    m_unk80 = m_unkE0;
    m_unk84 = m_unkE4;
    m_unk88 = m_unkE8;
    m_unk8C = 0x3F800000;
    m_unk90 = m_unkA0 + m_unkF0[0];
    m_unk94 = m_unkA0 + m_unkF0[1];
    m_unk98 = m_unkA0 + m_unkF0[2];
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001ED650 __dt__12PParticleGasFv
PParticleGas::~PParticleGas() {
    *(unsigned char **)this = __vt__12PParticleGas;
    if (m_unk150) {
        __dla__FPv(m_unk150);
        m_unk150 = 0;
    }
}

// FUNCTION: 0x001ED6D0 __ct__12PParticleGasFv
PParticleGas::PParticleGas() {
    *(unsigned char **)this = __vt__12PParticleGas;
    memset((char *)this + 0xE0, 0, 0x70);
    m_unk150 = 0;
    m_unk154 = 0;
    m_unk160 = 0;
    m_unk164 = 0;
    m_unk168 = 0;
}
