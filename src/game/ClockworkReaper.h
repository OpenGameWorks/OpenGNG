#ifndef CLOCKWORKREAPER_H
#define CLOCKWORKREAPER_H

#include "types.h"

// ClockworkReaper derives from EntityBaseClass at offset 0; the base is not
// declared here, so every member is named by its offset from the object start.
class ClockworkReaper {
public:
    void SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2);
    int AnimationViewer(int arg0);
    int GetRenderPassIndex();
    int InBlockableState();
    int CanAttackInState();
    int PlayerInAttackRadius();
    void DeleteEffects();
    void OnTimerEvent(unsigned int arg0);
    void OnStopAttack();

    char _pad000[0x20];
    int m_unk20;            // 0x020 state
    char _pad024[0x163 - 0x24];
    unsigned char m_unk163; // 0x163
    char _pad164[0x1B0 - 0x164];
    int m_unk1B0;           // 0x1B0 render pass selector
    char _pad1B4[0x1B8 - 0x1B4];
    float m_unk1B8[3];      // 0x1B8, written by SetRiseAndAttack
    float m_unk1C4;         // 0x1C4
    float m_unk1C8[3];      // 0x1C8
    float m_unk1D4;         // 0x1D4
    char _pad1D8[0x208 - 0x1D8];
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
    char _pad2A0[0x2E8 - 0x2A0];
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
