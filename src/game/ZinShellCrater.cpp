// FLAGS: -str readonly
#include "types.h"
#include "ZinShellCrater.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);
extern unsigned int ZinShellCrater_InitSeq[0xD];
extern unsigned int ZinShellCrater_FadeSeq[0x5];
extern char mTimerAPI__13EntityManager[0x28];
extern "C" int CreateTimer__8TimerAPIFUiUib(void *pThis, unsigned int nId, unsigned int nTime, bool bPal);
extern "C" void GetGroundPos__7MathAPIFPA4_f(float (*pPos)[4]); // static MathAPI::GetGroundPos

// FUNCTION: 0x001C8910 __dt__14ZinShellCraterFv
ZinShellCrater::~ZinShellCrater() {
}

// FUNCTION: 0x001C8970 GetClassName__14ZinShellCraterFv
const char *ZinShellCrater::GetClassName() {
    return "ZinShellCrater";
}

// FUNCTION: 0x001C8980 SetEditableVars__14ZinShellCraterFPc
void ZinShellCrater::SetEditableVars(char *pSrc) {
    memcpy(m_unk1B0, pSrc, 0x1);
}

// FUNCTION: 0x001C89A0 OnHitEvent__14ZinShellCraterFP15EntityBaseClassiUiUi
int ZinShellCrater::OnHitEvent(EntityBaseClass *, int, unsigned int, unsigned int) {
    return 0;
}

// FUNCTION: 0x001C89B0 Execute__14ZinShellCraterFv
void ZinShellCrater::Execute() {
    switch (m_unk20) {
    case -1:
        SetState(0);
        return;
    case 0:
        if (*((unsigned char *)this + 0xE9)) {
            CreateTimer__8TimerAPIFUiUib(mTimerAPI__13EntityManager, m_unk04, 6, false);
            void *pPos = (void *)m_unk190;
            if (m_unk3C != 0) {
                pPos = m_unk3C + 0x80;
            }
            GetGroundPos__7MathAPIFPA4_f((float (*)[4])pPos);
            PlaySequence(ZinShellCrater_InitSeq);
            return;
        }
        break;
    case 1:
        if (*((unsigned char *)this + 0xE9)) {
            PlaySequence(ZinShellCrater_FadeSeq);
        }
        // The original tests the flag as (flag != 0) ^ 1: sltu then xori.
        if ((m_unk160 != 0) ^ 1) {
            SetState(-2);
        }
        break;
    case -2:
        break;
    }
}

// FUNCTION: 0x001C8AA0 __ct__14ZinShellCraterFv
ZinShellCrater::ZinShellCrater() : EntityBaseClass((LoadClass)5, 0) {}
