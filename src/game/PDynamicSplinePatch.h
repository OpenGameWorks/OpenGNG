#ifndef PDYNAMICSPLINEPATCH_H
#define PDYNAMICSPLINEPATCH_H

#include "types.h"

class PMNode;

// Spline patch driven by a control node. Init stores three clamped counts at 0x00, 0x04, 0x08, 0x0C.
// Animate and SetControlNode copy node quadwords into a ring of 32 matrix slots of 0x40 bytes at 0x1690.
class PDynamicSplinePatch {
public:
    void Render();
    void Animate(float fTime);
    void SetControlNode(PMNode *pNode);
    int Init(int nA, int nB, int nC, float *pVecA, float *pVecB);

    void GenerateAndRenderVuSplinePatch();
    void InitSplineKeys(float *pVecA, float *pVecB);
    void InitMatrixCache();
    void ApplyControlMatrices();

    int m_unk00;                    // 0x00
    int m_unk04;                    // 0x04
    int m_unk08;                    // 0x08
    int m_unk0C;                    // 0x0C
    char _pad10[0x1690 - 0x10];
    char m_unk1690[0x800];          // 32 slots of 0x40 bytes
    char _pad1E90[0x1F68 - 0x1E90];
    int m_unk1F68;                  // 0x1F68, ring index into m_unk1690
    void *m_unk1F6C;                // 0x1F6C, PMNode *
    char _pad1F70[0x20];
    float m_unk1F90[4];             // 0x1F90
    float m_unk1FA0[4];             // 0x1FA0
    char _pad1FB0[0x20];
    char m_unk1FD0[0x10];           // 0x1FD0, quadword copy of node + 0x70
    int m_unk1FE0;                  // 0x1FE0
    char _pad1FE4[0x2011 - 0x1FE4];
    unsigned char m_unk2011;        // 0x2011, render enable
    unsigned char m_unk2012;        // 0x2012, matrix cache reset request
};

#endif
