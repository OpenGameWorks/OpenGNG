#include "Projectile.h"
#include "types.h"

// TODO(header): foreign declarations
extern unsigned char __vt__10Projectile[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void LoadMesh__15EntityBaseClassFUibb(void *pThis, unsigned int nMesh, bool bA, bool bB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void ProcessFxTriggers__6PMNodeFfP5PMat4bb(void *pThis, float fTime, void *pMat, bool bA, bool bB);
extern "C" void __dl__FPv(void *pMem);
extern "C" int InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(void *pThis, int nType, float (*pA)[4], float (*pB)[4], float (*pC)[4]);
extern "C" float sinf(float fX);
extern "C" float cosf(float fX);
extern float IceDoomPos[5][4];
extern "C" void FreezeCheck__15EntityBaseClassFP15EntityBaseClassi(void *pThis, void *pArg, int nArg);
extern "C" void ExtendCombo__6PlayerFv(void *pPlayer);
extern "C" void GameVarAdd__6PlayerFUiii(void *pPlayer, unsigned int nVar, int nA, int nB);
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, float (*pFx)[4], int nObjType, int nWeaponType, bool bFlag);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nHandle);
extern "C" void StopShooting__10HighwaymanFv(void *pThis);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern void *mpEntMgr__15EntityBaseClass;

// Virtual number 21 (vtable slot 0x5C) is OnAttackEvent. The twenty placeholders
// before it put that method in the same slot as EntityBaseClass::OnAttackEvent.
class ProjectileAttackView {
public:
    virtual ~ProjectileAttackView();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
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
    virtual void OnAttackEvent(void *pArg, int nArg);
};

// FUNCTION: 0x00166BB0 __dt__10ProjectileFv
extern "C" Projectile *__dt__10ProjectileFv(Projectile *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->m_unk0 = __vt__10Projectile;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00166C20 Delete__10ProjectileFv
void Projectile::Delete() {
    PMNode *pNode = m_unk3C;
    if (pNode != 0) {
        ProcessFxTriggers__6PMNodeFfP5PMat4bb(pNode, -1.0f, 0, true, false);
        LoadMesh__15EntityBaseClassFUibb(this, 0, false, true);
    }
    SetState__15EntityBaseClassFi(this, -2);
}

// FUNCTION: 0x00166C80 DoDamage__10ProjectileFb
void Projectile::DoDamage(bool bFlag) {
    ProjectileRecord *pRec = &ProjectileTable[m_unk1B0];
    if (bFlag) {
        unsigned short nHi = pRec->m_unk1A;
        m_unk15C = pRec->m_unk18;
        m_unk15E = nHi;
    } else {
        unsigned short nHi = pRec->m_unk1A;
        m_unk15C = 0;
        m_unk15E = nHi;
    }
}

// DRAFT: 0x00166CD0 OnAttackEvent__10ProjectileFP15EntityBaseClassi
// note: 121 words differ; prologue through 0x27 matches, the guard beqz target is 5 words short (original block is larger, nKind==6 body placed at block end). Tried: hoisting nObjType=3 (126), nKind==3 tested first (127), this+0x1B0 cached address (134).
void Projectile::OnAttackEvent(EntityBaseClass *pArg, int nArg) {
    FreezeCheck__15EntityBaseClassFP15EntityBaseClassi(this, pArg, nArg);
    if (*(unsigned char *)&m_unk1B8 != 0) {
        int nObjType;
        int nKind = *(int *)((char *)pArg + 0x10);
        if (nKind == 6) {
            nObjType = 3;
        } else if (nKind == 3) {
            void *pPlayer = *(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C);
            if (nArg == 3 || nArg == 4) {
                ExtendCombo__6PlayerFv(pPlayer);
            } else if (nArg == 1 || nArg == 2) {
                if (m_unk15C != 0) {
                    GameVarAdd__6PlayerFUiii(pPlayer, 0x12, 1, 0);
                }
            }
            nObjType = (*(unsigned char *)((char *)pArg + 0x166) == 0) ? 4 : 2;
        } else {
            nObjType = 5;
        }
        CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(this, 0, nObjType, 4, nArg >= 3);
    }
    int nLevel = m_unk1B0;
    if (nLevel < 9) {
        if (nLevel == 2 || nLevel == 3) {
            if (*(int *)((char *)pArg + 0x8) == 0x25) {
                int nSub = *(int *)((char *)pArg + 0x1B0);
                if (nSub == 0 || nSub == 0x10 || nSub == 0x11) {
                    return;
                }
            }
        }
    }
    if (*(int *)((char *)this + 0x20) != 1) {
        SetState__15EntityBaseClassFi(this, 1);
    }
    if (m_unk1B0 == 0x1C) {
        if (*(unsigned char *)((char *)pArg + 0x10C) == 1) {
            void *pApp = ApparitionIsValid__15EntityBaseClassFUi(*(unsigned int *)((char *)this + 0x1EC));
            if (pApp != 0) {
                ((ProjectileAttackView *)pApp)->OnAttackEvent(this, 0);
            }
        }
    }
    if (m_unk1B0 == 4) {
        PlaySound__15EntityBaseClassFUi(this, 0x165);
    }
    if (nArg < 3) {
        void *pApp = ApparitionIsValid__15EntityBaseClassFUi(*(unsigned int *)((char *)this + 0x1EC));
        if (pApp != 0) {
            StopShooting__10HighwaymanFv(pApp);
        }
    }
    if (m_unk1B0 == 6) {
        PlaySound__15EntityBaseClassFUi(this, 0x1CE);
    }
}

// DRAFT: 0x00166F00 InitIceDoom__10ProjectileFiPA4_fPA4_f
// note: 36 words differ: original has dead lui v0,0x3F80 and keeps the IceDoomPos row in v1 (ours uses v0); tried inline indexing (40), float*/float(*)[4] row pointers (36), unused 1.0f local (dropped by compiler)
void Projectile::InitIceDoom(int nIndex, float (*pOut)[4], float (*pIn)[4]) {
    float vec[4];
    m_unk1BC = nIndex;
    float fAngle = 0.017453292f * pIn[0][1];
    float fSin = sinf(fAngle);
    float fCos = cosf(fAngle);
    float (*pRow)[4] = IceDoomPos + nIndex;
    vec[0] = pOut[0][0] + (pRow[0][2] * fSin + pRow[0][0] * fCos);
    vec[1] = pOut[0][1];
    vec[2] = pOut[0][2] + (pRow[0][2] * fCos - pRow[0][0] * fSin);
    InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(this, 0x19, (float (*)[4])vec, pIn, 0);
    *(u_long128 *)&m_unk1D0 = *(u_long128 *)pOut;
    *(u_long128 *)&m_unk1C0 = *(u_long128 *)pIn;
    m_unk1B4 = 15.0f;
}

// FUNCTION: 0x00168140 __ct__10ProjectileFv
Projectile::Projectile() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 1);
    m_unk0 = __vt__10Projectile;
    EnableSleep__15EntityBaseClassFbb(this, false, false);
    m_unk1BC = 0;
    m_unk1F4 = 0;
}
