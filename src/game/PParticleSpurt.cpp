#include "types.h"
#include "PRandom.h"
#include "Debug.h"
#include "PParticleSpurt.h"

// TODO(header): foreign declarations
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void MulVector__5PMat4FPfPf(PMat4 *pMat, float *pSrc, float *pDst);
extern unsigned char __vt__14PParticleSpurt[];
extern "C" float sqrtf(float);
void FastMath_VectorFabs(float *pDst, float *pSrc);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int rand(void);
extern "C" float FastMath_Fabs__Ff(float fValue);
extern "C" void *AllocParticles__12PDisplayListFii(void *pThis, unsigned int nCount, int nType);
extern "C" void DmaScratchPadToMainMem__FPvPvsbb(void *pSpad, void *pMain, short nSize, bool bFlagA, bool bFlagB);
extern "C" float FastMath_Sin180__Ff(float fAngle);
extern "C" float FastMath_Cos180__Ff(float fAngle);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern char gGfxEng[1504384];

// DRAFT: 0x001CAED0 SetupBoundingBox__14PParticleSpurtFv
// note: 42 differing words; scale bits need mfc1 (every C float-to-int cast spills, so mfc1 is asm and not counted); VU0 blocks in asm; reg/order differ (0.5 in f2 not f1, sb in v0 not t0)
void PParticleSpurt::SetupBoundingBox() {
    float v20[4];
    float v30[4];
    float v40[4];
    float scale;
    int sb;
    float *pAdd;
    float *pSrc;
    float *pDst;

    scale = 0.5f * m_unk180[0];
    asm { mfc1 sb, scale }
    pAdd = m_unk130;
    pSrc = m_unk140;
    pDst = v20;
    asm {
        lqc2 vf1, 0x0(pSrc)
        lqc2 vf2, 0x0(pAdd)
        lqc2 vf5, 0x0(pDst)
        qmtc2.i sb, vf3
        vmulx.xyz vf4, vf1, vf3x
        vnop
        vnop
        vnop
        vadd.xyz vf5, vf4, vf2
        vnop
        vnop
        vnop
        sqc2 vf5, 0x0(pDst)
    }
    scale = 0.5f * m_unk194;
    asm { mfc1 sb, scale }
    pSrc = m_unk160;
    pDst = v40;
    asm {
        lqc2 vf1, 0x0(pSrc)
        lqc2 vf2, 0x0(pAdd)
        lqc2 vf5, 0x0(pDst)
        qmtc2.i sb, vf3
        vmulx.xyz vf4, vf1, vf3x
        vnop
        vnop
        vnop
        vadd.xyz vf5, vf4, vf2
        vnop
        vnop
        vnop
        sqc2 vf5, 0x0(pDst)
    }
    scale = 0.5f * m_unk180[0];
    asm { mfc1 sb, scale }
    pSrc = m_unk140;
    pAdd = m_unk1C0;
    pDst = v30;
    asm {
        lqc2 vf1, 0x0(pSrc)
        lqc2 vf2, 0x0(pAdd)
        lqc2 vf5, 0x0(pDst)
        qmtc2.i sb, vf3
        vmulx.xyz vf4, vf1, vf3x
        vnop
        vnop
        vnop
        vadd.xyz vf5, vf4, vf2
        vnop
        vnop
        vnop
        sqc2 vf5, 0x0(pDst)
    }
    FastMath_VectorFabs(v40, v40);
    FastMath_VectorFabs(v20, v20);

    m_unk80 = v30[0];
    m_unk84 = v30[1];
    m_unk88 = v30[2];
    m_unk8C = 0x3F800000;
    m_unk90 = v40[0] + (m_unkA0 + v20[0]);
    m_unk94 = v40[1] + (m_unkA0 + v20[1]);
    m_unk98 = v40[2] + (m_unkA0 + v20[2]);
    m_unk9C = sqrtf(m_unk90 * m_unk90 + m_unk94 * m_unk94 + m_unk98 * m_unk98);
}

// FUNCTION: 0x001CB080 ModifyPosition__14PParticleSpurtFP5PMat4
void PParticleSpurt::ModifyPosition(PMat4 *pMat) {
    if (m_unk19C != 0) {
        MulVector__5PMat4FPfPf(pMat, m_unk1C0, m_unkF0);
        float mat[4][4];
        sceVu0CopyMatrix(mat, (float (*)[4])pMat);
        mat[3][0] = 0.0f;
        mat[3][1] = 0.0f;
        mat[3][2] = 0.0f;
        mat[3][3] = 1.0f;
        MulVector__5PMat4FPfPf((PMat4 *)mat, m_unk1B0, m_unk140);
        sceVu0Normalize(m_unk1B0, m_unk1B0);
        SetupBoundingBox();
    } else {
        sceVu0CopyMatrix((float (*)[4])&m_unk40, (float (*)[4])pMat);
    }
}

// FUNCTION: 0x001CB120 SetPosition__14PParticleSpurtFPfPf
void PParticleSpurt::SetPosition(float *, float *) {
}

// DRAFT: 0x001CB130 Animate__14PParticleSpurtFf
// note: 725 differing words; frame is 0x110 in the original and the prologue saves s0-s7/fp, so every word shifts; VU0 blocks (lqc2/vcallms/sqc2) replaced by C lerps. Tried: adding a spC local (no change)
void PParticleSpurt::Animate(float fDt) {
    float spA0[4];
    float spB0[4];
    float spD[4];
    float spE0[4];
    float spF[4];
    float v100[4];
    float fRange;
    float fRange2;
    float f22;
    float fLerp;
    float fTmp;
    float fTmp2;
    float fOut;
    float fA7;
    float fA7b;
    float fA1;
    float fA2;
    float fA1n;
    float fT22;
    float fT24;
    float fT25;
    float fS;
    float *pRnd;
    float *pVec;
    char *pBuf;
    char *pEl;
    int nZero;
    int nRnd;
    int nRnd2;
    unsigned int i;
    unsigned int nDone;

    if (m_unk15 != 0) {
        if (m_unk16 != 0) {
            return;
        }
        if (m_unk17 != 0 || m_unkA4 != 0) {
            m_unkD0 = m_unk1E4;
            fRange = m_unk178 - m_unk174;
            fRange2 = m_unk17C - m_unk178;
            sceVu0SubVector(spA0, m_unk110, m_unk100);
            sceVu0SubVector(spB0, m_unk120, m_unk110);
            nZero = (m_unk130[0] == 0.0f && m_unk130[1] == 0.0f && m_unk130[2] == 0.0f) ? 1 : 0;
            pBuf = (char *)AllocParticles__12PDisplayListFii(*(void **)(gGfxEng + 0x154C80), m_unk04, 2);
            if (pBuf == 0) {
                CdsAssert("PParticleSpurt.cpp", 0xB2, "apVuParticles");
            }
            m_unk08 = pBuf;
            if (m_unk04 < 0x101) {
                pBuf = (char *)0x70001000;
                if ((m_unk04 << 5) >= 0x2001) {
                    CdsAssert("PParticleSpurt.cpp", 0xBA, "(sizeof(VuParticle) * muNumParticles) <= SPAD_TEMP_BUFFER_SIZE");
                }
            }
            spD[0] = 0.0f;
            spD[1] = 0.0f;
            spD[2] = 0.0f;
            spD[3] = 0.0f;
            nDone = 0;
            i = 0;
            while (i < m_unk04) {
                pEl = pBuf + (i << 5);
                pRnd = (float *)((char *)m_unkE0 + i * 4);
                if (m_unk18 != 0) {
                    *pRnd = *pRnd + fDt * (m_unk180[2] + (1.0f - m_unk180[2]) * ParticleRand01(m_unkD0));
                } else {
                    *pRnd = *pRnd + fDt * (0.6f + 0.39999998f * ParticleRand01(m_unkD0));
                }
                fTmp = m_unk1E0;
                if (!(*pRnd < fTmp)) {
                    *pRnd = fTmp;
                    if (m_unk17 != 0 || m_unk18 == 0) {
                        nDone++;
                        if (nDone >= m_unk170) {
                            m_unk16 = m_unk17;
                            m_unk15 = 0;
                            return;
                        }
                    } else {
                        *pRnd -= m_unk1E0;
                        if (m_unk19C != 0) {
                            *(u_long128 *)((char *)m_unkE8 + (i << 4)) = *(u_long128 *)m_unk1B0;
                            *(u_long128 *)((char *)m_unkE4 + (i << 4)) = *(u_long128 *)m_unk1C0;
                        }
                    }
                }
                f22 = *pRnd / m_unk1E0;
                if (!(f22 < 0.9999999f)) {
                    f22 = 0.9999999f;
                }
                fTmp = f22 * (0.5f + 3.5f * ParticleRand01(m_unkD0));
                fTmp2 = fTmp - (float)(int)fTmp;
                if (fTmp2 <= 0.5f) {
                    fOut = 0.3f * (-1.0f + 4.0f * fTmp2) * m_unk190;
                } else {
                    fOut = 0.3f * (1.0f + (-4.0f * (fTmp2 - 0.5f))) * m_unk190;
                }
                spD[0] = f22;
                spD[1] = f22 * f22;
                spD[2] = f22 * fOut;

                if (m_unk19C != 0) {
                    if (nZero != 0) {
                        *(u_long128 *)spE0 = *(u_long128 *)((char *)m_unkE4 + (i << 4));
                    } else {
                        spE0[0] = ParticleRand01(m_unkD0);
                        spE0[1] = ParticleRand01(m_unkD0);
                        spE0[2] = ParticleRand01(m_unkD0);
                    }
                    pVec = (float *)((char *)m_unkE8 + (i << 4));
                } else {
                    if (nZero != 0) {
                        *(u_long128 *)spE0 = *(u_long128 *)m_unk1C0;
                    } else {
                        spE0[0] = ParticleRand01(m_unkD0);
                        spE0[1] = ParticleRand01(m_unkD0);
                        spE0[2] = ParticleRand01(m_unkD0);
                    }
                    pVec = m_unk1B0;
                }
                *(u_long128 *)v100 = *(u_long128 *)pVec;

                spF[0] = ParticleRand01(m_unkD0);
                spF[1] = ParticleRand01(m_unkD0);
                spF[2] = ParticleRand01(m_unkD0);

                ((float *)pEl)[0] = v100[0] + (spE0[0] - v100[0]) * f22;
                ((float *)pEl)[1] = v100[1] + (spE0[1] - v100[1]) * f22;
                ((float *)pEl)[2] = v100[2] + (spE0[2] - v100[2]) * f22;

                fTmp2 = 0.75f * m_unk180[3];
                m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
                if (f22 <= 0.5f) {
                    fLerp = m_unk174 + 2.0f * (f22 * fRange);
                } else {
                    fLerp = m_unk178 + 2.0f * ((f22 - 0.5f) * fRange2);
                }
                ((float *)pEl)[3] = (1.0f + (-fTmp2 + (2.0f * fTmp2 * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF))))) * fLerp;

                if (m_unk19 != 0) {
                    fA7 = 30.0f * (float)m_unk2C;
                    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
                    nRnd = m_unkD0;
                    m_unkD0 = nRnd * 0x343FD + 0x269EC3;
                    nRnd2 = m_unkD0;
                    fA7b = 0.001f + (0.0139999995f * (float)m_unk28);
                    fA1 = 0.2f * fA7b;
                    fA2 = 2.0f * fA1;
                    fA1n = -fA1;
                    m_unkD0 = nRnd2 * 0x343FD + 0x269EC3;
                    fT24 = 180.0f * ((((float)((int)((fA7 + ((0.5f * fA7 - fA7) * (0.000030517578f * (float)((nRnd >> 16) & 0x7FFF)))) * *pRnd) % 360)) / 180.0f) - 1.0f);
                    fT22 = fA7b + (fA1n + (fA2 * (0.000030517578f * (float)((nRnd2 >> 16) & 0x7FFF))));
                    fT25 = fA7b + (fA1n + (fA2 * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF))));
                    fS = FastMath_Sin180__Ff(fT24);
                    ((float *)pEl)[4] = fT22 * FastMath_Cos180__Ff(fT24);
                    ((float *)pEl)[5] = fT25 * fS;
                }
                i++;
            }
            if (((int)pBuf & 0x70000000) == 0x70000000) {
                DmaScratchPadToMainMem__FPvPvsbb(pBuf, m_unk08, (short)(m_unk04 * 2), false, false);
            }
        }
    }
}

// DRAFT: 0x001CBCD0 Create__14PParticleSpurtFP22tagParticleSpurtParamsfff
// note: 125 differing words, size 0x340 vs 0x33C; the rand() float-to-int cast spills through the stack (C emits no mfc1); the m_unk1D0 selector store order and early-return epilogue differ. Tried: if/else min tail (126), positive-comparison selector (125).
int PParticleSpurt::Create(tagParticleSpurtParams *pParams, float fX, float fY, float fZ) {
    unsigned int i;
    int off;
    float f1;
    float f2;
    float f3;
    float v0;

    if (PParticleSystem::Create(pParams->m_unk80, 0) == 0) {
        return 0;
    }
    m_unkE0 = __nwa__FUi(pParams->m_unk80 * 4);
    if (m_unkE0 == 0) {
        return 0;
    }
    m_unk30 = 0x48;
    memcpy(m_unkF0, pParams, 0xC0);
    m_unkF0[0] += fX;
    m_unkF0[1] += fY;
    m_unkF0[2] += fZ;
    *(u_long128 *)m_unk1C0 = *(u_long128 *)m_unkF0;
    *(u_long128 *)m_unk1B0 = *(u_long128 *)m_unk140;
    m_unk1D0[0] = FastMath_Fabs__Ff(m_unk1B0[0]);
    m_unk1D0[1] = FastMath_Fabs__Ff(m_unk1B0[1]);
    m_unk1D0[2] = FastMath_Fabs__Ff(m_unk1B0[2]);
    f1 = m_unk1D0[0];
    f2 = m_unk1D0[1];
    if (!(f1 <= f2) && !(f1 <= m_unk1D0[2])) {
        m_unk1D0[0] = 0.0f;
        m_unk1D0[1] = 1.0f;
        m_unk1D0[2] = 1.0f;
    } else if (!(f2 <= f1)) {
        if (!(f2 <= m_unk1D0[2])) {
            m_unk1D0[0] = 1.0f;
            m_unk1D0[1] = 0.0f;
            m_unk1D0[2] = 1.0f;
        } else {
            m_unk1D0[0] = 1.0f;
            m_unk1D0[1] = 1.0f;
            m_unk1D0[2] = 0.0f;
        }
    } else {
        m_unk1D0[0] = 1.0f;
        m_unk1D0[1] = 1.0f;
        m_unk1D0[2] = 0.0f;
    }
    m_unk1E0 = 10.0f + (140.0f * (1.0f - m_unk180[1]));
    m_unk1E4 = (int)(0.5f + (24684.0f + (23958.0f * ((float)rand() / 2.1474836e9f))));
    m_unk0C = 7;
    if (m_unk19C != 0) {
        m_unkE8 = __nwa__FUi(pParams->m_unk80 * 0x10);
        if (m_unkE8 == 0) {
            return 0;
        }
        m_unkE4 = __nwa__FUi(pParams->m_unk80 * 0x10);
        if (m_unkE4 == 0) {
            return 0;
        }
        i = 0;
        off = 0;
        while (i < m_unk04) {
            i++;
            *(float *)((char *)m_unkE0 + off) = m_unk1E0;
            off += 4;
        }
    } else {
        memset(m_unkE0, 0, m_unk04 * 4);
    }
    m_unk180[3] = 1.0f - m_unk180[3];
    f1 = m_unk174;
    f2 = m_unk178;
    v0 = f2;
    if (!(f1 <= f2)) {
        v0 = f1;
    }
    f3 = m_unk17C;
    if (!(v0 <= f3)) {
        if (!(f1 <= f2)) {
        } else {
            f1 = f2;
        }
    } else {
        f1 = f3;
    }
    m_unkA0 = f1;
    SetupBoundingBox();
    return 1;
}

// FUNCTION: 0x001CC010 __dt__14PParticleSpurtFv
extern "C" void *__dt__14PParticleSpurtFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleSpurt *pSelf = (PParticleSpurt *)pThis;
        *(void **)pThis = __vt__14PParticleSpurt;
        if (pSelf->m_unkE0 != 0) {
            __dla__FPv(pSelf->m_unkE0);
            pSelf->m_unkE0 = 0;
        }
        if (pSelf->m_unkE8 != 0) {
            __dla__FPv(pSelf->m_unkE8);
            pSelf->m_unkE8 = 0;
        }
        if (pSelf->m_unkE4 != 0) {
            __dla__FPv(pSelf->m_unkE4);
            pSelf->m_unkE4 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001CC0C0 __ct__14PParticleSpurtFv
PParticleSpurt::PParticleSpurt() {
    *(void **)this = __vt__14PParticleSpurt;
    m_unkE0 = 0;
    m_unkE8 = 0;
    m_unkE4 = 0;
}
