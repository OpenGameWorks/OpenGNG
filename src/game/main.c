// FLAGS: -str readonly
#include "main.h"

// TODO(header): foreign declarations
typedef struct MainEngine {
    char pad0[0x137E0];
    char unk137E0[0x50C0];
    char *unk188A0;
} MainEngine;
extern char gszFilePrefix[0x80];
extern char *IrxTbl[9];
extern char SerNo[0x10];
extern char gDebug[0x40];
extern MainEngine gEng;
extern char gInterface[0x40];
extern char gMC[0x40];
extern char gPad[0x40];
extern char gPad2[0x40];
extern char gSound[0x40];
extern short gbMusic;
extern char gbSoundFilesOnDisc;
extern char gbMoviesOnDisc;
void *memset(void *dst, int c, unsigned int n);
int mwInit(void);
int mwExit(void);
int printf(const char *fmt, ...);
int sceSifInitRpc(int mode);
int sceCdInit(int mode);
int sceCdGetDiskType(void);
int sceCdMmode(int mode);
int sceSifRebootIop(const char *path);
int sceSifSyncIop(void);
int sceSifLoadFileReset(void);
int sceSifInitIopHeap(void);
int sceFsReset(void);
int sceSdRemoteInit(void);
int sceSifLoadModule(const char *path, int arg, const char *argp);
int sceGsSyncV(int mode);
int scePcStop(void);
char *strcpy(char *dst, const char *src);
char *strcat(char *dst, const char *src);
unsigned int strlen(const char *s);
int strncasecmp(const char *a, const char *b, unsigned int n);
void PadInit__Fv(void);
void InitPad__3PadFi(void *this, int arg0);
void EngineInit__9MaxEngineFv(void *this);
void InitDebug__5DebugFv(void *this);
void Init__9InterfaceFv(void *this);
void Init__10MemoryCardFv(void *this);
void Init__13EntityManagerFv(void *this);
void MainGame__10MaximoMainFv(void *this);
void PadEnd__Fv(void);
void PSoundShutdown__6PSoundFv(void *this);

// DRAFT: 0x0012A670 main
// note: 155 words differ. Original uses daddiu for dFlag = 1 (ours addiu; long dFlag did not change it), keeps a duplicated argc test, and its switch and block_16 branch forms differ from ours. else-if split gave 164.
int main(int argc, char **argv) {
    char sp70[0x100];
    char sp170[0x100];
    char sp270[0x100];
    int dFlag = 0;
    int i;
    int mode;
    char *typeStr;

    memset(gszFilePrefix, 0, 0x80);
    mwInit();
    if (argc > 1) {
        for (i = 1; i < argc; i++) {
            printf("argv[%d] '%s'\n", i, argv[i]);
            if (strncasecmp(argv[i], "-d", 2) == 0 || strncasecmp(argv[i], "d", 1) == 0) {
                dFlag = 1;
            }
        }
        if (dFlag != 0) {
            printf("Load overlay from Program folder\n");
            gEng.unk188A0[0x24] = 0;
        }
    } else {
        printf("No command args\n");
    }
    printf("SerNo %s\n", SerNo);
    sceSifInitRpc(0);
    sceCdInit(0);
    switch (sceCdGetDiskType()) {
    case 20:
        mode = 2;
        typeStr = "D";
        goto block_16;
    case 18:
        mode = 1;
        typeStr = "C";
block_16:
        sceCdMmode(mode);
        strcpy(sp70, gszFilePrefix);
        strcat(sp70, "cdrom0:\\PSXIRX\\IOPRP252.IMG;1");
        while (sceSifRebootIop(sp70) == 0) {
        }
        while (sceSifSyncIop() == 0) {
        }
        sceSifInitRpc(0);
        sceSifLoadFileReset();
        sceSifInitIopHeap();
        sceCdInit(0);
        sceCdMmode(mode);
        sceFsReset();
        for (i = 0; i < 9; i++) {
            strcpy(sp170, gszFilePrefix);
            strcat(sp170, IrxTbl[i]);
            if (sceSifLoadModule(sp170, 0, 0) < 0) {
                printf("Can't load module %s\n", IrxTbl[i]);
                return 0;
            }
        }
        sceSdRemoteInit();
        gbMusic = 1;
        gbSoundFilesOnDisc = 1;
        gbMoviesOnDisc = 1;
        strcpy(sp270, gszFilePrefix);
        strcat(sp270, "cdrom0:\\PSXIRX\\MJOLNM2R.IRX;1");
        if (sceSifLoadModule(sp270, strlen(typeStr) + 1, typeStr) < 0) {
            printf("Can't load module: %s\n", sp270);
        } else {
            PadInit__Fv();
            InitPad__3PadFi(gPad, 0);
            InitPad__3PadFi(gPad2, 1);
            EngineInit__9MaxEngineFv(&gEng);
            InitDebug__5DebugFv(gDebug);
            Init__9InterfaceFv(gInterface);
            Init__10MemoryCardFv(gMC);
            Init__13EntityManagerFv(gEng.unk137E0);
            MainGame__10MaximoMainFv(&gEng);
            PadEnd__Fv();
            scePcStop();
            PSoundShutdown__6PSoundFv(gSound);
            sceGsSyncV(0);
            sceGsSyncV(0);
            mwExit();
        }
        break;
    default:
        printf("Unknown disc type or Load from HD\n");
        break;
    }
    return 0;
}
