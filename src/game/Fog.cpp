// FLAGS: -str readonly
#include "types.h"
#include "Fog.h"
#include "PZBufferFog.h"

// TODO(header): foreign declarations
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);

// DRAFT: 0x001CFC20 Execute__3FogFv
// note: 25 words differ; the -2 body loads 0x21C and literals in a different order, and the prologue schedules addiu v1,-2 differently. Tried switch orders (-1,-2,0 / -2,0,-1 / 0,-1,-2) and if/else-if orders; the if-chain (-2,0,-1) gives the fewest differing words.
void Fog::Execute() {
    if (m_unk20 == -2) {
        if (m_unk21C == 0) {
            CdsAssert__FPciPc("Fog.cpp", 0x25, "m_FogObj");
        }
        m_unk21C->m_unk17A9 = 0;
    } else if (m_unk20 == 0) {
    } else if (m_unk20 == -1) {
        SetState(0);
    }
}

// FUNCTION: 0x001CFCA0 __dt__3FogFv
Fog::~Fog() {
    if (m_unk21C != 0) {
        m_unk21C->m_unk17A9 = 0;
    }
}

// FUNCTION: 0x001CFD10 __ct__3FogFv
Fog::Fog() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
