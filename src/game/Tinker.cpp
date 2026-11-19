#include "types.h"
#include "Tinker.h"

// TODO(header): foreign declarations
class EntityBaseClass;
class EntityManager;
class PArray;
// The second argument is not set by the caller; the original leaves a1 untouched.
extern "C" int InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" void *GetPtrToApparition__13EntityManagerFUi(EntityManager *pThis, unsigned int arg0);
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(EntityManager *pThis, int eLoadClass, PArray *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nState, char cParam, unsigned int uParam);
extern unsigned char gInterface[];

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
