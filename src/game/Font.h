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
    int AdvanceText();

    char *m_unk0;               // 0x000 vertex block, 0x40 bytes per entry, colour at +0x20
    unsigned short m_unk4;      // 0x004 entry count
    char _pad006[0x6];
    unsigned short m_unkC;      // 0x00C visible entry count
};

class FontManager {
public:
    void InitSubTitle(int arg0);
    void RemoveText(FontNode *pNode);
    void InitFMV();

    char _pad000[0x100];        // 0x000 base PArray, and a second PArray at 0x01C
    int m_unk100;               // 0x100 subtitle table, 12 bytes per entry
    char _pad104[0x8];
    int m_unk10C;               // 0x10C texture id passed to the FMV overlay
    char _pad110[0x1C];
    int m_unk12C;               // 0x12C current subtitle entry
    int m_unk130;               // 0x130 subtitle timer, 0xFFFF when idle
    signed char m_unk134;       // 0x134 subtitle flag
};

#endif
