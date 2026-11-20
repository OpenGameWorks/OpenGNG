// FLAGS: -str readonly
#include "types.h"
#include "Shield.h"
#include "EntityBaseClass.h"

// TODO(header): foreign declarations
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int state);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int type, float (*matrix)[4]);
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(void *pThis, unsigned int arg);
extern "C" void CdsAssert__FPciPc(char *file, int line, char *expr);
extern "C" void sceVu0SubVector(float (*dst)[4], float (*a)[4], void *b);
extern "C" float sceVu0InnerProduct(float (*a)[4], float (*b)[4]);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *pThis, unsigned int handle);
extern "C" void LoadMesh__15EntityBaseClassFUibb(void *pThis, unsigned int arg, unsigned char a, unsigned char b);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, unsigned char a, unsigned char b);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void DeleteEffect__9EffectAPIFUi(void *pThis, unsigned int handle);
extern "C" void Destroy__16PParticleManagerFUi(void *pThis, unsigned int handle);
extern "C" char mEffectAPI__13EntityManager[0x10];
extern "C" char gGfxEng[0x10];
extern "C" float gUnitMatrix[4][4];
extern "C" char __vt__6Shield[0x10];

// FUNCTION: 0x00168700 OnHitEvent__6ShieldFP15EntityBaseClassiUiUi
int Shield::OnHitEvent(EntityBaseClass *arg0, int arg1, unsigned int arg2, unsigned int arg3) {
    if (arg0->m_unk08 == 0x7C) {
        return 0;
    }
    SetState__15EntityBaseClassFi(this, 2);
    SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 5, 0);
    m_unk1DA = 1;
    return 1;
}

// DRAFT: 0x00168760 ShieldDistance__6ShieldFPA4_f
// note: 39 words differ; the a1 argument to ApparitionIsValid is kept in a1 in the original, ours reloads from s0 (tried inline cast, local tmp, cast hoisted above assert)
float Shield::ShieldDistance(float (*arg0)[4]) {
    char *var_v0;
    void *temp_v0;

    if (m_unk1DB != 0) {
        var_v0 = *(char **)((char *)m_unk1B8 + 0x28C);
    } else {
        var_v0 = 0;
    }
    if (var_v0 != 0) {
        *(u_long128 *)arg0 = *(u_long128 *)(var_v0 + 0x70);
    } else {
        if (m_unk1BC == 0) {
            CdsAssert__FPciPc("Shield.cpp", 0x193, "mParentRef");
        }
        temp_v0 = ApparitionIsValid__15EntityBaseClassFUi(m_unk1BC, (unsigned int)arg0);
        if (temp_v0 == 0) {
            return 0.0f;
        }
        if (m_unk1B8 != temp_v0) {
            CdsAssert__FPciPc("Shield.cpp", 0x19C, "mpParent == apParent");
        }
        *(u_long128 *)arg0 = *(u_long128 *)(*(char **)((char *)m_unk1B8 + 0x3C) + 0x80);
        arg0[0][1] += 2.0f;
    }
    sceVu0SubVector(arg0, arg0, m_unk3C + 0x80);
    return sceVu0InnerProduct(arg0, arg0);
}

// FUNCTION: 0x00168BF0 HoverCheck__6ShieldFv
int Shield::HoverCheck() {
    if (m_unk1D9 != 0) {
        if (*(unsigned short *)((char *)m_unk1B8 + 0x1B2) & 0x200) {
            void *tmp = m_unk1C0;
            if (tmp != 0) {
                ((char *)tmp)[0x9F] = 1;
                ((unsigned int *)tmp)[1] = 0;
                m_unk1C0 = 0;
            }
            *(u_long128 *)m_unk38 = *(u_long128 *)gUnitMatrix;
            SetState__15EntityBaseClassFi(this, 1);
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x00169300 DeleteShield__6ShieldFv
void Shield::DeleteShield() {
    if (m_unk1D0 != 0) {
        StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk1D0);
        m_unk1D0 = 0;
    }
    if (m_unk3C != 0) {
        LoadMesh__15EntityBaseClassFUibb(this, 0, 0, 1);
    }
    void *tmp = m_unk1C0;
    if (tmp != 0) {
        ((char *)tmp)[0x9F] = 1;
        ((unsigned int *)tmp)[1] = 0;
        m_unk1C0 = 0;
    }
    if (m_unk1C4 != 0) {
        DeleteEffect__9EffectAPIFUi(mEffectAPI__13EntityManager, m_unk1C4);
        m_unk1C4 = 0;
    }
    Destroy__16PParticleManagerFUi(gGfxEng + 0x154F00, m_unk1C8);
    Destroy__16PParticleManagerFUi(gGfxEng + 0x154F00, m_unk1CC);
    m_unk1C8 = 0;
    m_unk1CC = 0;
}

// DRAFT: 0x001694F0 __ct__6ShieldFv
// note: 37 words differ; original spills this to 0x1C(sp) and reloads before each store, ours keeps this in s0 (tried local self pointer, same count; embedding PArray would add a ctor call)
Shield::Shield() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 5, 1);
    m_unk0 = __vt__6Shield;
    EnableSleep__15EntityBaseClassFbb(this, 0, 0);
    m_unk1D9 = 0;
    m_unk1D8 = 0;
    m_unk1D4 = 0;
    m_unk1DA = 0;
    m_unk1C0 = 0;
    m_unk1C4 = 0;
    m_unk1C8 = 0;
    m_unk1CC = 0;
    m_unk1D0 = 0;
    m_unk1DB = 0;
    m_unk1BC = 0;
}
