#ifndef PBANECAPE_H
#define PBANECAPE_H

#include "types.h"
#include "PDynamicSplinePatch.h"

class PMNode;
class PAnim;

// Bane cape: a PDynamicSplinePatch with two angle words past the base class end (0x2018).
// Enable writes the base render flag at 0x2011 and the control-node flag at 0x2012.
class PBaneCape : public PDynamicSplinePatch {
public:
    PBaneCape();
    ~PBaneCape();
    void Enable(bool bEnable, PMNode *pNode);
    void Init(float *pVec);
    void Init();
    void AnimateControlNode(PAnim *pAnim, float fTime);
    // Past the base class end (0x2018).
    char _pad2018[8];
    float m_unk2020;                // 0x2020, angle accumulator
    float m_unk2024;                // 0x2024, angle step
};

#endif
