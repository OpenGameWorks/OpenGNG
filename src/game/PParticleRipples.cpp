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

// DRAFT: 0x001EDFB0 Create__16PParticleRipplesFPffff
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
