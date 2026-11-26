#include "types.h"
#include "PParticleTrail.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern unsigned char __vt__14PParticleTrail[];
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void __dla__FPv(void *);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" int rand(void);
extern "C" float sqrtf(float x);

// SKIP: 0x001C5650 AnimateSmoothTrail__14PParticleTrailFv: 0x8B4 bytes (557 instructions) with an LCG random chain on unkD0, FastMath sin/cos and sceVu0ScaleVectorXYZ calls; not drafted in this run.
// FUNCTION: 0x001C5F10 Start__14PParticleTrailFv
void PParticleTrail::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk1B4 = 0;
}

// FUNCTION: 0x001C5F30 ModifyPosition__14PParticleTrailFP5PMat4
void PParticleTrail::ModifyPosition(PMat4 *pMat) {
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk190;
    pMat->MulVector(m_unk190, &m_unkE0);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
}

// FUNCTION: 0x001C5F90 SetPosition__14PParticleTrailFPfPf
void PParticleTrail::SetPosition(float *pPos, float *pUnused) {
    *(u_long128 *)m_unk1A0 = *(u_long128 *)m_unk190;
    sceVu0CopyVector(m_unk190, pPos);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
}

// DRAFT: 0x001C69F0 Create__14PParticleTrailFP22tagParticleTrailParamsfff
// note: 10 words differ: clamp fMax and m_unkA0 ternaries match in shape; the post-clamp store order and sqrt tail (0x2B8-0x2C0) still differ. Tried fLo<=fMid vs fLo>fMid spellings, per-store reloads, nested-if clamp.
int PParticleTrail::Create(tagParticleTrailParams *pParams, float fA, float fB, float fC) {
    if (PParticleSystem::Create(pParams->m_unk50, true) == 0) {
        return 0;
    }
    m_unk0C = 4;
    m_unk30 = 0x48;
    memcpy(&m_unkE0, pParams, 0xA0);
    m_unkE0 += fA;
    m_unkE4 += fB;
    m_unkE8 += fC;
    *(u_long128 *)m_unk190 = *(u_long128 *)&m_unkE0;
    *(u_long128 *)m_unk1A0 = *(u_long128 *)&m_unkE0;
    m_unk1B0 = 10.0f + (80.0f * (1.0f - m_unk144));
    m_unk1BC = (int)(0.5f + (56789.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
    m_unk1B8 = 0;
    m_unk158 = 1.0f - m_unk158;
    m_unk1B4 = 0;
    if (m_unk160 != 0) {
        m_unk180 = __nwa__FUi(pParams->m_unk50 * 0x10);
        if (m_unk180 == 0) {
            return 0;
        }
        m_unk184 = __nwa__FUi(pParams->m_unk50 * 0x10);
        if (m_unk184 == 0) {
            return 0;
        }
        unsigned int i = 0;
        unsigned int off = 0;
        for (; i < m_unk04;) {
            ++i;
            *(float *)((unsigned char *)m_unk180 + off) = m_unk190[0];
            *(float *)((unsigned char *)m_unk180 + off + 4) = m_unk190[1];
            *(float *)((unsigned char *)m_unk180 + off + 8) = m_unk190[2];
            *(float *)((unsigned char *)m_unk180 + off + 12) = 1.0f + m_unk1B0;
            float *pB = (float *)((unsigned char *)m_unk184 + off);
            pB[2] = 0.0f;
            off += 0x10;
            pB[1] = 0.0f;
            pB[0] = 0.0f;
            pB[3] = 1.0f;
        }
    } else {
        unsigned int i = 0;
        unsigned int off = 0;
        for (; i < m_unk04;) {
            ++i;
            float *pA = (float *)((unsigned char *)m_unk08 + off);
            pA[0] = m_unk190[0];
            pA[1] = m_unk190[1];
            pA[2] = m_unk190[2];
            off += 0x20;
        }
    }
    float fLo = m_unk134;
    float fMid = m_unk138;
    float fMax = (fLo > fMid) ? fLo : fMid;
    m_unkA0 = (fMax <= m_unk13C) ? m_unk13C : ((fLo <= fMid) ? fMid : fLo);
    m_unk80 = m_unk190[0];
    m_unk84 = m_unk190[1];
    m_unk88 = m_unk190[2];
    m_unk8C = 0x3F800000;
    m_unk90 = m_unkA0 + m_unk120;
    m_unk94 = m_unkA0 + m_unk124;
    m_unk98 = m_unkA0 + m_unk128;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001C6D50 __dt__14PParticleTrailFv
PParticleTrail::~PParticleTrail() {
    *(unsigned char **)this = __vt__14PParticleTrail;
    if (m_unk180) {
        __dla__FPv(m_unk180);
        m_unk180 = 0;
    }
    if (m_unk184) {
        __dla__FPv(m_unk184);
        m_unk184 = 0;
    }
}

// FUNCTION: 0x001C6DF0 __ct__14PParticleTrailFv
PParticleTrail::PParticleTrail() {
    *(unsigned char **)this = __vt__14PParticleTrail;
    m_unk180 = 0;
    m_unk184 = 0;
    m_unk1B8 = 0;
}
