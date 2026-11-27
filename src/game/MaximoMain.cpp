// FLAGS: -str readonly
#include "MaximoMain.h"
#include "PSlideShow.h"
#include "PResourceManager.h"
#include "Camera.h"
#include "PAnim.h"

// TODO(header): foreign declarations
extern "C" int ReadPush__3PadFv(void *);
extern char BONUSSCREEN_FILE[26];
extern int Level2GalleryMap[21];
extern "C" PMNode *Load__6PWorldFPCcb13eTextureGroup(void *, const char *, bool, int);
extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
extern "C" void RemoveAllParticleSystems__16PParticleManagerFv(void *);
extern "C" void ReturnControlOfIOPToMjln__6PSoundFv(void *);
class FontNode {
public:
    char _pad00[8];
    int m_unk8;
};
class FontManager {
public:
    void RemoveText(FontNode *pNode);
    void RemoveText(unsigned short nId);
    void *DisplayString(int nText, int x, int y, bool bFlag);
    void InitFrame();
    char _pad000[0x13];
    signed char m_unk13;
    char _pad014[0x100 - 0x14];
    char *m_unk100;         // 0x100 subtitle table, 12 bytes per entry
};
extern unsigned char gInterface[2656];
extern unsigned char gMC[16320];
extern unsigned char MemMgr[908];
extern PMNode *pBonusScreen;
extern "C" void Destroy__6PWorldFv(void *);
extern "C" void RemoveAllFogObjects__16PParticleManagerFv(void *);
extern "C" void UnloadGlobalResource__16PResourceManagerFv(void *);
extern "C" int LoadGlobalResource__16PResourceManagerFPCcb(void *, const char *, bool);
extern "C" void Unload__16PResourceManagerFv(void *);
extern "C" void DmaWaitForCompletion__Fib(int, bool);
extern "C" void sceGsSyncPath(int, int);
extern unsigned char LevelTable[2688];
extern unsigned char gSound[98496];
extern "C" void FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(void *, float, float, bool, int);
extern "C" void AddMeshLayer__9InterfaceFP6PMNode(void *, PMNode *);
extern "C" void DeleteMeshLayer__9InterfaceFP6PMNode(void *, PMNode *);
extern "C" PMNode *GetResource__16PResourceManagerFUib(void *, unsigned int, bool);
extern "C" void FadeOutAllMusic__6PSoundFUi(void *, unsigned int);
extern "C" int PlaySoundUbiquitous__6PSoundFUi(void *, unsigned int);
extern "C" void UpdateStatus__9InterfaceFUib(void *, unsigned int, bool);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void __dl__FPv(void *);
extern "C" int Find__6PArrayFPv(void *, void *);
extern "C" void *DisplayString__11FontManagerFPcffi9FontColor9FontAlign(void *, const char *, float, float, int, int, int);
extern "C" void RemoveAll__11FontManagerFb(void *, bool);
extern "C" void *DisplayString__11FontManagerFiiib(void *, int, int, int, bool);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern PMNode *pMasteryTextIcon;
extern unsigned char __vt__9PResource[12];
extern "C" int GetDialogStreamReadiness__6PSoundFUi(void *, unsigned int);
extern "C" void PrepDialog__6PSoundFUi(void *, unsigned int);
extern "C" void PSoundLevelClear__6PSoundFv(void *);
extern "C" void LevelClear__9InterfaceFv(void *);
extern "C" void SaveApparitionData__13EntityManagerFi(void *, int);
extern "C" int CalculateTallyData__13EntityManagerFv(void *);
extern "C" void DeleteMeshLayer__9InterfaceFv(void *);
extern "C" void UpdateHeader__10MemoryCardFUc(void *, unsigned char);
extern float RES_POS;
extern unsigned int TallySound[6];
struct LevelFiles {
    char _pad00[0x10];
    int m_unk10;            // 0x10, zero when the level lists no dialog files
};
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void *__dt__6CameraFv(void *, short);
extern "C" void *__dt__13EntityManagerFv(void *, short);
extern "C" void *__dt__9MaxEngineFv(void *, short);
extern "C" void ResetGameData__10MemoryCardFv(void *);
extern "C" void InitLoadGame__10MemoryCardFv(void *);
extern "C" void InitRenderFrame__9MaxEngineFbUi(void *, bool, unsigned int);
extern "C" int LoadGame__10MemoryCardFv(void *);
extern "C" int Render__9InterfaceFi(void *, int);
extern "C" void SetInputMode__3PadFQ23Pad10eInputModePQ23Pad9InputDatai(void *, int, void *, int);
extern int miAbilityCount__15EntityBaseClass;
extern int miRandom__7MathAPI;
extern unsigned char MODE_PAL;
extern unsigned char DemoTable[24];
extern unsigned char DemoTableP[24];
extern unsigned char gPad[448];
extern unsigned char gEng[0x1A000];
extern "C" void DisplayLevelName__9InterfaceFii(void *, int, int);
extern "C" void SetMonoOut__6PSoundFb(void *, unsigned char);
extern "C" int RenderSkybox__9MaxEngineFi(void *, int);
extern "C" void RenderWorld__9MaxEngineFib(void *, int, bool);
extern "C" int Render__13EntityManagerFP13PLightManager(void *, void *);
extern "C" void RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(void *, void *, int, int);
extern "C" unsigned int GetPauseCategories__6PSoundFv(void *);
extern "C" void SetPauseCategories__6PSoundFUi(void *, unsigned int);
extern "C" void PlayMusic__6PSoundFUi(void *, unsigned int);
extern short gbMusic;
extern "C" void SetMainMusicRelVolume__6PSoundFUi(void *, unsigned int);
extern "C" void SetEffectsRelVolume__6PSoundFUi(void *, unsigned int);
extern "C" void ScaleSet__6PMNodeFffff(void *, float, float, float, float);
extern "C" void EnableVibrate__3PadFb(void *, unsigned char);
extern "C" void SetColor__8FontNodeF9FontColor(void *, int);
extern "C" unsigned char PlayingCutCamera__6CameraFv(void *);
extern "C" void __ct__9MaxEngineFv(void *);
extern "C" void __ct__13EntityManagerFv(void *);
extern "C" void __ct__6CameraFv(void *);
extern int U_MILLISEC_PER_FRAME_HI;
extern int U_MILLISEC_PER_FRAME_LO;
extern "C" void SoundGainEEControl__9InterfaceFv(void *);
extern "C" void RestartAndLoadInterfaceTypeBank__6PSoundFUi(void *, unsigned int);
extern "C" void StopMusic__6PSoundFv(void *);
extern "C" void ResetWarning__11FontManagerFv(void *);
extern "C" float GetFrameTime__6PMNodeFv(void *);
extern "C" PMNode *Load__9InterfaceFPCc(void *, char const *);
extern "C" void *__nw__FUi(unsigned int);
extern unsigned char __vt__6PMNode[16];
extern unsigned char __vt__9PMeshNode[16];
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void InitMembers__6PMNodeFv(void *pThis);
extern "C" void InitMembers__9PMeshNodeFv(void *pThis);
extern "C" void CopyMNode__6PMNodeFR6PMNodeb(void *pThis, void *pSrc, bool bFlag);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nCount);
extern "C" void ResetAnimations__15PCutScenePlayerFv(void *pThis);
extern "C" void SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf(void *pThis, void *pArray, float fOpacity);
extern "C" void CutSceneEnter__6PSoundFPUiUiUiUi(void *pThis, unsigned int *pOut, unsigned int nA, unsigned int nB, unsigned int nC);
extern char gGfxEng[1504384];
extern "C" int AbilityScreen__9InterfaceFv(void *);
extern "C" int IsPauseDisabled__6PlayerFv(void *);
extern "C" int IsConnected__3PadFv(void *);
extern "C" void PauseVibrate__3PadFb(void *, bool);
extern "C" void Pause__6PSoundFv(void *);
extern "C" void Resume__6PSoundFv(void *);
extern "C" void SetPause__9InterfaceFv(void *);
extern "C" void InitSaveGame__10MemoryCardFPQ26Player10PlayerDataib(void *, void *, int, bool);
extern "C" int SaveGame__10MemoryCardFv(void *);
extern "C" void PolyDebug__6CameraFv(void *);
extern "C" void Animate__13EntityManagerFif(void *, int, float);
extern "C" void Process__13EntityManagerFv(void *);
extern "C" void ObjectCollision__13EntityManagerFv(void *);
extern "C" void RunPhysics__13EntityManagerFf(void *, float);
extern "C" void Update__6CameraFv(void *);
extern "C" void ResetFollowCamera__6CameraFv(void *);
extern "C" void Init__6CameraFv(void *);
extern "C" void Reset__19EntityAttackManagerFv(void *);
extern "C" void LoadOverlay__13EntityManagerFPcPc(void *, char *, char *);
extern "C" void InitWorld__9MaxEngineFPvP16PResourceManager(void *, void *, void *);
extern "C" void InitSwordBGAnimList__13EntityManagerFP9PMeshNode(void *, void *);
extern "C" void LoadApparitionData__13EntityManagerFi(void *, int);
extern "C" void SpawnEditedInstances__13EntityManagerFPcb(void *, char *, bool);
extern "C" void InitHud__9InterfaceFv(void *);
extern "C" void scePcStop(void);
extern "C" void SetLevelParameters__6PSoundFUiUiUiUi(void *, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void EnableLevelProcessing__6PSoundFb(void *, bool);
extern "C" void PSoundRestart__6PSoundFv(void *);
extern "C" void CutSceneLeave__6PSoundFUi(void *, unsigned int);
extern "C" void Abort__15PCutScenePlayerFv(void *);
extern "C" void EnableParticleFx__13EntityManagerFb(void *, bool);
extern "C" int MapScreen__10MaximoMainFv(void *);
extern int mbHard__15EntityBaseClass;
extern unsigned char mbGlobalSleep__15EntityBaseClass;
// TODO(header): foreign declarations for ScreenAdjust
// The copy constructor makes PMat4 non-POD, so a by-value PMat4 parameter arrives by reference without a callee copy.
struct PMat4 {
    PMat4() {}
    PMat4(const PMat4 &);
    char _pad00[0x40];
};
// Four debug lines: start, end, start colour, end colour (x, y, z, w each).
struct tagVuLineBuf { float m_unk00[64]; };
extern "C" int ReadNew__3PadFv(void *pThis);
extern "C" void SetTvOffset__10PGfxEngineFii(void *pThis, int nX, int nY);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void BeginDebugRender__10PGfxEngineFv(void *pThis);
extern "C" void EndDebugRender__10PGfxEngineFv(void *pThis);
extern "C" void DrawLines__10PGfxEngineFP9tagVuLinei(void *pThis, void *pLines, int nCount);
extern "C" void InitRender__9InterfaceFv(void *pThis);
extern "C" void InitStatic__15EntityBaseClassFP16PResourceManagerP13EntityManagerP9PFrustrum(void *, void *, void *);
extern "C" void LoadResource__13EntityManagerFPcb(void *, const char *, bool);
extern "C" void StaticDemo__9InterfaceFPCcUiUiiUs(void *, const char *, unsigned int, unsigned int, int, unsigned short);
extern "C" void Reset__13EntityManagerFb(void *, bool);
extern "C" void Destroy__9InterfaceFv(void *);
extern "C" void Destroy__9MaxEngineFv(void *);
extern "C" int PlayMovie__9MaxEngineFiiUi(void *, int, int, unsigned int);
extern "C" void StopAllSounds__6PSoundFv(void *);
extern "C" void Unload__15PCutScenePlayerFb(void *, int);
extern float GAME_FPS;
extern unsigned char gUnitMatrix[64];
extern unsigned char lit_002403B0[128];
extern u_long128 lit_00240380;
extern u_long128 lit_00240390;
extern u_long128 lit_002403A0;
extern u_long128 lit_003016E0;
extern u_long128 lit_003016F0;
extern "C" void sceVu0AddVector(void *pDst, void *pA, void *pB);
extern "C" void sceVu0MulVector(void *pDst, void *pA, void *pB);
extern "C" void StopAllRegularSounds__6PSoundFv(void *pThis);
extern "C" int Init__13PScreenBlurFxFfffffffb(void *pThis, float, float, float, float, float, float, float, bool);
extern "C" void __ct__13PScreenBlurFxFv(void *pThis);
extern "C" void *__dt__13PScreenBlurFxFv(void *pThis, short nFlag);
extern "C" void Animate__13PScreenBlurFxFf(void *pThis, float fStep);
extern "C" void Render__13PScreenBlurFxFv(void *pThis);
extern "C" void SkipToFadeOut__13PScreenBlurFxFv(void *pThis);
extern "C" void BeginFxRender__10PGfxEngineFv(void *pThis);
extern "C" void EndFxRender__10PGfxEngineFv(void *pThis);
extern "C" void BeginSprites__10PGfxEngineFv(void *pThis);
extern "C" void EndSprites__10PGfxEngineFv(void *pThis);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTex, void *pVec, bool bFlag, unsigned int nA, unsigned int nB);
extern "C" void SetScreenMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetViewMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetClipMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void DrawSprites__10PGfxEngineFP11tagVuSpriteib(void *pThis, void *pSprites, int nA, bool bFlag);
// GameOver frame: PScreenBlurFx at 0x50, four-float vectors at 0x8500..0x8550, sprite table at 0x8550.
union GameOverVec4 {
    u_long128 q;
    float f[4];
};
struct GameOverFrame {
    char blur[0x84B0];
    GameOverVec4 v8500;
    GameOverVec4 v8510;
    GameOverVec4 v8520;
    GameOverVec4 v8530;
    GameOverVec4 v8540;
    unsigned char sprites[0x80];
};
struct PMChildList {
    unsigned int count;     // child count
    unsigned int m_unk4;
    PMNode **children;      // child array
};
class PMNode {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2(float);
    virtual void Slot3();
    virtual void Slot4(int, float, float, int, int);
    virtual void Slot5(void *);
    PMNode *Find(unsigned int id);
    void SetAnimLoopCount(int arg0, bool arg1);
    void EnableAnim(bool arg0, bool arg1);
    char _pad000[0x10];
    PMChildList m_unk14;
    char _pad020[0x2C - 0x20];
    int m_unk2C;            // 0x2C, zeroed by LoadTitleMesh
    char _pad030[0x3E - 0x30];
    unsigned char m_unk3E;  // flags
    signed char m_unk3F;  // flags, low 3 bits tested by TitleDemo
};

// FUNCTION: 0x00134940 UpdateGameTimes__10MaximoMainFv
void MaximoMain::UpdateGameTimes() {
    unsigned int old;

    m_unk19B6C += U_MILLISEC_PER_FRAME_HI;
    old = m_unk19B70;
    m_unk19B70 += U_MILLISEC_PER_FRAME_LO;
    if ((unsigned int)m_unk19B70 < old) {
        m_unk19B6C++;
    }
    if (!(m_unk19A7C & 4)) {
        m_unk19B74 += U_MILLISEC_PER_FRAME_HI;
        old = m_unk19B78;
        m_unk19B78 += U_MILLISEC_PER_FRAME_LO;
        if ((unsigned int)m_unk19B78 < old) {
            m_unk19B74++;
        }
    }
    if (!(m_unk19A7C & 8)) {
        m_unk19B7C += U_MILLISEC_PER_FRAME_HI;
        old = m_unk19B80;
        m_unk19B80 += U_MILLISEC_PER_FRAME_LO;
        if ((unsigned int)m_unk19B80 < old) {
            m_unk19B7C++;
        }
    }
}

// FUNCTION: 0x00134AE0 InitGameTimes__10MaximoMainFv
void MaximoMain::InitGameTimes() {
    m_unk19B6C = 0;
    m_unk19B70 = 0;
    m_unk19B74 = 0;
    m_unk19B78 = 0;
    m_unk19B7C = 0;
    m_unk19B80 = 0;
}

// FUNCTION: 0x001357C0 Controls__10MaximoMainFv
void MaximoMain::Controls() {
    int nState = 0;
    int nPad;
    float f17 = 17.0f;
    PMNode *pNode = GetResource__16PResourceManagerFUib((char *)this + 0x188A4, 0x8100003DU, false);
    if (pNode == 0) {
        CdsAssert__FPciPc("MaximoMain.cpp", 0x1734, "pMeshNode");
    }
    AddMeshLayer__9InterfaceFP6PMNode(gInterface, pNode);
    ((FontManager *)(gInterface + 0x80))->DisplayString(0x25C, 0, 0, false);
    for (;;) {
        nPad = *(unsigned short *)(gPad + 0x110);
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        switch (nState) {
        case 0:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface,0.0f, 17.0f, true, 0);
            nState++;
            break;
        case 1:
            if (gInterface[0x425] == 0) {
                nState++;
            }
            break;
        case 2:
            if (nPad & 0x1000) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                nState++;
            }
            break;
        case 3:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface,255.0f, f17, true, 0);
            nState++;
            break;
        case 4:
            if (gInterface[0x425] == 0) {
                ((FontManager *)(gInterface + 0x80))->RemoveText((unsigned short)6);
                DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pNode);
                return;
            }
            break;
        }
        pNode->Slot4(0, 0.0f, 1.0f, 0, 0);
        Render__9InterfaceFi(gInterface, 0);
    }
}

// Element list at gInterface + 0x404: count, next index, element pointers.
struct TVList {
    unsigned int m_unk0;
    unsigned int m_unk4;
    char **m_unk8;
};

// FUNCTION: 0x001359D0 TVAdjust__10MaximoMainFv
void MaximoMain::TVAdjust() {
    int nState = 0;
    TVList *pList = (TVList *)(gInterface + 0x404);
    char *pElem;
    PMNode *pNode;
    int nPad;
    unsigned int nIdx;

    pList->m_unk4 = 0;
    pElem = (pList->m_unk0 != 0) ? pList->m_unk8[0] : 0;
    while (pElem != 0) {
        *(int *)(pElem + 0x2C) = 0;
        nIdx = pList->m_unk4 + 1;
        pList->m_unk4 = nIdx;
        pElem = (nIdx < pList->m_unk0) ? pList->m_unk8[pList->m_unk4] : 0;
    }
    pNode = GetResource__16PResourceManagerFUib((char *)this + 0x188A4, 0x81000036U, false);
    if (pNode == 0) {
        CdsAssert__FPciPc("MaximoMain.cpp", 0x16F0, "pMeshNode");
    }
    AddMeshLayer__9InterfaceFP6PMNode(gInterface, pNode);
    ((FontManager *)(gInterface + 0x80))->DisplayString(0x25A, 0, 0, false);
    for (;;) {
        nPad = *(unsigned short *)(gPad + 0x110);
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        switch (nState) {
        case 0:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 17.0f, true, 0);
            nState++;
            break;
        case 1:
            if (gInterface[0x425] == 0) {
                nState++;
            }
            break;
        case 2:
            if (nPad & 0x1000) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                nState++;
            }
            break;
        case 3:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 17.0f, true, 0);
            nState++;
            break;
        case 4:
            if (gInterface[0x425] == 0) {
                ((FontManager *)(gInterface + 0x80))->RemoveText((unsigned short)6);
                DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pNode);
                pList->m_unk4 = 0;
                pElem = (pList->m_unk0 != 0) ? pList->m_unk8[0] : 0;
                while (pElem != 0) {
                    *(int *)(pElem + 0x2C) = 0x3F800000;
                    nIdx = pList->m_unk4 + 1;
                    pList->m_unk4 = nIdx;
                    pElem = (nIdx < pList->m_unk0) ? pList->m_unk8[pList->m_unk4] : 0;
                }
                return;
            }
            break;
        }
        Render__9InterfaceFi(gInterface, 0);
    }
}

// FUNCTION: 0x00135CA0 ScreenAdjust__10MaximoMainFRiRi
int MaximoMain::ScreenAdjust(int &arg0, int &arg1)
{
    int state;
    bool moved;
    unsigned short pad;
    int c;
    float f17 = 17.0f;

    state = 0;
    ((FontManager *)(gInterface + 0x80))->DisplayString(0x257, 0, 0, false);
    tagVuLineBuf lines = {{
        -32.0f, 22.0f, 0.0f, 1.0f, 32.0f, 22.0f, 0.0f, 1.0f, 255.0f, 0.0f, 0.0f, 0.0f, 255.0f, 0.0f, 0.0f, 0.0f,
        32.0f, 22.0f, 0.0f, 1.0f, 32.0f, -22.0f, 0.0f, 1.0f, 255.0f, 0.0f, 0.0f, 0.0f, 255.0f, 0.0f, 0.0f, 0.0f,
        32.0f, -22.0f, 0.0f, 1.0f, -32.0f, -22.0f, 0.0f, 1.0f, 255.0f, 0.0f, 0.0f, 0.0f, 255.0f, 0.0f, 0.0f, 0.0f,
        -32.0f, -22.0f, 0.0f, 1.0f, -32.0f, 22.0f, 0.0f, 1.0f, 255.0f, 0.0f, 0.0f, 0.0f, 255.0f, 0.0f, 0.0f, 0.0f,
    }};
    while (1) {
        InitRenderFrame__9MaxEngineFbUi(this, 0, 0);
        switch (state) {
        case 0:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 17.0f, true, 0);
            state++;
            *(int *)(gInterface + 0x1C0) = 0x81;
            break;
        case 1:
            if (gInterface[0x425] == 0) state++;
            break;
        case 2:
            moved = 0;
            pad = *(unsigned short *)(gPad + 0x110);
            if (pad & 0x1000) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                state++;
            } else {
                if (pad & 1) {
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                    arg0 = 0;
                    moved = 1;
                    arg1 = 0;
                } else {
                    c = ReadNew__3PadFv(gPad) & 0xFFFF;
                    if (c & 0x50) {
                        int v = arg1 + ((c & 0x40) ? 2 : -2);
                        if (v >= -32 && v < 33) {
                            arg1 = v;
                            moved = 1;
                        }
                    }
                    if (c & 0xA0) {
                        int v = arg0 + ((c & 0x20) ? 2 : -2);
                        if (v >= -32 && v < 33) {
                            arg0 = v;
                            moved = 1;
                        }
                    }
                }
                if (moved) SetTvOffset__10PGfxEngineFii(gGfxEng, arg0, arg1);
            }
            break;
        case 3:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, f17, true, 0);
            state++;
            break;
        case 4:
            if (gInterface[0x425] == 0) {
                ((FontManager *)(gInterface + 0x80))->RemoveText((unsigned short)6);
                *(int *)(gInterface + 0x1C0) = 0x89;
                return 1;
            }
            break;
        }
        PMat4 mat;
        sceVu0UnitMatrix(&mat);
        SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, &mat);
        InitRender__9InterfaceFv(gInterface);
        BeginDebugRender__10PGfxEngineFv(gGfxEng);
        DrawLines__10PGfxEngineFP9tagVuLinei(gGfxEng, &lines, 4);
        EndDebugRender__10PGfxEngineFv(gGfxEng);
        Render__9InterfaceFi(gInterface, 0);
    }
}

// Byte fields of MemorySetting read by RefreshOptionsValue; the struct is only a view.
struct MemorySettingBytes {
    unsigned char m_unk0;
    unsigned char m_unk1;
    unsigned char m_unk2;
    unsigned char m_unk3;
    signed char m_unk4;
    signed char m_unk5;
    short m_unk6;
    short m_unk8;
    char _pad0A[2];
};

// DRAFT: 0x00135FB0 RefreshOptionsValue__10MaximoMainFP13MemorySettingb
// note: DIFF 14 words; the original keeps the MemorySetting pointer in s1 and the bool in s0, ours swaps them (only the 14 s0/s1 lines differ). Tried: bool->unsigned char for SetMonoOut and EnableVibrate (147->45->14), inline cast without local (139), bool/int local copy of arg1 (14/130), mem declared then assigned (14), arg1-first condition (54), register hint on mem (14), !m_unk19B44 form (14), direct arg0 cast in first block (14), unsigned char* mem (105).
void MaximoMain::RefreshOptionsValue(MemorySetting *arg0, bool arg1) {
    MemorySettingBytes *mem = (MemorySettingBytes *)arg0;
    if (m_unk19B44 == 0 || arg1) {
        SetMonoOut__6PSoundFb(&gSound, mem->m_unk3);
        if (mem->m_unk3 != 0) {
            SetColor__8FontNodeF9FontColor(m_unk19AE0, 7);
            SetColor__8FontNodeF9FontColor(m_unk19AE4, 4);
        } else {
            SetColor__8FontNodeF9FontColor(m_unk19AE0, 4);
            SetColor__8FontNodeF9FontColor(m_unk19AE4, 7);
        }
    }
    if (m_unk19B44 == 1 || arg1) {
        SetMainMusicRelVolume__6PSoundFUi(&gSound, (unsigned int)mem->m_unk4);
        ScaleSet__6PMNodeFffff(m_unk19B3C, (float)mem->m_unk4 / 100.0f, 1.0f, 1.0f, 1.0f);
    }
    if (m_unk19B44 == 2 || arg1) {
        SetEffectsRelVolume__6PSoundFUi(&gSound, (unsigned int)mem->m_unk5);
        ScaleSet__6PMNodeFffff(m_unk19B40, (float)mem->m_unk5 / 100.0f, 1.0f, 1.0f, 1.0f);
    }
    if (m_unk19B44 == 3 || arg1) {
        EnableVibrate__3PadFb(&gPad, mem->m_unk1);
        if (mem->m_unk1 != 0) {
            SetColor__8FontNodeF9FontColor(m_unk19B04, 4);
            SetColor__8FontNodeF9FontColor(m_unk19B08, 7);
        } else {
            SetColor__8FontNodeF9FontColor(m_unk19B04, 7);
            SetColor__8FontNodeF9FontColor(m_unk19B08, 4);
        }
    }
}

// TODO(header): foreign declarations for Options
extern "C" void GetSetting__10MemoryCardFP13MemorySetting(void *, void *);
extern "C" void SetSetting__10MemoryCardFP13MemorySetting(void *, void *);
extern "C" void ResetSetting__10MemoryCardFv(void *);
extern "C" void SetVibrate__3PadFQ23Pad7VibTypeUc(void *, int, unsigned char);
extern "C" void StopSoundBySoundRef__6PSoundFUi(void *, unsigned int);

#define OPT_ROW(i) (((OptionsRow *)((char *)this + 0x19ADC))[i])
struct OptionsRow {
    FontNode *m_unk0;
    FontNode *m_unk4;
    FontNode *m_unk8;
};

// DRAFT: 0x001361F0 Options__10MaximoMainFv
// note: DIFF 529 words; stack layout differs (original frame 0xE0 with nAdjust 0xA0, nCool 0xB0, set 0xC8, ours 0xF0 with set spilled to other slots), nSound spilled instead of held in fp, pMesh in fp not s7, state switch/case-5 shape not yet aligned. Tried: local declaration order (3 variants), set struct size 0xA/0x10.
int MaximoMain::Options() {
    int nState;
    PMNode *pMesh;
    int nAdjust;
    int nCool;
    int nSound;
    MemorySettingBytes set;
    int nA;
    int nB;
    FontManager *pFont = (FontManager *)(gInterface + 0x80);

    m_unk19B44 = 0;
    nAdjust = 0;
    GetSetting__10MemoryCardFP13MemorySetting(gMC, &set);
    nSound = 0;
    nCool = 0;
    nState = 0;
    for (;;) {
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        switch (nState) {
        case 0: {
            TVList *pList;
            int i;
            int n;
            pMesh = GetResource__16PResourceManagerFUib((char *)this + 0x188A4, 0x81000037U, false);
            if (pMesh == 0) {
                CdsAssert__FPciPc("MaximoMain.cpp", 0x14FB, "pMeshNode");
            }
            pList = (TVList *)((char *)pMesh + 0x14);
            m_unk19B3C = (PMNode *)((pList->m_unk0 >= 2) ? pList->m_unk8[1] : 0);
            m_unk19B40 = (PMNode *)((pList->m_unk0 != 0) ? pList->m_unk8[0] : 0);
            ScaleSet__6PMNodeFffff(m_unk19B3C, (float)set.m_unk4 / 100.0f, 1.0f, 1.0f, 1.0f);
            ScaleSet__6PMNodeFffff(m_unk19B40, (float)set.m_unk5 / 100.0f, 1.0f, 1.0f, 1.0f);
            if (!(m_unk19B3C && m_unk19B40)) {
                CdsAssert__FPciPc("MaximoMain.cpp", 0x1504, "mpMusicSlider && mpEffectSlider");
            }
            AddMeshLayer__9InterfaceFP6PMNode(gInterface, pMesh);
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 17.0f, true, 0);
            n = 0;
            for (i = 0; i < 8; i++) {
                FontNode *p = (FontNode *)pFont->DisplayString(0x249 + n, 0, 0, false);
                n++;
                OPT_ROW(i).m_unk0 = p;
                p->m_unk8 = 0x3F19999A;
                if (i == 3 || i == 0) {
                    p = (FontNode *)pFont->DisplayString(0x249 + n, 0, 0, false);
                    n++;
                    OPT_ROW(i).m_unk4 = p;
                    p->m_unk8 = 0x3F19999A;
                    p = (FontNode *)pFont->DisplayString(0x249 + n, 0, 0, false);
                    n++;
                    OPT_ROW(i).m_unk8 = p;
                    p->m_unk8 = 0x3F19999A;
                }
            }
            RefreshOptionsValue((MemorySetting *)&set, true);
            pFont->DisplayString(0x249 + n, 0, 0, false);
            nState++;
            OPT_ROW(m_unk19B44).m_unk0->m_unk8 = 0x3F800000;
            break;
        }
        case 1:
            if (gInterface[0x425] == 0) {
                nState++;
            }
            break;
        case 2: {
            int nPush = ReadPush__3PadFv(gPad) & 0xFFFF;
            int nHeld = ReadNew__3PadFv(gPad) & 0xFFFF;
            if (nPush & 0x1000) {
                nState++;
                m_unk19B44 = 0;
                nAdjust = 0;
                if (nSound != 0) {
                    StopSoundBySoundRef__6PSoundFUi(gSound, nSound);
                    nSound = 0;
                }
            } else if (nPush & 0x50) {
                OPT_ROW(m_unk19B44).m_unk0->m_unk8 = 0x3F19999A;
                if (nSound != 0) {
                    StopSoundBySoundRef__6PSoundFUi(gSound, nSound);
                    nSound = 0;
                }
                if (nPush & 0x40) {
                    m_unk19B44++;
                    if (m_unk19B44 >= 8) {
                        m_unk19B44 = 0;
                    }
                } else {
                    m_unk19B44--;
                    if (m_unk19B44 < 0) {
                        m_unk19B44 = 7;
                    }
                }
                OPT_ROW(m_unk19B44).m_unk0->m_unk8 = 0x3F800000;
                if (m_unk19B44 == 2) {
                    nSound = PlaySoundUbiquitous__6PSoundFUi(gSound, 0x1C7);
                }
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
            }
            switch (m_unk19B44) {
            case 0:
                if (nPush & 0xA0) {
                    set.m_unk3 = (set.m_unk3 == 0);
                    RefreshOptionsValue((MemorySetting *)&set, false);
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                }
                break;
            case 1: {
                int v = set.m_unk4;
                if (nHeld & 0xA0) {
                    if ((nHeld & 0x80) && v > 0) {
                        v--;
                    } else if ((nHeld & 0x20) && v < 100) {
                        v++;
                    }
                    if (v != set.m_unk4) {
                        set.m_unk4 = v;
                        RefreshOptionsValue((MemorySetting *)&set, false);
                    }
                }
                break;
            }
            case 2: {
                int v = set.m_unk5;
                if (nHeld & 0xA0) {
                    if ((nHeld & 0x80) && v > 0) {
                        v--;
                    } else if ((nHeld & 0x20) && v < 100) {
                        v++;
                    }
                    if (v != set.m_unk5) {
                        set.m_unk5 = v;
                        RefreshOptionsValue((MemorySetting *)&set, false);
                        if (nCool == 0) {
                            nCool = 0xF;
                            PlaySoundUbiquitous__6PSoundFUi(gSound, 0x1C5);
                        }
                        if (nCool != 0) {
                            nCool--;
                        }
                    } else {
                        nCool = 0;
                    }
                }
                break;
            }
            case 3:
                if (nPush & 0xA0) {
                    set.m_unk1 = (set.m_unk1 == 0);
                    RefreshOptionsValue((MemorySetting *)&set, false);
                    if (set.m_unk1 != 0) {
                        SetVibrate__3PadFQ23Pad7VibTypeUc(gPad, 2, (unsigned char)(0.5f * GAME_FPS));
                    }
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                }
                break;
            case 4:
                if (nPush & 0x4000) {
                    nState++;
                    nAdjust = 1;
                }
                break;
            case 5:
                if (nPush & 0x4000) {
                    nState++;
                    nAdjust = 2;
                }
                break;
            case 6:
                if (nPush & 0x4000) {
                    nState++;
                    nAdjust = 3;
                }
                break;
            case 7:
                if (nPush & 0x4000) {
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                    ResetSetting__10MemoryCardFv(gMC);
                    GetSetting__10MemoryCardFP13MemorySetting(gMC, &set);
                    RefreshOptionsValue((MemorySetting *)&set, true);
                }
                break;
            default:
                ((0) ? (void)0 : CdsAssert__FPciPc("MaximoMain.cpp", 0x15CD, "This is not an option yet"));
                break;
            }
            break;
        }
        case 3:
            PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 17.0f, true, 0);
            nState++;
            break;
        case 4:
            if (gInterface[0x425] == 0) {
                DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pMesh);
                pFont->RemoveText((unsigned short)6);
                SetSetting__10MemoryCardFP13MemorySetting(gMC, &set);
                if (nAdjust == 0) {
                    return 0;
                }
                nState++;
            }
            break;
        case 5:
            switch (nAdjust) {
            case 1:
                nA = set.m_unk6;
                nB = set.m_unk8;
                if (ScreenAdjust(nA, nB)) {
                    set.m_unk6 = nA;
                    set.m_unk8 = nB;
                }
                break;
            case 2:
                TVAdjust();
                break;
            case 3:
                Controls();
                break;
            }
            nState = 0;
            continue;
        }
        pMesh->Slot4(0, 0.0f, 1.0f, 0, 0);
        Render__9InterfaceFi(gInterface, 0);
    }
}

// DRAFT: 0x00136BD0 GameOver__10MaximoMainFv
// note: 331 words differ: frame is 0x8630 vs 0x85D0 (saves s3..s7 and fp, the frame base and vector addresses kept live across calls, where the original recomputes sp+N); this kept in s3 not s2; fAcc multiply sits before the ctor call. Tried ctor first (358 words, worse).
void MaximoMain::GameOver()
{
    GameOverFrame frame;
    PMNode *pTex;
    float fAcc;
    float fStep;
    float fTwo;
    int nState;
    int nLeft;
    unsigned char *pSrc;
    unsigned char *pDst;
    u_long128 qTemp;

    fAcc = 4.0f * GAME_FPS;
    __ct__13PScreenBlurFxFv(&frame);
    frame.v8500.q = lit_00240380;
    frame.v8510.q = lit_003016E0;
    fStep = 4.0f * GAME_FPS;
    frame.v8510.f[3] = 1.0f / fStep;
    frame.v8520.q = lit_00240390;
    frame.v8530.q = lit_002403A0;
    frame.v8540.q = lit_003016F0;
    frame.v8540.f[0] = 0.4f / fStep;

    pSrc = lit_002403B0;
    pDst = frame.sprites;
    nLeft = 4;
    do {
        nLeft--;
        qTemp = *(u_long128 *)(pSrc + 0x10);
        *(u_long128 *)pDst = *(u_long128 *)pSrc;
        pSrc += 0x20;
        *(u_long128 *)(pDst + 0x10) = qTemp;
        pDst += 0x20;
    } while (nLeft > 0);

    pTex = GetResource__16PResourceManagerFUib((char *)this + 0x137E0 + 0x50C4, 0x840001B8U, false);
    fTwo = 2.0f * GAME_FPS;
    Init__13PScreenBlurFxFfffffffb(&frame, fTwo, fAcc, fTwo, 129.0f, 129.0f, 129.0f, 96.0f, true);
    StopAllRegularSounds__6PSoundFv(gSound);
    nState = 0;
loop_3:
    switch (nState) {
    case 3:
        break;
    case 0:
        nState = 2;
        Destroy__9InterfaceFv(gInterface);
        FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 2.125f, true, 0);
        SetMainMusicRelVolume__6PSoundFUi(gSound, gMC[0x21D]);
        PlayMusic__6PSoundFUi(gSound, 0x1C);
    default:
    block_17:
        if (nState > 0) {
            if (!(fAcc <= 0.0f)) {
                fAcc -= 1.0f;
            } else {
                fAcc = 0.0f;
            }
        }
        if ((frame.v8500.f[3] < 1.0f) || !(frame.v8500.f[3] <= 0.0f)) {
            sceVu0AddVector(&frame.v8500, &frame.v8500, &frame.v8510);
            if (frame.v8520.f[3] < 1.0f) {
                sceVu0AddVector(&frame.v8530, &frame.v8530, &frame.v8540);
                sceVu0MulVector(&frame.sprites[0x30], &frame.v8520, &frame.v8530);
            }
        }
        this->m_unk19AD8 = RenderSkybox__9MaxEngineFi(this, 3);
        RenderWorld__9MaxEngineFib(this, 3, false);
        this->m_unk19AD8 += Render__13EntityManagerFP13PLightManager((char *)this + 0x137E0, (char *)this + 0x1F0);
        RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(this, (char *)this + 0x19760, 3, 2);
        Animate__13PScreenBlurFxFf(&frame, 1.0f);
        Render__13PScreenBlurFxFv(&frame);
        Render__9InterfaceFi(gInterface, 0);
        BeginFxRender__10PGfxEngineFv(gGfxEng);
        SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, (int)pTex, &frame.v8500, true, 0x48, 0x50000);
        SetScreenMatrix__10PGfxEngineFP5PMat4(gGfxEng, gInterface);
        SetViewMatrix__10PGfxEngineFP5PMat4(gGfxEng, gInterface + 0x40);
        SetClipMatrix__10PGfxEngineFP5PMat4(gGfxEng, gEng + 0x50);
        SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, gUnitMatrix);
        BeginSprites__10PGfxEngineFv(gGfxEng);
        DrawSprites__10PGfxEngineFP11tagVuSpriteib(gGfxEng, frame.sprites, 2, true);
        EndSprites__10PGfxEngineFv(gGfxEng);
        EndFxRender__10PGfxEngineFv(gGfxEng);
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        goto loop_3;
    case 1:
        if (gInterface[0x425] == 0) {
            nState += 1;
        }
        goto block_17;
    case 2:
        if ((fAcc == 0.0f) || (*(unsigned short *)(gPad + 0x110) & 0x1000)) {
            SkipToFadeOut__13PScreenBlurFxFv(&frame);
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 2.125f, true, 0);
            nState += 1;
            frame.v8510.f[3] = -frame.v8510.f[3];
        }
        goto block_17;
    }
    if (gInterface[0x425] != 0) {
        goto block_17;
    }
    if (!(frame.v8500.f[3] <= 0.0f)) {
        goto block_17;
    }
    SetMainMusicRelVolume__6PSoundFUi(gSound, gMC[0x21C]);
    Destroy__9InterfaceFv(gInterface);
    Reset__13EntityManagerFb((char *)this + 0x137E0, true);
    Destroy__9MaxEngineFv(this);
    gGfxEng[0x158E26] = 1;
    __dt__13PScreenBlurFxFv(&frame, -1);
}

// DRAFT: 0x00137190 GameOptions__10MaximoMainFv
// note: 113 words differ: dispatch uses v1 for the constant 1 (original v0) and the case bodies sit in another order; the original's render calls follow the case-0 body, ours follow the loop. Tried case 2 before default with goto (113), skybox store after the call (113), accumulator temporaries for the entity and UI renders (113).
void MaximoMain::GameOptions() {
    int state = 0;
    unsigned int cats;
    int music;

    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 8.5f, true, 0);
    ((FontManager *)(gInterface + 0x80))->RemoveText((unsigned short)4);
    music = m_unk19B48;
    if (music == 0) {
        music = 5;
    }
    if (gbMusic != 0) {
        PlayMusic__6PSoundFUi(gSound, music);
    }
    cats = GetPauseCategories__6PSoundFv(gSound);
    SetPauseCategories__6PSoundFUi(gSound, cats & ~2u);
    for (;;) {
        switch (state) {
        case 0:
            if (gInterface[0x425] == 0) {
                state = 1;
            }
            break;
        case 1:
            *(int *)(gInterface + 0x1C0) = 0x89;
            Options();
            *(int *)(gInterface + 0x1C0) = 0xF;
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 8.5f, true, 0);
            PauseDisplay(1);
            state = 2;
            /* fall through */
        default:
        block_16:
            InitRenderFrame__9MaxEngineFbUi(this, false, 0);
            continue;
        case 2:
            if (gInterface[0x425] == 0) {
                m_unk19A70 = 1;
            }
            break;
        }
        break;
    }
    m_unk19AD8 = RenderSkybox__9MaxEngineFi(this, 3);
    RenderWorld__9MaxEngineFib(this, 3, false);
    m_unk19AD8 = m_unk19AD8 + Render__13EntityManagerFP13PLightManager((char *)this + 0x137E0, (char *)this + 0x1F0);
    RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(this, (char *)this + 0x19760, 3, 2);
    m_unk19AD8 = m_unk19AD8 + Render__9InterfaceFi(gInterface, 3);
    if (m_unk19A70 == 2) {
        goto block_16;
    }
    SetPauseCategories__6PSoundFUi(gSound, cats);
    if (music != m_unk19B48 && gbMusic != 0) {
        PlayMusic__6PSoundFUi(gSound, m_unk19B48);
    }
}

// DRAFT: 0x00137430 LoadGame__10MaximoMainFv
// note: 32 words differ (was 39). The switch(result) case 0xB form drops the count. Remaining: the 0x78 beq delay slot takes the body's first instruction (original has nop, hoisted lui); the 0x6C beq targets 0xE0 in ours, 0xE4 in original. Tried: nested if/return, inverted 0xB test (worse), do/while, flat if/break.
int MaximoMain::LoadGame() {
    ResetGameData__10MemoryCardFv(gMC);
    InitLoadGame__10MemoryCardFv(gMC);
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 8.5f, true, 0);
    miAbilityCount__15EntityBaseClass = 0;
    for (;;) {
        InitRenderFrame__9MaxEngineFbUi(this, 0, 0);
        int result = LoadGame__10MemoryCardFv(gMC);
        if (result != -1) {
            switch (result) {
            case 0xB:
                m_unk19A78 = gMC[0x22C];
                if (m_unk19A78 >= 0x14) {
                    m_unk19A78 = 0x13;
                }
                return 1;
            }
            m_unk19A78 = 0;
            return 0;
        }
        Render__9InterfaceFi(gInterface, 0);
    }
}

// FUNCTION: 0x00137560 LoadTitleMesh__10MaximoMainFv
void MaximoMain::LoadTitleMesh() {
    static char TITLE[] = "PSXDATA\\GAME\\TITLE.PAK";
    static unsigned int Copyrights[2] = {0x6214ECB4, 0xCC8B1693};
    PMNode *node;
    int i;
    int off;

    m_unk19AC8 = Load__9InterfaceFPCc(gInterface, TITLE);
    m_unk19AC8->SetAnimLoopCount(0, true);
    m_unk19ACC = m_unk19AC8->Find(0xC72EE251);
    if (m_unk19ACC != 0) {
        m_unk19ACC->SetAnimLoopCount(1, true);
    }
    i = 0;
    off = 0;
    do {
        node = m_unk19AC8->Find(*(unsigned int *)((char *)Copyrights + off));
        if (node != 0) {
            node->m_unk2C = 0;
            if (i == 1) {
                m_unk19AD0 = node;
            }
        }
        i++;
        off += 4;
    } while (i < 2);
    m_unk19AC8->EnableAnim(true, true);
}

// FUNCTION: 0x00137540 InitStaticDemo__10MaximoMainFv
void MaximoMain::InitStaticDemo() {
    m_unk19784 = 0;
    m_unkD0 = 0;
    m_unkD4 = 0;
    m_unkD8 = 0x42180000;
}

// FUNCTION: 0x00137680 TitleDemo__10MaximoMainFv
int MaximoMain::TitleDemo() {
    int state = 0;
    int result = 0;
    int timer = (int)(30.0f * GAME_FPS);
    SoundGainEEControl__9InterfaceFv(gInterface);
    LoadTitleMesh();
    m_unk19B4C = 0;
    RestartAndLoadInterfaceTypeBank__6PSoundFUi(gSound, 0x72U);
    if (gbMusic != 0) {
        m_unk19B48 = 3;
        PlayMusic__6PSoundFUi(gSound, 3U);
    }
    ResetWarning__11FontManagerFv(gInterface + 0x80);
    for (;;) {
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        switch (state) {
        case 0:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 4.25f, true, 0);
            state += 1;
            /* fall through */
        case 1:
            if (*(unsigned char *)(gInterface + 0x425) == 0) {
                state += 1;
                if (gbMusic != 0) {
                    PlayMusic__6PSoundFUi(gSound, 3U);
                }
            }
            break;
        case 2:
            if (*(unsigned short *)(gPad + 0x110) & 8) {
                m_unk19ACC->Slot2(1000.0f);
                state += 3;
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x1CA);
            } else if (!(GetFrameTime__6PMNodeFv(m_unk19ACC) <= 35.0f)) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x1CC);
                state += 1;
            }
            break;
        case 3:
            if (*(unsigned short *)(gPad + 0x110) & 8) {
                m_unk19ACC->Slot2(1000.0f);
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x1CB);
                state += 2;
            } else if (!(GetFrameTime__6PMNodeFv(m_unk19ACC) <= 75.0f)) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x1CB);
                state += 1;
            }
            break;
        case 4: {
            signed char flags = m_unk19ACC->m_unk3F & 7;
            if (flags == 0 || (*(unsigned short *)(gPad + 0x110) & 8)) {
                m_unk19ACC->Slot2(1000.0f);
                state += 1;
            }
            break;
        }
        case 5:
            PressStart(-0x78);
            if (*(unsigned short *)(gPad + 0x110) & 8) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                result = 1;
            } else {
                timer -= 1;
                if (timer <= 0) {
                    state += 1;
                    float fB = 4.25f; FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, fB, true, 0);
                    if (gbMusic != 0) {
                        FadeOutAllMusic__6PSoundFUi(gSound, 0x1F4U);
                    }
                }
                if (m_unk19AD0 != 0) {
                    float f = *(float *)&m_unk19AD0->m_unk2C;
                    if (f < 1.0f) {
                        f += 0.2f;
                        if (!(f < 1.0f)) {
                            f = 1.0f;
                        }
                        *(float *)&m_unk19AD0->m_unk2C = f;
                    }
                }
            }
            break;
        case 6:
            if (*(unsigned char *)(gInterface + 0x425) == 0) {
                if (gbMusic != 0) {
                    StopMusic__6PSoundFv(gSound);
                }
                return 0;
            }
            if (*(unsigned short *)(gPad + 0x110) & 8) {
                if (gbMusic != 0) {
                    StopMusic__6PSoundFv(gSound);
                }
                FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 8.5f, true, 0);
                result = 1;
            }
            break;
        }
        m_unk19AC8->Slot4(0, 0.0f, 1.0f, 0, 0);
        Render__9InterfaceFi(gInterface, 0);
        if (result != 0) {
            return result;
        }
    }
}

// FUNCTION: 0x00137B00 InitPlayDemo__10MaximoMainFi
void MaximoMain::InitPlayDemo(int arg0) {
    int *entry;
    if (MODE_PAL != 0) {
        entry = (int *)(DemoTableP + m_unk19B54++ * 12);
    } else {
        entry = (int *)(DemoTable + m_unk19B54++ * 12);
    }
    m_unk19A78 = entry[0];
    int value;
    if (arg0 == 2) {
        value = 0x1C20;
    } else {
        value = entry[1];
    }
    m_unk19B5C = value;
    if ((unsigned int)m_unk19B54 >= 2) {
        m_unk19B54 = 0;
    }
    SetInputMode__3PadFQ23Pad10eInputModePQ23Pad9InputDatai(gPad, arg0, (void *)entry[2], 0);
    miRandom__7MathAPI = 0;
    miAbilityCount__15EntityBaseClass = 0;
    ResetGameData__10MemoryCardFv(gMC);
}

// DRAFT: 0x00137C10 AttractDemo__10MaximoMainFv
// note: 148 words differ; dispatch compare order (original tests 0,1,2,3 via beq chain, counter load out of line at 0x137D30) and beq/bne sense. Tried if-chain, else-if chain, switch(state) variants.
int MaximoMain::AttractDemo() {
    int state = 0;
    int r;
    for (;;) {
        switch (state) {
        case 0: {
            int t = TitleDemo();
            DeletePressStart();
            state = (t != 0) ? 1 : 3;
            continue;
        }
        case 1: {
            int g = GameSelect();
            switch (g) {
            case 4:
                state = 3;
                continue;
            case 2:
                state = 2;
                continue;
            case 3:
                return 7;
            case 0:
                return 2;
            case 1:
                m_unk19AC0 = -1;
                return 3;
            }
            continue;
        }
        case 2:
            Options();
            state = 1;
            continue;
        case 3: {
            int count = m_unk19B58 + 1;
            m_unk19B58 = count;
            if (count >= 3) {
                m_unk19B58 = 0;
                if (PlayMovie__9MaxEngineFiiUi(this, 0, 0x320, 0x4009) != 2) {
                    state = 0;
                    continue;
                }
                state = 1;
            } else {
                m_unk19AC8 = 0;
                m_unk19ACC = 0;
                InitPlayDemo(1);
                m_unk19A70 = 0;
                r = Game(1);
                DeletePressStart();
                InitRenderFrame__9MaxEngineFbUi(this, 0, 0);
                StopAllSounds__6PSoundFv(gSound);
                int i = 0;
                int off = 0;
                do {
                    Unload__15PCutScenePlayerFb((char *)this + off + 0x220, 1);
                    i++;
                    off += 0x2140;
                } while (i < 4);
                Reset__13EntityManagerFb((char *)this + 0x137E0, true);
                Destroy__9InterfaceFv(gInterface);
                Destroy__9MaxEngineFv(this);
                ResetGameData__10MemoryCardFv(gMC);
                SetInputMode__3PadFQ23Pad10eInputModePQ23Pad9InputDatai(gPad, 0, 0, 0);
                state = (r == 0) ? 0 : 1;
            }
            continue;
        }
        }
    }
}

// FUNCTION: 0x00137EA0 DeletePressStart__10MaximoMainFv
void MaximoMain::DeletePressStart() {
    if (m_unk19AC4 != 0) {
        ((FontManager *)(gInterface + 0x80))->RemoveText((FontNode *)m_unk19AC4);
        m_unk19AC4 = 0;
    }
}

// DRAFT: 0x00137EF0 PressStart__10MaximoMainFi
// note: 58 words differ: state-machine register picks (at vs v1 for the nMode test, a0 vs a2 for the state load, f0/f1 order in the ramps), nested branch shape; kept pFont local, text load via pFont+0x100, nMode before nFlag (129 -> 101 -> 67 -> 58); ternary assert, state-first reorder (62), and direct m_unk19AD4 reads (58, no change) tried
void MaximoMain::PressStart(int arg0) {
    unsigned char *pFont = gInterface + 0x80;
    unsigned int nMode = *(unsigned int *)pFont;
    int nFlag = *(int *)(gInterface + 0x1B8);
    if (nMode >= 2 && nFlag == 0) return;
    if (m_unk19AC4 != 0) {
        if (Find__6PArrayFPv(pFont, m_unk19AC4) < 0) m_unk19AC4 = 0;
    }
    if (m_unk19AC4 == 0) {
        if (nMode != 0 && nFlag == 0) return;
        m_unk19AD4 = 0;
        char *pText = **(char ***)(pFont + 0x100);
        m_unk19AC4 = DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, pText, 0.0f, (float)arg0, 0, 4, 1);
        if (m_unk19AC4 == 0) CdsAssert__FPciPc("MaximoMain.cpp", 0x122E, "mpPress");
        *(int *)((char *)m_unk19AC4 + 8) = 0;
    }
    float fAlpha = *(float *)((char *)m_unk19AC4 + 8);
    int nState = m_unk19AD4;
    if (nState == 30) {
        fAlpha = fAlpha - 0.1f;
        if (fAlpha <= 0.0f) { fAlpha = 0.0f; m_unk19AD4 = 0; }
    } else if (nState == 0) {
        fAlpha = fAlpha + 0.1f;
        if (!(fAlpha < 1.0f)) { fAlpha = 1.0f; m_unk19AD4 = nState + 1; }
    } else {
        m_unk19AD4 = nState + 1;
    }
    *(float *)((char *)m_unk19AC4 + 8) = fAlpha;
}

// DRAFT: 0x00139AB0 SetMarker__10MaximoMainFP6PMNodeiP6PMNode
// note: 33 words differ (was 34). The PMChildList pointer local fixed one word; the rest is register choice: original keeps count in v1 and children in v0 via addiu v0,s0,0x14 + lw 8(v0), ours count in a0 and children in v1. Tried: children[count], -4 cast, local count, &m_unk14+8 base, else-branch, inline index (all 33)
PMNode *MaximoMain::SetMarker(PMNode *arg0, int arg1, PMNode *arg2) {
    PMNode *node = arg0->Find(*(unsigned int *)(LevelTable + (arg1 << 7)));

    if (node != 0) {
        PMNode *child;
        PMChildList *list = &node->m_unk14;
        if (list->count != 0) {
            PMNode **children = (PMNode **)((char *)list->children - 4);
            child = children[list->count];
        } else {
            child = 0;
        }
        if (child != 0) {
            *(u_long128 *)((char *)arg2 + 0x80) = *(u_long128 *)((char *)child + 0x80);
            arg2->m_unk3E |= 8;
            arg2->Slot4(0, 0.0f, 0.0f, 0, 0);
        }
    }
    return node;
}

// DRAFT: 0x00138110 GameSelect__10MaximoMainFv
// note: DIFF 190; state-0 FadeScreen arg setup (a0 lui, a2=0 hoisted before float loads) and gp reloc for GAME_FPS differ; tried if/else and goto dispatch, enum-arg variants
int MaximoMain::GameSelect() {
    int s0;
    int s1;
    unsigned int s2;
    void *fm = gInterface + 0x80;
    unsigned int s4;
    int t;
    int s7 = 0;

    *(int *)(gInterface + 0x1C0) = 5;
    s0 = 0;
    s2 = 0;
    s1 = 20 * (int)GAME_FPS;
    RemoveAll__11FontManagerFb(fm, true);
    for (;;) {
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        switch (s0) {
        case 0:
            {
                FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 8.5f, false, 0);
                if (m_unk19AC8 == 0) {
                    SoundGainEEControl__9InterfaceFv(gInterface);
                    LoadTitleMesh();
                    ReturnControlOfIOPToMjln__6PSoundFv(gSound);
                    m_unk19ACC->Slot2(1000.0f);
                }
                if (m_unk19AD0 != 0) m_unk19AD0->m_unk2C = 0;
                DisplayString__11FontManagerFiiib(fm, 9, 0, 0, false);
                ResetWarning__11FontManagerFv(fm);
                if (gbMusic != 0) {
                    s0 += 1;
                    m_unk19B48 = 3;
                    PlayMusic__6PSoundFUi(gSound, 3);
                }
            }
            break;
        case 1:
            {
                if (gInterface[0x425] == 0) s0 += 1;
            }
            break;
        case 2:
            {
                s4 = ReadPush__3PadFv(gPad) & 0xFFFF;
                if (s4 & 0x4008) {
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                    if (s2 == 0) {
                        RemoveAll__11FontManagerFb(fm, true);
                        s0 = 4;
                        DisplayString__11FontManagerFiiib(fm, 0xD, 0, 0, false);
                        s2 = 0;
                        SetColor__8FontNodeF9FontColor((0 < *(int *)fm) ? ((void **)*(void ***)((char *)fm + 8))[0] : 0, 4);
                        s1 = 20 * (int)GAME_FPS;
                    } else {
                        if (s2 != 2) FadeOutAllMusic__6PSoundFUi(gSound, 0x1F4);
                        FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 4.25f, true, 0);
                        s0 += 1;
                    }
                    s7 = s2;
                    m_unk19A78 = 0;
                    goto tail;
                }
                if (s4 & 0x50) {
                    void *pNode;
                    void *pNode2;
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
                    pNode = (s2 < *(int *)fm) ? ((void **)*(void ***)((char *)fm + 8))[s2] : 0;
                    ((pNode) ? (void)0 : CdsAssert__FPciPc("MaximoMain.cpp", 0x119B, "pNode"));
                    SetColor__8FontNodeF9FontColor(pNode, 7);
                    s2 += (s4 & 0x40) ? 1 : -1;
                    if (!(s2 < 3)) {
                        s2 = 0;
                        if (!(s4 & 0x40)) s2 = 2;
                    }
                    pNode2 = (s2 < *(int *)fm) ? ((void **)*(void ***)((char *)fm + 8))[s2] : 0;
                    ((pNode2) ? (void)0 : CdsAssert__FPciPc("MaximoMain.cpp", 0x11A2, "pNode"));
                    SetColor__8FontNodeF9FontColor(pNode2, 4);
                    t = 10 * (int)GAME_FPS;
                    if (s1 < t) s1 = t;
                }
                if (!(*(unsigned short *)(gPad + 0x10C) & 1)) {
                    s1 -= 1;
                    if (s1 == 0) {
                        s0 += 1;
                        s7 = 4;
                        FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 8.5f, true, 0);
                    }
                }
            }
            break;
        case 3:
            {
                if (gInterface[0x425] == 0) {
                    Destroy__9InterfaceFv(gInterface);
                    m_unk19AC8 = 0;
                    m_unk19ACC = 0;
                    m_unk19AD0 = 0;
                    RemoveAllParticleSystems__16PParticleManagerFv(gGfxEng + 0x154F00);
                    return s7;
                }
            }
            break;
        case 4:
            {
                unsigned int v = ReadPush__3PadFv(gPad) & 0xFFFF;
                if (v & 0x4008) {
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                    *(unsigned char *)(gMC + 0x26EF) = (unsigned char)s2;
                    FadeOutAllMusic__6PSoundFUi(gSound, 0x1F4);
                    s0 = 3;
                    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 4.25f, true, 0);
                    goto tail;
                }
                if (v & 0x1000) {
                    RemoveAll__11FontManagerFb(fm, true);
                    DisplayString__11FontManagerFiiib(fm, 9, 0, 0, false);
                    s0 = 2;
                    s2 = 0;
                    goto tail;
                }
                if (v & 0xA0) {
                    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
                    SetColor__8FontNodeF9FontColor((s2 < *(int *)fm) ? ((void **)*(void ***)((char *)fm + 8))[s2] : 0, 7);
                    s2 ^= 1;
                    SetColor__8FontNodeF9FontColor((s2 < *(int *)fm) ? ((void **)*(void ***)((char *)fm + 8))[s2] : 0, 4);
                    t = 10 * (int)GAME_FPS;
                    if (s1 < t) s1 = t;
                    goto tail;
                }
                s1 -= 1;
                if (s1 == 0) {
                    s7 = 4;
                    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 8.5f, true, 0);
                    s0 = 3;
                }
            }
            break;
        }
    tail:
        if (m_unk19AC8 != 0) {
            m_unk19AC8->Slot4(0, 0.0f, 1.0f, 0, 0);
            m_unk19ACC->Slot4(0, 0.0f, 1.0f, 0, 0);
        }
        Render__9InterfaceFi(gInterface, 0);
    }
}

// DRAFT: 0x001387C0 MainGame__10MaximoMainFv
// note: DIFF 109; original frame 0x40 keeps this in s1, pEntity in s2, this+0x137E0 in s0 (ours s0/s1, frame 0x30); tried local pMgr (107) and pSelf copy (117)
void MaximoMain::MainGame() {
    char *pGfxEng = (char *)this + 0x188A4;
    m_unk19A74 = 0;
    InitStatic__15EntityBaseClassFP16PResourceManagerP13EntityManagerP9PFrustrum(pGfxEng, (char *)this + 0x137E0, (char *)this + 0xF0);
    LoadResource__13EntityManagerFPcb((char *)this + 0x137E0, "PSXDATA\\RESOURCE\\GLOBAL.PAK", true);
    *(void **)gGfxEng = pGfxEng;
    for (;;) {
        switch (m_unk19A74) {
        case 0:
            StaticDemo__9InterfaceFPCcUiUiiUs(gInterface, "CAPCOM", 1, 0x19B, (int)GAME_FPS * 6, 0);
            m_unk19A74 = 1;
            break;
        case 1:
            ResetGameData__10MemoryCardFv(gMC);
            m_unk19A78 = 0;
            m_unk19A74 = AttractDemo();
            break;
        case 2:
            ResetGameData__10MemoryCardFv(gMC);
            miAbilityCount__15EntityBaseClass = 0;
            PlayMovie__9MaxEngineFiiUi(this, 0, 0, 1);
            m_unk19A74 = 4;
            break;
        case 3:
            if (LoadGame()) {
                m_unk19A74 = 4;
                m_unk19A70 = 7;
            } else {
                m_unk19A74 = 1;
            }
            break;
        case 4: {
            int r = Game(0);
            if (r == 2) {
                m_unk19A74 = 5;
            } else if (r == 1) {
                Reset__13EntityManagerFb((char *)this + 0x137E0, true);
                Destroy__9InterfaceFv(gInterface);
                Destroy__9MaxEngineFv(this);
                m_unk19A74 = 6;
            } else if (r == 0) {
                return;
            }
            break;
        }
        case 5:
            m_unk19A74 = 1;
            break;
        case 6:
            m_unk19A74 = 1;
            break;
        case 7:
            return;
        }
    }
}

// FUNCTION: 0x00138A40 QuitGame__10MaximoMainFv
void MaximoMain::QuitGame() {
    m_unk19A70 = 8;
    float f255 = 255.0f;
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, f255, 4.25f, true, 0);
    FadeOutAllMusic__6PSoundFUi(gSound, 0x3E8);
}

// DRAFT: 0x00138AA0 TextureViewer__10MaximoMainFPQ210MaximoMain12BonusGalleryi
// note: 181 differing words; 0x50 daddiu vs addiu for $s7, spAC/spCC stack slots swapped (0xAC/0xCC), branch offsets follow
int MaximoMain::TextureViewer(MaximoMain::BonusGallery *arg0, int arg1)
{
    PSlideShow spD0;
    FontNode *spCC;
    FontManager *spB0;
    int spAC;
    int var_fp;
    int var_s0;
    int var_s1;
    int var_s2 = arg1;
    int var_s6;
    int var_s7;
    int temp_a0;
    int temp_s0;
    int temp_v0;
    int var_a1;

    var_s7 = 1;
    spD0.Create(0x1C0, 0xD0);
    var_s0 = 0;
    var_s1 = 0;
    spAC = 0;
    PResourceManager sp120;
    char sp1F0[64];
    spB0 = (FontManager *)(gInterface + 0x80);
    spCC = (FontNode *)spB0->DisplayString(0x26F, 0, 0, false);

    for (;;) {
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        if (var_s7 == 0) {
            spD0.Animate(1.0f);
            spD0.Render();
            if (spD0.m_ucUnk41 == 0) {
                Render__9InterfaceFi(gInterface, 0);
            }
        }
        temp_a0 = (*(unsigned short *)(gPad + 0x10C) & 0x10A0) | (*(unsigned short *)(gPad + 0x108) & 0xA0);
        switch (var_s0) {
        case 0:
            InitRenderFrame__9MaxEngineFbUi(this, false, 0);
            DmaWaitForCompletion__Fib(1, false);
            sceGsSyncPath(0, 0);
            var_s0 = 1;
            var_s7 = 1;
            gMC[var_s2 + 0x6B5] = 2;
            var_s6 = 0x3C;
            if ((var_s2 >= 0x12) && (var_s2 < 0x15)) {
                UnloadGlobalResource__16PResourceManagerFv(&sp120);
            } else {
                UnloadGlobalResource__16PResourceManagerFv(&sp120);
                sprintf(sp1F0, "PSXDATA\\GAME\\BONUS%d.PAK", var_s2 + 1);
                temp_s0 = *(int *)(MemMgr + 0x18);
                *(int *)(MemMgr + 0x18) = 1;
                ((LoadGlobalResource__16PResourceManagerFPCcb(&sp120, sp1F0, false) != 0) ? (void)0 : CdsAssert__FPciPc("MaximoMain.cpp", 0xF00, "0"));
                *(int *)(MemMgr + 0x18) = temp_s0;
                ((sp120.GetNumResourcesOfType((eResourceTypes)4, true) != 0) ? (void)0 : CdsAssert__FPciPc("MaximoMain.cpp", 0xF04, "mBonusResource.GetNumResourcesOfType( RES_TEXTURE, true )"));
                if (var_s1 < 0) {
                    var_s1 = sp120.GetNumResourcesOfType((eResourceTypes)4, true) - 1;
                } else {
                    var_s1 = 0;
                }
                var_s0 = 3;
            }
            continue;
        case 1:
            this->m_unk19B68 = 1;
            spCC->m_unk8 = 0;
            if (pBonusScreen != 0) {
                DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pBonusScreen);
                pBonusScreen = 0;
            }
            if (*(int *)gEng != 0) {
                Destroy__6PWorldFv(this);
                RemoveAllFogObjects__16PParticleManagerFv(gGfxEng + 0x154F00);
                this->m_unk19B64 = 0;
            }
            InitRenderFrame__9MaxEngineFbUi(this, false, 0);
            switch (var_s2) {
            case 18:
                var_fp = PlayMovie__9MaxEngineFiiUi(this, 3, 0, 0x1001U);
                break;
            case 19:
                var_fp = PlayMovie__9MaxEngineFiiUi(this, 4, 0, 0x1001U);
                break;
            case 20:
                var_fp = PlayMovie__9MaxEngineFiiUi(this, 5, 0, 0x1001U);
                break;
            }
            var_s0 = 2;
            spCC->m_unk8 = 0x3F800000;
            if (var_fp != 2) {
                continue;
            }
            break;
        case 2:
            var_a1 = var_s2 - 1;
            if (var_s1 >= 0) {
                var_a1 = var_s2 + 1;
            }
            if (var_a1 != var_s2) {
                for (;;) {
                    if (var_a1 == 0x15) {
                        var_a1 = 0;
                    } else if (var_a1 == -1) {
                        var_a1 = 0x14;
                    }
                    if (var_a1 == var_s2) {
                        break;
                    }
                    if (arg0[var_a1].m_unk4 != 0) {
                        var_s2 = var_a1;
                        var_s0 = 0;
                        break;
                    }
                    if (var_s1 < 0) {
                        var_a1 -= 1;
                    } else {
                        var_a1 += 1;
                    }
                    if (var_a1 == var_s2) {
                        break;
                    }
                }
            }
            if (var_s0 != 0) {
                if (var_s1 < 0) {
                    var_s1 = sp120.GetNumResourcesOfType((eResourceTypes)4, true) - 1;
                } else {
                    var_s1 = 0;
                }
                var_s6 = 0x3C;
                var_s0 = 3;
            }
            continue;
        case 3:
            if (temp_a0 & 0x1000) {
                break;
            } else {
                bool show = false;
                if ((spD0.m_ucUnk41 == 0) && (var_s6 == 0)) {
                    if (temp_a0 & 0x20) {
                        var_s1 += 1;
                        show = true;
                    } else if (temp_a0 & 0x80) {
                        var_s1 -= 1;
                        if (var_s1 < 0) {
                            var_s0 = 2;
                        } else {
                            show = true;
                        }
                    } else {
                        show = true;
                    }
                } else {
                    show = true;
                }
                if (show) {
                    temp_v0 = (int)sp120.GetResource(var_s1, (eResourceTypes)4, true);
                    if (temp_v0 == 0) {
                        var_s0 = 2;
                    } else {
                        if ((spD0.m_unk04 == 0) || (var_s7 != 0)) {
                            spD0.SetFirstImage(temp_v0);
                            var_s7 = 0;
                            spAC = temp_v0;
                            var_s6 = 0x3C;
                        }
                        if ((spD0.m_ucUnk41 == 0) && (temp_v0 != spAC)) {
                            spD0.SetNextImage(temp_v0);
                            var_s6 = 0;
                        }
                        var_s6 -= 1;
                        spAC = temp_v0;
                        if (var_s6 <= 0) {
                            var_s6 = 0;
                        }
                    }
                }
                continue;
            }
        }
        break;
    }
    Unload__16PResourceManagerFv(&sp120);
    SetScreenMatrix__10PGfxEngineFP5PMat4(gGfxEng, gEng + 0x10);
    spB0->RemoveText(spCC);
    spB0->InitFrame();
    return var_s2;
}

// DRAFT: 0x00139070 BonusScreen__10MaximoMainFP6PMNode
// note: 564 differing words, size 0xA54 vs 0xA38; state var in s0 (orig s1), this spill at 0xEC (orig 0xFC), gallery array 8 bytes low (0xF8 vs 0x100); tried local reorder and sp280[16] (kept)
void MaximoMain::BonusScreen(PMNode *arg0) {
    PResourceManager sp1B0;
    BonusGallery sp100[21];
    char sp280[16];
    char sp28C[4];
    static int aX;
    static int aY;
    static int aYStart;
    FontNode *spBC;
    FontNode *spB8;
    int spA0;
    int spC0;
    int spD0;
    int spE0;
    int var_s1;
    int var_s1_2;
    int var_s1_3;
    int var_s1_4;
    int var_s2;
    int var_s2_2;
    int var_s2_3;
    int var_s5;
    int var_s6;
    int var_s7;
    int var_fp;
    int var_a1;
    int var_a2;
    int var_a2_2;
    int var_a2_3;
    int var_a3;
    int temp_s2;
    int temp_s3;
    int temp_s4;
    int temp_v0;
    int temp_v1;
    int var_v0_2;
    int var_v0_3;
    signed char var_v0;

    var_s1 = 0;
loop_1:
    InitRenderFrame__9MaxEngineFbUi(this, false, 0);
    *(float *)((char *)this + 0x1E8) = 1.0f;
    switch (var_s1) {
    case 3:
        break;
    case 0:
        FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 4.25f, true, 0);
block_7:
        spBC = (FontNode *)DisplayString__11FontManagerFiiib(gInterface + 0x80, 0x26E, 0, 0, false);
        spB8 = (FontNode *)DisplayString__11FontManagerFiiib(gInterface + 0x80, 0x293, 0, 0, false);
        SoundGainEEControl__9InterfaceFv(gInterface);
        pBonusScreen = Load__6PWorldFPCcb13eTextureGroup(this, BONUSSCREEN_FILE, false, 0x65);
        ReturnControlOfIOPToMjln__6PSoundFv(gSound);
        ResetWarning__11FontManagerFv(gInterface + 0x80);
        ((pBonusScreen != 0) ? (void)0 : CdsAssert__FPciPc("MaximoMain.cpp", 0xD8F, "pBonusScreen"));
        *(float *)((char *)pBonusScreen + 0x2C) = 1.0f;
        *(int *)((char *)pBonusScreen + 0x0C) = 1;
        ((void (*)(void *, int, int, int, int, int))(*(void ***)pBonusScreen)[6])(pBonusScreen, 0, 0, 0, 0, 0x3F800000);
        AddMeshLayer__9InterfaceFP6PMNode(gInterface, pBonusScreen);
        spC0 = 0;
        var_s1_2 = 0;
        var_s5 = 4;
        spD0 = 0;
        spE0 = 0;
        do {
            var_fp = spE0;
            var_s2 = 0;
loop_11:
            {
                static bool init;
                if (!init) {
                    aX = 0xC8;
                    init = true;
                }
            }
            {
                static bool init;
                if (!init) {
                    aY = -0x28;
                    init = true;
                }
            }
            {
                static bool init;
                if (!init) {
                    aYStart = 0x64;
                    init = true;
                }
            }
            temp_v1 = var_s2 + (spD0 * 8);
            temp_s3 = temp_v1 - 1;
            if (temp_s3 != 0x13) {
                if (temp_v1 == 0x16) {
                    var_s2 = 8;
                    spD0 = 2;
                } else {
                    temp_s4 = Level2GalleryMap[temp_s3];
                    if ((temp_s3 == 0xC) || (temp_s3 == 0x10) || (temp_s3 == 0x14)) {
                        var_s6 = var_s5;
                        var_s7 = 2;
                        var_s5 += 1;
                        strcpy(sp280, *(char **)(gInterface + 0x180) + 0x1EF0);
                        sprintf(sp28C, " %d", var_s5 - 4);
                        strcat(sp280, sp28C);
                    } else {
                        var_s6 = var_s1_2;
                        var_s1_2 += 1;
                        var_s7 = spC0;
                        if (var_s1_2 == 8) {
                            var_fp += 8;
                            var_s1_2 = 0;
                            spE0 += 8;
                            spC0 = var_s7 + 1;
                        }
                        strcpy(sp280, *(char **)(gInterface + 0x180) + 0x1EFC);
                        sprintf(sp28C, " %d", var_s1_2 + var_fp);
                        strcat(sp280, sp28C);
                    }
                    if (temp_s4 != 0) {
                        var_v0 = 0;
                        if (temp_s3 < 0x15) {
                            var_v0 = *(signed char *)(gMC + (temp_s3 * 0x31) + 0x2B0);
                        }
                        if (var_v0 >= 0x64) {
                            goto block_31;
                        }
                        sp100[temp_s4].m_unk0 = (int)DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x80, "???", (float)((var_s7 - 1) * aX), (float)(aYStart + (aY * var_s6)), 0, 7, 0);
                        sp100[temp_s4].m_unk4 = 0;
                    } else {
block_31:
                        sp100[temp_s4].m_unk0 = (int)DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x80, sp280, (float)((var_s7 - 1) * aX), (float)(aYStart + (aY * var_s6)), 0, 4, 0);
                        sp100[temp_s4].m_unk4 = 1;
                    }
                    ((FontNode *)sp100[temp_s4].m_unk0)->m_unk8 = 0x3F000000;
                }
            }
            var_s2 += 1;
            if (var_s2 < 8) {
                goto loop_11;
            }
            temp_v0 = spD0 + 1;
            spD0 = temp_v0;
        } while (temp_v0 < 3);
        var_s1 = 1;
    default:
block_95:
        ((void (*)(void *, int, int, int, int, int))(*(void ***)pBonusScreen)[6])(pBonusScreen, 0, 0, 0, 0, 0x3F800000);
        this->m_unk19AD8 += Render__9InterfaceFi(gInterface, 0);
        goto loop_1;
    case 1:
        if (gInterface[0x425] == 0) {
            var_s1 = 2;
            spA0 = 0;
        }
        goto block_95;
    case 2:
        temp_s2 = (gPad[0x10A] & 0xF0) | (*(unsigned short *)(gPad + 0x110) & 0xF0) | (*(unsigned short *)(gPad + 0x110) & 0x5000);
        if ((temp_s2 & 0x4000) && (sp100[spA0].m_unk4 != 0)) {
            PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
            var_a1 = 0;
            var_a2 = 0;
            *(float *)((char *)pBonusScreen + 0x2C) = 0.0f;
            spB8->m_unk8 = 0;
            spBC->m_unk8 = 0;
            do {
                char *p = (char *)sp100 + var_a2;
                var_a1 += 8;
                var_a2 += 0x40;
                ((FontNode *)*(int *)(p + 0x00))->m_unk8 = 0;
                ((FontNode *)*(int *)(p + 0x08))->m_unk8 = 0;
                ((FontNode *)*(int *)(p + 0x10))->m_unk8 = 0;
                ((FontNode *)*(int *)(p + 0x18))->m_unk8 = 0;
                ((FontNode *)*(int *)(p + 0x20))->m_unk8 = 0;
                ((FontNode *)*(int *)(p + 0x28))->m_unk8 = 0;
                ((FontNode *)*(int *)(p + 0x30))->m_unk8 = 0;
                ((FontNode *)*(int *)(p + 0x38))->m_unk8 = 0;
            } while (var_a1 < 0xD);
            var_a2_2 = var_a1 * 8;
            if (var_a1 < 0x15) {
                do {
                    ((FontNode *)*(int *)((char *)sp100 + var_a2_2))->m_unk8 = 0;
                    var_a1 += 1;
                    var_a2_2 += 8;
                } while (var_a1 < 0x15);
            }
            spA0 = TextureViewer(sp100, spA0);
            if (pBonusScreen == 0) {
                ((FontManager *)(gInterface + 0x80))->RemoveText(spB8);
                ((FontManager *)(gInterface + 0x80))->RemoveText(spBC);
                var_s1_3 = 0;
                var_s2_2 = 0;
                do {
                    ((FontManager *)(gInterface + 0x80))->RemoveText((FontNode *)*(int *)((char *)sp100 + var_s2_2));
                    var_s1_3 += 1;
                    var_s2_2 += 8;
                } while (var_s1_3 < 0x15);
                ((FontManager *)(gInterface + 0x80))->InitFrame();
                goto block_7;
            }
            *(float *)((char *)pBonusScreen + 0x2C) = 1.0f;
            var_a3 = 0;
            var_a2_3 = 0;
            spB8->m_unk8 = 0x3F800000;
            spBC->m_unk8 = 0x3F800000;
            do {
                if (var_a3 == spA0) {
                    ((FontNode *)sp100[var_a3].m_unk0)->m_unk8 = 0x3F800000;
                } else {
                    ((FontNode *)sp100[var_a3].m_unk0)->m_unk8 = 0x3F000000;
                }
                var_a3 += 1;
                var_a2_3 += 8;
            } while (var_a3 < 0x15);
            goto block_55;
        }
block_55:
        if (temp_s2 & 0x1000) {
            var_s1 = 3;
            PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 4.25f, true, 0);
        } else {
            if ((temp_s2 & 0x80) && (spA0 >= 8)) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
                ((FontNode *)sp100[spA0].m_unk0)->m_unk8 = 0x3F000000;
                switch (spA0) {
                case 18:
                    spA0 = 0xC;
                    break;
                case 19:
                    spA0 = 0xD;
                    break;
                case 20:
                    spA0 = 0xE;
                    break;
                default:
                    if ((spA0 - 8) < 0x14) {
                        spA0 -= 8;
                    } else {
                        spA0 = 0x14;
                    }
                    break;
                }
            }
            if ((temp_s2 & 0x20) && (spA0 < 0x10)) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
                ((FontNode *)sp100[spA0].m_unk0)->m_unk8 = 0x3F000000;
                switch (spA0) {
                case 11:
                case 12:
                    var_v0_2 = 0x12;
                    break;
                case 13:
                    var_v0_2 = 0x13;
                    break;
                case 14:
                    var_v0_2 = 0x14;
                    break;
                default:
                    if ((spA0 + 8) < 0x14) {
                        var_v0_2 = spA0 + 8;
                    } else {
                        var_v0_2 = 0x14;
                    }
                    break;
                }
                spA0 = var_v0_2;
            }
            if (temp_s2 & 0x10) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
                ((FontNode *)sp100[spA0].m_unk0)->m_unk8 = 0x3F000000;
                if ((spA0 - 1) < 0) {
                    spA0 = 0;
                } else {
                    spA0 -= 1;
                }
            }
            if (temp_s2 & 0x40) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
                ((FontNode *)sp100[spA0].m_unk0)->m_unk8 = 0x3F000000;
                if ((spA0 + 1) < 0x14) {
                    var_v0_3 = spA0 + 1;
                } else {
                    var_v0_3 = 0x14;
                }
                spA0 = var_v0_3;
            }
            ((FontNode *)sp100[spA0].m_unk0)->m_unk8 = 0x3F800000;
        }
        goto block_95;
    }
    if (gInterface[0x425] != 0) {
        goto block_95;
    }
    DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pBonusScreen);
    ((FontManager *)(gInterface + 0x80))->RemoveText(spB8);
    ((FontManager *)(gInterface + 0x80))->RemoveText(spBC);
    var_s1_4 = 0;
    var_s2_3 = 0;
    do {
        ((FontManager *)(gInterface + 0x80))->RemoveText((FontNode *)*(int *)((char *)sp100 + var_s2_3));
        var_s1_4 += 1;
        var_s2_3 += 8;
    } while (var_s1_4 < 0x15);
    ((FontManager *)(gInterface + 0x80))->InitFrame();
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 4.25f, true, 0);
}

// FUNCTION: 0x0013C700 SetViewMatrix__6CameraF5PMat4
void Camera::SetViewMatrix(PMat4 mat) {
    sceVu0CopyMatrix(m_unk30, (float (*)[4])&mat);
}

// FUNCTION: 0x0013C710 GetEndFrame__5PAnimFv
int PAnim::GetEndFrame() {
    return 0;
}

// FUNCTION: 0x0013C720 MapscreenOpenBonusExists__10MaximoMainFv
int MaximoMain::MapscreenOpenBonusExists() {
    int i = 0;

    do {
        if (gMC[i + 0x6B5] == 1) {
            return 1;
        }
        i++;
    } while (i < 0x20);
    return 0;
}

// DRAFT: 0x0013C770 MapscreenPrintInfo__10MaximoMainFP11FontManageri
// note: 79 words differ; the first call's arguments (mtc1 of -120.0f and 0.0f) are hoisted above the entry index math in the original. Tried: short vs signed char loads, tbl pointer, declaration order, entry as a block-scoped pointer (79, no change).
void MaximoMain::MapscreenPrintInfo(FontManager *arg0, int arg1) {
    char buf[0x20];
    static float aBonus;
    static char initBonus;
    static float aSave;
    static char initSave;
    int s0;
    int sc;
    int s1;
    unsigned char v;
    char *entry;
    char *tbl;

    s0 = arg1;
    RemoveAll__11FontManagerFb(arg0, true);
    pMasteryTextIcon->m_unk2C = 0;
    entry = arg0->m_unk100 + (s0 + 0x270) * 12;
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(arg0, *(char **)entry, 0.0f, -120.0f, *(signed char *)(entry + 0xA), 4, 1);
    if (s0 == 0x13) {
        s0 = 0x14;
    }
    v = 0;
    if (s0 < 0x15) {
        v = gMC[0x2B0 + s0 * 49];
    }
    sc = (signed char)v;
    if (sc >= 0x64) {
        pMasteryTextIcon->m_unk2C = 0x3F800000;
        pMasteryTextIcon->Slot5(0);
        pMasteryTextIcon->Slot2(20.0f);
        pMasteryTextIcon->Slot4(0, 0.0f, 1.0f, 0, 0);
    } else {
        s1 = 0x32;
        if (arg0->m_unk13 == 4) {
            s1 = 0x78;
        }
        tbl = arg0->m_unk100;
        entry = tbl + 0xCD8;
        DisplayString__11FontManagerFPcffi9FontColor9FontAlign(arg0, *(char **)(tbl + 0xCD8), (float)s1, -160.0f, *(signed char *)(tbl + 0xCE2), 3, 2);
        if (sc < 0) {
            sc = 0;
        }
        sprintf(buf, "%d%s", sc, "%");
        DisplayString__11FontManagerFPcffi9FontColor9FontAlign(arg0, buf, (float)(s1 + 0x1E), -160.0f, *(signed char *)(entry + 0xA), 3, 0);
    }
    DisplayString__11FontManagerFiiib(arg0, 0x293, 0, 0, false);
    if (initBonus == 0) {
        aBonus = -330.0f;
        initBonus = 1;
    }
    if (initSave == 0) {
        aSave = 332.0f;
        initSave = 1;
    }
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(arg0, "a          ~#", aBonus, -200.0f, 1, 0, 1);
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(arg0, "~{         ;a", aSave, -200.0f, 1, 0, 1);
}

// DRAFT: 0x0013C9F0 SetMarkerAsMastered__10MaximoMainFP6PMNodeP6PMNode
// note: 7 words: PMNode vtable lui hoisted above the 0x58/0x5C spills in the original (same as PWorld LoadMeshNodeHierarchy). Tried: split decl/assign, vtable local (also for both vtables), raw-pointer local, index store, pNodeV from pMeshV (all 7 or worse).
void MaximoMain::SetMarkerAsMastered(PMNode *arg0, PMNode *arg1) {
    if (arg1 != 0) {
        PMNode *found = arg0->Find(0xA5D4D353U);
        if (found == 0) {
            CdsAssert__FPciPc((char *)"MaximoMain.cpp", 0x7F1, (char *)"aMastery");
        }
        PMNode *node;
        if ((node = (PMNode *)__nw__FUi(0x140)) != 0) {
            char *volatile pMeshV = (char *)node;
            {
                char *volatile pNodeV = (char *)node;
                *(void **)node = __vt__9PResource;
                *(int *)(pNodeV + 4) = 0;
                *(void **)pNodeV = __vt__6PMNode;
                __ct__6PArrayFv(pNodeV + 0x14);
                sceVu0UnitMatrix(pNodeV + 0x40);
                __ct__6PArrayFv(pNodeV + 0xD8);
                InitMembers__6PMNodeFv((PMNode *)pNodeV);
            }
            *(void **)pMeshV = __vt__9PMeshNode;
            __ct__6PArrayFv(pMeshV + 0x130);
            InitMembers__9PMeshNodeFv((PMNode *)pMeshV);
            node = (PMNode *)pMeshV;
        }
        CopyMNode__6PMNodeFR6PMNodeb(node, found, true);
        *(u_long128 *)((char *)node + 0x80) = *(u_long128 *)((char *)arg1 + 0x80);
        *((unsigned char *)node + 0x3E) |= 8;
        node->Slot4(0, 0.0f, 0.0f, 0, 0);
        Add__6PArrayFPv((char *)arg0 + 0x14, node);
        arg0->Slot4(0, 0.0f, 0.0f, 0, 0);
    }
}

// FUNCTION: 0x0013CB80 __dt__9PResourceFv
extern "C" void *__dt__9PResourceFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__9PResource;
        ((int *)pThis)[1] = 0;
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0013CBD0 GetMapScreenPath__10MaximoMainFP6PMNodeiR6PArrayb
void MaximoMain::GetMapScreenPath(PMNode *arg0, int arg1, PArray &arg2, bool arg3) {
    int i;
    int j;
    PMNode *node;
    PMChildList *list;
    PMNode *child;

    char *pRec = (char *)(LevelTable + 0x78);
    node = arg0->Find(*(unsigned int *)(pRec + (arg1 << 7)));
    if (node != 0) {
        list = &node->m_unk14;
        Allocate__6PArrayFUi(&arg2, list->count);
        if (!arg3) {
            for (i = 0; (unsigned int)i < list->count; i++) {
                child = ((unsigned int)i < list->count) ? list->children[i] : 0;
                if (child != 0) {
                    Add__6PArrayFPv(&arg2, child);
                }
            }
        } else {
            for (j = (int)list->count - 2; j >= 0; j--) {
                child = ((unsigned int)j < list->count) ? list->children[j] : 0;
                if (child != 0) {
                    Add__6PArrayFPv(&arg2, child);
                }
            }
        }
    }
}

// FUNCTION: 0x0013CCF0 PlayMarkerSound__10MaximoMainFi
int MaximoMain::PlayMarkerSound(int arg0) {
    int sound = 0;

    switch (arg0) {
    case 0:
        sound = 0x28D;
        break;
    case 1:
    case 2:
        sound = 0x264;
        break;
    case 4:
    case 5:
    case 6:
        sound = 0x323;
        break;
    case 9:
    case 10:
    case 11:
        sound = 0x325;
        break;
    case 12:
    case 13:
        sound = 0x326;
        break;
    case 14:
        sound = 0x327;
        break;
    }
    if (sound != 0) {
        return PlaySoundUbiquitous__6PSoundFUi(gSound, sound);
    }
    return 0;
}

// FUNCTION: 0x0013CD70 PlayBGSound__10MaximoMainFi
int MaximoMain::PlayBGSound(int arg0) {
    int sound = 0;

    switch (arg0) {
    case 0:
        break;
    case 1:
        sound = 0x322;
        break;
    case 2:
        sound = 0x324;
        break;
    case 3:
        sound = 0x288;
        break;
    case 4:
        sound = 0x328;
        break;
    case 5:
        sound = 0x285;
        break;
    }
    if (sound != 0) {
        return PlaySoundUbiquitous__6PSoundFUi(gSound, sound);
    }
    return 0;
}

// FUNCTION: 0x0013CDF0 RestartGame__10MaximoMainFb
void MaximoMain::RestartGame(bool arg0) {
    if (arg0) {
        m_unk19A70 = 0xA;
        UpdateStatus__9InterfaceFUib(gInterface, 9, false);
        return;
    }
    m_unk19A70 = 9;
}

// DRAFT: 0x0013CE50 LevelClearDemo__10MaximoMainFv
// note: fncmp DIFF 570 words, size 0x9bc vs 0x9f8; switch case order, tally loop, sprintf/divu chain and the 0x19A70 state store differ from the asm (one variant tried)
int MaximoMain::LevelClearDemo() {
    char sp50[32];
    char sp70[32];
    int colour;
    unsigned int snd;
    char *tbl;
    int lvl;
    int tally;

    switch (m_unk19AAC) {
    case 0:
        m_unk19AC0 = m_unk19A78;
        PSoundLevelClear__6PSoundFv(gSound);
        FadeOutAllMusic__6PSoundFUi(gSound, 1000);
        RemoveAll__11FontManagerFb(gInterface + 0x80, true);
        LevelClear__9InterfaceFv(gInterface);
        SaveApparitionData__13EntityManagerFi((char *)this + 0x137E0, m_unk19A78);
        if (LevelTable[0x7C + (m_unk19A78 << 7)] & 0x80) {
            m_unk19AAC = 6;
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 4.25f, false, 0);
            lvl = m_unk19A78;
            if (lvl < 0x15) {
                if ((signed char)gMC[0x2B0 + lvl * 0x31] < 0x64) {
                    gMC[0x2B0 + lvl * 0x31] = 0x64;
                }
            }
        } else {
            m_unk19AAC = 1;
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 64.0f, 4.25f, false, 0);
            tbl = *(char **)(gInterface + 0x180);
            ((FontManager *)(gInterface + 0x80))->DisplayString(m_unk19A78 + 0x270, -1, 0, false);
            ((FontManager *)(gInterface + 0x80))->DisplayString(0x10E, 0, 0, false);
            DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x80, *(char **)(tbl + (gMC[0x22F] + 0xD) * 0xC), 230.0f, 200.0f, 3, 7, 0);
            RES_POS = (float)*(int *)(tbl + 0xD00);
            m_unk19AB0 = 0;
            tally = CalculateTallyData__13EntityManagerFv((char *)this + 0x137E0) + (m_unk19AAC * 8);
            m_unk19AB4 = ((int *)tally)[0];
            m_unk19AB8 = ((int *)tally)[1];
            if (LevelTable[0x75 + (m_unk19A78 << 7)] != 0) {
                m_unk19AB4 = m_unk19AB4 + m_unk1932C;
                if ((unsigned int)m_unk19AB4 >= 0x3E8) {
                    m_unk19AB4 = 0x3E7;
                }
                m_unk19AB8 = m_unk19AB8 + m_unk1932C;
                if ((unsigned int)m_unk19AB8 >= 0x3E8) {
                    m_unk19AB8 = 0x3E7;
                }
            }
            m_unk19ABC = 0;
            m_unk19AD4 = 4;
        }
        m_unk18838 = 8;
        return 1;
    case 1:
    case 2:
    case 3:
    case 4:
        if ((unsigned int)m_unk19AB4 >= (unsigned int)m_unk19AB0) {
            if (gPad[0x110] & 0x5000) {
                m_unk19AB0 = m_unk19AB4;
                m_unk19AD4 = 0;
            }
            m_unk19AD4 = m_unk19AD4 - 1;
            if (m_unk19AD4 <= 0) {
                m_unk19AD4 = 4;
                PlaySoundUbiquitous__6PSoundFUi(gSound, TallySound[m_unk19AAC]);
                if (m_unk19ABC != 0) {
                    ((FontManager *)(gInterface + 0x80))->RemoveText((FontNode *)m_unk19ABC);
                }
                tbl = *(char **)(gInterface + 0x180);
                if ((unsigned int)m_unk19AB0 < (unsigned int)m_unk19AB8) {
                    sprintf(sp50, "%d (%d)", m_unk19AB0, m_unk19AB8);
                    colour = 0;
                } else {
                    sprintf(sp50, *(char **)(tbl + 0xCFC), m_unk19AB0, m_unk19AB8);
                    colour = 4;
                }
                m_unk19ABC = DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x80, sp50, RES_POS, (float)*(short *)(tbl + (m_unk19AAC + 0x10D) * 0xC + 6), 0, colour, 0);
                m_unk19AB0 = m_unk19AB0 + 1;
                if ((unsigned int)(m_unk19AB0 - 1) >= (unsigned int)m_unk19AB4) {
                    m_unk19AAC = m_unk19AAC + 1;
                    ((FontManager *)(gInterface + 0x80))->DisplayString(m_unk19AAC + 0x10D, 0, 0, false);
                    m_unk19AB0 = 0;
                    m_unk19AB4 = m_unk19304[m_unk19AAC * 2];
                    m_unk19AB8 = m_unk19304[m_unk19AAC * 2 + 1];
                    m_unk19ABC = 0;
                    if (m_unk19AAC >= 5) {
                        int sum0 = 0;
                        int sum1 = 0;
                        int a3 = 1;
                        int *t = &m_unk19304[2];
                        do {
                            a3 += 1;
                            sum0 += t[0];
                            sum1 += t[1];
                            t += 2;
                        } while (a3 < 5);
                        float q = (float)(sum0 * 100) / (float)sum1;
                        unsigned int pct = (unsigned int)q;
                        if (pct >= 0x64) {
                            sprintf(sp50, *(char **)(tbl + 0xCFC), sum0, a3);
                            colour = 4;
                            snd = 0xFF;
                            pct = 0x64;
                        } else {
                            sprintf(sp50, "%d%s", pct, "%");
                            colour = 3;
                            snd = 0xFE;
                        }
                        PlaySoundUbiquitous__6PSoundFUi(gSound, snd);
                        lvl = m_unk19A78;
                        if (lvl < 0x15 && (signed char)gMC[0x2B0 + lvl * 0x31] < (signed char)pct) {
                            gMC[0x2B0 + lvl * 0x31] = (unsigned char)pct;
                        }
                        DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x80, sp50, RES_POS, (float)*(short *)(tbl + 0xCDE), 0, colour, 0);
                        sprintf(sp70, "%d:%02d'%02d\"", (*(int *)(gMC + 0x230) / 60) / 60, (*(int *)(gMC + 0x230) / 60) % 60);
                        DisplayString__11FontManagerFPcffi9FontColor9FontAlign(gInterface + 0x80, sp70, RES_POS, (float)(*(short *)(tbl + 0xCD8 + 6) - 0x2D), 0, 3, 0);
                    }
                }
            }
        }
        break;
    case 5:
        if (gPad[0x110] & 0x4000) {
            m_unk19AAC = m_unk19AAC + 1;
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 4.25f, true, 0);
        }
        break;
    case 6:
        if (gInterface[0x425] == 0) {
            RemoveAll__11FontManagerFb(gInterface + 0x80, true);
            DeleteMeshLayer__9InterfaceFv(gInterface);
            Reset__13EntityManagerFb((char *)this + 0x137E0, true);
            Destroy__6PWorldFv(this);
            RemoveAllFogObjects__16PParticleManagerFv(gGfxEng + 0x154F00);
            lvl = m_unk19A78;
            if ((LevelTable[0x7C + (lvl << 7)] & 0x3F) == 0x16) {
                UpdateHeader__10MemoryCardFUc(gMC, lvl & 0xFF);
                PlayMovie__9MaxEngineFiiUi(this, 2, 0, 1);
                PlayCredits();
                m_unk19A70 = 8;
            } else {
                m_unk19A78 = LevelTable[0x7C + (lvl << 7)] & 0x3F;
                UpdateHeader__10MemoryCardFUc(gMC, m_unk19A78 & 0xFF);
                m_unk19A70 = (m_unk19A78 != 0x14) ? 7 : 0;
            }
            return 0;
        }
        break;
    default:
        return 0;
    }
    m_unk18838 = 8;
    return 1;
}

// FUNCTION: 0x0013D850 SetLevelClear__10MaximoMainFv
void MaximoMain::SetLevelClear() {
    if (m_unk19A70 != 6) {
        m_unk19A70 = 6;
        m_unk19AAC = 0;
        SetState__15EntityBaseClassFi(m_unk1883C, 2);
    }
}

// FUNCTION: 0x0013D8B0 GetLevelFile__10MaximoMainFi
void *MaximoMain::GetLevelFile(int arg0) {
    int idx = arg0;

    if (idx < 0) {
        idx = m_unk19A78;
    }
    if (idx < 0x15) {
        return LevelTable + (idx << 7);
    }
    return 0;
}

// FUNCTION: 0x0013D8F0 InitCutSceneIfDialogReady__10MaximoMainFv
int MaximoMain::InitCutSceneIfDialogReady() {
    int stream = m_unk19AA4;
    bool start = true;

    if (stream != 0) {
        int readiness = GetDialogStreamReadiness__6PSoundFUi(gSound, stream);
        if (readiness != 0) {
            start = false;
            if (readiness < 0) {
                CdsAssert__FPciPc((char *)"MaximoMain.cpp", 0x65C, (char *)"0");
                start = true;
                m_unk19AA4 = 0;
            }
        }
    }
    if (start) {
        InitCutScene();
        return 0;
    }
    return 1;
}

// DRAFT: 0x0013D990 InitCutScene__10MaximoMainFv
// note: 100 words differ; the original reads m_unk8724 through (char *)this+0x8724 into v1 and reloads it for the index test, and its clamp branches differ.
void MaximoMain::InitCutScene() {
    char *pLevel = (char *)LevelTable + (m_unk19A78 << 7);
    int nIndex;
    char *pEntry;
    char *pSlot;
    int nW;
    int nH;

    m_unk19A70 = 5;
    nIndex = m_unk8724;
    pEntry = pLevel + nIndex * 16 + 0x14;
    if (nIndex < 4) {
        m_unk8724 = nIndex;
        pSlot = (char *)this + nIndex * 0x2140 + 0x220;
        ResetAnimations__15PCutScenePlayerFv(pSlot);
        m_unk8720 = 1;
        SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf(pSlot, pSlot + 0x60, 0.0f);
        SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf(pSlot, pSlot + 0x90, 1.0f);
    }
    *(short *)(gInterface + 0x414) = 30;
    *(int *)(gInterface + 0x1C0) &= ~0xE;
    CutSceneEnter__6PSoundFPUiUiUiUi(gSound, (unsigned int *)((char *)this + 0x19B50), m_unk19AA4,
                                     *(unsigned int *)(pEntry + 8), (unsigned int)(int)(signed char)pEntry[0xD]);
    nW = *(short *)(pLevel + 0x6A);
    if (nW < 0x97) {
        nW = 0x96;
    }
    nH = *(short *)(pLevel + 0x6C);
    if (nH < 0x8D) {
        nH = 0x8C;
    }
    *(float *)(gGfxEng + 0x6A0) = (float)nW * (float)nW;
    *(float *)(gGfxEng + 0x6A4) = (float)nH * (float)nH;
}

// DRAFT: 0x0013DB50 StartCutScene__10MaximoMainFi
// note: 18 differing lines, register numbering only: in the index chain and in the runtime gEng+0x19760 camera argument the original puts the first operand in v0 and the second in v1, ours swaps them. Uses the runtime (int)gEng + 0x19760 argument, a bare truth test and one shared return 0. Tried: (int)&gEng, (unsigned int) casts, offset-first sum, one-line index, split += index, && merged guard (all 18-39).
int MaximoMain::StartCutScene(int arg0) {
    int ok;
    DisplayLevelName__9InterfaceFii(gInterface, -1, 0xF0);
    ok = 0;
    if (arg0 < 4) {
        unsigned int base = (unsigned int)this + 0x260;
        unsigned int addr = base + arg0 * 0x2140;
        ok = *(int *)addr != 0;
    }
    if (ok) {
        if (!(*(int *)((char *)m_unk1883C + 0x264) & 8)) {
            m_unk19A70 = 3;
            *(int *)((char *)this + 0x8724) = arg0;
            if (PlayingCutCamera__6CameraFv((char *)((int)gEng + 0x19760))) {
                gEng[0x19A18] = 0;
            }
            return 1;
        }
    }
    return 0;
}
// FUNCTION: 0x0013DC30 FindFirstDialog__10MaximoMainFPC10LevelFilesb
unsigned int MaximoMain::FindFirstDialog(LevelFiles const *arg0, bool arg1) {
    int s1;
    unsigned int temp_s2;
    int idx;
    int a0;

    m_unk19AA4 = 0;
    if (arg0->m_unk10 == 0) {
        m_unk19AA8 = -1;
        return 0;
    }
    for (s1 = 0, idx = 0, a0 = 0; s1 < 4; s1++, idx += 0x2140, a0 += 0x10) {
        if (*(int *)((char *)this + idx + 0x260) != 0) {
            temp_s2 = *(unsigned int *)((char *)arg0 + a0 + 0x18);
            if (temp_s2 != 0 && (!arg1 || m_unk19AA8 < s1)) {
                PrepDialog__6PSoundFUi(gSound, temp_s2);
                m_unk19AA4 = temp_s2;
                m_unk19AA8 = s1;
                return temp_s2;
            }
        }
    }
    return 0;
}

// DRAFT: 0x0013DD20 Game__10MaximoMainFi
// note: not yet matching; the goto state machine compiles, but the switch layout and register use still differ.
int MaximoMain::Game(int arg0) {
    int nRet = 0;
    int nPause = 0;
    int bInit = 0;
    int nRenderSum = 0;
    int nS3 = 0;
    int nCombined;
    int bCam;
    int nMovie;
    int nMusic;
    char *pLvl;
    char *pSlot;
    unsigned char nFlagS1;
    signed char nHard;
    float fScale;
    float fA;
    float fB;
    float fT;

loop_2:
    InitRenderFrame__9MaxEngineFbUi(this, 0, 0U);
    if (arg0 == 1) {
        if (MODE_PAL != 0) {
            fScale = 1.2f;
        } else {
            fScale = 1.0f;
        }
        *(float *)((char *)this + 0x1E8) = fScale;
        m_unk19B5C = m_unk19B5C - 1;
        if (m_unk19B5C <= 0) {
            return nRet;
        }
        if (m_unk19B5C == 0x3C) {
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 4.25f, true, 0);
            FadeOutAllMusic__6PSoundFUi(gSound, 0x1F4U);
        } else if ((*(unsigned short *)(gPad + 0x110) & 8) && (m_unk19B5C >= 0x3D)) {
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 8.5f, true, 0);
            FadeOutAllMusic__6PSoundFUi(gSound, 0x1F4U);
            nRet = 1;
            m_unk19B5C = 0x1E;
        }
    }
block_13:
    nFlagS1 = *(unsigned char *)((char *)this + 0x137D8);
    pLvl = (char *)LevelTable + (m_unk19A78 << 7);
    switch (m_unk19A70) {
    case 0:
        if ((unsigned int)m_unk19A78 >= 0x15U) {
            CdsAssert__FPciPc("MaximoMain.cpp", 0x4BF, "miLevelID < sizeof(LevelTable) / sizeof(LevelFiles)");
        }
        m_unk19A7C = 0;
        *((char *)this + 0x19A9D) = 0;
        RemoveAll__11FontManagerFb(gInterface + 0x80, true);
        DeleteMeshLayer__9InterfaceFv(gInterface);
        SoundGainEEControl__9InterfaceFv(gInterface);
        nMovie = (*(int *)(pLvl + 0x7C) >> 8) & 3;
        if (nMovie != 0) {
            PlayMovie__9MaxEngineFiiUi(this, nMovie - 1, 0, 1U);
        }
        Load__9InterfaceFPCc(gInterface, "HUD");
        if (arg0 == 1) {
            nHard = 0;
        } else {
            nHard = (signed char)gMC[0x22F];
        }
        mbHard__15EntityBaseClass = (int)nHard;
        Reset__19EntityAttackManagerFv((char *)this + 0x137E0);
        *(int *)((char *)this + 0x137F0) = (gMC[0x22F] == 0) ? 1 : 2;
        LoadOverlay__13EntityManagerFPcPc((char *)this + 0x137E0, *(char **)(pLvl + 8), *(char **)(pLvl + 0xC));
        *(int *)(MemMgr + 0x18) = 0;
        InitWorld__9MaxEngineFPvP16PResourceManager(this, pLvl, (char *)this + 0x188A4);
        InitSwordBGAnimList__13EntityManagerFP9PMeshNode((char *)this + 0x137E0, *(void **)this);
        *(int *)(MemMgr + 0x18) = 1;
        scePcStop();
        *(int *)((char *)this + 0x19A80) = 0;
        InitGameTimes();
        LoadApparitionData__13EntityManagerFi((char *)this + 0x137E0, m_unk19A78);
        SpawnEditedInstances__13EntityManagerFPcb((char *)this + 0x137E0, *(char **)pLvl, true);
        *(float *)((char *)this + 0x18854) = (float)*(short *)(pLvl + 0x72);
        mbGlobalSleep__15EntityBaseClass = *(unsigned char *)(pLvl + 0x74);
        *(int *)(MemMgr + 0x18) = 0;
        InitHud__9InterfaceFv(gInterface);
        Init__6CameraFv((char *)this + 0x19760);
        SetVibrate__3PadFQ23Pad7VibTypeUc(gPad, 0, 0x14U);
        if (*(int *)(pLvl + 0x20) & 0x10) {
            void **pObj;
            m_unk19A70 = 3;
            m_unk8724 = 0;
            *((unsigned char *)this + 0x19A9C) = 1;
            pObj = (void **)m_unk1883C;
            ((void (*)(void *))((void **)*pObj)[4])(pObj);
            bInit = 0;
        } else {
            m_unk19A70 = 1;
            *((unsigned char *)this + 0x19A9C) = 0;
            DisplayLevelName__9InterfaceFii(gInterface, m_unk19A78, 0xF0);
            bInit = 1;
        }
        ReturnControlOfIOPToMjln__6PSoundFv(gSound);
        FindFirstDialog((LevelFiles const *)pLvl, false);
        *(unsigned int *)((char *)this + 0x19B4C) = *(unsigned int *)(pLvl + 0x58);
        SetLevelParameters__6PSoundFUiUiUiUi(gSound, *(unsigned int *)((char *)this + 0x19B4C),
                                             *(unsigned int *)(pLvl + 0x5C), *(unsigned short *)(pLvl + 0x5E),
                                             *(unsigned short *)(pLvl + 0x60));
        nMusic = *(unsigned short *)(pLvl + 0x56);
        if (nMusic != 0) {
            m_unk19B48 = nMusic & 0xFFFF;
            if (gbMusic != 0 && bInit != 0) {
                PlayMusic__6PSoundFUi(gSound, m_unk19B48);
            }
        }
        EnableLevelProcessing__6PSoundFb(gSound, true);
        ResetWarning__11FontManagerFv(gInterface + 0x80);
        /* fall through */
    default:
block_80:
        if (arg0 == 1) {
            PressStart(-0xD2);
        }
        goto loop_2;
    case 10:
        Reset__19EntityAttackManagerFv((char *)this + 0x137E0);
        DeleteMeshLayer__9InterfaceFv(gInterface);
        Reset__13EntityManagerFb((char *)this + 0x137E0, false);
        fT = (float)*(short *)(pLvl + 0x68);
        *(float *)((char *)this + 0xEC) = fT;
        *(float *)((char *)this + 0x1CC) = fT;
        PSoundRestart__6PSoundFv(gSound);
        *(int *)((char *)this + 0x19A80) = 0;
        InitGameTimes();
        *(int *)(MemMgr + 0x18) = 1;
        SpawnEditedInstances__13EntityManagerFPcb((char *)this + 0x137E0, 0, false);
        *(int *)(MemMgr + 0x18) = 0;
        FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 4.25f, true, 0);
        {
            void *pObj;
            pObj = *(void **)(gInterface + 0x290);
            ((void (*)(void *))*(void **)((char *)pObj + 0x18))(gInterface + 0x290);
        }
        *(short *)(gInterface + 0x414) = 0;
        *(int *)(gInterface + 0x1C0) = 0xF;
        *(unsigned char *)(gInterface + 0x416) = 0;
        Init__6CameraFv((char *)this + 0x19760);
        SetVibrate__3PadFQ23Pad7VibTypeUc(gPad, 0, 0x14U);
        FindFirstDialog((LevelFiles const *)pLvl, false);
        SetLevelParameters__6PSoundFUiUiUiUi(gSound, *(unsigned int *)((char *)this + 0x19B4C),
                                             *(unsigned int *)(pLvl + 0x5C), *(unsigned short *)(pLvl + 0x5E),
                                             *(unsigned short *)(pLvl + 0x60));
        nMusic = m_unk19B48;
        if (nMusic != 0 && gbMusic != 0) {
            PlayMusic__6PSoundFUi(gSound, nMusic);
        }
        EnableLevelProcessing__6PSoundFb(gSound, true);
        ResetWarning__11FontManagerFv(gInterface + 0x80);
        m_unk19A70 = 1;
        /* fall through */
    case 1:
        nPause = PauseCheck();
        if (nPause == 0 && nFlagS1 == 0) {
            if (m_unk19A7C == 0) {
                *(int *)((char *)this + 0x19A80) = *(int *)((char *)this + 0x19A80) + 1;
                UpdateGameTimes();
            }
        block_38:
            Update__6CameraFv((char *)this + 0x19760);
            Process__13EntityManagerFv((char *)this + 0x137E0);
            m_unk19AD8 = RenderSkybox__9MaxEngineFi(this, m_unk19A7C);
            RenderWorld__9MaxEngineFib(this, m_unk19A7C, false);
            PolyDebug__6CameraFv((char *)this + 0x19760);
            *(int *)(MemMgr + 0x18) = 1;
            Animate__13EntityManagerFif((char *)this + 0x137E0, m_unk19A7C, *(float *)((char *)this + 0x1E8));
            m_unk19AD8 = m_unk19AD8 + Render__13EntityManagerFP13PLightManager((char *)this + 0x137E0, (char *)this + 0x1F0);
            RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(this, (char *)this + 0x19760, nPause, 2);
            ObjectCollision__13EntityManagerFv((char *)this + 0x137E0);
            RunPhysics__13EntityManagerFf((char *)this + 0x137E0, *(float *)((char *)this + 0x1E8));
            *(int *)(MemMgr + 0x18) = 0;
            nRenderSum = m_unk19AD8 + Render__9InterfaceFi(gInterface, 0);
        } else {
            bCam = (*(int *)(gInterface + 0x2F8) != 0);
            nCombined = nFlagS1 | nPause;
            if (bCam != 0) {
                bCam = (*(int *)(gInterface + 0x1C0) & 0x40) == 0;
            }
            if (bCam != 0) {
                m_unk19AD8 = RenderSkybox__9MaxEngineFi(this, nCombined);
                RenderWorld__9MaxEngineFib(this, nCombined, false);
                m_unk19AD8 = m_unk19AD8 + Render__13EntityManagerFP13PLightManager((char *)this + 0x137E0, (char *)this + 0x1F0);
                RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(this, (char *)this + 0x19760, nCombined, 2);
            } else {
                m_unk19AD8 = 0;
            }
            nRenderSum = m_unk19AD8 + Render__9InterfaceFi(gInterface, nCombined);
        }
    block_79:
        m_unk19AD8 = nRenderSum;
        goto block_80;
    case 3:
        pSlot = (char *)this + m_unk8724 * 0x2140 + 0x220;
        EnableParticleFx__13EntityManagerFb((char *)this + 0x137E0, false);
        if (pSlot[0x213D] & 8) {
            m_unk19A70 = 4;
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 8.5f, true, 0);
        case 4:
            if (gInterface[0x425] == 0) {
                FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f,
                    255.0f / (60.0f * *(float *)((char *)this + m_unk8724 * 0x2140 + 0x2354)), true, 0);
                InitCutSceneIfDialogReady();
            } else {
                Update__6CameraFv((char *)this + 0x19760);
                Process__13EntityManagerFv((char *)this + 0x137E0);
                m_unk19AD8 = RenderSkybox__9MaxEngineFi(this, m_unk19A7C);
                RenderWorld__9MaxEngineFib(this, m_unk19A7C, true);
                *(int *)(MemMgr + 0x18) = 1;
                Animate__13EntityManagerFif((char *)this + 0x137E0, m_unk19A7C, *(float *)((char *)this + 0x1E8));
                m_unk19AD8 = m_unk19AD8 + Render__13EntityManagerFP13PLightManager((char *)this + 0x137E0, (char *)this + 0x1F0);
                RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(this, (char *)this + 0x19760, nPause, 2);
                ObjectCollision__13EntityManagerFv((char *)this + 0x137E0);
                RunPhysics__13EntityManagerFf((char *)this + 0x137E0, *(float *)((char *)this + 0x1E8));
                *(int *)(MemMgr + 0x18) = 0;
                nRenderSum = m_unk19AD8 + Render__9InterfaceFi(gInterface, nPause);
                goto block_79;
            }
        } else {
            InitCutSceneIfDialogReady();
        }
        goto block_80;
    case 5:
        nS3 = 0;
        pSlot = (char *)this + m_unk8724 * 0x2140 + 0x220;
        if (gInterface[0x425] == 0 && (pSlot[0x213D] & ~0x7F)) {
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f,
                255.0f / (60.0f * *(float *)(pSlot + 0x2138)), true, 0);
        }
        m_unk19AD8 = RenderSkybox__9MaxEngineFi(this, 0);
        RenderWorld__9MaxEngineFib(this, 0, true);
        RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(this, (char *)this + 0x19760, nFlagS1, 2);
        m_unk19AD8 = m_unk19AD8 + Render__9InterfaceFi(gInterface, 0);
        if (m_unk8720 == 0) {
            nS3 = 1;
        } else if (*(unsigned short *)(gPad + 0x110) & 1) {
            Abort__15PCutScenePlayerFv(pSlot);
            nS3 = 2;
            m_unk8720 = 0;
        }
        if (nS3 != 0) {
            EnableParticleFx__13EntityManagerFb((char *)this + 0x137E0, true);
            pSlot = (char *)this + m_unk8724 * 0x2140 + 0x220;
            if (pSlot != 0 && (pSlot[0x213D] & 0x20)) {
                SetLevelClear();
                *((unsigned char *)this + 0x19A9D) = 1;
                FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 0.0f, true, 0);
            } else {
                if (pSlot != 0 && (pSlot[0x213D] & 0x10) && gbMusic != 0) {
                    PlayMusic__6PSoundFUi(gSound, m_unk19B48);
                }
                m_unk19A70 = 1;
            }
            ResetFollowCamera__6CameraFv((char *)this + 0x19760);
            Update__6CameraFv((char *)this + 0x19760);
            Animate__13EntityManagerFif((char *)this + 0x137E0, m_unk19A7C, 0.0f);
            m_unk19A7C = 0;
            *(short *)(gInterface + 0x414) = 0;
            *(int *)(gInterface + 0x1C0) = *(int *)(gInterface + 0x1C0) | 0xE;
            CutSceneLeave__6PSoundFUi(gSound, *(unsigned int *)((char *)this + 0x19B50));
            FindFirstDialog((LevelFiles const *)pLvl, true);
            fA = (float)*(short *)(pLvl + 0x6A);
            fB = (float)*(short *)(pLvl + 0x6C);
            *(float *)(gGfxEng + 0x6A0) = fA * fA;
            *(float *)(gGfxEng + 0x6A4) = fB * fB;
            if (*((unsigned char *)this + 0x19A9C) != 0) {
                *((unsigned char *)this + 0x19A9C) = 0;
                DisplayLevelName__9InterfaceFii(gInterface, m_unk19A78, 0xF0);
            }
        }
        goto block_80;
    case 2:
        GameOptions();
        goto block_80;
    case 6:
        if (LevelClearDemo() == 0 || *((unsigned char *)this + 0x19A9D) != 0) {
            nRenderSum = Render__9InterfaceFi(gInterface, nPause);
        } else {
            goto block_38;
        }
        goto block_79;
    case 7:
        if (MapScreen__10MaximoMainFv(this) != 0) {
            goto block_80;
        }
    block_77:
        PSoundLevelClear__6PSoundFv(gSound);
        InitRenderFrame__9MaxEngineFbUi(this, 0, 0U);
        return 1;
    case 9:
        GameOver();
        return 1;
    case 8:
        if (gInterface[0x425] == 0) {
            goto block_77;
        }
        m_unk19AD8 = RenderSkybox__9MaxEngineFi(this, nPause);
        RenderWorld__9MaxEngineFib(this, nPause, false);
        m_unk19AD8 = m_unk19AD8 + Render__13EntityManagerFP13PLightManager((char *)this + 0x137E0, (char *)this + 0x1F0);
        RenderParticleFx__9MaxEngineFP6Camerai8ePSLayer(this, (char *)this + 0x19760, nPause, 2);
        nRenderSum = m_unk19AD8 + Render__9InterfaceFi(gInterface, 0);
        goto block_79;
    }
}

// FUNCTION: 0x0013ED80 PauseDisplay__10MaximoMainFi
void MaximoMain::PauseDisplay(int arg0) {
    FontManager *fm = (FontManager *)(gInterface + 0x80);
    int i = 0;
    int off = 0;

    do {
        void *text = fm->DisplayString(i + 1, 0, 0, false);
        *(void **)((char *)this + off + 0x19A88) = text;
        float alpha;
        if (i != arg0) {
            alpha = 0.5f;
        } else {
            alpha = 1.0f;
        }
        i++;
        off += 4;
        *(float *)((char *)text + 8) = alpha;
    } while (i < 3);
}

// DRAFT: 0x0013EE30 PauseCheck__10MaximoMainFv
// note: DIFF 502 (525 first); differs in m_unk19814 compare scheduling and branch forms at 0x5C/0x68/0x70-0x7C, 0x2A4 null-test form (sltiu vs sltu/xori), m_unk19A7C&1 layout at 0x8C-0xA4, switch/jump-table tail after 0x0CC, size 0x830 vs 0x878, PlaySoundUbiquitous reloc at 0x848. Tried: tmp removal (no change), fm local (514), reversed early-return ternary (502), 0x2A4 ternary respelling (no change), 0x19814 if-form (no change).
int MaximoMain::PauseCheck() {
    void *p;
    int pad;
    int state;
    int var;
    void *text;

    if (gInterface[0x425] == 0) {
        goto block_2;
    }
    return (m_unk19A7C != 0) ? 3 : 0;
block_2:
    p = m_unk1883C;
    if (p == 0) {
        goto block_5;
    }
    if (IsPauseDisabled__6PlayerFv(p) == 0) {
        goto block_7;
    }
block_5:
    return 0;
block_7:
    if (m_unk19814 != 1) {
        goto block_10;
    }
    return 0;
block_10:
    if (m_unk19A7C & 1) {
        goto block_18;
    }
    var = (*(int *)((char *)p + 0x264) & 0x4000) != 0;
    if (var == 0) {
        goto block_13;
    }
    var = (*(void **)((char *)p + 0x2A4)) == 0;
block_13:
    if (!(var & 0xFF)) {
        goto block_18;
    }
    if (AbilityScreen__9InterfaceFv(gInterface) == 0) {
        goto block_17;
    }
    m_unk19A7C |= 2;
    return m_unk19A7C & 3;
block_17:
    m_unk19A7C &= ~2;
block_18:
    pad = ReadPush__3PadFv(gPad) & 0xFFFF;
    FontManager *fm = (FontManager *)(gInterface + 0x80);
    if (m_unk19A7C != 0) {
        goto block_20;
    }
    if (IsConnected__3PadFv(gPad) == 0) {
        goto block_23;
    }
block_20:
    if (!(pad & 8)) {
        goto block_27;
    }
    if (m_unk19A84 >= 3) {
        goto block_26;
    }
block_22:
block_23:
    gGfxEng[0x1558B0] = (char)(m_unk19A7C != 0);
    m_unk19A7C ^= 1;
    PauseVibrate__3PadFb(gPad, m_unk19A7C != 0);
    m_unk19A84 = 0;
    if (m_unk19A7C == 0) {
        goto block_25;
    }
    RemoveAll__11FontManagerFb(fm, false);
    PauseDisplay(0);
    Pause__6PSoundFv(gSound);
    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x3E);
    SetPause__9InterfaceFv(gInterface);
    DisplayLevelName__9InterfaceFii(gInterface, -1, 0xF0);
    goto block_26;
block_25:
    Resume__6PSoundFv(gSound);
    fm->RemoveText((unsigned short)4);
    fm->RemoveText((unsigned short)5);
    return 3;
block_26:
block_27:
    if (!(m_unk19A7C & 3)) {
        goto block_77;
    }
    state = m_unk19A84;
    var = pad & 0x50;
    if ((unsigned int)state >= 0xB) {
        goto block_69;
    }
    switch (state) {
    case 0:
        if (!(pad & 0x4000)) {
            goto block_68;
        }
        PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
        goto block_22;
    case 1:
        if (!(pad & 0x4000)) {
            goto block_68;
        }
        PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
        m_unk19A70 = 2;
        return 3;
    case 2:
        if (!(pad & 0x4000)) {
            goto block_68;
        }
        PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
        m_unk19A84 = 3;
        m_unk19A94 = fm->DisplayString(5, 0, 0, false);
        text = fm->DisplayString(6, 0, 0, false);
        m_unk19A98 = text;
        *(float *)((char *)text + 8) = 0.5f;
        fm->DisplayString(8, 0, 0, false);
        return 3;
    case 3:
    case 4:
        if (!(pad & 0x4000)) {
            goto block_42;
        }
        PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
        fm->RemoveText((unsigned short)5);
        if (m_unk19A84 != 3) {
            goto block_40;
        }
        m_unk19A84 = 8;
        FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 8.5f, true, 0);
        goto block_46;
    block_40:
        m_unk19A84 = 5;
        goto block_46;
    block_42:
        if (!(pad & 0xA0)) {
            goto block_46;
        }
        var = 3;
        *(float *)((char *)m_unk19A88[state] + 8) = 0.5f;
        if (m_unk19A84 != 3) {
            goto block_45;
        }
        var = 4;
    block_45:
        m_unk19A84 = var;
        *(float *)((char *)m_unk19A88[m_unk19A84] + 8) = 1.0f;
        PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
    block_46:
        return 3;
    case 5:
        m_unk19A84 = 7;
        text = fm->DisplayString(5, 0, 0, false);
        m_unk19A94 = text;
        *(float *)((char *)text + 8) = 0.5f;
        m_unk19A98 = fm->DisplayString(6, 0, 0, false);
        fm->DisplayString(7, 0, 0, false);
        return 3;
    case 6:
    case 7:
        if (!(pad & 0x4000)) {
            goto block_54;
        }
        PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
        fm->RemoveText((unsigned short)5);
        if (m_unk19A84 != 6) {
            goto block_52;
        }
        m_unk19A84 = 0;
        QuitGame();
        goto block_58;
    block_52:
        m_unk19A84 = 2;
        goto block_58;
    block_54:
        if (!(pad & 0xA0)) {
            goto block_58;
        }
        var = 6;
        *(float *)((char *)((void **)&m_unk19A7C)[state] + 8) = 0.5f;
        if (m_unk19A84 != 6) {
            goto block_57;
        }
        var = 7;
    block_57:
        m_unk19A84 = var;
        *(float *)((char *)((void **)&m_unk19A7C)[m_unk19A84] + 8) = 1.0f;
        PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
    block_58:
        return 3;
    case 8:
        if (gInterface[0x425] != 0) {
            goto block_61;
        }
        m_unk19A84 += 1;
        RemoveAll__11FontManagerFb(fm, true);
        FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 8.5f, true, 0);
        InitSaveGame__10MemoryCardFPQ26Player10PlayerDataib(gMC, (char *)m_unk1883C + 0x1D0, m_unk19A78, false);
    block_61:
        return 3;
    case 9:
        if (gInterface[0x425] != 0) {
            goto block_64;
        }
        m_unk19A84 += 1;
    block_64:
        return 3;
    case 10:
        if (SaveGame__10MemoryCardFv(gMC) == -1) {
            goto block_67;
        }
        m_unk19A84 = 5;
        PauseDisplay(2);
    block_67:
        return 3;
    }
block_68:
    var = pad & 0x50;
block_69:
    if (var == 0) {
        goto block_76;
    }
    pad &= 0x40;
    *(float *)((char *)m_unk19A88[state] + 8) = 0.5f;
    if (pad == 0) {
        goto block_72;
    }
    var = 1;
    goto block_73;
block_72:
    var = -1;
block_73:
    m_unk19A84 += var;
    if ((unsigned int)m_unk19A84 < 3) {
        goto block_75;
    }
    m_unk19A84 = (pad == 0) ? 2 : 0;
block_75:
    *(float *)((char *)m_unk19A88[m_unk19A84] + 8) = 1.0f;
    PlaySoundUbiquitous__6PSoundFUi(gSound, 0x40);
block_76:
block_77:
    return m_unk19A7C & 3;
}

// FUNCTION: 0x0013F6B0 __dt__10MaximoMainFv
extern "C" void *__dt__10MaximoMainFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        __dt__6CameraFv((char *)pThis + 0x19760, -1);
        __dt__13EntityManagerFv((char *)pThis + 0x137E0, -1);
        __dt__9MaxEngineFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0013F730 __ct__10MaximoMainFv
extern "C" MaximoMain *__ct__10MaximoMainFv(MaximoMain *volatile pThis)
{
    __ct__9MaxEngineFv(pThis);
    __ct__13EntityManagerFv((char *)pThis + 0x137E0);
    __ct__6CameraFv((char *)pThis + 0x19760);
    pThis->m_unk19AC4 = 0;
    pThis->m_unk19A7C = 0;
    pThis->m_unk19B54 = 0;
    pThis->m_unk19B58 = 0;
    pThis->m_unk19B44 = 0;
    pThis->m_unk19B48 = 0;
    pThis->m_unk19B4C = 0;
    pThis->m_unk19AA0 = 0;
    return pThis;
}
