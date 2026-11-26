#include "TriggerSystem.h"
#include "types.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" int CheckHammer__6PlayerFb(void *pThis, bool bFlag);
extern "C" void ResetCutScene__15PCutScenePlayerFv(void *pThis);
extern "C" void RecurseResetAnimByID__6PMNodeFUi(void *pThis, unsigned int nID);
extern unsigned char gEng[0x19B90];

// FUNCTION: 0x0014FA00 InitMembers__13TriggerSystemFv
void TriggerSystem::InitMembers()
{
    memset(this, 0, 0x50);
    m_unk18 = 0;
    m_unk14 = 0;
    m_unk10 = 0;
    m_unk9 = 0;
    m_unkA = 0;
    m_unk24 = 0;
}

// FUNCTION: 0x0014FA50 __ct__13TriggerSystemFiPA4_fUisbsfbUiUiP24TriggerSystemWakeKillRec
TriggerSystem::TriggerSystem(int nId, float (*pMatrix)[4], unsigned int nU3, short nS4, bool bB5, short nS6, float fRadius,
                             bool bB8, unsigned int nU9, unsigned int nU10, TriggerSystemWakeKillRec *pRec)
{
    InitMembers();
    *(u_long128 *)&m_unk10 = *(u_long128 *)pMatrix;
    m_unk1C = fRadius * fRadius;
    m_unk0 = nU3;
    m_unk2 = nS4;
    m_unk8 = bB5;
    m_unk4 = nId;
    m_unk6 = nS6;
    m_unkB = bB8;
    m_unk20 = nU9;
    m_unk24 = nU10;
    if (pRec) {
        m_unk28 = pRec->m_unk0;
        m_unk2C = pRec->m_unk4;
        m_unk30 = pRec->m_unk8;
        m_unk34 = pRec->m_unkC;
        m_unk38 = pRec->m_unk10;
        m_unk3C = pRec->m_unk14;
        m_unk40 = pRec->m_unk18;
        m_unk44 = pRec->m_unk1C;
    }
}

// FUNCTION: 0x0014FB60 __ct__13TriggerSystemFiPA4_fUisbsfbUiUiUiUiUiUiUiUiUiUibb
TriggerSystem::TriggerSystem(int nId, float (*pMatrix)[4], unsigned int nU3, short nS4, bool bB5, short nS6, float fRadius,
                             bool bB8, unsigned int nU9, unsigned int nU10, unsigned int nU11, unsigned int nU12,
                             unsigned int nU13, unsigned int nU14, unsigned int nU15, unsigned int nU16,
                             unsigned int nU17, unsigned int nU18, bool bB19, bool bB20)
{
    InitMembers();
    *(u_long128 *)&m_unk10 = *(u_long128 *)pMatrix;
    m_unk1C = fRadius * fRadius;
    m_unk0 = nU3;
    m_unk2 = nS4;
    m_unk8 = bB5;
    m_unk4 = nId;
    m_unk6 = nS6;
    m_unkB = bB8;
    m_unk20 = nU9;
    m_unk24 = nU10;
    m_unk28 = nU11;
    m_unk2C = nU12;
    m_unk30 = nU13;
    m_unk34 = nU17;
    m_unk38 = nU14;
    m_unk3C = nU15;
    m_unk40 = nU16;
    m_unk44 = nU18;
    m_unk48 = bB19;
    m_unk49 = bB20;
}

// FUNCTION: 0x0014FC70 ConditionCheck__13TriggerSystemFP6Player
int TriggerSystem::ConditionCheck(Player *pPlayer)
{
    switch (m_unkA) {
    case 1:
        return CheckHammer__6PlayerFb(pPlayer, true);
    }
    return 1;
}

// FUNCTION: 0x0014FCB0 ResetTrigger__13TriggerSystemFP9PMeshNode
void TriggerSystem::ResetTrigger(PMeshNode *pNode)
{
    if (m_unk9 == 0) {
        return;
    }
    m_unk9 = 0;
    if (pNode == 0) {
        return;
    }
    if (m_unk6 >= 0) {
        ResetCutScene__15PCutScenePlayerFv((char *)gEng + m_unk6 * 0x2140 + 0x220);
        gEng[0x8720] = 0;
        return;
    }
    if (m_unk0 > 1) {
        RecurseResetAnimByID__6PMNodeFUi(pNode, m_unk0);
    }
}
