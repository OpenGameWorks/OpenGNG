#include "types.h"
#include "PMidasShieldRings.h"

// TODO(header): foreign declarations
extern "C" void FadeAndDie__15PParticleSystemFUi(void *, unsigned int);
extern "C" void *__ct__15PParticleSystemFv(void *);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dla__FPv(void *);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__17PMidasShieldRings[];
extern "C" void SetMaterial__10PGfxEngineFPfbUlUl(void *, float *, bool, unsigned long, unsigned long);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *, int, float *, bool, unsigned long, unsigned long);
extern "C" void BeginFxInstances__10PGfxEngineFPvib(void *, void *, int, bool);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *, void *, int, bool);
extern unsigned char gGfxEng[0x10];
extern unsigned char gDisplayListPtr[0x10];
extern "C" float FastMath_Sin180__Ff(float);
extern "C" float FastMath_Cos180__Ff(float);
extern "C" void CdsAssert__FPciPc(const char *, int, const char *);
extern "C" void *__nwa__FUi(unsigned int);
extern "C" void QwordCopy__FP1P1Ui(u_long128 *, u_long128 *, unsigned int);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void sceVu0UnitMatrix(void *);
extern "C" void sceVu0CopyVector(float *, float *);
extern "C" int rand(void);

// DRAFT: 0x001F8980 InitRingMeshPacket__17PMidasShieldRingsFRiib
// note: frame, call order and arguments match; 86 words differ in local layout and register scheduling; tried direct array indexing and single-expression total
void *PMidasShieldRings::InitRingMeshPacket(int &nCount, int nSegs, bool bFlag) {
    float sA[50][4];
    float sB[50][4];
    float sC[50][4];
    int nA;
    int nTotal;
    if (bFlag) {
        nA = CreateRingTriStrip(nSegs, 0.3f, 0.4f, 0, 0xFF, sA, sB, sC);
        nTotal = nA + CreateRingTriStrip(nSegs, 0.4f, 0.5f, 0xFF, 0, sA + nA, sB + nA, sC + nA);
    } else {
        nA = CreateRingTriStrip(nSegs, 0.0f, 0.5f, 0x80, 0x80, sA, sB, sC);
        nTotal = nA;
    }
    ((int *)sA[nA])[3] |= 0x8000;
    ((int *)sA[nA + 1])[3] |= 0x8000;
    if (nTotal >= 50) {
        CdsAssert__FPciPc("PMidasShieldRings.cpp", 0x184, "iNumVerts < fx_i_instance_max_vertices");
    }
    int *pHdr = (int *)__nwa__FUi(0x970);
    if (pHdr == 0) {
        CdsAssert__FPciPc("PMidasShieldRings.cpp", 0x18C, "apPacket");
    }
    pHdr[0] = nTotal;
    pHdr[1] = 0;
    pHdr[2] = 0;
    pHdr[3] = 0;
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pHdr + 0x10), (u_long128 *)sB, 0x32);
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pHdr + 0x330), (u_long128 *)sC, 0x32);
    QwordCopy__FP1P1Ui((u_long128 *)((char *)pHdr + 0x650), (u_long128 *)sA, 0x32);
    nCount = 0x970;
    return pHdr;
}

// DRAFT: 0x001F8B40 CreateRingTriStrip__17PMidasShieldRingsFiffiiPA4_fPA4_fPA4_f
// note: 19 differing words in loop body (0x00C8-0x014C): lui a1 placement, addu a3/t0 order, sll placement, pc1 base register, slt vs addiu s2 and div.s order; tried guard 0<n, hoisting fAng/fStep/nIdx, moving pc1 decl, (nIdx+1)<<4
int PMidasShieldRings::CreateRingTriStrip(int nSegs, float fA, float fB, int iC, int iD, float (*pA)[4], float (*pB)[4], float (*pC)[4]) {
    int nCount = nSegs * 2 + 2;
    float fAng = 0.0f;
    float fStep = 360.0f / (float)nSegs;
    int nIdx = 0;
    if (0 < nCount) {
        int nOff = 0;
        do {
            float fSin = FastMath_Sin180__Ff(fAng - 180.0f);
            float fCos = FastMath_Cos180__Ff(fAng - 180.0f);
            float *pa = (float *)((char *)pA + nOff);
            float *pb = (float *)((char *)pB + nOff);
            int *pc0 = (int *)((char *)pC + nOff);
            int *pc1 = (int *)((char *)pC + (nIdx + 1) * 16);
            pa[1] = fA * fCos;
            nIdx += 2;
            nOff += 0x20;
            pa[2] = fA * fSin;
            float fRatio = fA / fB;
            pa[0] = 0.0f;
            pa[3] = 1.0f;
            fAng += fStep;
            float fHalf = 0.5f * fRatio;
            pb[0] = 0.5f + fCos * fHalf;
            pb[1] = 0.5f + fSin * fHalf;
            pc0[0] = 0x80;
            pc0[1] = 0x80;
            pc0[2] = 0x80;
            pc0[3] = iC;
            pc1[0] = 0x80;
            pc1[1] = 0x80;
            pc1[2] = 0x80;
            pc1[3] = iD;
            pa[5] = fB * fCos;
            pa[6] = fB * fSin;
            pa[4] = 0.0f;
            pa[7] = 1.0f;
            pb[4] = 0.5f + 0.5f * fCos;
            pb[5] = 0.5f + 0.5f * fSin;
        } while (nIdx < nCount);
    }
    return nCount;
}

// FUNCTION: 0x001F8D10 FindFreeRing__17PMidasShieldRingsFv
int PMidasShieldRings::FindFreeRing() {
    int i = 0;
    int off = 0;
    do {
        if (m_unk15C[off] == 0) {
            return i;
        }
        i++;
        off += 0x14;
    } while (i < 8);
    return -1;
}

// DRAFT: 0x001F8D50 Emit__17PMidasShieldRingsFv
// note: 6 differing lines, constant registers swapped: orig loads -0.015 into f5 first, ours loads 0.03 there; tried local -0.015f, reversed add operands
int PMidasShieldRings::Emit() {
    int nIdx = FindFreeRing();
    if (nIdx >= 0) {
        char *pSlot = (char *)this + nIdx * 0x14;
        *(int *)(pSlot + 0x14C) = 0;
        *(float *)(pSlot + 0x150) = 1.0f / (120.0f + (15.0f * m_unk140));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pSlot + 0x154) = -0.015f + (0.03f * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)));
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        *(float *)(pSlot + 0x158) = -0.015f + (0.03f * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)));
        pSlot[0x15C] = 1;
        m_unk1EC++;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001F8E80 FadeAndDie__17PMidasShieldRingsFUi
void PMidasShieldRings::FadeAndDie(unsigned int uArg) {
    FadeAndDie__15PParticleSystemFUi(this, uArg);
    m_unk18 = 0;
}

// DRAFT: 0x001F8EB0 Render__17PMidasShieldRingsFv
// note: 49 differing lines; m_unk200 gate uses beqz to the epilogue, original uses bnez to body plus b to epilogue; tried nested gates, early returns, goto done
void PMidasShieldRings::Render() {
    if (m_unk15 == 0) {
        return;
    }
    if (m_unk1EC == 0) {
        return;
    }
    if (m_unk200 == 0) {
        goto done;
    }
    if (m_unk19 != 0) {
        float a[4] = {1.1f, 1.1f, 1.1f, 1.0f};
        SetMaterial__10PGfxEngineFPfbUlUl(gGfxEng, a, true, m_unk30, 0x50000);
    } else {
        float b[4] = {1.0f, 1.0f, 1.0f, 0.8f};
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk10, b, true, m_unk30, 0x50000);
    }
    BeginFxInstances__10PGfxEngineFPvib(gGfxEng, m_unk1F4, m_unk1F8, m_unk19);
    DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)gDisplayListPtr, m_unk1FC, m_unk200, false);
done:
    return;
}

// FUNCTION: 0x001F9440 Create__17PMidasShieldRingsFfffPfPfPffffiibb
void PMidasShieldRings::Create(float fA, float fB, float fC, float *pA, float *pB, float *pC, float fD, float fE, float fF, int nA, int nB, bool bA, bool bB) {
    if (m_unk1F4 != 0) {
        __dla__FPv(m_unk1F4);
        m_unk1F4 = 0;
        m_unk1F8 = 0;
    }
    m_unk1F4 = InitRingMeshPacket(m_unk1F8, nB, bA);
    if (m_unk1F4 == 0) {
        CdsAssert__FPciPc("PMidasShieldRings.cpp", 0x46, "mpRingMeshPacket");
    }
    memset((char *)this + 0x14C, 0, 0xA0);
    m_unk1EC = 0;
    m_unk1F0 = 0;
    m_unk1FC = 0;
    m_unk15 = 1;
    m_unk18 = 1;
    m_unk14 = 1;
    sceVu0UnitMatrix(m_unk40);
    m_unkC = 0x12;
    m_unk19 = bB;
    m_unk144 = nA;
    m_unk148 = 0;
    m_unk140 = fF;
    m_unk204 = 1;
    sceVu0CopyVector(m_unkE0, pA);
    sceVu0CopyVector(m_unkF0, pB);
    sceVu0CopyVector(m_unk100, pC);
    m_unk110 = fA;
    m_unk114 = fD;
    m_unk118 = 0;
    m_unk11C = 0;
    m_unk120 = fB;
    m_unk124 = 0.5f * (fE + fD);
    m_unk128 = 0;
    m_unk12C = 0;
    m_unk130 = fC;
    m_unk134 = fE;
    m_unk138 = 0;
    m_unk13C = 0;
    m_unkD0 = (int)(0.5f + (26731.0f + (-12208.0f * ((float)rand() / 2147483648.0f))));
}

// DRAFT: 0x001F9670 Create__17PMidasShieldRingsFb
// note: 6 differing words, all float constant loads: ours 8,5,2,-4 vs orig 8,-4,5,2; tried local fD before/after call, local fB, fD/fB declaration order
void PMidasShieldRings::Create(bool bFlag) {
    float fD = -4.0f;
    float fB = 5.0f;
    float a[4];
    float b[4];
    float c[4];
    if (bFlag) {
        a[0] = 1.0f;
        a[1] = 1.0f;
        a[2] = 1.0f;
        a[3] = 0.0f;
        b[0] = 1.0f;
        b[1] = 1.0f;
        b[2] = 1.0f;
        b[3] = 1.0f;
        c[0] = 1.0f;
        c[1] = 1.0f;
        c[2] = 1.0f;
        c[3] = 0.0f;
    } else {
        a[0] = 1.2f;
        a[1] = 1.2f;
        a[2] = 1.2f;
        a[3] = 0.0f;
        b[0] = 1.2f;
        b[1] = 1.2f;
        b[2] = 1.2f;
        b[3] = 0.6f;
        c[0] = 1.0f;
        c[1] = 1.0f;
        c[2] = 1.0f;
        c[3] = 0.0f;
    }
    Create(8.0f, fB, 2.0f, a, b, c, fD, 0.0f, 0.75f, 25, 10, bFlag, bFlag);
    m_unk30 = 0x44;
}

// FUNCTION: 0x001F9770 __dt__17PMidasShieldRingsFv
extern "C" void *__dt__17PMidasShieldRingsFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PMidasShieldRings *pSelf = (PMidasShieldRings *)pThis;
        *(void **)pThis = __vt__17PMidasShieldRings;
        if (pSelf->m_unk1F4 != 0) {
            __dla__FPv(pSelf->m_unk1F4);
            pSelf->m_unk1F4 = 0;
            pSelf->m_unk1F8 = 0;
        }
        pSelf->m_unk1EC = 0;
        pSelf->m_unk1FC = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001F9800 __ct__17PMidasShieldRingsFv
PMidasShieldRings::PMidasShieldRings() {
    __ct__15PParticleSystemFv(this);
    m_unk000 = __vt__17PMidasShieldRings;
    m_unk1F4 = 0;
    m_unk1F8 = 0;
    m_unk1EC = 0;
    m_unk1FC = 0;
}
