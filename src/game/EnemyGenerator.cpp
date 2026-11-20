#include "types.h"
#include "EnemyGenerator.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__14EnemyGenerator[];
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern void *mpEntMgr__15EntityBaseClass;
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *pThis, unsigned int nId);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pExpr);
extern "C" int CreateTimer__8TimerAPIFUiUib(void *pThis, unsigned int nArg0, unsigned int nArg1, bool bFlag);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern unsigned char mTimerAPI__13EntityManager[0x20];
extern void *mPlayerAPI__13EntityManager;

// Virtual slots of the apparition object, declared in slot order so that GetHealth
// (slot 0x34, virtual number 11) is called through $t9 as the original does.
class EnemyGeneratorVirtuals {
public:
    virtual ~EnemyGeneratorVirtuals();
    virtual int Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual int GetHealth();
};

// FUNCTION: 0x0020DD90 __dt__14EnemyGeneratorFv
extern "C" EnemyGenerator *__dt__14EnemyGeneratorFv(EnemyGenerator *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__14EnemyGenerator;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0020DE40 OnTimerEvent__14EnemyGeneratorFUi
void EnemyGenerator::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk1B4) {
        m_unk1B0 = 1;
    }
}

// DRAFT: 0x0020DE60 CheckGeneratedEnemies__14EnemyGeneratorFv
// note: 14 words differ; loop-entry branch offset and the dead-branch reload of m_unk1E8 order are off.
void EnemyGenerator::CheckGeneratedEnemies() {
    for (int i = 0; i < m_unk1D8; i++) {
        if (m_unk1E8 != -1) {
            return;
        }
        void *pApp = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk1DC[i]);
        bool bDead = true;
        if (pApp != 0) {
            bDead = ((EnemyGeneratorVirtuals *)pApp)->GetHealth() <= 0;
        }
        if (bDead) {
            m_unk1D8--;
            m_unk1E8 = i;
            m_unk1DC[m_unk1E8] = 0;
            return;
        }
    }
}

// DRAFT: 0x0020E380 Execute__14EnemyGeneratorFv
// note: 123 words differ, size 0x208 vs 0x200; original tests -2, 1, 0, -1 and keeps the -1 init inline, while ours inlines the state-1 body (switch and if-chain variants tried).
void EnemyGenerator::Execute() {
    if (m_unk20 == 1) {
        if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) == 0) {
            GenerateEnemy();
            m_unk1C4++;
            m_unk1B0 = 0;
            m_unk1B4 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, m_unk1C0, 1);
            SetState__15EntityBaseClassFi(this, 0);
        }
        return;
    }
    if (m_unk20 == 0) {
        if (m_unk1B8 != 0) {
            return;
        }
        if (m_unk1B0 != 0 && m_unk1D8 < 3) {
            char *pPlayer = (char *)mPlayerAPI__13EntityManager;
            char *pPos = pPlayer + 0x190;
            char *pApp = *(char **)(pPlayer + 0x3C);
            if (pApp != 0) {
                pPos = pApp + 0x80;
            }
            float fDist = Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPos, &m_unk190);
            if (fDist < m_unk1EC) {
                SetState__15EntityBaseClassFi(this, 1);
                return;
            }
        }
        CheckGeneratedEnemies();
        return;
    }
    if (m_unk20 == -1) {
        memset(m_unk1C8, 0, 0xC);
        memset(m_unk1DC, 0, 0xC);
        m_unk1D4 = 0;
        m_unk1D8 = 0;
        for (int i = 0; i < 3; i++) {
            int v = m_unk1F0[i];
            if (v >= 0) {
                m_unk1C8[m_unk1D4] = v;
                m_unk1D4++;
            }
        }
        if (m_unk1D4 == 0) {
            CdsAssert__FPciPc("EnemyGenerator.cpp", 0x34, "m_iNumEnemyTypes");
        }
        m_unk1E8 = -1;
        if (m_unk1BC != 0) {
            m_unk1B0 = 0;
            m_unk1B4 = CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk4, m_unk1BC, 1);
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        SetState__15EntityBaseClassFi(this, 1);
        return;
    }
}

// FUNCTION: 0x0020E580 __ct__14EnemyGeneratorFv
EnemyGenerator::EnemyGenerator() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 0);
    *(unsigned char **)this = __vt__14EnemyGenerator;
    EnableSleep__15EntityBaseClassFbb(this, 0, 0);
    m_unk1B8 = 0;
    m_unk1BC = 0x1E0;
    m_unk1C0 = 0x1E0;
    m_unk1C4 = 0;
}
