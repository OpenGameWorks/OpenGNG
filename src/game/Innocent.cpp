// FLAGS: -str readonly
#include "types.h"
#include "Innocent.h"

// TODO(header): foreign declarations
// Only the fields read by AwardCheck are placed; the rest of EntityBaseClass is unknown.
class EntityBaseClass { public: char _pad000[4]; unsigned int m_unk4; char _pad008[8]; int m_unk10; };
class PMNode;
extern "C" void __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(void *pThis, int eLoadClass, unsigned int nFlags);
extern "C" void *__dt__15EntityBaseClassFv(void *pThis, short nFlag);
extern "C" void __dl__FPv(void *);
extern unsigned char __vt__8Innocent[];
extern "C" void SequenceViewer__15EntityBaseClassFPPUii(void *pThis, unsigned int **pTable, int nArg);
extern unsigned char SequenceTable[0x40];
// The second argument is not set by the caller; the original passes a1 through unchanged.
extern "C" EntityBaseClass *InstanceIsValid__15EntityBaseClassFUi(EntityBaseClass *pEntity);
extern "C" void ScaleSet__6PMNodeFffff(PMNode *pThis, float a, float b, float c, float d);
extern "C" void EnableSleep__15EntityBaseClassFbb(void *pThis, bool bA, bool bB);
extern "C" int ReadApparitionData__15EntityBaseClassFiUi(void *pThis, int nMode, unsigned int nId);
class Debug {
public:
    void DebugDisp(char *pText);
    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
};
extern Debug gDebug;
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
// Engine size is unknown; the placeholder keeps gEng out of small data (threshold 8 bytes).
class Engine { public: char _pad000[0x1E8]; float m_unk1E8; char _pad1EC[0x10]; };
extern Engine gEng;
extern "C" void StartCutCamera__6CameraFUib(void *pThis, unsigned int nId, bool bFlag);
class PArray;
class EntityManagerState { public: char _pad000[0x229]; signed char m_unk229; };
class EntityManager { public: char _pad000[0x505C]; EntityManagerState *m_unk505C; };
extern EntityManager *mpEntMgr__15EntityBaseClass;
extern "C" int GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(EntityManager *pThis, int eLoadClass, PArray *pArray, float (*pBox)[4], float fRadius, int nFlags, bool bFlagA, bool bFlagB);
struct tagWaypointGroup { char _pad000[4]; unsigned int m_unk4; };
extern "C" float *GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc(void *pThis, tagWaypointGroup *pGroup, unsigned int nIndex, unsigned char &rbFlag);

// FUNCTION: 0x0019F260 __dt__8InnocentFv
extern "C" void *__dt__8InnocentFv(void *pThis, short nFlag) {
    if (pThis != 0) {
        *(void **)pThis = __vt__8Innocent;
        __dt__15EntityBaseClassFv(pThis, 0);
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x0019F310 AnimationViewer__8InnocentFi
int Innocent::AnimationViewer(int arg0) {
    SequenceViewer__15EntityBaseClassFPPUii(this, (unsigned int **)SequenceTable, arg0);
    return 0x23;
}

// DRAFT: 0x0019F340 OnWakeEvent__8InnocentFv
// note: 13 words differ; original materializes 1.03f inline (lui/ori/mtc1 in the beqz delay slot), ours loads a pooled gp literal. Tried: function-scope local float, block-scope local float; count unchanged.
void Innocent::OnWakeEvent() {
    if (m_unk1B0 == 3) {
        PMNode *pNode = m_unk3C;
        if (pNode != 0) {
            ScaleSet__6PMNodeFffff(pNode, 1.03f, 1.03f, 1.03f, 1.0f);
        }
    }
}

// FUNCTION: 0x0019F520 EnemiesInCheckRadius__8InnocentFv
int Innocent::EnemiesInCheckRadius() {
    int result;
    if (mpEntMgr__15EntityBaseClass->m_unk505C->m_unk229 == 4 || ActivatedEnemiesDead() == 0) {
        result = 1;
    } else {
        float box[4];
        box[0] = m_unk1D0;
        box[1] = m_unk1D4;
        box[2] = m_unk1D8;
        box[3] = m_unk1DC;
        result = GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, 0, &box, box[3], -2, false, true);
    }
    return result;
}

// FUNCTION: 0x0019F5C0 TrappedEntityRemoved__8InnocentFv
int Innocent::TrappedEntityRemoved() {
    EntityBaseClass **pEnt;
    int i;
    i = 0;
    pEnt = m_unk1EC;
    do {
        if (*pEnt != 0 && InstanceIsValid__15EntityBaseClassFUi(*pEnt)) {
            return 0;
        }
        i++;
        pEnt++;
    } while (i < 3);
    return 1;
}

// FUNCTION: 0x0019F6F0 OutputDebug__8InnocentFv
void Innocent::OutputDebug() {
    char buf[0x100];
    sprintf(buf, "State = %d\n", m_unk20);
    gDebug.DebugDisp(buf);
    sprintf(buf, "Wp id = %d\n", m_unk254);
    gDebug.DebugDisp(buf);
}

// FUNCTION: 0x0019F940 OnTimerEvent__8InnocentFUi
void Innocent::OnTimerEvent(unsigned int nTimer) {
    if (nTimer == m_unk250) {
        m_unk266 = 1;
        return;
    }
    if (nTimer == m_unk284) {
        m_unk271 = 1;
        return;
    }
    if (nTimer == m_unk2A0) {
        EnableSleep__15EntityBaseClassFbb(this, false, false);
        StartCutCamera__6CameraFUib(&gEng, m_unk20C, false);
        m_unk17A = 0;
        return;
    }
    if (nTimer == m_unk27C) {
        m_unk278 = 1;
        return;
    }
    if (nTimer == m_unk288) {
        m_unk288 = 0;
    }
}

// FUNCTION: 0x0019FD70 GetNextPosition__8InnocentFRA4_f
int Innocent::GetNextPosition(float (&pos)[4]) {
    unsigned char bFlag;
    tagWaypointGroup *pGroup = (tagWaypointGroup *)m_unk290;
    if (pGroup != 0) {
        unsigned int nIndex = m_unk254;
        if (nIndex < pGroup->m_unk4) {
            float *pWp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, pGroup, nIndex, bFlag);
            pos[0] = pWp[0];
            pos[1] = pWp[1];
            pos[2] = pWp[2];
            pos[3] = 1.0f;
            m_unk254++;
            return 1;
        }
    }
    return 0;
}

// FUNCTION: 0x0019FE20 AwardCheck__8InnocentFv
int Innocent::AwardCheck() {
    if (ReadApparitionData__15EntityBaseClassFiUi(this, 0, 0) == 0 && ReadApparitionData__15EntityBaseClassFiUi(this, 1, 0) == 0) {
        return 1;
    }
    if (m_unk214 != 0) {
        EntityBaseClass *pValid = InstanceIsValid__15EntityBaseClassFUi(m_unk214);
        if (pValid != 0 && pValid->m_unk10 == 1) {
            return (ReadApparitionData__15EntityBaseClassFiUi(this, 0, pValid->m_unk4) != 0) ^ 1;
        }
    }
    return (m_unk26C != 0) ^ 1;
}

// FUNCTION: 0x001A1460 __ct__8InnocentFv
Innocent::Innocent() {
    __ct__15EntityBaseClassFQ215EntityBaseClass9LoadClassUi(this, 6, 0);
    m_unk0 = __vt__8Innocent;
    m_unk274 = 0;
    m_unkD4 = 0;
    m_unk272 = 0;
    m_unk288 = 0;
    m_unk103 = 0xFE;
    m_unk104 = 0x40000000;
    m_unk108 = 0x40800000;
}
