// FLAGS: -str readonly
#pragma opt_strength_reduction off
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
extern unsigned char gInterface[0xA60];
extern float gUnitMatrix[16];
extern "C" int rand(void);
extern "C" void sceVu0ScaleVectorXYZ(float *dst, float *src, float fScale);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *GetResource__16PParticleManagerFUi(void *pMgr, unsigned int nId);
extern "C" void *Create__16PParticleManagerFUifffP6PMNodeb(void *pMgr, unsigned int nId, float fA, float fB, float fC, PMNode *pNode, bool bFlag);

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
    virtual void Slot3(void *pMat);
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Stop();
};

// FUNCTION: 0x001F9DF0 UpdateFxInstances__9PFrozenFxFv
void PFrozenFx::UpdateFxInstances() {
    int i;
    char *pNode;
    char *pDst;
    int nDst;
    int nSrc;
    nSrc = 0;
    nDst = 0;
    for (i = 0; i < m_unk1F8; i++) {
        pDst = (char *)m_unk1F4 + nDst;
        if (!(nSrc < m_unk1E8)) {
            CdsAssert__FPciPc("PFrozenFx.cpp", 0x16A, "aiNode < miNumInstances");
        }
        pNode = (char *)m_unkE0[nSrc];
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
// note: DIFF 87 under opt_strength_reduction off (85 before; i*0x500 and pList-bound loops 123-152); original keeps this in s2 and i in s0 and reloads the list from m_unk1EC at the loop bottom, ours keeps this in s0; frame 0x264 vs 0x26c. Tried: decl order, pList local (DIFF 122 without, 85 with), pList inside loop (120), signed index (85), -str readonly not needed.
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

// DRAFT: 0x001FA660 Create__9PFrozenFxFP6PMNodePffff
// note: DIFF 283 words; this/pNode/pVec get s6/s5/s4 (original s0/s6/s5), extra s7 CSE of this+0xE0, 0xA0 frame vs 0x90; &m_unkE0 args, inline pFirst and loop-1 base variants gave no change
int PFrozenFx::Create(PMNode *pNode, float *pVec, float fA, float fB, float fC) {
    if (pNode == 0) {
        CdsAssert__FPciPc("PFrozenFx.cpp", 0x35, "poModel");
    }
    m_unkD0 = (int)(0.5f + (13254.0f + 30258.0f * ((float)rand() / 2.1474836e9f)));
    m_unk0C = 0x14;
    m_unk204 = m_unkD0;
    if (pNode->m_unk04 == 2) {
        PArray *pList = (PArray *)&pNode->m_unk14;
        if (pList == 0) {
            CdsAssert__FPciPc("PFrozenFx.cpp", 0x3F, "apChildList");
        }
        pList->m_unk4 = 0;
        PMNode *pChild = (pList->m_unk0 != 0) ? (PMNode *)pList->m_unk8[0] : 0;
        GetValidNodes(pChild, (PMNode **)m_unkE0);
    } else {
        GetValidNodes(pNode, (PMNode **)m_unkE0);
    }
    PParticleSystem::Create(m_unk1E8, false);
    m_unk1EC = GetResource__16PParticleManagerFUi(gGfxEng + 0x154F00, 0x86000003);
    if (m_unk1EC == 0) {
        return 0;
    }
    m_unk1E0 = __nwa__FUi(m_unk1E8 * 0x60);
    if (m_unk1E0 == 0) {
        CdsAssert__FPciPc("PFrozenFx.cpp", 0x54, "mpInstanceData");
    }
    m_unk1E4 = 0;
    m_unk1FC = fB;
    m_unk200 = fC;
    int nSrc = 0;
    int nDst = 0;
    for (int i = 0; i < m_unk1E8; i++) {
        char *pDst = (char *)m_unk1E0 + nDst;
        if (*(void **)((char *)this + 0xE0 + nSrc) == 0) {
            CdsAssert__FPciPc("PFrozenFx.cpp", 0x60, "apNode");
        }
        m_unkD0 = m_unkD0 * 0x343FD + 0x269EC3;
        float fScale = 1.0f + (-fA + (fA + fA) * (0.000030517578f * (float)((m_unkD0 >> 16) & 0x7FFF)));
        sceVu0ScaleVectorXYZ((float *)(pDst + 0x40), pVec, fScale);
        *(float *)(pDst + 0x4C) = pVec[3];
        asm {
            lui v0, 0x3F80
            dsll32 v0, v0, 0
            pcpyld v0, v0, zero
            sq v0, 0x50(pDst)
        }
        nDst += 0x60;
        nSrc += 4;
    }
    memcpy((char *)this + 0x80, (char *)pNode + 0x110, 0x20);
    void *pFirst = *(void **)((char *)this + 0xE0);
    if (pFirst != 0) {
        ((PFrozenFxView *)this)->Slot3((char *)pFirst + 0x40);
    }
    m_unk1F0 = Create__16PParticleManagerFUifffP6PMNodeb(gInterface + 0x4F0, 0x830001D8, 0.0f, 0.0f, 0.0f, 0, false);
    if (m_unk1F0 == 0) {
        CdsAssert__FPciPc("PFrozenFx.cpp", 0x73, "mpMasterFx");
    }
    int n = m_unk1E8 / 4;
    m_unk1F8 = (n < 2) ? 1 : n;
    m_unk1F4 = __nwa__FUi(m_unk1F8 * 0x50);
    if (m_unk1F4 == 0) {
        CdsAssert__FPciPc("PFrozenFx.cpp", 0x77, "mpFxInstanceData");
    }
    nDst = 0;
    nSrc = 0;
    for (int i = 0; i < m_unk1F8; i++) {
        char *pDst = (char *)m_unk1F4 + nDst;
        if (!(nSrc < m_unk1E8)) {
            CdsAssert__FPciPc("PFrozenFx.cpp", 0x7E, "aiNode < miNumInstances");
        }
        char *pNodeE = ((char **)((char *)this + 0xE0))[nSrc];
        if (pNodeE == 0) {
            CdsAssert__FPciPc("PFrozenFx.cpp", 0x81, "apNode");
        }
        nDst += 0x50;
        nSrc += 4;
        *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pNodeE + 0x40);
        *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pNodeE + 0x50);
        *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pNodeE + 0x60);
        *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pNodeE + 0x70);
        asm {
            lui v1, 0x3F80
            dsll32 v0, v1, 0
            or v0, v1, v0
            pcpyld v0, v0, v0
            sq v0, 0x40(pDst)
        }
    }
    return 1;
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

// FUNCTION: 0x001FABA0 __ct__9PFrozenFxFv
PFrozenFx::PFrozenFx() {
    *(void **)this = __vt__9PFrozenFx;
    m_unk1E0 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1F8 = 0;
    memset(m_unkE0, 0, 0x100);
}
