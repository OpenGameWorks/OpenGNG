#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

class Shield;
class PlingEffect;
class FontNode;
class PMNode;
class PMeshNode;

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
    void ResurrectionMove();
    int SetPowerupMotion(int arg0);
    unsigned char IsHanging();
    unsigned char Ready2Clear();
    int CheckAbility(int arg0);
    int CheckDuplicate(int arg0);
    int ValidateItem(int arg0);
    void ForceDie(int arg0);
    void GetBoxer(int arg0);
    void GameVarSet(unsigned int arg0, int arg1);
    int GameVarSub(unsigned int arg0, int arg1);
    int MightyBlowCheck(unsigned int arg0);
    void AirSliceMove();
    void GrimSliceMove();
    void GuardHitMove();
    void StabDownMove();
    int CancelAttack(unsigned int arg0);
    void CancelMove();
    void GrimSlash2Move();
    void GrimAirSlashMove();
    void GrimIdleMove();
    void ComboTarget(float arg0, float arg1, bool arg2);
    void HammerDSlashMove();
    void HammerSliceMove();
    void ResetPling();
    void ResetShield();
    void SetFlyingShield(Shield *arg0);
    void SetShield(bool arg0);
    void SetShockwave(int arg0);
    void UpdatePlayerFx();
    void ResetEye(bool arg0);
    void Kill();
    void SetDeath();
    int GetGroundAction();
    int SetAction(int arg0);
    void SetMaximo(char arg0, bool arg1);
    void EnablePlayerShadow(bool arg0);
    void GetShieldPass(bool *arg0);
    void LandingMove();
    void RollMove();
    void BackToMaximo();
    void ShowPlayer(bool arg0);
    void RenderCutScene();
    void *IsMidasActive();
    void OutputDebug();
    int CheckHammer(bool arg0);
    void SavePlayerData(PlayerData *arg0);
    void InitAttachableJoints();
    void GetKeyMove();
    void CatchIdleMove();
    void SetHeadCamera(bool arg0);
    void UpdateKey();
    void CatchLedgeMove();
    void OpenChestMove();
    void Over3Move();
    void LoadPlayerData(PlayerData *arg0);
    int GetComboLevel();
    int MultipleAttack(unsigned short *arg0);
    void SetPlayerAttack(unsigned short arg0, unsigned short arg1);
    void NotifyTreasure(float (*arg0)[4], float arg1);
    PMNode *IsPlayerOnNode(PMeshNode *arg0, bool arg1);
    void SetBoundingSphere(PMNode *arg0, float arg1);

    char _pad000[0x20];
    int m_unk20;            // 0x020
    char _pad024[0x38 - 0x24];
    int *m_unk38;           // 0x038 pointer, m_unk38[1] is written by AirSliceMove, m_unk38[0x42] (0x108) is read by Ready2Clear
    float *m_unk3C;         // 0x03C pointer, float at 0x34 is read by GrimSlash2Move, OutputDebug
    char _pad040[0x103 - 0x40];
    unsigned char m_unk103; // 0x103 set to 0xFE by ForceDie
    char _pad104[0x15C - 0x104];
    unsigned short m_unk15C; // 0x15C read by OutputDebug
    unsigned short m_unk15E; // 0x15E read by OutputDebug
    char _pad160[0x190 - 0x160];
    float m_unk190[4];      // 0x190 vector read by NotifyTreasure when m_unk3C is null
    char _pad1A0[0x1B0 - 0x1A0];
    unsigned short m_unk1B0; // 0x1B0 bit 0x200 is tested by IsMidasActive
    unsigned short m_unk1B2; // 0x1B2 bit 0x4000 is tested by CatchIdleMove
    char _pad1B4[0x1BA - 0x1B4];
    unsigned short m_unk1BA; // 0x1BA nonzero keeps ReleaseCheck counting the caught state
    int m_unk1BC;          // 0x1BC compared with 0x32 and 0x64 by GetGroundAction
    char _pad1C0[0x1C4 - 0x1C0];
    float m_unk1C4;         // 0x1C4 set from Physics float 0x11C by CatchIdleMove
    char _pad1C8[0x1D0 - 0x1C8];
    int m_unk1D0;           // 0x1D0
    char _pad1D4[0x1D8 - 0x1D4];
    int m_unk1D8;           // 0x1D8 cleared by ForceDie
    int m_unk1DC;           // 0x1DC index into MaximoArmor, read by BackToMaximo
    char _pad1E0[0x1F8 - 0x1E0];
    int m_unk1F8;           // 0x1F8 remaining-lives counter, decremented by SetDeath
    int m_unk1FC;           // 0x1FC compared with 2 by MightyBlowCheck
    char _pad200[0x20C - 0x200];
    int m_unk20C;           // 0x20C compared with the MightyCost value by MightyBlowCheck
    int m_unk210;           // 0x210 state, IsMidasActive requires it to equal 1
    int m_unk214;           // 0x214 ground action code, read by GetShieldPass
    int m_unk218;           // 0x218 state, NotifyTreasure requires it to equal 1
    int m_unk21C;           // 0x21C cleared by SavePlayerData
    int m_unk220;          // 0x220 read by OutputDebug
    char _pad224[0x229 - 0x224];
    signed char m_unk229;   // 0x229 state byte, compared with 4 by BackToMaximo
    char _pad22A[0x23B - 0x22A];
    signed char m_unk23B[8]; // 0x23B list of 8 signed bytes, scanned by CheckHammer
    char _pad243[0x24C - 0x243];
    float m_unk24C;         // 0x24C read by Over3Move as the CreateOneshot scale
    int m_unk250;           // 0x250
    void *m_unk254;         // 0x254 object whose byte 4 is the attack limit read by CancelMove
    void *m_unk258;         // 0x258 AttackTable entry set by MultipleAttack
    char _pad25C[0x260 - 0x25C];
    int m_unk260;           // 0x260
    int m_unk264;           // 0x264
    signed char m_unk268;   // 0x268 cleared by GrimIdleMove
    char _pad269[0x26C - 0x269];
    signed char m_unk26C;   // 0x26C byte set by SetHeadCamera
    char _pad26D[0x27C - 0x26D];
    int m_unk27C;           // 0x27C index into the attack list walked by MultipleAttack
    char _pad280[0x284 - 0x280];
    int m_unk284;           // 0x284 object address with a vtable, Slot04 called by RenderCutScene; +0x40 is a PMat4 read by UpdatePlayerFx
    void *m_unk288;         // 0x288 PMNode *
    void *m_unk28C;         // 0x28C object with a vtable, Slot04 called by RenderCutScene
    char _pad290[0x2A4 - 0x290];
    Shield *m_unk2A4;       // 0x2A4 shield object, DeleteShield'd by ResetShield
    int m_unk2A8;           // 0x2A8 effect id stored by Over3Move from CreateOneshot
    char _pad2AC[0x2C0 - 0x2AC];
    unsigned int m_unk2C0;  // 0x2C0 apparition id passed to GetPtrToApparition by ReleaseCheck
    int m_unk2C4;           // 0x2C4 hit counter, incremented and passed to OnHitEvent by ReleaseCheck
    int m_unk2C8;           // 0x2C8 countdown, reset to CAUGHT_TIME by ReleaseCheck
    char _pad2CC[0x2F8 - 0x2CC];
    int m_unk2F8;           // 0x2F8 cleared by InitAttachableJoints
    char _pad2FC[0x308 - 0x2FC];
    int m_unk308;           // 0x308 cleared by SetDeath
    char _pad30C[0x31C - 0x30C];
    FontNode *m_unk31C;     // 0x31C font node, passed to FontManager::RemoveText and cleared by ForceDie
    char _pad320[0x324 - 0x320];
    int m_unk324;           // 0x324
    int m_unk328;           // 0x328 apparition id passed to GetPtrToApparition by OpenChestMove
    PlingEffect *m_unk32C;  // 0x32C pling effect object, Slot00(1) called by ResetPling
    char _pad330[0x335 - 0x330];
    signed char m_unk335;   // 0x335 flag, tested by SetPowerupMotion
    char _pad336[0x337 - 0x336];
    signed char m_unk337;   // 0x337 treasure proximity level (1 near, 2 far), set by NotifyTreasure
    char _pad338[0x33B - 0x338];
    unsigned char m_unk33B; // 0x33B set to (arg0 == 0) by ShowPlayer
    char _pad33C[0x344 - 0x33C];
    int m_unk344;           // 0x344 cleared by SetDeath
    char _pad348[0x360 - 0x348];
    struct BoundingSphere {
        PMNode *node;       // 0x00 owner, null when the slot is free
        float r2;           // 0x04 squared radius
    } m_unk360[4];          // 0x360 bounding spheres set by SetBoundingSphere
    char _pad380[0x23D0 - 0x380];
    signed char m_unk23D0;  // 0x23D0 cleared by InitAttachableJoints
    signed char m_unk23D1;  // 0x23D1 cleared by InitAttachableJoints
    char _pad23D2[2];
    int m_unk23D4;          // 0x23D4 set to 5 by InitAttachableJoints
};

#endif
