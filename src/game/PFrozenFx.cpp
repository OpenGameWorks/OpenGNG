#include "types.h"
#include "PFrozenFx.h"
#include "PMNode.h"
#include "PArray.h"
#include "PGfxEngine.h"
#include "PDisplayList.h"
#include "PShader.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern unsigned char __vt__9PFrozenFx[];
extern char gGfxEng[1504384];
extern float gUnitMatrix[16];

// Child object stored at m_unk1F0. Only the slots this file calls are named;
// slot N is virtual number (N - 8) / 4.
class PFrozenFxChild {
public:
    virtual ~PFrozenFxChild();
    virtual void Slot1(float fArg);
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5(unsigned int nFlag);
    virtual void Slot6();
};

// View of PFrozenFx's own vtable (stored by hand in the constructor). Slot N
// is virtual number (N - 8) / 4; only the slot 0x24 entry (Stop) is called.
class PFrozenFxView {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Stop();
};

// DRAFT: 0x001F9DF0 UpdateFxInstances__9PFrozenFxFv
// note: original recomputes nSrc*4 with sll each pass and keeps 7 saved regs, frame 0x70; MW strength-reduces the index (DIFF 57). Tried array-index form, decl reorder, -str readonly (61).
void PFrozenFx::UpdateFxInstances() {
    int nSrc = 0;
    int nDst = 0;
    for (int i = 0; i < m_unk1F8; i++) {
        char *pDst = (char *)m_unk1F4 + nDst;
        if (!(nSrc < m_unk1E8)) {
            CdsAssert__FPciPc("PFrozenFx.cpp", 0x16A, "aiNode < miNumInstances");
        }
        char *pNode = ((char **)((char *)this + 0xE0))[nSrc];
        if (pNode == 0) {
            CdsAssert__FPciPc("PFrozenFx.cpp", 0x16D, "apNode");
        }
        nDst += 0x50;
        nSrc += 4;
        *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pNode + 0x40);
        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pNode + 0x50);
        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pNode + 0x60);
        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pNode + 0x70);
    }
}

// FUNCTION: 0x001FA130 GetValidNodes__9PFrozenFxFP6PMNodePP6PMNode
void PFrozenFx::GetValidNodes(PMNode *pNode, PMNode **ppOut) {
    if (pNode->m_unk10 != 0) {
        if (m_unk1E8 >= 0x41) {
            return;
        }
        ppOut[m_unk1E8] = pNode;
        m_unk1E8++;
    }
    PArray *pList = (PArray *)&pNode->m_unk14;
    if (pList != 0) {
        pList->m_unk4 = 0;
        PMNode *pChild = (pList->m_unk0 != 0) ? (PMNode *)pList->m_unk8[0] : 0;
        while (pChild != 0) {
            GetValidNodes(pChild, ppOut);
            int nIdx = pList->m_unk4 + 1;
            pList->m_unk4 = nIdx;
            pChild = (nIdx < pList->m_unk0) ? (PMNode *)pList->m_unk8[pList->m_unk4] : 0;
        }
    }
}

// FUNCTION: 0x001FA210 Stop__9PFrozenFxFv
void PFrozenFx::Stop() {
    m_unk18 = 0;
    void *pChild = m_unk1F0;
    if (pChild != 0) {
        ((PFrozenFxChild *)pChild)->Slot6();
        UpdateFxInstances();
    }
    m_unk1E4 = 0;
}

// FUNCTION: 0x001FA260 Start__9PFrozenFxFv
void PFrozenFx::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    void *pChild = m_unk1F0;
    if (pChild != 0) {
        ((PFrozenFxChild *)pChild)->Slot6();
        UpdateFxInstances();
    }
    m_unk1E4 = 0;
}

// FUNCTION: 0x001FA2C0 FadeAndDie__9PFrozenFxFUi
void PFrozenFx::FadeAndDie(unsigned int nFlag) {
    ((PFrozenFxView *)this)->Stop();
    if (m_unk1F0 != 0) {
        UpdateFxInstances();
        ((PFrozenFxChild *)m_unk1F0)->Slot5(nFlag);
    }
}

// Shader and fx-instance list at m_unk1EC: shader pointer at 0, count at 8, entries at 0xC.
struct PFrozenFxFxEntry {
    int nSize;                  // 0x0
    void *pData;                // 0x4
};

struct PFrozenFxFxList {
    PShader *pShader;           // 0x0
    int m_unk4;                 // 0x4
    int nCount;                 // 0x8
    PFrozenFxFxEntry *pEntries; // 0xC
};

// DRAFT: 0x001FA320 Render__9PFrozenFxFv
// note: DIFF 85; original keeps this in s2 and i in s0 and reloads the list from m_unk1EC at the loop bottom, ours keeps this in s0; frame 0x264 vs 0x26c. Tried: decl order, pList local (DIFF 122 without, 85 with), pList inside loop (120), signed index (85), -str readonly not needed.
void PFrozenFx::Render() {
    if (m_unk1EC != 0 && m_unk15 != 0 && m_unkA4 != 0) {
        ((PGfxEngine *)gGfxEng)->SetZBufferUpdate(true, (eGsContext)0);
        ((PGfxEngine *)gGfxEng)->SetWorldMatrix((PMat4 *)gUnitMatrix);
        ((PFrozenFxFxList *)m_unk1EC)->pShader->Render(0x80, true, 0);
        PFrozenFxFxList *pList = (PFrozenFxFxList *)m_unk1EC;
        for (unsigned int i = 0; i < (unsigned int)((PFrozenFxFxList *)m_unk1EC)->nCount; i++) {
            int nSize = (i < (unsigned int)pList->nCount) ? pList->pEntries[i].nSize : 0;
            void *pData = (i < (unsigned int)pList->nCount) ? pList->pEntries[i].pData : 0;
            ((PGfxEngine *)gGfxEng)->BeginFxInstances(pData, nSize, false);
            (*(PDisplayList **)(gGfxEng + 0x154C80))->DrawFxInstances((struct tagVuFxInstance *)m_unk1E0, m_unk1E4, false);
        }
        ((PGfxEngine *)gGfxEng)->SetZBufferUpdate(false, (eGsContext)0);
    }
    if (m_unk1F0 != 0 && ((PParticleSystem *)m_unk1F0)->m_unk15 != 0 && m_unkA4 != 0) {
        float aVec[4];
        sceVu0CopyVector(aVec, &((PParticleSystem *)m_unk1F0)->m_unkC0);
        ((PGfxEngine *)gGfxEng)->SetMaterial((int)((PParticleSystem *)m_unk1F0)->m_unk10, aVec, true, ((PParticleSystem *)m_unk1F0)->m_unk30, 0x50000);
        unsigned int nRemain = ((PParticleSystem *)m_unk1F0)->m_unk04;
        unsigned int nChunks = nRemain / 40 + ((nRemain % 40) ? 1 : 0);
        char *pBase = (char *)((PParticleSystem *)m_unk1F0)->m_unk08;
        int nOff = 0;
        for (unsigned int i = 0; i < nChunks; i++) {
            unsigned int nCount = (nRemain < 0x28) ? nRemain : 0x28;
            nRemain -= nCount;
            ((PGfxEngine *)gGfxEng)->BeginParticleInstances((struct tagVuParticle *)(pBase + nOff), nCount, ((PParticleSystem *)m_unk1F0)->m_unkB8, ((PParticleSystem *)m_unk1F0)->m_unkBC, false);
            (*(PDisplayList **)(gGfxEng + 0x154C80))->DrawStaticInstances((struct tagVuStaticInstance *)m_unk1F4, m_unk1F8, 0x28, 0, 1, false);
            nOff += 0x500;
        }
    }
}

// FUNCTION: 0x001FA590 Animate__9PFrozenFxFf
void PFrozenFx::Animate(float fArg) {
    float fStep = fArg;
    if (m_unk1F0 == 0) {
        CdsAssert__FPciPc("PFrozenFx.cpp", 0x96, "mpMasterFx");
    }
    m_unk16 = ((PFrozenFx *)m_unk1F0)->m_unk16;
    m_unk15 = m_unk18;
    m_unkD0 = m_unk204;
    int nStep = m_unk1E4 + 2;
    m_unk1E4 = (m_unk1E8 < nStep) ? m_unk1E8 : nStep;
    if (m_unk15 != 0 && m_unk16 == 0 && m_unkA4 != 0) {
        UpdateMeshInstances();
    }
    if (m_unk1F0 != 0) {
        ((PFrozenFxChild *)m_unk1F0)->Slot1(fStep);
    }
}

// FUNCTION: 0x001FAAE0 __dt__9PFrozenFxFv
extern "C" void *__dt__9PFrozenFxFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PFrozenFx *pSelf = (PFrozenFx *)pThis;
        *(void **)pThis = __vt__9PFrozenFx;
        if (pSelf->m_unk1E0 != 0) {
            __dla__FPv(pSelf->m_unk1E0);
            pSelf->m_unk1E0 = 0;
        }
        if (pSelf->m_unk1F4 != 0) {
            __dla__FPv(pSelf->m_unk1F4);
            pSelf->m_unk1F4 = 0;
        }
        if (pSelf->m_unk1F0 != 0) {
            delete (PFrozenFxChild *)pSelf->m_unk1F0;
            pSelf->m_unk1F0 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001FABA0 __ct__9PFrozenFxFv
// note: original spills this to 0x1C(sp) and reloads it before each store; ours keeps it in s0 (DIFF 25 words, size 0x48 vs 0x70).
PFrozenFx::PFrozenFx() {
    *(void **)this = __vt__9PFrozenFx;
    m_unk1E0 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1F8 = 0;
    memset(m_unkE0, 0, 0x100);
}
