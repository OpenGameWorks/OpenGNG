// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Shield.h"
#include "EntityBaseClass.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int state);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int type, float (*matrix)[4]);
// Static EntityBaseClass::ApparitionIsValid(unsigned int): one argument, a0 only.
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" void sceVu0SubVector(float (*dst)[4], float (*a)[4], void *b);
extern "C" float sceVu0InnerProduct(float (*a)[4], float (*b)[4]);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *pThis, unsigned int handle);
extern "C" void LoadMesh__15EntityBaseClassFUibb(void *pThis, unsigned int arg, unsigned char a, unsigned char b);
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
extern "C" int PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int sound);
extern "C" void ExtendCombo__6PlayerFv(void *pThis);
extern "C" void GameVarAdd__6PlayerFUiii(void *pThis, unsigned int var, int a, int b);
extern "C" char mHitPos__15EntityBaseClass[0x10];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *);
extern "C" void SetFlyingShield__6PlayerFP6Shield(void *pThis, Shield *arg0);
extern "C" void UpdateShieldStatus__15ClockworkMaximoFP6Shield(void *pThis, Shield *arg0);
// gEng is a pointer read at its own address; the 16-byte placeholder keeps the load absolute.
extern "C" char gEng[0x10];
extern "C" PArray mTempArray__15EntityBaseClass;
extern "C" void *mpEntMgr__15EntityBaseClass;
extern "C" float RICOCHET_RADIUS;
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(void *pThis, int loadClass, PArray *pArray, float (*pos)[4], float radius, int a4, unsigned char a5, unsigned char a6);
extern "C" void *GetPtrToApparition__13EntityManagerFUi(void *pThis, unsigned int handle);
extern "C" void sceVu0Normalize(float (*dst)[4], float (*src)[4]);
extern "C" void sceVu0ScaleVector(float (*dst)[4], float (*src)[4], float scale);
extern "C" void CheckSwordBGAnim__13EntityManagerFP6PMNode(void *pThis, void *node);
extern "C" int CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(void *pThis, unsigned int a1, unsigned int a2, float (*a3)[4], float (*a4)[4], EntityBaseClass *a5, float a6, bool a7, int a8, bool a9);
extern "C" unsigned int HoverSound[8];
extern "C" void *CreateGhost__9EffectAPIFP9PMeshNode(void *pThis, void *node);
extern "C" float sqrtf(float fX);
extern "C" void ResetCollisions__15EntityBaseClassFv(void *pThis);

extern "C" void *__nw__FUi(unsigned int);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void *__ct__16PParticleRipplesFv(void *pThis);
extern "C" void Init__16PParticleRipplesFibb(void *pThis, int a, bool b, bool c);
extern "C" void AutoEmit__16PParticleRipplesFfPfffff(void *pThis, float a, float *pArr, float b, float c, float d, float e);
extern "C" void Add__16PParticleManagerFP15PParticleSystem(void *pThis, void *pSys);
extern "C" void AttachFx__6PMNodeFUiffffb(void *pThis, unsigned int id, float a, float b, float c, float d, bool e);
extern "C" int GetFxTexture__16PParticleManagerFUi(void *pThis, unsigned int id);
extern "C" void *Create__16PParticleManagerFUifffP6PMNodeb(void *pThis, unsigned int id, float a, float b, float c, void *pNode, bool flag);
extern "C" void *EffectValid__9EffectAPIFUi(void *pThis, unsigned int handle);
extern "C" void SetAnimLoopCount__6PMNodeFib(void *pThis, int nCount, bool bFlag);
extern "C" void *GetFirstMesh__6PMNodeFv(void *pThis);
extern "C" void SetRenderPassStatus__6PMNodeFbbbb(void *pThis, bool a, bool b, bool c, bool d);
extern "C" int mbHard__15EntityBaseClass;

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

// Leading virtuals of PMNode's vtable; slot 0x14 is the third virtual.
class PMNodeVirtuals {
public:
    virtual ~PMNodeVirtuals();
    virtual void Slot0C();
    virtual void Slot10();
    virtual void Slot14();
};

// FUNCTION: 0x001681A0 GetClassName__6ShieldFv
const char *Shield::GetClassName() {
    return "Shield";
}

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
            CdsAssert("Shield.cpp", 0x21F, "apWorldMat");
        }
        u_long128 q = *(u_long128 *)(src + 0x30);
        *(u_long128 *)pos = q;
        *(u_long128 *)tmp = q;
        if (m_unk38 == 0) {
            CdsAssert("Shield.cpp", 0x224, "mpPhysics");
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
            CdsAssert("Shield.cpp", 0x239, "apWorldMat");
        }
        *(u_long128 *)(dst + 0x30) = *(u_long128 *)tmp;
    }
}

// FUNCTION: 0x00168330 CheckRicochet__6ShieldFP15EntityBaseClass
int Shield::CheckRicochet(EntityBaseClass *arg0) {
    EntityBaseClass *s0;
    float (*target)[4];
    EntityBaseClass *s4;
    int s2;
    float vec[4];
    float (*t)[4];
    float f0;
    float f20;
    unsigned int id;

    if (m_unk3C != 0) {
        target = (float (*)[4])(m_unk3C + 0x80);
    } else {
        target = (float (*)[4])((char *)this + 0x190);
    }
    if (mTempArray__15EntityBaseClass.m_unk8 != 0) {
        mTempArray__15EntityBaseClass.m_unk0 = 0;
        mTempArray__15EntityBaseClass.m_unk4 = 0;
    }
    if (GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, &mTempArray__15EntityBaseClass, target, RICOCHET_RADIUS, 0, 1, 0) != 0) {
        s2 = arg0->m_unk04;
        f20 = 1000.0f;
        s0 = 0;
        mTempArray__15EntityBaseClass.m_unk4 = 0;
        id = (mTempArray__15EntityBaseClass.m_unk0 != 0) ? (unsigned int)mTempArray__15EntityBaseClass.m_unk8[0] : 0;
        while (id != 0) {
            if (id != (unsigned int)s2) {
                s4 = (EntityBaseClass *)GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, id);
                if (s4->m_unk3C != 0) {
                    t = (float (*)[4])(s4->m_unk3C + 0x80);
                } else {
                    t = (float (*)[4])((char *)s4 + 0x190);
                }
                sceVu0SubVector((float (*)[4])vec, t, target);
                f0 = sceVu0InnerProduct((float (*)[4])vec, (float (*)[4])vec);
                if (f0 < f20) {
                    f20 = f0;
                    s0 = s4;
                }
            }
            id = (++mTempArray__15EntityBaseClass.m_unk4 < mTempArray__15EntityBaseClass.m_unk0) ? (unsigned int)mTempArray__15EntityBaseClass.m_unk8[mTempArray__15EntityBaseClass.m_unk4] : 0;
        }
        if (s0 != 0) {
            if (s0->m_unk3C != 0) {
                t = (float (*)[4])(s0->m_unk3C + 0x80);
            } else {
                t = (float (*)[4])((char *)s0 + 0x190);
            }
            sceVu0SubVector((float (*)[4])vec, t, target);
            vec[1] += 2.0f;
            sceVu0Normalize((float (*)[4])vec, (float (*)[4])vec);
            sceVu0ScaleVector((float (*)[4])vec, (float (*)[4])vec, 0.7f);
            vec[3] = 1.0f;
            *(u_long128 *)m_unk38 = *(u_long128 *)vec;
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x94, 0);
            *(float *)((char *)this + 0x1B4) = 20.0f;
            SetState__15EntityBaseClassFi(this, 0);
            return 1;
        }
    }
    return 0;
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

// FUNCTION: 0x00168760 ShieldDistance__6ShieldFPA4_f
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
            CdsAssert("Shield.cpp", 0x193, "mParentRef");
        }
        temp_v0 = ApparitionIsValid__15EntityBaseClassFUi((unsigned int)m_unk1BC);
        if (temp_v0 == 0) {
            return 0.0f;
        }
        if (m_unk1B8 != temp_v0) {
            CdsAssert("Shield.cpp", 0x19C, "mpParent == apParent");
        }
        *(u_long128 *)arg0 = *(u_long128 *)(*(char **)((char *)m_unk1B8 + 0x3C) + 0x80);
        arg0[0][1] += 2.0f;
    }
    sceVu0SubVector(arg0, arg0, m_unk3C + 0x80);
    return sceVu0InnerProduct(arg0, arg0);
}

// DRAFT: 0x00168860 Execute__6ShieldFv
// note: DIFF 145; switch order -1,0,1,2 best of 3 (if-chain 218, order 1,0,-1,2 210, HoverCheck!=0 reorder 194); open: case 0 branch layout (bnez far), f0/f2 float order, a3[1] += sequence, ShieldDistance call symbol
void Shield::Execute() {
    float vec[4];
    float dist;
    float f1;
    float f0;
    float *a3;
    float len;
    float scale;

    switch (m_unk20) {
    case -1:
        m_unk1D0 = PlaySound__15EntityBaseClassFUi(this, HoverSound[m_unk1B0]);
        SetState__15EntityBaseClassFi(this, 0);
        return;
    case 0:
        if (HoverCheck() == 0) {
            CheckSwordBGAnim__13EntityManagerFP6PMNode(mpEntMgr__15EntityBaseClass, m_unk3C);
            f1 = m_unk1B4 - *(float *)gEng;
            m_unk1B4 = f1;
            if (f1 <= 0.0f) {
                SetState__15EntityBaseClassFi(this, 2);
                SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 5, 0);
                m_unk1DA = 1;
            }
        } else if (*(int *)((char *)m_unk38 + 0xE4) != 0) {
            m_unk1DA = 1;
            a3 = (float *)(m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190);
            CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(mEffectAPI__13EntityManager, 0x8100002A, 0x8200005C, (float (*)[4])a3, 0, 0, 0.5f, 0, 0, 0);
            PlaySound__15EntityBaseClassFUi(this, 0x1B);
        } else {
            f0 = *(float *)((char *)m_unk38 + 0xF8);
            if (f0 < 2.0f) {
                a3 = (float *)(m_unk3C ? (char *)m_unk3C + 0x80 : (char *)this + 0x190);
                a3[1] += 2.0f - f0;
            }
        }
        if (m_unk1DA != 0 && ShieldDistance(&vec) < 4.0f) {
            SetState__15EntityBaseClassFi(this, -2);
        } else if (sceVu0InnerProduct((float (*)[4])m_unk38, (float (*)[4])m_unk38) < 0.001f) {
            SetState__15EntityBaseClassFi(this, 2);
            SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 5, 0);
            m_unk1DA = 1;
        }
        break;
    case 1:
        if (m_unk1DB != 0) {
            if ((*(unsigned short *)((char *)m_unk1B8 + 0x1B0) & 0x200) == 0) {
                SetState__15EntityBaseClassFi(this, 2);
                SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 5, 0);
                m_unk1C0 = CreateGhost__9EffectAPIFP9PMeshNode(mEffectAPI__13EntityManager, m_unk3C);
            }
        }
        if (ShieldDistance(&vec) < 4.0f) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    case 2:
        dist = ShieldDistance(&vec);
        if (dist < 4.0f) {
            SetState__15EntityBaseClassFi(this, -2);
            return;
        }
        if (HoverCheck() == 0) {
            len = sqrtf(dist);
            scale = 0.7f / len;
            sceVu0ScaleVector(&vec, &vec, scale);
            vec[3] = 1.0f;
            *(u_long128 *)m_unk38 = *(u_long128 *)vec;
            CheckSwordBGAnim__13EntityManagerFP6PMNode(mpEntMgr__15EntityBaseClass, m_unk3C);
        }
        break;
    }
    if (m_unk3C != 0 && (*(signed char *)((char *)m_unk3C + 0x3F) & 4)) {
        ResetCollisions__15EntityBaseClassFv(this);
    }
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
            *(u_long128 *)m_unk38 = *(u_long128 *)gUnitMatrix[3];
            SetState__15EntityBaseClassFi(this, 1);
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x00168C60 InitShield__6ShieldFP15EntityBaseClassfPA4_fPA4_fUiPbi
void Shield::InitShield(EntityBaseClass *arg0, float arg1, float (*arg2)[4], float (*arg3)[4], unsigned int arg4, bool *arg5, int arg6) {
    static unsigned char ShieldAnim[16] = {0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x80, 0x3F};
    static float ShieldBox[8] = {0.0f, 0.0f, 0.0f, 1.0f, 1.4f, 1.0f, 1.4f, 2.22f};
    static float SparkBox[8] = {0.0f, -10.0f, 0.0f, 1.0f, 3.0f, 10.0f, 3.0f, 15.0f};
    float *pBox;
    unsigned int nId;
    unsigned int nId2;
    int nRadius;
    char *pNode;

    m_unk1B8 = arg0;
    m_unk1BC = (EntityBaseClass *)((EntityBaseClass *)m_unk1B8)->m_unk04;
    if (arg0->m_unk08 == 3) {
        m_unk1DB = 1;
        SetFlyingShield__6PlayerFP6Shield(m_unk1B8, this);
        m_unkE8 = 3;
        m_unk10C |= 0x021A1E01;
        LoadMesh__15EntityBaseClassFUibb(this, 0x81000003, 0, 1);
    } else {
        m_unkE8 = 0xB;
        m_unk10C |= 0x021B1902;
        switch (((EntityBaseClass *)m_unk1B8)->m_unk08) {
        case 0x72:
            break;
        default:
            CdsAssert("Shield.cpp", 0x8F, "mpParent->GetClassID() == ENT_CLOCKWORKMAXIMO");
        }
        switch (arg4) {
        case 0:
            break;
        default:
            CdsAssert("Shield.cpp", 0x90, "bHover == false");
        }
        UpdateShieldStatus__15ClockworkMaximoFP6Shield(m_unk1B8, this);
        LoadMesh__15EntityBaseClassFUibb(this, 0x0100043D, 0, 1);
    }
    m_unk1B4 = arg1;
    LoadAnim(0x8200001F, 1);
    SetAnimData((AnimData *)ShieldAnim);
    pNode = m_unk3C;
    if (arg5 != 0) {
        SetRenderPassStatus__6PMNodeFbbbb(pNode, arg5[0], arg5[1], arg5[2], 0);
    }
    ((PMNodeVirtuals *)pNode)->Slot14();
    m_unk1B0 = arg6;
    *(u_long128 *)(pNode + 0x80) = *(u_long128 *)arg2;
    *(unsigned char *)(pNode + 0x3E) |= 8;
    {
        void *p = __nw__FUi(0x120);
        if (p != 0) {
            p = __ct__7PhysicsFv(p);
        }
        m_unk38 = (Physics *)p;
    }
    if (m_unk38 == 0) {
        CdsAssert("Shield.cpp", 0xAB, "mpPhysics");
    }
    SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x94, 0);
    pBox = ShieldBox;
    *(u_long128 *)m_unk38 = *(u_long128 *)arg3;
    *(int *)((char *)m_unk38 + 0xEC) = 0x58;
    {
        char *pPhys = (char *)m_unk38;
        *(u_long128 *)(pPhys + 0x80) = *(u_long128 *)ShieldBox;
        *(u_long128 *)(pPhys + 0x90) = *(u_long128 *)(ShieldBox + 4);
    }
    m_unk1D9 = (arg4 & 0x10) != 0;
    m_unk1D8 = (arg4 & 0x20) != 0;
    m_unk1C0 = CreateGhost__9EffectAPIFP9PMeshNode(mEffectAPI__13EntityManager, pNode);
    nRadius = 0x4B;
    if (arg6 != 2) {
        if (arg6 != 1) {
            nId = 0;
        } else {
            nId = 0x8100023E;
            nId2 = 0x820003EB;
        }
    } else {
        nId = 0x8100023C;
        nId2 = 0x820003F3;
        nRadius = nRadius * 2;
        pBox = SparkBox;
    }
    if (m_unk1DB != 0 && mbHard__15EntityBaseClass == 0) {
        nRadius += 0x19;
    }
    m_unk15C = nRadius;
    m_unk15E = 0x800;
    {
        char *pMesh = (char *)GetFirstMesh__6PMNodeFv(pNode);
        *(unsigned char *)(pMesh + 0xE) = 0xA0;
        *(u_long128 *)(pMesh + 0x10) = *(u_long128 *)pBox;
        *(u_long128 *)(pMesh + 0x20) = *(u_long128 *)(pBox + 4);
        *(u_long128 *)(pNode + 0x110) = *(u_long128 *)pBox;
        *(u_long128 *)(pNode + 0x120) = *(u_long128 *)(pBox + 4);
    }
    if (nId != 0) {
        char *pFx;
        m_unk1C4 = CreateOneshot__9EffectAPIFUiUiPA4_fPA4_fP15EntityBaseClassfbib(mEffectAPI__13EntityManager, nId, nId2, 0, 0, this, 0.5f, false, 0, false);
        if (m_unk1C4 == 0) {
            CdsAssert("Shield.cpp", 0xDC, "mSpark");
        }
        pFx = (char *)EffectValid__9EffectAPIFUi(mEffectAPI__13EntityManager, m_unk1C4);
        if (pFx == 0) {
            CdsAssert("Shield.cpp", 0xDE, "pSpark");
        }
        SetAnimLoopCount__6PMNodeFib(*(void **)(pFx + 4), 0, true);
        if (arg6 == 1) {
            float vA[4] = {1.15f, 1.15f, 1.15f, 1.0f};
            float vB[4] = {1.5f, 1.5f, 1.5f, 1.0f};
            char *pRip = (char *)__nw__FUi(0x8C0);
            if (pRip != 0) {
                pRip = (char *)__ct__16PParticleRipplesFv(pRip);
            }
            if (pRip == 0) {
                CdsAssert("Shield.cpp", 0xE7, "apFx");
            }
            Init__16PParticleRipplesFibb(pRip, 8, true, true);
            AutoEmit__16PParticleRipplesFfPfffff(pRip, 5.0f, vA, 1.0f, 11.0f, 0.0f, 40.0f);
            pRip[0x19] = 1;
            *(int *)(pRip + 0x28) = 0;
            *(int *)(pRip + 0x2C) = 0;
            Add__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, pRip);
            AttachFx__6PMNodeFUiffffb(*(void **)(pFx + 4), (unsigned int)pRip, 0.0f, 0.0f, -1.0f, -1.0f, true);
            pRip = (char *)__nw__FUi(0x8C0);
            if (pRip != 0) {
                pRip = (char *)__ct__16PParticleRipplesFv(pRip);
            }
            if (pRip == 0) {
                CdsAssert("Shield.cpp", 0xEF, "apFx");
            }
            Init__16PParticleRipplesFibb(pRip, 8, false, false);
            *(int *)(pRip + 0x10) = GetFxTexture__16PParticleManagerFUi(gGfxEng + 0x154F00, 0x8400000D);
            *(long long *)(pRip + 0x30) = 0x48;
            AutoEmit__16PParticleRipplesFfPfffff(pRip, 5.0f, vB, 1.0f, 11.0f, 0.0f, 40.0f);
            Add__16PParticleManagerFP15PParticleSystem(gGfxEng + 0x154F00, pRip);
            AttachFx__6PMNodeFUiffffb(*(void **)(pFx + 4), (unsigned int)pRip, 0.0f, 0.0f, -1.0f, -1.0f, true);
            return;
        }
        if (arg6 == 2) {
            m_unk1C8 = (unsigned int)Create__16PParticleManagerFUifffP6PMNodeb(gGfxEng + 0x154F00, 0x830001E7, 0.0f, 0.0f, 0.0f, 0, true);
            {
                void *pSys = (void *)m_unk1C8;
                char *pMgr = gGfxEng + 0x154F00;
                if (pSys != 0 && IsValid__16PParticleManagerFP15PParticleSystem(pMgr, pSys) != 0) {
                    ((PParticleSystemVirtuals *)pSys)->Start();
                }
            }
            m_unk1CC = (unsigned int)Create__16PParticleManagerFUifffP6PMNodeb(gGfxEng + 0x154F00, 0x830001E8, 0.0f, 0.0f, 0.0f, 0, true);
            {
                void *pSys = (void *)m_unk1CC;
                char *pMgr = gGfxEng + 0x154F00;
                if (pSys != 0 && IsValid__16PParticleManagerFP15PParticleSystem(pMgr, pSys) != 0) {
                    ((PParticleSystemVirtuals *)pSys)->Start();
                }
            }
        }
    }
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

// FUNCTION: 0x001693C0 __dt__6ShieldFv
extern "C" void *__dt__6ShieldFv(void *pThis, short nFlag) {
    Shield *self = (Shield *)pThis;
    if (pThis != 0) {
        *(void **)pThis = __vt__6Shield;
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
            void *eng = *(void **)(gEng + 0x1883C);
            if (eng != 0) {
                SetFlyingShield__6PlayerFP6Shield(eng, 0);
            }
        } else {
            if (self->m_unk1B8 != 0) {
                if (ApparitionIsValid__15EntityBaseClassFUi((unsigned int)self->m_unk1BC) != 0) {
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

// FUNCTION: 0x001694F0 __ct__6ShieldFv
Shield::Shield() : EntityBaseClass((LoadClass)5, 1) {
    EnableSleep(false, false);
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
