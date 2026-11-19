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

// The drawable's draw handler sits at vtable byte offset 0xC.
class EffectDrawable {
public:
    virtual void Slot0();
    virtual int Draw(PLightManager *arg0, int arg1, int arg2);
};

extern "C" void __ct__6PArrayFv(void *);
extern "C" void Allocate__6PArrayFUi(void *, unsigned int);

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

// FUNCTION: 0x156C30 Render__10EffectNodeFP13PLightManager
int EffectNode::Render(PLightManager *arg0) {
    if (m_unk4 != 0) {
        *(unsigned char *)(gGfxEng + 0x158E22) = m_unkC;
        return ((EffectDrawable *)m_unk4)->Draw(m_unkC ? arg0 : 0, 0x80, 0);
    }
    return 0;
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
