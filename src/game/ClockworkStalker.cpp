#include "types.h"
#include "ClockworkStalker.h"

// TODO(header): foreign declarations
class EntityBaseClass;

class EffectAPI {
public:
    char _pad000[20];
    void DeleteEffect(unsigned int);
};

class MathAPI {
public:
    int FacingPoint(EntityBaseClass *, float (*)[4], float);
};

extern EffectAPI mEffectAPI__13EntityManager;
extern MathAPI *mPlayerAPI__13EntityManager;
extern char ClockworkStalker_KnockUp1Seq[];
extern char ClockworkStalker_KnockUp2Seq[];
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *, unsigned int *);

// FUNCTION: 0x001E2DA0 DeleteEffects__16ClockworkStalkerFv
void ClockworkStalker::DeleteEffects() {
    if (m_unk2E0 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2E0);
        m_unk2E0 = 0;
    }
}

// FUNCTION: 0x001E2DE0 InBlockableState__16ClockworkStalkerFv
int ClockworkStalker::InBlockableState() {
    if ((unsigned int)(m_unk20 - 0x14) <= 1U || m_unk20 == 0x1B ||
        m_unk140 == (unsigned int *)ClockworkStalker_KnockUp1Seq ||
        m_unk140 == (unsigned int *)ClockworkStalker_KnockUp2Seq) {
        return 0;
    }
    return 1;
}

// FUNCTION: 0x001E3110 PlayerFacingUs__16ClockworkStalkerFv
int ClockworkStalker::PlayerFacingUs() {
    MathAPI *player = mPlayerAPI__13EntityManager;
    if (player != 0) {
        char *target = &m_unk190;
        float (*unused)[4];
        if (m_unk3C != 0) {
            target = m_unk3C + 0x80;
        }
        if (player->FacingPoint((EntityBaseClass *)target, unused, 60.0f) != 0) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x001E34E0 OnWakeEvent__16ClockworkStalkerFv
void ClockworkStalker::OnWakeEvent() {
    if (m_unk2E4 != 0) {
        PlaySequence__15EntityBaseClassFPUi(this, m_unk2E4);
    }
}

// FUNCTION: 0x001E3880 OnStopAttack__16ClockworkStalkerFv
void ClockworkStalker::OnStopAttack() {
    if (m_unk163 == 2) {
        return;
    }
    if (m_unk20 == 0xD) {
        return;
    }
    if (m_unk20 == 0x1B) {
        return;
    }
    SetState__15EntityBaseClassFi(this, 0xD);
}
