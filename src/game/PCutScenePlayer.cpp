#include "types.h"
#include "PCutScenePlayer.h"

// TODO(header): foreign declarations
class PMat4;
class PMeshNode;
class PMNode {
public:
    void ProcessFxTriggers(float fTime, PMat4 *pMat, bool bA, bool bB);
};
class PArray {
public:
    void Remove(void *pItem);
};
class PGrimReaperCape {
public:
    void Enable(bool bFlag, PMNode *pNode);
};
class Player {
public:
    void FinishCutScene(PMeshNode *pNode, PMat4 *pMat, int nFlag);
};
class FontManager {
public:
    void RemoveAll(bool bFlag);
};

extern unsigned char gInterface[];
extern unsigned char gGfxEng[];
extern "C" void __dt__6PArrayFv(void *pThis, short nFlag);
extern "C" void __dt__15PGrimReaperCapeFv(void *pThis, short nFlag);

// DRAFT: 0x001BBBA0 KillActorFx__15PCutScenePlayerFv
// note: 33 differing lines; the diff starts at the prologue loop guard (original uses sltu $at,$zero,$s0 with a branch over the loop, ours tests the count directly) and the saved s1 register differs.
void PCutScenePlayer::KillActorFx() {
    unsigned int n = m_unkB0;
    for (unsigned int i = 0; i < n; i++) {
        void *pItem = (i < m_unkB0) ? m_unkB8[i] : 0;
        if (pItem != 0) {
            PMNode *pNode = *(PMNode **)((char *)pItem + 0x30);
            if (pNode != 0) {
                pNode->ProcessFxTriggers(-1.0f, 0, true, false);
            }
        }
    }
}

// FUNCTION: 0x001BC890 Abort__15PCutScenePlayerFv
void PCutScenePlayer::Abort() {
    SetBgNodesOpacity((PArray *)m_unk80, 0.0f);
    SetBgNodesOpacity((PArray *)m_unk70, 1.0f);
    KillActorFx();
    ((FontManager *)(gInterface + 0x1790))->RemoveAll(true);
    if ((m_unk213D & 1) != 0) {
        Unload(true);
    } else {
        UpdatePlayer();
    }
    m_unk213C = 0;
    ((PGrimReaperCape *)m_unk100)->Enable(false, 0);
    *(unsigned char *)(gGfxEng + 0x158E26) = 1;
}

// FUNCTION: 0x001BC940 ResetCutScene__15PCutScenePlayerFv
void PCutScenePlayer::ResetCutScene() {
    SetBgNodesOpacity((PArray *)m_unk60, 1.0f);
    SetBgNodesOpacity((PArray *)m_unk80, 1.0f);
    SetBgNodesOpacity((PArray *)m_unk90, 0.0f);
    SetBgNodesOpacity((PArray *)m_unk70, 0.0f);
    m_unk5C = m_unk2130;
    m_unk213C = 0;
    ((PGrimReaperCape *)m_unk100)->Enable(false, 0);
}

// DRAFT: 0x001BD270 UpdatePlayer__15PCutScenePlayerFv
// note: 9 differing lines; the loop matches, but the original has one extra nop before the RemoveAll call, which shifts the tail by one instruction. Tried: void* and char* element pointer, node local, for(;;) top test, guarded do-while (kept), index local, direct m_unkB4 increment (16 lines, reverted).
void PCutScenePlayer::UpdatePlayer() {
    char *pElem;
    m_unkB4 = 0;
    pElem = (m_unkB0 != 0) ? (char *)m_unkB8[0] : 0;
    if (pElem != 0) {
        do {
            if (*(Player **)(pElem + 0x38) != 0) {
                ((Player *)*(void **)(pElem + 0x38))->FinishCutScene(*(PMeshNode **)(pElem + 0x30), (PMat4 *)this, m_unk213D & 2);
                ((PArray *)(*(char **)(pElem + 0x30) + 0x14))->Remove(*(void **)(pElem + 0x34));
                break;
            }
            unsigned int nIdx = m_unkB4 + 1;
            m_unkB4 = nIdx;
            pElem = (nIdx < m_unkB0) ? (char *)m_unkB8[m_unkB4] : 0;
        } while (pElem != 0);
    }
    ((FontManager *)(gInterface + 0x1790))->RemoveAll(true);
}

// FUNCTION: 0x001BDBD0 __dt__15PCutScenePlayerFv
PCutScenePlayer::~PCutScenePlayer() {
    Unload(true);
    __dt__15PGrimReaperCapeFv((char *)this + 0x100, -1);
    __dt__6PArrayFv((char *)this + 0xB0, -1);
    __dt__6PArrayFv((char *)this + 0xA0, -1);
    __dt__6PArrayFv((char *)this + 0x90, -1);
    __dt__6PArrayFv((char *)this + 0x80, -1);
    __dt__6PArrayFv((char *)this + 0x70, -1);
    __dt__6PArrayFv((char *)this + 0x60, -1);
}
