#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

class Shield;
class PlingEffect;
class FontNode;
class PMNode;
class PMeshNode;
class PMat4;
class EntityBaseClass;
class GunTurret;
class PSkeleton;
class PLightManager;

class Player {
public:
    class PlayerData {
    public:
        char _pad000[0x7C];
    };

    int IsPauseDisabled();
    int IsPlayerOnAnimNode(unsigned int arg0);
    int ReleaseCheck();
    void PumpkinGrabMove();
    void AdjustPosition(EntityBaseClass *arg0, EntityBaseClass *arg1, float arg2, float arg3, float arg4);
    void AdjustPositionOfAttacker(EntityBaseClass *arg0, EntityBaseClass *arg1, float arg2, float arg3, float arg4);
    void ResurrectionMove();
    void UnlockGateMove();
    void UnlockChestMove();
    void AlignPosition(EntityBaseClass *arg0);
    int SetPowerupMotion(int arg0);
    unsigned char IsHanging();
    unsigned char Ready2Clear();
    int CheckAbility(int arg0);
    int CheckDuplicate(int arg0);
    int ValidateItem(int arg0);
    void FillItems(int *arg0, bool arg1);
    void ForceDie(int arg0);
    void GetBoxer(int arg0);
    void SwapAbility(int arg0);
    void SetSword();
    void GameVarSet(unsigned int arg0, int arg1);
    int GameVarSub(unsigned int arg0, int arg1);
    int MightyBlowCheck(unsigned int arg0);
    void AirSliceMove();
    void AirOverheadMove();
    void GrimSliceMove();
    void GuardHitMove();
    void StabDownMove();
    int CancelAttack(unsigned int arg0);
    void CancelMove();
    void GrimProjectileMove();
    void GrimSlash2Move();
    void GrimSlashMove();
    void GrimAirSlashMove();
    void GrimIdleMove();
    void GrimMove();
    void GrimRunMove();
    void ComboTarget(float arg0, float arg1, bool arg2);
    void HammerDSlashMove();
    void HammerSliceMove();
    void HammerSlashMove();
    void SwimMove();
    enum PlingType { PLING_TYPE_UNUSED = 0 };
    void SetPling(PlingType arg0, EntityBaseClass *arg1, unsigned int arg2);
    void ResetPling();
    void ResetShield();
    void InitCutScene();
    void SetFlyingShield(Shield *arg0);
    void SetShield(bool arg0);
    void SetShockwave(int arg0);
    void UpdatePlayerFx();
    void ResetEye(bool arg0);
    void Kill();
    void SetDeath();
    void DieMove();
    void UpwardStrikeMove();
    int SpinCheck();
    int GetGroundAction();
    int SetAction(int arg0);
    void SetMaximo(char arg0, bool arg1);
    void EnablePlayerShadow(bool arg0);
    void GetShieldPass(bool *arg0);
    void LandingMove();
    void JogLandMove();
    void JumpMove();
    void StandMove();
    void RollMove();
    int EndAction();
    void BackToMaximo();
    void ShowPlayer(bool arg0);
    void RenderCutScene();
    void Animate(int arg0, float arg1);
    void *IsMidasActive();
    void OutputDebug();
    int CheckHammer(bool arg0);
    void SavePlayerData(PlayerData *arg0);
    void InitAttachableJoints();
    void RefreshAttachableJoints();
    void SetAbilityAction(PSkeleton *arg0, int arg1, int arg2);
    int AnimationViewer(int arg0);
    void UpdateBodyBox();
    void CyclockDamageMove();
    void MBlowMove();
    void AirSlash2Move();
    void AirSlashMove();
    void GetKeyMove();
    void DialogMove();
    void GrabObjectMove();
    void CatchIdleMove();
    void SetHeadCamera(bool arg0);
    void ReleaseHeadCamera();
    void UpdateKey();
    void UpdateDisplayList();
    void CatchLedgeMove();
    void ArmorUpMove();
    void CatchUpMove();
    void OpenDoorMove();
    void OpenChestMove();
    void Over3Move();
    void LoadPlayerData(PlayerData *arg0);
    static void ResetPlayerData(PlayerData *arg0);
    int GetComboLevel();
    int MultipleAttack(unsigned short *arg0);
    void FootStepSound(unsigned short *arg0);
    void SetPlayerAttack(unsigned short arg0, unsigned short arg1);
    void NotifyTreasure(float (*arg0)[4], float arg1);
    void SetProbe(float (*arg0)[4], float arg1);
    PMNode *IsPlayerOnNode(PMeshNode *arg0, bool arg1);
    void SetBoundingSphere(PMNode *arg0, float arg1);
    void DetachJoint(int arg0);
    void FreeJoint(int arg0);
    int FindCurrentItem(int arg0, bool arg1);
    signed char GetAbility();
    void GetAttachableJointOffsets(int arg0, float (*arg1)[4]);
    int GetAttachableJoint(int arg0);
    void FinishCutCamera(float (*arg0)[4]);
    void DuckLaunchMove();
    void MBlow2Move();
    void SpinSlashMove();
    void HSpinMove();
    void Spin360Move();
    void CSliceMove();
    void SliceMove();
    void GunDeckMove();
    int GuardCheck(EntityBaseClass *arg0);

    char _pad000[0x20];
    int m_unk20;            // 0x020
    char _pad024[0x38 - 0x24];
    int *m_unk38;           // 0x038 pointer, m_unk38[1] is written by AirSliceMove, m_unk38[0x42] (0x108) is read by Ready2Clear
    float *m_unk3C;         // 0x03C pointer, float at 0x34 is read by GrimSlash2Move, OutputDebug
    char _pad040[0x50 - 0x40];
    int m_unk50;            // 0x050 set to -1.0f bits (0xBF800000) by Render
    char _pad054[0x70 - 0x54];
    int m_unk70;            // 0x070 set to 1.0f bits (0x3F800000) by Render
    char _pad074[0x80 - 0x74];
    u_long128 m_unk80;      // 0x080 copy of the m_unk380 vector by Render
    char _pad090[0xD0 - 0x90];
    signed char m_unkD0;    // 0x0D0 set to 1 by Render
    char _padD1[0xD4 - 0xD1];
    void *m_unkD4;          // 0x0D4 shadow object, byte 0 set by EnablePlayerShadow, +0xC holds a sub-object
    char _padD8[0x103 - 0xD8];
    unsigned char m_unk103; // 0x103 set to 0xFE by ForceDie
    char _pad104[0x10C - 0x104];
    int m_unk10C;           // 0x10C flags word, bit 0x01000000 cleared by CyclockDamageMove
    char _pad110[0x15C - 0x110];
    unsigned short m_unk15C; // 0x15C read by OutputDebug
    unsigned short m_unk15E; // 0x15E read by OutputDebug
    char _pad160[0x190 - 0x160];
    float m_unk190[4];      // 0x190 vector read by NotifyTreasure when m_unk3C is null
    char _pad1A0[0x1B0 - 0x1A0];
    unsigned short m_unk1B0; // 0x1B0 bit 0x200 is tested by IsMidasActive
    unsigned short m_unk1B2; // 0x1B2 bit 0x4000 is tested by CatchIdleMove
    signed char m_unk1B4;   // 0x1B4 compared against -74 and 75 by SpinCheck
    signed char m_unk1B5;   // 0x1B5 compared against -74 and 75 by SpinCheck
    signed char m_unk1B6;   // 0x1B6 cleared by DialogMove
    signed char m_unk1B7;   // 0x1B7 cleared by DialogMove
    char _pad1B8[0x1BA - 0x1B8];
    unsigned short m_unk1BA; // 0x1BA nonzero keeps ReleaseCheck counting the caught state
    int m_unk1BC;          // 0x1BC compared with 0x32 and 0x64 by GetGroundAction
    short m_unk1C0;         // 0x1C0 signed halfword read by SlashMove
    char _pad1C2[0x1C4 - 0x1C2];
    float m_unk1C4;         // 0x1C4 set from Physics float 0x11C by CatchIdleMove
    float m_unk1C8;         // 0x1C8 running float, updated by JogLandMove
    char _pad1CC[0x1D0 - 0x1CC];
    int m_unk1D0;           // 0x1D0
    int m_unk1D4;           // 0x1D4 compared against m_unk1DC by GetAbility
    int m_unk1D8;           // 0x1D8 cleared by ForceDie
    int m_unk1DC;           // 0x1DC index into MaximoArmor, read by BackToMaximo
    char _pad1E0[0x1F0 - 0x1E0];
    int m_unk1F0;           // 0x1F0 count of key-slot meshes, read by UpdateKey
    int m_unk1F4;           // 0x1F4 flag, UpdateKey takes the first key mesh when set
    int m_unk1F8;           // 0x1F8 remaining-lives counter, decremented by SetDeath
    int m_unk1FC;           // 0x1FC compared with 2 by MightyBlowCheck
    char _pad200[0x20C - 0x200];
    int m_unk20C;           // 0x20C compared with the MightyCost value by MightyBlowCheck
    int m_unk210;           // 0x210 state, IsMidasActive requires it to equal 1
    int m_unk214;           // 0x214 ground action code, read by GetShieldPass
    int m_unk218;           // 0x218 state, NotifyTreasure requires it to equal 1
    int m_unk21C;           // 0x21C cleared by SavePlayerData
    int m_unk220;          // 0x220 read by OutputDebug
    int m_unk224;           // 0x224 bitmask of owned items, tested by FillItems
    char _pad228[0x229 - 0x228];
    signed char m_unk229;   // 0x229 state byte, compared with 4 by BackToMaximo
    signed char m_unk22A;   // 0x22A previous ability id, stored by SwapAbility
    char _pad22B[0x23B - 0x22B];
    signed char m_unk23B[8]; // 0x23B list of 8 signed bytes, scanned by CheckHammer
    char _pad243[0x24C - 0x243];
    float m_unk24C;         // 0x24C read by Over3Move as the CreateOneshot scale
    int m_unk250;           // 0x250
    void *m_unk254;         // 0x254 object whose byte 4 is the attack limit read by CancelMove
    void *m_unk258;         // 0x258 AttackTable entry set by MultipleAttack
    void *m_unk25C;         // 0x25C table pointer, 8-byte entries read by JogLandMove
    int m_unk260;           // 0x260
    int m_unk264;           // 0x264
    signed char m_unk268;   // 0x268 cleared by GrimIdleMove
    char _pad269[0x26B - 0x269];
    unsigned char m_unk26B; // 0x26B tested by DialogMove
    unsigned char m_unk26C; // 0x26C byte set by SetHeadCamera
    char _pad26D[0x270 - 0x26D];
    int m_unk270;           // 0x270 spin state, read and written by SpinCheck
    char _pad274[0x278 - 0x274];
    int m_unk278;           // 0x278 spin state, read and written by SpinCheck
    int m_unk27C;           // 0x27C index into the attack list walked by MultipleAttack
    char _pad280[0x284 - 0x280];
    int m_unk284;           // 0x284 object address with a vtable, Slot04 called by RenderCutScene; +0x40 is a PMat4 read by UpdatePlayerFx
    void *m_unk288;         // 0x288 PMNode *
    void *m_unk28C;         // 0x28C object with a vtable, Slot04 called by RenderCutScene
    char _pad290[0x298 - 0x290];
    PMNode *m_unk298[3];    // 0x298 key-slot PMNodes, updated by UpdateKey
    Shield *m_unk2A4;       // 0x2A4 shield object, DeleteShield'd by ResetShield
    int m_unk2A8;           // 0x2A8 effect id stored by Over3Move from CreateOneshot
    unsigned int m_unk2AC;  // 0x2AC effect id, EffectValid and DeleteEffect by InitCutScene
    unsigned int m_unk2B0;  // 0x2B0 apparition id, GetPtrToApparition and Projectile::Delete by InitCutScene
    unsigned int m_unk2B4;  // 0x2B4 sound ref, StopSoundBySoundRef by InitCutScene
    void *m_unk2B8;         // 0x2B8 sound ref, StopSoundBySoundRef by ~Player
    char _pad2BC[4];
    unsigned int m_unk2C0;  // 0x2C0 apparition id passed to GetPtrToApparition by ReleaseCheck
    int m_unk2C4;           // 0x2C4 hit counter, incremented and passed to OnHitEvent by ReleaseCheck
    int m_unk2C8;           // 0x2C8 countdown, reset to CAUGHT_TIME by ReleaseCheck
    char _pad2CC[0x2D0 - 0x2CC];
    float m_unk2D0[4];      // 0x2D0 vector, source of sceVu0ApplyMatrix in CatchLedgeMove
    float m_unk2E0[4];      // 0x2E0 vector, source of sceVu0ApplyMatrix in CatchLedgeMove
    int m_unk2F0;           // 0x2F0 matrix holder, +0x40 is the matrix used by CatchLedgeMove
    char _pad2F4[0x2F8 - 0x2F4];
    int m_unk2F8;           // 0x2F8 cleared by InitAttachableJoints
    float m_unk2FC;         // 0x2FC attached timer value, set by DetachJoint
    char _pad300[0x308 - 0x300];
    int m_unk308;           // 0x308 cleared by SetDeath
    char _pad30C[0x31C - 0x30C];
    FontNode *m_unk31C;     // 0x31C font node, passed to FontManager::RemoveText and cleared by ForceDie
    char _pad320[0x324 - 0x320];
    int m_unk324;           // 0x324
    int m_unk328;           // 0x328 apparition id passed to GetPtrToApparition by OpenChestMove
    PlingEffect *m_unk32C;  // 0x32C pling effect object, Slot00(1) called by ResetPling
    GunTurret *m_unk330;    // 0x330 gun turret object, Slot58 and SetGunParams called by GunDeckMove
    unsigned char m_unk334; // 0x334 set to 1 or 0 by SetPling when a pling effect is created
    signed char m_unk335;   // 0x335 flag, tested by SetPowerupMotion
    char _pad336[0x337 - 0x336];
    signed char m_unk337;   // 0x337 treasure proximity level (1 near, 2 far), set by NotifyTreasure
    char _pad338[0x33B - 0x338];
    unsigned char m_unk33B; // 0x33B set to (arg0 == 0) by ShowPlayer
    char _pad33C[0x340 - 0x33C];
    int m_unk340;           // 0x340 idle timer, set and decremented by StandMove
    int m_unk344;           // 0x344 cleared by SetDeath
    char _pad348[0x350 - 0x348];
    float m_unk350[4];      // 0x350 probe vector, set by SetProbe
    struct BoundingSphere {
        PMNode *node;       // 0x00 owner, null when the slot is free
        float r2;           // 0x04 squared radius
    } m_unk360[4];          // 0x360 bounding spheres set by SetBoundingSphere
    float m_unk380[4];      // 0x380 vector; [0] is advanced by m_unk23C0 in Render
    char _pad390[0x23C0 - 0x390];
    float m_unk23C0;        // 0x23C0 float step added to m_unk380 in Render
    char _pad23C4[0x23C8 - 0x23C4];
    void *m_unk23C8;        // 0x23C8 shadow object, cleared or set by EnablePlayerShadow
    void *m_unk23CC;        // 0x23CC shadow object, cleared or set by EnablePlayerShadow
    signed char m_unk23D0;  // 0x23D0 cleared by InitAttachableJoints
    signed char m_unk23D1;  // 0x23D1 cleared by InitAttachableJoints
    char _pad23D2[2];
    int m_unk23D4;          // 0x23D4 set to 5 by InitAttachableJoints
    void FinishCutScene(PMeshNode *arg0, PMat4 *arg1, int arg2);
    void GrimAirAttackMove();
    void SlashMove();
    void GrimJumpMove();
    void GrimThrowMove();
    void SphereCheck();
    void OnTriggerCheck();
    int Render(PLightManager *pLightMgr);
    ~Player();
};

#endif
