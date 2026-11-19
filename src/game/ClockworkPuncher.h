#ifndef CLOCKWORKPUNCHER_H
#define CLOCKWORKPUNCHER_H

#include "types.h"

// ClockworkPuncher derives from EntityBaseClass; the base is not declared here,
// so every member is named by its offset from the object start.
class ClockworkPuncher {
public:
    void AttachDamageEffect(class PMNode *pNode, unsigned int nId, float fA, float fB, float fC);
    int Stalled(float fDist);
    int PlayerFacingUs();
    int InBlockableState();
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    void SetEditableVars(char *arg0);
    void SetDefaultVars();
    void OnSleepEvent();
    void OnEffectDelete(unsigned int nHandle);
    void OnStopAttack();
    void OnAttackEvent(class EntityBaseClass *pEntity, int nEvent);
    void DeleteEffects();
    void DeleteTimers();
    void SetSpawnedFromEntity(float *pPos, float *pAlt, int nType);
    void LoadCorrectMesh();

    char _pad000[0x20];
    int m_unk20;             // 0x020 state
    char _pad024[0x3C - 0x24];
    char *m_unk3C;           // 0x03C target entity pointer; +0x80 used when non-null
    char _pad040[0x163 - 0x40];
    unsigned char m_unk163;  // 0x163
    char _pad164[0x190 - 0x164];
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
    char _pad200[0x210 - 0x200];
    int m_unk210;            // 0x210
    unsigned int m_unk214;   // 0x214 timer handle, killed by DeleteTimers
    char _pad218[0x250 - 0x218];
    char m_unk250[0x270 - 0x250]; // 0x250 MathAPI object, passed as this to DistanceXZ
    unsigned char m_unk270;  // 0x270
    char _pad271;
    unsigned char m_unk272;  // 0x272
    char _pad273[0x27C - 0x273];
    unsigned int m_unk27C;   // 0x27C timer handle, killed by DeleteTimers
    char _pad280[0x288 - 0x280];
    unsigned int m_unk288;   // 0x288 timer handle, killed by DeleteTimers
    unsigned int m_unk28C;   // 0x28C timer handle, killed by DeleteTimers
    char _pad290[0x298 - 0x290];
    int m_unk298;            // 0x298 effect handle, cleared by OnEffectDelete
    int m_unk29C;            // 0x29C effect handle, cleared by OnEffectDelete
    int m_unk2A0;            // 0x2A0 effect handle, cleared by OnEffectDelete
    int m_unk2A4;            // 0x2A4 effect handle, cleared by OnEffectDelete
    int m_unk2A8;            // 0x2A8 effect handle, cleared by OnEffectDelete
    int m_unk2AC;            // 0x2AC effect handle, cleared by OnEffectDelete
    char _pad2B0[0x2B4 - 0x2B0];
    int m_unk2B4;            // 0x2B4
    char _pad2B8[0x2BD - 0x2B8];
    unsigned char m_unk2BD;  // 0x2BD
    char _pad2BE[0x2C4 - 0x2BE];
    int m_unk2C4;            // 0x2C4 damage fx handle, destroyed by the destructor
};

#endif
