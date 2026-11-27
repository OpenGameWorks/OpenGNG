#include "types.h"
#include "PRandom.h"
#include "Debug.h"
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
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, unsigned int nCount, int nType);
extern "C" float FastMath_Sin180__Ff(float fAngle);
extern "C" float FastMath_Cos180__Ff(float fAngle);
extern char gGfxEng[1504384];
extern char lit_00269E30[];
extern char lit_00269E48[];

struct tagParticleFireParams {
    char _pad0[0x50];
    unsigned int m_unk50;
    char _pad54[0x3C];
};

// Scratch block at absolute 0x70001000. Offsets 0x00-0x8F hold a copy of
// the tagParticleFireParams block that Create stores at this+0xF0.
struct PFScratch {
    char _p00[0x1C];
    float m_unk1C;
    char _p20[0x0C];
    float m_unk2C;
    char _p30[0x0C];
    float m_unk3C;
    char _p40[0x10];
    unsigned int m_unk50;
    float m_unk54;
    float m_unk58;
    float m_unk5C;
    float m_unk60;
    char _p64[0x04];
    float m_unk68;
    float m_unk6C;
    char _p70[0x04];
    float m_unk74;
    float m_unk78;
    float m_unk7C;
    float m_unk80;
    float m_unk84;
    char _p88[0x08];
    float m_unk90[4];
    char _pA0[0x0C];
    float m_unkAC;
    float m_unkB0;
    float m_unkB4;
    float m_unkB8;
    float m_unkBC;
    float m_unkC0;
    float m_unkC4;
    char _pC8[0x04];
    float m_unkCC;
    float m_unkD0;
    float m_unkD4;
    float m_unkD8;
    char _pDC[0x04];
    float m_unkE0;
    int m_unkE4;
    unsigned int m_unkE8;
    unsigned int m_unkEC;
    unsigned int m_unkF0;
    float m_unkF4;
    float m_unkF8;
    int m_unkFC;
    float m_unk100;
    float m_unk104;
    float m_unk108;
    float m_unk10C;
    float m_unk110;
    float m_unk114;
    float m_unk118;
    float m_unk11C;
    float m_unk120;
    float m_unk124;
    float m_unk128;
    float m_unk12C;
    float m_unk130;
    float m_unk134;
};

// FUNCTION: 0x001B6400 Enable__13PParticleFireFb
void PParticleFire::Enable(bool bEnable) {
    m_unk15 = bEnable;
    m_unk198 = (m_unk198 | !bEnable) != 0;
}

// FUNCTION: 0x001B6430 Stop__13PParticleFireFv
void PParticleFire::Stop() {
    *(unsigned char *)((char *)this + 0x18) = 0;
    m_unk198 = 1;
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

#define PF_STEP(p) ((p)->m_unkE4 = (p)->m_unkE4 * 0x343FD + 0x269EC3)
#define PF_RND(p) (0.000030517578f * (float)(((p)->m_unkE4 >> 16) & 0x7FFF))

#define pS ((PFScratch *)0x70001000)
// DRAFT: 0x001B65B0 Animate__13PParticleFireFf
// note: 828 words; prologue keeps this in s2 (orig s0) with 0x50 frame, memcpy call late, scratch base hoisted into s0 (orig per-use lui/ori), VU0 bodies and adda/madd chains unverified. Tried: this-relative VU0 bases (830->828), function-scoped scratch macro (828, kept).
void PParticleFire::Animate(float fDt) {
    float fRate = fDt;
    float fT;
    float fT2;
    float fT3;
    float fT4;
    float fT0;
    float fT1;
    float fRnd;
    float fVal;
    float fB8;
    float *pE0;
    float *pD0;
    float *pOut;
    float *pV0;
    float *pV1;
    float *pA0;
    char *pBuf;
    int nFix;

    if (m_unk15 != 0) {
        if (m_unk16 != 0) {
            return;
        }
        if (m_unk17 == 0) {
            if (m_unkA4 != 0) {
                goto block_6;
            }
        } else {
block_6:
            memcpy(pS, &m_unkF0, 0x90);
            *(u_long128 *)pS->m_unk90 = *(u_long128 *)m_unk180;
            pS->m_unkE0 = m_unk190;
            pS->m_unkE4 = m_unk194;
            pS->m_unkE8 = 0;
            pS->m_unkF0 = m_unk04;
            pS->m_unk130 = m_unk2C;
            pS->m_unk134 = m_unk28;
            pBuf = (char *)AllocParticles__12PDisplayListFii(*(void **)(gGfxEng + 0x154C80), pS->m_unkF0, 2);
            if (pBuf == 0) {
                CdsAssert(lit_00269E30, 0x9B, lit_00269E48);
            }
            m_unk08 = pBuf;
            pV0 = (float *)((char *)this + 0x10);
            pV1 = (float *)((char *)this + 0x20);
            pA0 = (float *)((char *)this + 0x30);
            nFix = 0x437F0000;
            asm {
                lqc2 vf29, 0x0(pV0)
                lqc2 vf30, 0x0(pV1)
                lqc2 vf31, 0x0(pA0)
                ctc2.ni nFix, vi21
            }
            if (m_unk18 != 0) {
                if (m_unk17 != 0) {
                    goto block_11;
                }
            } else {
block_11:
                fRate *= 4.0f;
            }
            pS->m_unkEC = 0;
            while (pS->m_unkEC < pS->m_unkF0) {
                fT = pS->m_unk80;
                PF_STEP(pS);
                pE0 = (float *)m_unkE0 + pS->m_unkEC;
                *pE0 += fRate * (fT + (1.0f - fT) * PF_RND(pS));
                fT0 = pS->m_unkE0;
                if (!(*pE0 <= fT0)) {
                    *pE0 = fT0;
                    if ((m_unk17 != 0) || (m_unk18 == 0)) {
                        pS->m_unkE8++;
                        if (pS->m_unkE8 >= pS->m_unk50) {
                            m_unk16 = m_unk17;
                            m_unk15 = 0;
                            return;
                        }
                        goto block_21;
                    }
                    *pE0 -= pS->m_unkE0;
                    if (m_unkE4 != 0) {
                        *(u_long128 *)((char *)m_unkE4 + pS->m_unkEC * 0x10) = *(u_long128 *)pS->m_unk90;
                    }
                    goto block_21;
                }
block_21:
                fRnd = *((float *)m_unkE0 + pS->m_unkEC) / pS->m_unkE0;
                if (fRnd < 0.9999999f) {
                } else {
                    fRnd = 0.9999999f;
                }
                pS->m_unkF4 = fRnd;
                PF_STEP(pS);
                pS->m_unkF8 = 1.0f + 19.0f * PF_RND(pS);
                pS->m_unkFC = (int)(pS->m_unkF8 * *((float *)m_unkE0 + pS->m_unkEC)) % 360;
                pS->m_unk100 = 180.0f * ((float)pS->m_unkFC / 180.0f - 1.0f);
                fT = pS->m_unk68;
                fT2 = 0.5f * fT;
                PF_STEP(pS);
                pS->m_unk104 = fT + (-fT2 + (2.0f * fT2 * PF_RND(pS)));
                fT = pS->m_unk6C;
                fT2 = 0.5f * fT;
                PF_STEP(pS);
                pS->m_unk108 = fT + (-fT2 + (2.0f * fT2 * PF_RND(pS)));
                pS->m_unk10C = FastMath_Sin180__Ff(pS->m_unk100);
                pS->m_unk110 = FastMath_Cos180__Ff(pS->m_unk100);
                if (m_unkE4 != 0) {
                    PF_STEP(pS);
                    pS->m_unkB0 = pS->m_unk104 * pS->m_unk110 + pS->m_unk108 * pS->m_unk10C;
                    pS->m_unkB4 = *(float *)((char *)m_unkE4 + 4 + pS->m_unkEC * 0x10) + pS->m_unkF4 * pS->m_unk60;
                    PF_STEP(pS);
                    fB8 = pS->m_unk104 * pS->m_unk110 + pS->m_unk108 * pS->m_unk10C;
                } else {
                    PF_STEP(pS);
                    pS->m_unkB0 = pS->m_unk104 * pS->m_unk110 + pS->m_unk108 * pS->m_unk10C;
                    pS->m_unkB4 = pS->m_unk90[1] + pS->m_unkF4 * pS->m_unk60;
                    PF_STEP(pS);
                    fB8 = pS->m_unk104 * pS->m_unk110 + pS->m_unk108 * pS->m_unk10C;
                }
                pS->m_unkB8 = fB8;
                fT0 = pS->m_unkF4 * pS->m_unk74;
                pS->m_unk114 = fT0;
                pS->m_unk114 = fT0 - (float)(int)fT0;
                fT2 = 0.75f * pS->m_unk84;
                PF_STEP(pS);
                pS->m_unk118 = 1.0f + (-fT2 + (2.0f * fT2 * PF_RND(pS)));
                fT3 = pS->m_unk114;
                if (fT3 <= 0.5f) {
                    fT4 = pS->m_unk54;
                    fVal = fT4 + (2.0f * (fT3 * (pS->m_unk58 - fT4)));
                } else {
                    fT4 = pS->m_unk58;
                    fVal = fT4 + (2.0f * ((fT3 - 0.5f) * (pS->m_unk5C - fT4)));
                }
                pS->m_unkBC = fVal;
                pS->m_unkBC = pS->m_unkBC * pS->m_unk118;
                if (m_unk19 != 0) {
                    pS->m_unkF8 = 30.0f * pS->m_unk130;
                    fT2 = pS->m_unkF8;
                    PF_STEP(pS);
                    pS->m_unkF8 = fT2 + (((0.5f * fT2) - fT2) * PF_RND(pS));
                    pS->m_unkFC = (int)(pS->m_unkF8 * *((float *)m_unkE0 + pS->m_unkEC)) % 360;
                    pS->m_unk100 = 180.0f * ((float)pS->m_unkFC / 180.0f - 1.0f);
                    fT0 = 0.001f + (0.0139999995f * pS->m_unk134);
                    pS->m_unk124 = fT0;
                    fT1 = 0.2f * fT0;
                    PF_STEP(pS);
                    pS->m_unk128 = fT0 + (-fT1 + (2.0f * fT1 * PF_RND(pS)));
                    fT3 = pS->m_unk124;
                    fT1 = 0.2f * fT3;
                    PF_STEP(pS);
                    pS->m_unk12C = fT3 + (-fT1 + (2.0f * fT1 * PF_RND(pS)));
                    pS->m_unk10C = FastMath_Sin180__Ff(pS->m_unk100);
                    pS->m_unk110 = FastMath_Cos180__Ff(pS->m_unk100);
                    pS->m_unkC0 = pS->m_unk128 * pS->m_unk110;
                    pS->m_unkC4 = pS->m_unk12C * pS->m_unk10C;
                } else {
                    fT2 = pS->m_unkF4 * pS->m_unk78;
                    fT1 = fT2 - (float)(int)fT2;
                    pS->m_unk11C = fT2;
                    pS->m_unk11C = fT1;
                    pD0 = &pS->m_unkD0;
                    pOut = (float *)((char *)pS + 0xC0);
                    if (fT1 <= 0.5f) {
                        fT0 = 2.0f * fT1;
                        pS->m_unkD8 = fT0;
                        pS->m_unkD4 = fT0;
                        pS->m_unkD0 = fT0;
                        asm {
                            lqc2 vf27, 0x0(pD0)
                            vsub.xyz vf1, vf30, vf29
                            vmul.xyz vf1, vf1, vf27
                            vadd.xyz vf2, vf1, vf29
                            vmax.xyz vf2, vf2, vf0
                            vminii.xyz vf2, vf2, I
                            sqc2 vf2, 0x0(pOut)
                        }
                    } else {
                        fT0 = 2.0f * (fT1 - 0.5f);
                        pS->m_unkD8 = fT0;
                        pS->m_unkD4 = fT0;
                        pS->m_unkD0 = fT0;
                        asm {
                            lqc2 vf27, 0x0(pD0)
                            vsub.xyz vf1, vf31, vf30
                            vmul.xyz vf1, vf1, vf27
                            vadd.xyz vf2, vf1, vf30
                            vmax.xyz vf2, vf2, vf0
                            vminii.xyz vf2, vf2, I
                            sqc2 vf2, 0x0(pOut)
                        }
                    }
                }
                fT0 = pS->m_unkF4 * pS->m_unk7C;
                fT1 = fT0 - (float)(int)fT0;
                pS->m_unk120 = fT0;
                pS->m_unk120 = fT1;
                if (fT1 <= 0.5f) {
                    pS->m_unkAC = pS->m_unk2C - pS->m_unk1C;
                    pS->m_unkAC = pS->m_unkAC * (2.0f * pS->m_unk120);
                    fVal = pS->m_unkAC + pS->m_unk1C;
                } else {
                    pS->m_unkAC = pS->m_unk3C - pS->m_unk2C;
                    pS->m_unkAC = pS->m_unkAC * (2.0f * (pS->m_unk120 - 0.5f));
                    fVal = pS->m_unkAC + pS->m_unk2C;
                }
                pS->m_unkAC = fVal;
                fRnd = pS->m_unkAC;
                if (fRnd < 128.0f) {
                } else {
                    fRnd = 128.0f;
                }
                fB8 = 0.0f;
                if (!(fRnd <= 0.0f)) {
                    fB8 = pS->m_unkAC;
                    if (fB8 < 128.0f) {
                    } else {
                        fB8 = 128.0f;
                    }
                }
                pS->m_unkCC = fB8;
                *(u_long128 *)(pBuf + (pS->m_unkEC << 5)) = *(u_long128 *)&pS->m_unkB0;
                *(u_long128 *)(pBuf + (pS->m_unkEC << 5) + 0x10) = *(u_long128 *)&pS->m_unkC0;
                pS->m_unkEC = pS->m_unkEC + 1;
            }
        }
    }
}

#undef pS
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
            ((float *)m_unkE0)[k] = 0.0f + (m_unk190 - 0.0f) * ParticleRand01(m_unkD0);
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
