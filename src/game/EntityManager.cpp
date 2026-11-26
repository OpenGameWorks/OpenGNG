// FLAGS: -str readonly
#include "EntityManager.h"

#include "PArray.h"

// TODO(header): foreign declarations
class PHashTable {
public:
    ~PHashTable();
    int Lookup(void *pKey, void *&pValue);
    void Add(void *pKey, void *pValue);
    void *Remove(void *pKey);
    void RemoveAll();
};

class MathAPI;
extern MathAPI *mPlayerAPI__13EntityManager;
extern "C" void ShellSort__FPFPvPv_bPPvi(bool (*pCompare)(void *, void *), void **ppItems, int nCount);
int CompareDistToCam(void *pA, void *pB);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" char *strcat(char *pDst, const char *pSrc);
extern "C" unsigned int strlen(const char *pStr);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" CEifFile *__ct__8CEifFileFv(void *pThis);
extern int mbHard__15EntityBaseClass;
extern int TypeSizeTable[17];

class PList {
public:
    ~PList();
    void RemoveAll();
};

// Sleep-list entry: first virtual (vtable slot 0 at offset 8) takes an int.
class SleepEntity {
public:
    virtual void Sleep(int arg0);
};

class WaypointManager {
public:
    ~WaypointManager();
};

class AnimData;
class PMat4;
class SoundRoom;
class EntityBaseClass;

enum EnumSoundTrigletPawnType {
    SOUND_TRIGLET_PAWN_TYPE_1 = 1,
    SOUND_TRIGLET_PAWN_TYPE_2 = 2
};

class PSound {
public:
    void RegisterSoundEntityAmounts(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3);
    int RegisterRoom(SoundRoom *pRoom);
    void RegisterSoundTrigletPawn(EntityBaseClass *pEntity, EnumSoundTrigletPawnType eType);
    void AfterSpawnEditedInstances();
    char _pad000[0x10];
};
extern PSound gSound;

class PMNode {
public:
    virtual ~PMNode();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Animate(float arg0, float arg1, PMat4 *arg2, int arg3, bool arg4);   // 0x18, virtual #4
    virtual void SetAllAnimFlags(AnimData *pData);   // 0x1C, virtual #5
    int CheckAnimated();
    void RecurseResetAnimByID(unsigned int arg0);
    void RecurseApplyAnimFlagsByID(unsigned int arg0, bool arg1, int arg2);
    void BuildAnimList(PArray *arg0, unsigned int arg1);
    void ProcessFxTriggers(float arg0, PMat4 *arg1, bool arg2, bool arg3);
    float GetFrameTime();

    char _pad004[0x24 - 0x4];
    int *m_unk24;               // 0x24 record whose [1] is the type id tested by SetHolyGround
    float (*m_unk28)[2][4];     // 0x28
    float m_unk2C;              // 0x2C
    char _pad030[0x3C - 0x30];
    unsigned char m_unk3C;      // 0x3C
    char _pad03D[0x3F - 0x3D];
    signed char m_unk3F;        // 0x3F, low 3 bits tested by ProcessIcons
    float m_unk40[4][4];        // 0x40
    char _pad080[0x110 - 0x80];
    float m_unk110[2][4];       // 0x110
};

extern "C" void DeleteMeshLayer__9InterfaceFP6PMNode(void *pThis, PMNode *pNode);
extern "C" void Unload__15PCutScenePlayerFb(void *pThis, bool bFlag);
extern "C" void __dl__FPv(void *pMem);
extern "C" void __ct__19EntityAttackManagerFv(void *pThis);
extern "C" void __ct__15WaypointManagerFv(void *pThis);
extern "C" void __ct__6PArrayFv(void *pThis);
extern "C" void __ct__10PHashTableFv(void *pThis);
extern "C" void __ct__16PResourceManagerFv(void *pThis);
extern "C" void __ct__5PListFv(void *pThis);
extern "C" int Create__10PHashTableFUi(void *pThis, unsigned int nSize);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" void *__ct__14OverlayManagerFUi(void *pThis, unsigned int nFlag);
extern "C" void InitLoadSystem__15EntityBaseClassFv();
struct TriggerNode {
    char _pad00[4];
    unsigned short m_unk04;     // 0x04 flag index, bound by m_unk5054
    short m_unk06;              // 0x06 cutscene key, negative when unused
    char _pad08;
    signed char m_unk09;        // 0x09 active flag
};
extern unsigned char gInterface[2656];

class PWorld {
public:
    void UpdateAnimate(PMNode *pNode);
};

extern "C" void sceVu0ApplyMatrix(float *, float (*)[4], float *);
static int BoxSphereCheck(float (*pBox)[4][4], float (*pSphere)[2][4], float fRadius);

class OverlayManager {
public:
    int LoadOverlay(const char *pName);
};

class Icon {
public:
    void Reset();

    int m_unk0;                 // 0x00
    char _pad004[0x8 - 0x4];
    int m_unk8;                 // 0x08
    signed char m_unkC;         // 0x0C
    signed char m_unkD;         // 0x0D
    char _pad00E[0x10 - 0x0E];
    int m_unk10;                // 0x10
    int m_unk14;                // 0x14
};

class PVirtObj {
public:
    virtual void Slot02(unsigned int arg0);
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09(unsigned int arg0);
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Slot15();
    virtual void Slot16();
    virtual void Slot17();
    virtual void Slot18();
    virtual void Slot19();
    virtual void Slot20();
    virtual void Slot21();
    virtual void Slot22();
    virtual void Slot23();
    virtual void Slot24();
    virtual void Slot25();
};

class Player;
class TriggerSystem {
public:
    int TriggerCheck(float (*pArr)[4], PMeshNode *pNode, Player *pPlayer);
    void ResetTrigger(PMeshNode *pNode);
    char _pad0[4];
    unsigned short m_unk4;
    char _pad6[3];
    signed char m_unk9;
};

void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" int printf(const char *fmt, ...);
extern "C" int sprintf(char *pBuf, const char *fmt, ...);

class PResourceManager {
public:
    ~PResourceManager();
    int LoadGlobalResource(const char *pName, bool bFlag);
    int LoadLocalResource(const char *pName, bool bFlag);
};

class Pickup {
public:
    void AdjustPickupBox();
};

class MathAPI {
public:
    float GetRelAngleYToPoint(float (*arg0)[4], float arg1, float (*arg2)[4]);
    static float DistanceXZ(float (*arg0)[4], float (*arg1)[4]);
    static float DistanceSquared(float (*arg0)[4], float (*arg1)[4]);

    char _pad000[0x20];
    float m_unk20[4];           // 0x20, element 1 at 0x24
};

float FastMath_Fabs(float f);
extern char gEng[105360];
extern "C" void sceVu0SubVector(float *dst, float *a, float *b);
extern "C" float sceVu0InnerProduct(float *a, float *b);
extern "C" void sceVu0Normalize(float *dst, float *src);
extern "C" float sqrtf(float x);

extern unsigned char gMC[0x1000];

class Debug {
public:
    void StartTimer(unsigned int nId);
    void StopTimer(unsigned int nId);
    void StartDebugTimer();
    void StopDebugTimer(void *arg0);
    char _pad000[0x10];         // placeholder size, keeps gDebug out of small data
};
extern Debug gDebug;
// Leading virtuals of EntityBaseClass's vtable (slot 0x2C is virtual #9); a call
// through this view loads the slot into $t9 as the original's virtual calls do.
class EntityBaseVirtuals {
public:
    virtual ~EntityBaseVirtuals();
    virtual int GetTallyType();
    virtual void Slot02();
    virtual void OutputDebug();
    virtual char *Slot04();
    virtual void SetEditableVars(char *);
    virtual void SetDefaultVars();
    virtual void OnTimerEvent(unsigned int);
    virtual int Render(void *);
    virtual void Animate(int, float);
    virtual void Slot10();
    virtual void Slot11();
    virtual void Slot12();
    virtual void Slot13();
    virtual void Slot14();
    virtual int Slot15();
    virtual int Slot16();
    virtual unsigned char Slot17();
};

class MemMgrType {
public:
    char _pad000[0x18];
    int m_unk18;                // 0x18 set around Process
};
extern MemMgrType MemMgr;

class Camera {
public:
    void ResetCamBoxCount();
    void SetEntityYOffset(unsigned short arg0);
    unsigned short GetEntityYOffset();
};

class TimerAPI {
public:
    void ProcessTimers(class EntityManager *arg0);
    char _pad000[0x10];         // placeholder size, keeps mTimerAPI out of small data
};

class EntityAttackManager {
public:
    void DisplayDebug();
};

class EntityBaseClass {
public:
    bool CameraLookingAtMe();
    int CheckSleep(bool arg0);
    void ProcessPhysics(float arg0, int arg1);
    void PlingInnocent();
    void CollisionCheck(EntityBaseClass *arg0);
    int SequenceViewer(unsigned int **arg0, int arg1);
    int LoadMesh(unsigned int arg0, bool arg1, bool arg2);
    int LoadAnim(unsigned int arg0, bool arg1);
    void SetAnimData(AnimData *arg0);
    int ChangedState();
    void ProcessSequence();
    void ProcessMeshFade();
    void SetState(int arg0);
    int AddToLoad();
    void RestoreOnWake();
    int WantsToWake();

    char _pad000[0x04];
    unsigned int m_unk04;       // 0x04
    int m_unk08;                // 0x08 key compared by AddToRenderList
    unsigned int m_unk0C;       // 0x0C
    int m_unk10;                // 0x10 group key compared by WakeUpApparitions
    char _pad14[0x18 - 0x14];
    unsigned char m_unk18;      // 0x18
    unsigned char m_unk19;      // 0x19
    unsigned char m_unk1A;      // 0x1A
    unsigned char m_unk1B;      // 0x1B
    unsigned char m_unk1C;      // 0x1C
    char _pad1D[0x1E - 0x1D];
    unsigned char m_unk1E;      // 0x1E nonzero while the entity is active
    char _pad1F[0x20 - 0x1F];
    int m_unk20;                // 0x20 state, -2 takes the sleep path
    char _pad24[0x3C - 0x24];
    char *m_unk3C;              // 0x3C
    char _pad040[0xE9 - 0x40];
    unsigned char m_unkE9;      // 0xE9 flag set from ChangedState
    char _padEA[0x10C - 0xEA];
    unsigned int m_unk10C;      // 0x10C collision flags, bits 24-26 mark collidable
    char _pad110[0x182 - 0x110];
    unsigned short m_unk182;    // 0x182 range, compared against DistanceXZ
    unsigned short m_unk184;    // 0x184 camera Y offset applied when in range
    char _pad186[0x190 - 0x186];
    float m_unk190[4];          // 0x190
    float m_unk1A0[4];          // 0x1A0
};

class Player {
public:
    enum PlingType {
        PLING_TYPE_UNUSED = 0
    };
    void SetPling(PlingType arg0, EntityBaseClass *arg1, unsigned int arg2);
    char _pad000[0x3C];
    char *m_unk3C;              // 0x3C
    char _pad040[0x190 - 0x40];
    float m_unk190[4];          // 0x190
};

extern char *mpEntMgr__15EntityBaseClass;   // pointer global, its target holds the Player at 0x505C

extern "C" void EnableFx__6PMNodeFbb(PMNode *pNode, bool arg0, bool arg1);
extern "C" void EnableFxByType__16PParticleManagerF7ePSTypeb(void *pMgr, int theType, bool arg0);
class EffectAPI {
public:
    char _pad000[20];
};
extern "C" void EnableParticleFx__9EffectAPIFb(EffectAPI *pApi, bool arg0);
extern "C" void Reset__9EffectAPIFv(EffectAPI *pApi);
extern "C" void __dt__6PArrayFv(void *pThis, short destroyFlag);
extern "C" void __dt__8CEifFileFv(void *pThis, short destroyFlag);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void Animate__9EffectAPIFf(EffectAPI *pApi, float arg0);
extern "C" int Render__9EffectAPIFP13PLightManager(EffectAPI *pApi, PLightManager *arg0);
extern EffectAPI mEffectAPI__13EntityManager;
extern char gGfxEng[1504384];

class CEifInstance {
public:
    int GetEntityID();
    int GetInstanceID();
    int GetFlags();
    int GetNumEditVars();
    char *GetInstanceName();
    void SetStartPosition(float arg0, float arg1, float arg2);
    void GetStartPosition(float &arg0, float &arg1, float &arg2);
    void GetStartOrientation(float &arg0, float &arg1, float &arg2);
    void *GetEditVarData(int arg0);
};

class CEifInstanceGroup {
public:
    int GetNumInstances();
    CEifInstance *GetInstanceData(int arg0);
};

class CEifFile {
public:
    int Load(const char *arg0);
    int GetNumInstanceGroups();
    CEifInstanceGroup *GetInstanceGroup(int arg0);
};

// DRAFT: 0x001460D0 BGAnimIsReset__13EntityManagerFi
// note: 21 diffs; entry beqz targets differ (orig +0x1F to shared return-0, ours +0x1B); tried guard form, while form (34), local cursor (21), flipped cursor order (25), early return (30+)
int EntityManager::BGAnimIsReset(int arg0) {
    m_unk5B8C = m_unk5B84;
    int v;
    if (m_unk5B84 != 0) {
        v = m_unk5B84->m_unk00;
    } else {
        v = 0;
    }
    if (v != 0) {
        do {
            if (v == arg0) {
                return 1;
            }
            if (m_unk5B8C == 0) {
                m_unk5B8C = m_unk5B84;
                if (m_unk5B84 != 0) {
                    v = m_unk5B84->m_unk00;
                } else {
                    v = 0;
                }
            } else {
                BGAnimNode *next = m_unk5B8C->m_unk04;
                if (next != 0) {
                    m_unk5B8C = next;
                    v = m_unk5B8C->m_unk00;
                } else {
                    v = 0;
                }
            }
        } while (v != 0);
    }
    return 0;
}

struct ParticleSubList {
    unsigned int m_unk00;
    unsigned int m_unk04;
    void **m_unk08;
};

struct ParticleNode {
    char _pad00[8];
    int m_unk08;
    char _pad0C[0x3C - 0x0C];
    PMNode *m_unk3C;
};

// DRAFT: 0x00146180 EnableParticleFx__13EntityManagerFb
// note: 30 diffs, all register/index-reload; orig keeps new index in reg; tried swap found/i (30, kept), inner idx local (56), outer idx local (49)
void EntityManager::EnableParticleFx(bool arg0) {
    int keys[1] = { 3 };
    ParticleSubList *pList;
    ParticleNode *pNode;
    PMNode *pChild;
    int found;
    int i;

    this->m_unk50A4 = 0;
    pList = (this->m_unk50A0 != 0) ? (ParticleSubList *)this->m_unk50A8[0] : 0;
    if (pList != 0) {
        do {
            pList->m_unk04 = 0;
            pNode = (pList->m_unk00 != 0) ? (ParticleNode *)pList->m_unk08[0] : 0;
            if (pNode != 0) {
                do {
                    found = 0;
                    for (i = 0; i < 1; i++) {
                        if (pNode->m_unk08 == keys[i]) {
                            found = 1;
                            break;
                        }
                    }
                    if (found == 0) {
                        pChild = pNode->m_unk3C;
                        if (pChild != 0) {
                            EnableFx__6PMNodeFbb(pChild, arg0, 1);
                        }
                    }
                    pList->m_unk04++;
                    pNode = (pList->m_unk04 < pList->m_unk00) ? (ParticleNode *)pList->m_unk08[pList->m_unk04] : 0;
                } while (pNode != 0);
            }
            this->m_unk50A4++;
            pList = (this->m_unk50A4 < this->m_unk50A0) ? (ParticleSubList *)this->m_unk50A8[this->m_unk50A4] : 0;
        } while (pList != 0);
    }
    EnableFxByType__16PParticleManagerF7ePSTypeb((void *)(gGfxEng + 0x154F00), 0x1A, arg0);
    EnableParticleFx__9EffectAPIFb(&mEffectAPI__13EntityManager, arg0);
}

// FUNCTION: 0x00146310 UpdateSwordBGAnim__13EntityManagerFv
void EntityManager::UpdateSwordBGAnim() {
    m_unk5B54 = 0;
    PMNode *node;
    if (m_unk5B50 != 0) {
        node = *m_unk5B58;
    } else {
        node = 0;
    }
    if (node != 0) {
        do {
            if (node->CheckAnimated() != 0) {
                ((PArray *)&m_unk5B50)->RemoveCurrent();
            }
            unsigned int idx = m_unk5B54 + 1;
            m_unk5B54 = idx;
            node = (idx < (unsigned int)m_unk5B50) ? m_unk5B58[m_unk5B54] : 0;
        } while (node != 0);
    }
}

// FUNCTION: 0x001463B0 ResetSwordBGAnim__13EntityManagerFv
void EntityManager::ResetSwordBGAnim() {
    m_unk5B54 = 0;
    PMNode *node;
    if (m_unk5B50 != 0) {
        node = *m_unk5B58;
    } else {
        node = 0;
    }
    if (node != 0) {
        do {
            node->RecurseResetAnimByID(0);
            node->RecurseApplyAnimFlagsByID(1, true, 0);
            node->RecurseApplyAnimFlagsByID(0x3E8, true, 0);
            unsigned int idx = m_unk5B54 + 1;
            m_unk5B54 = idx;
            node = 0;
            if (idx < (unsigned int)m_unk5B50) {
                node = m_unk5B58[m_unk5B54];
            }
        } while (node != 0);
    }
}

// FUNCTION: 0x00146470 CheckSwordBGAnim__13EntityManagerFP6PMNode
void EntityManager::CheckSwordBGAnim(PMNode *pNode) {
    if ((pNode->m_unk3C & 0x80) == 0) {
        return;
    }
    float vec[4];
    sceVu0ApplyMatrix(vec, pNode->m_unk40, (float *)pNode->m_unk28);
    float f20 = pNode->m_unk28[0][1][3];
    m_unk5B54 = 0;
    PMNode *node;
    if (m_unk5B50 != 0) {
        node = *m_unk5B58;
    } else {
        node = 0;
    }
    if (node != 0) {
        do {
            if (node->CheckAnimated() == 0) {
                float (*box)[2][4] = node->m_unk28;
                if (box == 0) {
                    box = &node->m_unk110;
                }
                if (box != 0 && BoxSphereCheck(&node->m_unk40, box, f20) != 0) {
                    node->SetAllAnimFlags(0);
                    ((PWorld *)gEng)->UpdateAnimate(node);
                }
            }
            unsigned int idx = m_unk5B54 + 1;
            m_unk5B54 = idx;
            node = (idx < (unsigned int)m_unk5B50) ? m_unk5B58[m_unk5B54] : 0;
        } while (node != 0);
    }
}

// DRAFT: 0x00146590 BoxSphereCheck__FPA4_A4_fPA2_A4_ff
// note: DIFF 62 with the placeholder; VU0 run (lqc2..vmul, qmfc2 of vf6) now in asm, MMI lane shuffles (pcpyud, prot3w, pextlw, pcgtw) still unmatched
static int BoxSphereCheck(float (*pBox)[4][4], float (*pSphere)[2][4], float fRadius) {
    u_long128 q6;
    float dist2;
    float s;
    int result = 0;
    asm {
        lqc2 vf1, 0x0(pBox)
        lqc2 vf2, 0x10(pBox)
        lqc2 vf3, 0x20(pBox)
        lqc2 vf4, 0x30(pBox)
        lqc2 vf5, 0x0(pSphere)
        lqc2 vf6, 0x10(pSphere)
        vmulax.xyzw ACC, vf1, vf5x
        qmfc2.ni q6, vf6
        vmadday.xyzw ACC, vf2, vf5y
        vmaddaz.xyzw ACC, vf3, vf5z
        vmaddw.xyzw vf7, vf4, vf5w
        vsub.xyz vf7, vf7, vf9
        vmul.xyz vf7, vf7, vf7
        vaddy.x vf7, vf7, vf7y
        vaddz.x vf7, vf7, vf7z
        qmfc2.ni dist2, vf7
    }
    s = fRadius + fRadius;
    if (!((s * s) <= dist2)) {
        result = 1;
    }
    return result;
}

// FUNCTION: 0x00146690 InitSwordBGAnimList__13EntityManagerFP9PMeshNode
void EntityManager::InitSwordBGAnimList(PMeshNode *pMesh) {
    if (m_unk5B58 != 0) {
        m_unk5B50 = 0;
        m_unk5B54 = 0;
    }
    ((PMNode *)pMesh)->BuildAnimList((PArray *)&m_unk5B50, 0x208);
    if ((unsigned int)m_unk5B50 > 0x20) {
        CdsAssert("EntityManager.cpp", 0x827, "mSwordBGAnimList.GetCount() <= MAX_SWORD_BGANIM");
    }
    if (m_unk5B78 != 0) {
        m_unk5B70 = 0;
        m_unk5B74 = 0;
    }
    ((PMNode *)pMesh)->BuildAnimList((PArray *)&m_unk5B70, 0x202);
    ((PMNode *)pMesh)->BuildAnimList((PArray *)&m_unk5B70, 0x1FF);
    ((PMNode *)pMesh)->BuildAnimList((PArray *)&m_unk5B70, 0x200);
    if ((unsigned int)m_unk5B70 > 0x20) {
        CdsAssert("EntityManager.cpp", 0x82C, "mOnTriggerList.GetCount() <= MAX_TRIGGER");
    }
}

// DRAFT: 0x00146770 ExecuteApparitions__13EntityManagerFv
// note: DIFF 146; prologue and pEntity load differ in register roles (orig s3 = i, s5 = byte offset, s4 = this, s0 = nTerminated, s2 = destroy index, s1 = pEntity). Tried byte-offset pointer walk (147), reverted to m_unk5080[i] (146, kept).
void EntityManager::ExecuteApparitions() {
    EntityBaseClass *apTerminated[0x180];
    int nTerminated = 0;
    ((Camera *)mCameraAPI)->SetEntityYOffset(0);
    for (unsigned int i = 0; i < m_unk5078; i++) {
        EntityBaseClass *pEntity = (i < m_unk5078) ? (EntityBaseClass *)m_unk5080[i] : 0;
        if (pEntity == 0) {
            CdsAssert("EntityManager.cpp", 0x7CB, "pEntity");
        }
        if (pEntity->m_unk1E != 0) {
            if (pEntity->ChangedState() != 0) {
                pEntity->m_unkE9 = 1;
            } else {
                pEntity->m_unkE9 = 0;
            }
            pEntity->ProcessSequence();
            pEntity->ProcessMeshFade();
            if (pEntity->m_unk20 == -2) {
                ((EntityBaseVirtuals *)pEntity)->Slot02();
                pEntity->SetState(-3);
                apTerminated[nTerminated] = pEntity;
                nTerminated++;
                if (nTerminated >= 0x181) {
                    CdsAssert("EntityManager.cpp", 0x7E6, "iNTerminated <= sizeof( apTerminated ) / 4");
                }
            } else {
                ((EntityBaseVirtuals *)pEntity)->Slot02();
                if ((((Camera *)mCameraAPI)->GetEntityYOffset() & 0xFFFF) == 0) {
                    unsigned short range = pEntity->m_unk182;
                    if (range != 0) {
                        float (*pt)[4] = (pEntity->m_unk3C != 0) ? (float (*)[4])(pEntity->m_unk3C + 0x80) : &pEntity->m_unk190;
                        float dist = MathAPI::DistanceXZ(pt, (float (*)[4])mCameraAPI);
                        float limit = (float)range;
                        if (dist < limit) {
                            ((Camera *)mCameraAPI)->SetEntityYOffset(pEntity->m_unk184);
                        }
                    }
                }
            }
            float (*target)[4] = (pEntity->m_unk3C != 0) ? (float (*)[4])(pEntity->m_unk3C + 0x80) : &pEntity->m_unk190;
            if (target[0][1] <= -1000.0f) {
                pEntity->SetState(-3);
                apTerminated[nTerminated] = pEntity;
                nTerminated++;
                if (nTerminated >= 0x181) {
                    CdsAssert("EntityManager.cpp", 0x811, "iNTerminated <= sizeof( apTerminated ) / 4");
                }
            }
        }
    }
    if (nTerminated > 0) {
        int idx = 0;
        do {
            EntityBaseClass *pEntity = apTerminated[idx];
            Destroy(pEntity->m_unk04, pEntity->m_unk0C);
            idx++;
        } while (idx < nTerminated);
    }
}

// DRAFT: 0x00146A30 WakeUpApparitions__13EntityManagerFv
// note: DIFF 182; frame 0x6C0 vs 0x6B0 (extra slot at sp+0xB0, apWake at 0xC0), this in s5 vs s4, nWake s7 vs s6; tried nWake in if (188), nWake before array (182), key inlined (191), player point inlined (188)
void EntityManager::WakeUpApparitions() {
    EntityBaseClass *apWake[0x180];
    int nWake = 0;
    if (m_unk5D48 == 0) {
        for (unsigned int i = 0; i < m_unk5078; i++) {
            EntityBaseClass *pEntity = (i < m_unk5078) ? (EntityBaseClass *)m_unk5080[i] : 0;
            if (pEntity == 0) {
                CdsAssert("EntityManager.cpp", 0x75B, "pEntity");
            }
            if (pEntity->m_unk1B != 0) {
                if (pEntity->m_unk1C != 0 && pEntity->WantsToWake() != 0) {
                    if (nWake >= 0x180) {
                        CdsAssert("EntityManager.cpp", 0x76B, "iWakeIdx < MAX_EDITED_INSTANCES");
                    }
                    apWake[nWake] = pEntity;
                    nWake++;
                }
            } else if (pEntity->m_unk18 != 0) {
                if (pEntity->m_unk1C != 0 && pEntity->m_unk1A != 0) {
                    if (nWake >= 0x180) {
                        CdsAssert("EntityManager.cpp", 0x77B, "iWakeIdx < MAX_EDITED_INSTANCES");
                    }
                    apWake[nWake] = pEntity;
                    nWake++;
                }
            } else {
                pEntity->m_unk1C = 0;
                pEntity->m_unk1E = 1;
            }
        }
        if (nWake != 0) {
            ShellSort__FPFPvPv_bPPvi((bool (*)(void *, void *))CompareDistToCam, (void **)apWake, nWake);
            for (int i = 0; i < nWake; i++) {
                EntityBaseClass *pWake = apWake[i];
                if (pWake->AddToLoad() != 0) {
                    pWake->m_unk1C = 0;
                    pWake->m_unk1E = 1;
                    pWake->RestoreOnWake();
                } else {
                    int key = pWake->m_unk10;
                    for (unsigned int j = 0; j < m_unk5078; j++) {
                        EntityBaseClass *pOther = (j < m_unk5078) ? (EntityBaseClass *)m_unk5080[j] : 0;
                        if (pOther->m_unk10 == key && pOther->m_unk19 != 0) {
                            Player *pPlayer = (Player *)mPlayerAPI__13EntityManager;
                            float (*pPlayerPt)[4] = (pPlayer->m_unk3C != 0) ? (float (*)[4])(pPlayer->m_unk3C + 0x80) : &pPlayer->m_unk190;
                            float (*pWakePt)[4] = (pWake->m_unk3C != 0) ? (float (*)[4])(pWake->m_unk3C + 0x80) : &pWake->m_unk190;
                            float fWake = MathAPI::DistanceSquared(pWakePt, pPlayerPt);
                            float (*pOtherPt)[4] = (pOther->m_unk3C != 0) ? (float (*)[4])(pOther->m_unk3C + 0x80) : &pOther->m_unk190;
                            float fOther = MathAPI::DistanceSquared(pOtherPt, pPlayerPt);
                            if (fWake < fOther && pOther->m_unk1B != 0 && pOther->m_unk1C == 0) {
                                pOther->CheckSleep(true);
                                pWake->m_unk1C = 0;
                                pWake->m_unk1E = 1;
                                pWake->RestoreOnWake();
                                return;
                            }
                        }
                    }
                    pWake->m_unk1E = 0;
                }
            }
        }
    }
}

// DRAFT: 0x00146D80 CompareDistToCam__FPvPv
// note: string literals fixed by -str readonly; still differs in register allocation (pA lands in s2 with pCam in s0, original pCam s2/pA s0/pB s1), f20 prologue save order, and pB copy placement; tried pA used directly, pCam as float*.
int CompareDistToCam(void *pA, void *pB) {
    float sp50[4];
    float *pCam = (float *)(gEng + 0x19760);
    if (pCam == 0) {
        CdsAssert("EntityManager.cpp", 0x740, "pCam");
    }
    char *srcA = *(char **)((char *)pA + 0x3C);
    float *pTargetA = (float *)((char *)pA + 0x190);
    if (srcA != 0) {
        pTargetA = (float *)(srcA + 0x80);
    }
    sceVu0SubVector(sp50, pCam, pTargetA);
    float d0 = sqrtf(sceVu0InnerProduct(sp50, sp50));
    char *srcB = *(char **)((char *)pB + 0x3C);
    float *pTargetB = (float *)((char *)pB + 0x190);
    if (srcB != 0) {
        pTargetB = (float *)(srcB + 0x80);
    }
    sceVu0SubVector(sp50, pCam, pTargetB);
    float d1 = sqrtf(sceVu0InnerProduct(sp50, sp50));
    return d0 > d1;
}

// DRAFT: 0x00146E70 PutApparitionsToSleep__13EntityManagerFv
// note: 45 lines differ; prologue and entry addressing match, loop shape differs (original enters at a bottom test via b with s0=0 in the delay slot, has a beqz $at guard at the head, and loads m_unk5078 at the test). Tried while form, swapped counter/offset declarations (worse), for form (45, kept).
void EntityManager::PutApparitionsToSleep() {
    if (m_unk5D48 == 0) {
        unsigned int off = 0;
        for (unsigned int i = 0; i < m_unk5078; i++) {
            EntityBaseClass *pEntity = *(EntityBaseClass **)((char *)m_unk5080 + off);
            if (pEntity == 0) {
                CdsAssert("EntityManager.cpp", 0x721, "pEntity");
            }
            if (pEntity->m_unk1B != 0 && pEntity->m_unk1C == 0) {
                if (pEntity->CheckSleep(false)) {
                    Destroy(pEntity->m_unk04, pEntity->m_unk0C);
                }
            }
            off += 4;
        }
    }
}

// FUNCTION: 0x00146F50 ProcessApparitions__13EntityManagerFv
void EntityManager::ProcessApparitions() {
    int n = m_unk5D48;
    if (n != 0) {
        m_unk5D48 = n - 1;
    }
    PutApparitionsToSleep();
    WakeUpApparitions();
    ExecuteApparitions();
}

// FUNCTION: 0x00146FA0 CalculateTallyData__13EntityManagerFv
void *EntityManager::CalculateTallyData() {
    m_unk5B24[0].m_unk00 = 0;
    m_unk5B24[1].m_unk00 = 0;
    m_unk5B24[2].m_unk00 = 0;
    m_unk5B24[3].m_unk00 = 0;
    m_unk5B24[4].m_unk00 = 0;
    unsigned int i = 0;
    int off = 0;
    for (; i < m_unk5054; i++) {
        signed char t = *(signed char *)((char *)this + 0x53A0 + off);
        switch (t) {
        case 1:
        case 2:
        case 3:
        case 4:
            m_unk5B24[t].m_unk00 = m_unk5B24[t].m_unk00 + 1;
            break;
        }
        off += 4;
    }
    return m_unk5B24;
}

// FUNCTION: 0x001471D0 Reset__4IconFv
void Icon::Reset() {
    m_unk0 = 0;
    m_unkC = 1;
    m_unk8 = 0;
    m_unkD = 0;
    m_unk10 = 0;
    m_unk14 = 0;
}

// FUNCTION: 0x001471F0 FindTrigger__13EntityManagerFUii
void *EntityManager::FindTrigger(unsigned int arg0, int arg1) {
    m_unk5B64 = 0;
    TriggerEntry *p = 0;
    if (m_unk5B60 != 0) {
        p = (TriggerEntry *)m_unk5B68[0];
    } else {
        p = 0;
    }
    while (p != 0) {
        if (arg1 >= 0) {
            if (arg1 == p->m_unk06) {
                return p;
            }
        } else {
            if (arg0 == p->m_unk00) {
                return p;
            }
        }
        int idx = m_unk5B64 + 1;
        m_unk5B64 = idx;
        p = (idx < (unsigned int)m_unk5B60) ? (TriggerEntry *)m_unk5B68[m_unk5B64] : 0;
    }
    return 0;
}

// DRAFT: 0x00147290 ProcessTrigger__13EntityManagerFv
// note: DIFF 81; frame 0x90 vs 0x80, this in s6 vs s0, pNode in s7 vs s4; tried key-local removal (83), key after assert (83), pNode after i/off (81), pArr default-then-override (81), m_unk5B68[i] indexing (81)
void EntityManager::ProcessTrigger() {
    Player *pPlayer = *(Player **)((char *)this + 0x505C);
    if (pPlayer != 0) {
        float (*pArr)[4] = (float (*)[4])((char *)pPlayer + 0x190);
        if (pPlayer->m_unk3C != 0) {
            pArr = (float (*)[4])(pPlayer->m_unk3C + 0x80);
        }
        PMeshNode *pNode = *(PMeshNode **)gEng;
        unsigned int i = 0;
        for (;;) {
            TriggerSystem *pTrig = 0;
            if (i < (unsigned int)m_unk5B60) {
                pTrig = (TriggerSystem *)m_unk5B68[i];
            }
            if (pTrig == 0) {
                break;
            }
            int r = pTrig->TriggerCheck(pArr, pNode, *(Player **)((char *)this + 0x505C));
            if (r != 0) {
                unsigned short key = pTrig->m_unk4;
                if (key >= 0x180) {
                    CdsAssert("EntityManager.cpp", 0x5C1, "pTrigger->GetReference() < MAX_EDITED_INSTANCES");
                }
                if ((signed char)m_unk53A1[key * 4] >= 0) {
                    if (r >= 0) {
                        m_unk53A1[key * 4] = 1;
                    } else {
                        m_unk53A1[key * 4] = -2;
                    }
                    if (r == -2) {
                        *((char *)this + 0x59A0 + key) = -2;
                    }
                }
            }
            i++;
        }
    }
}

// DRAFT: 0x001473D0 RestoreHolyGround__13EntityManagerFv
// note: DIFF 18 against the original; the differing lines were not analysed in this job
void EntityManager::RestoreHolyGround() {
    PMeshNode *pNode = *(PMeshNode **)gEng;
    if (pNode != 0) {
        m_unk5B64 = 0;
        TriggerSystem *pTrig = 0;
        if (m_unk5B60 != 0) {
            pTrig = (TriggerSystem *)m_unk5B68[0];
        }
        if (pTrig != 0) {
            do {
                if (pTrig->m_unk9 != 0 && *(signed char *)((char *)this + pTrig->m_unk4 + 0x59A0) >= 0) {
                    pTrig->ResetTrigger(pNode);
                }
                unsigned int idx = m_unk5B64 + 1;
                m_unk5B64 = idx;
                if (idx < (unsigned int)m_unk5B60) {
                    pTrig = (TriggerSystem *)m_unk5B68[m_unk5B64];
                } else {
                    pTrig = 0;
                }
            } while (pTrig != 0);
        }
        signed char *pSrc = (signed char *)((char *)this + 0x59A0);
        signed char *pDst = (signed char *)((char *)this + 0x53A1);
        int n = 0x180;
        do {
            n--;
            *pDst = *pSrc;
            pSrc++;
            pDst += 4;
        } while (n != 0);
    }
    int *pMC = (int *)&gMC[0x234];
    pMC[8] = *(signed char *)((char *)this + 0x5B20);
    pMC[9] = *(signed char *)((char *)this + 0x5B21);
    if (pNode != 0) {
        ((PMNode *)pNode)->ProcessFxTriggers(-2.0f, 0, true, false);
    }
}

struct IconEntry {
    PMNode *m_unk00;            // 0x00 icon mesh node
    char _pad04[8];
    unsigned char m_unk0C;      // 0x0C active flag, gates the countdown
    unsigned char m_unk0D;      // 0x0D live flag, clear means release the mesh
    char _pad0E[2];
    int m_unk10;                // 0x10 countdown
    int m_unk14;                // 0x14 countdown total
    unsigned char m_unk18;      // 0x18 scale-by-progress flag
};

// DRAFT: 0x00147040 ProcessIcons__13EntityManagerFv
// note: 65 diffs; m_unk3F test lacks the original's sign-extend, release/countdown order, float-store reload and cursor-advance order differ; int cast on m_unk3F test did not change count
void EntityManager::ProcessIcons() {
    IconEntry *pEntry;
    PMNode *pNode;

    m_unk5F5C = m_unk5F54;
    pEntry = m_unk5F54 ? (IconEntry *)*m_unk5F54 : 0;
    if (pEntry != 0) {
        do {
            if (pEntry->m_unk0D != 0) {
                pNode = pEntry->m_unk00;
                pNode->Animate(0.0f, 1.0f, 0, 0, false);
                if (pEntry->m_unk0C != 0) {
                    if ((pNode->m_unk3F & 7) == 0) {
                        if (pEntry->m_unk10 == 0) {
                            DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pEntry->m_unk00);
                            pEntry->m_unk00 = 0;
                            pEntry->m_unk0D = 0;
                        } else {
                            pEntry->m_unk10 = pEntry->m_unk10 - 1;
                            if (pEntry->m_unk18 != 0) {
                                pEntry->m_unk00->m_unk2C = (float)pEntry->m_unk10 / (float)pEntry->m_unk14;
                            }
                        }
                    }
                }
            } else {
                pNode = pEntry->m_unk00;
                if (pNode != 0) {
                    DeleteMeshLayer__9InterfaceFP6PMNode(gInterface, pNode);
                    pEntry->m_unk00 = 0;
                }
            }
            if (m_unk5F5C == 0) {
                m_unk5F5C = m_unk5F54;
                pEntry = m_unk5F54 ? (IconEntry *)*m_unk5F54 : 0;
            } else {
                if (((void **)m_unk5F5C)[1] != 0) {
                    m_unk5F5C = (void **)((void **)m_unk5F5C)[1];
                    pEntry = (IconEntry *)((void **)m_unk5F5C)[0];
                } else {
                    pEntry = 0;
                }
            }
        } while (pEntry != 0);
    }
}

// DRAFT: 0x00147500 SetHolyGround__13EntityManagerFPA4_ffb
// note: DIFF 102; missing loop-tail nop near 0x548 not forced by any source form. Tried do-while, while (n--), for with dst++ first, unsigned counter (all 102).
void EntityManager::SetHolyGround(float (*arg0)[4], float arg1, bool arg2) {
    int i;
    TriggerNode *pTrigger;
    PMNode *pNode;
    int key;
    int flag;

    m_unk5070 = arg2;
    *(u_long128 *)&m_unk5060 = *(u_long128 *)arg0;
    m_unk506C = arg1;
    ValidateDependencyList();
    {
        char *dst = m_unk59A0;
        char *src = m_unk53A1;
        int n;
        for (n = 0x180; n != 0; n--) {
            *dst = *src;
            src += 4;
            dst++;
        }
    }
    m_unk5B20 = ((signed char *)m_unk505C)[0x1F0];
    m_unk5B21 = ((signed char *)m_unk505C)[0x1F4];
    m_unk5B64 = 0;
    pTrigger = m_unk5B60 ? (TriggerNode *)m_unk5B68[0] : 0;
    while (pTrigger != 0) {
        if (pTrigger->m_unk09 != 0) {
            key = pTrigger->m_unk06;
            flag = 0;
            if (key >= 0 && (gEng[key * 0x2140 + 0x235D] & 0x4)) {
                Unload__15PCutScenePlayerFb(gEng + key * 0x2140 + 0x220, false);
                flag = 1;
            } else if (pTrigger->m_unk04 < m_unk5054 && m_unk53A1[pTrigger->m_unk04 * 4] < -1) {
                flag = 1;
            }
            if (flag) {
                ((PArray *)&m_unk5B60)->RemoveCurrent();
                __dl__FPv(pTrigger);
            }
        }
        m_unk5B64++;
        pTrigger = (m_unk5B64 < m_unk5B60) ? (TriggerNode *)m_unk5B68[m_unk5B64] : 0;
    }
    m_unk5B74 = 0;
    pNode = m_unk5B70 ? (PMNode *)m_unk5B78[0] : 0;
    while (pNode != 0) {
        if ((pNode->m_unk24 ? pNode->m_unk24[1] : 0) == 0x1FF || (pNode->m_unk24 ? pNode->m_unk24[1] : 0) == 0x202) {
            if (pNode->GetFrameTime() != 0.0f) {
                ((PArray *)&m_unk5B70)->RemoveCurrent();
            }
        }
        m_unk5B74++;
        pNode = (m_unk5B74 < m_unk5B70) ? (PMNode *)m_unk5B78[m_unk5B74] : 0;
    }
    UpdateSwordBGAnim();
    ModifyEifPosition();
}

// DRAFT: 0x00147760 ValidateDependencyList__13EntityManagerFv
// note: 7 words; offset and pointer swap registers (original offset a3, pointer t0; ours offset a2, pointer a3); tried scoped counter (9), unsigned offset (9), comma-increment (8), array index (25), offset-first (9), chptr (8), while loop, pointer decl, if-wrap, dropped p (all 7, counter-first kept).
void EntityManager::ValidateDependencyList() {
    int i = 0;
    int off = 0;
    for (; i < m_unk519C; i++) {
        DependencyEntry *p = (DependencyEntry *)((char *)this + off);
        unsigned int v = p->m_unk04;
        if (v < m_unk5054 && (signed char)m_unk53A1[v * 4] >= 0) {
            m_unk53A1[p->m_unk00 * 4] = 0;
        }
        off += 8;
    }
    m_unk519C = 0;
}

// FUNCTION: 0x001477C0 Add2DependencyList__13EntityManagerFUiUi
void EntityManager::Add2DependencyList(unsigned int arg0, unsigned int arg1) {
    if (m_unk519C >= 0x40) {
        CdsAssert("EntityManager.cpp", 0x4ED, "miDependencySize < MAX_DEPENDENCY");
    }
    int n = m_unk519C;
    m_unk519C = n + 1;
    DependencyEntry *e = &m_unk51A0[n];
    e->m_unk00 = arg0;
    e->m_unk04 = arg1;
}

// DRAFT: 0x00147AA0 SaveApparitionData__13EntityManagerFi
// note: 23 diffs; register allocation (pointer, offset, mask, counter), beqz target 0x24 vs 0x23, loop tail order. Tried unsigned char b (25), unsigned int b (23), p declared after i (worse), inner check removed (39).
void EntityManager::SaveApparitionData(int arg0) {
    if (arg0 < 0x15) {
        unsigned char *p = 0;
        if (arg0 < 0x15) {
            p = &gMC[arg0 * 0x31];
            p = p + 0x2B1;
        }
        unsigned int b = 0x80;
        unsigned int mask = 0x40;
        int i = 1;
        int off = 4;
        do {
            if (*(signed char *)((char *)this + 0x53A0 + off) > 0) {
                b |= mask;
            }
            mask = mask >> 1;
            if (mask == 0) {
                *p = b;
                mask = 0x80;
                p = p + 1;
                b = 0;
            }
            i = i + 1;
            off = off + 4;
        } while (i < 0x180);
        if (i & 7) {
            *p = b;
        }
    }
}

// DRAFT: 0x00147B40 LoadApparitionData__13EntityManagerFi
// note: 22 lines differ; branch offset 0x1D vs 0x1C, p=0 in t1 (orig v1), addiu 0x2B1 placement, b/mask/i/off/q registers (orig a2/a3/t0/t1/t2), loop tail order. Tried gMC[idx+0x2B1] (27), two-pointer q (22), single pointer p (22), counters before byte load (23).
void EntityManager::LoadApparitionData(int arg0) {
    if (arg0 < 0x15) {
        unsigned char *p = 0;
        if (arg0 < 0x15) {
            p = &gMC[arg0 * 0x31];
            p = p + 0x2B1;
        }
        unsigned char b = *p;
        p = p + 1;
        unsigned int mask = 0x80;
        int i = 0;
        int off = 0;
        do {
            int bit = (unsigned char)b & mask;
            mask = mask >> 1;
            *(signed char *)((char *)this + 0x53A0 + off) = bit;
            if (mask == 0) {
                b = *p;
                mask = 0x80;
                p = p + 1;
            }
            i = i + 1;
            off = off + 4;
        } while (i < 0x180);
    }
}

struct EifEntry {
    float m_unk00;
    float m_unk04;
    float m_unk08;
    unsigned short m_unk0C;
    unsigned short m_unk0E;
};

// DRAFT: 0x00147BC0 SetEifPosition__13EntityManagerFUiUiPA4_f
// note: 35 diffs; original keeps count+1 in a1 and the entry offset in v1, ours swaps them and stores count+1 early (not in the delay slot). Tried store placement, pointer-indexed entry, direct member test (slti, 36).
void EntityManager::SetEifPosition(unsigned int arg0, unsigned int arg1, float (*arg2)[4]) {
    unsigned int count = m_unk5D4C;
    if (count < 0x20) {
        EifEntry *entry = (EifEntry *)((char *)this + 0x5D50 + count * 0x10);
        m_unk5D4C = count + 1;
        if (arg0 >= 0x10000) {
            CdsAssert("EntityManager.cpp", 0x44E, "iInstance < 0x10000");
        }
        entry->m_unk0C = (short)arg0;
        entry->m_unk0E = (short)arg1;
        entry->m_unk00 = arg2[0][0];
        entry->m_unk04 = arg2[0][1];
        entry->m_unk08 = arg2[0][2];
        return;
    }
    printf("Too many SetEifPosition() call\n");
}

// FUNCTION: 0x00147C80 ModifyEifPosition__13EntityManagerFv
void EntityManager::ModifyEifPosition() {
    unsigned int count = m_unk5D4C;
    EifEntry *entry = (EifEntry *)((char *)this + 0x5D50);
    if (count != 0) {
        do {
            int numGroups = m_unk5194->GetNumInstanceGroups();
            for (int g = 0; g < numGroups; g++) {
                CEifInstanceGroup *pGroup = m_unk5194->GetInstanceGroup(g);
                if (pGroup == 0) {
                    CdsAssert("EntityManager.cpp", 0x433, "pEifInstanceGroup");
                }
                int numInst = pGroup->GetNumInstances();
                for (int i = 0; i < numInst; i++) {
                    CEifInstance *pInst = pGroup->GetInstanceData(i);
                    if (entry->m_unk0E != pInst->GetEntityID()) {
                        break;
                    }
                    if (entry->m_unk0C == pInst->GetInstanceID()) {
                        pInst->SetStartPosition(entry->m_unk00, entry->m_unk04, entry->m_unk08);
                        goto next;
                    }
                }
            }
next:
            count--;
            entry++;
        } while (count != 0);
    }
    m_unk5D4C = 0;
}

struct EditVarData {
    int m_unk00;                // 0x00 data type, 1 is DT_BOOL
    char _pad04[4];
    bool m_unk08;               // 0x08 value written by SetEifWoken
};

// FUNCTION: 0x00147DF0 SetEifWoken__13EntityManagerFUibUi
int EntityManager::SetEifWoken(unsigned int arg0, bool arg1, unsigned int arg2) {
    int numGroups = m_unk5194->GetNumInstanceGroups();
    for (int g = 0; g < numGroups; g++) {
        CEifInstanceGroup *pGroup = m_unk5194->GetInstanceGroup(g);
        if (pGroup == 0) {
            CdsAssert("EntityManager.cpp", 0x414, "pEifInstanceGroup");
        }
        int numInst = pGroup->GetNumInstances();
        for (int i = 0; i < numInst; i++) {
            CEifInstance *pInst = pGroup->GetInstanceData(i);
            if (arg2 != 0 && arg2 != (unsigned int)pInst->GetEntityID()) {
                break;
            }
            if (arg0 == (unsigned int)pInst->GetInstanceID()) {
                signed char slot = *(signed char *)((char *)this + pInst->GetEntityID() + 0x5B90);
                if (slot >= 0) {
                    EditVarData *pVarData = (EditVarData *)pInst->GetEditVarData(slot);
                    if (pVarData == 0) {
                        CdsAssert("EntityManager.cpp", 0x41F, "pVarData");
                    }
                    if (pVarData->m_unk00 != 1) {
                        CdsAssert("EntityManager.cpp", 0x420, "pVarData->eType == DT_BOOL");
                    }
                    pVarData->m_unk08 = arg1;
                }
            }
        }
    }
    return 0;
}

// DRAFT: 0x00147F90 AfterSpawnEditedInstances__13EntityManagerFv
// note: DIFF 167; original frame 0x6A0 (fp saved, ra at 0x90) vs ours 0x690 (no fp); loop-1 count lives in fp in the original, s0 here; gSound reloc at 0x278 missing; size 0x288 vs 0x2AC. Tried byte-offset loop 1 (167, no gain), count first (170), ternary tail (170).
void EntityManager::AfterSpawnEditedInstances() {
    int count = m_unk5078;
    EntityBaseClass *apTerminated[0x180];
    int iNTerminated = 0;
    int nTotal = 0;
    int n16 = 0;
    int n71 = 0;
    for (int i = 0; i < count; i++) {
        EntityBaseClass *pEntity = ((unsigned int)i < m_unk5078) ? (EntityBaseClass *)m_unk5080[i] : 0;
        if (pEntity == 0) {
            CdsAssert("EntityManager.cpp", 0x3AB, "pEntity");
        }
        if (pEntity->m_unk08 == 0x71) {
            nTotal++;
            n71++;
        } else if (pEntity->m_unk08 == 0x70) {
            nTotal++;
        } else if (pEntity->m_unk08 == 0x16) {
            n16++;
        }
    }
    gSound.RegisterSoundEntityAmounts(n16, nTotal, n71, 0);
    iNTerminated = 0;
    for (int i = 0; i < count; i++) {
        EntityBaseClass *pEntity = ((unsigned int)i < (unsigned int)count) ? (EntityBaseClass *)m_unk5080[i] : 0;
        if (pEntity == 0) {
            CdsAssert("EntityManager.cpp", 0x3D2, "pEntity");
        }
        int flag = 0;
        if (pEntity->m_unk08 == 0x71) {
            gSound.RegisterSoundTrigletPawn(pEntity, SOUND_TRIGLET_PAWN_TYPE_2);
            flag = 1;
        } else if (pEntity->m_unk08 == 0x70) {
            gSound.RegisterSoundTrigletPawn(pEntity, SOUND_TRIGLET_PAWN_TYPE_1);
            flag = 1;
        } else if (pEntity->m_unk08 == 0x16) {
            gSound.RegisterRoom((SoundRoom *)pEntity);
            flag = 1;
        }
        if (flag != 0) {
            apTerminated[iNTerminated] = pEntity;
            iNTerminated++;
            if (iNTerminated >= 0x181) {
                CdsAssert("EntityManager.cpp", 0x3FA, "iNTerminated <= sizeof( apTerminated ) / 4");
            }
        }
    }
    if (iNTerminated > 0) {
        int idx = 0;
        do {
            EntityBaseClass *pEntity = apTerminated[idx];
            Destroy(pEntity->m_unk04, pEntity->m_unk0C);
            idx++;
        } while (idx < iNTerminated);
    }
    gSound.AfterSpawnEditedInstances();
}

// DRAFT: 0x00148240 SpawnEditedInstances__13EntityManagerFPcb
// note: DIFF 348; bool copy of arg1 keeps andi (orig daddu), block layout differs at 0x40/0x12C (Load-fail path), 0x5050 tail and loop head; tried bool var_fp (390, reverted), new-file temp (349->348 kept)
void EntityManager::SpawnEditedInstances(char *arg0, bool arg1) {
    char sFile[0x100];
    char sp1D0[0x200];
    float sp1C0[4];
    float sp3D8;
    float sp3DC;
    float sp3E0;
    float sp3E4;
    float sp3E8;
    float sp3EC;
    int var_fp;
    int spA0;
    int var_s7;
    CEifInstanceGroup *pGroup;
    CEifInstance *pInst;
    EntityBaseClass *pEnt;
    int flags;
    int entityID;
    int nEditVars;
    int nTotalSize;
    int nSize;
    int nTally;
    int nSavedMem;
    int i;
    char *pVar;
    char *pDst;
    CEifFile *pNewFile;

    var_fp = arg1;
    if ((var_fp != 0) || (m_unk5194 == 0)) {
        if (m_unk5194 != 0) {
            __dt__8CEifFileFv(m_unk5194, 1);
        }
        pNewFile = (CEifFile *)__nw__FUi(0x330);
        if (pNewFile != 0) {
            pNewFile = __ct__8CEifFileFv(pNewFile);
        }
        m_unk5194 = pNewFile;
        if (m_unk5194 == 0) {
            CdsAssert("EntityManager.cpp", 0x2D0, "mpEifFile");
        }
        if (arg0 == 0) {
            CdsAssert("EntityManager.cpp", 0x2D3, "pPsxFilename");
        }
        strcpy(sFile, arg0);
        sFile[strlen(sFile)] = 0;
        strcat(sFile, "EIF");
        if (strlen(sFile) >= 0x100U) {
            CdsAssert("EntityManager.cpp", 0x2D7, "strlen( pFileName ) < 256");
        }
        if (m_unk5194->Load(sFile) == 0) {
            __dt__8CEifFileFv(m_unk5194, 1);
            m_unk5194 = 0;
            return;
        }
        strcpy(m_unk5C10, arg0);
        m_unk5B24[0].m_unk00 = 0;
        m_unk5B24[0].m_unk04 = 0;
        m_unk5B24[1].m_unk00 = 0;
        m_unk5B24[1].m_unk04 = 0;
        m_unk5B24[2].m_unk00 = 0;
        m_unk5B24[2].m_unk04 = 0;
        m_unk5B24[3].m_unk00 = 0;
        m_unk5B24[3].m_unk04 = 0;
        m_unk5B24[4].m_unk00 = 0;
        m_unk5B24[4].m_unk04 = 0;
        var_fp = 1;
    }
    spA0 = 0;
    m_unk5050 = 1;
    while (spA0 < m_unk5194->GetNumInstanceGroups()) {
        pGroup = m_unk5194->GetInstanceGroup(spA0);
        if (pGroup == 0) {
            CdsAssert("EntityManager.cpp", 0x2EB, "pEifInstanceGroup");
        }
        var_s7 = 0;
        if (pGroup->GetNumInstances() > 0) {
            do {
                pInst = pGroup->GetInstanceData(var_s7);
                if (pInst == 0) {
                    CdsAssert("EntityManager.cpp", 0x2F0, "pEifInstance");
                }
                flags = pInst->GetFlags();
                if (!(flags & 1)) {
                    if (((mbHard__15EntityBaseClass == 0) && (flags & 2)) || ((signed char)m_unk53A1[m_unk5050 * 4] < -1)) {
                        m_unk5050 += 1;
                    } else {
                        entityID = pInst->GetEntityID();
                        pEnt = (EntityBaseClass *)Spawn(entityID, true, pInst->GetNumEditVars());
                        if (entityID >= 0x80U) {
                            CdsAssert("EntityManager.cpp", 0x304, "iClassID < MAX_ENTITY_ID");
                        }
                        m_unk5B90[entityID] = ((EntityBaseVirtuals *)pEnt)->Slot17();
                        if (entityID == 3) {
                            if (var_fp == 0) {
                                *(u_long128 *)sp1C0 = *(u_long128 *)&m_unk5060;
                                sp1C0[3] = 1.0f;
                                *(u_long128 *)pEnt->m_unk190 = *(u_long128 *)sp1C0;
                                sp1C0[0] = 0.0f;
                                sp1C0[1] = m_unk506C;
                                sp1C0[2] = 0.0f;
                                sp1C0[3] = 0.0f;
                                *(u_long128 *)pEnt->m_unk1A0 = *(u_long128 *)sp1C0;
                                ((EntityBaseVirtuals *)pEnt)->Slot02();
                            } else {
                                pInst->GetStartPosition(m_unk5060, m_unk5064, m_unk5068);
                                pInst->GetStartOrientation(sp3E4, m_unk506C, sp3EC);
                                goto block_32;
                            }
                        } else {
block_32:
                            pInst->GetStartPosition(sp3D8, sp3DC, sp3E0);
                            sp1C0[0] = sp3D8;
                            sp1C0[1] = sp3DC;
                            sp1C0[2] = sp3E0;
                            sp1C0[3] = 1.0f;
                            *(u_long128 *)pEnt->m_unk190 = *(u_long128 *)sp1C0;
                            pInst->GetStartOrientation(sp3E4, sp3E8, sp3EC);
                            sp1C0[0] = sp3E4;
                            sp1C0[1] = sp3E8;
                            sp1C0[2] = sp3EC;
                            if ((pEnt->m_unk10 != 6) && (pEnt->m_unk10 != 3)) {
                            } else if ((sp1C0[0] != 0.0f) || (sp1C0[2] != 0.0f)) {
                                char *pName = ((EntityBaseVirtuals *)pEnt)->Slot04();
                                printf("%s has BAD ROTATION ( %s )\n", pName, pInst->GetInstanceName());
                                sp1C0[0] = 0.0f;
                                sp1C0[1] = 0.0f;
                                sp1C0[2] = 0.0f;
                                sp1C0[3] = 0.0f;
                            }
                            *(u_long128 *)pEnt->m_unk1A0 = *(u_long128 *)sp1C0;
                            nEditVars = pInst->GetNumEditVars();
                            if (nEditVars > 0) {
                                nSize = 0;
                                i = 0;
                                if (nEditVars > 0) {
                                    do {
                                        pVar = (char *)pInst->GetEditVarData(i);
                                        if (pVar == 0) {
                                            CdsAssert("EntityManager.cpp", 0x344, "pVarData");
                                        }
                                        i += 1;
                                        nSize += TypeSizeTable[*pVar];
                                    } while (i < nEditVars);
                                }
                                if (nSize >= 0x200U) {
                                    CdsAssert("EntityManager.cpp", 0x348, "iTotalSize < sizeof(VarStore)");
                                }
                                pDst = sp1D0;
                                i = 0;
                                if (nEditVars > 0) {
                                    do {
                                        pVar = (char *)pInst->GetEditVarData(i);
                                        if (pVar == 0) {
                                            CdsAssert("EntityManager.cpp", 0x34F, "pVarData");
                                        }
                                        nTotalSize = TypeSizeTable[*pVar];
                                        memcpy(pDst, pVar + 8, nTotalSize);
                                        i += 1;
                                        pDst += nTotalSize;
                                    } while (i < nEditVars);
                                }
                            }
                            ((EntityBaseVirtuals *)pEnt)->SetEditableVars(sp1D0);
                            if (var_fp != 0) {
                                nTally = ((EntityBaseVirtuals *)pEnt)->GetTallyType();
                                if (nTally > 0) {
                                    m_unk5B24[nTally].m_unk04 += 1;
                                }
                                if (*((char *)this + m_unk5050 * 4 + 0x539C) != 0) {
                                    *((char *)this + m_unk5050 * 4 + 0x539C) = nTally;
                                }
                            }
                            if ((((EntityBaseVirtuals *)pEnt)->Slot15() != 0) || (((EntityBaseVirtuals *)pEnt)->Slot16() != 0)) {
                                pEnt->m_unk1A = 0;
                            }
                            if (pInst->GetInstanceID() != 0) {
                                pEnt->m_unk0C = pInst->GetInstanceID();
                                nSavedMem = MemMgr.m_unk18;
                                MemMgr.m_unk18 = 0;
                                ((PHashTable *)m_unk5094)->Add((void *)pInst->GetInstanceID(), pEnt);
                                MemMgr.m_unk18 = nSavedMem;
                            }
                        }
                    }
                }
                var_s7 += 1;
            } while (var_s7 < pGroup->GetNumInstances());
        }
        spA0 += 1;
    }
    m_unk5054 = m_unk5050;
    if (m_unk5054 >= 0x180U) {
        CdsAssert("EntityManager.cpp", 0x380, "m_iEditedInstances < MAX_EDITED_INSTANCES");
    }
    AfterSpawnEditedInstances();
}

// FUNCTION: 0x00148960 GetPtrToInstance__13EntityManagerFUi
void *EntityManager::GetPtrToInstance(unsigned int arg0) {
    void *pValue;
    if (((PHashTable *)m_unk5094)->Lookup((void *)arg0, pValue) != 0) {
        return pValue;
    }
    return 0;
}

// FUNCTION: 0x001489A0 GetPtrToApparition__13EntityManagerFUi
void *EntityManager::GetPtrToApparition(unsigned int arg0) {
    void *pValue;
    if (((PHashTable *)m_unk5088)->Lookup((void *)arg0, pValue) != 0) {
        return pValue;
    }
    return 0;
}

// FUNCTION: 0x001489E0 Animate__13EntityManagerFif
void EntityManager::Animate(int arg0, float arg1) {
    ParticleSubList *pList;
    void *pEnt;
    int flags;
    unsigned int i;

    gDebug.StartTimer(6);
    flags = arg0 | m_unk5058;
    m_unk50A4 = 0;
    pList = 0;
    if (m_unk50A0 != 0) {
        pList = (ParticleSubList *)m_unk50A8[0];
    }
    while (pList != 0) {
        pList->m_unk04 = 0;
        pEnt = 0;
        if (pList->m_unk00 != 0) {
            pEnt = pList->m_unk08[0];
        }
        while (pEnt != 0) {
            gDebug.StartDebugTimer();
            ((EntityBaseVirtuals *)pEnt)->Animate(flags, arg1);
            gDebug.StopDebugTimer(pEnt);
            i = pList->m_unk04 + 1;
            pList->m_unk04 = i;
            pEnt = (i < pList->m_unk00) ? pList->m_unk08[pList->m_unk04] : 0;
        }
        i = m_unk50A4 + 1;
        m_unk50A4 = i;
        pList = (ParticleSubList *)((i < m_unk50A0) ? m_unk50A8[m_unk50A4] : 0);
    }
    gDebug.StopTimer(6);
    gDebug.StartTimer(7);
    if (!(flags & 1)) {
        Animate__9EffectAPIFf(&mEffectAPI__13EntityManager, arg1);
    }
    gDebug.StopTimer(7);
}

// FUNCTION: 0x00148B90 ObjectCollision__13EntityManagerFv
void EntityManager::ObjectCollision() {
    gDebug.StartTimer(3);
    EntityBaseClass *pA;
    unsigned int j;
    int joff;
    int off;
    unsigned int i;
    i = 0;
    off = 0;
    for (; i < m_unk50B0; off += 4, i++) {
        pA = 0;
        if (i < m_unk50B0) { pA = *(EntityBaseClass **)((char *)m_unk50B8 + off); }
        j = i + 1;
        if (pA->m_unk10C & 0x07000000) {
            joff = j << 2;
            for (;;) {
                EntityBaseClass *pB = 0;
                if (j < m_unk50B0) { pB = *(EntityBaseClass **)((char *)m_unk50B8 + joff); }
                if (pB == 0) { break; }
                if (pB->m_unk10C & 0x07000000) {
                    if (pB->m_unk10C & 1) { pB->CollisionCheck(pA); } else { pA->CollisionCheck(pB); }
                }
                joff += 4;
                j++;
            }
        }
    }
    gDebug.StopTimer(3);
}

// FUNCTION: 0x00148CC0 RunPhysics__13EntityManagerFf
void EntityManager::RunPhysics(float arg0) {
    gDebug.StartTimer(2);
    m_unk50B4 = 0;
    EntityBaseClass *pEntity = (m_unk50B0 != 0) ? (EntityBaseClass *)m_unk50B8[0] : 0;
    if (pEntity != 0) {
        do {
            pEntity->ProcessPhysics(arg0, m_unk5058);
            unsigned int idx = m_unk50B4 + 1;
            m_unk50B4 = idx;
            pEntity = (idx < (unsigned int)m_unk50B0) ? (EntityBaseClass *)m_unk50B8[m_unk50B4] : 0;
        } while (pEntity != 0);
    }
    gDebug.StopTimer(2);
}

// FUNCTION: 0x00148D80 Render__13EntityManagerFP13PLightManager
int EntityManager::Render(PLightManager *arg0) {
    ParticleSubList *pList;
    EntityBaseVirtuals *pEnt;
    int total;

    gDebug.StartTimer(9);
    {
        void *pPlayer = m_unk505C;
        unsigned char flag = (pPlayer != 0);
        if (flag) {
            flag = (*((unsigned char *)pPlayer + 0x26C) != 0);
        }
        gGfxEng[0x158E21] = flag;
    }
    if (arg0 != 0) {
        gGfxEng[0x158E22] = 1;
    }
    total = 0;
    this->m_unk50A4 = 0;
    pList = (this->m_unk50A0 != 0) ? (ParticleSubList *)this->m_unk50A8[0] : 0;
    if (pList != 0) {
        do {
            pList->m_unk04 = 0;
            pEnt = (pList->m_unk00 != 0) ? (EntityBaseVirtuals *)pList->m_unk08[0] : 0;
            if (pEnt != 0) {
                do {
                    total += pEnt->Render(arg0);
                    pEnt = (++pList->m_unk04 < pList->m_unk00) ? (EntityBaseVirtuals *)pList->m_unk08[pList->m_unk04] : 0;
                } while (pEnt != 0);
            }
            pList = (++this->m_unk50A4 < this->m_unk50A0) ? (ParticleSubList *)this->m_unk50A8[this->m_unk50A4] : 0;
        } while (pList != 0);
    }
    gGfxEng[0x158E21] = 1;
    gDebug.StopTimer(9);
    gDebug.StartTimer(10);
    total += Render__9EffectAPIFP13PLightManager(&mEffectAPI__13EntityManager, arg0);
    gDebug.StopTimer(10);
    gGfxEng[0x158E22] = 0;
    return total;
}

// DRAFT: 0x00148F40 LoadResource__13EntityManagerFPcb
// note: 45 words, frame 0x130 vs 0x120 (saves s1 for arg0, buffer at sp+0x30); original saves arg0 in s0 and never spills this, a0 reaches AdjustPickupBox unreloaded; local name pointer variant also 45.
void EntityManager::LoadResource(char *arg0, bool arg1) {
    char buf[0x100];

    if (arg1) {
        if (((PResourceManager *)((char *)this + 0x50C4))->LoadGlobalResource(arg0, false) == 0) {
            sprintf(buf, "Error loading resource file ( %s )", arg0);
            CdsAssert("EntityManager.cpp", 0x221, buf);
        }
        ((Pickup *)((char *)this + 0x50C4))->AdjustPickupBox();
        return;
    }
    if (((PResourceManager *)((char *)this + 0x50C4))->LoadLocalResource(arg0, true) == 0) {
        sprintf(buf, "Error loading resource file ( %s )", arg0);
        CdsAssert("EntityManager.cpp", 0x228, buf);
    }
}

// FUNCTION: 0x00148FF0 Process__13EntityManagerFv
void EntityManager::Process() {
    gDebug.StartTimer(0xE);
    ((Camera *)(gEng + 0x19760))->ResetCamBoxCount();
    MemMgr.m_unk18 = 1;
    ProcessTrigger();
    int i = 0;
    do {
        if (!(GetItemCounter((ItemCounterType)i) <= 0.0f)) {
            float dec = *(float *)(gEng + 0x1E8);
            SetItemCounter((ItemCounterType)i, GetItemCounter((ItemCounterType)i) - dec);
        }
        i++;
    } while (i < ITEM_COUNTER_MAX);
    ProcessApparitions();
    mTimerAPI.ProcessTimers(this);
    ProcessIcons();
    ((EntityAttackManager *)this)->DisplayDebug();
    MemMgr.m_unk18 = 0;
    gDebug.StopTimer(0xE);
}

// DRAFT: 0x001490F0 SetItemCounter__13EntityManagerFQ213EntityManager15ItemCounterTypef
// note: 1 word differs: addu operand order (0048 original `addu v1,v1,a0`, ours `addu v1,a0,v1`). Tried: base-first sum (3), pointer index (3), signed index, constant-first base, multiply index, shift-assign index (1 each, no gain); all folding spellings from before (9-10).
void EntityManager::SetItemCounter(ItemCounterType theType, float value) {
    if (theType >= ITEM_COUNTER_MAX) {
        CdsAssert("EntityManager.cpp", 0x192, "theType < ITEM_COUNTER_MAX");
    }
    unsigned int idx = (unsigned int)theType << 2;
    unsigned int base = (unsigned int)this + 0x5F74;
    *(float *)(idx + base) = value;
}

// DRAFT: 0x00149160 GetItemCounter__13EntityManagerFQ213EntityManager15ItemCounterType
// note: 1 word differs: addu operand order (0040 original `addu v0,v0,v1`, ours `addu v0,v1,v0`); the sll-first schedule and the 0x5F74 addiu now match. Tried: m_unk5F74[i], float* and char* bases (8), base-first, constant-first base, pointer index (3 or 1), signed index, multiply index (1 each).
float EntityManager::GetItemCounter(ItemCounterType theType) {
    if (theType >= ITEM_COUNTER_MAX) {
        CdsAssert("EntityManager.cpp", 0x18A, "theType < ITEM_COUNTER_MAX");
    }
    unsigned int idx = (unsigned int)theType << 2;
    unsigned int base = (unsigned int)this + 0x5F74;
    return *(float *)(idx + base);
}

// DRAFT: 0x001491C0 CallOnTimerEvent__13EntityManagerFUiUi
// note: 16 lines, all in the failure branch; the Slot09 call and Lookup match under the current PVirtObj layout. Original tests the string address at runtime (lui/addiu/sltu/xori/bnez over the CdsAssert call, frame 0x30) and ours folds !"..." away; tried local char* pMsg (0x40 frame, worse), early return (more lines), if(!(!"...")) else arm (16 lines, kept).
void EntityManager::CallOnTimerEvent(unsigned int arg0, unsigned int arg1) {
    void *pValue;
    if (((PHashTable *)m_unk5088)->Lookup((void *)arg0, pValue) != 0) {
        ((PVirtObj *)pValue)->Slot09(arg1);
    } else {
        if (!(!"Invalid Apparition Accessed")) {
            CdsAssert("EntityManager.cpp", 0x184, "!\"Invalid Apparition Accessed\"");
        }
    }
}

// FUNCTION: 0x00149240 AddToRenderList__13EntityManagerFP15EntityBaseClass
void EntityManager::AddToRenderList(EntityBaseClass *arg0) {
    PArray *pList;
    PArray *pNew;
    unsigned int i;
    int key;

    ((PArray *)&m_unk50B0)->Add(arg0);
    key = arg0->m_unk08;
    m_unk50A4 = 0;
    pList = 0;
    if (m_unk50A0 != 0) {
        pList = (PArray *)m_unk50A8[0];
    }
    while (pList != 0) {
        EntityBaseClass *pEnt;
        pList->m_unk4 = 0;
        if (pList->m_unk0 != 0) {
            pEnt = (EntityBaseClass *)pList->m_unk8[0];
        } else {
            pEnt = 0;
        }
        if (key == pEnt->m_unk08) {
            pList->Add(arg0);
            return;
        }
        i = m_unk50A4 + 1;
        m_unk50A4 = i;
        pList = 0;
        if (i < m_unk50A0) {
            pList = (PArray *)m_unk50A8[m_unk50A4];
        }
    }
    pNew = new PArray;
    if (pNew == 0) {
        CdsAssert("EntityManager.cpp", 0x16C, "pList");
    }
    pNew->Add(arg0);
    ((PArray *)&m_unk50A0)->Add(pNew);
}

// FUNCTION: 0x00149370 RemoveFromRenderList__13EntityManagerFP15EntityBaseClass
void EntityManager::RemoveFromRenderList(EntityBaseClass *arg0) {
    int key;
    PArray *pList;
    unsigned int i;

    if (((PArray *)&m_unk50B0)->Remove(arg0) != 0) {
        key = arg0->m_unk08;
        m_unk50A4 = 0;
        pList = (m_unk50A0 != 0) ? (PArray *)m_unk50A8[0] : 0;
        while (pList != 0) {
            EntityBaseClass *pEnt;
            pList->m_unk4 = 0;
            pEnt = (pList->m_unk0 != 0) ? (EntityBaseClass *)pList->m_unk8[0] : 0;
            if (pEnt == 0) {
                CdsAssert("EntityManager.cpp", 0x14A, "pEnt");
            }
            if (key == pEnt->m_unk08 && pEnt != 0) {
                for (;;) {
                    if (pEnt == arg0) {
                        pList->RemoveCurrent();
                        if (pList->m_unk0 == 0) {
                            ((PArray *)&m_unk50A0)->RemoveCurrent();
                            delete pList;
                        }
                        return;
                    }
                    i = pList->m_unk4 + 1;
                    pList->m_unk4 = i;
                    pEnt = (i < pList->m_unk0) ? (EntityBaseClass *)pList->m_unk8[pList->m_unk4] : 0;
                    if (pEnt == 0) {
                        break;
                    }
                }
            }
            i = m_unk50A4 + 1;
            m_unk50A4 = i;
            pList = (i < m_unk50A0) ? (PArray *)m_unk50A8[m_unk50A4] : 0;
        }
    }
}

// FUNCTION: 0x00149500 Destroy__13EntityManagerFUiUi
void EntityManager::Destroy(unsigned int arg0, unsigned int arg1) {
    if (arg1 != 0) {
        ((PHashTable *)m_unk5094)->Remove((void *)arg1);
    }
    PVirtObj *pObj = (PVirtObj *)((PHashTable *)m_unk5088)->Remove((void *)arg0);
    if (pObj != 0) {
        pObj->Slot25();
        ((PArray *)&m_unk5078)->Remove(pObj);
        RemoveFromRenderList((EntityBaseClass *)pObj);
        if (pObj != 0) {
            pObj->Slot02(1);
        }
    }
}

// FUNCTION: 0x001495A0 Spawn__13EntityManagerFUibi
void *EntityManager::Spawn(unsigned int arg0, bool arg1, int arg2) {
    void *pEnt;
    if (arg1) {
        pEnt = SpawnEntity(arg0, arg2);
    } else {
        pEnt = SpawnEntity(arg0, -1);
    }
    if (pEnt == (void *)-1) {
        char buf[0x100];
        sprintf(buf, "EIF file for level ( %s ) out of date. Re-export with latest BEF files", (char *)this + 0x5C10);
        CdsAssert("EntityManager.cpp", 0x107, buf);
    }
    if (pEnt == 0) {
        CdsAssert("EntityManager.cpp", 0x10B, "pEnt");
    }
    *((char *)pEnt + 0x18) = (char)arg1;
    ((EntityBaseClass *)pEnt)->m_unk08 = arg0;
    ((EntityBaseClass *)pEnt)->m_unk04 = m_unk5050;
    if (!arg1) {
        ((PVirtObj *)pEnt)->Slot08();
    }
    if (arg0 == 3) {
        if (!((m_unk505C != 0) ^ 1)) {
            CdsAssert("EntityManager.cpp", 0x118, "!mpPlayer");
        }
        m_unk505C = pEnt;
        mPlayerAPI__13EntityManager = (MathAPI *)m_unk505C;
    }
    if (m_unk5078 >= 0x180) {
        CdsAssert("EntityManager.cpp", 0x11D, "mActiveApparitions.GetCount() < MAX_ACTIVE_APPARITIONS");
    }
    ((PArray *)&m_unk5078)->Add(pEnt);
    int saved = MemMgr.m_unk18;
    MemMgr.m_unk18 = 0;
    ((PHashTable *)m_unk5088)->Add((void *)m_unk5050, pEnt);
    MemMgr.m_unk18 = saved;
    m_unk5050 += 1;
    return pEnt;
}

// FUNCTION: 0x00149720 Reset__13EntityManagerFb
void EntityManager::Reset(bool arg0) {
    m_unk5058 = 0;
    m_unk5D4C = 0;
    m_unk5050 = 1;
    m_unk5054 = 1;
    m_unk5D48 = 4;
    ((PHashTable *)m_unk5088)->RemoveAll();
    ((PHashTable *)m_unk5094)->RemoveAll();
    *(int *)((char *)this + 0x5B4C) = 0;
    m_unk505C = 0;
    mPlayerAPI__13EntityManager = 0;
    m_unk507C = 0;
    void *pSleep = 0;
    if (m_unk5078 != 0) {
        pSleep = m_unk5080[0];
    }
    if (pSleep != 0) {
        do {
            if (pSleep != 0) {
                ((SleepEntity *)pSleep)->Sleep(1);
            }
            unsigned int idx = m_unk507C + 1;
            m_unk507C = idx;
            pSleep = (idx < m_unk5078) ? m_unk5080[m_unk507C] : 0;
        } while (pSleep != 0);
    }
    if (m_unk5080 != 0) {
        m_unk5078 = 0;
        m_unk507C = 0;
    }
    m_unk50A4 = 0;
    void *pSub = 0;
    if (m_unk50A0 != 0) {
        pSub = m_unk50A8[0];
    }
    if (pSub != 0) {
        do {
            __dt__6PArrayFv(pSub, 1);
            unsigned int idx = m_unk50A4 + 1;
            m_unk50A4 = idx;
            pSub = (idx < m_unk50A0) ? m_unk50A8[m_unk50A4] : 0;
        } while (pSub != 0);
    }
    if (m_unk50A8 != 0) {
        m_unk50A0 = 0;
        m_unk50A4 = 0;
    }
    if (m_unk50B8 != 0) {
        m_unk50B0 = 0;
        m_unk50B4 = 0;
    }
    if (arg0) {
        m_unk5B20 = 0;
        m_unk5B21 = 0;
        m_unk519C = 0;
    } else {
        ValidateDependencyList();
    }
    RestoreHolyGround();
    m_unk5B64 = 0;
    void *pTrig = 0;
    if (m_unk5B60 != 0) {
        pTrig = m_unk5B68[0];
    }
    if (pTrig != 0) {
        do {
            __dl__FPv(pTrig);
            unsigned int idx = m_unk5B64 + 1;
            m_unk5B64 = idx;
            pTrig = 0;
            if (idx < (unsigned int)m_unk5B60) {
                pTrig = m_unk5B68[m_unk5B64];
            }
        } while (pTrig != 0);
    }
    if (m_unk5B68 != 0) {
        m_unk5B60 = 0;
        m_unk5B64 = 0;
    }
    ((PList *)((char *)this + 0x5B80))->RemoveAll();
    int cnt = 0;
    if (arg0) {
        m_unk5070 = 0;
        memset((char *)this + 0x53A0, 0, 0x600);
        memset((char *)this + 0x59A0, 0, 0x180);
        if (m_unk5B78 != 0) {
            m_unk5B70 = 0;
            m_unk5B74 = 0;
        }
        CEifFile *pEif = m_unk5194;
        if (pEif != 0) {
            __dt__8CEifFileFv(pEif, 1);
            m_unk5194 = 0;
        }
    } else {
        int ofs = 0;
        do {
            char *pBase = (char *)this + ofs;
            cnt += 8;
            pBase[0x53A2] = 0;
            pBase[0x53A6] = 0;
            pBase[0x53AA] = 0;
            pBase[0x53AE] = 0;
            pBase[0x53B2] = 0;
            pBase[0x53B6] = 0;
            pBase[0x53BA] = 0;
            pBase[0x53BE] = 0;
            ofs += 0x20;
        } while (cnt < 0x180);
        m_unk5B74 = 0;
        void *pNode = 0;
        if (m_unk5B70 != 0) {
            pNode = m_unk5B78[0];
        }
        if (pNode != 0) {
            do {
                ((PMNode *)pNode)->RecurseResetAnimByID(0x202);
                ((PMNode *)pNode)->RecurseResetAnimByID(0x1FF);
                unsigned int idx = m_unk5B74 + 1;
                m_unk5B74 = idx;
                pNode = 0;
                if (idx < (unsigned int)m_unk5B70) {
                    pNode = m_unk5B78[m_unk5B74];
                }
            } while (pNode != 0);
        }
        ResetSwordBGAnim();
    }
    Reset__9EffectAPIFv(&mEffectAPI__13EntityManager);
    m_unk5F5C = m_unk5F54;
    Icon *pIcon = 0;
    if (m_unk5F54 != 0) {
        pIcon = (Icon *)*m_unk5F54;
    }
    if (pIcon != 0) {
        do {
            pIcon->Reset();
            void **pCur = m_unk5F5C;
            if (pCur == 0) {
                m_unk5F5C = m_unk5F54;
                pIcon = (m_unk5F54 != 0) ? (Icon *)*m_unk5F54 : 0;
            } else {
                void **pNext = (void **)pCur[1];
                if (pNext != 0) {
                    m_unk5F5C = pNext;
                    pIcon = (Icon *)m_unk5F5C[0];
                } else {
                    pIcon = 0;
                }
            }
        } while (pIcon != 0);
    }
}

// DRAFT: 0x00149B10 LoadOverlay__13EntityManagerFPcPc
// note: 21 words differ; the original tests the failure-message string address at runtime (lui/addiu/sltu/xori/bnez, skip over the CdsAssert call) and ours folds the test away; the 0x13-word beqz skip differs from 0x15. Tried !(!"...") (23), local char* pMsg with pMsg != 0 (21), !(!pMsg) (21, kept as pMsg != 0 form).
void EntityManager::LoadOverlay(char *arg0, char *arg1) {
    m_unk5D4C = 0;
    Reset(true);
    if (arg0 != 0) {
        if (((OverlayManager *)m_unk50C0)->LoadOverlay(arg0) == 0) {
            char *pMsg = "Load Overlay failed";
            if (pMsg != 0) {
                CdsAssert("EntityManager.cpp", 0x8A, "!\"Load Overlay failed\"");
            }
        }
        LoadResource(arg1, false);
    }
}

// FUNCTION: 0x00149BB0 Init__13EntityManagerFv
void EntityManager::Init() {
    EntityManager::mCameraAPI = gEng + 0x19760;
    m_unk5D4C = 0;
}

// FUNCTION: 0x00149BD0 __dt__13EntityManagerFv
EntityManager::~EntityManager() {
    Reset(true);
    ((PArray *)((char *)this + 0x5F64))->~PArray();
    ((PList *)((char *)this + 0x5F50))->~PList();
    ((PList *)((char *)this + 0x5B80))->~PList();
    ((PArray *)((char *)this + 0x5B70))->~PArray();
    ((PArray *)((char *)this + 0x5B60))->~PArray();
    ((PArray *)((char *)this + 0x5B50))->~PArray();
    ((PResourceManager *)((char *)this + 0x50C4))->~PResourceManager();
    ((PArray *)((char *)this + 0x50B0))->~PArray();
    ((PArray *)((char *)this + 0x50A0))->~PArray();
    ((PHashTable *)((char *)this + 0x5094))->~PHashTable();
    ((PHashTable *)((char *)this + 0x5088))->~PHashTable();
    ((PArray *)((char *)this + 0x5078))->~PArray();
    ((WaypointManager *)((char *)this + 0x30))->~WaypointManager();
    if (this != 0) {
        ((PList *)this)->~PList();
    }
}

// DRAFT: 0x00149CE0 __ct__13EntityManagerFv
// note: DIFF 140; members not embedded as real classes, so this is spilled and reloaded at 0x1C(sp) with a 0x20 frame; original keeps this in s5 with a 0xB0 frame and caches member addresses in s7/fp/s6/s0. Tried: first draft only.
EntityManager::EntityManager() {
    __ct__19EntityAttackManagerFv(this);
    __ct__15WaypointManagerFv((char *)this + 0x30);
    __ct__6PArrayFv((char *)this + 0x5078);
    __ct__10PHashTableFv((char *)this + 0x5088);
    __ct__10PHashTableFv((char *)this + 0x5094);
    __ct__6PArrayFv((char *)this + 0x50A0);
    __ct__6PArrayFv((char *)this + 0x50B0);
    __ct__16PResourceManagerFv((char *)this + 0x50C4);
    __ct__6PArrayFv((char *)this + 0x5B50);
    __ct__6PArrayFv((char *)this + 0x5B60);
    __ct__6PArrayFv((char *)this + 0x5B70);
    __ct__5PListFv((char *)this + 0x5B80);
    __ct__5PListFv((char *)this + 0x5F50);
    __ct__6PArrayFv((char *)this + 0x5F64);
    m_unk5050 = 1;
    if (Create__10PHashTableFUi((char *)this + 0x5088, 0x11) == 0) {
        char *pMsg = "Hash table creation failed";
        if (pMsg != 0) {
            CdsAssert("EntityManager.cpp", 0x34, "!\"Hash table creation failed\"");
        }
    }
    if (Create__10PHashTableFUi((char *)this + 0x5094, 0x11) == 0) {
        char *pMsg = "Hash table creation failed";
        if (pMsg != 0) {
            CdsAssert("EntityManager.cpp", 0x3A, "!\"Hash table creation failed\"");
        }
    }
    ((PArray *)((char *)this + 0x5078))->Allocate(0x180);
    ((PArray *)((char *)this + 0x50A0))->Allocate(0x20);
    ((PArray *)((char *)this + 0x50B0))->Allocate(0x180);
    ((PArray *)((char *)this + 0x5B60))->Allocate(0x20);
    ((PArray *)((char *)this + 0x5B70))->Allocate(0x20);
    ((PArray *)((char *)this + 0x5B50))->Allocate(0x20);
    ((PArray *)((char *)this + 0x5F64))->Allocate(0x180);
    void *pOverlay = __nw__FUi(0x28);
    if (pOverlay != 0) {
        pOverlay = __ct__14OverlayManagerFUi(pOverlay, 1);
    }
    m_unk50C0 = pOverlay;
    if (m_unk50C0 == 0) {
        CdsAssert("EntityManager.cpp", 0x48, "WorldOverlays");
    }
    InitLoadSystem__15EntityBaseClassFv();
    m_unk505C = 0;
    m_unk5194 = 0;
    m_unk5B20 = 0;
    m_unk5B21 = 0;
    *(int *)((char *)this + 0x5F60) = 1;
    printf("Entity Manager v%d\n", 1);
}

// DRAFT: 0x00149F60 SequenceViewer__15EntityBaseClassFPPUii
// note: 28 words differ; s1 init is daddiu not addiu, dispatch chain offsets off by 2 words, case-3 halfword interleave, loop-tail daddu/nop shape. Tried: arm orders, bool flag (size grows to 0x1B8).
int EntityBaseClass::SequenceViewer(unsigned int **arg0, int arg1) {
    struct SeqAnimData {
        unsigned short m_unk00;
        unsigned short m_unk02;
        unsigned short m_unk04;
        unsigned short m_unk06;
        unsigned short m_unk08;
        short m_unk0A;
        float m_unk0C;
    };
    char *s0 = (char *)arg0[arg1];
    int s1 = 1;
    do {
        int op = *(int *)s0;
        s0 += 4;
        switch (op) {
        case 1:
            if (LoadMesh(*(unsigned int *)s0, false, false) == 0) {
                s1 = 0;
            }
            s0 += 4;
            break;
        case 2:
            if (LoadAnim(*(unsigned int *)s0, false) == 0) {
                s1 = 0;
            }
            s0 += 4;
            break;
        case 3: {
            SeqAnimData anim;
            anim.m_unk00 = *(unsigned short *)(s0 + 0x00);
            anim.m_unk02 = *(unsigned short *)(s0 + 0x04);
            anim.m_unk04 = *(unsigned short *)(s0 + 0x08);
            anim.m_unk06 = *(unsigned short *)(s0 + 0x0C);
            anim.m_unk08 = *(unsigned short *)(s0 + 0x10);
            anim.m_unk0A = *(unsigned short *)(s0 + 0x14);
            if (anim.m_unk0A == 2) {
                anim.m_unk0A = 6;
            }
            anim.m_unk0C = (float)*(int *)(s0 + 0x18) / 256.0f;
            s0 += 0x1C;
            SetAnimData((AnimData *)&anim);
            s1 = 0;
            break;
        }
        case 0xFF:
            s1 = 0;
            break;
        case 4:
            s0 += 0xC;
            break;
        case 6:
        case 5:
        case 9:
        case 0xA:
            s0 += 4;
            break;
        case 7:
            s0 += 8;
            break;
        default:
            break;
        }
    } while (s1 != 0);
    return 0;
}

// DRAFT: 0x0014A220 CameraLookingAtMe__15EntityBaseClassFv
// note: 2 words; lui for 0x420C lands in v1, original uses v0 (0x38 lui, 0x3C mtc1); tried reversed compare (4), if-return (3), direct m_unk20[1] (23), inline fabs, if/else pointer, float local, p before pf, bool temp (all 2, pf and fabs locals kept).
bool EntityBaseClass::CameraLookingAtMe() {
    MathAPI *pCam = (MathAPI *)EntityManager::mCameraAPI;
    float *pf = pCam->m_unk20;
    float (*p)[4] = m_unk3C != 0 ? (float (*)[4])(m_unk3C + 0x80) : &m_unk190;
    float a = FastMath_Fabs(pCam->GetRelAngleYToPoint(p, pf[1], (float (*)[4])pCam));
    return a <= 35.0f;
}

// FUNCTION: 0x0014A290 PlingInnocent__15EntityBaseClassFv
void EntityBaseClass::PlingInnocent() {
    float sp40[4];
    Player *player = *(Player **)(mpEntMgr__15EntityBaseClass + 0x505C);
    char *a2 = m_unk3C != 0 ? m_unk3C + 0x80 : (char *)m_unk190;
    char *a1 = player->m_unk3C != 0 ? player->m_unk3C + 0x80 : (char *)player->m_unk190;
    sceVu0SubVector(sp40, (float *)a1, (float *)a2);
    if (sceVu0InnerProduct(sp40, sp40) < 36.0f && CameraLookingAtMe()) {
        char *s2 = player->m_unk3C + 0x40;
        sceVu0Normalize(sp40, sp40);
        if (!(sceVu0InnerProduct((float *)(s2 + 0x20), sp40) <= 0.5f)) {
            player->SetPling((Player::PlingType)6, this, 0U);
        }
    }
}
