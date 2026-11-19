#include "EntityManager.h"

// TODO(header): foreign declarations
class PHashTable {
public:
    int Lookup(void *pKey, void *&pValue);
    void *Remove(void *pKey);
};

class PArray {
public:
    void Remove(void *pItem);
};

class OverlayManager {
public:
    int LoadOverlay(const char *pName);
};

class Icon {
public:
    void Reset();

    int m_unk0;                 // 0x00
    char _pad004[0x8 - 0x4];
    int m_unk8;                 // 0x08
    signed char m_unkC;         // 0x0C
    signed char m_unkD;         // 0x0D
    char _pad00E[0x10 - 0x0E];
    int m_unk10;                // 0x10
    int m_unk14;                // 0x14
};

class PVirtObj {
public:
    virtual void Slot02(unsigned int arg0);
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09(unsigned int arg0);
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
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
};

void CdsAssert(char *pFile, int nLine, char *pExpr);

class MathAPI {
public:
    float GetRelAngleYToPoint(float (*arg0)[4], float arg1, float (*arg2)[4]);

    char _pad000[0x20];
    float m_unk20[4];           // 0x20, element 1 at 0x24
};

float FastMath_Fabs(float f);

extern unsigned char gMC[0x1000];

class EntityBaseClass {
public:
    bool CameraLookingAtMe();

    char _pad000[0x3C];
    char *m_unk3C;              // 0x3C
    char _pad040[0x190 - 0x40];
    float m_unk190[4];          // 0x190
};

// FUNCTION: 0x00146F50 ProcessApparitions__13EntityManagerFv
void EntityManager::ProcessApparitions() {
    int n = m_unk5D48;
    if (n != 0) {
        m_unk5D48 = n - 1;
    }
    PutApparitionsToSleep();
    WakeUpApparitions();
    ExecuteApparitions();
}

// DRAFT: 0x00146FA0 CalculateTallyData__13EntityManagerFv
// note: 17 lines differ; constants preload order and the join placement differ (ours inlines off+=4 before the body); tried ||-chain signed char (32 words), !=/else (26), int t (32), offset-first decl (26), switch 4..1 (21), switch 1..4 with ascending cases (17, kept).
void *EntityManager::CalculateTallyData() {
    m_unk5B24[0].m_unk00 = 0;
    m_unk5B24[1].m_unk00 = 0;
    m_unk5B24[2].m_unk00 = 0;
    m_unk5B24[3].m_unk00 = 0;
    m_unk5B24[4].m_unk00 = 0;
    unsigned int i = 0;
    int off = 0;
    for (; i < m_unk5054; i++) {
        signed char t = *(signed char *)((char *)this + 0x53A0 + off);
        switch (t) {
        case 1:
        case 2:
        case 3:
        case 4:
            m_unk5B24[t].m_unk00 = m_unk5B24[t].m_unk00 + 1;
            break;
        }
        off += 4;
    }
    return m_unk5B24;
}

// FUNCTION: 0x001471D0 Reset__4IconFv
void Icon::Reset() {
    m_unk0 = 0;
    m_unkC = 1;
    m_unk8 = 0;
    m_unkD = 0;
    m_unk10 = 0;
    m_unk14 = 0;
}

// DRAFT: 0x001471F0 FindTrigger__13EntityManagerFUii
// note: 8 lines; the else-arm p=0 leaves a b over the else at 0x14/0x1C (original falls through into the while test) and the increment uses a3 for the new index (original uses v1). Tried truthiness test (32), if-sense reversed (11), index reload (11), local idx without else (32), local idx with else (8, kept).
void *EntityManager::FindTrigger(unsigned int arg0, int arg1) {
    m_unk5B64 = 0;
    TriggerEntry *p = 0;
    if (m_unk5B60 != 0) {
        p = (TriggerEntry *)m_unk5B68[0];
    } else {
        p = 0;
    }
    while (p != 0) {
        if (arg1 >= 0) {
            if (arg1 == p->m_unk06) {
                return p;
            }
        } else {
            if (arg0 == p->m_unk00) {
                return p;
            }
        }
        int idx = m_unk5B64 + 1;
        m_unk5B64 = idx;
        p = 0;
        if (idx < (unsigned int)m_unk5B60) {
            p = (TriggerEntry *)m_unk5B68[m_unk5B64];
        }
    }
    return 0;
}

// DRAFT: 0x00147760 ValidateDependencyList__13EntityManagerFv
// note: 7 lines; loop counter and byte offset swap registers (original keeps offset in a3 and counter in a1, ours offset a1 and counter a2); tried scoped counter (9 lines), unsigned offset (9 lines), counter-first ordering (7 lines, kept).
void EntityManager::ValidateDependencyList() {
    int i = 0;
    int off = 0;
    for (; i < m_unk519C; i++) {
        DependencyEntry *p = (DependencyEntry *)((char *)this + off);
        unsigned int v = p->m_unk04;
        if (v < m_unk5054 && (signed char)m_unk53A1[v * 4] >= 0) {
            m_unk53A1[p->m_unk00 * 4] = 0;
        }
        off += 8;
    }
    m_unk519C = 0;
}

// FUNCTION: 0x001477C0 Add2DependencyList__13EntityManagerFUiUi
void EntityManager::Add2DependencyList(unsigned int arg0, unsigned int arg1) {
    if (m_unk519C >= 0x40) {
        CdsAssert("EntityManager.cpp", 0x4ED, "miDependencySize < MAX_DEPENDENCY");
    }
    int n = m_unk519C;
    m_unk519C = n + 1;
    DependencyEntry *e = &m_unk51A0[n];
    e->m_unk00 = arg0;
    e->m_unk04 = arg1;
}

// DRAFT: 0x00147B40 LoadApparitionData__13EntityManagerFi
// note: 22 lines differ; branch offset 0x1D vs 0x1C, p=0 in t1 (orig v1), addiu 0x2B1 placement, b/mask/i/off/q registers (orig a2/a3/t0/t1/t2), loop tail order. Tried gMC[idx+0x2B1] (27), two-pointer q (22), single pointer p (22), counters before byte load (23).
void EntityManager::LoadApparitionData(int arg0) {
    if (arg0 < 0x15) {
        unsigned char *p = 0;
        if (arg0 < 0x15) {
            p = &gMC[arg0 * 0x31];
            p = p + 0x2B1;
        }
        unsigned char b = *p;
        p = p + 1;
        unsigned int mask = 0x80;
        int i = 0;
        int off = 0;
        do {
            int bit = (unsigned char)b & mask;
            mask = mask >> 1;
            *(signed char *)((char *)this + 0x53A0 + off) = bit;
            if (mask == 0) {
                b = *p;
                mask = 0x80;
                p = p + 1;
            }
            i = i + 1;
            off = off + 4;
        } while (i < 0x180);
    }
}

// FUNCTION: 0x00148960 GetPtrToInstance__13EntityManagerFUi
void *EntityManager::GetPtrToInstance(unsigned int arg0) {
    void *pValue;
    if (((PHashTable *)m_unk5094)->Lookup((void *)arg0, pValue) != 0) {
        return pValue;
    }
    return 0;
}

// FUNCTION: 0x001489A0 GetPtrToApparition__13EntityManagerFUi
void *EntityManager::GetPtrToApparition(unsigned int arg0) {
    void *pValue;
    if (((PHashTable *)m_unk5088)->Lookup((void *)arg0, pValue) != 0) {
        return pValue;
    }
    return 0;
}

// DRAFT: 0x001490F0 SetItemCounter__13EntityManagerFQ213EntityManager15ItemCounterTypef
// note: 10 lines; original keeps this+0x5F74 as a separate addiu after sll, ours folds 0x5F74 into swc1 displacement; tried m_unk5F74[i] (9 lines), local float* base (9), offset-then-add (9), deferred pointer (9); final form 10.
void EntityManager::SetItemCounter(ItemCounterType theType, float value) {
    if (theType >= ITEM_COUNTER_MAX) {
        CdsAssert("EntityManager.cpp", 0x192, "theType < ITEM_COUNTER_MAX");
    }
    m_unk5F74[theType] = value;
}

// DRAFT: 0x00149160 GetItemCounter__13EntityManagerFQ213EntityManager15ItemCounterType
// note: original keeps this+0x5F74 as a separate addiu (lwc1 0(v0)); ours folds 0x5F74 into lwc1 and is 0x58 bytes vs 0x5C; tried m_unk5F74[i], local float*, (float*)(this+0x5F74)[i], char* index-then-offset, constant-first sum.
float EntityManager::GetItemCounter(ItemCounterType theType) {
    if (theType >= ITEM_COUNTER_MAX) {
        CdsAssert("EntityManager.cpp", 0x18A, "theType < ITEM_COUNTER_MAX");
    }
    return *(float *)((char *)this + 0x5F74 + ((int)theType << 2));
}

// DRAFT: 0x001491C0 CallOnTimerEvent__13EntityManagerFUiUi
// note: 16 lines, all in the failure branch; the Slot09 call and Lookup match under the current PVirtObj layout. Original tests the string address at runtime (lui/addiu/sltu/xori/bnez over the CdsAssert call, frame 0x30) and ours folds !"..." away; tried local char* pMsg (0x40 frame, worse), early return (more lines), if(!(!"...")) else arm (16 lines, kept).
void EntityManager::CallOnTimerEvent(unsigned int arg0, unsigned int arg1) {
    void *pValue;
    if (((PHashTable *)m_unk5088)->Lookup((void *)arg0, pValue) != 0) {
        ((PVirtObj *)pValue)->Slot09(arg1);
    } else {
        if (!(!"Invalid Apparition Accessed")) {
            CdsAssert("EntityManager.cpp", 0x184, "!\"Invalid Apparition Accessed\"");
        }
    }
}

// FUNCTION: 0x00149500 Destroy__13EntityManagerFUiUi
void EntityManager::Destroy(unsigned int arg0, unsigned int arg1) {
    if (arg1 != 0) {
        ((PHashTable *)m_unk5094)->Remove((void *)arg1);
    }
    PVirtObj *pObj = (PVirtObj *)((PHashTable *)m_unk5088)->Remove((void *)arg0);
    if (pObj != 0) {
        pObj->Slot25();
        ((PArray *)m_unk5078)->Remove(pObj);
        RemoveFromRenderList((EntityBaseClass *)pObj);
        if (pObj != 0) {
            pObj->Slot02(1);
        }
    }
}

// DRAFT: 0x00149B10 LoadOverlay__13EntityManagerFPcPc
// note: 21 words differ; the original tests the failure-message string address at runtime (lui/addiu/sltu/xori/bnez, skip over the CdsAssert call) and ours folds the test away; the 0x13-word beqz skip differs from 0x15. Tried !(!"...") (23), local char* pMsg with pMsg != 0 (21), !(!pMsg) (21, kept as pMsg != 0 form).
void EntityManager::LoadOverlay(char *arg0, char *arg1) {
    m_unk5D4C = 0;
    Reset(true);
    if (arg0 != 0) {
        if (((OverlayManager *)m_unk50C0)->LoadOverlay(arg0) == 0) {
            char *pMsg = "Load Overlay failed";
            if (pMsg != 0) {
                CdsAssert("EntityManager.cpp", 0x8A, "!\"Load Overlay failed\"");
            }
        }
        LoadResource(arg1, false);
    }
}

// DRAFT: 0x0014A220 CameraLookingAtMe__15EntityBaseClassFv
// note: 2 words; lui scratch is v1 (original v0). Tried reversed compare (4), if-return (3), direct m_unk20[1] (23); kept pf local + fabs local (2).
bool EntityBaseClass::CameraLookingAtMe() {
    MathAPI *pCam = (MathAPI *)EntityManager::mCameraAPI;
    float *pf = pCam->m_unk20;
    float (*p)[4] = m_unk3C != 0 ? (float (*)[4])(m_unk3C + 0x80) : &m_unk190;
    float a = FastMath_Fabs(pCam->GetRelAngleYToPoint(p, pf[1], (float (*)[4])pCam));
    return a <= 35.0f;
}
