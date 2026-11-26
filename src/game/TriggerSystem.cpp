#include "TriggerSystem.h"
#include "types.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" int CheckHammer__6PlayerFb(void *pThis, bool bFlag);
extern "C" void ResetCutScene__15PCutScenePlayerFv(void *pThis);
extern "C" void RecurseResetAnimByID__6PMNodeFUi(void *pThis, unsigned int nID);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" int printf(const char *fmt, ...);
extern "C" void *FindTrigger__13EntityManagerFUii(void *pThis, unsigned int nId, int nUnk);
extern "C" void *GetPtrToInstance__13EntityManagerFUi(void *pThis, unsigned int nId);
extern "C" void SetEifWoken__13EntityManagerFUibUi(void *pThis, unsigned int nId, bool bFlag, unsigned int nArg);
extern "C" void Add2DependencyList__13EntityManagerFUiUi(void *pThis, unsigned int nA, unsigned int nB);
extern "C" void Destroy__13EntityManagerFUiUi(void *pThis, unsigned int nA, unsigned int nB);
extern "C" void *FindAnimNode__6PMNodeFUi(void *pThis, unsigned int nId);
extern "C" int StartCutScene__10MaximoMainFi(void *pThis, int nId);
extern "C" void ShakeScreen__9CameraAPIFfffUi(void *pThis, float fA, float fB, float fC, unsigned int nD);
extern "C" void TriggerSystemSound__6PSoundFUiUiP6PMNode(void *pThis, unsigned int nA, unsigned int nB, void *pNode);
extern "C" void RecurseApplyAnimLoopByID__6PMNodeFUisib(void *pThis, unsigned int nId, short nS, int nI, bool bB);
extern "C" void StartCutCamera__6CameraFUib(void *pThis, unsigned int nId, bool bFlag);
extern "C" void BackToMaximo__6PlayerFv(void *pThis);
extern unsigned char gEng[0x19B90];
extern unsigned char gSound[0x10];
extern unsigned char gInterface[0x2000];
extern unsigned char mCameraAPI__13EntityManager[1];

// DRAFT: 0x0014F620 TriggerCheck__13TriggerSystemFPA4_fP9PMeshNodeP6Player
// note: frame 0xB0 vs 0xC0, pPlayer/pNode/this in wrong s-registers, size 0x3D0 vs 0x3D4, 223 words; tried decl order, dropping self-assign, pMgr hoisting (165 words only with pMgr uninitialised)
int TriggerSystem::TriggerCheck(float (*pMatrix)[4], PMeshNode *pNode, Player *pPlayer)
{
    char *pMgr;
    int nRet = 0;
    float vDiff[4];
    bool bSwap;
    void *pTrig;
    void *pAnim;
    void *pEntry;
    int i;
    unsigned int nOff;

    if (m_unk9 != 0) {
        nRet = 1;
        if (m_unk9 != 2) {
            return 0;
        }
        goto block20;
    }
    if (!m_unk1C) {
        void *pA = *(void **)((char *)pPlayer + 0x38);
        void *pB = *(void **)((char *)pA + 0xCC);
        unsigned int nCmp = 0;
        if (pB == 0) {
            return 0;
        }
        pEntry = *(void **)((char *)pB + 0x24);
        if (pEntry != 0) {
            nCmp = *(unsigned int *)((char *)pEntry + 4);
        }
        if (m_unk0 != nCmp) {
            return 0;
        }
        goto block20;
    }
    sceVu0SubVector(vDiff, (float *)((char *)this + 0x10), (float *)pMatrix);
    if (m_unk1C < sceVu0InnerProduct(vDiff, vDiff)) {
        return 0;
    }
    if (m_unk20 >= 2) {
        pTrig = FindTrigger__13EntityManagerFUii((char *)gEng + 0x137E0, m_unk20, -1);
        if (pTrig != 0 && *((signed char *)pTrig + 9) == 0) {
            return 0;
        }
        pAnim = FindAnimNode__6PMNodeFUi(*(void **)gEng, m_unk20);
        if (pAnim != 0 && (signed char)(*((signed char *)pAnim + 0x3F) & 7) != 0) {
            return 0;
        }
    }
    nRet = -1;
    if (ConditionCheck(pPlayer) == 0) {
        return 0;
    }

block20:
    bSwap = (m_unk6 >= 0);
    if (m_unk6 >= 0) {
        bSwap = (*((signed char *)gEng + m_unk6 * 0x2140 + 0x235D) & 1) != 0;
    }
    if (bSwap) {
        nRet = -2;
    }
    pMgr = (char *)gEng + 0x137E0;
    nOff = 0;
    i = 0;
    do {
        char *pSlot = (char *)this + nOff;
        unsigned int nA = *(unsigned int *)(pSlot + 0x28);
        if (nA != 0) {
            pEntry = GetPtrToInstance__13EntityManagerFUi(pMgr, nA);
            if (pEntry != 0) {
                *((char *)pEntry + 0x1A) = 1;
                if (bSwap) {
                    SetEifWoken__13EntityManagerFUibUi(pMgr, *(unsigned int *)((char *)pEntry + 0xC), false,
                                                       *(unsigned int *)((char *)pEntry + 8));
                } else {
                    Add2DependencyList__13EntityManagerFUiUi(pMgr, (unsigned short)m_unk4,
                                                             *(unsigned int *)((char *)pEntry + 4));
                }
            }
        }
        if (*(unsigned int *)(pSlot + 0x38) != 0) {
            pEntry = GetPtrToInstance__13EntityManagerFUi(pMgr, *(unsigned int *)(pSlot + 0x38));
            if (pEntry != 0) {
                Destroy__13EntityManagerFUiUi(pMgr, *(unsigned int *)((char *)pEntry + 4),
                                              *(unsigned int *)(pSlot + 0x38));
            }
        }
        i++;
        nOff += 4;
    } while (i < 4);

    if (m_unk6 >= 0) {
        if (StartCutScene__10MaximoMainFi(gEng, m_unk6) != 0) {
            if (m_unkB) {
                ShakeScreen__9CameraAPIFfffUi(mCameraAPI__13EntityManager, 0.0f, 2.0f, 3.0f, 0);
            }
        }
        m_unk9 = 1;
        return nRet;
    }
    pAnim = FindAnimNode__6PMNodeFUi(pNode, m_unk0);
    if (pAnim == 0) {
        printf("BG AnimID %d not found\n", m_unk0);
        m_unk9 = 1;
        return -1;
    }
    TriggerSystemSound__6PSoundFUiUiP6PMNode(gSound, m_unk0, *(unsigned int *)((char *)pAnim + 0xE8), pAnim);
    RecurseApplyAnimLoopByID__6PMNodeFUisib(pNode, m_unk0, m_unk2, m_unk8, true);
    if (m_unk24 != 0) {
        StartCutCamera__6CameraFUib((char *)gEng + 0x19760, m_unk24, m_unk49);
        *(short *)((char *)gInterface + 0x1B24) = 30;
        *(int *)((char *)gInterface + 0x18D0) &= ~0xE;
    }
    m_unk9 = 1;
    if (m_unkB) {
        ShakeScreen__9CameraAPIFfffUi(mCameraAPI__13EntityManager, 0.0f, 2.0f, 3.0f, 0);
    }
    if (m_unk48) {
        BackToMaximo__6PlayerFv(pPlayer);
    }
    return nRet;
}

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
