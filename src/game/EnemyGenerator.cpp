#include "types.h"
#include "EnemyGenerator.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

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
extern "C" int RandomIntRange__7MathAPIFii(int nLo, int nHi);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void *Spawn__13EntityManagerFUibi(void *pThis, unsigned int nType, bool bFlag, int nArg);

// Virtual slots of the apparition object, declared in slot order: virtual number N is
// slot 0x08 + 4 * N. SetInnocentInstanceID (slot 0x30) and GetHealth (slot 0x34) are
// called through $t9 as the original does; SetSpawnedFromEntity is slot 0x68.
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
    virtual void SetInnocentInstanceID(unsigned int nId);
    virtual int GetHealth();
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
    virtual void Slot22();
    virtual void Slot23();
    virtual void SetSpawnedFromEntity(float *pPos, float *pAlt, int nType);
    int m_unk4;
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

// FUNCTION: 0x0020DDF0 GetHealth__14EnemyGeneratorFv
int EnemyGenerator::GetHealth() {
    return 100;
}

// FUNCTION: 0x0020DE10 GetWokenVarPos__14EnemyGeneratorFv
int EnemyGenerator::GetWokenVarPos() {
    return 4;
}

// FUNCTION: 0x0020DE20 GetClassName__14EnemyGeneratorFv
const char *EnemyGenerator::GetClassName() {
    return "EnemyGenerator";
}

// FUNCTION: 0x0020DE30 SetEditableVars__14EnemyGeneratorFPc
void EnemyGenerator::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1EC, pSrc, 0x18);
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

// DRAFT: 0x0020DF30 GenerateEnemy__14EnemyGeneratorFv
// note: 209 words differ: loop-head compare uses $v1 not original $a0/$at, arm-end b targets and pointer-select layout differ; combined continue, reversed case order (211) and reversed upper-bound compare tried, no gain
void EnemyGenerator::GenerateEnemy() {
    if (m_unk1D4 == 0) {
        CdsAssert__FPciPc("EnemyGenerator.cpp", 0x7A, "m_iNumEnemyTypes");
    }
    if (m_unk1D8 >= 3) {
        CdsAssert__FPciPc("EnemyGenerator.cpp", 0x7B, "m_iNumEnemies < MAX_GENERATED_ENEMIES");
    }
    int nRoll = RandomIntRange__7MathAPIFii(0, 100);
    int nStep = 100 / m_unk1D4;
    for (int i = 0; i < m_unk1D4; i++) {
        if (nRoll < nStep * i) {
            continue;
        }
        if (nStep * m_unk1D4 < nRoll) {
            continue;
        }
        void *pEnt;
        switch (i) {
        case 0:
            pEnt = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x17, false, 0);
            if (pEnt == 0) {
                CdsAssert__FPciPc("EnemyGenerator.cpp", 0x90, "apEntity");
            }
            if (RandomIntRange__7MathAPIFii(0, 4) == 0) {
                void *pApp = m_unk3C;
                float *pAlt = pApp ? (float *)((char *)pApp + 0x90) : (float *)((char *)this + 0x1A0);
                float *pPos = pApp ? (float *)((char *)pApp + 0x80) : m_unk190;
                ((EnemyGeneratorVirtuals *)pEnt)->SetSpawnedFromEntity(pPos, pAlt, 1);
            } else {
                void *pApp = m_unk3C;
                float *pAlt = pApp ? (float *)((char *)pApp + 0x90) : (float *)((char *)this + 0x1A0);
                float *pPos = pApp ? (float *)((char *)pApp + 0x80) : m_unk190;
                ((EnemyGeneratorVirtuals *)pEnt)->SetSpawnedFromEntity(pPos, pAlt, 0);
            }
            break;
        case 1:
            pEnt = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x22, false, 0);
            if (pEnt == 0) {
                CdsAssert__FPciPc("EnemyGenerator.cpp", 0x9E, "apEntity");
            }
            if (RandomIntRange__7MathAPIFii(0, 4) == 0) {
                void *pApp = m_unk3C;
                float *pAlt = pApp ? (float *)((char *)pApp + 0x90) : (float *)((char *)this + 0x1A0);
                float *pPos = pApp ? (float *)((char *)pApp + 0x80) : m_unk190;
                ((EnemyGeneratorVirtuals *)pEnt)->SetSpawnedFromEntity(pPos, pAlt, 1);
            } else {
                void *pApp = m_unk3C;
                float *pAlt = pApp ? (float *)((char *)pApp + 0x90) : (float *)((char *)this + 0x1A0);
                float *pPos = pApp ? (float *)((char *)pApp + 0x80) : m_unk190;
                ((EnemyGeneratorVirtuals *)pEnt)->SetSpawnedFromEntity(pPos, pAlt, 0);
            }
            break;
        case 2:
            pEnt = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x37, false, 0);
            if (pEnt == 0) {
                CdsAssert__FPciPc("EnemyGenerator.cpp", 0xA7, "apEntity");
            }
            if (RandomIntRange__7MathAPIFii(0, 4) == 0) {
                void *pApp = m_unk3C;
                float *pAlt = pApp ? (float *)((char *)pApp + 0x90) : (float *)((char *)this + 0x1A0);
                float *pPos = pApp ? (float *)((char *)pApp + 0x80) : m_unk190;
                ((EnemyGeneratorVirtuals *)pEnt)->SetSpawnedFromEntity(pPos, pAlt, 1);
            } else {
                void *pApp = m_unk3C;
                float *pAlt = pApp ? (float *)((char *)pApp + 0x90) : (float *)((char *)this + 0x1A0);
                float *pPos = pApp ? (float *)((char *)pApp + 0x80) : m_unk190;
                ((EnemyGeneratorVirtuals *)pEnt)->SetSpawnedFromEntity(pPos, pAlt, 0);
            }
            break;
        default:
            pEnt = 0;
            break;
        }
        if (pEnt == 0) {
            CdsAssert__FPciPc("EnemyGenerator.cpp", 0xB4, "apEntity");
        }
        EnableSleep__15EntityBaseClassFbb(pEnt, false, false);
        if (m_unk200 != 0 && InstanceIsValid__15EntityBaseClassFUi(m_unk200)) {
            ((EnemyGeneratorVirtuals *)pEnt)->SetInnocentInstanceID(m_unk200);
        }
        if (m_unk1E8 == -1) {
            if (m_unk1DC[m_unk1D8] != 0) {
                CdsAssert__FPciPc("EnemyGenerator.cpp", 0xC3, "m_EnemyRefs[m_iNumEnemies] == 0");
            }
            m_unk1DC[m_unk1D8] = ((EnemyGeneratorVirtuals *)pEnt)->m_unk4;
        } else {
            if (m_unk1DC[m_unk1E8] != 0) {
                CdsAssert__FPciPc("EnemyGenerator.cpp", 0xC9, "m_EnemyRefs[m_iEmptyEnemySlot] == 0");
            }
            m_unk1DC[m_unk1E8] = ((EnemyGeneratorVirtuals *)pEnt)->m_unk4;
            m_unk1E8 = -1;
        }
        m_unk1D8++;
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
