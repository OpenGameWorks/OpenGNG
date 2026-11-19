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

    char _pad000[0x20];
    int m_unk20;            // 0x020 state
    char _pad024[0x1B0 - 0x24];
    int m_unk1B0;           // 0x1B0 render pass selector
    char _pad1B4[0x1B8 - 0x1B4];
    float m_unk1B8[3];      // 0x1B8, written by SetRiseAndAttack
    float m_unk1C4;         // 0x1C4
    float m_unk1C8[3];      // 0x1C8
    float m_unk1D4;         // 0x1D4
};

#endif
