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
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int rand(void);
extern "C" float FastMath_Fabs__Ff(float fValue);

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
