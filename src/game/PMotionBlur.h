#ifndef PMOTIONBLUR_H
#define PMOTIONBLUR_H

#include "types.h"
#include "PArray.h"

class PMNode;

// SetData parameter block: copied over the first 0x80 bytes of PMotionBlur.
// Count of blur objects at 0x08 (asserted below 4).
struct tagMotionBlurParams {
    char m_pad0[8];         // 0x00
    int m_unk8;             // 0x08
    char m_padC[0x74];      // 0x0C
};

// One blur entry: matrix block at 0x00 (64 bytes per step, freed through
// __destroy_new_array with PMat4's destructor), source pointer at 0x08.
struct PMotionBlurEntry {
    void *m_pMatrices;      // 0x00
    unsigned int m_unk4;    // 0x04
    void *m_pSource;        // 0x08
};

// Motion blur trail: source and blur nodes at 0x80/0x84, step count at 0x88,
// embedded entry array at 0x90 (PArray: count 0x90, storage 0x98), current
// write step at 0xA0. Size 0xA6.
class PMotionBlur {
public:
    PMotionBlur();
    ~PMotionBlur();
    void Reset();
    void Update();
    bool Create(PMNode *poSourceObj, PMNode *poBlurObj, int nCount);
    void CreateBlurNodes(PMNode *poSourceObj, PMNode *poBlurObj);
    void SetData(tagMotionBlurParams *pParams);

    char m_pad0[0x60];          // 0x00 cleared by Reset (memset 0x80)
    unsigned char m_unk60;      // 0x60
    char m_pad61[0x1F];         // 0x61
    PMNode *m_unk80;            // 0x80
    PMNode *m_unk84;            // 0x84
    int m_unk88;                // 0x88
    float m_unk8C;              // 0x8C set to 20.0f by the constructor
    PArray m_unk90;             // 0x90 entry array
    int m_unkA0;                // 0xA0 current write step
    unsigned char m_unkA4;      // 0xA4 active flag
    unsigned char m_unkA5;      // 0xA5
};

#endif
