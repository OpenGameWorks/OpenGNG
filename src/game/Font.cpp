// FLAGS: -str readonly
#include "Font.h"

// TODO(header): foreign declarations
class PArray {
public:
    int Remove(void *pItem);
    void Add(void *pItem);
    void RemoveCurrent();
    void Allocate(unsigned int nCount);
};

class PResourceManager {
public:
    int GetResource(unsigned int nId, bool bFlag);
    int LoadGlobalResource(const char *pName, bool bFlag);
};

struct tagVuSprite;

class PMovieOverlayEngine {
public:
    void InitTextures(int *pTextures, int nCount);
    void BeginSprites();
    void DrawSprites(tagVuSprite *pSprite, int nCount, bool bFlag);
    void EndSprites();
    void SetMaterial(int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
    char _pad[0x10];
};

extern PMovieOverlayEngine gOverlayEng;
extern unsigned char FontColors[176];
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dla__FPv(void *pMem);
extern "C" int printf(const char *fmt, ...);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
class Innocent {
public:
    static int BuildDialogTable();
};
extern int LanguageTable[6];
void CdsAssert(char *pszFile, int nLine, char *pszExpr);
extern "C" void *__ct__6PArrayFv(void *pThis);
extern "C" void *__ct__16PResourceManagerFv(void *pThis);
extern "C" void *__dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void *__dt__16PResourceManagerFv(void *pThis, short nFlag);
extern "C" float FastMath_Fabs__Ff(float f);
extern "C" void *__dt__8FontNodeFv(FontNode *pThis, short nFlag);
extern unsigned char mbFadeOut__8FontNode;
extern char *mpTextBox__8FontNode;
extern int mbEnableBox__8FontNode;
extern unsigned char gInterface[];
extern char Large_fontCharDef[0x100];
extern float BOXX;
extern float BOXY;

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

// FUNCTION: 0x132F70 Scroll__8FontNodeFf
int FontNode::Scroll(float arg0) {
    int nIndex = 0;
    int nOffset = 0;
    while (nIndex < m_unk4) {
        *(float *)(m_unk0 + nOffset + 4) += arg0;
        if (!(*(float *)(m_unk0 + nOffset + 4) <= 30.0f)) {
            return 0;
        }
        nOffset += 0x40;
        nIndex++;
    }
    if (m_unk4 != 0) {
        m_unk8 = (30.0f - FastMath_Fabs__Ff(*(float *)(m_unk0 + 4))) / 30.0f;
    }
    return 1;
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
            pNode = ((unsigned int)nIndex < (unsigned int)m_unk0) ? m_unk8[m_unk4] : 0;
        } while (pNode != 0);
    }
}

// DRAFT: 0x1330C0 InitFrame__11FontManagerFv
// note: original is 0xD0 bytes against our 0xC8; original loads m_unk20 into a0 and stores a0 (new value) before the index reload, ours stores the old register and reloads; 25 words for both m_unk20 = m_unk20 + 1 and m_unk20++ (also tried local nIndex 28, pArg temp 43).
void FontManager::InitFrame() {
    FontNode *pNode;

    m_unk20 = 0;
    if (m_unk1C != 0) {
        pNode = *m_unk24;
    } else {
        pNode = 0;
    }
    if (pNode != 0) {
        do {
            __dt__8FontNodeFv(pNode, 1);
            if (pNode == m_unk18) {
                m_unk18 = 0;
                m_unk14 = 0;
                m_unk12 = 0;
                m_unk120 = 0;
                mbFadeOut__8FontNode = 0;
            }
            m_unk20 = m_unk20 + 1;
            pNode = 0;
            if ((unsigned int)m_unk20 < (unsigned int)m_unk1C) {
                pNode = m_unk24[m_unk20];
            }
        } while (pNode != 0);
    }
    if (m_unk24 != 0) {
        m_unk1C = 0;
        m_unk20 = 0;
    }
}

// FUNCTION: 0x133190 RemoveAll__11FontManagerFb
void FontManager::RemoveAll(bool arg0) {
    FontNode *pNode;

    m_unk4 = 0;
    if (m_unk0 != 0) {
        pNode = *m_unk8;
    } else {
        pNode = 0;
    }
    if (pNode != 0) {
        do {
            ((PArray *)((char *)this + 0x1C))->Add(pNode);
            int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            pNode = 0;
            if ((unsigned int)nIndex < (unsigned int)m_unk0) {
                pNode = m_unk8[m_unk4];
            }
        } while (pNode != 0);
    }
    if (m_unk8 != 0) {
        m_unk0 = 0;
        m_unk4 = 0;
    }
    m_unk18 = 0;
    m_unk14 = 0;
    m_unk12 = 0;
    m_unk120 = 0;
    mbFadeOut__8FontNode = 0;
    ResetWarning();
}

// FUNCTION: 0x133250 RemoveText__11FontManagerFP8FontNode
void FontManager::RemoveText(FontNode *pNode) {
    if (((PArray *)this)->Remove(pNode) != 0) {
        ((PArray *)((char *)this + 0x1C))->Add(pNode);
    }
}

// FUNCTION: 0x133290 RemoveText__11FontManagerFUs
void FontManager::RemoveText(unsigned short nId) {
    m_unk4 = 0;
    FontNode *pNode = (m_unk0 != 0) ? m_unk8[0] : 0;
    if (pNode != 0) {
        do {
            if (nId == pNode->m_unk6) {
                ((PArray *)((char *)this + 0x1C))->Add(pNode);
                ((PArray *)this)->RemoveCurrent();
            }
            int nIndex = m_unk4 + 1;
            m_unk4 = nIndex;
            pNode = ((unsigned int)nIndex < (unsigned int)m_unk0) ? m_unk8[m_unk4] : 0;
        } while (pNode != 0);
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

// FUNCTION: 0x1333A0 GetTextCount__11FontManagerFi
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

// FUNCTION: 0x133410 JapanAddNumber__11FontManagerFPUsPUsi
unsigned short *FontManager::JapanAddNumber(unsigned short *pStr, unsigned short *pNum, int nUnused) {
    unsigned short *pDst = (unsigned short *)this;
    unsigned short *pSrc = pStr;
    unsigned short c;
    char buf[8];
    for (;;) {
        c = *pSrc;
        pSrc++;
        if (c == 0) {
            break;
        }
        *pDst = c;
        pDst++;
    }
    if ((int)pNum >= 0) {
        *pDst = 0x20;
        pDst++;
        sprintf(buf, "%d", (int)pNum);
        char *pBuf;
        int i;
        i = 0;
        pBuf = buf;
        for (;;) {
            c = (unsigned short)pBuf[i];
            if (c == 0) {
                break;
            }
            *pDst = c;
            i++;
            pDst++;
            if (i >= 8) {
                break;
            }
        }
    }
    *pDst = 0;
    return pDst;
}

// DRAFT: 0x1338A0 AdjustTextBox__8FontNodeFPf
// note: our code is 0xC0 bytes vs 0xB8; BOXX/BOXY gp offsets and the mpTextBox reload pattern differ, 32 words.
void FontNode::AdjustTextBox(float *arg0) {
    char *pMesh;
    float *pBox;

    pBox = (float *)this;
    if (mpTextBox__8FontNode != 0) {
        pMesh = *(char **)(mpTextBox__8FontNode + 0x10);
        if (pMesh == 0) {
            CdsAssert("Font.cpp", 0x282, "pMesh");
        }
        *(float *)(mpTextBox__8FontNode + 0x40) = ((BOXX + (pBox[2] - pBox[0])) * 0.5f) / *(float *)(pMesh + 0x20);
        *(float *)(mpTextBox__8FontNode + 0x54) = ((BOXY + (pBox[3] - pBox[1])) * 0.5f) / *(float *)(pMesh + 0x24);
        *(float *)(mpTextBox__8FontNode + 0x74) = 0.5f * (pBox[3] + pBox[1]);
    }
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

// FUNCTION: 0x133E70 ResetWarning__11FontManagerFv
void FontManager::ResetWarning() {
    m_unk114 = 0;
    FontNode *pNode = (m_unk110 != 0) ? m_unk118[0] : 0;
    if (pNode != 0) {
        do {
            ((PArray *)((char *)this + 0x1C))->Add(pNode);
            int nIndex = m_unk114 + 1;
            m_unk114 = nIndex;
            pNode = ((unsigned int)nIndex < (unsigned int)m_unk110) ? m_unk118[m_unk114] : 0;
        } while (pNode != 0);
    }
    if (m_unk118 != 0) {
        m_unk110 = 0;
        m_unk114 = 0;
    }
    m_unk122 = 0;
    m_unk124 = 0;
    m_unk121 = 1;
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

// DRAFT: 0x134110 RenderFMV__8FontNodeFiP9FontTableb
// note: 1 word differs, the c.eq.s operand order ($f1,$f0 in original); tried shared epilogue, 0x3048D constant, swapped compare operands, !(m_unk8 == 0.0f); all still 1 word.
int FontNode::RenderFMV(int nId, FontTable *pTable, bool bUnused) {
    float afColor[4];

    if (m_unkC >= 2) {
        if (!(m_unk8 == 0.0f)) {
            afColor[0] = m_unk8;
            afColor[1] = m_unk8;
            afColor[2] = m_unk8;
            afColor[3] = 1.0f;
            pTable = (FontTable *)((char *)pTable + m_unkE * 12);
            gOverlayEng.BeginSprites();
            nId = *(int *)((char *)pTable + 8);
            gOverlayEng.SetMaterial(nId, afColor, 0, 0x44, 0x3048D);
            gOverlayEng.DrawSprites((tagVuSprite *)m_unk0, m_unkC, 0);
            gOverlayEng.EndSprites();
        }
    }
    return nId;
}

// FUNCTION: 0x134690 InitFMV__11FontManagerFv
void FontManager::InitFMV() {
    int nTexture = m_unk10C;
    gOverlayEng.InitTextures(&nTexture, 1);
}

// FUNCTION: 0x1346C0 Init__11FontManagerFv
void FontManager::Init() {
    static char FontFile[] = "PSXDATA\\RESOURCE\\FONT.PAK";
    ((PArray *)this)->Allocate(0x30);
    ((PArray *)((char *)this + 0x1C))->Allocate(0x30);
    ((PArray *)((char *)this + 0x110))->Allocate(4);
    if (((PResourceManager *)m_unk2C)->LoadGlobalResource(FontFile, 0) == 0) {
        CdsAssert("Font.cpp", 0x5E, "0");
    }
    gInterface[0x1B37] = 1;
    m_unk104 = (int)&Large_fontCharDef | 0x30000000;
    m_unk108 = 0x21;
    m_unk10A = 0xFE;
    m_unk10C = ((PResourceManager *)m_unk2C)->GetResource(0x8400000B, 0);
    mpTextBox__8FontNode = (char *)((PResourceManager *)m_unk2C)->GetResource(0x810001DC, 0);
    mbEnableBox__8FontNode = 0;
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

// FUNCTION: 0x134820 __dt__11FontManagerFv
extern "C" void *__dt__11FontManagerFv(FontManager *pThis, short nFlag) {
    if (pThis != 0) {
        pThis->RemoveAll(1);
        pThis->InitFrame();
        pThis->ResetWarning();
        __dt__6PArrayFv((char *)pThis + 0x110, -1);
        __dt__16PResourceManagerFv((char *)pThis + 0x2C, -1);
        __dt__6PArrayFv((char *)pThis + 0x1C, -1);
        __dt__6PArrayFv(pThis, -1);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
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
