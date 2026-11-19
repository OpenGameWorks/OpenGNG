// FLAGS: -str readonly
#include "MaximoMain.h"

// TODO(header): foreign declarations
class FontNode;
class FontManager {
public:
    void RemoveText(FontNode *pNode);
    void *DisplayString(int nText, int x, int y, bool bFlag);
};
extern unsigned char gInterface[2656];
extern unsigned char gMC[16320];
extern unsigned char LevelTable[2688];
extern unsigned char gSound[98496];
extern "C" void FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(void *, float, float, bool, int);
extern "C" void FadeOutAllMusic__6PSoundFUi(void *, unsigned int);
extern "C" int PlaySoundUbiquitous__6PSoundFUi(void *, unsigned int);
extern "C" void UpdateStatus__9InterfaceFUib(void *, unsigned int, bool);
extern "C" void SetState__15EntityBaseClassFi(void *, int);
extern "C" void __dl__FPv(void *);
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
class PMNode {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Slot4(int, float, float, int, int);
    PMNode *Find(unsigned int id);
    char _pad000[0x10];
    struct {
        unsigned int count;     // child count
        unsigned int m_unk4;
        PMNode **children;      // child array
    } m_unk14;
    char _pad020[0x3E - 0x20];
    unsigned char m_unk3E;  // flags
};

// FUNCTION: 0x00134AE0 InitGameTimes__10MaximoMainFv
void MaximoMain::InitGameTimes() {
    m_unk19B6C = 0;
    m_unk19B70 = 0;
    m_unk19B74 = 0;
    m_unk19B78 = 0;
    m_unk19B7C = 0;
    m_unk19B80 = 0;
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

// DRAFT: 0x0013DC30 FindFirstDialog__10MaximoMainFPC10LevelFilesb
// note: 22 lines differ; saved regs and loop match, but the original duplicates the early-return v0 tail (b past the shared daddu v0) and sets jal a0 before the a1 delay slot. Tried: do-while (29), base var, for-loop with pre-test (28), counter first (22), unsigned 0 return (22)
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
