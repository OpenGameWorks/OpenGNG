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

// FUNCTION: 0x0014A970 DestroyDamageFx__15EntityBaseClassFUi
void EntityBaseClass::DestroyDamageFx(unsigned int arg0) {
    if (arg0 != 0) {
        ((PParticleManager *)(gGfxEng + 0x154F00))->Remove((PParticleSystem *)arg0);
    }
}

// FUNCTION: 0x0014C160 MusicChangePrimary__15EntityBaseClassFUiUi
int EntityBaseClass::MusicChangePrimary(unsigned int arg0, unsigned int arg1) {
    return gSound.PlayMusic(arg0) & 0xFF;
}

// DRAFT: 0x0014C6D0 GetDistFromPlayer__15EntityBaseClassFv
// note: ours has a stack frame and jal to MathAPI::Distance; original is a leaf with tail j (18 words differ); tried a0/a1 if-else forms.
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

// FUNCTION: 0x0014C7E0 ChangedState__15EntityBaseClassFv
int EntityBaseClass::ChangedState() {
    int cur = this->m_unk20;

    if (cur != this->m_unk24) {
        this->m_unk24 = cur;
        return 1;
    }
    return 0;
}

// DRAFT: 0x0014E900 SetAnimData__15EntityBaseClassFP8AnimData
// note: vtable load and call land in v0; original uses t9 (3 words differ); tried named fn ptr, typed vt, direct member, void** cast.
void EntityBaseClass::SetAnimData(AnimData *arg0) {
    if (this->m_unk3C != 0) {
        void **vt = *(void ***)this->m_unk3C;
        ((void (*)(void *, AnimData *))vt[7])(this->m_unk3C, arg0);
    }
}
