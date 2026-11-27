// FLAGS: -str readonly
#include "Player.h"
#include "Debug.h"
#include "PResourceManager.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void EnableFx__6PMNodeFbb(void *pNode, int a, int b);
extern "C" int LoadAnim__15EntityBaseClassFUib(void *pThis, unsigned int nId, bool bFlag);
extern "C" void SetAnimData__15EntityBaseClassFP8AnimData(void *pThis, void *pAnim);
extern "C" void SetData__16MotionBlurEffectFPv(void *pFx, void *pData);
extern "C" void SetAnimation__15PGrimReaperCapeFUi(void *pCape, unsigned int nAnim);
extern unsigned char HammerActions[];
extern unsigned char gMaximoMotionBlurTable[];
extern "C" void Add__6PArrayFPv(void *pArray, void *pItem);
extern "C" void BuildDispList__9PSkeletonFv(void *pSkeleton);
extern "C" void EnableOneRenderPassOnly__6PMNodeFi(void *pNode, int nPass);
extern unsigned char gEng[0x1A000];
extern PResourceManager *mpResMgr__15EntityBaseClass;
extern char mMaximoData__6Player[380];
extern float HAMMER_REBOUND_TIME;
extern float mHitPos__15EntityBaseClass[4];
extern "C" float sqrtf(float x);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void *__dt__6ShadowFv(void *pThis, short nFlag);
extern "C" void *__dt__15PGrimReaperCapeFv(void *pThis, short nFlag);
extern "C" void __ct__15PGrimReaperCapeFv(void *pThis);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
extern int PeddlerItems[14];
extern int GuardItems[19];
extern "C" void EnableFullScreenFx__10PGfxEngineFb(void *pThis, bool bEnable);
extern unsigned char __vt__6Player[124];
extern unsigned char gMC[0x3FC0];
extern "C" void ComboFinish__8HudComboFv(void *pCombo);
extern "C" int Find__6PArrayFPv(void *pArray, void *pItem);
extern "C" int IsTreasureOK__9InterfaceFv(void *pInterface);
extern "C" void FlashTexture__15EntityBaseClassFUii(void *pEnt, unsigned int nTex, int nMode);
extern "C" void UpdateSulphurFx__15EntityBaseClassFf(void *pEnt, float fDt);
extern "C" void SetHeadCamera__6PlayerFb(void *pPlayer, bool bOn);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pPhysics, unsigned int nType, float *pMat);
extern "C" void *DisplayString__11FontManagerFiiib(void *pFont, int nStr, int nX, int nY, bool bFlag);
extern "C" void RemoveText__11FontManagerFP8FontNode(void *pFont, void *pNode);
extern float GRIM_TIME;
extern float SULFUR_TIME;
extern char gGfxEng[1504384];
extern int miRandom__7MathAPI;
extern "C" int rand();
extern "C" int LoadMesh__15EntityBaseClassFUibb(void *pThis, unsigned int uId, bool bA, bool bB);
extern "C" void SetAbilityAction__6PlayerFP9PSkeletonii(void *pSkeleton, int nIndex, int nRemain);
extern float MIN_TOP;
extern "C" void PlaySoundApparition__6PSoundFUiUi(void *pThis, unsigned int nSound, unsigned int nFlags);
extern "C" void Add__16PParticleManagerFP15PParticleSystem(void *pThis, void *pSystem);
extern "C" int GetFxTexture__16PParticleManagerFUi(void *pThis, unsigned int hFx);
extern "C" int printf(const char *pFmt, ...);
class HitEntity {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual int Slot58(Player *pPlayer, int nA, int nB, int nC, int nD);
    virtual void Slot5C(Player *pPlayer, int nA);
    unsigned int m_unk4;
    char _pad008[0x3C - 0x8];
    float *m_unk3C;
    char _pad040[0x15C - 0x40];
    unsigned short m_unk15C;
    char _pad15E[0x163 - 0x15E];
    unsigned char m_unk163;
    char _pad164[0x190 - 0x164];
    float m_unk190[4];
    float m_unk1A0[4];
    char _pad1B0[0x2C0 - 0x1B0];
    float m_unk2C0;
};
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, float (*pPos)[4], int nObj, int nWeapon, bool bFlag);
extern "C" void EndGrab__19ClockworkSoulsuckerFv(void *pThis);
extern "C" void SetDrainHit__19ClockworkSoulsuckerFUi(void *pThis, unsigned int nHit);
extern "C" void FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(void *pThis, void *pOther);
extern "C" void SpawnPickups__15EntityBaseClassFiiPA4_fb(void *pThis, int nType, int nCount, float (*pPos)[4], bool bFlag);
extern "C" void CreateFireDamageFx__15EntityBaseClassFf(void *pThis, float fTime);
extern float DAMAGE_JUMP;
extern "C" void CheckSwordBGAnim__13EntityManagerFP6PMNode(void *pMgr, PMNode *pNode);
extern "C" void CreateOneShot__16PParticleManagerFUifff(void *pMgr, unsigned int nId, float fX, float fY, float fZ);
extern "C" void UpdateAnimate__6PWorldFP6PMNode(void *pWorld, PMNode *pNode);
extern unsigned int LandSound[8];
extern float CWSS_X;
extern float CWSS_Y;
extern float CWSS_Z;
struct PlingEntry {
    int unk0;
    int unk4;
    unsigned char unk8;
    char _pad009[3];
};
extern PlingEntry PlingTable[8];
class VirtualSlot08Object {
public:
    virtual void Slot08(int arg0);
};
struct SpinEffectEntry {
    unsigned int a;
    unsigned int b;
};
extern "C" void SetFrameRate__6PMNodeFfb(PMNode *, float, bool);
// AnimStateCall as RunMove calls it: Slot18 takes the action, Slot28 takes no argument.
class AnimStateRunCall {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual int Slot18(int arg0);
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual int Slot28();
};
struct SwordEntry {
    unsigned int uId;
    char _pad004[3];
    signed char b7;
    char _pad008[4];
    float fC;
};
extern SwordEntry SwordTbl[4];
extern "C" void SetShadowCaster__13PShadowVolumeFP6PMNode(void *pVol, void *pNode);
class VirtualSlot58Object {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual int Slot58(void *arg0, int arg1, int arg2, void *arg3);
};
class VirtualSlot14Object {
public:
    virtual void Slot08(int arg0);
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14(void *arg0);
};
extern "C" void sceVu0UnitMatrix(float (*)[4]);
extern "C" void CalculateMatrix__6PMNodeFfP6PMNodePA4_A4_f(PMeshNode *, float, PMNode *, float (*)[4][4]);
extern "C" void SetHolyGround__13EntityManagerFPA4_ffb(void *, float (*)[4], float, bool);
extern float GRIM_AIRATTACKG;
extern float GRIM_AIRATTACKV;
extern float GRIM_AIRATTACKY;
extern float GRIM_JUMPG;
extern int HEAD_BUTT_COUNT;
extern void *mCameraAPI__13EntityManager;
extern "C" void ShakeScreenUsingTable__9CameraAPIFiUi(void *pThis, int nA, unsigned int nB);
class Interface {
public:
    char _pad000[0x10];
    void AddAbility(int arg0);
    void UpdateStatus(unsigned int arg0, bool arg1);
    char _pad010[0x415];
    unsigned char m_unk425;
    enum eFadeColor { eFadeColor_Value0 = 0, eFadeColor_Value1 = 1, eFadeColor_Value2 = 2 };
    void FadeScreen(float arg0, float arg1, bool arg2, eFadeColor arg3);
    void SetPlayerData(Player::PlayerData *arg0);
};
extern Interface gInterface;
extern signed char AbilityTable[];
extern unsigned short HSpin360Attack;
extern unsigned short HSpin720Attack;
struct AttackEntry {
    unsigned short m_unk0;
    unsigned short m_unk2;
    unsigned short m_unk4;
    unsigned short m_unk6;
    unsigned short m_unk8;
    unsigned short m_unkA;
};
extern AttackEntry AttackTable[42];
class EntityBaseClass {
public:
    int Render(PLightManager *pLightMgr);
    int ProcessHitBack();
    void SetState(int arg0);
    int PlaySound(unsigned int arg0);
    void ResetCollisions();
    void Animate(int arg0, float arg1);
    void StopSoundBySoundRef(unsigned int arg0);
    void EnableSleep(bool arg0, bool arg1);
};
class PAnim;
class PShadowVolume;
class Shadow {
public:
    enum ShadowType { eShadowNone = 0, eShadowParticle = 1, eShadowMesh = 2 };
    Shadow(ShadowType arg0, unsigned int arg1);
    unsigned char m_unk0;
    char _pad1[3];
    void *m_unk4;
    float m_unk8;
    PShadowVolume *m_unkC;
};
extern signed char MaximoArmor[8];
extern unsigned int FootSound[8];
class FontManager {
public:
    void RemoveText(FontNode *pNode);
};
extern float GRIM_G;
extern float gUnitMatrix[16];
extern float LEye[4];
extern float REye[4];
extern float AIR_ATTACK_SPEED;
extern float FAST_G;
class CutSceneObject {
public:
    virtual void Slot00();
    virtual void Slot04(int arg0, int arg1, int arg2);
};
class RenderSlotObject {
public:
    virtual void Slot00();
    virtual int Slot04(PLightManager *arg0, int arg1, int arg2);
};
class Shield {
public:
    void DeleteShield();
};
class PlingEffect {
public:
    virtual void Slot00(int arg0);
};
// Virtual slots 0..3 are the destructor, Load, Load and Animate; slot 4 (0x18) is IsAnimate.
class PAnimFrame {
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual int IsAnimate();
};
class PMat4;
class AnimStateObject {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual int Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual int Slot28();
    int m_unk4;
};

// TODO(header): foreign declarations
// AnimStateObject's vtable with Slot28 taking one int (the caller's a1), as SwimMove calls it.
class AnimStateCall {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual int Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual int Slot28(int arg0);
};

class PMNode {
public:
    virtual void Slot08();
    virtual int Slot0C(PLightManager *arg0, int arg1, int arg2);
    virtual void Slot10(float arg0);
    virtual void Slot14();
    virtual void Animate(float arg0, float arg1, PMat4 *arg2, int arg3, bool arg4);
    virtual void Slot1C(int arg0);
    char _pad04[0x0C];
    void *m_unk10;
    struct {
        int m_unk0;
        int m_unk4;
        void **m_unk8;
    } m_unk14;              // 0x14 list header: count, index, data (0x18 and 0x1C)
    char _pad20[0x24 - 0x20];
    AnimStateObject *m_unk24;
    char _pad28[0x34 - 0x28];
    float m_unk34;
    char _pad38[0x3E - 0x38];
    unsigned char m_unk3E;
    signed char m_unk3F;
    char _pad40[0x80 - 0x40];
    u_long128 m_unk80;      // 0x80 vector written by CatchLedgeMove
    char _pad90[0x94 - 0x90];
    float m_unk94;          // 0x94 angle written by CatchLedgeMove
    char _pad98[0xE8 - 0x98];
    unsigned int m_unkE8;
    void SetRenderPassStatus(bool bA, bool bB, bool bC, bool bD);
    void *GetFirstMesh();
    void ProcessFxTriggers(float arg0, PMat4 *arg1, bool arg2, bool arg3);
    void EnableFx(bool arg0, bool arg1);
    void EnableAnim(bool arg0, bool arg1);
    void SetAnimLoopCount(int arg0, bool arg1);
    void AttachFx(unsigned int arg0, float arg1, float arg2, float arg3, float arg4, bool arg5);
    float GetFrameTime();
    PMNode *FindAnimNode(unsigned int arg0);
    int Find(PMNode *arg0);
    PMNode *Find(unsigned int arg0);
};
class GunTurret {
public:
    virtual ~GunTurret();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C();
    virtual void Slot20();
    virtual void Slot24();
    virtual void Slot28();
    virtual void Slot2C();
    virtual void Slot30();
    virtual void Slot34();
    virtual void Slot38();
    virtual void Slot3C();
    virtual void Slot40();
    virtual void Slot44();
    virtual void Slot48();
    virtual void Slot4C();
    virtual void Slot50();
    virtual void Slot54();
    virtual void Slot58(Player *arg0, int arg1, int arg2, int arg3);
    void SetGunParams(signed char arg0, bool arg1);
    void SetPlayerLeftDeck();
};
class FreeJoint {
public:
    int m_unk00;
    unsigned char m_unk04;
    unsigned char _pad05[3];
};
extern FreeJoint m_pFreeJoints[5];
struct HitSurf {
    char _pad000[0xC];
    unsigned int m_unkC;
    float m_unk10[4];
};
class Physics {
public:
    Physics();
    char _pad000[4];
    float m_unk4;
    char _pad008[0xA0 - 0x8];
    char m_unkA0[0x14];
    float m_unkB4;
    char _padB8[0xC4 - 0xB8];
    float m_unkC4;
    float m_unkC8;
    PMNode *m_unkCC;
    char _padD0[0xE0 - 0xD0];
    PMNode *m_unkE0;
    HitSurf *m_unkE4;
    unsigned int m_unkE8;
    unsigned int m_unkEC;
    char _padF0[0xF8 - 0xF0];
    float m_unkF8;
    char _pad0FC[0x100 - 0xFC];
    float m_unk100;
    char _pad104[0x108 - 0x104];
    unsigned int m_unk108;
    char _pad10C[0x118 - 0x10C];
    float m_unk118;
    float m_unk11C;
    void SetPhysicsType(unsigned int arg0, float (*arg1)[4]);
    void SetVelocity(float arg0, float arg1);
    void ResetPhysics(PMeshNode *pNode);
};
extern Debug gDebug;
class Camera {
public:
    int SetHeadCam(bool arg0);
    int ControlledByApp(unsigned int arg0);
    void SetupShakeScreen(float arg0, float arg1, float arg2, int arg3, int arg4, unsigned int arg5);
};
class PSound {
public:
    char _pad000[0x18080];
    void PlaySoundApparition(unsigned int arg0, unsigned int arg1);
    void TriggerSystemSound(unsigned int arg0, unsigned int arg1, PMNode *arg2);
    void FadeOutAllMusic(unsigned int arg0);
    enum EnumMusicSpecialVols { MUSIC_SPECIAL_VOLS_NONE = 0 };
    void SetMainMusicSpecialVolume(EnumMusicSpecialVols eVol);
};
extern PSound gSound;
class EffectNode {
public:
    char _pad000[4];
    int m_unk4;
};
class Projectile {
public:
    void Delete();
};
class EffectAPI {
public:
    char _pad000[20];
    int CreateOneshot(unsigned int, unsigned int, float (*)[4], float (*)[4], EntityBaseClass *, float, bool, int, bool);
    int CreateOneshot(unsigned int, unsigned int, PMat4 *, EntityBaseClass *, float, int, bool);
    EffectNode *EffectValid(unsigned int arg0);
    void DeleteEffect(EffectNode *arg0);
    void DeleteEffect(unsigned int arg0);
    PlingEffect *CreatePling(EntityBaseClass *arg0, float arg1, unsigned int arg2, unsigned int arg3, bool arg4);
};
extern EffectAPI mEffectAPI__13EntityManager;
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" long long fptodp(float arg0);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__10PAnimFrame[];
extern "C" void *__dt__5PAnimFv(void *pThis, short nFlag);
extern void *mpEntMgr__15EntityBaseClass;
extern int mbHard__15EntityBaseClass;
extern int ComboLevel[20];
extern "C" void memset(void *, int, unsigned int);
extern unsigned char GameVarTbl[0x78];
extern int CAUGHT_TIME;
extern int LEDGE_UP_TIME;
extern int UP_TIME;
extern float GRIM_AIR_POS;
extern int TAP_COUNT;
extern int TAP_TIMER;
extern float AttachedTimer[5];
class MathAPI {
public:
    static int RandomIntRange(int arg0, int arg1);
    static void GetForwardVector(EntityBaseClass *arg0, float (&arg1)[4]);
    static void VectorRotateY(float (*arg0)[4], float arg1);
};
struct AttachableJoint {
    int m_unk00;
    int m_unk04;
    float m_unk08;
    float m_unk0C;
    float m_unk10;
};
extern AttachableJoint m_AttachableJoints[5];
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *, unsigned int);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" float FastMath_Fabs__Ff(float fValue);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0ApplyMatrix(float *pDst, float *pMat, float *pSrc);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void *Spawn__13EntityManagerFUibi(void *, unsigned int, bool, int);
extern "C" void InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(void *, int, float *, float *, float *);
extern "C" float sinf(float x);
extern "C" float cosf(float x);
extern "C" float atan2f(float fY, float fX);
extern "C" float Round180__Ff(float fAngle);
extern "C" int GameVarSub__6PlayerFUii(void *pThis, unsigned int nId, int nValue);
extern "C" short IsNoDamage__5DebugFv(void *pThis);
extern "C" void InitShield__6ShieldFP15EntityBaseClassfPA4_fPA4_fUiPbi(void *pThis, void *pOwner, float fArg1, float (*pArg2)[4], float (*pArg3)[4], unsigned int nArg4, bool *pArg5, int nArg6);
extern "C" float FastMath_Sin180__Ff(float fAngle);
extern "C" float FastMath_Cos180__Ff(float fAngle);
extern "C" void *GetLevelFile__10MaximoMainFi(void *pThis, int nIdx);
extern "C" void ReleaseControlOfCamera__9CameraAPIFP15EntityBaseClassb(void *pThis, void *pEntity, bool bFlag);
extern "C" int __ptmf_test(void *pVec);
extern "C" void __ptmf_scall(void *pThis);
class VirtualSlot18Call {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18(int arg0, int arg1, int arg2, int arg3, int arg4);
};
extern float SLOW_JUMP;
class Pad {
public:
    enum VibType { VIB_0 = 0, VIB_1 = 1 };
    void SetVibrate(VibType arg0, unsigned char arg1);
    char _pad000[0x108];
    unsigned short m_unk108;
    unsigned short m_unk10A;
    short m_unk10C;
    char _pad10E[0x110 - 0x10E];
    short m_unk110;
    char _pad112[0x114 - 0x112];
    signed char m_unk114;
    signed char m_unk115;
    signed char m_unk116;
    signed char m_unk117;
};
extern Pad gPad;
class MaximoMain {
public:
    void RestartGame(bool arg0);
};
class ApparitionVirtuals {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual int OnHitEvent(void *pSource, int nEvent, unsigned int nArg1, unsigned int nArg2);
};

// FUNCTION: 0x00158F60 Ready2Clear__6PlayerFv
unsigned char Player::Ready2Clear() {
    if (m_unk264 & 0x32) {
        int r = (m_unk1D0 & 4) != 0;
        if (r == 0) {
            r = (m_unk38[0x42] & 1) != 0;
        }
        return r & 0xFF;
    }
    return 0;
}

// FUNCTION: 0x00158FA0 IsPlayerOnAnimNode__6PlayerFUi
int Player::IsPlayerOnAnimNode(unsigned int arg0) {
    if (m_unk1D0 & 4) {
        PMNode *node = (PMNode *)m_unk38[0x33];
        if (node != 0) {
            int *p = *(int **)((char *)node + 0x24);
            if (p != 0) {
                return arg0 == (unsigned int)p[1];
            }
            PMNode *found = (*(PMNode **)gEng)->FindAnimNode(arg0);
            if (found != 0) {
                return found->Find(node);
            }
        }
    }
    return 0;
}

// FUNCTION: 0x00159030 IsPauseDisabled__6PlayerFv
int Player::IsPauseDisabled() {
    int ret = (m_unk264 & 0x808) != 0;
    if (ret == 0) {
        ret = m_unk20 != 0;
    }
    if (ret == 0) {
        ret = gEng[0x19A18] != 0;
    }
    return ret;
}

// DRAFT: 0x00159080 DetachJoint__6PlayerFi
// note: 30 words differ. Ours hoists lui a0 into the bgez delay slot of the assert (original has nop), which shifts the assert block and every later branch. The tail is fixed by `if (!fTimer)`. Tried the if/else and !(...) assert forms (30, no gain), direct store, local fTimer, fZero, reversed compare.
void Player::DetachJoint(int arg0) {
    if (m_pFreeJoints[arg0].m_unk04 == 0) {
        m_pFreeJoints[arg0].m_unk00 = 0;
        m_pFreeJoints[arg0].m_unk04 = 1;
        m_unk23D4 += 1;
        ((m_unk23D4 >= 0) ? (void)0 : CdsAssert("Player.cpp", 0x2260, "m_iNumFreeJoints >= 0"));
        m_unk23D1 = (unsigned int)m_unk23D4 < 4U;
        float fTimer = AttachedTimer[5 - m_unk23D4];
        m_unk2FC = fTimer;
        if (!fTimer) {
            *(float *)&m_unk2F8 = 0.0f;
        }
    }
}

// FUNCTION: 0x00159150 FreeJoint__6PlayerFi
void Player::FreeJoint(int arg0) {
    int idx = m_unk23D4 + arg0;
    m_unk23D1 = (unsigned int)idx < 4U;
    if ((unsigned int)idx > 5U) {
        idx = 5;
    }
    float fTimer = AttachedTimer[5 - idx];
    m_unk2FC = fTimer;
    if (!fTimer) {
        *(float *)&m_unk2F8 = 0.0f;
    }
    int freed = 0;
    int r = MathAPI::RandomIntRange(1, 4);
    int i = r;
    while (m_unk23D4 != 5) {
        if (m_pFreeJoints[i].m_unk04 == 0) {
            m_pFreeJoints[i].m_unk00 = 0;
            freed += 1;
            m_pFreeJoints[i].m_unk04 = 1;
            m_unk23D4 += 1;
            if (freed == arg0) {
                return;
            }
        }
        i += 1;
        if (i == r) {
            return;
        }
        if (i == 5) {
            i = 0;
        }
    }
}

// FUNCTION: 0x00159260 GetAttachableJointOffsets__6PlayerFiPA4_f
void Player::GetAttachableJointOffsets(int arg0, float (*arg1)[4]) {
    float fVec[4];
    unsigned int uVal;
    if (m_pFreeJoints[arg0].m_unk00 == 0) {
        CdsAssert("Player.cpp", 0x2221, "m_pFreeJoints[index].pJoint");
    }
    fVec[0] = m_AttachableJoints[arg0].m_unk08;
    fVec[1] = m_AttachableJoints[arg0].m_unk0C;
    fVec[2] = m_AttachableJoints[arg0].m_unk10;
    uVal = (unsigned char)m_pFreeJoints[arg0]._pad05[0];
    fVec[3] = (float)uVal;
    *(u_long128 *)arg1 = *(u_long128 *)fVec;
}

// DRAFT: 0x00159360 GetAttachableJoint__6PlayerFPi
// note: DIFF 150 words; size 0x218 vs 0x264, frame 0x60 vs 0x70 (original keeps this in s5 and has a RandomIntRange(0,100) coin-flip branch and AttachableJoints lookups missing here); while-form scored 152.
void Player::GetAttachableJoint(int *arg0) {
    int idx;
    bool wrapped;
    int limit;
    class FreeJoint *pJ;
    unsigned char *pFlag;
    int a1;

    wrapped = false;
    limit = MathAPI::RandomIntRange(1, 4);
    idx = limit;
    for (;;) {
        if (wrapped || m_unk23D4 == 0) {
            m_unk23D0 = 1;
            *arg0 = -1;
            return;
        }
        pJ = &m_pFreeJoints[idx];
        if (pJ->m_unk04 != 0 && m_unk3C != 0) {
            pFlag = &pJ->_pad05[0];
            *pFlag = 1;
            if (idx == 4) {
                a1 = m_AttachableJoints[idx].m_unk00;
                *pFlag = 0;
                pJ->_pad05[1] = 0;
            } else if (MathAPI::RandomIntRange(0, 100) & 1) {
                a1 = m_AttachableJoints[idx].m_unk00;
                pJ->_pad05[1] = 0;
            } else {
                a1 = m_AttachableJoints[idx].m_unk04;
                pJ->_pad05[1] = 1;
                if (idx == 0 || idx == 1) {
                    *pFlag = 0;
                }
            }
            pJ->m_unk00 = (int)((PMNode *)m_unk3C)->Find(a1);
            pJ->m_unk04 = 0;
            if (pJ->m_unk00 == 0) {
                CdsAssert("Player.cpp", 0x2200, "m_pFreeJoints[i].pJoint");
            }
            m_unk23D4 -= 1;
            if (m_unk23D4 < 0) {
                CdsAssert("Player.cpp", 0x2204, "m_iNumFreeJoints >= 0");
            }
            m_unk23D1 = (unsigned int)m_unk23D4 < 4U;
            m_unk2FC = AttachedTimer[5 - m_unk23D4];
            if (m_unk23D4 == 4) {
                m_unk2F8 = 0x3F800000;
            }
            *arg0 = idx;
            return;
        }
        idx += 1;
        if (idx == limit) {
            wrapped = true;
        }
        if (idx == 5) {
            idx = 0;
        }
    }
}

// FUNCTION: 0x001595D0 GetAttachableJoint__6PlayerFi
int Player::GetAttachableJoint(int arg0) {
    return m_pFreeJoints[arg0].m_unk00;
}

// DRAFT: 0x001595F0 RefreshAttachableJoints__6PlayerFv
// note: 9 diff words; goto-entered unsigned loop matches the shape, but the counter takes s0 where the original has s2 (strided offsets s0/s1). Tried int i, late init, uID at top, 4 == i, switch (63), FreeJoint pointer local (72).
void Player::RefreshAttachableJoints() {
    unsigned int i = 0;
    goto test;
loop:
    {
        if (m_pFreeJoints[i].m_unk04 == 0) {
            unsigned int uID;
            if (i == 4) {
                uID = m_AttachableJoints[i].m_unk00;
            } else if (m_pFreeJoints[i]._pad05[1] == 0) {
                uID = m_AttachableJoints[i].m_unk00;
            } else {
                uID = m_AttachableJoints[i].m_unk04;
            }
            m_pFreeJoints[i].m_unk00 = (int)((PMNode *)m_unk3C)->Find(uID);
            if (m_pFreeJoints[i].m_unk00 == 0) {
                m_pFreeJoints[i].m_unk04 = 1;
                m_unk23D4 += 1;
            }
        }
    }
    i++;
test:
    if (i < 5) goto loop;
    m_unk2FC = AttachedTimer[5 - m_unk23D4];
}

// FUNCTION: 0x00159720 InitAttachableJoints__6PlayerFv
void Player::InitAttachableJoints() {
    m_unk23D0 = 0;
    m_unk23D4 = 5;
    m_unk23D1 = 0;
    m_unk2F8 = 0;
    m_pFreeJoints[0].m_unk00 = 0;
    m_pFreeJoints[0].m_unk04 = 1;
    m_pFreeJoints[1].m_unk00 = 0;
    m_pFreeJoints[1].m_unk04 = 1;
    m_pFreeJoints[2].m_unk00 = 0;
    m_pFreeJoints[2].m_unk04 = 1;
    m_pFreeJoints[3].m_unk00 = 0;
    m_pFreeJoints[3].m_unk04 = 1;
    m_pFreeJoints[4].m_unk04 = 1;
    m_pFreeJoints[4].m_unk00 = 0;
}

// FUNCTION: 0x00159790 AnimationViewer__6PlayerFi
int Player::AnimationViewer(int arg0) {
    int nIndex = 0;
    int nOffset = 0;
    int nSum = 0;
    do {
        unsigned short nDur = *(unsigned short *)(mMaximoData__6Player + nOffset + 4);
        if ((unsigned int)(arg0 - nSum) < nDur) break;
        nIndex++;
        nSum += nDur;
        nOffset += 0x4C;
    } while (nIndex < 5);
    char *pIdBase = mMaximoData__6Player + 8;
    if (LoadMesh__15EntityBaseClassFUibb(this, *(unsigned int *)(pIdBase + nIndex * 0x4C), false, true)) {
        PMNode *pNode = (PMNode *)m_unk3C;
        bool bBuilt = false;
        PMNode *pEntry = pNode->Find(0xB5714B5AU);
        if (pEntry) {
            PMNode *pRes = mpResMgr__15EntityBaseClass->GetResource(0x81000001, true);
            void *pMesh = pRes->m_unk10;
            pEntry->m_unk10 = pMesh;
            pEntry->m_unk3E &= 0xEF;
            if (pMesh && ((unsigned char *)pMesh)[0xC]) pEntry->m_unk3E |= 0x10;
            bBuilt = true;
        }
        pEntry = pNode->Find(0x6499DC24U);
        if (pEntry) {
            PMNode *pShield = mpResMgr__15EntityBaseClass->GetResource(0x81000002, true);
            if (!pShield) CdsAssert("Player.cpp", 0x2189, "pShield");
            void *pMesh = pShield->GetFirstMesh();
            pEntry->m_unk10 = pMesh;
            pEntry->m_unk3E &= 0xEF;
            if (pMesh && ((unsigned char *)pMesh)[0xC]) pEntry->m_unk3E |= 0x10;
            bBuilt = true;
        }
        if (bBuilt) BuildDispList__9PSkeletonFv(pNode);
    }
    SetAbilityAction__6PlayerFP9PSkeletonii(m_unk3C, nIndex, arg0 - nSum);
    int nTotal = 0;
    nTotal += *(unsigned short *)(mMaximoData__6Player + 0x4);
    nTotal += *(unsigned short *)(mMaximoData__6Player + 0x50);
    nTotal += *(unsigned short *)(mMaximoData__6Player + 0x9C);
    nTotal += *(unsigned short *)(mMaximoData__6Player + 0xE8);
    nTotal += *(unsigned short *)(mMaximoData__6Player + 0x134);
    return nTotal;
}

struct MaximoAbilityEntry {
    unsigned int m_unk00;
    unsigned char m_unk04;
    unsigned char m_unk05;
    signed char m_unk06;
    unsigned char m_unk07;
    int m_unk08;
    char _pad0C[0x10];
};

struct SetAbilityBlock {
    short m_unk00;
    short m_unk02;
    short m_unk04;
    short m_unk06;
    short m_unk08;
    short m_unk0A;
    float m_unk0C;
};

// Slots named by vtable offset: Slot08 is the first virtual after the header.
class AbilityVirtuals {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual int Slot18(int arg0, int arg1);
    virtual void Slot1C(void *arg0);
    virtual int Slot20(void *arg0);
};

// FUNCTION: 0x001599C0 SetAbilityAction__6PlayerFP9PSkeletonii
void Player::SetAbilityAction(PSkeleton *arg0, int arg1, int arg2) {
    MaximoAbilityEntry *pEntry;
    pEntry = *(MaximoAbilityEntry **)(mMaximoData__6Player + (int)arg0 * 76) + arg1;
    if (pEntry->m_unk00 != 0 && ((AbilityVirtuals *)this)->Slot20(mpResMgr__15EntityBaseClass->GetResource(pEntry->m_unk00, false)) != 0) {
        SetAbilityBlock blk;
        int flags = pEntry->m_unk08;
        blk.m_unk00 = 0;
        blk.m_unk02 = -1;
        if (pEntry->m_unk05 == 0) {
            blk.m_unk06 = -1;
            blk.m_unk04 = 0;
        } else {
            blk.m_unk06 = pEntry->m_unk05;
            blk.m_unk04 = pEntry->m_unk04;
        }
        blk.m_unk08 = pEntry->m_unk06;
        blk.m_unk0A = pEntry->m_unk07;
        if (blk.m_unk0A == 2) {
            blk.m_unk0A = 6;
        }
        blk.m_unk0C = (flags & 0x40) ? 1.0f : 0.5f;
        ((AbilityVirtuals *)this)->Slot1C(&blk);
    }
}

// FUNCTION: 0x00159AF0 OutputDebug__6PlayerFv
void Player::OutputDebug() {
    char buf[0x100];
    if (m_unk3C != 0) {
        sprintf(buf, "Action %d, frame %f, Atk(%d, 0x%x), Combo %d", m_unk260, (double)m_unk3C[13], m_unk15C, m_unk15E, m_unk220);
        gDebug.DebugDisp(buf);
    }
}

// FUNCTION: 0x00159B60 FinishCutCamera__6PlayerFPA4_f
void Player::FinishCutCamera(float (*arg0)[4]) {
    char *obj = (char *)m_unk3C;
    m_unk1C4 = arg0[0][3];
    *(float *)(obj + 0x94) = arg0[0][3];
    ((unsigned char *)obj)[0x3E] |= 8;
    arg0[0][3] = 1.0f;
    *(u_long128 *)(obj + 0x80) = *(u_long128 *)arg0;
    ((unsigned char *)obj)[0x3E] |= 8;
    *(u_long128 *)m_unk38 = *(u_long128 *)&gUnitMatrix[12];
    Physics *phys = (Physics *)m_unk38;
    phys->m_unk11C = Round180__Ff(m_unk1C4);
    if (m_unk335 == 0) {
        SetAction(0);
    }
    m_unk26C = 0;
    m_unk33B = 0;
    EnablePlayerShadow(true);
    if (m_unk229 == 4) {
        ((PMNode *)obj)->Animate(0.0f, 0.0f, 0, 0, false);
    }
}

// DRAFT: 0x00159C50 FinishCutScene__6PlayerFP9PMeshNodeP5PMat4i
// note: arg1 copy into s2 sinks to the ternary delay slot (original copies a2 to s2 at entry); 86 differing words, size 0x17c vs 0x180; tried PMat4* and float(*)[4] locals, no gain.
void Player::FinishCutScene(PMeshNode *arg0, PMat4 *arg1, int arg2) {
    PMNode *obj = (PMNode *)m_unk3C;
    obj->m_unk14.m_unk4 = 0;
    PMNode *node = (obj->m_unk14.m_unk0 != 0) ? (PMNode *)obj->m_unk14.m_unk8[0] : 0;
    float mtx[4][4];
    sceVu0UnitMatrix(mtx);
    sceVu0CopyMatrix(mtx, (float (*)[4])arg1);
    CalculateMatrix__6PMNodeFfP6PMNodePA4_A4_f(arg0, 5000.0f, node, &mtx);
    mtx[3][1] -= 2.5f;
    *(u_long128 *)&obj->m_unk80 = *(u_long128 *)mtx[3];
    obj->m_unk3E |= 8;
    float ang = 57.295776f * atan2f(mtx[2][0], mtx[2][2]);
    obj->m_unk94 = ang;
    obj->m_unk3E |= 8;
    m_unk1C4 = ang;
    ResetEye(true);
    *(u_long128 *)m_unk38 = *(u_long128 *)&gUnitMatrix[12];
    ((Physics *)m_unk38)->m_unk11C = Round180__Ff(m_unk1C4);
    if (arg2 != 0) {
        SetHolyGround__13EntityManagerFPA4_ffb(mpEntMgr__15EntityBaseClass, mtx + 3, ang, false);
    }
    SetAction(0);
    ((Physics *)m_unk38)->ResetPhysics((PMeshNode *)obj);
    m_unk26C = 0;
    EnablePlayerShadow(true);
    m_unk33B = 0;
}

// FUNCTION: 0x00159DD0 GetKeyMove__6PlayerFv
void Player::GetKeyMove() {
    if (m_unk250 == 0 && (int)((PMNode *)m_unk3C)->GetFrameTime() >= 2) {
        m_unk250 = 1;
        UpdateKey();
        ((EntityBaseClass *)this)->PlaySound(0x1A);
    }
}

// FUNCTION: 0x00159E40 PumpkinGrabMove__6PlayerFv
void Player::PumpkinGrabMove() {
    if (!(((float *)m_unk38)[0x3E] <= 2.0f)) {
        SetAction(6);
        return;
    }
    if (ReleaseCheck() != 0) {
        m_unk1C4 = ((Physics *)m_unk38)->m_unk11C;
        SetAction(0x78);
    }
}

// FUNCTION: 0x00159EC0 AdjustPositionOfAttacker__6PlayerFP15EntityBaseClassP15EntityBaseClassfff
void Player::AdjustPositionOfAttacker(EntityBaseClass *arg0, EntityBaseClass *arg1, float arg2, float arg3, float arg4) {
    float sp40[4];
    float sp50[4];
    float sp60[4];
    float *s0 = (float *)(*(char **)((char *)arg0 + 0x3C) + 0x40);
    MathAPI::GetForwardVector(arg1, sp50);
    sceVu0ScaleVector(sp50, sp50, -1.0f);
    sceVu0ScaleVector(sp40, sp50, arg2);
    sceVu0AddVector(sp40, sp40, s0 + 0xC);
    if (arg4 != 0.0f) {
        sceVu0ScaleVector(sp60, s0, arg4);
        sceVu0AddVector(sp40, sp40, sp60);
    }
    if (arg3 != 0.0f) {
        sp40[1] += arg3;
    }
    char *obj = *(char **)((char *)arg1 + 0x3C);
    if (obj != 0) {
        *(u_long128 *)(obj + 0x80) = *(u_long128 *)sp40;
        *(unsigned char *)(obj + 0x3E) |= 8;
    } else {
        *(u_long128 *)((char *)arg1 + 0x190) = *(u_long128 *)sp40;
    }
}

// FUNCTION: 0x00159FE0 AdjustPosition__6PlayerFP15EntityBaseClassP15EntityBaseClassfff
void Player::AdjustPosition(EntityBaseClass *arg0, EntityBaseClass *arg1, float arg2, float arg3, float arg4) {
    float sp40[4];
    float sp50[4];
    float sp60[4];
    float *s0 = (float *)(*(char **)((char *)arg0 + 0x3C) + 0x40);
    sceVu0ScaleVector(sp40, s0 + 8, arg2);
    sceVu0AddVector(sp40, sp40, s0 + 0xC);
    if (arg4 != 0.0f) {
        sceVu0ScaleVector(sp50, s0, arg4);
        sceVu0AddVector(sp40, sp40, sp50);
    }
    if (arg3 != 0.0f) {
        sceVu0ScaleVector(sp60, s0 + 4, arg3);
        sceVu0AddVector(sp40, sp40, sp60);
    }
    char *obj = *(char **)((char *)arg1 + 0x3C);
    if (obj != 0) {
        *(u_long128 *)(obj + 0x80) = *(u_long128 *)sp40;
        *(unsigned char *)(obj + 0x3E) |= 8;
    } else {
        *(u_long128 *)((char *)arg1 + 0x190) = *(u_long128 *)sp40;
    }
}

// FUNCTION: 0x0015A0E0 ReleaseCheck__6PlayerFv
int Player::ReleaseCheck() {
    void *pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk2C0);
    if (pApparition != 0) {
        int nLeft = m_unk2C8 - 1;
        m_unk2C8 = nLeft;
        if (nLeft <= 0) {
            m_unk2C4 = 0;
        }
        if ((m_unk1B2 & 0xF000) || (m_unk1BA != 0)) {
            m_unk2C4 = m_unk2C4 + 1;
            m_unk2C8 = CAUGHT_TIME;
            if (((ApparitionVirtuals *)pApparition)->OnHitEvent(this, m_unk2C4, 0x1FC, 0) == 1) {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

// FUNCTION: 0x0015A300 CatchIdleMove__6PlayerFv
void Player::CatchIdleMove() {
    CatchLedgeMove();
    if (m_unk250 == 0) {
        m_unk250 = 1;
    }
    if (m_unk1B2 & 0x4000) {
        m_unk1C4 = ((Physics *)m_unk38)->m_unk11C;
        SetAction(0x2C);
        ((Physics *)m_unk38)->SetPhysicsType(0x800, 0);
    }
}

// FUNCTION: 0x0015A370 CatchLedgeMove__6PlayerFv
void Player::CatchLedgeMove() {
    float sp40[4];
    PMNode *node = (PMNode *)m_unk3C;
    if (m_unk2F0 != 0) {
        float *pMat = (float *)(m_unk2F0 + 0x40);
        sceVu0ApplyMatrix(sp40, pMat, m_unk2D0);
        sp40[1] -= 6.0f;
        *(u_long128 *)&node->m_unk80 = *(u_long128 *)sp40;
        node->m_unk3E |= 8;
        sceVu0ApplyMatrix(sp40, pMat, m_unk2E0);
        float fAngle = Round180__Ff(57.295776f * atan2f(sp40[0], sp40[2]));
        node->m_unk94 = fAngle;
        node->m_unk3E |= 8;
        Physics *phys = (Physics *)m_unk38;
        phys->m_unk11C = Round180__Ff(fAngle);
    }
    if (m_unk260 == 0x2A && (m_unk1B2 & 0x4000) && (int)node->GetFrameTime() >= LEDGE_UP_TIME) {
        m_unk1C4 = ((Physics *)m_unk38)->m_unk11C;
        SetAction(0x2C);
    }
    ((Physics *)m_unk38)->SetPhysicsType(0x800, 0);
}

// FUNCTION: 0x0015A4B0 IsHanging__6PlayerFv
unsigned char Player::IsHanging() {
    int ret;
    switch (m_unk260) {
    case 0x2B:
    case 0x2A:
        ret = 1;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}

// FUNCTION: 0x0015A4E0 NotifyTreasure__6PlayerFPA4_ff
void Player::NotifyTreasure(float (*arg0)[4], float arg1) {
    if (m_unk218 != 1) {
        return;
    }
    float *src;
    if (m_unk3C) {
        src = (float *)((char *)m_unk3C + 0x80);
    } else {
        src = m_unk190;
    }
    float diff[4];
    sceVu0SubVector(diff, *arg0, src);
    float dist2 = sceVu0InnerProduct(diff, diff);
    if (dist2 < arg1 * arg1) {
        m_unk337 = 1;
        return;
    }
    float outer = 6.0f + arg1;
    if (dist2 < outer * outer) {
        m_unk337 = 2;
    }
}

// FUNCTION: 0x0015A590 ArmorUpMove__6PlayerFv
void Player::ArmorUpMove() {
    if (m_unk250 == 0) {
        m_unk250 = 1;
    }
}

// FUNCTION: 0x0015A5B0 SetProbe__6PlayerFPA4_ff
void Player::SetProbe(float (*arg0)[4], float arg1) {
    *(float *)&m_unk344 = arg1 * arg1;
    *(u_long128 *)m_unk350 = *(u_long128 *)arg0;
}

// DRAFT: 0x0015A5D0 FillItems__6PlayerFPib
// note: 91 words differ; frame -0x120 matches; andi before bool branch (original bare bnez), Guard block placement, global addend (addiu s0,s0,0 vs 0x44A0/0x44E0), this/arg0 registers swapped (s7/s5 original, s5/s4 ours); variants: swapped branch 119/118, !arg1 117+, cached mask 125
void Player::FillItems(int *arg0, bool arg1) {
    int spA0[32];
    int *pTable;
    int fp = 0;
    int s1 = 0;
    int s2 = 0;
    int s6 = 1;
    int s3;
    int temp;
    int a3;
    unsigned int a2;
    unsigned int t0;
    int s1_2;
    int i;

    if (arg1 == 0) {
        pTable = PeddlerItems;
        a2 = 0;
        a3 = 0;
        for (;;) {
            t0 = arg0[a3] - 1;
            if (t0 < 0x1F) {
                a2 = t0;
                if ((m_unk224 & (1 << t0)) == 0) {
                    fp = t0 + 0x25;
                    break;
                }
            }
            a3++;
            if (a3 >= 5) {
                fp = a2 + 0x25;
                break;
            }
        }
    } else {
        pTable = GuardItems;
    }
    s1 = 0;
    s6 = 1;
    s2 = 0;
    while ((s3 = *pTable++) != 0) {
        if (s3 < 0) {
            s3 = *pTable++;
            s6 = 0;
        }
        if (s3 == 0x25) {
            s3 = fp;
        }
        temp = CheckAbility(s3);
        switch (temp) {
        case -1:
            arg0[s2] = s3;
            s2++;
            break;
        case -2:
        case -3:
        case -4:
            if (s6 != 0) {
                arg0[s2] = s3;
                s2++;
            } else if (temp != -2) {
                s1++;
                spA0[s1 - 1] = s3;
            }
            break;
        }
        if (s2 >= 5) {
            return;
        }
    }
    s1_2 = s1 - 1;
    if (s2 < 5) {
        do {
            if (s1_2 < 0) {
                CdsAssert("Player.cpp", 0x1E9E, "iResItem >= 0");
            }
            arg0[s2] = spA0[s1_2];
            s2++;
            s1_2--;
        } while (s2 < 5);
    }
}

// FUNCTION: 0x0015A7F0 ValidateItem__6PlayerFi
int Player::ValidateItem(int arg0) {
    int result = arg0;
    if (CheckAbility(arg0) != -1) {
        result = -1;
    }
    return result;
}

// FUNCTION: 0x0015A830 CheckDuplicate__6PlayerFi
int Player::CheckDuplicate(int arg0) {
    int i = 0;
    char *p = (char *)this + AbilityTable[arg0 * 16 + 5] * 8 + 0x22B;
    do {
        int c = *p;
        p++;
        if (c == arg0) {
            return 1;
        }
        i++;
    } while (i < 8);
    return 0;
}

// note: 15 words differ: original loads 3 into a0 and 2 into v1 before the loop, compiled code swaps them; the bltz guard on negative bytes is now present. Tried if-chain, switch, case order swap, pointer/counter declaration order and the guard (V1-V6).
// DRAFT: 0x0015A880 CheckHammer__6PlayerFb
int Player::CheckHammer(bool arg0) {
    signed char *p = m_unk23B;
    int i = 0;
    do {
        int c = *p++;
        if (c >= 0) {
            switch (c) {
            case 3:
                return 1;
            case 2:
                if (!arg0) {
                    return 1;
                }
                break;
            }
        }
        i++;
    } while (i < 8);
    return 0;
}

// DRAFT: 0x0015A8E0 CheckAbility__6PlayerFi
// note: 166 words; attempts 1-6 tried (separate returns 207, single result 192, default at bottom 166 kept, default at top 177, index order and mask-operand order no gain); remaining: default li -1 tail placement, jump-table relocs, case 3/4 loop registers, missing 0x304 AbilityTable reloc, case 8 and 11/12 tails.
int Player::CheckAbility(int arg0) {
    int a1 = arg0;
    int a2 = a1 - 0x25;
    int result;
    if (a2 >= 0) {
        a1 = 0x25;
    }
    signed char *entry = AbilityTable + a1 * 16;
    switch (entry[4]) {
    case 1:
    case 2:
        result = FindCurrentItem(a1, true);
        break;
    case 5:
    case 7:
        result = FindCurrentItem(a1, false);
        break;
    case 6:
        if (m_unk214 < 0x6B) {
            result = -3;
        } else if (m_unk214 < 0xA0) {
            result = (a1 == 0x13) ? -1 : -2;
        } else {
            result = (a1 == 0x12) ? -1 : -2;
        }
        break;
    case 8:
        result = -2;
        if (m_unk204 / 10 + 0x1A == a1) {
            result = -1;
        }
        break;
    case 9:
        result = ((m_unk1D0 & *(unsigned int *)entry) == 0) ? -1 : -3;
        break;
    case 4:
        a1 = 3;
        a2 = 2;
        goto block19;
    case 3:
        a1 = 1;
        a2 = 0;
    block19:
        if (m_unk1D0 & *(unsigned int *)entry) {
            result = -3;
            break;
        }
        {
            signed char *base = (signed char *)this + a2 * 8;
            int i = 0;
            result = -2;
            do {
                if (base[i + 0x22B] == a1) {
                    result = -1;
                    break;
                }
                i++;
            } while (i < 8);
        }
        break;
    case 10: {
        unsigned int mask = *(unsigned int *)entry;
        unsigned int half;
        if (m_unk1D0 & mask) {
            result = -3;
            break;
        }
        half = mask >> 1;
        result = -2;
        if (half == (m_unk1D0 & (mask | half))) {
            result = -1;
        }
        break;
    }
    case 11:
        if (m_unk1DC < m_unk1D4) {
            result = -1;
            break;
        }
        result = -4;
        if (m_unk1D8 < m_unk1DC * 0xC8) {
            result = -1;
        }
        break;
    case 12:
        result = -1;
        if (m_unk1D8 >= m_unk1DC * 0xC8) {
            result = -4;
        }
        break;
    case 13:
        result = -1;
        if (m_unk20C >= m_unk208 * 0x280) {
            result = -2;
        }
        break;
    case 14:
        if ((unsigned int)a2 < 0x1E) {
            if (!(m_unk224 & (1 << a2))) {
                result = -1;
                break;
            }
        }
        result = -4;
        break;
    case 15:
        if (m_unk1D0 & *(unsigned int *)entry) {
            result = -3;
            break;
        }
        result = (CheckHammer(false) == 0) ? -2 : -1;
        break;
    case 16:
        result = (m_unk208 + 0x21 == a1) ? -1 : -2;
        break;
    case 17:
        result = -4;
        if (m_unk1F8 < 0x63) {
            result = -1;
        }
        break;
    default:
        result = -1;
        break;
    }
    return result;
}

// FUNCTION: 0x0015ABE0 FindCurrentItem__6PlayerFib
int Player::FindCurrentItem(int arg0, bool arg1) {
    signed char *pData = &AbilityTable[arg0 * 16];
    signed char group = pData[4];
    if ((unsigned int)pData[5] >= 4) {
        CdsAssert("Player.cpp", 0x1D8E, "(u_int)pData->iGroup < ICON_GROUP");
    }
    signed char *row = (signed char *)((char *)this + pData[5] * 8 + 0x22B);
    int i = 0;
    do {
        int idx = *row;
        row++;
        if (idx >= 0 && group == AbilityTable[idx * 16 + 4]) {
            if (idx == arg0) {
                return -3;
            }
            if (arg1 && arg0 < idx) {
                return -2;
            }
        }
        i++;
    } while (i < 8);
    return -1;
}

// DRAFT: 0x0015ACE0 GetAbility__6PlayerFv
// note: 47 words; goto-entered unsigned loop, case 32 first and > tests fix the shape; buf is addressed through sp+N where the original keeps a base register (t4/a0) and the table row pointer in t5. Tried buf pointer local (67-70), row pointer (48), for second loop (48), (int)i > 0 guard (49).
signed char Player::GetAbility() {
    static signed char BonusTable[16] = {
        32, 30, 30, 20, 31, 30, 26, 15, 32, 30, 30, 15, 31, 30, 26, 10
    };
    signed char buf[32];
    int sum = 0;
    unsigned int i;
    int row = mbHard__15EntityBaseClass * 8;
    i = 0;
    goto test;
loop:
    {
        signed char type = BonusTable[row + i];
        signed char value = BonusTable[row + i + 1];
        buf[i + 1] = type;
        switch (type) {
        case 32:
            break;
        case 30:
            if (m_unk1D8 % 200 > 100) {
                value = 1;
            }
            break;
        case 31:
            if (m_unk20C > 0x300) {
                value = 1;
            }
            break;
        case 26:
            if (m_unk1DC >= m_unk1D4) {
                value = 0;
            }
            break;
        }
        buf[i] = value;
        sum += value;
    }
    i += 2;
test:
    if (i < 16) goto loop;
    int r = MathAPI::RandomIntRange(0, sum);
    if (0 < (int)i) {
        int j = 0;
        do {
            if (buf[j] != 0) {
                r -= buf[j];
                if (r <= 0) {
                    return buf[j + 1];
                }
            }
            j += 2;
        } while (j < (int)i);
    }
    CdsAssert("Player.cpp", 0x1D82, "0");
    return 0;
}

// DRAFT: 0x0015AE60 SetPowerupMotion__6PlayerFi
// note: 27 words; original keeps 0x3D in v0 and uses a shared jr-ra exit (size 0x80); ours uses v1/a2 and separate epilogues (size 0x6c). Tried separate returns (28), goto exit (27), nested with result (27), reversed compare (27), switch-form nesting (27), early-return guard with 0x3D/4 tests first (28), swapped && operands (28).
int Player::SetPowerupMotion(int arg0) {
    int result = 0;
    if (m_unk260 != 0x3D && m_unk229 < 4) {
        if (m_unk335 != 0 || (m_unk264 & 0x30)) {
            if (m_unk38[0x42] & 1) {
                result = SetAction(arg0);
            }
        }
    }
    return result;
}

// FUNCTION: 0x0015AEE0 GetBoxer__6PlayerFi
void Player::GetBoxer(int arg0) {
    GameVarSet(0x11, arg0 - 0x15);
    gInterface.AddAbility(arg0);
}

// FUNCTION: 0x0015AF20 SwapAbility__6PlayerFi
void Player::SwapAbility(int arg0) {
    int temp;
    signed char *entry = &AbilityTable[arg0 * 16];
    switch (entry[5]) {
    case 0:
    case 2:
        temp = m_unk1FC;
        if ((arg0 ^ temp) & 2) {
            m_unk22A = (signed char)temp;
        }
        m_unk1FC = arg0;
        SetSword();
        if (m_unk260 < 0x3F) {
            if (m_unk260 == 0x3A) {
                m_unk260 = 0;
            }
            SetAction(m_unk260);
        }
        break;
    case 1:
        GameVarSet(0xF, arg0 - 4);
        break;
    case 3:
        GameVarSet(0x11, arg0 - 0x15);
        break;
    default:
        return;
    }
    ((EntityBaseClass *)this)->PlaySound(0xE4U);
}

// DRAFT: 0x0015B020 SetAbility__6PlayerFii
// note: 154 words; the clamp temp lands in v1 (original uses a1), so lui AbilityTable is not hoisted into the blez slot; the original shares one exit and a 0x280 size vs our 0x29c. Variants tried: `arg0 > 0x25`, `arg0 - 0x25 > 0`, `int t = arg0 - 0x25`.
void Player::SetAbility(int arg0, int arg1) {
    if (arg1 == 0 && m_unk335 != 0) {
        arg1 = 2;
    }
    if (arg0 - 0x25 > 0) {
        arg0 = 0x25;
    }
    int a6 = *(int *)&AbilityTable[arg0 * 16];
    switch (a6) {
    case -13:
        if (arg0 < 0x1E) {
            m_unk224 |= 1 << arg0;
        }
        return;
    case -12:
        GameVarAdd(0xC, 0xA, 0);
        ((EntityBaseClass *)this)->PlaySound(0x26C);
        return;
    case -11:
        m_unk214 = (arg0 == 0x12) ? 0x9F : 0x6A;
        if (m_unk28C) {
            SetShield(true);
        }
        gInterface.UpdateStatus(0x10, false);
        ((EntityBaseClass *)this)->PlaySound(0xE7);
        return;
    case -10:
        GameVarAdd(0xE, 0x280, arg1);
        if (arg1 < 2 && SetPowerupMotion(0x32) != 0 && arg1 != 0) {
            m_unk335 |= 2;
        }
        return;
    case -9:
        GameVarAdd(1, 0xC8, arg1);
        return;
    case -8:
        GameVarAdd(2, 1, arg1);
        return;
    case -7:
        GameVarAdd(9, 1, 0);
        return;
    case -5:
        GameVarSet(0xF, arg0 - 4);
        gInterface.AddAbility(arg0);
        return;
    case -4:
        GetBoxer(arg0);
        return;
    case -3:
    case -2:
        GameVarSet(0xA, arg0);
        gInterface.AddAbility(arg0);
        return;
    case -1:
        GameVarAdd(0xD, 1, 0);
        GameVarAdd(0xE, 0x280, 0);
        return;
    default:
        m_unk1D0 |= a6;
        gInterface.AddAbility(arg0);
        return;
    }
}

// FUNCTION: 0x0015B2A0 ResurrectionMove__6PlayerFv
void Player::ResurrectionMove() {
    switch (m_unk250) {
    case 0:
            m_unk250 = 2;
            mEffectAPI__13EntityManager.CreateOneshot(0x81000038, 0x8200006D, (float (*)[4])((char *)m_unk3C + 0x80), (float (*)[4])((char *)m_unk3C + 0x90), 0, 0.5f, false, 0, false);
            break;
    }
}

// DRAFT: 0x0015B310 DialogMove__6PlayerFv
// note: 58 words differ, size 0x14c vs 0x144; if-chain with gotos. Differs: first compare delay slot (nop vs next constant), a1=3 reused for the 0x250 store, case1 tail store placement, extra SetAction reloc at 0x134. Best variant in src/scratch/Player-72973/Player_dialog_v4_58.cpp.
void Player::DialogMove() {
    void *pApparition;
    int state = m_unk250;
    if (state == 3) {
        goto case3;
    }
    if (state == 2) {
        goto case2;
    }
    if (state == 1) {
        goto case1;
    }
    if (state != 0) {
        return;
    }
    if (m_unk335 & 4) {
        m_unk335 = m_unk335 | 1;
    }
    m_unk250 = 1;
case1:
    m_unk1B6 = 0;
    m_unk1B7 = 0;
    m_unk1B0 &= 0xFBFF;
    m_unk1B2 &= 0xFBFF;
    pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk328);
    if (!(m_unk335 & 5)) {
        if (pApparition == 0 || *(unsigned char *)((char *)pApparition + 0x17A) == 0) {
            m_unk250 = 2;
        }
    }
    return;
case2:
    if (m_unk26B == 0) {
        m_unk250 = 3;
        m_unk264 = 0x4130;
        *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) = 0;
        m_unk335 &= ~2;
        pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk328);
        if (pApparition != 0) {
            *(signed char *)((char *)pApparition + 0xE8) = *(signed char *)((char *)pApparition + 0xE8) | 8;
        }
    }
    return;
case3: {
    int action = GetGroundAction();
    if (action != 0) {
        m_unk335 = 0;
        SetAction(action);
    }
    }
}

// DRAFT: 0x0015B460 GrabObjectMove__6PlayerFv
// note: 72 words; m_unk328 and gp load order before the jal, assert delay slot nop vs lui, switch compare order differ
void Player::GrabObjectMove() {
    gInterface.UpdateStatus(3, true);
    void *pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk328);
    if (pApparition == 0) {
        CdsAssert("Player.cpp", 0x1B7D, "pPling");
    }
    switch (m_unk250) {
    case 0:
        m_unk33B = 1;
        ShowPlayer(0);
        ((ApparitionVirtuals *)pApparition)->OnHitEvent(this, -1, 0x1FE, 0);
        m_unk250 = 1;
        return;
    case 1:
        if (((ApparitionVirtuals *)pApparition)->OnHitEvent(this, m_unk1B2, 0x1FE, 0) == 1) {
            m_unk250 = 2;
            gSound.SetMainMusicSpecialVolume(PSound::MUSIC_SPECIAL_VOLS_NONE);
            return;
        }
        return;
    case 2:
        if (((Camera *)(gEng + 0x19760))->ControlledByApp(m_unk328) == 0) {
            m_unk33B = 0;
            ShowPlayer(1);
            SetAction(0);
        }
        break;
    }
}

// DRAFT: 0x0015B6D0 AlignPosition__6PlayerFP15EntityBaseClass
// note: 93 words; the literal copy is a static (reloc kIdentity$458) not the rodata at 0x244220, and the frame keeps an extra s2 save
void Player::AlignPosition(EntityBaseClass *arg0) {
    float sp40[4];
    float sp50[4];
    float *vecA;
    float *vecB;
    float *dir;
    float *pv;
    float dot;
    float fScale;
    char *temp;
    static const float kIdentity[4] = {1.0f, 0.0f, 0.0f, 0.0f};

    if (arg0 != 0) {
        temp = (char *)m_unk3C;
        vecA = m_unk190;
        if (temp != 0) {
            vecA = (float *)(temp + 0x80);
        }
        temp = *(char **)((char *)arg0 + 0x3C);
        vecB = (float *)((char *)arg0 + 0x190);
        if (temp != 0) {
            vecB = (float *)(temp + 0x80);
        }
        sceVu0SubVector(sp40, vecB, vecA);

        temp = *(char **)((char *)arg0 + 0x3C);
        if (temp != 0) {
            dir = (float *)(temp + 0x40);
        } else {
            *(u_long128 *)sp50 = *(u_long128 *)kIdentity;
            temp = *(char **)((char *)arg0 + 0x3C);
            if (temp != 0) {
                pv = (float *)(temp + 0x90);
            } else {
                pv = (float *)((char *)arg0 + 0x1A0);
            }
            MathAPI::VectorRotateY((float (*)[4])sp50, pv[1]);
            dir = sp50;
        }

        dot = sceVu0InnerProduct(sp40, dir);
        if (!(FastMath_Fabs__Ff(dot) <= 0.1f)) {
            *(u_long128 *)sp40 = *(u_long128 *)dir;
            if (dot < 0.0f) {
                fScale = -0.05f;
            } else {
                fScale = 0.05f;
            }
            sceVu0ScaleVector(sp40, sp40, fScale);
            temp = (char *)m_unk3C;
            vecA = m_unk190;
            if (temp != 0) {
                vecA = (float *)(temp + 0x80);
            }
            sceVu0AddVector(sp40, sp40, vecA);
            *(int *)&sp40[3] = 0x3F800000;
            temp = (char *)m_unk3C;
            if (temp != 0) {
                *(u_long128 *)(temp + 0x80) = *(u_long128 *)sp40;
                ((unsigned char *)temp)[0x3E] = ((unsigned char *)temp)[0x3E] | 8;
                return;
            }
            *(u_long128 *)m_unk190 = *(u_long128 *)sp40;
        }
    }
}

// FUNCTION: 0x0015B9B0 UnlockGateMove__6PlayerFv
void Player::UnlockGateMove() {
    void *pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, *(unsigned int *)((char *)this + 0x328));
    if (pApparition != 0) {
        int state = m_unk250;
        int h = (int)m_unk3C[13];
        switch (state) {
        case 0:
            ((ApparitionVirtuals *)pApparition)->OnHitEvent(this, 0, 0x1FF, 0);
            m_unk250 = 1;
            break;
        case 1:
            if (h >= 0xD) {
                m_unk250 = 2;
                GameVarSub(8, 1);
                UpdateKey();
            }
            break;
        case 2:
            if (h >= 0x23) {
                m_unk250 = 3;
                ((EntityBaseClass *)this)->PlaySound(0x99);
            }
            break;
        }
        AlignPosition((EntityBaseClass *)pApparition);
    }
}

// DRAFT: 0x0015BAB0 UnlockChestMove__6PlayerFv
// note: 2 words differ; the m_unk328 load must precede the mpEntMgr gp load (delay slot), tried hoisting id, mgr copy, pre-declared pApparition, Player *self, *(unsigned int *)(this+0x328), id local, inline helper with swapped args, member call via EntityManager cast
void Player::UnlockChestMove() {
    int state = m_unk250;
    int h = (int)m_unk3C[13];
    switch (state) {
    case 0:
        if (!((float)h < 16.0f)) {
            m_unk250 = 1;
            GameVarSub(7, 1);
            UpdateKey();
        }
        break;
    case 1:
        if (h >= 0x19) {
            m_unk250 = 2;
            ((EntityBaseClass *)this)->PlaySound(0x99);
        }
        break;
    case 2:
        if (h >= 0x2D) {
            m_unk250 = 3;
            ((EntityBaseClass *)this)->PlaySound(0xB5);
        }
        break;
    case 3: {
        void *pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk328);
        if (pApparition == 0) {
            m_unk250 = 4;
            break;
        }
        if (!((float)h <= 70.0f)) {
            m_unk250 = 4;
            ((ApparitionVirtuals *)pApparition)->OnHitEvent(this, 0, 0x1FF, 0);
        }
        AlignPosition((EntityBaseClass *)pApparition);
        break;
    }
    }
}

// FUNCTION: 0x0015BC20 OpenChestMove__6PlayerFv
void Player::OpenChestMove() {
    if (m_unk250 == 0 && !(m_unk3C[0xD] <= 8.0f)) {
        m_unk250 = 1;
        void *pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, *(unsigned int *)((char *)this + 0x328));
        if (pApparition != 0) {
            ((ApparitionVirtuals *)pApparition)->OnHitEvent(this, 0, 0x1FD, 0);
        }
    }
}

// FUNCTION: 0x0015BCB0 SetDeath__6PlayerFv
void Player::SetDeath() {
    gPad.SetVibrate((Pad::VibType)0, 0);
    m_unk308 = 0;
    m_unk344 = 0;
    m_unk229 = 0;
    m_unk1D8 = 0x190;
    m_unk1DC = 2;
    int t = m_unk1F8;
    m_unk1F8 = t - 1;
    if (t) {
        if (m_unk20C < 0x1AA) {
            m_unk20C = 0x1AA;
        }
        ((MaximoMain *)gEng)->RestartGame(true);
    } else {
        ((MaximoMain *)gEng)->RestartGame(false);
    }
}

// FUNCTION: 0x0015BD50 CyclockDamageMove__6PlayerFv
void Player::CyclockDamageMove() {
    int state = m_unk250;
    switch (state) {
    case 0:
        m_unk10C &= 0xFEFFFFFF;
        m_unk250 = 1;
        /* fallthrough */
    case 1:
        if (!(m_unk1D0 & 1)) {
            m_unk250 = 2;
        }
        break;
    case 2: {
        void *pObj = *(void **)((char *)m_unk3C + 0x24);
        int r = (pObj != 0) ? (((AnimStateObject *)pObj)->Slot18() != 0) : 0;
        if (!(r & 0xFF)) {
            m_unk250 = 3;
            gSound.FadeOutAllMusic(0x1F4);
            if (m_unk1F8 <= 0) {
                SetDeath();
                m_unk250 = 4;
            } else {
                gInterface.FadeScreen(255.0f, 8.5f, true, (Interface::eFadeColor)0);
            }
        }
        break;
    }
    case 3:
        if (gInterface.m_unk425 == 0) {
            SetDeath();
        }
        break;
    }
}

// note: 27 words differ: the bool lives in a1 instead of v1 and the original's andi v1,v1,0xFF truncation is missing. Tried unsigned char flag (27), implicit int-to-bool assignment (27), int flag with if/else (42), and bool with pAnim == 0 || !IsAnimate (44).
// DRAFT: 0x0015BE80 DieMove__6PlayerFv
// note: 27 words differ: the bool lives in a1 instead of v1 and the original's andi v1,v1,0xFF truncation is missing. Tried a bool outside the switch (34), an unsigned char flag with a cast (no andi, still a1), and == 0 (andi added, a1 kept).
void Player::DieMove() {
    switch (m_unk250) {
    case 0: {
        PAnimFrame *pAnim = *(PAnimFrame **)((char *)m_unk3C + 0x24);
        bool animating = false;
        if (pAnim != 0) {
            animating = pAnim->IsAnimate() != 0;
        }
        if (!animating) {
            m_unk250 = 1;
            gSound.FadeOutAllMusic(0x1F4);
            if (m_unk1F8 > 0) {
                gInterface.FadeScreen(255.0f, 8.5f, true, (Interface::eFadeColor)0);
            } else {
                SetDeath();
                m_unk250 = 2;
            }
        }
        break;
    }
    case 1:
        if (gInterface.m_unk425 == 0) {
            SetDeath();
        }
        break;
    }
}

// DRAFT: 0x0015B5C0 GunDeckMove__6PlayerFv
// note: DIFF 32 words; original hoists first-arg moves into beqz delay slots (ours nop), and ours sign-extends m_unk3F (dsll32/dsra32). Tried !(m_unk3F&7) (32), local fx ptr (32), int local for m_unk3F (45), direct m_unk3C casts without s0 (54), nested if for s1 (32), &0x7 spelling (32).
void Player::GunDeckMove() {
    PMNode *s0 = (PMNode *)m_unk3C;
    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        m_unk330->Slot58(this, 0, 0x1FB, 0);
        if (m_unk288 != 0) {
            ((PMNode *)m_unk288)->EnableFx(false, true);
        }
        s0->EnableAnim(false, false);
    case 1:
        if (m_unk1B2 & 0x4000) {
            SetAction(3);
            m_unk330->SetPlayerLeftDeck();
            m_unk330 = 0;
            return;
        }
        {
            bool s1 = (m_unk1B0 & 0x8000) != 0;
            m_unk330->SetGunParams(m_unk1B4, s1);
            if (s1 && (s0->m_unk3F & 7) == 0) {
                s0->Slot1C(0);
            }
        }
        return;
    default:
        return;
    }
}

// FUNCTION: 0x0015BF70 InitCutScene__6PlayerFv
void Player::InitCutScene() {
    if (m_unk229 > 3) {
        SetMaximo(MaximoArmor[m_unk1DC], true);
    }
    ResetEye(false);
    ResetShield();
    if (m_unk2AC != 0) {
        EffectNode *e = mEffectAPI__13EntityManager.EffectValid(m_unk2AC);
        if (e != 0) {
            ((PMNode *)e->m_unk4)->ProcessFxTriggers(-1.0f, 0, true, false);
            mEffectAPI__13EntityManager.DeleteEffect(e);
        }
        m_unk2AC = 0;
        if (m_unk2B4 != 0) {
            ((EntityBaseClass *)this)->StopSoundBySoundRef(m_unk2B4);
            m_unk2B4 = 0;
        }
    }
    if (m_unk2A8 != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2A8);
        m_unk2A8 = 0;
    }
    if (m_unk2B0 != 0) {
        Projectile *p = (Projectile *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk2B0);
        if (p != 0) {
            p->Delete();
        }
        m_unk2B0 = 0;
    }
    ReleaseHeadCamera();
}

// FUNCTION: 0x0015C090 ResetShield__6PlayerFv
void Player::ResetShield() {
    if (m_unk2A4 != 0) {
        m_unk2A4->DeleteShield();
        ((EntityBaseClass *)m_unk2A4)->SetState(-2);
        m_unk2A4 = 0;
        SetShield(true);
    }
}

// FUNCTION: 0x0015C0E0 SetFlyingShield__6PlayerFP6Shield
void Player::SetFlyingShield(Shield *arg0) {
    SetShield(arg0 ? false : true);
    if (arg0 == 0 && m_unk2A4 != 0) {
        ((EntityBaseClass *)this)->PlaySound(0x1C);
        if (m_unk260 != 0x22 && m_unk260 != 0) {
            m_unk2A4 = arg0;
            return;
        }
        SetAction(0x23);
    }
    m_unk2A4 = arg0;
}

// DRAFT: 0x0015C170 ShieldThrowMove__6PlayerFv
// note: 190 differing lines; frame 0x70 vs 0x80 (original keeps a Physics pointer in s2), case-0 register swap, f20 select layout, mpEntMgr gp load, CdsAssert arm order, sqrtf (sqrt.s) and the extra 4 instructions in the tail; tried sp50/sp60 order, Physics local, int* local for case 0, if/else f20
void Player::ShieldThrowMove() {
    bool sp7C;
    float sp60[4];
    float sp50[4];
    float f20;
    unsigned int s0;
    float fDot;
    void *r;
    u_long128 *pVec;

    switch (m_unk250) {
    case 0:
        if (m_unk260 == 0x24) {
            m_unk38[1] = 0x3727C5AC;
            m_unk38[0x44] = 0;
        }
        m_unk2B4 = ((EntityBaseClass *)this)->PlaySound(0x38);
        m_unk250 += 1;
        /* fallthrough */
    case 1:
    case 32:
        if ((int)m_unk3C[13] >= (int)((unsigned char *)m_unk254)[4]) {
            m_unk23D2 = 1;
            *(float *)((char *)m_unk38 + 0x110) = *(float *)((char *)m_unk25C + 0x38);
            m_unk2A4 = (Shield *)Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 5, false, 0);
            if (m_unk2A4 == 0) CdsAssert("Player.cpp", 0x1992, "mpShield");
            f20 = (m_unk1D0 & 0x10) ? 41.0f : 20.5f;
            s0 = m_unk1D0 & 0x30;
            m_unk250 = -1;
            GameVarSub__6PlayerFUii(this, 0xE, m_unk214);
            *(u_long128 *)sp60 = *(u_long128 *)((char *)m_unk28C + 0x70);
            r = ComboTarget(0.5f, f20 * f20, false);
            if (r != 0) {
                if (((int *)r)[0xF] != 0) {
                    pVec = (u_long128 *)(((int *)r)[0xF] + 0x80);
                } else {
                    pVec = (u_long128 *)((char *)r + 0x190);
                }
                *(u_long128 *)sp50 = *pVec;
                sp50[1] += 2.0f;
                sceVu0SubVector(sp50, sp50, sp60);
                fDot = sceVu0InnerProduct(sp50, sp50);
                sceVu0ScaleVector(sp50, sp50, 0.7f / sqrtf(fDot));
                ((Physics *)m_unk38)->m_unk11C = Round180__Ff(m_unk1C4);
            } else {
                float a = 0.017453292f * ((Physics *)m_unk38)->m_unk11C;
                sp50[2] = 0.7f * -cosf(a);
                sp50[1] = 0;
                sp50[0] = 0.7f * -sinf(a);
            }
            sp50[3] = 1.0f;
            GetShieldPass(&sp7C);
            InitShield__6ShieldFP15EntityBaseClassfPA4_fPA4_fUiPbi(m_unk2A4, this, (f20 - 5.0f) / 0.7f, (float (*)[4])sp60, (float (*)[4])sp50, s0, &sp7C, m_unk210);
            sp60[0] = m_unk3C[0x20];
            sp60[2] = m_unk3C[0x22];
            *(u_long128 *)((char *)*(void **)((char *)m_unk2A4 + 0x38) + 0xA0) = *(u_long128 *)sp60;
        }
        /* fallthrough */
    case -1:
        return;
    }
}

// FUNCTION: 0x0015C490 IsMidasActive__6PlayerFv
void *Player::IsMidasActive() {
    switch (m_unk210) {
    case 1:
        if (m_unk2A4 != 0) {
            return m_unk2A4;
        }
        Player *p = this;
        if (!(m_unk264 & 2) || ((m_unk1B0 & 0x200) == 0)) {
            p = 0;
        }
        return p;
    }
    return 0;
}

// FUNCTION: 0x0015C4F0 GuardHitMove__6PlayerFv
void Player::GuardHitMove() {
    switch (m_unk250) {
    case 0:
        if (((EntityBaseClass *)this)->ProcessHitBack() == 0) {
            m_unk250 = 1;
        }
        break;
    }
}

struct ShieldPowerup {
    unsigned int a;
    unsigned int b;
    unsigned int c;
};

static ShieldPowerup ShieldPowerupTable[2] = {
    {0x81000047, 0x82000079, 0x1F},
    {0x8100023D, 0x820003EA, 0x2A2},
};

class PMidasShieldRings {
public:
    PMidasShieldRings();
    void Create(bool bFlag);
    char _pad000[0x10];
    int m_unk10;
    char _pad14[0x30 - 0x14];
    unsigned long long m_unk30;
    char _pad38[0x210 - 0x38];
};

// FUNCTION: 0x0015C540 GuardMove__6PlayerFv
// note: mwccps2 schedules this function by heap layout; it matches only with the file's current bytes
void Player::GuardMove() {
    if (!(m_unk1B0 & 0x200)) {
        EndAction();
        if (m_unk2AC != 0) {
            mEffectAPI__13EntityManager.DeleteEffect(m_unk2AC);
            m_unk2AC = 0;
            if (m_unk2B4 != 0) {
                ((EntityBaseClass *)this)->StopSoundBySoundRef(m_unk2B4);
                m_unk2B4 = 0;
            }
        }
    } else {
        AnimStateObject *s0 = ((PMNode *)m_unk3C)->m_unk24;
        if (s0->Slot28() != 0 || s0->Slot18() == 0) {
            SetAction(0x27);
            return;
        }
        {
            int m = m_unk210;
            switch (m) {
            case 1:
            case 2:
                if (m_unk2AC == 0 && (short)((PMNode *)m_unk3C)->m_unk34 >= ((unsigned char *)m_unk254)[4]) {
                    ShieldPowerup *e = &ShieldPowerupTable[m - 1];
                    float fHalf = 0.5f;
                    m_unk2AC = mEffectAPI__13EntityManager.CreateOneshot(e->a, e->b, (PMat4 *)((char *)m_unk28C + 0x40), (EntityBaseClass *)this, fHalf, 0, false);
                    if (m_unk2AC == 0) {
                        CdsAssert("Player.cpp", 0x1925, "mMidas");
                    }
                    EffectNode *temp = mEffectAPI__13EntityManager.EffectValid(m_unk2AC);
                    if (temp == 0) {
                        CdsAssert("Player.cpp", 0x1927, "pMidas");
                    }
                    ((PMNode *)temp->m_unk4)->SetAnimLoopCount(0, true);
                    if (m_unk2B4 == 0) {
                        m_unk2B4 = ((EntityBaseClass *)this)->PlaySound(e->c);
                    }
                    if (m == 1) {
                        PMidasShieldRings *p = new PMidasShieldRings;
                        if (p == 0) {
                            CdsAssert("Player.cpp", 0x192F, "apFx");
                        }
                        p->Create(true);
                        Add__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, p);
                        ((PMNode *)temp->m_unk4)->AttachFx((unsigned int)p, 0.0f, 0.0f, -1.0f, -1.0f, true);
                        PMidasShieldRings *q = new PMidasShieldRings;
                        if (q == 0) {
                            CdsAssert("Player.cpp", 0x1935, "apFx");
                        }
                        q->Create(false);
                        q->m_unk10 = GetFxTexture__16PParticleManagerFUi(gGfxEng + 0x154F00, 0x8400000D);
                        q->m_unk30 = 0x48;
                        Add__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, q);
                        ((PMNode *)temp->m_unk4)->AttachFx((unsigned int)q, 0.0f, 0.0f, -1.0f, -1.0f, true);
                    }
                }
                break;
            }
        }
    }
    Physics *pPhys = (Physics *)m_unk38;
    pPhys->m_unk11C = Round180__Ff(m_unk1C4);
}

// FUNCTION: 0x0015C8A0 MBlow2Move__6PlayerFv
void Player::MBlow2Move() {
    static struct {
        unsigned int id0;
        unsigned int id1;
    } MBlow2Effect[2] = {
        {0x810001bd, 0x82000361},
        {0x81000202, 0x820003b2},
    };

    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        int idx = (m_unk1FC != 0) ? 1 : 0;
        unsigned int *e = &MBlow2Effect[idx].id0;
        m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(e[0], e[1], 0, 0, (EntityBaseClass *)this, m_unk24C, true, 0, false);
        break;
    case 1:
        if ((int)((PMNode *)m_unk3C)->GetFrameTime() >= 0x20) {
            ((EntityBaseClass *)this)->PlaySound(0x191U);
            m_unk250 = 2;
        }
        break;
    }
}

// FUNCTION: 0x0015C960 MBlowMove__6PlayerFv
void Player::MBlowMove() {
    static struct {
        unsigned int id0;
        unsigned int id1;
    } MBlowEffects[3] = {
        {0x81000034, 0x8200006c},
        {0x81000272, 0x8200042d},
        {0x81000449, 0x82000746},
    };
    static unsigned short HBlowAttack[5] = {0x14, 0x1d, 0x19, 0x1e, 0xffff};

    int h = (int)m_unk3C[13];
    switch (m_unk250) {
    case 0: {
        m_unk250 = 1;
        int idx = (m_unk1D0 & 2) ? ((m_unk1D0 & 0x4000) ? 2 : 1) : 0;
        unsigned int *e = &MBlowEffects[idx].id0;
        m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(e[0], e[1], 0, 0, (EntityBaseClass *)this, 1.0f, false, 0, false);
        break;
    }
    case 1:
        if (h >= 0x10) {
            ((EntityBaseClass *)this)->PlaySound((m_unk1D0 & 2) ? 0x283U : 0x177U);
            m_unk250 = 2;
        }
        break;
    case 2:
        if (h >= 0x28 && CancelAttack(0x30) != 0) {
            return;
        }
        break;
    }
    if (m_unk1D0 & 2) {
        MultipleAttack(HBlowAttack);
    }
}

// DRAFT: 0x0015CA90 StabDownMove__6PlayerFv
// note: DIFF 18 words; original hoists the 0x400 constant, keeps var_v1 in $v1, and case 1 reuses the andi result for the tail test. Tried: local pointer for m_unk38, bits local removed, if-chain instead of switch (36 words).
void Player::StabDownMove() {
    int temp_a1 = m_unk250;
    int temp_f0 = (int)m_unk3C[13];
    int var_v1 = temp_f0 < 0x12;
    switch (temp_a1) {
    case 0:
        m_unk250 = 1;
        {
            int *p = m_unk38;
            p[0] = 0;
            p[2] = 0;
        }
        break;
    case 1:
        if (m_unk1B2 & 0x8000) {
            m_unk250 = 0x800;
        } else if (m_unk1B2 & 0x1000) {
            m_unk250 = 0x400;
        }
        /* fallthrough */
    case 0x800:
        var_v1 = temp_f0 < 0x12;
        /* fallthrough */
    case 0x400:
        if (var_v1 == 0) {
            m_unk250 |= 8;
        }
        break;
    }
    if (temp_f0 >= 0x4B) {
        CancelAttack(0x30);
    }
}

// FUNCTION: 0x0015CB60 SpinSlashMove__6PlayerFv
void Player::SpinSlashMove() {
    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        if (m_unk1FC == 1) {
            m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(0x81000322U, 0x82000555U, 0, 0, (EntityBaseClass *)this, m_unk24C, false, 0, false);
        }
        break;
    case 1:
        if ((int)((PMNode *)m_unk3C)->GetFrameTime() >= 4) {
            m_unk250 = 2;
            ((EntityBaseClass *)this)->PlaySound(0x2AU);
        }
        break;
    }
}

// FUNCTION: 0x0015CC30 CSliceMove__6PlayerFv
void Player::CSliceMove() {
    if (m_unk250 == 0) {
        m_unk250 = 1;
        if (m_unk1FC == 1) {
            m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(0x81000324U, 0x82000556U, 0, 0, (EntityBaseClass *)this, m_unk24C, false, 0, false);
        }
    }
    int t = (int)m_unk3C[13];
    if (t >= 0x28) {
        if (CancelAttack(0x30) != 0) {
            return;
        }
    } else if (t != 0 && (m_unk1B2 & 0x8000)) {
        m_unk250 |= 4;
    }
    if (m_unk250 & 4) {
        if (t >= 0x20) {
            float fR = 100.0f;
            ComboTarget(-1.0f, fR, true);
            SetAction(0x74);
        }
    }
}

// DRAFT: 0x0015CD50 SliceMove__6PlayerFv
// note: 5 words differ (since CSliceMove matched): CancelAttack branch form; also tried fR local with -1.0f literal (9) and one-case switch guards (42-46); earlier: (inverted test gives 27, a v1-first else gives 32), the ComboTarget literal order (a local float gives 9), and the t!=0 block placement.
void Player::SliceMove() {
    static unsigned char SliceMoves[2] = {0x00, 0x73};
    int v1;
    int t = (int)m_unk3C[13];
    if (t >= 0x20) {
        if (CancelAttack(0x30)) {
            return;
        }
        v1 = t < 0x12;
    } else {
        if (t != 0) {
            int a = 0;
            if (m_unk1B2 & 0x8000) {
                a = 1;
            }
            if (m_unk250 < a) {
                m_unk250 = a;
            }
        }
        v1 = t < 0x12;
    }
    if (v1 == 0 && m_unk250 != 0) {
        float fRange = 100.0f;
        float fDir = -1.0f;
        ComboTarget(fDir, fRange, true);
        SetAction(SliceMoves[m_unk250]);
    }
}

// FUNCTION: 0x0015CE30 Over3Move__6PlayerFv
void Player::Over3Move() {
    static unsigned short Over3Attacks[3] = {0x11, 0x0C, 0xFFFF};
    if (m_unk250 == 0) {
        m_unk250 = 1;
        if (m_unk1FC == 1) {
            m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(0x81000323, 0x82000554, 0, 0, (EntityBaseClass *)this, m_unk24C, false, 0, false);
        }
    }
    MultipleAttack(&Over3Attacks[0]);
}

// DRAFT: 0x0015CEC0 MTapMove__6PlayerFv
// note: 108 words differ; prologue saves s1/s2 in another order, the 0x270 test and s0 load are scheduled differently, branch targets at 0x002C/0x0030 differ. 6 of 8 attempts used.
void Player::MTapMove() {
    static unsigned int MTapEffects[4] = {0x8100006B, 0x820000BD, 0x81000327, 0x82000558};
    static int MTapTable[5] = {0x13, 0x1B, 0x23, 0x2B, 0xFFFF};
    static unsigned short MTapAttack[9] = {0x13, 0x12, 0x1B, 0x12, 0x23, 0x12, 0x34, 0x13, 0xFFFF};
    PMNode *node;
    int v;
    int state;
    int limit;
    unsigned int c;
    float f;

    state = m_unk270;
    node = (PMNode *)m_unk3C;
    if (state != 0) {
        v = state - 1;
        if (m_unk1B2 & 0x8000) {
            v = m_unk274;
        }
        m_unk270 = v;
    }
    if (node->m_unk3F & 4) {
        m_unk27C = 0;
        m_unk250 = 1;
        m_unk274 -= 1;
        if (ComboTarget(-1.0f, 100.0f, true) != 0) {
            ((Physics *)m_unk38)->m_unk11C = Round180__Ff(m_unk1C4);
        }
        if (m_unk274 >= HEAD_BUTT_COUNT) {
            goto block8;
        }
        goto block15;
    }
block8:
    state = m_unk250;
    limit = (int)node->m_unk34;
    switch (state) {
    case 5:
        break;
    case 4:
        if (limit >= 0x30) {
            m_unk250 = state + 1;
            ((EntityBaseClass *)this)->PlaySound(0x13C);
        }
        break;
    default:
        if (limit >= MTapTable[state]) {
            m_unk250 = state + 1;
            if (m_unk270 == 0) {
block15:
                m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(MTapEffects[m_unk1FC * 2], MTapEffects[m_unk1FC * 2 + 1], 0, 0, (EntityBaseClass *)this, m_unk24C, false, 0, false);
                m_unk250 = 4;
                c = ((unsigned char *)m_unk254)[5];
                f = (float)c;
                node->Slot10(f);
                node->SetAnimLoopCount(1, false);
                m_unk27C = 6;
                if (ComboTarget(-1.0f, 100.0f, true) != 0) {
                    ((Physics *)m_unk38)->m_unk11C = Round180__Ff(m_unk1C4);
                }
            }
        }
        break;
    }
    if (MultipleAttack(MTapAttack) != 0) {
        ((EntityBaseClass *)this)->PlaySound(m_unk1FC == 0 ? 0x24U : 0xB0U);
        if (m_unk27C == 8) {
            ShakeScreenUsingTable__9CameraAPIFiUi((void *)&mCameraAPI__13EntityManager, 0, 0U);
        }
    }
}

// DRAFT: 0x0015D140 DSlashMove__6PlayerFv
// note: DIFF 111 words; size 0x244 vs 0x258; lhu/andi register swap (flags s0, spin s4 in original), TAP_COUNT/TAP_TIMER reloc form differs; tried reorders of decls and v1/CancelAttack (120, 133)
void Player::DSlashMove() {
    static unsigned char DSlashMoves[8] = {0x00, 0x75, 0x72, 0x70, 0x0E, 0x11, 0x35, 0x12};
    int spin;
    unsigned short flags = m_unk1B2;
    spin = flags & 0x8000;
    int v1;
    if (spin != 0) {
        m_unk270 += 1;
    }
    PMNode *pNode = (PMNode *)m_unk3C;
    int frame = (int)pNode->m_unk34;
    if (frame >= 0x1D) {
        v1 = frame < 0x14;
        if (CancelAttack(0x30) != 0) {
            return;
        }
    } else {
        int s2;
        int s3;
        if (frame >= 0xC && (flags & 0x9000)) {
            s2 = 0;
            s3 = 0;
            if (m_unk1C0 != 0 && (short)m_unk1C0 < UP_TIME) {
                if (FastMath_Fabs__Ff(Round180__Ff(m_unk1C4 - pNode->m_unk94)) < 55.0f) {
                    s3 = 1;
                }
            }
            if (flags & 0x1000) {
                s2 = 7;
                if (s3 == 0) {
                    s2 = 4;
                    if (m_unk1BC >= 0x65 && (m_unk1D0 & 0x300) != 0) {
                        s2 = (m_unk1D0 & 0x200) ? 6 : 5;
                    }
                }
            } else if (spin != 0) {
                if (m_unk270 >= TAP_COUNT) {
                    s2 = 3;
                } else if (s3 != 0) {
                    s2 = 2;
                } else if (m_unk1BC >= 0x65) {
                    s2 = 1;
                }
            }
            if (m_unk250 < s2) {
                m_unk250 = s2;
            }
        }
        v1 = frame < 0x14;
    }
    if (v1 == 0) {
        if (m_unk250 != 0) {
            if (m_unk250 != 6 && m_unk250 != 5) {
            } else if (MightyBlowCheck(m_unk1D0) == 0) {
                m_unk250 = 4;
            }
            ComboTarget(-1.0f, 100.0f, 1);
            SetAction(DSlashMoves[m_unk250]);
            m_unk274 = TAP_TIMER;
            m_unk270 = TAP_TIMER;
        }
    }
}

// FUNCTION: 0x0015D3A0 HSpinMove__6PlayerFv
void Player::HSpinMove() {
    unsigned short *attack = &HSpin720Attack;
    if (m_unk260 == 0x40) {
        attack = &HSpin360Attack;
    }
    MultipleAttack(attack);
}

// DRAFT: 0x0015D3C0 Spin360Move__6PlayerFv
// note: 49 words; branch layout differs (original places the 720 and 360 blocks out of line), and the Spin360Attack address is hoisted before the compares; tried reordered store, folded index
void Player::Spin360Move() {
    static unsigned short Spin360Attack[3] = {0x10, 0x08, 0xFFFF};
    static unsigned short Spin720Attack[8] = {0x10, 0x08, 0x1E, 0x08, 0xFFFF, 0, 0, 0};
    static unsigned int SpinEffect[9] = {0x8100020C, 0x82000367, 0x81000201, 0x820003B1, 0x81000337, 0x8200057F, 0, 0, 0x8100006B};
    unsigned short *attack;
    switch (m_unk250) {
    case 0: {
        SpinEffectEntry *eff = 0;
        int fx = m_unk1FC;
        if (m_unk260 == 0x33) {
            m_unk250 = 1;
            if (fx != 0) {
                eff = (SpinEffectEntry *)&SpinEffect[4];
            }
        } else {
            m_unk250 = 2;
            eff = ((SpinEffectEntry *)SpinEffect) + ((fx != 0) ? 1 : 0);
            if (fx != 0) {
                ((EntityBaseClass *)this)->PlaySound(0xAD);
            }
        }
        if (eff != 0) {
            m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(eff->a, eff->b, 0, 0, (EntityBaseClass *)this, 1.0f, true, 0, false);
        }
    }
    case 1:
        attack = Spin360Attack;
        break;
    case 2:
        attack = Spin720Attack;
        break;
    }
    MultipleAttack(attack);
}

// FUNCTION: 0x0015D4C0 UpwardStrikeMove__6PlayerFv
void Player::UpwardStrikeMove() {
    static unsigned int UpperFx[2][2] = {{0x8100006A, 0x820000BC}, {0x810001ED, 0x8200039A}};
    static unsigned short UpwardStrikeAttack[7] = {0x0F, 0x14, 0x10, 0x14, 0x11, 0x15, 0xFFFF};
    switch (m_unk250) {
    case 0: {
        m_unk250 = 1;
        int idx = (m_unk1FC == 1) ? 1 : 0;
        unsigned int *row = &UpperFx[idx][0];
        m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(row[0], row[1], 0, 0, (EntityBaseClass *)this, m_unk24C, false, 0, false);
        break;
    }
    case 1:
        if ((int)m_unk3C[13] >= 0x2D && CancelAttack(0x30) != 0) {
            return;
        }
        break;
    }
    MultipleAttack(&UpwardStrikeAttack[0]);
}

// FUNCTION: 0x0015D5A0 MultipleAttack__6PlayerFPUs
int Player::MultipleAttack(unsigned short *arg0) {
    unsigned short *pEntry = arg0 + m_unk27C;
    if ((int)m_unk3C[13] >= pEntry[0]) {
        ((EntityBaseClass *)this)->ResetCollisions();
        m_unk258 = &AttackTable[pEntry[1]];
        SetPlayerAttack(((AttackEntry *)m_unk258)->m_unk0, ((AttackEntry *)m_unk258)->m_unk2 | (m_unk15E & 0x1C0));
        m_unk27C += 2;
        return 1;
    }
    return 0;
}

// DRAFT: 0x0015D660 AirSlash2Move__6PlayerFv
// note: 24 words differ: branch sense at 0x0020 (orig beqz a3 to state-0 block, ours bnez); m_unk250 in $a3 orig vs $a0 ours. Tried: state local, per-store reload, empty then-branch.
void Player::AirSlash2Move() {
    static unsigned char Air2Moves[5] = {0x00, 0x00, 0x71, 0x0f, 0x10};
    int h = (int)m_unk3C[13];
    if (m_unk250 == 0) {
        m_unk250 = 1;
        float *f = (float *)m_unk38;
        f[0] = f[0] * AIR_ATTACK_SPEED;
        m_unk38[1] = 0;
        f[2] = f[2] * AIR_ATTACK_SPEED;
        m_unk38[0x44] = 0;
        return;
    }
    if (h >= 0x18) {
        return;
    }
    int a2 = 0;
    if (m_unk1B2 & 0x1000) {
        a2 = (m_unk268 >= 2) ? 4 : 3;
    } else if (m_unk1B2 & 0x8000) {
        a2 = 2;
    }
    if (m_unk250 < a2) {
        m_unk250 = a2;
    }
    if (h < 0xF) {
        return;
    }
    if (m_unk250 >= 2) {
        ComboTarget(-1.0f, 100.0f, true);
        SetAction(Air2Moves[m_unk250]);
    }
    *(float *)((char *)m_unk38 + 0x110) = *(float *)((char *)m_unk25C + 0x38);
}

// DRAFT: 0x0015D790 AirSlashMove__6PlayerFv
// note: 93 words differ: AirMoves is a plain local because the original's function-local static (79 words) broke DuckLaunchMove MATCH; a2/m_unk250 swap, ternary 2:0 emits movz, m_unk250==0 block layout
void Player::AirSlashMove() {
    unsigned char AirMoves[5] = {0x00, 0x00, 0x26, 0x0f, 0x10};
    int h = (int)m_unk3C[13];
    int st = m_unk250;
    int a2;
    if (st == -1) {
        return;
    }
    if (st == 0) {
        m_unk250 = 1;
        float *f = (float *)m_unk38;
        f[0] = f[0] * AIR_ATTACK_SPEED;
        f[2] = f[2] * AIR_ATTACK_SPEED;
        m_unk38[1] = 0x33D6BF95;
        m_unk38[0x44] = 0;
        return;
    }
    if (h >= 0x14) {
        return;
    }
    if (m_unk1D0 & 2) {
        a2 = 0;
    } else if (m_unk1B2 & 0x1000) {
        a2 = (m_unk268 < 2) ? 3 : 4;
    } else {
        a2 = (m_unk1B2 & 0x8000) ? 2 : 0;
    }
    if (m_unk250 < a2) {
        m_unk250 = a2;
    }
    if (h < 0xE) {
        return;
    }
    *(float *)((char *)m_unk38 + 0x110) = *(float *)((char *)m_unk25C + 0x38);
    if (m_unk250 < 2) {
        return;
    }
    if (*(float *)((char *)m_unk38 + 0xF8) < 1.0f) {
        m_unk250 = -1;
        return;
    }
    ComboTarget(-1.0f, 100.0f, true);
    SetAction(AirMoves[m_unk250]);
}

// FUNCTION: 0x0015D900 DuckLaunchMove__6PlayerFv
void Player::DuckLaunchMove() {
    int t = (int)m_unk3C[13];
    if (t >= 0x1E) {
        if (CancelAttack(0x30) != 0) {
            return;
        }
    } else if (t != 0) {
        unsigned short f = m_unk1B2;
        if (f & 0x8000) {
            m_unk250 |= 4;
        }
        if (f & 0x1000) {
            m_unk250 |= 8;
        }
    }
    if (t >= 0xB && m_unk250 != 0) {
        float fLo = -1.0f;
        float fHi = 100.0f;
        ComboTarget(fLo, fHi, true);
        SetAction((m_unk250 & 8) ? 0xE : 0xC);
    }
}

// FUNCTION: 0x0015D9F0 HammerSliceMove__6PlayerFv
void Player::HammerSliceMove() {
    if (((int)m_unk3C[13] < 0x32 || CancelAttack(0x30) == 0) && m_unk250 == 0 && (int)m_unk3C[13] >= 0x1C) {
        m_unk250 = 1;
        SetShockwave(10);
    }
}

// FUNCTION: 0x0015DA80 HammerDSlashMove__6PlayerFv
void Player::HammerDSlashMove() {
    if (m_unk250 == 0 && (int)m_unk3C[13] > 0x14) {
        m_unk250 = 1;
        SetShockwave(10);
    }
}

// DRAFT: 0x0015DAD0 HammerSlashMove__6PlayerFv
// note: 22 words (single-case switch on m_unk250); cancel-path shape and slti/bnez at branch form at t>=0x33 differ. Tried: 65 flat, 68 nested, flipped compares 0x32 < t, 0x1A >= t, t <= 0x1A (22, no gain).
void Player::HammerSlashMove() {
    static unsigned char HammerSlashMoves[3] = {0x00, 0x00, 0x45};
    int t;
    int var_a1;
    int var_a1_2;
    int temp_a2;

    switch (m_unk250) {
    case 0:
            m_unk250 = 1;
            m_unk270 = -1;
            break;
    }
    t = (int)m_unk3C[13];
    if (t >= 0x33) {
        if (CancelAttack(0x30) != 0) {
        }
    } else if (t < 0x1B) {
        if (SpinCheck() != 0) {
            m_unk250 = 4;
        }
    } else {
        temp_a2 = m_unk250;
        if (temp_a2 == 4) {
            var_a1 = 0x40;
            if (m_unk1D0 & 0x20000) {
                var_a1 = 0x41;
                if (m_unk1FC == 3) {
                    var_a1 = 0x42;
                }
            }
            SetAction(var_a1);
            return;
        }
        var_a1_2 = 0;
        if (m_unk1B2 & 0x8000) {
            var_a1_2 = 2;
        }
        if (temp_a2 < var_a1_2) {
            m_unk250 = var_a1_2;
        }
        if ((t >= 0x22) && (m_unk250 >= 2)) {
            ComboTarget(-1.0f, 100.0f, true);
            SetAction(HammerSlashMoves[m_unk250]);
        }
    }
}

// FUNCTION: 0x0015DC20 CancelMove__6PlayerFv
void Player::CancelMove() {
    if ((int)m_unk3C[13] >= ((unsigned char *)m_unk254)[4]) {
        CancelAttack(0x30);
    }
}

// DRAFT: 0x0015DC70 SlashMove__6PlayerFv
// note: 81 words differ, size 0x200 vs 0x20C; original tests a0 via sltu/beqz, re-sign-extends a0 (dsll32/dsra32) before the UP_TIME compare, and the movz s1 order differs. Tried s2/s3 order, nested ifs, bool nz, combined && (all 81).
void Player::SlashMove() {
    static unsigned char SlashMoves[7] = {0x00, 0x00, 0x38, 0x72, 0x0E, 0x12, 0x33};
    int s0;
    int s1;
    unsigned short s2;
    int s3;

    if (m_unk250 == 0) {
        m_unk250 = 1;
        m_unk270 = -1;
    }
    s0 = (int)m_unk3C[13];
    if (s0 < 14) {
        if (SpinCheck()) {
            m_unk250 = 6;
        }
    } else if (m_unk250 == 6) {
        FreeJoint(5);
        m_unk1C4 = ((Physics *)m_unk38)->m_unk11C;
        SetAction((m_unk1D0 & 0x1000) ? 0x34 : 0x33);
        return;
    }
    s1 = 0;
    if (s0 != 0) {
        short a0 = m_unk1C0;
        s2 = m_unk1B2;
        s3 = 0;
        if (a0 != 0) {
            if (a0 < UP_TIME) {
                if (FastMath_Fabs__Ff(Round180__Ff(m_unk1C4 - m_unk3C[37])) < 55.0f) {
                    s3 = 1;
                }
            }
        }
        if (s2 & 0x1000) {
            s1 = s3 ? 5 : 4;
        } else if (s2 & 0x8000) {
            s1 = s3 ? 3 : 2;
        }
        if (m_unk250 < s1) {
            m_unk250 = s1;
        }
    }
    if (s0 < 0x19) {
        return;
    }
    if (m_unk250 >= 2) {
        ComboTarget(-1.0f, 100.0f, true);
        SetAction((int)SlashMoves[m_unk250]);
        m_unk270 = 0;
        return;
    }
    if (s0 < 0x20) {
        return;
    }
    CancelAttack((s0 < 0x28) ? 0x10 : 0x30);
}

// DRAFT: 0x0015DE80 SpinCheck__6PlayerFv
// note: DIFF 41; a1/a2 block layout tests +75 first where the original tests -74 first with beqz and daddu in the delay slot; default-first, flipped-sense and early-return variants reached 49, 50 and 52.
int Player::SpinCheck() {
    static signed char SpinIO[3][3] = {{7, 0, 1}, {6, -1, 2}, {5, 4, 3}};
    int a1;
    int a2;
    int v;
    if (m_unk1BC >= 0x4B) {
        a1 = (m_unk1B4 < -74) ? 0 : ((m_unk1B4 < 75) ? 1 : 2);
        a2 = (m_unk1B5 < -74) ? 2 : ((m_unk1B5 < 75) ? 1 : 0);
        signed char *row = &SpinIO[a2][0];
        v = *(row + a1);
        if (v >= 0) {
            if (m_unk270 < 0) {
                m_unk270 = v;
                m_unk278 = (v - 2) & 7;
            } else if (v == ((m_unk270 - 1) & 7)) {
                if (m_unk278 == v) {
                    return 1;
                }
                m_unk270 = v;
            }
        }
    }
    return 0;
}

// FUNCTION: 0x0015DF60 CancelAttack__6PlayerFUi
int Player::CancelAttack(unsigned int arg0) {
    m_unk264 |= arg0;
    if (m_unk2A4 == 0) {
        if ((m_unk38[0x42] & 1) && (m_unk1B0 & 0x200)) {
            return SetAction(0x27);
        }
    }
    return 0;
}

// DRAFT: 0x0015DFD0 ComboTarget__6PlayerFffb
// note: 98 words differ: original saves 3 float regs (f20-f22) and keeps vec at 0x90(sp); ours saves 5 (f20-f24, args copied before the m_unkEA test) and vec at 0x80(sp). Tried reusing arg1 as the running best: still 98.
void *Player::ComboTarget(float arg0, float arg1, bool arg2) {
    if (m_unkEA == 0) {
        return 0;
    }
    float ang = 0.017453292f * m_unk1C4;
    float vec[4];
    vec[0] = sinf(ang);
    vec[1] = 0.0f;
    vec[2] = cosf(ang);
    vec[3] = 0.0f;
    float *pos = (float *)((char *)m_unk3C + 0x80);
    PArray *pa = (PArray *)((char *)mpEntMgr__15EntityBaseClass + 0x50B0);
    pa->m_unk4 = 0;
    char *s5 = (pa->m_unk0 != 0) ? (char *)pa->m_unk8[0] : 0;
    char *s2 = 0;
    float d[4];
    float res[4];
    while (s5 != 0) {
        if ((!arg2 || *(int *)(s5 + 0x10) == 3) && s5[0xEA] != 0 && *(char **)(s5 + 0x3C) != 0) {
            unsigned int kind = (unsigned char)s5[0x163] - 1;
            if (kind < 4) {
                float *target;
                if (*(char **)(s5 + 0x3C) != 0) {
                    target = (float *)(*(char **)(s5 + 0x3C) + 0x80);
                } else {
                    target = (float *)(s5 + 0x190);
                }
                sceVu0SubVector(d, pos, target);
                if (FastMath_Fabs__Ff(d[1]) < 10.0f) {
                    float dd = sceVu0InnerProduct(d, d);
                    if (dd < arg1) {
                        sceVu0Normalize(d, d);
                        float dot = sceVu0InnerProduct(d, vec);
                        if (!(dot < arg0)) {
                            float v = dd * (2.0f - dot);
                            if (v < arg1) {
                                arg1 = v;
                                s2 = s5;
                                res[0] = d[0];
                                res[1] = d[1];
                                res[2] = d[2];
                                res[3] = d[3];
                            }
                        }
                    }
                }
            }
        }
        pa->m_unk4++;
        s5 = (pa->m_unk4 < (int)pa->m_unk0) ? (char *)pa->m_unk8[pa->m_unk4] : 0;
    }
    if (s2 == 0) {
        m_unk1CC = 0;
        return 0;
    }
    m_unk1CC = *(int *)(s2 + 4);
    m_unk1C4 = Round180__Ff(atan2f(res[0], res[2]) * 57.29578f);
    return s2;
}

// FUNCTION: 0x0015E250 AirSliceMove__6PlayerFv
void Player::AirSliceMove() {
    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        m_unk38[1] = 0x3A83126F;
        break;
    }
}

// FUNCTION: 0x0015E280 AirOverheadMove__6PlayerFv
void Player::AirOverheadMove() {
    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        {
            float *p = (float *)m_unk38;
            p[0] = p[0] * AIR_ATTACK_SPEED;
            p[2] = p[2] * AIR_ATTACK_SPEED;
            ((int *)p)[1] = 0x33D6BF95;
        }
        m_unk38[0x44] = 0;
        return;
    case 1:
        {
            unsigned int f = m_unk1B2;
            if (f & 0x8000) {
                m_unk250 = 0x10000;
            } else if (f & 0x1000) {
                m_unk250 = 0x8000;
            }
        }
        /* fallthrough */
    default:
        if ((int)m_unk3C[13] >= 0x10) {
            *(float *)((char *)m_unk38 + 0x110) = FAST_G;
            m_unk250 |= 4;
        }
        return;
    }
}

// DRAFT: 0x0015E350 JumpMove__6PlayerFv
// note: 24 words differ (idx chain in original test order <0x32, <0x4B, <0x64 gave 32 to 24). Remaining: pVel/25C register choice (ours reloads m_unk25C into v0, original keeps a2), and the out[] stores. Tried: shared char *pBase for 0x25C (24), flipped pVel operands (24).
void Player::JumpMove() {
    switch (m_unk250) {
    case 0:
            m_unk250 = 1;
            float *pVel = (float *)((char *)m_unk25C + m_unk268 * 8 + 0x3C);
            int idx;
            if (m_unk1BC < 0x32) {
                idx = 0;
            } else if (m_unk1BC < 0x4B) {
                idx = 1;
            } else if (m_unk1BC < 0x64) {
                idx = 2;
            } else {
                idx = 3;
            }
            float out[4];
            out[1] = pVel[0];
            float fScale = -*(float *)((char *)m_unk25C + 0x18 + idx * 8) * pVel[1];
            if (m_unk23D1 != 0) {
                out[1] *= SLOW_JUMP;
            }
            out[3] = 1.0f;
            out[0] = fScale * FastMath_Sin180__Ff(m_unk1C4);
            out[2] = fScale * FastMath_Cos180__Ff(m_unk1C4);
            *(u_long128 *)m_unk38 = *(u_long128 *)out;
            m_unk268 += 1;
            if (m_unk38[0x42] & 0x200) {
                ((EntityBaseClass *)this)->PlaySound(0xE5);
            }
            break;
    }
    Physics *pPhys = (Physics *)m_unk38;
    pPhys->m_unk11C = Round180__Ff(m_unk1C4);
}

// FUNCTION: 0x0015E490 JogLandMove__6PlayerFv
void Player::JogLandMove() {
    static unsigned short JogLandStep[2] = {0x13, 0xFFFF};
    int action = GetGroundAction();
    switch (action) {
    case 2:
        FootStepSound(JogLandStep);
        break;
    default:
        SetAction(action);
        return;
    }
    Physics *phys = (Physics *)m_unk38;
    phys->m_unk11C = Round180__Ff(m_unk1C4);
    int idx;
    if (m_unk1BC < 0x32) {
        idx = 0;
    } else if (m_unk1BC < 0x4B) {
        idx = 1;
    } else if (m_unk1BC < 0x64) {
        idx = 2;
    } else {
        idx = 3;
    }
    char *entry = (char *)m_unk25C + idx * 8;
    float *pf = (float *)(entry + 0x18);
    float t = pf[0];
    if (m_unk1C8 > t) {
        m_unk1C8 = t;
    } else {
        m_unk1C8 = m_unk1C8 + pf[1];
    }
    ((Physics *)m_unk38)->SetVelocity(((Physics *)m_unk38)->m_unk11C, m_unk1C8);
}

// FUNCTION: 0x0015E590 GrimSliceMove__6PlayerFv
void Player::GrimSliceMove() {
    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(0x810001DE, 0x82000384, 0, 0, (EntityBaseClass *)this, 0.5f, false, 0, false);
        break;
    case 1:
        if ((int)((PMNode *)m_unk3C)->GetFrameTime() >= 0x21) {
            m_unk250 = 2;
            ((EntityBaseClass *)this)->PlaySound(0x11B);
        }
        break;
    }
}

// DRAFT: 0x0015E650 GrimThrowMove__6PlayerFv
// note: 30 words differ, size 0x1A8 vs 0x1AC; index/frame registers swapped at 0x0A8-0x0CC, else-if delay slot nop missing, 100.0f loaded after -1.0f, GrimThrowAttack$2267 reloc shifted; tried inline frame in delta, index local, named 100.0f local, split delta computation and frame-first delta (all 30, no gain)
void Player::GrimThrowMove() {
    static int GrimThrowFrames[3] = {52, 91, 4095};
    static unsigned short GrimThrowAttack[23] = {0x1F, 0x26, 0x2D, 0x26, 0x37, 0x26, 0x41, 0x27, 0x4B, 0x27, 0x55, 0x27, 0x5F, 0x27, 0x69, 0x27, 0x73, 0x27, 0x7D, 0x27, 0x87, 0x27, 0xFFFF};
    if (m_unk250 == 0) {
        m_unk250 = 1;
        ((!(m_unk2B4 != 0)) ? (void)0 : CdsAssert("Player.cpp", 0x1381, "!miSound"));
        m_unk2B4 = ((EntityBaseClass *)this)->PlaySound(0x110);
        m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(0x810002E3, 0x820004D1, 0, 0, (EntityBaseClass *)this, 1.0f, false, 0, false);
    }
    int frame = (int)((PMNode *)m_unk3C)->GetFrameTime();
    int delta = GrimThrowFrames[m_unk250 - 1] - frame;
    if (delta <= 0) {
        ((PMNode *)m_unk3C)->Slot10(141.0f);
        if (m_unk2A8 != 0) {
            EffectNode *e = mEffectAPI__13EntityManager.EffectValid(m_unk2A8);
            if (e) {
                ((PMNode *)e->m_unk4)->Slot10(141.0f);
            }
        }
        m_unk250 = 3;
    } else if (delta < 0x10 && (m_unk1B2 & 0x2000)) {
        m_unk250 = m_unk250 + 1;
        ComboTarget(-1.0f, 100.0f, true);
        Physics *ph = (Physics *)m_unk38;
        ph->m_unk11C = Round180__Ff(m_unk1C4);
    }
    MultipleAttack(GrimThrowAttack);
}

// FUNCTION: 0x0015E800 GrimProjectileMove__6PlayerFv
void Player::GrimProjectileMove() {
    static float vOffset[4] = {0.0f, 3.0f, -3.0f, 1.0f};
    float sp40[4];
    float sp50[4];
    switch (m_unk250) {
    case 0:
        *(int *)((char *)m_unk38 + 0x110) = 0;
        m_unk250 = 1;
        break;
    case 1:
        if ((int)m_unk3C[13] >= 0xC) {
            m_unk250 = 2;
            *(float *)((char *)m_unk38 + 0x110) = *(float *)((char *)m_unk25C + 0x38);
            void *proj = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2D, false, 0);
            if (proj != 0) {
                float *pm = m_unk3C;
                sceVu0ApplyMatrix(sp40, (float *)((char *)pm + 0x40), vOffset);
                void *tgt = ComboTarget(0.5f, 900.0f, false);
                if (tgt != 0) {
                    int sub = *(int *)((char *)tgt + 0x3C);
                    void *src = (char *)tgt + 0x190;
                    if (sub != 0) {
                        src = (char *)sub + 0x80;
                    }
                    sceVu0SubVector(sp50, (float *)src, sp40);
                    sceVu0Normalize(sp50, sp50);
                } else {
                    *(u_long128 *)sp50 = *(u_long128 *)((char *)pm + 0x60);
                    sceVu0ScaleVector(sp50, sp50, -0.7070000171661377f);
                    sp50[1] = -0.7070000171661377f;
                    sp50[3] = 1.0f;
                }
                InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(proj, 0, sp40, (float *)((char *)pm + 0x90), sp50);
            }
        }
        break;
    }
}

// FUNCTION: 0x0015E970 GrimSlash2Move__6PlayerFv
void Player::GrimSlash2Move() {
    if ((int)m_unk3C[13] >= 0x32) {
        CancelAttack(0x30);
    }
}

// DRAFT: 0x0015E9B0 GrimSlashMove__6PlayerFv
// note: DIFF 26 words; switch form with `lo = t < 0x19` hoisted: original keeps lo in v1 (ours in a3), and case-2 branch target and case-0 store order differ; if-chain form gave DIFF 54
void Player::GrimSlashMove() {
    int t = (int)m_unk3C[13];
    if (t >= 0x28) {
        CancelAttack(0x30);
        return;
    }
    int lo = t < 0x19;
    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        mEffectAPI__13EntityManager.CreateOneshot(0x810002DCU, 0x820004C8U, 0, 0, (EntityBaseClass *)this, 1.0f, false, 0, false);
        return;
    case 1:
        if (!(t >= 0xE && (m_unk1B2 & 0x8000))) {
            return;
        }
        m_unk250 = 2;
        lo = t < 0x19;
    case 2:
        if (lo == 0) {
            ComboTarget(-1.0f, 100.0f, true);
            SetAction(0x27);
        }
        return;
    }
}

// FUNCTION: 0x0015EAC0 GrimAirSlashMove__6PlayerFv
void Player::GrimAirSlashMove() {
    int temp = (int)m_unk3C[13];
    if (temp > 6) {
        if (m_unk1B2 & 0x8000) {
            m_unk250 = 1;
        }
        if (temp >= 0xC && m_unk250 != 0) {
            float fD = -1.0f;
            ComboTarget(fD, 100.0f, true);
            SetAction(0x26);
        }
    }
}

// FUNCTION: 0x0015EB60 GrimIdleMove__6PlayerFv
void Player::GrimIdleMove() {
    if (m_unk1BC >= 0x32) {
        SetAction(1);
        return;
    }
    int *p = m_unk38;
    float f = ((float *)p)[0x3E] - 0.5f;
    float v = 0.0f;
    if (f < 0.0f) {
        v = GRIM_G;
    } else if (!(f <= 1.5f)) {
        v = -GRIM_G;
    } else {
        m_unk268 = 0;
    }
    ((float *)p)[1] = v;
    p[0] = 0;
    p[2] = 0;
}

// FUNCTION: 0x0015EC00 GrimAirAttackMove__6PlayerFv
void Player::GrimAirAttackMove() {
    switch (m_unk250) {
    case 0:
        m_unk250 = 1;
        m_unk260 = 0x82;
        break;
    case 1:
        if ((int)((float *)m_unk3C)[13] < 9) {
            return;
        }
        m_unk250 = 2;
        {
            float v[4];
            v[3] = 1.0f;
            v[1] = GRIM_AIRATTACKG;
            v[0] = GRIM_AIRATTACKV * FastMath_Sin180__Ff(m_unk1C4);
            v[2] = GRIM_AIRATTACKV * FastMath_Cos180__Ff(m_unk1C4);
            *(u_long128 *)m_unk38 = *(u_long128 *)v;
        }
        {
            Physics *phys = (Physics *)m_unk38;
            phys->m_unk11C = Round180__Ff(m_unk1C4);
        }
        break;
    case 2:
        if (!(((Physics *)m_unk38)->m_unkF8 < GRIM_AIRATTACKY)) {
            return;
        }
        m_unk250 = 3;
        {
            PMNode *node = (PMNode *)m_unk3C;
            node->Slot10((float)(((unsigned char *)m_unk254)[5] + 1));
            node->SetAnimLoopCount(1, false);
        }
        ((float *)m_unk38)[0x110 / 4] = ((float *)m_unk25C)[0x38 / 4];
        ((Physics *)m_unk38)->SetPhysicsType(0x1032, 0);
        m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(0x810002E4, 0x820004D2, 0, 0, (EntityBaseClass *)this, 1.0f, false, 0, false);
        break;
    }
}

// DRAFT: 0x0015EDA0 GrimJumpMove__6PlayerFv
// note: 102 words differ; case 0 register allocation (constant 1, base, tier) and float setup order (neg.s/swc1/sw) differ; case 1 matches. Tried split base offset (102) and tier-first declaration order (110).
void Player::GrimJumpMove() {
    switch (m_unk250) {
    case 0: {
        m_unk250 = 1;
        char *base = (char *)m_unk25C;
        float *ent = (float *)(base + (m_unk268 << 3) + 0x3C);
        int bias = m_unk1BC;
        int tier;
        if (bias < 0x32) {
            tier = 0;
        } else if (bias < 0x4B) {
            tier = 1;
        } else if (bias < 0x64) {
            tier = 2;
        } else {
            tier = 3;
        }
        char *tb = base + 0x18;
        float f2 = *(float *)(tb + tier * 8);
        float f20 = -f2 * ent[1];
        float vec[4];
        vec[1] = ent[0];
        vec[3] = 1.0f;
        vec[0] = f20 * FastMath_Sin180__Ff(m_unk1C4);
        vec[2] = f20 * FastMath_Cos180__Ff(m_unk1C4);
        *(u_long128 *)m_unk38 = *(u_long128 *)vec;
        m_unk268 = 2;
        break;
    }
    case 1: {
        float *m = (float *)m_unk38;
        float v = m[1];
        float g;
        if (v <= 0.0f) {
            g = GRIM_JUMPG;
        } else {
            g = *(float *)((char *)m_unk25C + 0x38);
        }
        v = v - g * *(float *)(gEng + 0x1E8);
        m[1] = v;
        int tier;
        if (m_unk1BC < 0x32) {
            tier = 0;
        } else if (m_unk1BC < 0x4B) {
            tier = 1;
        } else if (m_unk1BC < 0x64) {
            tier = 2;
        } else {
            tier = 3;
        }
        float t0 = *(float *)((char *)m_unk25C + 0x18 + tier * 8);
        float t2 = *(float *)((char *)m_unk25C + 0x1C + tier * 8);
        if (m_unk1C8 <= t0) {
            m_unk1C8 = m_unk1C8 - t2;
        } else {
            m_unk1C8 = m_unk1C8 + t2;
        }
        float *p = m_unk3C ? (float *)((char *)m_unk3C + 0x90) : (float *)((char *)this + 0x1A0);
        ((Physics *)m_unk38)->SetVelocity(p[1], m_unk1C8);
        break;
    }
    }
    Physics *phys = (Physics *)m_unk38;
    phys->m_unk11C = Round180__Ff(m_unk1C4);
}

// FUNCTION: 0x0015F0E0 GrimRunMove__6PlayerFv
void Player::GrimRunMove() {
    float *fp = m_unk3C;
    int tier;
    if (m_unk1BC < 0x32) {
        tier = 0;
    } else if (m_unk1BC < 0x4B) {
        tier = 1;
    } else if (m_unk1BC < 0x64) {
        tier = 2;
    } else {
        tier = 3;
    }
    if (tier != 0) {
        switch (m_unk260) {
        case 1:
        case 2:
            if ((int)fp[13] >= *((unsigned char *)m_unk254 + 5)) {
                SetAction(2);
            }
            break;
        default:
            SetAction(2);
            break;
        }
    } else {
        EndAction();
        SetFrameRate__6PMNodeFfb((PMNode *)fp, 0.5f, false);
    }
    GrimMove();
}

// FUNCTION: 0x0015F1E0 SwimMove__6PlayerFv
void Player::SwimMove() {
    int action = GetGroundAction();
    switch (action) {
    case 0:
    case 10: {
        PMNode *node = (PMNode *)m_unk3C;
        int result = 0;
        if (node->m_unk24 != 0) {
            result = ((AnimStateCall *)node->m_unk24)->Slot28(action);
        }
        if (result != 0) {
            return;
        }
        node->SetAnimLoopCount(1, false);
        node->m_unk14.m_unk4 = 0;
        void **hdr = (void **)&node->m_unk14;
        void *p = (node->m_unk14.m_unk0 != 0) ? *(void **)hdr[2] : 0;
        *(unsigned char *)((char *)p + 0x3D) = 6;
        *(u_long128 *)m_unk38 = *(u_long128 *)&gUnitMatrix[12];
        return;
    }
    default:
        SetAction(action);
        return;
    case 11: {
        PMNode *node = (PMNode *)m_unk3C;
        int result = 0;
        if (node->m_unk24 != 0) {
            result = ((AnimStateCall *)node->m_unk24)->Slot28(action);
        }
        if (result == 0) {
            int moving = 0;
            if (node->m_unk24 != 0) {
                moving = ((AnimStateCall *)node->m_unk24)->Slot18() != 0;
            }
            if (!(moving & 0xFF)) {
                goto block_19;
            }
        } else {
block_19:
            SetAction(11);
        }
        Physics *phys = (Physics *)m_unk38;
        phys->m_unk11C = Round180__Ff(m_unk1C4);
        break;
    }
    }
}

// DRAFT: 0x0015F5E0 FootStepSound__6PlayerFPUs
// note: 6 words differ: addu index temp goes to a0 not a1, lhu/cvt order and mfc1 register swapped, slt sense inverted. Tried negated compare (31), index local (29), else-if sound chain (6, kept), flipped compare (7), temp local before index (6), temp local with flipped compare (7).
void Player::FootStepSound(unsigned short *arg0) {
    if ((signed char)(((signed char *)m_unk3C)[0x3F] & 4)) {
        m_unk27C = 0;
    }
    if (arg0[m_unk27C] <= (int)m_unk3C[13]) {
        unsigned int sound;
        if (m_unk38[0x42] & 0x200) {
            sound = 0x4E25;
        } else if (m_unk229 == 2) {
            sound = 0x4E20;
        } else {
            sound = FootSound[((unsigned int)m_unk38[0x3A] >> 11) & 7];
        }
        ((EntityBaseClass *)this)->PlaySound(sound);
        m_unk27C += 1;
    }
}

static float SLOW_RATE = 0.8f;

// DRAFT: 0x0015F330 RunMove__6PlayerFv
// note: 90 words; remaining: branch offsets 0x68-0xF8, Slot18 test shape, speed-index chain, SLOW_RATE and SetVelocity order, duplicated SetFrameRate tail 0x26C-0x284, size 0x298 vs 0x2a4; unsigned m_unk23D1 gives lbu but no gain.
void Player::RunMove() {
    int action = GetGroundAction();
    switch (action) {
    case 0:
        if (m_unk260 != 1) {
            SetAction(1);
        }
        if (EndAction() != 0) {
            *(u_long128 *)m_unk38 = *(u_long128 *)&gUnitMatrix[12];
        }
        return;
    default:
        SetAction(action);
        return;
    case 2: {
        static unsigned short RunSound[3] = {0x0F, 0x22, 0xFFFF};
        static unsigned short HammerRunSound[3] = {0x0000, 0x0009, 0xFFFF};
        unsigned short *snd = 0;
        switch (m_unk154) {
        case 0x82000002:
            snd = RunSound;
            break;
        case 0x820000CD:
            snd = HammerRunSound;
            break;
        }
        if (snd != 0) {
            FootStepSound(snd);
        }
    }
    /* fallthrough */
    case 1: {
        if (m_unk260 != action) {
            SetAction(action);
            return;
        }
        PMNode *node = (PMNode *)m_unk3C;
        int result = 0;
        if (node->m_unk24 != 0) {
            result = ((AnimStateRunCall *)node->m_unk24)->Slot28();
        } else {
            result = 0;
        }
        if (result == 0) {
            int moving = 0;
            if (node->m_unk24 != 0) {
                moving = ((AnimStateRunCall *)node->m_unk24)->Slot18(action) != 0;
            }
            if (!(moving & 0xFF)) {
                goto block_27;
            }
        } else {
block_27:
            SetAction(action);
        }
        Physics *phys = (Physics *)m_unk38;
        phys->m_unk11C = Round180__Ff(m_unk1C4);
        int idx;
        if (m_unk1BC < 0x32) {
            idx = 0;
        } else if (m_unk1BC < 0x4B) {
            idx = 1;
        } else if (m_unk1BC < 0x64) {
            idx = 2;
        } else {
            idx = 3;
        }
        char *rec = (char *)m_unk25C + idx * 8;
        float f2 = *(float *)(rec + 0x18);
        if (m_unk23D1 != 0) {
            f2 *= SLOW_RATE;
        }
        float f1 = m_unk1C8;
        if (!(f1 <= f2)) {
            m_unk1C8 = f2;
        } else {
            m_unk1C8 = f1 + *(float *)(rec + 0x1C);
        }
        phys->SetVelocity(phys->m_unk11C, m_unk1C8);
        float f12 = phys->m_unk100;
        if (f12 < 0.8f) {
            f12 = 0.8f;
        }
        if (!(m_unk264 & 0x40)) {
            f12 *= 0.5f;
        }
        if (m_unk23D1 != 0) {
            f12 *= SLOW_RATE;
        }
        SetFrameRate__6PMNodeFfb(node, f12, false);
        break;
    }
    }
}

// FUNCTION: 0x0015F6C0 RollMove__6PlayerFv
void Player::RollMove() {
    int v = (int)m_unk3C[0xD];
    if (v >= 14) {
        m_unk264 |= 0x30;
        if (m_unk1D0 & 4) {
            int g = GetGroundAction();
            if (g) {
                SetAction(g);
            }
        } else {
            SetAction(5);
        }
    } else if (v >= 12) {
        m_unk264 &= 0xFFFFEFFF;
    }
}

// note: 2 words differ: ours hoists `this` (daddu a0,s0,zero) into the beq delay slot at 0x34; the original has nop there and the move in the jal delay slot at 0x3C. Tried early-return split (13), nested if (2), swapped operands (3), guard return (13).
// DRAFT: 0x0015F770 LandingMove__6PlayerFv
void Player::LandingMove() {
    int action = GetGroundAction();
    if (action != 0xA && action != 0 && action != m_unk260) {
        SetAction(action);
    }
}

// note: DIFF 31 best; early-return guard, temp-based idle decrement, gEng local tried. Differs: idle-branch gEng/IdleActions load order, sign-extend of m_unk3F&4 (dsll32/dsra32), SetAction tail.
// DRAFT: 0x0015F7C0 StandMove__6PlayerFv
void Player::StandMove() {
    static int IdleActions[2][4] = {{0, 0x7e, 0x7f, 0}, {0, 0, 0x80, 0x81}};
    if (((Physics *)m_unk38)->m_unkF8 > 3.0f) {
        SetAction(5);
        return;
    }
    if (m_unk20 == 0) {
        switch (m_unk250) {
        case 0:
            m_unk340 = MathAPI::RandomIntRange(0x100, 0x1FF);
            m_unk250 = 1;
        case 1: {
            int g = GetGroundAction();
            if (g != m_unk260) {
                SetAction(g);
            } else if (g == 0) {
                int t = m_unk340 - 1;
                m_unk340 = t;
                if (t < 0 && (((PMNode *)m_unk3C)->m_unk3F & 4)) {
                    SetAction(IdleActions[m_unk1FC >> 1][(*(unsigned int *)(gEng + 0x19A80) >> 9) & 3]);
                    m_unk260 = 0;
                }
            }
            break;
        }
        }
    }
}

// note: 19 words differ; `unsigned int raw` gives srl (was 36). Left: beqz/bnez layout at 0x1C (original shares one return-0 exit through andi) and tail (original falls through to addiu v0,1; ours has b and a dead daddu v0,0). Tried bool ok (46-47), merged guards (44, 49), split early returns (54).
// DRAFT: 0x0015F8F0 EndAction__6PlayerFv
int Player::EndAction() {
    PMNode *node = (PMNode *)m_unk3C;
    if (node->m_unk24 == 0) {
        return 0;
    }
    if (node->m_unk24->Slot18()) {
        if (node->m_unk24 != 0 && node->m_unk24->Slot28() == 1) {
            return 0;
        }
        unsigned int raw = ((unsigned char *)m_unk254)[5];
        if ((signed char)raw != -1) {
            float f;
            if (raw >= 0) {
                f = (float)raw;
            } else {
                f = 2.0f * (float)((raw >> 1) | (raw & 1));
            }
            node->Slot10(f);
        }
        node->SetAnimLoopCount(1, false);
        return 1;
    }
    return 0;
}

// DRAFT: 0x0015FB40 SetAction__6PlayerFi
// note: 343 words differ: frame 0xC0 saving fp vs original 0xA0 with s0-s7, and every branch order differs; StatusTable$1966 lookup replaced by 0 (file-local symbol unnamed in C).
int Player::SetAction(int arg0) {
    unsigned char *pTbl;
    unsigned char *pAct;
    unsigned int nFlags;
    unsigned int nS2;
    unsigned int nSound;
    unsigned int nS5;
    int nAnim;
    float fScale;
    unsigned int nTmp;
    struct {
        short s0;
        short s1;
        short s2;
        short s3;
        short s4;
        short s5;
        float f;
    } tmp;

    pTbl = *(unsigned char **)((char *)this + 0x25C);
    if (arg0 >= *(int *)(pTbl + 4)) {
        return 0;
    }
    pAct = *(unsigned char **)pTbl + arg0 * 0x1C;
    if (*(unsigned int *)pAct == 0) {
        return 0;
    }
    nFlags = *(unsigned int *)(pAct + 8);
    if (!(*(int *)((char *)this + 0x1D0) & 1) && !(nFlags & 8)) {
        return 0;
    }
    m_unk269 = 0;
        *(unsigned char *)((char *)this + 0x163) = 0;
    nTmp = *(unsigned int *)((char *)this + 0x2B4);
    if (nTmp != 0) {
        ((EntityBaseClass *)this)->StopSoundBySoundRef(nTmp);
        *(unsigned int *)((char *)this + 0x2B4) = 0;
    }
    if (*(void **)((char *)this + 0x288) != 0 && *(int *)((char *)this + 0x260) == 0x3E) {
        EnableFx__6PMNodeFbb(*(void **)((char *)this + 0x288), 1, 1);
    }
    nS5 = *(unsigned short *)(pAct + 0xE);
    if (arg0 < 0x3F && (*(int *)((char *)this + 0x1D0) & 2) && *(signed char *)((char *)this + 0x229) < 4) {
        pAct = *(unsigned char **)pTbl + (HammerActions[arg0] * 0x1C);
        if (*(unsigned short *)(pAct + 0xE) != 0) {
            nS5 = *(unsigned short *)(pAct + 0xE);
        }
        nFlags = *(unsigned int *)(pAct + 8);
    }
    nS2 = nFlags & 0x400;
    *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) = (nS2 == 0) ? 0 : 8;
    if (nS2 != 0) {
        *(unsigned char *)((char *)this + 0x336) = 0;
    }
    *(signed char *)((char *)this + 0xE8) &= ~8;
    *(int *)((char *)this + 0x304) = 0;
    nAnim = LoadAnim__15EntityBaseClassFUib(this, *(unsigned int *)pAct, 1) & 0xFF;
    if (nAnim != 0) {
        *(unsigned int *)((char *)this + 0x264) = nFlags;
        *(signed char *)((char *)this + 0x103) = !(nFlags & 0x100) ? 0x20 : 0xFD;
        *(int *)((char *)this + 0x260) = arg0;
        *(unsigned char **)((char *)this + 0x254) = pAct;
        tmp.s0 = 0;
        tmp.s1 = -1;
        if (pAct[5] == 0) {
            tmp.s3 = -1;
            tmp.s2 = 0;
        } else {
            tmp.s3 = pAct[5];
            tmp.s2 = *(short *)(pAct + 4);
        }
        tmp.s4 = *(short *)(pAct + 6);
        if (nFlags & 0x8000) {
            FreeJoint(1);
        }
        fScale = (nFlags & 0x40) ? 1.0f : 0.5f;
        if (pAct[0xC] >= 0x2A) {
            CdsAssert("Player.cpp", 0x10EB, "pAct->iAttackID < sizeof(AttackTable) / sizeof(AttackData)");
        }
        nTmp = 0x8019FF55;
        *(unsigned char **)((char *)this + 0x258) = (unsigned char *)AttackTable + (pAct[0xC] * 0xC);
        if (nFlags & 1) {
            *(signed char *)((char *)this + 0x23D2) = 1;
            *(unsigned char *)((char *)this + 0x336) = 1;
            if (*(int *)((char *)this + 0x1FC) != 0) {
                if (*(unsigned short *)(*(unsigned char **)((char *)this + 0x258) + 6) != 0) {
                    nS5 = *(unsigned short *)(*(unsigned char **)((char *)this + 0x258) + 6);
                }
            }
            ((EntityBaseClass *)this)->ResetCollisions();
            if (pAct[7] == 2) {
                nTmp = 0x8019FFD5;
            }
            {
                unsigned char *pAtk = *(unsigned char **)((char *)this + 0x258);
                unsigned short nId = *(unsigned short *)(pAtk + 0);
                unsigned short nA2 = *(unsigned short *)(pAtk + 2);
                if (pAtk[8] != 0) {
                    switch (*(int *)((char *)this + 0x1FC)) {
                    case 1:
                        nA2 = (nA2 | 0x80) & 0xFFFF;
                        nId = (nId + 0x19) & 0xFFFF;
                        break;
                    case 2:
                        nA2 = (nA2 | 0x40) & 0xFFFF;
                        nId = (nId + 0x19) & 0xFFFF;
                        break;
                    case 3:
                        nId = (nId + 0x19) & 0xFFFF;
                        nA2 = (nA2 | ((pAtk[8] == 1) ? 0x140 : 0x40)) & 0xFFFF;
                        break;
                    }
                }
                SetPlayerAttack(nId, nA2);
            }
            if (*(signed char *)((char *)this + 0x23D1) != 0) {
                fScale *= SLOW_RATE;
            }
        } else {
            *(int *)((char *)this + 0x1CC) = 0;
            if (*(unsigned char *)((char *)this + 0x336) != 0 && nS2 == 0) {
                *(unsigned char *)((char *)this + 0x336) = 0;
                *(int *)((char *)this + 0x314) = 0;
                *(int *)((char *)this + 0x220) = 0;
                *(int *)((char *)this + 0x21C) = 0;
                ComboFinish__8HudComboFv((char *)&gInterface + 0x290);
            }
        }
        *(unsigned int *)(*(char **)((char *)this + 0x38) + 0xEC) = nTmp;
        if (nS5 != 0) {
            ((EntityBaseClass *)this)->PlaySound(nS5);
        }
        tmp.s5 = (short)pAct[7];
        if (*(unsigned char *)((char *)this + 0x26B) != 0 && tmp.s5 == 2) {
            tmp.s5 = 6;
        }
        tmp.f = fScale;
        *(float *)((char *)this + 0x24C) = fScale;
        SetAnimData__15EntityBaseClassFP8AnimData(this, (void *)&tmp);
        *(int *)((char *)this + 0x250) = 0;
        *(int *)((char *)this + 0x27C) = 0;
        *(float *)(*(char **)((char *)this + 0x38) + 0x11C) = Round180__Ff(*(float *)((char *)this + 0x1C4));
        if (nFlags & 0x2000) {
            SetPhysicsType__7PhysicsFUiPA4_f(*(void **)((char *)this + 0x38), 0x1030, 0);
        } else {
            *(float *)(*(char **)((char *)this + 0x38) + 0x110) = *(float *)(*(char **)((char *)this + 0x25C) + 0x38);
            SetPhysicsType__7PhysicsFUiPA4_f(*(void **)((char *)this + 0x38), 0x1032, 0);
        }
        if (nFlags & 0x200) {
            *(u_long128 *)*(char **)((char *)this + 0x38) = *(u_long128 *)&gUnitMatrix[12];
            *(int *)((char *)this + 0x1C8) = 0;
        }
        nTmp = *(unsigned int *)((char *)this + 0x2A8);
        if (nTmp != 0) {
            mEffectAPI__13EntityManager.DeleteEffect(nTmp);
            *(unsigned int *)((char *)this + 0x2A8) = 0;
        }
        if (!(nFlags & 2)) {
            nTmp = *(unsigned int *)((char *)this + 0x2AC);
            if (nTmp != 0) {
                mEffectAPI__13EntityManager.DeleteEffect(nTmp);
                *(unsigned int *)((char *)this + 0x2AC) = 0;
            }
        }
        if (*(void **)((char *)this + 0x2BC) != 0) {
            if (pAct[0xD] != 0) {
                SetData__16MotionBlurEffectFPv(*(void **)((char *)this + 0x2BC), (char *)&gMaximoMotionBlurTable + ((pAct[0xD] & 0xFF) << 7));
            } else {
                SetData__16MotionBlurEffectFPv(*(void **)((char *)this + 0x2BC), 0);
            }
        }
        if (*(unsigned char *)((char *)this + 0x229) == 4) {
            SetAnimation__15PGrimReaperCapeFUi((char *)this + 0x390, *(unsigned int *)pAct);
        }
    }
    return nAnim;
}

// note: 16 words differ: original keeps the constant 1 in v0 for the 0x9F path and loads 2/0 into v0 for the others; compiled code uses a2. Tried if/else chain (16 lines), int idx = 1 (about 14, branch layout differs).
// DRAFT: 0x00160090 GetShieldPass__6PlayerFPb
void Player::GetShieldPass(bool *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 1;
    int idx = 0;
    if (m_unk214 == 0x6A) {
        idx = 2;
    } else if (m_unk214 == 0x9F) {
        idx = 1;
    }
    arg0[idx] = 1;
}

// note: 26 words differ: this stays in s1 (original keeps it in s0), mesh/shield reload pattern after calls differs. Tried a top-level cached shield local (38), else-branch local (31), and the 26-word form kept.
// DRAFT: 0x001600F0 SetShield__6PlayerFb
void Player::SetShield(bool arg0) {
    bool pass[3];
    if (m_unk28C != 0) {
        if (arg0) {
            GetShieldPass(pass);
            PMNode *mesh = mpResMgr__15EntityBaseClass->GetResource(0x81000002, true);
            if (mesh == 0) {
                CdsAssert("Player.cpp", 0x1077, "pShield");
            }
            void *first = mesh->GetFirstMesh();
            PMNode *shield = (PMNode *)m_unk28C;
            shield->m_unk10 = first;
            shield->m_unk3E &= 0xEF;
            if (first != 0 && *((unsigned char *)first + 0xC) != 0) {
                shield->m_unk3E |= 0x10;
            }
            shield->SetRenderPassStatus(pass[0], pass[1], pass[2], true);
            shield->Slot14();
        } else {
            ((PMNode *)m_unk28C)->m_unk10 = 0;
            ((PMNode *)m_unk28C)->m_unk3E &= 0xEF;
        }
    }
}

// FUNCTION: 0x001601F0 UpdatePlayerFx__6PlayerFv
void Player::UpdatePlayerFx() {
    PMNode *temp_a1 = (PMNode *)m_unk288;
    if (temp_a1 != 0) {
        temp_a1->ProcessFxTriggers(1.0f, (PMat4 *)(*(char **)((char *)this + 0x284) + 0x40), false, false);
    }
}

// FUNCTION: 0x00160230 EnablePlayerShadow__6PlayerFb
void Player::EnablePlayerShadow(bool arg0) {
    bool *shadow = (bool *)m_unkD4;
    shadow[0] = arg0;
    char *sub = *(char **)((char *)shadow + 0xC);
    if (sub != 0) {
        *(bool *)(sub + 0x18) = arg0;
    }
    char *a = (char *)m_unk23C8;
    if (a != 0 && m_unk23CC != 0) {
        if (m_unk229 == 4) {
            *(bool *)a = 0;
            sub = *(char **)(a + 0xC);
            if (sub != 0) {
                *(bool *)(sub + 0x18) = 0;
            }
            char *b = (char *)m_unk23CC;
            *(bool *)b = 0;
            sub = *(char **)(b + 0xC);
            if (sub != 0) {
                *(bool *)(sub + 0x18) = 0;
            }
        } else if (m_unk1FC >= 2) {
            *(bool *)a = arg0;
            sub = *(char **)(a + 0xC);
            if (sub != 0) {
                *(bool *)(sub + 0x18) = arg0;
            }
            char *b = (char *)m_unk23CC;
            *(bool *)b = 0;
            sub = *(char **)(b + 0xC);
            if (sub != 0) {
                *(bool *)(sub + 0x18) = 0;
            }
        } else {
            *(bool *)a = 0;
            sub = *(char **)(a + 0xC);
            if (sub != 0) {
                *(bool *)(sub + 0x18) = 0;
            }
            char *b = (char *)m_unk23CC;
            *(bool *)b = arg0;
            sub = *(char **)(b + 0xC);
            if (sub != 0) {
                *(bool *)(sub + 0x18) = arg0;
            }
        }
    }
}

// DRAFT: 0x00160320 SetSword__6PlayerFv
// note: 101 words differ; child lands in v1 not a0 (register swap at 0x00D0-0x00D8), 0x284 not reloaded before the 0x110/0x124/0x144 calls, branch targets at 0x002C/0x003C, size 0x268 vs 0x280. Literal pool order, SwordTbl and mpResMgr relocations also differ. 7 of 8 attempts used.
void Player::SetSword() {
    m_unk1D0 &= ~2;
    if (m_unk284 != 0 && m_unk229 != 4) {
        unsigned int s0 = m_unk1FC;
        ((s0 < 4) ? (void)0 : CdsAssert("Player.cpp", 0x1004, "iSword < SwordPowerupMax"));
        if (m_unk288 != 0) {
            if (m_unk288 != 0) {
                ((VirtualSlot14Object *)m_unk288)->Slot08(1);
            }
            m_unk288 = 0;
        }
        SwordEntry *s1 = &SwordTbl[s0];
        PMNode *s2 = mpResMgr__15EntityBaseClass->GetResource(s1->uId, false);
        ((s2 != 0) ? (void)0 : CdsAssert("Player.cpp", 0x100C, "pSword"));
        void *child = s2->m_unk10;
        *((char *)child + 0xE) = 0;
        PMNode *node = (PMNode *)m_unk284;
        node->m_unk10 = child;
        node->m_unk3E &= 0xEF;
        if (child != 0 && *(int *)((char *)child + 0xC) != 0) {
            node->m_unk3E |= 0x10;
        }
        void *a1 = (char *)child + 0x10;
        *((unsigned char *)node + 0x3C) = 0;
        *(void **)((char *)node + 0x28) = a1;
        *(bool *)((char *)node + 0xD4) = true;
        *((unsigned char *)node + 0xD5) = 1;
        *((unsigned char *)node + 0xD6) = 1;
        *((unsigned char *)node + 0xD7) = 1;
        node->m_unk3E &= 0x7F;
        ((VirtualSlot14Object *)node)->Slot14(a1);
        *(float *)((char *)m_unk3C + 0x12C) = s1->fC;
        if (s0 != 0) {
            m_unk288 = s2;
            if (s1->b7 == 1) {
                m_unk1D0 |= 2;
            }
        }
        if (s2 != 0) {
            ((VirtualSlot14Object *)s2)->Slot08(1);
        }
        void *p23C8 = m_unk23C8;
        if (p23C8 != 0) {
            void *p23CC = m_unk23CC;
            if (p23CC != 0) {
                if ((int)m_unk1FC >= 2) {
                    void *sub = *(void **)((char *)p23C8 + 0xC);
                    if (sub != 0) {
                        SetShadowCaster__13PShadowVolumeFP6PMNode(sub, (void *)m_unk284);
                    }
                } else {
                    void *sub = *(void **)((char *)p23CC + 0xC);
                    if (sub != 0) {
                        SetShadowCaster__13PShadowVolumeFP6PMNode(sub, (void *)m_unk284);
                    }
                }
            }
        }
        EnablePlayerShadow(*(bool *)m_unkD4);
    }
    if (m_unk229 == 4) {
        void *p = m_unk23C8;
        if (p != 0 && m_unk23CC != 0) {
            *(char *)p = 0;
            void *q = *(void **)((char *)p + 0xC);
            if (q != 0) {
                *((char *)q + 0x18) = 0;
            }
            p = m_unk23CC;
            *(char *)p = 0;
            q = *(void **)((char *)p + 0xC);
            if (q != 0) {
                *((char *)q + 0x18) = 0;
            }
        }
    }
}

// FUNCTION: 0x001605A0 ResetEye__6PlayerFb
void Player::ResetEye(bool arg0) {
    PMNode *s1 = (PMNode *)m_unk3C;
    PMNode *v0 = s1->Find(0x4F1C44BDU);
    if (v0 != 0) {
        float *v1;
        if (arg0) {
            v1 = LEye;
        } else {
            v1 = &gUnitMatrix[12];
        }
        *(u_long128 *)((char *)v0 + 0x90) = *(u_long128 *)v1;
        *((unsigned char *)v0 + 0x3E) |= 8;
    }
    v0 = s1->Find(0x52D670E4U);
    if (v0 != 0) {
        float *v1;
        if (arg0) {
            v1 = REye;
        } else {
            v1 = &gUnitMatrix[12];
        }
        *(u_long128 *)((char *)v0 + 0x90) = *(u_long128 *)v1;
        *((unsigned char *)v0 + 0x3E) |= 8;
    }
}

// TODO(header): foreign declarations (SetMaximo)
extern "C" void *__ct__10PAnimFrameFs(void *pThis, short nId);
extern "C" void RestoreAnim__10PAnimFrameFP10PAnimFrame(void *pDst, void *pSrc);
extern "C" void *Create__16PParticleManagerFUifffP6PMNodeb(void *pThis, unsigned int nId, float fX, float fY, float fZ, void *pNode, bool bFlag);
extern "C" int IsValid__16PParticleManagerFP15PParticleSystem(void *pThis, void *pSys);
extern "C" void Enable__15PGrimReaperCapeFbP6PMNode(void *pCape, bool bOn, void *pNode);
extern "C" unsigned int CreateMotionBlurEffect__9EffectAPIFP6PMNodeUii(void *pThis, void *pNode, unsigned int nId, int nCount);
class VDel {
public:
    virtual ~VDel();
};
class PSysVirt {
public:
    virtual void Slot00();
    virtual void Slot04();
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
    virtual void Slot18();
    virtual void Slot1C(int arg0);
    virtual void Slot20();
};

// DRAFT: 0x00160660 SetMaximo__6PlayerFcb
// note: 346 words differ; nIdx lands in s0 not s3, frame/saved-reg set differs (original keeps arg2 in fp), static init flag not reproduced; tried m_unk2BC member and VDel virtual delete
void Player::SetMaximo(char arg0, bool arg1) {
    static char st_lastMaximo = 0;
    char spC0[0x40];
    bool bSkip = arg1;
    int nIdx = arg0;
    if (nIdx >= 5) {
        CdsAssert("Player.cpp", 0xEFF, "iMaximo < MAXIMO_NO");
    }
    if (m_unk2BC != 0) {
        mEffectAPI__13EntityManager.DeleteEffect(m_unk2BC);
        m_unk2BC = 0;
    }
    if (m_unk288 != 0) {
        delete (VDel *)m_unk288;
        m_unk288 = 0;
    }
    bool bFresh = false;
    __ct__10PAnimFrameFs(spC0, 0);
    int *pData = (int *)(mMaximoData__6Player + nIdx * 0x4C);
    if (m_unk25C == 0 || *pData != *(int *)m_unk25C) {
        bFresh = true;
    } else {
        memcpy(spC0, *(void **)((char *)m_unk3C + 0x24), 0x34);
    }
    unsigned char nShadow = *(unsigned char *)m_unkD4;
    unsigned int nMesh = pData[2];
    if (nIdx == 2) {
        if (m_unk218 == 4) {
            nMesh = 0x81000424;
        }
    }
    LoadMesh__15EntityBaseClassFUibb(this, nMesh, true, true);
    *(unsigned char *)m_unkD4 = nShadow;
    void *pSub = *(void **)((char *)m_unkD4 + 0xC);
    if (pSub != 0) {
        *(unsigned char *)((char *)pSub + 0x18) = nShadow;
    }
    PMNode *pSkel = (PMNode *)m_unk3C;
    if (pData[3] != 0) {
        PMNode *pEye = pSkel->Find(0x72799E69U);
        void *pRes = *(void **)((char *)mpResMgr__15EntityBaseClass->GetResource(pData[3], true) + 0x10);
        pEye->m_unk10 = pRes;
        pEye->m_unk3E &= 0xEF;
        if (pRes != 0) {
            if (*(int *)((char *)pRes + 0xC) != 0) {
                pEye->m_unk3E |= 0x10;
            }
        }
        BuildDispList__9PSkeletonFv(pSkel);
    }
    ResetEye(true);
    m_unk310 = 0;
    bool bBlur = true;
    unsigned int nHash = 0xB5714B5A;
    switch (nIdx) {
    case 4:
        bBlur = false;
        m_unk310 = 1.0f;
        m_unk2F8 = 0;
        nHash = 0xA1EDEE90;
        m_unk23D1 = 0;
        m_unk268 = 2;
        break;
    case 2:
        if (m_unk218 < 4) {
            EnableOneRenderPassOnly__6PMNodeFi(pSkel, m_unk218);
        }
        break;
    case 3:
        break;
    }
    m_unk284 = (int)pSkel->Find(nHash);
    *(PMNode **)((char *)this + 0x290) = pSkel->Find(0x8EA3DD30U);
    *(PMNode **)((char *)this + 0x294) = pSkel->Find(0x294D6F4FU);
    m_unk28C = pSkel->Find(0x6499DC24U);
    m_unk298[0] = pSkel->Find(0xC4DC9D1EU);
    m_unk298[1] = pSkel->Find(0xE263A967U);
    m_unk298[2] = pSkel->Find(0xFFF6BAB0U);
    BuildDispList__9PSkeletonFv(pSkel);
    Add__6PArrayFPv((char *)pSkel + 0x150, (void *)m_unk284);
    char *pInit = *(char **)(pData + 5);
    if (bFresh) {
        int nAct = 0;
        if (m_unk25C != 0) {
            void *pFx = 0;
            u_long128 vPos = *(u_long128 *)((char *)m_unk3C + 0x80);
            if (nIdx == 4) {
                if (m_unk2B8 == 0) {
                    m_unk2B8 = (void *)((EntityBaseClass *)this)->PlaySound(0x1C0U);
                }
                nAct = 0x25;
                EnableFullScreenFx__10PGfxEngineFb(gGfxEng, true);
                PMNode *pCape = ((PMNode *)m_unk3C)->Find(0x9980D6C3U);
                if (pCape != 0) {
                    Enable__15PGrimReaperCapeFbP6PMNode((char *)this + 0x390, true, pCape);
                    *(void **)((char *)this + 0x2370) = mpResMgr__15EntityBaseClass->GetResource(0x84000010U, false);
                }
            } else {
                if (m_unk2B8 != 0) {
                    ((EntityBaseClass *)this)->StopSoundBySoundRef((unsigned int)m_unk2B8);
                    m_unk2B8 = 0;
                }
                m_unkD0 = 0;
                EnableFullScreenFx__10PGfxEngineFb(gGfxEng, false);
                if (!bSkip) {
                    float *pv = (float *)&vPos;
                    pv[1] = pv[1] + 2.5f;
                    pFx = Create__16PParticleManagerFUifffP6PMNodeb(gGfxEng + 0x154F00, 0x8300034BU, pv[0], pv[1], pv[2], 0, true);
                }
                Enable__15PGrimReaperCapeFbP6PMNode((char *)this + 0x390, false, 0);
                float *pPhys = (float *)m_unk38;
                if (!(pPhys[0xF8 / 4] <= 0.0f)) {
                    nAct = 5;
                    m_unk38[1] = 0xB8D1B717;
                } else {
                    m_unk268 = 0;
                }
            }
            if (!bSkip) {
                if (pFx != 0 && IsValid__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, pFx)) {
                    ((PSysVirt *)pFx)->Slot20();
                }
                if (pFx != 0 && IsValid__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, pFx)) {
                    ((PSysVirt *)pFx)->Slot1C(0);
                }
            }
        }
        char *pPh = (char *)m_unk38;
        *(u_long128 *)(pPh + 0x80) = *(u_long128 *)pInit;
        *(u_long128 *)(pPh + 0x90) = *(u_long128 *)(pInit + 0x10);
        m_unk25C = pData;
        m_unk229 = arg0;
        SetAction(nAct);
    } else {
        char *pPh = (char *)m_unk38;
        *(float *)(pPh + 0x90) = *(float *)(pInit + 0x10);
        *(float *)(pPh + 0x98) = *(float *)(pInit + 0x18);
        LoadAnim__15EntityBaseClassFUib(this, **(unsigned int **)&m_unk254, true);
        pSkel->m_unk14.m_unk4 = 0;
        char *pNode;
        if (pSkel->m_unk14.m_unk0 != 0) {
            pNode = (char *)pSkel->m_unk14.m_unk8[0];
        } else {
            pNode = 0;
        }
        pNode[0x3D] = *((unsigned char *)m_unk254 + 7);
        *(float *)(pNode + 0x34) = *(float *)(spC0 + 0x2C);
        *(float *)(pNode + 0x38) = *(float *)(spC0 + 0x2C);
        RestoreAnim__10PAnimFrameFP10PAnimFrame(pSkel->m_unk24, spC0);
        unsigned int nEff = *(unsigned int *)((char *)this + 0x2AC);
        if (nEff != 0) {
            void *pE = mEffectAPI__13EntityManager.EffectValid(nEff);
            if (pE != 0) {
                *(char **)((char *)pE + 0x10) = (char *)m_unk28C + 0x40;
            }
        }
    }
    m_unk1C4 = *(float *)((char *)m_unk38 + 0x11C);
    *(u_long128 *)((char *)pSkel + 0x110) = *(u_long128 *)pInit;
    *(u_long128 *)((char *)pSkel + 0x120) = *(u_long128 *)(pInit + 0x10);
    m_unk25C = pData;
    m_unk229 = arg0;
    UpdateKey();
    SetSword();
    SetShield(m_unk2A4 == 0 ? true : false);
    if (bBlur) {
        m_unk2BC = (EffectNode *)CreateMotionBlurEffect__9EffectAPIFP6PMNodeUii(&mEffectAPI__13EntityManager, pSkel, 0x81000053U, 0xC);
    }
    pSkel->Animate(0.0f, 0.0f, 0, 0, false);
    RefreshAttachableJoints();
    *(unsigned char **)spC0 = __vt__10PAnimFrame;
    st_lastMaximo = arg0;
    __dt__5PAnimFv(spC0, 0);
}


// FUNCTION: 0x00160CD0 __dt__10PAnimFrameFv
extern "C" void *__dt__10PAnimFrameFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__10PAnimFrame;
        __dt__5PAnimFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00160D30 UpdateKey__6PlayerFv
void Player::UpdateKey() {
    int i = 0;
    int n;
    PMNode *res;
    PMNode *pk;
    PMNode *node;
    PMesh *mesh;
    if (m_unk298[0] != 0) {
        i = 0;
        if (m_unk1F4 != 0) {
            res = mpResMgr__15EntityBaseClass->GetResource(0x81000024, true);
            if (res == 0) {
                CdsAssert("Player.cpp", 0xEDF, "pKey");
            }
            PMesh *m1 = (PMesh *)res->m_unk10;
            m1->m_unkE = 0;
            pk = m_unk298[0];
            pk->m_unk10 = m1;
            pk->m_unk3E &= 0xEF;
            if (m1 != 0 && m1->m_unkC != 0) {
                pk->m_unk3E |= 0x10;
            }
            i++;
        }
        res = mpResMgr__15EntityBaseClass->GetResource(0x81000023, true);
        if (res == 0) {
            CdsAssert("Player.cpp", 0xEE8, "pKey");
        }
        mesh = (PMesh *)res->m_unk10;
        mesh->m_unkE = 0;
        n = m_unk1F0;
        for (; i < 3; i++, n--) {
                node = m_unk298[i];
                node->m_unk10 = (n > 0) ? mesh : 0;
                node->m_unk3E &= 0xEF;
                if (((n > 0) ? mesh : 0) != 0 && ((n > 0) ? mesh : 0)->m_unkC != 0) {
                    node->m_unk3E |= 0x10;
                }
        }
    }
}

// DRAFT: 0x00160EB0 UpdateDisplayList__6PlayerFv
// note: 122 words differ; frame -0x90 vs -0xA0, no s7/s0 D4 pointer precompute (addiu s2,v1,0xD4), reloads of m_unk284/m_unk28C after calls, assert literal addend, call reloc at 0x108/0x110/0x12C; variants: char* offsets 129, pointer locals 133, reloads 122, keep[4] 122
void Player::UpdateDisplayList() {
    void *keep[3];
    char *sword;
    char *shield;
    int swordD4;
    int shieldD4;
    void *swordTex;
    void *shieldTex;
    char *node;
    int i;

    if (m_unk229 == 2) {
        sword = (char *)m_unk284;
        shield = (char *)m_unk28C;
        if (sword == 0) {
            CdsAssert("Player.cpp", 0xEAD, "mpSwordBone");
        }
        if (shield == 0) {
            CdsAssert("Player.cpp", 0xEAE, "mpShieldBone");
        }
        swordD4 = *(int *)(sword + 0xD4);
        shieldD4 = *(int *)(shield + 0xD4);
        swordTex = *(void **)(sword + 0x10);
        shieldTex = *(void **)(shield + 0x10);
        *(void **)(sword + 0x10) = 0;
        *(unsigned char *)(sword + 0x3E) &= 0xEF;
        *(void **)(shield + 0x10) = 0;
        *(unsigned char *)(shield + 0x3E) &= 0xEF;
        for (i = 0; i < 3; i++) {
            node = (char *)m_unk298[i];
            keep[i] = *(void **)(node + 0x10);
            if (keep[i] != 0) {
                *(void **)(node + 0x10) = 0;
                *(unsigned char *)(node + 0x3E) &= 0xEF;
            }
        }
        if (m_unk218 < 4) {
            EnableOneRenderPassOnly__6PMNodeFi(m_unk3C, m_unk218);
        }
        BuildDispList__9PSkeletonFv(m_unk3C);
        Add__6PArrayFPv((char *)m_unk3C + 0x150, (void *)m_unk284);
        *(int *)(sword + 0xD4) = swordD4;
        *(int *)(shield + 0xD4) = shieldD4;
        *(void **)((char *)m_unk284 + 0x10) = swordTex;
        *(unsigned char *)((char *)m_unk284 + 0x3E) &= 0xEF;
        if (swordTex != 0 && ((PMesh *)swordTex)->m_unkC != 0) {
            *(unsigned char *)((char *)m_unk284 + 0x3E) |= 0x10;
        }
        *(void **)((char *)m_unk28C + 0x10) = shieldTex;
        *(unsigned char *)((char *)m_unk28C + 0x3E) &= 0xEF;
        if (shieldTex != 0 && ((PMesh *)shieldTex)->m_unkC != 0) {
            *(unsigned char *)((char *)m_unk28C + 0x3E) |= 0x10;
        }
        for (i = 0; i < 3; i++) {
            if (keep[i] == 0) {
                break;
            }
            node = (char *)m_unk298[i];
            *(void **)(node + 0x10) = keep[i];
            *(unsigned char *)(node + 0x3E) &= 0xEF;
            if (((PMesh *)keep[i])->m_unkC != 0) {
                *(unsigned char *)(node + 0x3E) |= 0x10;
            }
        }
    }
}

// DRAFT: 0x001614C0 OnHitEvent__6PlayerFP15EntityBaseClassiUiUi
// note: DIFF 652 words; frame 0xB0 and opcode sequence close but branch delay slots stay unfilled (nop where original hoists lui/lb) from the 0x229 test on, shifting every later word. Needs Player::OnHitEvent declared in Player.h (extern "C" stand-in here). Tried: nested-if/goto return-0 layout, ternary vs default-first 3C selects.
extern "C" int OnHitEvent__6PlayerFP15EntityBaseClassiUiUi(Player *pThis, HitEntity *pAttacker, int nDamage, unsigned int nType, unsigned int nB) {
    float spVel[4];
    float spHit[4];
    float *pSrc;
    float *pDst;
    float fAng;
    int nAct;
    int nSnd;
    int nRet;
    unsigned int nMasked;
    int n;

    if (!(pThis->m_unk1D0 & 1) || pThis->m_unk26B != 0 || pThis->m_unk20 != 0 || pAttacker->m_unk163 == 4 || gInterface.m_unk425) {
        return 0;
    }
    {
    if (pThis->m_unk229 == 4) {
        pThis->m_unk310 = 1.0f;
        ((EntityBaseClass *)pThis)->PlaySound(0x111);
        return 5;
    }
    if (pThis->m_unk264 & 0x1000) {
        if (nType != 0x3005) {
            return 5;
        }
    }
    if (nType == 0x100E) {
        if (!(pThis->m_unk38[0x42] & 1)) {
            return 5;
        }
        pSrc = pThis->m_unk3C != 0 ? pThis->m_unk3C + 0x20 : pThis->m_unk190;
        if (!(pAttacker->m_unk2C0 - pSrc[1] <= 1.5f)) {
            return 5;
        }
    }
    if (pThis->m_unk26C != 0) {
        SetHeadCamera__6PlayerFb(pThis, 0);
    }
    nRet = 1;
    if (nType & 0x4000) {
        pSrc = pAttacker->m_unk3C != 0 ? pAttacker->m_unk3C + 0x24 : pAttacker->m_unk1A0;
        fAng = Round180__Ff(180.0f + pSrc[1]);
    } else {
        pDst = pAttacker->m_unk190;
        if (pAttacker->m_unk3C != 0) {
            pDst = pAttacker->m_unk3C + 0x20;
        }
        pSrc = pThis->m_unk190;
        if (pThis->m_unk3C != 0) {
            pSrc = pThis->m_unk3C + 0x20;
        }
        sceVu0SubVector(spVel, pSrc, pDst);
        fAng = Round180__Ff(57.295776f * atan2f(spVel[0], spVel[2]));
    }
    nMasked = nType & 0xFFFF1F7F;
    if (pThis->m_unk264 & 2) {
        if (pThis->m_unk2A4 == 0) {
            if ((pThis->m_unk1B0 & 0x200) && !(nType & 0x2000) && pThis->GuardCheck((EntityBaseClass *)pAttacker) != 0) {
                nSnd = 0x1B;
                if (pThis->m_unk2AC != 0 && pThis->m_unk210 == 2 && nMasked < 0x1010 && pThis->m_unk20C >= 0x6A && FastMath_Fabs__Ff(Round180__Ff(fAng - pThis->m_unk1C4)) < 45.0f) {
                    pAttacker->Slot58(pThis, 0x32, 0x800, 0, 0);
                    pThis->GameVarSub(0xE, 0x6A);
                    nSnd = 0x1D;
                } else {
                    if (!(nDamage < 0x32)) {
                        nDamage = 0x32;
                    }
                    if (nType == 0x100E) {
                        nDamage = 0x32;
                    }
                    if (nType == 0x100F) {
                        nDamage = 0x32;
                        pSrc = pThis->m_unk3C != 0 ? pThis->m_unk3C + 0x20 : pThis->m_unk190;
                        *(u_long128 *)mHitPos__15EntityBaseClass = *(u_long128 *)pSrc;
                        mHitPos__15EntityBaseClass[1] = mHitPos__15EntityBaseClass[1] + 2.5f;
                    }
                    pThis->m_unkD8 = Round180__Ff(180.0f + fAng);
                    pThis->m_unkDC = 0.014f * (float)nDamage;
                    gPad.SetVibrate((Pad::VibType)3, 10);
                }
                pThis->m_unk1C4 = fAng;
                pThis->m_unk3C[0x25] = fAng;
                ((unsigned char *)pThis->m_unk3C)[0x3E] |= 8;
                ((EntityBaseClass *)pThis)->PlaySound(nSnd);
                pThis->SetAction(0x28);
                CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(pThis, 0, 1, 4, true);
                return 3;
            }
        }
    }
    pThis->m_unk314 = 0x3F800000;
    if (pThis->GameVarSub(1, nDamage) <= 0) {
        nAct = 0x16;
        nRet = 2;
        if (nType == 0x100E) {
            EndGrab__19ClockworkSoulsuckerFv(pAttacker);
        }
        if (nType == 0x100F) {
            pSrc = pThis->m_unk3C != 0 ? pThis->m_unk3C + 0x20 : pThis->m_unk190;
            *(u_long128 *)mHitPos__15EntityBaseClass = *(u_long128 *)pSrc;
            mHitPos__15EntityBaseClass[1] = mHitPos__15EntityBaseClass[1] + 2.5f;
        }
        goto fire;
    }
    switch (nMasked) {
    default:
        if (!(pThis->m_unk38[0x42] & 1)) {
            if (nType & 0x8000) {
                goto sub;
            }
            spHit[1] = ((float *)pThis->m_unk38)[1];
            if (spHit[1] < 0.0f) {
                spHit[1] = DAMAGE_JUMP;
            }
            spHit[0] = 0.1f * sinf(0.017453292f * fAng);
            nAct = 0x15;
            spHit[2] = 0.1f * cosf(0.017453292f * fAng);
            *(u_long128 *)pThis->m_unk38 = *(u_long128 *)spHit;
        } else {
        sub:
            switch (nMasked) {
            case 0x1000:
                pThis->m_unk1C4 = fAng;
                nAct = 0x1B;
                break;
            case 0x1007:
            case 0x1014:
                pThis->m_unk1C4 = fAng;
                nAct = 0x1F;
                break;
            case 0x1008:
            case 0x1011:
                pThis->m_unk1C4 = fAng;
                nAct = 0x20;
                break;
            case 0x1001:
            case 0x1013:
            case 0x1012:
            case 0x1010:
                pThis->m_unk1C4 = fAng;
                nAct = 0x1C;
                break;
            case 0x1006:
                nAct = 0x1D;
                break;
            case 0x100D:
                nAct = 0x1F;
                pSrc = pAttacker->m_unk3C != 0 ? pAttacker->m_unk3C + 0x24 : pAttacker->m_unk1A0;
                pThis->m_unk1C4 = Round180__Ff(180.0f + pSrc[1]);
                break;
            default:
                pThis->m_unk1C4 = fAng;
                nAct = (*(unsigned int *)(gEng + 0x19A80) & 1) + 0x13;
                break;
            }
        }
    fin:
        pThis->m_unk3C[0x25] = pThis->m_unk1C4;
        ((unsigned char *)pThis->m_unk3C)[0x3E] |= 8;
    fire:
        if (nType & 0x80) {
            CreateFireDamageFx__15EntityBaseClassFf(pThis, 120.0f);
        } else {
            nSnd = 0x2DA;
            if (pThis->m_unk229 == 2) {
                nSnd = 0x2DB;
            }
            ((EntityBaseClass *)pThis)->PlaySound(nSnd);
        }
        pThis->SetAction(nAct);
        if (pThis->m_unk330 != 0) {
            pThis->m_unk330->SetPlayerLeftDeck();
            pThis->m_unk330 = 0;
        }
    case 0x100C:
        CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(pThis, 0, 1, 0, false);
        mEffectAPI__13EntityManager.CreateOneshot(0x81000055, 0x82000093, (float (*)[4])mHitPos__15EntityBaseClass, 0, 0, 0.5f, false, 0, false);
        return nRet;
    case 0x1005:
        return 1;
    case 0x1004:
        if (!(((Physics *)pThis->m_unk38)->m_unkF8 <= 2.0f)) {
            return 0;
        }
        nAct = 0x77;
        pThis->m_unk1C4 = fAng;
        pThis->AdjustPosition((EntityBaseClass *)pAttacker, (EntityBaseClass *)pThis, -4.0f, 0.0f, 0.0f);
        pThis->m_unk2C0 = pAttacker->m_unk4;
        pThis->m_unk2C4 = 0;
        pThis->m_unk2C8 = CAUGHT_TIME;
        pSrc = pAttacker->m_unk3C != 0 ? pAttacker->m_unk3C + 0x24 : pAttacker->m_unk1A0;
        pThis->m_unk1C4 = Round180__Ff(180.0f + pSrc[1]);
        goto fin;
    case 0x100B:
        nAct = 0x79;
        pThis->m_unk1C4 = fAng;
        pThis->AdjustPosition((EntityBaseClass *)pAttacker, (EntityBaseClass *)pThis, -9.5f, 0.0f, 0.0f);
        goto fin;
    case 0x100A:
        n = MathAPI::RandomIntRange(2, 3);
        if (pThis->m_unk1E0 < n) {
            n = pThis->m_unk1E0;
        }
        if (n != 0) {
            SpawnPickups__15EntityBaseClassFiiPA4_fb(pThis, 0, n, 0, false);
        }
        pThis->GameVarSub(3, n);
        pThis->m_unk1C4 = fAng;
        nAct = 0x13;
        goto fin;
    case 0x100E:
        n = pThis->m_unk1E4;
        if (n > 0) {
            n = 1;
        } else if (n > 0) {
        } else {
            n = 0;
        }
        if (n != 0) {
            pThis->GameVarSub(4, n);
        }
        SetDrainHit__19ClockworkSoulsuckerFUi(pAttacker, n);
        pThis->m_unk10C &= 0xFDFFFFFF;
        FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(pThis, pAttacker);
        pSrc = pThis->m_unk3C != 0 ? pThis->m_unk3C + 0x24 : (float *)&pThis->m_unk1A0;
        pThis->m_unk1C4 = pSrc[1];
        pThis->AdjustPositionOfAttacker((EntityBaseClass *)pThis, (EntityBaseClass *)pAttacker, CWSS_Z, CWSS_Y, CWSS_X);
        nAct = 0x21;
        gPad.SetVibrate((Pad::VibType)5, 0x46);
        n = pThis->m_unk200;
        if (n >= 2) {
            pThis->GameVarSub(0xB, 2);
        } else if (n > 0) {
            pThis->GameVarSub(0xB, n);
        }
        goto fin;
    case 0x100F:
        n = pThis->m_unk1E4;
        if (n >= 3) {
            n = 3;
        } else if (n > 0) {
        } else {
            n = 0;
        }
        pThis->GameVarSub(4, n);
        SpawnPickups__15EntityBaseClassFiiPA4_fb(pThis, 0x26, n, 0, false);
        FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(pThis, pAttacker);
        pSrc = pThis->m_unk3C != 0 ? pThis->m_unk3C + 0x24 : (float *)&pThis->m_unk1A0;
        pThis->m_unk1C4 = pSrc[1];
        gPad.SetVibrate((Pad::VibType)5, 0x1E);
        n = pThis->m_unk200;
        if (n >= 3) {
            pThis->GameVarSub(0xB, 3);
        } else if (n > 0) {
            pThis->GameVarSub(0xB, n);
        }
        nAct = 0x1C;
        pSrc = pThis->m_unk3C != 0 ? pThis->m_unk3C + 0x20 : pThis->m_unk190;
        *(u_long128 *)mHitPos__15EntityBaseClass = *(u_long128 *)pSrc;
        goto fin;
    }
    }
}

// DRAFT: 0x00161F20 GuardCheck__6PlayerFP15EntityBaseClass
// note: DIFF 11; differs at the early mbHard return branch (b +0x2C vs +0x2A), the bc1f/bc1t sense on the 0xC2B4 compare, and the v0 materialisation (addiu/daddu with b vs v1+xori). Tried: arg0 pointer join (44->13), return-form sense flip (11, kept), flipped inner compare (11), int ret variable (17, reverted), !mbHard (11, reverted).
int Player::GuardCheck(EntityBaseClass *arg0) {
    float vec[4];
    float *a1;
    float *a2;

    if (mbHard__15EntityBaseClass == 0) {
        return 1;
    }
    a2 = m_unk190;
    if (m_unk3C != 0) {
        a2 = m_unk3C + 0x20;
    }
    float *p = *(float **)((char *)arg0 + 0x3C);
    a1 = (float *)arg0;
    if (p != 0) {
        a1 = p + 0x20;
    } else {
        a1 = (float *)((char *)a1 + 0x190);
    }
    sceVu0SubVector(vec, a1, a2);
    float fAngle = Round180__Ff(57.295776f * atan2f(-vec[0], -vec[2]) - m_unk1C4);
    if (fAngle < 90.0f) {
        if (!(fAngle <= -90.0f)) {
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x00162010 GetGroundAction__6PlayerFv
int Player::GetGroundAction() {
    unsigned short flags = m_unk1B0;
    if (m_unk1D0 & 8) {
        if (m_unk1BC < 0x32) {
            return 0xA;
        }
        return 0xB;
    }
    if ((flags & 0x200) && m_unk2A4 == 0) {
        return 0x27;
    }
    if (m_unk1BC < 0x32) {
        return 0;
    }
    if (m_unk1BC < 0x64) {
        return 1;
    }
    return 2;
}

// DRAFT: 0x00162090 SetShockwave__6PlayerFi
// note: DIFF 58 words; frame and s1/s2/s3 spill order now match; remaining diff is the if-test branch layout (beq/bne to tail, andi hoisted into delay slot) and sll scheduling; tried !=0 mask test, flag split (63), s1*4.
void Player::SetShockwave(int arg0) {
    void *proj;
    int s1;
    float *p80 = (float *)((char *)m_unk3C + 0x80);
    float *p90 = (float *)((char *)m_unk3C + 0x90);
    proj = Spawn__13EntityManagerFUibi(mpEntMgr__15EntityBaseClass, 0x2D, false, 0);
    if (proj == 0) {
        CdsAssert("Player.cpp", 0xC67, "pPrj");
    }
    m_unk2B0 = *(unsigned int *)((char *)proj + 4);
    unsigned int v1 = m_unk1D0;
    s1 = m_unk1FC;
    if (arg0 == 9) {
        goto body;
    }
    if (arg0 != 10) {
        goto tail;
    }
    if (!(v1 & 2)) {
        goto tail;
    }
body:
    {
        unsigned int a0 = m_unk250;
        if (v1 & 2) {
            v1 >>= 5;
            a0 >>= 5;
        }
        if (v1 & (a0 & 0xC00)) {
            int t = m_unk20C;
            if ((v1 & 0x800) && t >= 0x300 && (s1 & 1)) {
                arg0 = 0xC;
                GameVarSub(0xE, 0x300);
            } else if ((v1 & 0x400) && t >= 0x100) {
                arg0 = 0xB;
                GameVarSub(0xE, 0x100);
            }
        }
    }
tail:
    arg0 += (s1 << 2);
    InitProjectile__10ProjectileFQ210Projectile14ProjectileTypePA4_fPA4_fPA4_f(proj, arg0, p80, p90, 0);
}

// DRAFT: 0x00162200 AnimCheck__6PlayerFv
// note: DIFF 761 words with the typed m_unk269/m_unk320 members (728 with raw offset casts, which alias every store); first-pass translation of the m2c goto structure. Frame 0xD0 vs 0xB0 (extra locals/s-register), the original keeps &m_38->unkA0 in s2 (reads 0xC4 and 0xE8 through it) and holds bGround/bSlide/bFall in other s registers; not yet tuned. m_unk308 is still read as float through a cast.
void Player::AnimCheck() {
    PMNode *pNode;
    PMNode *pCarrier;
    Physics *pPhys;
    float fY;
    float spA0[4];
    unsigned int nEFlags;
    unsigned int nHit;
    unsigned int nPFlags;
    int bGround;
    int nSwim;
    int bFall;
    int bSlide;
    int nAct;
    int nDmg;
    int nGround;
    int nPrev;
    int nVal;
    unsigned int nSnd;
    unsigned int nSnd2;
    HitEntity *pApp;
    HitSurf *pSurf;

    m_unk1D0 &= ~0xC;
    nPFlags = m_unk264;
    if (nPFlags & 8) {
        m_unk1D0 |= 4;
        return;
    }
    if (m_unk284 != 0 && (nPFlags & 1)) {
        CheckSwordBGAnim__13EntityManagerFP6PMNode(mpEntMgr__15EntityBaseClass, (PMNode *)m_unk284);
    }
    SphereCheck();
    pNode = (PMNode *)m_unk3C;
    nVal = 0;
    if (pNode->m_unk24 != 0) {
        nVal = pNode->m_unk24->Slot18() != 0;
    }
    pPhys = (Physics *)m_unk38;
    nSwim = nVal & 0xFF;
    nEFlags = pPhys->m_unk108;
    bGround = nEFlags & 1;
    bSlide = nEFlags & 2;
    if (m_unk229 == 4 && pPhys->m_unkF8 <= 1.0f) {
        nVal = nSwim == 0;
        bGround = 1;
        if (nVal == 0) {
            nVal = (((unsigned char *)m_unk254)[8] & 0x30) != 0;
        }
        bSlide = nVal & 0xFF;
        if (nVal != 0) {
            nVal = 1;
            if (!(pPhys->m_unk4 < 0.0f)) {
                nVal = 0;
            }
            bSlide = nVal & 0xFF;
        }
    }
    if (bGround != 0) {
        m_unk26A = 0;
        m_unk1D0 |= 4;
        OnTriggerCheck();
    }
    pPhys = (Physics *)m_unk38;
    nHit = pPhys->m_unkE8;
    nVal = (nHit & 0x100000) != 0;
    fY = *(float *)((char *)pNode + 0x84);
    if (nVal != 0) {
        nVal = 1;
        if (!((1.0f + fY) < pPhys->m_unkC4)) {
            nVal = 0;
        }
    }
    bFall = nVal & 0xFF;
    if (bFall != 0) {
        if (*(float *)&m_unk308 == 0.0f) {
            nSnd = 0xB2;
            if (nHit & 1) {
                nSnd = 0x18B;
                nSnd2 = 0x188;
            } else {
                nSnd2 = 0xB7;
            }
            m_unk320 = ((EntityBaseClass *)this)->PlaySound(nSnd2);
            ((EntityBaseClass *)this)->PlaySound(nSnd);
        }
        m_unk1D0 |= 8;
        if (*(float *)&m_unk308 == 0.0f) {
            if (m_unk229 == 4) {
                GameVarSub(0xB, 2);
            } else if (GameVarSub(1, 0x32) == 0) {
                SetAction(0x18);
                pPhys->SetPhysicsType(0x800, 0);
                return;
            }
            m_unk308 = 0x3F800000;
        }
    } else {
        if (bGround != 0) {
            if (*(float *)&m_unk308 != 0.0f) {
                ((EntityBaseClass *)this)->StopSoundBySoundRef(m_unk320);
                m_unk320 = 0;
            }
            m_unk308 = 0;
        }
    }
    if (!(fY <= *(float *)((char *)mpEntMgr__15EntityBaseClass + 0x5074))) {
        goto die;
    }
    nEFlags = pPhys->m_unkE8;
    if ((nEFlags & 0x10000) && !(pPhys->m_unkC4 <= fY)) {
        goto die;
    }
    if (nSwim == 0 && m_unk260 == 0x76) {
        SetMaximo(4, false);
        return;
    }
    nPFlags = m_unk264;
    if (!(nPFlags & 0x1000) || m_unk260 == 0x29) {
        pSurf = (HitSurf *)pPhys->m_unkE4;
        nHit = 0;
        if (pSurf != 0) {
            nHit = pSurf->m_unkC;
        }
        if (bGround != 0 && (nEFlags & 4)) {
            ForceDie(0x17);
            pPhys->SetPhysicsType(0x800, 0);
            return;
        }
        if (m_unk269 == 0) {
            if (nHit & 0x208000) {
                if (m_unk26C != 0) {
                    SetHeadCamera__6PlayerFb(this, 0);
                }
                *(u_long128 *)spA0 = *(u_long128 *)pPhys->m_unkE4->m_unk10;
                spA0[3] = 0.0f;
                pCarrier = pPhys->m_unkE0;
                if (pCarrier != 0) {
                    sceVu0ApplyMatrix(spA0, (float *)((char *)pCarrier + 0x40), spA0);
                }
                nDmg = 0;
                m_unk1C4 = Round180__Ff(57.295776f * atan2f(spA0[0], spA0[2]));
                if (nHit & 0x200000) {
                    nAct = 0x1C;
                } else {
                    nVal = nHit & 0x3800;
                    if (nVal != 0) {
                        if (nVal != 0x1800) {
                            nAct = 0x1B;
                            nDmg = 0x32;
                        } else {
                            ((EntityBaseClass *)this)->PlaySound(0x28E);
                            CreateOneShot__16PParticleManagerFUifff(gGfxEng + 0x154F00, 0x83000371, *(float *)((char *)pNode + 0x80), 2.5f + *(float *)((char *)pNode + 0x84), *(float *)((char *)pNode + 0x88));
                            goto fall;
                        }
                    } else {
                    fall:
                        nAct = 0x1C;
                        nDmg = 0x19;
                    }
                }
                if (pCarrier != 0) {
                    unsigned short nApp = *(unsigned short *)((char *)pCarrier + 0x100);
                    if (nApp != 0) {
                        pApp = (HitEntity *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, nApp);
                        if (pApp != 0) {
                            pApp->Slot5C(this, 6);
                            nDmg = pApp->m_unk15C;
                            m_unk1C4 = Round180__Ff(180.0f + (pApp->m_unk3C != 0 ? pApp->m_unk3C + 0x24 : pApp->m_unk1A0)[1]);
                        }
                    } else {
                        AnimStateObject *pA = ((PMNode *)pCarrier)->m_unk24;
                        if (pA != 0 && pA->m_unk4 == 0x212 && pA->Slot18() == 0) {
                            ((PMNode *)pCarrier)->Slot1C(0);
                            UpdateAnimate__6PWorldFP6PMNode(gEng, (PMNode *)pCarrier);
                        }
                    }
                }
                nVal = nAct;
                if (nDmg != 0) {
                    if (GameVarSub(1, nDmg) == 0) {
                        nAct = 0x16;
                    }
                    nVal = nAct;
                }
                SetAction(nVal);
                m_unk269 = 1;
                m_unk268 = 0;
                m_unk314 = 0x3F800000;
                return;
            }
        }
        if ((nPFlags & 0x30) == 0 || !(nHit & 0x4000) || LedgeCheck((SurfaceInfo *)pPhys->m_unkA0) == 0) {
            goto notledge;
        }
    } else {
    notledge:
        if (bFall == 0) {
            nSnd = m_unk320;
            if (nSnd != 0) {
                ((EntityBaseClass *)this)->StopSoundBySoundRef(nSnd);
                m_unk320 = 0;
            }
            m_unk308 = 0;
        }
        if (bGround != 0) {
            if (bSlide != 0) {
                switch (m_unk260) {
                case 0x2C:
                case 0x24:
                case 0x7D:
                case 0x15:
                case 6:
                case 5:
                case 0x26:
                case 0xD:
                case 3:
                case 4:
                    nVal = GetGroundAction();
                    switch (nVal) {
                    case 10:
                        nVal = 9;
                        break;
                    case 0:
                        nVal = 7;
                        break;
                    case 2:
                        nVal = !(m_unk1B0 & 0x200) ? 8 : 0x29;
                        break;
                    case 39:
                        if (m_unk1BC >= 0x65) {
                            nVal = 0x29;
                        }
                        break;
                    }
                    SetAction(nVal);
                    ((EntityBaseClass *)this)->PlaySound(LandSound[(((Physics *)m_unk38)->m_unkE8 >> 0xB) & 7]);
                    break;
                case 0x71:
                    m_unk1C4 = ((Physics *)m_unk38)->m_unk11C;
                    SetShockwave(0xA);
                    SetAction(0x3B);
                    break;
                case 0x10:
                    FreeJoint(5);
                case 0xF:
                    if (m_unk1FC >= 2) {
                        m_unk1C4 = ((Physics *)m_unk38)->m_unk11C;
                        nVal = 0xA;
                        if (m_unk268 >= 2) {
                            nVal = 9;
                        }
                        SetShockwave(nVal);
                        SetAction(0x3B);
                    } else {
                        unsigned char nLim = ((unsigned char *)m_unk254)[5];
                        if ((int)pNode->m_unk34 < (int)nLim) {
                            pNode->Slot10((float)nLim);
                            pNode->SetAnimLoopCount(1, false);
                            nVal = 9;
                            if (m_unk260 == 0xF) {
                                nVal = 0xA;
                            }
                            SetShockwave(nVal);
                        }
                    }
                    break;
                }
                goto tail;
            }
            if (nSwim == 0) {
                nGround = GetGroundAction();
                if (m_unk335 & 6) {
                    nGround = 0x3A;
                }
                nPrev = m_unk260;
                if (nGround != nPrev) {
                    switch (nPrev) {
                    case 0x79:
                        m_unk10C |= 0x01000000;
                    case 0x1D:
                    case 0x20:
                    case 0x1B:
                        nGround = 0x1E;
                    again:
                        if (m_unk260 == 0x21) {
                    case 0x21:
                            m_unk10C |= 0x071A1E01;
                        }
                    default:
                        nPrev = m_unk260;
                        SetAction(nGround);
                        switch (nGround) {
                        case 39:
                            if (nPrev == 0x28) {
                                pNode->Slot10((float)((unsigned char *)m_unk254)[4]);
                                if (m_unk210 != 0 && m_unk2B4 == 0) {
                                    m_unk2B4 = ((EntityBaseClass *)this)->PlaySound(ShieldPowerupTable[m_unk210 - 1].c);
                                }
                            }
                            break;
                        case 2:
                        case 1:
                            if (nPrev == 8) {
                                pNode->Slot10((float)((unsigned char *)m_unk254)[4]);
                            }
                            break;
                        }
                        goto tail;
                    case 0x28:
                        if (nGround == 0) {
                            nGround = 0x27;
                        }
                        goto again;
                    }
                } else {
                    if (nGround == 0) {
                        SetAction(0);
                    }
                    goto tail;
                }
            } else {
            tail:
                if (((Physics *)m_unk38)->m_unk4 <= 0.0f) {
                    m_unk268 = 0;
                }
            }
        } else {
            if ((m_unk264 & 0x30) && (((Physics *)m_unk38)->m_unk108 & 4)) {
                SetAction(6);
                return;
            }
            if (nSwim == 0 && (nPrev = m_unk260, nPrev != 0x1B)) {
                switch (nPrev) {
                case 42:
                    m_unk1C4 = ((Physics *)m_unk38)->m_unk11C;
                    SetAction(0x2B);
                    return;
                case 21:
                    SetAction(5);
                    return;
                default:
                    if (!(((Physics *)m_unk38)->m_unkF8 <= 3.0f)) {
                        SetAction(5);
                    }
                    break;
                }
            }
        }
    }
    return;
die:
    ForceDie(0x19);
    gSound.FadeOutAllMusic(0x1F4);
    if (m_unk1F8 <= 0) {
        gInterface.FadeScreen(255.0f, 8.5f, true, (Interface::eFadeColor)0);
    }
}

// FUNCTION: 0x00162E50 ForceDie__6PlayerFi
void Player::ForceDie(int arg0) {
    if (m_unk229 == 4) {
        SetMaximo(MaximoArmor[m_unk1DC], false);
    }
    SetAction(arg0);
    m_unk1D0 &= -2;
    m_unk103 = 0xFE;
    m_unk1D8 = 0;
    if (m_unk31C != 0) {
        ((FontManager *)((char *)&gInterface + 0x80))->RemoveText(m_unk31C);
        m_unk31C = 0;
    }
}

// Node list at mpEntMgr + 0x5B70: count, index, element array.
struct PMNodeList {
    int m_unk0;
    int m_unk4;
    PMNode **m_unk8;
};

// DRAFT: 0x00162EE0 OnTriggerCheck__6PlayerFv
// note: does not match, 52 words: switch order is right but the animId compare chain differs (orig beq 1FF/200/202 then b end) and the function end is 2 words short
void Player::OnTriggerCheck() {
    PMNode *pTarget = (PMNode *)m_unk38[0x33];
    if (pTarget == 0) {
        return;
    }
    int animId = 0;
    if (pTarget->m_unk24 != 0) {
        animId = pTarget->m_unk24->m_unk4;
    }
    switch (animId) {
    case 0x202:
    case 0x200:
    case 0x1FF:
        break;
    default:
        return;
    }
    char *mgr = (char *)mpEntMgr__15EntityBaseClass;
    *(int *)(mgr + 0x5B74) = 0;
    PMNodeList *list = (PMNodeList *)(mgr + 0x5B70);
    PMNode *pNode = 0;
    if (list->m_unk0 != 0) {
        pNode = list->m_unk8[0];
    }
    while (pNode != 0) {
        if (pNode->Find(pTarget)) {
            int busy = 0;
            if (pNode->m_unk24 != 0) {
                busy = pNode->m_unk24->Slot18() != 0;
            }
            if (!busy && (animId == 0x200 || pNode->m_unk34 == 0.0f)) {
                gSound.TriggerSystemSound(animId, pTarget->m_unkE8, pTarget);
                pNode->Slot1C(0);
                if (animId == 0x1FF) {
                    ((Camera *)(gEng + 0x19760))->SetupShakeScreen(0.0f, 2.0f, 3.0f, 0, 0, 0U);
                }
            }
            break;
        }
        list->m_unk4 += 1;
        pNode = 0;
        if ((unsigned int)list->m_unk4 < (unsigned int)list->m_unk0) {
            pNode = list->m_unk8[list->m_unk4];
        }
    }
}

// TODO(header): foreign declarations
struct LedgeSurf {
    float *m_pVert[3];
    unsigned int m_nFlags;
    float m_normal[4];
};
class SurfaceInfo {
public:
    char _pad[0x40];
    void *m_unk40;
    LedgeSurf *m_unk44;
};
extern "C" void InversMatrix__FPA4_A4_fPA4_A4_f(float (*)[4][4], float (*)[4][4]);
extern "C" void sceVu0InversMatrix(float *, void *);
extern "C" void RotateY__5PMat4Ff(float *, float);
// DRAFT: 0x001630A0 LedgeCheck__6PlayerFP11SurfaceInfo
// note: 295 words differ; fMin/fMax land in f21/f20 swapped, loop induction regs differ, 0x20 bytes larger; tried decl reorders and nOff spelling
int Player::LedgeCheck(SurfaceInfo *pSurf) {
    float spC0[3][4];
    float spF0[4];
    float sp100[4];
    float sp110[4];
    float sp120[16];
    float sp160[16];
    if (m_unk229 >= 4) {
        return 0;
    }
    int nMin = 0;
    switch (m_unk260) {
    case 3:
        nMin = 0xC;
        break;
    case 4:
        nMin = 0x1E;
        break;
    case 0x2C:
        nMin = 0x26;
        break;
    }
    PMNode *pNode = (PMNode *)m_unk3C;
    float *pPhys = (float *)m_unk38;
    if ((int)pNode->m_unk34 < nMin || !(pPhys[1] < 0.0f) || ((Physics *)m_unk38)->m_unkF8 < 2.0f) {
        return 0;
    }
    float fMin = 1000.0f;
    int nMaxIdx;
    float fMax = -1000.0f;
    LedgeSurf *pData = pSurf->m_unk44;
    float **ppVert = pData->m_pVert;
    int i = 0;
    *(u_long128 *)spC0[0] = *(u_long128 *)((char *)pNode + 0x60);
    *(u_long128 *)spF0 = *(u_long128 *)pData->m_normal;
    if (pSurf->m_unk40 != 0) {
        float *pMat = (float *)((char *)pSurf->m_unk40 + 0x40);
        spF0[3] = 0.0f;
        sceVu0ApplyMatrix(spF0, pMat, spF0);
        if (sceVu0InnerProduct(spF0, spC0[0]) < 0.5f) {
            return 0;
        }
        for (i = 0; i < 3; i++) {
            float *pV = spC0[i];
            sceVu0ApplyMatrix(pV, pMat, *ppVert++);
            float f = pV[1];
            if (f < fMin) {
                fMin = f;
            }
            if (!(f <= fMax)) {
                fMax = f;
                nMaxIdx = i;
            }
        }
    } else {
        if (sceVu0InnerProduct(spF0, spC0[0]) < 0.5f) {
            return 0;
        }
        for (i = 0; i < 3; i++) {
            float *pV = spC0[i];
            *(u_long128 *)pV = *(u_long128 *)*ppVert++;
            float f = pV[1];
            if (f < fMin) {
                fMin = f;
            }
            if (!(f <= fMax)) {
                fMax = f;
                nMaxIdx = i;
            }
        }
    }
    float *pPos = (float *)((char *)pNode + 0x80);
    if (pData->m_nFlags & 0x20000) {
        int j;
        for (j = 0; j < 3; j++) {
            if (j != nMaxIdx) {
                float *pB = spC0[nMaxIdx];
                float *pA = spC0[j];
                float t;
                sceVu0SubVector(sp110, pA, pB);
                if (FastMath_Fabs__Ff(sp110[0]) > FastMath_Fabs__Ff(sp110[2])) {
                    t = (pPos[0] - pB[0]) / sp110[0];
                } else {
                    t = (pPos[2] - pB[2]) / sp110[2];
                }
                if (!(t < 0.0f)) {
                    float y = t * sp110[1] + pB[1];
                    if (!(y < pA[1])) {
                        fMax = (y - pPos[1]) - 6.0f;
                        break;
                    }
                }
            }
        }
        if (j >= 3) {
            return 0;
        }
    } else {
        fMax = fMax - (6.0f + pPos[1]);
    }
    if (!(FastMath_Fabs__Ff(fMax) < 2.0f)) {
        return 0;
    }
    float fAng = Round180__Ff(57.295776f * atan2f(spF0[0], spF0[2]));
    sceVu0UnitMatrix((float (*)[4])sp120);
    RotateY__5PMat4Ff(sp120, -fAng);
    float fLo = 10000.0f;
    float fHi = -fLo;
    for (int n = 0; n < 3; n++) {
        sceVu0ApplyMatrix(sp100, sp120, spC0[n]);
        float x = sp100[0];
        if (x < fLo) {
            fLo = x;
        }
        if (!(x <= fHi)) {
            fHi = x;
        }
    }
    sceVu0ApplyMatrix(sp100, sp120, pPos);
    float xp = sp100[0];
    if (xp < fLo || !(xp <= fHi)) {
        return 0;
    }
    pPos[1] += fMax;
    *(u_long128 *)m_unk2E0 = *(u_long128 *)pData->m_normal;
    m_unk2F0 = (int)pSurf->m_unk40;
    if (m_unk2F0 != 0) {
        *(int *)&m_unk2E0[3] = 0;
        *(u_long128 *)sp100 = *(u_long128 *)pPos;
        sp100[1] += 6.0f;
        PMNode *pM = (PMNode *)m_unk2F0;
        if (pM->m_unk3E & 4) {
            InversMatrix__FPA4_A4_fPA4_A4_f((float (*)[4][4])sp160, (float (*)[4][4])((char *)pM + 0x40));
        } else {
            sceVu0InversMatrix(sp160, (char *)pM + 0x40);
        }
        sceVu0ApplyMatrix(m_unk2D0, sp160, sp100);
    }
    m_unk1C4 = fAng;
    pNode->m_unk94 = fAng;
    SetAction(0x2A);
    pNode->m_unk3E |= 8;
    ((EntityBaseClass *)this)->PlaySound(m_unk2F4);
    m_unk268 = 1;
    *(int *)((char *)m_unk38 + 0x110) = 0;
    return 1;
}

// FUNCTION: 0x00163660 IsPlayerOnNode__6PlayerFP9PMeshNodeb
PMNode *Player::IsPlayerOnNode(PMeshNode *arg0, bool arg1) {
    if (!(m_unk1D0 & 4)) {
        return 0;
    }
    PMNode *node = (PMNode *)m_unk38[0x33];
    if (node == 0 || ((PMNode *)arg0)->Find(node) == 0) {
        return 0;
    }
    if (arg1) {
        if (m_unk264 & 0x30) {
            SetAction(3);
        }
    }
    return node;
}

// note: 67 words differ: sqrtf(d2)/sqrtf(d2) is CSE'd to one sqrt.s plus div.s f3,f3,f3 (original: two sqrt.s then div.s f4,f4,f0), so later branch offsets and loads shift; prologue zero lands in f1 (original f0). Tried split sqrt locals (67), reversed 0.0f compare (67), unsigned epilogue pointer (67, kept).
// DRAFT: 0x00163700 SphereCheck__6PlayerFv
void Player::SphereCheck() {
    float sp60[4];
    float sp70[4];
    *(u_long128 *)sp60 = *(u_long128 *)((char *)m_unk3C + 0x80);
    if (*(float *)&m_unk344 != 0.0f) {
        sceVu0SubVector(sp70, sp60, m_unk350);
        sp70[1] = 0.0f;
        float d2 = sceVu0InnerProduct(sp70, sp70);
        if (d2 > *(float *)&m_unk344) {
            float f4 = sqrtf(d2) / sqrtf(d2);
            sp60[0] = m_unk350[0] + sp70[0] * f4;
            sp60[2] = m_unk350[2] + sp70[2] * f4;
        }
    }
    for (int i = 0; i < 4; i++) {
        PMNode *node = m_unk360[i].node;
        if (node != 0) {
            float *c = (float *)((char *)node + 0x70);
            sceVu0SubVector(sp70, sp60, c);
            float d2 = sceVu0InnerProduct(sp70, sp70);
            if (d2 < m_unk360[i].r2) {
                float f4 = sqrtf(d2) / sqrtf(d2);
                sp60[0] = c[0] + sp70[0] * f4;
                sp60[2] = c[2] + sp70[2] * f4;
            }
        }
    }
    unsigned char *p = (unsigned char *)m_unk3C;
    *(u_long128 *)(p + 0x80) = *(u_long128 *)sp60;
    p[0x3E] |= 8;
}

// note: 37 words differ: the first compare is c.eq.s f0,f12 against the original f12,f0; the original uses two base pointers (0x360, 0x364) and no sll. Tried swapped init order (39), off-based stores (37), separate char* bases (39), i-loop with off (37), `arg1 == 0.0f` with swapped arms (37).
// DRAFT: 0x00163880 SetBoundingSphere__6PlayerFP6PMNodef
void Player::SetBoundingSphere(PMNode *arg0, float arg1) {
    int i;
    int off;
    if (arg1 != 0.0f) {
        off = 0;
        for (i = 0; i < 4; i++) {
            if (*(PMNode **)((char *)this + 0x360 + off) == 0) {
                *(PMNode **)((char *)this + 0x360 + i * 8) = arg0;
                *(float *)((char *)this + 0x364 + i * 8) = arg1 * arg1;
                return;
            }
            off += 8;
        }
    } else {
        off = 0;
        for (i = 0; i < 4; i++) {
            if (*(PMNode **)((char *)this + 0x360 + off) == arg0) {
                *(PMNode **)((char *)this + 0x360 + i * 8) = 0;
                return;
            }
            off += 8;
        }
    }
}

// FUNCTION: 0x00163930 BackToMaximo__6PlayerFv
void Player::BackToMaximo() {
    if (m_unk229 == 4) {
        SetMaximo(MaximoArmor[m_unk1DC], false);
        ((EntityBaseClass *)this)->PlaySound(0x119);
    }
}

// DRAFT: 0x00163980 ButtonCheck__6PlayerFv
// note: DIFF 223 words (most are shifted branch offsets). Differs: ComboTarget float arg load order (v1=100.0f first), 0x69/0xC SetAction arg (original keeps one shared jal with a1 set in delay slots; ours s0/duplicated), 0x264 and 0x1D0 guard layout matches. Tried fNeg/fHund locals, if/else and comma forms, switch(0x20), sltu spellings for SetHeadCamera. Best copies in src/scratch/Player-51556/.
int Player::ButtonCheck() {
    if ((m_unk264 & 0x30) == 0 || (m_unk264 & 4)) {
        return 0;
    }
    int nBit4 = m_unk1D0 & 4;
    if (nBit4 != 0) {
        signed char nVar = m_unk339;
        if (nVar >= 0 && m_unk229 != 4) {
            GameVarSet(0xA, nVar);
            m_unk339 = -1;
            return 1;
        }
    }
    unsigned short nPad = m_unk1B2;
    if ((nPad & 4) && (m_unk264 & 0x4000) && !*(float *)&m_unk2F8) {
        PMNode *pNode = ((Physics *)m_unk38)->m_unkCC;
        unsigned int nHead = m_unk26C;
        if (nHead != 0 || pNode == 0 || !(((signed char)(pNode->m_unk3F & 7)) & 1)) {
            SetHeadCamera(!(nHead > 0));
        }
    }
    if (m_unk26C != 0) {
        return 1;
    }
    if (nPad & 0x4000) {
        signed char nSub = m_unk268;
        if (nSub < 2) {
            Physics *pPhys = (Physics *)m_unk38;
            float fDiff = pPhys->m_unkC8 - pPhys->m_unkB4;
            if (nSub == 0 || fDiff <= 0.0f || !(fDiff <= 6.0f)) {
                SetAction(nSub + 3);
                return 1;
            }
        }
    }
    if (!(m_unk264 & 0x20) || (m_unk1D0 & 8)) {
        return 0;
    }
    {
    float fNeg = -1.0f;
    if (nPad & 0x8000) {
        ComboTarget(fNeg, 100.0f, true);
        if (nBit4 == 0) {
            return SetAction(0xD);
        }
        return SetAction(((m_unk1D0 & 2) && m_unk1C0 != 0 && (short)m_unk1C0 < UP_TIME && FastMath_Fabs__Ff(Round180__Ff(m_unk1C4 - ((float *)m_unk3C)[0x94 / 4])) < 55.0f) ? 0x69 : 0xC);
    }
    if (nPad & 0x2000) {
        if (m_unk2A4 == 0) {
            int nFlag = 1;
            if (m_unk229 != 4 && m_unk20C < m_unk214) {
                nFlag = 0;
            }
            if (nBit4 == 0) {
                if (nFlag != 0) {
                    return SetAction(0x24);
                }
            } else {
                return SetAction(nFlag ? 0x22 : 0x25);
            }
        }
    }
    if (nPad & 0x1000) {
        ComboTarget(fNeg, 100.0f, true);
        if (nBit4 != 0) {
            short nT = m_unk1C0;
            int nAct = 0xE;
            if (nT != 0 && nT < UP_TIME && FastMath_Fabs__Ff(Round180__Ff(m_unk1C4 - ((float *)m_unk3C)[0x94 / 4])) < 55.0f) {
                nAct = 0x12;
            } else if (m_unk229 < 4) {
                unsigned int nFl = m_unk1D0;
                if (m_unk1FC >= 2) {
                    nFl = nFl >> 5;
                }
                if ((nFl & 0x300) && m_unk1BC >= 0x65 && MightyBlowCheck(nFl) != 0) {
                    nAct = !(nFl & 0x200) ? 0x11 : 0x35;
                } else {
                    nAct = 0xE;
                }
            }
            return SetAction(nAct);
        }
        if (m_unk229 != 4) {
            int nAct = 0xF;
            if (m_unk268 >= 2) {
                nAct = 0x10;
            }
            return SetAction(nAct);
        }
        int nAct = 0xF;
        if (!(((Physics *)m_unk38)->m_unkF8 < GRIM_AIR_POS)) {
            nAct = 0x10;
        }
        return SetAction(nAct);
    }
    if (nPad & 0x800) {
        if (m_unk229 == 4) {
            SetMaximo(MaximoArmor[m_unk1DC], false);
            ((EntityBaseClass *)this)->PlaySound(0x119);
            return 1;
        }
        if (m_unk200 >= 0xA) {
            SetAction(0x76);
            m_unk2A8 = mEffectAPI__13EntityManager.CreateOneshot(0x810002CF, 0x820004AE, 0, 0, (EntityBaseClass *)this, 0.5f, false, 0, false);
            return 1;
        }
    }
    if (nBit4 != 0) {
    if (nPad & 0x100) {
        signed char nPrev = m_unk22A;
        if (nPrev >= 0) {
            GameVarSet(0xA, nPrev);
            *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) = 0;
            m_unk264 &= ~0x1000;
            return 1;
        }
    }
    if (nPad & 0x200) {
        if (m_unk2A4 == 0) {
            return SetAction(0x27);
        }
    }
    }
    }
    return 0;
}

// FUNCTION: 0x00163F10 MightyBlowCheck__6PlayerFUi
int Player::MightyBlowCheck(unsigned int arg0) {
    static const int MightyCost[4] = {128, 128, 192, 192};
    int idx = 0;
    if (arg0 & 0x200) {
        idx = 1;
    }
    if (m_unk1FC >= 2) {
        idx += 2;
    }
    int cost = MightyCost[idx];
    if (m_unk20C >= cost) {
        GameVarSub(0xE, cost);
        return 1;
    }
    return 0;
}

// DRAFT: 0x00165E60 GameVarAdd__6PlayerFUiii
// note: arg0/arg1 swapped vs original (arg0 s0 not s3, nVal shares arg1 reg), frame 0x70 vs 0x60 (extra s5 save); tried locals order, short/int nCap, bool bAt (best), slot spelling, switch order (already matches chain)
int Player::GameVarAdd(unsigned int arg0, int arg1, int arg2) {
    unsigned char *pTbl;
    int *pSlot;
    int nVal;
    short nCap;
    int nStep;
    int nTmp;
    int nArg;
    int nCost;
    bool bAt;

    ((arg0 < 0x14) ? (void)0 : CdsAssert("Player.cpp", 0x45E, "iVar < GameVarMax"));
    ((arg1 >= 0) ? (void)0 : CdsAssert("Player.cpp", 0x45F, "iValue >= 0"));

    pTbl = GameVarTbl + arg0 * 6;
    if (pTbl[4] != 0 && !(m_unk1D0 & 1)) {
        return 0;
    }
    if (pTbl[5] != 0 && m_unk229 >= 4) {
        return 0;
    }
    nCap = *(short *)(pTbl + 2);
    pSlot = (int *)((char *)this + 0x1D4) + arg0;
    nVal = arg1 + *pSlot;
    if (nCap < nVal) {
        nVal = nCap;
    }
    switch (arg0) {
    case 1:
        nStep = m_unk1DC * 0xC8;
        bAt = nStep < nVal;
        if (nStep < m_unk1D8) {
            nStep += 0xC8;
            bAt = nStep < nVal;
        }
        if (bAt) {
            nVal = nStep;
        }
        if (arg2 < 2 && SetPowerupMotion(0x32) != 0 && arg2 != 0) {
            m_unk335 |= 2;
        }
    default:
    block_64:
        *pSlot = nVal;
        ((Interface *)((char *)&gInterface + 0x1710))->UpdateStatus(arg0, false);
        return 1;
    case 2:
        nTmp = m_unk1D4;
        if (nTmp < nVal) {
            nVal = nTmp;
            if (nTmp * 0xC8 < m_unk1D8) {
                nVal = nTmp + 1;
            }
        }
        if (m_unk229 != 4) {
            if (MaximoArmor[nVal] != m_unk229) {
                SetMaximo(MaximoArmor[nVal], false);
                bAt = arg2 < 2;
                if (m_unk33B != 0) {
                    ShowPlayer(false);
                }
                if (bAt != 0 && SetPowerupMotion(0x31) != 0 && arg2 != 0) {
                    m_unk335 |= 2;
                }
            }
        }
        ((EntityBaseClass *)this)->PlaySound(8U);
        m_unk1DC = nVal;
        GameVarAdd(1, 0x190, arg2);
        goto block_64;
    case 14:
        nTmp = m_unk208 * 0x280;
        if (nTmp < nVal) {
            nVal = nTmp;
        }
        goto block_64;
    case 4:
        nArg = 0xA;
        if (m_unk218 == 2) {
            nArg = 0xF;
        }
        GameVarAdd(0xE, nArg, 0);
        GameVarAdd(0xB, 1, 0);
        nCost = *(int *)((char *)this + 0x1EC);
        if (nVal >= nCost && m_unk1F8 < 0x63) {
            GameVarAdd(9, 1, 0);
            nVal -= nCost;
            if (nCost < 0x96) {
                *(int *)((char *)this + 0x1EC) += 0x14;
            }
        }
        goto block_64;
    case 7:
    case 8:
        *pSlot = nVal;
        switch (arg2) {
        case 1:
            SetAction(0x3C);
            m_unk335 |= 2;
            break;
        default:
            if (SetPowerupMotion(0x3C) == 0) {
            case 2:
                UpdateKey();
                ((EntityBaseClass *)this)->PlaySound(0x1A);
            }
            break;
        }
        goto block_64;
    case 18:
        m_unk314 = 0x42A00000;
        m_unk220 += *(unsigned char *)((char *)m_unk258 + 0xA);
        if (m_unk220 >= 0x64) {
            m_unk220 = 0x63;
        }
        goto block_64;
    case 11:
        if (m_unk229 == 4) {
            return 1;
        }
        nTmp = m_unk204;
        if (nTmp < nVal) {
            nVal = nTmp;
        }
        goto block_64;
    }
}

// DRAFT: 0x001662B0 GameVarSub__6PlayerFUii
// note: 190 diff words; original computes the GameVarTbl entry pointer before the slot load and keeps arg1 in s3, slot (this+0x1D4 unfolded) in s4. Tried decl order, byte-offset/indexed slot spellings, value copy, pTbl local.
int Player::GameVarSub(unsigned int arg0, int arg1) {
    int nRem;
    int *pSlot;
    int nVal;
    int nStep;
    int nAdd;
    float *pA;
    float *pB;
    float *pTemp;
    FontNode *pFont;
    unsigned char *pTbl;

    ((arg0 < 0x14) ? (void)0 : CdsAssert("Player.cpp", 0x3FB, "iVar < GameVarMax"));
    ((arg1 >= 0) ? (void)0 : CdsAssert("Player.cpp", 0x3FC, "iValue >= 0"));

    pTbl = GameVarTbl + arg0 * 6;
    pSlot = ((int *)((char *)this + 0x1D0) + 1) + arg0;
    nVal = *pSlot;
    if (nVal <= 0) {
        return nVal;
    }
    nRem = nVal - arg1;
    if (pTbl[4] != 0) {
        if (!(m_unk1D0 & 1)) {
            return nVal;
        }
    }
    if (nRem < 0) {
        nRem = 0;
    }
    switch (arg0) {
    case 1:
        if (m_unk20 != 0) {
            return nVal;
        }
        nAdd = arg1 >> 2;
        if (m_unk218 == 2) {
            nAdd += nAdd >> 1;
        }
        GameVarAdd(0xE, nAdd, 0);
        if (IsNoDamage__5DebugFv(&gDebug)) {
            return 1;
        }
        if ((m_unk1DC - 1) * 200 >= nRem) {
            nStep = (nRem + 0xC7) / 200;
            if (nStep != 0) {
                ((EntityBaseClass *)this)->PlaySound(4);
                ((EntityBaseClass *)this)->PlaySound(0xC3);
            }
            switch (nStep) {
            case 0:
                nStep = 1;
                break;
            case 1:
                SetMaximo(2, false);
                if (m_unk218 == 3) {
                    GameVarAdd(0xE, 0xA00, 0);
                }
                pTemp = m_unk3C;
                pA = (pTemp != 0) ? (float *)((char *)pTemp + 0x80) : m_unk190;
                pB = (pTemp != 0) ? (float *)((char *)pTemp + 0x90) : (float *)((char *)this + 0x1A0);
                mEffectAPI__13EntityManager.CreateOneshot(0x8100045A, 0x82000070, (float (*)[4])pA, (float (*)[4])pB, 0, 0.5f, false, 0, false);
                break;
            case 2:
                SetMaximo(0, false);
                break;
            default:
                if (m_unk229 == 3) {
                    SetMaximo(1, false);
                    pTemp = m_unk3C;
                    pA = (pTemp != 0) ? (float *)((char *)pTemp + 0x80) : m_unk190;
                    pB = (pTemp != 0) ? (float *)((char *)pTemp + 0x90) : (float *)((char *)this + 0x1A0);
                    mEffectAPI__13EntityManager.CreateOneshot(0x81000459, 0x82000754, (float (*)[4])pA, (float (*)[4])pB, 0, 0.5f, false, 0, false);
                }
                break;
            }
            m_unk1DC = nStep;
        }
        if (nRem == 0) {
            if (m_unk229 == 4) {
                SetMaximo(MaximoArmor[m_unk1DC], false);
            }
            m_unk1D0 &= ~1;
            m_unk103 = 0xFE;
            pFont = m_unk31C;
            if (pFont != 0) {
                ((FontManager *)((char *)&gInterface + 0x1790))->RemoveText(pFont);
                m_unk31C = 0;
            }
        }
        break;
    case 0xB:
        if (nRem <= 0) {
            SetMaximo(MaximoArmor[m_unk1DC], false);
        }
        break;
    default:
        break;
    }
    *pSlot = nRem;
    ((Interface *)((char *)&gInterface + 0x1710))->UpdateStatus(arg0, false);
    return nRem;
}

// FUNCTION: 0x00166690 __dt__6PlayerFv
extern "C" void *__dt__6PlayerFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        Player *self = (Player *)pThis;
        *(unsigned char **)pThis = __vt__6Player;
        if (self->m_unk2B8 != 0) {
            ((EntityBaseClass *)self)->StopSoundBySoundRef((unsigned int)self->m_unk2B8);
            self->m_unk2B8 = 0;
        }
        if (self->m_unk229 == 4) {
            self->m_unk229 = MaximoArmor[self->m_unk1DC];
        }
        self->SavePlayerData((Player::PlayerData *)(gMC + 0x234));
        self->ResetPling();
        EnableFullScreenFx__10PGfxEngineFb(gGfxEng, 0);
        if (self->m_unk2AC != 0) {
            mEffectAPI__13EntityManager.DeleteEffect(self->m_unk2AC);
            self->m_unk2AC = 0;
        }
        if (self->m_unk288 != 0) {
            if (self->m_unk288 != 0) {
                ((VirtualSlot08Object *)self->m_unk288)->Slot08(1);
            }
            self->m_unk288 = 0;
        }
        if (self->m_unk23CC != 0) {
            __dt__6ShadowFv(self->m_unk23CC, 1);
            self->m_unk23CC = 0;
        }
        if (self->m_unk23C8 != 0) {
            __dt__6ShadowFv(self->m_unk23C8, 1);
            self->m_unk23C8 = 0;
        }
        miRandom__7MathAPI = (int)(0.5f + (12345.0f + (41976.0f * ((float)rand() / 2.1474836e9f))));
        __dt__15PGrimReaperCapeFv((char *)self + 0x390, -1);
        __dt__15EntityBaseClassFv(self, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

#define PL_AT(T, off) (*(T *)((char *)this + (off)))

// FUNCTION: 0x00166830 __ct__6PlayerFv
extern "C" Player *__ct__6PlayerFv(Player *volatile pThis)
{
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 5, 1);
    *(unsigned char **)pThis = __vt__6Player;
    __ct__15PGrimReaperCapeFv((char *)pThis + 0x390);
    (*(unsigned char *)((char *)pThis + (0xE8))) = 0x13;
    ((EntityBaseClass *)pThis)->EnableSleep(false, false);
    (*(unsigned char *)((char *)pThis + (0x103))) = 0x20;
    (*(unsigned char *)((char *)pThis + (0xEA))) = 1;
    (*(unsigned char *)((char *)pThis + (0x1B6))) = 0;
    (*(unsigned char *)((char *)pThis + (0x1B7))) = 0;
    (*(unsigned char *)((char *)pThis + (0x1B4))) = 0;
    (*(unsigned char *)((char *)pThis + (0x1B5))) = 0;
    (*(int *)((char *)pThis + (0x25C))) = 0;
    (*(int *)((char *)pThis + (0x260))) = 0;
    (*(unsigned char *)((char *)pThis + (0x33A))) = 0;
    (*(int *)((char *)pThis + (0x2A4))) = 0;
    (*(int *)((char *)pThis + (0x284))) = 0;
    (*(int *)((char *)pThis + (0x28C))) = 0;
    (*(int *)((char *)pThis + (0x2A8))) = 0;
    (*(int *)((char *)pThis + (0x2B0))) = 0;
    (*(int *)((char *)pThis + (0x2AC))) = 0;
    (*(int *)((char *)pThis + (0x2B4))) = 0;
    (*(int *)((char *)pThis + (0x2B8))) = 0;
    (*(int *)((char *)pThis + (0x320))) = 0;
    (*(int *)((char *)pThis + (0x308))) = 0;
    (*(int *)((char *)pThis + (0x314))) = 0;
    (*(int *)((char *)pThis + (0x2F8))) = 0;
    (*(int *)((char *)pThis + (0x324))) = 0;
    (*(int *)((char *)pThis + (0x32C))) = 0;
    pThis->m_unk339 = -1;
    (*(int *)((char *)pThis + (0x330))) = 0;
    (*(unsigned char *)((char *)pThis + (0x335))) = 0;
    (*(unsigned char *)((char *)pThis + (0x337))) = 0;
    (*(int *)((char *)pThis + (0x318))) = 0;
    (*(int *)((char *)pThis + (0x31C))) = 0;
    (*(int *)((char *)pThis + (0x288))) = 0;
    (*(int *)((char *)pThis + (0x1CC))) = 0;
    (*(int *)((char *)pThis + (0x2BC))) = 0;
    (*(unsigned char *)((char *)pThis + (0x338))) = 0;
    (*(int *)((char *)pThis + (0x23C4))) = 3;
    pThis->m_unk38 = (int *)(new Physics);
    if (pThis->m_unk38 == 0) {
        CdsAssert("Player.cpp", 0x358, "mpPhysics");
    }
    ((Physics *)pThis->m_unk38)->m_unk118 = 0.2f;
    ((Physics *)pThis->m_unk38)->m_unkEC = 0x8019FF55;
    pThis->m_unkD4 = new Shadow(Shadow::eShadowParticle, 0x8700000B);
    (*(void * *)((char *)pThis + (0x23CC))) = new Shadow(Shadow::eShadowParticle, 0x87000009);
    (*(void * *)((char *)pThis + (0x23C8))) = new Shadow(Shadow::eShadowParticle, 0x87000004);
    if (pThis->m_unkD4 == 0) {
        CdsAssert("Player.cpp", 0x36B, "mpShadow");
    }
    {
        Shadow *pShadow = (Shadow *)pThis->m_unkD4;
        if (pShadow != 0) {
            pShadow->m_unk0 = 1;
            char *pPart = (char *)pShadow->m_unkC;
            if (pPart != 0) {
                *(unsigned char *)(pPart + 0x18) = 1;
            }
        }
    }
    (*(float *)((char *)pThis + (0x104))) = 1.0f;
    (*(float *)((char *)pThis + (0x108))) = 4.0f;
    (*(float *)((char *)pThis + (0xE4))) = 1.0f;
    pThis->m_unk10C |= 0x071A1E01;
    (*(int *)((char *)pThis + (0x344))) = 0;
    (*(int *)((char *)pThis + (0x360))) = 0;
    (*(int *)((char *)pThis + (0x368))) = 0;
    (*(int *)((char *)pThis + (0x370))) = 0;
    (*(int *)((char *)pThis + (0x378))) = 0;
    pThis->LoadPlayerData((Player::PlayerData *)(gMC + 0x234));
    gInterface.SetPlayerData((Player::PlayerData *)((char *)pThis + 0x1D0));
    (*(float *)((char *)pThis + (0x380))) = 128.0f;
    (*(float *)((char *)pThis + (0x384))) = 10.0f;
    (*(int *)((char *)pThis + (0x388))) = 0;
    (*(int *)((char *)pThis + (0x38C))) = 0;
    (*(float *)((char *)pThis + (0x23C0))) = -2.5f;
    ((PGrimReaperCape *)((char *)pThis + 0x390))->Init();
    pThis->InitAttachableJoints();
    return pThis;
}

#undef PL_AT

// FUNCTION: 0x00163F80 ShowPlayer__6PlayerFb
void Player::ShowPlayer(bool arg0) {
    m_unk33B = !arg0;
    EnablePlayerShadow(arg0);
    PMNode *temp = (PMNode *)m_unk288;
    if (temp != 0) {
        temp->EnableFx(arg0, true);
    }
}

// FUNCTION: 0x00163FE0 SetHeadCamera__6PlayerFb
void Player::SetHeadCamera(bool arg0) {
    if (((Camera *)(gEng + 0x19760))->SetHeadCam(arg0) != 0) {
        m_unk26C = arg0;
        ShowPlayer(!arg0);
        gSound.PlaySoundApparition(0x3F, 0x80000000U);
    }
}

// FUNCTION: 0x00164050 RenderCutScene__6PlayerFv
void Player::RenderCutScene() {
    ((CutSceneObject *)m_unk28C)->Slot04(0, 0x80, 0);
    ((CutSceneObject *)m_unk284)->Slot04(0, 0x80, 0);
}

// FUNCTION: 0x001640B0 Render__6PlayerFP13PLightManager
int Player::Render(PLightManager *pLightMgr) {
    int total;
    int i;
    if (m_unk26C != 0 || m_unk33B != 0) return 0;
    if (m_unk229 == 4) {
        m_unkD0 = 1;
        memset((char *)this + 0x40, 0, 0x90);
        m_unk50 = 0xBF800000;
        m_unk70 = 0x3F800000;
        *(u_long128 *)&m_unk80 = *(u_long128 *)m_unk380;
        m_unk380[0] += m_unk23C0;
        if (m_unk380[0] < 50.0f || !(m_unk380[0] < 128.0f)) m_unk23C0 = -m_unk23C0;
        total = ((EntityBaseClass *)this)->Render(pLightMgr);
        ((PDynamicSplinePatch *)((char *)this + 0x390))->Render();
    } else {
        total = ((EntityBaseClass *)this)->Render(pLightMgr);
        if (m_unk2A4 == 0) total += ((RenderSlotObject *)m_unk28C)->Slot04(pLightMgr, 0x80, 0);
        total += ((RenderSlotObject *)m_unk284)->Slot04(pLightMgr, 0x80, 0);
        for (i = 0; i < 3; i++) {
            PMNode *node = m_unk298[i];
            if (node == 0 || node->m_unk10 == 0) break;
            total += node->Slot0C(pLightMgr, 0x80, 0);
        }
    }
    return total;
}

// FUNCTION: 0x00164270 Animate__6PlayerFif
void Player::Animate(int arg0, float arg1) {
    PMNode *node = 0;
    PAnim *anim = 0;
    if (m_unk229 == 4) {
        float t = ((PMNode *)m_unk3C)->GetFrameTime();
        node = ((PMNode *)m_unk3C)->Find(0x9980D6C3U);
        if (node != 0) {
            anim = *(PAnim **)((char *)node + 0x24);
            *(PAnim **)((char *)node + 0x24) = 0;
            ((PGrimReaperCape *)((char *)this + 0x390))->AnimateControlNode(anim, t);
        }
    }
    ((EntityBaseClass *)this)->Animate(arg0, arg1);
    if (m_unk229 == 4) {
        ((PDynamicSplinePatch *)((char *)this + 0x390))->Animate(1.0f);
        if (node != 0 && anim != 0) {
            *(PAnim **)((char *)node + 0x24) = anim;
        }
    }
}

// DRAFT: 0x00164360 Execute__6PlayerFv
// note: 230 words differ; case -1/0/1-2 layout (beq targets 0x1C/0x28/0x30), PadUpdate/epilogue b+ld ra, mpEntMgr gp load, quad copy order, vcall arg setup; tried default-arm removal (252), bPad/break layout (231), pSub local (233)
void Player::Execute() {
    float sp40[4];
    float sp30[4];
    m_unk23D2 = 0;
    switch (m_unk20) {
    case -1:
        ((EntityBaseClass *)this)->SetState(0);
        m_unk1C4 = Round180__Ff(m_unk1A4);
        m_unk1A0 = 0;
        m_unk1A8 = 0;
        m_unk250 = 0;
        m_unk1D0 |= 1;
        SetMaximo(m_unk229, false);
        {
            int nAct = 0x37;
            if (*(unsigned char *)((char *)mpEntMgr__15EntityBaseClass + 0x5070) == 0) {
                nAct = 0;
            }
            SetAction(nAct);
        }
        *(u_long128 *)((char *)m_unk3C + 0x90) = *(u_long128 *)&m_unk1A0;
        *((unsigned char *)m_unk3C + 0x3E) |= 8;
        *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(m_unk1C4);
        ((VirtualSlot18Call *)m_unk3C)->Slot18(0, 0, 0, 0, 0);
        m_unk268 = 2;
        m_unk26A = 1;
        m_unk26C = 0;
        m_unk26D = 0;
        m_unk33B = 0;
        m_unk335 = 0;
        m_unk336 = 0;
        m_unk300 = 0x42700000;
        switch (*(unsigned int *)((char *)GetLevelFile__10MaximoMainFi(gEng, -1) + 0x7C) & 0x3C00) {
        case 0x1000:
            m_unk2F4 = 0x25B;
            FootSound[0] = 0x4E24;
            break;
        case 0xC00:
        case 0x800:
            m_unk2F4 = 9;
            FootSound[0] = 0x4E24;
            break;
        default:
            FootSound[0] = 0x4E21;
            m_unk2F4 = 9;
            break;
        }
        m_unk30C = 0x19;
        if (mbHard__15EntityBaseClass == 0) {
            m_unk30C = 0xC;
            if (*(int *)(gEng + 0x19A78) != 0x10) {
                m_unk30C = 0x19;
            }
        }
        return;
    case 0: {
        int bPad = (*(unsigned char *)((char *)&gInterface + 0x425) == 0) & 0xFF;
        PadUpdate(bPad);
        goto block_19;
    }
    case 1:
    case 2:
        m_unk1C4 = ((float *)m_unk3C)[0x94 / 4];
        *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(m_unk1C4);
        if (m_unk229 >= 4) {
            SetMaximo(MaximoArmor[m_unk1DC], false);
        }
        PadUpdate(0);
        goto block_19;
    default:
        return;
    }
block_19:
    if (m_unk335 & 1) {
        if (m_unk1B2 & 0xF000) {
            if (*(int *)((char *)&gInterface + 0x98) == 0) {
                *(int *)((char *)&gInterface + 0x94) = 1;
                m_unk335 &= ~1;
                ReleaseControlOfCamera__9CameraAPIFP15EntityBaseClassb(mCameraAPI__13EntityManager, 0, true);
                gSound.SetMainMusicSpecialVolume(PSound::MUSIC_SPECIAL_VOLS_NONE);
            } else {
                *((unsigned char *)&gInterface + 0x91) = 1;
            }
        }
    }
    TimerUpdate();
    AnimCheck();
    PlingCheck();
    if (m_unk33B == 0) {
        UpdatePlayerFx();
    }
    if (ButtonCheck() == 0 && m_unk229 != 4 && !(m_unk1D0 & 4) && (m_unk264 & 0x30) && m_unk1BC >= 0x33) {
        float *pV = (float *)m_unk38;
        pV[0] = pV[0] - 0.008f * FastMath_Sin180__Ff(m_unk1C4);
        pV[2] = pV[2] - 0.008f * FastMath_Cos180__Ff(m_unk1C4);
    }
    sp40[0] = *(float *)((char *)m_unk254 + 0x10);
    sp40[1] = *(float *)((char *)m_unk254 + 0x14);
    sp40[2] = *(float *)((char *)m_unk254 + 0x18);
    if (__ptmf_test(sp40) != 0) {
        __ptmf_scall(this);
    }
    *(u_long128 *)sp30 = *(u_long128 *)m_unk38;
    sp30[1] = 0.0f;
    m_unk1C8 = sceVu0InnerProduct(sp30, sp30);
    UpdateBodyBox();
}

// FUNCTION: 0x00164770 ResetPling__6PlayerFv
void Player::ResetPling() {
    m_unk324 = 0;
    PlingEffect *t = m_unk32C;
    if (t != 0) {
        if (t != 0) {
            t->Slot00(1);
        }
        m_unk32C = 0;
    }
}

// FUNCTION: 0x001647C0 PlingCheck__6PlayerFv
void Player::PlingCheck() {
    float sp30[4];
    if (m_unk324 != 0 && (m_unk264 & 0x30) && (m_unk1D0 & 4)) {
        char *s0 = (char *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, *(unsigned int *)((char *)this + 0x328));
        if (m_unk26C == 0 && m_unk26B == 0 && s0 != 0) {
            unsigned int a1 = m_unk1B2;
            switch (m_unk324) {
            case 1:
                if (a1 & 0x8000) {
                    char *pE = *(char **)(s0 + 0x3C);
                    float *pB = (float *)(pE != 0 ? pE + 0x80 : s0 + 0x190);
                    float *pA = (float *)(m_unk3C != 0 ? (char *)m_unk3C + 0x80 : (char *)m_unk190);
                    sceVu0SubVector(sp30, pA, pB);
                    m_unk1C4 = Round180__Ff(57.295776f * atan2f(sp30[0], sp30[2]));
                    SetAction(0x2D);
                }
                break;
            case 2:
                if ((a1 & 0xB000) && m_unk334 != 0) {
                    char *pE = *(char **)(s0 + 0x3C);
                    float *pB = (float *)(pE != 0 ? pE + 0x80 : s0 + 0x190);
                    float *pA = (float *)(m_unk3C != 0 ? (char *)m_unk3C + 0x80 : (char *)m_unk190);
                    sceVu0SubVector(sp30, pA, pB);
                    float fAng = Round180__Ff(57.295776f * atan2f(sp30[0], sp30[2]));
                    m_unk1C4 = fAng;
                    m_unk3C[37] = fAng;
                    SetAction(0x3D);
                    gSound.SetMainMusicSpecialVolume((PSound::EnumMusicSpecialVols)2);
                }
                break;
            case 6:
                if ((a1 & 0xB000) && m_unk334 != 0 && ((VirtualSlot58Object *)s0)->Slot58(this, -1, 0x1FE, 0) == 1) {
                    char *pE = *(char **)(s0 + 0x3C);
                    float *pB = (float *)(pE != 0 ? pE + 0x80 : s0 + 0x190);
                    float *pA = (float *)(m_unk3C != 0 ? (char *)m_unk3C + 0x80 : (char *)m_unk190);
                    sceVu0SubVector(sp30, pA, pB);
                    float fAng = Round180__Ff(57.295776f * atan2f(sp30[0], sp30[2]));
                    m_unk1C4 = fAng;
                    m_unk3C[37] = fAng;
                    char *pD = *(char **)(s0 + 0x3C) + 0x90;
                    *(float *)(pD + 4) = Round180__Ff(180.0f + m_unk1C4);
                    SetAction(0x3A);
                    m_unk335 = 4;
                    PlingEffect *t = m_unk32C;
                    if (t != 0) {
                        mEffectAPI__13EntityManager.DeleteEffect((EffectNode *)t);
                        m_unk32C = 0;
                    }
                    gSound.SetMainMusicSpecialVolume((PSound::EnumMusicSpecialVols)2);
                }
                break;
            case 3:
                if ((a1 & 0x8000) && m_unk334 != 0) {
                    char *pE = *(char **)(s0 + 0x3C);
                    float *pV = (float *)(pE != 0 ? pE + 0x90 : s0 + 0x1A0);
                    m_unk1C4 = Round180__Ff(180.0f + pV[1]);
                    SetAction(0x2E);
                    EnableSleep__15EntityBaseClassFbb(s0, false, false);
                }
                break;
            case 5:
                if ((a1 & 0x8000) && m_unk334 != 0) {
                    char *pE = *(char **)(s0 + 0x3C);
                    float *pV = (float *)(pE != 0 ? pE + 0x90 : s0 + 0x1A0);
                    m_unk1C4 = Round180__Ff(180.0f + pV[1]);
                    SetAction(0x2F);
                }
                break;
            case 4:
                if ((a1 & 0x8000) && m_unk334 != 0) {
                    char *pE = *(char **)(s0 + 0x3C);
                    float *pV = (float *)(pE != 0 ? pE + 0x90 : s0 + 0x1A0);
                    m_unk1C4 = Round180__Ff(180.0f + pV[1]);
                    SetAction(0x30);
                }
                break;
            case 7:
                if (a1 & 0x8000) {
                    char *pE = *(char **)(s0 + 0x3C);
                    float *pV = (float *)(pE != 0 ? pE + 0x90 : s0 + 0x1A0);
                    m_unk1C4 = pV[1];
                    SetAction(0x3E);
                    m_unk330 = (GunTurret *)s0;
                }
                break;
            }
        }
    } else {
        PlingEffect *t = m_unk32C;
        if (t != 0) {
            *(int *)((char *)t + 0x14) = 0x3DCCCCCD;
            m_unk32C = 0;
        }
    }
    m_unk324 = 0;
}

// DRAFT: 0x00164BF0 SetPling__6PlayerFQ26Player9PlingTypeP15EntityBaseClassUi
// note: 120 words; sound-ID branch grouping, m_unk334 placement and the printf guard are unresolved.
void Player::SetPling(PlingType arg0, EntityBaseClass *arg1, unsigned int arg2) {
    if (*((unsigned char *)&gInterface + 0x1A07) == 0) {
        return;
    }
    if (m_unk32C != 0) {
        m_unk32C->Slot00(1);
        m_unk32C = 0;
        return;
    }
    if (m_unk26C != 0) {
        return;
    }
    if (m_unk26B != 0) {
        return;
    }
    if (m_unk2F8 != 0.0f) {
        return;
    }
    if (m_unk229 >= 4) {
        return;
    }
    if (m_unk324 != 0) {
        return;
    }
    if ((m_unk264 & 0x30) == 0) {
        return;
    }
    if ((m_unk1D0 & 4) == 0) {
        return;
    }
    if (arg0 >= 8) {
        CdsAssert("Player.cpp", 0x770, "eType < MAX_PLING");
    }
    m_unk324 = arg0;
    m_unk328 = *(int *)((char *)arg1 + 4);
    if (m_unk32C == 0) {
        PlingEntry *e = &PlingTable[arg0];
        if (arg2 == 0) {
            arg2 = e->unk4;
        }
        if (arg2 != 0) {
            unsigned int v = *(unsigned int *)((char *)this + 0x1D4 + e->unk0 * 4);
            if (v < arg2) {
                unsigned int nSnd;
                unsigned int nTag;
                unsigned int nArg;
                if (e->unk8 != 0) {
                    arg2 = 0x81000009;
                    nTag = 0x82000040;
                    nSnd = 0x34;
                    m_unk334 = 0;
                } else {
                    arg2 = 0x81000007;
                    nTag = 0x8200003F;
                    nSnd = 0xE3;
                    m_unk334 = 0;
                }
                m_unk334 = 1;
                PlaySoundApparition__6PSoundFUiUi(&gSound, nSnd, 0x80000000);
                m_unk32C = mEffectAPI__13EntityManager.CreatePling((EntityBaseClass *)this, 4.5f, arg2, nTag, false);
                nArg = nSnd;
                if (nArg != 0) {
                    printf("Pling is used by %d\n", nArg);
                }
                return;
            }
        }
    }
}

// DRAFT: 0x00164E20 UpdateBodyBox__6PlayerFv
// note: 98 words differ; float clamp block uses f1-f3 where original uses f20/f21, 6-arm exit layout and FastMath_Fabs reloc differ; tried switch form, else-first, and single-load case 6 (109)
void Player::UpdateBodyBox() {
    char *a3 = *(char **)((char *)this + 0x294);
    if (a3 != 0) {
        float *s0 = (float *)((char *)m_unk38 + 0x80);
        switch (m_unk260) {
        case 6:
            s0[1] = s0[6];
            s0[5] = s0[6];
            break;
        default: {
            float f1 = *(float *)((char *)m_unk3C + 0x84);
            float f2;
            if ((m_unk1D0 & 4) || !(m_unk264 & 0x80)) {
                f2 = 0.0f;
            } else {
                f2 = *(float *)(a3 + 0x74) - f1;
            }
            float f21 = *(float *)(*(char **)((char *)this + 0x290) + 0x74) - f1;
            float f20 = f2;
            if (f21 < f2) {
                f20 = f21;
                f21 = f2;
            }
            float c20 = f20 - 0.75f;
            if (c20 < 0.0f) {
                c20 = 0.0f;
            }
            float c21 = f21 + 1.0f;
            float t0 = 2.0f + c20;
            if (c21 < t0) {
                c21 = t0;
            }
            if ((c20 == 0.0f) && (c21 < MIN_TOP)) {
                c21 = MIN_TOP;
            }
            float t22 = s0[1] + s0[5];
            float t23 = c21 - t22;
            if (!(FastMath_Fabs__Ff(t23) <= 1.0f)) {
                c21 = t22 - 1.0f;
                if (!(t23 <= 0.0f)) {
                    c21 = 1.0f + t22;
                }
            }
            float t22b = s0[1] - s0[5];
            float t23b = c20 - t22b;
            if (!(FastMath_Fabs__Ff(t23b) <= 1.0f)) {
                c20 = t22b - 1.0f;
                if (!(t23b <= 0.0f)) {
                    c20 = 1.0f + t22b;
                }
            }
            float h = 0.5f * (c21 + c20);
            s0[1] = h;
            s0[5] = c21 - h;
        }
        }
    }
}

static int PadTimer;
static signed char StickDir[2];
static signed char stick_tbl[32];

// DRAFT: 0x00165050 TimerUpdate__6PlayerFv
// note: DIFF 282; size 0x4DC vs 0x518 (prologue frame 0x30 vs 0x40, no f20/s1 spill match); m_unk314 bc1t delay slot filled by andi; m_unk20 early return layout; gEng gate addend 0x194F0 (asm lui 0x2F + lw -0x6B10) unverified; tried one-case switch on m_unk26B (288->282), pFont hoist (316->288), one-case switch on m_unk20 (285, reverted), flag-first test order (286, reverted)
void Player::TimerUpdate() {
    float fDt = *(float *)(gEng + 0x1E8);
    if (m_unk304) {
        m_unk304 = m_unk304 - fDt;
        if (m_unk304 <= 0.0f) {
            m_unk304 = 0.0f;
            *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) = 0;
            m_unkE8 = 0x13;
        }
    }
    int nFlags = m_unk264;
    if (!(nFlags & 0x400)) {
        switch (m_unk26B) {
        case 0:
        if (*(float *)&m_unk314 && !(nFlags & 0x401)) {
            *(float *)&m_unk314 = *(float *)&m_unk314 - fDt;
            if (*(float *)&m_unk314 <= 0.0f) {
                *(float *)&m_unk314 = 0.0f;
                m_unk220 = 0;
                m_unk21C = 0;
                ComboFinish__8HudComboFv((char *)&gInterface + 0x19A0);
            }
        }
        if (m_unk1D0 & 1) {
            if (m_unk20 != 0) {
                return;
            }
            *(float *)&m_unk300 = *(float *)&m_unk300 - fDt;
            if (*(float *)&m_unk300 <= 0.0f) {
                *(float *)&m_unk300 = 60.0f;
                *(int *)(gMC + 0x26F0) = *(int *)(gMC + 0x26F0) + 1;
            }
            if (m_unk229 == 4) {
                *(float *)&m_unk310 = *(float *)&m_unk310 - fDt;
                if (*(float *)&m_unk308) {
                    *(float *)&m_unk310 = *(float *)&m_unk310 - fDt;
                }
                if (*(float *)&m_unk310 <= 0.0f) {
                    if (m_unk200 >= 2 || (m_unk264 & 0x30)) {
                        GameVarSub(0xB, 1);
                        *(float *)&m_unk310 = GRIM_TIME;
                    }
                }
            } else {
                if (*(float *)&m_unk308 && !(m_unk264 & 0x1000)) {
                    *(float *)&m_unk308 = *(float *)&m_unk308 - fDt;
                    if (*(float *)&m_unk308 <= 0.0f) {
                        if (m_unk26C != 0) {
                            SetHeadCamera(false);
                        }
                        if (GameVarSub(1, m_unk30C) == 0) {
                            SetAction(0x18);
                            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x800U, 0);
                            return;
                        }
                        *(float *)&m_unk308 = SULFUR_TIME;
                        FlashTexture__15EntityBaseClassFUii(this, 0x84000008U, 10);
                        if ((*(int *)((char *)m_unk38 + 0xE8) & 0x100001) == 0x100000) {
                            UpdateSulphurFx__15EntityBaseClassFf(this, *(float *)((char *)m_unk38 + 0xC4));
                        }
                    }
                }
            }
            if (*(float *)&m_unk2F8) {
                *(float *)&m_unk2F8 = *(float *)&m_unk2F8 - fDt;
                if (*(float *)&m_unk2F8 <= 0.0f) {
                    *(float *)&m_unk2F8 = m_unk2FC;
                    if (GameVarSub(1, 0x19) == 0) {
                        SetAction(0x16);
                        return;
                    }
                    FlashTexture__15EntityBaseClassFUii(this, 0x84000008U, 10);
                }
            }
            if (*(float *)&m_unk318) {
                *(float *)&m_unk318 = *(float *)&m_unk318 - fDt;
                if (*(float *)&m_unk318 < 0.0f) {
                    *(float *)&m_unk318 = 0.0f;
                }
            }
            char *pFont = (char *)&gInterface + 0x1790;
            if (m_unk337 != 0) {
                if (*(float *)&m_unk318 == 0.0f) {
                    *(float *)&m_unk318 = 60.0f;
                    int nVib = 4;
                    if (m_unk337 == 1) {
                        nVib = 8;
                    }
                    gPad.SetVibrate((Pad::VibType)4, nVib & 0xFF);
                }
                if (*((unsigned char *)&gPad + 0x16F) == 0) {
                    FontNode *pText = m_unk31C;
                    if (pText != 0 && Find__6PArrayFPv(pFont, pText) < 0) {
                        m_unk31C = 0;
                    }
                    if (m_unk31C == 0 && IsTreasureOK__9InterfaceFv((char *)&gInterface + 0x1710) != 0) {
                        m_unk31C = (FontNode *)DisplayString__11FontManagerFiiib(pFont, 0x9D, 0, 0, false);
                    }
                    FontNode *pCur = m_unk31C;
                    if (pCur != 0) {
                        float fStep;
                        if (m_unk337 == 1) {
                            fStep = 0.05f;
                        } else {
                            fStep = 0.03f;
                        }
                        float fNew = *(float *)((char *)pCur + 8) - fStep;
                        if (fNew < 0.0f) {
                            fNew = 1.0f;
                        }
                        *(float *)((char *)pCur + 8) = fNew;
                    }
                }
                m_unk337 = 0;
            } else {
                *(float *)&m_unk318 = 0.0f;
                FontNode *pRem = m_unk31C;
                if (pRem != 0) {
                    RemoveText__11FontManagerFP8FontNode(pFont, pRem);
                    m_unk31C = 0;
                }
            }
            if (m_unk229 == 2 && m_unk218 == 3 && (gEng[0x194F0] & 1)) {
                GameVarAdd(0xE, 1, 0);
            }
        }
        break;
        }
    }
}

// DRAFT: 0x00165570 PadUpdate__6PlayerFb
// note: DIFF 197, size 0x3DC vs 0x3A4; flag-chain order, branch layout, 0x3D pointer walk, stick_tbl bytes, gEng/gPad addends differ; tried nested and flat 0x26B guard (197), pointer-walk variant (202)
void Player::PadUpdate(bool arg0) {
    if (arg0) {
        unsigned char *pEng = gEng + 0x19760;
        m_unk1B0 = *(short *)((char *)m_unk25C + 6) & gPad.m_unk10C;
        m_unk1B2 = *(short *)((char *)m_unk25C + 6) & gPad.m_unk110;
        m_unk1B6 = gPad.m_unk116;
        m_unk1B7 = gPad.m_unk117;
        m_unk1B8 = gPad.m_unk108;
        m_unk1BA = gPad.m_unk10A;
        unsigned char prev = m_unk26B;
        m_unk26B = pEng[0x2B8];
        if (m_unk26B != 0) {
            if ((m_unk26B & 0xFF) != prev) {
                if (((unsigned char *)m_unk254)[7] == 2) {
                    char *p = (char *)m_unk3C;
                    *(int *)(p + 0x18) = 0;
                    char *q = 0;
                    if (*(char **)(p + 0x14) != 0) {
                        q = *(char **)(*(char **)(p + 0x14) + 8);
                    }
                    if (q != 0) {
                        q[0x3D] = 6;
                    }
                }
            }
        }
        if ((m_unk26C != 0) || (m_unk26A != 0) || (m_unk26B != 0) || (m_unk26D != 0)) {
            m_unk1B0 &= 9;
            if ((m_unk26A != 0) || (m_unk26B != 0) || (m_unk26D != 0)) {
                m_unk1B2 &= 9;
            }
            m_unk1B4 = 0;
            m_unk1B5 = 0;
        } else {
            m_unk1B4 = gPad.m_unk114;
            m_unk1B5 = gPad.m_unk115;
            if (*(int *)(pEng + 0xB4) == 3) {
                m_unk1B4 = stick_tbl[((m_unk1B0 >> 4) & 0xF) * 2];
                m_unk1B5 = stick_tbl[((m_unk1B0 >> 4) & 0xF) * 2 + 1];
            }
            if (PadTimer != 0) {
                PadTimer = PadTimer - 1;
                if (PadTimer <= 0) {
                    char *p3;
                    if (m_unk3C != 0) {
                        p3 = (char *)m_unk3C + 0x80;
                    } else {
                        p3 = (char *)&m_unk190;
                    }
                    PadTimer = ((int)*(float *)p3 & 0xF) + 8;
                    m_unk1B2 = 1 << ((*(unsigned short *)(gEng + 0x19A80) & 0xF) + 0xC);
                    char *p4;
                    if (m_unk3C != 0) {
                        p4 = (char *)m_unk3C + 0x80;
                    } else {
                        p4 = (char *)&m_unk190;
                    }
                    StickDir[0] = (signed char)((unsigned char)gEng[0x19A80] + (*(int *)(p4 + 8) & 0xFF));
                    StickDir[1] = -StickDir[0];
                }
                m_unk1B4 = StickDir[0];
                m_unk1B5 = StickDir[1];
            }
        }
    } else {
        m_unk1B0 = 0;
        m_unk1B2 = 0;
        m_unk1B4 = 0;
        m_unk1B5 = 0;
        m_unk1B6 = 0;
        m_unk1B7 = 0;
        m_unk1B8 = 0;
        m_unk1BA = 0;
    }
    signed char a = m_unk1B4;
    signed char b = m_unk1B5;
    if (a < 0) {
        a = -a;
    }
    bool useB = b < a;
    if (b < 0) {
        b = -b;
        useB = b < a;
    }
    m_unk1BC = ((useB == 0) ? b : a) & 0xFF;
    if (m_unk1BC >= 0x65) {
        m_unk1C0 += 1;
    } else {
        m_unk1C0 = 0;
    }
    float f;
    if ((m_unk1BC >= 0x32) && !(m_unk264 & 0x400)) {
        float t = 57.295776f * atan2f((float)-m_unk1B4, (float)m_unk1B5);
        unsigned char *pEng2 = gEng + 0x19760;
        if (pEng2[0xB1] != 0) {
            f = Round180__Ff(t + *(float *)(pEng2 + 0x24));
        } else {
            f = Round180__Ff(t);
        }
    } else {
        f = *(float *)((char *)m_unk38 + 0x11C);
    }
    m_unk1C4 = f;
}

// FUNCTION: 0x00165930 SavePlayerData__6PlayerFPQ26Player10PlayerData
void Player::SavePlayerData(Player::PlayerData *arg0) {
    if (arg0 == 0) {
        CdsAssert("Player.cpp", 0x58C, "pData");
    }
    m_unk21C = 0;
    memcpy(arg0, &m_unk1D0, 0x7C);
}

// FUNCTION: 0x00165990 LoadPlayerData__6PlayerFPQ26Player10PlayerData
void Player::LoadPlayerData(Player::PlayerData *arg0) {
    if (arg0 == 0) {
        CdsAssert("Player.cpp", 0x581, "pData");
    }
    memcpy(&m_unk1D0, arg0, 0x7C);
    if (m_unk229 == 4) {
        m_unk229 = MaximoArmor[m_unk1DC];
    }
    m_unk21C = 0;
    m_unk220 = 0;
}

// FUNCTION: 0x00165A20 ResetPlayerData__6PlayerFPQ26Player10PlayerData
void Player::ResetPlayerData(Player::PlayerData *arg0) {
    int i;
    int a1;
    int a3;
    if (arg0 == 0) {
        CdsAssert("Player.cpp", 0x570, "pData");
    }
    ((char *)arg0)[0x58] = 0;
    ((char *)arg0)[0x59] = 0;
    ((char *)arg0)[0x5A] = -0x80;
    *(int *)arg0 = 1;
    i = 0;
    a1 = 0;
    a3 = 0;
    while (i < 0xC) {
        short *src = (short *)((char *)GameVarTbl + a1);
        int *dst = (int *)((char *)arg0 + a3);
        dst[1] = src[0];
        dst[2] = src[3];
        dst[3] = src[6];
        dst[4] = src[9];
        dst[5] = src[12];
        dst[6] = src[15];
        dst[7] = src[18];
        dst[8] = src[21];
        i += 8;
        a1 += 0x30;
        a3 += 0x20;
    }
    for (; i < 0x14; i++) {
        ((int *)arg0)[i + 1] = ((short *)((char *)GameVarTbl + i * 6))[0];
    }
    memset((void *)((unsigned int)arg0 + 0x5B), -1, 0x20);
    *(int *)((char *)arg0 + 0x54) = 1;
    ((char *)arg0)[0x5B] = 0;
    ((char *)arg0)[0x63] = 4;
    ((char *)arg0)[0x73] = 0x15;
}

// FUNCTION: 0x00165B60 Kill__6PlayerFv
void Player::Kill() {
    if (m_unk1D0 & 1) {
        ForceDie(0x1A);
    }
}

// DRAFT: 0x00165C20 GameVarSet__6PlayerFUii
// note: 95 words; returns int (0 on the GameVarTbl gates, 1 otherwise); tried &GameVarTbl[i], (T*)(GameVarTbl+i) pointer forms, no gain.
int Player::GameVarSet(unsigned int arg0, int arg1) {
    unsigned char *pEntry;
    ((arg0 < 0x14) ? (void)0 : CdsAssert("Player.cpp", 0x506, "iVar < GameVarMax"));
    ((arg1 >= 0) ? (void)0 : CdsAssert("Player.cpp", 0x507, "iValue >= 0"));
    pEntry = (unsigned char *)GameVarTbl + arg0 * 6;
    if (pEntry[4] != 0 && (m_unk1D0 & 1) == 0) return 0;
    if (pEntry[5] != 0 && m_unk229 >= 4) return 0;
    if (arg0 != 0xD) {
        if (arg0 == 0xF) {
            ((EntityBaseClass *)this)->PlaySound(0x20);
            if (m_unk210 != arg1) {
                m_unk210 = arg1;
                if (m_unk2A4 == 0) SetShield(true);
            }
            return 1;
        }
        if (arg0 == 0xA) {
            int old = m_unk1FC;
            if (old == arg1) return 1;
            if (((old ^ arg1) & 2) != 0) {
                if (m_unk229 != 4 && (*(int *)((char *)m_unk38 + 0x108) & 1) == 0) {
                    m_unk339 = (signed char)arg1;
                    return 1;
                }
                *((char *)this + 0x22A) = (char)old;
            }
            SetSword();
            m_unk1FC = arg1;
            ((EntityBaseClass *)this)->PlaySound(0xE4);
            SetPowerupMotion(0x39);
            return 1;
        }
        if (arg0 == 0x11) {
            int old = m_unk218;
            m_unk218 = arg1;
            m_unk1D4 = (arg1 == 4) ? 4 : 3;
            if (m_unk229 == 2) {
                if (((old ^ arg1) & 4) != 0) SetMaximo(2, false);
                else UpdateDisplayList();
            }
        }
    }
    ((int *)((char *)this + 0x1D4))[arg0] = arg1;
    return 1;
}

// note: 31 differing lines; original keeps the row base in a2 and counter in a0 with mbHard loaded first; ours uses a1/a0 and a different loop shape. Tried: first loop form (about 30), base pointer ComboLevel[mb*10] (32), mb/thr locals first (31, kept).
// DRAFT: 0x00165B90 GetComboLevel__6PlayerFv
// note: 26 differing words with the goto-entered loop (was 29); original has mb in a2, thr in a1, off in a3, i in a0, and a different tail sum order (ComboLevel+4 then row then i*8). Tried: base pointer, unsigned i, decl orders, &ComboLevel[1] tail, explicit pointer walk, for-loop form.
int Player::GetComboLevel() {
    unsigned int i = 0;
    int off = 0;
    int mb = mbHard__15EntityBaseClass;
    int thr = m_unk220;
    char *base = (char *)ComboLevel + mb * 0x28;
    goto test;
loop:
    if (*(int *)(base + off) >= thr) { goto done; }
    off += 8;
    i++;
test:
    if (i < 10) goto loop;
done:
    return *(int *)((char *)&ComboLevel[1] + mb * 0x28 + i * 8);
}
