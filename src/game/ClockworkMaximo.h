#ifndef CLOCKWORKMAXIMO_H
#define CLOCKWORKMAXIMO_H

#include "types.h"

// ClockworkMaximo derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class EntityBaseClass;
class Shield;
class Shadow;

class ClockworkMaximoState {
public:
    char _pad000[0xE4];
    char *m_unkE4;          // 0x0E4
    unsigned int m_unkE8;   // 0x0E8
    unsigned int m_unkEC;   // 0x0EC
    char _pad0F0[0x108 - 0xF0];
    int m_unk108;           // 0x108
    char _pad10C[0x11C - 0x10C];
    float m_unk11C;         // 0x11C
};

class ClockworkMaximo {
public:
    enum WEAPON_TYPE {
        WEAPON_TYPE_0 = 0,
        WEAPON_TYPE_1 = 1,
        WEAPON_TYPE_2 = 2
    };

    void FootStepSound(unsigned int arg0);
    int CanJump(float (*arg0)[4]);
    int DetermineIdleState();
    int DetermineNewState();
    void OnWakeEvent();
    void Execute();
    void OnTimerEvent(unsigned int arg0);
    void OnAttackEvent(EntityBaseClass *arg0, int arg1);
    void AttachWeapon(WEAPON_TYPE arg0);
    void DetachWeapon(WEAPON_TYPE arg0);
    void UpdateShieldStatus(Shield *arg0);
    void ThrowShield();
    bool TargetFacingUs();
    bool FacingTarget(EntityBaseClass *arg0);
    void FaceHit(EntityBaseClass *arg0);
    bool IsMoving();
    bool StopMoving();
    ClockworkMaximo *GetTarget();
    bool FaceTarget(float arg0);
    bool Stalled(float arg0, unsigned int &arg1);
    bool InBlockableState();
    void CheckBlockAttack();
    void SetDefaultVars();
    void SetShockwave();
    void SetSpawnedFromEntity(float *arg0, float *arg1, int arg2);
    void SetEditableVars(char *arg0);
    ClockworkMaximo();
    int OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3);
    int GetHealth();
    const char *GetClassName();
    int GetTallyType();
    int GetArenaWaveID();
    bool IsArenaApparition();
    int NeedsToBeWoken();
    int GetWokenVarPos();
    void SetInnocentInstanceID(unsigned int);

    bool IsAlive();
    int GetAttackTimeOut();
    void *m_unk0;                  // 0x000 vtable pointer
    unsigned int m_unk4;            // 0x004 timer argument for CreateTimer
    char _pad008[0x0C - 0x08];
    int m_unkC;                     // 0x00C (lw in the original)
    char _pad010[0x1B - 0x10];
    unsigned char m_unk1B;          // 0x01B
    char _pad01C[0x20 - 0x1C];
    int m_unk20;                    // 0x020
    char _pad024[0x38 - 0x24];
    ClockworkMaximoState *m_unk38;  // 0x038
    int m_unk3C;                    // 0x03C
    char _pad040[0xD4 - 0x40];
    Shadow *m_unkD4;                // 0x0D4 (lw/sw in the original)
    char _pad0D8[0xE9 - 0xD8];
    unsigned char m_unkE9;          // 0x0E9 (lbu in the original)
    char _pad0EA[0xF8 - 0xEA];
    int m_unkF8;                   // 0x0F8 set to 0x3F000000 by the constructor
    int m_unkFC;                    // 0x0FC set to 0x3F400000 by the constructor
    char _pad100[0x103 - 0x100];
    unsigned char m_unk103;         // 0x103
    int m_unk104;                   // 0x104 (lw/sw in the original)
    int m_unk108;                   // 0x108 (lw/sw in the original)
    int m_unk10C;                   // 0x10C (lw/sw in the original)
    char _pad110[0x140 - 0x110];
    int m_unk140;                   // 0x140
    char _pad144[0x160 - 0x144];
    unsigned char m_unk160;         // 0x160 (lbu in the original)
    char _pad161[0x166 - 0x161];
    unsigned char m_unk166;        // 0x166 set to 1 by the constructor
    char _pad167[0x18C - 0x167];
    float m_unk18C;                 // 0x18C
    u_long128 m_unk190;             // 0x190
    u_long128 m_unk1A0;             // 0x1A0
    int m_unk1B0;                   // 0x1B0 (lw in the original)
    int m_unk1B4;                  // 0x1B4
    int m_unk1B8;                   // 0x1B8
    int m_unk1BC;                   // 0x1BC
    int m_unk1C0;                   // 0x1C0
    int m_unk1C4;                   // 0x1C4
    float m_unk1C8;                 // 0x1C8
    float m_unk1CC;                 // 0x1CC
    float m_unk1D0;                 // 0x1D0
    int m_unk1D4;                   // 0x1D4
    int m_unk1D8;                   // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;                   // 0x1E0
    int m_unk1E4;                   // 0x1E4
    int m_unk1E8;                   // 0x1E8
    char _pad1EC[0x1F0 - 0x1EC];
    float m_unk1F0;                 // 0x1F0
    float m_unk1F4;                 // 0x1F4
    float m_unk1F8;                 // 0x1F8
    char _pad1FC[0x200 - 0x1FC];
    float m_unk200;                 // 0x200
    float m_unk204;                 // 0x204
    float m_unk208;                 // 0x208
    char _pad20C[0x210 - 0x20C];
    u_long128 m_unk210;             // 0x210
    char _pad220[0x230 - 0x220];
    u_long128 m_unk230;             // 0x230
    int m_unk240;                   // 0x240
    int m_unk244;                   // 0x244
    char _pad248[0x24C - 0x248];
    int m_unk24C;                   // 0x24C
    unsigned int m_unk250;          // 0x250
    int m_unk254;                   // 0x254
    unsigned char m_unk258;         // 0x258 cleared by the constructor
    char _pad259[0x25C - 0x259];
    int m_unk25C;                   // 0x25C set to -1 by the constructor
    unsigned char m_unk260;         // 0x260
    char _pad261[0x264 - 0x261];
    int m_unk264;                   // 0x264 cleared by the constructor
    // 0x268: a member whose type declares a destructor; the constructor keeps
    // `this` spilled at 0x1C(sp), which CodeWarrior does only for such members.
    struct Member268 { ~Member268(); char _pad268[0x26C - 0x268]; float m_unk26C; int m_unk270; } m_unk268;
    int m_unk274;                   // 0x274
    int m_unk278;                   // 0x278
    char m_unk27C;                  // 0x27C
    Shield *m_unk280;               // 0x280
    int m_unk284;                   // 0x284 cleared by the constructor
    int m_unk288;                   // 0x288 cleared by the constructor
    unsigned char m_unk28C;         // 0x28C cleared by the constructor
    unsigned char m_unk28D;         // 0x28D cleared by the constructor
    unsigned char m_unk28E;         // 0x28E cleared by the constructor
    unsigned char m_unk28F;         // 0x28F cleared by the constructor
    unsigned char m_unk290;         // 0x290 cleared by the constructor
};

#endif
