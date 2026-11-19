#include "ClockworkReaper.h"
#include "types.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    void SequenceViewer(unsigned int **arg0, int arg1);
};

static unsigned int *SequenceTable[32];

// FUNCTION: 0x001BF820 SetRiseAndAttack__15ClockworkReaperFPA4_fff
void ClockworkReaper::SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2) {
    m_unk1B8[0] = arg0[0][0];
    m_unk1B8[1] = arg0[0][1];
    m_unk1B8[2] = arg0[0][2];
    m_unk1C8[0] = arg0[0][0];
    m_unk1C8[1] = arg0[0][1];
    m_unk1C8[2] = arg0[0][2];
    m_unk1C4 = arg1;
    m_unk1D4 = arg2;
}

// FUNCTION: 0x001BF8E0 AnimationViewer__15ClockworkReaperFi
int ClockworkReaper::AnimationViewer(int arg0) {
    ((EntityBaseClass *)this)->SequenceViewer(SequenceTable, arg0);
    return 0x20;
}

// DRAFT: 0x001BF910 GetRenderPassIndex__15ClockworkReaperFv
// note: 14 differing lines; switch with case 0 and nested if/else tried, branch shape and lw order still differ.
int ClockworkReaper::GetRenderPassIndex() {
    if (m_unk1B0 == 2) {
        return 2;
    }
    if (m_unk1B0 == 1) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x001BF9C0 InBlockableState__15ClockworkReaperFv
// note: 2 differing lines: range test is sltiu into v0, original uses at (sltiu at,v0,N; bnez at); early-return, ternary and operand-swap forms tried.
int ClockworkReaper::InBlockableState() {
    if ((unsigned int)(m_unk20 - 0x15) < 5U || m_unk20 == 4) {
        return 1;
    }
    return 0;
}

// DRAFT: 0x001C02F0 CanAttackInState__15ClockworkReaperFv
// note: 2 differing lines: range test is sltiu into v0, original uses at (same as InBlockableState); split-range form gave 13, early returns 17.
int ClockworkReaper::CanAttackInState() {
    if (m_unk20 == 0 || m_unk20 == 3 || (unsigned int)(m_unk20 - 0x15) < 7U || m_unk20 == 0x1C) {
        return 1;
    }
    return 0;
}
