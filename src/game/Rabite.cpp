// FLAGS: -str readonly
#include "types.h"
#include "Rabite.h"

// TODO(header): foreign declarations
// Only the calls made by Rabite functions are declared; EntityBaseClass is partial here.
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" int RandomIntRange__7MathAPIFii(int nMin, int nMax);
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
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

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Rabite.cpp", line, #cond))

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
