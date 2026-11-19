// FLAGS: -sdatathreshold 0
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
};
extern char gGfxEng[1504384];

class MathAPI {
public:
    static float Distance(float (*arg0)[4], float (*arg1)[4]);
};

extern EntityBaseClass *mPlayerAPI__13EntityManager;

// PArray size is unknown; the placeholder member only keeps mBGAnimList__7Physics a complete object.
class PArray {
public:
    void Remove(void *arg0);
    char _pad000[0x10];
};
extern PArray mBGAnimList__7Physics;

class PMeshNode;

class Physics {
public:
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
extern PMNode *gEng;

// FUNCTION: 0x0014A970 DestroyDamageFx__15EntityBaseClassFUi
void EntityBaseClass::DestroyDamageFx(unsigned int arg0) {
    if (arg0 != 0) {
        ((PParticleManager *)(gGfxEng + 0x154F00))->Remove((PParticleSystem *)arg0);
    }
}

// FUNCTION: 0x0014B330 IsBGAnimating__15EntityBaseClassFUi
long long EntityBaseClass::IsBGAnimating(unsigned int arg0) {
    PMNode *node = gEng->FindAnimNode(arg0);

    if (node != 0) {
        return (signed char)(node->m_3F & 7);
    }
    return 0;
}

// FUNCTION: 0x0014C160 MusicChangePrimary__15EntityBaseClassFUiUi
int EntityBaseClass::MusicChangePrimary(unsigned int arg0, unsigned int arg1) {
    return gSound.PlayMusic(arg0) & 0xFF;
}

// DRAFT: 0x0014C6D0 GetDistFromPlayer__15EntityBaseClassFv
// note: ours has a stack frame and jal to MathAPI::Distance; original is a leaf with tail j (19 differing lines); tried a0/a1 if-else forms.
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

// FUNCTION: 0x0014E900 SetAnimData__15EntityBaseClassFP8AnimData
void EntityBaseClass::SetAnimData(AnimData *arg0) {
    if (this->m_unk3C != 0) {
        ((PMNode *)this->m_unk3C)->VirtSlot5(arg0);
    }
}
