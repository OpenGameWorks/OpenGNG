#ifndef ENTITYBASECLASS_H
#define ENTITYBASECLASS_H

#include "types.h"

class AnimData;
class Physics;

class EntityBaseClass {
public:
    void ProcessPhysics(float arg0, int arg1);
    void CheckDie(bool arg0);
    void DestroyDamageFx(unsigned int arg0);
    long long IsBGAnimating(unsigned int arg0);
    int MusicChangePrimary(unsigned int arg0, unsigned int arg1);
    void UpdateSulphurFx(float arg0);
    void FacePlayer(float arg0);
    float GetDistFromPlayer();
    void SetRenderPass(int arg0);
    int ChangedState();
    void RotateTo(float arg0, float arg1);
    void RemoveCollision(EntityBaseClass *arg0);
    int FindCollision(EntityBaseClass *arg0);
    void RemovePhysicsAnimList();
    void AddPhysicsAnimList();
    void SetAnimData(AnimData *arg0);
    int AddToLoad();
    void RadiusAdjust(float arg0, float (*arg1)[4]);
    void RemoveFromBGAnimList();
    void AddToBGAnimList();
    void SetState(int arg0);
    void SetActiveLoad();

    char _pad000[0x4];
    int m_unk04;                // 0x004
    char _pad008[0x8];          // 0x008..0x00F
    int m_unk10;                // 0x010
    int m_unk14;                // 0x014
    unsigned char m_unk18;      // 0x018
    char _pad019[0x7];          // 0x019..0x01F
    int m_unk20;                // 0x020
    int m_unk24;                // 0x024
    char _pad028[0x10];         // 0x028..0x037
    Physics *m_unk38;           // 0x038
    char *m_unk3C;              // 0x03C
    char _pad040[0x90];         // 0x040..0x0CF
    signed char m_unkD0;        // 0x0D0
    char _padD1[0x17];          // 0x0D1..0x0E7
    signed char m_unkE8;        // 0x0E8
    char _pad0E9[0x19];         // 0x0E9..0x101
    unsigned char m_unk102;     // 0x102 physics anim list flag
    char _pad103[0xD];          // 0x103..0x10F
    int m_unk110[10];           // 0x110..0x137
    char _pad138[0x29];         // 0x138..0x160
    unsigned char m_unk161;     // 0x161 BG anim list flag
    char _pad162[0x2E];         // 0x162..0x18F; MathAPI matrix block at 0x190
};

#endif
