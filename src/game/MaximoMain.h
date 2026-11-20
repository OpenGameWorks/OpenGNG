#ifndef MAXIMOMAIN_H
#define MAXIMOMAIN_H

#include "types.h"

class PMNode;
class PArray;
class MemorySetting;
class FontManager;
struct LevelFiles;

class MaximoMain {
public:
    MaximoMain();
    void InitGameTimes();
    void Controls();
    void UpdateGameTimes();
    void LoadTitleMesh();
    int LoadGame();
    void InitPlayDemo(int arg0);
    void InitStaticDemo();
    void DeletePressStart();
    void PressStart(int arg0);
    void QuitGame();
    int MapscreenOpenBonusExists();
    int PlayMarkerSound(int arg0);
    int PlayBGSound(int arg0);
    void RestartGame(bool arg0);
    void SetLevelClear();
    void *GetLevelFile(int arg0);
    PMNode *SetMarker(PMNode *arg0, int arg1, PMNode *arg2);
    void SetMarkerAsMastered(PMNode *arg0, PMNode *arg1);
    void GetMapScreenPath(PMNode *arg0, int arg1, PArray &arg2, bool arg3);
    int InitCutSceneIfDialogReady();
    int StartCutScene(int arg0);
    unsigned int FindFirstDialog(LevelFiles const *arg0, bool arg1);
    void InitCutScene();
    void PauseDisplay(int arg0);
    void RefreshOptionsValue(MemorySetting *arg0, bool arg1);
    void MainGame();
    int Game(int arg0);
    int AttractDemo();
    int TitleDemo();
    int GameSelect();
    void Options();
    void MapscreenPrintInfo(FontManager *arg0, int arg1);

    char _pad000[0xD0];
    int m_unkD0;            // 0x0D0
    int m_unkD4;            // 0x0D4
    int m_unkD8;            // 0x0D8, 0x42180000 (38.0f) after InitStaticDemo
    char _pad0DC[0x260 - 0xDC];
    char _pad00260[0x8720 - 0x260]; // 0x00260, cut scene slots of CutSlot size 0x2140 (four slots)
    signed char m_unk8720;  // 0x08720, set to 1 by InitCutScene
    char _pad08721[3];
    int m_unk8724;          // 0x08724, cut scene index, checked against 4 by InitCutScene
    char _pad08728[0x8760 - 0x8728];
    char _pad08760[0x1883C - 0x8760];
    void *m_unk1883C;       // 0x1883C, EntityBaseClass pointer driven by SetLevelClear
    char _pad18840[0x19784 - 0x18840];
    int m_unk19784;         // 0x19784
    char _pad19788[0x19A70 - 0x19788];
    int m_unk19A70;         // 0x19A70, game state (7 after MainGame's LoadGame succeeds, 8 after QuitGame, 6 after SetLevelClear, 9/10 after RestartGame)
    int m_unk19A74;         // 0x19A74, MainGame state switch word
    int m_unk19A78;         // 0x19A78, fallback level index for GetLevelFile
    int m_unk19A7C;         // 0x19A7C, cleared by the constructor
    char _pad19A80[0x19A88 - 0x19A80];
    void *m_unk19A88[3];    // 0x19A88, PauseDisplay font strings
    char _pad19A94[0x19AA0 - 0x19A94];
    int m_unk19AA0;         // 0x19AA0, cleared by the constructor
    int m_unk19AA4;         // 0x19AA4, dialog stream handle checked by InitCutSceneIfDialogReady
    int m_unk19AA8;         // 0x19AA8, dialog index chosen by FindFirstDialog (-1 when none)
    int m_unk19AAC;        // 0x19AAC, cleared by SetLevelClear
    char _pad19AB0[0x19AC0 - 0x19AB0];
    int m_unk19AC0;         // 0x19AC0, set to -1 by AttractDemo
    void *m_unk19AC4;      // 0x19AC4, press-start FontNode, cleared by DeletePressStart
    PMNode *m_unk19AC8;     // 0x19AC8, title mesh root loaded by LoadTitleMesh
    PMNode *m_unk19ACC;     // 0x19ACC, title animation node found by LoadTitleMesh
    PMNode *m_unk19AD0;     // 0x19AD0, copyright node found by LoadTitleMesh
    int m_unk19AD4;         // 0x19AD4, press-start state counter (0 to 30 pulse)
    char _pad19AD8[0x19AE0 - 0x19AD8];
    void *m_unk19AE0;       // 0x19AE0, FontNode colored by RefreshOptionsValue (sound mono)
    void *m_unk19AE4;       // 0x19AE4, FontNode colored by RefreshOptionsValue (sound mono)
    char _pad19AE8[0x19B04 - 0x19AE8];
    void *m_unk19B04;       // 0x19B04, FontNode colored by RefreshOptionsValue (vibrate)
    void *m_unk19B08;       // 0x19B08, FontNode colored by RefreshOptionsValue (vibrate)
    char _pad19B0C[0x19B3C - 0x19B0C];
    PMNode *m_unk19B3C;     // 0x19B3C, slider mesh scaled by the main music volume
    PMNode *m_unk19B40;     // 0x19B40, slider mesh scaled by the effects volume
    int m_unk19B44;         // 0x19B44, cleared by the constructor
    int m_unk19B48;         // 0x19B48, cleared by the constructor
    int m_unk19B4C;         // 0x19B4C, cleared by the constructor
    char _pad19B50[0x19B54 - 0x19B50];
    int m_unk19B54;         // 0x19B54, demo table index, advanced by InitPlayDemo and wrapped at 2
    int m_unk19B58;         // 0x19B58, cleared by the constructor
    int m_unk19B5C;         // 0x19B5C, demo value set by InitPlayDemo
    char _pad19B60[0x19B6C - 0x19B60];
    int m_unk19B6C;         // 0x19B6C
    int m_unk19B70;         // 0x19B70
    int m_unk19B74;         // 0x19B74
    int m_unk19B78;         // 0x19B78
    int m_unk19B7C;         // 0x19B7C
    int m_unk19B80;         // 0x19B80
};

#endif
