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
extern "C" void Create__18PObjectDisplayListFP6PArrayP6PMNodeP5PMeshPb(void *pThis, void *pArr, void *pNode, void *pMesh, bool *pFlag);

// Object held at PSkeleton+0x24. Slot 0x1C is the frame query; slots 0..4 are unknown.
class PFrameSourceView {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
};

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
