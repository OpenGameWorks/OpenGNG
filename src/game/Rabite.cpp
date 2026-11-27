// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Rabite.h"

// TODO(header): foreign declarations
// Only the calls made by Rabite functions are declared; EntityBaseClass is partial here.
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" int RandomIntRange__7MathAPIFii(int nMin, int nMax);
class EntityBaseClass { public: char _pad000[0x8]; int m_unk8; char _pad00C[0x229 - 0x0C]; signed char m_unk229; };
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSequence);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void GetAttachableJoint__6PlayerFPi(void *pThis, int *pJoint);
extern "C" void GetAttachableJointOffsets__6PlayerFiPA4_f(void *pThis, int nJoint, float (*pOffsets)[4]);
extern "C" float RandomFloatRange__7MathAPIFff(float fMin, float fMax);
extern unsigned char __vt__6Rabite[];
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void DetachJoint__6PlayerFi(void *pThis, int nJoint);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);
// Only the m_unk505C slot of EntityManager is used here.
class EntityManager { public: char _pad000[0x505C]; void *m_unk505C; };
extern EntityManager *mpEntMgr__15EntityBaseClass;
// Mesh table sizes are unknown; the placeholders keep these globals out of small data (threshold 8 bytes).
extern unsigned int Rabite_Mesh[4];
extern unsigned int Rabite_Mean_Mesh[4];
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float cosf(float fAngle);
extern "C" float sinf(float fAngle);
extern "C" float acosf(float fValue);
extern "C" float FastMath_Fabs__Ff(float fValue);
// 20 hop offsets of four floats each; the size is a placeholder that keeps this global out of small data.
extern float m_vRabiteOffsets[20][4];
// Execute: the player API pointer is a 4-byte gp-relative global.
extern void *mPlayerAPI__13EntityManager;
extern unsigned char gEng[0x19B90];
extern unsigned char gPad[448];
extern "C" void *GetAttachableJoint__6PlayerFi(void *pThis, int nJoint);
extern "C" void VectorRotateY__7MathAPIFPA4_ff(float (*pMatrix)[4], float fAngle);
extern "C" float Distance__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" int printf(const char *pFormat, ...);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *pThis, int nType, unsigned int nFlags);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int nType, float (*pMatrix)[4]);
extern "C" void SetVibrate__3PadFQ23Pad7VibTypeUc(void *pThis, int nType, unsigned char nCount);
extern "C" void ScaleSet__6PMNodeFffff(void *pThis, float fX, float fY, float fZ, float fW);
extern "C" int PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void StopSoundBySoundRef__15EntityBaseClassFUi(void *pThis, int nSound);
extern "C" void FacePlayer__15EntityBaseClassFf(void *pThis, float fWeight);
extern unsigned int Rabite_Mean_BurrowUp[4];
extern unsigned int Rabite_Attached[4];
extern unsigned int Rabite_Attached2[4];
extern unsigned int Rabite_Mean_Ready[4];
extern unsigned int Rabite_Ready[4];
extern unsigned int Rabite_Hop[4];
extern unsigned int Rabite_Mean_Hop[4];
extern unsigned int Rabite_Transform[4];
extern unsigned int Rabite_Mean_Transform[4];
extern unsigned int Rabite_Hit[4];
extern unsigned int Rabite_Mean_Hit[4];
extern unsigned int Rabite_Mean_HopAttack[4];
extern unsigned int Rabite_BurrowDown[4];
extern unsigned int Rabite_Mean_BurrowDown[4];
extern "C" void RotateTo__15EntityBaseClassFff(void *pThis, float fAngle, float fRate);
extern "C" float GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(void *pThis, float (*pPoint)[4]);
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(float (*pA)[4], float (*pB)[4]);
extern "C" void LoadMesh__15EntityBaseClassFUibb(void *pThis, unsigned int nMesh, bool bA, bool bB);
extern "C" void SpawnBonus__15EntityBaseClassFPfii(void *pThis, float *pPos, int nA, int nB);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nA, char nB, unsigned int nC);
extern unsigned int Rabite_Mean_Death[17];

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("Rabite.cpp", line, #cond))

// FUNCTION: 0x001FB910 GetHealth__6RabiteFv
int Rabite::GetHealth() {
    return m_unk1E0;
}

// FUNCTION: 0x001FB920 GetClassName__6RabiteFv
const char *Rabite::GetClassName() {
    return "Rabite";
}

// FUNCTION: 0x001FB930 GetTallyType__6RabiteFv
int Rabite::GetTallyType() {
    return 1;
}

// FUNCTION: 0x001FB940 GetArenaWaveID__6RabiteFv
int Rabite::GetArenaWaveID() {
    return m_unk1D0;
}

// FUNCTION: 0x001FB950 IsArenaApparition__6RabiteFv
bool Rabite::IsArenaApparition() {
    return m_unk1D0 ? true : false;
}

// FUNCTION: 0x001FB960 NeedsToBeWoken__6RabiteFv
int Rabite::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x1D4);
}

// FUNCTION: 0x001FB970 GetWokenVarPos__6RabiteFv
int Rabite::GetWokenVarPos() {
    return 3;
}

// FUNCTION: 0x001FB980 LoadCorrectMesh__6RabiteFv
void Rabite::LoadCorrectMesh() {
    if (m_unk218 != 0) {
        PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Mesh);
        return;
    }
    PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mesh);
}

// DRAFT: 0x001FB9C0 SetupHopToPoint__6RabiteFv
// note: DIFF 112 words; the first loop is close, but the second loop's mula/madd normalisation and the player-side target are not modelled (m2c could not decode them).
void Rabite::SetupHopToPoint() {
    float fAngle = 0.0f;
    float fRadius = 0.33333334f;
    float v60[4];
    float v70[4];
    int i = 0;
    if (m_vRabiteOffsets[0][0] == 0.0f) {
        do {
            float rad = 0.017453292f * fAngle;
            m_vRabiteOffsets[i][0] = fRadius * cosf(rad);
            m_vRabiteOffsets[i][1] = 0.0f;
            m_vRabiteOffsets[i][2] = fRadius * sinf(rad);
            m_vRabiteOffsets[i][3] = 1.0f;
            fAngle += 60.0f;
            if (!(fAngle <= 360.0f)) {
                fAngle -= 360.0f;
                fRadius += 0.33333334f;
            }
            i++;
        } while (i < 20);
    }
    i = 0;
    do {
        sceVu0ScaleVector(v60, m_vRabiteOffsets[i], m_unk1CC);
        sceVu0AddVector(v60, m_unk1F0, v60);
        float *pTarget = m_unk3C != 0 ? (float *)((char *)m_unk3C + 0x80) : &m_unk190;
        sceVu0SubVector(v70, v60, pTarget);
        float fDot = v70[0] * v60[0] + v70[1] * v60[1] + v70[2] * v60[2];
        float fLen = (v70[0] * v70[0] + v70[1] * v70[1] + v70[2] * v70[2]) *
                     (v60[0] * v60[0] + v60[1] * v60[1] + v60[2] * v60[2]);
        float fDeg = FastMath_Fabs__Ff(57.295776f * acosf(fDot / fLen));
        if (fDeg > 30.0f) {
            m_unk200 = v60[0];
            m_unk204 = v60[1];
            m_unk208 = v60[2];
            return;
        }
        i++;
    } while (i < 20);
}

// FUNCTION: 0x001FBC60 SetEditableVars__6RabiteFPc
void Rabite::SetEditableVars(char *arg0) {
    memcpy((char *)this + 0x1B0, arg0, 0x30);
    if (RandomIntRange__7MathAPIFii(1, 100) & 1) {
        m_unk1E0 = 0x32;
    } else {
        m_unk1E0 = 0x5A;
    }
    m_unk179 = 0;
    m_unk10C &= 0xF8FFFFFF;
    m_unk10C |= 0x031B1902;
    if (m_unk1B0 == 0.0f && m_unk1B4 == 0.0f && m_unk1B8 == 0.0f) {
        CDS_ASSERT(0x36B, !"eif 0, 0, 0 error.  see keith or ted");
        m_unk1B0 = m_unk190;
        m_unk1B4 = m_unk194;
        m_unk1B8 = m_unk198;
    }
    if (m_unk1D0 != 0) {
        m_unk1BC = m_unk18C;
        m_unk1CC = m_unk18C;
    }
    m_unk218 = m_unk1D8 != 0;
}

// FUNCTION: 0x001FBD90 OnWakeEvent__6RabiteFv
void Rabite::OnWakeEvent() {
    if (m_unk20 == 8) {
        SetState__15EntityBaseClassFi(this, 0xE);
    }
}

// FUNCTION: 0x001FBDC0 OnAttackEvent__6RabiteFP15EntityBaseClassi
void Rabite::OnAttackEvent(EntityBaseClass *arg0, int arg1) {
    static float aRandRot;
    static signed char init;
    if (arg0->m_unk8 == 3 && arg1 != 3 && arg0->m_unk229 != 4) {
        GetAttachableJoint__6PlayerFPi(arg0, &m_unk21C);
        if (m_unk21C != -1) {
            SetState__15EntityBaseClassFi(this, 0xC);
            if (init == 0) {
                aRandRot = 90.0f;
                init = 1;
            }
            m_unk220 = RandomFloatRange__7MathAPIFff(-aRandRot, aRandRot);
            GetAttachableJointOffsets__6PlayerFiPA4_f(arg0, m_unk21C, (float (*)[4])m_unk230);
        }
    }
}

// DRAFT: 0x001FBE70 OnHitEvent__6RabiteFP15EntityBaseClassiUiUi
// note: DIFF 31; byte in v0 instead of v1, and the original re-tests m_unk218 at 0x2C. Tried: nested alt-first order (35), byte local with alt-first (32), and locals inside the if (33).
int Rabite::OnHitEvent(EntityBaseClass *pAttacker, int nDamage, unsigned int nA, unsigned int nB) {
    int nState = m_unk20;
    unsigned char bAlt = m_unk218;
    if (m_unk21C == -1) {
        if (bAlt == 0) {
            if (nState == 6 || nState == 5) {
                return 5;
            }
        } else {
            if (nState == 7) {
                return 5;
            }
            m_unk1E0 -= nDamage;
        }
        if (m_unk1E0 > 0) {
            SetState__15EntityBaseClassFi(this, 5);
            return 1;
        }
        SetState__15EntityBaseClassFi(this, 0xA);
        return 2;
    }
    return 0;
}

// DRAFT: 0x001FBF20 Execute__6RabiteFv
// note: all switch cases transcribed; size 0xE98 vs 0xDE4, DIFF 907 words. Default return moved last. Original shares one epilogue at 0xDD0; ours duplicates it after case 10. Prologue delay slot (nop vs lui) and static gp offsets also differ. Tried: case -2 label, local float temp, !init, case 10 return.
void Rabite::Execute() {
    static float SCALESCALESCALE;
    static signed char init;
    float vPos[4];
    float vJoint[4];
    float vOff[4];
    void *pPlayer;
    void *pSrc;
    void *pJoint;

    if (m_unk3C != 0) {
        if (init == 0) {
            SCALESCALESCALE = 0.75f;
            init = 1;
        }
        ScaleSet__6PMNodeFffff(m_unk3C, SCALESCALESCALE, SCALESCALESCALE, SCALESCALESCALE, 1.0f);
    }
    if (m_unk21C != -1) {
        pPlayer = mPlayerAPI__13EntityManager;
        if (*(void **)((char *)pPlayer + 0x3C) != 0) {
            pSrc = (char *)*(void **)((char *)pPlayer + 0x3C) + 0x90;
        } else {
            pSrc = (char *)pPlayer + 0x1A0;
        }
        *(u_long128 *)vPos = *(u_long128 *)pSrc;
        pJoint = GetAttachableJoint__6PlayerFi(mpEntMgr__15EntityBaseClass->m_unk505C, m_unk21C);
        if (pJoint == 0) {
            m_unk21C = -1;
            SetState__15EntityBaseClassFi(this, 5);
            PlaySound__15EntityBaseClassFUi(this, 0x1AD);
            StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk214);
        } else {
            *(u_long128 *)vJoint = *(u_long128 *)((char *)pJoint + 0x70);
            if (m_unk230[1] != 0.0f) {
                vOff[0] = 0.0f;
                vOff[1] = 0.0f;
                vOff[2] = m_unk230[1];
                VectorRotateY__7MathAPIFPA4_ff((float (*)[4])vOff, vPos[1]);
                sceVu0AddVector(vJoint, vJoint, vOff);
            }
            vJoint[1] += m_unk230[0];
            if (m_unk3C != 0) {
                *(u_long128 *)((char *)m_unk3C + 0x80) = *(u_long128 *)vJoint;
                *((unsigned char *)m_unk3C + 0x3E) |= 8;
            } else {
                *(u_long128 *)&m_unk190 = *(u_long128 *)vJoint;
            }
            vPos[1] += m_unk220 + m_unk230[2];
            if (m_unk3C != 0) {
                *(u_long128 *)((char *)m_unk3C + 0x90) = *(u_long128 *)vPos;
                *((unsigned char *)m_unk3C + 0x3E) |= 8;
            } else {
                *(u_long128 *)m_unk1A0 = *(u_long128 *)vPos;
            }
            if (m_unk240 != 0) {
                m_unk240 = (int)((float)m_unk240 - *(float *)(gEng + 0x1E8));
                if (m_unk240 < 0) {
                    m_unk240 = 0;
                }
            }
            if (m_unk240 == 0) {
                m_unk240 = 0x1E;
                SetVibrate__3PadFQ23Pad7VibTypeUc(&gPad, 1, 0xA);
            }
        }
    }
    switch (m_unk20) {
    case -1:
        if (m_unkE9 != 0) {
            m_unk1F0[0] = m_unk1C0[0];
            m_unk1F0[1] = m_unk1C0[1];
            m_unk1F0[2] = m_unk1C0[2];
            m_unk200 = m_unk1B0;
            m_unk204 = m_unk1B4;
            m_unk208 = m_unk1B8;
        }
        {
            float *pFrom = &m_unk190;
            if (m_unk3C != 0) {
                pFrom = (float *)((char *)m_unk3C + 0x80);
            }
            if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pFrom, (float (*)[4])m_unk1F0) <= m_unk1CC)) {
                printf("ERROR - Rabite shutdown as initial position wasn't inside attack radius\n");
                SetState__15EntityBaseClassFi(this, -2);
                return;
            }
        }
        {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])&m_unk200, (float (*)[4])pPos) <= m_unk1BC) {
                if (m_unkD4 == 0) {
                    void *pShadow = __nw__FUi(0x10);
                    if (pShadow != 0) {
                        pShadow = __ct__6ShadowFQ26Shadow10ShadowTypeUi(pShadow, 1, 0x87000006);
                    }
                    m_unkD4 = pShadow;
                    if (m_unkD4 == 0) {
                        CdsAssert("Rabite.cpp", 0x157, "mpShadow");
                    }
                }
                {
                    void *pShadow = m_unkD4;
                    if (pShadow != 0) {
                        *(int *)pShadow = 1;
                        void *pSub = *(void **)((char *)pShadow + 0xC);
                        if (pSub != 0) {
                            *(int *)((char *)pSub + 0x18) = 1;
                        }
                    }
                }
                if (m_unk38 == 0) {
                    void *pPhys = __nw__FUi(0x120);
                    if (pPhys != 0) {
                        pPhys = __ct__7PhysicsFv(pPhys);
                    }
                    m_unk38 = pPhys;
                    if (m_unk38 == 0) {
                        CdsAssert("Rabite.cpp", 0x15E, "mpPhysics");
                    }
                    SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
                }
                SetState__15EntityBaseClassFi(this, 9);
                return;
            }
        }
        return;
    case 9:
        if (m_unkE9 != 0) {
            FacePlayer__15EntityBaseClassFf(this, 1.0f);
            LoadCorrectMesh();
            PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_BurrowUp);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 0);
            return;
        }
        break;
    case 12:
        if (m_unkE9 != 0) {
            if (*(float *)((char *)this + 0x23C) != 0.0f) {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Attached2);
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Attached);
            }
            m_unk214 = PlaySound__15EntityBaseClassFUi(this, 0x1C9U);
        }
        {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pPos) <= m_unk1CC)) {
                void *pAttached = mpEntMgr__15EntityBaseClass->m_unk505C;
                if (pAttached != 0) {
                    DetachJoint__6PlayerFi(pAttached, m_unk21C);
                    m_unk21C = -1;
                    SetState__15EntityBaseClassFi(this, 5);
                    StopSoundBySoundRef__15EntityBaseClassFUi(this, m_unk214);
                    return;
                }
            }
        }
        break;
    case 0: {
        float fDist;
        LoadCorrectMesh();
        {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            fDist = Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pPos);
        }
        if (m_unk218 != 0) {
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Ready);
            }
            if (fDist <= m_unk1CC) {
                SetState__15EntityBaseClassFi(this, 3);
            } else {
                float *pFrom = &m_unk190;
                if (m_unk3C != 0) {
                    pFrom = (float *)((char *)m_unk3C + 0x80);
                }
                if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pFrom) <= m_unk1CC)) {
                    SetState__15EntityBaseClassFi(this, 0xD);
                } else {
                    SetState__15EntityBaseClassFi(this, 8);
                }
            }
        } else {
            if (m_unkE9 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Ready);
            }
            if (fDist <= m_unk1CC) {
                SetState__15EntityBaseClassFi(this, 2);
            } else {
                float *pFrom = &m_unk190;
                if (m_unk3C != 0) {
                    pFrom = (float *)((char *)m_unk3C + 0x80);
                }
                if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pFrom) <= m_unk1CC)) {
                    SetState__15EntityBaseClassFi(this, 0xD);
                }
            }
        }
        FacePlayer__15EntityBaseClassFf(this, 0.4f);
        return;
    }
    case 13:
        if (m_unkE9 != 0) {
            if (m_unk218 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Hop);
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Hop);
            }
        }
        if (((signed char)(*((unsigned char *)m_unk3C + 0x3F) & 7)) & 4) {
            if (m_unk218 != 0) {
                PlaySound__15EntityBaseClassFUi(this, 0x4E51U);
            } else {
                PlaySound__15EntityBaseClassFUi(this, 0xEU);
            }
        }
        RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])m_unk1F0), 0.4f);
        if (m_unk218 != 0) {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPlayerPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            float *pThisPos = &m_unk190;
            if (m_unk3C != 0) {
                pThisPos = (float *)((char *)m_unk3C + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pThisPos, (float (*)[4])pPlayerPos) <= 3.0f) {
                SetState__15EntityBaseClassFi(this, 4);
                return;
            }
        }
        {
            float *pThisPos = &m_unk190;
            if (m_unk3C != 0) {
                pThisPos = (float *)((char *)m_unk3C + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pThisPos) <= m_unk1CC) {
                SetState__15EntityBaseClassFi(this, 0);
            }
        }
        {
            float *pThisPos = &m_unk190;
            if (m_unk3C != 0) {
                pThisPos = (float *)((char *)m_unk3C + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pThisPos, (float (*)[4])m_unk1F0) < 3.0f) {
                SetState__15EntityBaseClassFi(this, 0);
                return;
            }
        }
        break;
    case 3:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Hop);
        }
        if (((signed char)(*((unsigned char *)m_unk3C + 0x3F) & 7)) & 4) {
            PlaySound__15EntityBaseClassFUi(this, 0x4E51U);
        }
        FacePlayer__15EntityBaseClassFf(this, 0.4f);
        {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPlayerPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayerPos, (float (*)[4])m_unk1F0) <= m_unk1CC)) {
                SetState__15EntityBaseClassFi(this, 0);
            }
        }
        {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPlayerPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            float *pThisPos = &m_unk190;
            if (m_unk3C != 0) {
                pThisPos = (float *)((char *)m_unk3C + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pThisPos, (float (*)[4])pPlayerPos) <= 3.0f) {
                SetState__15EntityBaseClassFi(this, 4);
                return;
            }
        }
        break;
    case 2:
        if (m_unkE9 != 0) {
            m_unk218 = 0;
            SetupHopToPoint();
            PlaySequence__15EntityBaseClassFPUi(this, Rabite_Hop);
        }
        if (((signed char)(*((unsigned char *)m_unk3C + 0x3F) & 7)) & 4) {
            if (m_unk218 != 0) {
                PlaySound__15EntityBaseClassFUi(this, 0x4E51U);
            } else {
                PlaySound__15EntityBaseClassFUi(this, 0xEU);
            }
        }
        RotateTo__15EntityBaseClassFff(this, GetAngleYToPoint__7MathAPIFP15EntityBaseClassPA4_f(this, (float (*)[4])&m_unk200), 0.04f);
        {
            float *pThisPos = &m_unk190;
            if (m_unk3C != 0) {
                pThisPos = (float *)((char *)m_unk3C + 0x80);
            }
            if (DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])pThisPos, (float (*)[4])&m_unk200) <= 2.0f) {
                SetupHopToPoint();
                return;
            }
        }
        {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPlayerPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            if (DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])&m_unk200, (float (*)[4])pPlayerPos) < 10.0f) {
                SetupHopToPoint();
                return;
            }
        }
        {
            void *pPlayer = mPlayerAPI__13EntityManager;
            float *pPlayerPos = (float *)((char *)pPlayer + 0x190);
            if (*(void **)((char *)pPlayer + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)pPlayer + 0x3C) + 0x80);
            }
            if (!(DistanceXZ__7MathAPIFPA4_fPA4_f((float (*)[4])m_unk1F0, (float (*)[4])pPlayerPos) <= (1.1f * m_unk1CC))) {
                SetState__15EntityBaseClassFi(this, 0);
                return;
            }
        }
        if ((((signed char)(*((unsigned char *)m_unk3C + 0x3F) & 7)) & 4) && (*(int *)((char *)m_unk38 + 0xE4) != 0)) {
            SetupHopToPoint();
            return;
        }
        break;
    case 6:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, Rabite_Transform);
            m_unk103 = 0xFE;
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 7);
            return;
        }
        break;
    case 7:
        if (m_unkE9 != 0) {
            m_unk218 = 1;
            LoadCorrectMesh();
            PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Transform);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, 3);
            m_unk103 = 0x10;
            return;
        }
        break;
    case 5:
        if (m_unkE9 != 0) {
            FacePlayer__15EntityBaseClassFf(this, 1.0f);
            if (m_unk218 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Hit);
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Hit);
            }
        }
        if (m_unk160 == 0) {
            if (m_unk218 != 0) {
                SetState__15EntityBaseClassFi(this, 0);
                return;
            }
            SetState__15EntityBaseClassFi(this, 6);
            return;
        }
        break;
    case 4:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_HopAttack);
            FacePlayer__15EntityBaseClassFf(this, 0.4f);
        }
        if (m_unk160 == 0) {
            float *pPlayerPos = (float *)((char *)mPlayerAPI__13EntityManager + 0x190);
            if (*(void **)((char *)mPlayerAPI__13EntityManager + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)mPlayerAPI__13EntityManager + 0x3C) + 0x80);
            }
            if (!(Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayerPos, (float (*)[4])m_unk1F0) <= m_unk1CC)) {
                SetState__15EntityBaseClassFi(this, 0);
                return;
            }
            SetState__15EntityBaseClassFi(this, 3);
            return;
        }
        break;
    case 8:
        if (m_unkE9 != 0) {
            if (m_unk218 != 0) {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_BurrowDown);
            } else {
                PlaySequence__15EntityBaseClassFPUi(this, Rabite_BurrowDown);
            }
        }
        if (m_unk160 == 0) {
            void *pShadow = m_unkD4;
            if (pShadow != 0) {
                *(int *)pShadow = 0;
                void *pSub = *(void **)((char *)pShadow + 0xC);
                if (pSub != 0) {
                    *(int *)((char *)pSub + 0x18) = 0;
                }
            }
            float *pPlayerPos = (float *)((char *)mPlayerAPI__13EntityManager + 0x190);
            if (*(void **)((char *)mPlayerAPI__13EntityManager + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)mPlayerAPI__13EntityManager + 0x3C) + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayerPos, (float (*)[4])m_unk1F0) < m_unk1CC) {
                SetState__15EntityBaseClassFi(this, 9);
                return;
            }
        }
        break;
    case 14:
        {
            float *pPlayerPos = (float *)((char *)mPlayerAPI__13EntityManager + 0x190);
            if (*(void **)((char *)mPlayerAPI__13EntityManager + 0x3C) != 0) {
                pPlayerPos = (float *)((char *)*(void **)((char *)mPlayerAPI__13EntityManager + 0x3C) + 0x80);
            }
            if (Distance__7MathAPIFPA4_fPA4_f((float (*)[4])pPlayerPos, (float (*)[4])m_unk1F0) < m_unk1CC) {
                LoadCorrectMesh();
                SetState__15EntityBaseClassFi(this, 9);
                return;
            }
        }
        if (m_unk3C != 0) {
            LoadMesh__15EntityBaseClassFUibb(this, 0, 0, 1);
            return;
        }
        break;
    case 10:
        if (m_unkE9 != 0) {
            static float BonusPos[4] = {0.0f, 2.0f, 0.0f, 1.0f};
            m_unk10C &= 0xF8FFFFFF;
            void *pShadow = m_unkD4;
            if (pShadow != 0) {
                *(int *)pShadow = 0;
                void *pSub = *(void **)((char *)pShadow + 0xC);
                if (pSub != 0) {
                    *(int *)((char *)pSub + 0x18) = 0;
                }
            }
            PlaySequence__15EntityBaseClassFPUi(this, Rabite_Mean_Death);
            SpawnBonus__15EntityBaseClassFPfii(this, BonusPos, 1, 1);
            WriteApparitionData__15EntityBaseClassFicUi(this, 1, -3, 0);
            WriteApparitionData__15EntityBaseClassFicUi(this, 0, 1, 0);
        }
        if (m_unk160 == 0) {
            SetState__15EntityBaseClassFi(this, -2);
        }
        break;
    default:
        return;
    }
}

// FUNCTION: 0x001FCD10 __dt__6RabiteFv
extern "C" void *__dt__6RabiteFv(Rabite *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__6Rabite;
        if (pThis->m_unk21C != -1) {
            void *pPlayer = mpEntMgr__15EntityBaseClass->m_unk505C;
            if (pPlayer != 0) {
                DetachJoint__6PlayerFi(pPlayer, pThis->m_unk21C);
                pThis->m_unk21C = -1;
            }
        }
        pThis->m_unk240 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001FCDB0 __ct__6RabiteFv
Rabite::Rabite() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 3, 5);
    m_unk0 = __vt__6Rabite;
    m_unk21C = -1;
    m_unkF8 = 0.3f;
    m_unkFC = 0.6f;
    m_unk103 = 0x10;
    m_unk15C = 0;
    m_unk15E = 0x100C;
    m_unkEA = 0;
    m_unk104 = 0.5f;
    m_unk108 = 1.0f;
}
