// FLAGS: -str readonly
#pragma opt_strength_reduction off
#include "types.h"
#include "Debug.h"
#include "PMNode.h"
#include "PLightManager.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" int Render__18PObjectDisplayListF13eBoxIntersect(PObjectDisplayList *, eBoxIntersect);
extern "C" void vu1BeginMesh__F13eBoxIntersect(eBoxIntersect);
extern "C" void vu1EndMesh__Fv(void);
extern "C" void vu1SetWorldMatrix__FP5PMat4(PMat4 *);
extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
extern "C" void sceVu0CopyVector(float *dst, float *src);
extern "C" void sceVu0SubVector(float *, float *, float *);
extern "C" float mvTrans__6PMNode[4];
extern "C" void __dt__5PMeshFv(void *, short);
extern "C" void SetSTAnimOptions__5PMeshFb(void *, bool);
extern "C" void *__nw__FUi(unsigned int);
extern "C" void __dl__FPv(void *);
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void sceVu0UnitMatrix(float (*)[4]);
extern "C" void AddVectorXYZ__FPfPf(float *, float *);
extern "C" void FastMath_ComputeMatrix__FPA4_A4_fPA4_fPA4_fPA4_fPA4_fPA4_fPA4_A4_f(float (*)[4][4], float *, float *, float *, float *, float *, float (*)[4][4]);
// TODO(header): tagParticleFxTrigger layout as ClockworkReaper.cpp names it; only the word at 0x20 (the PParticleSystem pointer) is used here.
struct tagParticleFxTrigger {
    unsigned int m_unk00;
    unsigned int m_unk04;
    unsigned int m_unk08;
    unsigned int m_unk0C;
    unsigned int m_unk10;
    unsigned int m_unk14;
    unsigned int m_unk18;
    unsigned int m_unk1C;
    unsigned int m_unk20;
    unsigned int m_unk24;
};
extern "C" PObjectDisplayList *__ct__18PObjectDisplayListFv(PObjectDisplayList *);
extern "C" void __dt__18PObjectDisplayListFv(PObjectDisplayList *, short);
extern "C" void *__dt__6PArrayFv(void *pThis, short nFlag);
// TODO(header): PArray::Find is not declared in PArray.h; same declaration as Peddler.cpp.
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" char __vt__9PResource[];
extern "C" int Create__18PObjectDisplayListFP6PMNodePb(PObjectDisplayList *, PMNode *, bool *);
extern "C" void sceVu0CopyMatrix(float (*)[4], float (*)[4]);
extern "C" void *__ct__6PArrayFv(void *);
extern "C" void *__ct__9PMeshNodeFR9PMeshNode(void *, void *);
extern "C" char __vt__6PMNode[];
extern "C" void Allocate__6PArrayFUi(void *, unsigned int);
extern "C" void Add__6PArrayFPv(void *, void *);
// TODO(header): PAnimFrame is the 0x34-byte frame object held at PMNode+0x24; only its vtable slots 0x0C and 0x10 are named here.
class PAnimFrame {
public:
    virtual ~PAnimFrame();
    virtual void Slot01();
    virtual int LoadHeader(void *pFile, void *pHeader);
    virtual void Slot03();
    virtual signed char IsAnimate();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual float GetFrameRate();
    char _pad04[0x22];
    short m_unk26;
    short m_unk28;
};
extern "C" PAnimFrame *__ct__10PAnimFrameFP5PAnim(PAnimFrame *, PAnim *);
extern "C" PAnimFrame *__ct__10PAnimFrameFs(PAnimFrame *, short);
extern "C" PAnim *__ct__5PAnimFv(PAnim *);
class PMat4;
class PDisplayList {
public:
    void AddMatrix(PMat4 *pMat, unsigned int uIdx);
};
// TODO(header): gGfxEng is a PDisplayList pointer. The original reaches it with lui/lw, which needs a placeholder larger than 8 bytes.
struct PGfxEngineRef {
    PDisplayList *pDisplayList;
    char _pad04[0x10];
};
extern PGfxEngineRef gGfxEng;
// PGfxEngine methods used by DebugDrawBox; gGfxEng is passed as (PGfxEngine *)&gGfxEng.
class PGfxEngine {
public:
    void BeginDebugRender();
    void DrawBox(float (*pBox)[2][4], float fA, float fB, float fC);
    void EndDebugRender();
};
// TODO(header): PParticleManager and PParticleSystem belong to the particle headers; only IsValid is called here.
// Virtual slots only: the destructor is slot 0 (0x08), Enable is slot 9 (0x2C). Slots 1..8 are placeholders that keep Enable at its offset.
class PParticleSystem {
public:
    virtual ~PParticleSystem();
    virtual void Slot1();
    virtual void Slot2();
    virtual void Slot3(PMat4 *pMat);
    virtual void Slot4();
    virtual void Slot5(bool bFlag);
    virtual void Slot6();
    virtual void Slot7();
    virtual void Slot8();
    virtual void Enable(bool bFlag);
    char _pad04[0x11];
    unsigned char m_unk15;
};
class PParticleManager {
public:
    int IsValid(PParticleSystem *pSystem);
    PParticleSystem *Create(unsigned int uID, float fA, float fB, float fC, PMNode *pNode, bool bFlag);
    void Stop(unsigned int uID);
    void Destroy(unsigned int uID);
};
// PSound size is unknown; the placeholder member only keeps gSound out of small data (threshold 8 bytes).
class PSound {
public:
    int IsAmbientSoundByID(unsigned int nID);
    int IsObjectPlayingAmbientByID(unsigned int p0, unsigned int p1, unsigned int p2);
    int PlaySoundPMNode(unsigned int p0, unsigned int p1, const PMNode *pNode);
    void StopAmbientSoundsByOriginatorRef(unsigned int p0, unsigned int p1);
    void StopSoundsByOriginatorRef(unsigned int p0, unsigned int p1, unsigned int p2);
    void StopSoundBySoundRefIfAmbient(unsigned int uID);
    void StopSoundBySoundRef(unsigned int uID);
    char _pad000[0x10];
};
extern PSound gSound;
// TODO(header): mst_NextPMNodeRef__6PMNode is a static PMNode counter; a 4-byte int keeps it gp-relative as the original does.
extern "C" int mst_NextPMNodeRef__6PMNode;
class PPakFile;
// TODO(header): PCDFile is a foreign class; only Read is needed here.
class PCDFile {
public:
    int Read(void *pBuf, unsigned int size);
};

class AnimData;
#include "PArray.h"

// TODO(header): PAnim, PChannel and eAnimType belong to the animation headers. Placeholder shapes; only the names, the FindChannel/AnimateBox signatures and the byte at PAnim+0xA matter here.
enum eAnimType { eAnimType_Placeholder = 0 };
class PChannel {
public:
    void *AnimateBox(float fTime, unsigned char &bOut);
    void EvaluateAnim(float fTime, float *pOut, int nA, float fB);
};
class PAnim {
public:
    PChannel *FindChannel(eAnimType eType);
    float Animate(float fTime, float fUnused, float (*pMatrix)[4], float *pOut, bool bFlag);
    char _pad000[0x8];
    short m_unk8;
    unsigned char m_unkA;
};

// TODO(header): PMNode objects carry a vptr at offset 0; this view names the slots SetFrameTime calls on a child.
class PNodeVirtual {
public:
    virtual void Slot00();
    virtual void Slot01();
    virtual void Slot02(float fTime);
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05(AnimData *pAnim);
};

// Object held at PMNode+0x24. Slot 18 (0x48) is the frame-rate query; slots 0..17 are unknown.
class PFrameSource {
public:
    virtual ~PFrameSource();   // two slots in CodeWarrior (complete and deleting)
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(AnimData *pAnim);
    virtual void Slot11(int nCount);
    virtual float Slot12();
    virtual void Slot13();
    virtual void Slot14(int nArg);
    virtual void Slot15();
    virtual void Slot16(float fRate);
    virtual float GetFrameRate();
    int m_unk04;            // 0x04 state; 0x3E8 and 1 are excluded from CheckAnimated
    char _pad08[2];
    unsigned char m_unk0A;  // 0x0A nonzero keeps the object alive in RemoveNullAnimation
};

// Same vtable as PFrameSource. Slot13 (0x38) takes an int at the RecurseSetLoopRateByID call site, and no argument at RecurseSetAnimFlagsByID.
class PFrameSourceArgView {
public:
    virtual ~PFrameSourceArgView();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(AnimData *pAnim);
    virtual void Slot11(int nCount);
    virtual float Slot12();
    virtual void Slot13(int nArg);
};

// Same vtable as PFrameSource. Slot06 (0x1C) takes a float at the RecurseResetAnimByID call site, and no argument at SetFrameTime.
class PFrameSourceFloatView {
public:
    virtual ~PFrameSourceFloatView();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06(float fArg);
};

// Same vtable as PFrameSource. Slot13 (0x38) takes a bool at the RecurseApplyAnimFlagsByID call site; passing it as int adds an andi.
class PFrameSourceBoolView {
public:
    virtual ~PFrameSourceBoolView();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10(AnimData *pAnim);
    virtual void Slot11(int nCount);
    virtual float Slot12();
    virtual void Slot13(bool bArg);
};

// Object held at PMNode+0x24 for the animation loop path. Vtable slots 0x1C, 0x24, 0x30, 0x38 and 0x3C match PAnim (tools/vtable.py PAnim); 0x08 holds the destructor.
class PAnimView {
public:
    virtual ~PAnimView();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void SetFrameTime(float fTime);
    virtual void Slot07();
    virtual void SetEndFrame(short sFrame);
    virtual void Slot09();
    virtual void Slot10();
    virtual void SetAnimLoopCount(int nCount);
    virtual void Slot12();
    virtual void EnableAnim(bool bFlag);
    virtual void SetLoopFrame(short sFrame);
    int m_unk04;            // 0x04 anim id compared with uID
    short m_unk08;          // 0x08 end frame; loop path runs only when positive
};

// FUNCTION: 0x001917D0 StopSoundBySoundRefIfAmbient__6PMNodeFUi
void PMNode::StopSoundBySoundRefIfAmbient(unsigned int value) {
    gSound.StopSoundBySoundRefIfAmbient(value);
}

// FUNCTION: 0x001917E0 StopAmbientSoundsByObject__6PMNodeFv
void PMNode::StopAmbientSoundsByObject() {
    m_unkF4 = 0;
    gSound.StopAmbientSoundsByOriginatorRef(m_unkE8, 0x20U);
}

// FUNCTION: 0x00191800 StopAllSoundsByObject__6PMNodeFv
void PMNode::StopAllSoundsByObject() {
    gSound.StopSoundsByOriginatorRef(m_unkE8, 0x20U, 3U);
}

// FUNCTION: 0x00191820 StopSoundBySoundRef__6PMNodeFUi
void PMNode::StopSoundBySoundRef(unsigned int value) {
    gSound.StopSoundBySoundRef(value);
}

// FUNCTION: 0x00191830 PlaySound__6PMNodeFUi
int PMNode::PlaySound(unsigned int arg0) {
    int var_s0 = 0;
    int var_s1 = 1;
    if (gSound.IsAmbientSoundByID(arg0) != 0) {
        var_s0 = 1;
        m_unkF4 = 1;
        if (gSound.IsObjectPlayingAmbientByID(arg0, m_unkE8, 0x20) != 0) {
            var_s1 = 0;
        }
    }
    if (var_s1 != 0) {
        m_unkEC = gSound.PlaySoundPMNode(arg0, m_unkE8, this);
        if (var_s0 != 0) {
            m_unkF0 = m_unkEC;
        }
    } else {
        m_unkEC = 0;
    }
    return m_unkEC;
}

// FUNCTION: 0x001918F0 UpdateCameraFade__6PMNodeFb
void PMNode::UpdateCameraFade(bool bFlag) {
    if (bFlag) {
        m_unk3E |= 0x20;
    } else {
        void *pObj = m_unk24;
        int nVal = (pObj != 0) ? ((int *)pObj)[1] : 0;
        if ((unsigned int)(nVal - 500) < 10) {
            bFlag = true;
            m_unk3E |= 0x20;
        }
    }
    m_unk18 = 0;
    PMNode *pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->UpdateCameraFade(bFlag);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x001919E0 CreateObjectDisplayList__6PMNodeFv
int PMNode::CreateObjectDisplayList() {
    PObjectDisplayList *p = m_pObjDisplayList;
    if (p != 0) {
        __dt__18PObjectDisplayListFv(p, 1);
        m_pObjDisplayList = 0;
    }
    p = (PObjectDisplayList *)__nw__FUi(0x1F0);
    if (p != 0) {
        p = __ct__18PObjectDisplayListFv(p);
    }
    m_pObjDisplayList = p;
    if (m_pObjDisplayList == 0) {
        CdsAssert("PMNode.cpp", 0x99E, "mpObjDisplayList");
    }
    if (Create__18PObjectDisplayListFP6PMNodePb(m_pObjDisplayList, this, &m_unkD4) == 0) {
        __dt__18PObjectDisplayListFv(m_pObjDisplayList, 1);
        m_pObjDisplayList = 0;
        return 0;
    }
    return 1;
}

// DRAFT: 0x00191A90 DebugDrawBox__6PMNodeFi
// note: DIFF 68 words; original keeps this in a0 and reloads m_unk04 into a1, zero-inits sit after the bFlags test; tried 3/2 order, zero-init placement, pBox placement.
void PMNode::DebugDrawBox(int nMode) {
    float (*pBox)[2][4];
    unsigned char bFlags;
    int nA;
    int nB;
    int nC;
    if (nMode == 3 || nMode == 2) {
        if (m_unk04 == 2 || m_unk04 == 1) {
            pBox = &m_unk110;
            bFlags = 0x20;
        } else {
            return;
        }
    } else if (nMode == 1) {
        pBox = (float (*)[2][4])m_unk28;
        bFlags = m_unk3C;
    } else {
        return;
    }
    if (bFlags == 0) {
        return;
    }
    nA = 0;
    nB = 0;
    nC = 0;
    unsigned int uMask = bFlags & 0xE0;
    if (uMask == 0x40) {
        nC = 0x80;
        nB = 0x80;
    } else if (uMask == 0x80) {
        nA = 0x80;
    } else if (uMask == 0x20) {
        nB = 0x80;
    } else {
        return;
    }
    ((PGfxEngine *)&gGfxEng)->BeginDebugRender();
    ((PGfxEngine *)&gGfxEng)->DrawBox(pBox, (float)nA, (float)nB, (float)nC);
    ((PGfxEngine *)&gGfxEng)->EndDebugRender();
}

// DRAFT: 0x00191BD0 Render__6PMNodeFP13PLightManagerii
// note: DIFF 106. Early beqz a1 targets +0x75 in orig (shared return-0 block), +0xA in ours; m_unk3F lb/andi test and nArg2==0x80 check order differ; 0x178 reloc is vu1EndMesh__Fv, orig DebugDrawBox__6PMNodeFi. Tried: separate early returns (112), flat returns (112), nested body (106), local pMesh (139), pre-increment loop tail (106, neutral).
int PMNode::Render(PLightManager *pLM, int nArg1, int nArg2) {
    int nResult = 0;
    if (m_unk0C != 0) {
        nArg1 = (int)((float)nArg1 * m_unk2C);
        if (nArg1 != 0) {
            if (m_pObjDisplayList != 0 && nArg1 == 0x80 && !(m_unk3F & 0x10) && nArg2 == 0) {
                nResult += Render__18PObjectDisplayListF13eBoxIntersect(m_pObjDisplayList, (eBoxIntersect)m_unk0C);
                return nResult;
            }
            if (m_unk10 != 0) {
                if (pLM != 0) {
                    pLM->ComputeLights((PMesh *)m_unk10, (PMat4 *)m_unk40, true, true, true, 0, 1.0f);
                }
                vu1SetWorldMatrix__FP5PMat4((PMat4 *)m_unk40);
                vu1BeginMesh__F13eBoxIntersect((eBoxIntersect)m_unk0C);
                if (m_unk3E & 0x80) {
                    nResult += ((PMesh *)m_unk10)->Render(nArg1, (bool *)&m_unkD4, false);
                } else {
                    nResult += ((PMesh *)m_unk10)->Render(nArg1, 0, false);
                }
                if (nArg2 != 0) {
                    DebugDrawBox(nArg2);
                }
                vu1EndMesh__Fv();
            } else if (nArg2 == 3) {
                vu1BeginMesh__F13eBoxIntersect((eBoxIntersect)m_unk0C);
                vu1SetWorldMatrix__FP5PMat4((PMat4 *)m_unk40);
                DebugDrawBox(nArg2);
                vu1EndMesh__Fv();
            }
            m_unk18 = 0;
            PMNode *pChild = (m_unk14 != 0) ? m_unk1C[0] : 0;
            while (pChild != 0) {
                nResult += pChild->Render(pLM, nArg1, nArg2);
                m_unk18++;
                pChild = (m_unk18 < m_unk14) ? m_unk1C[m_unk18] : 0;
            }
            return nResult;
        }
    }
    return 0;
}

// DRAFT: 0x00191E00 ProcessFxTriggers__6PMNodeFfP5PMat4bb
// note: size 0x6d4 vs 0x71c, frame 0xC0 vs 0xD0; original asserts on a constant address (s4), not pMgr; 424 words differ; ternary assert form tried, same count.
void PMNode::ProcessFxTriggers(float fTime, PMat4 *pMat, bool bA, bool bB) {
    PParticleManager *pMgr = (PParticleManager *)((char *)&gGfxEng + 0x154F00);
    ((pMgr != 0) ? (void)0 : CdsAssert("PMNode.cpp", 0x82D, "apParticleMgr"));
    if (fTime != 0.0f && fTime == m_unk38) {
        if (bB) {
            unsigned int nCount = m_unkD8;
            unsigned int i = 0;
            if (nCount != 0) {
                do {
                    tagParticleFxTrigger *pTrig = (i < m_unkD8) ? m_unkE0[i] : 0;
                    if (pTrig != 0) {
                        PParticleSystem *pSys = (PParticleSystem *)pTrig->m_unk20;
                        if (pMat != 0) {
                            if (pSys != 0 && pMgr->IsValid(pSys) != 0) {
                                pSys->Slot3(pMat);
                            }
                        } else {
                            if (pSys != 0 && pMgr->IsValid(pSys) != 0) {
                                pSys->Slot3((PMat4 *)m_unk40);
                            }
                        }
                    }
                    i++;
                } while (i < nCount);
            }
        }
        if (bA) {
            m_unk18 = 0;
            PMNode *pChild = (m_unk14 != 0) ? m_unk1C[0] : 0;
            if (pChild != 0) {
                do {
                    pChild->ProcessFxTriggers(fTime, pMat, bA, bB);
                    unsigned int uNext = m_unk18 + 1;
                    m_unk18 = uNext;
                    pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
                } while (pChild != 0);
            }
        }
        return;
    }
    unsigned int nCount = m_unkD8;
    unsigned int i = 0;
    if (nCount != 0) {
        do {
            tagParticleFxTrigger *pTrig = (i < m_unkD8) ? m_unkE0[i] : 0;
            if (pTrig != 0) {
                float fStart = *(float *)&pTrig->m_unk10;
                bool bStartHit;
                if (fStart != -2.0f && fStart != -1.0f) {
                    bStartHit = !(fTime < fStart);
                } else {
                    bStartHit = (fTime == fStart);
                }
                if (pMgr->IsValid((PParticleSystem *)pTrig->m_unk20) == 0) {
                    pTrig->m_unk20 = 0;
                }
                PParticleSystem *pSys = (PParticleSystem *)pTrig->m_unk20;
                if (pSys == 0 && bStartHit) {
                    pTrig->m_unk20 = (unsigned int)pMgr->Create(pTrig->m_unk00, *(float *)&pTrig->m_unk04,
                                                                *(float *)&pTrig->m_unk08, *(float *)&pTrig->m_unk0C, this, true);
                    if (pMat != 0) {
                        pSys = (PParticleSystem *)pTrig->m_unk20;
                        if (pSys != 0 && pMgr->IsValid(pSys) != 0) {
                            pSys->Slot3(pMat);
                        }
                    } else {
                        pSys = (PParticleSystem *)pTrig->m_unk20;
                        if (pSys != 0 && pMgr->IsValid(pSys) != 0) {
                            pSys->Slot3((PMat4 *)m_unk40);
                        }
                    }
                    pTrig->m_unk24 &= ~1U;
                    pTrig->m_unk24 &= ~2U;
                } else if (pMat != 0 && pSys != 0 && pMgr->IsValid(pSys) != 0) {
                    pSys->Slot3(pMat);
                }
                float fEnd = *(float *)&pTrig->m_unk14;
                bool bEndHit;
                if (fEnd != -2.0f && fEnd != -1.0f) {
                    bEndHit = !(fTime < fEnd);
                } else {
                    bEndHit = (fTime == fEnd);
                }
                if (bEndHit && !(pTrig->m_unk24 & 1)) {
                    pSys = (PParticleSystem *)pTrig->m_unk20;
                    if (pSys != 0 && pMgr->IsValid(pSys) != 0) {
                        pSys->Slot6();
                    }
                    pTrig->m_unk24 |= 1;
                } else if ((fTime < fEnd) || (fTime == 0.0f && fTime != m_unk38)) {
                    pTrig->m_unk24 &= ~1U;
                }
                float fStop = *(float *)&pTrig->m_unk18;
                bool bStopHit;
                if (fStop != -2.0f && fStop != -1.0f) {
                    bStopHit = !(fTime < fStop);
                } else {
                    bStopHit = (fTime == fStop);
                }
                if (bStopHit && !(pTrig->m_unk24 & 2)) {
                    pMgr->Stop((unsigned int)pTrig->m_unk20);
                    pTrig->m_unk24 |= 2;
                } else if ((fTime < fStop) || (fTime == 0.0f && fTime != m_unk38)) {
                    pTrig->m_unk24 &= ~2U;
                }
                if (fTime == -1.0f) {
                    pMgr->Destroy((unsigned int)pTrig->m_unk20);
                    pTrig->m_unk20 = 0;
                    pTrig->m_unk24 |= 1;
                    pTrig->m_unk24 |= 2;
                }
            }
            i++;
        } while (i < nCount);
    }
    if (bA) {
        m_unk18 = 0;
        PMNode *pChild = (m_unk14 != 0) ? m_unk1C[0] : 0;
        if (pChild != 0) {
            do {
                pChild->ProcessFxTriggers(fTime, pMat, bA, bB);
                unsigned int uNext = m_unk18 + 1;
                m_unk18 = uNext;
                pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
            } while (pChild != 0);
        }
    }
}

// DRAFT: 0x00192520 DestroyFxTriggersBySpawnFrame__6PMNodeFfb
// note: 11 words differ: pTrig/pSystem swap s4/s5 only. Loop now for (unsigned idx = n - 1; (int)idx >= 0; idx--) like SetFxColorMultiplier. Tried: pSystem declared before/after pTrig, function-scope vs loop-scope, nested ifs, if-form pTrig load (68), initialised locals.
void PMNode::DestroyFxTriggersBySpawnFrame(float fFrame, bool bFlag) {
    PParticleManager *pMgr = (PParticleManager *)((char *)&gGfxEng + 0x154F00);
    if (pMgr == 0) {
        CdsAssert("PMNode.cpp", 0x80C, "apParticleMgr");
    }
    tagParticleFxTrigger *pTrig;
    for (unsigned int idx = m_unkD8 - 1; (int)idx >= 0; idx--) {
        pTrig = (idx < m_unkD8) ? m_unkE0[idx] : 0;
        if (pTrig != 0 && *(float *)&pTrig->m_unk10 == fFrame) {
            PParticleSystem *pSystem = (PParticleSystem *)pTrig->m_unk20;
            if (pSystem != 0 && pMgr->IsValid(pSystem) != 0) {
                pSystem->Slot5(false);
            }
            __dl__FPv(pTrig);
            ((PArray *)&m_unkD8)->Remove(pTrig);
        }
    }
    if (bFlag) {
        m_unk18 = 0;
        PMNode *pChild;
        for (pChild = (m_unk14 != 0) ? m_unk1C[0] : 0; pChild != 0; pChild = (++m_unk18 < m_unk14) ? m_unk1C[m_unk18] : 0) {
            pChild->DestroyFxTriggersBySpawnFrame(fFrame, bFlag);
        }
    }
}

// FUNCTION: 0x001926C0 SetFxColorMultiplier__6PMNodeFPfb
void PMNode::SetFxColorMultiplier(float *pColor, bool bFlag) {
    PParticleManager *pMgr = (PParticleManager *)((char *)&gGfxEng + 0x154F00);
    if (pMgr == 0) {
        CdsAssert("PMNode.cpp", 0x7EE, "apParticleMgr");
    }
    tagParticleFxTrigger *pTrig;
    for (unsigned int idx = m_unkD8 - 1; (int)idx >= 0; idx--) {
        pTrig = (idx < m_unkD8) ? m_unkE0[idx] : 0;
        if (pMgr->IsValid((PParticleSystem *)pTrig->m_unk20) != 0) {
            *(char *)(pTrig->m_unk20 + 0x1C) = 0;
            sceVu0CopyVector((float *)(pTrig->m_unk20 + 0xC0), pColor);
        }
    }
    if (bFlag) {
        m_unk18 = 0;
        PMNode *pChild;
        for (pChild = (m_unk14 != 0) ? m_unk1C[0] : 0; pChild != 0; pChild = (++m_unk18 < m_unk14) ? m_unk1C[m_unk18] : 0) {
            pChild->SetFxColorMultiplier(pColor, bFlag);
        }
    }
}

// FUNCTION: 0x00192820 AttachFx__6PMNodeFUiffffb
void *PMNode::AttachFx(unsigned int uID, float fA, float fB, float fC, float fD, bool bFlag) {
    char *pBlk;
    PParticleManager *pMgr = (PParticleManager *)((char *)&gGfxEng + 0x154F00);
    if (pMgr == 0) {
        CdsAssert("PMNode.cpp", 0x7B3, "apParticleMgr");
    }
    if (pMgr->IsValid((PParticleSystem *)uID) != 0) {
        pBlk = (char *)__nw__FUi(0x28);
        if (pBlk == 0) {
            CdsAssert("PMNode.cpp", 0x7B8, "apTrigger");
        }
        *(int *)(pBlk + 0xC) = 0;
        *(int *)(pBlk + 0x8) = 0;
        *(int *)(pBlk + 0x4) = 0;
        *(float *)(pBlk + 0x10) = fA;
        *(float *)(pBlk + 0x14) = fB;
        *(float *)(pBlk + 0x18) = fC;
        *(float *)(pBlk + 0x1C) = fD;
        *(unsigned int *)(pBlk + 0x20) = uID;
        *(int *)(pBlk + 0x0) = 0;
        *(int *)(pBlk + 0x24) = bFlag ? 4 : 0;
        ((PArray *)((char *)this + 0xD8))->Add(pBlk);
        return pBlk;
    }
    return 0;
}

// DRAFT: 0x00192940 EnableFx__6PMNodeFbb
// note: 74 words differ; original keeps pMgr in s0, cnt s1, idx s2, this s5, bA s4, bB s3, pSys s6 and no s7; ours puts pMgr in s7 and strength-reduces the m_unkE0 index (s3). Tried local pMgr (74), idx before cnt (74), in-loop m_unkD8 bound (91, also with local pMgr), pTrig via ?: (82), nested if for pSys (74).
void PMNode::EnableFx(bool bA, bool bB) {
    PParticleManager *pMgr = (PParticleManager *)((char *)&gGfxEng + 0x154F00);
    if (pMgr == 0) {
        CdsAssert("PMNode.cpp", 0x796, "apParticleMgr");
    }
    unsigned int idx = 0;
    unsigned int cnt = m_unkD8;
    if (cnt != 0) {
        idx = 0;
        do {
            tagParticleFxTrigger *pTrig = 0;
            if (idx < cnt) {
                pTrig = m_unkE0[idx];
            }
            if (pTrig != 0) {
                PParticleSystem *pSys = (PParticleSystem *)pTrig->m_unk20;
                if (pSys != 0 && pMgr->IsValid(pSys) != 0) {
                    pSys->Enable(bA);
                }
            }
            idx++;
        } while (idx < cnt);
    }
    if (bB) {
        m_unk18 = 0;
        PMNode *pChild = 0;
        if (m_unk14 != 0) {
            pChild = m_unk1C[0];
        }
        if (pChild != 0) {
            do {
                pChild->EnableFx(bA, bB);
                m_unk18++;
                pChild = 0;
                if (m_unk18 < m_unk14) {
                    pChild = m_unk1C[m_unk18];
                }
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x00192AB0 Enable__15PParticleSystemFb
void PParticleSystem::Enable(bool value) {
    m_unk15 = (unsigned char)value;
}

// DRAFT: 0x00192AC0 DestroyFxTriggers__6PMNodeFbbb
// note: DIFF 96 words; the two pTrig null tests (loop entry and loop head) and the ok ternary layout differ. Tried: pTrig!=0 in the if (103), ok as an if statement (96), nested pTrig!=0 guard (103).
void PMNode::DestroyFxTriggers(bool bA, bool bB, bool bC) {
    m_unkDC = 0;
    tagParticleFxTrigger *pTrig = (m_unkD8 != 0) ? m_unkE0[0] : 0;
    while (pTrig != 0) {
        if (!bA || (pTrig->m_unk24 & 4)) {
            PParticleSystem *pSys = (PParticleSystem *)pTrig->m_unk20;
            unsigned char ok = (pSys != 0 && ((PParticleManager *)((char *)&gGfxEng + 0x154F00))->IsValid(pSys) != 0) ? pSys->m_unk15 : 0;
            if (ok == 0 || bB) {
                ((PParticleManager *)((char *)&gGfxEng + 0x154F00))->Destroy((unsigned int)pTrig->m_unk20);
            } else {
                pSys = (PParticleSystem *)pTrig->m_unk20;
                if (pSys != 0 && ((PParticleManager *)((char *)&gGfxEng + 0x154F00))->IsValid(pSys) != 0) {
                    pSys->Slot5(false);
                }
            }
            __dl__FPv(pTrig);
            ((PArray *)&m_unkD8)->RemoveCurrent();
        }
        m_unkDC++;
        pTrig = (m_unkDC < m_unkD8) ? m_unkE0[m_unkDC] : 0;
    }
    if (bC && m_unk14 != 0) {
        m_unk18 = 0;
        PMNode *pChild = m_unk1C[0];
        if (pChild != 0) {
            do {
                pChild->DestroyFxTriggers(bA, bB, bC);
                m_unk18++;
                pChild = 0;
                if (m_unk18 < m_unk14) {
                    pChild = m_unk1C[m_unk18];
                }
            } while (pChild != 0);
        }
    }
}

// DRAFT: 0x00192CC0 CopyFxTriggers__6PMNodeFR6PMNode
// note: 30 lines differ. Uses bool bAny = (count > 0) ? true : false. Remaining: constant addiu v1,zero,1 hoisted to the function top; the original does not hoist it.
void PMNode::CopyFxTriggers(PMNode &src) {
    unsigned int count = src.m_unkD8;
    unsigned int idx = 0;
    bool bAny = (count > 0) ? true : false;
    if (bAny) {
        do {
            tagParticleFxTrigger *pTrig = 0;
            if (idx < src.m_unkD8) {
                pTrig = src.m_unkE0[idx];
            }
            if (pTrig != 0 && !(*(int *)((char *)pTrig + 0x24) & 4)) {
                AddFxTrigger(pTrig, false);
            }
            idx++;
        } while (idx < count);
    }
}

// FUNCTION: 0x00192D70 AddFxTriggers__6PMNodeFP6PArrayb
void PMNode::AddFxTriggers(PArray *pArr, bool bFlag) {
    tagParticleFxTrigger *pTrig;
    unsigned int count;
    unsigned int idx;
    if (pArr == 0) {
        CdsAssert("PMNode.cpp", 0x753, "poTriggers");
    }
    count = pArr->m_unk0;
    idx = 0;
    if (idx < count) {
        do {
            pTrig = 0;
            if (idx < pArr->m_unk0) {
                pTrig = (tagParticleFxTrigger *)pArr->m_unk8[idx];
            }
            AddFxTrigger(pTrig, bFlag);
        } while (++idx < count);
    }
}

// FUNCTION: 0x00192E30 AddFxTrigger__6PMNodeFP20tagParticleFxTriggerb
int PMNode::AddFxTrigger(tagParticleFxTrigger *pTrigger, bool bFlag) {
    char *pBlk = (char *)__nw__FUi(0x28);
    if (pBlk == 0) {
        CdsAssert("PMNode.cpp", 0x746, "apTrigger");
    }
    memcpy(pBlk, pTrigger, 0x28);
    *(int *)(pBlk + 0x20) = 0;
    *(int *)(pBlk + 0x24) = bFlag ? 4 : 0;
    ((PArray *)((char *)this + 0xD8))->Add(pBlk);
    return 1;
}

// FUNCTION: 0x00192ED0 LoadFxTriggers__6PMNodeFP8PPakFile
int PMNode::LoadFxTriggers(PPakFile *pFile) {
    unsigned int nCount = 0;
    unsigned int idx;
    char *pBlk;
    DestroyFxTriggers(false, false, false);
    if (((PCDFile *)pFile)->Read(&nCount, 4) != 4) {
        return 0;
    }
    idx = 0;
    while (idx < nCount) {
        pBlk = (char *)__nw__FUi(0x28);
        if (pBlk == 0) {
            CdsAssert("PMNode.cpp", 0x732, "apTrigger");
        }
        if (((PCDFile *)pFile)->Read(pBlk, 0x28) != 0x28) {
            return 0;
        }
        *(int *)(pBlk + 0x20) = 0;
        *(int *)(pBlk + 0x24) = 0;
        ((PArray *)((char *)this + 0xD8))->Add(pBlk);
        idx++;
    }
    return 1;
}

// FUNCTION: 0x00192FD0 SetAllFade__6PMNodeFf
void PMNode::SetAllFade(float fFade) {
    PMNode *pChild;
    unsigned int idx;
    m_unk2C = fFade;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->SetAllFade(fFade);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193070 GetFrameRate__6PMNodeFv
float PMNode::GetFrameRate() {
    void *pObj = m_unk24;
    if (pObj != 0) {
        return ((PFrameSource *)pObj)->GetFrameRate();
    }
    return 0.0f;
}

// FUNCTION: 0x001930B0 SetFrameRate__6PMNodeFfb
void PMNode::SetFrameRate(float fRate, bool bFlag) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot16(fRate);
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetFrameRate(fRate, bFlag);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// DRAFT: 0x00193170 GetDeltaMove__6PMNodeFP10PAnimFramePA4_f
// note: DIFF 115 words. Zeroing is one asm sqc2 vf0 store; fTime local removed and GetFrameRate >= 0 branch form tried (134 to 115). Still differs: compiled saves s0-s4 where the original saves s0-s3 (sEnd lives in s4, original reuses s1), original keeps fTime in f20 across calls, and the m_unk24 and mode branch layout and prologue store order differ. Also tried: fTime local after m_unk24 (131), unsigned mode with mode > 2 (125), vEnd/vStart swap (116), w store moved (121), x/z temporaries (115), IsAnimate() & 4 != 0 (115).
int PMNode::GetDeltaMove(PAnimFrame *pFrame, float (*pOut)[4]) {
    float vStart[4];
    float vEnd[4];
    PChannel *pChan;
    unsigned char mode;
    short sStart;
    short sEnd;

    asm {
        sqc2 vf0, 0x0(pOut)
    }

    if (m_unk24 == 0) {
        return 0;
    }
    if (*(float *)&m_unk34 == m_unk38) {
        return 0;
    }
    mode = m_unk3D & 7;
    if (mode != 2 && mode != 1 && mode != 0) {
        return 0;
    }
    pChan = ((PAnim *)m_unk24)->FindChannel((eAnimType)1);
    if (pChan == 0) {
        return 0;
    }
    if (pFrame->IsAnimate() & 4) {
        pChan->EvaluateAnim(m_unk38, vStart, 3, 0.0f);
    }
    if (pFrame->GetFrameRate() >= 0.0f) {
        sEnd = pFrame->m_unk26;
        sStart = pFrame->m_unk28;
    } else {
        sStart = pFrame->m_unk26;
        sEnd = pFrame->m_unk28;
    }
    pChan->EvaluateAnim((float)sStart, vEnd, 3, 0.0f);
    sceVu0SubVector(*pOut, vEnd, vStart);
    pChan->EvaluateAnim((float)sEnd, vStart, 3, 0.0f);
    (*pOut)[0] = (*pOut)[0] + (mvTrans__6PMNode[0] - vStart[0]);
    (*pOut)[2] = (*pOut)[2] + (mvTrans__6PMNode[2] - vStart[2]);
    if (m_unk3D & 2) {
        (*pOut)[1] = 0.0f;
    } else {
        (*pOut)[1] = (*pOut)[1] + (mvTrans__6PMNode[1] - vStart[1]);
    }
    (*pOut)[3] = 1.0f;
    return 1;
}

// FUNCTION: 0x00193380 FindBone__6PMNodeFUi
PMNode *PMNode::FindBone(unsigned int uID) {
    PMNode *pChild;
    if (uID == 0xFFFFFFFFU) {
        return 0;
    }
    if (m_unkD0 == (int)uID) {
        return this;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            PMNode *pFound = pChild->FindBone(uID);
            unsigned int uNext;
            if (pFound != 0) {
                return pFound;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}

// FUNCTION: 0x00193450 RecurseEnableBone__6PMNodeFP6PArrayb
void PMNode::RecurseEnableBone(PArray *pArr, bool bFlag) {
    if (m_unk10 != 0) {
        if (Find__6PArrayFPv(pArr, this) >= 0) {
            if (!bFlag) {
                pArr->Remove(this);
            }
        } else if (bFlag) {
            pArr->Add(this);
        }
    }
    m_unk18 = 0;
    PMNode *pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->RecurseEnableBone(pArr, bFlag);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193540 BuildDispList__6PMNodeFP6PArray
void PMNode::BuildDispList(PArray *pArr) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk10 != 0 || m_unkD0 >= 0) {
        pArr->Add(this);
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    }
    if (pChild != 0) {
        do {
            pChild->BuildDispList(pArr);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193600 AddBoneMatrixToDisplayList__6PMNodeFb
void PMNode::AddBoneMatrixToDisplayList(bool bRecurse) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unkD0 >= 0) {
        (*(PDisplayList **)((char *)&gGfxEng + 0x154C80))->AddMatrix((PMat4 *)m_unk40, m_unkD0 * 4 + 0x296);
    }
    if (bRecurse) {
        m_unk18 = 0;
        pChild = 0;
        if (m_unk14 != 0) {
            pChild = *m_unk1C;
        }
        if (pChild != 0) {
            do {
                pChild->AddBoneMatrixToDisplayList(bRecurse);
                idx = m_unk18 + 1;
                m_unk18 = idx;
                pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x001936C0 SetFrameTime__6PMNodeFf
void PMNode::SetFrameTime(float fTime) {
    PMNode *pChild;
    void *pObj;
    m_unk38 = *(float *)&m_unk34;
    *(float *)&m_unk34 = fTime;
    m_unk3E |= 8;
    pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot06();
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            ((PNodeVirtual *)pChild)->Slot02(fTime);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// DRAFT: 0x00193790 CheckAnimated__6PMNodeFv
// note: DIFF 48 words; nRet (48) is best; the prologue saves s1 and uses a 0x30 frame because nRet lives across the recursive call, while the original keeps no frame locals; early returns (53), ternary init (53).
int PMNode::CheckAnimated() {
    int nRet = 0;
    PFrameSource *pObj = (PFrameSource *)m_unk24;
    if (pObj != 0 && pObj->m_unk04 != 0x3E8 && pObj->m_unk04 != 1 && 0.0f != pObj->Slot12()) {
        nRet = 1;
    } else {
        m_unk18 = 0;
        PMNode *pChild = (m_unk14 != 0) ? m_unk1C[0] : 0;
        if (pChild != 0) {
            do {
                if (pChild->CheckAnimated() != 0) {
                    nRet = 1;
                    break;
                }
                m_unk18++;
                pChild = (m_unk18 < m_unk14) ? m_unk1C[m_unk18] : 0;
            } while (pChild != 0);
        }
    }
    return nRet;
}

// FUNCTION: 0x00193890 GetFrameTime__6PMNodeFv
float PMNode::GetFrameTime() {
    PMNode *pChild;
    float fTime = *(float *)&m_unk34;
    if (fTime) {
        return fTime;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            float fChild = pChild->GetFrameTime();
            unsigned int uNext;
            if (fChild) {
                return fChild;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0.0f;
}

// FUNCTION: 0x00193960 SetAnimLoopCount__6PMNodeFib
void PMNode::SetAnimLoopCount(int nCount, bool bFlag) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot11(nCount);
    }
    if (!bFlag) {
        return;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetAnimLoopCount(nCount, bFlag);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193A30 SetAllAnimFlags__6PMNodeFP8AnimData
void PMNode::SetAllAnimFlags(AnimData *pAnim) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot10(pAnim);
        float fTime = ((PFrameSource *)m_unk24)->Slot12();
        *(float *)&m_unk34 = fTime;
        m_unk38 = fTime;
    }
    m_unk3F = 3;
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            ((PNodeVirtual *)pChild)->Slot05(pAnim);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00193B10 GetWorldMeshCenter__6PMNodeFPf
int PMNode::GetWorldMeshCenter(float *pOut) {
    u_long128 tmp;
    char *pMesh = (char *)GetFirstMesh();
    if (pMesh != 0) {
        sceVu0ApplyMatrix((float *)&tmp, m_unk40, (float *)(pMesh + 0x10));
        *(u_long128 *)pOut = tmp;
        return 0;
    }
    *(u_long128 *)pOut = *(u_long128 *)m_unk40[3];
    return 0;
}

// FUNCTION: 0x00193B70 CalculateMatrix__6PMNodeFfP6PMNodePA4_A4_f
int PMNode::CalculateMatrix(float fA, PMNode *pNode, float (*pOut)[4][4]) {
    float sp60[4];
    float sp70[4];
    float sp80[4];
    float sp90[4];
    float spA0[4][4];
    unsigned char bAnim;
    float *pA3;
    PMNode *pChild;

    sceVu0UnitMatrix(spA0);
    if (m_unk24 != 0 && ((PAnim *)m_unk24)->m_unk8 != 0) {
        ((PAnim *)m_unk24)->Animate(fA, 0.0f, (float (*)[4])sp60, sp90, false);
        bAnim = ((PAnim *)m_unk24)->m_unkA;
        if (bAnim & 1) {
            if (m_unk04 == 3) {
                if (!(m_unk3D & 1)) {
                    sp60[0] = 0.0f;
                    sp60[2] = 0.0f;
                }
                if (!(m_unk3D & 2)) {
                    sp60[1] = 0.0f;
                }
            } else {
                AddVectorXYZ__FPfPf(sp60, m_unk80);
            }
        } else {
            *(u_long128 *)sp60 = *(u_long128 *)m_unk80;
        }
        if (!(bAnim & 2)) {
            *(u_long128 *)sp70 = *(u_long128 *)m_unk90;
        } else {
            AddVectorXYZ__FPfPf(sp70, m_unk90);
        }
        pA3 = (bAnim & 4) ? sp80 : m_unkA0;
        FastMath_ComputeMatrix__FPA4_A4_fPA4_fPA4_fPA4_fPA4_fPA4_fPA4_A4_f(pOut, sp60, sp70, pA3, m_unkB0, m_unkC0, pOut);
    } else {
        FastMath_ComputeMatrix__FPA4_A4_fPA4_fPA4_fPA4_fPA4_fPA4_fPA4_A4_f(pOut, m_unk80, m_unk90, m_unkA0, m_unkB0, m_unkC0, pOut);
    }
    if (this == pNode) {
        return 1;
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? m_unk1C[0] : 0;
    while (pChild != 0) {
        if (pChild->Find(pNode)) {
            if (pChild->CalculateMatrix(fA, pNode, pOut)) {
                return 1;
            }
        }
        pChild = (++m_unk18 < m_unk14) ? m_unk1C[m_unk18] : 0;
    }
    return 0;
}

// Views of the vtables Animate calls through: the object at PMNode+0x24 (PAnim layout) and each child PMNode (slot 0x18 is Animate).
class PAnimVirt {
public:
    virtual ~PAnimVirt();
    virtual void Slot01();
    virtual void Slot02();
    virtual float Animate(float fTime, float fUnused, float *pOut, float *pOut2, int nA);
    virtual int IsAnimate();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot10();
    virtual float GetFrameTime();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual int IsPAnimFrame();
    int m_unk04;
    short m_unk08;
    unsigned char m_unk0A;
};
class PNodeAnimVirt {
public:
    virtual ~PNodeAnimVirt();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual int Animate(float fA, float fB, PMat4 *pMat, int nMode, bool bFlag);
};

// DRAFT: 0x00193D80 Animate__6PMNodeFffP5PMat4ib
// note: DIFF 332 words, mostly a 1-word shift: original loads m_unk24 into v1 then daddu a0,v1 before the 0x4C virtual call, ours loads straight into a0; tried a pAnim local, repeated (PAnimVirt *)m_unk24 casts, bool flags, IsAnimate as int + signed char cast.
int PMNode::Animate(float fA, float fB, PMat4 *pMat, int nMode, bool bFlag) {
    float spA0[4];
    float spB0[4];
    float spC0[4];
    int nOld;
    bool bPlay = false;
    int nCur;
    bool nStop = false;
    unsigned char bAnim;
    int nFrames = 0;
    bool bMoved = false;
    float *pScale;
    float fPrev;
    PNodeAnimVirt *pChild;
    int nRet;
    PAnimVirt *pAnim;
    float fT;
    int nChildRet;
    bool bClear;

    nFrames = 0;
    bPlay = false;
    nStop = false;
    fT = fA;
    if ((pAnim = (PAnimVirt *)m_unk24) != 0) {
        if (pAnim->m_unk08 != 0) {
            bPlay = true;
            if (pAnim->IsPAnimFrame() != 0) {
                fT = ((PAnimVirt *)m_unk24)->GetFrameTime();
            }
        }
        if (((PAnimVirt *)m_unk24)->IsAnimate() != 0) {
            nStop = true;
        }
        nFrames = ((PAnimVirt *)m_unk24)->m_unk04;
    }
    nRet = nMode;
    if (nRet == 0 && !nStop && (m_unk3E & 8) == 0) {
        if (m_unk3E & 4) {
            bFlag = true;
        }
    } else {
        nRet |= 8;
        if (bPlay) {
            nOld = (int)(0.5 + m_unk30);
            fPrev = fT;
            fT = ((PAnimVirt *)m_unk24)->Animate(fT, fB, spA0, &m_unk2C, 1);
            if (!(fB <= 0.0f) && fT < fPrev) {
                m_unk30 = 0.0f;
            }
            nRet |= (signed char)((PAnimVirt *)m_unk24)->IsAnimate();
            bAnim = ((PAnimVirt *)m_unk24)->m_unk0A;
            if (bAnim & 1) {
                if (m_unk04 == 3) {
                    if (!(m_unk3D & 1)) {
                        *(u_long128 *)mvTrans__6PMNode = *(u_long128 *)spA0;
                        spA0[0] = 0.0f;
                        spA0[2] = 0.0f;
                    }
                    if (!(m_unk3D & 2)) {
                        spA0[1] = 0.0f;
                    }
                } else {
                    AddVectorXYZ__FPfPf(spA0, m_unk80);
                }
            } else {
                *(u_long128 *)spA0 = *(u_long128 *)m_unk80;
            }
            if (!(bAnim & 2)) {
                *(u_long128 *)spB0 = *(u_long128 *)m_unk90;
            } else {
                AddVectorXYZ__FPfPf(spB0, m_unk90);
            }
            pScale = (bAnim & 4) ? spC0 : m_unkA0;
            FastMath_ComputeMatrix__FPA4_A4_fPA4_fPA4_fPA4_fPA4_fPA4_fPA4_A4_f((float (*)[4][4])m_unk40, spA0, spB0, pScale, m_unkB0, m_unkC0, (float (*)[4][4])pMat);
            bMoved = true;
            nCur = (int)(0.5f + m_unk30);
            bClear = false;
            if (nCur != nOld) {
                switch (nCur) {
                case 0x7F00:
                    StopAllSoundsByObject();
                    bClear = true;
                    break;
                case 0x7F01:
                    StopAmbientSoundsByObject();
                    bClear = true;
                    break;
                case 0x7F03:
                    StopSoundBySoundRefIfAmbient(m_unkEC);
                    bClear = true;
                    break;
                case 0x7F02:
                    StopSoundBySoundRef(m_unkEC);
                    bClear = true;
                    break;
                case 0:
                    StopAllSoundsByObject();
                    bClear = true;
                    break;
                }
                if (bClear) {
                    m_unkEC = 0;
                } else if (nCur != 0x7F04) {
                    m_unkEC = PlaySound(nCur);
                }
            }
        } else {
            pScale = m_unkA0;
            FastMath_ComputeMatrix__FPA4_A4_fPA4_fPA4_fPA4_fPA4_fPA4_fPA4_A4_f((float (*)[4][4])m_unk40, m_unk80, m_unk90, pScale, m_unkB0, m_unkC0, (float (*)[4][4])pMat);
            bMoved = true;
        }
        if (!bFlag && (pScale[0] != 1.0f || pScale[1] != 1.0f || pScale[2] != 1.0f)) {
            bFlag = true;
        }
        if (bFlag) {
            m_unk3E = m_unk3E | 4;
        } else {
            m_unk3E = m_unk3E & 0xFB;
        }
        AnimateBox(fT);
        m_unk3E = m_unk3E & 0xF7;
    }
    if (m_unk10 != 0 && (m_unk3E & 0x10)) {
        if (nFrames >= 2) {
            ((PMesh *)m_unk10)->AnimateShaders(fT, true);
        } else {
            ((PMesh *)m_unk10)->AnimateShaders(0.5f * fB, false);
        }
    }
    m_unk38 = m_unk34;
    m_unk34 = fT;
    if (m_unk24 != 0) {
        ProcessFxTriggers(m_unk34, (PMat4 *)m_unk40, false, bMoved);
    }
    if (m_unk2C < 1.0f) {
        nRet |= 0x10;
    }
    m_unk18 = 0;
    pChild = (PNodeAnimVirt *)((m_unk14 != 0) ? m_unk1C[0] : 0);
    while (pChild != 0) {
        nChildRet = pChild->Animate(fT, fB, (PMat4 *)m_unk40, nRet & 9, bFlag);
        if (nChildRet & 7) {
            nRet |= 2;
            if (nChildRet & 4) {
                nRet |= 4;
            }
        }
        nRet |= nChildRet & 0x10;
        pChild = (PNodeAnimVirt *)((++m_unk18 < m_unk14) ? m_unk1C[m_unk18] : 0);
    }
    m_unk3F = nRet & ~8;
    if (m_unkF4 != 0) {
        if (!(m_unk3F & 7)) {
            StopAmbientSoundsByObject();
        }
    }
    return nRet;
}

// FUNCTION: 0x00194340 DisableAllHitBox__6PMNodeFv
void PMNode::DisableAllHitBox() {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk10 != 0) {
        ((unsigned char *)m_unk10)[0xD] = 0;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    }
    if (pChild != 0) {
        do {
            pChild->DisableAllHitBox();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x001943E0 AnimateBox__6PMNodeFf
void PMNode::AnimateBox(float fTime) {
    PAnim *pAnim;
    unsigned char *pMesh;
    pAnim = (PAnim *)m_unk24;
    if (pAnim != 0 && (pAnim->m_unkA & 0x10)) {
        m_unk28 = pAnim->FindChannel((eAnimType)5)->AnimateBox(fTime, m_unk3C);
        if (m_unk28 != 0) {
            return;
        }
        if (m_unk3C != 0) {
            if (m_unk10 != 0) {
                m_unk28 = (char *)m_unk10 + 0x10;
            }
        }
        return;
    } else {
        pMesh = (unsigned char *)m_unk10;
        if (pMesh != 0 && pMesh[0xD] != 0) {
            m_unk3C = pMesh[0xE];
            m_unk28 = (char *)m_unk10 + 0x10;
            return;
        }
        m_unk3C = 0;
        m_unk28 = 0;
    }
}

// FUNCTION: 0x001944B0 BuildAnimList__6PMNodeFP6PArrayUi
void PMNode::BuildAnimList(PArray *pArr, unsigned int uID) {
    PMNode *pChild;
    int nObjID;
    void *pObj = m_unk24;
    if (pObj != 0) {
        nObjID = *(int *)((char *)pObj + 4);
    } else {
        nObjID = 0;
    }
    if (uID == (unsigned int)nObjID) {
        pArr->Add(this);
        return;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->BuildAnimList(pArr, uID);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00194580 FindAnimNode__6PMNodeFUi
PMNode *PMNode::FindAnimNode(unsigned int uID) {
    PMNode *pChild;
    int nObjID;
    void *pObj = m_unk24;
    if (pObj != 0) {
        nObjID = *(int *)((char *)pObj + 4);
    } else {
        nObjID = 0;
    }
    if (uID == (unsigned int)nObjID) {
        return this;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            PMNode *pFound;
            unsigned int uNext;
            pFound = pChild->FindAnimNode(uID);
            if (pFound != 0) {
                return pFound;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}


// DRAFT: 0x00194650 EnableOneRenderPassOnly__6PMNodeFi
// note: 3 words (0x44, 0x4C, 0x54): the four flags are cleared through a bool* loop over &m_unkD4; the original materializes the constant 1 in a0 before adding nPass, ours adds first and uses a1. A real bool m_abPass[4] header member gives 36. Tried: ab[nPass] = 1, *(ab + nPass), ab += nPass, bool local, i outside the for, (&m_unkD4)[i] in the loop (3-4), indexed stores without the loop (4-36).
void PMNode::EnableOneRenderPassOnly(int nPass) {
    if (nPass >= 4) {
        CdsAssert("PMNode.cpp", 0x446, "iPassIndex < MAX_PASSES_PER_SHADER");
    }
    bool *ab = &m_unkD4;
    for (int i = 0; i < 4; i++) {
        ab[i] = false;
    }
    ab[nPass] = true;
    m_unk3E |= 0x80;
    m_unk18 = 0;
    PMNode *pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetRenderPassStatus(m_unkD4, *(bool *)&m_unkD5, *(bool *)&m_unkD6, *(bool *)&m_unkD7);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00194740 SetRenderPassStatus__6PMNodeFbbbb
void PMNode::SetRenderPassStatus(bool bA, bool bB, bool bC, bool bD) {
    PMNode *pChild;
    m_unkD4 = bA;
    m_unkD5 = bB;
    m_unkD6 = bC;
    m_unkD7 = bD;
    if (bA && bB && bC && bD) {
        m_unk3E &= 0x7F;
    } else {
        m_unk3E |= 0x80;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetRenderPassStatus(bA, bB, bC, bD);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00194850 Find__6PMNodeFUi
PMNode *PMNode::Find(unsigned int uID) {
    PMNode *pChild;
    if (uID == 0) {
        return 0;
    }
    if (m_unk08 == uID) {
        return this;
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            PMNode *pFound = pChild->Find(uID);
            unsigned int uNext;
            if (pFound != 0) {
                return pFound;
            }
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}

// FUNCTION: 0x00194920 Find__6PMNodeFP6PMNode
int PMNode::Find(PMNode *pNode) {
    PMNode *pChild;
    if (this == pNode) {
        return 1;
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            if (pChild->Find(pNode) != 0) {
                return 1;
            }
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}

// FUNCTION: 0x001949E0 RecurseSetSTAnimOptions__6PMNodeFb
unsigned char PMNode::RecurseSetSTAnimOptions(bool bFlag) {
    unsigned char bResult = 0;
    PMNode *pChild;
    if (m_unk10 != 0) {
        SetSTAnimOptions__5PMeshFb(m_unk10, bFlag);
        bResult = *((unsigned char *)m_unk10 + 0xC);
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            if (pChild->RecurseSetSTAnimOptions(bFlag)) {
                bResult = 1;
            }
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    if (bResult) {
        m_unk3E |= 0x10;
    }
    return bResult;
}

// FUNCTION: 0x00194AD0 GetFirstMesh__6PMNodeFv
void *PMNode::GetFirstMesh() {
    PMNode *pChild;
    unsigned int idx;
    void *pMesh = m_unk10;
    if (pMesh != 0) {
        return pMesh;
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            void *pFound = pChild->GetFirstMesh();
            if (pFound != 0) {
                return pFound;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return 0;
}

// FUNCTION: 0x00194B80 SetAllFrustrumTest__6PMNodeF13eBoxIntersect
void PMNode::SetAllFrustrumTest(eBoxIntersect eMode) {
    PMNode *pChild;
    unsigned int idx;
    m_unk0C = (int)eMode;
    if (m_unk04 == 2) {
        return;
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            pChild->SetAllFrustrumTest(eMode);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00194C30 ScaleSet__6PMNodeFffff
void PMNode::ScaleSet(float a, float b, float c, float d) {
    m_unkA0[0] = a;
    m_unkA0[1] = b;
    m_unkA0[2] = c;
    m_unkA0[3] = d;
    m_unk3E |= 8;
}

// FUNCTION: 0x00194C50 LoadMesh__6PMNodeFP8PPakFileP6PArray16ePsx2FileVersion
int PMNode::LoadMesh(PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion) {
    unsigned int hdr[4];
    if (((PCDFile *)pFile)->Read(hdr, 0x10) != 0x10) {
        return 0;
    }
    if (hdr[0] != 0) {
        if (m_unk10 != 0) {
            CdsAssert("PMNode.cpp", 0x283, "mpMesh == NULL");
        }
        m_unk10 = new PMesh();
        if (m_unk10 == 0) {
            CdsAssert("PMNode.cpp", 0x287, "mpMesh");
        }
        m_unk3E |= 1;
        if (((PMesh *)m_unk10)->Load(pFile, pArr, hdr[0], hdr[1], eVersion, true) == 0) {
            DestroyMesh();
            return 0;
        }
        if (((PMesh *)m_unk10)->m_unkC != 0) {
            m_unk3E |= 0x10;
        }
        m_unk28 = (char *)m_unk10 + 0x10;
        m_unk3C = ((PMesh *)m_unk10)->m_unkE;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x00194DB0 LoadBone__6PMNodeFP8PPakFileP6PArray16ePsx2FileVersion
int PMNode::LoadBone(PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion) {
    unsigned char hdrA[0x60];
    unsigned char hdrB[0x44];
    unsigned int meshHdr[4];
    float box[2][4];
    unsigned int tag;
    PMNode *apCloneChild;

    ((pFile) ? (void)0 : CdsAssert("PMNode.cpp", 0x1F5, "poFile"));
    ((pArr) ? (void)0 : CdsAssert("PMNode.cpp", 0x1F6, "poTextureHandles"));

    if ((int)eVersion >= 0x20000) {
        if (((PCDFile *)pFile)->Read(hdrB, 0x44) != 0x44) { return 0; }
        m_unk08 = *(int *)(hdrB + 0x00);
        m_unkD0 = *(int *)(hdrB + 0x34);
    } else {
        if (((PCDFile *)pFile)->Read(hdrA, 0x60) != 0x60) { return 0; }
        m_unk08 = *(int *)(hdrA + 0x00);
        m_unkD0 = *(int *)(hdrA + 0x50);
        memcpy(hdrB + 4, hdrA + 0x20, 0x10);
        memcpy(hdrB + 0x14, hdrA + 0x30, 0x20);
        *(int *)(hdrB + 0x34) = *(int *)(hdrA + 0x50);
        *(int *)(hdrB + 0x38) = *(int *)(hdrA + 0x54);
        memcpy(hdrB + 0x3C, hdrA + 0x58, 8);
    }

    if ((int)eVersion >= 0x10001) {
        if (!LoadFxTriggers(pFile)) { return 0; }
    }

    if (((PCDFile *)pFile)->Read(meshHdr, 0x10) != 0x10) { return 0; }
    memcpy(m_unk80, hdrB + 4, 0x10);

    if (meshHdr[0] != 0) {
        m_unk10 = new PMesh();
        if (m_unk10 == 0) { CdsAssert("PMNode.cpp", 0x235, "mpMesh"); }
        m_unk3E |= 1;
        if (((PMesh *)m_unk10)->Load(pFile, pArr, meshHdr[0], meshHdr[1], eVersion, false) == 0) { return 0; }
        if (((PMesh *)m_unk10)->m_unkC != 0) { m_unk3E |= 0x10; }
        memcpy(box, hdrB + 0x14, 0x20);
        ((PMesh *)m_unk10)->SetBoundBox(&box);
        m_unk28 = (char *)m_unk10 + 0x10;
        ((PMesh *)m_unk10)->m_unkE = hdrB[0x38];
        m_unk3C = hdrB[0x38];
    }

    tag = 0;
    if (((PCDFile *)pFile)->Read(&tag, 4) != 4) { return 0; }
    if (tag == 9) { return 1; }
    while (tag == 8) {
        if ((apCloneChild = (PMNode *)__nw__FUi(0x100)) != 0) {
            char *volatile pThis = (char *)apCloneChild;
            *(void **)apCloneChild = __vt__9PResource;
            *(int *)(pThis + 4) = 0;
            *(void **)pThis = __vt__6PMNode;
            __ct__6PArrayFv((PArray *)(pThis + 0x14));
            sceVu0UnitMatrix((float (*)[4])(pThis + 0x40));
            __ct__6PArrayFv((PArray *)(pThis + 0xD8));
            ((PMNode *)pThis)->InitMembers();
            apCloneChild = (PMNode *)pThis;
        }
        ((apCloneChild) ? (void)0 : CdsAssert("PMNode.cpp", 0x25D, "apChildBone"));
        Add__6PArrayFPv(&m_unk14, apCloneChild);
        if (!apCloneChild->LoadBone(pFile, pArr, eVersion)) { return 0; }
        tag = 0;
        if (((PCDFile *)pFile)->Read(&tag, 4) != 4) { return 0; }
        if (tag == 9) { return 1; }
    }
    return 0;
}

// FUNCTION: 0x00195180 DestroyChildren__6PMNodeFv
void PMNode::DestroyChildren() {
    PMNode *pChild;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            delete pChild;
            unsigned int idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    if (m_unk1C != 0) {
        m_unk14 = 0;
        m_unk18 = 0;
    }
}

// FUNCTION: 0x00195240 DestroyMesh__6PMNodeFv
void PMNode::DestroyMesh() {
    void *pMesh = m_unk10;
    if (pMesh != 0 && (m_unk3E & 1)) {
        __dt__5PMeshFv(pMesh, 1);
        StopAmbientSoundsByObject();
    }
    m_unk10 = 0;
    m_unk3E &= 0xEE;
    m_unk28 = 0;
    m_unk3C = 0;
}

// FUNCTION: 0x001952B0 RecurseSetFade__6PMNodeFf
void PMNode::RecurseSetFade(float fFade) {
    PMNode *pChild;
    unsigned int idx;
    m_unk2C = fFade;
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->RecurseSetFade(fFade);
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00195350 RecurseSetLoopRateByID__6PMNodeFUiif
int PMNode::RecurseSetLoopRateByID(unsigned int uID, int nCount, float fRate) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk24 != 0 && uID == ((PFrameSource *)m_unk24)->m_unk04) {
        ((PFrameSource *)m_unk24)->Slot11(nCount);
        ((PFrameSource *)m_unk24)->Slot16(fRate);
        ((PFrameSourceArgView *)m_unk24)->Slot13(1);
        m_unk3F |= 1;
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            if (pChild->RecurseSetLoopRateByID(uID, nCount, fRate) != 0) {
                m_unk3F |= 2;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return m_unk3F;
}

// FUNCTION: 0x00195480 SetAllLoopCountByID__6PMNodeFUii
void PMNode::SetAllLoopCountByID(unsigned int uID, int nCount) {
    PMNode *pChild;
    void *pObj = m_unk24;
    if (pObj != 0 && (uID == 0 || uID == *(unsigned int *)((char *)pObj + 4))) {
        uID = 0;
        ((PFrameSource *)pObj)->Slot11(nCount);
    }
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = m_unk1C[0];
    }
    if (pChild != 0) {
        do {
            unsigned int uNext;
            pChild->SetAllLoopCountByID(uID, nCount);
            uNext = m_unk18 + 1;
            m_unk18 = uNext;
            pChild = (uNext < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00195560 RecurseResetAnimByID__6PMNodeFUi
int PMNode::RecurseResetAnimByID(unsigned int uID) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk24 != 0 && (uID == 0 || uID == ((PFrameSource *)m_unk24)->m_unk04)) {
        ((PFrameSourceArgView *)m_unk24)->Slot13(0);
        ((PFrameSourceFloatView *)m_unk24)->Slot06(0.0f);
        m_unk34 = 0;
        *(unsigned int *)&m_unk38 = 0xC61C4000;
        m_unk3F = 0;
        m_unk3E |= 8;
        m_unk3F |= 1;
        ProcessFxTriggers(-1.0f, 0, 0, 0);
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            if (pChild->RecurseResetAnimByID(uID) != 0) {
                m_unk3F |= 2;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return m_unk3F;
}

// FUNCTION: 0x001956A0 RecurseSetAnimFlagsByID__6PMNodeFUiP8AnimData
int PMNode::RecurseSetAnimFlagsByID(unsigned int uID, AnimData *pAnim) {
    PMNode *pChild;
    unsigned int idx;
    void *pObj = m_unk24;
    if (pObj != 0 && uID == ((PFrameSource *)pObj)->m_unk04) {
        ((PFrameSource *)pObj)->Slot10(pAnim);
        m_unk3F |= 1;
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            if (pChild->RecurseSetAnimFlagsByID(uID, pAnim) != 0) {
                m_unk3F |= 2;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return m_unk3F;
}

// FUNCTION: 0x001957A0 RecurseApplyAnimLoopByID__6PMNodeFUisib
int PMNode::RecurseApplyAnimLoopByID(unsigned int uID, short sA, int nB, bool bC) {
    PMNode *pChild;
    unsigned int idx;
    short sCount;
    if (m_unk24 != 0 && uID == ((PAnimView *)m_unk24)->m_unk04) {
        m_unk3F |= 1;
        sCount = ((PAnimView *)m_unk24)->m_unk08;
        if (sCount > 0) {
            ((PAnimView *)m_unk24)->SetEndFrame(sCount);
            ((PAnimView *)m_unk24)->EnableAnim(bC);
            ((PAnimView *)m_unk24)->SetAnimLoopCount(nB);
            ((PAnimView *)m_unk24)->SetFrameTime(0.0f);
            ((PAnimView *)m_unk24)->SetLoopFrame(sA);
        }
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            if (pChild->RecurseApplyAnimLoopByID(uID, sA, nB, bC) != 0) {
                m_unk3F |= 2;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return m_unk3F;
}

// FUNCTION: 0x00195920 RecurseApplyAnimFlagsByID__6PMNodeFUibi
int PMNode::RecurseApplyAnimFlagsByID(unsigned int uID, bool bA, int nB) {
    PMNode *pChild;
    unsigned int idx;
    if (m_unk24 != 0 && uID == ((PFrameSource *)m_unk24)->m_unk04) {
        ((PFrameSourceBoolView *)m_unk24)->Slot13(bA);
        ((PFrameSource *)m_unk24)->Slot11(nB);
        m_unk3F |= 1;
    }
    m_unk18 = 0;
    pChild = (m_unk14 != 0) ? *m_unk1C : 0;
    if (pChild != 0) {
        do {
            if (pChild->RecurseApplyAnimFlagsByID(uID, bA, nB) != 0) {
                m_unk3F |= 2;
            }
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
    return m_unk3F;
}

// FUNCTION: 0x00195A40 EnableAnim__6PMNodeFbb
void PMNode::EnableAnim(bool bA, bool bB) {
    PMNode *pChild;
    unsigned int idx;
    void *pObj = m_unk24;
    if (pObj != 0) {
        ((PFrameSource *)pObj)->Slot13();
    }
    m_unk3F = bA;
    if (!bB) {
        return;
    }
    if (bB && m_unk04 == 1) {
        m_unk18 = 0;
        pChild = (m_unk14 != 0) ? *m_unk1C : 0;
        if (pChild != 0) {
            do {
                pChild->EnableAnim(bA, true);
                if (m_unk3F == 0 && (signed char)(pChild->m_unk3F & 7) != 0) {
                    m_unk3F = 2;
                }
                idx = m_unk18 + 1;
                m_unk18 = idx;
                pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
            } while (pChild != 0);
        }
    }
}

// FUNCTION: 0x00195B50 AttachAnim__6PMNodeFP5PAnimb
void PMNode::AttachAnim(PAnim *pAnim, bool bFlag) {
    PAnimFrame *pFrame;
    if (pAnim == 0) {
        CdsAssert("PMNode.cpp", 0x10C, "pAnim");
    }
    DestroyAnim();
    if (bFlag) {
        pFrame = (PAnimFrame *)__nw__FUi(0x34);
        if (pFrame != 0) {
            pFrame = __ct__10PAnimFrameFP5PAnim(pFrame, pAnim);
        }
        m_unk24 = pFrame;
        if (m_unk24 == 0) {
            CdsAssert("PMNode.cpp", 0x113, "mpAnim");
        }
        m_unk3E |= 2;
    } else {
        m_unk24 = pAnim;
        m_unk3E &= 0xFD;
    }
}

struct PAnimHeader {
    unsigned int uA;
    unsigned int uNumChannels;
    unsigned int uC;
    unsigned short uFlags;
    unsigned short uG;
};

// FUNCTION: 0x00195C20 LoadAnim__6PMNodeFP8PPakFile
int PMNode::LoadAnim(PPakFile *pFile) {
    PAnimHeader hdr;
    PAnimFrame *pObj;
    DestroyAnim();
    if (((PCDFile *)pFile)->Read(&hdr, 0x10) != 0x10) {
        return 0;
    }
    if (hdr.uNumChannels > 5) {
        CdsAssert("PMNode.cpp", 0xFA, "aHeader.uNumChannels <= CHANNEL_MAX");
    }
    if (hdr.uFlags == 0 && hdr.uA > 1) {
        pObj = (PAnimFrame *)__nw__FUi(0x34);
        if (pObj != 0) {
            pObj = __ct__10PAnimFrameFs(pObj, 0);
        }
        m_unk24 = pObj;
    } else {
        pObj = (PAnimFrame *)__nw__FUi(0x20);
        if (pObj != 0) {
            pObj = (PAnimFrame *)__ct__5PAnimFv((PAnim *)pObj);
        }
        m_unk24 = pObj;
    }
    if (m_unk24 == 0) {
        CdsAssert("PMNode.cpp", 0x102, "mpAnim");
    }
    return ((PAnimFrame *)m_unk24)->LoadHeader(pFile, &hdr);
}

// FUNCTION: 0x00195D30 DestroyAnim__6PMNodeFv
void PMNode::DestroyAnim() {
    unsigned char flags = m_unk3E;
    if (flags & 2) {
        m_unk3E = flags & 0xFD;
        if (m_unk24 != 0) {
            delete (PFrameSource *)m_unk24;
        }
    }
    m_unk3E |= 8;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk3C = 0;
    StopAmbientSoundsByObject();
    m_unk3F = 0;
    *(unsigned int *)&m_unk2C = 0x3F800000;
    m_unk30 = 0;
    m_unk34 = 0;
    *(unsigned int *)&m_unk38 = 0xC61C4000;
}

// FUNCTION: 0x00195DD0 RecurseDetachAnim__6PMNodeFv
void PMNode::RecurseDetachAnim() {
    PMNode *pChild;
    unsigned int idx;
    DestroyAnim();
    DestroyFxTriggers(true, false, false);
    m_unk18 = 0;
    pChild = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    }
    if (pChild != 0) {
        do {
            pChild->RecurseDetachAnim();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}

// FUNCTION: 0x00195E70 __dt__6PMNodeFv
PMNode::~PMNode() {
    DestroyMesh();
    DestroyAnim();
    DestroyChildren();
    DestroyFxTriggers(false, false, false);
    m_unk04 = 0;
    if (m_pObjDisplayList != 0) {
        __dt__18PObjectDisplayListFv(m_pObjDisplayList, 1);
        m_pObjDisplayList = 0;
    }
    StopAmbientSoundsByObject();
    m_unkEC = 0;
    m_unkF0 = 0;
    __dt__6PArrayFv(&m_unkD8, -1);
    __dt__6PArrayFv(&m_unk14, -1);
    if (this != 0) {
        *(void **)this = __vt__9PResource;
        m_unk04 = 0;
    }
}

// FUNCTION: 0x00195F50 CopyMNode__6PMNodeFR6PMNodeb
void PMNode::CopyMNode(PMNode &src, bool bFlag) {
    PMNode *apCloneChild;
    PMNode *pChild;

    m_unk08 = src.m_unk08;
    m_unk3E = 8;
    m_unk3D = src.m_unk3D;
    {
        void *pMesh = src.m_unk10;
        m_unk10 = pMesh;
        m_unk3E &= 0xEF;
        if (pMesh != 0 && ((unsigned char *)pMesh)[0xC] != 0) {
            m_unk3E |= 0x10;
        }
    }
    m_unk28 = src.m_unk28;
    m_unk3C = src.m_unk3C;
    m_unk0C = src.m_unk0C;
    m_unk24 = src.m_unk24;
    m_unk2C = src.m_unk2C;
    m_unk04 = src.m_unk04;
    m_pObjDisplayList = 0;
    m_unkD0 = src.m_unkD0;
    *(u_long128 *)m_unk80 = *(u_long128 *)src.m_unk80;
    *(u_long128 *)m_unk90 = *(u_long128 *)src.m_unk90;
    *(u_long128 *)m_unkA0 = *(u_long128 *)src.m_unkA0;
    *(u_long128 *)m_unkB0 = *(u_long128 *)src.m_unkB0;
    *(u_long128 *)m_unkC0 = *(u_long128 *)src.m_unkC0;
    sceVu0CopyMatrix(m_unk40, src.m_unk40);
    CopyFxTriggers(src);
    if (bFlag) {
        PArray *pSrcArr = (PArray *)&src.m_unk14;
        Allocate__6PArrayFUi(&m_unk14, pSrcArr->m_unk0);
        pSrcArr->m_unk4 = 0;
        pChild = (pSrcArr->m_unk0 != 0) ? ((PMNode **)pSrcArr->m_unk8)[0] : 0;
        if (pChild) {
            do {
                switch (pChild->m_unk04) {
                case 1: {
                    PMNode *pNew = (PMNode *)__nw__FUi(0x140);
                    if (pNew) {
                        pNew = (PMNode *)__ct__9PMeshNodeFR9PMeshNode(pNew, pChild);
                    }
                    apCloneChild = pNew;
                    break;
                }
                case 3: {
                    if ((apCloneChild = (PMNode *)__nw__FUi(0x100)) != 0) {
                        char *volatile pThis = (char *)apCloneChild;
                        *(void **)apCloneChild = __vt__9PResource;
                        *(int *)(pThis + 4) = 0;
                        *(void **)pThis = __vt__6PMNode;
                        __ct__6PArrayFv((PArray *)(pThis + 0x14));
                        sceVu0UnitMatrix((float (*)[4])(pThis + 0x40));
                        __ct__6PArrayFv((PArray *)(pThis + 0xD8));
                        ((PMNode *)pThis)->InitMembers();
                        apCloneChild = (PMNode *)pThis;
                    }
                }
                    ((apCloneChild) ? (void)0 : CdsAssert("PMNode.cpp", 0xA0, "apCloneChild"));
                    apCloneChild->CopyMNode(*pChild, true);
                    break;
                default:
                    ((!"no CopyMNode() for this type\n") ? (void)0 : CdsAssert("PMNode.cpp", 0xA4, "!\"no CopyMNode() for this type\\n\""));
                    break;
                }
                ((apCloneChild) ? (void)0 : CdsAssert("PMNode.cpp", 0xA7, "apCloneChild"));
                Add__6PArrayFPv(&m_unk14, apCloneChild);
                pChild = ((unsigned int)++pSrcArr->m_unk4 < pSrcArr->m_unk0) ? ((PMNode **)pSrcArr->m_unk8)[pSrcArr->m_unk4] : 0;
            } while (pChild);
        }
    }
}

// FUNCTION: 0x00196220 InitMembers__6PMNodeFv
void PMNode::InitMembers() {
    char *pBase;
    m_unk08 = 0;
    m_unk10 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    pBase = (char *)this + 0x80;
    m_unk3C = 0;
    m_unk3E = 8;
    m_unk3D = 3;
    m_unk3F = 0;
    asm {
        sqc2 vf0, 0x0(pBase)
        sqc2 vf0, 0x10(pBase)
        sqc2 vf0, 0x30(pBase)
        sqc2 vf0, 0x40(pBase)
    }
    m_unkA0[3] = 1.0f;
    m_unkA0[2] = 1.0f;
    m_unkA0[1] = 1.0f;
    m_unkA0[0] = 1.0f;
    m_unk2C = 1.0f;
    m_unk30 = 0;
    m_unk34 = 0;
    m_unk38 = -10000.0f;
    m_unk04 = 3;
    m_unk0C = 4;
    m_unkD4 = true;
    m_unkD5 = 1;
    m_unkD6 = 1;
    m_unkD7 = 1;
    m_unkD0 = -1;
    m_pObjDisplayList = 0;
    m_unkE8 = mst_NextPMNodeRef__6PMNode;
    mst_NextPMNodeRef__6PMNode = mst_NextPMNodeRef__6PMNode + 1;
    m_unkEC = 0;
    m_unkF0 = 0;
    m_unkF4 = 0;
}

// FUNCTION: 0x001962E0 RemoveNullAnimation__6PMNodeFv
void PMNode::RemoveNullAnimation() {
    PMNode *pChild;
    unsigned int idx;
    void *pObj = m_unk24;
    if (pObj != 0 && ((PFrameSource *)pObj)->m_unk0A == 0) {
        delete (PFrameSource *)pObj;
        m_unk24 = 0;
        StopAmbientSoundsByObject();
    }
    m_unk18 = 0;
    if (m_unk14 != 0) {
        pChild = *m_unk1C;
    } else {
        pChild = 0;
    }
    if (pChild != 0) {
        do {
            pChild->RemoveNullAnimation();
            idx = m_unk18 + 1;
            m_unk18 = idx;
            pChild = (idx < m_unk14) ? m_unk1C[m_unk18] : 0;
        } while (pChild != 0);
    }
}
