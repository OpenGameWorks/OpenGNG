#include "types.h"
#include "EntityAttackManager.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    float GetDistFromPlayer();
};
class PLightManager;

// Leading virtuals of EntityBaseClass's vtable (__vt__15EntityBaseClass); a call
// through this view loads the slot into $t9 as the original's virtual calls do.
class EntityBaseClassVirtuals {
public:
    virtual ~EntityBaseClassVirtuals();
    virtual int GetTallyType();
    virtual void Slot10();
    virtual void OutputDebug();
    virtual void Slot18();
    virtual void SetEditableVars(char *);
    virtual void SetDefaultVars();
    virtual void OnTimerEvent(unsigned int);
    virtual void Render(PLightManager *);
    virtual void Animate(int, float);
    virtual void SetInnocentInstanceID(unsigned int);
    virtual int GetHealth();
    virtual void OnStopAttack();
};

extern "C" void __ct__5PListFv(void *);

// FUNCTION: 0x00154AF0 CallAllOnStopAttack__19EntityAttackManagerFv
void EntityAttackManager::CallAllOnStopAttack() {
    m_unkC = m_unk4;
    EntityBaseClass *p = m_unk4 ? (EntityBaseClass *)m_unk4->m_unk0 : 0;
    while (p != 0) {
        ((EntityBaseClassVirtuals *)p)->OnStopAttack();
        if (m_unkC == 0) {
            m_unkC = m_unk4;
            p = m_unk4 ? (EntityBaseClass *)m_unk4->m_unk0 : 0;
        } else {
            PListNode *n = m_unkC->m_unk4;
            if (n != 0) {
                m_unkC = n;
                p = (EntityBaseClass *)m_unkC->m_unk0;
            } else {
                p = 0;
            }
        }
    }
}

// FUNCTION: 0x00154BB0 NotifyAttackManager__19EntityAttackManagerFP15EntityBaseClass
void EntityAttackManager::NotifyAttackManager(EntityBaseClass *pEntity) {
    if (Remove(pEntity)) {
        m_unk14--;
    }
}

// DRAFT: 0x00154BF0 RequestCloserThanAttacking__19EntityAttackManagerFf
// note: 3 words differ: bFound=1 is addiu (original daddiu, bool-typed flag gave 43 words), and the (v>>1)|(v&1) or targets v1 (original a0); swapping the or operands gave 5 words.
EntityBaseClass *EntityAttackManager::RequestCloserThanAttacking(float fDist) {
    EntityBaseClass *p;
    float fClosest;
    int bFound;

    m_unkC = m_unk4;
    p = m_unk4 ? (EntityBaseClass *)m_unk4->m_unk0 : 0;
    fClosest = 0.0f;
    bFound = 0;
    if (p != 0) {
        do {
            float d = p->GetDistFromPlayer();
            if (!(d <= fClosest)) {
                m_unk1C = p;
                fClosest = d;
            }
            if (!(d <= fDist)) {
                bFound = 1;
            }
            if (m_unkC == 0) {
                m_unkC = m_unk4;
                p = m_unk4 ? (EntityBaseClass *)m_unk4->m_unk0 : 0;
            } else {
                PListNode *n = m_unkC->m_unk4;
                if (n != 0) {
                    m_unkC = n;
                    p = (EntityBaseClass *)m_unkC->m_unk0;
                } else {
                    p = 0;
                }
            }
        } while (p != 0);
    }
    if (bFound != 0) {
        EntityBaseClass *c = m_unk1C;
        unsigned int v = *(unsigned short *)((char *)c + 0x180);
        float f;
        if ((int)v >= 0) {
            f = (float)(int)v;
        } else {
            float t = (float)(int)((v >> 1) | (v & 1));
            f = t + t;
        }
        if (!(fClosest <= f)) {
            return c;
        }
    }
    return 0;
}

// FUNCTION: 0x00154FD0 Reset__19EntityAttackManagerFv
void EntityAttackManager::Reset() {
    m_unk14 = 0;
    m_unk10 = 1;
    m_unk20 = 0;
    RemoveAll();
}

// FUNCTION: 0x00154FF0 __ct__19EntityAttackManagerFv
EntityAttackManager::EntityAttackManager() {
    __ct__5PListFv(this);
    Reset();
}
