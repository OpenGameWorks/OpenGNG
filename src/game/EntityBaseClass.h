#ifndef ENTITYBASECLASS_H
#define ENTITYBASECLASS_H

#include "types.h"

class AnimData;
class Physics;
class PMNode;

class EntityBaseClass {
public:
    // Enumerator values are not recovered yet; only the nested type name matters for linking.
    enum eHitObjectType { eHitObjectType_Unrecovered = 0 };
    enum eHitWeaponType { eHitWeaponType_Unrecovered = 0 };
    enum LoadClass { LoadClass_Unrecovered = 0 };

    void ProcessPhysics(float arg0, int arg1);
    void CheckDie(bool arg0);
    void DestroyDamageFx(unsigned int arg0);
    int ProcessHitBack();
    int ChangeDamageFxInterval(unsigned int arg0, float arg1);
    long long IsBGAnimating(unsigned int arg0);
    int MusicChangePrimary(unsigned int arg0, unsigned int arg1);
    void UpdateSulphurFx(float arg0);
    void FacePlayer(float arg0);
    void FaceHitDirection(EntityBaseClass *arg0);
    void ProcessMeshFade();
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
    void FlashTexture(unsigned int arg0, int arg1);
    void ResetCollisions();
    void UpdateShadowVolume();
    void FreezeCheck(EntityBaseClass *arg0, int arg1);
    void SetShadowVolume(float arg0);
    void SetFreeze(float arg0);
    void CreateHitMarkFx(float (*arg0)[4], eHitObjectType arg1, eHitWeaponType arg2, bool arg3);
    void OnInnocentAttack(EntityBaseClass *arg0, int arg1);
    void CheckVariable(int arg0, int arg1);
    void RequestAttack(EntityBaseClass *arg0, unsigned int arg1);
    void CreateFireDamageFx(float arg0);
    void InitLoadSystem();
    void RestoreOnWake();
    void FadeMesh(short arg0, short arg1, unsigned int arg2);
    int SkeletonCollision(PMNode *arg0, EntityBaseClass *arg1);
    int MeshNodeCollision(PMNode *arg0, float (*arg1)[2][4], float (&arg2)[4][4], unsigned char arg3);
    int PlaySequence(unsigned int *arg0);
    void ModifyLoadClass(LoadClass arg0);
    void LoadMesh(unsigned int arg0, bool arg1, bool arg2);
    void ResumeAmbientSoundsByObject();
    void StopSoundBySoundRef(unsigned int arg0);
    void ProcessSequence();

    char _pad000[0x4];
    int m_unk04;                // 0x004
    int m_unk08;                // 0x008
    char _pad00C[0x4];          // 0x00C..0x00F
    int m_unk10;                // 0x010
    int m_unk14;                // 0x014
    unsigned char m_unk18;      // 0x018
    unsigned char m_unk19;      // 0x019 active-load flag
    char _pad01A[0x5];          // 0x01A..0x01E
    unsigned char m_unk1F;      // 0x01F restore-on-wake flag
    int m_unk20;                // 0x020
    int m_unk24;                // 0x024 set to -2 on wake
    int m_unk28;                // 0x028 mesh argument for LoadMesh on wake
    int m_unk2C;                // 0x02C state restored on wake
    int m_unk30;                // 0x030 texture resource
    int m_unk34;                // 0x034 texture id
    Physics *m_unk38;           // 0x038
    char *m_unk3C;              // 0x03C
    char _pad040[0x90];         // 0x040..0x0CF
    signed char m_unkD0;        // 0x0D0
    char _padD1[0x1];           // 0x0D1
    short m_unkD2;              // 0x0D2
    char *m_unkD4;              // 0x0D4 sound/anim state block pointer
    float m_unkD8;              // 0x0D8
    float m_unkDC;              // 0x0DC
    float m_unkE0;              // 0x0E0 shadow volume scale
    char _padE4[0x4];           // 0x0E4..0x0E7
    signed char m_unkE8;        // 0x0E8
    char _pad0E9[0x7];          // 0x0E9..0x0EF
    float m_unkF0;              // 0x0F0
    int m_unkF4;                // 0x0F4 freeze timer
    char _pad0F8[0xA];          // 0x0F8..0x101
    unsigned char m_unk102;     // 0x102 physics anim list flag
    char _pad103[0xD];          // 0x103..0x10F
    int m_unk110[10];           // 0x110..0x137
    char _pad138[0x4];          // 0x138..0x13B
    int m_unk13C;               // 0x13C current sequence
    int m_unk140;               // 0x140 previous sequence
    int m_unk144;               // 0x144
    int m_unk148;               // 0x148
    int m_unk14C;               // 0x14C
    char _pad150[0x8];          // 0x150..0x157
    int m_unk158;               // 0x158 sound reference
    char _pad15C[0x2];          // 0x15C..0x15D
    unsigned short m_unk15E;    // 0x15E flag halfword
    unsigned char m_unk160;     // 0x160 sequence active flag
    unsigned char m_unk161;     // 0x161 BG anim list flag
    unsigned char m_unk162;     // 0x162 sequence flag
    unsigned char m_unk163;     // 0x163 cleared on wake
    char _pad164[0x2];          // 0x164..0x165
    unsigned char m_unk166;     // 0x166
    char _pad167[0x1];          // 0x167
    short m_unk168;             // 0x168
    char _pad16A[0x2];          // 0x16A..0x16B
    float m_unk16C;             // 0x16C
    float m_unk170;             // 0x170 mesh fade timer
    float m_unk174;             // 0x174 mesh fade accumulator
    unsigned char m_unk178;     // 0x178 mesh fade active flag
    char _pad179[0x17];         // 0x179..0x18F; MathAPI matrix block at 0x190
};

#endif
