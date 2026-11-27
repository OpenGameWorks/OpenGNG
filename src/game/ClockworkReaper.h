#ifndef CLOCKWORKREAPER_H
#define CLOCKWORKREAPER_H

#include "types.h"

// ClockworkReaper derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class PMNode;
class Physics;
class Shadow;
class EntityBaseClass;

class ClockworkReaper {
public:
    ClockworkReaper();
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    void AttachSoulStoneEffect(PMNode *arg0);
    int AnimationViewer(int arg0);
    int GetRenderPassIndex();
    int InBlockableState();
    int CheckBlockAttack();
    int CanAttackInState();
    int PlayerInAttackRadius();
    int CheckAttackPlayer();
    void LoadCorrectMesh(bool arg0);
    void FaceHit();
    int Stalled(float arg0);
    void DeleteEffects();
    void OnTimerEvent(unsigned int arg0);
    void OnStopAttack();
    void OutputDebug();
    void CheckOnWakeTasks();
    void SetSpawnedFromEntity(float *arg0, float *arg1, int arg2);
    void SetupHealth();
    void SetDefaultVars();
    void SetEditableVars(char *arg0);
    int GetHealth();
    const char *GetClassName();
    int GetTallyType();
    int GetArenaWaveID();
    bool IsArenaApparition();
    int NeedsToBeWoken();
    int GetWokenVarPos();
    void SetInnocentInstanceID(unsigned int);

    void Execute();
    void SetSpawnedFromLift();
    void OnWakeEvent();
    void OnSleepEvent();
    char _pad000[0x4];
    int m_unk4;             // 0x004 compared with the player's 0x1CC by CheckBlockAttack
    int m_unk8;             // 0x008 compared with 0x6C and 0x1D by OnHitEvent
    char _pad00C[0x20 - 0xC];
    int m_unk20;           // 0x020 state
    char _pad024[0x38 - 0x24];
    Physics *m_unk38;       // 0x038 physics object
    PMNode *m_unk3C;        // 0x03C node whose frame time and flags OutputDebug reads
    char _pad040[0xD4 - 0x40];
    Shadow *m_unkD4;        // 0x0D4 shadow object, LoadCorrectMesh
    char _pad0D8[0xE9 - 0xD8];
    unsigned char m_unkE9;  // 0x0E9 set on the first frame of a state
    char _pad0EA[0xF4 - 0xEA];
    int m_unkF4;            // 0x0F4 nonzero makes CheckBlockAttack return 0
    char _pad0F8[0x103 - 0xF8];
    signed char m_unk103;   // 0x103
    float m_unk104;         // 0x104
    float m_unk108;         // 0x108
    unsigned int m_unk10C;  // 0x10C, masked by OnHitEvent
    char _pad110[0x140 - 0x110];
    unsigned int *m_unk140; // 0x140 current sequence
    char _pad144[0x15C - 0x144];
    short m_unk15C;         // 0x15C
    short m_unk15E;         // 0x15E
    unsigned char m_unk160; // 0x160 sequence playing
    char _pad161[0x163 - 0x161];
    unsigned char m_unk163; // 0x163
    char _pad164[0x18C - 0x164];
    float m_unk18C;         // 0x18C
    u_long128 m_unk190;     // 0x190 spawn copy target, SetSpawnedFromEntity
    u_long128 m_unk1A0;     // 0x1A0 second spawn copy target, SetSpawnedFromEntity
    int m_unk1B0;           // 0x1B0 render pass selector
    char _pad1B4[0x1B8 - 0x1B4];
    float m_unk1B8[3];      // 0x1B8, written by SetRiseAndAttack
    float m_unk1C4;         // 0x1C4
    float m_unk1C8[3];      // 0x1C8
    float m_unk1D4;         // 0x1D4
    int m_unk1D8;           // 0x1D8 cleared by SetDefaultVars
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;           // 0x1E0 cleared by SetSpawnedFromEntity
    union {
        int m_unk1E4;       // 0x1E4
        float m_unk1E4f;
    };
    union {
        int m_unk1E8;       // 0x1E8
        float m_unk1E8f;
    };
    union {
        int m_unk1EC;       // 0x1EC
        float m_unk1ECf;
    };
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;           // 0x1F4
    union {
        int m_unk1F8;       // 0x1F8 default 0.1f bit pattern, set by SetDefaultVars
        float m_unk1F8f;
    };
    int m_unk1FC;           // 0x1FC
    int m_unk200;           // 0x200 nonzero forces the 0x2B6 flag, SetupHealth
    int m_unk204;           // 0x204
    int m_unk208;           // 0x208 health value, SetupHealth
    char _pad20C[0x210 - 0x20C];
    int m_unk210;           // 0x210 copy of m_unk208, SetupHealth
    float m_unk214;         // 0x214
    unsigned char m_unk218; // 0x218, set by OnTimerEvent
    char _pad219[0x21C - 0x219];
    float m_unk21C;         // 0x21C
    int m_unk220;           // 0x220 timer id
    int m_unk224;           // 0x224 stored by OnHitEvent
    int m_unk228;           // 0x228 stored by OnHitEvent
    int m_unk22C;           // 0x22C stored by OnHitEvent
    float *m_unk230;        // 0x230
    char _pad234[0x238 - 0x234];
    float m_unk238;         // 0x238
    unsigned int m_unk23C;  // 0x23C
    unsigned char m_unk240; // 0x240, set by OnTimerEvent
    char _pad241[0x244 - 0x241];
    int m_unk244;           // 0x244
    int m_unk248;           // 0x248 compared by OnHitEvent
    unsigned char m_unk24C; // 0x24C
    unsigned char m_unk24D; // 0x24D, set by OnTimerEvent
    char _pad24E[0x250 - 0x24E];
    int m_unk250;           // 0x250 timer id
    char _pad254[0x255 - 0x254];
    unsigned char m_unk255; // 0x255, tested by LoadCorrectMesh
    char _pad256[0x258 - 0x256];
    int m_unk258;           // 0x258
    int m_unk25C;           // 0x25C
    int m_unk260;           // 0x260
    int m_unk264;           // 0x264
    int m_unk268;           // 0x268
    int m_unk26C;           // 0x26C
    int m_unk270;           // 0x270
    char _pad274[0x278 - 0x274];
    signed char m_unk278;   // 0x278 select stored by OnHitEvent
    char _pad279[0x280 - 0x279];
    float m_unk280[3];      // 0x280
    char _pad28C[0x290 - 0x28C];
    float m_unk290[4];      // 0x290 position tested by PlayerInAttackRadius
    u_long128 m_unk2A0;     // 0x2A0 MathAPI-sized copy target, Stalled
    char _pad2B0[0x2B4 - 0x2B0];
    unsigned char m_unk2B4; // 0x2B4
    unsigned char m_unk2B5; // 0x2B5
    unsigned char m_unk2B6; // 0x2B6, tested by CheckOnWakeTasks
    unsigned char m_unk2B7; // 0x2B7
    unsigned char m_unk2B8; // 0x2B8, tested by CheckOnWakeTasks
    unsigned char m_unk2B9; // 0x2B9
    char _pad2BA[0x2BC - 0x2BA];
    int m_unk2BC;           // 0x2BC
    float m_unk2C0;         // 0x2C0
    signed char m_unk2C4;   // 0x2C4, cleared by CheckOnWakeTasks
    unsigned char m_unk2C5; // 0x2C5, set by CheckBlockAttack
    char _pad2C6[0x2C8 - 0x2C6];
    int m_unk2C8;           // 0x2C8, cleared by CheckBlockAttack
    char _pad2CC[0x2D0 - 0x2CC];
    float m_unk2D0[4];      // 0x2D0
    unsigned char m_unk2E0; // 0x2E0, set by AttachSoulStoneEffect
    char _pad2E1[0x2E4 - 0x2E1];
    unsigned char m_unk2E4; // 0x2E4
    unsigned char m_unk2E5; // 0x2E5
    signed char m_unk2E6;   // 0x2E6 cleared by OnHitEvent
    unsigned char m_unk2E7; // 0x2E7
    int m_unk2E8;           // 0x2E8 timer id
    int m_unk2EC;           // 0x2EC effect handle
    int m_unk2F0;           // 0x2F0 effect handle
    int m_unk2F4;           // 0x2F4 effect handle
    int m_unk2F8;           // 0x2F8 damage fx handle
    unsigned char m_unk2FC; // 0x2FC
    unsigned char m_unk2FD; // 0x2FD
    unsigned char m_unk2FE; // 0x2FE, set by OnTimerEvent
    char _pad2FF[0x300 - 0x2FF];
    int m_unk300;           // 0x300 timer id
    unsigned int m_unk304;        // 0x304
    unsigned int m_unk308;  // 0x308
};

#endif
