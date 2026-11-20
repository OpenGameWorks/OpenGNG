// FLAGS: -str readonly
#include "types.h"
#include "BattleArena.h"
#include "Debug.h"

// TODO(header): foreign declarations
extern Debug gDebug;
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" int fptodp(float f);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void *InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nApparitionId);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nSize);
extern "C" void __ct__18WAVE_TABLE_ELEMENTFv(void *pThis);
extern "C" void __dt__18WAVE_TABLE_ELEMENTFv(void *pThis, short nFlags);
extern "C" void __construct_array(void *pArray, void (*pCtor)(void *), void (*pDtor)(void *, short), unsigned int nElemSize, unsigned int nCount);
extern "C" void __ct__5PListFv(void *pThis);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bFlagA, bool bFlagB);
extern unsigned char __vt__11BattleArena[0x40];

// Virtual layout of EntityBaseClass as the vtable exposes it: slot N is virtual (N - 8) / 4.
// Slot 0x08 is the destructor (virtual 0); slot 0x44 is IsArenaApparition (virtual 15).
class EntityVirtualView {
public:
    virtual ~EntityVirtualView();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual int IsArenaApparition();
    virtual void v16();
    virtual void v17();
    virtual void SetArenaRadius(float fRadius);
};

// FUNCTION: 0x001C7290 OutputDebug__11BattleArenaFv
void BattleArena::OutputDebug() {
    char buf[0x100];
    if (m_unk20 >= 0) {
        sprintf(buf, "Arena state = %d\n", m_unk20);
        gDebug.DebugDisp(buf);
        sprintf(buf, "Completed delay = %d\n", fptodp(m_unk3E8));
        gDebug.DebugDisp(buf);
        if (m_unk3C8 != 0) {
            sprintf(buf, "All Enemies dead = true\n");
        } else {
            sprintf(buf, "All Enemies dead = false\n");
        }
        gDebug.DebugDisp(buf);
        sprintf(buf, "Current wave = %d\n", m_unk3C0);
        gDebug.DebugDisp(buf);
    }
}

// FUNCTION: 0x001C7370 ActivateInstances__11BattleArenaFv
void BattleArena::ActivateInstances() {
    EntityBaseClass *pInst;
    if (m_unk1CC[0] != 0) {
        pInst = (EntityBaseClass *)InstanceIsValid__15EntityBaseClassFUi(m_unk1CC[0]);
        if (pInst != 0 && ((EntityVirtualView *)pInst)->IsArenaApparition() == 0) {
            pInst->m_unk1A = 1;
        }
    }
    if (m_unk1CC[1] != 0) {
        pInst = (EntityBaseClass *)InstanceIsValid__15EntityBaseClassFUi(m_unk1CC[1]);
        if (pInst != 0 && ((EntityVirtualView *)pInst)->IsArenaApparition() == 0) {
            pInst->m_unk1A = 1;
        }
    }
    if (m_unk1CC[2] != 0) {
        pInst = (EntityBaseClass *)InstanceIsValid__15EntityBaseClassFUi(m_unk1CC[2]);
        if (pInst != 0 && ((EntityVirtualView *)pInst)->IsArenaApparition() == 0) {
            pInst->m_unk1A = 1;
        }
    }
    if (m_unk1CC[3] != 0) {
        pInst = (EntityBaseClass *)InstanceIsValid__15EntityBaseClassFUi(m_unk1CC[3]);
        if (pInst != 0 && ((EntityVirtualView *)pInst)->IsArenaApparition() == 0) {
            pInst->m_unk1A = 1;
        }
    }
}

// FUNCTION: 0x001C75B0 SpawnEnemyFromCurrentWave__11BattleArenaFUi
void BattleArena::SpawnEnemyFromCurrentWave(unsigned int nApparitionId) {
    void *pInst;
    if ((pInst = ApparitionIsValid__15EntityBaseClassFUi(nApparitionId)) != 0) {
        ((EntityBaseClass *)pInst)->m_unk1A = 1;
        ((EntityVirtualView *)pInst)->SetArenaRadius(*(float *)m_unk1B0);
    }
}

// DRAFT: 0x001C7600 SetEditableVars__11BattleArenaFPc
// note: layout matches; the assert test !"..." folds to a constant, original keeps a runtime sltu/xori/bnez on the literal address (tried !"..." and !(bool)"...").
void BattleArena::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0x34);
    if (m_unk1B4 < 0) {
        if (!(!"BattleArena AnimID shouldn't be -1. Designer, Please fix")) {
            CdsAssert__FPciPc("BattleArena.cpp", 0x25E, "!\"BattleArena AnimID shouldn't be -1. Designer, Please fix\"");
        }
    }
}

// DRAFT: 0x001C8740 __ct__11BattleArenaFv
// note: DIFF 23; real PArray members are constructed before the body, so the original's base ctor call (0x14, before any PArray ctor) is out of order; explicit PArray ctor calls after the vptr store gave DIFF 46 (size 0xC0 vs 0xCC).
BattleArena::BattleArena() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 0U);
    *(void **)this = __vt__11BattleArena;
    __construct_array(m_unk204, __ct__18WAVE_TABLE_ELEMENTFv, __dt__18WAVE_TABLE_ELEMENTFv, 0x2C, 0xA);
    __ct__5PListFv(m_unk3D0);
    EnableSleep__15EntityBaseClassFbb(this, false, false);
    Allocate__6PArrayFUi((char *)this + 0x1E4, 0xA);
    Allocate__6PArrayFUi((char *)this + 0x1F4, 0x64);
    m_unk3F4 = 0;
    m_unk3F5 = 0;
    m_unk3EC = 0;
}
