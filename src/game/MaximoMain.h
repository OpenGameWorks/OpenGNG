#ifndef MAXIMOMAIN_H
#define MAXIMOMAIN_H

#include "types.h"

class MaximoMain {
public:
    void InitGameTimes();
    void InitStaticDemo();
    void DeletePressStart();
    int MapscreenOpenBonusExists();
    void *GetLevelFile(int arg0);

    char _pad000[0xD0];
    int m_unkD0;            // 0x0D0
    int m_unkD4;            // 0x0D4
    int m_unkD8;            // 0x0D8, 0x42180000 (38.0f) after InitStaticDemo
    char _pad0DC[0x19784 - 0xDC];
    int m_unk19784;         // 0x19784
    char _pad19788[0x19A78 - 0x19788];
    int m_unk19A78;         // 0x19A78, fallback level index for GetLevelFile
    char _pad19A7C[0x19AC4 - 0x19A7C];
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
