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
extern "C" void Animate__15EntityBaseClassFif(void *pThis, int arg, float dt);
extern "C" int IsValid__16PParticleManagerFP15PParticleSystem(void *pThis, void *pSystem);
extern "C" void FreezeCheck__15EntityBaseClassFP15EntityBaseClassi(void *pThis, EntityBaseClass *arg0, int arg1);
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, float (*matrix)[4], int objType, unsigned int weaponType, unsigned char flag);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int sound);
extern "C" void ExtendCombo__6PlayerFv(void *pThis);
extern "C" void GameVarAdd__6PlayerFUiii(void *pThis, unsigned int var, int a, int b);
extern "C" char mHitPos__15EntityBaseClass[0x10];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *);
extern "C" void SetFlyingShield__6PlayerFP6Shield(void *pThis, Shield *arg0);
extern "C" void UpdateShieldStatus__15ClockworkMaximoFP6Shield(void *pThis, Shield *arg0);
// gEng is a pointer read at its own address; the 16-byte placeholder keeps the load absolute.
extern "C" char gEng[0x10];

// Leading virtuals of PParticleSystem's vtable (__vt__15PParticleSystem); a call
// through this view loads the slot into $t9 as the original's virtual calls do.
class PParticleSystemVirtuals {
public:
    virtual ~PParticleSystemVirtuals();
    virtual void Slot0C();
    virtual void Render();
    virtual void ModifyPosition(void *arg);
    virtual void FrustrumTest(void *arg, float *a, float b, float c);
    virtual void FadeAndDie(unsigned int arg);
    virtual void Start();
    virtual void Stop();
    virtual void SetPosition(float *a, float *b);
};

// DRAFT: 0x001681B0 Animate__6ShieldFif
// note: 43 words differ; clamp arm stores via swc1 $f2 (original mov.s f0,f2 first), epilogue/null-branch shape and the pos-10 arm order differ; tried v>lim, v<=lim, lim>=v, local sys pointer
void Shield::Animate(int arg0, float arg1) {
    float pos[4];
    float tmp[4];
    char *src;
    char *dst;
    char *sub;

    Animate__15EntityBaseClassFif(this, arg0, arg1);
    if (m_unk1C8 != 0) {
        src = m_unk3C + 0x40;
        if (src == 0) {
            CdsAssert__FPciPc("Shield.cpp", 0x21F, "apWorldMat");
        }
        u_long128 q = *(u_long128 *)(src + 0x30);
        *(u_long128 *)pos = q;
        *(u_long128 *)tmp = q;
        if (m_unk38 == 0) {
            CdsAssert__FPciPc("Shield.cpp", 0x224, "mpPhysics");
        }
        sub = (char *)m_unk38 + 0xA0;
        if (sub != 0) {
            if (*(unsigned short *)((char *)m_unk38 + 0x106) & 1) {
                tmp[1] = pos[1] - 10.0f;
            } else {
                float v = pos[1] - 10.0f;
                float lim = *(float *)(sub + 0x14);
                if (v > lim) {
                    tmp[1] = v;
                } else {
                    tmp[1] = lim;
                }
            }
        } else {
            tmp[1] = pos[1] - 10.0f;
        }
        void *sys = (void *)m_unk1C8;
        if (sys != 0 && IsValid__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, sys)) {
            ((PParticleSystemVirtuals *)sys)->SetPosition(pos, tmp);
        }
        dst = (char *)m_unk1CC + 0x40;
        if (dst == 0) {
            CdsAssert__FPciPc("Shield.cpp", 0x239, "apWorldMat");
        }
        *(u_long128 *)(dst + 0x30) = *(u_long128 *)tmp;
    }
}

// DRAFT: 0x00168570 OnAttackEvent__6ShieldFP15EntityBaseClassi
// note: 79 words differ; epilogue beq offset, objType constant materialized as addiu v1 at 0x40 (ours reuses a2), arg1 switch chain layout, movn/movz select and lw 0x1C8 tail at 0x88-0xC0; swapped ternary form and case sense variants tried
void Shield::OnAttackEvent(EntityBaseClass *arg0, int arg1) {
    int objType;
    unsigned int weaponType;

    if (arg1 != 5) {
        FreezeCheck__15EntityBaseClassFP15EntityBaseClassi(this, arg0, arg1);
        objType = 3;
        if (arg0->m_unk10 == 6) {
        } else if (arg0->m_unk10 != 3) {
            objType = 5;
        } else {
            objType = 4;
            if (m_unk1DB != 0) {
                switch (arg1) {
                case 2:
                case 1:
                    GameVarAdd__6PlayerFUiii(m_unk1B8, 0x12, 1, 0);
                    break;
                case 4:
                case 3:
                    ExtendCombo__6PlayerFv(m_unk1B8);
                    break;
                }
                objType = (arg0->m_unk166 == 0) ? 4 : 2;
            }
        }
        if (m_unk1C8 != 0) {
            char *c = arg0->m_unk3C;
            if (c != 0) {
                *(float *)mHitPos__15EntityBaseClass = *(float *)(c + 0x114) + *(float *)(c + 0x84);
            }
        }
        weaponType = (m_unk1B0 == 2) ? 5 : 4;
        CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(this, 0, objType, weaponType, arg1 >= 3);
        PlaySound__15EntityBaseClassFUi(this, 0x1B);
        if (m_unk1D8 != 0 && CheckRicochet(arg0) != 0) {
            return;
        }
        SetState__15EntityBaseClassFi(this, 2);
        SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 5, 0);
        m_unk1DA = 1;
    }
}

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

// DRAFT: 0x001693C0 __dt__6ShieldFv
// note: 1 word differs at 0xA0: the 1C8 load is duplicated into the beqz v0 delay slot, original has nop; tried handle local (else arm) and nested 1B8 test (same)
extern "C" void *__dt__6ShieldFv(void *pThis, short nFlag) {
    Shield *self = (Shield *)pThis;
    if (pThis != 0) {
        self->m_unk0 = __vt__6Shield;
        if (self->m_unk1D0 != 0) {
            StopSoundBySoundRef__15EntityBaseClassFUi(pThis, self->m_unk1D0);
            self->m_unk1D0 = 0;
        }
        void *tmp = self->m_unk1C0;
        if (tmp != 0) {
            ((char *)tmp)[0x9F] = 1;
            ((unsigned int *)tmp)[1] = 0;
            self->m_unk1C0 = 0;
        }
        if (self->m_unk1C4 != 0) {
            DeleteEffect__9EffectAPIFUi(mEffectAPI__13EntityManager, self->m_unk1C4);
            self->m_unk1C4 = 0;
        }
        if (self->m_unk1DB != 0) {
            void *eng = *(void **)gEng;
            if (eng != 0) {
                SetFlyingShield__6PlayerFP6Shield(eng, 0);
            }
        } else {
            unsigned int handle = self->m_unk1C8;
            if (self->m_unk1B8 != 0) {
                if (ApparitionIsValid__15EntityBaseClassFUi(self->m_unk1BC, handle) != 0) {
                    UpdateShieldStatus__15ClockworkMaximoFP6Shield(self->m_unk1B8, 0);
                }
            }
        }
        Destroy__16PParticleManagerFUi(gGfxEng + 0x154F00, self->m_unk1C8);
        Destroy__16PParticleManagerFUi(gGfxEng + 0x154F00, self->m_unk1CC);
        self->m_unk1C8 = 0;
        self->m_unk1CC = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
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
