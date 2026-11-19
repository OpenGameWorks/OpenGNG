#include "Player.h"

// TODO(header): foreign declarations
extern unsigned char gEng[];
class Interface {
public:
    char _pad000[0x10];
    void AddAbility(int arg0);
};
extern Interface gInterface;
extern signed char AbilityTable[];
class EntityBaseClass {
public:
    int ProcessHitBack();
    void SetState(int arg0);
    void PlaySound(unsigned int arg0);
};
extern signed char MaximoArmor[8];
class CutSceneObject {
public:
    virtual void Slot00();
    virtual void Slot04(int arg0, int arg1, int arg2);
};
class Shield {
public:
    void DeleteShield();
};
class PlingEffect {
public:
    virtual void Slot00(int arg0);
};
class PMat4;
class PMNode {
public:
    void ProcessFxTriggers(float arg0, PMat4 *arg1, bool arg2, bool arg3);
    void EnableFx(bool arg0, bool arg1);
};

// FUNCTION: 0x00158F60 Ready2Clear__6PlayerFv
unsigned char Player::Ready2Clear() {
    if (m_unk264 & 0x32) {
        int r = (m_unk1D0 & 4) != 0;
        if (r == 0) {
            r = (m_unk38[0x42] & 1) != 0;
        }
        return r & 0xFF;
    }
    return 0;
}

// FUNCTION: 0x00159030 IsPauseDisabled__6PlayerFv
int Player::IsPauseDisabled() {
    int ret = (m_unk264 & 0x808) != 0;
    if (ret == 0) {
        ret = m_unk20 != 0;
    }
    if (ret == 0) {
        ret = gEng[0x19A18] != 0;
    }
    return ret;
}

// note: 8 words differ: original keeps the loaded value in v1 and the 1 in v0 before the 0x2A compare; compiled code loads into a0 and uses daddiu. Tried bool, ||, nested if/else and unsigned char locals.
// DRAFT: 0x0015A4B0 IsHanging__6PlayerFv
unsigned char Player::IsHanging() {
    int state = m_unk260;
    int ret = 1;
    if (state != 0x2A) {
        if (state != 0x2B) {
            ret = 0;
        }
    }
    return ret;
}

// FUNCTION: 0x0015A7F0 ValidateItem__6PlayerFi
int Player::ValidateItem(int arg0) {
    int result = arg0;
    if (CheckAbility(arg0) != -1) {
        result = -1;
    }
    return result;
}

// FUNCTION: 0x0015A830 CheckDuplicate__6PlayerFi
int Player::CheckDuplicate(int arg0) {
    int i = 0;
    char *p = (char *)this + AbilityTable[arg0 * 16 + 5] * 8 + 0x22B;
    do {
        int c = *p;
        p++;
        if (c == arg0) {
            return 1;
        }
        i++;
    } while (i < 8);
    return 0;
}

// FUNCTION: 0x0015AEE0 GetBoxer__6PlayerFi
void Player::GetBoxer(int arg0) {
    GameVarSet(0x11, arg0 - 0x15);
    gInterface.AddAbility(arg0);
}

// FUNCTION: 0x0015C090 ResetShield__6PlayerFv
void Player::ResetShield() {
    if (m_unk2A4 != 0) {
        m_unk2A4->DeleteShield();
        ((EntityBaseClass *)m_unk2A4)->SetState(-2);
        m_unk2A4 = 0;
        SetShield(true);
    }
}

// note: 12 words differ: original tests m_unk250 with beqz into the body and exits via b with ld ra in the delay slot; compiled code emits bnez to the shared exit. Tried nested if, inner early return and && forms, all 12 words.
// DRAFT: 0x0015C4F0 GuardHitMove__6PlayerFv
void Player::GuardHitMove() {
    if (m_unk250 != 0) {
        return;
    }
    if (((EntityBaseClass *)this)->ProcessHitBack() == 0) {
        m_unk250 = 1;
    }
}

// FUNCTION: 0x0015DA80 HammerDSlashMove__6PlayerFv
void Player::HammerDSlashMove() {
    if (m_unk250 == 0 && (int)m_unk3C[13] > 0x14) {
        m_unk250 = 1;
        SetShockwave(10);
    }
}

// FUNCTION: 0x0015DC20 CancelMove__6PlayerFv
void Player::CancelMove() {
    if ((int)m_unk3C[13] >= ((unsigned char *)m_unk254)[4]) {
        CancelAttack(0x30);
    }
}

// note: 10 words differ: original branches to the body on beqz and skips it with an unthreaded b to the epilogue; compiled code threads that into bnez. Tried the early-return form and an empty-then if/else, both threaded the same way.
// DRAFT: 0x0015E250 AirSliceMove__6PlayerFv
void Player::AirSliceMove() {
    if (m_unk250 == 0) {
        m_unk250 = 1;
        m_unk38[1] = 0x3A83126F;
    }
}

// FUNCTION: 0x0015E970 GrimSlash2Move__6PlayerFv
void Player::GrimSlash2Move() {
    if ((int)m_unk3C[13] >= 0x32) {
        CancelAttack(0x30);
    }
}

// note: 2 words differ: the move of this into a0 lands in the beq delay slot instead of the jal delay slot. Tried nested ifs, early return, reordered operands and swapped != form (3 lines).
// DRAFT: 0x0015F770 LandingMove__6PlayerFv
void Player::LandingMove() {
    int action = GetGroundAction();
    if (action != 0xA && action != 0 && action != m_unk260) {
        SetAction(action);
    }
}

// note: 16 words differ: original keeps the constant 1 in v0 for the 0x9F path and loads 2/0 into v0 for the others; compiled code uses a2. Tried if/else chain (16 lines), int idx = 1 (about 14, branch layout differs).
// DRAFT: 0x00160090 GetShieldPass__6PlayerFPb
void Player::GetShieldPass(bool *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 1;
    int idx = 0;
    if (m_unk214 == 0x6A) {
        idx = 2;
    } else if (m_unk214 == 0x9F) {
        idx = 1;
    }
    arg0[idx] = 1;
}

// note: 4 words differ: original keeps the loaded pointer in a1 and passes it as a0 for the call; compiled code keeps it in t0. Tried void * and int locals; int does not compile, void * still 4 words.
// DRAFT: 0x001601F0 UpdatePlayerFx__6PlayerFv
void Player::UpdatePlayerFx() {
    PMNode *temp_a1 = (PMNode *)m_unk288;
    if (temp_a1 != 0) {
        temp_a1->ProcessFxTriggers(1.0f, (PMat4 *)(m_unk284 + 0x40), false, false);
    }
}

// FUNCTION: 0x00163930 BackToMaximo__6PlayerFv
void Player::BackToMaximo() {
    if (m_unk229 == 4) {
        SetMaximo(MaximoArmor[m_unk1DC], false);
        ((EntityBaseClass *)this)->PlaySound(0x119);
    }
}

// FUNCTION: 0x00163F80 ShowPlayer__6PlayerFb
void Player::ShowPlayer(bool arg0) {
    m_unk33B = !arg0;
    EnablePlayerShadow(arg0);
    PMNode *temp = (PMNode *)m_unk288;
    if (temp != 0) {
        temp->EnableFx(arg0, true);
    }
}

// FUNCTION: 0x00164050 RenderCutScene__6PlayerFv
void Player::RenderCutScene() {
    ((CutSceneObject *)m_unk28C)->Slot04(0, 0x80, 0);
    ((CutSceneObject *)m_unk284)->Slot04(0, 0x80, 0);
}

// FUNCTION: 0x00164770 ResetPling__6PlayerFv
void Player::ResetPling() {
    m_unk324 = 0;
    PlingEffect *t = m_unk32C;
    if (t != 0) {
        if (t != 0) {
            t->Slot00(1);
        }
        m_unk32C = 0;
    }
}

// FUNCTION: 0x00165B60 Kill__6PlayerFv
void Player::Kill() {
    if (m_unk1D0 & 1) {
        ForceDie(0x1A);
    }
}
