// FLAGS: -str readonly
#include "PSkeleton.h"
#include "types.h"

// TODO(header): foreign declarations
extern unsigned char __vt__9PSkeleton[0x40];
extern "C" void *Find__6PMNodeFUi(void *pThis, unsigned int nId);
extern "C" void RecurseEnableBone__6PMNodeFP6PArrayb(void *pNode, void *pArr, bool bFlag);
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void __dt__9PMeshNodeFv(void *pThis, short nFlag);
extern "C" void InitMembers__9PMeshNodeFv(void *pThis);
extern "C" void __dl__FPv(void *pMem);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nCount);
extern "C" void BuildDispList__6PMNodeFP6PArray(void *pThis, void *pArr);
extern "C" int Create__18PObjectDisplayListFP6PArrayP6PMNodeP5PMeshPb(void *pThis, void *pArr, void *pNode, void *pMesh, bool *pFlag);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" float sqrtf(float fValue);
extern "C" PObjectDisplayList *__ct__18PObjectDisplayListFv(PObjectDisplayList *pThis);
extern "C" void __dt__18PObjectDisplayListFv(PObjectDisplayList *pThis, short nFlag);
extern "C" void *FindBone__6PMNodeFUi(void *pThis, unsigned int nId);
extern "C" int Animate__6PMNodeFffP5PMat4ib(void *pThis, float fTime, float fDelta, PMat4 *pMat, int nFlag, bool bFlag);
extern "C" int GetDeltaMove__6PMNodeFP10PAnimFramePA4_f(void *pThis, void *pFrame, float (*pMat)[4]);
extern "C" void sceVu0ApplyMatrix(void *pDst, void *pMat, void *pSrc);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void InitMembers__6PMNodeFv(void *pThis);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void CopyMNode__6PMNodeFR6PMNodeb(void *pThis, void *pSrc, bool bFlag);
extern "C" void AddFxTriggers__6PMNodeFP6PArrayb(void *pThis, void *pArr, bool bFlag);
extern "C" void RecurseDetachAnim__6PMNodeFv(void *pThis);
extern "C" void *__ct__10PAnimFrameFs(void *pThis, short nFlag);
extern unsigned char __vt__9PResource[0x40];
extern unsigned char __vt__6PMNode[0x40];
extern unsigned char __vt__9PMeshNode[0x40];
extern char gGfxEng[1504384];
extern "C" int Render__18PObjectDisplayListF13eBoxIntersect(void *pThis, int nBox);
extern "C" void BeginMatrixList__12PDisplayListFv(void *pThis);
extern "C" void EndMatrixList__12PDisplayListFv(void *pThis);
extern "C" void AddBoneMatrixToDisplayList__6PMNodeFb(void *pThis, bool bFlag);
extern "C" void BeginSharedMesh__10PGfxEngineF13eBoxIntersectP6PMNode(void *pThis, int nBox, void *pNode);
extern "C" int Render__5PMeshFiPbb(void *pThis, int nScale, bool *pFlag, bool bFlag);
extern "C" void ComputeLights__13PLightManagerFP5PMeshP5PMat4bbbP21tagComputedLightCachef(void *pThis, void *pMesh, void *pMat, bool bA, bool bB, bool bC, void *pCache, float fScale);
extern "C" void vu1SetWorldMatrix__FP5PMat4(void *pMat);
extern "C" void vu1BeginMesh__F13eBoxIntersect(int nBox);
extern "C" void vu1EndMesh__Fv(void);
extern "C" void DebugDrawBox__6PMNodeFi(void *pThis, int nMode);
extern "C" int LoadBone__6PMNodeFP8PPakFileP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion);
extern "C" int LoadFxTriggers__6PMNodeFP8PPakFile(void *pThis, PPakFile *pFile);
extern "C" int LoadMesh__6PMNodeFP8PPakFileP6PArray16ePsx2FileVersion(void *pThis, PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuf, unsigned int nSize);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);

class AnimData;

// Object held at PSkeleton+0x24. Slot 0x1C is the frame query; slots 0..4 and 6..8 are unknown.
class PFrameSourceView {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9(AnimData *pAnim);
    virtual void Slot10();
    virtual float Slot11();
};

// FUNCTION: 0x001974D0 CreateObjectDisplayList__9PSkeletonFv
int PSkeleton::CreateObjectDisplayList() {
    PObjectDisplayList *p = m_unkF8;
    if (p != 0) {
        __dt__18PObjectDisplayListFv(p, 1);
        m_unkF8 = 0;
    }
    p = (PObjectDisplayList *)__nw__FUi(0x1F0);
    if (p != 0) {
        p = __ct__18PObjectDisplayListFv(p);
    }
    m_unkF8 = p;
    if (m_unkF8 == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x2EC, "mpObjDisplayList");
    }
    m_unk18 = 0;
    void *pNode = 0;
    if (m_unk14 != 0) {
        pNode = m_unk1C[0];
    }
    if (Create__18PObjectDisplayListFP6PArrayP6PMNodeP5PMeshPb(m_unkF8, m_unk150, pNode, m_unk10, &m_unkD4) == 0) {
        __dt__18PObjectDisplayListFv(m_unkF8, 1);
        m_unkF8 = 0;
        return 0;
    }
    return 1;
}

// FUNCTION: 0x001975A0 EnableBone__9PSkeletonFPUib
void PSkeleton::EnableBone(unsigned int *pIds, bool bEnable) {
    unsigned int nId;
    while ((nId = *pIds++) != 0) {
        void *pNode = Find__6PMNodeFUi(this, nId);
        if (pNode != 0) {
            RecurseEnableBone__6PMNodeFP6PArrayb(pNode, &m_unk150, bEnable);
        }
    }
    VSlot3(nId);
}

// DRAFT: 0x00197620 SetSharedBonePtr__9PSkeletonFP5PMesh
// note: frame and register set differ; the loop-invariant pMesh+4 is CSE'd into a pointer (addiu s7) and nId lands in fp. Tried decl order, pointer cast, and byte-offset loads; all DIFF 77.
void PSkeleton::SetSharedBonePtr(PMesh *pMesh) {
    if (pMesh == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x2BF, "pSharedMesh");
    }
    unsigned int i = 0;
    unsigned int nCount = *(unsigned int *)((unsigned char *)pMesh + 4);
    if (nCount != 0) {
        unsigned int nOff = 0;
        do {
            unsigned char *pFrag;
            if (i < *(unsigned int *)((unsigned char *)pMesh + 4)) {
                pFrag = *(unsigned char **)pMesh + nOff;
            } else {
                pFrag = 0;
            }
            if (pFrag == 0) {
                CdsAssert__FPciPc("PSkeleton.cpp", 0x2C8, "apFragment");
            }
            unsigned int nId = *(unsigned int *)(pFrag + 0x64);
            m_unk18 = 0;
            void *pNode = 0;
            if (m_unk14 != 0) {
                pNode = m_unk1C[0];
            }
            if (pNode == 0) {
                CdsAssert__FPciPc("PSkeleton.cpp", 0x2CC, "apRootBone");
            }
            i++;
            *(void **)(pFrag + 0x64) = FindBone__6PMNodeFUi(pNode, nId);
            nOff += 0x90;
        } while (i < nCount);
    }
}

// FUNCTION: 0x00197760 SetFrameTime__9PSkeletonFf
void PSkeleton::SetFrameTime(float fTime) {
    m_unk38 = m_unk34;
    m_unk34 = fTime;
    m_unk3E |= 8;
    void *pSrc = m_unk24;
    if (pSrc != 0) {
        ((PFrameSourceView *)pSrc)->Slot5();
        m_unk18 = 0;
        void *pChild;
        if (m_unk14 != 0) {
            pChild = m_unk1C[0];
        } else {
            pChild = 0;
        }
        *(float *)((unsigned char *)pChild + 0x34) = fTime;
        *(float *)((unsigned char *)pChild + 0x38) = fTime;
    }
}

// DRAFT: 0x001977E0 RecurseAttachAnim__9PSkeletonFP22PMeshNodeAnimDataTable
// note: DIFF 66 words, size 0x1D0 vs 0x1C8; loop regs (offset/pEntry/pChild) and AnimSetup store order differ; nOff variants gave 68.
int PSkeleton::RecurseAttachAnim(PMeshNodeAnimDataTable *pTable) {
    struct AnimSetup {
        short a;
        short nMax;
        short c;
        short d;
        short e;
        float f;
    };

    if (pTable == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x266, "pAnimDataTable");
    }
    m_unk18 = 0;
    void *pNode = 0;
    if (m_unk14 != 0) {
        pNode = m_unk1C[0];
    }
    m_unk3F = 0;
    m_unk2C = 1.0f;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk38 = 0;
    RecurseDetachAnim__6PMNodeFv(pNode);

    char *pEntries = *(char **)((char *)pTable + 0xC);
    if (pEntries == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x272, "apAnimTable");
    }
    unsigned int nCount = *(unsigned int *)((char *)pTable + 0x8);
    unsigned int i = 0;
    unsigned int nMax = 0;
    for (; i < nCount; i++) {
        char *pEntry = pEntries + i * 0x18;
        void *pChild = Find__6PMNodeFUi(this, *(unsigned int *)pEntry);
        if (pChild != 0) {
            AddFxTriggers__6PMNodeFP6PArrayb(pChild, pEntry + 8, true);
            *(void **)((char *)pChild + 0x24) = *(void **)(pEntry + 4);
            short v = *(short *)((char *)*(void **)(pEntry + 4) + 8);
            if (nMax < (unsigned int)v) {
                nMax = v;
            }
        }
    }

    if (m_unk24 == 0) {
        void *p = __nw__FUi(0x34);
        if (p != 0) {
            p = __ct__10PAnimFrameFs(p, 0);
        }
        m_unk24 = p;
        if (m_unk24 == 0) {
            CdsAssert__FPciPc("PSkeleton.cpp", 0x28E, "mpAnim");
        }
    }
    *(short *)((char *)m_unk24 + 8) = (short)nMax;
    if (nMax != 0) {
        AnimSetup setup;
        setup.a = 0;
        setup.nMax = (short)nMax;
        setup.c = 0;
        setup.d = (short)nMax;
        setup.e = 1;
        setup.f = 0.5f;
        ((PFrameSourceView *)m_unk24)->Slot9((AnimData *)&setup);
    }
    return 1;
}

// FUNCTION: 0x001979B0 ComputeBoundingBox__9PSkeletonFv
void PSkeleton::ComputeBoundingBox() {
    UpdateBoundBox();
}

// DRAFT: 0x001979C0 UpdateBoundBox__9PSkeletonFv
// note: DIFF 57 words; float regs min in f7/f2/f3 and max in f8/f4/f5 (original min f3/f2/f4, max f5/f6/f7), pNode in v1 vs a0. Literal-zero first pick took 120 to 57; max-first 66; fCentre/pInfo/pNode decl orders 57.
void PSkeleton::UpdateBoundBox()
{
    char *pInfo;
    float fMinX = 32767.0f;
    float fMinY = 32767.0f;
    float fMinZ = 32767.0f;
    float fMaxX = -32767.0f;
    float fMaxY = -32767.0f;
    float fMaxZ = -32767.0f;
    char *pNode;
    float fCentre;
    float fLo;
    float fHi;

    m_unk154 = 0;
    pNode = (*(unsigned int *)m_unk150 != 0) ? (char *)m_unk158[0] : 0;
    while (pNode) {
        pInfo = *(char **)(pNode + 0x10);
        if (pInfo) {
            fLo = *(float *)(pNode + 0x70) + *(float *)(pInfo + 0x10);
            fHi = *(float *)(pInfo + 0x20);
            fCentre = fLo - fHi;
            if (fCentre < fMinX) {
                fMinX = fCentre;
            }
            fCentre = fHi + fLo;
            if (fCentre > fMaxX) {
                fMaxX = fCentre;
            }
            fLo = *(float *)(pNode + 0x74) + *(float *)(pInfo + 0x14);
            fHi = *(float *)(pInfo + 0x24);
            fCentre = fLo - fHi;
            if (fCentre < fMinY) {
                fMinY = fCentre;
            }
            fCentre = fHi + fLo;
            if (fCentre > fMaxY) {
                fMaxY = fCentre;
            }
            fLo = *(float *)(pNode + 0x78) + *(float *)(pInfo + 0x18);
            fHi = *(float *)(pInfo + 0x28);
            fCentre = fLo - fHi;
            if (fCentre < fMinZ) {
                fMinZ = fCentre;
            }
            fCentre = fHi + fLo;
            if (fCentre > fMaxZ) {
                fMaxZ = fCentre;
            }
        }
        m_unk154++;
        pNode = (m_unk154 < *(unsigned int *)m_unk150) ? (char *)m_unk158[m_unk154] : 0;
    }

    fCentre = (fMinX + fMaxX) / 2.0f;
    m_unk110 = fCentre;
    m_unk120 = fMaxX - fCentre;
    fCentre = (fMinY + fMaxY) / 2.0f;
    m_unk114 = fCentre;
    m_unk124 = fMaxY - fCentre;
    fCentre = (fMinZ + fMaxZ) / 2.0f;
    m_unk118 = fCentre;
    m_unk128 = fMaxZ - fCentre;
    m_unk12C = 1.5f * sqrtf(sceVu0InnerProduct(&m_unk120, &m_unk120));
}

// FUNCTION: 0x00197BC0 BuildDispList__9PSkeletonFv
void PSkeleton::BuildDispList() {
    m_unk18 = 0;
    void *pNode;
    if (m_unk14 != 0) {
        pNode = m_unk1C[0];
    } else {
        pNode = 0;
    }
    if (pNode != 0) {
        if (m_unk15C == 0) {
            Allocate__6PArrayFUi(m_unk150, 0x20);
        } else if (m_unk158 != 0) {
            *(int *)m_unk150 = 0;
            m_unk154 = 0;
        }
        BuildDispList__6PMNodeFP6PArray(pNode, m_unk150);
        if (m_unkF8 != 0) {
            Create__18PObjectDisplayListFP6PArrayP6PMNodeP5PMeshPb(m_unkF8, m_unk150, pNode, m_unk10, &m_unkD4);
        }
    }
}

// DRAFT: 0x00197C70 Render__9PSkeletonFP13PLightManagerii
// note: compiles; still differs in prologue and branch layout
int PSkeleton::Render(PLightManager *pLights, int nFlag, int nMode) {
    void *pNode;
    int nRet = 0;
    if (m_unk0C != 0) {
        int nScale = (int)((float)nFlag * m_unk2C);
        if (nScale != 0) {
            nRet = 0;
            if (nScale == 0x80 && nMode != 1 && *(unsigned char *)((char *)gGfxEng + 0x158E21) == 0 && m_unkF8 != 0) {
                nRet += Render__18PObjectDisplayListF13eBoxIntersect(m_unkF8, m_unk0C);
            } else {
                if (m_unk10 != 0) {
                    BeginMatrixList__12PDisplayListFv(*(void **)((char *)gGfxEng + 0x154C80));
                    m_unk154 = 0;
                    if (*(unsigned int *)m_unk150 != 0) {
                        pNode = m_unk158[0];
                    } else {
                        pNode = 0;
                    }
                    while (pNode != 0) {
                        AddBoneMatrixToDisplayList__6PMNodeFb(pNode, false);
                        m_unk154++;
                        if (m_unk154 < *(unsigned int *)m_unk150) {
                            pNode = m_unk158[m_unk154];
                        } else {
                            pNode = 0;
                        }
                    }
                    EndMatrixList__12PDisplayListFv(*(void **)((char *)gGfxEng + 0x154C80));
                    m_unk18 = 0;
                    if (m_unk14 != 0) {
                        BeginSharedMesh__10PGfxEngineF13eBoxIntersectP6PMNode(gGfxEng, m_unk0C, m_unk1C[0]);
                    } else {
                        BeginSharedMesh__10PGfxEngineF13eBoxIntersectP6PMNode(gGfxEng, m_unk0C, 0);
                    }
                    if (m_unk3E & 0x80) {
                        nRet += Render__5PMeshFiPbb(m_unk10, nScale, &m_unkD4, 0);
                    } else {
                        nRet += Render__5PMeshFiPbb(m_unk10, nScale, 0, 0);
                    }
                    *(unsigned char *)((char *)gGfxEng + 0x158E24) = 0;
                    *(unsigned int *)((char *)gGfxEng + 0x16D400) = 0;
                }
                m_unk154 = 0;
                if (*(unsigned int *)m_unk150 != 0) {
                    pNode = m_unk158[0];
                } else {
                    pNode = 0;
                }
                while (pNode != 0) {
                    void *pMesh = *(void **)((char *)pNode + 0x10);
                    if (pMesh != 0) {
                        void *pMat = (char *)pNode + 0x40;
                        if (pLights != 0) {
                            ComputeLights__13PLightManagerFP5PMeshP5PMat4bbbP21tagComputedLightCachef(pLights, pMesh, pMat, true, true, true, 0, 1.0f);
                        }
                        vu1SetWorldMatrix__FP5PMat4(pMat);
                    }
                    vu1BeginMesh__F13eBoxIntersect(m_unk0C);
                    if (m_unk3E & 0x80) {
                        nRet += Render__5PMeshFiPbb(pMesh, nScale, (bool *)((char *)pNode + 0xD4), 0);
                    } else {
                        nRet += Render__5PMeshFiPbb(pMesh, nScale, 0, 0);
                    }
                    if (nMode == 1) {
                        DebugDrawBox__6PMNodeFi(pNode, nMode);
                    }
                    vu1EndMesh__Fv();
                    m_unk154++;
                    if (m_unk154 < *(unsigned int *)m_unk150) {
                        pNode = m_unk158[m_unk154];
                    } else {
                        pNode = 0;
                    }
                }
            }
        }
    }
    return nRet;
}

// FUNCTION: 0x00197F70 SetAllAnimFlags__9PSkeletonFP8AnimData
void PSkeleton::SetAllAnimFlags(AnimData *pAnim) {
    m_unk18 = 0;
    unsigned char *pChild;
    if (m_unk14 != 0) {
        pChild = (unsigned char *)m_unk1C[0];
    } else {
        pChild = 0;
    }
    if (m_unk24 != 0) {
        ((PFrameSourceView *)m_unk24)->Slot9(pAnim);
        float fTime = ((PFrameSourceView *)m_unk24)->Slot11();
        m_unk34 = fTime;
        m_unk38 = fTime;
        *(float *)(pChild + 0x34) = fTime;
        *(float *)(pChild + 0x38) = fTime;
    }
    m_unk3F = 3;
    short nFlag = 3;
    if (pAnim != 0) {
        nFlag = *(short *)((unsigned char *)pAnim + 0xA);
    }
    *(pChild + 0x3D) = (unsigned char)nFlag;
}

// FUNCTION: 0x00198020 Animate__9PSkeletonFffP5PMat4ib
int PSkeleton::Animate(float fTime, float fDelta, PMat4 *pMat, int nFlag, bool bFlag) {
    fTime = ((PFrameSourceView *)m_unk24)->Slot11();
    float fLimit = (float)*(short *)((unsigned char *)m_unk24 + 8);
    if (fTime > fLimit) {
        fTime = fLimit;
    }
    int nRet = Animate__6PMNodeFffP5PMat4ib((void *)this, fTime, fDelta, pMat, nFlag, bFlag);
    m_unk18 = 0;
    void *pChild;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    } else {
        pChild = 0;
    }
    if (pChild == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0xE7, "pHip");
    }
    if (GetDeltaMove__6PMNodeFP10PAnimFramePA4_f(pChild, m_unk24, (float (*)[4])m_unk140) != 0) {
        sceVu0ApplyMatrix(m_unk80, m_unk40, m_unk140);
    }
    m_unk2C = *(float *)((unsigned char *)pChild + 0x2C);
    return nRet;
}

class PSkelNodeVirt {
public:
    virtual void V08();
    virtual void V0C();
    virtual void V10();
    virtual void V14();
    virtual void V18(float a, float b, void *c, int d, bool e);
};

// FUNCTION: 0x00198130 Load__9PSkeletonFP8PPakFileP6PArray16ePsx2FileVersion
int PSkeleton::Load(PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion) {
    unsigned char hdr16[0x10];
    int n;
    void *node;
    if (pFile == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x4D, "poFile");
    }
    if (pArr == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x4E, "poTextureHandles");
    }
    if (Read__7PCDFileFPvUi(pFile, hdr16, 0x10) != 0x10) {
        return 0;
    }
    if ((int)eVersion >= 0x10001) {
        if (LoadFxTriggers__6PMNodeFP8PPakFile((void *)this, pFile) == 0) {
            return 0;
        }
    }
    n = 0;
    if (Read__7PCDFileFPvUi(pFile, &n, 4) != 4) {
        return 0;
    }
    if (n != 8) {
        return 0;
    }
    if ((node = __nw__FUi(0x100)) != 0) {
        char *volatile pThis = (char *)node;
        *(void **)node = (void *)__vt__9PResource;
        *(unsigned int *)(pThis + 4) = 0;
        *(void **)pThis = (void *)__vt__6PMNode;
        __ct__6PArrayFv(pThis + 0x14);
        sceVu0UnitMatrix(pThis + 0x40);
        __ct__6PArrayFv(pThis + 0xD8);
        InitMembers__6PMNodeFv(pThis);
        node = pThis;
    }
    if (node == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x70, "pRootBone");
    }
    if (LoadBone__6PMNodeFP8PPakFileP6PArray16ePsx2FileVersion(node, pFile, pArr, eVersion) == 0) {
        return 0;
    }
    Add__6PArrayFPv((void *)&m_unk14, node);
    BuildDispList();
    if (*(int *)hdr16 != 0) {
        if (LoadMesh__6PMNodeFP8PPakFileP6PArray16ePsx2FileVersion((void *)this, pFile, pArr, eVersion) == 0) {
            return 0;
        }
        ((unsigned char *)m_unk10)[0xE] = 0;
        if (m_unk10 != 0) {
            SetSharedBonePtr((PMesh *)m_unk10);
        }
    }
    n = 0;
    if (Read__7PCDFileFPvUi(pFile, &n, 4) != 4) {
        return 0;
    }
    if (n != 7) {
        return 0;
    }
    ((PSkelNodeVirt *)node)->V18(0.0f, 0.0f, 0, 0, 0);
    UpdateBoundBox();
    return 1;
}

// FUNCTION: 0x001983D0 __dt__9PSkeletonFv
extern "C" PSkeleton *__dt__9PSkeletonFv(PSkeleton *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__9PSkeleton;
        __dt__6PArrayFv(&pThis->m_unk150, -1);
        __dt__9PMeshNodeFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00198440 __ct__9PSkeletonFR9PSkeleton
extern "C" PSkeleton *__ct__9PSkeletonFR9PSkeleton(PSkeleton *volatile pThis, PSkeleton &rSrc) {
    {
        unsigned char *pRaw = (unsigned char *)pThis;
        unsigned char *volatile pMesh = pRaw;
        {
            unsigned char *volatile pBase = pRaw;
            *(unsigned char **)pRaw = __vt__9PResource;
            *(unsigned int *)(pBase + 4) = 0;
            *(unsigned char **)pBase = __vt__6PMNode;
            __ct__6PArrayFv(pBase + 0x14);
            sceVu0UnitMatrix(pBase + 0x40);
            __ct__6PArrayFv(pBase + 0xD8);
            InitMembers__6PMNodeFv((PSkeleton *)pBase);
        }
        *(unsigned char **)pMesh = __vt__9PMeshNode;
        __ct__6PArrayFv(pMesh + 0x130);
        InitMembers__9PMeshNodeFv((PSkeleton *)pMesh);
    }
    *(void **)pThis = __vt__9PSkeleton;
    __ct__6PArrayFv((char *)pThis + 0x150);
    pThis->InitMembers();
    CopyMNode__6PMNodeFR6PMNodeb(pThis, &rSrc, true);
    *(u_long128 *)((char *)pThis + 0x110) = *(u_long128 *)((char *)&rSrc + 0x110);
    *(u_long128 *)((char *)pThis + 0x120) = *(u_long128 *)((char *)&rSrc + 0x120);
    pThis->BuildDispList();
    void *pAnim = __nw__FUi(0x34);
    if (pAnim != 0) {
        pAnim = __ct__10PAnimFrameFs(pAnim, 0);
    }
    pThis->m_unk24 = pAnim;
    if (pThis->m_unk24 == 0) {
        CdsAssert__FPciPc("PSkeleton.cpp", 0x3B, "mpAnim");
    }
    pThis->m_unk3E |= 2;
    pThis->m_unk4 = 2;
    return pThis;
}

// FUNCTION: 0x001985A0 InitMembers__9PSkeletonFv
void PSkeleton::InitMembers() {
    InitMembers__9PMeshNodeFv(this);
    m_unk4 = 0;
}

// FUNCTION: 0x001985D0 __ct__9PSkeletonFQ29PResource11eResObjType
extern "C" PSkeleton *__ct__9PSkeletonFQ29PResource11eResObjType(PSkeleton *volatile pThis, int eType) {
    {
        unsigned char *pRaw = (unsigned char *)pThis;
        unsigned char *volatile pMesh = pRaw;
        {
            unsigned char *volatile pBase = pRaw;
            *(unsigned char **)pRaw = __vt__9PResource;
            *(unsigned int *)(pBase + 4) = 0;
            *(unsigned char **)pBase = __vt__6PMNode;
            __ct__6PArrayFv(pBase + 0x14);
            sceVu0UnitMatrix(pBase + 0x40);
            __ct__6PArrayFv(pBase + 0xD8);
            InitMembers__6PMNodeFv((PSkeleton *)pBase);
        }
        *(unsigned char **)pMesh = __vt__9PMeshNode;
        __ct__6PArrayFv(pMesh + 0x130);
        InitMembers__9PMeshNodeFv((PSkeleton *)pMesh);
    }
    *(unsigned char **)pThis = __vt__9PSkeleton;
    __ct__6PArrayFv((unsigned char *)pThis + 0x150);
    pThis->InitMembers();
    pThis->m_unk4 = (unsigned int)eType;
    return pThis;
}
