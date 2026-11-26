#ifndef PGRIMREAPERCAPE_H
#define PGRIMREAPERCAPE_H

#include "types.h"
#include "PDynamicSplinePatch.h"

class PMNode;

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
};

#endif
