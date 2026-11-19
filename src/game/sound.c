#include "sound.h"

// TODO(header): foreign declarations
extern short IOPCommandData[64];
extern int gSOUND_EEControlReq;
extern int gSOUND_EEControlReqCallCnt;
void SetIOPCommand(int cmd, int count);

static int fst_uEECallCnt;
static int fst_WaitUpdateArray;

// DRAFT: 0x001ADA80 SOUND_MakeStreamTransactionID
// note: flag load goes to $v1 (original $v0) and 0x100 uses $a0; 9 differing lines. Tried reversed decl order, signed char, !init vs init==0, += 1 vs ++; no change.
void SOUND_MakeStreamTransactionID(void) {
    static int st_nextStreamTransactionID;
    static char init;
    if (!init) {
        st_nextStreamTransactionID = 0x100;
        init = 1;
    }
    st_nextStreamTransactionID += 1;
}

// DRAFT: 0x001ADAB0 SOUND_MakeSoundStreamRef
// note: same flag-register difference as the ID function, plus original uses addiu $v1,$v0,1 after reload; 9 differing lines.
void SOUND_MakeSoundStreamRef(void) {
    static int st_nextStreamRef;
    static char init;
    if (!init) {
        st_nextStreamRef = 0x100;
        init = 1;
    }
    st_nextStreamRef += 1;
}

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

// FUNCTION: 0x001ADB30 SOUND_SetChanUse
void SOUND_SetChanUse(short arg0, short arg1, short arg2, short arg3, short arg4) {
    IOPCommandData[2] = arg2;
    IOPCommandData[3] = arg3;
    IOPCommandData[4] = arg4;
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x3A, 5);
}

// DRAFT: 0x001ADBE0 SOUND_EnableFeatures
// note: 11 differing lines; compiler stores index 1 from $a0 before index 0 and drops the original's and/ori 0xFFFF; tried unsigned int args, no (short) cast on index 1, hi local.
void SOUND_EnableFeatures(unsigned int arg0, unsigned int arg1) {
    IOPCommandData[3] = arg1;
    IOPCommandData[0] = (short)(arg0 >> 16);
    IOPCommandData[1] = (short)(arg0 & 0xFFFF);
    IOPCommandData[2] = (short)(arg1 >> 16);
    SetIOPCommand(0x2A, 4);
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

// DRAFT: 0x001ADE20 SOUND_ReverbSetAdrs
// note: same 11-line diff as SOUND_EnableFeatures (store order and dropped and/ori 0xFFFF); no variant reduced it.
void SOUND_ReverbSetAdrs(unsigned int arg0, unsigned int arg1) {
    IOPCommandData[3] = arg1;
    IOPCommandData[0] = (short)(arg0 >> 16);
    IOPCommandData[1] = (short)(arg0 & 0xFFFF);
    IOPCommandData[2] = (short)(arg1 >> 16);
    SetIOPCommand(0x4A, 4);
}

// FUNCTION: 0x001ADE80 SOUND_ChangeReverbCore
void SOUND_ChangeReverbCore(short arg0, short arg1, short arg2, short arg3, short arg4, short arg5) {
    IOPCommandData[2] = arg2;
    IOPCommandData[3] = arg3;
    IOPCommandData[4] = arg4;
    IOPCommandData[5] = arg5;
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x4D, 6);
}

// FUNCTION: 0x001AE3A0 SOUND_SetSPUWriteAddress
void SOUND_SetSPUWriteAddress(unsigned int arg0) {
    IOPCommandData[1] = (short)arg0;
    IOPCommandData[0] = (short)(arg0 >> 16);
    SetIOPCommand(0x0E, 2);
}

// DRAFT: 0x001AE4B0 SOUND_ResumeMultipleSounds
// note: 12 differing words; compiler drops the original's ori $v1,0xFFFF + and mask on index 1 (sh truncates) and the stored size is 0x34 vs 0x3c. Tried signed int, unsigned short cast, mask local, unsigned long args; 12 best.
void SOUND_ResumeMultipleSounds(unsigned int arg0, unsigned int arg1) {
    IOPCommandData[3] = arg1;
    IOPCommandData[0] = (short)(arg0 >> 16);
    IOPCommandData[1] = (short)(arg0 & 0xFFFF);
    IOPCommandData[2] = (short)(arg1 >> 16);
    SetIOPCommand(0x45, 4);
}

// DRAFT: 0x001AE4F0 SOUND_PauseMultipleSounds
// note: 12 differing words; same masked-store shape as SOUND_ResumeMultipleSounds (mask ori/and dropped by compiler).
void SOUND_PauseMultipleSounds(unsigned int arg0, unsigned int arg1) {
    IOPCommandData[3] = arg1;
    IOPCommandData[0] = (short)(arg0 >> 16);
    IOPCommandData[1] = (short)(arg0 & 0xFFFF);
    IOPCommandData[2] = (short)(arg1 >> 16);
    SetIOPCommand(0x44, 4);
}

// DRAFT: 0x001AE530 SOUND_StopMultipleSounds
// note: 12 differing words; same masked-store shape as SOUND_ResumeMultipleSounds (mask ori/and dropped by compiler).
void SOUND_StopMultipleSounds(unsigned int arg0, unsigned int arg1) {
    IOPCommandData[3] = arg1;
    IOPCommandData[0] = (short)(arg0 >> 16);
    IOPCommandData[1] = (short)(arg0 & 0xFFFF);
    IOPCommandData[2] = (short)(arg1 >> 16);
    SetIOPCommand(0x1F, 4);
}

// FUNCTION: 0x001AE5A0 SOUND_StopStream
int SOUND_StopStream(unsigned int arg0) {
    if (arg0 >= 4) {
        return -1;
    }
    IOPCommandData[0] = (short)arg0;
    SetIOPCommand(5, 1);
    return 0;
}
