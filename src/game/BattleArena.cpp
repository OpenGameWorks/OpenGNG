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
class PMNode;
struct PMNodeHolder {
    PMNode *ptr;
    char _pad004[0x1E4];
    float m_unk1E8;
};
extern PMNodeHolder gEng;
extern char mPlayerAPI__13EntityManager[0x10];
extern "C" int CheckHammer__6PlayerFb(void *pThis, bool bFlag);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("BattleArena.cpp", line, #cond))

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

// FUNCTION: 0x001C7260 GetClassName__11BattleArenaFv
const char *BattleArena::GetClassName() {
    return "BattleArena";
}

// FUNCTION: 0x001C7270 NeedsToBeWoken__11BattleArenaFv
int BattleArena::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x1DC);
}

// FUNCTION: 0x001C7280 GetWokenVarPos__11BattleArenaFv
int BattleArena::GetWokenVarPos() {
    return 11;
}

// FUNCTION: 0x001C7290 OutputDebug__11BattleArenaFv
void BattleArena::OutputDebug() {
    char buf[0x100];
    if (m_unk20 >= 0) {
        sprintf(buf, "Arena state = %d\n", m_unk20);
        gDebug.DebugDisp(buf);
        sprintf(buf, "Completed delay = %d\n", (double)m_unk3E8);
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

// Wave walk: each node holds an apparition id at +0 and the next node at +4.
struct ArenaWaveNode {
    unsigned int nApparitionId;
    ArenaWaveNode *pNext;
};

// Cursor view at wave element + 0x220: begin list at +0x04, current node at +0x0C.
struct ArenaWaveCursor {
    char _pad0[4];
    ArenaWaveNode *pBegin;
    char _pad8[4];
    ArenaWaveNode *pCur;
};

// FUNCTION: 0x001C7490 SpawnAllEnemiesInCurrentWave__11BattleArenaFv
void BattleArena::SpawnAllEnemiesInCurrentWave() {
    char *pElem;
    ArenaWaveCursor *pCursor;
    ArenaWaveNode *pNode;
    EntityBaseClass *pInst;
    unsigned int nId;

    pElem = (char *)this + m_unk3C0 * 0x2C;
    *(ArenaWaveNode **)(pElem + 0x22C) = *(ArenaWaveNode **)(pElem + 0x224);
    pNode = *(ArenaWaveNode **)(pElem + 0x224);
    nId = (pNode != 0) ? pNode->nApparitionId : 0;
    if (nId != 0) {
        do {
            if ((pInst = (EntityBaseClass *)ApparitionIsValid__15EntityBaseClassFUi(nId)) != 0) {
                pInst->m_unk1A = 1;
                ((EntityVirtualView *)pInst)->SetArenaRadius(*(float *)m_unk1B0);
            }
            pElem = (char *)this + m_unk3C0 * 0x2C;
            pCursor = (ArenaWaveCursor *)(pElem + 0x220);
            if (*(ArenaWaveNode **)(pElem + 0x22C) == 0) {
                pCursor->pCur = pCursor->pBegin;
                pNode = pCursor->pBegin;
                nId = (pNode != 0) ? pNode->nApparitionId : 0;
            } else {
                pNode = (*(ArenaWaveNode **)(pElem + 0x22C))->pNext;
                if (pNode != 0) {
                    pCursor->pCur = pNode;
                    nId = pCursor->pCur->nApparitionId;
                } else {
                    nId = 0;
                }
            }
        } while (nId != 0);
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

// FUNCTION: 0x001C7600 SetEditableVars__11BattleArenaFPc
void BattleArena::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0x34);
    if (m_unk1B4 < 0) {
        CDS_ASSERT(0x25E, !"BattleArena AnimID shouldn't be -1. Designer, Please fix");
    }
}

// DRAFT: 0x001C7660 Execute__11BattleArenaFv
// note: prologue, gEng assert and switch dispatch are in place; cases 1-5, 7-12 and -2 are empty stubs, so the body is far from the 0x10DC original.
void BattleArena::Execute() {
    if (gEng.ptr == 0) {
        CdsAssert__FPciPc("BattleArena.cpp", 0x26, "pRoot");
    }
    switch (m_unk20) {
    case -2:
        break;
    case -1:
        for (int i = 0; i < 10; i++) {
            char *e = (char *)this + 0x204 + i * 0x2C;
            *(int *)(e + 0x00) = 0;
            *(int *)(e + 0x04) = 0;
            *(int *)(e + 0x08) = 0;
            *(int *)(e + 0x0C) = -1;
            *(int *)(e + 0x10) = 0;
            *(int *)(e + 0x14) = 0;
            *(float *)(e + 0x18) = 0.0f;
        }
        m_unk3BC = 0;
        m_unk3C0 = 0;
        m_unk3E8 = 60.0f * m_unk1B8;
        SetState__15EntityBaseClassFi(this, 1);
        return;
    case 0:
        if (m_unk1E0 == 1 && CheckHammer__6PlayerFb(*(void **)mPlayerAPI__13EntityManager, false) == 0) {
            return;
        }
        {
            char *pPl = *(char **)mPlayerAPI__13EntityManager;
            char *pPlA = *(char **)(pPl + 0x3C);
            char *pPlPos = (pPlA != 0) ? pPlA + 0x80 : *(char **)(pPl + 0x190);
            char *pThA = *(char **)((char *)this + 0x3C);
            char *pThPos = (pThA != 0) ? pThA + 0x80 : *(char **)((char *)this + 0x190);
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pThPos, (float (*)[4])pPlPos) <=
                (float)*(int *)((char *)this + 0x3E0)) {
                *(int *)((char *)this + 0x3E0) = 0;
                SetState__15EntityBaseClassFi(this, 6);
                return;
            }
        }
        break;
    case 1:
        SetState__15EntityBaseClassFi(this, 0);
        return;
    case 6: {
        int t = *(int *)((char *)this + 0x3E0);
        if (t > 0) {
            *(int *)((char *)this + 0x3E0) = (int)((float)t - gEng.m_unk1E8);
            return;
        }
        SetState__15EntityBaseClassFi(this, 2);
        return;
    }
    default:
        return;
    }
}

// DRAFT: 0x001C8740 __ct__11BattleArenaFv
// note: DIFF 32; base ctor call is a mem-initializer, but the real PArray members are constructed before the body, so the original's base-ctor order (0x14, before any PArray ctor) differs; explicit PArray ctor calls after the vptr store gave DIFF 46 (size 0xC0 vs 0xCC).
BattleArena::BattleArena() : EntityBaseClass((LoadClass)5, 0U) {
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
