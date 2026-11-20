#include "types.h"
#include "ClockworkStinger.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern char ClockworkStinger_HitSpinSeq[];
extern char ClockworkStinger_HitFlippedSeq[];
extern char ClockworkStinger_StruggleUpSeq[];
extern char ClockworkStinger_HitLaunchSeq[];
extern char ClockworkStinger_HitJuggleSeq[];
extern char ClockworkStinger_HitJuggleFinalSeq[];
class TimerAPI {
public:
    char _pad000[40];
    void KillTimer(unsigned int);
    int CreateTimer(unsigned int, unsigned int, bool);
};
extern TimerAPI mTimerAPI__13EntityManager;
extern "C" void DestroyDamageFx__15EntityBaseClassFUi(void *, unsigned int);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern unsigned char __vt__16ClockworkStinger[];
extern int miRandom__7MathAPI;
extern "C" void *memcpy(void *, const void *, unsigned int);
class MathAPI;
extern "C" float DistanceXZ__7MathAPIFPA4_fPA4_f(MathAPI *, float (*)[4]);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int nLoadClass, unsigned int nFlags);

// FUNCTION: 0x001E6500 GetSequenceState__16ClockworkStingerFv
int ClockworkStinger::GetSequenceState() {
    int result = 0;
    if (m_unk140 == (unsigned int *)ClockworkStinger_HitSpinSeq ||
        m_unk140 == (unsigned int *)ClockworkStinger_HitFlippedSeq ||
        (m_unk140 == (unsigned int *)ClockworkStinger_StruggleUpSeq && m_unk3C->GetFrameTime() <= 12.0f) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitLaunchSeq && !(m_unk3C->GetFrameTime() < 28.0f)) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitJuggleSeq && !(m_unk3C->GetFrameTime() < 18.0f)) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitJuggleFinalSeq && !(m_unk3C->GetFrameTime() < 28.0f))) {
        result |= 1;
    }
    if ((m_unk140 == (unsigned int *)ClockworkStinger_HitLaunchSeq && m_unk3C->GetFrameTime() <= 27.0f &&
         !(m_unk3C->GetFrameTime() < 2.0f)) ||
        (m_unk140 == (unsigned int *)ClockworkStinger_HitJuggleSeq && m_unk3C->GetFrameTime() <= 17.0f)) {
        result |= 2;
    }
    return result;
}

// FUNCTION: 0x001E66D0 IsStalled__16ClockworkStingerFfPA4_f
int ClockworkStinger::IsStalled(float arg0, float (*arg1)[4]) {
    MathAPI *pRef;
    float d1;
    float d2;
    if (m_unk3C != 0) {
        pRef = (MathAPI *)((char *)m_unk3C + 0x80);
    } else {
        pRef = (MathAPI *)((char *)this + 0x190);
    }
    d1 = DistanceXZ__7MathAPIFPA4_fPA4_f((MathAPI *)((char *)this + 0x220), arg1);
    d2 = DistanceXZ__7MathAPIFPA4_fPA4_f(pRef, arg1);
    return (FastMath_Fabs__Ff(d1 - d2) <= arg0) ? 1 : 0;
}

// FUNCTION: 0x001E6BA0 SetRiseAndAttack__16ClockworkStingerFPA4_fff
void ClockworkStinger::SetRiseAndAttack(float (*arg0)[4], float arg1, float arg2) {
    m_unk1B8 = arg0[0][0];
    m_unk1BC = arg0[0][1];
    m_unk1C0 = arg0[0][2];
    m_unk1C8 = arg0[0][0];
    m_unk1CC = arg0[0][1];
    m_unk1D0 = arg0[0][2];
    m_unk1C4 = arg1;
    m_unk1D4 = arg2;
}

// FUNCTION: 0x001E6BE0 SetSpawnedFromEntity__16ClockworkStingerFPfPfi
void ClockworkStinger::SetSpawnedFromEntity(float *arg0, float *arg1, int arg2) {
    char *pDst;
    m_unk1C8 = arg0[0];
    m_unk1CC = arg0[1];
    m_unk1D0 = arg0[2];
    *(int *)&m_unk1D4 = 0x43160000;
    miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
    m_unk1FC = !(miRandom__7MathAPI & 1) ? 0xB4 : 0x6E;
    *(int *)&m_unk1C4 = 0x42960000;
    m_unk1B0 = 0;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1D8 = 0;
    *(int *)&m_unk1F8 = 0x3DCCCCCD;
    m_unk1F4 = 0;
    if (m_unk3C != 0) {
        pDst = (char *)m_unk3C + 0x80;
    } else {
        pDst = (char *)this + 0x190;
    }
    *(u_long128 *)pDst = *(u_long128 *)arg0;
    if (arg1 != 0) {
        if (m_unk3C != 0) {
            pDst = (char *)m_unk3C + 0x90;
        } else {
            pDst = (char *)this + 0x1A0;
        }
        *(u_long128 *)pDst = *(u_long128 *)arg1;
    }
}

// FUNCTION: 0x001E6CB0 SetDefaultVars__16ClockworkStingerFv
void ClockworkStinger::SetDefaultVars() {
    miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
    m_unk1FC = !(miRandom__7MathAPI & 1) ? 0xB4 : 0x6E;
    *(int *)&m_unk1C4 = 0x41C80000;
    *(int *)&m_unk1D4 = 0x420C0000;
    m_unk1B0 = 0;
    m_unk1E0 = 0;
    m_unk1E4 = 0;
    m_unk1E8 = 0;
    m_unk1EC = 0;
    m_unk1D8 = 0;
    m_unk1F8 = 0x3DCCCCCD;
    m_unk1F4 = 0;
}

// FUNCTION: 0x001E6D30 SetEditableVars__16ClockworkStingerFPc
void ClockworkStinger::SetEditableVars(char *arg0) {
    memcpy(&m_unk1B0, arg0, 0x4C);
    if (m_unk1B0 == 0) {
        miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
        m_unk1FC = !(miRandom__7MathAPI & 1) ? 0xB4 : 0x6E;
    } else {
        miRandom__7MathAPI = (miRandom__7MathAPI * 0x343FD) + 0x269EC3;
        m_unk1FC = !(miRandom__7MathAPI & 1) ? 0x78 : 0x64;
    }
}

// FUNCTION: 0x001E6DE0 OnStopAttack__16ClockworkStingerFv
void ClockworkStinger::OnStopAttack() {
    if ((m_unk1B0 == 0) && (m_unk20 != 4)) {
        m_unk258 = mTimerAPI__13EntityManager.CreateTimer(m_unk4, 2, false);
        SetState__15EntityBaseClassFi(this, 4);
    }
}

// FUNCTION: 0x001E6E40 OnTimerEvent__16ClockworkStingerFUi
void ClockworkStinger::OnTimerEvent(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk240) {
        m_unk240 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk254) {
        m_unk254 = 0;
        return;
    }
    if (arg0 == (unsigned int)m_unk258) {
        m_unk258 = 0;
    }
}

// FUNCTION: 0x001E8CF0 __dt__16ClockworkStingerFv
extern "C" ClockworkStinger *__dt__16ClockworkStingerFv(ClockworkStinger *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__16ClockworkStinger;
        DestroyDamageFx__15EntityBaseClassFUi(pThis, pThis->m_unk250);
        pThis->m_unk250 = 0;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001E8D60 __ct__16ClockworkStingerFv
extern "C" ClockworkStinger *__ct__16ClockworkStingerFv(ClockworkStinger *pThis) {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(pThis, 3, 0xA);
    *(unsigned char **)pThis = __vt__16ClockworkStinger;
    pThis->m_unk200 = 0;
    pThis->m_unk204 = 0;
    pThis->m_unk208 = 0;
    pThis->m_unk20C = 0;
    pThis->m_unk210 = 0;
    pThis->m_unk214 = 0;
    pThis->m_unk218 = 0;
    pThis->m_unk21C = 0;
    pThis->m_unk220 = 0;
    pThis->m_unk224 = 0;
    pThis->m_unk228 = 0;
    pThis->m_unk22C = 0;
    pThis->m_unk230 = 0;
    pThis->m_unk234 = 0;
    pThis->m_unk238 = 0;
    pThis->m_unk23C = 0;
    pThis->m_unk240 = 0;
    pThis->m_unk244 = 0;
    pThis->m_unk248 = 0;
    pThis->m_unk24C = 0;
    pThis->m_unk250 = 0;
    pThis->m_unk254 = 0;
    pThis->m_unk258 = 0;
    pThis->m_unk25C = 0;
    pThis->m_unk260 = 0;
    pThis->m_unk264 = 0;
    pThis->m_unk268 = 0;
    pThis->m_unk103 = 0x10;
    pThis->m_unk104 = 0x40000000;
    pThis->m_unk108 = 0x3FC00000;
    pThis->m_unk166 = 1;
    return pThis;
}
