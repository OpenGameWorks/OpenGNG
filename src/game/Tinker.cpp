#include "types.h"
#include "Tinker.h"

// TODO(header): foreign declarations
class EntityBaseClass;
class EntityManager;
class PArray;
class MathAPI;
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
// The second argument is not set by the caller; the original leaves a1 untouched.
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" void *GetPtrToApparition__13EntityManagerFUi(EntityManager *pThis, unsigned int arg0);
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(EntityManager *pThis, int eLoadClass, PArray *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nState, char cParam, unsigned int uParam);
extern unsigned char gInterface[];
extern unsigned char __vt__6Tinker[0x10];
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char Tinker_AttackSeq[0x10];
extern unsigned char Tinker_Attack2Seq[0x10];
extern unsigned char Manda_AttackSeq[0x10];
extern "C" void PlaySoundOnFrame__15EntityBaseClassFUiUi(void *pThis, unsigned int nSound, unsigned int nFrame);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);

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

// DRAFT: 0x00209440 SetAsActivatedEnemyTarget__6TinkerFv
// note: 5 differing lines; MW emits a `b` to the loop test before the body (the original falls into the body) and fills the join nop after the Slot12 call with off+=4. Tried merged null check (21 words), do-while (11 words), and increment order (5 words, kept).
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
    unsigned int n = m_unk2D0;
    unsigned int i;
    int v;
    i = 0;
    off = 0;
    for (; i < n; i++) {
        v = 0;
        if (i < n) {
            v = *(int *)((char *)m_unk2D8 + off);
        }
        if (v == (int)arg0) {
            return 1;
        }
        off += 4;
    }
    return 0;
}

// FUNCTION: 0x00209930 IsStalled__6TinkerFfPA4_f
int Tinker::IsStalled(float fDist, float (*arg1)[4]) {
    MathAPI *pTarget;
    float d1;
    float d2;
    if (m_unk3C != 0) {
        pTarget = (MathAPI *)(m_unk3C + 0x80);
    } else {
        pTarget = (MathAPI *)m_unk190;
    }
    d1 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk250, arg1);
    d2 = DistanceXZ__7MathAPIFPA4_fPA4_f(pTarget, arg1);
    return ((d1 - d2) <= fDist) ? 1 : 0;
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
