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
    void Execute();

    char _pad190[0x20];
    char m_unk1B0[0xC];         // 0x1B0 editable-vars block; SetEditableVars memcpys 0x48 bytes from here
    float m_unk1BC;             // 0x1BC
    int m_unk1C0;               // 0x1C0 type/apparition id, compared against 8, 3, 1 and passed to FindAnimNode
    int m_unk1C4;               // 0x1C4 anim frame count, halved for the animation key range
    unsigned int m_unk1C8;      // 0x1C8
    unsigned int m_unk1CC;      // 0x1CC
    int m_unk1D0;               // 0x1D0
    int m_unk1D4;               // 0x1D4
    float m_unk1D8[3];          // 0x1D8 copied to m_unk230 on the first Execute pass
    float m_unk1E4;             // 0x1E4 radius for the main enemy search
    float m_unk1E8[3];          // 0x1E8 copied to m_unk210 on the first Execute pass
    float m_unk1F4;             // 0x1F4 distance threshold
    PMNode *m_unk1F8;           // 0x1F8 anim node, set by SetEditableVars
    short m_unk1FC;             // 0x1FC countdown before the next spawn check
    short m_unk1FE;             // 0x1FE
    int m_unk200;               // 0x200
    char _pad204[0xC];
    float m_unk210[3];          // 0x210 saved position
    char _pad21C[4];
    float m_unk220[3];          // 0x220 box for the wake-up search
    char _pad22C[4];
    float m_unk230[3];          // 0x230 box for the spawn-count search
};

#endif
