// FLAGS: -str readonly
#include "Player.h"

// TODO(header): foreign declarations
extern unsigned char gEng[];
class Interface {
public:
    char _pad000[0x10];
    void AddAbility(int arg0);
    char _pad010[0x415];
    unsigned char m_unk425;
    enum eFadeColor { eFadeColor_Value0 = 0, eFadeColor_Value1 = 1, eFadeColor_Value2 = 2 };
    void FadeScreen(float arg0, float arg1, bool arg2, eFadeColor arg3);
};
extern Interface gInterface;
extern signed char AbilityTable[];
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
    int ProcessHitBack();
    void SetState(int arg0);
    void PlaySound(unsigned int arg0);
    void ResetCollisions();
    void Animate(int arg0, float arg1);
};
class PAnim;
class PGrimReaperCape {
public:
    void AnimateControlNode(PAnim *arg0, float arg1);
};
class PDynamicSplinePatch {
public:
    void Animate(float arg0);
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
};

class PMNode {
public:
    virtual void Slot08();
    virtual void Slot0C();
    virtual void Slot10(float arg0);
    virtual void Slot14();
    virtual void Animate(float arg0, float arg1, PMat4 *arg2, int arg3, bool arg4);
    char _pad04[0x20];
    AnimStateObject *m_unk24;
    void ProcessFxTriggers(float arg0, PMat4 *arg1, bool arg2, bool arg3);
    void EnableFx(bool arg0, bool arg1);
    void SetAnimLoopCount(int arg0, bool arg1);
    float GetFrameTime();
    PMNode *FindAnimNode(unsigned int arg0);
    int Find(PMNode *arg0);
    PMNode *Find(unsigned int arg0);
};
class FreeJoint {
public:
    int m_unk00;
    unsigned char m_unk04;
    char _pad05[3];
};
extern FreeJoint m_pFreeJoints[5];
class Physics {
public:
    char _pad000[0x11C];
    float m_unk11C;
    void SetPhysicsType(unsigned int arg0, float (*arg1)[4]);
    void SetVelocity(float arg0, float arg1);
};
class Debug {
public:
    void DebugDisp(char *pText);
    char _pad000[0x10];
};
extern Debug gDebug;
class Camera {
public:
    int SetHeadCam(bool arg0);
};
class PSound {
public:
    char _pad000[0x18080];
    void PlaySoundApparition(unsigned int arg0, unsigned int arg1);
    void FadeOutAllMusic(unsigned int arg0);
};
extern PSound gSound;
class EffectAPI {
public:
    char _pad000[20];
    int CreateOneshot(unsigned int, unsigned int, float (*)[4], float (*)[4], EntityBaseClass *, float, bool, int, bool);
};
extern EffectAPI mEffectAPI__13EntityManager;
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" long long fptodp(float arg0);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void __dl__FPv(void *pMem);
extern unsigned char __vt__10PAnimFrame[];
extern "C" void *__dt__5PAnimFv(void *pThis, short nFlag);
extern void *mpEntMgr__15EntityBaseClass;
extern int mbHard__15EntityBaseClass;
extern int ComboLevel[20];
extern int CAUGHT_TIME;
extern float AttachedTimer[5];
struct AttachableJoint {
    int m_unk00;
    int m_unk04;
    float m_unk08;
    float m_unk0C;
    float m_unk10;
};
extern AttachableJoint m_AttachableJoints[5];
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *, unsigned int);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" float atan2f(float fY, float fX);
extern "C" float Round180__Ff(float fAngle);
class Pad {
public:
    enum VibType { VIB_0 = 0, VIB_1 = 1 };
    void SetVibrate(VibType arg0, unsigned char arg1);
    char _pad000[0x110];
    unsigned short m_unk110;
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
// note: 30 words differ. Ours hoists lui a0 into the bgez delay slot (original has nop); f0/f1 allocation swapped (original zero in f0, timer in f1). Tried direct store, local fTimer, fZero, reversed compare.
void Player::DetachJoint(int arg0) {
    if (m_pFreeJoints[arg0].m_unk04 == 0) {
        m_pFreeJoints[arg0].m_unk00 = 0;
        m_pFreeJoints[arg0].m_unk04 = 1;
        m_unk23D4 += 1;
        if (m_unk23D4 < 0) {
            CdsAssert__FPciPc("Player.cpp", 0x2260, "m_iNumFreeJoints >= 0");
        }
        m_unk23D1 = (unsigned int)m_unk23D4 < 4U;
        float fTimer = AttachedTimer[5 - m_unk23D4];
        m_unk2FC = fTimer;
        if (fTimer == 0.0f) {
            *(float *)&m_unk2F8 = 0.0f;
        }
    }
}

// FUNCTION: 0x00159260 GetAttachableJointOffsets__6PlayerFiPA4_f
void Player::GetAttachableJointOffsets(int arg0, float (*arg1)[4]) {
    float fVec[4];
    unsigned int uVal;
    if (m_pFreeJoints[arg0].m_unk00 == 0) {
        CdsAssert__FPciPc("Player.cpp", 0x2221, "m_pFreeJoints[index].pJoint");
    }
    fVec[0] = m_AttachableJoints[arg0].m_unk08;
    fVec[1] = m_AttachableJoints[arg0].m_unk0C;
    fVec[2] = m_AttachableJoints[arg0].m_unk10;
    uVal = (unsigned char)m_pFreeJoints[arg0]._pad05[0];
    fVec[3] = (float)uVal;
    *(u_long128 *)arg1 = *(u_long128 *)fVec;
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

// FUNCTION: 0x00159AF0 OutputDebug__6PlayerFv
void Player::OutputDebug() {
    char buf[0x100];
    if (m_unk3C != 0) {
        sprintf(buf, "Action %d, frame %f, Atk(%d, 0x%x), Combo %d", m_unk260, fptodp(m_unk3C[13]), m_unk15C, m_unk15E, m_unk220);
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

// note: 8 words differ: original keeps the loaded value in v1 and the 1 in v0 before the 0x2A compare; compiled code loads into a0 and uses daddiu. Tried bool, ||, nested if/else and unsigned char locals.
// DRAFT: 0x0015A4B0 IsHanging__6PlayerFv
unsigned char Player::IsHanging() {
    int state = m_unk260;
    int ret = 1;
    if (state != 0x2A) {
        if (state != 0x2B) {
            ret = 0;
        }
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

// DRAFT: 0x0015AE60 SetPowerupMotion__6PlayerFi
// note: original keeps 0x3D in v0 and uses a shared jr-ra exit (size 0x80); ours uses v1/a2 and separate epilogues (size 0x6c). Tried separate returns (28 words), goto exit (27), nested with result (27), reversed compare (27).
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

// DRAFT: 0x0015B2A0 ResurrectionMove__6PlayerFv
// note: 23 words, size 0x64 vs 0x6c; original uses beqz with addiu v1,2 in delay slot and a shared b exit; if-body, if/else-return, goto and early-return forms all stay at 23 (bnez + nop).
void Player::ResurrectionMove() {
    if (m_unk250 == 0) {
        m_unk250 = 2;
        mEffectAPI__13EntityManager.CreateOneshot(0x81000038, 0x8200006D, (float (*)[4])((char *)m_unk3C + 0x80), (float (*)[4])((char *)m_unk3C + 0x90), 0, 0.5f, false, 0, false);
    }
}

// note: 1 word differs at 0x14: original copies this to s1 at entry and loads 0x328(s1); ours loads 0x328(a0). Tried hoisted id local, plain this, self pointer, and ((Player *)self) cast; all the same.
// DRAFT: 0x0015B9B0 UnlockGateMove__6PlayerFv
void Player::UnlockGateMove() {
    Player *self = this;
    void *pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, ((Player *)self)->m_unk328);
    if (pApparition != 0) {
        int state = self->m_unk250;
        int h = (int)self->m_unk3C[13];
        switch (state) {
        case 0:
            ((ApparitionVirtuals *)pApparition)->OnHitEvent(self, 0, 0x1FF, 0);
            self->m_unk250 = 1;
            break;
        case 1:
            if (h >= 0xD) {
                self->m_unk250 = 2;
                self->GameVarSub(8, 1);
                self->UpdateKey();
            }
            break;
        case 2:
            if (h >= 0x23) {
                self->m_unk250 = 3;
                ((EntityBaseClass *)self)->PlaySound(0x99);
            }
            break;
        }
        self->AlignPosition((EntityBaseClass *)pApparition);
    }
}

// note: 2 words differ: the gp global mpEntMgr loads into a0 before the m_unk328 load into a1; the original has them reversed. Tried a hoisted id local (worse), a cast local (same).
// DRAFT: 0x0015BC20 OpenChestMove__6PlayerFv
void Player::OpenChestMove() {
    if (m_unk250 == 0 && !(m_unk3C[0xD] <= 8.0f)) {
        m_unk250 = 1;
        void *pApparition = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, m_unk328);
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

// note: 27 words differ: the bool lives in a1 instead of v1 and the original's andi v1,v1,0xFF truncation is missing. Tried unsigned char flag (27), implicit int-to-bool assignment (27), int flag with if/else (42), and bool with pAnim == 0 || !IsAnimate (44).
// DRAFT: 0x0015BE80 DieMove__6PlayerFv
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

// FUNCTION: 0x0015C090 ResetShield__6PlayerFv
void Player::ResetShield() {
    if (m_unk2A4 != 0) {
        m_unk2A4->DeleteShield();
        ((EntityBaseClass *)m_unk2A4)->SetState(-2);
        m_unk2A4 = 0;
        SetShield(true);
    }
}

// note: 2 words differ: SetShield argument is lowered to movn/sltu instead of the original's daddu zero-preload and movz a1,v0,s0. Tried arg0 ? 0 : 1 (33 words), (arg0 == 0) ? true : false (movn, no gain), and the empty-then layout (33 words).
// DRAFT: 0x0015C0E0 SetFlyingShield__6PlayerFP6Shield
void Player::SetFlyingShield(Shield *arg0) {
    SetShield((arg0 == 0) ? 1 : 0);
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

// note: 2 words differ: the zero-set for the return-0 arm lands in the bne delay slot and the nop moves to the b delay slot. Tried ret=0 and return 0 in the != 1 arm (both 2 lines), and the == 1 layout (about 20 lines).
// DRAFT: 0x0015C490 IsMidasActive__6PlayerFv
void *Player::IsMidasActive() {
    void *ret;
    if (m_unk210 != 1) {
        ret = 0;
    } else {
        if (m_unk2A4 != 0) {
            ret = m_unk2A4;
        } else {
            Player *p = this;
            if (!(m_unk264 & 2) || ((m_unk1B0 & 0x200) == 0)) {
                p = 0;
            }
            ret = p;
        }
    }
    return ret;
}

// note: 12 words differ: original tests m_unk250 with beqz into the body and exits via b with ld ra in the delay slot; compiled code emits bnez to the shared exit. Tried nested if, inner early return and && forms, all 12 words.
// DRAFT: 0x0015C4F0 GuardHitMove__6PlayerFv
void Player::GuardHitMove() {
    if (m_unk250 != 0) {
        return;
    }
    if (((EntityBaseClass *)this)->ProcessHitBack() == 0) {
        m_unk250 = 1;
    }
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

// DRAFT: 0x0015CD50 SliceMove__6PlayerFv
// note: 9 words differ: CancelAttack branch form (inverted test gives 27, a v1-first else gives 32), the ComboTarget literal order (a local float gives 9), and the t!=0 block placement.
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
        ComboTarget(-1.0f, 100.0f, true);
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

// FUNCTION: 0x0015D4C0 UpwardStrikeMove__6PlayerFv
void Player::UpwardStrikeMove() {
    static unsigned int UpperFx[3][2] = {{0x8100006A, 0x820000BC}, {0x810001ED, 0x8200039A}, {0x8100020C, 0x82000367}};
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
        float fHi = 100.0f;
        float fLo = -1.0f;
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

// FUNCTION: 0x0015DC20 CancelMove__6PlayerFv
void Player::CancelMove() {
    if ((int)m_unk3C[13] >= ((unsigned char *)m_unk254)[4]) {
        CancelAttack(0x30);
    }
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

// note: 10 words differ: original branches to the body on beqz and skips it with an unthreaded b to the epilogue; compiled code threads that into bnez. Tried the early-return form and an empty-then if/else, both threaded the same way.
// DRAFT: 0x0015E250 AirSliceMove__6PlayerFv
void Player::AirSliceMove() {
    if (m_unk250 == 0) {
        m_unk250 = 1;
        m_unk38[1] = 0x3A83126F;
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

// FUNCTION: 0x0015E970 GrimSlash2Move__6PlayerFv
void Player::GrimSlash2Move() {
    if ((int)m_unk3C[13] >= 0x32) {
        CancelAttack(0x30);
    }
}

// DRAFT: 0x0015EAC0 GrimAirSlashMove__6PlayerFv
// note: 6 words differ: first temp<7 compare uses v1 not at, and ComboTarget float literal loads are in reverse order (f12 before f13); early-return form and nested form tried, same count.
void Player::GrimAirSlashMove() {
    int temp = (int)m_unk3C[13];
    if (temp >= 7) {
        if (m_unk1B2 & 0x8000) {
            m_unk250 = 1;
        }
        if (temp >= 0xC && m_unk250 != 0) {
            ComboTarget(-1.0f, 100.0f, true);
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

// DRAFT: 0x0015F5E0 FootStepSound__6PlayerFPUs
// note: 6 words differ: addu index temp goes to a0 not a1, lhu/cvt order and mfc1 register swapped, slt sense inverted. Tried negated compare (31), index local (29), else-if sound chain (6, kept).
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

// note: 2 words differ: the move of this into a0 lands in the beq delay slot instead of the jal delay slot. Tried nested ifs, early return, reordered operands and swapped != form (3 lines).
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

// DRAFT: 0x0015F770 LandingMove__6PlayerFv
void Player::LandingMove() {
    int action = GetGroundAction();
    if (action != 0xA && action != 0 && action != m_unk260) {
        SetAction(action);
    }
}

// note: DIFF 36 best (separate null guard); nested guard DIFF 43; bool/uchar Slot18 and early-return variants worse. Differs: beqz/bnez at 0x1C, sltu/andi after Slot18 call, branch-to-tail shape.
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
        int raw = ((unsigned char *)m_unk254)[5];
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

// note: 4 words differ: original keeps the loaded pointer in a1 and passes it as a0 for the call; compiled code keeps it in t0. Tried void * and int locals; int does not compile, void * still 4 words.
// DRAFT: 0x001601F0 UpdatePlayerFx__6PlayerFv
void Player::UpdatePlayerFx() {
    PMNode *temp_a1 = (PMNode *)m_unk288;
    if (temp_a1 != 0) {
        temp_a1->ProcessFxTriggers(1.0f, (PMat4 *)(m_unk284 + 0x40), false, false);
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

// FUNCTION: 0x001605A0 ResetEye__6PlayerFb
void Player::ResetEye(bool arg0) {
    PMNode *s1 = (PMNode *)m_unk3C;
    PMNode *v0 = s1->Find(0x4F1C44BDU);
    if (v0 != 0) {
        float *v1;
        if (arg0) {
            v1 = LEye;
        } else {
            v1 = gUnitMatrix;
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
            v1 = gUnitMatrix;
        }
        *(u_long128 *)((char *)v0 + 0x90) = *(u_long128 *)v1;
        *((unsigned char *)v0 + 0x3E) |= 8;
    }
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

// note: branch shape and 0x27 path match; the original keeps m_unk1BC in v0 and flags in v1, ours uses v1 for m_unk1BC. Tried flags local (fixes lhu slot), early-return tail (worse), nested 0x200 check (same), direct field reads (same).
// DRAFT: 0x00162010 GetGroundAction__6PlayerFv
int Player::GetGroundAction() {
    unsigned short flags = m_unk1B0;
    if (m_unk1D0 & 8) {
        int r = 0xB;
        if (m_unk1BC < 0x32) {
            r = 0xA;
        }
        return r;
    }
    if (flags & 0x200) {
        if (m_unk2A4 == 0) {
            return 0x27;
        }
    }
    if (m_unk1BC < 0x32) {
        return 0;
    }
    int r2 = 2;
    if (m_unk1BC < 0x64) {
        r2 = 1;
    }
    return r2;
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
        ((FontManager *)((char *)&gInterface + 0x1790))->RemoveText(m_unk31C);
        m_unk31C = 0;
    }
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

// note: 37 words differ: the first compare is c.eq.s f0,f12 against the original f12,f0; the original uses two base pointers (0x360, 0x364) and no sll. Tried swapped init order (39), off-based stores (37), separate char* bases (39), and the i-loop with off (37, kept).
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

// FUNCTION: 0x00165930 SavePlayerData__6PlayerFPQ26Player10PlayerData
void Player::SavePlayerData(Player::PlayerData *arg0) {
    if (arg0 == 0) {
        CdsAssert__FPciPc("Player.cpp", 0x58C, "pData");
    }
    m_unk21C = 0;
    memcpy(arg0, &m_unk1D0, 0x7C);
}

// FUNCTION: 0x00165990 LoadPlayerData__6PlayerFPQ26Player10PlayerData
void Player::LoadPlayerData(Player::PlayerData *arg0) {
    if (arg0 == 0) {
        CdsAssert__FPciPc("Player.cpp", 0x581, "pData");
    }
    memcpy(&m_unk1D0, arg0, 0x7C);
    if (m_unk229 == 4) {
        m_unk229 = MaximoArmor[m_unk1DC];
    }
    m_unk21C = 0;
    m_unk220 = 0;
}

// FUNCTION: 0x00165B60 Kill__6PlayerFv
void Player::Kill() {
    if (m_unk1D0 & 1) {
        ForceDie(0x1A);
    }
}

// note: 31 differing lines; original keeps the row base in a2 and counter in a0 with mbHard loaded first; ours uses a1/a0 and a different loop shape. Tried: first loop form (about 30), base pointer ComboLevel[mb*10] (32), mb/thr locals first (31, kept).
// DRAFT: 0x00165B90 GetComboLevel__6PlayerFv
int Player::GetComboLevel() {
    int mb = mbHard__15EntityBaseClass;
    int thr = m_unk220;
    int i = 0;
    int off = 0;
    int row = mb * 0x28;
    while (i < 10) {
        if (*(int *)((char *)ComboLevel + row + off) >= thr) {
            break;
        }
        off += 8;
        i++;
    }
    return *(int *)((char *)ComboLevel + 4 + row + i * 8);
}
