#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

class Player {
public:
    int IsPauseDisabled();
    unsigned char IsHanging();
    int CheckAbility(int arg0);
    int ValidateItem(int arg0);
    void ForceDie(int arg0);
    void AirSliceMove();
    void Kill();

    char _pad000[0x20];
    int m_unk20;            // 0x020
    char _pad024[0x38 - 0x24];
    int *m_unk38;           // 0x038 pointer, m_unk38[1] is written by AirSliceMove
    char _pad03C[0x1D0 - 0x3C];
    int m_unk1D0;           // 0x1D0
    char _pad1D4[0x250 - 0x1D4];
    int m_unk250;           // 0x250
    char _pad254[0x260 - 0x254];
    int m_unk260;           // 0x260
    int m_unk264;           // 0x264
};

#endif
