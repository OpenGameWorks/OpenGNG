#ifndef DEBUG_H
#define DEBUG_H

class ETiming;

class Debug {
public:
    void StopDebugTimer(void *pArg);
    void ResetDebugTimer();
    void DebugDisp(char *pStr);
    void DebugColorDisp(char *pStr, unsigned char nColor);
    void DebugClear();
    void LineFeed(char *pStr);
    void RenderPerformanceMeters();
    void StopTimer(unsigned int nId);
    void StartTimer(unsigned int nId);

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
    char _pad028[0x2D - 0x28];
    unsigned char m_unk2D;          // 0x02D
};

#endif
