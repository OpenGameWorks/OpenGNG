#include "types.h"
#include "PParticleFire.h"
#include "PMat4.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern unsigned char __vt__13PParticleFire[];
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int rand(void);
extern "C" float sqrtf(float x);

struct tagParticleFireParams {
    char _pad0[0x50];
    unsigned int m_unk50;
    char _pad54[0x3C];
};

// FUNCTION: 0x001B6400 Enable__13PParticleFireFb
void PParticleFire::Enable(bool bEnable) {
    m_unk15 = bEnable;
    m_unk198 = (m_unk198 | !bEnable) != 0;
}

// FUNCTION: 0x001B6440 ModifyPosition__13PParticleFireFP5PMat4
void PParticleFire::ModifyPosition(PMat4 *pMat) {
    pMat->MulVector(m_unk180, m_unkF0);
    m_unk80 = m_unk180[0];
    m_unk84 = m_unk180[1] + 0.5f * m_unk150;
    m_unk88 = m_unk180[2];
    m_unk8C = 0x3F800000;
    if (m_unk198) {
        if (m_unkE4) {
            unsigned int i = 0;
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unkE4)[i] = *(u_long128 *)m_unk180;
            }
            m_unk198 = 0;
        }
    }
}

// FUNCTION: 0x001B6500 SetPosition__13PParticleFireFPfPf
void PParticleFire::SetPosition(float *pPos, float *pUnused) {
    sceVu0CopyVector(m_unk180, pPos);
    m_unk80 = m_unk180[0];
    m_unk84 = m_unk180[1] + 0.5f * m_unk150;
    m_unk88 = m_unk180[2];
    m_unk8C = 0x3F800000;
    if (m_unk198) {
        if (m_unkE4) {
            unsigned int i = 0;
            for (i = 0; i < m_unk04; i++) {
                ((u_long128 *)m_unkE4)[i] = *(u_long128 *)m_unk180;
            }
            m_unk198 = 0;
        }
    }
}

// DRAFT: 0x001B7160 Create__13PParticleFireFP21tagParticleFireParamsfff
// note: 124 differing words; original inlines sqrt.s with adda.s/madd.s (size 0x384 vs ours 0x374, calls sqrtf); fill-loop bottom test, rand division register order and m_unkA0 selection differ. Tried: tail range selection per-arm stores (kept), m_unk194 temp variable (124, reverted), fRand temp (141, reverted).
int PParticleFire::Create(tagParticleFireParams *pParams, float fX, float fY, float fZ) {
    if (PParticleSystem::Create(pParams->m_unk50, 0) == 0) {
        return 0;
    }
    m_unkE0 = __nwa__FUi(pParams->m_unk50 * 4);
    if (m_unkE0 == 0) {
        return 0;
    }
    memset(m_unkE0, 0, pParams->m_unk50 * 4);
    m_unk0C = 1;
    m_unk30 = 0x48;
    memcpy(m_unkF0, pParams, 0x90);
    m_unkF0[0] = m_unkF0[0] + fX;
    m_unkF0[1] += fY;
    m_unkF0[2] += fZ;
    *(u_long128 *)m_unk180 = *(u_long128 *)m_unkF0;
    m_unk190 = 10.0f + 290.0f * (1.0f - m_unk154);
    m_unk194 = (int)(0.5f + (23456.0f + 41976.0f * ((float)rand() / 2.1474836e9f)));
    m_unk174 = 1.0f - m_unk174;
    if (!(m_unk160 <= 0.0f)) {
        m_unkE4 = __nwa__FUi(pParams->m_unk50 * 0x10);
        if (m_unkE4 == 0) {
            return 0;
        }
        memset(m_unkE4, 0, pParams->m_unk50 * 0x10);
        unsigned int i = 0;
        int off = 0;
        int k = 0;
        for (i = 0; i < m_unk04; i++) {
            *(float *)((char *)m_unkE4 + off) = m_unk180[0];
            *(float *)((char *)m_unkE4 + off + 4) = m_unk180[1];
            *(float *)((char *)m_unkE4 + off + 8) = m_unk180[2];
            off += 0x10;
            m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
            ((float *)m_unkE0)[k] = 0.0f + (m_unk190 - 0.0f) * (0.000030517578f * (float)(((int)m_unkD0 >> 16) & 0x7FFF));
            k++;
        }
        m_unk198 = 1;
    }
    float fA = m_unk144;
    float fB = m_unk148;
    float fMax = fB;
    if (!(fA <= fB)) {
        fMax = fA;
    }
    if (!(fMax <= m_unk14C)) {
        if (fA <= fB) {
            m_unkA0 = fB;
        } else {
            m_unkA0 = fA;
        }
    } else {
        m_unkA0 = m_unk14C;
    }
    m_unk80 = m_unk180[0];
    m_unk84 = m_unk180[1] + 0.5f * m_unk150;
    m_unk88 = m_unk180[2];
    m_unk8C = 0x3F800000;
    m_unk90 = m_unkA0 + m_unk130;
    m_unk94 = 0.5f * m_unk150 + m_unkA0;
    m_unk98 = m_unkA0 + m_unk138;
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
    return 1;
}

// FUNCTION: 0x001B74F0 __dt__13PParticleFireFv
PParticleFire::~PParticleFire() {
    *(unsigned char **)this = __vt__13PParticleFire;
    if (m_unkE0) {
        __dla__FPv(m_unkE0);
        m_unkE0 = 0;
    }
    if (m_unkE4) {
        __dla__FPv(m_unkE4);
        m_unkE4 = 0;
    }
}

// FUNCTION: 0x001B7590 __ct__13PParticleFireFv
PParticleFire::PParticleFire() {
    *(unsigned char **)this = __vt__13PParticleFire;
    m_unkE4 = 0;
    m_unkE0 = 0;
}
