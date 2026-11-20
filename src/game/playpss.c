// FLAGS: -lang c++ -str readonly
#include "playpss.h"

// TODO(header): foreign declarations
class Movie {
public:
    static void MovieOutputCurVol();
};

extern "C" int sceCdStatus();
extern "C" int sceCdGetDiskType();
extern "C" int sceGsSyncV(int);
extern "C" int sceMpegDemuxPss(sceMpeg *, void *, int);
extern "C" void RemoteChangePCMVolume(int);
void CdsAssert(char *, int, char *);
void audioUpdate();
void getTrayStatus();

extern signed char gbMoviesOnDisc;
extern int fst_trayOpen;
extern int fst_disk_status;
extern int fst_readCount;
extern int muxBuffFullness;
extern int bgDuration;
extern int (*fileRead)(void *, int);
extern char muxBuff[0x8000];

// DRAFT: 0x001FFBB0 checkAndWaitForDisk__Fv
// note: 20 words differ; loop layout (do-while back-branch one word early, unfilled delay-slot nops after sceCdGetDiskType, tail call at 0x80 vs 0x88). Tried while(1), loop-scoped diskType, for(;;)+break; none reduced the diff.
void checkAndWaitForDisk() {
    if (gbMoviesOnDisc != 0) {
        getTrayStatus();
        if (fst_trayOpen != 0) {
            RemoteChangePCMVolume(0);
            do {
                sceGsSyncV(0);
                getTrayStatus();
            } while (fst_trayOpen != 0);
            while (1) {
                int diskType = sceCdGetDiskType();
                if (diskType == 0x14 || diskType == 0x12) {
                    break;
                }
                sceGsSyncV(0);
            }
            Movie::MovieOutputCurVol();
        }
    }
}

// FUNCTION: 0x001FFC50 getTrayStatus__Fv
void getTrayStatus() {
    int status;

    status = sceCdStatus();
    fst_disk_status = status;
    if (status == 1 || status == 0x20) {
        fst_trayOpen = 1;
        return;
    }
    fst_trayOpen = 0;
}

// FUNCTION: 0x001FFCB0 fillBuff__FP7sceMpegi
int fillBuff(sceMpeg *arg0, int arg1) {
    char *var_a1;
    int temp_v0;

    if (muxBuffFullness != 0) {
        var_a1 = muxBuff + 0x8000 - muxBuffFullness;
        goto block_8;
    }
loop_2:
    muxBuffFullness = fileRead(muxBuff, 0x8000);
    if (muxBuffFullness == 0 && arg1 == 0) {
        return 0;
    }
    if (muxBuffFullness != 0) {
        var_a1 = muxBuff;
        if (fst_readCount == 0) {
            fst_readCount += 1;
        }
block_8:
        temp_v0 = sceMpegDemuxPss(arg0, var_a1, muxBuffFullness);
        muxBuffFullness -= temp_v0;
        return temp_v0;
    }
    goto loop_2;
}

// FUNCTION: 0x001FFD60 errorCallback__FP7sceMpegP13sceMpegCbDataPv
int errorCallback(sceMpeg *arg0, sceMpegCbData *arg1, void *arg2) {
    CdsAssert("playpss.c", 0x3DB, "0");
    return 1;
}

// DRAFT: 0x001FFD90 backgroundCallback__FP7sceMpegP13sceMpegCbDataPv
// note: 2 words differ; load order of the counter and bgDuration. Tried single-expression, split, counter-local, cast, and swapped-operand forms; the counter-local form is the best at 2.
int backgroundCallback(sceMpeg *arg0, sceMpegCbData *arg1, void *arg2) {
    unsigned int temp_s0;
    unsigned int counter;

    counter = *(unsigned int *)0x10000000;
    temp_s0 = bgDuration + counter;
    while ((unsigned int)*(unsigned int *)0x10000000 < temp_s0) {
        fillBuff(arg0, 0);
        audioUpdate();
    }
    return 1;
}
