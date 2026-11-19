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
extern "C" PObjectDisplayList *__ct__18PObjectDisplayListFv(PObjectDisplayList *pThis);
extern "C" void __dt__18PObjectDisplayListFv(PObjectDisplayList *pThis, short nFlag);
extern "C" void *FindBone__6PMNodeFUi(void *pThis, unsigned int nId);
extern "C" int Animate__6PMNodeFffP5PMat4ib(void *pThis, float fTime, float fDelta, PMat4 *pMat, int nFlag, bool bFlag);
extern "C" int GetDeltaMove__6PMNodeFP10PAnimFramePA4_f(void *pThis, void *pFrame, float (*pMat)[4]);
extern "C" void sceVu0ApplyMatrix(void *pDst, void *pMat, void *pSrc);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void InitMembers__6PMNodeFv(void *pThis);
extern "C" void __ct__6PArrayFv(void *pThis);
extern unsigned char __vt__9PResource[0x40];
extern unsigned char __vt__6PMNode[0x40];
extern unsigned char __vt__9PMeshNode[0x40];

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

// FUNCTION: 0x001985A0 InitMembers__9PSkeletonFv
void PSkeleton::InitMembers() {
    InitMembers__9PMeshNodeFv(this);
    m_unk4 = 0;
}

// DRAFT: 0x001985D0 __ct__9PSkeletonFQ29PResource11eResObjType
// note: manual __ct__6PArrayFv calls at 0x14/0xD8/0x130/0x150; the original spills this to the stack and needs PArray members, which overlap the scalar fields and lack base classes here. Not restructured.
extern "C" PSkeleton *__ct__9PSkeletonFQ29PResource11eResObjType(PSkeleton *pThis, int eType) {
    unsigned char *p = (unsigned char *)pThis;
    *(unsigned char **)p = __vt__9PResource;
    pThis->m_unk4 = 0;
    *(unsigned char **)p = __vt__6PMNode;
    __ct__6PArrayFv(p + 0x14);
    sceVu0UnitMatrix(p + 0x40);
    __ct__6PArrayFv(p + 0xD8);
    InitMembers__6PMNodeFv(pThis);
    *(unsigned char **)p = __vt__9PMeshNode;
    __ct__6PArrayFv(p + 0x130);
    InitMembers__9PMeshNodeFv(pThis);
    *(unsigned char **)p = __vt__9PSkeleton;
    __ct__6PArrayFv(p + 0x150);
    pThis->InitMembers();
    pThis->m_unk4 = (unsigned int)eType;
    return pThis;
}
