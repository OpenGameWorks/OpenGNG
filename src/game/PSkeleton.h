#ifndef PSKELETON_H
#define PSKELETON_H

#include "types.h"
#include "PMesh.h"

class PArray;
class PObjectDisplayList;
class AnimData;
class PMat4;
class PMeshNodeAnimDataTable;
class PLightManager;
class PPakFile;

class PSkeleton {
public:
    // Slots 0-2 are not yet identified; VSlot3 sits at vtable offset 0x14.
    virtual void VSlot0();
    virtual void VSlot1();
    virtual void VSlot2();
    virtual void VSlot3(unsigned int nId);

    int CreateObjectDisplayList();
    void EnableBone(unsigned int *pIds, bool bEnable);
    void SetSharedBonePtr(PMesh *pMesh);
    void SetFrameTime(float fTime);
    int RecurseAttachAnim(PMeshNodeAnimDataTable *pTable);
    void UpdateBoundBox();
    void BuildDispList();
    void SetAllAnimFlags(AnimData *pAnim);
    int Animate(float fTime, float fDelta, PMat4 *pMat, int nFlag, bool bFlag);
    void InitMembers();
    int Render(PLightManager *pLights, int nFlag, int nMode);
    int Load(PPakFile *pFile, PArray *pArr, ePsx2FileVersion eVersion);

    // 0x000 vtable pointer is implicit (virtual functions).
    unsigned int m_unk4;                // 0x004 cleared by InitMembers
    char _pad008[0x0C - 0x08];
    int m_unk0C;                        // 0x00C eBoxIntersect, read by Render
    void *m_unk10;                     // 0x010 PMesh *, passed to PObjectDisplayList::Create
    unsigned int m_unk14;               // 0x014 child count
    unsigned int m_unk18;               // 0x018 child index
    void **m_unk1C;                     // 0x01C child array
    char _pad020[0x24 - 0x20];
    void *m_unk24;                      // 0x024 frame source; vtable slot 0x1C returns the frame value
    char _pad028[0x2C - 0x28];
    float m_unk2C;                      // 0x02C copied from the child bone by Animate
    int m_unk30;                        // 0x030 cleared by RecurseAttachAnim
    float m_unk34;                      // 0x034 frame time
    float m_unk38;                      // 0x038 previous frame time
    char _pad03C[0x3E - 0x3C];
    unsigned char m_unk3E;              // 0x03E flags; 0x08 set by SetFrameTime
    unsigned char m_unk3F;              // 0x03F set to 3 by SetAllAnimFlags
    char m_unk40[0x40];                 // 0x040 4x4 matrix, source of sceVu0ApplyMatrix
    char m_unk80[0x10];                 // 0x080 vector, destination of sceVu0ApplyMatrix
    char _pad090[0xD4 - 0x90];
    bool m_unkD4;                       // 0x0D4 out flag from PObjectDisplayList::Create
    char _padD5[0xF8 - 0xD5];
    PObjectDisplayList *m_unkF8;        // 0x0F8
    char _pad0FC[0x110 - 0xFC];
    float m_unk110;                     // 0x110 bounding box centre X, (min + max) / 2
    float m_unk114;                     // 0x114 bounding box centre Y
    float m_unk118;                     // 0x118 bounding box centre Z
    char _pad11C[0x120 - 0x11C];
    float m_unk120;                     // 0x120 bounding box half extent X, max - centre
    float m_unk124;                     // 0x124 half extent Y
    float m_unk128;                     // 0x128 half extent Z
    float m_unk12C;                     // 0x12C bounding radius, 1.5 * sqrt(dot(extent, extent))
    char _pad130[0x140 - 0x130];
    float m_unk140[4];                  // 0x140 vector filled by GetDeltaMove, source of sceVu0ApplyMatrix
    char m_unk150[0x4];                 // 0x150 PArray, passed by address
    unsigned int m_unk154;              // 0x154 PArray index
    void **m_unk158;                    // 0x158 PArray data, element pointers
    int m_unk15C;                       // 0x15C
};

#endif
