#include "types.h"
#include "PFallingShellsFx.h"
#include "PMat4.h"
#include "PGfxEngine.h"

// TODO(header): foreign declarations
class PShader {
public:
    void Render(int nFlags, bool bFlag, bool *pOut);
};
void FastMath_RotateMatrix(float (*)[4][4], float (*)[4][4], float (*)[4], float (*)[4][4]);
extern "C" void DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(void *pThis, void *pData, int nCount, bool bFlag);
extern char gUnk45B300[16];
extern float gUnitMatrix[16];
extern PGfxEngine gGfxEng;
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0CopyMatrix(float (*)[4], float (*)[4]);
extern "C" int rand();
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" int GetResource__16PParticleManagerFUi(void *pThis, unsigned int nId);
extern unsigned char __vt__16PFallingShellsFx[];

// FUNCTION: 0x0020CB90 FindFreeShell__16PFallingShellsFxFv
int PFallingShellsFx::FindFreeShell() {
    int i;
    int off;
    for (i = 0, off = 0; i < 0x40; i++, off += 0x70) {
        if (((unsigned char *)this)[off + 0x1B2] == 0) {
            return i;
        }
    }
    return -1;
}

static const float kUnitW[4] = {0.0f, 0.0f, 0.0f, 1.0f};
static const float kOneW[4] = {1.0f, 1.0f, 1.0f, 1.0f};

// DRAFT: 0x0020CBD0 SpawnShell__16PFallingShellsFxFv
// note: DIFF 100, size 0x28c vs 0x284. Sample sequence and stores match; FP register roles differ in x/z blocks (ours f1/f0 swapped), bltz target 0x97 vs 0x95, and kUnitW rodata load vs original register-built {0,0,0,1}. Tried load order swap (no change) and 128-bit shift for the unit vector (MWCC rejects shift by 96).
void PFallingShellsFx::SpawnShell() {
    int idx;
    int off;
    char *pShell;
    float fA;
    float fB;
    float fC;
    float fD;

    idx = FindFreeShell();
    if (idx < 0) {
        return;
    }
    off = ((idx << 3) - idx) << 4;
    pShell = (char *)this + off + 0x150;
    *(u_long128 *)pShell = *(u_long128 *)m_unkF0;

    fD = m_unk110[0];
    fC = m_unk120[0];
    fA = fC - fD;
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    fB = (float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f;
    *(float *)(pShell + 0x20) = fD + fA * fB;

    fC = m_unk120[2];
    fD = m_unk110[2];
    fA = fC - fD;
    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    fB = (float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f;
    *(float *)(pShell + 0x28) = fD + fA * fB;

    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    fB = (float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f;
    sceVu0ScaleVector((float *)(pShell + 0x20), (float *)(pShell + 0x20), 0.2f + 0.2f * fB);

    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    fB = (float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f;
    *(float *)(pShell + 0x24) = 0.5f + 0.25f * fB;

    *(int *)(pShell + 0x5C) = 0xBDCA233A;
    *(int *)(pShell + 0x58) = 0x3C23D70A;
    *(float *)(pShell + 0x54) = m_unk144;
    *(unsigned char *)(pShell + 0x60) = 0;
    *(unsigned char *)(pShell + 0x61) = 0;
    *(u_long128 *)(pShell + 0x40) = *(u_long128 *)kUnitW;

    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    fB = (float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f;
    *(float *)(pShell + 0x40) = 15.0f + (-5.0f * fB);

    m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
    fB = (float)((m_unkD0 >> 16) & 0x7FFF) * 0.000030517578125f;
    *(float *)(pShell + 0x44) = 5.0f + 5.0f * fB;

    *(u_long128 *)(pShell + 0x30) = *(u_long128 *)kUnitW;
    *(int *)(pShell + 0x10) = 0;
    *(int *)(pShell + 0x14) = 0;
    *(int *)(pShell + 0x18) = 0;
    *(float *)(pShell + 0x1C) = 1.0f;
    *(float *)(pShell + 0x50) = 1.0f;
    *(unsigned char *)(pShell + 0x62) = 1;
    m_unk1D50++;
}

// DRAFT: 0x0020CE60 ModifyPosition__16PFallingShellsFxFP5PMat4
// note: DIFF 39; original frame 0x90 with this in s0, no dtor call, row-3 (0,0,0,1) store at sp+0x70. Tried float mat[4][4] local (DIFF 42), kept PMat4 local.
void PFallingShellsFx::ModifyPosition(PMat4 *pMat) {
    float vec[4];
    PMat4 mat;
    float dir[4];

    if (pMat == 0) {
        CdsAssert__FPciPc("PFallingShellsFx.cpp", 0x113, "pMat");
    }
    pMat->MulVector(m_unkF0, m_unkE0);
    *(u_long128 *)vec = *(u_long128 *)kUnitW;
    vec[1] = m_unk140;
    pMat->MulVector(vec, vec);
    m_unk144 = vec[1];
    sceVu0UnitMatrix((float *)&mat);
    sceVu0CopyMatrix((float (*)[4])&mat, (float (*)[4])pMat);
    mat.MulVector(dir, m_unk100);
    SetDirection(dir);
}

// FUNCTION: 0x0020CF40 SetDirection__16PFallingShellsFxFPf
void PFallingShellsFx::SetDirection(float *pDir) {
    float mat[4][4];

    sceVu0UnitMatrix((float *)mat);
    ((PMat4 *)mat)->RotateY(0.5f * m_unk138);
    ((PMat4 *)mat)->MulVector(m_unk110, pDir);
    sceVu0Normalize(m_unk110, m_unk110);
    sceVu0UnitMatrix((float *)mat);
    ((PMat4 *)mat)->RotateY(-0.5f * m_unk138);
    ((PMat4 *)mat)->MulVector(m_unk120, pDir);
    sceVu0Normalize(m_unk120, m_unk120);
}

// Resource referenced by m_unk148: shader at 0x00, entry count at 0x08, entry table at 0x0C.
struct FxResource {
    PShader *pShader;
    int _pad04;
    int nCount;
    int *pEntries;
};

// DRAFT: 0x0020CFF0 Render__16PFallingShellsFxFv
// note: DIFF 88. Early-return exits sit at 0x60/0x5D/0x59 vs original 0x66/0x63/0x5F; from 0x90 the original reloads m_unk148 into v1 and tests nCount via lw v0,8(v1)/sltu, ours uses a0/beqz. Tried != 0 test (88), block-local count (89), split early returns (107).
void PFallingShellsFx::Render() {
    int i;
    int off;
    int rec;

    if (!m_unk15 || !m_unkA4 || !m_unk1D50) {
        return;
    }
    gGfxEng.SetZBufferUpdate(true, (eGsContext)0);
    gGfxEng.SetWorldMatrix((PMat4 *)gUnitMatrix);

    ((FxResource *)m_unk148)->pShader->Render(0x7E, true, 0);

    gGfxEng.BeginFxInstances((((FxResource *)m_unk148)->nCount) ? (void *)((FxResource *)m_unk148)->pEntries[1] : 0,
                             (((FxResource *)m_unk148)->nCount) ? ((FxResource *)m_unk148)->pEntries[0] : 0, false);

    if (m_unk1D50 * 96 >= 0x2000) {
        CdsAssert__FPciPc("PFallingShellsFx.cpp", 0xC5, "miNumInstances * sizeof(VuFxInstance) < SPAD_TEMP_BUFFER_SIZE");
    }

    rec = 0;
    for (i = 0, off = 0; i < 0x40; i++, off += 0x70) {
        if (*(unsigned char *)((char *)this + off + 0x1B2) != 0) {
            char *pShell = (char *)this + off + 0x150;
            char *pRec = (char *)0x70001000 + rec;
            FastMath_RotateMatrix((float (*)[4][4])pRec, 0, (float (*)[4])(pShell + 0x10), 0);
            *(u_long128 *)(pRec + 0x30) = *(u_long128 *)pShell;
            *(u_long128 *)(pRec + 0x40) = *(u_long128 *)kOneW;
            *(float *)(pRec + 0x4C) = *(float *)(pShell + 0x50);
            rec += 0x60;
        }
    }

    DrawFxInstances__12PDisplayListFP15tagVuFxInstanceib(*(void **)gUnk45B300, (void *)0x70001000, m_unk1D50, true);
    gGfxEng.SetZBufferUpdate(false, (eGsContext)0);
}

// FUNCTION: 0x0020D610 Create__16PFallingShellsFxFfPfPffff
int PFallingShellsFx::Create(float fA, float *pA, float *pB, float fC, float fD, float fE) {
    m_unkD0 = (int)(0.5f + (23154.0f + 20367.0f * ((float)rand() / 2147483648.0f)));
    m_unk0C = 0x19;
    m_unk14C = m_unkD0;
    PParticleSystem::Create(1, false);
    m_unk148 = GetResource__16PParticleManagerFUi((void *)((char *)&gGfxEng + 0x154F00), 0x8600001F);
    if (m_unk148 == 0) {
        return 0;
    }
    memcpy(m_unkF0, pA, 0x10);
    memcpy(m_unkE0, pA, 0x10);
    *(int *)&m_unkF0[3] = 0x3F800000;
    m_unk130 = fA;
    m_unk134 = fA;
    m_unk140 = fD;
    m_unk144 = fD;
    m_unk138 = fC;
    m_unk13C = fE;
    memcpy(m_unk100, pB, 0x10);
    SetDirection(pB);
    return 1;
}

// FUNCTION: 0x0020D780 __dt__16PFallingShellsFxFv
extern "C" void *__dt__16PFallingShellsFxFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PFallingShellsFx *pSelf = (PFallingShellsFx *)pThis;
        *(void **)pThis = __vt__16PFallingShellsFx;
        pSelf->m_unk148 = 0;
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x0020D7F0 __ct__16PFallingShellsFxFv
// note: DIFF 19; original keeps this in s0 without spill to 0x1C(sp); memset from 0x14C variant left the count unchanged.
PFallingShellsFx::PFallingShellsFx() {
    *(void **)this = __vt__16PFallingShellsFx;
    m_unk148 = 0;
    memset((char *)this + 0x14C, 0, 0x1C00);
    *(int *)((char *)this + 0x1D4C) = 0;
}
