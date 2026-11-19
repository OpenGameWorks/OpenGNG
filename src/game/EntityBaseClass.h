#ifndef ENTITYBASECLASS_H
#define ENTITYBASECLASS_H

#include "types.h"

class AnimData;

class EntityBaseClass {
public:
    void DestroyDamageFx(unsigned int arg0);
    int MusicChangePrimary(unsigned int arg0, unsigned int arg1);
    float GetDistFromPlayer();
    int ChangedState();
    void SetAnimData(AnimData *arg0);

    char _pad000[0x20];
    int m_unk20;                // 0x020
    int m_unk24;                // 0x024
    char _pad028[0x14];
    char *m_unk3C;              // 0x03C
    char _pad040[0x150];        // 0x040..0x18F; MathAPI matrix block at 0x190
};

#endif
