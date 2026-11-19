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

class PParticleManager {
public:
    void Remove(PParticleSystem *pSystem);
    void CreateSulphurReaction(float *arg0, float arg1);
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
    char _pad8[0x4];
};
extern LoadEntry mLoadTable__15EntityBaseClass[6];

extern "C" void sceVu0ScaleVector(float *pDst);
extern "C" void sceVu0AddVector(float *pDst, float *pSrc0, float *pSrc1);
extern "C" void CdsAssert__FPciPc(char *, int, char *);

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
