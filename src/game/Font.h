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

class FontNode {
public:
    void SetColor(FontColor arg0);
    int Scroll(float arg0);
    int AdvanceText();

    char *m_unk0;               // 0x000 vertex block, 0x40 bytes per entry, colour at +0x20
    unsigned short m_unk4;      // 0x004 entry count
    unsigned short m_unk6;      // 0x006 id, compared by FontManager::RemoveText(unsigned short)
    float m_unk8;               // 0x008 alpha, written by FontManager::EnableAllText
    unsigned short m_unkC;      // 0x00C visible entry count
};

class FontManager {
public:
    void InitSubTitle(int arg0);
    void EnableAllText(bool arg0);
    void RemoveText(FontNode *pNode);
    void RemoveText(unsigned short nId);
    int GetTextCount(int arg0);
    unsigned short *JapanAddNumber(unsigned short *pStr, unsigned short *pNum, int nUnused);
    void InitFMV();
    void SetLanguage(char arg0);
    void ResetWarning();
    void InitFrame();
    void RemoveAll(bool arg0);

    int m_unk0;                 // 0x000 base PArray: item count
    int m_unk4;                 // 0x004 base PArray: index
    FontNode **m_unk8;          // 0x008 base PArray: item table
    char _pad00C[0x4];
    unsigned char m_unk10;      // 0x010 cleared by the constructor
    char _pad011[0x2];
    signed char m_unk13;        // 0x013 language index
    char _pad014[0x4];
    int m_unk18;                // 0x018 cleared by the constructor
    char _pad01C[0xE0];         // 0x01C second PArray
    int m_unkFC;                // 0x0FC dialog table, from BuildDialogTable
    int m_unk100;               // 0x100 subtitle table, 12 bytes per entry
    char _pad104[0x8];
    int m_unk10C;               // 0x10C texture id passed to the FMV overlay
    int m_unk110;               // 0x110 third PArray: item count
    int m_unk114;               // 0x114 third PArray: index
    FontNode **m_unk118;        // 0x118 third PArray: item table
    char _pad11C[0x5];
    signed char m_unk121;       // 0x121 warning flag, set by ResetWarning
    unsigned short m_unk122;    // 0x122 cleared by the constructor and ResetWarning
    int m_unk124;               // 0x124 cleared by ResetWarning
    int m_unk128;               // 0x128 cleared by the constructor
    int m_unk12C;               // 0x12C current subtitle entry
    int m_unk130;               // 0x130 subtitle timer, 0xFFFF when idle
    signed char m_unk134;       // 0x134 subtitle flag
};

#endif
