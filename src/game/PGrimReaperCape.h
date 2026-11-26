#ifndef PGRIMREAPERCAPE_H
#define PGRIMREAPERCAPE_H

#include "types.h"
#include "PDynamicSplinePatch.h"

class PMNode;
class PAnim;

// Grim reaper cape: a PDynamicSplinePatch with no members of its own. Enable writes the
// base render flag at 0x2011 and the control-node flag at 0x2012. SetAnimation copies a
// 0x48-byte lag control matrix index block into the base at 0x1F20.
enum eGrimCapeTable {
    kGrimCapeTable0,
    kGrimCapeTable1,
    kGrimCapeTable2,
    kGrimCapeTable3,
    kGrimCapeTable4,
    kGrimCapeTable5,
    kGrimCapeTable6,
    kGrimCapeTable7,
    kGrimCapeTable8,
    kGrimCapeTable9,
    kGrimCapeTable10,
    kGrimCapeTable11,
    kGrimCapeTable12
};

class PGrimReaperCape : public PDynamicSplinePatch {
public:
    PGrimReaperCape();
    ~PGrimReaperCape();
    void Enable(bool bEnable, PMNode *pNode);
    void SetAnimation(eGrimCapeTable eTable);
    void SetAnimation(unsigned int nAnimId);
    void AnimateControlNode(PAnim *pAnim, float fTime);
    void Init(float *pVec);
    void Init();
    // Angle accumulator and step, past the base class end (0x2018).
    char _pad2018[8];
    float m_unk2020;                // 0x2020
    float m_unk2024;                // 0x2024
};

#endif
