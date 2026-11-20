#include "types.h"
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
