#ifndef MAXIMOMAIN_H
#define MAXIMOMAIN_H

#include "types.h"

class PMNode;

class MaximoMain {
public:
    void InitGameTimes();
    void InitStaticDemo();
    void DeletePressStart();
    void QuitGame();
    int MapscreenOpenBonusExists();
    int PlayMarkerSound(int arg0);
    int PlayBGSound(int arg0);
    void RestartGame(bool arg0);
    void SetLevelClear();
    void *GetLevelFile(int arg0);
    PMNode *SetMarker(PMNode *arg0, int arg1, PMNode *arg2);
    int InitCutSceneIfDialogReady();
    void InitCutScene();
    void PauseDisplay(int arg0);

    char _pad000[0xD0];
    int m_unkD0;            // 0x0D0
    int m_unkD4;            // 0x0D4
    int m_unkD8;            // 0x0D8, 0x42180000 (38.0f) after InitStaticDemo
    char _pad0DC[0x1883C - 0xDC];
    void *m_unk1883C;       // 0x1883C, EntityBaseClass pointer driven by SetLevelClear
    char _pad18840[0x19784 - 0x18840];
    int m_unk19784;         // 0x19784
    char _pad19788[0x19A70 - 0x19788];
    int m_unk19A70;         // 0x19A70, game state (8 after QuitGame, 6 after SetLevelClear, 9/10 after RestartGame)
    char _pad19A74[0x19A78 - 0x19A74];
    int m_unk19A78;         // 0x19A78, fallback level index for GetLevelFile
    char _pad19A7C[0x19A88 - 0x19A7C];
    void *m_unk19A88[3];    // 0x19A88, PauseDisplay font strings
    char _pad19A94[0x19AA4 - 0x19A94];
    int m_unk19AA4;         // 0x19AA4, dialog stream handle checked by InitCutSceneIfDialogReady
    char _pad19AA8[0x19AAC - 0x19AA8];
    int m_unk19AAC;        // 0x19AAC, cleared by SetLevelClear
    char _pad19AB0[0x19AC4 - 0x19AB0];
    void *m_unk19AC4;       // 0x19AC4, press-start FontNode, cleared by DeletePressStart
    char _pad19AC8[0x19B6C - 0x19AC8];
    int m_unk19B6C;         // 0x19B6C
    int m_unk19B70;         // 0x19B70
    int m_unk19B74;         // 0x19B74
    int m_unk19B78;         // 0x19B78
    int m_unk19B7C;         // 0x19B7C
    int m_unk19B80;         // 0x19B80
};

#endif
