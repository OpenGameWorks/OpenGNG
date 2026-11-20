#ifndef PMNODE_H
#define PMNODE_H

#include "types.h"
#include "PMesh.h"

struct tagParticleFxTrigger;
class PObjectDisplayList;
class PArray;
class PAnim;
class PAnimFrame;
class AnimData;
class PPakFile;
class PMat4;
class PLightManager;
// TODO(header): eBoxIntersect belongs to the owner header of the box-test enum. Placeholder until that header defines it; only the name matters for mangling.
enum eBoxIntersect { eBoxIntersect_Placeholder = 0 };

class PMNode {
public:
    virtual ~PMNode();
    virtual int Render(PLightManager *pLM, int nArg1, int nArg2);
    int PlaySound(unsigned int arg0);
    int AddFxTrigger(tagParticleFxTrigger *pTrigger, bool bFlag);
    void AddFxTriggers(PArray *pArr, bool bFlag);
    void SetAllFade(float fFade);
    float GetFrameRate();
    PMNode *FindBone(unsigned int uID);
    void SetFrameRate(float fRate, bool bFlag);
    int GetDeltaMove(PAnimFrame *pFrame, float (*pOut)[4]);
    int GetWorldMeshCenter(float *pOut);
    int CalculateMatrix(float fA, PMNode *pNode, float (*pOut)[4][4]);
    void DisableAllHitBox();
    void AnimateBox(float fTime);
    int Find(PMNode *pNode);
    PMNode *Find(unsigned int uID);
    void ScaleSet(float a, float b, float c, float d);
    void DestroyChildren();
    void DestroyMesh();
    void RecurseSetFade(float fFade);
    void DestroyAnim();
    void RecurseDetachAnim();
    void AttachAnim(PAnim *pAnim, bool bFlag);
    void DestroyFxTriggers(bool bA, bool bB, bool bC);
    void DestroyFxTriggersBySpawnFrame(float fFrame, bool bFlag);
    void *GetFirstMesh();
    void StopAmbientSoundsByObject();
    void StopAllSoundsByObject();
    int CreateObjectDisplayList();
    void *AttachFx(unsigned int uID, float fA, float fB, float fC, float fD, bool bFlag);
    void CopyFxTriggers(PMNode &src);
    void BuildDispList(PArray *pArr);
    void AddBoneMatrixToDisplayList(bool bRecurse);
    void SetFrameTime(float fTime);
    float GetFrameTime();
    void SetAnimLoopCount(int nCount, bool bFlag);
    void SetAllAnimFlags(AnimData *pAnim);
    void BuildAnimList(PArray *pArr, unsigned int uID);
    PMNode *FindAnimNode(unsigned int uID);
    void SetAllLoopCountByID(unsigned int uID, int nCount);
    void SetAllFrustrumTest(eBoxIntersect eMode);
    void InitMembers();
    void RemoveNullAnimation();
    void UpdateCameraFade(bool bFlag);
    int LoadFxTriggers(PPakFile *pFile);
    int LoadMesh(PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion);
    void RecurseEnableBone(PArray *pArr, bool bFlag);
    void EnableOneRenderPassOnly(int nPass);
    void SetRenderPassStatus(bool bA, bool bB, bool bC, bool bD);
    unsigned char RecurseSetSTAnimOptions(bool bFlag);
    int LoadAnim(PPakFile *pFile);
    int CheckAnimated();
    int RecurseSetAnimFlagsByID(unsigned int uID, AnimData *pAnim);
    int RecurseApplyAnimFlagsByID(unsigned int uID, bool bA, int nB);
    int RecurseApplyAnimLoopByID(unsigned int uID, short sA, int nB, bool bC);
    void EnableAnim(bool bA, bool bB);
    int RecurseSetLoopRateByID(unsigned int uID, int nCount, float fRate);
    int RecurseResetAnimByID(unsigned int uID);
    void ProcessFxTriggers(float fTime, PMat4 *pMat, bool bA, bool bB);
    void SetFxColorMultiplier(float *pColor, bool bFlag);
    void EnableFx(bool bA, bool bB);
    void DebugDrawBox(int nMode);
    void CopyMNode(PMNode &src, bool bFlag);

    int m_unk04;           // 0x004 state; 2 skips frustum test
    int m_unk08;            // 0x008 zeroed by InitMembers
    int m_unk0C;            // 0x00C eBoxIntersect mode
    void *m_unk10;          // 0x010 PMesh *
    unsigned int m_unk14;   // 0x014 child count
    unsigned int m_unk18;   // 0x018 child index
    PMNode **m_unk1C;       // 0x01C child array
    char _pad020[0x4];
    void *m_unk24;          // 0x024 object whose vtable slot 0x48 returns a frame rate
    void *m_unk28;          // 0x028 AnimateBox result (PChannel return or PMesh + 0x10)
    float m_unk2C;          // 0x02C fade value
    int m_unk30;            // 0x030
    int m_unk34;            // 0x034
    float m_unk38;          // 0x038
    unsigned char m_unk3C;  // 0x03C
    unsigned char m_unk3D;  // 0x03D
    unsigned char m_unk3E;  // 0x03E flags: 0x01 owns mesh, 0x08 scale set
    signed char m_unk3F;    // 0x03F flags: 0x01 set by RecurseSetAnimFlagsByID, 0x02 child matched; read with lb
    float m_unk40[4][4];    // 0x040 matrix; row 3 (0x070) is a vector
    float m_unk80[4];       // 0x080 CalculateMatrix copy target
    float m_unk90[4];       // 0x090 CalculateMatrix vector
    float m_unkA0[4];       // 0x0A0
    float m_unkB0[4];       // 0x0B0 CalculateMatrix matrix
    float m_unkC0[4];       // 0x0C0 CalculateMatrix matrix
    int m_unkD0;            // 0x0D0 signed; negative means no display entry
    bool m_unkD4;           // 0x0D4 out flag from PObjectDisplayList::Create
    unsigned char m_unkD5;  // 0x0D5
    unsigned char m_unkD6;  // 0x0D6
    unsigned char m_unkD7;  // 0x0D7
    unsigned int m_unkD8;   // 0x0D8 fx trigger count
    unsigned int m_unkDC;   // 0x0DC fx trigger index in DestroyFxTriggers
    tagParticleFxTrigger **m_unkE0; // 0x0E0 fx trigger array
    char _padE4[0x4];
    int m_unkE8;            // 0x0E8 copy of mst_NextPMNodeRef
    int m_unkEC;            // 0x0EC
    int m_unkF0;            // 0x0F0
    unsigned char m_unkF4;  // 0x0F4
    char _padF5[0x3];
    PObjectDisplayList *m_pObjDisplayList; // 0x0F8
    char _pad0FC[0x14];
    float m_unk110[2][4];                  // 0x110 box used by DebugDrawBox
};

#endif
