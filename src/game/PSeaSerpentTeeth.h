#ifndef PSEASERPENTTEETH_H
#define PSEASERPENTTEETH_H

#include "types.h"

class PMNode;
struct tagToothInfo;
struct tagVuStaticInstance;

class PSeaSerpentTeeth {
public:
    PSeaSerpentTeeth();
    ~PSeaSerpentTeeth();
    void ComputeInstanceData(PMNode *pNode, tagToothInfo *pTeeth, int nCount, tagVuStaticInstance *pOut);
    void KnockOutTeeth();
    void Render();

    PMNode *m_unk0;                 // 0x000
    char _pad004[4];                // 0x004
    PMNode *m_unk8;                 // 0x008
    PMNode *m_unkC;                 // 0x00C
    char m_unk10[0xB40];            // 0x010 tagToothInfo array, stride 0x30
    char m_unkB50[0x5A0];           // 0xB50 tagToothInfo array, stride 0x30
    char m_unk10F0[0x5A0];          // 0x10F0 tagToothInfo array, stride 0x30
    void *m_unk1690;                // 0x1690 PShader holder
    void *m_unk1694;                // 0x1694 PShader holder
    char _pad1698[8];               // 0x1698
    char m_unk16A0[0x12C0];         // 0x16A0 tagVuStaticInstance array
    char m_unk2960[0x960];          // 0x2960 tagVuStaticInstance array
    char m_unk32C0[0x960];          // 0x32C0 tagVuStaticInstance array
    unsigned char m_unk3C20;        // 0x3C20
};

#endif
