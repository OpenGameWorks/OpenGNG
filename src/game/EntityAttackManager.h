#ifndef ENTITYATTACKMANAGER_H
#define ENTITYATTACKMANAGER_H

#include "PList.h"

class EntityBaseClass;

// PList base at 0x00 (0x10 bytes). Attack bookkeeping follows.
class EntityAttackManager : public PList {
public:
    EntityAttackManager();
    void Reset();
    void CallAllOnStopAttack();
    void NotifyAttackManager(EntityBaseClass *pEntity);
    EntityBaseClass *RequestCloserThanAttacking(float fDist);
    int RequestAttack(EntityBaseClass *pEnemy, float fDist, unsigned int uDelay, EntityBaseClass *pVictim);

    int m_unk10;            // 0x10 flag, set to 1 by Reset
    int m_unk14;            // 0x14 count, decremented by NotifyAttackManager
    char m_unk18[4];        // 0x18 not recovered
    EntityBaseClass *m_unk1C; // 0x1C closest entity found by RequestCloserThanAttacking
    int m_unk20;            // 0x20 cleared by Reset
};

#endif
