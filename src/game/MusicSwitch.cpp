// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "MusicSwitch.h"
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);
extern char *mpEntMgr__15EntityBaseClass;
extern "C" void sceVu0CopyVector(float *pDst, float *pSrc);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void MusicSwitchToPrimary__15EntityBaseClassFUi(void *pThis, unsigned int nArg0);
extern "C" void MusicSwitchToSecondary__15EntityBaseClassFUiUiUiUi(void *pThis, unsigned int nArg0, unsigned int nArg1, unsigned int nArg2, unsigned int nArg3);

// FUNCTION: 0x001C6E30 __dt__11MusicSwitchFv
MusicSwitch::~MusicSwitch() {
}

// FUNCTION: 0x001C6E90 GetClassName__11MusicSwitchFv
const char *MusicSwitch::GetClassName() {
    return "MusicSwitch";
}

// FUNCTION: 0x001C6EA0 OnHitEvent__11MusicSwitchFP15EntityBaseClassiUiUi
void MusicSwitch::OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int) {
}

// FUNCTION: 0x001C6EB0 SetEditableVars__11MusicSwitchFPc
void MusicSwitch::SetEditableVars(char *pSrc) {
    memcpy((char *)this + 0x1B0, pSrc, 0x20);
}

// DRAFT: 0x001C6EC0 Execute__11MusicSwitchFv
// note: 141 words differ. Vector copy order, dispatch block layout (orig tests 2,1,0,-1 first) and case -1 range check still differ. Tried: pSrc float* local (no change), load-then-store copy (142->141), switch order 2,1,0,-1 (154), SetState tail move (154->142).
void MusicSwitch::Execute() {
    float vDiff[4];
    float vRef[4];
    float vDst[4];
    char *pPlayer = *(char **)(mpEntMgr__15EntityBaseClass + 0x505C);
    char *pSrc = *(char **)(pPlayer + 0x3C);
    if (pSrc != 0) {
        pSrc = pSrc + 0x80;
    } else {
        pSrc = pPlayer + 0x190;
    }
    float f0 = ((float *)pSrc)[0];
    float f1 = ((float *)pSrc)[1];
    float f2 = ((float *)pSrc)[2];
    float f3 = ((float *)pSrc)[3];
    vRef[3] = f3;
    vRef[2] = f2;
    vRef[1] = f1;
    vRef[0] = f0;

    switch (m_unk20) {
    case -1: {
        if (m_unk1C0 < 3 || m_unk1C0 >= 0x21) {
            CdsAssert("MusicSwitch.cpp", 0x1E, "0");
            m_unk1C0 = 3;
        }
        char *pBase = (m_unk3C != 0) ? (m_unk3C + 0x80) : ((char *)this + 0x190);
        vDst[0] = ((float *)pBase)[0];
        vDst[1] = ((float *)pBase)[1];
        vDst[2] = ((float *)pBase)[2];
        vDst[3] = 1.0f;
        sceVu0CopyVector(&m_unk1D0, vDst);
        m_unk1E0 = m_unk1B0 * m_unk1B0;
        sceVu0CopyVector(&m_unk1F0, &m_unk1D0);
        m_unk200 = m_unk1B4 * m_unk1B4;
        m_unk204 = 0;
        SetState(0);
        return;
    }
    case 0: {
        unsigned int nOld = m_unk204;
        m_unk204 = nOld + 1;
        if (nOld >= 4) {
            SetState(1);
        }
        return;
    }
    case 1: {
        sceVu0SubVector(vDiff, &m_unk1D0, vRef);
        float d = sceVu0InnerProduct(vDiff, vDiff);
        if (d < m_unk1E0) {
            if (m_unk1C4 != 0) {
                MusicSwitchToPrimary__15EntityBaseClassFUi(this, m_unk1B8);
            } else if (m_unk1C8 != 0) {
                MusicChangePrimary(m_unk1C0, m_unk1B8);
            } else {
                MusicSwitchToSecondary__15EntityBaseClassFUiUiUiUi(this, m_unk1C0, m_unk1B8, m_unk1BC, 0);
            }
            if (m_unk1CC != 0) { SetState(-2); } else { SetState(2); }
        }
        return;
    }
    case 2: {
        sceVu0SubVector(vDiff, &m_unk1F0, vRef);
        float d = sceVu0InnerProduct(vDiff, vDiff);
        if (d > m_unk200) {
            SetState(1);
        }
        return;
    }
    }
}

// FUNCTION: 0x001C7120 __ct__11MusicSwitchFv
MusicSwitch::MusicSwitch() : EntityBaseClass((LoadClass)5, 0) {
}
