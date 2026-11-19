#include "ClockworkPuncher.h"

// TODO(header): foreign declarations
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void SetState__15EntityBaseClassFi(void *, int);

// DRAFT: 0x001DEB90 InBlockableState__16ClockworkPuncherFv
// note: 2 lines differ: original sltiu uses $at for the 0xE..0xF range test, compiled uses v0. Tried early returns, separate ifs, reordered ||, two-sided range, int temp; this form is best.
int ClockworkPuncher::InBlockableState() {
    if (m_unk20 == 2 || m_unk20 == 0x17 || (unsigned int)(m_unk20 - 0xE) < 2U || m_unk20 == 0x10) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001DEE00 SetRiseAndAttack__16ClockworkPuncherFPA4_fff
void ClockworkPuncher::SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2) {
    m_unk1B8[0] = arg0[0][0];
    m_unk1B8[1] = arg0[0][1];
    m_unk1B8[2] = arg0[0][2];
    m_unk1C8[0] = arg0[0][0];
    m_unk1C8[1] = arg0[0][1];
    m_unk1C8[2] = arg0[0][2];
    m_unk1C4 = arg1;
    m_unk1D4 = arg2;
}

// FUNCTION: 0x001DEF20 SetEditableVars__16ClockworkPuncherFPc
void ClockworkPuncher::SetEditableVars(char *arg0) {
    memcpy((char *)this + 0x1B0, arg0, 0x4C);
    m_unk1FC = 1000;
    m_unk210 = m_unk1FC;
}

// FUNCTION: 0x001DF1B0 OnSleepEvent__16ClockworkPuncherFv
void ClockworkPuncher::OnSleepEvent() {
    DeleteEffects();
    DeleteTimers();
    m_unk272 = 1;
    m_unk2B4 = 0;
}

// FUNCTION: 0x001DF9A0 OnStopAttack__16ClockworkPuncherFv
void ClockworkPuncher::OnStopAttack() {
    if (m_unk163 != 2) {
        if (m_unk20 != 0xE) {
            SetState__15EntityBaseClassFi(this, 0);
        }
    }
}
