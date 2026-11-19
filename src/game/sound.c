#include "sound.h"

// TODO(header): foreign declarations
extern short IOPCommandData[64];
extern int gSOUND_EEControlReq;
extern int gSOUND_EEControlReqCallCnt;
extern char SOUND_SPUKeyStatus[0x40];
void SetIOPCommand(int cmd, int count);
extern char gCd[0x40];
int sceSifInitRpc(int mode);
int sceSifBindRpc(void *client, unsigned int rpc_number, int mode);
int printf(const char *fmt, ...);

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

// FUNCTION: 0x001ADB70 SOUND_SetGlobalRelVols
void SOUND_SetGlobalRelVols(short arg0, short arg1, short arg2, short arg3, short arg4, short arg5, short arg6, short arg7) {
    IOPCommandData[2] = arg2;
    IOPCommandData[3] = arg3;
    IOPCommandData[4] = arg4;
    IOPCommandData[5] = arg5;
    IOPCommandData[6] = arg6;
    IOPCommandData[7] = arg7;
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x39, 8);
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

// DRAFT: 0x001ADC60 SOUND_LevelRestart
// note: 23 differing lines; frame and call match, but first-loop base is lui $a0 vs original lui $v1 (+addiu 0x3E50), pointer in $a2 vs $a0, loop test in $v1 vs $at, and second loop stores before addiu. Tried indexed stores (23), p = &arr[i] with mid-block increment (23 with reordered tail), and i += 1 ahead of the store.
void SOUND_LevelRestart(void) {
    int i;
    char *p;
    SetIOPCommand(0x24, 0);
    i = 6;
    do {
        SOUND_SPUKeyStatus[i + 0] = 0;
        SOUND_SPUKeyStatus[i + 1] = 0;
        SOUND_SPUKeyStatus[i + 2] = 0;
        SOUND_SPUKeyStatus[i + 3] = 0;
        SOUND_SPUKeyStatus[i + 4] = 0;
        SOUND_SPUKeyStatus[i + 5] = 0;
        SOUND_SPUKeyStatus[i + 6] = 0;
        SOUND_SPUKeyStatus[i + 7] = 0;
        i += 8;
    } while (i < 8);
    if (i < 0x10) {
        do {
            p = &SOUND_SPUKeyStatus[i];
            i += 1;
            *p = 0;
        } while (i < 0x10);
    }
}

// DRAFT: 0x001ADCF0 SOUND_StopAllSounds
// note: 23 differing lines; same loop shape and same register-allocation gap as SOUND_LevelRestart (base in $a0 vs $v1, pointer in $a2 vs $a0).
void SOUND_StopAllSounds(void) {
    int i;
    char *p;
    SetIOPCommand(0x1E, 0);
    i = 6;
    do {
        SOUND_SPUKeyStatus[i + 0] = 0;
        SOUND_SPUKeyStatus[i + 1] = 0;
        SOUND_SPUKeyStatus[i + 2] = 0;
        SOUND_SPUKeyStatus[i + 3] = 0;
        SOUND_SPUKeyStatus[i + 4] = 0;
        SOUND_SPUKeyStatus[i + 5] = 0;
        SOUND_SPUKeyStatus[i + 6] = 0;
        SOUND_SPUKeyStatus[i + 7] = 0;
        i += 8;
    } while (i < 8);
    if (i < 0x10) {
        do {
            p = &SOUND_SPUKeyStatus[i];
            i += 1;
            *p = 0;
        } while (i < 0x10);
    }
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

// DRAFT: 0x001AE060 SOUND_CountFreeSPUChannels
// note: loop and lbu match; still differs in early-return scheduling (second compare sits in a branch delay slot with v0 vs at, and lui placement). Tried: split returns, reordered ||, arg0 >= vs > 0x2F.
int SOUND_CountFreeSPUChannels(unsigned int arg0, unsigned int arg1) {
    int count;
    unsigned int i;
    i = arg0;
    if (i > 0x2FU) {
        return -2;
    }
    if ((arg1 < i) || (arg1 >= 0x30U)) {
        return -3;
    }
    count = 0;
    while (arg1 >= i) {
        if (*(unsigned char *)&SOUND_SPUKeyStatus[i] == 0) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

// DRAFT: 0x001AE0D0 SOUND_FindFreeSPUChannel
// note: 17 words differ: first compare in $at (orig $v0), base/var_a2 swapped between $a2/$a3, hoisted delay slot.
int SOUND_FindFreeSPUChannel(unsigned int arg0, unsigned int arg1, unsigned int arg2) {
    unsigned int var_a0;
    unsigned int var_a2;
    unsigned int var_v0;
    unsigned char *temp_a1;
    unsigned char *temp_t0;

    var_a0 = arg0;
    if (arg0 >= 0x30U) {
        return -2;
    }
    if ((arg1 < var_a0) || (arg1 >= 0x30U)) {
        return -3;
    }
    var_a2 = arg2 + 1;
    if ((var_a2 < var_a0) || (arg1 < var_a2)) {
        var_a2 = var_a0;
    }
    var_v0 = var_a2;
    while (var_v0 <= arg1) {
        temp_t0 = (unsigned char *)&SOUND_SPUKeyStatus[var_v0];
        if (*temp_t0 == 0) {
            *temp_t0 = 3;
            return var_v0;
        }
        var_v0 += 1;
    }
    while (var_a0 < var_a2) {
        temp_a1 = (unsigned char *)&SOUND_SPUKeyStatus[var_a0];
        if (*temp_a1 == 0) {
            *temp_a1 = 3;
            return var_a0;
        }
        var_a0 += 1;
    }
    return -1;
}

// FUNCTION: 0x001AE3A0 SOUND_SetSPUWriteAddress
void SOUND_SetSPUWriteAddress(unsigned int arg0) {
    IOPCommandData[1] = (short)arg0;
    IOPCommandData[0] = (short)(arg0 >> 16);
    SetIOPCommand(0x0E, 2);
}

// DRAFT: 0x001AE3C0 SOUND_AllocateStreamBuffer
// note: 6 differing lines; compiler folds the low-half mask so the original's ori $v0,0xFFFF + and is missing. Tried arg1 & 0xFFFFU, (short)(arg1 & 0xFFFF), (unsigned short) cast, unsigned long arg1 (header conflict); all 6.
void SOUND_AllocateStreamBuffer(short arg0, unsigned int arg1, unsigned int arg2) {
    IOPCommandData[0] = arg0;
    IOPCommandData[4] = (short)arg2;
    IOPCommandData[3] = (short)(arg2 >> 16);
    IOPCommandData[1] = (short)(arg1 >> 16);
    IOPCommandData[2] = arg1 & 0xFFFFU;
    SetIOPCommand(0xD, 5);
}

// FUNCTION: 0x001AE5E0 SOUND_SetChannelPitch
int SOUND_SetChannelPitch(unsigned int arg0, short arg1) {
    if (arg0 > 0x2FU) {
        return -1;
    }
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(3, 2);
    return 0;
}

// FUNCTION: 0x001AE630 SOUND_SetChanRelVol
int SOUND_SetChanRelVol(unsigned int arg0, short arg1, short arg2) {
    if (arg0 > 0x2FU) {
        return -1;
    }
    IOPCommandData[2] = arg2;
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x3B, 3);
    return 0;
}

// FUNCTION: 0x001AE680 SOUND_PlaySFXRelVol
int SOUND_PlaySFXRelVol(short arg0, unsigned int arg1, short arg2, short arg3, unsigned int arg4) {
    if (arg1 > 0x2FU) {
        return -1;
    }
    SOUND_SPUKeyStatus[arg1] = 3;
    IOPCommandData[2] = arg2;
    IOPCommandData[3] = arg3;
    IOPCommandData[4] = (short)(arg4 >> 16);
    IOPCommandData[5] = (short)arg4;
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x3C, 6);
    return 0;
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

// DRAFT: 0x001AE7F0 SOUND_DataDestEEDirect
// note: 30 lines differ: arg2&0xFFFF (ori/and in orig) folded to plain sh, epilogue branch target off by one instr; (unsigned short) cast gives same count.
unsigned int SOUND_DataDestEEDirect(unsigned int arg0, short arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5, unsigned int arg6) {
    if (arg0 >= 4U) {
        return -1U;
    }
    IOPCommandData[0] = arg0;
    IOPCommandData[2] = (short)(arg2 >> 16);
    IOPCommandData[1] = arg1;
    IOPCommandData[3] = arg2 & 0xFFFFU;
    IOPCommandData[4] = (short)(arg3 >> 16);
    IOPCommandData[5] = arg3;
    IOPCommandData[6] = (short)(arg4 >> 16);
    IOPCommandData[7] = arg4;
    IOPCommandData[8] = (short)(arg5 >> 16);
    IOPCommandData[9] = arg5;
    IOPCommandData[10] = (short)(arg6 >> 16);
    IOPCommandData[11] = arg6;
    SetIOPCommand(0x30, 0xC);
    return arg2;
}

// DRAFT: 0x001AE8B0 SOUND_StreamAfterFlags
// note: masked [2] store (x & 0xFFFF) is folded to plain sh; store order of [2]/[3]/[5]/[6] and early-branch offset differ; 25 lines
void SOUND_StreamAfterFlags(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5) {
    if (arg0 < 4U) {
        IOPCommandData[0] = arg0;
        IOPCommandData[1] = (short)(arg1 >> 16);
        IOPCommandData[4] = arg2;
        IOPCommandData[2] = (short)(arg1 & 0xFFFF);
        IOPCommandData[3] = (short)(arg2 >> 16);
        IOPCommandData[5] = (short)(arg3 >> 16);
        IOPCommandData[6] = arg3;
        IOPCommandData[7] = (short)(arg4 >> 16);
        IOPCommandData[8] = arg4;
        IOPCommandData[9] = (short)(arg5 >> 16);
        IOPCommandData[10] = arg5;
        SetIOPCommand(0x42, 0xB);
    }
}

// DRAFT: 0x001AE950 SOUND_PlayDialogRelVol
// note: 26 differing lines; the original's ori $a2,0xFFFF + and mask on arg2's low half is folded to a plain sh, which shifts the branch and epilogue. (unsigned short) cast gives the same 26.
unsigned int SOUND_PlayDialogRelVol(unsigned int arg0, short arg1, unsigned int arg2, short arg3, unsigned int arg4) {
    if (arg0 >= 4U) {
        return -1;
    }
    SOUND_SPUKeyStatus[arg0 * 2] = 3;
    IOPCommandData[2] = (short)(arg2 >> 16);
    IOPCommandData[3] = arg2 & 0xFFFFU;
    IOPCommandData[4] = arg3;
    IOPCommandData[5] = (short)(arg4 >> 16);
    IOPCommandData[6] = (short)arg4;
    IOPCommandData[0] = (short)arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x41, 7);
    return arg2;
}

// DRAFT: 0x001AE9F0 SOUND_PlayMusicRelVol
// note: 26 differing lines; same shape as SOUND_PlayDialogRelVol: the ori $a2,0xFFFF + and mask on arg2's low half is folded to a plain sh, shifting the branch and epilogue.
unsigned int SOUND_PlayMusicRelVol(unsigned int arg0, short arg1, unsigned int arg2, short arg3, unsigned int arg4) {
    if (arg0 >= 4U) {
        return -1;
    }
    SOUND_SPUKeyStatus[arg0 * 2] = 3;
    IOPCommandData[2] = (short)(arg2 >> 16);
    IOPCommandData[3] = arg2 & 0xFFFFU;
    IOPCommandData[4] = arg3;
    IOPCommandData[5] = (short)(arg4 >> 16);
    IOPCommandData[6] = (short)arg4;
    IOPCommandData[0] = (short)arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x3E, 7);
    return arg2;
}

// DRAFT: 0x001AEA90 SOUND_TransferSFX
// note: 8 differing words; compiler folds arg2 & 0xFFFF into a plain sh, dropping the original's ori $v0,0xFFFF + and. Tried store reorder (9 words) and hoisted masked local (9 words).
void SOUND_TransferSFX(short arg0, short arg1, unsigned int arg2, unsigned int arg3) {
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    IOPCommandData[2] = (short)(arg2 >> 16);
    IOPCommandData[5] = (short)arg3;
    IOPCommandData[3] = arg2 & 0xFFFFU;
    IOPCommandData[4] = (short)(arg3 >> 16);
    SetIOPCommand(6, 6);
}

// DRAFT: 0x001AECF0 SOUND_InitIOP
// note: about 20 differing lines: bgez delay slot filled with countdown init (orig fills with lui a0 of printf block), shifts countdown and tail by 3 instructions; do-while and for-loop countdown both tried, same count.
int SOUND_InitIOP(void) {
    int temp_v0;
    int var_v1;

    fst_WaitUpdateArray = 0;
    sceSifInitRpc(0);
loop_1:
    if (sceSifBindRpc(gCd, 0x6D6A6C6E, 0) < 0) {
        printf("error: sceSifBindRpc \n");
loop_3:
        goto loop_3;
    }
    for (var_v1 = 0x2710; var_v1 != 0; var_v1--) {
    }
    if (*(int *)(gCd + 0x24) != 0) {
        SOUND_InitWaitUpdate();
        return 1;
    }
    goto loop_1;
}
