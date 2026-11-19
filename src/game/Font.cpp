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
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dla__FPv(void *pMem);
extern "C" int printf(const char *fmt, ...);
class Innocent {
public:
    static int BuildDialogTable();
};
extern int LanguageTable[6];
void CdsAssert(char *pszFile, int nLine, char *pszExpr);
extern "C" void *__ct__6PArrayFv(void *pThis);
extern "C" void *__ct__16PResourceManagerFv(void *pThis);

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

// FUNCTION: 0x133030 EnableAllText__11FontManagerFb
void FontManager::EnableAllText(bool arg0) {
    float fAlpha;
    if (arg0) {
        fAlpha = 1.0f;
    } else {
        fAlpha = 0.0f;
    }
    m_unk4 = 0;
    FontNode *pNode = (m_unk0 != 0) ? m_unk8[0] : 0;
    if (pNode != 0) {
        do {
            pNode->m_unk8 = fAlpha;
            int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            if ((unsigned int)nIndex < (unsigned int)m_unk0) {
                pNode = m_unk8[m_unk4];
            } else {
                pNode = 0;
            }
        } while (pNode != 0);
    }
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

// DRAFT: 0x1333A0 GetTextCount__11FontManagerFi
// note: the original's loop-exit branch lands on an extra nop before the epilogue (5 differing lines); tried a return-in-loop form (9), a while form with count+1 (19), a do-while (5) and the for+break form kept here (5).
int FontManager::GetTextCount(int arg0) {
    if ((unsigned int)arg0 >= 0x56E) {
        printf("Invalid text ID %d\n", arg0);
        return 0;
    }
    int count = 0;
    char *p = (char *)(m_unk100 + arg0 * 0xC);
    for (;;) {
        count += 1;
        if (p[9] & 1) {
            break;
        }
        p += 0xC;
    }
    return count;
}

// FUNCTION: 0x133E00 __dt__8FontNodeFv
extern "C" void *__dt__8FontNodeFv(FontNode *pThis, short nFlag) {
    if (pThis != 0) {
        if (pThis->m_unk0 != 0) {
            __dla__FPv(pThis->m_unk0);
            pThis->m_unk0 = 0;
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
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

// FUNCTION: 0x1347A0 SetLanguage__11FontManagerFc
void FontManager::SetLanguage(char arg0) {
    int nLang = arg0;
    if ((unsigned int)nLang >= 6) {
        CdsAssert("Font.cpp", 0x43, "iLanguage < sizeof(LanguageTable) / 4");
    }
    m_unk13 = arg0;
    m_unk100 = LanguageTable[nLang];
    m_unkFC = Innocent::BuildDialogTable();
}

// FUNCTION: 0x1348C0 __ct__11FontManagerFv
extern "C" void *__ct__11FontManagerFv(FontManager *pThis) {
    FontManager *volatile pSelf = pThis;
    __ct__6PArrayFv(pSelf);
    __ct__6PArrayFv((char *)pSelf + 0x1C);
    __ct__16PResourceManagerFv((char *)pSelf + 0x2C);
    __ct__6PArrayFv((char *)pSelf + 0x110);
    pSelf->SetLanguage(1);
    pSelf->m_unk18 = 0;
    pSelf->m_unk10 = 0;
    pSelf->m_unk122 = 0;
    pSelf->m_unk128 = 0;
    return pSelf;
}
