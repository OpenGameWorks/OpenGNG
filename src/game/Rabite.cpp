#include "types.h"
#include "Rabite.h"

// TODO(header): foreign declarations
// Only the calls made by Rabite functions are declared; EntityBaseClass is partial here.
class EntityBaseClass { public: char _pad000[0x4]; };
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSequence);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern unsigned char __vt__6Rabite[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void DetachJoint__6PlayerFi(void *pThis, int nJoint);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
// Only the m_unk505C slot of EntityManager is used here.
class EntityManager { public: char _pad000[0x505C]; void *m_unk505C; };
extern EntityManager *mpEntMgr__15EntityBaseClass;
// Mesh table sizes are unknown; the placeholders keep these globals out of small data (threshold 8 bytes).
extern unsigned int Rabite_Mesh[4];
extern unsigned int Rabite_Mean_Mesh[4];

// FUNCTION: 0x001FB980 LoadCorrectMesh__6RabiteFv
void Rabite::LoadCorrectMesh() {
    if (m_unk218 != 0) {
        PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Mesh);
        return;
    }
    PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mesh);
}

// FUNCTION: 0x001FBD90 OnWakeEvent__6RabiteFv
void Rabite::OnWakeEvent() {
    if (m_unk20 == 8) {
        SetState__15EntityBaseClassFi(this, 0xE);
    }
}

// DRAFT: 0x001FBE70 OnHitEvent__6RabiteFP15EntityBaseClassiUiUi
// note: DIFF 31; byte in v0 instead of v1, and the original re-tests m_unk218 at 0x2C. Tried: nested alt-first order (35), byte local with alt-first (32), and locals inside the if (33).
int Rabite::OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB) {
    int nState = m_unk20;
    unsigned char bAlt = m_unk218;
    if (m_unk21C == -1) {
        if (bAlt == 0) {
            if (nState == 6 || nState == 5) {
                return 5;
            }
        } else {
            if (nState == 7) {
                return 5;
            }
            m_unk1E0 -= nDamage;
        }
        if (m_unk1E0 > 0) {
            SetState__15EntityBaseClassFi(this, 5);
            return 1;
        }
        SetState__15EntityBaseClassFi(this, 0xA);
        return 2;
    }
    return 0;
}

// FUNCTION: 0x001FCD10 __dt__6RabiteFv
extern "C" void *__dt__6RabiteFv(Rabite *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__6Rabite;
        if (pThis->m_unk21C != -1) {
            void *pPlayer = mpEntMgr__15EntityBaseClass->m_unk505C;
            if (pPlayer != 0) {
                DetachJoint__6PlayerFi(pPlayer, pThis->m_unk21C);
                pThis->m_unk21C = -1;
            }
        }
        pThis->m_unk240 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001FCDB0 __ct__6RabiteFv
Rabite::Rabite() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 5);
    m_unk0 = __vt__6Rabite;
    m_unk21C = -1;
    m_unkF8 = 0.3f;
    m_unkFC = 0.6f;
    m_unk103 = 0x10;
    m_unk15C = 0;
    m_unk15E = 0x100C;
    m_unkEA = 0;
    m_unk104 = 0.5f;
    m_unk108 = 1.0f;
}
