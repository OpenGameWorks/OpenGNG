#ifndef CLOCKWORKSTALKER_H
#define CLOCKWORKSTALKER_H

#include "types.h"

class EntityBaseClass;

// ClockworkStalker derives from EntityBaseClass; the base is not declared here,
// so every member is named by its offset from the object start.
class ClockworkStalker {
public:
    ClockworkStalker();
    void PlaySoundOnFrame(unsigned int arg0, unsigned int arg1);
    void CircleAround(float *arg0, float arg1);
    void KillTimers();
    void DeleteEffects();
    void CheckBlockAttack();
    int InBlockableState();
    int IsStalled(float fDist, float (*arg1)[4]);
    int PlayerFacingUs();
    int CanAttackPlayer();
    void SetDefaultVars();
    void SetEditableVars(char *arg0);
    void SetSpawnedFromEntity(float *arg0, float *arg1, int arg2);
    void OnTimerEvent(unsigned int arg0);
    void LoadCorrectMesh(bool arg0);
    void OnWakeEvent();
    void OnStopAttack();
    void FaceHit();
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    void Execute();

    char _pad000[4];
    unsigned int m_unk4;            // 0x004 timer argument
    char _pad008[0x20 - 0x08];
    int m_unk20;                    // 0x020 state
    char _pad024[0x38 - 0x24];
    char *m_unk38;                  // 0x038 entity whose 0x11C float receives FaceHit's angle
    char *m_unk3C;                  // 0x03C
    char _pad040[0xD4 - 0x40];
    void *m_unkD4;                  // 0x0D4 Shadow object, created by the attack-start state
    char _pad0D8[0xE9 - 0xD8];
    unsigned char m_unkE9;          // 0x0E9 nonzero while the position block is valid
    char _padEA[0xF4 - 0xEA];
    int m_unkF4;                    // 0x0F4 zero while no block is pending
    char _pad0F8[0x103 - 0xF8];
    unsigned char m_unk103;         // 0x103 set to 0x40 by the constructor
    int m_unk104;                   // 0x104 float bits 3.0f
    int m_unk108;                   // 0x108 float bits 2.0f
    int m_unk10C;                   // 0x10C flag word, bits 24..26 rewritten by the attack-start state
    char _pad110[0x140 - 0x110];
    unsigned int *m_unk140;         // 0x140
    char _pad144[0x163 - 0x144];
    unsigned char m_unk163;         // 0x163
    char _pad164[0x166 - 0x164];
    unsigned char m_unk166;         // 0x166 set to 1 by the constructor
    char _pad167[0x18C - 0x167];
    int m_unk18C;                   // 0x18C copied to m_unk1C4 and m_unk1D4 when m_unk1D8 is set
    char m_unk190;                 // 0x190 start of the embedded EntityBaseClass block
    char _pad191[0x1A0 - 0x191];
    char m_unk1A0[0x10];            // 0x1A0 16-byte block, second copy target in SetSpawnedFromEntity
    char _pad1B0[0x1B4 - 0x1B0];
    // 0x1B0..0x1FB is also the 0x4C-byte block copied by SetEditableVars
    int m_unk1B4;                   // 0x1B4
    int m_unk1B8;                   // 0x1B8
    int m_unk1BC;                   // 0x1BC
    int m_unk1C0;                   // 0x1C0
    int m_unk1C4;                   // 0x1C4 float bits 25.0f
    float m_unk1C8;                 // 0x1C8 copied from SetSpawnedFromEntity arg0[0]
    float m_unk1CC;                 // 0x1CC copied from SetSpawnedFromEntity arg0[1]
    float m_unk1D0;                 // 0x1D0 copied from SetSpawnedFromEntity arg0[2]
    int m_unk1D4;                   // 0x1D4 float bits 35.0f
    int m_unk1D8;                   // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;                   // 0x1E0
    int m_unk1E4;                   // 0x1E4
    int m_unk1E8;                   // 0x1E8
    int m_unk1EC;                   // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;                   // 0x1F4
    int m_unk1F8;                   // 0x1F8 float bits 0.1f
    int m_unk1FC;                   // 0x1FC
    float m_unk200[4];              // 0x200 position passed to Distance
    int m_unk210;                   // 0x210
    int m_unk214;                   // 0x214 timer id slot
    unsigned int m_unk218;          // 0x218 hit damage/state, written by OnHitEvent from arg3
    unsigned int m_unk21C;          // 0x21C written by OnHitEvent from arg3
    unsigned char m_unk220;         // 0x220 cleared by the constructor
    unsigned char m_unk221;         // 0x221 attack-ready flag
    unsigned char m_unk222;         // 0x222 timer-fired flag
    char _pad223[0x224 - 0x223];
    int m_unk224;                   // 0x224 random facing angle, set by the case 10 state
    int m_unk228;                   // 0x228
    int m_unk22C;                   // 0x22C
    int m_unk230;                   // 0x230
    int m_unk234;                   // 0x234 written by the attack-start state
    char _pad238[0x240 - 0x238];
    char m_unk240[0x264 - 0x240];   // 0x240 MathAPI object, passed as this to DistanceXZ
    int m_unk264;                   // 0x264 random 1 or 2, set by the attack-start state
    int m_unk268;                   // 0x268
    int m_unk26C;                   // 0x26C
    int m_unk270;                   // 0x270
    int m_unk274;                   // 0x274
    unsigned char m_unk278;         // 0x278 set to 1 by the constructor
    char _pad279[0x27C - 0x279];
    int m_unk27C;                   // 0x27C
    int m_unk280;                   // 0x280
    char _pad284[0x290 - 0x284];
    float m_unk290;                 // 0x290 player position X
    float m_unk294;                 // 0x294 player position Y
    float m_unk298;                 // 0x298 player position Z
    char _pad29C[0x2A0 - 0x29C];
    int m_unk2A0;                   // 0x2A0 mesh/state selector, toggled by OnTimerEvent
    int m_unk2A4;                   // 0x2A4
    int m_unk2A8;                   // 0x2A8 float bits -1.0f
    int m_unk2AC;                   // 0x2AC timer id slot
    unsigned char m_unk2B0;         // 0x2B0
    char _pad2B1[0x2C0 - 0x2B1];
    float m_unk2C0;                 // 0x2C0 attack-range state value
    float m_unk2C4;                 // 0x2C4 attack-range state value
    char _pad2C8[0x2D0 - 0x2C8];
    int m_unk2D0;                   // 0x2D0 timer id slot
    unsigned char m_unk2D4;         // 0x2D4 set from the 0x200 bit of OnHitEvent's arg3
    unsigned char m_unk2D5;         // 0x2D5 timer-fired flag
    char _pad2D6[0x2D8 - 0x2D6];
    int m_unk2D8;                   // 0x2D8 timer id slot
    int m_unk2DC;                   // 0x2DC
    unsigned int m_unk2E0;          // 0x2E0 effect id
    unsigned int *m_unk2E4;         // 0x2E4 sequence pointer
    unsigned int m_unk2E8;          // 0x2E8 damage fx handle, destroyed in dtor
    int m_unk2EC;                   // 0x2EC
    float m_unk2F0;                 // 0x2F0 random 90..110 value, set by the attack-start state
    unsigned int m_unk2F4;          // 0x2F4 last sound frame id, written by PlaySoundOnFrame
};

#endif
