#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "types.h"

class EntityManager {
public:
    enum ItemCounterType {
        ITEM_COUNTER_MAX = 2
    };

    void ProcessApparitions();
    void *GetPtrToInstance(unsigned int arg0);
    void *GetPtrToApparition(unsigned int arg0);
    float GetItemCounter(ItemCounterType theType);
    void PutApparitionsToSleep();
    void WakeUpApparitions();
    void ExecuteApparitions();

    char _pad000[0x5088];
    char m_unk5088[0xC];        // 0x5088 PHashTable, looked up by GetPtrToApparition
    char m_unk5094[0x5D48 - 0x5094];    // 0x5094 PHashTable, looked up by GetPtrToInstance
    int m_unk5D48;              // 0x5D48 countdown, decremented by ProcessApparitions
    char _pad5D4C[0x5F74 - 0x5D4C];
    float m_unk5F74[2];         // 0x5F74 indexed by ItemCounterType
};

#endif
