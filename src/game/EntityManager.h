#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "types.h"

class PMNode;
class PMeshNode;
class TimerAPI;
class CEifFile;
class PLightManager;

struct BGAnimNode {
    int m_unk00;                // 0x00 animation id, 0 ends the list
    BGAnimNode *m_unk04;        // 0x04 next node
};

class EntityManager {
public:
    EntityManager();
    ~EntityManager();

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
    void *SpawnEntity(unsigned int arg0, int arg1);
    void *Spawn(unsigned int arg0, bool arg1, int arg2);
    void LoadOverlay(char *arg0, char *arg1);
    void Reset(bool arg0);
    int Render(PLightManager *arg0);
    void LoadResource(char *arg0, bool arg1);
    void AddToRenderList(struct EntityBaseClass *arg0);
    void RemoveFromRenderList(struct EntityBaseClass *arg0);
    int BGAnimIsReset(int arg0);
    void EnableParticleFx(bool arg0);
    void UpdateSwordBGAnim();
    void ResetSwordBGAnim();
    void CheckSwordBGAnim(PMNode *pNode);
    void InitSwordBGAnimList(PMeshNode *pMesh);
    void SaveApparitionData(int arg0);
    void SetEifPosition(unsigned int arg0, unsigned int arg1, float (*arg2)[4]);
    void ModifyEifPosition();
    int SetEifWoken(unsigned int arg0, bool arg1, unsigned int arg2);
    void SpawnEditedInstances(char *arg0, bool arg1);
    void AfterSpawnEditedInstances();
    void RunPhysics(float arg0);
    void Animate(int arg0, float arg1);
    void ObjectCollision();
    void Process();
    void ProcessTrigger();
    void RestoreHolyGround();
    void SetHolyGround(float (*arg0)[4], float arg1, bool arg2);
    void ProcessIcons();
    void Init();

    static TimerAPI mTimerAPI;  // TimerAPI instance ticked by Process

    static void *mCameraAPI;    // MathAPI instance read by EntityBaseClass::CameraLookingAtMe

    void BGAnimAdd(int);
    char _pad000[0x5050];
    unsigned int m_unk5050;     // 0x5050 entity id counter, used by Spawn
    unsigned int m_unk5054;     // 0x5054 bound for dependency flag indices
    int m_unk5058;              // 0x5058 physics pass argument, not yet named
    void *m_unk505C;            // 0x505C player entity, stored by Spawn for arg0 == 3
    float m_unk5060;            // 0x5060 16-byte copy from the SetHolyGround argument, also written by SpawnEditedInstances
    float m_unk5064;            // 0x5064
    float m_unk5068;            // 0x5068
    float m_unk506C;            // 0x506C holy ground value, stored by SetHolyGround
    unsigned char m_unk5070;    // 0x5070 holy ground flag, stored by SetHolyGround
    char _pad5071[0x5078 - 0x5071];
    unsigned int m_unk5078;     // 0x5078 PArray count of apparitions put to sleep
    int m_unk507C;              // 0x507C PArray index
    void **m_unk5080;           // 0x5080 PArray entries, removed by Destroy
    char _pad5084[0x5088 - 0x5084];
    char m_unk5088[0xC];        // 0x5088 PHashTable, looked up by GetPtrToApparition
    char m_unk5094[0x50A0 - 0x5094];    // 0x5094 PHashTable, looked up by GetPtrToInstance
    unsigned int m_unk50A0;     // 0x50A0 PArray count of sub-lists keyed by arg0->m_unk08
    unsigned int m_unk50A4;     // 0x50A4 PArray index
    void **m_unk50A8;           // 0x50A8 PArray entries
    char _pad50AC[0x50B0 - 0x50AC];
    unsigned int m_unk50B0;    // 0x50B0 physics list count
    unsigned int m_unk50B4;     // 0x50B4 physics list index
    void **m_unk50B8;           // 0x50B8 physics list entries, EntityBaseClass pointers
    char _pad50BC[0x50C0 - 0x50BC];
    void *m_unk50C0;            // 0x50C0 OverlayManager *, used by LoadOverlay
    char _pad50C4[0x5194 - 0x50C4];
    CEifFile *m_unk5194;        // 0x5194 CEifFile *, walked by ModifyEifPosition
    char _pad5198[0x519C - 0x5198];
    int m_unk519C;             // 0x519C dependency count (max 0x40)
    DependencyEntry m_unk51A0[0x40];    // 0x51A0 dependency list
    char _pad53A0[0x53A1 - 0x53A0];
    char m_unk53A1[0x59A0 - 0x53A1];    // 0x53A1 per-entry flag bytes, indexed by value*4
    char m_unk59A0[0x5B20 - 0x59A0];    // 0x59A0 packed copy of the flag bytes, one per entry
    unsigned char m_unk5B20;    // 0x5B20 player byte copied from player+0x1F0
    unsigned char m_unk5B21;    // 0x5B21 player byte copied from player+0x1F4
    char _pad5B22[0x5B24 - 0x5B22];
    TallyEntry m_unk5B24[5];    // 0x5B24 tally counters, indexed by type (0..4)
    char _pad5B4C[0x5B50 - 0x5B4C];
    int m_unk5B50;              // 0x5B50 PArray count of sword BG animations
    int m_unk5B54;              // 0x5B54 PArray index
    PMNode **m_unk5B58;         // 0x5B58 PArray entries
    char _pad5B5C[0x5B60 - 0x5B5C];
    int m_unk5B60;              // 0x5B60 trigger count
    int m_unk5B64;              // 0x5B64 trigger scan index
    void **m_unk5B68;           // 0x5B68 trigger list, TriggerEntry pointers
    char _pad5B6C[0x5B70 - 0x5B6C];
    int m_unk5B70;              // 0x5B70 PArray count of trigger list (max 0x20)
    int m_unk5B74;              // 0x5B74 PArray index
    void **m_unk5B78;           // 0x5B78 PArray entries
    char _pad5B7C[0x5B84 - 0x5B7C];
    BGAnimNode *m_unk5B84;      // 0x5B84 BG animation list head
    char _pad5B88[4];
    BGAnimNode *m_unk5B8C;      // 0x5B8C BG animation list cursor
    char m_unk5B90[0x80];       // 0x5B90 spawned entity class table, indexed by class id (< 0x80)
    char m_unk5C10[0x5D48 - 0x5C10];    // 0x5C10 level EIF filename, strcpy target
    int m_unk5D48;              // 0x5D48 countdown, decremented by ProcessApparitions
    int m_unk5D4C;              // 0x5D4C cleared by LoadOverlay
    char _pad5D50[0x5F54 - 0x5D50];
    void **m_unk5F54;           // 0x5F54 icon list entries, IconEntry pointers
    char _pad5F58[0x5F5C - 0x5F58];
    void **m_unk5F5C;           // 0x5F5C icon list cursor (node: [0] entry, [1] next)
    char _pad5F60[0x5F74 - 0x5F60];
    float m_unk5F74[2];         // 0x5F74 indexed by ItemCounterType
};

#endif
