// FLAGS: -str readonly
#include "types.h"
#include "PArray.h"
#include "LiftOperator.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" void CdsAssert__FPciPc(const char *pFile, int nLine, const char *pMsg);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__12LiftOperator[0x7C];
extern int miSpawnLevel__12LiftOperator;
extern unsigned char gEng[];
extern "C" int RandomIntRange__7MathAPIFii(int nLo, int nHi);
extern void *mpEntMgr__15EntityBaseClass;
extern PArray mTempArray__15EntityBaseClass;
extern "C" void GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *pThis, int nLoadClass, PArray *pList, float (*pBox)[4], float fRadius, int nFilter, bool bA, bool bB);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);

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

// DRAFT: 0x00210440 __ct__12LiftOperatorFv
// note: 26 differing words; compiled code spills this to 0x1C(sp), uses sd ra,0(sp) and stores vptr via reloaded this, original keeps this in s0 (sq s0,0(sp)) and frame 0x20; vptr/member store order variants gave no gain
LiftOperator::LiftOperator() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 2, 0U);
    *(void **)this = __vt__12LiftOperator;
    m_unk1F8 = 0;
    miSpawnLevel__12LiftOperator = 6;
}
