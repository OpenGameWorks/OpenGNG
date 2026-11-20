#ifndef CLOCKWORKPUNCHER_H
#define CLOCKWORKPUNCHER_H

#include "types.h"

class PMNode;

// ClockworkPuncher derives from EntityBaseClass; the base is not declared here,
// so every member is named by its offset from the object start.
class ClockworkPuncher {
public:
    ClockworkPuncher();
    void AttachSparkEffect();
    void AttachDamageMesh();
    void AttachDamageEffect(class PMNode *pNode, unsigned int nId, float fA, float fB, float fC);
    int Stalled(float fDist);
    int PlayerFacingUs();
    int InBlockableState();
    void CheckBlockAttack();
    int CanAttackPlayer();
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    void SetEditableVars(char *arg0);
    void SetDefaultVars();
    void OnTimerEvent(unsigned int nHandle);
    void OnWakeEvent();
    void OnSleepEvent();
    void OnEffectDelete(unsigned int nHandle);
    void OnStopAttack();
    void OnAttackEvent(class EntityBaseClass *pEntity, int nEvent);
    int OnHitEvent(class EntityBaseClass *pEntity, int nArg, unsigned int nFlags, unsigned int nFlags2);
    void DeleteEffects();
    void DeleteTimers();
    void FaceHit();
    void SetSpawnedFromEntity(float *pPos, float *pAlt, int nType);
    void LoadCorrectMesh();
    void ChooseNextState();
    void ChooseAttack();
    void SetEffectsFrameRate(float fRate);

    void *m_unk0;            // 0x000 vtable pointer
    int m_unk4;             // 0x004 compared with the player's +0x1CC link by CheckBlockAttack
    char _pad008[0x20 - 0x08];
    int m_unk20;             // 0x020 state
    char _pad024[0x38 - 0x24];
    char *m_unk38;           // 0x038 object whose +0x11C float is set by FaceHit
    char *m_unk3C;           // 0x03C target entity pointer; +0x80 used when non-null
    char _pad040[0xD8 - 0x40];
    float m_unkD8;           // 0x0D8 float, stored by OnHitEvent
    union {
        int m_unkDC;         // 0x0DC written as int 0 by the constructor path
        float m_unkDCf;      // 0x0DC written as float 0.3f by OnHitEvent
    };
    char _pad0E0[0xF4 - 0xE0];
    int m_unkF4;             // 0x0F4
    float m_unkF8;           // 0x0F8 set to 1.5f by the constructor
    float m_unkFC;           // 0x0FC set to 2.0f by the constructor
    char _pad100[0x163 - 0x100];
    unsigned char m_unk163;  // 0x163
    char _pad164[0x166 - 0x164];
    char m_unk166;           // 0x166 set to 1 by the constructor
    char _pad167[0x190 - 0x167];
    char m_unk190;           // 0x190 start of the embedded EntityBaseClass block, address taken
    char _pad191[0x1B4 - 0x191];
    int m_unk1B4;            // 0x1B4
    float m_unk1B8[3];       // 0x1B8, written by SetRiseAndAttack
    float m_unk1C4;          // 0x1C4
    float m_unk1C8[3];       // 0x1C8
    float m_unk1D4;          // 0x1D4
    int m_unk1D8;            // 0x1D8
    char _pad1DC[0x1E0 - 0x1DC];
    int m_unk1E0;            // 0x1E0
    int m_unk1E4;            // 0x1E4
    int m_unk1E8;            // 0x1E8
    int m_unk1EC;            // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;            // 0x1F4
    float m_unk1F8;          // 0x1F8
    // 0x1B0..0x1FB is also the 0x4C-byte block copied by SetEditableVars
    int m_unk1FC;            // 0x1FC
    char m_unk200[0x10];     // 0x200 16-byte block copied from 0x190 or the target's +0x80
    int m_unk210;            // 0x210
    unsigned int m_unk214;   // 0x214 timer handle, killed by DeleteTimers
    int m_unk218;            // 0x218 state flags, set by OnHitEvent
    int m_unk21C;            // 0x21C
    char _pad220[0x224 - 0x220];
    int m_unk224;            // 0x224 set to 0 by the constructor
    char _pad228[0x250 - 0x228];
    char m_unk250[0x270 - 0x250]; // 0x250 MathAPI object, passed as this to DistanceXZ
    unsigned char m_unk270;  // 0x270
    unsigned char m_unk271;  // 0x271
    unsigned char m_unk272;  // 0x272
    char _pad273[0x274 - 0x273];
    char m_unk274;           // 0x274
    char _pad275[0x276 - 0x275];
    unsigned char m_unk276;  // 0x276 read by ChooseNextState
    char m_unk277;           // 0x277 set to 1 by the constructor
    char m_unk278;           // 0x278 set to 1 by OnTimerEvent
    char _pad279[0x27C - 0x279];
    unsigned int m_unk27C;   // 0x27C timer handle, killed by DeleteTimers
    int m_unk280;            // 0x280
    float m_unk284;          // 0x284 frame rate passed to SetFrameRate and SetEffectsFrameRate
    unsigned int m_unk288;   // 0x288 timer handle, killed by DeleteTimers
    unsigned int m_unk28C;   // 0x28C timer handle, killed by DeleteTimers
    float m_unk290;          // 0x290 written to PMNode +0x90 by OnTimerEvent
    float m_unk294;          // 0x294 set to 7.0f by the constructor
    int m_unk298;            // 0x298 effect handle, cleared by OnEffectDelete
    int m_unk29C;            // 0x29C effect handle, cleared by OnEffectDelete
    int m_unk2A0;            // 0x2A0 effect handle, cleared by OnEffectDelete
    int m_unk2A4;            // 0x2A4 effect handle, cleared by OnEffectDelete
    int m_unk2A8;            // 0x2A8 effect handle, cleared by OnEffectDelete
    int m_unk2AC;            // 0x2AC effect handle, cleared by OnEffectDelete
    int m_unk2B0;            // 0x2B0
    PMNode *m_unk2B4;        // 0x2B4 PMNode pointer, used by AttachSparkEffect and AttachDamageEffect
    int m_unk2B8;            // 0x2B8
    unsigned char m_unk2BC;  // 0x2BC
    unsigned char m_unk2BD;  // 0x2BD
    char _pad2BE[0x2C0 - 0x2BE];
    int m_unk2C0;            // 0x2C0
    int m_unk2C4;            // 0x2C4 damage fx handle, destroyed by the destructor
    int m_unk2C8;            // 0x2C8
    int m_unk2CC;            // 0x2CC
    int m_unk2D0;            // 0x2D0
    unsigned char m_unk2D4;  // 0x2D4
};

#endif
