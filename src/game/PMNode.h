#ifndef PMNODE_H
#define PMNODE_H

#include "types.h"

struct tagParticleFxTrigger;
class PObjectDisplayList;
class PArray;
// TODO(header): eBoxIntersect belongs to the owner header of the box-test enum. Placeholder until that header defines it; only the name matters for mangling.
enum eBoxIntersect { eBoxIntersect_Placeholder = 0 };

class PMNode {
public:
    int AddFxTrigger(tagParticleFxTrigger *pTrigger, bool bFlag);
    void SetAllFade(float fFade);
    float GetFrameRate();
    int GetWorldMeshCenter(float *pOut);
    void DisableAllHitBox();
    void ScaleSet(float a, float b, float c, float d);
    void DestroyMesh();
    void RecurseSetFade(float fFade);
    void DestroyAnim();
    void RecurseDetachAnim();
    void DestroyFxTriggers(bool bA, bool bB, bool bC);
    void *GetFirstMesh();
    void StopAmbientSoundsByObject();
    int CreateObjectDisplayList();
    void CopyFxTriggers(PMNode &src);
    void BuildDispList(PArray *pArr);
    void SetAllFrustrumTest(eBoxIntersect eMode);

    char _pad000[4];
    int m_unk04;            // 0x004 state; 2 skips frustum test
    char _pad008[4];
    int m_unk0C;            // 0x00C eBoxIntersect mode
    void *m_unk10;          // 0x010 PMesh *
    unsigned int m_unk14;   // 0x014 child count
    unsigned int m_unk18;   // 0x018 child index
    PMNode **m_unk1C;       // 0x01C child array
    char _pad020[0x4];
    void *m_unk24;          // 0x024 object whose vtable slot 0x48 returns a frame rate
    int m_unk28;            // 0x028
    float m_unk2C;          // 0x02C fade value
    int m_unk30;            // 0x030
    int m_unk34;            // 0x034
    float m_unk38;          // 0x038
    unsigned char m_unk3C;  // 0x03C
    char _pad03D[0x1];
    unsigned char m_unk3E;  // 0x03E flags: 0x01 owns mesh, 0x08 scale set
    unsigned char m_unk3F;  // 0x03F
    float m_unk40[4][4];    // 0x040 matrix; row 3 (0x070) is a vector
    char _pad080[0x20];
    float m_unkA0[4];       // 0x0A0
    char _pad0B0[0x20];
    int m_unkD0;            // 0x0D0 signed; negative means no display entry
    bool m_unkD4;           // 0x0D4 out flag from PObjectDisplayList::Create
    char _padD5[0x3];
    unsigned int m_unkD8;   // 0x0D8 fx trigger count
    char _padDC[0x4];
    tagParticleFxTrigger **m_unkE0; // 0x0E0 fx trigger array
    char _padE4[0x14];
    PObjectDisplayList *m_pObjDisplayList; // 0x0F8
};

#endif
