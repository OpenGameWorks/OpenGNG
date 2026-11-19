#include "ClockworkMaximo.h"
#include "types.h"

// TODO(header): foreign declarations
class EntityBaseClass {
public:
    void PlaySoundOnFrame(unsigned int arg0, unsigned int arg1);

    char _pad000[8];
    int m_unk8;             // 0x008
};

class MathAPI {
public:
    static int RandomIntRange(int arg0, int arg1);
};

extern unsigned int FootSound[8];

// DRAFT: 0x00210600 FootStepSound__15ClockworkMaximoFUi
// note: original is a tail call (j) with no frame; ours sets up a frame and jal. Tried dropping temp local, ternary single call, bare constant call: no drop.
void ClockworkMaximo::FootStepSound(unsigned int arg0) {
    ClockworkMaximoState *temp = m_unk38;
    unsigned int snd;

    if (temp->m_unk108 & 0x200) {
        snd = 0x4E25;
    } else {
        snd = FootSound[(temp->m_unkE8 >> 11) & 7];
    }
    ((EntityBaseClass *)this)->PlaySoundOnFrame(snd, arg0);
}

// FUNCTION: 0x00211510 DetermineIdleState__15ClockworkMaximoFv
int ClockworkMaximo::DetermineIdleState() {
    m_unk38->m_unkEC = 0x80113FD5;
    return (MathAPI::RandomIntRange(0, 0x64) & 1) != 0;
}

// DRAFT: 0x00211780 OnWakeEvent__15ClockworkMaximoFv
// note: ternary compiles to branches, not movz; load order differs. Tried local-variable form: same 15 lines.
void ClockworkMaximo::OnWakeEvent() {
    if (m_unk3C != 0) {
        AttachWeapon((m_unk1E4 == 0) ? WEAPON_TYPE_0 : WEAPON_TYPE_2);
        if (m_unk1E8 != 0) {
            AttachWeapon(WEAPON_TYPE_1);
        }
    }
}

// FUNCTION: 0x002117D0 OnTimerEvent__15ClockworkMaximoFUi
void ClockworkMaximo::OnTimerEvent(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk274) {
        m_unk274 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk278) {
        m_unk278 = 0;
    }
}

// DRAFT: 0x00211C50 OnAttackEvent__15ClockworkMaximoFP15EntityBaseClassi
// note: branch layout differs (original uses beq/b to shared exit, ours bne); positive form 15 lines, explicit else-return 17 lines.
void ClockworkMaximo::OnAttackEvent(EntityBaseClass *arg0, int arg1) {
    int t;

    if (arg0 != 0) {
        t = arg0->m_unk8;
        if (t == 0x48 || t == 3) {
            t = m_unk20;
            m_unk27C = (t == 0x18) || (t == 0xE);
        }
    }
}
