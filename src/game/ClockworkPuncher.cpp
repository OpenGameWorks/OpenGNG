#include "ClockworkPuncher.h"

// TODO(header): foreign declarations
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void PlaySound__15EntityBaseClassFUi(void *, unsigned int);

class EntityBaseClass {
public:
    char _pad000[8];
    int m_unk8;
};

class MathAPI {
public:
    int FacingPoint(EntityBaseClass *arg0, float (*arg1)[4], float arg2);
};
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern MathAPI *mPlayerAPI__13EntityManager;

struct tagParticleFxTrigger;
class PMNode {
public:
    int AddFxTrigger(struct tagParticleFxTrigger *pTrigger, bool bFlag);
};

// FUNCTION: 0x001DE730 AttachDamageEffect__16ClockworkPuncherFP6PMNodeUifff
void ClockworkPuncher::AttachDamageEffect(PMNode *pNode, unsigned int nId, float fA, float fB, float fC) {
    struct FxTriggerBlock {
        unsigned int id;
        float a;
        float b;
        float c;
        int z0;
        int z1;
        int n0;
        int n1;
        int z2;
        int z3;
    } trig;

    if (pNode != 0) {
        trig.id = nId;
        trig.a = fA;
        trig.b = fB;
        trig.c = fC;
        trig.z0 = 0;
        trig.z1 = 0;
        trig.n0 = (int)0xBF800000;
        trig.n1 = (int)0xBF800000;
        trig.z2 = 0;
        trig.z3 = 0;
        pNode->AddFxTrigger((struct tagParticleFxTrigger *)&trig, 0);
    }
}

// FUNCTION: 0x001DEAE0 Stalled__16ClockworkPuncherFf
int ClockworkPuncher::Stalled(float fDist) {
    char *target;
    float dist;
    if (m_unk3C != 0) {
        target = m_unk3C + 0x80;
    } else {
        target = &m_unk190;
    }
    dist = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)m_unk250, (float (*)[4])target);
    if (dist <= fDist) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001DEB30 PlayerFacingUs__16ClockworkPuncherFv
int ClockworkPuncher::PlayerFacingUs() {
    MathAPI *player = mPlayerAPI__13EntityManager;
    if (player != 0) {
        char *target = &m_unk190;
        float (*unused)[4];
        if (m_unk3C != 0) {
            target = m_unk3C + 0x80;
        }
        if (player->FacingPoint((EntityBaseClass *)target, unused, 45.0f) != 0) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x001DEB90 InBlockableState__16ClockworkPuncherFv
int ClockworkPuncher::InBlockableState() {
    if (m_unk20 == 2 || m_unk20 == 0x17 || (unsigned int)(m_unk20 - 0xE) <= 1U || m_unk20 == 0x10) {
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

// FUNCTION: 0x001DEE40 SetDefaultVars__16ClockworkPuncherFv
void ClockworkPuncher::SetDefaultVars() {
    m_unk1FC = 0x3E8;
    m_unk210 = m_unk1FC;
    m_unk1B8[0] = 0.0f;
    m_unk1B8[1] = 0.0f;
    m_unk1B8[2] = 0.0f;
    *(int *)&m_unk1C4 = 0x41C80000;
    *(int *)&m_unk1D4 = 0x420C0000;
    m_unk1B4 = 0;
    m_unk1E0 = 1;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1F4 = 0;
    m_unk1D8 = 0;
    *(int *)&m_unk1F8 = 0x3DCCCCCD;
    m_unk2BD = 1;
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

// FUNCTION: 0x001DF950 OnAttackEvent__16ClockworkPuncherFP15EntityBaseClassi
void ClockworkPuncher::OnAttackEvent(EntityBaseClass *arg0, int arg1) {
    if (arg0->m_unk8 == 3 && arg1 != 5 && m_unk20 == 0x18) {
        PlaySound__15EntityBaseClassFUi((void *)this, 0x10D);
    }
}

// FUNCTION: 0x001DF9A0 OnStopAttack__16ClockworkPuncherFv
void ClockworkPuncher::OnStopAttack() {
    if (m_unk163 != 2) {
        if (m_unk20 != 0xE) {
            SetState__15EntityBaseClassFi(this, 0);
        }
    }
}
