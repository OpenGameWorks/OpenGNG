#include "sound.h"

// TODO(header): foreign declarations
extern short IOPCommandData[64];
extern int gSOUND_EEControlReq;
extern int gSOUND_EEControlReqCallCnt;
void SetIOPCommand(int cmd, int count);

static int fst_uEECallCnt;
static int fst_WaitUpdateArray;

// FUNCTION: 0x001ADAE0 SOUND_Set_EE_Control
void SOUND_Set_EE_Control(int arg0) {
    int cnt = fst_uEECallCnt;
    gSOUND_EEControlReq = arg0;
    IOPCommandData[0] = (short)arg0;
    gSOUND_EEControlReqCallCnt = cnt;
    SetIOPCommand(0x2E, 1);
}

// FUNCTION: 0x001ADB00 SOUND_InitWaitUpdate
void SOUND_InitWaitUpdate(void) {
    unsigned int addr = (unsigned int)&fst_WaitUpdateArray;
    IOPCommandData[1] = (short)addr;
    IOPCommandData[0] = (short)(addr >> 16);
    SetIOPCommand(0x2D, 2);
}

// FUNCTION: 0x001ADD80 SOUND_FadeMusicStream
void SOUND_FadeMusicStream(short arg0, short arg1, short arg2) {
    IOPCommandData[2] = arg2;
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x1D, 3);
}

// FUNCTION: 0x001ADDF0 SOUND_ChangeReverbMasterVolume
void SOUND_ChangeReverbMasterVolume(short arg0, short arg1, short arg2) {
    IOPCommandData[2] = arg2;
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x4E, 3);
}

// FUNCTION: 0x001AE3A0 SOUND_SetSPUWriteAddress
void SOUND_SetSPUWriteAddress(unsigned int arg0) {
    IOPCommandData[1] = (short)arg0;
    IOPCommandData[0] = (short)(arg0 >> 16);
    SetIOPCommand(0x0E, 2);
}
