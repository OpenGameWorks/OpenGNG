// FLAGS: -str readonly
#include "types.h"
#include "Interface.h"
#include "PTextureManager.h"
#include "PArray.h"
#include "PGrimBarAura.h"

// TODO(header): foreign declarations
extern "C" void *__nw__FUi(unsigned int nSize);
extern unsigned char __vt__9PResource[];
extern unsigned char __vt__6PMNode[];
extern "C" void InitMembers__6PMNodeFv(PMNode *pThis);
extern "C" void CopyMNode__6PMNodeFR6PMNodeb(PMNode *pThis, PMNode *src, bool flag);
class Player {
public:
    void SwapAbility(int arg0);
};
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    void StopStreamsAndRequestEEControl();
    int GetEEControlStatus();
    void SetAllowCallOneFrameHasElapsed(bool flag);
    void AbilityScreenEnter();
    void AbilityScreenLeave();
    void PlaySoundUbiquitous(unsigned int id);
    char _pad000[0x10];
};
extern PSound gSound;

class FileUtils {
public:
    void LoadingHangCheckInit();
};

class PParticleManager {
public:
    void Remove(PParticleSystem *pSystem);
};
extern char gGfxEng[1504384];

// PDisplayList is declared in PDisplayList.h without ClearFrameBuffer; only the two members used here are listed.
class PDisplayList {
public:
    void SetGsRegisters(u_long128 *pRegData, int nNumRegs);
    void ClearFrameBuffer(short x0, short x1, short x2, short x3, char r, char g, char b, char a, unsigned int z);
};

extern unsigned char fst_bUseOldLoadingDisplay;
// TODO(header): LoadingDisplayNew frame statistics and the VBlank counter (all gp-relative).
extern unsigned int fst_VBlankCount;
extern unsigned int gCDSVBlankCount;
extern unsigned int fst_callsThisFrame;
extern unsigned int fst_maxCallsPerFrameAllowed;
extern unsigned int fst_maxCallsPerFrameDone;
extern unsigned int fst_nCallsTotal;
extern unsigned int fst_nFramesTotal;
extern float fst_fAvgCallsPerFrame;

// Pad is reached via lui/addiu; the placeholder keeps gPad above the 8-byte small-data threshold.
class Pad {
public:
    void PauseVibrate(bool flag);

    char _pad000[0x110];
    unsigned short m_unk110;    // 0x110 button state
};
extern Pad gPad;

// Polymorphic embedded object; Slot04 is the vtable word at offset 0x18
// (the compiler places the first virtual slot at offset 0x8).
class PVirtObj {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03(int flag);
    virtual void Slot04();
    virtual void Slot05(int flag);
};

// Same vtable layout as PVirtObj; Slot05 takes the bool argument unconverted.
class PVirtObjBool {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03(int flag);
    virtual void Slot04();
    virtual void Slot05(bool flag);
};

// Object at PMNode+0x24; virtual slots 10, 12, 13 and 15 are called by GameHud::UpdateStatus.
class PVirtSlots {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(int flag);
    virtual void Slot11();
    virtual void Slot12(int flag);
    virtual void Slot13(short flag);
    virtual void Slot14();
    virtual void Slot15(float flag);
};

// Only the mangled name (13eBoxIntersect) matters here; the enumerator names are placeholders.
enum eBoxIntersect { eBoxIntersect_Value0 = 0, eBoxIntersect_Value1 = 1 };

class PMat4;

class PMNode {
public:
    virtual void Slot00(int flag);
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual int Slot04(float fA, float fB, PMat4 *pMat, int arg3, bool bFlag);
    void ProcessFxTriggers(float arg0, PMat4 *arg1, bool arg2, bool arg3);
    PMNode *Find(unsigned int id);
    void RecurseSetSTAnimOptions(bool flag);
    void SetAllFrustrumTest(eBoxIntersect arg0);
    void RecurseSetLoopRateByID(unsigned int id, int arg1, float arg2);
    void ScaleSet(float arg0, float arg1, float arg2, float arg3);
    void EnableAnim(bool arg0, bool arg1);
    void SetAnimLoopCount(int arg0, bool arg1);

    char _pad004[0x8];
    int m_unkC;                 // 0x00C
    char _pad010[0x4];
    int m_unk14;                // 0x014 element count of the walk list
    int m_unk18;                // 0x018 walk index
    PMNode **m_unk1C;           // 0x01C element pointer array
    char _pad020[0x60];
    float m_unk80;              // 0x080
};

// Same vtable as PMNode; the slot at 0x18 takes four arguments at this call site.
class PMNodeView {
public:
    virtual void Slot00(int flag);
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03(int flag);
    virtual int Slot04(float fA, float fB, PMat4 *pMat, int arg3);
};

// Placeholder size; the original object is larger than the 8-byte small-data threshold.
extern char CoinAnim[0x10];
extern char DefaultLoopAnim[0x10];

// Placeholder size; gDebug is reached via lui/addiu, so its type must exceed the 8-byte small-data threshold.
extern char gDebug[0x10];
extern "C" void DebugClear__5DebugFv(void *pThis);
extern "C" void DebugDispPos__5DebugFPcUiUii(void *pThis, char *text, unsigned int x, unsigned int y, int color);
extern "C" void RefreshDisplay__10PGfxEngineFv(void *pThis);
extern "C" void SoundOneFrameHasElapsed_R__9MaxEngineFRiRi(void *pThis, int *pA, int *pB);
extern "C" void IncrementSecondarySyncCounts__9MaxEngineFv(void *pThis);
extern "C" void SetFrameRate__6PMNodeFfb(PMNode *pThis, float rate, bool flag);
extern "C" PMNode *Find__6PMNodeFUi(PMNode *pThis, unsigned int uID);
extern unsigned char MODE_PAL;
extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;
// PMat4 member; the call passes the matrix object as pThis. PMat4.h has no declaration for it.
extern "C" void MakeParallelProjectionMatrix__5PMat4Fffffffffffff(void *pThis, float, float, float, float, float, float, float, float, float, float, float, float);
extern "C" void EnableAllText__11FontManagerFb(void *pThis, bool bFlag);
extern "C" void *DisplayString__11FontManagerFPcffi9FontColor9FontAlign(void *pThis, char *pStr, float fX, float fY, int nZ, int nColor, int nAlign);
extern "C" void JapanAddNumber__11FontManagerFPUsPUsi(unsigned short *pDst, unsigned short *pSrc, int nVal);
extern "C" int printf(const char *fmt, ...);
extern "C" int strcasecmp(const char *pA, const char *pB);
extern "C" unsigned int strlen(const char *pStr);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" void scePcStart(int nMode, int nA, int nB);
extern "C" void scePcStop(void);
extern "C" PMNode *Load__6PWorldFPCcb13eTextureGroup(void *pThis, const char *pName, bool bFlag, eTextureGroup eGroup);
extern "C" void RemoveNullAnimation__6PMNodeFv(PMNode *pThis);
// Owns a virtual destructor as its first slot (slot 8); delete through it reaches the deleting destructor.
class PDeletable {
public:
    virtual ~PDeletable();
};

// Vtable whose slot 0x18 (index 4) returns int; slots 0..3 are placeholders.
class PVirtIntSlot4 {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual int Slot04();
};

class HudData {
public:
    unsigned int m_unk0;
    signed char m_unk4;
    unsigned char m_unk5;
};

class HudInventory {
public:
    HudInventory();
    void AddIcon(int id);
    void Reset();
    void UpdateGroup(int arg0);
    void UpdateStatus(bool flag);
    void Delete();
    int SwapCheck(unsigned int arg0);
    void UpdateShieldIcon();
    void Init(PMeshNode *arg0, HudData *arg1);
    void Update(int arg0);
    void InfoScreen();

    char _pad000[0x4];
    void *m_unk4;               // 0x004
    char _pad008[0x6];
    signed char m_unkE;         // 0x00E
    signed char m_unkF;         // 0x00F
    unsigned char m_unk10;      // 0x010
    char _pad011[0x3];
    PMNode *m_unk14;            // 0x014 first group node, PArray at +0x14
    PMNode *m_unk18;            // 0x018 second group node
    void *m_unk1C;              // 0x01C element with a PArray at 0x14 (index 0x18, storage 0x1C)
    char _pad020[0x14];
    PMNode *m_unk34;            // 0x034
    PMNode *m_unk38;            // 0x038 mpCursor node
    int m_unk3C;                // 0x03C
    int m_unk40;                // 0x040 icon index, used by SwapCheck
};

extern unsigned char __vt__7GameHud[];
extern unsigned char __vt__12HudInventory[];
extern unsigned char __vt__7HudGrim[];
extern unsigned char __vt__8HudCombo[];
extern unsigned char __vt__12HudBossMeter[];
extern unsigned char __vt__8HudSuper[];
extern unsigned char __vt__9HudHealth[];
class HudHealth;
extern "C" void __dl__FPv(void *pMem);

class FontNode;

class FontManager {
public:
    void Init();
    void RemoveText(FontNode *pNode);
    void RemoveText(unsigned short arg0);
    int DisplayString(int arg0, int arg1, int arg2, bool arg3);
    void RemoveAll(bool flag);
    void RenderWarning(int arg0);
};

// MemMgr is 908 bytes; the field at offset 0x18 is saved and cleared around AddIcon.
extern char MemMgr[908];

extern "C" void CdsAssert__FPciPc(char *, int, char *);
extern Interface gInterface;
// HintTable is 120 bytes (symbols.tsv); element size taken from the lw/sll 2 indexing.
extern int HintTable[30];
// BoxSize is a table of 12-byte entries; the float fields at offsets 4 and 8 are read by InitNode.
extern char BoxSize[0x100];
// gEng is 105360 bytes; the array size keeps it out of small data. InitRender reads gEng + 0x50.
extern char gEng[105360];
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0ScaleVectorXYZ(float *dst, float *src, float scale);
extern "C" void RenderBlendedFragments__10PGfxEngineFPf(void *pThis, float *pBuf);
extern "C" void vu1ZBufferUpdate__Fb(bool bEnable);
extern "C" void vu1ClearZBuffer__Fv(void);
extern "C" void vu1SetScreenMatrix__FP5PMat4(void *pMat);
extern "C" void vu1SetViewMatrix__FP5PMat4(void *pMat);
extern "C" void vu1SetClipMatrix__FP5PMat4(void *pMat);
extern "C" void sceVu0UnitMatrix(void *pMat);
extern "C" void __ct__11FontManagerFv(void *pThis);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void __ct__12HudInventoryFv(void *pThis);

// FUNCTION: 0x13F800 __dt__7HudGrimFv
extern "C" HudGrim *__dt__7HudGrimFv(HudGrim *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__7HudGrim;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x13F880 SoundGainEEControl__9InterfaceFv
void Interface::SoundGainEEControl() {
    gSound.StopStreamsAndRequestEEControl();
    WaitForEEControl();
}

// FUNCTION: 0x13F8C0 WaitForEEControl__9InterfaceFv
void Interface::WaitForEEControl() {
    ((FileUtils *)this)->LoadingHangCheckInit();
    for (unsigned int i = 0;; i++) {
        if (gSound.GetEEControlStatus() == 3) {
            gSound.SetAllowCallOneFrameHasElapsed(false);
            break;
        }
        LoadingDisplay(i, 6);
    }
}

// FUNCTION: 0x13F940 SetPause__9InterfaceFv
void Interface::SetPause() {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    ((PVirtObj *)((char *)this + 0x1FC))->Slot05(1);
    ((PVirtObj *)((char *)this + 0x1EC))->Slot05(1);
    ((PVirtObj *)((char *)this + 0x21C))->Slot05(1);
    ((PVirtObj *)((char *)this + 0x20C))->Slot05(1);
    *(int *)(MemMgr + 0x18) = saved;
}

// FUNCTION: 0x13F9D0 LevelClear__9InterfaceFv
void Interface::LevelClear() {
    ((PVirtObj *)((char *)this + 0x290))->Slot04();
    ((PVirtObj *)((char *)this + 0x250))->Slot04();
    m_unk1C0 &= ~8;
}

// FUNCTION: 0x13FA20 UpdateStatus__9InterfaceFUib
void Interface::UpdateStatus(unsigned int arg0, bool arg1) {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    switch (arg0) {
    case 3:
        ((PVirtObjBool *)((char *)this + 0x1FC))->Slot05(arg1);
        break;
    case 4:
        ((PVirtObjBool *)((char *)this + 0x1EC))->Slot05(arg1);
        break;
    case 9:
        ((PVirtObjBool *)((char *)this + 0x20C))->Slot05(arg1);
        break;
    case 7:
        ((PVirtObjBool *)((char *)this + 0x21C))->Slot05(arg1);
        break;
    case 13:
        ((HudSuper *)((char *)this + 0x1DC))->UpdateMaxSuper();
        break;
    case 11:
        ((PVirtObj *)((char *)this + 0x22C))->Slot05(0);
        break;
    case 12:
        ((HudGrim *)((char *)this + 0x22C))->UpdateCover();
        break;
    case 20:
        break;
    case 18:
        ((PVirtObjBool *)((char *)this + 0x290))->Slot05(arg1);
        break;
    case 16:
        ((HudInventory *)((char *)this + 0x2E8))->UpdateShieldIcon();
        break;
    }
    *(int *)(MemMgr + 0x18) = saved;
}

// FUNCTION: 0x13FB90 HudUpdate__9InterfaceFi
void Interface::HudUpdate(int arg0) {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    ((PVirtObj *)((char *)this + 0x1CC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x1DC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x1EC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x1FC))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x20C))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x21C))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x22C))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x250))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x270))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x290))->Slot03(arg0);
    ((PVirtObj *)((char *)this + 0x2E8))->Slot03(arg0);
    *(int *)(MemMgr + 0x18) = saved;
}

// TODO(header): mpPlayerData__7GameHud is a pointer-sized small-data global.
extern GameHud *mpPlayerData__7GameHud;
// TODO(header): IconTable is a 0x20-byte-stride table indexed by icon type; AbilityTable is shared with Player.cpp.
extern char IconTable[0x1100];
extern signed char AbilityTable[];

// DRAFT: 0x0013FCC0 Update__7HudGrimFi
// note: DIFF 116; the +4 folds into lw 4(v0) where the original uses addiu before addu and lw 0(v0); prologue and register allocation also differ.
void HudGrim::Update(int arg0) {
    int idx = m_unkE;
    char *base = (char *)mpPlayerData__7GameHud + 4;
    int target = *(int *)(base + (idx << 2));
    if (target > 0x28) {
        target = 0x28;
    }
    if (m_unkC != target) {
        m_unkF--;
        if ((signed char)m_unkF <= 0) {
            m_unkF = 4;
            char *list = (char *)m_unk4 + 0x14;
            short cur = m_unkC;
            int dir;
            bool bEnable = false;
            short idx;
            if (target - cur >= 0) {
                idx = cur;
                dir = 1;
                m_unkC = cur + 1;
                if (m_unkC == 10) {
                    for (int i = 0; i < 10; i++) {
                        ((PGrimBarAura *)m_unk20)->EnableParticle(i, true);
                    }
                }
                bEnable = (m_unkC < 10) ? (*(signed char *)((char *)mpPlayerData__7GameHud + 0x59) == 4) : true;
            } else {
                cur = cur - 1;
                dir = 0;
                m_unkC = cur;
                idx = cur;
            }
            int count = *(int *)list;
            void **storage = *(void ***)(list + 8);
            PMNode *elem = ((unsigned int)idx < (unsigned int)count) ? (PMNode *)storage[idx] : 0;
            *(int *)((char *)elem + 0xC) = dir;
            ((PGrimBarAura *)m_unk20)->EnableParticle(idx, bEnable);
            if (m_unkC == 0) {
                *(int *)((char *)m_unk4 + 0xC) = 0;
            }
            if (m_unk10 != 0) {
                *(int *)((char *)m_unk10 + 0xC) = (m_unkC < 10) ? 0 : 1;
            }
        }
    }
    m_unk4->Slot04(0.0f, 1.0f, 0, 0, false);
    if (m_unk10 != 0 && *(int *)((char *)m_unk10 + 0xC) != 0) {
        ((PMNode *)m_unk10)->Slot04(0.0f, 1.0f, 0, 0, false);
    }
}

// FUNCTION: 0x13FEC0 UpdateStatus__7HudGrimFb
void HudGrim::UpdateStatus(bool arg0) {
    m_unkF = 1;
    *(int *)((char *)m_unk4 + 0xC) = 1;
}

// FUNCTION: 0x13FEE0 UpdateCover__7HudGrimFv
void HudGrim::UpdateCover() {
    int threshold = 0x14;
    int hp = *(int *)((char *)mpPlayerData__7GameHud + 0x34);
    int i = 0;
    int off = 0;
    do {
        void *elem = *(void **)((char *)this + off + 0x14);
        if (elem != 0) {
            int val;
            if (hp >= threshold) {
                val = 1;
            } else {
                val = 0;
            }
            *(int *)((char *)elem + 0xC) = val;
        }
        i += 1;
        off += 4;
        threshold += 0xA;
    } while (i < 3);
}

// FUNCTION: 0x140180 Delete__7HudGrimFv
void HudGrim::Delete() {
    PParticleSystem *temp_a1 = m_unk20;
    if (temp_a1 != 0) {
        ((PParticleManager *)(gGfxEng + 0x154F00))->Remove(temp_a1);
        m_unk20 = 0;
    }
}

// Cover element IDs; the original local object GrimCover$1444 at 0x241200 (12 bytes).
static unsigned int GrimCover_1444[3] = {0x0D3B7139, 0x2F38C229, 0xC132DB59};

// DRAFT: 0x1401C0 Init__7HudGrimFP9PMeshNodeP7HudData
// note: 10 words differ; GrimCover table reloc names GrimCover_1444 (original GrimCover$1444, '$' rejected), and the Find arg setup and store address order differ. Tried: static table, do/while with offset walk.
void HudGrim::Init(PMeshNode *meshNode, HudData *hud) {
    ((GameHud *)this)->Init(meshNode, hud);
    m_unk10 = ((PMNode *)meshNode)->Find(0x303B74C6);
    if (m_unk4 != 0) {
        m_unk4->RecurseSetSTAnimOptions(false);
    }
    int n = 0;
    int off = 0;
    do {
        n++;
        *(void **)((char *)m_unk14 + off) = ((PMNode *)meshNode)->Find(*(unsigned int *)((char *)GrimCover_1444 + off));
        off += 4;
    } while (n < 3);
    m_unk20 = 0;
}

// FUNCTION: 0x140270 Update__8HudSuperFi
void HudSuper::Update(int arg0) {
    short cur = m_unkC;
    int target = *(int *)((char *)mpPlayerData__7GameHud + 0x3C);
    int diff = target - cur;
    if (diff != 0) {
        if (diff > 0) {
            m_unkC = cur + 4;
            if (target < m_unkC) {
                m_unkC = (short)target;
            }
        } else {
            m_unkC = cur - 4;
            if (m_unkC < target) {
                m_unkC = (short)target;
            }
        }
        UpdateBar(m_unkC);
    }
}

// DRAFT: 0x140550 UpdateBar__8HudSuperFi
// note: 30 words differ; the gate uses slti/beqz not slti/bnez, the 1.0f load is hoisted before the gate, and the loop-exit branch is one instruction short. Tried nested-if, empty-then and swapped-inner variants; all worse.
void HudSuper::UpdateBar(int arg0) {
    void *pBase = m_unk4;
    PArray *pWalk;
    PMNode *pNode;
    ((PMNode *)pBase)->m_unk18 = 0;
    pWalk = (PArray *)((char *)pBase + 0x14);
    pNode = (pWalk->m_unk0 != 0) ? (PMNode *)pWalk->m_unk8[0] : 0;
    if (pNode != 0) {
        do {
            PMNode *pBlock = pNode->Find(0x136CC35A);
            if (pBlock == 0) {
                CdsAssert__FPciPc("Interface.cpp", 0x9F9, "pBlock");
            }
            float fScale = 1.0f;
            if (arg0 < 640) {
                if (arg0 > 0) {
                    fScale = (float)arg0 / 640.0f;
                } else {
                    fScale = 0.0f;
                }
            }
            pBlock->ScaleSet(fScale, 1.0f, 1.0f, 1.0f);
            int nIndex = pWalk->m_unk4 + 1;
            pWalk->m_unk4 = nIndex;
            arg0 -= 640;
            pNode = (nIndex < pWalk->m_unk0) ? (PMNode *)pWalk->m_unk8[nIndex] : 0;
        } while (pNode != 0);
    }
    ((PMNode *)m_unk4)->Slot04(0.0f, 0.0f, 0, 8, false);
}

// FUNCTION: 0x1411C0 AbilityScreen__9InterfaceFv
int Interface::AbilityScreen() {
    int buttons = gPad.m_unk110;
    if (m_unk324 < 0) {
        if (buttons & 1) {
            m_unk1C0 &= ~8;
            gGfxEng[0x1558B0] = 0;
            SetPause();
            DisplayLevelName(-1, 0xF0);
            ((PVirtObj *)((char *)this + 0x2E8))->Slot05(0);
            gPad.PauseVibrate(true);
            ((FontManager *)((char *)this + 0x80))->RemoveAll(true);
        } else {
            return 0;
        }
    }
    return 1;
}

// FUNCTION: 0x141270 AddAbility__9InterfaceFi
void Interface::AddAbility(int arg0) {
    int saved = *(int *)(MemMgr + 0x18);
    *(int *)(MemMgr + 0x18) = 0;
    ((HudInventory *)((char *)this + 0x2E8))->AddIcon(arg0);
    *(int *)(MemMgr + 0x18) = saved;
}

// FUNCTION: 0x001412B0 SetMaxValue__12HudBossMeterFsi
void HudBossMeter::SetMaxValue(short arg0, int arg1) {
    float oldMax = *(float *)&m_unk10;
    m_unkC = arg0;
    *(float *)&m_unk10 = (float)arg0;
    if (m_unk14 < 0) {
        m_unk14 = arg0;
    } else {
        m_unk14 = (short)(((float)m_unk14 * *(float *)&m_unk10) / oldMax);
    }
    if ((unsigned char)m_unkF != 2) {
        m_unkF = 1;
        *(float *)((char *)m_unk4 + 0x84) = m_unk8 - 5.0f;
    }
    if (arg1 > 0 && arg1 != m_unk16) {
        m_unk16 = (signed char)arg1;
        SetFace();
    }
    ((PMNode *)m_unk4)->Slot04(0.0f, 0.0f, 0, 8, false);
    *(int *)((char *)m_unk4 + 0xC) = 1;
}

// FUNCTION: 0x1413A0 SetValue__12HudBossMeterFs
void HudBossMeter::SetValue(short value) {
    m_unkC = value;
    if (value < m_unk14) {
        float f = (float)value / *(float *)&m_unk10;
        if (!(f <= 1.0f)) {
            f = 1.0f;
        }
        *(float *)((char *)m_unk18 + 0xA0) = f;
        *((unsigned char *)m_unk18 + 0x3E) |= 8;
    }
}

// DRAFT: 0x141410 Update__12HudBossMeterFi
// note: DIFF 116 words; case 2 branch lands at 0x30 not 0x31, flag-block delay slot and f0/f1/f2 register assignment differ, and gInterface reloc form (lui $at,0) differs. Tried case order swap (123), case 1 first (117), inverted flags (117), no-else (121), load order and operand order (116 neutral).
void HudBossMeter::Update(int arg0) {
    float f;
    switch ((unsigned char)m_unkF) {
    case 1: {
        if ((unsigned char)m_unk17 != 0 && gInterface.m_unk1A0 == 0) {
            f = 1.0f;
        } else {
            f = 0.0f;
        }
        *(float *)((char *)m_unk4 + 0x2C) = f;
        if (!((m_unk8 - *(float *)((char *)m_unk4 + 0x84)) <= 0.0f)) {
            float cur = *(float *)((char *)m_unk4 + 0x84);
            float next = cur + 0.5f;
            if (!(next < m_unk8)) {
                m_unkF = 2;
            }
            *(float *)((char *)m_unk4 + 0x84) = next;
            ((PMNode *)m_unk4)->Slot04(0.0f, 0.0f, 0, 8, false);
        }
        break;
    }
    case 2: {
        if ((unsigned char)m_unk17 != 0 && gInterface.m_unk1A0 == 0) {
            f = 1.0f;
        } else {
            f = 0.0f;
        }
        *(float *)((char *)m_unk4 + 0x2C) = f;
        int diff = (short)m_unkC - (short)m_unk14;
        if (diff != 0) {
            if (diff < 0) {
                int v = m_unk14 + diff;
                if (diff < -2) {
                    v = m_unk14 - 2;
                }
                m_unk14 = (short)v;
                f = (float)m_unk14 / *(float *)&m_unk10;
                if (!(f <= 1.0f)) {
                    f = 1.0f;
                }
                *(float *)((char *)m_unk1C + 0xA0) = f;
            } else {
                if (diff >= 5) {
                    diff = 4;
                }
                m_unk14 += (short)diff;
                f = (float)m_unk14 / *(float *)&m_unk10;
                if (!(f <= 1.0f)) {
                    f = 1.0f;
                }
                *(float *)((char *)m_unk18 + 0xA0) = f;
            }
            ((PMNode *)m_unk4)->Slot04(0.0f, 0.0f, 0, 8, false);
        }
        break;
    }
    }
}

// FUNCTION: 0x141630 SetFace__12HudBossMeterFv
void HudBossMeter::SetFace() {
    static unsigned int FaceID[3] = {0x00000000, 0x902DF890, 0x4B01E2EE};
    int i = 0;
    int off = 0;
    do {
        PMNode *node = ((PMNode *)m_unk4)->Find(*(unsigned int *)((char *)FaceID + off));
        if (node != 0) {
            *(int *)((char *)node + 0xC) = (i == m_unk16) ? 1 : 0;
        }
        i++;
        off += 4;
    } while (i < 3);
}

// FUNCTION: 0x1416B0 Reset__12HudBossMeterFv
void HudBossMeter::Reset() {
    *(int *)((char *)m_unk4 + 0xC) = 0;
    *(int *)((char *)m_unk4 + 0x2C) = 0x3F800000;
    *(float *)((char *)m_unk4 + 0x84) = m_unk8 - 5.0f;
    *(int *)((char *)m_unk18 + 0xA0) = 0x3F800000;
    *(int *)((char *)m_unk1C + 0xA0) = 0;
    m_unkF = 0;
    m_unk14 = -1;
    m_unk10 = 0x42C80000;
    m_unk17 = 1;
}

// DRAFT: 0x141710 Init__12HudBossMeterFP9PMeshNodeP7HudData
// note: DIFF 28 words; branch layout and shared sb $zero,0x16 delay slot differ. Tried ==/!= polarity (33, 28), pre-branch m_unk16 store (44).
void HudBossMeter::Init(PMeshNode *meshNode, HudData *hud) {
    m_unk4 = ((PMNode *)meshNode)->Find(hud->m_unk0);
    m_unkF = hud->m_unk5;
    m_unkE = hud->m_unk4;
    m_unk8 = *(float *)((char *)m_unk4 + 0x84);
    if (hud->m_unk0 != 0xA389995D) {
        m_unk18 = ((PMNode *)m_unk4)->Find(0x463547C7U);
        m_unk1C = ((PMNode *)m_unk4)->Find(0x6780BC04U);
        m_unk16 = 2;
    } else {
        m_unk18 = ((PMNode *)m_unk4)->Find(0x2291CBBBU);
        m_unk1C = ((PMNode *)m_unk4)->Find(0x20DDED4AU);
        m_unk16 = 0;
    }
    SetFace();
}

// DRAFT: 0x001417F0 Update__8HudComboFi
// note: 29 words differ; case 2 loads m_unk8 into $f2 and swaps sub.s operands (original loads $f1 first, then 0x3F80 into $f2); case 3 Slot04 loads 1.0f into $f13 before 0.0f into $f12 (ours reverses); original shares one epilogue b between case 3 and default and is 0x16C bytes vs our 0x174. Tried: local fStep vs compound -= (31), local fOne for 1.0f (29, no change), default before case 3 (44).
void HudCombo::Update(int arg0) {
    switch (m_unkF) {
    case 1:
        if ((signed char)(*(signed char *)((char *)m_unk4 + 0x3F) & 7) == 0) {
            m_unkF = m_unkF + 1;
            *(float *)&m_unk8 = 80.0f;
        }
        break;
    case 2:
        if (arg0 == 0) {
            float fStep = *(float *)&m_unk8 - 1.0f;
            *(float *)&m_unk8 = fStep;
            if (fStep <= 0.0f) {
                m_unkF = 3;
                m_unk4->EnableAnim(true, false);
                m_unk4->SetAnimLoopCount(1, false);
                SetFrameRate__6PMNodeFfb(m_unk4, -0.5f, false);
                *(int *)((char *)m_unk48 + 0x2C) = 0x3F800000;
            }
        }
        break;
    case 3:
        if ((m_unk4->Slot04(0.0f, 1.0f, 0, 0, false) & 7) == 0) {
            m_unkF = 0;
            m_unk4->SetAllFrustrumTest((eBoxIntersect)0);
        }
        return;
    default:
        return;
    }
    m_unk4->Slot04(0.0f, 1.0f, 0, 0, false);
}

// DRAFT: 0x00141960 UpdateStatus__8HudComboFb
// note: 54 words differ; original hoists the state constant 2 to entry, loads the mpPlayerData pointer and adds 4 before the index, and compares 2,1,3,0; ours folds +4 into lh offset. Tried: case orders 2,3,1,0 (69) and 2,1,3,0 (64); short-indexed global load (56).
void HudCombo::UpdateStatus(bool flag) {
    m_unkC = *(short *)((char *)mpPlayerData__7GameHud + 4 + (m_unkE * 4));
    switch (m_unkF) {
    case 0:
        m_unkF = 1;
        m_unk4->SetAllFrustrumTest((eBoxIntersect)1);
        ((PVirtObj *)m_unk4)->Slot05(0);
        ComboNumber();
        return;
    case 2:
        if (flag) {
            m_unk8 = 0x40000000;
            return;
        }
        m_unkF = 1;
        break;
    case 3:
        SetFrameRate__6PMNodeFfb(m_unk4, 0.5f, false);
        m_unkF = 1;
        break;
    case 1:
        break;
    default:
        return;
    }
    ComboNumber();
    if (m_unk44 != 0) {
        ((PVirtObj *)m_unk44)->Slot05(0);
    }
    if (m_unk4C != 0) {
        ((PVirtObj *)m_unk4C)->Slot05(0);
    }
}

// FUNCTION: 0x141A80 ComboFinish__8HudComboFv
void HudCombo::ComboFinish() {
    void *temp_a1 = m_unk48;
    if (temp_a1 != 0) {
        *(int *)((char *)temp_a1 + 0x2C) = 0x3F800000;
    }
    void *temp_a0 = m_unk38;
    if (temp_a0 != 0) {
        *(int *)((char *)temp_a0 + 0x2C) = 0x3F800000;
    }
}

// Ten 32-bit hash keys looked up by HudCombo::InitCombo; the original local object ComboNumber$1169 at 0x241080 (40 bytes).
static unsigned int ComboNumber_1169[10] = {0x6B0BE84A, 0x6AAE41FC, 0x6840BB26, 0x69E51290, 0x6D9D4E92,
                                            0x6C38E724, 0x6ED61DFE, 0x6F73B448, 0x6626A5FA, 0x67830C4C};

// DRAFT: 0x141DF0 InitCombo__8HudComboFP9PMeshNodeP7HudDataP6PMNode
// note: 74 words. Differs from 0x130 on: Find/Remove/Add argument order and m_unk4 load before Find; frame 0x60 vs 0x70 with the node kept in s1 (ours spills to 0x6C); CdsAssert and CopyMNode argument order. Tried: vtable +0x970/+0xE00 (75), void **slots loop (134), scoped slotBase loop (134), direct *(void **) temp_v1 load (74, reverted).
void HudCombo::InitCombo(PMeshNode *arg0, HudData *arg1, PMNode *arg2) {
    m_unk4 = Find__6PMNodeFUi((PMNode *)arg0, arg1->m_unk0);
    m_unkF = arg1->m_unk5;
    m_unkE = arg1->m_unk4;
    *(int *)((char *)this + 0x3C) = 0;
    *(int *)((char *)this + 0x40) = 0;
    m_unk44 = Find__6PMNodeFUi((PMNode *)arg0, 0xEE9AFE2CU);
    m_unk48 = Find__6PMNodeFUi((PMNode *)arg0, 0x9A4EBB54U);
    ((PMNode *)m_unk48)->SetAllFrustrumTest((eBoxIntersect)0);
    *(int *)((char *)m_unk48 + 0xC) = 1;
    m_unk4C = Find__6PMNodeFUi((PMNode *)arg0, 0x2BE31146U);
    PMNode *temp_v0 = Find__6PMNodeFUi((PMNode *)arg0, 0x4F83EE74U);
    if (temp_v0 == 0) {
        CdsAssert__FPciPc("Interface.cpp", 0x781, "pNumber");
    }
    for (int i = 0; i < 10; i++) {
        ((void **)((char *)this + 0x10))[i] = Find__6PMNodeFUi(temp_v0, ComboNumber_1169[i]);
    }
    void *temp_v1 = ((void **)((char *)this + 0x10))[0];
    m_unk50 = *(float *)((char *)temp_v1 + 0x80);
    m_unk54 = *(float *)((char *)temp_v1 + 0x84);
    ((PArray *)((char *)Find__6PMNodeFUi(m_unk4, 0xF796F8CBU) + 0x14))->Remove(temp_v0);
    ((PArray *)((char *)arg2 + 0x14))->Add(temp_v0);
    void *node = __nw__FUi(0x100);
    if (node != 0) {
        *(unsigned char **)node = __vt__9PResource;
        *(int *)((char *)node + 4) = 0;
        *(unsigned char **)node = __vt__6PMNode;
        __ct__6PArrayFv((char *)node + 0x14);
        sceVu0UnitMatrix((char *)node + 0x40);
        __ct__6PArrayFv((char *)node + 0xD8);
        InitMembers__6PMNodeFv((PMNode *)node);
    }
    m_unk38 = node;
    if (m_unk38 == 0) {
        CdsAssert__FPciPc("Interface.cpp", 0x78B, "mpNumberBase");
    }
    CopyMNode__6PMNodeFR6PMNodeb((PMNode *)m_unk38, temp_v0, false);
    ((PArray *)((char *)m_unk4 + 0x14))->Add(m_unk38);
}

// DRAFT: 0x1424A0 UpdateStatus__7GameHudFb
// note: switch on m_unkF with case order 0,3,2,1 gives DIFF 54 (if-chain 65, case order 2,3,1,0 67); compare sequence 1,2,3,0 vs original 2,3,1,0 and register use in the CoinAnim/virtual calls differ.
void GameHud::UpdateStatus(bool arg0) {
    m_unk8 = arg0 ? 2.0f : 80.0f;
    switch (m_unkF) {
    case 0:
        m_unkF = 1;
        SetNumber();
        ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)1);
        ((PVirtObj *)m_unk4)->Slot05((int)&CoinAnim);
        break;
    case 3:
        m_unkF = 1;
        {
            PVirtSlots *pSlots = *(PVirtSlots **)((char *)m_unk4 + 0x24);
            pSlots->Slot15(1.0f);
            pSlots->Slot12(1);
            pSlots->Slot10(0);
            pSlots->Slot13(*(short *)(CoinAnim + 4));
        }
        break;
    case 2:
        if (!arg0) {
            m_unkF = 1;
            ((PMNode *)m_unk4)->EnableAnim(true, false);
            ((PMNode *)m_unk4)->SetAnimLoopCount(0, false);
        }
        break;
    case 1:
        break;
    }
}

// DRAFT: 0x142620 Reset__7GameHudFv
// note: 30 words differ; lbu/bltz match, but the original loads the mpPlayerData pointer before andi and folds +4 into addiu before the index add; ours folds +4 into the lh offset and reloads the global after andi. Tried: int local for m_unkE, char* base + 4, int table view, explicit offset variable.
void GameHud::Reset() {
    int idx = m_unkE;
    if (idx >= 0) {
        char *base = (char *)mpPlayerData__7GameHud;
        int off = (idx & 0xFF) << 2;
        m_unkC = *(short *)(base + 4 + off);
        if (m_unkC == 0) {
            *(int *)((char *)m_unk4 + 0xC) = 0;
            m_unkF = 0;
            return;
        }
        m_unkF = 1;
        SetNumber();
        ((PMNode *)m_unk4)->SetAllFrustrumTest((eBoxIntersect)1);
        ((PVirtObj *)m_unk4)->Slot05((int)&CoinAnim);
    }
}

// DRAFT: 0x142900 SwapCheck__12HudInventoryFUi
// note: 69 words differ. Separate early returns where the original shares one return-0 exit; hud + 0x5B is reassociated; gp reload order. Tried: base in two steps, single result variable (84), hudRow temp (69).
int HudInventory::SwapCheck(unsigned int arg0) {
    if (!(arg0 & 0x4000)) {
        return 0;
    }
    int idx = m_unk40;
    if (idx >= 0x18) {
        return 0;
    }
    int group = 2;
    if (idx < 0xC) {
        group = 0;
    }
    int slot = idx % 12;
    if (slot >= 7) {
        group++;
        slot -= 7;
    }
    char *hud = (char *)mpPlayerData__7GameHud;
    char *base = hud + 0x5B + (group << 3);
    char *cell = base + slot;
    int icon = *cell;
    if (slot == 0) {
        if (group != 2 && group != 0) {
            return 0;
        }
        if (*(int *)(hud + 0x2C) == icon) {
            return 0;
        }
    }
    if (icon < 0) {
        return 0;
    }
    if (AbilityTable[(icon << 4) + 6] != -2) {
        return 0;
    }
    *cell = *base;
    *base = icon;
    UpdateGroup(group);
    ((Player *)*(char **)(gEng + 0x1883C))->SwapAbility(icon);
    m_unk40 = *(int *)(IconTable + 0x1008 + (group << 5));
    return 1;
}

// DRAFT: 0x00142DD0 Update__12HudInventoryFi
// note: DIFF 120; frame is 0x50 with this in s0 (original 0x60 with this in s2), state dispatch order and the gInterface base register differ.
void HudInventory::Update(int arg0) {
    unsigned char state = m_unkF;
    if (state == 3) {
        PMNode *node = Find__6PMNodeFUi((PMNode *)m_unk4, 0x7BDFB173);
        if (node != 0) {
            PVirtIntSlot4 *sub = *(PVirtIntSlot4 **)((char *)node + 0x24);
            int r = 0;
            if (sub != 0) {
                r = sub->Slot04();
            }
            if (r == 0) {
                *(int *)((char *)m_unk4 + 0xC) = 0;
                m_unkF = 0;
                *(int *)((char *)&gInterface + 0x18D0) = 15;
            }
        }
    } else if (state == 2) {
        InfoScreen();
    } else if (state == 1) {
        PMNode *node = Find__6PMNodeFUi((PMNode *)m_unk4, 0x7BDFB173);
        if (node != 0) {
            PVirtIntSlot4 *sub = *(PVirtIntSlot4 **)((char *)node + 0x24);
            int r = 0;
            if (sub != 0) {
                r = sub->Slot04();
            }
            if (r == 0) {
                m_unk10 = 0;
                m_unkF = 2;
                Interface *ui = &gInterface;
                char *p = *(char **)((char *)ui + 0x100);
                char *s1 = p + 0xA14;
                if (*(signed char *)(p + 0xA1E) < 0xC) {
                    ((FontManager *)ui)->DisplayString(0xD6, 0, 0, false);
                } else {
                    unsigned short buf[16];
                    buf[0] = 0x7B;
                    buf[1] = 0x20;
                    JapanAddNumber__11FontManagerFPUsPUsi(&buf[2], *(unsigned short **)s1, -1);
                    void *fm = DisplayString__11FontManagerFPcffi9FontColor9FontAlign((void *)ui, (char *)buf, 145.0f, -215.0f, *(signed char *)(s1 + 0xA), 0, 0);
                    *(short *)((char *)fm + 6) = 0x15;
                    ((FontManager *)ui)->DisplayString(0xD6, 0, 0, false);
                }
            }
        }
    } else if (state == 0) {
        return;
    }
    ((PMNode *)m_unk4)->Slot04(0.0f, 1.0f, 0, 0, false);
}

// FUNCTION: 0x142FF0 UpdateStatus__12HudInventoryFb
void HudInventory::UpdateStatus(bool flag) {
    float rate;
    if (flag) {
        m_unkF = 3;
        rate = -0.5f;
        m_unk10 = 1;
        m_unk3C = -1;
        gPad.PauseVibrate(false);
        gSound.AbilityScreenLeave();
    } else {
        m_unkF = 1;
        gSound.AbilityScreenEnter();
        *(int *)((char *)m_unk4 + 0xC) = 1;
        rate = 0.5f;
        m_unk3C = 0;
    }
    ((PMNode *)m_unk4)->RecurseSetLoopRateByID(-1U, 1, rate);
    gSound.PlaySoundUbiquitous(0x3A);
}

// FUNCTION: 0x1430B0 Delete__12HudInventoryFv
void HudInventory::Delete() {
    m_unk4 = 0;
    m_unk10 = 1;
    m_unk3C = -1;
}

// DRAFT: 0x1430D0 UpdateShieldIcon__12HudInventoryFv
// note: 64 words differ, size 0x110 vs 0x128. Original keeps elem in v1 and the PArray in a0; the m44 switch lays out 0x6A last; tail loop uses positive-branch sb body. Tried: if/else-if node (73), ternary node (73), switch m44 (73), if-chain m44 (67), reordered tail compares (73), explicit PArray pointer (65), ternary store (64), restored compare order (64).
void HudInventory::UpdateShieldIcon() {
    char *elem = (char *)m_unk1C;
    *(int *)(elem + 0x18) = 0;
    char *pa = elem + 0x14;
    char *node = 0;
    if (*(unsigned int *)pa != 0) {
        node = ((char **)*(char ***)(pa + 8))[0];
    }
    int m44 = *(int *)((char *)mpPlayerData__7GameHud + 0x44);
    int sel;
    int val;
    switch (m44) {
    case 0x6A:
        sel = 2;
        val = 0x13;
        break;
    case 0x9F:
        sel = 1;
        val = 0x12;
        break;
    default:
        sel = 0;
        val = 4;
        break;
    }
    for (int i = 0; i < 3; i++) {
        char *e = 0;
        if ((unsigned int)i < *(unsigned int *)(node + 0x14)) {
            e = ((char **)*(char ***)(node + 0x1C))[i];
        }
        if (e) {
            *(int *)(e + 0xC) = (i == sel) ? 1 : 0;
        }
    }
    char *p = (char *)mpPlayerData__7GameHud + 0x63;
    for (int k = 0; k < 3; k++, p++) {
        signed char v = *p;
        if (v == 4 || v == 0x12 || v == 0x13) {
            *p = (signed char)val;
        }
    }
}

// DRAFT: 0x00143200 AddIcon__12HudInventoryFi
// note: 68 words differ. Early branch at 0x20 targets 0x50 (orig 0x3B) so the copy loop is unrolled by eight in ours and the exit lands later. Tried: IconTable offset folded into index, i=0 before w=1, w declared before i, copy loop as base[i] (no change).
void HudInventory::AddIcon(int arg0) {
    signed char sp18[8];
    signed char *entry;
    signed char *base;
    int iconType;
    int count;
    int w;
    int i;
    signed char slot;
    signed char c;
    signed char *dst;

    entry = AbilityTable + arg0 * 16;
    iconType = entry[5];
    if ((unsigned int)iconType < 4) {
        slot = entry[6];
        if (slot != -1) {
            count = *(int *)(IconTable + (iconType << 5));
            if (slot == -2) {
                sp18[0] = arg0;
                i = 0;
                w = 1;
                base = (signed char *)mpPlayerData__7GameHud + 0x5B + iconType * 8;
                for (; i < count; i++) {
                    c = base[i];
                    if (c != arg0) {
                        sp18[w] = c;
                        w++;
                    }
                }
                dst = base;
                for (i = 0; i < count; i++) {
                    *dst = sp18[i];
                    dst++;
                }
            } else {
                base = (signed char *)mpPlayerData__7GameHud + 0x5B + iconType * 8;
                base[count + slot] = arg0;
            }
            UpdateGroup(iconType);
        }
    }
}

// DRAFT: 0x00143320 UpdateGroup__12HudInventoryFi
// note: 120 words differ; scheduling and address form of the pair loads/stores; first arrangement 121, one reorder 120.
void HudInventory::UpdateGroup(int arg0) {
    int a2 = arg0 * 8;
    PMNode *s7 = *(PMNode **)((char *)this + 0x18 + a2);
    PMNode *s6 = *(PMNode **)((char *)this + 0x14 + a2);
    PArray *s5 = (PArray *)((char *)s7 + 0x14);
    char *s0;
    signed char *s1;
    u_long128 *s2;
    PMNode *s4;
    float f12;
    int s3;

    s6->SetAllFrustrumTest((eBoxIntersect)0);
    s0 = IconTable + (arg0 << 5);
    s1 = (signed char *)mpPlayerData__7GameHud + a2 + 0x5B;
    if (s7 != 0) {
        s7->SetAllFrustrumTest((eBoxIntersect)0);
    }
    s2 = *(u_long128 **)(s0 + 0x1C);
    s3 = 0;
    do {
        signed char v0 = *s1;
        if (v0 >= 0) {
            signed char *a0 = AbilityTable + (v0 << 4);
            signed char v1 = a0[6];
            if (v1 != -1) {
                if (s3 < *(int *)(s0 + 0x14)) {
                    s4 = s6->Find(*(unsigned int *)(a0 + 8));
                    if (s3 != 0) {
                        f12 = *(float *)(s0 + 0x10);
                    } else {
                        f12 = 1.0f;
                    }
                    s4->ScaleSet(f12, f12, 1.0f, 1.0f);
                    *(u_long128 *)((char *)s4 + 0x80) = *s2;
                    s2 += 1;
                    ((unsigned char *)s4)[0x3E] |= 8;
                } else {
                    s4 = (((unsigned int)v1) < s5->m_unk0) ? (PMNode *)s5->m_unk8[v1] : 0;
                }
                s4->m_unkC = 1;
            }
        }
        s3++;
        s1++;
    } while (s3 < 8);
    s6->m_unkC = 1;
    if (s7 != 0) {
        s7->m_unkC = 1;
    }
    if (arg0 == 1) {
        UpdateShieldIcon();
    }
    ((PMNodeView *)s6)->Slot04(0.0f, 0.0f, 0, 0);
}

// DRAFT: 0x143510 Reset__12HudInventoryFv
// note: 8 words differ; size 0x88 vs 0x8c. The original has an extra nop before the loop bnez, and the call-site reloc set is otherwise equal. Tried: pointer local for this+4 (CSE into s0), member m_unk4, for-loop form (16 words), UpdateGroup(i++) (12 words).
void HudInventory::Reset() {
    if (m_unk4 != 0) {
        ((PVirtObj *)m_unk4)->Slot05((int)&DefaultLoopAnim);
        *(int *)((char *)m_unk4 + 0xC) = 0;
        *(signed char *)((char *)this + 0xF) = 0;
    }
    *(signed char *)((char *)this + 0x10) = 1;
    *(int *)((char *)this + 0x3C) = -1;
    *(int *)((char *)this + 0x40) = 0;
    int i = 0;
    do {
        UpdateGroup(i);
        i += 1;
    } while (i < 4);
}

// DRAFT: 0x001435A0 Init__12HudInventoryFP9PMeshNodeP7HudData
// note: 110 words differ; original keeps 8 saved regs (this in s7, arg0 in s6, entry ptr live across the loop), ours 7 saved, frame 0x80 vs 0x90; tried pointer entry (112->111), s2/s3 induction offsets (111->110), root copy of arg0 (no change).
void HudInventory::Init(PMeshNode *arg0, HudData *arg1) {
    PMNode *root = (PMNode *)arg0;
    m_unk4 = root->Find(arg1->m_unk0);
    m_unkF = arg1->m_unk5;
    m_unkE = arg1->m_unk4;
    int i = 0;
    unsigned int s2 = 0;
    int s3 = 0;
    do {
        char *entry = IconTable + s2;
        char *slot = (char *)this + s3;
        PMNode *n0 = root->Find(*(unsigned int *)entry);
        *(PMNode **)(slot + 0x14) = n0;
        PMNode *n1 = root->Find(*(unsigned int *)(entry + 4));
        *(PMNode **)(slot + 0x18) = n1;
        PArray *pa = (PArray *)((char *)n1 + 0x14);
        u_long128 *dst = *(u_long128 **)(entry + 0x1C);
        for (int j = 0; j < *(int *)(entry + 0x14); j++) {
            void *src = (j < pa->m_unk0) ? pa->m_unk8[j] : 0;
            if (src) {
                *dst = *(u_long128 *)((char *)src + 0x80);
            }
            dst++;
        }
        i++;
        s2 += 0x20;
        s3 += 8;
    } while (i < 4);
    m_unk34 = ((PMNode *)arg0)->Find(0xBBCD34F9);
    if (m_unk34 != 0) {
        float *pBox = (float *)(BoxSize + *(signed char *)((char *)&gInterface + 0x93) * 0xC);
        m_unk34->ScaleSet(pBox[0], 1.0f, 1.0f, 1.0f);
    }
    m_unk38 = ((PMNode *)arg0)->Find(0x2C87C156);
    if (m_unk38 == 0) {
        CdsAssert__FPciPc("Interface.cpp", 0x4DB, "mpCursor");
    }
    m_unk38->m_unkC = 0;
}

// FUNCTION: 0x143770 __ct__12HudInventoryFv
HudInventory::HudInventory() {
    *(void **)this = __vt__7GameHud;
    *(int *)((char *)this + 0x4) = 0;
    *(void **)this = __vt__12HudInventory;
    *(int *)((char *)this + 0x4) = 0;
    *(signed char *)((char *)this + 0x10) = 1;
    *(int *)((char *)this + 0x14) = 0;
    *(int *)((char *)this + 0x18) = 0;
    *(int *)((char *)this + 0x1C) = 0;
    *(int *)((char *)this + 0x20) = 0;
    *(int *)((char *)this + 0x24) = 0;
    *(int *)((char *)this + 0x28) = 0;
    *(int *)((char *)this + 0x2C) = 0;
    *(int *)((char *)this + 0x30) = 0;
    *(int *)((char *)this + 0x3C) = -1;
}

// FUNCTION: 0x1437D0 __dt__7GameHudFv
GameHud::~GameHud() {
    m_unk0 = __vt__7GameHud;
    ((PVirtObj *)this)->Slot01();
}

// DRAFT: 0x143BC0 EnableBG__7HudHintFb
// note: DIFF 57; ours is 0x170 bytes vs 0x180. Dispatch and loop-entry branches differ (original enters the for loop with a b to its test, ours falls in), and the Find call has no reloc. Tried: static initialiser, member Find call, extern "C" Find, while loop.
void HudHint::EnableBG(bool arg0) {
    static unsigned int InventoryNames[4] = {0x4781EFDE, 0x59DDFCBB, 0xFCFE9AB1, 0xBBCD34F9};
    unsigned int i;
    void *pBase;
    PArray *pWalk;
    PMNode *pNode;
    PMNode *pFound;
    float fValue;
    int nIndex;

    fValue = arg0 ? 1.0f : 0.0f;
    pBase = gInterface.m_unk1C4;
    pWalk = (PArray *)((char *)pBase + 0x14);
    pWalk->m_unk4 = 0;
    pNode = (pWalk->m_unk0 != 0) ? (PMNode *)pWalk->m_unk8[0] : 0;
    if (pNode != 0) {
        do {
            switch (*(unsigned int *)((char *)pNode + 0x8)) {
            case 0x2BA0F70C:
                for (i = 0; i < 4; i++) {
                    pFound = pNode->Find(InventoryNames[i]);
                    if (pFound != 0) {
                        *(float *)((char *)pFound + 0x2C) = fValue;
                    }
                }
                break;
            case 0xFBD2D937:
                *(int *)((char *)m_unkB4 + 0xC) = (arg0 == 0) ? 1 : 0;
                break;
            default:
                *(float *)((char *)pNode + 0x2C) = fValue;
                break;
            }
            nIndex = pWalk->m_unk4 + 1;
            pWalk->m_unk4 = nIndex;
            pNode = (nIndex < (int)pWalk->m_unk0) ? (PMNode *)pWalk->m_unk8[pWalk->m_unk4] : 0;
        } while (pNode != 0);
    }
}

// DRAFT: 0x143D40 WriteHint__7HudHintFv
// note: 20 differing lines; index load goes to v1 where original uses a1 (addiu v1,s1,0x38 precedes the index scale). Tried: local idx, base pointer m_unk38, pointer arithmetic, pointer-offset form; codegen identical in all four.
void HudHint::WriteHint() {
    FontManager *fm = (FontManager *)((char *)&gInterface + 0x80);
    fm->RemoveText((unsigned short)0x14);
    fm->DisplayString(HintTable[m_unk38[m_unkC]] + 1, 0, 10, false);
}

// FUNCTION: 0x143FF0 InitHint__7HudHintFv
void HudHint::InitHint() {
    FontManager *fm = (FontManager *)((char *)&gInterface + 0x80);
    EnableAllText__11FontManagerFb(fm, false);
    fm->DisplayString(0xD4, 0, 0, false);
    m_unkC = 0;
    m_unkB0 = 0;
    for (int i = 0; i < 0x1E; i++) {
        if (m_unk8 & (1 << i)) {
            m_unk38[m_unkB0++] = i;
        }
    }
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
    m_unk30 = 0;
    m_unk34 = 0;
    DisplayTitle(0);
    if (m_unkB0 != 0) {
        WriteHint();
    }
    char buf[5];
    char *p = buf;
    if (m_unkB0 >= 10) {
        *p++ = (char)(m_unkB0 / 10 + '0');
    }
    *p++ = (char)(m_unkB0 % 10 + '0');
    *p++ = '/';
    *p++ = '3';
    *p++ = '0';
    *p = 0;
    DisplayString__11FontManagerFPcffi9FontColor9FontAlign(fm, buf, -200.0f, 50.0f, 0, 0, 2);
}

// FUNCTION: 0x144180 Init__7HudHintFUi
void HudHint::Init(unsigned int arg0) {
    m_unk0 = 0;
    m_unk8 = arg0;
    gInterface.FadeScreen(255.0f, 17.0f, true, (Interface::eFadeColor)0);
    m_unk4 = gInterface.m_unk1C0;
    gInterface.m_unk1C0 = m_unk4 | 0x10;
}

// FUNCTION: 0x1441F0 InitNode__7HudHintFP9PMeshNode
void HudHint::InitNode(PMeshNode *node) {
    m_unkB4 = ((PMNode *)node)->Find(0xFBD2D937U);
    if (m_unkB4 == 0) {
        CdsAssert__FPciPc("Interface.cpp", 0x3A0, "mpBG");
    }
    m_unkB4->m_unkC = 0;
    float *pBox = (float *)(BoxSize + *(signed char *)((char *)&gInterface + 0x93) * 0xC);
    PMNode *pNode = ((PMNode *)node)->Find(0x4FEFC567U);
    if (pNode != 0) {
        pNode->ScaleSet(pBox[1], 1.0f, 1.0f, 1.0f);
        pNode->m_unk80 += pBox[2];
    }
}

// FUNCTION: 0x001442C0 ResetGameHud__9InterfaceFv
class HudResetElement {
public:
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3();
    virtual void Reset();       // virtual slot 4, vtable offset 0x18
};

void Interface::ResetGameHud() {
    m_unk1C0 |= 2;
    ((HudResetElement *)((char *)this + 0x1CC))->Reset();
    ((HudResetElement *)((char *)this + 0x1DC))->Reset();
    ((HudResetElement *)((char *)this + 0x1EC))->Reset();
    ((HudResetElement *)((char *)this + 0x1FC))->Reset();
    ((HudResetElement *)((char *)this + 0x20C))->Reset();
    ((HudResetElement *)((char *)this + 0x21C))->Reset();
    ((HudResetElement *)((char *)this + 0x22C))->Reset();
    ((HudResetElement *)((char *)this + 0x250))->Reset();
    ((HudResetElement *)((char *)this + 0x270))->Reset();
    ((HudResetElement *)((char *)this + 0x290))->Reset();
    ((HudResetElement *)((char *)this + 0x2E8))->Reset();
}

// FUNCTION: 0x144690 Init__7GameHudFP9PMeshNodeP7HudData
void GameHud::Init(PMeshNode *meshNode, HudData *hud) {
    m_unk4 = ((PMNode *)meshNode)->Find(hud->m_unk0);
    m_unkF = hud->m_unk5;
    m_unkE = hud->m_unk4;
}

// FUNCTION: 0x144930 LoadingDisplayGuts__9InterfaceFUi
void Interface::LoadingDisplayGuts(unsigned int arg0) {
    static int st_uCount;
    static signed char init;
    if (init == 0) {
        st_uCount = 0;
        init = 1;
    }
    DebugClear__5DebugFv(gDebug);
    st_uCount += 1;
    if (arg0 == 0) {
        st_uCount = 0;
    }
    if (st_uCount & 0x10) {
        DebugDispPos__5DebugFPcUiUii(gDebug, "LOADING...", 10, 20, 7);
    }
    RefreshDisplay__10PGfxEngineFv(gGfxEng);
}

// DRAFT: 0x001449C0 LoadingDisplayNew__9InterfaceFUi
// note: 101 words differ, size 0x1B0 vs 0x1C8. Original keeps VBlank in t0, CDS in a2, doGuts in v1; ours has VBlank in t1, CDS in t0, doGuts in a3; the busy-wait reads COP0 Count via inline mfc0. Tried: helper call, plain C wait loop, inline mfc0 asm (104->101), doCall flag, declaration reorders, scoped t/target, doGuts initialized at declaration: all 101.
void Interface::LoadingDisplayNew(unsigned int arg0) {
    int a;
    int b;
    int doGuts;
    int doCall;
    unsigned int t;
    unsigned int target;
    doGuts = 0;
    if (fst_VBlankCount >= gCDSVBlankCount && fst_callsThisFrame >= fst_maxCallsPerFrameAllowed) {
        while (fst_VBlankCount >= gCDSVBlankCount) {
        }
    }
    if (fst_VBlankCount < gCDSVBlankCount) {
        doGuts = 1;
        doCall = doGuts;
        fst_callsThisFrame = 0;
        fst_VBlankCount = gCDSVBlankCount;
        fst_nFramesTotal += 1;
    } else {
        fst_callsThisFrame += 1;
        doCall = 1;
        if (fst_callsThisFrame >= 2) {
            asm {
                mfc0 t, $9
            }
            target = t + (0x3A0458 / fst_maxCallsPerFrameAllowed);
            while (t < target) {
                asm {
                    mfc0 t, $9
                }
            }
        }
    }
    if (doGuts) {
        LoadingDisplayGuts(arg0);
        fst_VBlankCount = gCDSVBlankCount;
    }
    if (doCall) {
        SoundOneFrameHasElapsed_R__9MaxEngineFRiRi(gEng, &a, &b);
    }
    fst_nCallsTotal += 1;
    if (fst_maxCallsPerFrameDone < fst_callsThisFrame) {
        fst_maxCallsPerFrameDone = fst_callsThisFrame;
    }
    fst_fAvgCallsPerFrame = (float)fst_nCallsTotal / (float)fst_nFramesTotal;
}

// FUNCTION: 0x144B90 LoadingDisplayOld__9InterfaceFUii
void Interface::LoadingDisplayOld(unsigned int arg0, int arg1) {
    int a;
    int b;
    if (m_unk427 != 0) {
        int msg = 0x28F;
        switch (arg1) {
        case 2:
            msg = 0x28E;
            break;
        case 3:
            msg = 0x28B;
            break;
        case 1:
        case 4:
            msg = 0x290;
            break;
        case 6:
            msg = 0x292;
            break;
        }
        ((FontManager *)((char *)this + 0x80))->RenderWarning(msg);
    }
    SoundOneFrameHasElapsed_R__9MaxEngineFRiRi(gEng, &a, &b);
    if (m_unk427 != 0) {
        RefreshDisplay__10PGfxEngineFv(gGfxEng);
    }
    IncrementSecondarySyncCounts__9MaxEngineFv(gEng);
}

// FUNCTION: 0x144C60 LoadingDisplay__9InterfaceFUii
void Interface::LoadingDisplay(unsigned int arg0, int arg1) {
    if (fst_bUseOldLoadingDisplay != 0) {
        LoadingDisplayOld(arg0, arg1);
        return;
    }
    LoadingDisplayNew(arg0);
}

// FUNCTION: 0x144CA0 AddMeshLayer__9InterfaceFP6PMNode
void Interface::AddMeshLayer(PMNode *node) {
    if ((unsigned int)m_unk404 >= 8) {
        CdsAssert__FPciPc("Interface.cpp", 0x1ED, "mMeshLayerList.GetCount() < MAX_MESHLAYER");
    }
    ((PArray *)&m_unk404)->Add(node);
    m_unk1C0 |= 8;
}

// FUNCTION: 0x144D10 DeleteMeshLayer__9InterfaceFP6PMNode
void Interface::DeleteMeshLayer(PMNode *node) {
    if (node != 0) {
        node->Slot00(1);
    }
    ((PArray *)((char *)this + 0x404))->Remove(node);
}

// DRAFT: 0x144D60 DeleteMeshLayer__9InterfaceFv
// note: 25 differing words; frame (0x20) and s0-only saves match; original has a nop after the Slot00 jalr and reloads m_unk408 for the list index (ours keeps idx in a1), so the loop skip is 0x17 vs ours 0x15. Tried NULL->0, if/else on first list read, m_unk408 header field (37 -> 31 -> 25), if/else in loop tail (27), m_unk408 index in tail (27); last two reverted.
void Interface::DeleteMeshLayer() {
    PMNode *node;
    unsigned int idx;
    m_unk408 = 0;
    if (m_unk404 != 0) {
        node = (PMNode *)(*(void ***)((char *)this + 0x40C))[0];
    } else {
        node = 0;
    }
    if (node != 0) {
        do {
            if (node != 0) {
                node->Slot00(1);
            }
            idx = m_unk408 + 1;
            m_unk408 = idx;
            node = 0;
            if (idx < (unsigned int)m_unk404) {
                node = (PMNode *)(*(void ***)((char *)this + 0x40C))[idx];
            }
        } while (node != 0);
    }
    if (*(void ***)((char *)this + 0x40C) != 0) {
        m_unk404 = 0;
        m_unk408 = 0;
    }
}

// DRAFT: 0x00144E20 Destroy__9InterfaceFv
// note: 60 words differ, original frame 0x30 keeps this in s1 with field slots in s0 (addiu s0,s1,0x1C4/0x1C8); ours keeps this in s0 and folds the offsets; tried slot pointers, hoisted slot, declaration reorder, self local (6 attempts)
void Interface::Destroy() {
    Interface *self;
    PMNode **slot;
    PMNode *node;
    void **obj;
    void ***objSlot;
    self = this;
    slot = (PMNode **)((char *)self + 0x1C4);
    node = *(PMNode **)((char *)self + 0x1C4);
    if (node != 0) {
        node->ProcessFxTriggers(-1.0f, 0, true, false);
        node = *slot;
        if (node != 0) {
            node->Slot00(1);
        }
        *slot = 0;
        ((PVirtObj *)((char *)this + 0x22C))->Slot01();
        ((PVirtObj *)((char *)this + 0x290))->Slot01();
        ((PTextureManager *)((char *)gGfxEng + 0x154C90))->UnloadDynamicTextures((eTextureGroup)0x6A);
    }
    objSlot = (void ***)((char *)self + 0x1C8);
    obj = *(void ***)((char *)self + 0x1C8);
    if (obj != 0) {
        if (obj != 0) {
            ((PMNode *)obj)->Slot00(1);
        }
        *objSlot = 0;
    }
    *(signed char *)((char *)this + 0x2F8) = 1;
    *(signed char *)((char *)this + 0x3E4) = 0;
    m_unk1C0 = 1;
    DeleteMeshLayer();
    ((FontManager *)((char *)this + 0x80))->RemoveAll(true);
    *(short *)((char *)this + 0x414) = 0;
    *(short *)((char *)this + 0x416) = 0;
}

// FUNCTION: 0x00144F10 Load__9InterfaceFPCc
PMNode *Interface::Load(const char *arg0) {
    m_unk1C0 |= 4;
    *(short *)((char *)this + 0x414) = 0;
    *(short *)((char *)this + 0x416) = 0;
    if (strcasecmp(arg0, mName) == 0) {
        return (PMNode *)m_unk1C4;
    }
    if (m_unk1C4 != 0) {
        delete (PDeletable *)m_unk1C4;
        m_unk1C4 = 0;
        ((PVirtObj *)((char *)this + 0x2E8))->Slot01();
        ((PVirtObj *)((char *)this + 0x22C))->Slot01();
        ((PVirtObj *)((char *)this + 0x290))->Slot01();
        ((PTextureManager *)(gGfxEng + 0x154C90))->UnloadDynamicTextures((eTextureGroup)0x6A);
    }
    if (m_unk1C8 != 0) {
        delete (PDeletable *)m_unk1C8;
        m_unk1C8 = 0;
    }
    if (strlen(arg0) >= 0x20U) {
        CdsAssert__FPciPc("Interface.cpp", 0x1AD, "strlen(pName) < sizeof(mName)");
    }
    strcpy(mName, arg0);
    SoundGainEEControl();
    m_unk1C4 = Load__6PWorldFPCcb13eTextureGroup(gEng, arg0, false, (eTextureGroup)0x6A);
    if (m_unk1C4 == 0) {
        printf("%s Load Error\n", arg0);
        CdsAssert__FPciPc("Interface.cpp", 0x1B4, "0");
    }
    RemoveNullAnimation__6PMNodeFv((PMNode *)m_unk1C4);
    ((PMNode *)m_unk1C4)->SetAllFrustrumTest((eBoxIntersect)1);
    scePcStart(0x8008003E, 0, 0);
    scePcStop();
    *(float *)(gEng + 0x1E8) = 1.0f;
    return (PMNode *)m_unk1C4;
}

// DRAFT: 0x001450D0 ProcessScreenFade__9InterfaceFv
// note: 2 words differ, mul.s operand order and c.eq.s operand order; tried swapped mul operands, read-modify-write form, local temp (4), and both branch forms
void Interface::ProcessScreenFade() {
    if (*(unsigned char *)&m_unk425 != 0) {
        *(float *)&m_unk41C += *(float *)(gEng + 0x1E8) * *(float *)&m_unk418;
        if (((*(float *)&m_unk418 < 0.0f) && (*(float *)&m_unk41C <= *(float *)&m_unk420)) ||
            (!(*(float *)&m_unk418 <= 0.0f) && !(*(float *)&m_unk41C < *(float *)&m_unk420))) {
            *(float *)&m_unk41C = *(float *)&m_unk420;
            m_unk425 = 0;
        }
        DisplayFadeRectangle();
        return;
    }
    if (*(float *)&m_unk41C != 0.0f) {
        DisplayFadeRectangle();
    }
}

// DRAFT: 0x001451B0 DisplayFadeRectangle__9InterfaceFv
// note: 42 words; gs store order and branch shape differ, gGfxEng+0x154C80 load scheduled earlier; size 0xf8 vs 0xe8. Tried gs initializer (56), (int) alpha cast (54), per-use table index (54).
void Interface::DisplayFadeRectangle() {
    static char vFadeRGB[2][3] = {{0, 0, 0}, {-128, -128, -128}};
    unsigned long long gs[6];
    gs[2] = 0;
    gs[3] = 0x1A;
    gs[4] = 0x48;
    gs[5] = 0x1B;
    if (m_unk426 != 0) {
        gs[0] = 0x48;
        gs[1] = 0x42;
    } else {
        gs[0] = 0x44;
        gs[1] = 0x42;
    }
    PDisplayList *pd = *(PDisplayList **)(gGfxEng + 0x154C80);
    pd->SetGsRegisters((u_long128 *)gs, 3);
    pd = *(PDisplayList **)(gGfxEng + 0x154C80);
    char *rgb = vFadeRGB[m_unk426];
    pd->ClearFrameBuffer(0x800, 0x800, 0x800, 0x800, rgb[0], rgb[1],
                         rgb[2], (char)(int)*(float *)&m_unk41C, 0x3F800000);
}

// DRAFT: 0x1452A0 FadeScreen__9InterfaceFffbQ29Interface10eFadeColor
// note: 1 differing line, c.eq.s operand order (orig $f20,$f0 vs ours $f0,$f20); tried 0.0f!=v, arg1!=0, inverted ==0 layout (18 diffs), !(v==0).
void Interface::FadeScreen(float arg0, float arg1, bool arg2, eFadeColor arg3) {
    float var_f20 = arg1;
    if ((int)arg3 >= 2) {
        CdsAssert__FPciPc("Interface.cpp", 0x14E, "eColor < FADE_COLOR_MAX");
    }
    m_unk426 = (signed char)arg3;
    m_unk424 = arg2;
    if (!(var_f20 == 0.0f)) {
        m_unk425 = 1;
        *(float *)&m_unk420 = arg0;
        if (arg0 < *(float *)&m_unk41C) {
            var_f20 = -var_f20;
        }
        *(float *)&m_unk418 = var_f20;
        return;
    }
    m_unk425 = 0;
    *(float *)&m_unk41C = arg0;
    DisplayFadeRectangle();
    *(float *)&m_unk418 = arg0;
}

// FUNCTION: 0x145370 InitScreenFadeVars__9InterfaceFv
void Interface::InitScreenFadeVars() {
    m_unk425 = 0;
    m_unk418 = 0;
    m_unk41C = 0x43000000;
    m_unk420 = 0x43000000;
    m_unk426 = 0;
    m_unk424 = 1;
}

// DRAFT: 0x1453A0 IsTreasureOK__9InterfaceFv
// note: 11 words differ; original shares one false exit and keeps the 0x80 test as bnez, compiler emits beqz/sltu/xori. Tried bool, int, result-var, nested-guard and inverted-test layouts.
int Interface::IsTreasureOK() {
    if (m_unk2F7 != 0) {
        return 0;
    }
    if (m_unk1B8 != 0) {
        return 1;
    }
    if (m_unk80 == 0) {
        return 1;
    }
    return 0;
}

// FUNCTION: 0x1453E0 DisplayLevelName__9InterfaceFii
void Interface::DisplayLevelName(int arg0, int arg1) {
    if (m_unk1B8 != 0) {
        ((FontManager *)((char *)this + 0x80))->RemoveText((FontNode *)m_unk1B8);
        m_unk1B8 = 0;
    }
    if (arg0 >= 0) {
        m_unk1B8 = ((FontManager *)((char *)this + 0x80))->DisplayString(arg0 + 0x270, arg1, 0, false);
        m_unk1BC = arg1;
    }
}

// FUNCTION: 0x145820 InitRender__9InterfaceFv
void Interface::InitRender() {
    float v[4];
    sceVu0CopyVector(v, (float *)((char *)this + 0x70));
    sceVu0ScaleVectorXYZ(v, v, -1.0f);
    RenderBlendedFragments__10PGfxEngineFPf(gGfxEng, v);
    vu1ZBufferUpdate__Fb(true);
    vu1ClearZBuffer__Fv();
    vu1SetScreenMatrix__FP5PMat4(this);
    vu1SetViewMatrix__FP5PMat4((char *)this + 0x40);
    vu1SetClipMatrix__FP5PMat4(gEng + 0x50);
    gGfxEng[0x158E22] = 0;
}

// FUNCTION: 0x1458B0 InitMatrices__9InterfaceFv
void Interface::InitMatrices() {
    if (MODE_PAL != 0) {
        float h = (float)SCREEN_HEIGHT;
        float f2 = 9.75f * (h / 224.0f);
        float w = (float)SCREEN_WIDTH;
        MakeParallelProjectionMatrix__5PMat4Fffffffffffff(this, 2048.0f, 2048.0f, w, h, 100.0f, 16777215.0f, (float)-SCREEN_WIDTH / 19.5f, w / 19.5f, h / f2, -h / f2, -100.0f, 100.0f);
    } else {
        *(int *)((char *)this + 0x00) = 0x411C0000;
        *(int *)((char *)this + 0x14) = 0x409C0000;
        *(int *)((char *)this + 0x28) = 0xC7A3D6C9;
        *(int *)((char *)this + 0x30) = 0x45000000;
        *(int *)((char *)this + 0x34) = 0x45000000;
        *(int *)((char *)this + 0x38) = 0x4B000031;
    }
    *(int *)((char *)this + 0x54) = 0xBF733333;
    *(int *)((char *)this + 0x68) = 0xBF800000;
    *(int *)((char *)this + 0x78) = 0x4210CCCD;
}

// FUNCTION: 0x1459D0 Init__9InterfaceFv
void Interface::Init() {
    ((FontManager *)((char *)this + 0x80))->Init();
    ((PArray *)((char *)this + 0x404))->Allocate(8);
    InitMatrices();
}

// DRAFT: 0x145CA0 __ct__9InterfaceFv
// note: DIFF 99 words; frame and this spill now match via InterfaceSpillGuard, but the six vtable lui/addiu pairs are scheduled and register-assigned differently (original keeps this in t0 for the first stores) and each store reloads this. Tried: spill guard member (100 -> 99).
Interface::Interface() {
    sceVu0UnitMatrix(this);
    sceVu0UnitMatrix((char *)this + 0x40);
    __ct__11FontManagerFv((char *)this + 0x80);
    m_unk1CC = __vt__7GameHud;
    *(int *)((char *)this + 0x1D0) = 0;
    m_unk1CC = __vt__9HudHealth;
    m_unk1DC = __vt__7GameHud;
    *(int *)((char *)this + 0x1E0) = 0;
    m_unk1DC = __vt__8HudSuper;
    m_unk1EC = __vt__7GameHud;
    *(int *)((char *)this + 0x1F0) = 0;
    m_unk1FC = __vt__7GameHud;
    *(int *)((char *)this + 0x200) = 0;
    m_unk20C = __vt__7GameHud;
    *(int *)((char *)this + 0x210) = 0;
    m_unk21C = __vt__7GameHud;
    *(int *)((char *)this + 0x220) = 0;
    m_unk22C = __vt__7GameHud;
    *(int *)((char *)this + 0x230) = 0;
    m_unk22C = __vt__7HudGrim;
    *(int *)((char *)this + 0x24C) = 0;
    *(int *)((char *)this + 0x230) = 0;
    m_unk250 = __vt__7GameHud;
    *(int *)((char *)this + 0x254) = 0;
    m_unk250 = __vt__12HudBossMeter;
    m_unk270 = __vt__7GameHud;
    *(int *)((char *)this + 0x274) = 0;
    m_unk270 = __vt__12HudBossMeter;
    m_unk290 = __vt__7GameHud;
    *(int *)((char *)this + 0x294) = 0;
    m_unk290 = __vt__8HudCombo;
    __ct__12HudInventoryFv((char *)this + 0x2E8);
    __ct__6PArrayFv((char *)this + 0x404);
    m_unk1C4 = 0;
    m_unk1C8 = 0;
    *(int *)((char *)this + 0x428) = 0;
    m_unk1B8 = 0;
    m_unk1BC = 0;
    m_unk1C0 = 9;
    mName[0] = 0;
    m_unk414 = 0;
    m_unk416 = 0;
    InitScreenFadeVars();
    m_unk427 = 0;
    *(int *)((char *)this + 0x42C) = 0;
    *(int *)((char *)this + 0xA50) = 0;
}

// FUNCTION: 0x145E40 __dt__12HudInventoryFv
extern "C" HudInventory *__dt__12HudInventoryFv(HudInventory *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__12HudInventory;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x145EC0 __dt__8HudComboFv
extern "C" HudCombo *__dt__8HudComboFv(HudCombo *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__8HudCombo;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x145F40 __dt__12HudBossMeterFv
extern "C" HudBossMeter *__dt__12HudBossMeterFv(HudBossMeter *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__12HudBossMeter;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x145FC0 __dt__8HudSuperFv
extern "C" HudSuper *__dt__8HudSuperFv(HudSuper *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__8HudSuper;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x146040 __dt__9HudHealthFv
extern "C" HudHealth *__dt__9HudHealthFv(HudHealth *pThis, short nFlag) {
    if (pThis != 0) {
        *(unsigned char **)pThis = __vt__9HudHealth;
        if (pThis != 0) {
            *(unsigned char **)pThis = __vt__7GameHud;
            ((PVirtObj *)pThis)->Slot01();
        }
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}
