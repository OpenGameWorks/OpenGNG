#ifndef FONT_H
#define FONT_H

#include "types.h"

enum FontColor {
    FONTCOLOR_0,
    FONTCOLOR_1,
    FONTCOLOR_2,
    FONTCOLOR_3,
    FONTCOLOR_4,
    FONTCOLOR_5,
    FONTCOLOR_6,
    FONTCOLOR_7,
    FONTCOLOR_8,
    FONTCOLOR_9,
    FONTCOLOR_10
};

enum FontAlign {
    FONTALIGN_0,
    FONTALIGN_1,
    FONTALIGN_2
};

struct FontSubtitle {
    char *m_unk0;               // 0x00 text pointer
    short m_unk4;               // 0x04 start time
    short m_unk6;               // 0x06 id
    signed char m_unk8;         // 0x08 colour
    signed char m_unk9;         // 0x09 end flag
    signed char m_unkA;         // 0x0A z value
};

class FontTable;

class FontNode {
public:
    void SetColor(FontColor arg0);
    int Scroll(float arg0);
    int AdvanceText();
    void AdjustTextBox(float *arg0);
    int RenderFMV(int nId, FontTable *pTable, bool bUnused);
    int Render(int nId, FontTable *pTable, bool bUnused);

    char *m_unk0;               // 0x000 vertex block, 0x40 bytes per entry, colour at +0x20
    unsigned short m_unk4;      // 0x004 entry count
    unsigned short m_unk6;      // 0x006 id, compared by FontManager::RemoveText(unsigned short)
    float m_unk8;               // 0x008 alpha, written by FontManager::EnableAllText
    unsigned short m_unkC;      // 0x00C visible entry count
    signed char m_unkE;         // 0x00E table entry index, scaled by 12 into FontTable
};

class FontManager {
public:
    void ProcessSubtitle(int arg0);
    void InitSubTitle(int arg0);
    void EnableAllText(bool arg0);
    void RemoveText(FontNode *pNode);
    void RemoveText(unsigned short nId);
    int GetTextCount(int arg0);
    unsigned short *JapanAddNumber(unsigned short *pStr, unsigned short *pNum, int nUnused);
    FontNode *DisplayString(char *pStr, float fX, float fY, int nZ, FontColor nColor, FontAlign nAlign);
    void InitFMV();
    void Init();
    void SetLanguage(char arg0);
    void ResetWarning();
    void RenderWarning(int arg0);
    void InitFrame();
    void RemoveAll(bool arg0);

    int m_unk0;                 // 0x000 base PArray: item count
    int m_unk4;                 // 0x004 base PArray: index
    FontNode **m_unk8;          // 0x008 base PArray: item table
    char _pad00C[0x4];
    unsigned char m_unk10;      // 0x010 cleared by the constructor
    char _pad011[0x1];
    unsigned char m_unk12;      // 0x012 cleared by InitFrame
    signed char m_unk13;        // 0x013 language index
    int m_unk14;                // 0x014 cleared by InitFrame
    FontNode *m_unk18;          // 0x018 current node, cleared by the constructor
    int m_unk1C;                // 0x01C second PArray: item count
    int m_unk20;                // 0x020 second PArray: index
    FontNode **m_unk24;         // 0x024 second PArray: item table
    char _pad028[0x4];
    char m_unk2C[0xD0];         // 0x02C embedded PResourceManager
    int m_unkFC;                // 0x0FC dialog table, from BuildDialogTable
    int m_unk100;               // 0x100 subtitle table, 12 bytes per entry
    int m_unk104;               // 0x104 font character table pointer, ORed with 0x30000000
    unsigned short m_unk108;    // 0x108 set by Init
    unsigned short m_unk10A;    // 0x10A set by Init
    int m_unk10C;               // 0x10C texture id passed to the FMV overlay
    int m_unk110;               // 0x110 third PArray: item count
    int m_unk114;               // 0x114 third PArray: index
    FontNode **m_unk118;        // 0x118 third PArray: item table
    char _pad11C[0x4];
    unsigned char m_unk120;     // 0x120 cleared by InitFrame
    unsigned char m_unk121;     // 0x121 warning flag, set by ResetWarning
    short m_unk122;             // 0x122 cleared by the constructor and ResetWarning
    float m_unk124;             // 0x124 warning fade, cleared by ResetWarning
    int m_unk128;               // 0x128 cleared by the constructor
    int m_unk12C;               // 0x12C current subtitle entry
    int m_unk130;               // 0x130 subtitle timer, 0xFFFF when idle
    unsigned char m_unk134;     // 0x134 subtitle flag
};

#endif
