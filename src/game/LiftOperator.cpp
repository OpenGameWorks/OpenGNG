// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PArray.h"
#include "LiftOperator.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern int miSpawnLevel__12LiftOperator;
extern unsigned char gEng[];
extern "C" int RandomIntRange__7MathAPIFii(int nLo, int nHi);
extern void *mpEntMgr__15EntityBaseClass;
extern PArray mTempArray__15EntityBaseClass;
extern "C" void GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *pThis, int nLoadClass, PArray *pList, float (*pBox)[4], float fRadius, int nFilter, bool bA, bool bB);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void *Spawn__13EntityManagerFUibi(void *pThis, unsigned int nType, bool bFlag, int nArg);
extern "C" float RandomFloatRange__7MathAPIFff(float fLo, float fHi);
extern "C" void SetSpawnedFromLift__15ClockworkReaperFv(void *pThis);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *pA, void *pB);
extern void *mPlayerAPI__13EntityManager;

// MinSpawnCount is indexed by miSpawnLevel; the values come from the original .data at 0x251630.
static int MinSpawnCount[7] = {0, 5, 5, 5, 4, 4, 3};

// PMNode.h declares SetFrameTime, Animate and SetAllAnimFlags non-virtual; the original
// calls them through vtable slots 0x10, 0x18 and 0x1C, so this view supplies those slots.
struct PMNodeVirtView {
    virtual ~PMNodeVirtView();
    virtual void Render(void *pLights, int nA, int nB);
    virtual void SetFrameTime(float fTime);
    virtual void CreateObjectDisplayList();
    virtual void Animate(float fA, float fB, void *pMat, int nFlag, bool bFlag);
    virtual void SetAllAnimFlags(void *pAnim);
};

// Spawned entities are reached through vtable slot 0x68 (virtual number 24): the virtual
// destructor takes slot 0, then 23 placeholder slots precede SetSpawnedFromEntity.
struct SpawnedEntityVirtView {
    virtual ~SpawnedEntityVirtView();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
    virtual void Slot10();
    virtual void Slot11();
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
};

// FUNCTION: 0x0020FA70 __dt__12LiftOperatorFv
LiftOperator::~LiftOperator() {
}

// FUNCTION: 0x0020FAD0 GetClassName__12LiftOperatorFv
const char *LiftOperator::GetClassName() {
    return "LiftOperator";
}

// FUNCTION: 0x0020FAE0 SpawnEnemy__12LiftOperatorFv
void LiftOperator::SpawnEnemy() {
    int nState = *(int *)(gEng + 0x19A78);
    if (nState == 8) {
        if (miSpawnLevel__12LiftOperator != 0) {
            if (m_unk1C0 == 8) {
                SpawnEnemyType(3, 1);
                return;
            }
            if (RandomIntRange__7MathAPIFii(0, 4) == 0) {
                SpawnEnemyType(1, 1);
                return;
            }
            SpawnEnemyType(0, 1);
            return;
        }
    }
    if (nState == 18) {
        int nMode = 2;
        if (m_unk1FE >= m_unk1D0 * 2) {
            nMode = 1;
        }
        if (m_unk200 & 1) {
            SpawnEnemyType(m_unk1CC, nMode);
        } else {
            SpawnEnemyType(m_unk1C8, nMode);
        }
        m_unk200 += 1;
    }
}

// DRAFT: 0x0020FBE0 SpawnEnemyType__12LiftOperatorFUii
// note: 75 words differ: loop-exit beqz target (+0x50 vs +0x4A), second RandomFloatRange call order, sum register (f1/f0), constant-load registers; variants tried: vec/fOff operand order, compound +=, 0 < nType guard.
void LiftOperator::SpawnEnemyType(unsigned int nApparitionId, int nType) {
    int nVariant = 0;
    switch (nApparitionId) {
    case 0:
        nApparitionId = 0x17;
        break;
    case 1:
        nApparitionId = 0x17;
        nVariant = 1;
        break;
    case 2:
        nApparitionId = 0x17;
        nVariant = 2;
        break;
    case 3:
        nApparitionId = 0x22;
        break;
    case 4:
        nApparitionId = 0x22;
        nVariant = 1;
        break;
    case 5:
        nApparitionId = 0x37;
        break;
    case 6:
        nApparitionId = 0x37;
        nVariant = 1;
        break;
    case 7:
        nApparitionId = 0x2B;
        break;
    case 8:
        nApparitionId = 0x6B;
        break;
    case 9:
        nApparitionId = 0x6B;
        nVariant = 1;
        break;
    case 10:
        nApparitionId = 0x72;
        break;
    }
    int i = 0;
    if (0 < nType) {
        do {
            void *pEnt = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, nApparitionId, false, 0);
            if (pEnt == 0) {
                CdsAssert("LiftOperator.cpp", 0x14C, "pEnt");
            }
            float vec[4];
            *(u_long128 *)vec = *(u_long128 *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190);
            float fOff = 1e-8f * (float)i;
            vec[0] += fOff + RandomFloatRange__7MathAPIFff(-0.1f, 0.1f);
            vec[2] += fOff + RandomFloatRange__7MathAPIFff(-0.1f, 0.1f);
            float *pDst = (float *)(m_unk3C ? m_unk3C + 0x90 : (char *)this + 0x1A0);
            ((SpawnedEntityVirtView *)pEnt)->SetSpawnedFromEntity(vec, pDst, nVariant);
            if (nApparitionId == 0x17) {
                SetSpawnedFromLift__15ClockworkReaperFv(pEnt);
            }
            ((EntityBaseClass *)pEnt)->EnableSleep(false, false);
            i++;
        } while (i < nType);
    }
    m_unk1FE += nType;
}

// FUNCTION: 0x0020FE20 EnemiesInRadius__12LiftOperatorFPA4_ffb
int LiftOperator::EnemiesInRadius(float (*pBox)[4], float fRadius, bool bFlag) {
    if (mTempArray__15EntityBaseClass.m_unk8 != 0) {
        mTempArray__15EntityBaseClass.m_unk0 = 0;
        mTempArray__15EntityBaseClass.m_unk4 = 0;
    }
    GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, &mTempArray__15EntityBaseClass, pBox, fRadius, -1, false, false);
    unsigned int i;
    int nCount = 0;
    if (bFlag) {
        for (i = 0; i < mTempArray__15EntityBaseClass.m_unk0; i++) {
            void *pEnt = ApparitionIsValid__15EntityBaseClassFUi((i < mTempArray__15EntityBaseClass.m_unk0) ? (unsigned int)mTempArray__15EntityBaseClass.m_unk8[i] : 0U);
            if (pEnt != 0 && *(int *)((char *)pEnt + 0x20) >= 0) {
                nCount++;
            }
        }
    } else {
        nCount = mTempArray__15EntityBaseClass.m_unk0;
    }
    return nCount;
}

// FUNCTION: 0x0020FF20 SetEditableVars__12LiftOperatorFPc
void LiftOperator::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x48);
    PMNode *pNode = *(PMNode **)gEng;
    if (pNode != 0) {
        m_unk1F8 = pNode->FindAnimNode(m_unk1C0);
        if (m_unk1F8 == 0) {
            CdsAssert("LiftOperator.cpp", 0xED, "m_pAnimNode");
        }
        ((PMNodeVirtView *)m_unk1F8)->SetFrameTime(0.0f);
        ((PMNodeVirtView *)m_unk1F8)->Animate(0.0f, 0.0f, 0, 0, false);
        m_unk1F8->SetFrameRate(0.5f, true);
        ((PMNodeVirtView *)m_unk1F8)->SetAllAnimFlags(0);
        m_unk1F8->EnableAnim(false, true);
    }
}

// DRAFT: 0x00210000 Execute__12LiftOperatorFv
// note: 258 words, size 0x494 vs 0x438. Differs: switch range branch at 0x18 (0x103 vs 0x11A), case -1 store/call delay-slot fill at 0x54-0x78, gEng/player and Distance branch shapes 0x98-0xF0, case 0 E9 test and tail layout from 0xF8. Tried: 0x1FE store after the first memcpy (259 to 258, kept); 0x200 store after the second memcpy (262, reverted).
void LiftOperator::Execute() {
    static unsigned char acheckwake;
    static char init;
    static short mAnimData[8] = {0, -1, 0, -1, 1, 6, 0, 0};
    int cnt;

    switch (m_unk20) {
    case -2:
    case 1:
        break;
    case -1:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            EnableSleep(false, false);
            memcpy(m_unk220, m_unk1B0, 0xC);
            m_unk1FE = 0;
            m_unk200 = 0;
            memcpy(m_unk230, m_unk1D8, 0xC);
            memcpy(m_unk210, m_unk1E8, 0xC);
        }
        if (*(int *)(gEng + 0x19A78) == 0x12) {
            char *pPlayer = (char *)mPlayerAPI__13EntityManager;
            miSpawnLevel__12LiftOperator = 4;
            char *pT = *(char **)(pPlayer + 0x3C);
            char *pTarget = pT ? pT + 0x80 : pPlayer + 0x190;
            if (Distance__7MathAPIFPA4_fPA4_f(m_unk210, pTarget) <= m_unk1F4) {
                SetState(0);
            }
        } else {
            SetState(0);
        }
        return;
    case 0:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            if (*(int *)(gEng + 0x19A78) == 8) {
                m_unk1FC = RandomIntRange__7MathAPIFii(0, 0x190);
            } else {
                m_unk1FC = RandomIntRange__7MathAPIFii(0, 0x3C);
            }
            return;
        }
        if (--m_unk1FC > 0) {
            return;
        }
        if (init == 0) {
            acheckwake = 0;
            init = 1;
        }
        cnt = EnemiesInRadius((float (*)[4])m_unk230, m_unk1E4, acheckwake);
        if (cnt < MinSpawnCount[miSpawnLevel__12LiftOperator]) {
            SetState(4);
        } else {
            m_unk1FC = RandomIntRange__7MathAPIFii(0, 0x190);
        }
        return;
    case 4:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            SpawnEnemy();
        } else {
            if ((m_unk1F8->m_unk3F & 7) == 0) {
                PlaySound(0x2CA);
                SetState(3);
            }
            return;
        }
        {
            short v = m_unk1C4 >> 1;
            mAnimData[0] = 0;
            mAnimData[2] = 0;
            mAnimData[1] = v;
            mAnimData[3] = v;
        }
        (*(PMNode **)gEng)->RecurseSetAnimFlagsByID(m_unk1C0, (AnimData *)mAnimData);
        PlaySound(0x2CC);
        return;
    case 3:
        if (EnemiesInRadius((float (*)[4])m_unk220, m_unk1BC, true) == 0) {
            SetState(2);
        }
        return;
    case 2:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            short v = m_unk1C4 >> 1;
            mAnimData[0] = v;
            mAnimData[2] = v;
            mAnimData[1] = m_unk1C4;
            mAnimData[3] = m_unk1C4;
            (*(PMNode **)gEng)->RecurseSetAnimFlagsByID(m_unk1C0, (AnimData *)mAnimData);
            PlaySound(0x2CC);
            return;
        }
        if ((m_unk1F8->m_unk3F & 7) != 0) {
            return;
        }
        PlaySound(0x2CA);
        if (*(int *)(gEng + 0x19A78) == 0x12) {
            if (m_unk1FE < m_unk1D4 + (m_unk1D0 << 1)) {
                SetState(0);
            } else {
                SetState(5);
            }
        } else {
            SetState(0);
        }
        return;
    case 5:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            mAnimData[0] = 0;
            mAnimData[2] = 0;
            mAnimData[1] = 10;
            mAnimData[3] = 10;
            (*(PMNode **)gEng)->RecurseSetAnimFlagsByID(m_unk1C0, (AnimData *)mAnimData);
            PlaySound(0x2CC);
            if ((m_unk1F8->m_unk3F & 7) == 0) {
                PlaySound(0x2CA);
                SetState(6);
            }
            return;
        }
        SetState(0);
        return;
    case 6:
        if (EnemiesInRadius((float (*)[4])m_unk230, m_unk1E4, true) == 0) {
            SetState(-2);
            WriteApparitionData(1, -3, 0);
        }
        return;
    }
}

// FUNCTION: 0x00210440 __ct__12LiftOperatorFv
LiftOperator::LiftOperator() : EntityBaseClass((LoadClass)2, 0) {
    m_unk1F8 = 0;
    miSpawnLevel__12LiftOperator = 6;
}
