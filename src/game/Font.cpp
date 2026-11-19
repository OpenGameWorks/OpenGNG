#include "Font.h"

// TODO(header): foreign declarations
class PArray {
public:
    int Remove(void *pItem);
    void Add(void *pItem);
};

class PMovieOverlayEngine {
public:
    void InitTextures(int *pTextures, int nCount);
    char _pad[0x10];
};

extern PMovieOverlayEngine gOverlayEng;
extern unsigned char FontColors[176];

// FUNCTION: 0x132F30 InitSubTitle__11FontManagerFi
void FontManager::InitSubTitle(int arg0) {
    int var = 0;
    if (arg0 != 0) {
        var = m_unk100 + (arg0 * 0xC);
    }
    m_unk12C = var;
    m_unk134 = 0;
    m_unk130 = 0xFFFF;
}

// FUNCTION: 0x133250 RemoveText__11FontManagerFP8FontNode
void FontManager::RemoveText(FontNode *pNode) {
    if (((PArray *)this)->Remove(pNode) != 0) {
        ((PArray *)((char *)this + 0x1C))->Add(pNode);
    }
}

// DRAFT: 0x133350 SetColor__8FontNodeF9FontColor
// note: original guards the loop with beqz a0 before it and is 0x48 bytes; plain while gives 6 differing lines; guarded do-while and while variants gave 14 and 16.
void FontNode::SetColor(FontColor arg0) {
    char *p = m_unk0;
    int n = m_unk4;
    while (n != 0) {
        n -= 1;
        *(u_long128 *)(p + 0x20) = *(u_long128 *)(FontColors + arg0 * 16);
        p += 0x40;
    }
}

// DRAFT: 0x1340E0 AdvanceText__8FontNodeFv
// note: original loads m_unkC into v1 before m_unk4 into v0 (slt at,v1,v0); ours loads m_unk4 first; 3 differing lines after about 9 variants.
int FontNode::AdvanceText() {
    int ret = 0;
    if (m_unk4 > m_unkC) {
        ret = 1;
        m_unkC = m_unkC + 1;
    }
    return ret;
}

// FUNCTION: 0x134690 InitFMV__11FontManagerFv
void FontManager::InitFMV() {
    int nTexture = m_unk10C;
    gOverlayEng.InitTextures(&nTexture, 1);
}
