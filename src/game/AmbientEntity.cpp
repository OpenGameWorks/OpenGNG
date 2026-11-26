// FLAGS: -str readonly
#include "types.h"
#include "AmbientEntity.h"

#include "EntityManager.h"
#include "TimerAPI.h"
#include "Camera.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern "C" void sceVu0UnitMatrix(float (*m)[4]);
extern "C" void sceVu0SubVector(float *v0, float *v1, float *v2);
extern "C" void sceVu0AddVector(float *v0, float *v1, float *v2);
extern "C" void sceVu0ScaleVector(float *v0, float *v1, float s);
extern "C" float sceVu0InnerProduct(float *v0, float *v1);
extern "C" float sinf(float x);
extern "C" float sqrtf(float x);
extern "C" float atan2f(float y, float x);
extern "C" float Round180__Ff(float f);
extern unsigned int AmbientZinShell_InitShellSeq[];
extern char gEng[];
class MathAPI {
public:
    static float RandomFloatRange(float fMin, float fMax);
};

// FUNCTION: 0x001BF1D0 __dt__13AmbientEntityFv
AmbientEntity::~AmbientEntity() {
}

// FUNCTION: 0x001BF230 GetClassName__13AmbientEntityFv
const char *AmbientEntity::GetClassName() {
    return "AmbientEntity";
}

// FUNCTION: 0x001BF240 SetEditableVars__13AmbientEntityFPc
void AmbientEntity::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0x4);
}

// FUNCTION: 0x001BF250 OnTimerEvent__13AmbientEntityFUi
void AmbientEntity::OnTimerEvent(unsigned int nTimer) {
    if (nTimer == m_unk1F0) {
        SetState(1);
    }
}

// FUNCTION: 0x001BF280 OnHitEvent__13AmbientEntityFP15EntityBaseClassiUiUi
void AmbientEntity::OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int) {
}

// FUNCTION: 0x001BF290 OnTouchEvent__13AmbientEntityFP15EntityBaseClass
void AmbientEntity::OnTouchEvent(EntityBaseClass *) {
}

// FUNCTION: 0x001BF2A0 Execute__13AmbientEntityFv
void AmbientEntity::Execute() {
    switch (m_unk20) {
    case -1:
        SetState(0);
        break;
    case 0:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            m_unk1F0 = EntityManager::mTimerAPI.CreateTimer(m_unk04, (unsigned int)m_unk1B0, false);
        }
        break;
    case 1:
        if (*(unsigned char *)((char *)this + 0xE9) != 0) {
            PlaySequence(AmbientZinShell_InitShellSeq);
            Camera *pCam = (Camera *)(gEng + 0x19760);
            float fwd[4];
            pCam->GetForwardVector(fwd);
            float fX = 170.0f * fwd[0] + pCam->m_unk00[0];
            float fZ = 170.0f * fwd[2] + pCam->m_unk00[2];
            float mat[4][4];
            sceVu0UnitMatrix(mat);
            sceVu0CopyMatrix(mat, pCam->m_unk30);
            float fFar = 150.0f;
            float fNear = 50.0f;
            float fRightX = -mat[0][0];
            float fRightZ = -mat[2][0];
            m_unk1E0[0] = fX + fRightX * MathAPI::RandomFloatRange(fNear, fFar);
            m_unk1E0[1] = 10.0f - MathAPI::RandomFloatRange(10.0f, 20.0f);
            m_unk1E0[2] = fZ + fRightZ * MathAPI::RandomFloatRange(fNear, fFar);
            float end[4];
            end[0] = fX - fRightX * MathAPI::RandomFloatRange(fNear, fFar);
            end[1] = -30.0f - MathAPI::RandomFloatRange(10.0f, 20.0f);
            end[2] = fZ - fRightZ * MathAPI::RandomFloatRange(fNear, fFar);
            sceVu0SubVector(m_unk1C0, end, m_unk1E0);
            m_unk1D0 = 0.01f;
            m_unk1D4 = sqrtf(sceVu0InnerProduct(m_unk1C0, m_unk1C0)) / 2.0f;
            m_unk1D8 = 0.0005f + MathAPI::RandomFloatRange(0.0005f, 0.001f);
            char *pNode = m_unk3C;
            *(u_long128 *)(pNode + 0x80) = *(u_long128 *)m_unk1E0;
            *(unsigned char *)(pNode + 0x3E) |= 8;
        }
        m_unk1D8 *= 1.02f;
        if (!(m_unk1D8 <= 0.02f)) {
            m_unk1D8 = 0.02f;
        }
        float fDt = *(float *)(gEng + 0x1E8);
        m_unk1D0 += m_unk1D8 * fDt;
        if (m_unk1D0 <= 1.0f) {
            float step[4];
            float pos[4];
            sceVu0ScaleVector(step, m_unk1C0, m_unk1D0);
            sceVu0AddVector(pos, m_unk1E0, step);
            pos[1] += m_unk1D4 * sinf(0.017453292f * (180.0f * m_unk1D0));
            sceVu0SubVector(step, pos, (float *)(m_unk3C + 0x80));
            if (step[0] != 0.0f || step[2] != 0.0f) {
                float rot[4];
                rot[0] = 57.295776f * atan2f(-step[1], -sqrtf(step[0] * step[0] + step[2] * step[2]));
                rot[0] = rot[0] - 90.0f;
                rot[1] = 57.295776f * (3.1415927f + atan2f(step[0], step[2]));
                rot[2] = 0.0f;
                Round180__Ff(rot[0]);
                Round180__Ff(rot[1]);
                char *pRotNode = m_unk3C;
                *(u_long128 *)(pRotNode + 0x90) = *(u_long128 *)rot;
                *(unsigned char *)(pRotNode + 0x3E) |= 8;
            }
            char *pPosNode = m_unk3C;
            *(u_long128 *)(pPosNode + 0x80) = *(u_long128 *)pos;
            *(unsigned char *)(pPosNode + 0x3E) |= 8;
        } else {
            SetState(0);
        }
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x001BF750 __ct__13AmbientEntityFv
AmbientEntity::AmbientEntity() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
