#include "types.h"
#include "PFrozenFx.h"

// TODO(header): foreign declarations
extern "C" void *__dt__15PParticleSystemFv(void *, short);
extern "C" void __dl__FPv(void *);
extern "C" void __dla__FPv(void *);
extern "C" void *memset(void *pDst, int nVal, unsigned int nSize);
extern unsigned char __vt__9PFrozenFx[];

// Child object stored at m_unk1F0. Only the slots this file calls are named;
// slot N is virtual number (N - 8) / 4.
class PFrozenFxChild {
public:
    virtual ~PFrozenFxChild();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5(unsigned int nFlag);
    virtual void Slot6();
};

// View of PFrozenFx's own vtable (stored by hand in the constructor). Slot N
// is virtual number (N - 8) / 4; only the slot 0x24 entry (Stop) is called.
class PFrozenFxView {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Stop();
};

// FUNCTION: 0x001FA210 Stop__9PFrozenFxFv
void PFrozenFx::Stop() {
    m_unk18 = 0;
    void *pChild = m_unk1F0;
    if (pChild != 0) {
        ((PFrozenFxChild *)pChild)->Slot6();
        UpdateFxInstances();
    }
    m_unk1E4 = 0;
}

// FUNCTION: 0x001FA260 Start__9PFrozenFxFv
void PFrozenFx::Start() {
    m_unk15 = 1;
    m_unk18 = 1;
    void *pChild = m_unk1F0;
    if (pChild != 0) {
        ((PFrozenFxChild *)pChild)->Slot6();
        UpdateFxInstances();
    }
    m_unk1E4 = 0;
}

// FUNCTION: 0x001FA2C0 FadeAndDie__9PFrozenFxFUi
void PFrozenFx::FadeAndDie(unsigned int nFlag) {
    ((PFrozenFxView *)this)->Stop();
    if (m_unk1F0 != 0) {
        UpdateFxInstances();
        ((PFrozenFxChild *)m_unk1F0)->Slot5(nFlag);
    }
}

// FUNCTION: 0x001FAAE0 __dt__9PFrozenFxFv
extern "C" void *__dt__9PFrozenFxFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        PFrozenFx *pSelf = (PFrozenFx *)pThis;
        *(void **)pThis = __vt__9PFrozenFx;
        if (pSelf->m_unk1E0 != 0) {
            __dla__FPv(pSelf->m_unk1E0);
            pSelf->m_unk1E0 = 0;
        }
        if (pSelf->m_unk1F4 != 0) {
            __dla__FPv(pSelf->m_unk1F4);
            pSelf->m_unk1F4 = 0;
        }
        if (pSelf->m_unk1F0 != 0) {
            delete (PFrozenFxChild *)pSelf->m_unk1F0;
            pSelf->m_unk1F0 = 0;
        }
        __dt__15PParticleSystemFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x001FABA0 __ct__9PFrozenFxFv
// note: original spills this to 0x1C(sp) and reloads it before each store; ours keeps it in s0 (DIFF 25 words, size 0x48 vs 0x70).
PFrozenFx::PFrozenFx() {
    *(void **)this = __vt__9PFrozenFx;
    m_unk1E0 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1F8 = 0;
    memset(m_unkE0, 0, 0x100);
}
