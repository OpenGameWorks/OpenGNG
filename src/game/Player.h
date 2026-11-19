#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

class Shield;
class PlingEffect;

class Player {
public:
    class PlayerData {
    public:
        char _pad000[0x7C];
    };

    int IsPauseDisabled();
    unsigned char IsHanging();
    unsigned char Ready2Clear();
    int CheckAbility(int arg0);
    int CheckDuplicate(int arg0);
    int ValidateItem(int arg0);
    void ForceDie(int arg0);
    void GetBoxer(int arg0);
    void GameVarSet(unsigned int arg0, int arg1);
    void AirSliceMove();
    void GuardHitMove();
    void CancelAttack(unsigned int arg0);
    void CancelMove();
    void GrimSlash2Move();
    void HammerDSlashMove();
    void ResetPling();
    void ResetShield();
    void SetShield(bool arg0);
    void SetShockwave(int arg0);
    void UpdatePlayerFx();
    void Kill();
    int GetGroundAction();
    void SetAction(int arg0);
    void SetMaximo(char arg0, bool arg1);
    void EnablePlayerShadow(bool arg0);
    void GetShieldPass(bool *arg0);
    void LandingMove();
    void BackToMaximo();
    void ShowPlayer(bool arg0);
    void RenderCutScene();
    void *IsMidasActive();
    void OutputDebug();
    int CheckHammer(bool arg0);
    void SavePlayerData(PlayerData *arg0);

    char _pad000[0x20];
    int m_unk20;            // 0x020
    char _pad024[0x38 - 0x24];
    int *m_unk38;           // 0x038 pointer, m_unk38[1] is written by AirSliceMove, m_unk38[0x42] (0x108) is read by Ready2Clear
    float *m_unk3C;         // 0x03C pointer, float at 0x34 is read by GrimSlash2Move, OutputDebug
    char _pad040[0x15C - 0x40];
    unsigned short m_unk15C; // 0x15C read by OutputDebug
    unsigned short m_unk15E; // 0x15E read by OutputDebug
    char _pad160[0x1B0 - 0x160];
    unsigned short m_unk1B0; // 0x1B0 bit 0x200 is tested by IsMidasActive
    char _pad1B2[0x1D0 - 0x1B2];
    int m_unk1D0;           // 0x1D0
    char _pad1D4[0x1DC - 0x1D4];
    int m_unk1DC;           // 0x1DC index into MaximoArmor, read by BackToMaximo
    char _pad1E0[0x210 - 0x1E0];
    int m_unk210;           // 0x210 state, IsMidasActive requires it to equal 1
    int m_unk214;           // 0x214 ground action code, read by GetShieldPass
    char _pad218[0x21C - 0x218];
    int m_unk21C;           // 0x21C cleared by SavePlayerData
    int m_unk220;          // 0x220 read by OutputDebug
    char _pad224[0x229 - 0x224];
    signed char m_unk229;   // 0x229 state byte, compared with 4 by BackToMaximo
    char _pad22A[0x23B - 0x22A];
    signed char m_unk23B[8]; // 0x23B list of 8 signed bytes, scanned by CheckHammer
    char _pad243[0x250 - 0x243];
    int m_unk250;           // 0x250
    void *m_unk254;         // 0x254 object whose byte 4 is the attack limit read by CancelMove
    char _pad258[0x260 - 0x258];
    int m_unk260;           // 0x260
    int m_unk264;           // 0x264
    char _pad268[0x284 - 0x268];
    int m_unk284;           // 0x284 object address with a vtable, Slot04 called by RenderCutScene; +0x40 is a PMat4 read by UpdatePlayerFx
    void *m_unk288;         // 0x288 PMNode *
    void *m_unk28C;         // 0x28C object with a vtable, Slot04 called by RenderCutScene
    char _pad290[0x2A4 - 0x290];
    Shield *m_unk2A4;       // 0x2A4 shield object, DeleteShield'd by ResetShield
    char _pad2A8[0x324 - 0x2A8];
    int m_unk324;           // 0x324
    char _pad328[0x32C - 0x328];
    PlingEffect *m_unk32C;  // 0x32C pling effect object, Slot00(1) called by ResetPling
    char _pad330[0x33B - 0x330];
    unsigned char m_unk33B; // 0x33B set to (arg0 == 0) by ShowPlayer
};

#endif
