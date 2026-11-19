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

    struct TallyEntry {
        int m_unk00;            // 0x00 counter, stride 8
        int m_unk04;            // 0x04 unused by tally
    };

    struct TriggerEntry {
        unsigned short m_unk00; // 0x00 key matched when arg1 < 0
        char _pad02[4];
        short m_unk06;          // 0x06 key matched when arg1 >= 0
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
    void *CalculateTallyData();
    void *FindTrigger(unsigned int arg0, int arg1);
    void LoadApparitionData(int arg0);
    void Destroy(unsigned int arg0, unsigned int arg1);
    void LoadOverlay(char *arg0, char *arg1);
    void Reset(bool arg0);
    void LoadResource(char *arg0, bool arg1);
    void RemoveFromRenderList(struct EntityBaseClass *arg0);

    static void *mCameraAPI;    // MathAPI instance read by EntityBaseClass::CameraLookingAtMe

    char _pad000[0x5054];
    unsigned int m_unk5054;     // 0x5054 bound for dependency flag indices
    char _pad5058[0x5078 - 0x5058];
    char m_unk5078[0x10];       // 0x5078 PArray, entries removed by Destroy
    char m_unk5088[0xC];        // 0x5088 PHashTable, looked up by GetPtrToApparition
    char m_unk5094[0x50C0 - 0x5094];    // 0x5094 PHashTable, looked up by GetPtrToInstance
    void *m_unk50C0;            // 0x50C0 OverlayManager *, used by LoadOverlay
    char _pad50C4[0x519C - 0x50C4];
    int m_unk519C;              // 0x519C dependency count (max 0x40)
    DependencyEntry m_unk51A0[0x40];    // 0x51A0 dependency list
    char _pad53A0[0x53A1 - 0x53A0];
    char m_unk53A1[0x5B24 - 0x53A1];    // 0x53A1 per-entry flag bytes, indexed by value*4
    TallyEntry m_unk5B24[5];    // 0x5B24 tally counters, indexed by type (0..4)
    char _pad5B4C[0x5B60 - 0x5B4C];
    int m_unk5B60;              // 0x5B60 trigger count
    int m_unk5B64;              // 0x5B64 trigger scan index
    void **m_unk5B68;           // 0x5B68 trigger list, TriggerEntry pointers
    char _pad5B6C[0x5D48 - 0x5B6C];
    int m_unk5D48;              // 0x5D48 countdown, decremented by ProcessApparitions
    int m_unk5D4C;              // 0x5D4C cleared by LoadOverlay
    char _pad5D50[0x5F74 - 0x5D50];
    float m_unk5F74[2];         // 0x5F74 indexed by ItemCounterType
};

#endif
