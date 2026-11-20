#include "types.h"
#include "Tinker.h"

// TODO(header): foreign declarations
class EntityBaseClass;
class EntityManager;
class PArray;
class MathAPI;
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(float (*)[4], float (*)[4]);
// Apparition scratch list used by GetAllActiveApparitionsInRadius (same layout as Innocent.cpp).
struct TempApparitionArray { int m_count; int m_unk04; unsigned int *m_pData; char _pad0C[4]; };
extern TempApparitionArray mTempArray__15EntityBaseClass;
// The second argument is not set by the caller; the original leaves a1 untouched.
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Tinker.cpp", line, #cond))
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" void *GetPtrToApparition__13EntityManagerFUi(EntityManager *pThis, unsigned int arg0);
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(EntityManager *pThis, int eLoadClass, PArray *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nState, char cParam, unsigned int uParam);
extern unsigned char gInterface[0xA60];
extern unsigned char gEng[0x19B90];
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bFlagA, bool bFlagB);
extern "C" void StartCutCamera__6CameraFUib(void *pThis, unsigned int arg0, bool bFlag);
extern "C" void Kill__6PlayerFv(void *pThis);
extern "C" void SetMaxValue__12HudBossMeterFsi(void *pThis, short nValue, int nFlag);
extern unsigned char __vt__6Tinker[0x10];
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char Tinker_AttackSeq[0x10];
extern unsigned char Tinker_Attack2Seq[0x10];
extern unsigned char Manda_AttackSeq[0x10];
extern unsigned char Baron_WalkSeq[0x10];
extern unsigned char Baron_RunSeq[0x10];
extern unsigned char Tinker_RunSeq[0x10];
extern unsigned char Tinker_WalkSeq[0x10];
extern unsigned char Manda_RunSeq[0x10];
extern unsigned char BGuard_RunSeq[0x10];
extern "C" void PlaySoundOnFrame__15EntityBaseClassFUiUi(void *pThis, unsigned int nSound, unsigned int nFrame);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
struct tagWaypointGroup { char _pad000[4]; unsigned int m_unk4; };
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" int ReadApparitionData__15EntityBaseClassFiUi(void *pThis, int nMode, unsigned int nId);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" float GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(EntityBaseClass *pEntity, float (*pPos)[4]);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void CheckVariable__15EntityBaseClassFii(EntityBaseClass *pThis, int nValue, int nIndex);
extern int mbHard__15EntityBaseClass;
extern "C" void FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(void *pThis, EntityBaseClass *pOther);
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, float (*pBox)[4], int nObjType, int nWeaponType, bool bFlag);
extern "C" void SetValue__12HudBossMeterFs(void *pThis, short nValue);

// Apparition objects are reached through a virtual table; slot 12 sits at offset 0x30.
class ApparitionVirtual {
public:
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
    virtual void Slot12(int arg);
    virtual int Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual int Slot17();
};

// FUNCTION: 0x00208D60 __dt__6TinkerFv
extern "C" Tinker *__dt__6TinkerFv(Tinker *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__6Tinker;
        __dt__6PArrayFv((char *)pThis + 0x2D0, -1);
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00208E10 AttackSound__6TinkerFv
void Tinker::AttackSound() {
    if (m_unk140 == (void *)Tinker_AttackSeq) {
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x2A4, 0xB);
    } else if (m_unk140 == (void *)Tinker_Attack2Seq) {
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x2A4, 0xB);
    } else if ((void *)Manda_AttackSeq != 0) {
        PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0xD9, 0xE);
    }
}

// FUNCTION: 0x00208E90 FootstepSound__6TinkerFv
void Tinker::FootstepSound() {
    int nType = m_unk1B0;
    int nSeq = (int)m_unk140;
    switch (nType) {
    case 1:
        if (nSeq == (int)Baron_WalkSeq || nSeq == (int)Baron_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E23, 0x12);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E23, 0x21);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E23, 0x30);
        }
        break;
    case 0:
        if (nSeq == (int)Tinker_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 5);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 0xE);
            return;
        }
        if (nSeq == (int)Tinker_WalkSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 0xA);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E22, 0x19);
        }
        break;
    case 2:
        if (nSeq == (int)Manda_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0xA);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0x14);
        }
        break;
    case 3:
        if (nSeq == (int)BGuard_RunSeq) {
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0xA);
            PlaySoundOnFrame__15EntityBaseClassFUiUi(this, 0x4E24, 0x14);
        }
        break;
    }
}

// FUNCTION: 0x00209440 SetAsActivatedEnemyTarget__6TinkerFv
void Tinker::SetAsActivatedEnemyTarget() {
    int i;
    int off;
    if (m_unk280 != 0) {
        CdsAssert__FPciPc("Tinker.cpp", 0xACD, "m_bTrapped == false");
    }
    for (i = 0, off = 0; i < 4; off += 4, i++) {
        EntityBaseClass *pEnt = *(EntityBaseClass **)((char *)this + off + 0x2AC);
        if (pEnt != 0) {
            ApparitionVirtual *pObj = (ApparitionVirtual *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pObj != 0) {
                pObj->Slot12(m_unk00C);
            }
        }
    }
}

// FUNCTION: 0x002094E0 SetAsEnemyTarget__6TinkerFUib
void Tinker::SetAsEnemyTarget(unsigned int arg0, bool arg1) {
    void *pObj = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, arg0);
    if (pObj != 0) {
        int v = arg1 ? m_unk00C : 0;
        ((ApparitionVirtual *)pObj)->Slot12(v);
    }
}

// FUNCTION: 0x00209E40 TrappedEntityRemoved__6TinkerFv
bool Tinker::TrappedEntityRemoved() {
    EntityBaseClass **pEnt = m_unk1F0;
    int i = 0;
    do {
        if (*pEnt != 0 && InstanceIsValid__15EntityBaseClassFUi(*pEnt)) {
            return false;
        }
        i++;
        pEnt++;
    } while (i < 4);
    return true;
}

// FUNCTION: 0x00209540 IsBadWaypoint__6TinkerFUi
unsigned int Tinker::IsBadWaypoint(unsigned int arg0) {
    int off;
    unsigned int n = m_unk2D0.m_unk0;
    unsigned int i;
    i = 0;
    off = 0;
    int v;
    goto test;
body:
    v = (i < n) ? *(int *)((char *)m_unk2D0.m_unk8 + off) : 0;
    if (v == (int)arg0) {
        return 1;
    }
    off += 4;
    i++;
test:
    if (i < n) goto body;
    return 0;
}

// DRAFT: 0x002095A0 GetClosestWaypoint__6TinkerFRA4_fb
// note: 30 words differ: if/else arm order for m_unk3C, bc1t/bc1f on the angle bool, bLast/nBest order (reorder tried, 49 words), epilogue return materialisation. Variants tried: early-return restructure, if/else DistanceXZ, stored bool bNear, bLast reorder.
int Tinker::GetClosestWaypoint(float (&pos)[4], bool bFlag) {
    int nBest;
    unsigned char bLast;
    float fBest;
    float *wp;
    unsigned int i;
    unsigned char bWpFlag;
    float p[4];
    float d;

    if (m_unk2A8 != 0) {
        nBest = -1;
        bLast = 0;
        fBest = 99999.0f;
        for (i = 0; i < m_unk2C8; i++) {
            wp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, (tagWaypointGroup *)m_unk2A8, i, bWpFlag);
            if (i == m_unk2C4 || IsBadWaypoint(i)) {
                continue;
            }
            p[0] = wp[0];
            p[1] = wp[1];
            p[2] = wp[2];
            if (bFlag) {
                unsigned char bNear;
                bNear = FastMath_Fabs__Ff(GetRelAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f((EntityBaseClass *)this, &p)) <= 90.0f;
                if (!bNear) {
                    continue;
                }
            }
            if (m_unk3C != 0) {
                d = DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])(m_unk3C + 0x80), &p);
            } else {
                d = DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])((char *)this + 0x190), &p);
            }
            if (d < fBest) {
                *(u_long128 *)pos = *(u_long128 *)p;
                fBest = d;
                nBest = i;
                bLast = 0;
                if (bWpFlag != 0) {
                    bLast = (i + 1 < m_unk2C8);
                }
            }
        }
        if (nBest >= 0) {
            Add__6PArrayFPv((char *)this + 0x2D0, (void *)m_unk2C4);
            m_unk2C4 = nBest;
            m_unk2E0 = bLast;
            return 1;
        }
    }
    return 0;
}

// DRAFT: 0x00209760 GetNextPosition__6TinkerFRA4_f
// note: 13 differing lines; branch layout at 0x18, 0x68, 0x88 and bc1f vs bc1t at 0xD4, bool materialization through v1 at 0xD8-0xF4. Tried early returns (more diffs), nested if with single exit, split scoped bPrimary/bFlag, return compare (14); ternary return kept (13).
int Tinker::GetNextPosition(float (&pos)[4]) {
    tagWaypointGroup *pGroup = (tagWaypointGroup *)m_unk2A8;
    if (pGroup != 0) {
        if (m_unk2CC < m_unk2C8) {
            unsigned char bPrimary;
            float *pWp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, m_unk2CC, bPrimary);
            pos[0] = pWp[0];
            pos[1] = pWp[1];
            pos[2] = pWp[2];
            m_unk2CC++;
            return 1;
        }
        unsigned char bFlag;
        float *pWp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, m_unk2C8 - 1, bFlag);
        if (bFlag) {
            pos[0] = pWp[0];
            pos[1] = pWp[1];
            pos[2] = pWp[2];
            float (*pTarget)[4];
            if (m_unk3C != 0) {
                pTarget = (float (*)[4])(m_unk3C + 0x80);
            } else {
                pTarget = (float (*)[4])m_unk190;
            }
            return (DistanceXZ__7MathAPIFPA4_fPA4_f(pTarget, &pos) > 1.0f) ? 1 : 0;
        }
    }
    return 0;
}

// DRAFT: 0x00209860 AwardCheck__6TinkerFv
// note: 44 differing lines; original materializes m_unk1B0 == 0 and == 1 as xor/sltiu bools (bnez), ours uses beqz/bne, and s0 is set late in the original. Tried: shared tail (kept), int locals (45), bool locals in both orders (44, kept).
int Tinker::AwardCheck() {
    int r;
    bool bOne = (m_unk1B0 == 1);
    bool bZero = (m_unk1B0 == 0);
    if (bZero || bOne) {
        r = ReadApparitionData__15EntityBaseClassFiUi(this, 2, 0);
    } else if (m_unk200 == 8 || m_unk200 == 7) {
        r = ReadApparitionData__15EntityBaseClassFiUi(this, 1, 0);
    } else {
        r = ReadApparitionData__15EntityBaseClassFiUi(this, 3, 0);
    }
    if (r == 0) {
        return 1;
    }
    return (m_unk2C1 != 0) ^ 1;
}

// FUNCTION: 0x00209930 IsStalled__6TinkerFfPA4_f
int Tinker::IsStalled(float fDist, float (*arg1)[4]) {
    float (*pTarget)[4];
    float d1;
    float d2;
    if (m_unk3C != 0) {
        pTarget = (float (*)[4])(m_unk3C + 0x80);
    } else {
        pTarget = (float (*)[4])m_unk190;
    }
    d1 = DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk250, arg1);
    d2 = DistanceXZ__7MathAPIFPA4_fPA4_f(pTarget, arg1);
    return ((d1 - d2) <= fDist) ? 1 : 0;
}

// FUNCTION: 0x00209C30 FindClosestEnemy__6TinkerFPA4_fQ215EntityBaseClass9LoadClassUi
void *Tinker::FindClosestEnemy(float (*pBox)[4], EntityBaseClass::LoadClass eLoadClass, unsigned int nFlags) {
    EntityBaseClass *pNearestApparition;
    EntityBaseClass *pSecond;
    float fNearest;
    float fSecond;
    unsigned int nHandle;
    EntityBaseClass *pApp;
    float fDist;
    float (*pPos)[4];
    int nIdx;

    if (mTempArray__15EntityBaseClass.m_pData != 0) {
        mTempArray__15EntityBaseClass.m_count = 0;
        mTempArray__15EntityBaseClass.m_unk04 = 0;
    }
    GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, eLoadClass, (PArray *)&mTempArray__15EntityBaseClass, pBox, m_unk1D0[3], nFlags, true, false);
    mTempArray__15EntityBaseClass.m_unk04 = 0;
    fNearest = 99999.0f;
    fSecond = 99999.0f;
    pNearestApparition = 0;
    pSecond = 0;
    nHandle = (mTempArray__15EntityBaseClass.m_count != 0) ? mTempArray__15EntityBaseClass.m_pData[0] : 0;
    while (nHandle != 0) {
        pApp = (EntityBaseClass *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, nHandle);
        if (pApp != 0 && pApp->m_unk163 != 6 && pApp->m_unk3C != 0) {
            pPos = (pApp->m_unk3C != 0) ? (float (*)[4])(pApp->m_unk3C + 0x80) : (float (*)[4])((char *)pApp + 0x190);
            fDist = DistanceXZ__7MathAPIFPA4_fPA4_f(pBox, pPos);
            if (fDist < fNearest) {
                fSecond = fNearest;
                pSecond = pNearestApparition;
                fNearest = fDist;
                pNearestApparition = pApp;
            } else if (fDist < fSecond) {
                fSecond = fDist;
                pSecond = pApp;
            }
        }
        nIdx = mTempArray__15EntityBaseClass.m_unk04 + 1;
        mTempArray__15EntityBaseClass.m_unk04 = nIdx;
        nHandle = ((unsigned int)nIdx < (unsigned int)mTempArray__15EntityBaseClass.m_count) ? mTempArray__15EntityBaseClass.m_pData[mTempArray__15EntityBaseClass.m_unk04] : 0;
    }
    if (pSecond != 0) {
        CDS_ASSERT(0x91B, pNearestApparition);
        if (pNearestApparition->m_unk04 == *(int *)((char *)*(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x1CC) || pNearestApparition->m_unk04 == m_unk2E8) {
            pNearestApparition = pSecond;
        }
    }
    return pNearestApparition;
}

// DRAFT: 0x00209EB0 EnemiesInCheckRadius__6TinkerFv
// note: 19 differing lines; the original stores f12 once and passes it via mov.s in the jal delay slot, ours reloads 0x1DC from memory. Tried bool return, pointer-to-last-element, and a fRadius local; no improvement.
int Tinker::EnemiesInCheckRadius() {
    float box[4];
    float *pLast = &box[3];
    float fRadius;
    box[0] = m_unk1D0[0];
    box[1] = m_unk1D0[1];
    box[2] = m_unk1D0[2];
    fRadius = m_unk1D0[3];
    *pLast = fRadius;
    return GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, 0, &box, fRadius, 0, true, false);
}

// DRAFT: 0x00209F10 ActivateAttackingEnemies__6TinkerFv
// note: 38 differing lines; original keeps entity in s2, valid in s3, offset in s4, i in s1 (0x70 frame); ours assigns s3/s4/s1/s2 differently (0x60 frame). Tried locals in 3 orders and hoisted pEnt/pValid; count stays 38.
void Tinker::ActivateAttackingEnemies() {
    EntityBaseClass **pSlot = m_unk1E0;
    int off = 0;
    int i = 0;
    EntityBaseClass *pEnt;
    ApparitionVirtual *pValid;
    do {
        pEnt = *pSlot;
        if (pEnt != 0) {
            pValid = (ApparitionVirtual *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pValid != 0) {
                if (pValid->Slot17() == 0) {
                    ((unsigned char *)pValid)[0x1A] = 1;
                }
                if (m_unk280 == 0) {
                    pValid->Slot12(m_unk00C);
                }
                *(EntityBaseClass **)((char *)this + off + 0x2AC) = pEnt;
            }
        }
        i++;
        off += 4;
        pSlot++;
    } while (i < 4);
    m_unk2C0 = 1;
}

// DRAFT: 0x00209FF0 ActivatedEnemiesDead__6TinkerFv
// note: 30 differing lines; the m_unk2BC/m_unk2C0 guards are folded into one `&&` (42 nested, 30 folded) and the m_unk2C0==0 path returns 1 as the asm does; still differs at the 0x1C/0x28 branch targets and the loop-init and join layout from 0x2C on. Tried early returns (49), and a `return 0` vs `return 1` on the m_unk2C0 guard (42, unchanged).
int Tinker::ActivatedEnemiesDead() {
    if (m_unk2BC != 0 && m_unk2C0 != 0) {
        int i = 0;
        int off = 0;
        do {
            EntityBaseClass **pSlot = (EntityBaseClass **)((char *)this + off + 0x2AC);
            EntityBaseClass *pEnt = *pSlot;
            if (pEnt != 0) {
                ApparitionVirtual *pValid = (ApparitionVirtual *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
                if (pValid != 0 && pValid->Slot13() > 0) {
                    return 0;
                }
                *pSlot = 0;
            }
            i++;
            off += 4;
        } while (i < 4);
        if (m_unk228 == 0) {
            return 1;
        }
        if (InstanceIsValid__15EntityBaseClassFUi(m_unk228) == 0) {
            return 1;
        }
        return 0;
    }
    return 1;
}

// Layout-compatible view of the Tinker vtable. Two header entries precede the
// first virtual, so the 14th declared slot (index 13) sits at offset 0x3C.
class TinkerVirtual {
public:
    virtual void Slot0();
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
    virtual unsigned char Slot13();
};

// FUNCTION: 0x0020A0F0 SetEditableVars__6TinkerFPc
void Tinker::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x84);
    m_unk1B8 *= 0x32;
    if (mbHard__15EntityBaseClass == 0) {
        int t = m_unk1B8;
        if (t != 0) {
            m_unk1B8 = t + 0x32;
        }
    }
    m_unk288 = m_unk1B8;
    CheckVariable__15EntityBaseClassFii((EntityBaseClass *)this, m_unk1B0, 4);
    CheckVariable__15EntityBaseClassFii((EntityBaseClass *)this, m_unk1B4, 3);
    m_unk2AC[0] = m_unk1E0[0];
    m_unk2AC[1] = m_unk1E0[1];
    m_unk2AC[2] = m_unk1E0[2];
    m_unk2AC[3] = m_unk1E0[3];
    if (m_unk210 < 0) {
        m_unk210 = 0;
    }
    if (m_unk1C0 == 0.0f && m_unk1C4 == 0.0f && m_unk1C8 == 0.0f) {
        CDS_ASSERT(0x82E, !"eif 0, 0, 0 error.  see keith or ted");
        float *p = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
        m_unk240 = p[0];
        p = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
        m_unk244 = p[1];
        p = (m_unk3C != 0) ? (float *)(m_unk3C + 0x80) : m_unk190;
        m_unk248 = p[2];
    }
    m_unk240 = m_unk1C0;
    m_unk244 = m_unk1C4;
    m_unk248 = m_unk1C8;
}

class HudBossVirtual {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
};

// FUNCTION: 0x0020A2A0 OnTimerEvent__6TinkerFUi
void Tinker::OnTimerEvent(unsigned int arg0) {
    if (arg0 == m_unk2EC) {
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        StartCutCamera__6CameraFUib(gEng + 0x19760, m_unk218, false);
        m_unk17A = 0;
    } else if (arg0 == m_unk278) {
        m_unk2F4 = 1;
        m_unk278 = 0;
    } else if (arg0 == m_unk2A4) {
        m_unk2A0 = 1;
    } else if (arg0 == m_unk284) {
        m_unk284 = 0;
    } else if (arg0 == m_unk28C) {
        m_unk28C = 0;
        int nBoss = m_unk1B8;
        if (nBoss != 0) {
            int nState = (m_unk1B0 == 0) ? 2 : 1;
            ((HudBossVirtual *)(gInterface + 0x270))->Slot4();
            SetMaxValue__12HudBossMeterFsi(gInterface + 0x270, (short)nBoss, nState);
        }
    } else if (arg0 == m_unk290) {
        m_unk290 = 0;
        Kill__6PlayerFv(*(void **)((char *)mpEntMgr__15EntityBaseClass + 0x505C));
    } else if (arg0 == m_unk294) {
        m_unk294 = 0;
    }
}

// DRAFT: 0x0020A3E0 OnHitEvent__6TinkerFP15EntityBaseClassiUiUi
// note: 96 words differ; the 0x1FE block is 27 words in the original and 23 here, so the branch offsets and the shared jal/delay-slot placement shift. Tried: flat else-if (99), switch with fall-through (103), 6 tested before 16 (98).
int Tinker::OnHitEvent(EntityBaseClass *pOther, int arg1, unsigned int arg2, unsigned int arg3) {
    if (arg2 == 0x1FE) {
        if (m_unk20 != 10) {
            if (m_unk20 == 16 || m_unk20 == 6) {
                SetState__15EntityBaseClassFi(this, 0xD);
            } else {
                return 5;
            }
        } else {
            SetState__15EntityBaseClassFi(this, 0x14);
        }
        m_unk0E8 = 3;
        return 1;
    }
    int nPrevState = m_unk20;
    if ((*(unsigned int *)((char *)pOther + 0x10C) & 1) != 0) {
        return (*(int *)((char *)pOther + 0x8) == 3) ? 5 : 4;
    }
    if (nPrevState == 3 || nPrevState == 4) {
        return 5;
    }
    if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) != 0) {
        return 5;
    }
    FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(this, pOther);
    CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(this, 0, 3, 0, false);
    m_unk1B8 -= arg1;
    if (m_unk1B8 < 0) {
        m_unk1B8 = 0;
    }
    bool bFlag = (m_unk1B0 == 0 || m_unk1B0 == 1);
    if (bFlag) {
        SetValue__12HudBossMeterFs(gInterface + 0x1980, (short)m_unk1B8);
    }
    if (m_unk1B8 > 0) {
        m_unk29C = nPrevState;
        SetState__15EntityBaseClassFi(this, 3);
    } else {
        SetState__15EntityBaseClassFi(this, 4);
        if (bFlag) {
            *(unsigned char *)(*(char **)((char *)mpEntMgr__15EntityBaseClass + 0x505C) + 0x26D) = 1;
        }
    }
    return 1;
}

// DRAFT: 0x0020A5A0 OnTouchEvent__6TinkerFP15EntityBaseClass
// note: 28 differing lines; the vtable call at 0x3C matches. The original branches each guard with beqz to the shared epilogue (plus a `b` after the 0x5058 check), while MW emits bnez/beqz to a different exit. Tried early-return guards (about 30), a merged || (about 30), a flat && chain (28, kept), and nested ifs (28).
void Tinker::OnTouchEvent(EntityBaseClass *pOther) {
    if (((TinkerVirtual *)this)->Slot13() != 0 && *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) == 0 && m_unk1B4 == 0 && pOther != 0 && (*(unsigned int *)((char *)pOther + 0x10C) & 1) == 0 && m_unk2E4 != *(unsigned int *)((char *)pOther + 0x4) && m_unk20 != 8) {
        SetState__15EntityBaseClassFi(this, 7);
    }
}

// DRAFT: 0x0020A660 OnDestroyEvent__6TinkerFv
// note: 21 differing lines; the original computes both `== 0` and `== 1` as xor/sltiu values and branches on them, MW emits beqz/bne. Tried a local int, unsigned int, and bool first term; none changed the codegen.
void Tinker::OnDestroyEvent() {
    if (m_unk1B0 == 0 || m_unk1B0 == 1) {
        char *pSub = *(char **)(gInterface + 0x274);
        if (pSub != 0) {
            *(int *)(pSub + 0xC) = 0;
        }
    }
    if (m_unk1B0 == 0) {
        WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0);
    }
}

// DRAFT: 0x0020C160 __ct__6TinkerFv
// note: 17 words differ; frame, this spill at 0x1C(sp) and member store order match, but the original runs the EntityBaseClass ctor before the implicit PArray construction and ours does the reverse (base ctor is a body call). Tried: volatile pSelf (55), integer-bit float stores (49), PArray as real member (17).
Tinker::Tinker() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 6, 0);
    *(unsigned char **)this = __vt__6Tinker;
    m_unk2F0 = 0;
    m_unk0D4 = 0;
    m_unk2C4 = -1;
    m_unk2CC = -1;
    m_unk280 = 0;
    m_unk284 = 0;
    m_unk294 = 0;
    m_unk2EC = 0;
    m_unk278 = 0;
    m_unk2A4 = 0;
    m_unk284 = 0;
    m_unk28C = 0;
    m_unk290 = 0;
    m_unk294 = 0;
    m_unk104 = 1.5f;
    m_unk108 = 3.0f;
}
