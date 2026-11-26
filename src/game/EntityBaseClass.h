#ifndef ENTITYBASECLASS_H
#define ENTITYBASECLASS_H

#include "types.h"

class AnimData;
class Physics;
class PMNode;
class PParticleSystem;
class PZinDamageFx;
class TriggerSystemWakeKillRec;
class PLightManager;
class Shadow;
class PResourceManager;
class EntityManager;
class PFrustrum;

class EntityBaseClass {
public:
    // Enumerator values are not recovered yet; only the nested type name matters for linking.
    enum eHitObjectType { eHitObjectType_Unrecovered = 0 };
    enum eHitWeaponType { eHitWeaponType_Unrecovered = 0 };
    enum LoadClass { LoadClass_Unrecovered = 0 };

    // Derived constructors name this base in a mem-initializer; CodeWarrior then stores the vtable once (Rain probe).
    EntityBaseClass(LoadClass eLoadClass, unsigned int nFlags);
    virtual ~EntityBaseClass();
    void EnableSleep(bool bA, bool bB);
    void ProcessPhysics(float arg0, int arg1);
    int CheckDie(bool arg0);
    int CheckSleep(bool arg0);
    int Render(PLightManager *arg0);
    void Animate(int arg0, float arg1);
    void DestroyDamageFx(unsigned int arg0);
    int ProcessHitBack();
    int ChangeDamageFxInterval(unsigned int arg0, float arg1);
    long long IsBGAnimating(unsigned int arg0);
    void TriggerBGAnim(unsigned int arg0, int arg1, bool arg2, unsigned int arg3, TriggerSystemWakeKillRec *arg4);
    void TriggerBGAnim(unsigned int arg0, int arg1, bool arg2, unsigned int arg3);
    int MusicChangePrimary(unsigned int arg0, unsigned int arg1);
    void MusicSwitchToPrimary(unsigned int arg0);
    void MusicSwitchToSecondary(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3);
    static void *ApparitionIsValid(unsigned int arg0);
    static void *InstanceIsValid(unsigned int arg0);
    void UpdateSulphurFx(float arg0);
    void UpdateRipple(float arg0, unsigned int arg1, bool arg2);
    void FacePlayer(float arg0);
    void FaceHitDirection(EntityBaseClass *arg0);
    void ProcessMeshFade();
    void SetupInnocentCamera();
    float GetDistFromPlayer();
    void SetRenderPass(int arg0);
    int ChangedState();
    void RotateTo(float arg0, float arg1);
    void AddCollision(EntityBaseClass *arg0);
    void RemoveCollision(EntityBaseClass *arg0);
    int FindCollision(EntityBaseClass *arg0);
    void CollisionCheck(EntityBaseClass *arg0);
    void RemovePhysicsAnimList();
    void AddPhysicsAnimList();
    void SetAnimData(AnimData *arg0);
    int AddToLoad();
    void RadiusAdjust(float arg0, float (*arg1)[4]);
    void RemoveFromBGAnimList();
    void AddToBGAnimList();
    void SetState(int arg0);
    void SetActiveLoad();
    void FreeActiveLoad();
    void FlashTexture(unsigned int arg0, int arg1);
    void ResetCollisions();
    void UpdateShadowVolume();
    void FreezeCheck(EntityBaseClass *arg0, int arg1);
    void SetShadowVolume(float arg0);
    void SetFreeze(float arg0);
    int PlaySound(unsigned int arg0);
    int PlaySoundUbiquitous(unsigned int arg0);
    int PlaySoundOnFrame(unsigned int arg0, unsigned int arg1);
    void CreateHitMarkFx(float (*arg0)[4], eHitObjectType arg1, eHitWeaponType arg2, bool arg3);
    void CreateSplash(float arg0, bool arg1, bool arg2);
    EntityBaseClass *SpawnPickups(int arg0, int arg1, float (*arg2)[4], bool arg3);
    void SpawnBonus(float *arg0, int arg1, int arg2);
    void OnInnocentAttack(EntityBaseClass *arg0, int arg1);
    PZinDamageFx *CreateDamageFx(float arg0, unsigned int arg1);
    void ShakeScreen(int arg0, int arg1, int arg2, int arg3, float arg4, int arg5);
    void CheckVariable(int arg0, int arg1);
    void RequestAttack(EntityBaseClass *arg0, unsigned int arg1);
    void CreateFireDamageFx(float arg0);
    void InitLoadSystem();
    static void InitStatic(PResourceManager *arg0, EntityManager *arg1, PFrustrum *arg2);
    void RestoreOnWake();
    int WantsToWake();
    void FadeMesh(short arg0, short arg1, unsigned int arg2);
    int SkeletonCollision(PMNode *arg0, EntityBaseClass *arg1);
    int MeshNodeCollision(PMNode *arg0, float (*arg1)[2][4], float (&arg2)[4][4], unsigned char arg3);
    int SkeletonCollision(PMNode *arg0, float (*arg1)[2][4], float (&arg2)[4][4], unsigned char arg3);
    int MeshNodeCollision(PMNode *arg0, EntityBaseClass *arg1);
    int PlaySequence(unsigned int *arg0);
    void ModifyLoadClass(LoadClass arg0);
    int LoadMesh(unsigned int arg0, bool arg1, bool arg2);
    int LoadAnim(unsigned int arg0, bool arg1);
    void ResumeAmbientSoundsByObject();
    void PauseAmbientSoundsByObject();
    void StopSoundBySoundRef(unsigned int arg0);
    void StopAmbientSoundsByObject();
    void StopAllSoundsByObject();
    void RemoveFromAttackSystem();
    void ProcessSequence();
    char ReadApparitionData(int arg0, unsigned int arg1);
    void WriteApparitionData(int arg0, char arg1, unsigned int arg2);

    int m_unk04;                // 0x004 (0x000 holds the vptr from the virtual destructor)
    int m_unk08;                // 0x008
    char _pad00C[0x4];          // 0x00C..0x00F
    int m_unk10;                // 0x010
    int m_unk14;                // 0x014
    unsigned char m_unk18;      // 0x018
    unsigned char m_unk19;      // 0x019 active-load flag
    unsigned char m_unk1A;      // 0x01A
    char _pad01B[0x4];          // 0x01B..0x01E
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
    unsigned char m_unkD0;      // 0x0D0
    bool m_unkD1;               // 0x0D1
    short m_unkD2;              // 0x0D2
    char *m_unkD4;              // 0x0D4 sound/anim state block pointer
    float m_unkD8;              // 0x0D8
    float m_unkDC;              // 0x0DC
    float m_unkE0;              // 0x0E0 shadow volume scale
    char _padE4[0x4];           // 0x0E4..0x0E7
    signed char m_unkE8;        // 0x0E8
    char _pad0E9[0x2];          // 0x0E9..0x0EA
    unsigned char m_unkEB;      // 0x0EB freeze enabled flag
    float m_unkEC;              // 0x0EC freeze value
    float m_unkF0;              // 0x0F0
    PParticleSystem *m_unkF4;   // 0x0F4 frozen particle system
    float m_unkF8;              // 0x0F8 frozen fx x
    float m_unkFC;              // 0x0FC frozen fx y
    unsigned char m_unk100;     // 0x100
    unsigned char m_unk101;     // 0x101
    unsigned char m_unk102;     // 0x102 physics anim list flag
    unsigned char m_unk103;     // 0x103 collision group
    float m_unk104;             // 0x104 collision radius
    float m_unk108;             // 0x108 collision radius (second)
    unsigned int m_unk10C;      // 0x10C collision flags
    int m_unk110[10];           // 0x110..0x137
    int m_unk138;               // 0x138 last frame value for PlaySoundOnFrame
    int m_unk13C;               // 0x13C current sequence
    int m_unk140;               // 0x140 previous sequence
    int m_unk144;               // 0x144
    int m_unk148;               // 0x148
    int m_unk14C;               // 0x14C
    int m_unk150;               // 0x150 mesh id loaded by LoadMesh
    int m_unk154;               // 0x154 animation argument
    int m_unk158;               // 0x158 sound reference
    unsigned short m_unk15C;    // 0x15C
    unsigned short m_unk15E;    // 0x15E flag halfword
    unsigned char m_unk160;     // 0x160 sequence active flag
    unsigned char m_unk161;     // 0x161 BG anim list flag
    unsigned char m_unk162;     // 0x162 sequence flag
    unsigned char m_unk163;     // 0x163 cleared on wake
    unsigned char m_unk164;     // 0x164
    char _pad165[0x1];          // 0x165
    unsigned char m_unk166;     // 0x166
    signed char m_unk167;       // 0x167 nonzero while freeze value is active
    short m_unk168;             // 0x168
    char _pad16A[0x2];          // 0x16A..0x16B
    float m_unk16C;             // 0x16C
    float m_unk170;             // 0x170 mesh fade timer
    float m_unk174;             // 0x174 mesh fade accumulator
    unsigned char m_unk178;     // 0x178 mesh fade active flag
    char _pad179[0x2];          // 0x179..0x17A
    unsigned char m_unk17B;     // 0x17B ShakeScreen active flag
    int m_unk17C;               // 0x17C ShakeScreen frame that triggered
    char _pad180[0x6];          // 0x180..0x185
    unsigned char m_unk186;     // 0x186 ability/spawn enable flag
    unsigned char m_unk187;     // 0x187 combo bonus flag
    unsigned char m_unk188;     // 0x188
    char _pad189[0x7];          // 0x189..0x18F; vec4 at 0x190 is reached through a cast
};

#endif
