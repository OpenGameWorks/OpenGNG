// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "EntityAttackManager.h"
#include "Player.h"
#include "Camera.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    float GetDistFromPlayer();
};
class PLightManager;

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("EntityAttackManager.cpp", line, #cond))
extern unsigned char gEng[0x1A000];

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


// FUNCTION: 0x00154AE0 DisplayDebug__19EntityAttackManagerFv
void EntityAttackManager::DisplayDebug() {
}

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

// FUNCTION: 0x00154BF0 RequestCloserThanAttacking__19EntityAttackManagerFf
EntityBaseClass *EntityAttackManager::RequestCloserThanAttacking(float fDist) {
    EntityBaseClass *p;
    float fClosest;
    bool bFound;

    m_unkC = m_unk4;
    p = m_unk4 ? (EntityBaseClass *)m_unk4->m_unk0 : 0;
    fClosest = 0.0f;
    bFound = false;
    if (p != 0) {
        do {
            float d = p->GetDistFromPlayer();
            if (!(d <= fClosest)) {
                m_unk1C = p;
                fClosest = d;
            }
            if (!(d <= fDist)) {
                bFound = true;
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
    if (bFound) {
        EntityBaseClass *c = m_unk1C;
        unsigned int v = *(unsigned short *)((char *)c + 0x180);
        if (!(fClosest <= (float)v)) {
            return c;
        }
    }
    return 0;
}

// DRAFT: 0x00154D50 RequestAttack__19EntityAttackManagerFP15EntityBaseClassfUiP15EntityBaseClass
// note: 78 words differ. Merging pause/flag/camera early returns into one || condition cut 83 to 78; tried separate returns (83), goto shared exit (89), char* gEng bases (83), dropping the pause cast (115), flag != 0 (78), camera before flag (113). Branch sense at 0x00A8 still differs.
int EntityAttackManager::RequestAttack(EntityBaseClass *pEnemy, float fDist, unsigned int uDelay, EntityBaseClass *pVictim) {
    Player *pPlayer;
    EntityBaseClass *c;
    PListNode *n;

    CDS_ASSERT(0x27, pEnemy);
    CDS_ASSERT(0x28, pVictim);
    pPlayer = *(Player **)(gEng + 0x1883C);
    CDS_ASSERT(0x2C, pPlayer);
    if ((unsigned char)pPlayer->IsPauseDisabled() || (pPlayer->m_unk264 & 0x10000) || ((Camera *)(gEng + 0x19760))->PlayingCutCamera()) {
        return 0;
    }
    if (*(int *)((char *)pVictim + 8) != 3) {
        return 1;
    }
    if (m_unk20 != 0) {
        if (*(unsigned int *)(gEng + 0x19A80) < (unsigned int)m_unk20) {
            return 0;
        }
        m_unk20 = 0;
    }
    n = m_unk4;
    while (n != 0) {
        if (n->m_unk0 == pEnemy) {
            return 1;
        }
        n = n->m_unk4;
    }
    if ((unsigned int)m_unk14 < (unsigned int)m_unk10) {
        if (Add(pEnemy)) {
            m_unk14++;
        }
        m_unk20 = uDelay ? uDelay + *(unsigned int *)(gEng + 0x19A80) : 0;
        return 1;
    }
    c = RequestCloserThanAttacking(fDist);
    if (c == 0) {
        return 0;
    }
    if (((EntityBaseClassVirtuals *)c)->GetHealth() > 0) {
        ((EntityBaseClassVirtuals *)c)->OnStopAttack();
    }
    if (Remove(c)) {
        m_unk14--;
    }
    if (Add(pEnemy)) {
        m_unk14++;
    }
    m_unk20 = uDelay ? uDelay + *(unsigned int *)(gEng + 0x19A80) : 0;
    return 1;
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
    Reset();
}
