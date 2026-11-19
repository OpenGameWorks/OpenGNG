#ifndef PFRUSTRUM_H
#define PFRUSTRUM_H

#include "types.h"

class PMat4;

class PFrustrum {
public:
    void Init(float, float, float, float, PMat4 *, float (*)[4]);
    char _pad000[0x10];
};

#endif
