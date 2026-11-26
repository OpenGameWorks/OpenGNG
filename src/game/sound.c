// FLAGS: -str readonly
#include "sound.h"

// TODO(header): foreign declarations
extern unsigned short IOPCommandData[64];
extern int gSOUND_EEControlReq;
extern int gSOUND_EEControlReqCallCnt;
extern char SOUND_SPUKeyStatus[0x40];
void SetIOPCommand(int cmd, int count);
extern char gCd[0x40];
int sceSifInitRpc(int mode);
int sceSifBindRpc(void *client, unsigned int rpc_number, int mode);
int printf(const char *fmt, ...);
void SOUND_CopyIOPBuffer(void);
int sceSifCheckStatRpc(void *cd);
void FlushCache(int nMode);
void SOUND_GetStatus(int arg0, int arg1);
void SOUND_SIFTransfer(int arg0, unsigned int arg1, int arg2);
void memcpy(void *dst, const void *src, unsigned int size);
extern unsigned short senddata[0x400];
extern short senddataPrevDbg[0x400];
extern int IOP_Cnt;
extern int SOUND_IOP_REQUEST_LOAD;
extern int gSOUND_uEECallCnt;
extern int gSOUND_EEMainSyncCount3Sent;
extern int gSOUND_EEMainSyncCount3Returned;
extern int sbuff2[128];
extern int SOUND_STREAM_ON[4];
extern int SOUND_STREAM_STATUS16[4];
extern int SOUND_STREAM_PLAY_HALF[4];
extern int SOUND_STREAM_ENV[4];
extern int SOUND_STREAM_CD_READ_PHASE[4];
extern int SOUND_STREAM_SPU_PHASE[4];
extern int SOUND_STREAM_SPU_PHASE_WAITING[4];
extern int SOUND_STREAM_SPU_ADDR[4];
extern int SOUND_STREAM_ID[4];
extern int SOUND_STREAM_CD_ACCESS;
extern char gSndEEDSSR[0x48];
extern int gSndRecentTransaction_IOPImageArray[12];
extern int gTransaction_IOPImageArray[4];
extern int SOUND_CD_IDLE;
extern int SOUND_CD_READY;
extern int SOUND_CD_IDLE_AND_READY;
extern int SOUND_CD_OUR_DISK_OP_ACTIVE;
extern int SOUND_CD_STAGE;
extern int SOUND_CD_TRAY_OPEN;
extern int SOUND_CD_CONTINUE_AFTER_TRAY_CLOSE;
extern int SOUND_IOP_CD_STATUS;
extern int SOUND_IOP_DISK_TYPE;
extern int SOUND_IOP_DATA_ADDRESS;
extern int SOUND_IOP_DATA_SIZE;
extern int SOUND_IOP_DATA_SEEK;
extern int SOUND_IOP_DATA_CHECK;
extern int SOUND_IOP_DATA_ID;
extern int SOUND_SFX_TRANSFER_END;
extern int SOUND_SPU_ADDR;
extern int SOUND_TRANSFER_DATA_BLOCK_TO_EE_STATUS;
extern int gSOUND_EEControl;
extern int gSOUND_EESync3AtStartOfIOPDiskOp;
extern int gSOUND_TrayCheckMjnlLoopCount;
extern int gSOUND_HardwarePhase;
extern int gSOUND_StageCountSeek;
extern int gSOUND_StageCountRead;
extern int gSOUND_StageCountDone;
extern int gSOUND_uEECallCntReturned;
void CdsAssert__FPciPc(char *, int, char *);

static unsigned int fst_uEECallCnt;
static int fst_WaitUpdateArray;
static unsigned int fst_uEECallCntReturned;
static unsigned char fst_bGetStatusRequested;

// FUNCTION: 0x001ADA80 SOUND_MakeStreamTransactionID
int SOUND_MakeStreamTransactionID(void) {
    static int st_nextStreamTransactionID;
    static char init;
    if (!init) {
        st_nextStreamTransactionID = 0x100;
        init = 1;
    }
    return ++st_nextStreamTransactionID;
}

// FUNCTION: 0x001ADAB0 SOUND_MakeSoundStreamRef
int SOUND_MakeSoundStreamRef(void) {
    static int st_nextStreamRef;
    static char init;
    if (!init) {
        st_nextStreamRef = 0x100;
        init = 1;
    }
    return st_nextStreamRef++;
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

// FUNCTION: 0x001ADBC0 SOUND_SetMasterRegisterVolumeAbs
void SOUND_SetMasterRegisterVolumeAbs(short arg0) {
    IOPCommandData[0] = arg0;
    SetIOPCommand(0x2C, 1);
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

// FUNCTION: 0x001ADC20 SOUND_SetOverallMusicPitch
void SOUND_SetOverallMusicPitch(short arg0, short arg1) {
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x29, 2);
}

// FUNCTION: 0x001ADC40 SOUND_MusicAddExciteHits
void SOUND_MusicAddExciteHits(short arg0) {
    IOPCommandData[0] = arg0;
    SetIOPCommand(0x28, 1);
}

// DRAFT: 0x001ADC60 SOUND_LevelRestart
// note: 19 words; frame and call match, but first-loop base is lui $a0 vs original lui $v1 (+addiu 0x3E50), pointer in $a2 vs $a0, loop test in $v1 vs $at, and second loop stores before addiu with an extra nop before the bnez. Tried indexed stores, p = &arr[i] with mid-block increment, i += 1 ahead of the store, pointer-base first loop (20), and the draft-shape alternates (19).
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
// note: 19 words; same loop shape and register-allocation gap as SOUND_LevelRestart (base in $a0 vs $v1, pointer in $a2 vs $a0). Tried four draft-shape and pointer-form alternates, all 19.
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

// FUNCTION: 0x001ADDB0 SOUND_FadeOutAllMusic
void SOUND_FadeOutAllMusic(short arg0) {
    IOPCommandData[0] = arg0;
    SetIOPCommand(0x1C, 1);
}

// FUNCTION: 0x001ADDD0 SOUND_AllChannelReverbOff
void SOUND_AllChannelReverbOff(short arg0) {
    IOPCommandData[0] = arg0;
    SetIOPCommand(0x17, 1);
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

// FUNCTION: 0x001ADE60 SOUND_ClearReverbWorkArea
void SOUND_ClearReverbWorkArea(short arg0, short arg1) {
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x2B, 2);
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

// FUNCTION: 0x001ADEC0 FlushIOPCommand
int FlushIOPCommand(int arg0, unsigned int arg1, unsigned int arg2) {
    int old;
    static volatile int oldcnt;

    SOUND_CopyIOPBuffer();
    if (senddata[0] == 0) {
        if (fst_bGetStatusRequested == 0) {
            return -2;
        }
    }
    if (fst_uEECallCntReturned != 0 && fst_uEECallCntReturned < fst_uEECallCnt) {
        printf("FlushIOP Waiting sync %d, returned %d\n", fst_uEECallCnt, fst_uEECallCntReturned);
        return -3;
    }
    FlushCache(0);
    asm { sync }
    asm { sync.p }
    if (sceSifCheckStatRpc(gCd) != 0) {
        return -1;
    }
    if (fst_bGetStatusRequested != 0) {
        fst_bGetStatusRequested = 0;
        SOUND_GetStatus(SOUND_IOP_REQUEST_LOAD, 0);
    }
    senddata[1] = 0;
    senddata[4] = (short)(arg1 >> 16);
    senddata[5] = (short)arg1;
    senddata[6] = (short)(arg2 >> 16);
    senddata[7] = (short)arg2;
    fst_uEECallCnt += 1;
    gSOUND_uEECallCnt = fst_uEECallCnt;
    senddata[2] = (short)(fst_uEECallCnt >> 16);
    senddata[3] = *(unsigned short *)&fst_uEECallCnt;
    FlushCache(0);
    asm { sync }
    asm { sync.p }
    SOUND_SIFTransfer(0, (unsigned int)senddata, arg0);
    memcpy(senddataPrevDbg, senddata, 0x800);
    FlushCache(0);
    asm { sync }
    asm { sync.p }
    old = IOP_Cnt;
    gSOUND_EEMainSyncCount3Sent = arg2;
    senddata[0] = 0;
    oldcnt = old;
    IOP_Cnt = 0;
    return oldcnt;
}

// DRAFT: 0x001AE060 SOUND_CountFreeSPUChannels
// note: 20 differing lines; do-while loop drops the top test (matches the original's loop body, but the original enters the loop through a bottom test). Still differs: early -3 check uses v0 vs at and no delay-slot fill for sltiu; original has b to the loop condition. Tried: split returns, reordered ||, arg0 >= vs > 0x2F, separate early-return checks (27), bad-local (25), while(i <= arg1) (23), for (23), reversed locals (20).
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
    do {
        if (*(unsigned char *)&SOUND_SPUKeyStatus[i] == 0) {
            count += 1;
        }
        i += 1;
    } while (arg1 >= i);
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

// FUNCTION: 0x001AE190 SOUND_ClearIOPBuffer
void SOUND_ClearIOPBuffer(void) {
    IOP_Cnt = 0;
    senddata[0] = 0;
}

// DRAFT: 0x001AE1A0 SetIOPCommand
// note: 128 words differ; original frame is 0x30 with s0/s1 saved and 0x200 bytes vs our 0x180; signed loop index 140, cached IOP_Cnt no change.
void SetIOPCommand(int arg0, int arg1) {
    static char init;
    static int overflowCnt;
    unsigned int t4;

    if (init == 0) {
        overflowCnt = 0;
        init = 1;
    }
    if ((unsigned int)(IOP_Cnt + arg1 + 10) >= 0x400U) {
        printf("*** Function:SetIOPCommand - IOP Buffer full(%d), cmd %d  ***\n", gSOUND_EEMainSyncCount3Returned, arg0);
        return;
    }
    t4 = 0;
    senddata[8 + IOP_Cnt] = arg0;
    senddata[9 + IOP_Cnt] = arg1;
    if (arg1 != 0) {
        if ((unsigned int)arg1 >= 9U) {
            do {
                senddata[IOP_Cnt + 10 + t4 + 0] = IOPCommandData[t4 + 0];
                senddata[IOP_Cnt + 10 + t4 + 1] = IOPCommandData[t4 + 1];
                senddata[IOP_Cnt + 10 + t4 + 2] = IOPCommandData[t4 + 2];
                senddata[IOP_Cnt + 10 + t4 + 3] = IOPCommandData[t4 + 3];
                senddata[IOP_Cnt + 10 + t4 + 4] = IOPCommandData[t4 + 4];
                senddata[IOP_Cnt + 10 + t4 + 5] = IOPCommandData[t4 + 5];
                senddata[IOP_Cnt + 10 + t4 + 6] = IOPCommandData[t4 + 6];
                senddata[IOP_Cnt + 10 + t4 + 7] = IOPCommandData[t4 + 7];
                t4 += 8;
            } while (t4 < (unsigned int)(arg1 - 8));
        }
        for (; t4 < (unsigned int)arg1; t4++) {
            senddata[IOP_Cnt + 10 + t4] = IOPCommandData[t4];
        }
    }
    senddata[0] += 1;
    IOP_Cnt += 2;
    IOP_Cnt += arg1;
}

// FUNCTION: 0x001AE3A0 SOUND_SetSPUWriteAddress
void SOUND_SetSPUWriteAddress(unsigned int arg0) {
    IOPCommandData[1] = (short)arg0;
    IOPCommandData[0] = (short)(arg0 >> 16);
    SetIOPCommand(0x0E, 2);
}

// DRAFT: 0x001AE3C0 SOUND_AllocateStreamBuffer
// note: 6 differing lines; compiler folds the low-half mask so the original's ori $v0,0xFFFF + and is missing. Tried arg1 & 0xFFFFU, (short)(arg1 & 0xFFFF), (unsigned short) cast, unsigned long arg1 (header conflict), unsigned int lo local with &=, mask local, (int)arg1 & 0xFFFF, arg1 & 65535; all 6.
void SOUND_AllocateStreamBuffer(short arg0, unsigned int arg1, unsigned int arg2) {
    IOPCommandData[0] = arg0;
    IOPCommandData[4] = (short)arg2;
    IOPCommandData[3] = (short)(arg2 >> 16);
    IOPCommandData[1] = (short)(arg1 >> 16);
    IOPCommandData[2] = arg1 & 0xFFFFU;
    SetIOPCommand(0xD, 5);
}

// FUNCTION: 0x001AE410 SOUND_CloseStreamBuffer
void SOUND_CloseStreamBuffer(short arg0) {
    IOPCommandData[0] = arg0;
    SetIOPCommand(0xF, 1);
}

// FUNCTION: 0x001AE430 SOUND_SetLanguage
void SOUND_SetLanguage(short arg0) {
    IOPCommandData[0] = arg0;
    SetIOPCommand(0x21, 1);
}

// FUNCTION: 0x001AE450 SOUND_InitStreamData
void SOUND_InitStreamData(short arg0) {
    IOPCommandData[0] = arg0;
    SetIOPCommand(0xC, 1);
}

// FUNCTION: 0x001AE470 SOUND_InitSPU
void SOUND_InitSPU(void) {
    SetIOPCommand(7, 0);
}

// FUNCTION: 0x001AE480 SOUND_GetStatusPatient
void SOUND_GetStatusPatient(void) {
    fst_bGetStatusRequested = 1;
}

// FUNCTION: 0x001AE490 SOUND_GetStatus
void SOUND_GetStatus(int arg0, int arg1) {
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    SetIOPCommand(0x9, 2);
}

// FUNCTION: 0x001AE570 SOUND_StopAllStreams
void SOUND_StopAllStreams(void) {
    SetIOPCommand(0x43, 0);
}

// FUNCTION: 0x001AE580 SOUND_StopAllRegularSounds
void SOUND_StopAllRegularSounds(void) {
    SetIOPCommand(0x48, 0);
}

// FUNCTION: 0x001AE590 SOUND_StopAllMusic
void SOUND_StopAllMusic(void) {
    SetIOPCommand(0x26, 0);
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
// note: 12 words; the original keeps ori 0xFFFF + and on index 1, ours folds it. No change from 0xFFFFLL/UL, (unsigned long long) arg, (unsigned short)-1, ~0xFFFF0000, static const mask, uncast stores, or compilers 3.0-011126/3.0.1-020123; (arg0 << 16) >> 16 gives 7 (adds dsll32/dsrl32).
void SOUND_PauseMultipleSounds(unsigned int arg0, unsigned int arg1) {
    IOPCommandData[3] = arg1;
    IOPCommandData[0] = (short)(arg0 >> 16);
    IOPCommandData[1] = (short)(arg0 & 0xFFFF);
    IOPCommandData[2] = (short)(arg1 >> 16);
    SetIOPCommand(0x44, 4);
}

// DRAFT: 0x001AE530 SOUND_StopMultipleSounds
// note: 12 words; the original keeps ori 0xFFFF + and on index 1, ours folds it. No change from 0xFFFFLL/UL, (unsigned long long) arg, (unsigned short)-1, ~0xFFFF0000, static const mask, uncast stores, or compilers 3.0-011126/3.0.1-020123; (arg0 << 16) >> 16 gives 7 (adds dsll32/dsrl32).
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

// DRAFT: 0x001AE700 SOUND_DataDestEEBuffered
// note: 41 words differ (orig 0xEC bytes, ours 0xE4): orig loads lui at,0x4B before most stores and has a different early-return branch and jal delay slot; tried short arg0, reordered stores, masked arg2 inline or via local, positive-if form (53 words).
int SOUND_DataDestEEBuffered(unsigned int arg0, short arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5, unsigned int arg6, short arg7, unsigned short arg8, unsigned int arg9) {
    unsigned int lo2;
    if (arg0 >= 4U) {
        return -1;
    }
    IOPCommandData[12] = arg7;
    IOPCommandData[2] = (short)(arg2 >> 16);
    IOPCommandData[0] = (short)arg0;
    lo2 = arg2 & 0xFFFFU;
    IOPCommandData[3] = (short)lo2;
    IOPCommandData[4] = (short)(arg3 >> 16);
    IOPCommandData[5] = (short)arg3;
    IOPCommandData[6] = (short)(arg4 >> 16);
    IOPCommandData[7] = (short)arg4;
    IOPCommandData[8] = (short)(arg5 >> 16);
    IOPCommandData[9] = (short)arg5;
    IOPCommandData[10] = (short)(arg6 >> 16);
    IOPCommandData[11] = (short)arg6;
    IOPCommandData[1] = arg1;
    IOPCommandData[13] = arg8;
    IOPCommandData[14] = (short)(arg9 >> 16);
    IOPCommandData[15] = (short)arg9;
    SetIOPCommand(0x31, 0x10);
    return arg2;
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
// note: 25 differing words; size 0x94 vs 0x9c. Original keeps ori $v0,0xFFFF + and on arg1 & 0xFFFF (the two missing words); ours folds it to a plain sh of a1. Tried arg1 & 0xFFFFU direct and in a block-scoped unsigned int local; both fold to sh (25).
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
// note: 26 differing words; size 0x98 vs 0xa0. The original's ori $a2,0xFFFF + and on arg2 & 0xFFFF (the two missing words) is folded to a plain sh, which shifts the b target and epilogue by 2 words. Tried (unsigned short) cast and (arg2 & 0xFFFFU) + 0U; both fold (26).
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
// note: 26 differing words; size 0x98 vs 0xa0. Same shape as SOUND_PlayDialogRelVol: the ori $a2,0xFFFF + and mask on arg2 & 0xFFFF is folded to a plain sh, shifting the b target and epilogue by 2 words. The original's SetIOPCommand code is 0x3E, not 0x41.
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
// note: 8 differing words; compiler folds arg2 & 0xFFFF into a plain sh, dropping the original's ori $v0,0xFFFF + and. Tried store reorder (9 words), hoisted masked local (9 words), in-place unsigned int lo local with &=, (int)arg2 & 0xFFFF (all 8).
void SOUND_TransferSFX(short arg0, short arg1, unsigned int arg2, unsigned int arg3) {
    IOPCommandData[0] = arg0;
    IOPCommandData[1] = arg1;
    IOPCommandData[2] = (short)(arg2 >> 16);
    IOPCommandData[5] = (short)arg3;
    IOPCommandData[3] = arg2 & 0xFFFFU;
    IOPCommandData[4] = (short)(arg3 >> 16);
    SetIOPCommand(6, 6);
}

#pragma cplusplus on
// FUNCTION: 0x001AECE0 JP__FPv
void JP(void *) {
}
#pragma cplusplus reset

// DRAFT: 0x001AECF0 SOUND_InitIOP
// note: 21 words; the original's countdown is a 0x2710 loop with v1 counter and v0 copy, 3 nops after the body, and one extra nop before the countdown init (bgez target) and in the printf-block pad, so the tail is 3 instructions short. Tried do-while, post-decrement (for/do/while), for(;;) and while(1) error loops, and gCd addressing forms: all 21 to 22.
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

// DRAFT: 0x001AEDA0 SOUND_CopyIOPBuffer
// note: 337 words off; frame -0xB0 (orig -0xC0, missing 16-byte spill at 0xA0 from reg pressure), clear loop unrolled, base pointers not hoisted, sync placement differs.
void SOUND_CopyIOPBuffer(void) {
    volatile int spB0;
    volatile int spA0[4];
    int i;
    int j;
    int s2;
    int w;
    int w2;
    int v;

    spB0 = 0;
    FlushCache(0);
    asm {
        sync
        sync.p
    }
    SOUND_STREAM_CD_ACCESS = 0;
    for (i = 0; i < 0x30; i++) {
        SOUND_STREAM_ON[i] = 0;
        SOUND_STREAM_STATUS16[i] = 0;
    }
    ((sbuff2[0] * 4 < 0x201) ? (void)0 : CdsAssert__FPciPc("sound.c", 0xC0, "(nWritten*4) <= IOP_RETURN_BUFFER_BYTES"));
    fst_uEECallCntReturned = sbuff2[2];
    gSOUND_uEECallCntReturned = fst_uEECallCntReturned;
    gSOUND_EEMainSyncCount3Returned = sbuff2[3];
    SOUND_SFX_TRANSFER_END = sbuff2[4];
    SOUND_SPU_ADDR = sbuff2[5];
    SOUND_IOP_REQUEST_LOAD = sbuff2[6];
    SOUND_CD_IDLE = sbuff2[7];
    SOUND_CD_READY = sbuff2[8];
    SOUND_CD_IDLE_AND_READY = sbuff2[9];
    SOUND_CD_OUR_DISK_OP_ACTIVE = sbuff2[10];
    SOUND_CD_STAGE = sbuff2[11];
    SOUND_CD_TRAY_OPEN = sbuff2[12];
    SOUND_CD_CONTINUE_AFTER_TRAY_CLOSE = sbuff2[13];
    SOUND_IOP_CD_STATUS = sbuff2[14];
    SOUND_IOP_DISK_TYPE = sbuff2[15];
    gSOUND_EESync3AtStartOfIOPDiskOp = sbuff2[16];
    gSOUND_TrayCheckMjnlLoopCount = sbuff2[17];
    SOUND_TRANSFER_DATA_BLOCK_TO_EE_STATUS = sbuff2[18];
    gSOUND_EEControl = sbuff2[19];
    gSOUND_HardwarePhase = sbuff2[20];
    gSOUND_StageCountSeek = sbuff2[21];
    gSOUND_StageCountRead = sbuff2[22];
    gSOUND_StageCountDone = sbuff2[23];
    for (i = 0; i < 12; i++) {
        gSndRecentTransaction_IOPImageArray[i] = sbuff2[24 + i];
    }
    for (i = 0; i < 4; i++) {
        gTransaction_IOPImageArray[i] = sbuff2[36 + i];
    }
    SOUND_IOP_DATA_ADDRESS = sbuff2[40];
    SOUND_IOP_DATA_SIZE = sbuff2[41];
    SOUND_IOP_DATA_SEEK = sbuff2[42];
    SOUND_IOP_DATA_CHECK = sbuff2[43];
    SOUND_IOP_DATA_ID = sbuff2[44];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 16; j++) {
            v = (sbuff2[45 + i] >> (0x1E - 2 * j)) & 3;
            if (v == 0 && SOUND_SPUKeyStatus[i * 16 + j] == 3) {
                v = 4;
            }
            SOUND_SPUKeyStatus[i * 16 + j] = v;
        }
    }
    s2 = 48;
    for (i = 0; i < 2; i++) {
        w = sbuff2[s2];
        SOUND_STREAM_ON[i] = 0;
        SOUND_STREAM_STATUS16[i] = w & 0xFFFF;
        if (w & 0x8000) {
            SOUND_STREAM_ON[i] = 1;
            spB0++;
        }
        SOUND_STREAM_PLAY_HALF[i] = (w >> 16) & 3;
        SOUND_STREAM_ENV[i] = w & 0xFFFF;
        w2 = sbuff2[s2 + 1];
        SOUND_STREAM_CD_READ_PHASE[i] = w2 & 0xFF;
        SOUND_STREAM_SPU_PHASE[i] = (w2 >> 8) & 0xFF;
        SOUND_STREAM_SPU_PHASE_WAITING[i] = (w2 >> 16) & 0xFF;
        SOUND_STREAM_SPU_ADDR[i] = sbuff2[s2 + 2];
        SOUND_STREAM_ID[i] = sbuff2[s2 + 3];
        s2 += 4;
    }
    for (i = 0; i < 2; i++) {
        memcpy(gSndEEDSSR + 0x24 * i, &sbuff2[s2], 0x24);
        SOUND_STREAM_ON[i + 2] = 0;
        if (*(int *)(gSndEEDSSR + 0x24 * i + 0xC) & 8) {
            SOUND_STREAM_ON[i + 2] = 1;
        }
        s2 += 9;
    }
}
