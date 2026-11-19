#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

class Player {
public:
    int IsPauseDisabled();
    unsigned char IsHanging();
    unsigned char Ready2Clear();
    int CheckAbility(int arg0);
    int ValidateItem(int arg0);
    void ForceDie(int arg0);
    void GetBoxer(int arg0);
    void GameVarSet(unsigned int arg0, int arg1);
    void AirSliceMove();
    void GuardHitMove();
    void CancelAttack(unsigned int arg0);
    void GrimSlash2Move();
    void UpdatePlayerFx();
    void Kill();

    char _pad000[0x20];
    int m_unk20;            // 0x020
    char _pad024[0x38 - 0x24];
    int *m_unk38;           // 0x038 pointer, m_unk38[1] is written by AirSliceMove, m_unk38[0x42] (0x108) is read by Ready2Clear
    float *m_unk3C;         // 0x03C pointer, float at 0x34 is read by GrimSlash2Move
    char _pad040[0x1D0 - 0x40];
    int m_unk1D0;           // 0x1D0
    char _pad1D4[0x250 - 0x1D4];
    int m_unk250;           // 0x250
    char _pad254[0x260 - 0x254];
    int m_unk260;           // 0x260
    int m_unk264;           // 0x264
    char _pad268[0x284 - 0x268];
    int m_unk284;           // 0x284 base address of a PMat4 when 0x40 is added
    void *m_unk288;         // 0x288 PMNode *
};

#endif
