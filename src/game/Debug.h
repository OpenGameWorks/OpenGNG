#ifndef DEBUG_H
#define DEBUG_H

class ETiming;

class Debug {
public:
    Debug();
    ~Debug();
    void StartDebugTimer();
    void StopDebugTimer(void *pArg);
    void ResetDebugTimer();
    void DebugDisp(char *pStr);
    void DebugDispPos(char *pStr, unsigned int nX, unsigned int nY, int nColor);
    void DebugColorDisp(char *pStr, unsigned char nColor);
    void DebugClear();
    void LineFeed(char *pStr);
    void FrameEnd();
    void RenderPerformanceMeters();
    void DispDebugTimer();
    void StopTimer(unsigned int nId);
    void StartTimer(unsigned int nId);
    void InitDebug();

    short IsNoDamage();
    char *m_unk00;                  // 0x000 passed to sceDevConsPrintf
    unsigned int m_unk04;           // 0x004 zeroed by DebugClear
    unsigned int m_unk08;           // 0x008 newline count, zeroed by DebugClear, bumped by LineFeed
    ETiming *m_unk0C;               // 0x00C
    unsigned int m_unk10;           // 0x010
    unsigned int m_unk14;           // 0x014
    unsigned int m_unk18;           // 0x018
    unsigned int m_unk1C;           // 0x01C
    unsigned int m_unk20;           // 0x020

    void *m_unk24;                  // 0x024
    unsigned int m_unk28;           // 0x028 zeroed by the constructor
    unsigned char m_unk2C;          // 0x02C zeroed by the constructor
    unsigned char m_unk2D;          // 0x02D
    char _pad02E[0x34 - 0x2E];
    unsigned int m_unk34;           // 0x034 zeroed by InitDebug
};

#endif
