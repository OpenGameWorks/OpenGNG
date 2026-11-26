// FLAGS: -str readonly
#include "types.h"
#include "Peddler.h"

static unsigned int GetItemID(unsigned int arg0);

// TODO(header): foreign declarations
extern "C" void FillItems__6PlayerFPib(void *pThis, int *pItems, bool bArg);
extern "C" tagWaypointGroup *GetWaypointGroupInfo__15WaypointManagerFUi(void *pThis, unsigned int iGroupId);
class Physics {
public:
    Physics();
    void SetPhysicsType(unsigned int nType, float (*pPos)[4]);
    char _pad[0x120];
};
class EntityBaseClass;
// The second argument is not set by the caller; the original passes a1 through unchanged.
extern "C" int InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);

class Debug {
public:
    void DebugDisp(char *pText);

    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
};
extern Debug gDebug;

extern "C" int sprintf(char *pDst, const char *pFmt, ...);

struct ItemEntry {
    char _pad000[4];
    int m_unk4;                     // 0x04
    unsigned int m_unk8;            // 0x08 resource id of the item node
    int m_unkC;                     // 0x0C resource id of the animation node
    char _pad010[0x14 - 0x10];
};
extern ItemEntry ItemTable[0x3C];

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern int mbHard__15EntityBaseClass;
extern "C" void memcpy(void *, const void *, unsigned int);
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("Peddler.cpp", line, #cond))
#define PFLD(T, off) (*(T *)((char *)this + (off)))
// Player is declared only for ValidateItem; the entity manager state at 0x505C is passed as its this.
class Player {
public:
    int ValidateItem(int nItem);
};
extern "C" int Find__6PArrayFPv(void *pThis, void *pItem);
extern "C" void Remove__6PArrayFPv(void *pThis, void *pItem);
extern "C" void AddMeshLayer__9InterfaceFP6PMNode(void *pThis, PMNode *pNode);
extern "C" void DeleteMeshLayer__9InterfaceFP6PMNode(void *pThis, PMNode *pNode);
extern unsigned char gInterface[];
extern float gUnitMatrix[16];
extern "C" float Round180__Ff(float fAngle);
extern "C" float FastMath_Fabs__Ff(float fVal);
extern "C" void *__nw__FUi(unsigned int nSize);
inline void *operator new(unsigned int, void *pWhere) { return pWhere; }
extern "C" void CheckVariable__15EntityBaseClassFii(void *pThis, int nFlags, int nValue);
extern unsigned char __vt__9PResource[];
extern unsigned char __vt__6PMNode[];
extern unsigned char __vt__9PMeshNode[];
extern "C" void sceVu0UnitMatrix(void *pDst);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void InitMembers__6PMNodeFv(void *pThis);
extern "C" void InitMembers__9PMeshNodeFv(void *pThis);
extern "C" void FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(void *pThis, float fX, float fY, bool bFlag, int eColor);
class PMNode;
extern "C" PMNode *__ct__9PMeshNodeFR9PMeshNode(PMNode *pThis, PMNode *pSrc);
extern "C" void Add__6PArrayFPv(void *pThis, void *pItem);
extern "C" PMNode *GetResource__16PResourceManagerFUib(void *pThis, unsigned int nId, bool bLocal);
extern "C" void SetAnimLoopCount__6PMNodeFib(void *pThis, int nCount, bool bFlag);
extern "C" void EnableAnim__6PMNodeFbb(void *pThis, bool bA, bool bB);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" void sceVu0Normalize(float *pDst, float *pSrc);
extern "C" void sceVu0ScaleVectorXYZ(float *pDst, float *pSrc, float fScale);
extern "C" void sceVu0ScaleVector(float *pDst, float *pSrc, float fScale);
extern "C" float atan2f(float fY, float fX);
extern "C" void TakeControlOfCamera__9CameraAPIFP15EntityBaseClassb(void *pThis, void *pEntity, bool bTake);
extern "C" void SetCameraLookAtParams__9CameraAPIFP15EntityBaseClassPfPf(void *pThis, void *pEntity, float *pPos, float *pVec);
extern "C" unsigned char mCameraAPI__13EntityManager;
extern "C" void sceVu0AddVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void ReleaseControlOfCamera__9CameraAPIFP15EntityBaseClassb(void *pThis, void *pEntity, bool bRelease);
extern "C" void BuildDispList__9PSkeletonFv(void *pThis);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(void *pThis, EntityBaseClass *pEntity);
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, void *pPos, int eObjType, int eWeaponType, bool bFlag);

// Slot object held at 0x22C; Release is virtual number 0, the first declared virtual.
class PeddlerSlotObject {
public:
    virtual void Release(int nMode);
};

// Sequence record, 88 bytes; the PeddlerSeqData symbol holds two of them (176 bytes).
struct PeddlerSeq {
    char _pad000[0x44];
    float m_unk44;                  // 0x44
    float m_unk48;                  // 0x48
    float m_unk4C;                  // 0x4C
    char _pad050[0x58 - 0x50];
};
extern PeddlerSeq PeddlerSeqData[2];

// Only the PMNode fields used here; offsets follow PMNode.h.
class PMNode {
public:
    // Virtual numbers follow the vtable slots: destructor 0 (0x08), Render 1 (0x0C), ... slot 0x20 is number 6.
    virtual ~PMNode();
    virtual void Render();
    virtual void SetFrameTime();
    virtual void CreateObjectDisplayList();
    virtual void Animate(int, int, int, float, float);
    virtual void SetAllAnimFlags();
    virtual int Slot20(void *pNode);
    void ScaleSet(float a, float b, float c, float d);
    int m_unk04;                    // 0x04 node type; 2 = list head
    char _pad008[0x0C];
    int m_unk14;                    // 0x14 list count
    int m_unk18;                    // 0x18 list index
    PMNode **m_unk1C;               // 0x1C list entries
    char _pad020[0x0C];
    float m_unk2C;                  // 0x2C fade value
    char _pad030[0x3E - 0x30];
    unsigned char m_unk3E;          // 0x3E flags; 0x08 = scale set
    char _pad03F[0x40 - 0x3F];
    char _pad040[0x40];
    char _pad080[0x20];
    float m_unkA0[4];               // 0xA0 animated scale vector
};

// Engine size is unknown; the placeholder keeps gEng out of small data (threshold 8 bytes).
class Engine {
public:
    char _pad000[0x1E8];
    float m_unk1E8;                 // 0x1E8
    char _pad1EC[0x10];
};
extern Engine gEng;

class PArray;
class EntityManagerState {
public:
    char _pad000[0x3C];
    char *m_unk3C;                  // 0x03C target object with 0x80 vector
    char _pad040[0x229 - 0x040];
    signed char m_unk229;           // 0x229 compared against 4
};
class EntityManager {
public:
    char _pad000[0x505C];
    EntityManagerState *m_unk505C;  // 0x505C
};
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(EntityManager *pThis, int eLoadClass, PArray *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);

struct tagWaypointGroup {
    char _pad000[4];
    unsigned int m_unk4;            // 0x04 waypoint count
};
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void Add2DependencyList__13EntityManagerFUiUi(EntityManager *pThis, unsigned int nFrom, unsigned int nTo);
extern unsigned char __vt__7Peddler[];
extern "C" void *__dt__15EntityBaseClassFv(EntityBaseClass *pThis, short nFlag);
extern "C" void __dl__FPv(void *pMem);

// Entity instance as seen through its vtable. Only slots 0x30 (void, one int) and 0x44 (int) are called here; the other slots are placeholders that keep those two at their offsets.
class EntityInstance {
public:
    virtual void Slot08() {}
    virtual void Slot0C() {}
    virtual void Slot10() {}
    virtual void Slot14() {}
    virtual void Slot18() {}
    virtual void Slot1C() {}
    virtual void Slot20() {}
    virtual void Slot24() {}
    virtual void Slot28() {}
    virtual void Slot2C() {}
    virtual void SetSlot30(int nArg) {}
    virtual void Slot34() {}
    virtual void Slot38() {}
    virtual void Slot3C() {}
    virtual void Slot40() {}
    virtual int Slot44() { return 0; }

    unsigned int m_unk4;            // 0x04
    char _pad008[0x1A - 0x08];
    unsigned char m_unk1A;          // 0x1A
};

extern "C" void OnInnocentAttack__15EntityBaseClassFP15EntityBaseClassi(void *pThis, EntityBaseClass *pAttacker, int nDamage);

// FUNCTION: 0x001D04F0 GetHealth__7PeddlerFv
int Peddler::GetHealth() {
    return m_unk1CC;
}

// FUNCTION: 0x001D0500 GetClassName__7PeddlerFv
const char *Peddler::GetClassName() {
    return "Peddler";
}

// FUNCTION: 0x001D0510 NeedsToBeWoken__7PeddlerFv
int Peddler::NeedsToBeWoken() {
    return *(int *)((char *)this + 0x208);
}

// FUNCTION: 0x001D0520 GetWokenVarPos__7PeddlerFv
int Peddler::GetWokenVarPos() {
    return 16;
}

// FUNCTION: 0x001D0530 EnemiesInCheckRadius__7PeddlerFv
int Peddler::EnemiesInCheckRadius() {
    int result;

    if (mpEntMgr__15EntityBaseClass->m_unk505C->m_unk229 == 4 || ActivatedEnemiesDead() == 0) {
        result = 1;
    } else {
        float box[4];

        box[0] = m_unk1E4;
        box[1] = m_unk1E8;
        box[2] = m_unk1EC;
        box[3] = m_unk1F0;
        result = GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, 0, &box, box[3], -2, false, true);
    }
    return result;
}

// FUNCTION: 0x001D05D0 TrappedEntityRemoved__7PeddlerFv
bool Peddler::TrappedEntityRemoved() {
    return !InstanceIsValid__15EntityBaseClassFUi(m_unk200);
}

// DRAFT: 0x001D0600 ActivatedEnemiesDead__7PeddlerFv
// note: 47 diff lines; original frame 0x50 keeps a slot pointer in s3 (saves ra+s0..s3), ours frame 0x40 with s0..s2 only. Tried: index loop (47), pointer+counter loop (48), slot-address local (47), unsigned counter (47).
int Peddler::ActivatedEnemiesDead() {
    int i;

    if (m_unk294 == 0) {
        return 1;
    }
    if (m_unk2A6 == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        if (m_unk2C8[i] != 0) {
            void *pInst = (void *)InstanceIsValid__15EntityBaseClassFUi(m_unk2C8[i]);
            if (pInst != 0) {
                int (*pfn)(void *) = *(int (**)(void *))((char *)*(void **)pInst + 0x34);
                if (pfn(pInst) > 0) {
                    return 0;
                }
            }
            m_unk2C8[i] = 0;
        }
    }
    return 1;
}

// FUNCTION: 0x001D06C0 OutputDebug__7PeddlerFv
void Peddler::OutputDebug() {
    char buf[0x100];

    sprintf(buf, "State = %d\n", m_unk20);
    gDebug.DebugDisp(buf);
    sprintf(buf, "Wp id = %d\n", m_unk288);
    gDebug.DebugDisp(buf);
}

// FUNCTION: 0x001D0730 ActivateAttackingEnemies__7PeddlerFv
void Peddler::ActivateAttackingEnemies() {
    EntityBaseClass **ppSlot = m_unk1F4;
    int i = 0;
    EntityBaseClass *pEnt;
    EntityInstance *pInst;
    unsigned int nOff = 0;
    do {
        pEnt = *ppSlot;
        if (pEnt != 0) {
            pInst = (EntityInstance *)InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pInst != 0) {
                if (pInst->Slot44() == 0) {
                    pInst->m_unk1A = 1;
                }
                pInst->SetSlot30(*(int *)((char *)this + 0xC));
                *(EntityBaseClass **)((char *)this + nOff + 0x2C8) = pEnt;
                Add2DependencyList__13EntityManagerFUiUi(mpEntMgr__15EntityBaseClass, pInst->m_unk4, *(unsigned int *)((char *)this + 4));
            }
        }
        i++;
        nOff += 4;
        ppSlot++;
    } while (i < 3);
    m_unk2A6 = 1;
}

// FUNCTION: 0x001D0810 GetNextPosition__7PeddlerFRA4_f
int Peddler::GetNextPosition(float (&afPos)[4]) {
    tagWaypointGroup *pGroup;
    unsigned char bFlag;
    float *pWaypoint;

    pGroup = m_unk284;
    if (pGroup != 0) {
        if (m_unk288 < pGroup->m_unk4) {
            pWaypoint = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, m_unk288, bFlag);
            afPos[0] = pWaypoint[0];
            afPos[1] = pWaypoint[1];
            afPos[2] = pWaypoint[2];
            m_unk288++;
            return 1;
        }
    }
    return 0;
}

// Reinterprets a bit pattern as float so the literal is built from lui/ori/mtc1, as the original does.
static inline float FloatBits(unsigned int uBits) {
    union {
        unsigned int u;
        float f;
    } conv;
    conv.u = uBits;
    return conv.f;
}

// FUNCTION: 0x001D08A0 IsAlive__7PeddlerFv
int Peddler::IsAlive() {
    int bAlive;
    if (m_unk1CC <= 0) {
        bAlive = 0;
    } else {
        bAlive = 1;
    }
    return bAlive;
}

// DRAFT: 0x001D08C0 Hide__12PeddlerItemsFv
// note: 48 diff lines; original keeps this in s1 and the 0x3DAAAAAB literal in f13, ours uses s2 and spills the literal to the stack; FloatBits literal and early hoist tried.
int PeddlerItems::Hide() {
    float fStepScale = FloatBits(0x3DAAAAAB);
    float fScale;
    float fFade;
    int bFadeDone;
    int bScaleDone;

    fScale = m_unk4->m_unkA0[0];
    fFade = m_unk4->m_unk2C;
    m_unk8 = 0.0f;
    m_unkC = 0.0f;
    bScaleDone = AnimateFloat(fScale, m_unk8, fStepScale) & 0xFF;
    m_unk4->ScaleSet(fScale, fScale, fScale, 1.0f);
    bFadeDone = AnimateFloat(fFade, m_unkC, FloatBits(0x3CCCCCCD)) & 0xFF;
    m_unk4->m_unk2C = fFade;
    ((void (*)(PMNode *, int, int, int, float, float))(*(void ***)m_unk0)[6])(m_unk0, 0, 0, 0, 0.0f, 1.0f);
    return (bScaleDone != 0) ? (bFadeDone != 0) : 0;
}

// DRAFT: 0x001D09B0 ReplaceItem__12PeddlerItemsFi
// note: DIFF 95; frame 0x50 vs 0x60 and s2 (ItemTable entry) not kept live. Tried: direct ItemTable indexing (114), 128-bit locals as arrays (114), char[16] spills (95, kept), local entry pointer after delete (101), entry pointer at top (107).
void PeddlerItems::ReplaceItem(int nItem) {
    char saved80[16];
    char saved90[16];

    if (m_unk4 == 0) {
        CdsAssert("Peddler.cpp", 0x6DF, "m_pItemNode");
    }
    if (m_unk0 == 0) {
        CdsAssert("Peddler.cpp", 0x6E0, "m_pRotateNode");
    }
    Remove__6PArrayFPv((char *)m_unk0 + 0x14, m_unk4);
    *(u_long128 *)saved80 = *(u_long128 *)((char *)m_unk4 + 0x80);
    *(u_long128 *)saved90 = *(u_long128 *)((char *)m_unk4 + 0x90);
    if (m_unk4 != 0) {
        delete m_unk4;
    }
    m_unk4 = GetResource__16PResourceManagerFUib(&gEng, ItemTable[nItem & 0x3F].m_unk8, false);
    if (m_unk4 == 0) {
        CdsAssert("Peddler.cpp", 0x6EA, "m_pItemNode");
    }
    if (m_unk4->Slot20(GetResource__16PResourceManagerFUib(&gEng, ItemTable[nItem & 0x3F].m_unkC, false)) == 0 && "Couldn't add animation") {
        CdsAssert("Peddler.cpp", 0x6EE, "!\"Couldn't add animation\"");
    }
    SetAnimLoopCount__6PMNodeFib(m_unk4, 0, true);
    EnableAnim__6PMNodeFbb(m_unk4, true, true);
    *(u_long128 *)((char *)m_unk4 + 0x80) = *(u_long128 *)saved80;
    m_unk4->m_unk3E |= 8;
    *(u_long128 *)((char *)m_unk4 + 0x90) = *(u_long128 *)saved90;
    m_unk4->m_unk3E |= 8;
    Add__6PArrayFPv((char *)m_unk0 + 0x14, m_unk4);
}

// FUNCTION: 0x001D0B80 CopyItemMesh__12PeddlerItemsFi
PMNode *PeddlerItems::CopyItemMesh(int nIndex) {
    bool bOk = m_unk4 && m_unk0;
    if (!bOk) {
        CdsAssert("Peddler.cpp", 0x6C9, "m_pItemNode && m_pRotateNode");
    }
    PMNode *pCopy = (PMNode *)__nw__FUi(0x140);
    if (pCopy) {
        pCopy = __ct__9PMeshNodeFR9PMeshNode(pCopy, m_unk4);
    }
    pCopy->ScaleSet(0.75f, 0.75f, 0.75f, 1.0f);
    PeddlerSeq *pSeq = &PeddlerSeqData[nIndex];
    *(float *)((char *)pCopy + 0x80) = pSeq->m_unk44;
    *(float *)((char *)pCopy + 0x84) = pSeq->m_unk48;
    *(int *)((char *)pCopy + 0x88) = 0;
    *(int *)((char *)pCopy + 0x90) = 0;
    *(unsigned int *)((char *)pCopy + 0x94) = 0x43870000;
    *(float *)((char *)pCopy + 0x98) = pSeq->m_unk4C;
    return pCopy;
}

// FUNCTION: 0x001D0C80 EnableDisplay__12PeddlerItemsFb
void PeddlerItems::EnableDisplay(bool bEnable) {
    if (m_unk0 == 0) {
        CdsAssert("Peddler.cpp", 0x6B9, "m_pRotateNode");
    }
    if (bEnable) {
        if (Find__6PArrayFPv(gInterface + 0x404, m_unk0) < 0) {
            AddMeshLayer__9InterfaceFP6PMNode(gInterface, m_unk0);
        }
    } else {
        Remove__6PArrayFPv(gInterface + 0x404, m_unk0);
    }
}

// DRAFT: 0x001D0D20 Reset__12PeddlerItemsFf
// note: 27 diff lines; the original defers the -R negation until after the m_unk0 block-2 store and keeps R in f12, ours negates right after the call and reorders the m_unk4 block. Tried: cached m_unk4 pointer (38), cached pItem for block 1 (32), pItem for block 2 (57), fRot local for R and -R (27).
void PeddlerItems::Reset(float fAngle) {
    float afVec[4];
    PMNode *pRotate = m_unk4;

    *(u_long128 *)(pRotate->_pad080) = *(u_long128 *)&gUnitMatrix[0];
    pRotate->m_unk3E |= 8;
    afVec[0] = 0.0f;
    afVec[1] = 7.0f;
    afVec[2] = 0.0f;
    afVec[3] = 1.0f;
    PMNode *pItem = m_unk0;
    *(u_long128 *)(pItem->_pad080) = *(u_long128 *)afVec;
    pItem->m_unk3E |= 8;
    afVec[1] = 0.0f;
    float fRot = Round180__Ff(fAngle);
    afVec[2] = fRot;
    *(u_long128 *)(m_unk0->_pad080 + 0x10) = *(u_long128 *)afVec;
    m_unk0->m_unk3E |= 8;
    afVec[2] = -fRot;
    *(u_long128 *)(m_unk4->_pad080 + 0x10) = *(u_long128 *)afVec;
    m_unk4->m_unk3E |= 8;
    m_unk4->ScaleSet(0.0f, 0.0f, 0.0f, 1.0f);
    m_unk4->m_unk2C = 0.0f;
}

// DRAFT: 0x001D0E10 AnimateFloat__12PeddlerItemsFRfff
// note: 33 diff lines; original keeps fDelta in f13 (fStep's register) and uses addiu flags, the -1.0f negate is mul.s with f0 as first operand, and the branch layout differs. Tried: int/unsigned char/bool flags (33 each), operand swap (33), fDelta declared first (33).
int PeddlerItems::AnimateFloat(float &fVal, float fTarget, float fStep) {
    float fDelta;
    bool bUp;
    bool bDone;

    bUp = 1;
    fDelta = fStep * gEng.m_unk1E8;
    if (!(fVal < fTarget)) {
        bUp = 0;
    }
    if (bUp == 0) {
        fDelta *= -1.0f;
    }
    fVal += fDelta;
    bDone = 1;
    if (bUp != 0) {
        if (fVal <= fTarget) {
            bDone = 0;
        }
    } else {
        if (!(fVal < fTarget)) {
            bDone = 0;
        }
    }
    if (bDone != 0) {
        fVal = fTarget;
        return 1;
    }
    return 0;
}

// FUNCTION: 0x001D0EC0 AnimateVector__12PeddlerItemsFRA4_fRA4_ff
int PeddlerItems::AnimateVector(float (&afVec)[4], float (&afTarget)[4], float fStep) {
    u_long128 qDelta;
    u_long128 qOrig;
    float fOldLenSq;

    float fScale = fStep;
    fScale = fScale * gEng.m_unk1E8;
    *(u_long128 *)&qOrig = *(u_long128 *)afVec;
    sceVu0SubVector((float *)&qDelta, afTarget, afVec);
    sceVu0Normalize((float *)&qDelta, (float *)&qDelta);
    sceVu0ScaleVectorXYZ((float *)&qDelta, (float *)&qDelta, fScale);
    sceVu0AddVector(afVec, afVec, (float *)&qDelta);
    sceVu0SubVector((float *)&qDelta, afVec, (float *)&qOrig);
    sceVu0SubVector((float *)&qOrig, afTarget, (float *)&qOrig);
    fOldLenSq = sceVu0InnerProduct((float *)&qDelta, (float *)&qDelta);
    if (sceVu0InnerProduct((float *)&qOrig, (float *)&qOrig) <= fOldLenSq) {
        afVec[0] = afTarget[0];
        afVec[1] = afTarget[1];
        afVec[2] = afTarget[2];
        return 1;
    }
    return 0;
}

// DRAFT: 0x001D0FB0 Animate__12PeddlerItemsFffff
// note: 49 words differ: fDelta register placement (f12 copied to f26), lwc1 order for fScaleB, virtual Animate call scheduling, sltu bool tail at 0x2B4; variants tried: afScale[4], scalar fScaleA/B, inline fabs recompute (best 49)
int PeddlerItems::Animate(float fA, float fB, float fC, float fD) {
    float afSp80[4];
    float afSp90[4];
    float fScaleA, fScaleB;
    float fDelta, fWrap, fAbs, fAbsW, fSign;
    unsigned char bDone0, bDone1, bDone2, bDone3;
    PMNode *pNode;

    fScaleA = m_unk4->m_unkA0[0];
    fScaleB = m_unk4->m_unk2C;
    *(u_long128 *)afSp80 = *(u_long128 *)(m_unk4->_pad080);
    *(u_long128 *)afSp90 = *(u_long128 *)(m_unk0->_pad080 + 0x10);

    fDelta = fB - afSp90[2];
    fWrap = 360.0f - FastMath_Fabs__Ff(fDelta);
    if (FastMath_Fabs__Ff(fDelta) > FastMath_Fabs__Ff(fWrap)) {
        fSign = (fDelta < 0.0f) ? -1.0f : 1.0f;
        afSp90[2] = fB + fWrap * fSign;
    } else if (FastMath_Fabs__Ff(fDelta) == FastMath_Fabs__Ff(fWrap)) {
        if (fB > afSp90[2]) {
            fSign = (fDelta < 0.0f) ? -1.0f : 1.0f;
            afSp90[2] = fB + fWrap * fSign;
        }
    }

    m_unk10[0] = fA;
    m_unk20[2] = fB;
    m_unk8 = fC;
    m_unkC = fD;
    bDone0 = AnimateVector(afSp80, m_unk10, 0.4f);
    pNode = m_unk4;
    *(u_long128 *)(pNode->_pad080) = *(u_long128 *)afSp80;
    pNode->m_unk3E |= 0x08;
    bDone1 = AnimateVector(afSp90, m_unk20, 3.5f);
    pNode = m_unk0;
    *(u_long128 *)(pNode->_pad080 + 0x10) = *(u_long128 *)afSp90;
    pNode->m_unk3E |= 0x08;
    afSp90[2] *= -1.0f;
    pNode = m_unk4;
    *(u_long128 *)(pNode->_pad080 + 0x10) = *(u_long128 *)afSp90;
    pNode->m_unk3E |= 0x08;
    bDone2 = AnimateFloat(fScaleA, m_unk8, 0.25f);
    m_unk4->ScaleSet(fScaleA, fScaleA, fScaleA, 1.0f);
    bDone3 = AnimateFloat(fScaleB, m_unkC, 0.1f);
    pNode = m_unk4;
    if (pNode->m_unk04 == 2) {
        pNode->m_unk18 = 0;
        pNode = (pNode->m_unk14 != 0) ? pNode->m_unk1C[0] : 0;
        pNode->m_unk2C = fScaleB;
    } else {
        pNode->m_unk2C = fScaleB;
    }
    m_unk0->Animate(0, 0, 0, 0.0f, 1.0f);
    return bDone0 && bDone1 && bDone2 && bDone3;
}

// FUNCTION: 0x001D12F0 __dt__12PeddlerItemsFv
PeddlerItems::~PeddlerItems() {
    if (m_unk0 != 0) {
        DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, m_unk0);
        m_unk0 = 0;
        m_unk4 = 0;
    }
}

// DRAFT: 0x001D1360 __ct__12PeddlerItemsFi
PeddlerItems::PeddlerItems(int nIndex) {
    ItemEntry entry = ItemTable[nIndex & 0x3F];
    *(u_long128 *)((char *)this + 0x10) = *(u_long128 *)&gUnitMatrix[12];
    *(u_long128 *)((char *)this + 0x20) = *(u_long128 *)&gUnitMatrix[12];
    m_unk8 = 0.0f;
    m_unkC = 0.0f;
    char *volatile pMesh = (char *)__nw__FUi(0x140);
    if (pMesh != 0) {
        char *volatile pNode = pMesh;
        *(void **)pNode = (void *)__vt__9PResource;
        *(int *)(pNode + 4) = 0;
        *(void **)pNode = (void *)__vt__6PMNode;
        __ct__6PArrayFv(pNode + 0x14);
        sceVu0UnitMatrix(pNode + 0x40);
        __ct__6PArrayFv(pNode + 0xD8);
        InitMembers__6PMNodeFv(pNode);
        *(void **)pMesh = (void *)__vt__9PMeshNode;
        __ct__6PArrayFv(pMesh + 0x130);
        InitMembers__9PMeshNodeFv(pMesh);
    }
    m_unk0 = (PMNode *)pMesh;
    m_unk4 = (PMNode *)GetResource__16PResourceManagerFUib((void *)((char *)&gEng + 0x188A4), entry.m_unk8, false);
    if (m_unk4 == 0) {
        CdsAssert("Peddler.cpp", 0x60B, "m_pItemNode");
    }
    if (m_unk4->Slot20(GetResource__16PResourceManagerFUib((void *)((char *)&gEng + 0x188A4), entry.m_unkC, false)) == 0 && "Couldn't add animation") {
        CdsAssert("Peddler.cpp", 0x60F, "!\"Couldn't add animation\"");
    }
    SetAnimLoopCount__6PMNodeFib(m_unk4, 0, true);
    EnableAnim__6PMNodeFbb(m_unk4, true, true);
    Add__6PArrayFPv((char *)m_unk0 + 0x14, m_unk4);
}

// DRAFT: 0x001D1550 LookAtPeddler__7PeddlerFv
// note: 55 differing lines; 57.295776f is pooled (lwc1 gp) where the original uses lui/ori/mtc1; 12-byte size gap. Tried: s0 reuse for m_unk38 (56), split atan2 into a local (55), constant in a local (55).
void Peddler::LookAtPeddler() {
    float afPos[4];
    float afVec[4];
    char *pObj;
    char *pTarget;
    EntityManagerState *pState;
    float fYaw;

    TakeControlOfCamera__9CameraAPIFP15EntityBaseClassb(&mCameraAPI__13EntityManager, this, false);
    pObj = m_unk3C;
    if (m_unk214 != 0) {
        *(u_long128 *)afVec = *(u_long128 *)(pObj + 0x80);
        pState = mpEntMgr__15EntityBaseClass->m_unk505C;
        if (pState->m_unk3C != 0) {
            pTarget = pState->m_unk3C + 0x80;
        } else {
            pTarget = (char *)pState + 0x190;
        }
        sceVu0SubVector(afPos, afVec, (float *)pTarget);
        fYaw = Round180__Ff(57.295776f * atan2f(afPos[0], afPos[2]));
        *(float *)(pObj + 0x94) = fYaw;
        *(unsigned char *)(pObj + 0x3E) |= 8;
        *(float *)((char *)m_unk38 + 0x11C) = Round180__Ff(fYaw);
        afPos[1] = 0.0f;
        sceVu0Normalize(afPos, afPos);
        sceVu0ScaleVector(afPos, afPos, -5.0f);
    } else {
        *(u_long128 *)afVec = *(u_long128 *)(pObj + 0x70);
        sceVu0ScaleVector(afPos, (float *)(pObj + 0x60), -5.0f);
    }
    afPos[1] = 1.0f;
    afVec[1] += 2.25f;
    sceVu0AddVector(afPos, afPos, afVec);
    SetCameraLookAtParams__9CameraAPIFP15EntityBaseClassPfPf(&mCameraAPI__13EntityManager, this, afPos, afVec);
    gInterface[0x1997] = 0;
}

// DRAFT: 0x001D16A0 AnimateItems__7PeddlerFv
// note: DIFF 22 (permute.py). Remaining: bDone init daddiu vs addiu (bool bDone gives 72), slti at vs v0 at loop top, float ternary arg order (original loads the -16.5/-14.0 pair first), tail call order. Tried: declaration order, fA local (DIFF 58), split assert (124), tail reorder.
int Peddler::AnimateItems() {
    int nSlot;
    int nStep;
    int bDone;

    nSlot = m_unk248;
    nStep = 0;
    bDone = 1;
    do {
        if (!(nSlot < 5 && m_unk218[nSlot]->m_unk4)) {
            CdsAssert("Peddler.cpp", 0x59F, "iItem < PEDDLER_MAX_ITEMS && m_pItems[iItem]->IsValid()");
        }
        bDone = bDone & m_unk218[nSlot]->Animate(
            (nSlot == m_unk248) ? -16.5f : -14.0f,
            90.0f + 360.0f * (float)nStep / 5.0f,
            (nSlot == m_unk248) ? 6.0f : 2.5f,
            (nSlot == m_unk248) ? 1.0f : 0.5f) & 0xFF;
        nSlot = (nSlot + 1) % 5;
        nStep++;
        if (m_unk218[nSlot] == 0) {
            break;
        }
        if (nSlot >= 5) {
            break;
        }
    } while (nSlot != m_unk248);

    if (bDone != 0) {
        unsigned int nBits;
        char *pState;

        pState = (char *)mpEntMgr__15EntityBaseClass->m_unk505C;
        nBits = *(unsigned short *)(pState + 0x1B8);
        if (0 == nBits) {
            nBits = *(unsigned short *)(pState + 0x1B0) & 0xA0;
        }
        if (nBits != 0) {
            m_unk248 += (nBits & 0x80) ? 1 : -1;
            if ((unsigned int)m_unk248 >= 5) {
                m_unk248 = (nBits & 0x80) ? 0 : 4;
                SetState__15EntityBaseClassFi(this, 0x13);
            }
            bDone = 0;
            PlaySound__15EntityBaseClassFUi(this, 0x3A);
        }
    }
    return bDone;
}

// DRAFT: 0x001D18A0 HideItems__7PeddlerFv
// note: 6 diff lines; this and slot pointer swap s3/s4 (orig this=s4, slot=s3). Tried 4 local orders (ppSlot-first best at 6), bool bAll (23), block-scoped ppSlot (13), signed nOff (6), char* base local (6), int bAll=true (6).
int Peddler::HideItems() {
    PeddlerItems **ppSlot;
    int bAll;
    int i;
    unsigned int nOff;

    nOff = 0;
    i = 0;
    bAll = 1;
    do {
        ppSlot = (PeddlerItems **)((char *)this + nOff + 0x218);
        if (*ppSlot != 0) {
            if ((*ppSlot)->m_unk4 == 0) {
                CdsAssert("Peddler.cpp", 0x58E, "m_pItems[iItem]->IsValid()");
            }
            bAll = bAll & (*ppSlot)->Hide() & 0xFF;
        }
        i++;
        nOff += 4;
    } while (i < 5);
    return bAll;
}

// DRAFT: 0x001D1950 ExitPeddlerView__7PeddlerFv
// note: DIFF 24 words with the plain 0.85f literal (was 56 with the bit pattern); remaining differences are register allocation (this in s3, orig s0) and frame size. Tried 3 declaration orders.
void Peddler::ExitPeddlerView() {
    int i;
    unsigned int nOff;
    PeddlerItems **ppSlot;

    if (m_unk22C != 0) {
        Remove__6PArrayFPv((char *)m_unk24C + 0x14, (void *)m_unk22C);
        BuildDispList__9PSkeletonFv(m_unk3C);
        if (m_unk22C != 0) {
            ((PeddlerSlotObject *)m_unk22C)->Release(1);
        }
        m_unk22C = 0;
    }
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 0.0f, 0.85f, 1, 0);
    ReleaseControlOfCamera__9CameraAPIFP15EntityBaseClassb(&mCameraAPI__13EntityManager, this, 1);

    i = 0;
    nOff = 0;
    ppSlot = (PeddlerItems **)((char *)this + nOff + 0x218);
    while (*ppSlot != 0 && i < 5) {
        if (!(i < 5 && (*ppSlot)->m_unk4 != 0)) {
            CdsAssert("Peddler.cpp", 0x57F, "i < PEDDLER_MAX_ITEMS && m_pItems[i]->IsValid()");
        }
        (*ppSlot)->EnableDisplay(0);
        nOff += 4;
        i++;
        ppSlot = (PeddlerItems **)((char *)this + nOff + 0x218);
    }
    gInterface[0x1997] = 1;
}

// DRAFT: 0x001D1A80 InitItems__7PeddlerFv
// note: 39 diff lines; frame 0x80 vs 0x70, this/pnId in s4/s3 vs s3/s4, add.s operand order; tried FloatBits literals, pnId pointer local, decl reorder, zeroing order, plain literals (kept), operand swap (no change)
void Peddler::InitItems() {
    int i;
    unsigned int nOff;
    PeddlerItems **ppSlot;
    int *pnId;
    PeddlerItems *pItem;
    float fAngle;

    ValidateItems();
    fAngle = 90.0f;
    i = 0;
    nOff = 0;
    do {
        ppSlot = (PeddlerItems **)((char *)this + nOff + 0x218);
        pnId = (int *)((char *)this + nOff + 0x230);
        if (*ppSlot == 0) {
            CheckVariable__15EntityBaseClassFii((void *)this, *pnId & 0x3F, 0x3C);
            pItem = (PeddlerItems *)__nw__FUi(0x30);
            if (pItem != 0) {
                new (pItem) PeddlerItems(*pnId);
            }
            *ppSlot = pItem;
            (*ppSlot)->Reset(fAngle);
        }
        (*ppSlot)->EnableDisplay(1);
        i++;
        nOff += 4;
        fAngle = fAngle + 72.0f;
    } while (i < 5);
    FadeScreen__9InterfaceFffbQ29Interface10eFadeColor(gInterface, 16.0f, 0.85f, 1, 0);
}

// FUNCTION: 0x001D1B90 GetTallyType__7PeddlerFv
int Peddler::GetTallyType() {
    return 3;
}

// FUNCTION: 0x001D1BA0 SetEditableVars__7PeddlerFPc
void Peddler::SetEditableVars(char *pName) {
    memcpy((char *)this + 0x1B0, pName, 0x68);
    m_unk1CC *= 50;
    if (!mbHard__15EntityBaseClass) {
        m_unk1CC += 50;
    }
    m_unk2C8[0] = m_unk1F4[0];
    m_unk2C8[1] = m_unk1F4[1];
    m_unk2C8[2] = m_unk1F4[2];
    CheckVariable__15EntityBaseClassFii(this, m_unk1C4, 2);
    if (m_unk1D4 == 0.0f && m_unk1D8 == 0.0f && m_unk1DC == 0.0f) {
        CDS_ASSERT(0x541, !"eif 0, 0, 0 error.  see keith or ted");
        m_unk260 = ((float *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190))[0];
        m_unk264 = ((float *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190))[1];
        m_unk268 = ((float *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190))[2];
    } else {
        m_unk260 = m_unk1D4;
        m_unk264 = m_unk1D8;
        m_unk268 = m_unk1DC;
    }
    if (m_unk1E4 == 0.0f && m_unk1E8 == 0.0f && m_unk1EC == 0.0f) {
        m_unk1E4 = ((float *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190))[0];
        m_unk1E8 = ((float *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190))[1];
        m_unk1EC = ((float *)(m_unk3C ? m_unk3C + 0x80 : (char *)this + 0x190))[2];
    }
}

// FUNCTION: 0x001D1DB0 OnTimerEvent__7PeddlerFUi
void Peddler::OnTimerEvent(unsigned int arg0) {
    if (arg0 == (unsigned int)m_unk2C4) {
        m_unk29C = 1;
        return;
    }
    if (arg0 == (unsigned int)m_unk2BC) {
        m_unk2A7 = 1;
        return;
    }
    if (arg0 == (unsigned int)m_unk2D4) {
        m_unk2D8 = 1;
    }
}

// FUNCTION: 0x001D1DF0 OnAttackEvent__7PeddlerFP15EntityBaseClassi
void Peddler::OnAttackEvent(EntityBaseClass *pAttacker, int nDamage) {
    OnInnocentAttack__15EntityBaseClassFP15EntityBaseClassi(this, pAttacker, nDamage);
}

// DRAFT: 0x001D1E00 OnHitEvent__7PeddlerFP15EntityBaseClassiUiUi
// note: control flow matches; 75 lines differ. Ours has frame 0x50 with this in s3, original 0x60 with this in s4 (nResult kept live in s0). Tried: nResult returns, declaration reorder, m_unk1CC sense swap (76->75), literal returns.
int Peddler::OnHitEvent(EntityBaseClass *pEntity, int nArg1, unsigned int nEvent, unsigned int nArg2) {
    int nFlag = *(unsigned int *)((char *)pEntity + 0x10C) & 1;
    int nState = m_unk20;
    int nResult = 5;

    if (nEvent != 0x1FE) {
        if (nFlag == 0 && m_unk288 != m_unk28C) {
            return 5;
        }
        if (nState == 5) {
            return 5;
        }
        if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) != 0) {
            return 5;
        }
        if (nState < 15 || nFlag == 0) {
            if (m_unk214 != 0) {
                FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(this, pEntity);
            }
            if (nFlag == 0) {
                int nHits = m_unk1CC - nArg1;
                CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(this, 0, 3, 0, false);
                m_unk1CC = nHits;
            }
            if (m_unk1CC <= 0) {
                SetState__15EntityBaseClassFi(this, 4);
            } else {
                SetState__15EntityBaseClassFi(this, 5);
                m_unk298 = nState;
            }
            return 1;
        }
        return 0;
    }

    m_unkE8 = 3;
    if (nArg1 == -1) {
        SetState__15EntityBaseClassFi(this, 0x12);
        return 5;
    }
    m_unk246 = (unsigned short)nArg1;
    if (!(nArg1 & 0x1000)) {
        return nResult;
    }
    if (m_unk20 == 0x14) {
        return nResult;
    }
    SetState__15EntityBaseClassFi(this, 0x15);
    nResult = 1;
    return nResult;
}

// DRAFT: 0x001D1F90 FindItem__7PeddlerFi
// note: original has one extra nop after the increments (0x2C) before the loop test; 8 diff lines. Tried: index loop (large diff), p++ in body (10), while form (8), i++ in header with p++ in body (10).
unsigned int Peddler::FindItem(int arg0) {
    unsigned int i;
    ItemEntry *p;

    for (i = 0, p = ItemTable; i < 0x3C; i++, p++) {
        if (p->m_unk4 == arg0) {
            return i;
        }
    }
    return 0;
}

// DRAFT: 0x001D1FE0 ValidateItems__7PeddlerFv
// note: 46 diff lines; register assignment differs (orig nOff=s5, index=s3, entry=s4, counter=s2; ours nOff=s3, index=s5, entry=s2, counter=s4) and the prologue zeroing order. Tried: pEntry/pBase split (46), declaration reorder (50), signed nOff (46), inline slot pointer (46).
void Peddler::ValidateItems() {
    unsigned int *pIndex;
    ItemEntry *pEntry;
    Player *pPlayer;
    unsigned int nOff;
    int i;
    int nIndex;
    int nCur;
    int nResult;
    int *pSlot;

    nOff = 0;
    i = 0;
    pIndex = (unsigned int *)((char *)this + 0x1B0);
    pPlayer = (Player *)mpEntMgr__15EntityBaseClass->m_unk505C;
    do {
        pSlot = (int *)((char *)this + nOff + 0x230);
        nIndex = *(int *)pIndex;
        nCur = *pSlot;
        pIndex++;
        if ((unsigned int)nIndex >= 0x3C) {
            CdsAssert("Peddler.cpp", 0x4BB, "(u_int)iItem < PEDDLER_MAX");
        }
        pEntry = &ItemTable[nIndex];
        if (pEntry->m_unk4 != 0) {
            nResult = pPlayer->ValidateItem(pEntry->m_unk4);
            if (nResult < 0) {
                nIndex = nCur | 0x40;
            } else if (nResult != pEntry->m_unk4) {
                nIndex = FindItem(nResult);
            }
        }
        i++;
        *pSlot = nIndex;
        nOff += 4;
    } while (i < 5);
}

// DRAFT: 0x001D2100 Execute__7PeddlerFv
// note: switch on m_unk20; only case -1 transcribed (1498 diff words); cases 0-5, 11, 12, 15, 16, 18-22 are empty breaks, so the jump table and most of the function still differ.
void Peddler::Execute() {
    switch (this->m_unk20) {
    case -1: {
        int nItem;
        int nCount;
        int nOff;
        int nValid;
        unsigned int i;
        unsigned int nOffset;
        int *pSlot;
        int nWaypoint;
        char spC0[0x20];
        FillItems__6PlayerFPib(mpEntMgr__15EntityBaseClass->m_unk505C, (int *)((char *)this + 0x1B0), m_unk1C4 != 0);
        pSlot = (int *)((char *)this + 0x1B0);
        nCount = 0;
        nOff = 0;
        do {
            *pSlot = (int)GetItemID(*pSlot);
            nCount += 1;
            PFLD(int, 0x230 + nOff) = *pSlot;
            nOff += 4;
            pSlot += 1;
        } while (nCount < 5);
        PFLD(unsigned int, 0x10C) &= 0xF8FFFFFF;
        PFLD(unsigned int, 0x10C) |= 0x03000000;
        WriteApparitionData(3, ReadApparitionData(0, 0U), 0U);
        if (PFLD(Physics *, 0x38) == 0) {
            PFLD(Physics *, 0x38) = new Physics;
        }
        ((PFLD(Physics *, 0x38) != 0) ? (void)0 : CdsAssert("Peddler.cpp", 0x1A9, "mpPhysics"));
        PFLD(Physics *, 0x38)->SetPhysicsType(0x12U, 0);
        PFLD(unsigned char, 0x103) = 0xFE;
        PFLD(int, 0x104) = 0x40000000;
        PFLD(int, 0x108) = 0x40800000;
        m_unk2A7 = 1;
        PFLD(int, 0x2B0) = 0;
        m_unk2D8 = 1;
        PFLD(int, 0x2DC) = 0;
        m_unk294 = 0;
        nValid = 0;
        for (i = 0, nOffset = 0; i < 3U; i++, nOffset += 4) {
            EntityBaseClass *pInst = (EntityBaseClass *)PFLD(EntityBaseClass *, 0x2C8 + nOffset);
            if (pInst != 0 && InstanceIsValid__15EntityBaseClassFUi(pInst) != 0) {
                m_unk294 += 1;
            }
        }
        m_unk2A6 = (m_unk294 == 0) ? 1U : 0U;
        SetState(0);
        nWaypoint = PFLD(int, 0x1D0);
        if (nWaypoint >= 0) {
            m_unk284 = GetWaypointGroupInfo__15WaypointManagerFUi((char *)mpEntMgr__15EntityBaseClass + 0x30, (unsigned int)nWaypoint);
            if (m_unk284 == 0) {
                sprintf(spC0, "Innocent refers to bad waypoint group ( group id = %d )", PFLD(int, 0x1D0));
                CdsAssert("Peddler.cpp", 0x1CA, spC0);
            }
        }
        PFLD(unsigned char, 0x29F) = 0;
        PFLD(unsigned char, 0x2A2) = 0;
        m_unk288 = 0;
        if (m_unk284 != 0) {
            m_unk28C = *(int *)((char *)m_unk284 + 4);
        } else {
            m_unk28C = 0;
        }
        m_unk246 = 0;
        return;
    }
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 11:
        break;
    case 12:
        break;
    case 15:
        break;
    case 16:
        break;
    case 18:
        break;
    case 19:
        break;
    case 20:
        break;
    case 21:
        break;
    case 22:
        break;
    default:
        m_unk246 = 0;
        return;
    }
}

// DRAFT: 0x001D3870 __dt__7PeddlerFv
// note: 18 diff lines; register permutation of this/nFlag/slot (orig this=s4, nFlag=s3, slot=s2). Raw vtable store restored (50 without it). Tried 3 local orders (nOff,ppSlot,i best; ppSlot-first 20, nOff-first alt 18), for-loop form (18, no change).
extern "C" Peddler *__dt__7PeddlerFv(Peddler *pThis, short nFlag) {
    unsigned int nOff;
    PeddlerItems **ppSlot;
    int i;

    if (pThis != 0) {
        *(void **)pThis = __vt__7Peddler;
        i = 0;
        nOff = 0;
        do {
            ppSlot = (PeddlerItems **)((char *)pThis + nOff + 0x218);
            if (*ppSlot != 0) {
                if ((*ppSlot)->m_unk4 == 0) {
                    CdsAssert("Peddler.cpp", 0x17B, "m_pItems[i]->IsValid()");
                }
                delete *ppSlot;
                *ppSlot = 0;
            }
            i++;
            nOff += 4;
        } while (i < 5);
        __dt__15EntityBaseClassFv((EntityBaseClass *)pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x001D3950 __ct__7PeddlerFv
Peddler::Peddler() : EntityBaseClass((LoadClass)6, 0) {
    m_unk24C = 0;
    m_unk248 = 0;
    m_unk22C = 0;
    m_unk284 = 0;
    m_unk244 = 1;
    m_unk2A5 = 1;
    m_unkD4 = 0;
    m_unk2B4 = 0;
    m_unk2A8 = 0;
    memset(m_unk218, 0, 0x14);
}

// FUNCTION: 0x001D39F0 GetItemID__FUi
static unsigned int GetItemID(unsigned int arg0) {
    unsigned int i = 0;
    ItemEntry *p = ItemTable;

    do {
        if ((unsigned int)p->m_unk4 == arg0) {
            return i;
        }
        i++;
        p++;
    } while (i < 0x3C);
    return 0;
}
