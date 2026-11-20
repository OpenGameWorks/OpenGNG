// FLAGS: -Cpp_exceptions off -str readonly
#include "types.h"
#include "EntityBaseClass.h"
#include "CameraAPI.h"

// TODO(header): foreign declarations
extern "C" int IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(void *pFrustum, void *pBox, void *pMat);
extern "C" void SetAllFrustrumTest__6PMNodeF13eBoxIntersect(void *pNode, int eMode);
extern "C" void SetShadowCaster__13PShadowVolumeFP6PMNode(void *pVol, void *pNode);
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    int PlayMusic(unsigned int arg0);
    void ResumeAmbientSoundsByOriginatorRef(unsigned int arg0, unsigned int arg1);
    void PauseAmbientSoundsByOriginatorRef(unsigned int arg0, unsigned int arg1);
    void StopAmbientSoundsByOriginatorRef(unsigned int arg0, unsigned int arg1);
    void StopSoundsByOriginatorRef(unsigned int arg0, unsigned int arg1, unsigned int arg2);
    int PlaySoundWPitch(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4);
    int IsAmbientSoundByID(unsigned int arg0);
    char _pad000[0x10];
};
extern PSound gSound;
extern "C" float cosf(float x);
extern "C" float sinf(float x);
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern float m_fYAngle__15EntityBaseClass;
extern "C" void sceVu0UnitMatrix(void *pMatrix);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
// Per-LoadClass table, 7 entries of 12 bytes (symbol ClassTable, 0x241270, 84 bytes).
struct ClassTableEntry {
    signed char m0;
    unsigned char m1;
    unsigned char m2;
    unsigned char m3;
    unsigned char m4;
    unsigned char m5;
    int m8;
};
extern ClassTableEntry ClassTable[7];

class PMNode;

// Virtual order follows the vtable: slot 0x08 is the destructor, 0x0C is an unnamed null entry, Start is slot 0x20.
class PParticleSystem {
public:
    virtual ~PParticleSystem();
    virtual void _unk0C();
    virtual void Render();
    virtual void ModifyPosition(float (*arg0)[4]);
    virtual void FrustrumTest(void *arg0, float *arg1, float arg2, float arg3);
    virtual void FadeAndDie(unsigned int arg0);
    virtual void Start();
};

class PParticleManager {
public:
    void Remove(PParticleSystem *pSystem);
    void Add(PParticleSystem *pSystem);
    void CreateSulphurReaction(float *arg0, float arg1);
    void CreateFireDamageFx(PMNode *arg0, unsigned int arg1);
    PParticleSystem *CreateFrozenFx(PMNode *arg0, float arg1, float arg2);
    int IsValid(PParticleSystem *pSystem);
    PParticleSystem *Create(unsigned int arg0, float arg1, float arg2, float arg3, PMNode *arg4, bool arg5);
    void CreateEweedReaction(float *arg0);
};
extern char gGfxEng[1504384];

class PParticleRipples {
public:
    void Create(float *arg0, float arg1, float arg2, float arg3);
    char _pad000[0x10];
};

// PZinDamageFx size is 0xF0 (the operator new argument); the placeholder keeps the allocation size.
class PZinDamageFx {
public:
    PZinDamageFx();
    void Create(EntityBaseClass *arg0, float arg1, unsigned int arg2);
    char _pad000[0xF0];
};

class EffectAPI {
public:
    char _pad000[20];
    int CreateOneshot(unsigned int arg0, unsigned int arg1, float (*arg2)[4], float (*arg3)[4], EntityBaseClass *arg4, float arg5, bool arg6, int arg7, bool arg8);
};
extern EffectAPI mEffectAPI__13EntityManager;

class MathAPI {
public:
    static float Distance(float (*arg0)[4], float (*arg1)[4]);
    static float GetAngleYToPoint(EntityBaseClass *arg0, float (*arg1)[4]);
    static float RandomFloatRange(float arg0, float arg1);
    static void GetForwardVector(EntityBaseClass *arg0, float (&arg1)[4]);
    static void VectorRotateY(float (*arg0)[4], float arg1);
};

extern EntityBaseClass *mPlayerAPI__13EntityManager;

// PArray size is unknown; the placeholder member only keeps mBGAnimList__7Physics a complete object.
class PArray {
public:
    void Remove(void *arg0);
    void Add(void *arg0);
    void Allocate(unsigned int arg0);
    char _pad000[0x10];
};
extern PArray mBGAnimList__7Physics;
extern PArray mTempArray__15EntityBaseClass;

class PMeshNode {
public:
    void RemoveFromCollisionArray(PArray *arg0);
    int BuildCollisionArray(PArray *arg0, unsigned int arg1);
};

// BGCollision size is unknown; the placeholder member only keeps mBGCollision__15EntityBaseClass a complete object.
class BGCollision {
public:
    int CheckCeiling(float (*arg0)[4]);
    int CheckIntersect(float (&arg0)[4], float (&arg1)[4], float (*arg2)[4], unsigned int arg3);
    char _pad000[0x10];
};
extern BGCollision mBGCollision__15EntityBaseClass;

class Physics {
public:
    void RunPhysics(EntityBaseClass *arg0, float arg1, int arg2, BGCollision *arg3);
    void AddBGAnimNode(PMeshNode *arg0);
    void SetVelocity(float arg0, float arg1);
    void SetPhysicsType(unsigned int arg0, float (*arg1)[4]);
};

class PMNode {
public:
    virtual void VirtSlot0(int arg0);
    virtual void VirtSlot1();
    virtual void VirtSlot2();
    virtual void VirtSlot3();
    virtual void VirtSlot4(float arg0, float arg1, void *arg2, int arg3, bool arg4);
    virtual void VirtSlot5(AnimData *arg0);
    virtual int VirtSlot6(void *arg0);
    PMNode *FindAnimNode(unsigned int arg0);
    void EnableOneRenderPassOnly(int arg0);
    void DestroyFxTriggersBySpawnFrame(float arg0, bool arg1);
    float GetFrameTime();
    int m_unk4;
    char _pad08[0xC];
    int m_unk14;
    int m_unk18;
    PMNode **m_unk1C;
    char _pad20[0x8];
    float (*m_unk28)[2][4];
    char _pad2C[0x10];
    unsigned char m_3C;
    char _pad3D[0x1];
    unsigned char m_3E;
    signed char m_3F;
    float m_unk40[4][4];
    char _pad80[0xD0];
    int m_unk150;
    int m_unk154;
    PMNode **m_unk158;
};
// gEng is a pointer; the placeholder pads it past the small-data threshold so the load is absolute.
struct PMNodeHolder {
    PMNode *ptr;
    char _pad004[0x1E4];
    float m_unk1E8;
};
extern PMNodeHolder gEng;

int NormalizedBox(float (*arg0)[2][4], float (&arg1)[2][4], float (*arg2)[4][4], float (&arg3)[4][4]);
int BoxBoxCheck(float (*arg0)[2][4], float (*arg1)[2][4], float (*arg2)[4][4], float (*arg3)[4][4]);

// mLoadTable entries are 12 bytes; the array extent is unknown, the declared extent only keeps the table a complete object.
struct LoadEntry {
    int m0;
    unsigned int m4;
    int m8;
};
extern LoadEntry mLoadTable__15EntityBaseClass[6];

// PResourceManager size is unknown; only the call through mpResMgr__15EntityBaseClass is needed.
class PResourceManager {
public:
    int GetResource(unsigned int arg0, bool arg1);
    int GetResType(unsigned int arg0);
    char _pad000[0x10];
};
extern PResourceManager *mpResMgr__15EntityBaseClass;

// EntityAttackManager size is unknown; the pointer global, the RequestAttack call and the m_unk505C pointer are needed.
class EntityAttackManager {
public:
    void RequestAttack(EntityBaseClass *arg0, float arg1, unsigned int arg2, EntityBaseClass *arg3);
    char _pad000[0x505C];
    EntityBaseClass *m_unk505C;
    char _pad5060[0x14];
    float m_unk5074;
    char _pad5078[0x38];
    unsigned int m_unk50B0;
    unsigned int m_unk50B4;
    void **m_unk50B8;
};
extern EntityAttackManager *mpEntMgr__15EntityBaseClass;
extern PFrustrum *mpFrustum__15EntityBaseClass;

class TriggerSystemWakeKillRec;

// EntityManager size is unknown; only FindTrigger is needed, reached through a cast of mpEntMgr.
class EntityManager {
public:
    void *FindTrigger(unsigned int arg0, int arg1);
    void *Spawn(unsigned int arg0, bool arg1, int arg2);
    void *GetPtrToApparition(unsigned int arg0);
    void RemoveFromRenderList(EntityBaseClass *arg0);
    void AddToRenderList(EntityBaseClass *arg0);
};

// Pickup is the spawned object; only the members SpawnBonus writes or reads are placed.
class Pickup {
public:
    void SetAbilityType(int arg0);
    void SetBonusVelocity(float (*arg0)[4], float *arg1, float arg2);
    char _pad000[0x3C];
    char *m_unk3C;
    char _pad040[0x150];
    float m_unk190[4];
    char _pad1A0[0x10];
    int m_unk1B0;
    char _pad1B4[0x1C];
    float m_unk1D0[4];
    int m_unk1E0;
};

// Player is reached through the m_unk505C pointer of mpEntMgr; only the three calls SpawnBonus makes are declared.
class Player {
public:
    int OnGunDeck();
    int GetAbility();
    int GetComboLevel();
};

// One entry per bonus gem kind: a count and a value, 8 bytes each.
struct BonusGemEntry {
    int count;
    int value;
};
extern BonusGemEntry BonusGems[3];
extern int aiSoulStonePickups[4];
extern int miAbilityCount__15EntityBaseClass;

// TimerAPI is only needed for the apparition-timer kill call; its size is not recovered, so the placeholder keeps the global complete.
class TimerAPI {
public:
    void KillAllApparitionTimers(unsigned int arg0, bool arg1);
    char _pad00[0x28];
};
extern TimerAPI mTimerAPI__13EntityManager;
extern CameraAPI mCameraAPI__13EntityManager;

// DrawObj is the base of the object stored at m_unk3C; only its virtual destructor is called.
class DrawObj {
public:
    virtual ~DrawObj();
};

// TriggerSystem is 0x50 bytes; only the constructor and the m_unk9 state byte are needed.
class TriggerSystem {
public:
    TriggerSystem(int arg0, float (*arg1)[4], unsigned int arg2, short arg3, bool arg4, short arg5, float arg6, bool arg7, unsigned int arg8, unsigned int arg9, TriggerSystemWakeKillRec *arg10);
    char _pad000[0x9];
    signed char m_unk9;
    char _pad00A[0x46];
};

namespace Vu0Legacy {
extern "C" void sceVu0ScaleVector(float *pDst);
}
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" float sqrtf(float x);
extern "C" void sceVu0ApplyMatrix(float *dst, float (*m)[4], float *src);
extern "C" void sceVu0AddVector(float *pDst, float *pSrc0, float *pSrc1);
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern float mHitPos__15EntityBaseClass[4];
extern "C" unsigned char PlayingCutCamera__6CameraFv(void *pCam);
extern "C" void GetForwardVector__6CameraFRA4_f(void *pCam, float *pOut);
extern float mfSleepDistance__15EntityBaseClass;
extern float BEHIND_WAKE;
extern float BEHIND_SLEEP;
extern unsigned char mbGlobalSleep__15EntityBaseClass;
extern "C" float atan2f(float y, float x);
extern "C" float FastMath_Fabs__Ff(float fVal);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern unsigned int guHitMarkFxID[7][7];
extern char gClockworkHitSpark[96];
struct tagParticleSparksParams { char _pad000[0x60]; };
class PParticleSparks : public PParticleSystem {
public:
    PParticleSparks();
    void Create(tagParticleSparksParams *arg0, float arg1, float arg2, float arg3);
};
#define CDS_ASSERT(line, cond, msg) ((cond) ? (void)0 : CdsAssert__FPciPc("EntityBaseClass.cpp", line, msg))
// TODO(header): foreign declarations
// Vtable view for the sequence default case: slot 0x18 is virtual #4 (slot 0x08 is the destructor).
class SeqSlotView {
public:
    virtual ~SeqSlotView();
    virtual void SeqSlot1();
    virtual void SeqSlot2();
    virtual void SeqSlot3();
    virtual char *SeqSlot4();
};

// Render-path views: the light manager, the PGfxEngine methods it calls, the ambient table, Shadow and the m_unk3C draw object.
class PMat4;
struct tagComputedLightCache;
class PLightManager {
public:
    void ComputeLights(float *pOut, bool bA, bool bB, bool bC, tagComputedLightCache *pCache, float (*pMatrix)[4], float fScale);
};
class PGfxEngine {
public:
    void SetOverrideTexture(int nIndex);
    void SetAmbientLight(float *pVec);
    void UpdateLights();
    void UpdateLights(PMat4 *pDirMat, PMat4 *pColorMat, float (*pAmbient)[4]);
};
extern float aAmb_642[4];
class Shadow {
public:
    ~Shadow();
    int Render(EntityBaseClass *arg0);
};
class RenderView {
public:
    virtual ~RenderView();
    virtual int Draw(int, int, unsigned char);
};
extern "C" int sprintf(char *, const char *, ...);
extern "C" int printf(const char *fmt, ...);

// PParticleSystem fields used by ChangeDamageFxInterval; the shared class header has no fields at these offsets.
class PParticleSystemView {
public:
    char _pad000[0xC];
    int m_unkC;
    char _pad010[0xD0];
    EntityBaseClass *m_unkE0;
    char _padE4[0x4];
    float m_unkE8;
};

// Vptr view used to call the object's virtual name getter at slot 0x18.
class EntityBaseClassVirtuals {
public:
    virtual ~EntityBaseClassVirtuals();
    virtual int GetTallyType();
    virtual void Slot2();
    virtual void Slot3();
    virtual const char *GetName();
    virtual void Slot5();
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Slot9();
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
    virtual int Slot20(EntityBaseClass *arg0, unsigned short a, unsigned short b);
    virtual void Slot21(EntityBaseClass *arg0, int n);
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
    virtual void Slot26(EntityBaseClass *arg0);
    virtual void OnSleepEvent();
    virtual void OnWakeEvent();
};

float Round180(float arg0);

// DRAFT: 0x0014A380 SetupInnocentCamera__15EntityBaseClassFv
// note: 171 words differ (size 0x3a0 vs 0x3c0); walk head reloads mpEntMgr, spAC zero is sh $zero not lh @1474, sp80/sp74 slots and s2 pointer differ; while-loop shape tried, no drop.
void EntityBaseClass::SetupInnocentCamera() {
    struct EntWalk {
        unsigned int count;
        unsigned int idx;
        void **data;
    };
    static float SCAN_RAD2;
    static signed char init;
    float sp60[4];
    float sp70[4];
    float sp80[4];
    float sp90[4];
    unsigned char spAC[2];
    EntityBaseClass *pEnt;
    EntityBaseClass *pNode;
    EntWalk *pWalk;
    float fDot0;
    float fDot1;
    float fSide;
    float fTmp;
    float fCam;
    int nType;
    int nIdx;
    unsigned int nNext;

    mCameraAPI__13EntityManager.TakeControlOfCamera(this, false);
    if (init == 0) {
        SCAN_RAD2 = 40.0f;
        init = 1;
    }
    pEnt = mpEntMgr__15EntityBaseClass->m_unk505C;
    *(u_long128 *)sp80 = *(u_long128 *)(pEnt->m_unk3C ? pEnt->m_unk3C + 0x80 : (char *)pEnt + 0x190);
    sceVu0AddVector(sp60, sp80, (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190));
    sceVu0ScaleVector(sp60, sp60, 0.5f);
    sceVu0SubVector(sp70, sp80, (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190));
    *(int *)&sp70[1] = 0;
    sceVu0Normalize(sp70, sp70);
    sceVu0SubVector(sp80, sp80, sp60);
    fDot0 = sceVu0InnerProduct(sp80, sp80);
    mpEntMgr__15EntityBaseClass->m_unk50B4 = 0;
    pWalk = (EntWalk *)&mpEntMgr__15EntityBaseClass->m_unk50B0;
    *(short *)spAC = 0;
    pNode = (pWalk->count != 0) ? (EntityBaseClass *)pWalk->data[0] : 0;
    if (pNode != 0) {
        do {
            nType = pNode->m_unk10;
            if ((nType != 3) && (nType != 6)) {
            } else if (pNode != this) {
                float *pNodePos = (float *)(pNode->m_unk3C ? pNode->m_unk3C + 0x80 : (char *)pNode + 0x190);
                sceVu0SubVector(sp80, pNodePos, sp60);
                fDot1 = sceVu0InnerProduct(sp80, sp80);
                if (!(fDot1 <= fDot0) && (fDot1 < SCAN_RAD2) && !(sceVu0InnerProduct(sp70, sp80) <= 0.0f)) {
                    fTmp = sp80[0];
                    sp80[0] = -sp80[2];
                    sp80[2] = fTmp;
                    if (sceVu0InnerProduct(sp80, sp70) <= 0.0f) {
                        spAC[1] = 1;
                    } else {
                        spAC[0] = 1;
                    }
                }
            }
            nNext = pWalk->idx + 1;
            pWalk->idx = nNext;
            pNode = (nNext < pWalk->count) ? (EntityBaseClass *)pWalk->data[nNext] : 0;
        } while (pNode != 0);
    }
    sp60[1] += 3.0f;
    sceVu0ScaleVector(sp70, sp70, 4.0f);
    *(int *)&sp70[1] = 0x40800000;
    if (spAC[0] != spAC[1]) {
        if (spAC[0] != 0) {
            fSide = -60.0f;
        } else {
            fSide = 60.0f;
        }
    } else {
        fCam = *(float *)((char *)mCameraAPI__13EntityManager.m_unk0 + 0x24);
        if ((fCam - (57.295776f * atan2f(sp70[0], sp70[2]))) < 0.0f) {
            fSide = -60.0f;
        } else {
            fSide = 60.0f;
        }
    }
    *(u_long128 *)sp90 = *(u_long128 *)sp70;
    MathAPI::VectorRotateY((float (*)[4])sp70, fSide);
    sceVu0AddVector(sp70, (float *)(pEnt->m_unk3C ? pEnt->m_unk3C + 0x80 : (char *)pEnt + 0x190), sp70);
    if (mBGCollision__15EntityBaseClass.CheckIntersect(sp60, sp70, 0, 2) != 0) {
        MathAPI::VectorRotateY((float (*)[4])sp90, -fSide);
        sceVu0AddVector(sp70, (float *)(pEnt->m_unk3C ? pEnt->m_unk3C + 0x80 : (char *)pEnt + 0x190), sp90);
    }
    mCameraAPI__13EntityManager.SetCameraLookAtParams(this, sp70, sp60);
}

// FUNCTION: 0x0014A740 ProcessPhysics__15EntityBaseClassFfi
void EntityBaseClass::ProcessPhysics(float arg0, int arg1) {
    if (this->m_unk38 != 0) {
        this->m_unk38->RunPhysics(this, arg0, arg1 & this->m_unkE8, &mBGCollision__15EntityBaseClass);
        this->CheckDie(0);
    }
}

// FUNCTION: 0x0014A790 CheckDie__15EntityBaseClassFb
int EntityBaseClass::CheckDie(bool arg0) {
    char *phys;
    char *view;
    char *q;
    float f1;
    unsigned int flags;

    phys = (char *)this->m_unk38;
    if (phys == 0) {
        goto done;
    }
    if ((*(unsigned short *)(phys + 0x106) & 2) == 0) {
        goto done;
    }
    if (this->m_unk10 != 3) {
        goto done;
    }
    view = phys + 0xA0;
    if (arg0 && *(int *)(view + 0x20) == 0 && *(float *)(phys + 4) < 0.0f) {
        goto die;
    }
    if (this->m_unk3C != 0) {
        q = this->m_unk3C + 0x80;
    } else {
        q = (char *)this + 0x190;
    }
    f1 = *(float *)(q + 4);
    if (f1 <= mpEntMgr__15EntityBaseClass->m_unk5074) {
        goto die;
    }
    flags = *(unsigned int *)(view + 0x48);
    if (flags & 4) {
        if (*(unsigned int *)(phys + 0x108) & 1) {
            goto die;
        }
    }
    if (flags & 0x10000) {
        if (*(float *)(view + 0x24) > f1) {
            goto die;
        }
    }
    goto done;
die:
    WriteApparitionData(1, -3, 0);
    WriteApparitionData(0, 1, 0);
    SetState(-2);
    printf("%s hits death surface\n", ((EntityBaseClassVirtuals *)this)->GetName());
    return 1;
done:
    return 0;
}

// FUNCTION: 0x0014A970 DestroyDamageFx__15EntityBaseClassFUi
void EntityBaseClass::DestroyDamageFx(unsigned int arg0) {
    if (arg0 != 0) {
        ((PParticleManager *)(gGfxEng + 0x154F00))->Remove((PParticleSystem *)arg0);
    }
}

// FUNCTION: 0x0014A9A0 ChangeDamageFxInterval__15EntityBaseClassFUif
int EntityBaseClass::ChangeDamageFxInterval(unsigned int arg0, float arg1) {
    int ret;

    if (arg0 != 0) {
        ret = ((PParticleManager *)(gGfxEng + 0x154F00))->IsValid((PParticleSystem *)arg0);
        if (ret != 0) {
            if (((PParticleSystemView *)arg0)->m_unkE0 != this) {
                ret = printf("\nEntity %s is not owner of Fx 0x%X", ((EntityBaseClassVirtuals *)this)->GetName(), arg0);
            }
            if (((PParticleSystemView *)arg0)->m_unkC == 0x1A) {
                ((PParticleSystemView *)arg0)->m_unkE8 = arg1;
                goto block_6;
            }
        }
    } else {
block_6:
        ret = 1;
    }
    return ret;
}

// DRAFT: 0x0014A8F0 OnInnocentAttack__15EntityBaseClassFP15EntityBaseClassi
// note: 21 differing lines; original keeps a2=3 default in a delay slot and compares m_unk10 against a separate v0 literal, ours reuses a2 and uses branch-form select where original uses movz. Tried: nested if/else with ternary, pre-assigned default, nested plain assignment, if/else-if chain.
void EntityBaseClass::OnInnocentAttack(EntityBaseClass *arg0, int arg1) {
    int hitType;

    this->FreezeCheck(arg0, arg1);
    hitType = 3;
    if (arg0->m_unk10 != 6) {
        if (arg0->m_unk10 == 3) {
            hitType = (arg0->m_unk166 == 0) ? 4 : 2;
        } else {
            hitType = 5;
        }
    }
    this->CreateHitMarkFx(0, (eHitObjectType)hitType, (eHitWeaponType)0, false);
}

// FUNCTION: 0x0014AA40 CreateDamageFx__15EntityBaseClassFfUi
PZinDamageFx *EntityBaseClass::CreateDamageFx(float arg0, unsigned int arg1) {
    PZinDamageFx *pFx;
    unsigned long long flags;

    pFx = new PZinDamageFx();
    if (pFx == 0) {
        CdsAssert__FPciPc("EntityBaseClass.cpp", 0xAFD, "apFx");
    }
    flags = arg1 ? (unsigned long long)arg1 : (((unsigned long long)0x8300 << 16) | 0x206);
    pFx->Create(this, arg0, (unsigned int)flags);
    ((PParticleManager *)(gGfxEng + 0x154F00))->Add((PParticleSystem *)pFx);
    ((PParticleSystem *)pFx)->Start();
    return pFx;
}

// DRAFT: 0x0014AB30 CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb
// note: else-arm table index one word short (b +0xA vs +0xB), table base reg v0 vs v1, temp reg swapped; 109 words over 8 variants (guHitMarkFxID[arg2][arg1], byte offset, row cast, flat &[arg2][0])
void EntityBaseClass::CreateHitMarkFx(float (*arg0)[4], eHitObjectType arg1, eHitWeaponType arg2, bool arg3) {
    PParticleManager *pMgr;
    PParticleSystem *pFx;
    PParticleSparks *pSparks;
    tagParticleSparksParams params;
    unsigned int fxId;

    pMgr = (PParticleManager *)((char *)&gGfxEng + 0x154F00);
    CDS_ASSERT(0xAD6, pMgr != 0, "apParticleMgr");
    if (arg3) {
        fxId = 0x830001B9;
    } else {
        fxId = ((unsigned int *)&guHitMarkFxID[arg2][0])[arg1];
    }
    pFx = pMgr->Create(fxId, mHitPos__15EntityBaseClass[0], mHitPos__15EntityBaseClass[1], mHitPos__15EntityBaseClass[2], 0, true);
    if (pFx != 0 && pMgr->IsValid(pFx)) {
        pFx->Start();
    }
    if (pFx != 0 && pMgr->IsValid(pFx)) {
        pFx->FadeAndDie(0);
    }
    if (arg1 == 2 && !arg3) {
        memcpy(&params, gClockworkHitSpark, 0x60);
        *(u_long128 *)((char *)&params + 0x10) = (u_long128)((unsigned long long)0x3F800000 << 32);
        if (arg2 == 2 || arg2 == 3) {
            *(unsigned int *)((char *)&params + 0x3C) = 0x3F266666;
        }
    }
    pSparks = new PParticleSparks();
    CDS_ASSERT(0xAEF, pSparks != 0, "apSparks");
    pSparks->Create(&params, mHitPos__15EntityBaseClass[0], mHitPos__15EntityBaseClass[1], mHitPos__15EntityBaseClass[2]);
    pMgr->Add((PParticleSystem *)pSparks);
    pSparks->Start();
    pSparks->FadeAndDie(0);
}

// FUNCTION: 0x0014AD50 ShakeScreen__15EntityBaseClassFiiiifi
void EntityBaseClass::ShakeScreen(int arg0, int arg1, int arg2, int arg3, float arg4, int arg5) {
    int frame = (int)((PMNode *)m_unk3C)->GetFrameTime();
    if (m_unk17B == 0) {
        if (arg0 != 0 && frame == arg0) {
            m_unk17C = arg0;
            m_unk17B = 1;
            if (arg5 == 0) {
                mCameraAPI__13EntityManager.ShakeScreen(0.0f, arg4, 3.0f, 0U);
            } else {
                mCameraAPI__13EntityManager.ShakeScreenUsingTable(0, 0U);
            }
            return;
        }
        if (arg1 != 0 && frame == arg1) {
            m_unk17C = arg1;
            m_unk17B = 1;
            if (arg5 == 0) {
                mCameraAPI__13EntityManager.ShakeScreen(0.0f, arg4, 3.0f, 0U);
            } else {
                mCameraAPI__13EntityManager.ShakeScreenUsingTable(0, 0U);
            }
            return;
        }
        if (arg2 != 0 && frame == arg2) {
            m_unk17C = arg2;
            m_unk17B = 1;
            if (arg5 == 0) {
                mCameraAPI__13EntityManager.ShakeScreen(0.0f, arg4, 3.0f, 0U);
            } else {
                mCameraAPI__13EntityManager.ShakeScreenUsingTable(0, 0U);
            }
            return;
        }
        if (arg3 != 0 && frame == arg3) {
            m_unk17C = arg3;
            m_unk17B = 1;
            if (arg5 == 0) {
                mCameraAPI__13EntityManager.ShakeScreen(0.0f, arg4, 3.0f, 0U);
            } else {
                mCameraAPI__13EntityManager.ShakeScreenUsingTable(0, 0U);
            }
            return;
        }
    } else if (frame != m_unk17C) {
        m_unk17B = 0;
    }
}

// DRAFT: 0x0014AF60 PlaySoundOnFrame__15EntityBaseClassFUiUi
// note: 55 words differ: float value/constant register (orig value f1, const f0), c.le.s operand order and branch sense, subtract-path regs, missing dsll32/dsra32 flag pair, addiu vs daddiu for inRange=1; tried f>=2^31 first (67), g-before-f with f<2^31 (55), (signed char) flag cast (56).
int EntityBaseClass::PlaySoundOnFrame(unsigned int arg0, unsigned int arg1) {
    int ret;
    int inRange;
    int frame;
    float g;
    float f;
    char *p;

    inRange = 0;
    p = m_unk3C;
    ret = 0;
    if (p != 0) {
        f = *(float *)(p + 0x34);
        if (f < 2147483648.0f) {
            frame = (int)f;
        } else {
            frame = (int)(f - 2147483648.0f) | 0x80000000;
        }
        if (frame != m_unk138) {
            m_unk138 = 0xF423F;
            if (frame == (int)arg1) {
                inRange = 1;
            } else {
                p = m_unk3C;
                g = *(float *)(p + 0x38);
                if (*(signed char *)(p + 0x3F) & 4) {
                    g = -1000000.0f;
                }
                if (arg1 < (unsigned int)frame) {
                    if ((int)arg1 >= 0) {
                        f = (float)(int)arg1;
                    } else {
                        f = 2.0f * (float)((arg1 >> 1) | (arg1 & 1));
                    }
                    if (g < f) {
                        inRange = 1;
                    }
                }
            }
            if (inRange) {
                m_unk138 = frame;
                ret = PlaySound(arg0);
            }
        }
    }
    return ret;
}

// FUNCTION: 0x0014B080 FlashTexture__15EntityBaseClassFUii
void EntityBaseClass::FlashTexture(unsigned int arg0, int arg1) {
    if (arg0 == 0) {
        CdsAssert__FPciPc("EntityBaseClass.cpp", 0xA16, "iTextureID");
    }
    this->m_unk30 = mpResMgr__15EntityBaseClass->GetResource(arg0, false);
    this->m_unk34 = arg1;
}

// FUNCTION: 0x0014B0F0 CheckVariable__15EntityBaseClassFii
void EntityBaseClass::CheckVariable(int arg0, int arg1) {
    char buf[0x100];
    int id;

    if ((unsigned int)arg0 >= (unsigned int)arg1) {
        id = this->m_unk08;
        sprintf(buf, "Invalid variable in %d %s. value %d < %d", id, ((EntityBaseClassVirtuals *)this)->GetName(), arg0, arg1);
        CdsAssert__FPciPc("EntityBaseClass.cpp", 0xA0C, buf);
    }
}

// DRAFT: 0x0014B170 ProcessHitBack__15EntityBaseClassFv
// note: original builds 0.05f inline (lui/ori/mtc1); mwcc pools it via gp (lwc1), shifting the body by one word.
int EntityBaseClass::ProcessHitBack() {
    float temp;
    int ret;

    temp = this->m_unkDC - 0.05f * *(float *)((char *)&gEng + 0x1E8);
    this->m_unkDC = temp;
    if (temp < 0.0f) {
        this->m_unkDC = 0.0f;
    } else {
        Physics *phys = this->m_unk38;
        if (phys != 0) {
            phys->SetVelocity(this->m_unkD8, temp);
        }
    }
    ret = 1;
    if (this->m_unkDC <= 0.0f) {
        ret = 0;
    }
    return ret;
}

// FUNCTION: 0x0014B210 TriggerBGAnim__15EntityBaseClassFUiibUiP24TriggerSystemWakeKillRec
void EntityBaseClass::TriggerBGAnim(unsigned int arg0, int arg1, bool arg2, unsigned int arg3, TriggerSystemWakeKillRec *arg4) {
    TriggerSystem *pTrig;

    pTrig = (TriggerSystem *)((EntityManager *)mpEntMgr__15EntityBaseClass)->FindTrigger(arg0, arg1);
    if (pTrig != 0) {
        if (pTrig->m_unk9 == 0) {
            pTrig->m_unk9 = 2;
        }
    } else if (arg0 != 0 || arg1 >= 0) {
        pTrig = new TriggerSystem(m_unk04, (float (*)[4])((m_unk3C != 0) ? (m_unk3C + 0x80) : ((char *)this + 0x190)), arg0, 0, true, (short)arg1, 0.0f, arg2, arg3, 0, arg4);
        if (pTrig->m_unk9 == 0) {
            pTrig->m_unk9 = 2;
        }
        ((PArray *)((char *)mpEntMgr__15EntityBaseClass + 0x5B60))->Add(pTrig);
    }
}

// FUNCTION: 0x0014B330 IsBGAnimating__15EntityBaseClassFUi
long long EntityBaseClass::IsBGAnimating(unsigned int arg0) {
    PMNode *node = gEng.ptr->FindAnimNode(arg0);

    if (node != 0) {
        return (signed char)(node->m_3F & 7);
    }
    return 0;
}

// DRAFT: 0x0014B370 AddToLoad__15EntityBaseClassFv
// note: 2 differing lines; the idx==5 beq targets the shared addiu v0,1 return with a nop delay slot, ours targets jr with addiu in the slot; tried early returns (worse), ret variable (worse), inline index (same 2).
int EntityBaseClass::AddToLoad() {
    if (this->m_unk18 != 0) {
        if (this->m_unk10 != 5) {
            LoadEntry *e = &mLoadTable__15EntityBaseClass[this->m_unk10];
            if (e->m4 < (unsigned int)(e->m0 + this->m_unk14)) {
                return 0;
            }
        }
        return 1;
    }
    return 1;
}

// FUNCTION: 0x0014B3E0 RestoreOnWake__15EntityBaseClassFv
void EntityBaseClass::RestoreOnWake() {
    char *blk;
    char *sub;

    this->m_unk163 = 0;
    this->m_unk24 = -2;
    if (this->m_unk1F == 0) {
        SetState(-1);
        this->m_unk163 = 0;
    } else {
        LoadMesh(this->m_unk28, 0, 1);
        blk = this->m_unkD4;
        if (blk != 0) {
            *blk = 1;
            sub = *(char **)(blk + 0xC);
            if (sub != 0) {
                sub[0x18] = 1;
            }
        }
        ResumeAmbientSoundsByObject();
        SetState(this->m_unk2C);
        this->m_unk163 = 0;
    }
    ((EntityBaseClassVirtuals *)this)->OnWakeEvent();
}

// DRAFT: 0x0014B490 WantsToWake__15EntityBaseClassFv
// note: 64 words; original shares one epilogue (v0=0 on the early path) and keeps the this+0x190 pointer uncached; the mula.s/madd.s dot product is not expressible in C++. Tried: if/else result variable (73), early return (64, kept)
int EntityBaseClass::WantsToWake() {
    float sp50[4];
    float sp60[4];
    float sp70[4];
    float f20;
    float range;
    char *cam;
    char *objPos;
    EntityBaseClass *obj;

    if (this->m_unk1A == 0) {
        return 0;
    }
    obj = mpEntMgr__15EntityBaseClass->m_unk505C;
    objPos = obj->m_unk3C ? obj->m_unk3C + 0x80 : (char *)obj + 0x190;
    cam = (char *)&gEng + 0x19760;
    if (PlayingCutCamera__6CameraFv(cam)) {
        sceVu0SubVector(sp50, (float *)cam,
                        (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190));
    } else {
        sceVu0SubVector(sp50, (float *)objPos,
                        (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190));
    }
    f20 = sceVu0InnerProduct(sp50, sp50);
    GetForwardVector__6CameraFRA4_f(cam, sp70);
    sceVu0SubVector(sp60, (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190),
                    (float *)cam);
    range = mfSleepDistance__15EntityBaseClass;
    if (sp70[0] * sp60[0] + sp70[2] * sp60[2] < 0.0f) {
        range = BEHIND_WAKE;
    }
    return f20 < range ? 1 : 0;
}

// DRAFT: 0x0014B5E0 CheckSleep__15EntityBaseClassFb
// note: DIFF 125 words; the mula.s/madd.s dot product of sp+0x80/sp+0x90 has no C form, and the if-body is 3 instructions short; cam/mpEntMgr load order also differs.
int EntityBaseClass::CheckSleep(bool arg0) {
    float sp70[4];
    float sp80[4];
    float sp90[4];
    float f20;
    float range;
    char *cam;
    char *objPos;
    EntityBaseClass *obj;
    int s0;

    s0 = 0;
    if (mbGlobalSleep__15EntityBaseClass) {
        cam = (char *)&gEng + 0x19760;
        obj = mpEntMgr__15EntityBaseClass->m_unk505C;
        objPos = obj->m_unk3C ? obj->m_unk3C + 0x80 : (char *)obj + 0x190;
        if (PlayingCutCamera__6CameraFv(cam)) {
            sceVu0SubVector(sp70, (float *)cam,
                            (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190));
        } else {
            sceVu0SubVector(sp70, (float *)objPos,
                            (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190));
        }
        f20 = sceVu0InnerProduct(sp70, sp70);
        GetForwardVector__6CameraFRA4_f(cam, sp90);
        sceVu0SubVector(sp80, (float *)(this->m_unk3C ? this->m_unk3C + 0x80 : (char *)this + 0x190),
                        (float *)cam);
        range = mfSleepDistance__15EntityBaseClass;
        if (sp90[0] * sp80[0] + sp90[2] * sp80[2] < 0.0f) {
            range = BEHIND_SLEEP;
        }
        if (f20 > range) {
            s0 = 1;
        }
    }

    if (!(s0 || arg0)) {
        return 0;
    }

    SetFreeze(0.0f);
    if (this->m_unk18 == 0 || *(unsigned char *)((char *)this + 0x1D) != 0) {
        ((EntityBaseClassVirtuals *)this)->OnSleepEvent();
        SetState(-3);
        return 1;
    }
    if (CheckDie(true)) {
        return 1;
    }
    if (this->m_unk1F) {
        this->m_unk2C = this->m_unk20;
        this->m_unk20 = -1;
        if (this->m_unk3C) {
            *(u_long128 *)((char *)this + 0x190) = *(u_long128 *)(this->m_unk3C + 0x80);
            *(float *)((char *)this + 0x1A4) = *(float *)(this->m_unk3C + 0x94);
        }
    }
    *(unsigned char *)((char *)this + 0x1E) = 0;
    *(unsigned char *)((char *)this + 0x1C) = 1;
    ((EntityBaseClassVirtuals *)this)->OnSleepEvent();
    this->m_unk13C = 0;
    FreeActiveLoad();
    this->m_unk140 = 0;
    LoadMesh(0, false, true);
    if (this->m_unkD4) {
        *this->m_unkD4 = 0;
        {
            char *p = *(char **)(this->m_unkD4 + 0xC);
            if (p) {
                p[0x18] = 0;
            }
        }
    }
    if (this->m_unk1F) {
        PauseAmbientSoundsByObject();
    } else {
        StopAmbientSoundsByObject();
    }
    RemoveFromAttackSystem();
    return 0;
}

// FUNCTION: 0x0014B880 UpdateSulphurFx__15EntityBaseClassFf
void EntityBaseClass::UpdateSulphurFx(float arg0) {
    float pos[4];
    float (*src)[4];

    if (this->m_unk3C != 0) {
        src = (float (*)[4])(this->m_unk3C + 0x80);
    } else {
        src = (float (*)[4])((char *)this + 0x190);
    }
    *(u_long128 *)pos = *(u_long128 *)src;
    pos[1] = arg0;
    ((PParticleManager *)(gGfxEng + 0x154F00))->CreateSulphurReaction(pos, 1.0f);
}

// DRAFT: 0x0014B8D0 UpdateRipple__15EntityBaseClassFfUib
// note: 106 words differ (re-measured; 105 earlier); original keeps gGfxEng in s0 across calls, ours rematerializes lui/addiu per call; copy reg v1 vs a0. Tried: gfx local (117), u_long128 posq temp (kept), gfx before sq (106), reload global per use (131).
void EntityBaseClass::UpdateRipple(float arg0, unsigned int arg1, bool arg2) {
    float pos[4];
    float v[4];
    float r;
    PParticleSystem *p;
    float (*src)[4];
    char *gfx;

    if (this->m_unk3C != 0) {
        src = (float (*)[4])(this->m_unk3C + 0x80);
    } else {
        src = (float (*)[4])((char *)this + 0x190);
    }
    u_long128 posq = *(u_long128 *)src;
    *(u_long128 *)pos = posq;
    gfx = gGfxEng;
    pos[1] = arg0;
    r = MathAPI::RandomFloatRange(120.0f, 150.0f);
    ((PParticleRipples *)(gfx + 0x1790))->Create(pos, 1.0f, 12.0f, r);
    ((PParticleRipples *)(gfx + 0xED0))->Create(pos, 1.0f, 12.0f, r);
    if (arg1 != 0) {
        p = ((PParticleManager *)gfx)->Create(0x83000088U, pos[0], pos[1], pos[2], 0, true);
        if (p != 0 && ((PParticleManager *)gfx)->IsValid(p)) {
            p->Start();
        }
        if (p != 0 && ((PParticleManager *)gfx)->IsValid(p)) {
            p->FadeAndDie(0);
        }
        v[0] = pos[0] + MathAPI::RandomFloatRange(-3.0f, 3.0f);
        v[1] = pos[1];
        v[2] = pos[2] + MathAPI::RandomFloatRange(-3.0f, 3.0f);
        r = MathAPI::RandomFloatRange(60.0f, 90.0f);
        ((PParticleRipples *)(gfx + 0x1790))->Create(v, 0.5f, 8.0f, r);
        ((PParticleRipples *)(gfx + 0xED0))->Create(v, 0.5f, 8.0f, r);
    }
    if (arg2) {
        ((PParticleManager *)gfx)->CreateEweedReaction(pos);
    }
}

// DRAFT: 0x0014BAE0 CreateSplash__15EntityBaseClassFfbb
// note: 2 words differ (mtc1 f12/f13 order for v[0]); scheduling depends on the preceding UpdateRipple body: with it emptied, v[0] = RandomFloatRange(3.0f, -3.0f) + pos[0] matches, so recheck that form once UpdateRipple matches
void EntityBaseClass::CreateSplash(float arg0, bool arg1, bool arg2) {
    float pos[4];
    float v[4];
    float r;
    float (*src)[4];
    PParticleSystem *ps;
    if (this->m_unk3C != 0) {
        src = (float (*)[4])(this->m_unk3C + 0x80);
    } else {
        src = (float (*)[4])((char *)this + 0x190);
    }
    *(u_long128 *)pos = *(u_long128 *)src;
    pos[1] = arg0;
    if (arg1) {
        mEffectAPI__13EntityManager.CreateOneshot(0x8100004D, 0x82000085, (float (*)[4])pos, 0, 0, 0.5f, false, 0, false);
    }
    PlaySound(0x14);
    char *gfx = (char *)&gGfxEng + 0x154F00;
    ps = ((PParticleManager *)gfx)->Create(0x83000141, pos[0], pos[1], pos[2], 0, true);
    if (ps != 0 && ((PParticleManager *)gfx)->IsValid(ps)) {
        ps->Start();
    }
    if (ps != 0 && ((PParticleManager *)gfx)->IsValid(ps)) {
        ps->FadeAndDie(0);
    }
    v[0] = pos[0] + MathAPI::RandomFloatRange(3.0f, -3.0f);
    v[1] = pos[1];
    v[2] = pos[2] + MathAPI::RandomFloatRange(-3.0f, 3.0f);
    r = MathAPI::RandomFloatRange(60.0f, 90.0f);
    ((PParticleRipples *)(gfx + 0x1790))->Create(v, 0.5f, 8.0f, r);
    ((PParticleRipples *)(gfx + 0xED0))->Create(v, 0.5f, 8.0f, r);
    r = MathAPI::RandomFloatRange(60.0f, 90.0f);
    ((PParticleRipples *)(gfx + 0x1790))->Create(v, 0.5f, 8.0f, r);
    ((PParticleRipples *)(gfx + 0xED0))->Create(v, 0.5f, 8.0f, r);
    if (arg2) {
        ((PParticleManager *)gfx)->CreateEweedReaction(pos);
    }
}

// DRAFT: 0x0014BD40 SpawnPickups__15EntityBaseClassFiiPA4_fb
// note: DIFF 173 words; original uses mula.s/madd.s/msub.s for the velocity and a 0xA0 frame, draft emits mul.s/add.s and 0xB0. Variants tried: inlined src local (180), no change in order.
EntityBaseClass *EntityBaseClass::SpawnPickups(int arg0, int arg1, float (*arg2)[4], bool arg3) {
    float local80[4];
    float vel[4];
    float step;
    EntityBaseClass *spawned = 0;
    int i;
    char *src;

    if (arg1 != 0) {
        if (arg2 == 0) {
            MathAPI::GetForwardVector(this, local80);
            local80[1] = 0.4f;
            local80[0] *= 0.1f;
            local80[2] *= 0.1f;
        } else {
            *(u_long128 *)local80 = *(u_long128 *)arg2;
        }
        step = 360.0f / (float)arg1;
        for (i = 0; i < arg1; i++) {
            spawned = (EntityBaseClass *)((EntityManager *)mpEntMgr__15EntityBaseClass)->Spawn(8, false, 0);
            if (spawned != 0) {
                if (arg0 == 0) {
                    PlaySound(0x95);
                }
                *(int *)((char *)spawned + 0x1B0) = arg0;
                src = (m_unk3C != 0) ? (m_unk3C + 0x80) : ((char *)this + 0x190);
                if (spawned->m_unk3C != 0) {
                    *(u_long128 *)(spawned->m_unk3C + 0x80) = *(u_long128 *)src;
                    *(unsigned char *)(spawned->m_unk3C + 0x3E) |= 8;
                } else {
                    *(u_long128 *)((char *)spawned + 0x190) = *(u_long128 *)src;
                }
                vel[0] = local80[2] * sinf(0.017453292f * m_fYAngle__15EntityBaseClass) +
                         local80[0] * cosf(0.017453292f * m_fYAngle__15EntityBaseClass);
                vel[2] = local80[2] * cosf(0.017453292f * m_fYAngle__15EntityBaseClass) -
                         local80[0] * sinf(0.017453292f * m_fYAngle__15EntityBaseClass);
                if (arg3) {
                    vel[1] = local80[1] + MathAPI::RandomFloatRange(0.0f, 0.3f);
                } else {
                    vel[1] = local80[1];
                }
                sceVu0CopyVector((float *)((char *)spawned + 0x1D0), vel);
                if (arg3) {
                    m_fYAngle__15EntityBaseClass += MathAPI::RandomFloatRange(-180.0f, 180.0f) + step;
                } else {
                    m_fYAngle__15EntityBaseClass += step;
                }
                m_fYAngle__15EntityBaseClass = Round180(m_fYAngle__15EntityBaseClass);
            }
        }
    }
    return spawned;
}

// FUNCTION: 0x0014BFA0 FacePlayer__15EntityBaseClassFf
void EntityBaseClass::FacePlayer(float arg0) {
    EntityBaseClass *player = mPlayerAPI__13EntityManager;
    float (*a1)[4];
    float angle;

    if (player->m_unk3C != 0) {
        a1 = (float (*)[4])(player->m_unk3C + 0x80);
    } else {
        a1 = (float (*)[4])((char *)player + 0x190);
    }
    angle = MathAPI::GetAngleYToPoint(this, a1);
    this->RotateTo(angle, arg0);
}

// DRAFT: 0x0014C010 ProcessMeshFade__15EntityBaseClassFv
// note: 9 words differ; original keeps clamp sum in v1 (addu v1,a1,v1) and orders clamp as bgez then slti. Tried: block-scope v, operand swap (worse), short v (worse), separate int temp (same).
void EntityBaseClass::ProcessMeshFade() {
    float temp;

    if (this->m_unk178 != 0) {
        temp = this->m_unk170;
        if (!(temp <= 0.0f)) {
            float dt = gEng.m_unk1E8;
            int v;
            this->m_unk170 = temp - dt;
            this->m_unk174 += this->m_unk16C * dt;
            v = this->m_unk168 + (int)this->m_unk174;
            if (v >= 0x81) {
                v = 0x80;
            } else if (v < 0) {
                v = 0;
            }
            this->m_unkD2 = v;
            return;
        }
        this->m_unk178 = 0;
    }
}

// FUNCTION: 0x0014C0B0 FadeMesh__15EntityBaseClassFssUi
void EntityBaseClass::FadeMesh(short arg0, short arg1, unsigned int arg2) {
    if (this->m_unk178 != 0) {
        return;
    }
    short v = (arg0 == -1) ? this->m_unkD2 : arg0;
    this->m_unk168 = v;
    this->m_unk170 = (float)(arg2 * 60) / 1000.0f;
    this->m_unk16C = (float)(arg1 - this->m_unk168) / this->m_unk170;
    this->m_unk174 = 0.0f;
    this->m_unk178 = 1;
}

// FUNCTION: 0x0014C160 MusicChangePrimary__15EntityBaseClassFUiUi
int EntityBaseClass::MusicChangePrimary(unsigned int arg0, unsigned int arg1) {
    return gSound.PlayMusic(arg0) & 0xFF;
}

// FUNCTION: 0x0014C1B0 ResumeAmbientSoundsByObject__15EntityBaseClassFv
void EntityBaseClass::ResumeAmbientSoundsByObject() {
    gSound.ResumeAmbientSoundsByOriginatorRef(m_unk04, 0x10U);
}

// FUNCTION: 0x0014C1D0 PauseAmbientSoundsByObject__15EntityBaseClassFv
void EntityBaseClass::PauseAmbientSoundsByObject() {
    gSound.PauseAmbientSoundsByOriginatorRef(m_unk04, 0x10U);
}

// FUNCTION: 0x0014C1F0 StopAmbientSoundsByObject__15EntityBaseClassFv
void EntityBaseClass::StopAmbientSoundsByObject() {
    gSound.StopAmbientSoundsByOriginatorRef(m_unk04, 0x10U);
}

// FUNCTION: 0x0014C210 StopAllSoundsByObject__15EntityBaseClassFv
void EntityBaseClass::StopAllSoundsByObject() {
    gSound.StopSoundsByOriginatorRef(m_unk04, 0x10U, 3U);
}

// FUNCTION: 0x0014C240 PlaySoundUbiquitous__15EntityBaseClassFUi
int EntityBaseClass::PlaySoundUbiquitous(unsigned int arg0) {
    return gSound.PlaySoundWPitch(arg0, m_unk04, 0U, 0x210U, 0U);
}

// FUNCTION: 0x0014C260 PlaySound__15EntityBaseClassFUi
int EntityBaseClass::PlaySound(unsigned int arg0) {
    return gSound.PlaySoundWPitch(arg0, m_unk04, 0U, 0x10U, 0U);
}

// DRAFT: 0x0014C280 SpawnBonus__15EntityBaseClassFPfii
// note: DIFF 109; idx lands in s1 (orig s0 shared with loop i), index-selection and second-block branch layout, sceVu0CopyVector reloc None; tried goto post_combo, q/off order, idx order, subtraction in q block, increment order, if/else index (113).
void EntityBaseClass::SpawnBonus(float *arg0, int arg1, int arg2) {
    int ability;
    int i;
    int q;
    int off;
    int cnt;
    int idx;
    BonusGemEntry *gem;
    float fwd[4];
    float vel[4];
    float c;
    float s;
    char *src;

    if (m_unk186 != 0 && ((Player *)mpEntMgr__15EntityBaseClass->m_unk505C)->OnGunDeck() == 0) {
        miAbilityCount__15EntityBaseClass++;
        if (miAbilityCount__15EntityBaseClass >= 4) {
            miAbilityCount__15EntityBaseClass -= 4;
            ability = ((Player *)mpEntMgr__15EntityBaseClass->m_unk505C)->GetAbility();
            if (ability != 0x20) {
                Pickup *spawned = (Pickup *)((EntityManager *)mpEntMgr__15EntityBaseClass)->Spawn(8, false, 0);
                if (spawned == 0) {
                    CdsAssert__FPciPc("EntityBaseClass.cpp", 0x72E, "pBonusEnt");
                }
                spawned->SetAbilityType(ability);
                spawned->SetBonusVelocity((float (*)[4])(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190), arg0, 0.0f);
                goto post_combo;
            }
        }
        if (m_unk187 != 0) {
            arg2 += ((Player *)mpEntMgr__15EntityBaseClass->m_unk505C)->GetComboLevel();
            for (i = 0, off = 0; i < 3 && arg2 > 0; off += 8, i++) {
                gem = (BonusGemEntry *)((char *)BonusGems + off);
                cnt = gem->count;
                q = arg2 / cnt;
                if (q != 0) {
                    SpawnPickups(gem->value, q, 0, false);
                    arg2 -= cnt * q;
                }
            }
        }
post_combo:
        if (!m_unk166) {
            return;
        }
    }
    if (!m_unk188) {
        return;
    }
    if (arg1 == 0) {
        return;
    }
    if (((Player *)mpEntMgr__15EntityBaseClass->m_unk505C)->OnGunDeck() != 0) {
        return;
    }
    idx = (arg1 < 4) ? 0 : ((arg1 < 6) ? 1 : 2);
    MathAPI::GetForwardVector(this, fwd);
    fwd[0] = fwd[0] * 0.1f;
    fwd[1] = 0.4f;
    fwd[2] = fwd[2] * 0.1f;
    {
        Pickup *spawned = (Pickup *)((EntityManager *)mpEntMgr__15EntityBaseClass)->Spawn(8, false, 0);
        if (spawned == 0) {
            return;
        }
        spawned->m_unk1B0 = aiSoulStonePickups[idx];
        src = m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190;
        if (spawned->m_unk3C != 0) {
            *(u_long128 *)(spawned->m_unk3C + 0x80) = *(u_long128 *)src;
            spawned->m_unk3C[0x3E] |= 8;
        } else {
            *(u_long128 *)spawned->m_unk190 = *(u_long128 *)src;
        }
        spawned->m_unk1E0 = arg1;
        c = cosf(0.017453292f * m_fYAngle__15EntityBaseClass);
        s = sinf(0.017453292f * m_fYAngle__15EntityBaseClass);
        vel[0] = fwd[2] * s + fwd[0] * c;
        vel[2] = fwd[2] * c - fwd[0] * s;
        vel[1] = fwd[1] + MathAPI::RandomFloatRange(0.0f, 0.3f);
        sceVu0CopyVector(spawned->m_unk1D0, vel);
    }
}

// DRAFT: 0x0014C620 FaceHitDirection__15EntityBaseClassFP15EntityBaseClass
// note: 15 words differ; 57.295776f is pooled via gp where the original builds it inline (lui/ori/mtc1), the tail store order differs, and m_unk38 is not kept in s0. Tried: cached m_unk38 local (20 words, worse, reverted).
void EntityBaseClass::FaceHitDirection(EntityBaseClass *arg0) {
    float vec[4];
    float (*a1)[4];
    float (*a2)[4];
    float ang;

    if (this->m_unk3C != 0) {
        a2 = (float (*)[4])((char *)arg0 + 0x190);
        if (arg0->m_unk3C != 0) {
            a2 = (float (*)[4])(arg0->m_unk3C + 0x80);
        }
        a1 = (float (*)[4])((char *)this + 0x190);
        if (this->m_unk3C != 0) {
            a1 = (float (*)[4])(this->m_unk3C + 0x80);
        }
        sceVu0SubVector(vec, (float *)a1, (float *)a2);
        ang = Round180(57.295776f * atan2f(vec[0], vec[2]));
        *(float *)(this->m_unk3C + 0x94) = ang;
        *(unsigned char *)(this->m_unk3C + 0x3E) |= 8;
        if (this->m_unk38 != 0) {
            *(float *)((char *)this->m_unk38 + 0x11C) = Round180(ang);
        }
    }
}

// FUNCTION: 0x0014C6D0 GetDistFromPlayer__15EntityBaseClassFv
float EntityBaseClass::GetDistFromPlayer() {
    EntityBaseClass *player = mPlayerAPI__13EntityManager;
    float (*a1)[4];
    float (*a0)[4];

    if (player->m_unk3C != 0) {
        a1 = (float (*)[4])(player->m_unk3C + 0x80);
    } else {
        a1 = (float (*)[4])((char *)player + 0x190);
    }
    if (this->m_unk3C != 0) {
        a0 = (float (*)[4])(this->m_unk3C + 0x80);
    } else {
        a0 = (float (*)[4])((char *)this + 0x190);
    }
    return MathAPI::Distance(a0, a1);
}

// FUNCTION: 0x0014C710 RequestAttack__15EntityBaseClassFP15EntityBaseClassUi
void EntityBaseClass::RequestAttack(EntityBaseClass *arg0, unsigned int arg1) {
    EntityBaseClass *player = mPlayerAPI__13EntityManager;
    float (*playerMtx)[4];
    float (*ownMtx)[4];
    float dist;

    if (player->m_unk3C != 0) {
        playerMtx = (float (*)[4])(player->m_unk3C + 0x80);
    } else {
        playerMtx = (float (*)[4])((char *)player + 0x190);
    }
    ownMtx = (float (*)[4])((char *)this + 0x190);
    if (this->m_unk3C != 0) {
        ownMtx = (float (*)[4])(this->m_unk3C + 0x80);
    }
    dist = MathAPI::Distance(ownMtx, playerMtx);
    mpEntMgr__15EntityBaseClass->RequestAttack(this, dist, arg1, arg0);
}

// FUNCTION: 0x0014C790 SetRenderPass__15EntityBaseClassFi
void EntityBaseClass::SetRenderPass(int arg0) {
    if (this->m_unk3C != 0) {
        ((PMNode *)this->m_unk3C)->EnableOneRenderPassOnly(arg0);
        ((PMNode *)this->m_unk3C)->VirtSlot3();
    }
}

// FUNCTION: 0x0014C7E0 ChangedState__15EntityBaseClassFv
int EntityBaseClass::ChangedState() {
    int cur = this->m_unk20;

    if (cur != this->m_unk24) {
        this->m_unk24 = cur;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0014C800 RotateTo__15EntityBaseClassFff
void EntityBaseClass::RotateTo(float arg0, float arg1) {
    Physics *phys = this->m_unk38;

    if (phys != 0) {
        *(float *)((char *)phys + 0x11C) = Round180(arg0);
        *(float *)((char *)this->m_unk38 + 0x118) = arg1;
    }
}

// DRAFT: 0x0014C850 SkeletonCollision__15EntityBaseClassFP6PMNodePA2_A4_fRA4_A4_fUc
// note: 110 differing lines; prologue frame is -0xF0 (sd ra 0x60) vs original -0x100 (sd ra 0x70), original keeps an int accumulator in s6 with one shared exit (ret-accumulator variant tried: 112, reverted); arg save order and local order differ.
int EntityBaseClass::SkeletonCollision(PMNode *arg0, float (*arg1)[2][4], float (&arg2)[4][4], unsigned char arg3) {
    float local2x4[2][4];
    float local4x4[4][4];
    float e0[4];
    float f0[4];
    float (*box)[2][4];
    float (*mtx)[4][4];
    unsigned int c1;
    unsigned int c2;

    box = arg0->m_unk28;
    if (box == 0) {
        return 0;
    }
    if (arg0->m_3C == 0) {
        return 0;
    }
    if (arg0->m_3E & 4) {
        if (!NormalizedBox(arg0->m_unk28, local2x4, &arg0->m_unk40, local4x4)) {
            return 0;
        }
        box = &local2x4;
        mtx = &local4x4;
    } else {
        mtx = &arg0->m_unk40;
    }
    if (!BoxBoxCheck(arg1, box, &arg2, mtx)) {
        return 0;
    }
    c2 = ((unsigned int)arg0->m_3C | 0x20) & 0xFF;
    c1 = arg3 & 0xFF;
    if (((c2 | c1) & 0x80) != 0 && mHitPos__15EntityBaseClass[0] == 0.0f) {
        sceVu0ApplyMatrix(e0, arg2, (float *)arg1);
        sceVu0ApplyMatrix(f0, arg0->m_unk40, (float *)box);
        if (c1 & 0x80) {
            sceVu0SubVector(f0, f0, e0);
            f0[1] = 0.0f;
            sceVu0Normalize(f0, f0);
            sceVu0ScaleVector(f0, f0, (*arg1)[1][0]);
        } else {
            sceVu0SubVector(e0, e0, f0);
            e0[1] = 0.0f;
            sceVu0Normalize(e0, e0);
            sceVu0ScaleVector(e0, e0, (*box)[1][0]);
        }
        sceVu0AddVector(mHitPos__15EntityBaseClass, e0, f0);
        mHitPos__15EntityBaseClass[3] = 1.0f;
    }
    return (int)((c1 << 16) | c2);
}

// DRAFT: 0x0014CA10 MeshNodeCollision__15EntityBaseClassFP6PMNodePA2_A4_fRA4_A4_fUc
// note: 145 words; frame 0x120 vs original 0x130 (16-byte spill slot at 0xA0 missing); volatile and padding variants tried, no gain.
int EntityBaseClass::MeshNodeCollision(PMNode *arg0, float (*arg1)[2][4], float (&arg2)[4][4], unsigned char arg3) {
    unsigned int c2;
    float local2x4[2][4];
    float local4x4[4][4];
    float e0[4];
    float f0[4];
    float (*box)[2][4];
    float (*mtx)[4][4];
    unsigned char m3C;
    unsigned int c1;
    unsigned int ret;
    PMNode *child;
    unsigned int idx;

    ret = 0;
    switch (arg0->m_unk4) {
    case 1:
        box = arg0->m_unk28;
        m3C = arg0->m_3C;
        if (box != 0 && m3C != 0) {
            mtx = &arg0->m_unk40;
            if (arg0->m_3E & 4) {
                if (!NormalizedBox(arg0->m_unk28, local2x4, &arg0->m_unk40, local4x4)) {
                    return 0;
                }
                box = &local2x4;
                mtx = &local4x4;
            }
            if (BoxBoxCheck(arg1, box, &arg2, mtx)) {
                c2 = ((unsigned int)m3C | 0x20) & 0xFF;
                c1 = arg3 & 0xFF;
                if (((c2 | c1) & 0x80) != 0 && mHitPos__15EntityBaseClass[0] == 0.0f) {
                    sceVu0ApplyMatrix(e0, arg2, (float *)arg1);
                    sceVu0ApplyMatrix(f0, arg0->m_unk40, (float *)box);
                    if (c1 & 0x80) {
                        sceVu0SubVector(f0, f0, e0);
                        f0[1] = 0.0f;
                        sceVu0Normalize(f0, f0);
                        sceVu0ScaleVector(f0, f0, (*arg1)[1][0]);
                    } else {
                        sceVu0SubVector(e0, e0, f0);
                        e0[1] = 0.0f;
                        sceVu0Normalize(e0, e0);
                        sceVu0ScaleVector(e0, e0, (*box)[1][0]);
                    }
                    sceVu0AddVector(mHitPos__15EntityBaseClass, e0, f0);
                    mHitPos__15EntityBaseClass[3] = 1.0f;
                }
                ret |= (c1 << 16) | c2;
            }
        }
        arg0->m_unk18 = 0;
        child = 0;
        if (arg0->m_unk14 != 0) {
            child = arg0->m_unk1C[0];
        }
        if (child != 0) {
            do {
                ret |= MeshNodeCollision(child, arg1, arg2, arg3);
                idx = arg0->m_unk18 + 1;
                arg0->m_unk18 = idx;
                child = 0;
                if (idx < (unsigned int)arg0->m_unk14) {
                    child = arg0->m_unk1C[arg0->m_unk18];
                }
            } while (child != 0);
        }
        break;
    case 2:
        arg0->m_unk154 = 0;
        child = 0;
        if (arg0->m_unk150 != 0) {
            child = arg0->m_unk158[0];
        }
        if (child != 0) {
            do {
                ret |= SkeletonCollision(child, arg1, arg2, arg3);
                idx = arg0->m_unk154 + 1;
                arg0->m_unk154 = idx;
                child = 0;
                if (idx < (unsigned int)arg0->m_unk150) {
                    child = arg0->m_unk158[arg0->m_unk154];
                }
            } while (child != 0);
        }
        break;
    }
    return ret;
}

// DRAFT: 0x0014CD10 SkeletonCollision__15EntityBaseClassFP6PMNodeP15EntityBaseClass
// note: DIFF 39 words; register allocation differs (original ret=s0, flags=s1, arg1=s2), the original ORs the call result into ret, and an andi on the u8 flag|0x20 argument is extra. Tried: ret|= (40), unsigned int flags (no gain), hoisted u8 flag|0x20 (42), early return (40).
int EntityBaseClass::SkeletonCollision(PMNode *arg0, EntityBaseClass *arg1) {
    float local40[2][4];
    float local60[4][4];
    int ret = 0;

    if (arg0->m_unk28 != 0) {
        unsigned char flags = arg0->m_3C;

        if (flags != 0) {
            if (arg0->m_3E & 4) {
                if (NormalizedBox(arg0->m_unk28, local40, &arg0->m_unk40, local60)) {
                    ret = arg1->MeshNodeCollision((PMNode *)arg1->m_unk3C, &local40, local60, flags | 0x20);
                }
            } else {
                ret = arg1->MeshNodeCollision((PMNode *)arg1->m_unk3C, arg0->m_unk28, arg0->m_unk40, flags | 0x20);
            }
        }
    }
    return ret;
}

// PMNode list header: length, walk index, element storage.
struct PMNodeList {
    unsigned int length;
    unsigned int index;
    PMNode **items;
};

// DRAFT: 0x0014CDB0 MeshNodeCollision__15EntityBaseClassFP6PMNodeP15EntityBaseClass
// note: DIFF 107 words; prologue register roles differ (original arg0=s1, arg1=s0, ret=s3; ours arg0=s4, arg1=s3, ret=s1) and the dispatch branch sense is inverted. Tried: ret moved to top (107), key==2 tested first (109), inline dispatch read (107), shared list pointer (107).
int EntityBaseClass::MeshNodeCollision(PMNode *arg0, EntityBaseClass *arg1) {
    int ret = 0;
    PMNodeList *list;
    float local60[2][4];
    float local80[4][4];
    if (*(int *)((char *)arg0 + 0x4) == 1) {
        if (arg0->m_unk28 != 0) {
            unsigned char flags = arg0->m_3C;
            if ((flags & 0xE0) != 0) {
                if (arg0->m_3E & 4) {
                    if (NormalizedBox(arg0->m_unk28, local60, &arg0->m_unk40, local80) == 0) {
                        return 0;
                    }
                    ret |= arg1->MeshNodeCollision((PMNode *)arg1->m_unk3C, &local60, local80, flags | 0x20);
                } else {
                    ret |= arg1->MeshNodeCollision((PMNode *)arg1->m_unk3C, arg0->m_unk28, arg0->m_unk40, flags | 0x20);
                }
            }
        }
        list = (PMNodeList *)((char *)arg0 + 0x14);
        list->index = 0;
        while (list->index < list->length) {
            ret |= MeshNodeCollision(list->items[list->index], arg1);
            list->index++;
        }
    } else if (*(int *)((char *)arg0 + 0x4) == 2) {
        list = (PMNodeList *)((char *)arg0 + 0x150);
        list->index = 0;
        while (list->index < list->length) {
            ret |= SkeletonCollision(list->items[list->index], arg1);
            list->index++;
        }
    }
    return ret;
}

// DRAFT: 0x0014CF80 NormalizedBox__FPA2_A4_fRA2_A4_fPA4_A4_fRA4_A4_f
// note: 41 differing lines; sqrt result lands in f1 not f0 and zero-compare operands are reversed (c.eq.s $f1,$f0 vs $f0,$f1); tried !(d!=0), else-branch restructure (57), block temp, folded sqrt, 1.0f!=d, 0.0f==d, len temp; sqc2 in asm.
#define NORMALIZEDBOX_ROW(I)                                    \
    d = sceVu0InnerProduct(arg2[0][I], arg2[0][I]);             \
    if (d != 1.0f) {                                            \
        if (d == 0.0f) {                                        \
            return 0;                                           \
        }                                                       \
        d = sqrtf(d);                                           \
        arg1[1][I] *= d;                                        \
        sceVu0ScaleVector(arg3[I], arg2[0][I], 1.0f / d);       \
    } else {                                                    \
        *(u_long128 *)arg3[I] = *(u_long128 *)arg2[0][I];       \
    }

int NormalizedBox(float (*arg0)[2][4], float (&arg1)[2][4], float (*arg2)[4][4], float (&arg3)[4][4]) {
    float len;
    float d;
    float *pRow0;

    sceVu0ApplyMatrix(arg3[3], arg2[0], (float *)arg0);
    pRow0 = &arg1[0][0];
    asm {
        sqc2 vf0, 0x0(pRow0)
    }
    *(u_long128 *)arg1[1] = *(u_long128 *)(*arg0)[1];
    NORMALIZEDBOX_ROW(0)
    NORMALIZEDBOX_ROW(1)
    NORMALIZEDBOX_ROW(2)
    return 1;
}

// DRAFT: 0x0014D180 CollisionCheck__15EntityBaseClassFP15EntityBaseClass
// note: 261 words; first beqz at 0x40 keeps a nop delay slot in the original but takes srl in ours; and-order, nesting and a separate mask variable (4 attempts) all stay at 261
void EntityBaseClass::CollisionCheck(EntityBaseClass *arg0) {
    float sp80[4];
    float sp90[4];
    float spA0[4];
    unsigned int a2 = m_unk10C;
    unsigned int a1 = arg0->m_unk10C;
    if ((a2 & a1 & 0x01000000) && ((a2 & ((a1 >> 16) & 0xFF)) || (a1 & ((a2 >> 16) & 0xFF)))) {
        sceVu0SubVector(sp80, (float *)(m_unk3C + 0x80), (float *)(arg0->m_unk3C + 0x80));
        float fy = sp80[1];
        float f20;
        if (fy < 0.0f) {
            f20 = m_unk108;
        } else {
            f20 = arg0->m_unk108;
        }
        if (FastMath_Fabs__Ff(fy) < f20) {
            float f3 = sqrtf(sp80[0] * sp80[0] + sp80[2] * sp80[2]);
            float f1 = (m_unk104 + arg0->m_unk104) - f3;
            if (!(f1 <= 0.0f)) {
                if (!(f1 <= 0.25f)) {
                    f1 = 0.25f;
                }
                if (f3 < 0.001f) {
                    f3 = 0.001f;
                }
                sceVu0ScaleVector(sp80, sp80, f1 / f3);
                ((int *)sp80)[1] = 0;
                unsigned char a0 = m_unk103;
                int v1 = a0 - arg0->m_unk103;
                if (v1 == 0) {
                    if (a0 != 0xFF) {
                        RadiusAdjust(0.5f, &sp80);
                        arg0->RadiusAdjust(-0.5f, &sp80);
                    }
                } else if (v1 < 0) {
                    RadiusAdjust(1.0f, &sp80);
                } else {
                    arg0->RadiusAdjust(-1.0f, &sp80);
                }
            }
        }
    }
    unsigned int b2 = m_unk10C;
    unsigned int b1 = arg0->m_unk10C;
    if ((b2 | b1) & 0x06000000) {
        int s2 = (b2 >> 8) & b1 & 0xFF;
        int s3 = (b1 >> 8) & b2 & 0xFF;
        if (s2 != 0 || s3 != 0) {
            PMNode *n0 = (PMNode *)m_unk3C;
            PMNode *n1 = (PMNode *)arg0->m_unk3C;
            float *s5 = (float *)((char *)n1 + 0x110);
            sceVu0ApplyMatrix(sp90, n0->m_unk40, (float *)((char *)n0 + 0x110));
            sceVu0ApplyMatrix(spA0, n1->m_unk40, s5);
            sceVu0SubVector(sp90, sp90, spA0);
            float d = sqrtf(sceVu0InnerProduct(sp90, sp90));
            if (d < *(float *)((char *)n0 + 0x12C) + *(float *)((char *)n1 + 0x12C)) {
                ((int *)mHitPos__15EntityBaseClass)[0] = 0;
                int v0 = MeshNodeCollision((PMNode *)m_unk3C, arg0);
                if (v0 != 0) {
                    if (v0 & 0x200020) {
                        if (m_unk10C & 0x04000000) {
                            ((EntityBaseClassVirtuals *)this)->Slot26(arg0);
                        }
                        if (arg0->m_unk10C & 0x04000000) {
                            ((EntityBaseClassVirtuals *)arg0)->Slot26(this);
                        }
                    }
                    if (v0 & 0x800080) {
                        int var_v1 = v0 & 0x80;
                        bool done = false;
                        if (v0 & 0x800000) {
                            if (s2 != 0 && m_unkF4 == 0 && (arg0->m_unk10C & 0x02000000) && FindCollision(arg0) == 0) {
                                AddCollision(arg0);
                                int t0 = ((EntityBaseClassVirtuals *)arg0)->Slot20(this, *(unsigned short *)((char *)this + 0x15C), m_unk15E);
                                if (t0 != 0) {
                                    ((EntityBaseClassVirtuals *)this)->Slot21(arg0, t0);
                                }
                                done = true;
                            }
                        }
                        if (!done && var_v1 != 0 && s3 != 0 && arg0->m_unkF4 == 0 && (m_unk10C & 0x02000000) && arg0->FindCollision(this) == 0) {
                            arg0->AddCollision(this);
                            int t1 = ((EntityBaseClassVirtuals *)this)->Slot20(arg0, *(unsigned short *)((char *)arg0 + 0x15C), arg0->m_unk15E);
                            if (t1 != 0) {
                                ((EntityBaseClassVirtuals *)arg0)->Slot21(this, t1);
                            }
                        }
                    }
                }
            }
        }
    }
}

// FUNCTION: 0x0014D620 RadiusAdjust__15EntityBaseClassFfPA4_f
void EntityBaseClass::RadiusAdjust(float arg0, float (*arg1)[4]) {
    float v[4];
    unsigned char *p;

    Vu0Legacy::sceVu0ScaleVector(v);
    v[3] = 0.0f;
    sceVu0AddVector(v, v, (float *)(this->m_unk3C + 0x80));
    p = (unsigned char *)this->m_unk3C;
    *(u_long128 *)(p + 0x80) = *(u_long128 *)v;
    p[0x3E] |= 8;
    this->m_unkD0 = 0;
}

// DRAFT: 0x0014D6D0 AddCollision__15EntityBaseClassFP15EntityBaseClass
// note: loop shape and store addressing differ (34 words); tried explicit this+0x110 base and post-loop store (35 words)
void EntityBaseClass::AddCollision(EntityBaseClass *arg0) {
    unsigned int i;
    unsigned int off;
    unsigned int target;
    void *pEnt;

    i = 0;
    off = 0;
    while (i < 10) {
        target = *(unsigned int *)((char *)this + off + 0x110);
        if (target == 0) {
            this->m_unk110[i] = arg0->m_unk04;
            return;
        }
        pEnt = ((EntityManager *)mpEntMgr__15EntityBaseClass)->GetPtrToApparition(target);
        if (pEnt == 0 || ((unsigned char *)pEnt)[0x163] == 6) {
            this->m_unk110[i] = arg0->m_unk04;
            return;
        }
        off += 4;
        i++;
    }
}

// DRAFT: 0x0014D680 RemoveCollision__15EntityBaseClassFP15EntityBaseClass
// note: 16 differing words (0x44 vs 0x50); source-level loop/store variants (return vs break, index init order, char-pointer and local-pointer store, compare operand swap) do not change the store and delay-slot allocation (original fills bne slot with nop and stores via sll a1 + addiu + addu).
void EntityBaseClass::RemoveCollision(EntityBaseClass *arg0) {
    int target;
    unsigned int i;
    unsigned int off;

    target = arg0->m_unk04;
    i = 0;
    off = 0;
    for (; i < 10; off += 4, i++) {
        if (*(int *)((char *)this + off + 0x110) == target) {
            this->m_unk110[i] = 0;
            break;
        }
    }
}

// DRAFT: 0x0014D790 FindCollision__15EntityBaseClassFP15EntityBaseClass
// note: 9 differing lines; bne operand order, loop tail nop, return branch targets jr at 0x40 not 0x3C; tried indexed m_unk110[i], byte-offset loop, hoisted target, decl reorder, operand swap, for-header off+=4, break/result variable (worse).
int EntityBaseClass::FindCollision(EntityBaseClass *arg0) {
    int target;
    unsigned int i;
    unsigned int off;

    target = arg0->m_unk04;
    off = 0;
    for (i = 0; i < 10; off += 4, i++) {
        if (*(int *)((char *)this + off + 0x110) == target) {
            return 1;
        }
    }
    return 0;
}

// DRAFT: 0x0014D7E0 ResetCollisions__15EntityBaseClassFv
// note: 6 words differ; original keeps a carried byte offset in the remainder loop and has an extra nop before its loop test (size 0x6c vs 0x68). Tried: simple loop, unroll-by-8 with i<10 loop, separate offset, unsigned counter, while and for remainder forms.
void EntityBaseClass::ResetCollisions() {
    unsigned int i;
    unsigned int off;

    i = 0;
    off = 0;
    do {
        char *base = (char *)this + off;
        *(int *)(base + 0x110) = 0;
        *(int *)(base + 0x114) = 0;
        *(int *)(base + 0x118) = 0;
        *(int *)(base + 0x11C) = 0;
        *(int *)(base + 0x120) = 0;
        *(int *)(base + 0x124) = 0;
        *(int *)(base + 0x128) = 0;
        *(int *)(base + 0x12C) = 0;
        off += 0x20;
        i += 8;
    } while (i < 2);
    off = i * 4;
    for (; i < 10; i++) {
        *(int *)((char *)this + off + 0x110) = 0;
        off += 4;
    }
}

// DRAFT: 0x0014D850 UpdateShadowVolume__15EntityBaseClassFv
// note: 12 words differ; original tail-merges the two SetShadowVolume arms into one jal with 0.4f built by lui/ori/mtc1 (ours pools 0.4f and calls twice). Tried: if/else with local scale, ternary, flipped branch, per-arm calls (best, 12 words; 15 for the others).
void EntityBaseClass::UpdateShadowVolume() {
    float (*mtx)[4];

    if (this->m_unk3C != 0) {
        mtx = (float (*)[4])(this->m_unk3C + 0x80);
    } else {
        mtx = (float (*)[4])((char *)this + 0x190);
    }
    if (mBGCollision__15EntityBaseClass.CheckCeiling(mtx) != 0) {
        this->SetShadowVolume(0.4f);
    } else {
        this->SetShadowVolume(1.0f);
    }
}

// DRAFT: 0x0014D8C0 SetShadowVolume__15EntityBaseClassFf
// note: 25 words differ; the original builds 0.02f inline (lui/ori/mtc1, first lui in a branch delay slot) and ours pools it via gp. Tried: goto shared exit (25), hoisted 0.02f local (25).
void EntityBaseClass::SetShadowVolume(float arg0) {
    float temp;

    if (arg0 != this->m_unkE0) {
        if (this->m_unkE0 < arg0) {
            temp = this->m_unkE0 + 0.02f;
            this->m_unkE0 = temp;
            if (!(temp <= arg0)) {
                goto block_5;
            }
        } else {
            temp = this->m_unkE0 - 0.02f;
            this->m_unkE0 = temp;
            if (temp < arg0) {
block_5:
                this->m_unkE0 = arg0;
            }
        }
        this->m_unkD0 = 0;
    }
}

// FUNCTION: 0x0014D940 RemovePhysicsAnimList__15EntityBaseClassFv
void EntityBaseClass::RemovePhysicsAnimList() {
    if (this->m_unk102 != 0) {
        if (this->m_unk3C != 0) {
            mBGAnimList__7Physics.Remove(this->m_unk3C);
        }
    }
    this->m_unk102 = 0;
}

// FUNCTION: 0x0014D980 AddPhysicsAnimList__15EntityBaseClassFv
void EntityBaseClass::AddPhysicsAnimList() {
    PMeshNode *node;

    if (this->m_unk102 == 0) {
        if (this->m_unk3C != 0) {
            ((Physics *)this->m_unk3C)->AddBGAnimNode(node);
            this->m_unk102 = 1;
        }
    }
}

// FUNCTION: 0x0014D9D0 RemoveFromBGAnimList__15EntityBaseClassFv
void EntityBaseClass::RemoveFromBGAnimList() {
    if (this->m_unk161 != 0) {
        if (this->m_unk3C == 0) {
            CdsAssert__FPciPc("EntityBaseClass.cpp", 0x430, "mpMeshNode");
        }
        this->m_unk161 = 0;
        ((PMeshNode *)this->m_unk3C)->RemoveFromCollisionArray((PArray *)((char *)&mBGCollision__15EntityBaseClass + 0x70));
    }
}

// DRAFT: 0x0014DA30 AddToBGAnimList__15EntityBaseClassFv
// note: 2 differing words (0x38/0x40): original loads a0=m_unk3C before a2=m_unk04, ours loads a2 first; tried node/size locals, size-before-node order, direct m_unk04 arg with node-local null test (frame grows, worse).
void EntityBaseClass::AddToBGAnimList() {
    PMeshNode *node;
    unsigned int size;

    if (this->m_unk161 == 0) {
        if (this->m_unk3C == 0) {
            CdsAssert__FPciPc("EntityBaseClass.cpp", 0x41F, "mpMeshNode");
        }
        size = this->m_unk04;
        node = (PMeshNode *)this->m_unk3C;
        if (node->BuildCollisionArray((PArray *)&mBGCollision__15EntityBaseClass, size) != 0) {
            this->m_unk161 = 1;
        }
    }
}

// DRAFT: 0x0014DAA0 WriteApparitionData__15EntityBaseClassFicUi
// note: DIFF 55 words; gate/tally block order and tail (sw before b, ld ra in delay slot) differ. Tried goto-done (74), tally-first (73), early returns (55).
void EntityBaseClass::WriteApparitionData(int arg0, char arg1, unsigned int arg2) {
    char *slot;
    if (m_unk18 == 0 && arg2 == 0) {
        if (arg0 == 0) {
            if (m_unk10 == 3) {
                *(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5B4C) += 1;
            }
            return;
        }
    } else {
        if (!(arg0 < 4)) {
            CdsAssert__FPciPc("EntityBaseClass.cpp", 0x3AB, "iOffset < STATIC_APPARITION_DATA_SIZE");
        }
    }
    if (arg2 == 0) {
        arg2 = m_unk04;
    }
    slot = 0;
    if (arg2 < *(unsigned int *)((char *)mpEntMgr__15EntityBaseClass + 0x5054)) {
        slot = (char *)mpEntMgr__15EntityBaseClass + 0x53A0 + arg2 * 4;
    }
    if (slot == 0) {
        return;
    }
    if (arg0 >= 0) {
        slot[arg0] = arg1;
        if (arg1 == -2 && arg0 == 1) {
            goto check;
        }
    }
    *((char *)mpEntMgr__15EntityBaseClass + 0x59A0 + arg2) = arg1;
check:
    if (arg0 != 0) {
        return;
    }
    if (arg1 == 0) {
        return;
    }
    {
        int tally = arg1;
        if (tally == ((EntityBaseClassVirtuals *)this)->GetTallyType()) {
            return;
        }
        printf("Tally mismatch for entity %d(%d != %d)\n", m_unk08, tally, ((EntityBaseClassVirtuals *)this)->GetTallyType());
    }
}

// DRAFT: 0x0014DC20 ReadApparitionData__15EntityBaseClassFiUi
// note: saved-register order is swapped (compiler puts iOffset in s1, original in s0); 27 words differ. Tried: local index copy, local offset copy after the first branch; same output.
char EntityBaseClass::ReadApparitionData(int iOffset, unsigned int uIndex) {
    if (m_unk18 == 0 && uIndex == 0) {
        return 0;
    }
    int off = iOffset;
    if (!(off < 4)) {
        CdsAssert__FPciPc("EntityBaseClass.cpp", 0x398, "iOffset < STATIC_APPARITION_DATA_SIZE");
    }
    if (uIndex == 0) {
        uIndex = m_unk04;
    }
    char *pSlot = 0;
    if (uIndex < *(unsigned int *)((char *)mpEntMgr__15EntityBaseClass + 0x5054)) {
        pSlot = (char *)mpEntMgr__15EntityBaseClass + 0x53A0 + uIndex * 4;
    }
    if (pSlot == 0) {
        return 0;
    }
    return pSlot[off];
}

// DRAFT: 0x0014DCE0 ProcessSequence__15EntityBaseClassFv
// note: 320 words differ; m3C kept in v1 not s1, andi 7 lacks dsll32/dsra32, branch targets 0x24-0x40 differ. Tried !=1 reorder (322), signed char flags (329), pMesh local (323).
void EntityBaseClass::ProcessSequence() {
    bool bLoop;
    int *p;
    int id;
    int arg;
    int s3;
    int v;
    short sA;
    short sB;
    unsigned int uC;
    unsigned int flags;
    struct {
        unsigned short a[6];
        float f;
    } anim;

    bLoop = true;
    if (m_unk13C != 0) {
        if (m_unk148 == 1) {
            CDS_ASSERT(0x2CE, m_unk3C != 0, "pMeshNode");
            if (m_unk3C[0x3F] & 7) {
                return;
            }
            m_unk148 = 0;
            if (m_unk158 != 0) {
                StopSoundBySoundRef(m_unk158);
                m_unk158 = 0;
            }
        } else if (m_unk148 != 0) {
            CdsAssert__FPciPc("EntityBaseClass.cpp", 0x2E7, "0");
        }
        do {
            p = (int *)m_unk13C;
            m_unk13C = (int)(p + 1);
            id = *p;
            switch (id) {
            case 1:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                arg = *p;
                if (arg != 0) {
                    CDS_ASSERT(0x2FB, mpResMgr__15EntityBaseClass->GetResType(arg) == 1, "Invalid mesh file passed to LoadMesh");
                }
                LoadMesh(arg, false, true);
                break;
            case 2:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                arg = *p;
                if (arg != 0) {
                    CDS_ASSERT(0x30A, mpResMgr__15EntityBaseClass->GetResType(arg) == 2, "Invalid animation file passed to LoadAnim");
                }
                LoadAnim(arg, true);
                if (m_unk38 != 0) {
                    flags = *(unsigned short *)((char *)m_unk38 + 0x106);
                    m_unk38->SetPhysicsType(flags & ~4, 0);
                }
                break;
            case 3:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                anim.a[0] = *(unsigned short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                anim.a[1] = *(unsigned short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                anim.a[2] = *(unsigned short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                anim.a[3] = *(unsigned short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                anim.a[4] = *(unsigned short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                anim.a[5] = *(unsigned short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                anim.f = (float)*p / 256.0f;
                SetAnimData((AnimData *)&anim);
                m_unk148 = 1;
                bLoop = false;
                m_unk14C++;
                break;
            case 4:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                sA = *(short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                sB = *(short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                uC = *(unsigned int *)p;
                FadeMesh(sA, sB, uC);
                m_unk162 = 1;
                break;
            case 5:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                v = *p;
                if (m_unk38 != 0) {
                    flags = *(unsigned short *)((char *)m_unk38 + 0x106);
                    if (v != 0) {
                        flags = flags | 4;
                    } else {
                        flags = flags & ~4;
                    }
                    m_unk38->SetPhysicsType(flags, 0);
                }
                break;
            case 6:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                m_unk163 = (unsigned char)*p;
                if (m_unk163 == 2) {
                    ResetCollisions();
                }
                break;
            case 7:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                m_unk15C = *(unsigned short *)p;
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                m_unk15E = *(unsigned short *)p;
                break;
            case 8:
                AddToBGAnimList();
                break;
            case 9:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                arg = *p;
                s3 = gSound.IsAmbientSoundByID(arg);
                if (s3 != 0) {
                    if (m_unk158 != 0) {
                        StopSoundBySoundRef(m_unk158);
                        m_unk158 = 0;
                    }
                }
                v = PlaySound(arg);
                if (s3 != 0) {
                    m_unk158 = v;
                }
                break;
            case 0xA:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                v = *p;
                if (m_unk38 != 0) {
                    *(int *)((char *)m_unk38 + 0xEC) = v;
                }
                break;
            case 0xB:
                p = (int *)m_unk13C;
                m_unk13C = (int)(p + 1);
                m_unk103 = (unsigned char)*p;
                break;
            case 0xFF:
                m_unk13C = 0;
                break;
            default:
                printf("invalid sequence command %d in %s\n", id, ((SeqSlotView *)this)->SeqSlot4());
                CdsAssert__FPciPc("EntityBaseClass.cpp", 0x378, "0");
                break;
            }
        } while (bLoop && m_unk13C != 0);
    }
    if (m_unk162 == 0) {
        if (m_unk13C == 0) {
            m_unk160 = 0;
        }
        return;
    }
    if (m_unk178 != 0) {
        return;
    }
    if (m_unk13C == 0) {
        m_unk160 = 0;
    }
    m_unk162 = 0;
}

// DRAFT: 0x0014E250 PlaySequence__15EntityBaseClassFPUi
// note: DIFF 2 words; original fills the ProcessSequence delay slot with sb zero,0x162 and computes a0 before jal, ours fills it with the a0 daddu. Tried: this->ProcessSequence() (no gain).
int EntityBaseClass::PlaySequence(unsigned int *arg0) {
    if (arg0 == 0) {
        CdsAssert__FPciPc("EntityBaseClass.cpp", 0x28D, "pSeq");
    }
    if ((int)arg0 != m_unk13C) {
        m_unk13C = (int)arg0;
        m_unk140 = m_unk13C;
        m_unk14C = 0;
        m_unk148 = 0;
        if (m_unk158 != 0) {
            StopSoundBySoundRef(m_unk158);
            m_unk158 = 0;
        }
        m_unk144 = 0;
        m_unk160 = 1;
        ProcessSequence();
        m_unk162 = 0;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x0014E2F0 FreezeCheck__15EntityBaseClassFP15EntityBaseClassi
void EntityBaseClass::FreezeCheck(EntityBaseClass *arg0, int arg1) {
    if (arg0->m_unkF4 == 0) {
        if ((this->m_unk15E & 0x100) && (arg1 == 1)) {
            arg0->SetFreeze(180.0f);
        }
    } else {
        float value;
        if (arg1 == 2) {
            value = -1.0f;
        } else {
            value = 0.0f;
        }
        arg0->SetFreeze(value);
    }
}

// DRAFT: 0x0014E370 SetFreeze__15EntityBaseClassFf
// note: 27 words differ: c.eq.s operands (orig f20,f0), first-branch b/bnez targets, shared store tail (orig duplicates swc1 in delay slot); tried operand swap, fx!=0 re-test (30), early return (38).
void EntityBaseClass::SetFreeze(float arg0) {
    if (arg0 > 0.0f) {
        if (m_unkEB != 0) {
            if (m_unkF4 == 0) {
                m_unkF4 = ((PParticleManager *)(gGfxEng + 0x154F00))->CreateFrozenFx((PMNode *)m_unk3C, m_unkF8, m_unkFC);
                PlaySound(0x13F);
            }
            m_unkEC = arg0;
        }
    } else {
        PParticleSystem *fx = m_unkF4;
        if (fx != 0) {
            if (arg0 == 0.0f && m_unkEC > 170.0f) {
                return;
            }
            if (((PParticleManager *)(gGfxEng + 0x154F00))->IsValid(fx)) {
                fx->FadeAndDie(0);
            }
            PlaySound(0x13B);
            m_unkF4 = 0;
        }
        m_unkEC = arg0;
    }
}

// DRAFT: 0x0014E480 CreateFireDamageFx__15EntityBaseClassFf
// note: 25000.0f compiles as int-to-float (addiu/cvt.s.w) not lui/ori/mtc1; c.eq.s operands stay f0,f20; a1/a2 load order differs. Tried: operand swap, both compare forms.
void EntityBaseClass::CreateFireDamageFx(float arg0) {
    PMNode *temp_a0;

    temp_a0 = (PMNode *)this->m_unk3C;
    if ((temp_a0 != 0) && (arg0 != 0.0f)) {
        temp_a0->DestroyFxTriggersBySpawnFrame(25000.0f, true);
        this->m_unkF0 = arg0;
        ((PParticleManager *)(gGfxEng + 0x154F00))->CreateFireDamageFx((PMNode *)this->m_unk3C, this->m_unk08);
    }
}

// DRAFT: 0x0014E500 Animate__15EntityBaseClassFif
// note: 104 words; c.eq.s operand order and zero loaded to $f0 at 0xD8 (original $f1) shift float regs; tried swapped != tests and hoisted IntersectBox pointer, no gain
void EntityBaseClass::Animate(int arg0, float arg1) {
    float f20;
    PParticleSystem *s1;
    int nBox;
    unsigned char var_v0;
    float f0;
    float fe;
    float f2;
    float f1;
    float t;
    int a0;

    f20 = arg1;
    CDS_ASSERT(0x216, this->m_unk3C != 0, "mpMeshNode");
    if (arg0 & this->m_unkE8) {
        f20 = 0.0f;
    } else {
        int v = this->m_unk34;
        if (v != 0) {
            v = v - 1;
            this->m_unk34 = v;
            if (v <= 0) {
                this->m_unk30 = 0;
            }
        }
    }
    if (f20 != 0.0f) {
        f0 = this->m_unkF0;
        if (f0 != 0.0f) {
            f0 = f0 - f20;
            this->m_unkF0 = f0;
            if (f0 <= 0.0f) {
                this->m_unkF0 = 0.0f;
                if (this->m_unk3C != 0) {
                    ((PMNode *)this->m_unk3C)->DestroyFxTriggersBySpawnFrame(25000.0f, true);
                }
            }
        }
    }
    if (f20 != 0.0f) {
        fe = this->m_unkEC;
        if (fe != 0.0f) {
            fe = fe - f20;
            this->m_unkEC = fe;
            if (fe <= 0.0f) {
                this->m_unkEC = 0.0f;
                s1 = this->m_unkF4;
                if (s1 != 0) {
                    if (((PParticleManager *)(gGfxEng + 0x154F00))->IsValid(s1)) {
                        s1->FadeAndDie(0);
                    }
                    this->m_unkF4 = 0;
                }
            }
            f20 = 0.0f;
        }
    }
    var_v0 = 1;
    if (f20 == 0.0f) {
        var_v0 = 0;
    }
    this->m_unk167 = var_v0;
    ((PMNode *)this->m_unk3C)->VirtSlot4(0.0f, f20, 0, 0, false);
    nBox = IntersectBox__9PFrustrumFPA2_A4_fP5PMat4(mpFrustum__15EntityBaseClass, this->m_unk3C + 0x110, this->m_unk3C + 0x40);
    SetAllFrustrumTest__6PMNodeF13eBoxIntersect(this->m_unk3C, nBox);
    if (this->m_unk100 != 0) {
        if (nBox == 4) {
            f2 = *(float *)((char *)mpFrustum__15EntityBaseClass + 0xE0);
            if (!(f2 <= -6.0f)) {
                f1 = 0.0f;
                t = -1.0f - f2;
                if (!(t <= 0.0f)) {
                    f1 = 25.6f * t;
                }
                if (!(f1 >= 2.1474836e9f)) {
                    a0 = (int)f1;
                } else {
                    a0 = (int)(f1 - 2.1474836e9f) | 0x80000000;
                }
                this->m_unk101 = (unsigned char)a0;
                return;
            }
        }
    }
    this->m_unk101 = 0x80;
}

// DRAFT: 0x0014E7A0 Render__15EntityBaseClassFP13PLightManager
// note: DIFF 2 words only, the lui/addiu pair at 0x60/0x6C for the local aAmb$642 (mwccps2 cannot spell '$', and config has no other alias); alpha and tail order match
int EntityBaseClass::Render(PLightManager *arg0) {
    int ret;

    if (this->m_unk3C == 0) {
        CdsAssert__FPciPc("EntityBaseClass.cpp", 0x1DF, "mpMeshNode");
    }
    if ((this->m_unk30 != 0) && (this->m_unk34 & 2)) {
        ((PGfxEngine *)(gGfxEng + 0x6680))->SetOverrideTexture(this->m_unk30);
        ((PGfxEngine *)(gGfxEng + 0x6680))->SetAmbientLight(aAmb_642);
        ((PGfxEngine *)(gGfxEng + 0x6680))->UpdateLights();
    } else if (this->m_unkD0 == 0) {
        this->m_unkD0 = 1;
        arg0->ComputeLights(this->m_unk3C != 0 ? (float *)(this->m_unk3C + 0x80) : (float *)((char *)this + 0x190), true, this->m_unkD1, true, (tagComputedLightCache *)((char *)this + 0x40), 0, this->m_unkE0);
    } else {
        ((PGfxEngine *)(gGfxEng + 0x6680))->UpdateLights((PMat4 *)((char *)this + 0x40), (PMat4 *)((char *)this + 0x80), (float (*)[4])((char *)this + 0xC0));
    }

    {
        int alpha = this->m_unkD2;

        if ((signed char)this->m_unk101 >= 0) {
            alpha = (alpha * this->m_unk101) >> 7;
        }
        ret = ((RenderView *)this->m_unk3C)->Draw(0, alpha, this->m_unk164);
    }
    ((PGfxEngine *)(gGfxEng + 0x6680))->SetOverrideTexture(0);
    if (this->m_unkD4 != 0) {
        ret += ((Shadow *)this->m_unkD4)->Render(this);
    }
    return ret;
}

// FUNCTION: 0x0014E900 SetAnimData__15EntityBaseClassFP8AnimData
void EntityBaseClass::SetAnimData(AnimData *arg0) {
    if (this->m_unk3C != 0) {
        ((PMNode *)this->m_unk3C)->VirtSlot5(arg0);
    }
}

// DRAFT: 0x0014E930 LoadAnim__15EntityBaseClassFUib
// note: DIFF 48 words; register allocation differs (original this=s1, arg0=s0, res=s2; ours this=s2, arg0=s1, res=s0) and the prologue save order differs. Tried: pm local for the copy block, if/else with == 5 first (out-of-line printf), res declared at top, buf scoped in the null block; all 48.
int EntityBaseClass::LoadAnim(unsigned int arg0, bool arg1) {
    char *res;
    if (this->m_unk3C == 0) {
        char buf[0x100];

        if (!arg1) {
            return 0;
        }
        sprintf(buf, "( %s ) Called load anim ( id = %d ) without loading mesh", ((EntityBaseClassVirtuals *)this)->GetName(), arg0 & 0xFFFF);
        CdsAssert__FPciPc("EntityBaseClass.cpp", 0x1A0, buf);
    }
    this->m_unk138 = 0xF423F;
    res = (char *)mpResMgr__15EntityBaseClass->GetResource(arg0, false);
    if (res == 0) {
        printf("No resource %d for Entity %d\n", arg0, this->m_unk08);
        return 0;
    }
    if (*(int *)(res + 4) == 5) {
        if (((PMNode *)this->m_unk3C)->VirtSlot6(res) == 0) {
            return 0;
        }
        char *pm = this->m_unk3C;
        if (*(int *)(pm + 4) == 1) {
            *(u_long128 *)(pm + 0x110) = *(u_long128 *)(res + 0x10);
            *(u_long128 *)(pm + 0x120) = *(u_long128 *)(res + 0x20);
        }
    } else {
        printf("%d isn't animation\n", arg0);
        return 0;
    }
    this->m_unk154 = arg0;
    return 1;
}

// DRAFT: 0x0014EA80 LoadMesh__15EntityBaseClassFUibb
// note: DIFF 207 words; prologue saves s0..s5 (original s0..s3, frame 0x70), so the compiler keeps extra values live across calls; tried locals scoping, address-taken sp locals, sp[2] array, m38 copy from sp50, pSys block scope; none lowered the count.
int EntityBaseClass::LoadMesh(unsigned int arg0, bool arg1, bool arg2) {
    u_long128 sp[2];

    if (!arg1 && arg0 == (unsigned int)this->m_unk150) {
        return 0;
    }
    if (arg0 != 0) {
        this->m_unk28 = arg0;
    }
    this->m_unk138 = 0xF423F;
    if (this->m_unkF4 != 0) {
        PParticleSystem *pSys = this->m_unkF4;
        if (pSys != 0 && ((PParticleManager *)(gGfxEng + 0x154F00))->IsValid(pSys)) {
            pSys->FadeAndDie(0);
        }
        this->m_unkF4 = 0;
        this->m_unkEC = 0.0f;
    }
    if (this->m_unk3C != 0) {
        sp[0] = *(u_long128 *)((char *)this->m_unk3C + 0x80);
        sp[1] = *(u_long128 *)((char *)this->m_unk3C + 0x90);
        this->RemoveFromBGAnimList();
        this->RemovePhysicsAnimList();
        if (this->m_unk3C != 0) {
            ((PMNode *)this->m_unk3C)->VirtSlot0(1);
        }
        this->m_unk3C = 0;
        if (arg0 == 0) {
            this->m_unk150 = 0;
            ((EntityManager *)mpEntMgr__15EntityBaseClass)->RemoveFromRenderList(this);
            this->ResetCollisions();
            if (this->m_unkD4 != 0) {
                void *pVol = *(void **)(this->m_unkD4 + 0xC);
                if (pVol != 0) {
                    SetShadowCaster__13PShadowVolumeFP6PMNode(pVol, 0);
                }
            }
            return 0;
        }
    } else {
        sp[0] = *(u_long128 *)((char *)this + 0x190);
        sp[1] = *(u_long128 *)((char *)this + 0x1A0);
        Physics *pPhys = this->m_unk38;
        if (pPhys != 0) {
            *(float *)((char *)pPhys + 0x11C) = Round180(*(float *)((char *)this + 0x1A4));
            if (*(float *)((char *)this->m_unk38 + 0xAC) == 0.0f) {
                *(u_long128 *)((char *)this->m_unk38 + 0xA0) = sp[0];
            }
        }
        if (this->m_unk150 == 0) {
            ((EntityManager *)mpEntMgr__15EntityBaseClass)->AddToRenderList(this);
        }
    }
    this->m_unk3C = (char *)mpResMgr__15EntityBaseClass->GetResource(arg0, false);
    if (arg2) {
        if (this->m_unk3C == 0) {
            printf("ERROR : Couldn't find resource with id (%d)\n", arg0);
        }
        CDS_ASSERT(0x159, this->m_unk3C != 0, "mpMeshNode");
    } else if (this->m_unk3C == 0) {
        return 0;
    }
    ((PMNode *)this->m_unk3C)->VirtSlot3();
    if (this->m_unkD4 != 0) {
        void *pVol = *(void **)(this->m_unkD4 + 0xC);
        if (pVol != 0) {
            SetShadowCaster__13PShadowVolumeFP6PMNode(pVol, this->m_unk3C);
        }
    }
    *(u_long128 *)((char *)this->m_unk3C + 0x80) = sp[0];
    ((PMNode *)this->m_unk3C)->m_3E |= 8;
    *(u_long128 *)((char *)this->m_unk3C + 0x90) = sp[1];
    ((PMNode *)this->m_unk3C)->m_3E |= 8;
    this->m_unk150 = arg0;
    if (this->m_unk38 != 0) {
        if ((int)this->m_unk163 < 4) {
            char *pn = this->m_unk3C;
            float fLo = 0.5f * (*(float *)(pn + 0x128) + *(float *)(pn + 0x120));
            if (fLo < 1.5f) {
                fLo = 1.5f;
            }
            float fHi = *(float *)(pn + 0x124);
            if (fHi < 1.5f) {
                fHi = 1.5f;
            }
            if (!(fLo <= fHi)) {
                fLo = fHi;
            }
            char *pa = (char *)this->m_unk38 + 0x80;
            *(float *)(pa + 0x10) = fLo;
            *(float *)(pa + 0x18) = fLo;
            if (this->m_unk10 == 6 || this->m_unk10 == 3) {
                float fTmp = 1.0f + fLo;
                if (fHi < fTmp) {
                    fHi = fTmp;
                }
            }
            *(float *)(pa + 0x4) = fHi;
            *(float *)(pa + 0x14) = fHi;
        }
    }
    return 1;
}

// FUNCTION: 0x0014EDE0 SetState__15EntityBaseClassFi
void EntityBaseClass::SetState(int arg0) {
    int cur;

    if (arg0 != -1) {
        cur = this->m_unk20;
        if (cur == arg0) {
            this->m_unk24 = -1;
        } else if (cur == -1) {
            this->SetActiveLoad();
        }
    }
    this->m_unk20 = arg0;
}

// FUNCTION: 0x0014EE40 FreeActiveLoad__15EntityBaseClassFv
void EntityBaseClass::FreeActiveLoad() {
    if (this->m_unk19 != 0) {
        this->m_unk19 = 0;
        mLoadTable__15EntityBaseClass[this->m_unk10].m0 -= this->m_unk14;
        if (mLoadTable__15EntityBaseClass[this->m_unk10].m0 < 0) {
            CdsAssert__FPciPc("EntityBaseClass.cpp", 0x102, "(int)mLoadTable[meLoadClass][CURRENT_CLASS_LOAD_VALUE] >= 0");
        }
        mLoadTable__15EntityBaseClass[this->m_unk10].m8 -= 1;
    }
}

// FUNCTION: 0x0014EF00 SetActiveLoad__15EntityBaseClassFv
void EntityBaseClass::SetActiveLoad() {
    if (this->m_unk19 == 0) {
        this->m_unk19 = 1;
        mLoadTable__15EntityBaseClass[this->m_unk10].m0 += this->m_unk14;
        mLoadTable__15EntityBaseClass[this->m_unk10].m8 += 1;
    }
}

// FUNCTION: 0x0014EF70 InitLoadSystem__15EntityBaseClassFv
void EntityBaseClass::InitLoadSystem() {
    mLoadTable__15EntityBaseClass[0].m0 = 0;
    mLoadTable__15EntityBaseClass[1].m0 = 0;
    mLoadTable__15EntityBaseClass[0].m4 = 0x64;
    mLoadTable__15EntityBaseClass[1].m4 = 0x64;
    mLoadTable__15EntityBaseClass[2].m0 = 0;
    mLoadTable__15EntityBaseClass[2].m4 = 0x64;
    mLoadTable__15EntityBaseClass[3].m0 = 0;
    mLoadTable__15EntityBaseClass[3].m4 = 0x64;
    mLoadTable__15EntityBaseClass[4].m0 = 0;
    mLoadTable__15EntityBaseClass[4].m4 = 0x64;
    mLoadTable__15EntityBaseClass[5].m0 = 0;
    mLoadTable__15EntityBaseClass[5].m4 = 0x64;
    mLoadTable__15EntityBaseClass[6].m4 = 0x64;
    mLoadTable__15EntityBaseClass[6].m0 = 0;
}

// FUNCTION: 0x0014EFF0 InitStatic__15EntityBaseClassFP16PResourceManagerP13EntityManagerP9PFrustrum
void EntityBaseClass::InitStatic(PResourceManager *arg0, EntityManager *arg1, PFrustrum *arg2) {
    mpResMgr__15EntityBaseClass = arg0;
    mpEntMgr__15EntityBaseClass = (EntityAttackManager *)arg1;
    mpFrustum__15EntityBaseClass = arg2;
    mTempArray__15EntityBaseClass.Allocate(0x20U);
}

// FUNCTION: 0x0014F010 ModifyLoadClass__15EntityBaseClassFQ215EntityBaseClass9LoadClass
void EntityBaseClass::ModifyLoadClass(LoadClass arg0) {
    if ((int)arg0 != this->m_unk10 && this->m_unk19 != 0) {
        mLoadTable__15EntityBaseClass[this->m_unk10].m0 -= this->m_unk14;
        mLoadTable__15EntityBaseClass[this->m_unk10].m8 -= 1;
        mLoadTable__15EntityBaseClass[(int)arg0].m0 += this->m_unk14;
        mLoadTable__15EntityBaseClass[(int)arg0].m8 += 1;
        this->m_unk10 = (int)arg0;
    }
}

// DRAFT: 0x0014F0B0 __dt__15EntityBaseClassFv
// note: DIFF 54 words; the 0x18 skip branch is 3 instructions shorter than the original, and the m_unk38 delete lacks the original's second null check and nop before __dl__. Tried: split delete check (54, same), virtual ~Physics (56, reverted); later branch shapes not analyzed.
EntityBaseClass::~EntityBaseClass() {
    RemoveFromBGAnimList();
    RemovePhysicsAnimList();
    if (m_unk3C != 0) {
        ((EntityManager *)mpEntMgr__15EntityBaseClass)->RemoveFromRenderList(this);
        delete (DrawObj *)m_unk3C;
        m_unk3C = 0;
    }
    if (m_unk38 != 0) {
        delete m_unk38;
        m_unk38 = 0;
    }
    if (m_unkD4 != 0) {
        delete (Shadow *)m_unkD4;
        m_unkD4 = 0;
    }
    m_unk178 = 0;
    PParticleSystem *pFx = m_unkF4;
    if (pFx != 0) {
        if (((PParticleManager *)(gGfxEng + 0x154F00))->IsValid(pFx)) {
            pFx->FadeAndDie(0);
        }
        m_unkF4 = 0;
        m_unkEC = 0.0f;
    }
    mTimerAPI__13EntityManager.KillAllApparitionTimers(m_unk04, false);
    FreeActiveLoad();
    ResetCollisions();
    StopAmbientSoundsByObject();
    RemoveFromAttackSystem();
}

// DRAFT: 0x0014F210 __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi
// note: first compiling draft from m2c order; not yet compared.
EntityBaseClass::EntityBaseClass(LoadClass eLoadClass, unsigned int nFlags)
{
    ClassTableEntry *pEntry = &ClassTable[(int)eLoadClass];
    sceVu0UnitMatrix((char *)this + 0x40);
    sceVu0UnitMatrix((char *)this + 0x80);
    m_unk04 = 0;
    m_unk08 = 0;
    *(unsigned char *)((char *)this + 0x1C) = 1;
    *(unsigned char *)((char *)this + 0x1B) = 1;
    *(unsigned char *)((char *)this + 0x1D) = 0;
    *(unsigned char *)((char *)this + 0x1E) = 0;
    m_unk164 = 0;
    m_unk102 = 0;
    *(int *)((char *)this + 0x0C) = 0;
    m_unk100 = 0;
    m_unk101 = 0x80;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unkEC = 0.0f;
    m_unkF8 = 1.0f;
    m_unkFC = 1.2f;
    m_unkF4 = 0;
    m_unk14C = 0;
    *(short *)((char *)this + 0x180) = 5;
    *(short *)((char *)this + 0x182) = 0;
    *(short *)((char *)this + 0x184) = 0;
    *(unsigned char *)((char *)this + 0x186) = 1;
    *(unsigned char *)((char *)this + 0x187) = 1;
    *(unsigned char *)((char *)this + 0x188) = 1;
    m_unk20 = -1;
    m_unk2C = -1;
    m_unkE8 = pEntry->m0;
    *(unsigned char *)((char *)this + 0xEA) = pEntry->m1;
    m_unkEB = pEntry->m3;
    *(unsigned char *)((char *)this + 0x179) = pEntry->m2;
    *(unsigned char *)((char *)this + 0x17A) = 0;
    m_unk1F = pEntry->m4;
    *(int *)((char *)this + 0x10C) = pEntry->m8;
    m_unkD1 = false;
    m_unkD2 = 0x80;
    m_unkE0 = 1.0f;
    *(int *)((char *)this + 0xE4) = 0;
    m_unkD0 = 0;
    m_unk150 = 0;
    m_unk28 = 0;
    m_unk3C = 0;
    m_unk38 = 0;
    {
        char *pVec = (char *)this + 0x190;
        asm {
            sqc2 vf0, 0x0(pVec)
            sqc2 vf0, 0x10(pVec)
        }
    }
    *(int *)((char *)this + 0x104) = 0;
    *(int *)((char *)this + 0x108) = 0;
    m_unkD4 = 0;
    m_unk13C = 0;
    m_unk140 = 0;
    m_unk144 = 0;
    m_unk178 = 0;
    m_unk162 = 0;
    *(short *)((char *)this + 0x15C) = 0;
    m_unk15E = 0;
    *(unsigned char *)((char *)this + 0x103) = 0;
    memset((char *)this + 0x110, 0, 0x28);
    m_unk163 = 0;
    CDS_ASSERT(0x89, (int)eLoadClass > 0, "eLoadClass > 0");
    CDS_ASSERT(0x8A, (int)eLoadClass < 7, "eLoadClass < LOAD_MAX");
    m_unk10 = (int)eLoadClass;
    if (nFlags == 0) {
        nFlags = pEntry->m5;
    }
    m_unk14 = nFlags;
    m_unk19 = 0;
    m_unk18 = 0;
    *(unsigned char *)((char *)this + 0xE9) = 1;
    *(unsigned char *)((char *)this + 0x165) = 0;
    m_unk166 = 0;
    m_unk161 = 0;
    m_unk1A = 1;
    *(int *)((char *)this + 0x18C) = 0x42C80000;
    m_unk138 = 0xF423F;
    m_unkDC = 0.0f;
    m_unk24 = 0;
    m_unk158 = 0;
    m_unkF0 = 0.0f;
}
