#ifndef CLOCKWORKREAPER_H
#define CLOCKWORKREAPER_H

#include "types.h"

// ClockworkReaper derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class PMNode;

class ClockworkReaper {
public:
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    void AttachSoulStoneEffect(PMNode *arg0);
    int AnimationViewer(int arg0);
    int GetRenderPassIndex();
    int InBlockableState();
    int CanAttackInState();
    int PlayerInAttackRadius();
    void DeleteEffects();
    void OnTimerEvent(unsigned int arg0);
    void OnStopAttack();
    void OutputDebug();
    void SetSpawnedFromEntity(float *arg0, float *arg1, int arg2);
    void SetupHealth();
    void SetDefaultVars();
    void SetEditableVars(char *arg0);

    char _pad000[0x20];
    int m_unk20;            // 0x020 state
    char _pad024[0x3C - 0x24];
    PMNode *m_unk3C;        // 0x03C node whose frame time and flags OutputDebug reads
    char _pad040[0x163 - 0x40];
    unsigned char m_unk163; // 0x163
    char _pad164[0x190 - 0x164];
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
    int m_unk1E4;           // 0x1E4
    int m_unk1E8;           // 0x1E8
    int m_unk1EC;           // 0x1EC
    char _pad1F0[0x1F4 - 0x1F0];
    int m_unk1F4;           // 0x1F4
    int m_unk1F8;           // 0x1F8 default 0.1f bit pattern, set by SetDefaultVars
    int m_unk1FC;           // 0x1FC
    char _pad200[0x204 - 0x200];
    int m_unk204;           // 0x204
    int m_unk208;           // 0x208
    char _pad20C[0x218 - 0x20C];
    unsigned char m_unk218; // 0x218, set by OnTimerEvent
    char _pad219[0x220 - 0x219];
    int m_unk220;           // 0x220 timer id
    char _pad224[0x240 - 0x224];
    unsigned char m_unk240; // 0x240, set by OnTimerEvent
    char _pad241[0x24D - 0x241];
    unsigned char m_unk24D; // 0x24D, set by OnTimerEvent
    char _pad24E[0x250 - 0x24E];
    int m_unk250;           // 0x250 timer id
    char _pad254[0x290 - 0x254];
    float m_unk290[4];      // 0x290 position tested by PlayerInAttackRadius
    char _pad2A0[0x2E0 - 0x2A0];
    unsigned char m_unk2E0; // 0x2E0, set by AttachSoulStoneEffect
    char _pad2E1[0x2E8 - 0x2E1];
    int m_unk2E8;           // 0x2E8 timer id
    int m_unk2EC;           // 0x2EC effect handle
    int m_unk2F0;           // 0x2F0 effect handle
    char _pad2F4[0x2F8 - 0x2F4];
    int m_unk2F8;           // 0x2F8 damage fx handle
    char _pad2FC[0x2FE - 0x2FC];
    unsigned char m_unk2FE; // 0x2FE, set by OnTimerEvent
    char _pad2FF[0x300 - 0x2FF];
    int m_unk300;           // 0x300 timer id
};

#endif
