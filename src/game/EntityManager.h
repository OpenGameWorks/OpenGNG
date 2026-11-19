#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "types.h"

class EntityManager {
public:
    enum ItemCounterType {
        ITEM_COUNTER_MAX = 2
    };

    struct DependencyEntry {
        int m_unk00;            // 0x00 flag index (times 4, from 0x53A1)
        int m_unk04;            // 0x04 flag index (times 4, from 0x53A1), bound by m_unk5054
    };

    void ProcessApparitions();
    void *GetPtrToInstance(unsigned int arg0);
    void *GetPtrToApparition(unsigned int arg0);
    float GetItemCounter(ItemCounterType theType);
    void PutApparitionsToSleep();
    void WakeUpApparitions();
    void ExecuteApparitions();
    void ValidateDependencyList();
    void Add2DependencyList(unsigned int arg0, unsigned int arg1);
    void SetItemCounter(ItemCounterType theType, float value);
    void CallOnTimerEvent(unsigned int arg0, unsigned int arg1);

    static void *mCameraAPI;    // MathAPI instance read by EntityBaseClass::CameraLookingAtMe

    char _pad000[0x5054];
    unsigned int m_unk5054;     // 0x5054 bound for dependency flag indices
    char _pad5058[0x5088 - 0x5058];
    char m_unk5088[0xC];        // 0x5088 PHashTable, looked up by GetPtrToApparition
    char m_unk5094[0x519C - 0x5094];    // 0x5094 PHashTable, looked up by GetPtrToInstance
    int m_unk519C;              // 0x519C dependency count (max 0x40)
    DependencyEntry m_unk51A0[0x40];    // 0x51A0 dependency list
    char _pad53A0[0x53A1 - 0x53A0];
    char m_unk53A1[0x5D48 - 0x53A1];    // 0x53A1 per-entry flag bytes, indexed by value*4
    int m_unk5D48;              // 0x5D48 countdown, decremented by ProcessApparitions
    char _pad5D4C[0x5F74 - 0x5D4C];
    float m_unk5F74[2];         // 0x5F74 indexed by ItemCounterType
};

#endif
