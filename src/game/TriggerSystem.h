#ifndef TRIGGERSYSTEM_H
#define TRIGGERSYSTEM_H

#include "types.h"

class Player;
class PMeshNode;

class TriggerSystemWakeKillRec {
public:
    int m_unk0;
    int m_unk4;
    int m_unk8;
    int m_unkC;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
};

// Size 0x50. Constructed in place by EntityBaseClass; m_unk9 is the trigger-armed state byte.
class TriggerSystem {
public:
    TriggerSystem(int nId, float (*pMatrix)[4], unsigned int nU3, short nS4, bool bB5, short nS6, float fRadius, bool bB8,
                  unsigned int nU9, unsigned int nU10, TriggerSystemWakeKillRec *pRec);
    TriggerSystem(int nId, float (*pMatrix)[4], unsigned int nU3, short nS4, bool bB5, short nS6, float fRadius, bool bB8,
                  unsigned int nU9, unsigned int nU10, unsigned int nU11, unsigned int nU12, unsigned int nU13,
                  unsigned int nU14, unsigned int nU15, unsigned int nU16, unsigned int nU17, unsigned int nU18,
                  bool bB19, bool bB20);

    void InitMembers();
    int ConditionCheck(Player *pPlayer);
    void ResetTrigger(PMeshNode *pNode);
    int TriggerCheck(float (*pMatrix)[4], PMeshNode *pNode, Player *pPlayer);

    unsigned short m_unk0;
    short m_unk2;
    short m_unk4;
    short m_unk6;
    bool m_unk8;
    signed char m_unk9;
    signed char m_unkA;
    bool m_unkB;
    char _pad0C[4];
    int m_unk10;
    int m_unk14;
    int m_unk18;
    float m_unk1C;
    unsigned int m_unk20;
    unsigned int m_unk24;
    unsigned int m_unk28;
    unsigned int m_unk2C;
    unsigned int m_unk30;
    unsigned int m_unk34;
    unsigned int m_unk38;
    unsigned int m_unk3C;
    unsigned int m_unk40;
    unsigned int m_unk44;
    bool m_unk48;
    bool m_unk49;
    char _pad4A[6];
};

#endif
