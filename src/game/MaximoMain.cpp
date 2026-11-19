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
extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern "C" void *__dt__6CameraFv(void *, short);
extern "C" void *__dt__13EntityManagerFv(void *, short);
extern "C" void *__dt__9MaxEngineFv(void *, short);
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

// FUNCTION: 0x00137540 InitStaticDemo__10MaximoMainFv
void MaximoMain::InitStaticDemo() {
    m_unk19784 = 0;
    m_unkD0 = 0;
    m_unkD4 = 0;
    m_unkD8 = 0x42180000;
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
