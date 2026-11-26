// FLAGS: -str readonly
#include "types.h"
#include "Innocent.h"

// TODO(header): foreign declarations
// Only the fields read by AwardCheck are placed; the rest of EntityBaseClass is unknown.
class EntityBaseClass { public: char _pad000[4]; unsigned int m_unk4; char _pad008[8]; int m_unk10; char _pad014[0x1A - 0x14]; unsigned char m_unk1A; char _pad01B[0x3C - 0x1B]; unsigned int m_unk3C; };
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
// Apparition handle list filled by GetAllActiveApparitionsInRadius (same layout as PArray's first words).
struct TempApparitionArray {
    int m_count;            // 0x00
    int m_unk04;            // 0x04 cleared with m_count
    unsigned int *m_pData;  // 0x08
    char _pad0C[4];
};
extern TempApparitionArray mTempArray__15EntityBaseClass;
extern "C" void *GetPtrToApparition__13EntityManagerFUi(EntityManager *pThis, unsigned int nId);
extern "C" void Add2DependencyList__13EntityManagerFUiUi(EntityManager *pThis, unsigned int nFrom, unsigned int nTo);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
extern "C" void CdsAssert__FPciPc(char *, int, char *);
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("Innocent.cpp", line, #cond))
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" int printf(const char *, ...);
extern "C" void SetState__15EntityBaseClassFi(void *pThis, int nState);
extern "C" void PlaySound__15EntityBaseClassFUi(void *pThis, unsigned int nSound);
extern "C" void FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(void *pThis, EntityBaseClass *pEntity);
extern "C" void CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(void *pThis, void *pPos, int eObjType, int eWeaponType, bool bFlag);
// Small type keeps mbHard in small data (gp-relative lw in the original).
extern int mbHard__15EntityBaseClass;
// Per-type sequence records, 0x4C bytes each, indexed by m_unk1B0; the size covers the ten types.
extern unsigned char InnocentSeqData[0x2B8];
extern int InnocentDialogID[0x100];
extern unsigned char gInterface[2656];
extern "C" void PlaySequence__15EntityBaseClassFPUi(void *pThis, unsigned int *pSeq);
extern "C" void WriteApparitionData__15EntityBaseClassFicUi(void *pThis, int nMode, char cValue, unsigned int nId);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__7PhysicsFv(void *pThis);
extern "C" void SetPhysicsType__7PhysicsFUiPA4_f(void *pThis, unsigned int eType, float (*pBox)[4]);
extern "C" void *__ct__6ShadowFQ26Shadow10ShadowTypeUi(void *pThis, int eType, unsigned int nFlags);
extern "C" tagWaypointGroup *GetWaypointGroupInfo__15WaypointManagerFUi(void *pThis, unsigned int nGroup);
extern "C" void FacePlayer__15EntityBaseClassFf(void *pThis, float fAngle);
extern "C" void PlingInnocent__15EntityBaseClassFv(void *pThis);
// Leading virtuals of EntityBaseClass's vtable (__vt__15EntityBaseClass), declared in slot order
// so that GetHealth (slot 0x34, virtual number 11) is called through $t9 as the original does.
class PLightManager;
class EntityBaseClassVirtuals {
public:
    virtual ~EntityBaseClassVirtuals();
    virtual int GetTallyType();
    virtual void Slot10();
    virtual void OutputDebug();
    virtual void Slot18();
    virtual void SetEditableVars(char *);
    virtual void SetDefaultVars();
    virtual void OnTimerEvent(unsigned int);
    virtual void Render(PLightManager *);
    virtual void Animate(int, float);
    virtual void SetInnocentInstanceID(unsigned int);
    virtual int GetHealth();
    virtual void OnStopAttack();
    virtual int IsAlive();
    virtual int GetArenaWaveID();
    virtual int IsArenaApparition();
};

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

// FUNCTION: 0x0019F340 OnWakeEvent__8InnocentFv
void Innocent::OnWakeEvent() {
    if (m_unk1B0 == 3) {
        PMNode *pNode = m_unk3C;
        if (pNode != 0) {
            ScaleSet__6PMNodeFffff(pNode, 1.03f, 1.03f, 1.03f, 1.0f);
        }
    }
}

// DRAFT: 0x0019F390 FindClosestEnemy__8InnocentFPA4_f
// note: 91 words differ, size 0x188 vs 0x190; 99999.0f folds to int-to-float cvt (original loads bit pattern); mTempArray and mpEntMgr relocations and prologue order differ. Tried: exponent literal 9.9999e4f, count unchanged.
void *Innocent::FindClosestEnemy(float (*pBox)[4]) {
    float vec[4];
    float fBest = 99999.0f;
    void *pBest = 0;
    unsigned int nHandle = 0;
    if (mTempArray__15EntityBaseClass.m_pData != 0) {
        mTempArray__15EntityBaseClass.m_count = 0;
        mTempArray__15EntityBaseClass.m_unk04 = 0;
    }
    GetAllActiveApparitionsInRadius__13EntityManagerFQ215EntityBaseClass9LoadClassP6PArrayPA4_ffibb(mpEntMgr__15EntityBaseClass, 3, (PArray *)&mTempArray__15EntityBaseClass, (float (*)[4])this, 14.0f, -2, true, false);
    mTempArray__15EntityBaseClass.m_unk04 = 0;
    if (mTempArray__15EntityBaseClass.m_count != 0) {
        nHandle = *mTempArray__15EntityBaseClass.m_pData;
    }
    if (nHandle != 0) {
        do {
            void *pApp = GetPtrToApparition__13EntityManagerFUi(mpEntMgr__15EntityBaseClass, nHandle);
            if (pApp != 0 && ((EntityBaseClassVirtuals *)pApp)->GetHealth() > 0) {
                int nNode = *(int *)((char *)pApp + 0x3C);
                char *pPos;
                if (nNode != 0) {
                    pPos = (char *)nNode + 0x80;
                } else {
                    pPos = (char *)pApp + 0x190;
                }
                sceVu0SubVector(vec, (float *)this, (float *)pPos);
                float fDist = sceVu0InnerProduct(vec, vec);
                if (fDist < fBest) {
                    fBest = fDist;
                    pBest = pApp;
                }
            }
            mTempArray__15EntityBaseClass.m_unk04 = mTempArray__15EntityBaseClass.m_unk04 + 1;
            nHandle = 0;
            if ((unsigned int)mTempArray__15EntityBaseClass.m_unk04 < (unsigned int)mTempArray__15EntityBaseClass.m_count) {
                nHandle = mTempArray__15EntityBaseClass.m_pData[mTempArray__15EntityBaseClass.m_unk04];
            }
        } while (nHandle != 0);
    }
    return pBest;
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

// DRAFT: 0x0019F630 ActivatedEnemiesDead__8InnocentFv
// note: 45 words differ, size 0x9c vs 0xc0; original has frame 0x50 with sq s3..s0 and a pointer walk over m_unk294. Tried: index loop (47 words), pointer walk with counter (45 words).
int Innocent::ActivatedEnemiesDead() {
    if (m_unk25C != 0) {
        if (m_unk270 == 0) {
            return 0;
        }
        EntityBaseClass **pEnt = m_unk294;
        int i = 0;
        do {
            if (*pEnt != 0) {
                EntityBaseClass *pValid = InstanceIsValid__15EntityBaseClassFUi(*pEnt);
                if (pValid != 0 && ((EntityBaseClassVirtuals *)pValid)->GetHealth() > 0) {
                    return 0;
                }
                *pEnt = 0;
            }
            i++;
            pEnt++;
        } while (i < 3);
        return 1;
    }
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

// FUNCTION: 0x0019F760 SetEditableVars__8InnocentFPc
void Innocent::SetEditableVars(char *pText) {
    memcpy(&m_unk1B0, pText, 0x6C);
    m_unk1B8 *= 50;
    if (mbHard__15EntityBaseClass == 0) {
        m_unk1B8 += 0x32;
    }
    // m_unk294..0x29C are EntityBaseClass handles in the header, but the original stores ints here.
    ((int *)m_unk294)[0] = m_unk1E0;
    ((int *)m_unk294)[1] = m_unk1E4;
    ((int *)m_unk294)[2] = m_unk1E8;
    if ((unsigned int)m_unk1B0 >= 10) {
        CdsAssert__FPciPc("Innocent.cpp", 0x687, "mEVars.m_iInnocentType < MAX_INNOCENT_TYPES");
    }
    if (*(int *)(InnocentSeqData + m_unk1B0 * 0x4C) == 0) {
        printf("ERROR - Bad Innocent type found - shutting down\n", m_unk1B0);
        SetState__15EntityBaseClassFi(this, -2);
        return;
    }
    if (m_unk208 < 0) {
        m_unk208 = 0;
    }
    if (m_unk1C0 == 0.0f && m_unk1C4 == 0.0f && m_unk1C8 == 0.0f) {
        CDS_ASSERT(0x696, !"eif 0, 0, 0 error.  see keith or ted");
        m_unk230 = ((m_unk3C != 0) ? (float *)((char *)m_unk3C + 0x80) : &m_unk190)[0];
        m_unk234 = ((m_unk3C != 0) ? (float *)((char *)m_unk3C + 0x80) : &m_unk190)[1];
        m_unk238 = ((m_unk3C != 0) ? (float *)((char *)m_unk3C + 0x80) : &m_unk190)[2];
    }
    m_unk230 = m_unk1C0;
    m_unk234 = m_unk1C4;
    m_unk238 = m_unk1C8;
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
        StartCutCamera__6CameraFUib((char *)&gEng + 0x19760, m_unk20C, false);
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

// DRAFT: 0x0019F9F0 OnHitEvent__8InnocentFP15EntityBaseClassiUiUi
// note: DIFF 108; s1/s2 swapped (original s2=pEnt, s1=nDamage; ours reversed). Tried int damage copy, goto single exit, pEnt local copy; no change.
int Innocent::OnHitEvent(EntityBaseClass *pEnt, int nDamage, unsigned int nHitId, unsigned int nUnused) {
    int state = m_unk20;
    int result;
    unsigned char *pSeq;
    if (state == 8 || state == 6) {
        result = 0;
        goto done;
    }
    if (nHitId == 0x1FE) {
        m_unkE8 = 3;
        SetState__15EntityBaseClassFi(this, 8);
        result = 1;
        goto done;
    }
    if (state >= 17 && (*(unsigned int *)((char *)pEnt + 0x10C) & 1)) {
        result = (*(int *)((char *)pEnt + 8) == 3) ? 0 : 4;
        goto done;
    }
    if (*(int *)((char *)mpEntMgr__15EntityBaseClass + 0x5058) != 0) {
        result = 5;
        goto done;
    }
    if (!(*(unsigned int *)((char *)pEnt + 0x10C) & 1)) {
        if (m_unk254 != m_unk258) {
            if (m_unk1B4 != 2) {
                result = 5;
                goto done;
            }
            if (state != 2) {
                result = 5;
                goto done;
            }
        }
    }
    FaceHitDirection__15EntityBaseClassFP15EntityBaseClass(this, pEnt);
    if (!(*(unsigned int *)((char *)pEnt + 0x10C) & 1)) {
        m_unk1B8 -= nDamage;
        CreateHitMarkFx__15EntityBaseClassFPA4_fQ215EntityBaseClass14eHitObjectTypeQ215EntityBaseClass14eHitWeaponTypeb(this, 0, 3, 0, false);
    }
    pSeq = InnocentSeqData + m_unk1B0 * 0x4C;
    if (m_unk1B8 > 0) {
        m_unk260 = state;
        m_unk264 = (m_unk140 == *(int *)(pSeq + 4));
        SetState__15EntityBaseClassFi(this, 6);
        PlaySound__15EntityBaseClassFUi(this, *(unsigned int *)(pSeq + 0x40));
        result = 1;
        goto done;
    }
    SetState__15EntityBaseClassFi(this, 5);
    PlaySound__15EntityBaseClassFUi(this, *(unsigned int *)(pSeq + 0x44));
    result = 1;
done:
    return result;
}

// DRAFT: 0x0019FBD0 IsEnemyReady__8InnocentFPUi
// note: size 0xa8 vs 0xbc, loop-join branch layout and xori/sltiu return differ (23 words); tried byte-offset do-while, counter/offset swap, branchy return (no gain).
int Innocent::IsEnemyReady(unsigned int *pOut) {
    int nCleared = 0;
    int nIndex = 0;
    unsigned int nOff = 0;
    do {
        EntityBaseClass **pSlot = (EntityBaseClass **)((char *)this + nOff);
        EntityBaseClass *pEnt = *pSlot;
        if (pEnt != 0) {
            EntityBaseClass *pValid = InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pValid != 0) {
                if (pValid->m_unk3C != 0) {
                    return 1;
                }
            } else {
                *pSlot = 0;
                nCleared++;
            }
        } else {
            nCleared++;
        }
        nIndex++;
        nOff += 4;
    } while (nIndex < 3);
    return nCleared == 3;
}

// FUNCTION: 0x0019FC90 ActivateAttackingEnemies__8InnocentFv
void Innocent::ActivateAttackingEnemies() {
    EntityBaseClass **pSlot = (EntityBaseClass **)((char *)this + 0x1E0);
    int nIndex = 0;
    EntityBaseClass *pEnt;
    EntityBaseClass *pValid;
    unsigned int nOff = 0;
    do {
        pEnt = *pSlot;
        if (pEnt != 0) {
            pValid = InstanceIsValid__15EntityBaseClassFUi(pEnt);
            if (pValid != 0) {
                if (((EntityBaseClassVirtuals *)pValid)->IsArenaApparition() == 0) {
                    pValid->m_unk1A = 1;
                }
                ((EntityBaseClassVirtuals *)pValid)->SetInnocentInstanceID(m_unkC);
                *(EntityBaseClass **)((char *)this + 0x294 + nOff) = pEnt;
                Add2DependencyList__13EntityManagerFUiUi(mpEntMgr__15EntityBaseClass, pValid->m_unk4, m_unk4);
            }
        }
        nIndex++;
        nOff += 4;
        pSlot++;
    } while (nIndex < 3);
    m_unk270 = 1;
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

// FUNCTION: 0x0019FE00 IsAlive__8InnocentFv
int Innocent::IsAlive() {
    int result = m_unk1B8;
    if (result <= 0) {
        result = 0;
    } else {
        result = 1;
    }
    return result;
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

// DRAFT: 0x0019FED0 Execute__8InnocentFv
// note: DIFF 1376 words; cases 4, 3, 6, 7, 5, 14, 11, 8, 17, 18 and the case 2 tail are not written yet.
void Innocent::Execute() {
    unsigned int *pSeq = (unsigned int *)((char *)InnocentSeqData + m_unk1B0 * 0x4C);
    switch (m_unk20) {
    case -1: {
        void *pNew;
        m_unk10C = (m_unk10C & 0xF8FFFFFF) | 0x03000000;
        WriteApparitionData__15EntityBaseClassFicUi(this, 3, (char)ReadApparitionData__15EntityBaseClassFiUi(this, 0, 0), 0);
        if (m_unk38 == 0) {
            pNew = __nw__FUi(0x120);
            if (pNew != 0) {
                pNew = __ct__7PhysicsFv(pNew);
            }
            m_unk38 = (Physics *)pNew;
            if (m_unk38 == 0) {
                CdsAssert__FPciPc("Innocent.cpp", 0x2C9, "mpPhysics");
            }
        }
        SetPhysicsType__7PhysicsFUiPA4_f(m_unk38, 0x12, 0);
        if (m_unkD4 == 0) {
            pNew = __nw__FUi(0x10);
            if (pNew != 0) {
                pNew = __ct__6ShadowFQ26Shadow10ShadowTypeUi(pNew, 1, 0x87000006);
            }
            m_unkD4 = (Shadow *)pNew;
            if (m_unkD4 == 0) {
                CdsAssert__FPciPc("Innocent.cpp", 0x2CF, "mpShadow");
            }
        }
        if (m_unkD4 != 0) {
            *(int *)m_unkD4 = 1;
            if (*(void **)((char *)m_unkD4 + 0xC) != 0) {
                *(int *)(*(char **)((char *)m_unkD4 + 0xC) + 0x18) = 1;
            }
        }
        m_unk290 = 0;
        m_unk278 = 1;
        m_unk26F = 1;
        m_unk271 = 1;
        m_unk25C = 0;
        for (int i = 0; i < 3; i++) {
            if (m_unk294[i] != 0 && InstanceIsValid__15EntityBaseClassFUi(m_unk294[i]) != 0) {
                m_unk25C += 1;
            }
        }
        m_unk270 = (m_unk25C == 0) ? 1 : 0;
        SetState__15EntityBaseClassFi(this, 1);
        if (m_unk1BC >= 0) {
            char sMsg[0x80];
            m_unk290 = GetWaypointGroupInfo__15WaypointManagerFUi((char *)mpEntMgr__15EntityBaseClass + 0x30, m_unk1BC);
            if (m_unk290 == 0) {
                sprintf(sMsg, "Innocent refers to bad waypoint group ( group id = %d )", m_unk1BC);
                CdsAssert__FPciPc("Innocent.cpp", 0x2ED, sMsg);
            }
        }
        m_unk269 = 0;
        if ((int)m_unk1F8 == 7 || (int)m_unk1F8 == 8) {
            m_unk26C = (ReadApparitionData__15EntityBaseClassFiUi(this, 1, 0) == 0) ? 0 : 1;
        } else {
            m_unk26C = (ReadApparitionData__15EntityBaseClassFiUi(this, 0, 0) == 0) ? 0 : 1;
        }
        m_unk254 = 0;
        m_unk258 = (m_unk290 != 0) ? m_unk290->m_unk4 : 0;
        return;
    }
    case 1:
        if (ActivatedEnemiesDead() != 0) {
            if (TrappedEntityRemoved() != 0) {
                if (m_unk290 != 0) {
                    unsigned char bFlag;
                    float *pWp;
                    float wp[4];
                    m_unk254 = m_unk290->m_unk4;
                    m_unk258 = m_unk254;
                    pWp = GetWaypoint__15WaypointManagerFP16tagWaypointGroupUiRUc((char *)mpEntMgr__15EntityBaseClass + 0x30, m_unk290, m_unk254 - 1, bFlag);
                    wp[0] = pWp[0];
                    wp[1] = pWp[1];
                    wp[2] = pWp[2];
                    wp[3] = 1.0f;
                    if (m_unk3C != 0) {
                        memcpy((char *)m_unk3C + 0x80, wp, 16);
                        *((unsigned char *)m_unk3C + 0x3E) |= 8;
                    } else {
                        memcpy(&m_unk190, wp, 16);
                    }
                    m_unk10C |= 0x40000;
                }
            }
        }
        SetState__15EntityBaseClassFi(this, 2);
        return;
    case 2:
        if (m_unkE9 != 0) {
            PlaySequence__15EntityBaseClassFPUi(this, &pSeq[0]);
            (*(void (**)(void *))((char *)m_unk0 + 0x78))(this);
            switch (m_unk1B4) {
            case 1:
            case 0:
            case 3:
                PlaySequence__15EntityBaseClassFPUi(this, &pSeq[3]);
                break;
            case 2:
                PlaySequence__15EntityBaseClassFPUi(this, &pSeq[12]);
                break;
            default:
                CdsAssert__FPciPc("Innocent.cpp", 0x32C, "Invalid Innocent AI mode");
                break;
            }
        }
        break;
    default:
        break;
    }
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

struct DialogSlot {
    int m_unk0;
    char _pad4[5];
    signed char m_unk9;
    char _padA[2];
};

// FUNCTION: 0x001A14D0 BuildDialogTable__8InnocentFv
int Innocent::BuildDialogTable() {
    int nID = 0x3F6;
    bool bPrev = false;
    int *pTbl = &InnocentDialogID[20];
    DialogSlot *pSlot = (DialogSlot *)(*(unsigned char **)(gInterface + 0x180) + 0x2F88);
    while (pSlot->m_unk0 != 0) {
        if (bPrev && !(pSlot->m_unk9 & 4)) {
            *pTbl = nID;
            bPrev = false;
            pTbl++;
        }
        if (pSlot->m_unk9 & 1) {
            bPrev = true;
        }
        nID++;
        pSlot++;
    }
    if (pTbl > &InnocentDialogID[256]) {
        CdsAssert__FPciPc("Innocent.cpp", 0x53, "pTbl <= &InnocentDialogID[MAX_DIALOG]");
    }
    return nID;
}
