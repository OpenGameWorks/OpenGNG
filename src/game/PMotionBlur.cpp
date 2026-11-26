// FLAGS: -str readonly
#include "types.h"
#include "PMotionBlur.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void __destroy_new_array(void *pArray, void (*pDtor)(void *));
extern "C" void *__construct_new_array(void *pArray, void (*pCtor)(void *), void (*pDtor)(void *), unsigned int nElemSize, int nCount);
extern "C" void __ct__5PMat4Fv(void *pThis);
extern "C" void __dt__5PMat4Fv(void *pThis);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void __dl__FPv(void *pMem);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern char gGfxEng[1504384];
extern "C" void BeginFxRender__10PGfxEngineFv(void *pThis);
extern "C" void BeginMesh__10PGfxEngineF13eBoxIntersect(void *pThis, int eBox);
extern "C" void BeginVertexGlow__10PGfxEngineFv(void *pThis);
extern "C" void EndVertexGlow__10PGfxEngineFv(void *pThis);
extern "C" void EndFxRender__10PGfxEngineFv(void *pThis);
extern "C" void EndMesh__12PDisplayListFv(void *pThis);
extern "C" void FadeFullScreenMotionBlur__10PGfxEngineFci(void *pThis, char cTarget, int nFrames);
extern "C" void SetAmbientLight__10PGfxEngineFPf(void *pThis, float *pVec);
extern "C" void SetGlowSizeAndColor__10PGfxEngineFffPf(void *pThis, float fA, float fB, float *pColor);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nIndex, float *pVec, bool bFlag, unsigned long nA, unsigned long nB);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetZBufferUpdate__10PGfxEngineFb10eGsContext(void *pThis, bool bEnable, int eCtx);
extern "C" void UpdateLights__10PGfxEngineFv(void *pThis);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float *pScale);
extern "C" int RenderAllPolys__5PMeshFv(void *pThis);
extern "C" int Render__5PMeshFiPbb(void *pThis, int nArg, bool *pbOut, bool bFlag);

// Child-list view of PMNode fields m_unk14 (count), m_unk18 (index), m_unk1C (children).
struct PMNodeChildList {
    unsigned int m_unk0;
    unsigned int m_unk4;
    PMNode **m_unk8;
};

// FUNCTION: 0x001C8AE0 CreateBlurNodes__11PMotionBlurFP6PMNodeP6PMNode
void PMotionBlur::CreateBlurNodes(PMNode *poSourceObj, PMNode *poBlurObj) {
    PMNode *pFound;
    PMotionBlurEntry *pEntry;
    PMNode *pChild;
    PMNodeChildList *pList;
    int nCount;
    unsigned int nIndex;

    pFound = 0;
    nCount = 0;
    if (poSourceObj != 0 && poBlurObj != 0) {
        if (poSourceObj->m_unk10 != 0) {
            if (poSourceObj->m_unk08 != 0) {
                pFound = poBlurObj->Find(poSourceObj->m_unk08);
                if (pFound != 0) {
                    nCount = (int)pFound->m_unk10;
                }
            }
        }
        if (pFound != 0 && nCount != 0) {
            pEntry = (PMotionBlurEntry *)__nw__FUi(0xC);
            if (pEntry == 0) {
                CdsAssert__FPciPc("PMotionBlur.cpp", 0x12F, "apData");
            }
            pEntry->m_pMatrices = __construct_new_array(__nwa__FUi((m_unk88 << 6) + 0x10), __ct__5PMat4Fv, __dt__5PMat4Fv, 0x40, m_unk88);
            if (pEntry->m_pMatrices == 0) {
                CdsAssert__FPciPc("PMotionBlur.cpp", 0x132, "apData->pMatCache");
            }
            pEntry->m_unk4 = nCount;
            pEntry->m_pSource = poSourceObj;
            m_unk90.Add(pEntry);
        }
        pList = (PMNodeChildList *)&poSourceObj->m_unk14;
        if (pList == 0) {
            CdsAssert__FPciPc("PMotionBlur.cpp", 0x13C, "apoSourceChildList");
        }
        pList->m_unk4 = 0;
        pChild = 0;
        if (pList->m_unk0 != 0) {
            pChild = *pList->m_unk8;
        }
        if (pChild != 0) {
            do {
                CreateBlurNodes(pChild, poBlurObj);
                nIndex = pList->m_unk4 + 1;
                pList->m_unk4 = nIndex;
                pChild = 0;
                if (nIndex < pList->m_unk0) {
                    pChild = pList->m_unk8[pList->m_unk4];
                }
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x001C8CB0 Reset__11PMotionBlurFv
void PMotionBlur::Reset() {
    int nCount;
    int i;
    PMotionBlurEntry *pEntry;

    nCount = m_unk90.m_unk0;
    for (i = 0; i < nCount; i++) {
        pEntry = (i < m_unk90.m_unk0) ? (PMotionBlurEntry *)m_unk90.m_unk8[i] : 0;
        if (pEntry != 0) {
            if (pEntry->m_pMatrices != 0) {
                __destroy_new_array(pEntry->m_pMatrices, __dt__5PMat4Fv);
                pEntry->m_pMatrices = 0;
            }
            __dl__FPv(pEntry);
        }
    }
    if (m_unk90.m_unk8 != 0) {
        m_unk90.m_unk0 = 0;
        m_unk90.m_unk4 = 0;
    }
    memset(this, 0, 0x80);
    m_unk60 = 0;
    m_unk80 = 0;
    m_unk84 = 0;
    m_unkA0 = 0;
    m_unkA5 = 0;
}

// FUNCTION: 0x001C8DA0 Enable__11PMotionBlurFb
void PMotionBlur::Enable(bool value) {
    m_unkA4 = (unsigned char)value;
}

// DRAFT: 0x001C8DB0 Render__11PMotionBlurFv
// note: 226 words differ (size 0x3D4 vs 0x404); vScale's {1,1,1,0} initializer is @N at 0x249D40. First element read is sltu/beqz/b in the original: early-return epilogue 16 insns short, assert delay slot (nop vs lui a0), ramp arm order and register use, loop i/j in fp/s7/s6 not matched. Tried: fTime init above m_unkA4 test (238->228), if-form assert (same), m_unk8C operand order (same).
void PMotionBlur::Render() {
    PMotionBlurEntry *pEntry;
    float fTime;
    float fMid;
    float vBlend[4];
    int i;
    int nAge;
    int j;
    int nCount;

    fTime = 0.0f;
    if (m_unkA4 == 0) {
        FadeFullScreenMotionBlur__10PGfxEngineFci(gGfxEng, 0, 0);
        return;
    }
    ((m_unk90.m_unk0) ? (void)0 : CdsAssert__FPciPc("PMotionBlur.cpp", 0x91, "moBlurNodes.GetCount()"));
    pEntry = (m_unk90.m_unk0 != 0) ? (PMotionBlurEntry *)m_unk90.m_unk8[0] : 0;
    if (pEntry != 0) {
        fTime = ((PMNode *)pEntry->m_pSource)->GetFrameTime();
    }
    if (fTime < m_unk6C || !(fTime <= m_unk70)) {
        FadeFullScreenMotionBlur__10PGfxEngineFci(gGfxEng, 0, 10);
    } else if (m_unkA5 != 0) {
        FadeFullScreenMotionBlur__10PGfxEngineFci(gGfxEng, m_unk68, 0);
        m_unkA5 = 0;
    }
    if (fTime >= m_unk0 && fTime <= m_unk4) {
        fMid = 0.5f * (m_unk0 + m_unk4);
        if (fTime < fMid) {
            fTime = m_unk8C * ((fTime - m_unk0) / (fMid - m_unk0));
        } else {
            fTime = m_unk8C - m_unk8C * ((fTime - fMid) / (m_unk4 - fMid));
        }
    }
    for (i = 0; i < m_unk8; i++) {
        nAge = m_unkA0 - ((int *)m_pad0C)[i];
        if (nAge < 0) {
            nAge += m_unk88;
        }
        if (m_unk60) {
            float vScale[4] = {1.0f, 1.0f, 1.0f, 0.0f};
            vScale[3] = fTime / 128.0f;
            sceVu0ScaleVector(vBlend, (float *)((char *)this + i * 16 + 0x20), vScale);
            SetZBufferUpdate__10PGfxEngineFb10eGsContext(gGfxEng, 0, 0);
            BeginFxRender__10PGfxEngineFv(gGfxEng);
            SetGlowSizeAndColor__10PGfxEngineFffPf(gGfxEng, 0.6f, 0.6f, vBlend);
            SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, m_unk64, vScale, 1, 0x48, 0x50000);
        } else {
            SetAmbientLight__10PGfxEngineFPf(gGfxEng, (float *)((char *)this + i * 16 + 0x20));
            UpdateLights__10PGfxEngineFv(gGfxEng);
        }
        nCount = m_unk90.m_unk0;
        for (j = 0; j < nCount; j++) {
            pEntry = (j < m_unk90.m_unk0) ? (PMotionBlurEntry *)m_unk90.m_unk8[j] : 0;
            if (pEntry != 0) {
                SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, (char *)pEntry->m_pMatrices + (nAge << 6));
                if (m_unk60) {
                    BeginVertexGlow__10PGfxEngineFv(gGfxEng);
                    RenderAllPolys__5PMeshFv((void *)pEntry->m_unk4);
                    EndVertexGlow__10PGfxEngineFv(gGfxEng);
                } else {
                    BeginMesh__10PGfxEngineF13eBoxIntersect(gGfxEng, 2);
                    Render__5PMeshFiPbb((void *)pEntry->m_unk4, (int)fTime, 0, 0);
                    EndMesh__12PDisplayListFv(*(void **)(gGfxEng + 0x154C80));
                }
            }
        }
        if (m_unk60) {
            SetZBufferUpdate__10PGfxEngineFb10eGsContext(gGfxEng, 1, 0);
        }
        EndFxRender__10PGfxEngineFv(gGfxEng);
    }
}

// FUNCTION: 0x001C91C0 Update__11PMotionBlurFv
void PMotionBlur::Update() {
    char *pSrc;
    int nCount;
    int i;
    PMotionBlurEntry *pEntry;

    if (m_unkA4 != 0) {
        nCount = m_unk90.m_unk0;
        for (i = 0; i < nCount; i++) {
            pEntry = (i < m_unk90.m_unk0) ? (PMotionBlurEntry *)m_unk90.m_unk8[i] : 0;
            if (pEntry != 0) {
                pSrc = (char *)pEntry->m_pSource;
                char *pDst = (char *)pEntry->m_pMatrices + (m_unkA0 << 6);
                *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x40);
                *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x50);
                *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x60);
                *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x70);
            }
        }
        m_unkA0++;
        if (m_unkA0 < m_unk88) {
            return;
        }
        m_unkA0 = 0;
    }
}

// FUNCTION: 0x001C9280 Create__11PMotionBlurFP6PMNodeP6PMNodei
bool PMotionBlur::Create(PMNode *poSourceObj, PMNode *poBlurObj, int nCount) {
    if (poSourceObj == 0) {
        CdsAssert__FPciPc("PMotionBlur.cpp", 0x49, "poSourceObj");
    }
    if (poBlurObj == 0) {
        CdsAssert__FPciPc("PMotionBlur.cpp", 0x4A, "poBlurObj");
    }
    Reset();
    m_unk80 = poSourceObj;
    m_unk84 = poBlurObj;
    m_unk88 = nCount;
    m_unkA0 = 0;
    CreateBlurNodes(m_unk80, m_unk84);
    m_unkA4 = 0;
    return m_unk90.m_unk0 != 0;
}

// DRAFT: 0x001C9340 SetData__11PMotionBlurFP19tagMotionBlurParams
// note: 20 words differ, all register allocation (original i=t0 j=t1 k=t2 pSrc=a3 pEntry=a2; ours i=a2 j=a3 k=t0 pSrc=t1 pEntry=t2). Outer guard fixed by `0 < nCount` (was 45 words). Tried 8 variants: local declaration orders, scoping pSrc/pEntry, pDst placement.
void PMotionBlur::SetData(tagMotionBlurParams *pParams) {
    int nCount;
    int i;
    int k;
    int j;
    char *pDst;

    if (pParams == 0) {
        CdsAssert__FPciPc("PMotionBlur.cpp", 0x27, "pData");
    }
    if (pParams->m_unk8 >= 4) {
        CdsAssert__FPciPc("PMotionBlur.cpp", 0x28, "pData->iNumBlurObjects < MAX_BLUR_OBJECTS");
    }
    memcpy(this, pParams, 0x80);
    m_unkA0 = 0;
    m_unkA4 = 1;
    m_unkA5 = 1;
    nCount = m_unk90.m_unk0;
    if (0 < nCount) {
        i = 0;
        do {
            PMotionBlurEntry *pEntry = (i < m_unk90.m_unk0) ? (PMotionBlurEntry *)m_unk90.m_unk8[i] : 0;
            if (pEntry != 0) {
                char *pSrc = (char *)pEntry->m_pSource + 0x40;
                j = 0;
                k = 0;
                while (j < m_unk88) {
                    j++;
                    pDst = (char *)pEntry->m_pMatrices + k;
                    *(u_long128 *)(pDst + 0x00) = *(u_long128 *)(pSrc + 0x00);
                    k += 0x40;
                    *(u_long128 *)(pDst + 0x10) = *(u_long128 *)(pSrc + 0x10);
                    *(u_long128 *)(pDst + 0x20) = *(u_long128 *)(pSrc + 0x20);
                    *(u_long128 *)(pDst + 0x30) = *(u_long128 *)(pSrc + 0x30);
                }
            }
            i++;
        } while (i < nCount);
    }
}

// FUNCTION: 0x001C9480 __dt__11PMotionBlurFv
PMotionBlur::~PMotionBlur() {
    Reset();
}

// FUNCTION: 0x001C94E0 __ct__11PMotionBlurFv
PMotionBlur::PMotionBlur() {
    memset(this, 0, 0x80);
    m_unkA0 = 0;
    m_unk80 = 0;
    m_unk84 = 0;
    m_unk88 = 0;
    m_unkA4 = 0;
    m_unkA5 = 0;
    m_unk8C = 20.0f;
}
