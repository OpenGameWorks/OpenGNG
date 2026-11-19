#ifndef ENTITYBASECLASS_H
#define ENTITYBASECLASS_H

#include "types.h"

class AnimData;

class EntityBaseClass {
public:
    void DestroyDamageFx(unsigned int arg0);
    long long IsBGAnimating(unsigned int arg0);
    int MusicChangePrimary(unsigned int arg0, unsigned int arg1);
    float GetDistFromPlayer();
    void SetRenderPass(int arg0);
    int ChangedState();
    int FindCollision(EntityBaseClass *arg0);
    void RemovePhysicsAnimList();
    void AddPhysicsAnimList();
    void SetAnimData(AnimData *arg0);

    char _pad000[0x4];
    int m_unk04;                // 0x004
    char _pad008[0x18];
    int m_unk20;                // 0x020
    int m_unk24;                // 0x024
    char _pad028[0x14];
    char *m_unk3C;              // 0x03C
    char _pad040[0xC2];         // 0x040..0x101
    unsigned char m_unk102;     // 0x102 physics anim list flag
    char _pad103[0xD];          // 0x103..0x10F
    int m_unk110[10];           // 0x110..0x137
    char _pad138[0x58];         // 0x138..0x18F; MathAPI matrix block at 0x190
};

#endif
