#include "Raven.h"
#include "types.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    char _pad000[8];
};

class Debug {
public:
    void DebugDisp(char *pText);

    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
};
extern Debug gDebug;

class PMNode;
extern "C" float GetFrameTime__6PMNodeFv(PMNode *);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *, int, unsigned int);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *, bool, bool);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__5Raven[0x80];

extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" long long fptodp(float arg0);

// FUNCTION: 0x001B25E0 __dt__5RavenFv
extern "C" void *__dt__5RavenFv(Raven *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__5Raven;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001B2770 OutputDebug__5RavenFv
void Raven::OutputDebug() {
    char buf[0x100];
    PMNode *node = m_unk3C;
    if (node != 0) {
        sprintf(buf, "Anim Frame = %f\n", fptodp(GetFrameTime__6PMNodeFv(node)));
        gDebug.DebugDisp(buf);
    }
}

// FUNCTION: 0x001B2C70 OnTimerEvent__5RavenFUi
void Raven::OnTimerEvent(unsigned int nId) {
    if (nId == (unsigned int)m_unk1C8) {
        m_unk1C5 = 1;
        return;
    }
    if (nId == (unsigned int)m_unk258) {
        m_unk1C6 = 1;
        return;
    }
    if (nId == (unsigned int)m_unk25C) {
        m_unk1C7 = 1;
    }
}

// FUNCTION: 0x001B2CB0 OnHitEvent__5RavenFP15EntityBaseClassiUiUi
int Raven::OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB) {
    m_unk244 -= nDamage;
    if (m_unk244 <= 0) {
        m_unk10C &= 0xF8FFFFFF;
        EnableSleep__15EntityBaseClassFbb(this, 0, 0);
        SetState__15EntityBaseClassFi(this, 0xC);
        return 2;
    }
    SetState__15EntityBaseClassFi(this, 0xA);
    return 1;
}

// FUNCTION: 0x001B3F20 __ct__5RavenFv
Raven::Raven() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 2U);
    m_unk0 = __vt__5Raven;
    m_unk250 = 0;
    m_unk1C0 = 0;
    m_unkEB = 0;
}
