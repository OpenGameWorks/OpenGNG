#include "EntityManager.h"

// TODO(header): foreign declarations
class PHashTable {
public:
    int Lookup(void *pKey, void *&pValue);
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

void CdsAssert(char *pFile, int nLine, char *pExpr);

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

// FUNCTION: 0x001471D0 Reset__4IconFv
void Icon::Reset() {
    m_unk0 = 0;
    m_unkC = 1;
    m_unk8 = 0;
    m_unkD = 0;
    m_unk10 = 0;
    m_unk14 = 0;
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

// DRAFT: 0x00149160 GetItemCounter__13EntityManagerFQ213EntityManager15ItemCounterType
// note: original keeps this+0x5F74 as a separate addiu (lwc1 0(v0)); ours folds 0x5F74 into lwc1 and is 0x58 bytes vs 0x5C; tried m_unk5F74[i], local float*, (float*)(this+0x5F74)[i], char* index-then-offset, constant-first sum.
float EntityManager::GetItemCounter(ItemCounterType theType) {
    if (theType >= ITEM_COUNTER_MAX) {
        CdsAssert("EntityManager.cpp", 0x18A, "theType < ITEM_COUNTER_MAX");
    }
    return *(float *)((char *)this + 0x5F74 + ((int)theType << 2));
}
