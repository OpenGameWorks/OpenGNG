// FLAGS: -str readonly
#include "types.h"
#include "PParticleRipples.h"

// TODO(header): foreign declarations
extern "C" void FadeAndDie__15PParticleSystemFUi(void *, unsigned int);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void sceVu0CopyVector(void *pDst, float *pSrc);
extern "C" int rand(void);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void *__nwa__FUi(unsigned int nSize);
void QwordCopy(u_long128 *pDst, u_long128 *pSrc, unsigned int nQwords);
extern unsigned char __vt__16PParticleRipples[];

struct PGfxEngineRef {
    char _pad000[0x155570];
    int m_unk155570;
};
extern PGfxEngineRef gGfxEng;
extern unsigned char gDisplayListPtr[0x10];
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *, void *, int, bool);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *, void *, int, bool);
float FastMath_Sin180(float fAngle);
float FastMath_Cos180(float fAngle);
float FastMath_IntSin180(int nAngle);
float FastMath_IntCos180(int nAngle);
extern "C" void *AllocParticles__12PDisplayListFii(void *, int, int);

// DRAFT: 0x001ED740 InitRingMeshPacket__16PParticleRipplesFRiib
// note: DIFF 90 words; saved-register swap of this/nOut and float-load order unresolved. Tried: nOut-early variant (96), float-typed m_unk898..m_unk8A4 (94 to 90).
void *PParticleRipples::InitRingMeshPacket(int &nOut, int nArg1, bool bArg2) {
    float aTop[50][4];
    float aMid[50][4];
    float aBot[50][4];
    int nCount;
    int nFirst;
    int nSecond;
    if (bArg2) {
        nFirst = CreateRingTriStrip(nArg1, m_unk898, m_unk89C, 0xFF, 0xFF, aTop, aMid, aBot);
        nSecond = CreateRingTriStrip(nArg1, m_unk8A0, m_unk8A4, 0xFF, 0, aTop + nFirst, aMid + nFirst, aBot + nFirst);
    } else {
        nFirst = CreateRingTriStrip(nArg1, m_unk898, m_unk8A4, 0x80, 0x80, aTop, aMid, aBot);
        nSecond = 0;
    }
    nCount = nFirst + nSecond;
    if (nCount >= 0x32) {
        CdsAssert__FPciPc("PParticleRipples.cpp", 0x16E, "iNumVerts < fx_i_instance_max_vertices");
    }
    ((unsigned int *)aTop[nCount])[3] |= 0x8000;
    ((unsigned int *)aTop[nCount + 1])[3] |= 0x8000;
    void *pPacket = __nwa__FUi(0x970);
    if (pPacket == 0) {
        CdsAssert__FPciPc("PParticleRipples.cpp", 0x176, "apPacket");
    }
    ((int *)pPacket)[0] = nCount;
    ((int *)pPacket)[1] = 0;
    ((int *)pPacket)[2] = 0;
    ((int *)pPacket)[3] = 0;
    QwordCopy((u_long128 *)((char *)pPacket + 0x10), (u_long128 *)aMid, 0x32);
    QwordCopy((u_long128 *)((char *)pPacket + 0x330), (u_long128 *)aBot, 0x32);
    QwordCopy((u_long128 *)((char *)pPacket + 0x650), (u_long128 *)aTop, 0x32);
    nOut = 0x970;
    return pPacket;
}

// FUNCTION: 0x001ED8E0 CreateRingTriStrip__16PParticleRipplesFiffiiPA4_fPA4_fPA4_f
int PParticleRipples::CreateRingTriStrip(int nArg0, float fArg1, float fArg2, int nArg3, int nArg4,
                                         float (*pTop)[4], float (*pMid)[4], float (*pBot)[4]) {
    int nCount = nArg0 * 2 + 2;
    float fStep = 360.0f / (float)nArg0;
    float fAngle = 0.0f;
    for (int i = 0; i < nCount; i += 2) {
        float fSin = FastMath_Sin180(fAngle - 180.0f);
        float fCos = FastMath_Cos180(fAngle - 180.0f);
        pTop[i][0] = fArg1 * fCos;
        pTop[i][1] = 0.0f;
        pTop[i][2] = fArg1 * fSin;
        pTop[i][3] = 1.0f;
        float fHalf = 0.5f * (fArg1 / fArg2);
        pMid[i][0] = 0.5f + fCos * fHalf;
        pMid[i][1] = 0.5f + fSin * fHalf;
        ((int *)pBot[i])[0] = 0x80;
        ((int *)pBot[i])[1] = 0x80;
        ((int *)pBot[i])[2] = 0x80;
        ((int *)pBot[i])[3] = nArg3;
        ((int *)pBot[i + 1])[0] = 0x80;
        ((int *)pBot[i + 1])[1] = 0x80;
        ((int *)pBot[i + 1])[2] = 0x80;
        ((int *)pBot[i + 1])[3] = nArg4;
        pTop[i + 1][0] = fArg2 * fCos;
        pTop[i + 1][1] = 0.0f;
        pTop[i + 1][2] = fArg2 * fSin;
        pTop[i + 1][3] = 1.0f;
        pMid[i + 1][0] = 0.5f + 0.5f * fCos;
        pMid[i + 1][1] = 0.5f + 0.5f * fSin;
        fAngle += fStep;
    }
    return nCount;
}

// FUNCTION: 0x001EDAB0 FindFreeRipple__16PParticleRipplesFv
int PParticleRipples::FindFreeRipple() {
    int i = 0;
    unsigned int off = 0;
    do {
        if (*((unsigned char *)this + off + 0x11C) == 0) {
            return i;
        }
        i++;
        off += 0x40;
    } while (i < 0x1E);
    return -1;
}

// FUNCTION: 0x001EDAF0 FadeAndDie__16PParticleRipplesFUi
void PParticleRipples::FadeAndDie(unsigned int uArg) {
    FadeAndDie__15PParticleSystemFUi(this, uArg);
    m_unk018 = 0;
}

// DRAFT: 0x001EDB20 Render__16PParticleRipplesFv
// note: DIFF 48 words; original uses bnez over b to a shared epilogue (ld ra in delay slot), ours uses beqz straight to the return. Tried: three early returns (50), ==0 with empty then (50), !=0 with empty else (50), early-return form (50).
void PParticleRipples::Render() {
    if (m_unk015 == 0) {
        return;
    }
    if (m_unk860 == 0) {
        return;
    }
    if (m_unk8B1 != 0) {
        if (m_unk8B0 != 0) {
            float aMat[4] = {1.1f, 1.1f, 1.1f, 1.1f};
            SetMaterial__10PGfxEngineFiPfbUlUl(&gGfxEng, m_unk010, aMat, true, 0x44, 0x50000);
        } else {
            float aMat[4] = {1.0f, 1.0f, 1.0f, 1.0f};
            SetMaterial__10PGfxEngineFiPfbUlUl(&gGfxEng, m_unk010, aMat, true, 0x48, 0x50000);
        }
        BeginFxInstances__10PGfxEngineFPvib(&gGfxEng, m_unk890, m_unk894, m_unk8B0);
        DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)gDisplayListPtr, (void *)m_unk8A8, m_unk8AC, false);
    } else {
        return;
    }
}

// FUNCTION: 0x001EDC20 Animate__16PParticleRipplesFf
void PParticleRipples::Animate(float fArg) {
    float fAngle;

    if (m_unk015 == 0) {
        return;
    }
    if (m_unk868 > 0.0f && m_unk018 != 0) {
        m_unk86C -= fArg;
        if (m_unk86C <= 0.0f) {
            m_unk86C = m_unk868;
            float fRateA = 0.01f;
            float fRateB = 0.015f;
            Create((float *)(m_unk040 + 0x30), (float *)m_unk870, m_unk880, m_unk884, m_unk888, m_unk88C,
                   fRateA, fRateB);
        }
    }
    if (m_unk860 == 0) {
        m_unk016 = m_unk017;
        m_unk8B1 = 0;
        return;
    }
    m_unk8A8 = (char *)AllocParticles__12PDisplayListFii(*(void **)((char *)&gGfxEng + 0x154C80), m_unk860, 6);
    if (m_unk8A8 == 0) {
        CdsAssert__FPciPc("PParticleRipples.cpp", 0xA4, "mpFxInstances");
    }
    m_unk8AC = 0;
    if (m_unk8B0 != 0) {
        m_unk864 += 4.0f * fArg;
        if (m_unk864 >= 360.0f) {
            m_unk864 -= 360.0f;
        }
        fAngle = m_unk864;
    }
    for (int i = 0; i < 30; i++) {
        char *pSlot = (char *)this + i * 0x40 + 0xE0;
        if (m_unk8B0 != 0) {
            fAngle += 25.0f;
            if (fAngle >= 360.0f) {
                fAngle -= 360.0f;
            }
        }
        if (*(unsigned char *)(pSlot + 0x3C) != 0) {
            char *pOut = m_unk8A8 + m_unk8AC * 0x60;
            *(float *)(pSlot + 0x20) += *(float *)(pSlot + 0x2C) * fArg;
            *(float *)(pSlot + 0x1C) += *(float *)(pSlot + 0x30) * fArg;
            float fLife = *(float *)(pSlot + 0x34) - fArg;
            if (0.0f <= fLife) {
            } else {
                fLife = 0.0f;
            }
            *(float *)(pSlot + 0x34) = fLife;
            if (fLife <= 0.0f) {
                *(unsigned char *)(pSlot + 0x3C) = 0;
                *(float *)(pSlot + 0x20) = 0.0f;
                *(float *)(pSlot + 0x1C) = 0.0f;
                m_unk860 -= 1;
            }
            sceVu0UnitMatrix(pOut);
            *(float *)pOut = *(float *)(pSlot + 0x20);
            *(float *)(pOut + 0x28) = *(float *)(pSlot + 0x20);
            *(u_long128 *)(pOut + 0x30) = *(u_long128 *)pSlot;
            *(u_long128 *)(pOut + 0x40) = *(u_long128 *)(pSlot + 0x10);
            if (m_unk8B0 != 0) {
                int nAng = (int)(fAngle - 180.0f);
                float fSin = FastMath_IntSin180(nAng);
                float fCos = FastMath_IntCos180(nAng);
                *(float *)(pOut + 0x50) = 0.001f * fCos;
                *(float *)(pOut + 0x54) = *(float *)(pSlot + 0x38) * fSin;
            }
            m_unk8AC += 1;
        }
    }
}

// FUNCTION: 0x001EDF30 AutoEmit__16PParticleRipplesFfPfffff
void PParticleRipples::AutoEmit(float fArg0, float *pArr, float fArg2, float fArg3, float fArg4, float fArg5) {
    m_unk868 = fArg0;
    m_unk86C = 0;
    memcpy(m_unk870, pArr, 0x10);
    m_unk880 = fArg2;
    m_unk884 = fArg3;
    m_unk888 = fArg4;
    m_unk88C = fArg5;
}

// FUNCTION: 0x001EDFB0 Create__16PParticleRipplesFPffff
// note: DIFF 8 words; original copies the 1.0f quad via lq into $a3 with sq in the delay slot and builds 0.01f/0.015f with lui/ori/mtc1, ours loads literals from $gp and copies via $v0. Tried: plain literals (14), union bit patterns (17, 0x30 frame), literal locals declared first (14).
void PParticleRipples::Create(float *pArr, float fArg1, float fArg2, float fArg3) {
    float local[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    Create(pArr, local, fArg1, fArg2, 0.0f, fArg3, 0.01f, 0.015f);
}

// FUNCTION: 0x001EE000 Create__16PParticleRipplesFPfPfffffff
int PParticleRipples::Create(float *pArr0, float *pArr1, float fArg2, float fArg3, float fArg4, float fArg5, float fArg6, float fArg7) {
    int nIdx = FindFreeRipple();
    if (nIdx >= 0) {
        char *pSlot = m_unk0E0 + (nIdx << 6);
        sceVu0CopyVector(pSlot, pArr0);
        sceVu0CopyVector(pSlot + 0x10, pArr1);
        *(int *)(pSlot + 0xC) = 0x3F800000;
        *(float *)(pSlot + 0x20) = fArg2;
        *(float *)(pSlot + 0x24) = fArg2;
        *(float *)(pSlot + 0x28) = fArg3;
        *(float *)(pSlot + 0x2C) = (fArg3 - fArg2) / fArg5;
        *(float *)(pSlot + 0x30) = (fArg4 - pArr1[3]) / fArg5;
        *(float *)(pSlot + 0x34) = fArg5;
        *(float *)(pSlot + 0x38) = fArg6 + ((fArg7 - fArg6) * ((float)rand() / 2147483648.0f));
        *(unsigned char *)(pSlot + 0x3C) = 1;
        m_unk860 += 1;
        m_unk8B1 = 1;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001EE130 Init__16PParticleRipplesFibb
void PParticleRipples::Init(int nArg0, bool bArg1, bool bArg2) {
    void *pPacket = m_unk890;
    if (pPacket != 0) {
        __dla__FPv(pPacket);
        m_unk890 = 0;
        m_unk894 = 0;
    }
    m_unk890 = InitRingMeshPacket(m_unk894, nArg0, bArg1);
    if (m_unk890 == 0) {
        CdsAssert__FPciPc("PParticleRipples.cpp", 0x39, "mpRippleMeshPacket");
    }
    memset(m_unk0E0, 0, 0x780);
    m_unk860 = 0;
    m_unk864 = 0;
    m_unk8A8 = 0;
    m_unk015 = 1;
    m_unk018 = 1;
    m_unk014 = 1;
    sceVu0UnitMatrix(m_unk040);
    m_unk00C = 0xB;
    m_unk8B0 = bArg2;
    if (m_unk8B0 != 0) {
        m_unk010 = gGfxEng.m_unk155570;
    }
}

// FUNCTION: 0x001EE220 __dt__16PParticleRipplesFv
extern "C" void *__dt__16PParticleRipplesFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PParticleRipples *pSelf = (PParticleRipples *)pThis;
        *(void **)pThis = __vt__16PParticleRipples;
        if (pSelf->m_unk890 != 0) {
            __dla__FPv(pSelf->m_unk890);
            pSelf->m_unk890 = 0;
            pSelf->m_unk894 = 0;
        }
        pSelf->m_unk860 = 0;
        pSelf->m_unk8A8 = 0;
        pSelf->m_unk8B0 = 0;
        pSelf->m_unk868 = 0.0f;
        pSelf->m_unk86C = 0;
        pSelf->m_unk8B1 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001EE2C0 __ct__16PParticleRipplesFv
PParticleRipples::PParticleRipples() {
    __ct__15PParticleSystemFv(this);
    m_unk000 = __vt__16PParticleRipples;
    m_unk890 = 0;
    m_unk894 = 0;
    m_unk860 = 0;
    m_unk8A8 = 0;
    m_unk8B0 = 0;
    m_unk868 = 0.0f;
    m_unk86C = 0;
    m_unk898 = 0;
    m_unk89C = 0.4f;
    m_unk8A0 = 0.4f;
    m_unk8A4 = 0.5f;
    m_unk8B1 = 0;
}
