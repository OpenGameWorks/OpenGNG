#ifndef POBJECTDISPLAYLIST_H
#define POBJECTDISPLAYLIST_H

#include "types.h"

class PMNode;
class PShader;

class PObjectDisplayList {
public:
    PObjectDisplayList();
    ~PObjectDisplayList();
    void Destroy();
    int IsTextureUnique(int nTexture);
    int IsShaderUnique(PShader *pShader);
    void GetNumSharedBones(PMNode *pNode, int *pCount);

    int m_unk0;             // 0x000 cleared by ctor
    int m_unk4;             // 0x004
    int m_unk8;             // 0x008
    char m_unkC[0x10];      // 0x00C PArray, size not recovered
    int m_unk1C;            // 0x01C
    int m_unk20;            // 0x020 shader count
    char m_unk24[0xC0];     // 0x024 cleared by ctor
    PShader *m_apoShaders[12];  // 0x0E4 shader pointers
    int m_unk114;           // 0x114 texture count
    int m_unk118[0x30];     // 0x118 texture ids
    char _pad1D8[0xC];
    char m_unk1E4;          // 0x1E4 cleared by ctor
    char m_unk1E5;          // 0x1E5 cleared by ctor
};

#endif
