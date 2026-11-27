// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Shadow.h"
#include "PShadowBuffer.h"

// TODO(header): foreign declarations
extern char gGfxEng[1504384];
extern "C" void *__dt__13PShadowVolumeFv(PShadowVolume *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" PShadowVolume *GetResource__16PParticleManagerFUi(void *pThis, unsigned int nId);

// TODO(header): foreign declarations (Render)
class EntityBaseClass;
extern void *mpFrustum__15EntityBaseClass;
extern "C" int IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(void *pFrustum, void *pBox, void *pMat);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void vu1SetWorldMatrix__FP5PMat4(void *pMat);
extern "C" void vu1BeginMesh__F13eBoxIntersect(int eResult);
extern "C" void vu1EndMesh__Fv(void);
extern "C" int Render__5PMeshFiPbb(void *pMesh, int nFlags, void *pFlag, int bFlag);

// DRAFT: 0x001B0200 Render__6ShadowFP15EntityBaseClass
// note: 53 words differ; the m_unk0/m_unk4 guard is beqz to our final return instead of the original's shared return-0 b with bnez into the body; single-exit and early-return forms tried (79 and 57 words), nested and combined guards at 53.
extern "C" int Render__6ShadowFP15EntityBaseClass(Shadow *pThis, EntityBaseClass *pEntity) {
    if (pThis->m_unkC != 0) {
        void *pInfo = *(void **)((char *)pEntity + 0x38);
        if (pInfo != 0) {
            float fValue = *(float *)((char *)pInfo + 0xB4);
            if (fValue != -1000.0f) {
                *(float *)((char *)pThis->m_unkC + 0x10) = fValue;
            }
        }
        return 0;
    }
    if (pThis->m_unk0 != 0 && pThis->m_unk4 != 0) {
        float aMatrix[4][4];
        sceVu0UnitMatrix(aMatrix);
        void *pInfo = *(void **)((char *)pEntity + 0x38);
        if (pInfo == 0) {
            return 0;
        }
        *(u_long128 *)aMatrix[3] = *(u_long128 *)((char *)pInfo + 0xB0);
        aMatrix[0][0] = pThis->m_unk8;
        aMatrix[2][2] = pThis->m_unk8;
        int eResult = IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(mpFrustum__15EntityBaseClass,
                                                               (char *)pThis->m_unk4 + 0x10, aMatrix);
        if (eResult == 0) {
            return 0;
        }
        gGfxEng[0x158E22] = 0;
        vu1SetWorldMatrix__FP5PMat4(aMatrix);
        vu1BeginMesh__F13eBoxIntersect(eResult);
        int nResult = Render__5PMeshFiPbb(pThis->m_unk4, 0x80, 0, 0);
        vu1EndMesh__Fv();
        gGfxEng[0x158E22] = 1;
        return nResult;
    }
    return 0;
}

// FUNCTION: 0x001B0340 __dt__6ShadowFv
extern "C" Shadow *__dt__6ShadowFv(Shadow *pThis, short nFlag) {
    if (pThis != 0) {
        if (pThis->m_unk4 != 0) {
            pThis->m_unk4 = 0;
        }
        if (pThis->m_unkC != 0) {
            ((PShadowBuffer *)(gGfxEng + 0x157000))->RemoveShadowVolume(pThis->m_unkC);
            __dt__13PShadowVolumeFv(pThis->m_unkC, 1);
            pThis->m_unkC = 0;
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001B03D0 __ct__6ShadowFQ26Shadow10ShadowTypeUi
extern "C" Shadow *__ct__6ShadowFQ26Shadow10ShadowTypeUi(Shadow *pThis, int eType, unsigned int nId) {
    pThis->m_unk0 = 0;
    switch (eType) {
    case Shadow::eShadowParticle:
        pThis->m_unkC = GetResource__16PParticleManagerFUi(gGfxEng + 0x154F00, nId);
        if (pThis->m_unkC == 0) {
            CdsAssert("Shadow.cpp", 0x27, "mpShadowVolume");
        }
        ((PShadowBuffer *)(gGfxEng + 0x157000))->AddShadowVolume(pThis->m_unkC);
        return pThis;
    }
    pThis->m_unk4 = 0;
    pThis->m_unkC = 0;
    return pThis;
}

// TODO(header): foreign declarations (float ctor)
extern void *mpResMgr__15EntityBaseClass;
extern "C" void *GetResource__16PResourceManagerFUib(void *pThis, unsigned int nId, bool bFlag);
extern "C" void *GetFirstMesh__6PMNodeFv(void *pThis);

// DRAFT: 0x001B0460 __ct__6ShadowFQ26Shadow10ShadowTypef
// note: 31 words differ; the else path puts the sw zero,4 in the delay slot of a b, ours stores before the branch, and the tail order differs. Tried: branch sense (beqz matched), duplicated m_unkC store in the early-return branch (worse).
extern "C" Shadow *__ct__6ShadowFQ26Shadow10ShadowTypef(Shadow *pThis, int eType, float fValue) {
    pThis->m_unk0 = 0;
    pThis->m_unkC = 0;
    if (eType != 0) {
        pThis->m_unk4 = 0;
        return pThis;
    }
    void *pNode = GetResource__16PResourceManagerFUib(mpResMgr__15EntityBaseClass, 0x81000004, true);
    if (pNode == 0) {
        CdsAssert("Shadow.cpp", 0x14, "pNode");
    }
    pThis->m_unk4 = GetFirstMesh__6PMNodeFv(pNode);
    pThis->m_unk8 = fValue;
    return pThis;
}
