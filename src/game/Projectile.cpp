// FLAGS: -str readonly
#include "Projectile.h"
#include "types.h"

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Projectile.cpp", line, #cond))
// The original names some tested members differently from the header; the message is given explicitly.
#define CDS_ASSERT_NAMED(line, name, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Projectile.cpp", line, name))

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" float RandomFloatRange__7MathAPIFff(float fMin, float fMax);
extern "C" void LoadAnim__15EntityBaseClassFUib(void *pThis, unsigned int nAnim, bool bLoop);
extern "C" void SetAnimData__15EntityBaseClassFP8AnimData(void *pThis, void *pData);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *pThis, int nType, unsigned int nFlags);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pA)[4]);
extern "C" void SetVelocity__7PhysicsFff(void *pThis, float fA, float fB);
extern "C" void *GetFirstMesh__6PMNodeFv(void *pThis);
extern "C" void *Spawn__13EntityManagerFUibi(void *pThis, unsigned int nId, int nA, bool bB);
extern "C" void ShakeScreenUsingTable__9CameraAPIFiUi(void *pThis, int nA, unsigned int nB);
extern "C" void DisableAllHitBox__6PMNodeFv(void *pThis);
extern int mbHard__15EntityBaseClass;
extern void *mCameraAPI__13EntityManager;
extern unsigned char mEffectAPI__13EntityManager[];
extern unsigned char Anim[0x10];
extern unsigned char __vt__10Projectile[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void LoadMesh__15EntityBaseClassFUibb(void *pThis, unsigned int nMesh, bool bA, bool bB);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void ProcessFxTriggers__6PMNodeFfP5PMat4bb(void *pThis, float fTime, void *pMat, bool bA, bool bB);
extern "C" void __dl__FPv(void *pMem);
extern "C" float sinf(float fX);
extern "C" float cosf(float fX);
extern float IceDoomPos[5][4];
extern "C" void FreezeCheck__15EntityBaseClassFP15EntityBaseClassi(void *pThis, void *pArg, int nArg);
extern "C" void ExtendCombo__6PlayerFv(void *pPlayer);
extern "C" void GameVarAdd__6PlayerFUiii(void *pPlayer, unsigned int nVar, int nA, int nB);
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, float (*pFx)[4], int nObjType, int nWeaponType, bool bFlag);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nHandle);
extern "C" void StopShooting__10HighwaymanFv(void *pThis);
extern "C" unsigned int PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern void *mpEntMgr__15EntityBaseClass;
extern "C" int CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(void *pThis, unsigned int nA, unsigned int nB, void *pA, void *pB, void *pC, float fScale, bool bA, int nC, bool bD);
extern "C" void *EffectValid__9EffectAPIFUi(void *pThis, unsigned int nHandle);
extern "C" void DeleteEffect__9EffectAPIFUi(void *pThis, unsigned int nHandle);
extern "C" void CheckSwordBGAnim__13EntityManagerFP6PMNode(void *pThis, void *pNode);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(void *pA, void *pB);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(void *pA, void *pB);
extern "C" void VectorRotateY__7MathAPIFPA4_ff(void *pThis, void *pV, float fAngle);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pEnt, void *pPos);
extern "C" int RandomIntRange__7MathAPIFii(int nMin, int nMax);
extern "C" int GetGroundPos__11BGCollisionFPA4_f(void *pThis, void *pPos);
extern "C" void StopShockwaveAttack__13SulfurMonsterFv(void *pThis);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, void *pSeq);
extern "C" void RegisterPotShotDeath__7AchilleFUi(void *pThis, unsigned int nA);
extern "C" void sceVu0ScaleVector(float *pOut, float *pIn, float fScale);
extern "C" void sceVu0AddVector(float *pOut, float *pA, float *pB);
extern void *mPlayerAPI__13EntityManager;
extern unsigned char mEffectAPI__13EntityManager[0x100];
extern unsigned char SiegePuncher_ExplodeSeq[0x10];
extern unsigned int m_AchilleRef__7Achille;
extern unsigned char mBGCollision__15EntityBaseClass[0x10];
extern unsigned char gEng[0x1A000];

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
    InitProjectile((ProjectileType)0x19, (float (*)[4])vec, pIn, 0);
    *(u_long128 *)&m_unk1D0 = *(u_long128 *)pOut;
    *(u_long128 *)&m_unk1C0 = *(u_long128 *)pIn;
    m_unk1B4 = 15.0f;
}

// DRAFT: 0x00167000 Execute__10ProjectileFv
// note: partial (size 0x258 vs 0xCD0); cases 0 (m_unk1B0 == 8 block), 1, 4 and 5 are missing, and case 2 omits its m_unk1B0 == 0x1C branch.
void Projectile::Execute() {
    switch (m_unk20) {
    case -1:
        SetState__15EntityBaseClassFi(this, (m_unk1B0 < 9) ? 0 : 2);
        return;
    case -2:
        if (m_unk1F4 != 0) {
            DeleteEffect__9EffectAPIFUi(&mEffectAPI__13EntityManager, m_unk1F4);
            m_unk1F4 = 0;
        }
        break;
    case 0:
        if (m_unkE9 != 0) {
            m_unk1E4 = 0.0f;
            m_unk1E8 = 0.0f;
        }
        CheckSwordBGAnim__13EntityManagerFP6PMNode(mpEntMgr__15EntityBaseClass, m_unk3C);
        if (!(m_unkE8 & *(unsigned int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058))) {
            m_unk1B4 = m_unk1B4 - *(float *)((char *)gEng + 0x1E8);
            if (m_unk1B4 <= 0.0f) {
                SetState__15EntityBaseClassFi(this, -2);
            } else if (m_unk1B0 != 8 &&
                       (*(int *)((char *)m_unk38 + 0xE4) != 0 ||
                        (*(int *)((char *)m_unk38 + 0x108) & 1))) {
                SetState__15EntityBaseClassFi(this, 1);
            }
        }
        break;
    case 2:
        if ((*(unsigned char *)((char *)m_unk3C + 0x3F) & 7) == 0) {
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        break;
    case 3:
        CheckSwordBGAnim__13EntityManagerFP6PMNode(mpEntMgr__15EntityBaseClass, m_unk3C);
        if (m_unk1B4 != 0.0f) {
            m_unk1B4 = m_unk1B4 - *(float *)((char *)gEng + 0x1E8);
            if (m_unk1B4 <= 0.0f) {
                m_unk1B4 = 0.0f;
                m_unk1BC = m_unk1BC + 1;
                if ((unsigned int)m_unk1BC < 5U) {
                    void *pSpawn = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2D, 0, false);
                    CDS_ASSERT_NAMED(0x222, "pIce", pSpawn != 0);
                    ((Projectile *)pSpawn)->InitIceDoom(m_unk1BC, (float (*)[4])&m_unk1D0, (float (*)[4])&m_unk1C0);
                }
            }
        }
        if ((*(unsigned char *)((char *)m_unk3C + 0x3F) & 7) == 0) {
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        break;
    default:
        break;
    }
}

// DRAFT: 0x00167CD0 InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f
// note: switch dispatch is emitted as an ascending chain; original is beq 8,4,1E,7,6,1D,5,1C,3,2 with shared bodies; 246 words differ.
void Projectile::InitProjectile(ProjectileType nType, float (*pA)[4], float (*pB)[4], float (*pC)[4]) {
    static float ProjectileBox[2][4] = {{0.0f, 0.0f, 0.0f, 1.0f}, {0.75f, 0.5f, 0.75f, 1.0f}};
    CDS_ASSERT_NAMED(0x89, "eType < MaxProjectile", nType < PROJECTILE_TYPE_COUNT);
    m_unk1B0 = nType;
    ProjectileRecord *pRec = &ProjectileTable[nType];
    unsigned short nDamage = pRec->m_unk18;
    switch (nType) {
    case 8:
        m_unk10C &= 0xF8FFFFFF;
        *(unsigned char *)&m_unk1B8 = 0;
        m_unkE8 = 0xB;
        if (m_unkD4 == 0) {
            void *pShadow = __nw__FUi(0x10);
            if (pShadow != 0) {
                pShadow = __ct__6ShadowFQ26Shadow10ShadowTypeUi(pShadow, 1, 0x87000008);
            }
            m_unkD4 = (Shadow *)pShadow;
            CDS_ASSERT_NAMED(0xB3, "mpShadow", m_unkD4 != 0);
        }
        break;
    case 4:
    case 0x1E:
        m_unk10C |= 0x02001100;
        *(unsigned char *)&m_unk1B8 = 0;
        m_unkE8 = 0xB;
        break;
    case 7:
    case 6:
    case 0x1D:
    case 5:
    case 0x1C:
    case 3:
    case 2:
        m_unk10C |= 0x021B1902;
        *(unsigned char *)&m_unk1B8 = 0;
        m_unkE8 = 0xB;
        break;
    default:
        m_unk10C = 0x02001A01;
        *(unsigned char *)&m_unk1B8 = 1;
        m_unkE8 = 3;
        if (nDamage != 0 && mbHard__15EntityBaseClass == 0) {
            nDamage = (unsigned short)(nDamage + 0x19);
        }
        break;
    }

    m_unk1B4 = pRec->m_unk10;
    *(u_long128 *)&m_unk1D0 = *(u_long128 *)pA;
    *(u_long128 *)&m_unk190 = *(u_long128 *)pA;
    *(u_long128 *)&m_unk1A0 = *(u_long128 *)pB;
    LoadMesh__15EntityBaseClassFUibb(this, pRec->m_unk0, false, true);
    if (pRec->m_unk4 != 0) {
        LoadAnim__15EntityBaseClassFUib(this, pRec->m_unk4, true);
    }
    *(short *)(Anim + 8) = (pRec->m_unk10 == 0.0f) ? 1 : 0;
    *(float *)(Anim + 0xC) = pRec->m_unk1C;
    SetAnimData__15EntityBaseClassFP8AnimData(this, Anim);
    m_unk15C = nDamage;
    m_unk15E = pRec->m_unk1A;

    if (nType < 9) {
        void *pPhys = __nw__FUi(0x120);
        if (pPhys != 0) {
            pPhys = __ct__7PhysicsFv(pPhys);
        }
        m_unk38 = (Physics *)pPhys;
        CDS_ASSERT_NAMED(0xDE, "mpPhysics", m_unk38 != 0);
        if (nType != 8) {
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x14, 0);
            *(int *)((char *)m_unk38 + 0xEC) = 0x58;
        }
        if (pC != 0) {
            *(u_long128 *)m_unk38 = *(u_long128 *)pC;
        } else {
            SetVelocity__7PhysicsFff(m_unk38, pB[0][1], pRec->m_unk14);
        }
        *((unsigned char *)GetFirstMesh__6PMNodeFv(m_unk3C) + 0xE) = 0xA0;
        *(u_long128 *)((char *)m_unk38 + 0x80) = *(u_long128 *)ProjectileBox[0];
        *(u_long128 *)((char *)m_unk38 + 0x90) = *(u_long128 *)ProjectileBox[1];
    } else if (nType == 0x1C) {
        void *pPhys = __nw__FUi(0x120);
        if (pPhys != 0) {
            pPhys = __ct__7PhysicsFv(pPhys);
        }
        m_unk38 = (Physics *)pPhys;
        CDS_ASSERT_NAMED(0xF8, "mpPhysics", m_unk38 != 0);
        SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x14, 0);
        *(int *)((char *)m_unk38 + 0xEC) = 0x00100080;
    } else {
        if (nType == 0x18) {
            void *pSpawn = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2D, 0, false);
            CDS_ASSERT_NAMED(0xFF, "pIce", pSpawn != 0);
            ((Projectile *)pSpawn)->InitIceDoom(0, pA, pB);
        }
        ShakeScreenUsingTable__9CameraAPIFiUi(&mCameraAPI__13EntityManager, 0, 0);
        DisableAllHitBox__6PMNodeFv(m_unk3C);
    }

    if (pRec->m_unk8 != 0) {
        PlaySound__15EntityBaseClassFUi(this, pRec->m_unk8);
    }
    if (pRec->m_unkC != 0) {
        PlaySound__15EntityBaseClassFUi(this, pRec->m_unkC);
    }
    if (pRec->m_unk20 != 0) {
        SetState__15EntityBaseClassFi(this, pRec->m_unk20);
    }
}

// FUNCTION: 0x00168140 __ct__10ProjectileFv
Projectile::Projectile() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 1);
    m_unk0 = __vt__10Projectile;
    EnableSleep__15EntityBaseClassFbb(this, false, false);
    m_unk1BC = 0;
    m_unk1F4 = 0;
}
