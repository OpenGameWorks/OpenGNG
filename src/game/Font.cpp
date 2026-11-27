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
extern float mTextBox__8FontNode[4];
extern "C" void AdjustTextBox__8FontNodeFPf(float *arg0);
extern unsigned char gInterface[];
extern char Large_fontCharDef[0x100];
extern float BOXX;
extern float BOXY;
extern float WARNING_FADE;
extern char gGfxEng[1504384];
extern unsigned char gEng[0x1A000];
extern unsigned char gUnitMatrix[0x40];
extern "C" void InitRender__9InterfaceFv(void *pThis);
extern "C" void BeginFxRender__10PGfxEngineFv(void *pThis);
extern "C" void SetScreenMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetViewMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetClipMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void SetWorldMatrix__10PGfxEngineFP5PMat4(void *pThis, void *pMat);
extern "C" void BeginSprites__10PGfxEngineFv(void *pThis);
extern "C" void EndFxRender__10PGfxEngineFv(void *pThis);
extern "C" void SetMaterial__10PGfxEngineFiPfbUlUl(void *pThis, int nTexture, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void SetMaterial__10PGfxEngineFPfbUlUl(void *pThis, float *pColor, bool bFlag, unsigned long nArg4, unsigned long nArg5);
extern "C" void DrawSprites__10PGfxEngineFP11tagVuSpriteib(void *pThis, tagVuSprite *pSprite, int nCount, bool bFlag);
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" unsigned int strlen(const char *pStr);
extern unsigned char FontStyles[96];
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
class TextBoxVtbl {
public:
    virtual void Reserved();
    virtual void Draw(int nA, int nB, int nC);
};

// FUNCTION: 0x132E30 ProcessSubtitle__11FontManagerFi
void FontManager::ProcessSubtitle(int arg0) {
    int nDur;
    FontSubtitle *pEntry;
    FontNode *pNode;

    if (m_unk134 != 0) {
        if (arg0 < m_unk130) {
            return;
        }
        RemoveText(50);
        m_unk134 = 0;
        return;
    }
    pEntry = (FontSubtitle *)m_unk12C;
    if (pEntry == 0) {
        return;
    }
    if (arg0 < pEntry->m_unk4) {
        return;
    }
    RemoveText(50);
    pEntry = (FontSubtitle *)m_unk12C;
    pNode = DisplayString(pEntry->m_unk0, 0.0f, -220.0f, pEntry->m_unkA, (FontColor)pEntry->m_unk8, FONTALIGN_1);
    pNode->m_unk6 = 50;
    pEntry = (FontSubtitle *)m_unk12C;
    nDur = pEntry->m_unk6;
    if (nDur != 0) {
        m_unk130 = pEntry->m_unk4 + (short)nDur;
        m_unk134 = 1;
    }
    pEntry = (FontSubtitle *)m_unk12C;
    if (pEntry->m_unk9 != 0) {
        m_unk12C = 0;
        return;
    }
    m_unk12C = (int)(pEntry + 1);
    pEntry = (FontSubtitle *)m_unk12C;
    if (pEntry->m_unk4 < m_unk130) {
        m_unk134 = 0;
    }
}

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

// FUNCTION: 0x00132F60 Scroll__11FontManagerFf
void FontManager::Scroll(float value) {
    m_unk128 = value;
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

// FUNCTION: 0x1330C0 InitFrame__11FontManagerFv
void FontManager::InitFrame() {
    FontNode *pNode;

    m_unk20 = 0;
    for (pNode = (m_unk1C != 0) ? m_unk24[0] : 0; pNode != 0;
         pNode = ((unsigned int)++m_unk20 < (unsigned int)m_unk1C) ? m_unk24[m_unk20] : 0) {
        __dt__8FontNodeFv(pNode, 1);
        if (pNode == m_unk18) {
            m_unk18 = 0;
            m_unk14 = 0;
            m_unk12 = 0;
            m_unk120 = 0;
            mbFadeOut__8FontNode = 0;
        }
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
// note: 6 words; the original pads the short loop with two nops before bnez and one after its delay slot (0x48 bytes vs our 0x44)
void FontNode::SetColor(FontColor arg0) {
    char *p = m_unk0;
    u_long128 *c = (u_long128 *)(FontColors + arg0 * 16);
    int n = m_unk4;
    while (n != 0) {
        n--;
        *(u_long128 *)(p + 0x20) = *c;
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

// FUNCTION: 0x1334A0 DisplayString__11FontManagerFPcffi9FontColor9FontAlign
FontNode *FontManager::DisplayString(char *pStr, float fX, float fY, int nZ, FontColor nColor, FontAlign nAlign) {
    FontNode *pNode;

    if ((unsigned int)m_unk0 >= 0x30) {
        CdsAssert("Font.cpp", 0x317, "mFontList.GetCount() < MAX_TEXT");
    }
    pNode = new FontNode(this, pStr, fX, fY, 0, nZ, nColor, nAlign, false);
    if (pNode == 0) {
        CdsAssert("Font.cpp", 0x319, "pNode");
    }
    ((PArray *)this)->Add(pNode);
    mbEnableBox__8FontNode = 0;
    return pNode;
}

// DRAFT: 0x001335B0 DisplayString__11FontManagerFiiib
// note: DIFF 35 words: loop-bottom b target (0x58), ctor arg order (movz/movn for FontAlign, lh reuse), exit branch shape and tail store order; tried if-form, hoisted ternary, shared m_unk4 load, inverted ternary (97 words).
FontNode *FontManager::DisplayString(int nX, int nY, int nZ, bool bFlag) {
    FontNode *pFirst;
    FontSubtitle *pEntry;
    PArray *pList;
    FontNode *pNode;
    bool bNonZero;
    int nBox;

    if (nX >= m_unkFC) {
        printf("Invalid text ID %d\n", nX);
        return 0;
    }
    pFirst = 0;
    bNonZero = nY != 0;
    if (bNonZero) {
        RemoveText((unsigned short)9);
    }
    float box[4] = {1000.0f, 1000.0f, -1000.0f, -1000.0f};
    pEntry = (FontSubtitle *)(m_unk100 + nX * 12);
    nBox = pEntry->m_unk9 & 2;
    mbEnableBox__8FontNode = nBox;
    if (bFlag) {
        pList = (PArray *)((char *)this + 0x110);
    } else {
        pList = (PArray *)this;
    }
    while (1) {
        if (*(unsigned int *)pList >= 0x30) {
            CdsAssert("Font.cpp", 0x2A6, "pList->GetCount() < MAX_TEXT");
        }
        if (nY > 0) {
            if (pEntry->m_unkB != 9) {
                CdsAssert("Font.cpp", 0x2A8, "pString->iID == DIALOG_ID");
            }
        }
        pNode = new FontNode(this, pEntry->m_unk0, (float)pEntry->m_unk4, (float)(pEntry->m_unk6 + nZ), pEntry->m_unkB, pEntry->m_unkA, (FontColor)pEntry->m_unk8, (FontAlign)(pEntry->m_unk4 == 0 ? 1 : 0), bNonZero);
        if (pNode == 0) {
            CdsAssert("Font.cpp", 0x2AB, "pNode");
        }
        pList->Add(pNode);
        if (pFirst == 0) {
            pFirst = pNode;
        }
        if (nBox != 0) {
            if (mTextBox__8FontNode[0] < box[0]) {
                box[0] = mTextBox__8FontNode[0];
            }
            if (mTextBox__8FontNode[1] < box[1]) {
                box[1] = mTextBox__8FontNode[1];
            }
            if (mTextBox__8FontNode[2] > box[2]) {
                box[2] = mTextBox__8FontNode[2];
            }
            if (mTextBox__8FontNode[3] > box[3]) {
                box[3] = mTextBox__8FontNode[3];
            }
        }
        if (pEntry->m_unk9 & 1) {
            if (nBox != 0) {
                AdjustTextBox__8FontNodeFPf(box);
                m_unk120 = 1;
            }
            break;
        }
        pEntry++;
    }
    if (nY != 0) {
        if (nY > 0) {
            m_unk14 = nY;
        } else {
            nY = 0;
            m_unk14 = nY;
        }
        m_unk18 = pFirst;
        m_unk10 = 0;
        m_unk11 = 2;
        m_unk12 = 0;
    }
    return pFirst;
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

// DRAFT: 0x00133960 __ct__8FontNodeFP11FontManagerPcffUsi9FontColor9FontAlignb
// note: 215 words, size 0x480 vs 0x4A0; zero-store order, lbu at 0xC0, m_unkE reload, dispatch order differ. Tried: while loop (248), vCur[3] first (216), unsigned char temp (215).
FontNode::FontNode(FontManager *pMgr, char *pStr, float fX, float fY, unsigned short nArg4, int nZ, FontColor nColor, FontAlign nAlign, bool bFlag) {
    float vCur[4];
    float fMaxW;
    float fScale;
    float fAdv;
    float fW;
    char *pEntry;
    char *pTable;
    char *pEnt;
    char *pBlk;
    char *pRun;
    unsigned short nFirst;
    unsigned short nLen;
    unsigned int nCnt;
    unsigned int nN;
    int nState;
    unsigned char c;

    m_unk4 = 0;
    m_unk8 = 1.0f;
    m_unk6 = nArg4;
    vCur[0] = 0.0f;
    vCur[1] = 0.0f;
    vCur[2] = 10.0f;
    vCur[3] = 0.0f;
    fMaxW = 0.0f;
    ((nZ < 0xC) ? (void)0 : CdsAssert("Font.cpp", 0x1C8, "iFontStyle < MAX_FONT_STYLE"));
    fScale = *(float *)(FontStyles + nZ * 8 + 4);
    m_unkE = FontStyles[nZ * 8];
    ((m_unkE <= 0) ? (void)0 : CdsAssert("Font.h", 0x9A, "iFontSet < MaxFontSet"));
    pEntry = (char *)pMgr + 12 * m_unkE;
    pTable = *(char **)(pEntry + 0x104);
    nFirst = *(unsigned short *)(pEntry + 0x108);
    nLen = *(unsigned short *)(pEntry + 0x10A) - nFirst;
    nN = strlen(pStr);
    pBlk = new char[nN << 6];
    ((pBlk != 0) ? (void)0 : CdsAssert("Font.cpp", 0x215, "pSprite"));
    m_unk0 = pBlk;
    nState = nColor;
    if (*pStr) {
        do {
            c = (unsigned char)*pStr;
            pStr++;
            if (c == 0x96) {
                c = 0x2D;
            }
            if (c == 0 || c == 0x0A) {
                if (!(vCur[0] <= fMaxW)) {
                    fMaxW = vCur[0];
                }
                vCur[0] = 0.0f;
                vCur[1] -= 3.0f;
            } else if (c == 0x3D) {
                nState = 4;
            } else if (c == 0x3C) {
                nState = 3;
            } else if (c == 0x3B) {
                nState = 2;
            } else if (c == 0x2A) {
                nState = 1;
            } else if (c == 0x7E) {
                nState = 0;
            } else if (c == 0xA0 || c == 0x20) {
                vCur[0] += 1.0f;
            } else {
                if ((unsigned char)(c - nFirst) <= nLen) {
                    pEnt = pTable + (c << 5) - ((unsigned int)nFirst << 5);
                    if (*(float *)(pEnt + 0xC) == 1.0f) {
                        *(u_long128 *)(pBlk + 0x30) = *(u_long128 *)pEnt;
                        fAdv = *(float *)pEnt;
                        if (c == 0x31) {
                            fAdv += 0.3f;
                        }
                        vCur[0] += fAdv;
                        *(u_long128 *)pBlk = *(u_long128 *)vCur;
                        ((float *)pBlk)[1] += *(float *)(pEnt + 8);
                        vCur[0] += fAdv;
                        *(u_long128 *)(pBlk + 0x10) = *(u_long128 *)(pEnt + 0x10);
                        *(u_long128 *)(pBlk + 0x20) = *(u_long128 *)(FontColors + nState * 16);
                        pBlk += 0x40;
                        m_unk4++;
                    }
                }
            }
        } while (c != 0);
    }
    vCur[0] = 0.1f * fX;
    vCur[1] = 0.1f * fY;
    fW = fMaxW * fScale;
    if (nAlign == 2) {
        vCur[0] -= fW;
    } else if (nAlign == 1) {
        vCur[0] -= 0.5f * fW;
    }
    pRun = m_unk0;
    for (nCnt = m_unk4; nCnt != 0; nCnt--) {
        sceVu0ScaleVectorXYZ((float *)pRun, (float *)pRun, fScale);
        sceVu0AddVector((float *)pRun, (float *)pRun, vCur);
        sceVu0ScaleVectorXYZ((float *)(pRun + 0x30), (float *)(pRun + 0x30), fScale);
        pRun += 0x40;
    }
    mTextBox__8FontNode[0] = *(float *)m_unk0 - *(float *)(m_unk0 + 0x30);
    mTextBox__8FontNode[1] = *(float *)(m_unk0 + 4) - *(float *)(m_unk0 + 0x34);
    mTextBox__8FontNode[3] = *(float *)(m_unk0 + 4) + *(float *)(m_unk0 + 0x34);
    pEnt = m_unk0 + (m_unk4 << 6);
    mTextBox__8FontNode[2] = *(float *)(pEnt - 0x40) + *(float *)(pEnt - 0x10);
    m_unkC = bFlag ? 0 : m_unk4;
}

// FUNCTION: 0x133E00 __dt__8FontNodeFv
extern "C" void *__dt__8FontNodeFv(FontNode *pThis, short nFlag) {
    if (pThis != 0) {
        if (pThis->m_unk0 != 0) {
            delete[] pThis->m_unk0;
            pThis->m_unk0 = 0;
        }
        if (nFlag > 0) {
            delete pThis;
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

// FUNCTION: 0x00133F20 RenderWarning__11FontManagerFi
void FontManager::RenderWarning(int arg0) {
    if (arg0 != m_unk122) {
        ResetWarning();
        m_unk122 = arg0;
        DisplayString(arg0, 0, 0, true);
    }
    float fFade = m_unk121 ? WARNING_FADE : -WARNING_FADE;
    float fNew = m_unk124 + fFade;
    m_unk124 = fNew;
    if (fNew >= 1.0f) {
        m_unk121 = 0;
    } else {
        if (fNew <= 0.0f) {
            m_unk121 = 1;
        }
    }
    InitRender__9InterfaceFv(gInterface);
    BeginFxRender__10PGfxEngineFv(gGfxEng);
    SetScreenMatrix__10PGfxEngineFP5PMat4(gGfxEng, gInterface);
    SetViewMatrix__10PGfxEngineFP5PMat4(gGfxEng, gInterface + 0x40);
    SetClipMatrix__10PGfxEngineFP5PMat4(gGfxEng, gEng + 0x50);
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, gUnitMatrix);
    BeginSprites__10PGfxEngineFv(gGfxEng);
    m_unk114 = 0;
    int nRet = -1;
    FontNode *pNode = (m_unk110 != 0) ? m_unk118[0] : 0;
    while (pNode != 0) {
        pNode->m_unk8 = m_unk124;
        nRet = pNode->Render(nRet, (FontTable *)&m_unk104, false);
        int nNext = m_unk114 + 1;
        m_unk114 = nNext;
        pNode = ((unsigned int)nNext < (unsigned int)m_unk110) ? m_unk118[m_unk114] : 0;
    }
    EndFxRender__10PGfxEngineFv(gGfxEng);
}

// FUNCTION: 0x1340E0 AdvanceText__8FontNodeFv
int FontNode::AdvanceText() {
    unsigned short nVis = m_unkC;
    if (nVis < m_unk4) {
        m_unkC = nVis + 1;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x134110 RenderFMV__8FontNodeFiP9FontTableb
int FontNode::RenderFMV(int nId, FontTable *pTable, bool bUnused) {
    float afColor[4];

    if (m_unkC >= 2) {
        if (m_unk8) {
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

// FUNCTION: 0x134200 Render__8FontNodeFiP9FontTableb
int FontNode::Render(int nId, FontTable *pTable, bool bUnused) {
    float afColor[4];

    if (bUnused && m_unk6 == 9) {
        float fNew = m_unk8 - 0.03f;
        m_unk8 = fNew;
        if (fNew <= 0.2f) {
            m_unk8 = 0.0f;
            mbFadeOut__8FontNode = 1;
        }
    }
    if (m_unkC >= 2 && m_unk8) {
        afColor[0] = m_unk8;
        afColor[1] = m_unk8;
        afColor[2] = m_unk8;
        afColor[3] = 1.0f;
        pTable = (FontTable *)((char *)pTable + m_unkE * 12);
        int nTex = *(int *)((char *)pTable + 8);
        if (nTex != nId) {
            nId = nTex;
            SetMaterial__10PGfxEngineFiPfbUlUl(gGfxEng, nTex, afColor, false, 0x44, 0x5048D);
        } else {
            SetMaterial__10PGfxEngineFPfbUlUl(gGfxEng, afColor, false, 0x44, 0x5048D);
        }
        DrawSprites__10PGfxEngineFP11tagVuSpriteib(gGfxEng, (tagVuSprite *)m_unk0, m_unkC, false);
    }
    return nId;
}

// DRAFT: 0x134350 Render__11FontManagerFbb
// note: 133 words differ: m_unk10 decrement keeps the sign-extended value without reload, pNext lives in s0 and is zeroed in the Find delay slot, m_unk8[idx+1] uses a +4 base. Tried: --m_unk10, pNext declared before Find.
void FontManager::Render(bool arg0, bool arg1) {
    FontNode *pNode;
    int nId;
    m_unk4 = 0;
    pNode = (m_unk0 != 0) ? m_unk8[0] : 0;
    if (pNode == 0) {
        return;
    }
    if (arg1) {
        int nId = -1;
        if (pNode != 0) {
            do {
                nId = pNode->RenderFMV(nId, (FontTable *)&m_unk104, m_unk12);
                pNode = ((unsigned int)++m_unk4 < (unsigned int)m_unk0) ? m_unk8[m_unk4] : 0;
            } while (pNode != 0);
        }
        return;
    }
    if (m_unk18 != 0) {
        m_unk10--;
        if (m_unk10 <= 0) {
            m_unk10 = m_unk11;
            if (m_unk18->AdvanceText() == 0) {
                int idx = Find__6PArrayFPv(this, m_unk18);
                FontNode *pNext = 0;
                if (idx >= 0 && (unsigned int)(idx + 1) < (unsigned int)m_unk0) {
                    pNext = m_unk8[idx + 1];
                }
                if (pNext != 0 && pNext->m_unkC != 0) {
                    pNext = 0;
                }
                m_unk18 = pNext;
            }
        }
    } else if (m_unk14 != 0) {
        m_unk14--;
        if (m_unk14 <= 0) {
            m_unk12 = 1;
            mbFadeOut__8FontNode = 0;
        }
    }
    if (arg0) {
        InitRender__9InterfaceFv(gInterface);
    }
    BeginFxRender__10PGfxEngineFv(gGfxEng);
    SetScreenMatrix__10PGfxEngineFP5PMat4(gGfxEng, gInterface);
    SetViewMatrix__10PGfxEngineFP5PMat4(gGfxEng, gInterface + 0x40);
    SetClipMatrix__10PGfxEngineFP5PMat4(gGfxEng, gEng + 0x50);
    SetWorldMatrix__10PGfxEngineFP5PMat4(gGfxEng, gUnitMatrix);
    BeginSprites__10PGfxEngineFv(gGfxEng);
    if (pNode != 0) {
        do {
            if (m_unk128 == 0.0f) {
                nId = pNode->Render(nId, (FontTable *)&m_unk104, m_unk12);
            } else if (pNode->Scroll(m_unk128) != 0) {
                nId = pNode->Render(nId, (FontTable *)&m_unk104, m_unk12);
            } else {
                ((PArray *)this)->RemoveCurrent();
                ((PArray *)((char *)this + 0x1C))->Add(pNode);
            }
            pNode = ((unsigned int)++m_unk4 < (unsigned int)m_unk0) ? m_unk8[m_unk4] : 0;
        } while (pNode != 0);
    }
    EndFxRender__10PGfxEngineFv(gGfxEng);
    if (mbFadeOut__8FontNode != 0) {
        mbFadeOut__8FontNode = 0;
        RemoveText((unsigned short)9);
    }
    m_unk12 = 0;
    m_unk120 = 0;
    if (mbEnableBox__8FontNode != 0 && mpTextBox__8FontNode != 0) {
        ((TextBoxVtbl *)mpTextBox__8FontNode)->Draw(0, 0x80, 0);
    }
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
    gInterface[0x427] = 1;
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
            delete pThis;
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
