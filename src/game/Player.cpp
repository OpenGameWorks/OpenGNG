#include "Player.h"

// TODO(header): foreign declarations
extern unsigned char gEng[];
class Interface {
public:
    char _pad000[0x10];
    void AddAbility(int arg0);
};
extern Interface gInterface;
class EntityBaseClass {
public:
    int ProcessHitBack();
};
class PMat4;
class PMNode {
public:
    void ProcessFxTriggers(float arg0, PMat4 *arg1, bool arg2, bool arg3);
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

// FUNCTION: 0x0015AEE0 GetBoxer__6PlayerFi
void Player::GetBoxer(int arg0) {
    GameVarSet(0x11, arg0 - 0x15);
    gInterface.AddAbility(arg0);
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

// note: 4 words differ: original keeps the loaded pointer in a1 and passes it as a0 for the call; compiled code keeps it in t0. Tried void * and int locals; int does not compile, void * still 4 words.
// DRAFT: 0x001601F0 UpdatePlayerFx__6PlayerFv
void Player::UpdatePlayerFx() {
    PMNode *temp_a1 = (PMNode *)m_unk288;
    if (temp_a1 != 0) {
        temp_a1->ProcessFxTriggers(1.0f, (PMat4 *)(m_unk284 + 0x40), false, false);
    }
}

// FUNCTION: 0x00165B60 Kill__6PlayerFv
void Player::Kill() {
    if (m_unk1D0 & 1) {
        ForceDie(0x1A);
    }
}
