#ifndef LIFTOPERATOR_H
#define LIFTOPERATOR_H

#include "types.h"
#include "EntityBaseClass.h"

class PMNode;

// EntityBaseClass occupies 0x000..0x18F; LiftOperator adds its fields from 0x190 on.
class LiftOperator : public EntityBaseClass {
public:
    LiftOperator();
    virtual ~LiftOperator();
    void SpawnEnemy();
    void SpawnEnemyType(unsigned int nApparitionId, int nType);
    int EnemiesInRadius(float (*pBox)[4], float fRadius, bool bFlag);
    void SetEditableVars(char *pSrc);

    char _pad190[0x20];
    char m_unk1B0[0x10];        // 0x1B0 editable-vars block; SetEditableVars memcpys 0x48 bytes here
    int m_unk1C0;               // 0x1C0 type/apparition id, compared against 8, 3, 1 and passed to FindAnimNode
    char _pad1C4[4];
    unsigned int m_unk1C8;      // 0x1C8
    unsigned int m_unk1CC;      // 0x1CC
    int m_unk1D0;               // 0x1D0
    char _pad1D4[0x24];
    PMNode *m_unk1F8;           // 0x1F8 anim node, set by SetEditableVars
    char _pad1FC[2];
    short m_unk1FE;             // 0x1FE
    int m_unk200;               // 0x200
};

#endif
