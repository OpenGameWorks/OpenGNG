#include "types.h"
#include "EffectAPI.h"

// TODO(header): foreign declarations
extern char gEng[105360];
extern char gGfxEng[1504384];

class EntityManager {
public:
    void *GetPtrToApparition(unsigned int arg0);
};

// The apparition's delete-event handler sits at vtable byte offset 0x60.
// Slots 0..21 are placeholders; the emitted offset is 0x60 with this layout.
class EffectTarget {
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
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void SendDeleteEvent(int arg0);
};

// The drawable's draw handler sits at vtable byte offset 0xC; the update handler at 0x18.
class EffectDrawable {
public:
    virtual void Slot0(int arg0);
    virtual int Draw(PLightManager *arg0, int arg1, int arg2);
    virtual void Slot2();
    virtual void Slot3();
    virtual int Slot4(int arg0, int arg1, int arg2, float arg3, float arg4);
};

class PMat4;

class PFrustrum {
public:
    int IntersectBox(float (*arg0)[2][4], PMat4 *arg1);
};

enum eBoxIntersect {
    eBoxIntersect_Unknown = 0
};

class PMNode {
public:
    void SetAllFrustrumTest(eBoxIntersect arg0);
};

extern PFrustrum *mpFrustum__15EntityBaseClass;

extern "C" void __ct__6PArrayFv(void *);
extern "C" void Allocate__6PArrayFUi(void *, unsigned int);
extern "C" void Remove__6PArrayFPv(void *, void *);
extern "C" void __dl__FPv(void *);
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" void RemoveAt__6PArrayFi(void *pThis, int nIndex);
extern "C" int printf(const char *fmt, ...);
extern unsigned char mEffectAPI__13EntityManager[0x10];
extern unsigned char __vt__10EffectNode[0x40];
extern unsigned char __vt__11GhostEffect[0x20];
extern unsigned char __vt__13OneshotEffect[0x20];

// FUNCTION: 0x156010 CreatePling__9EffectAPIFP15EntityBaseClassfUiUib
void EffectAPI::CreatePling(EntityBaseClass *arg0, float arg1, unsigned int arg2, unsigned int arg3, bool arg4) {
    float vec[4];
    vec[0] = 0.0f;
    vec[1] = arg1;
    vec[2] = 0.0f;
    CreatePling(arg0, &vec, arg2, arg3, arg4);
}

// FUNCTION: 0x156440 SendDeleteEvent__10EffectNodeFi
void EffectNode::SendDeleteEvent(int arg0) {
    if (arg0 == 0) {
        return;
    }
    EffectTarget *pTarget = (EffectTarget *)((EntityManager *)(gEng + 0x137E0))->GetPtrToApparition(arg0);
    if (pTarget != 0) {
        pTarget->SendDeleteEvent(m_unk8);
    }
}

// DRAFT: 0x156BB0 Update__10EffectNodeFf
// note: 2 differing lines, a2/a1 addiu order (original computes a2 first). Tried: inline args, pMat local, PMNode struct fields, int base local (4 lines each for the last two).
int EffectNode::Update(float arg0) {
    if (m_unk4 != 0) {
        if (((EffectDrawable *)m_unk4)->Slot4(0, 0, 0, 0.0f, arg0) & 7) {
            PMat4 *pMat = (PMat4 *)(m_unk4 + 0x40);
            int test = mpFrustum__15EntityBaseClass->IntersectBox((float (*)[2][4])(m_unk4 + 0x110), pMat);
            ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)test);
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x156C30 Render__10EffectNodeFP13PLightManager
int EffectNode::Render(PLightManager *arg0) {
    if (m_unk4 != 0) {
        *(unsigned char *)(gGfxEng + 0x158E22) = m_unkC;
        return ((EffectDrawable *)m_unk4)->Draw(m_unkC ? arg0 : 0, 0x80, 0);
    }
    return 0;
}

// FUNCTION: 0x156C90 __dt__10EffectNodeFv
extern "C" void *__dt__10EffectNodeFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__10EffectNode;
        EffectNode *pNode = (EffectNode *)pThis;
        EffectDrawable *pDrawable = (EffectDrawable *)pNode->m_unk4;
        if (pDrawable != 0) {
            if (pDrawable != 0) {
                pDrawable->Slot0(1);
            }
            pNode->m_unk4 = 0;
        }
        Remove__6PArrayFPv(&mEffectAPI__13EntityManager, pThis);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x156FD0 DeleteEffect__9EffectAPIFP10EffectNode
void EffectAPI::DeleteEffect(EffectNode *arg0) {
    int nIndex = Find__6PArrayFPv(this, arg0);
    if (nIndex >= 0) {
        RemoveAt__6PArrayFi(this, nIndex);
        if (arg0 != 0) {
            ((EffectDrawable *)arg0)->Slot0(1);
        }
    } else {
        printf("EffectNode not found\n");
    }
}

// DRAFT: 0x157360 __ct__9EffectAPIFv
// note: original keeps this in stack home 0x1C(sp) and never uses s0; compile saves s0 and uses it (9 differing lines). Tried (void*) casts (9 lines) and volatile local (15 lines).
EffectAPI::EffectAPI() {
    __ct__6PArrayFv(this);
    Allocate__6PArrayFUi(this, 0x80);
}

// FUNCTION: 0x157390 __dt__11PlingEffectFv
PlingEffect::~PlingEffect() {
}

// FUNCTION: 0x157400 __dt__11GhostEffectFv
extern "C" void *__dt__11GhostEffectFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__11GhostEffect;
        __dt__10EffectNodeFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x157470 __dt__13OneshotEffectFv
extern "C" void *__dt__13OneshotEffectFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__13OneshotEffect;
        __dt__10EffectNodeFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
