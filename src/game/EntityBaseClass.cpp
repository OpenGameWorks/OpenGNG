// FLAGS: -Cpp_exceptions off
#include "types.h"
#include "EntityBaseClass.h"

// TODO(header): foreign declarations
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    int PlayMusic(unsigned int arg0);
    char _pad000[0x10];
};
extern PSound gSound;

class PParticleSystem;
class PMNode;

class PParticleManager {
public:
    void Remove(PParticleSystem *pSystem);
    void CreateSulphurReaction(float *arg0, float arg1);
    void CreateFireDamageFx(PMNode *arg0, unsigned int arg1);
};
extern char gGfxEng[1504384];

class MathAPI {
public:
    static float Distance(float (*arg0)[4], float (*arg1)[4]);
    static float GetAngleYToPoint(EntityBaseClass *arg0, float (*arg1)[4]);
};

extern EntityBaseClass *mPlayerAPI__13EntityManager;

// PArray size is unknown; the placeholder member only keeps mBGAnimList__7Physics a complete object.
class PArray {
public:
    void Remove(void *arg0);
    char _pad000[0x10];
};
extern PArray mBGAnimList__7Physics;

class PMeshNode {
public:
    void RemoveFromCollisionArray(PArray *arg0);
    int BuildCollisionArray(PArray *arg0, unsigned int arg1);
};

// BGCollision size is unknown; the placeholder member only keeps mBGCollision__15EntityBaseClass a complete object.
class BGCollision {
public:
    int CheckCeiling(float (*arg0)[4]);
    char _pad000[0x10];
};
extern BGCollision mBGCollision__15EntityBaseClass;

class Physics {
public:
    void RunPhysics(EntityBaseClass *arg0, float arg1, int arg2, BGCollision *arg3);
    void AddBGAnimNode(PMeshNode *arg0);
};

class PMNode {
public:
    virtual void VirtSlot0();
    virtual void VirtSlot1();
    virtual void VirtSlot2();
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual void VirtSlot5(AnimData *arg0);
    PMNode *FindAnimNode(unsigned int arg0);
    void EnableOneRenderPassOnly(int arg0);
    void DestroyFxTriggersBySpawnFrame(float arg0, bool arg1);
    char _pad04[0x3B];
    signed char m_3F;
};
// gEng is a pointer; the placeholder pads it past the small-data threshold so the load is absolute.
struct PMNodeHolder {
    PMNode *ptr;
    char _pad000[0x10];
};
extern PMNodeHolder gEng;

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
    char _pad000[0x10];
};
extern PResourceManager *mpResMgr__15EntityBaseClass;

// EntityAttackManager size is unknown; only the pointer global and the RequestAttack call are needed.
class EntityAttackManager {
public:
    void RequestAttack(EntityBaseClass *arg0, float arg1, unsigned int arg2, EntityBaseClass *arg3);
    char _pad000[0x10];
};
extern EntityAttackManager *mpEntMgr__15EntityBaseClass;

extern "C" void sceVu0ScaleVector(float *pDst);
extern "C" void sceVu0AddVector(float *pDst, float *pSrc0, float *pSrc1);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" int sprintf(char *, const char *, ...);

// Vptr view used to call the object's virtual name getter at slot 0x18.
class EntityBaseClassVirtuals {
public:
    virtual ~EntityBaseClassVirtuals();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual const char *GetName();
};

float Round180(float arg0);

// FUNCTION: 0x0014A740 ProcessPhysics__15EntityBaseClassFfi
void EntityBaseClass::ProcessPhysics(float arg0, int arg1) {
    if (this->m_unk38 != 0) {
        this->m_unk38->RunPhysics(this, arg0, arg1 & this->m_unkE8, &mBGCollision__15EntityBaseClass);
        this->CheckDie(0);
    }
}

// FUNCTION: 0x0014A970 DestroyDamageFx__15EntityBaseClassFUi
void EntityBaseClass::DestroyDamageFx(unsigned int arg0) {
    if (arg0 != 0) {
        ((PParticleManager *)(gGfxEng + 0x154F00))->Remove((PParticleSystem *)arg0);
    }
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
    ((PParticleManager *)gGfxEng)->CreateSulphurReaction(pos, 1.0f);
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

// FUNCTION: 0x0014C160 MusicChangePrimary__15EntityBaseClassFUiUi
int EntityBaseClass::MusicChangePrimary(unsigned int arg0, unsigned int arg1) {
    return gSound.PlayMusic(arg0) & 0xFF;
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

// FUNCTION: 0x0014D620 RadiusAdjust__15EntityBaseClassFfPA4_f
void EntityBaseClass::RadiusAdjust(float arg0, float (*arg1)[4]) {
    float v[4];
    unsigned char *p;

    sceVu0ScaleVector(v);
    v[3] = 0.0f;
    sceVu0AddVector(v, v, (float *)(this->m_unk3C + 0x80));
    p = (unsigned char *)this->m_unk3C;
    *(u_long128 *)(p + 0x80) = *(u_long128 *)v;
    p[0x3E] |= 8;
    this->m_unkD0 = 0;
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
        ((PMeshNode *)this->m_unk3C)->RemoveFromCollisionArray((PArray *)&mBGCollision__15EntityBaseClass);
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

// FUNCTION: 0x0014E900 SetAnimData__15EntityBaseClassFP8AnimData
void EntityBaseClass::SetAnimData(AnimData *arg0) {
    if (this->m_unk3C != 0) {
        ((PMNode *)this->m_unk3C)->VirtSlot5(arg0);
    }
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
