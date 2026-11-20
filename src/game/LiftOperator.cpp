// FLAGS: -str readonly
#include "types.h"
#include "PArray.h"
#include "LiftOperator.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pMsg);
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
                CdsAssert__FPciPc("LiftOperator.cpp", 0x14C, "pEnt");
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
            CdsAssert__FPciPc("LiftOperator.cpp", 0xED, "m_pAnimNode");
        }
        ((PMNodeVirtView *)m_unk1F8)->SetFrameTime(0.0f);
        ((PMNodeVirtView *)m_unk1F8)->Animate(0.0f, 0.0f, 0, 0, false);
        m_unk1F8->SetFrameRate(0.5f, true);
        ((PMNodeVirtView *)m_unk1F8)->SetAllAnimFlags(0);
        m_unk1F8->EnableAnim(false, true);
    }
}

// FUNCTION: 0x00210440 __ct__12LiftOperatorFv
LiftOperator::LiftOperator() : EntityBaseClass((LoadClass)2, 0) {
    m_unk1F8 = 0;
    miSpawnLevel__12LiftOperator = 6;
}
