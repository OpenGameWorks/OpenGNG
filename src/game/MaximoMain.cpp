// FLAGS: -str readonly
#include "MaximoMain.h"

// TODO(header): foreign declarations
class FontNode;
class FontManager {
public:
    void RemoveText(FontNode *pNode);
    void RemoveText(unsigned short nId);
    void *DisplayString(int nText, int x, int y, bool bFlag);
};
extern unsigned char gInterface[2656];
extern unsigned char gMC[16320];
extern unsigned char LevelTable[2688];
extern unsigned char gSound[98496];
extern "C" void FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(void *, float, float, bool, int);
extern "C" void AddMeshLayer__9InterfaceFP6PMNode(void *, PMNode *);
extern "C" void DeleteMeshLayer__9InterfaceFP6PMNode(void *, PMNode *);
extern "C" PMNode *GetResource__16PResourceManagerFUib(void *, unsigned int, bool);
extern "C" void FadeOutAllMusic__6PSoundFUi(void *, unsigned int);
extern "C" int PlaySoundUbiquitous__6PSoundFUi(void *, unsigned int);
extern "C" void UpdateStatus__9InterfaceFUib(void *, unsigned int, bool);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void __dl__FPv(void *);
extern "C" int Find__6PArrayFPv(void *, void *);
extern "C" void *DisplayString__11FontManagerFPcffi9FontColor9FontAlign(void *, char *, float, float, int, int, int);
extern unsigned char __vt__9PResource[12];
extern "C" int GetDialogStreamReadiness__6PSoundFUi(void *, unsigned int);
extern "C" void PrepDialog__6PSoundFUi(void *, unsigned int);
struct LevelFiles {
    char _pad00[0x10];
    int m_unk10;            // 0x10, zero when the level lists no dialog files
};
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void *__dt__6CameraFv(void *, short);
extern "C" void *__dt__13EntityManagerFv(void *, short);
extern "C" void *__dt__9MaxEngineFv(void *, short);
extern "C" void ResetGameData__10MemoryCardFv(void *);
extern "C" void InitLoadGame__10MemoryCardFv(void *);
extern "C" void InitRenderFrame__9MaxEngineFbUi(void *, bool, unsigned int);
extern "C" int LoadGame__10MemoryCardFv(void *);
extern "C" void Render__9InterfaceFi(void *, int);
extern "C" void SetInputMode__3PadFQ23Pad10eInputModePQ23Pad9InputDatai(void *, int, void *, int);
extern int miAbilityCount__15EntityBaseClass;
extern int miRandom__7MathAPI;
extern unsigned char MODE_PAL;
extern unsigned char DemoTable[24];
extern unsigned char DemoTableP[24];
extern unsigned char gPad[448];
extern unsigned char gEng[0x1A000];
extern "C" void DisplayLevelName__9InterfaceFii(void *, int, int);
extern "C" unsigned char PlayingCutCamera__6CameraFv(void *);
extern "C" void __ct__9MaxEngineFv(void *);
extern "C" void __ct__13EntityManagerFv(void *);
extern "C" void __ct__6CameraFv(void *);
extern int U_MILLISEC_PER_FRAME_HI;
extern int U_MILLISEC_PER_FRAME_LO;
extern "C" PMNode *Load__9InterfaceFPCc(void *, char const *);
extern "C" void *__nw__FUi(unsigned int);
extern unsigned char __vt__6PMNode[16];
extern unsigned char __vt__9PMeshNode[16];
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void InitMembers__6PMNodeFv(void *pThis);
extern "C" void InitMembers__9PMeshNodeFv(void *pThis);
extern "C" void CopyMNode__6PMNodeFR6PMNodeb(void *pThis, void *pSrc, bool bFlag);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" void Allocate__6PArrayFUi(void *pThis, unsigned int nCount);
extern "C" void ResetAnimations__15PCutScenePlayerFv(void *pThis);
extern "C" void SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf(void *pThis, void *pArray, float fOpacity);
extern "C" void CutSceneEnter__6PSoundFPUiUiUiUi(void *pThis, unsigned int *pOut, unsigned int nA, unsigned int nB, unsigned int nC);
extern char gGfxEng[1504384];
struct PMChildList {
    unsigned int count;     // child count
    unsigned int m_unk4;
    PMNode **children;      // child array
};
class PMNode {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4(int, float, float, int, int);
    PMNode *Find(unsigned int id);
    void SetAnimLoopCount(int arg0, bool arg1);
    void EnableAnim(bool arg0, bool arg1);
    char _pad000[0x10];
    PMChildList m_unk14;
    char _pad020[0x2C - 0x20];
    int m_unk2C;            // 0x2C, zeroed by LoadTitleMesh
    char _pad030[0x3E - 0x30];
    unsigned char m_unk3E;  // flags
};

// FUNCTION: 0x00134940 UpdateGameTimes__10MaximoMainFv
void MaximoMain::UpdateGameTimes() {
    unsigned int old;

    m_unk19B6C += U_MILLISEC_PER_FRAME_HI;
    old = m_unk19B70;
    m_unk19B70 += U_MILLISEC_PER_FRAME_LO;
    if ((unsigned int)m_unk19B70 < old) {
        m_unk19B6C++;
    }
    if (!(m_unk19A7C & 4)) {
        m_unk19B74 += U_MILLISEC_PER_FRAME_HI;
        old = m_unk19B78;
        m_unk19B78 += U_MILLISEC_PER_FRAME_LO;
        if ((unsigned int)m_unk19B78 < old) {
            m_unk19B74++;
        }
    }
    if (!(m_unk19A7C & 8)) {
        m_unk19B7C += U_MILLISEC_PER_FRAME_HI;
        old = m_unk19B80;
        m_unk19B80 += U_MILLISEC_PER_FRAME_LO;
        if ((unsigned int)m_unk19B80 < old) {
            m_unk19B7C++;
        }
    }
}

// FUNCTION: 0x00134AE0 InitGameTimes__10MaximoMainFv
void MaximoMain::InitGameTimes() {
    m_unk19B6C = 0;
    m_unk19B70 = 0;
    m_unk19B74 = 0;
    m_unk19B78 = 0;
    m_unk19B7C = 0;
    m_unk19B80 = 0;
}

// DRAFT: 0x001357C0 Controls__10MaximoMainFv
// note: 4 words differ: case 3 FadeScreen(255.0f, 17.0f) loads 17.0f into f13 before 255.0f into f12 in the original; tried reordering nState++ (11 words), local float for 17.0f (4 words), literal form kept.
void MaximoMain::Controls() {
    int nState = 0;
    PMNode *pNode = GetResource__16PResourceManagerFUib((char *)this + 0x188A4, 0x8100003DU, false);
    if (pNode == 0) {
        CdsAssert__FPciPc("MaximoMain.cpp", 0x1734, "pMeshNode");
    }
    AddMeshLayer__9InterfaceFP6PMNode(gInterface, pNode);
    ((FontManager *)(gInterface + 0x80))->DisplayString(0x25C, 0, 0, false);
    for (;;) {
        int nPad = *(unsigned short *)(gPad + 0x110);
        InitRenderFrame__9MaxEngineFbUi(this, false, 0);
        switch (nState) {
        case 0:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface,0.0f, 17.0f, true, 0);
            nState++;
            break;
        case 1:
            if (gInterface[0x425] == 0) {
                nState++;
            }
            break;
        case 2:
            if (nPad & 0x1000) {
                PlaySoundUbiquitous__6PSoundFUi(gSound, 0x41);
                nState++;
            }
            break;
        case 3:
            FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface,255.0f, 17.0f, true, 0);
            nState++;
            break;
        case 4:
            if (gInterface[0x425] == 0) {
                ((FontManager *)(gInterface + 0x80))->RemoveText((unsigned short)6);
                DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pNode);
                return;
            }
            break;
        }
        pNode->Slot4(0, 0.0f, 1.0f, 0, 0);
        Render__9InterfaceFi(gInterface, 0);
    }
}

// DRAFT: 0x00137430 LoadGame__10MaximoMainFv
// note: 37 lines differ. Frame and saves match. 0x6C beq targets 0xE4 in original, 0xDC in ours (return-path block length). 0x78 is beq 0xB in original, bne in ours. Tried: nested if/return, inverted 0xB test (worse, spreads to 0xA0), do/while, flat if/break.
int MaximoMain::LoadGame() {
    ResetGameData__10MemoryCardFv(gMC);
    InitLoadGame__10MemoryCardFv(gMC);
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 8.5f, true, 0);
    miAbilityCount__15EntityBaseClass = 0;
    for (;;) {
        InitRenderFrame__9MaxEngineFbUi(this, 0, 0);
        int result = LoadGame__10MemoryCardFv(gMC);
        if (result != -1) {
            if (result == 0xB) {
                m_unk19A78 = gMC[0x22C];
                if (m_unk19A78 >= 0x14) {
                    m_unk19A78 = 0x13;
                }
                return 1;
            }
            m_unk19A78 = 0;
            return 0;
        }
        Render__9InterfaceFi(gInterface, 0);
    }
}

// FUNCTION: 0x00137560 LoadTitleMesh__10MaximoMainFv
void MaximoMain::LoadTitleMesh() {
    static char TITLE[] = "PSXDATA\\GAME\\TITLE.PAK";
    static unsigned int Copyrights[2] = {0x6214ECB4, 0xCC8B1693};
    PMNode *node;
    int i;
    int off;

    m_unk19AC8 = Load__9InterfaceFPCc(gInterface, TITLE);
    m_unk19AC8->SetAnimLoopCount(0, true);
    m_unk19ACC = m_unk19AC8->Find(0xC72EE251);
    if (m_unk19ACC != 0) {
        m_unk19ACC->SetAnimLoopCount(1, true);
    }
    i = 0;
    off = 0;
    do {
        node = m_unk19AC8->Find(*(unsigned int *)((char *)Copyrights + off));
        if (node != 0) {
            node->m_unk2C = 0;
            if (i == 1) {
                m_unk19AD0 = node;
            }
        }
        i++;
        off += 4;
    } while (i < 2);
    m_unk19AC8->EnableAnim(true, true);
}

// FUNCTION: 0x00137540 InitStaticDemo__10MaximoMainFv
void MaximoMain::InitStaticDemo() {
    m_unk19784 = 0;
    m_unkD0 = 0;
    m_unkD4 = 0;
    m_unkD8 = 0x42180000;
}

// FUNCTION: 0x00137B00 InitPlayDemo__10MaximoMainFi
void MaximoMain::InitPlayDemo(int arg0) {
    int *entry;
    if (MODE_PAL != 0) {
        entry = (int *)(DemoTableP + m_unk19B54++ * 12);
    } else {
        entry = (int *)(DemoTable + m_unk19B54++ * 12);
    }
    m_unk19A78 = entry[0];
    int value;
    if (arg0 == 2) {
        value = 0x1C20;
    } else {
        value = entry[1];
    }
    m_unk19B5C = value;
    if ((unsigned int)m_unk19B54 >= 2) {
        m_unk19B54 = 0;
    }
    SetInputMode__3PadFQ23Pad10eInputModePQ23Pad9InputDatai(gPad, arg0, (void *)entry[2], 0);
    miRandom__7MathAPI = 0;
    miAbilityCount__15EntityBaseClass = 0;
    ResetGameData__10MemoryCardFv(gMC);
}

// FUNCTION: 0x00137EA0 DeletePressStart__10MaximoMainFv
void MaximoMain::DeletePressStart() {
    if (m_unk19AC4 != 0) {
        ((FontManager *)(gInterface + 0x80))->RemoveText((FontNode *)m_unk19AC4);
        m_unk19AC4 = 0;
    }
}

// DRAFT: 0x00137EF0 PressStart__10MaximoMainFi
// note: 58 words differ: state-machine register picks (at vs v1 for the nMode test, a0 vs a2 for the state load, f0/f1 order in the ramps), nested branch shape; kept pFont local, text load via pFont+0x100, nMode before nFlag (129 -> 101 -> 67 -> 58); ternary assert and state-first reorder (62) tried
void MaximoMain::PressStart(int arg0) {
    unsigned char *pFont = gInterface + 0x80;
    unsigned int nMode = *(unsigned int *)pFont;
    int nFlag = *(int *)(gInterface + 0x1B8);
    if (nMode >= 2 && nFlag == 0) return;
    if (m_unk19AC4 != 0) {
        if (Find__6PArrayFPv(pFont, m_unk19AC4) < 0) m_unk19AC4 = 0;
    }
    if (m_unk19AC4 == 0) {
        if (nMode != 0 && nFlag == 0) return;
        m_unk19AD4 = 0;
        char *pText = **(char ***)(pFont + 0x100);
        m_unk19AC4 = DisplayString__11FontManagerFPcffi9FontColor9FontAlign(pFont, pText, 0.0f, (float)arg0, 0, 4, 1);
        if (m_unk19AC4 == 0) CdsAssert__FPciPc("MaximoMain.cpp", 0x122E, "mpPress");
        *(int *)((char *)m_unk19AC4 + 8) = 0;
    }
    float fAlpha = *(float *)((char *)m_unk19AC4 + 8);
    int nState = m_unk19AD4;
    if (nState == 30) {
        fAlpha = fAlpha - 0.1f;
        if (fAlpha <= 0.0f) { fAlpha = 0.0f; m_unk19AD4 = 0; }
    } else if (nState == 0) {
        fAlpha = fAlpha + 0.1f;
        if (!(fAlpha < 1.0f)) { fAlpha = 1.0f; m_unk19AD4 = nState + 1; }
    } else {
        m_unk19AD4 = nState + 1;
    }
    *(float *)((char *)m_unk19AC4 + 8) = fAlpha;
}

// DRAFT: 0x00139AB0 SetMarker__10MaximoMainFP6PMNodeiP6PMNode
// note: vcall (Slot4) and prologue match; child select differs: original keeps count in v1 and loads children via addiu v0,s0,0x14 + lw 8(v0), then sll/addiu -4/addu; ours loads 0x1C directly. Tried: children[count], -4 cast, local count, &m_unk14+8 base, else-branch (all 33 lines)
PMNode *MaximoMain::SetMarker(PMNode *arg0, int arg1, PMNode *arg2) {
    PMNode *node = arg0->Find(*(unsigned int *)(LevelTable + (arg1 << 7)));

    if (node != 0) {
        PMNode *child;
        if (node->m_unk14.count != 0) {
            PMNode **children = (PMNode **)((char *)node->m_unk14.children - 4);
            child = children[node->m_unk14.count];
        } else {
            child = 0;
        }
        if (child != 0) {
            *(u_long128 *)((char *)arg2 + 0x80) = *(u_long128 *)((char *)child + 0x80);
            arg2->m_unk3E |= 8;
            arg2->Slot4(0, 0.0f, 0.0f, 0, 0);
        }
    }
    return node;
}

// DRAFT: 0x00138A40 QuitGame__10MaximoMainFv
// note: float args load in swapped order (original 4.25 into f13 first, ours 255 into f12 first); inline literals, locals in both orders, and locals before the state store all leave 4 words differing
void MaximoMain::QuitGame() {
    m_unk19A70 = 8;
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 255.0f, 4.25f, true, 0);
    FadeOutAllMusic__6PSoundFUi(gSound, 0x3E8);
}

// FUNCTION: 0x0013C720 MapscreenOpenBonusExists__10MaximoMainFv
int MaximoMain::MapscreenOpenBonusExists() {
    int i = 0;

    do {
        if (gMC[i + 0x6B5] == 1) {
            return 1;
        }
        i++;
    } while (i < 0x20);
    return 0;
}

// DRAFT: 0x0013C9F0 SetMarkerAsMastered__10MaximoMainFP6PMNodeP6PMNode
// note: 79 words differ; original inlines the PMeshNode ctor chain with this spilled to 0x5C(sp) and frame 0x60, ours uses manual __ct calls and frame 0x50 (stand-in PMNode has no embedded PArray member).
void MaximoMain::SetMarkerAsMastered(PMNode *arg0, PMNode *arg1) {
    if (arg1 != 0) {
        PMNode *found = arg0->Find(0xA5D4D353U);
        if (found == 0) {
            CdsAssert__FPciPc((char *)"MaximoMain.cpp", 0x7F1, (char *)"aMastery");
        }
        PMNode *node = (PMNode *)__nw__FUi(0x140);
        if (node != 0) {
            *(void **)node = __vt__9PResource;
            *(int *)((char *)node + 4) = 0;
            *(void **)node = __vt__6PMNode;
            __ct__6PArrayFv((char *)node + 0x14);
            sceVu0UnitMatrix((char *)node + 0x40);
            __ct__6PArrayFv((char *)node + 0xD8);
            InitMembers__6PMNodeFv(node);
            *(void **)node = __vt__9PMeshNode;
            __ct__6PArrayFv((char *)node + 0x130);
            InitMembers__9PMeshNodeFv(node);
        }
        CopyMNode__6PMNodeFR6PMNodeb(node, found, true);
        *(u_long128 *)((char *)node + 0x80) = *(u_long128 *)((char *)arg1 + 0x80);
        *((unsigned char *)node + 0x3E) |= 8;
        node->Slot4(0, 0.0f, 0.0f, 0, 0);
        Add__6PArrayFPv((char *)arg0 + 0x14, node);
        arg0->Slot4(0, 0.0f, 0.0f, 0, 0);
    }
}

// FUNCTION: 0x0013CB80 __dt__9PResourceFv
extern "C" void *__dt__9PResourceFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__9PResource;
        ((int *)pThis)[1] = 0;
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x0013CBD0 GetMapScreenPath__10MaximoMainFP6PMNodeiR6PArrayb
// note: 16 words differ, all the s1/s2 swap (original PArray in s2, bool in s1); a bool local copy, reordered locals, and a PArray pointer local all leave 16.
void MaximoMain::GetMapScreenPath(PMNode *arg0, int arg1, PArray &arg2, bool arg3) {
    unsigned int i;
    int idx;
    PMNode *node;
    PMChildList *list;
    PMNode *child;

    node = arg0->Find(*(unsigned int *)(LevelTable + (arg1 << 7)));
    if (node != 0) {
        list = &node->m_unk14;
        Allocate__6PArrayFUi(&arg2, list->count);
        if (!arg3) {
            for (i = 0; i < list->count; i++) {
                child = (i < list->count) ? list->children[i] : 0;
                if (child != 0) {
                    Add__6PArrayFPv(&arg2, child);
                }
            }
        } else {
            for (idx = (int)list->count - 2; idx >= 0; idx--) {
                child = ((unsigned int)idx < list->count) ? list->children[idx] : 0;
                if (child != 0) {
                    Add__6PArrayFPv(&arg2, child);
                }
            }
        }
    }
}

// FUNCTION: 0x0013CCF0 PlayMarkerSound__10MaximoMainFi
int MaximoMain::PlayMarkerSound(int arg0) {
    int sound = 0;

    switch (arg0) {
    case 0:
        sound = 0x28D;
        break;
    case 1:
    case 2:
        sound = 0x264;
        break;
    case 4:
    case 5:
    case 6:
        sound = 0x323;
        break;
    case 9:
    case 10:
    case 11:
        sound = 0x325;
        break;
    case 12:
    case 13:
        sound = 0x326;
        break;
    case 14:
        sound = 0x327;
        break;
    }
    if (sound != 0) {
        return PlaySoundUbiquitous__6PSoundFUi(gSound, sound);
    }
    return 0;
}

// FUNCTION: 0x0013CD70 PlayBGSound__10MaximoMainFi
int MaximoMain::PlayBGSound(int arg0) {
    int sound = 0;

    switch (arg0) {
    case 0:
        break;
    case 1:
        sound = 0x322;
        break;
    case 2:
        sound = 0x324;
        break;
    case 3:
        sound = 0x288;
        break;
    case 4:
        sound = 0x328;
        break;
    case 5:
        sound = 0x285;
        break;
    }
    if (sound != 0) {
        return PlaySoundUbiquitous__6PSoundFUi(gSound, sound);
    }
    return 0;
}

// FUNCTION: 0x0013CDF0 RestartGame__10MaximoMainFb
void MaximoMain::RestartGame(bool arg0) {
    if (arg0) {
        m_unk19A70 = 0xA;
        UpdateStatus__9InterfaceFUib(gInterface, 9, false);
        return;
    }
    m_unk19A70 = 9;
}

// FUNCTION: 0x0013D850 SetLevelClear__10MaximoMainFv
void MaximoMain::SetLevelClear() {
    if (m_unk19A70 != 6) {
        m_unk19A70 = 6;
        m_unk19AAC = 0;
        SetState__15EntityBaseClassFi(m_unk1883C, 2);
    }
}

// FUNCTION: 0x0013D8B0 GetLevelFile__10MaximoMainFi
void *MaximoMain::GetLevelFile(int arg0) {
    int idx = arg0;

    if (idx < 0) {
        idx = m_unk19A78;
    }
    if (idx < 0x15) {
        return LevelTable + (idx << 7);
    }
    return 0;
}

// FUNCTION: 0x0013D8F0 InitCutSceneIfDialogReady__10MaximoMainFv
int MaximoMain::InitCutSceneIfDialogReady() {
    int stream = m_unk19AA4;
    bool start = true;

    if (stream != 0) {
        int readiness = GetDialogStreamReadiness__6PSoundFUi(gSound, stream);
        if (readiness != 0) {
            start = false;
            if (readiness < 0) {
                CdsAssert__FPciPc((char *)"MaximoMain.cpp", 0x65C, (char *)"0");
                start = true;
                m_unk19AA4 = 0;
            }
        }
    }
    if (start) {
        InitCutScene();
        return 0;
    }
    return 1;
}

// DRAFT: 0x0013D990 InitCutScene__10MaximoMainFv
// note: 100 words differ; the original reads m_unk8724 through (char *)this+0x8724 into v1 and reloads it for the index test, and its clamp branches differ.
void MaximoMain::InitCutScene() {
    char *pLevel = (char *)LevelTable + (m_unk19A78 << 7);
    int nIndex;
    char *pEntry;
    char *pSlot;
    int nW;
    int nH;

    m_unk19A70 = 5;
    nIndex = m_unk8724;
    pEntry = pLevel + nIndex * 16 + 0x14;
    if (nIndex < 4) {
        m_unk8724 = nIndex;
        pSlot = (char *)this + nIndex * 0x2140 + 0x220;
        ResetAnimations__15PCutScenePlayerFv(pSlot);
        m_unk8720 = 1;
        SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf(pSlot, pSlot + 0x60, 0.0f);
        SetBgNodesOpacity__15PCutScenePlayerFP6PArrayf(pSlot, pSlot + 0x90, 1.0f);
    }
    *(short *)(gInterface + 0x414) = 30;
    *(int *)(gInterface + 0x1C0) &= ~0xE;
    CutSceneEnter__6PSoundFPUiUiUiUi(gSound, (unsigned int *)((char *)this + 0x19B50), m_unk19AA4,
                                     *(unsigned int *)(pEntry + 8), (unsigned int)(int)(signed char)pEntry[0xD]);
    nW = *(short *)(pLevel + 0x6A);
    if (nW < 0x97) {
        nW = 0x96;
    }
    nH = *(short *)(pLevel + 0x6C);
    if (nH < 0x8D) {
        nH = 0x8C;
    }
    *(float *)(gGfxEng + 0x6A0) = (float)nW * (float)nW;
    *(float *)(gGfxEng + 0x6A4) = (float)nH * (float)nH;
}

// DRAFT: 0x0013DB50 StartCutScene__10MaximoMainFi
// note: index math matches (addiu base, scaled adds); still differs in camera arg (gEng+0x19760 folded into one lui/addiu), so v0/a0 register order and the 0x30 branch shift; 6 variants tried (base ptr, slot array, member array, int addr, split base, operand order); 24 differing lines.
int MaximoMain::StartCutScene(int arg0) {
    int ok;
    DisplayLevelName__9InterfaceFii(gInterface, -1, 0xF0);
    ok = 0;
    if (arg0 < 4) {
        unsigned int base = (unsigned int)this + 0x260;
        unsigned int addr = base + arg0 * 0x2140;
        ok = *(int *)addr != 0;
    }
    if (ok) {
        if (!(*(int *)((char *)m_unk1883C + 0x264) & 8)) {
            m_unk19A70 = 3;
            *(int *)((char *)this + 0x8724) = arg0;
            if (PlayingCutCamera__6CameraFv(gEng + 0x19760) != 0) {
                gEng[0x19A18] = 0;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}

// FUNCTION: 0x0013DC30 FindFirstDialog__10MaximoMainFPC10LevelFilesb
unsigned int MaximoMain::FindFirstDialog(LevelFiles const *arg0, bool arg1) {
    int s1;
    unsigned int temp_s2;
    int idx;
    int a0;

    m_unk19AA4 = 0;
    if (arg0->m_unk10 == 0) {
        m_unk19AA8 = -1;
        return 0;
    }
    for (s1 = 0, idx = 0, a0 = 0; s1 < 4; s1++, idx += 0x2140, a0 += 0x10) {
        if (*(int *)((char *)this + idx + 0x260) != 0) {
            temp_s2 = *(unsigned int *)((char *)arg0 + a0 + 0x18);
            if (temp_s2 != 0 && (!arg1 || m_unk19AA8 < s1)) {
                PrepDialog__6PSoundFUi(gSound, temp_s2);
                m_unk19AA4 = temp_s2;
                m_unk19AA8 = s1;
                return temp_s2;
            }
        }
    }
    return 0;
}

// FUNCTION: 0x0013ED80 PauseDisplay__10MaximoMainFi
void MaximoMain::PauseDisplay(int arg0) {
    FontManager *fm = (FontManager *)(gInterface + 0x1790);
    int i = 0;
    int off = 0;

    do {
        void *text = fm->DisplayString(i + 1, 0, 0, false);
        *(void **)((char *)this + off + 0x19A88) = text;
        float alpha;
        if (i != arg0) {
            alpha = 0.5f;
        } else {
            alpha = 1.0f;
        }
        i++;
        off += 4;
        *(float *)((char *)text + 8) = alpha;
    } while (i < 3);
}

// FUNCTION: 0x0013F6B0 __dt__10MaximoMainFv
extern "C" void *__dt__10MaximoMainFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        __dt__6CameraFv((char *)pThis + 0x19760, -1);
        __dt__13EntityManagerFv((char *)pThis + 0x137E0, -1);
        __dt__9MaxEngineFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// DRAFT: 0x0013F730 __ct__10MaximoMainFv
// note: 47 lines; ours spills this to 0x1C(sp) and never saves s0 (original sq s0 / daddu s0,a0). Tried member, extern "C" with return this, local self before/after first call, register hint; all 47. Size 0xA8 vs 0xCC.
MaximoMain::MaximoMain() {
    __ct__9MaxEngineFv(this);
    MaximoMain *self = this;
    __ct__13EntityManagerFv((char *)self + 0x137E0);
    __ct__6CameraFv((char *)self + 0x19760);
    self->m_unk19AC4 = 0;
    self->m_unk19A7C = 0;
    self->m_unk19B54 = 0;
    self->m_unk19B58 = 0;
    self->m_unk19B44 = 0;
    self->m_unk19B48 = 0;
    self->m_unk19B4C = 0;
    self->m_unk19AA0 = 0;
}
