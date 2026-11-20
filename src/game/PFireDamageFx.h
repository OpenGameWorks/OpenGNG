#ifndef PFIREDAMAGEFX_H
#define PFIREDAMAGEFX_H

#include "types.h"

class PMNode;

// Maps a character type id to its row in gCharacterInfoTable (0 when unknown).
int GetCharacterType(unsigned int uType);

// Fire damage helper embedded in PParticleManager at offset 0x2088. It declares
// no virtuals and no data members; the constructor and destructor store nothing
// of their own.
class PFireDamageFx {
public:
    ~PFireDamageFx();
    int Create(PMNode *poRoot, unsigned int uCharType);
};

#endif
