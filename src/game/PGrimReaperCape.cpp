#include "types.h"
#include "PGrimReaperCape.h"

// TODO(header): foreign declarations
extern unsigned char giGrimLagControlMatrixIndices[936];
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void *__dt__19PDynamicSplinePatchFv(PDynamicSplinePatch *pThis, short nFlag);

// FUNCTION: 0x001F42A0 Enable__15PGrimReaperCapeFbP6PMNode
void PGrimReaperCape::Enable(bool bEnable, PMNode *pNode)
{
    if (pNode == 0) {
        m_unk2011 = 0;
        return;
    }
    m_unk2011 = bEnable;
    if (m_unk2011 != 0) {
        SetControlNode(pNode);
        m_unk2012 = 1;
    }
}

// FUNCTION: 0x001F42F0 SetAnimation__15PGrimReaperCapeF14eGrimCapeTable
void PGrimReaperCape::SetAnimation(eGrimCapeTable eTable)
{
    memcpy(m_unk1F20, giGrimLagControlMatrixIndices + eTable * 0x48, 0x48);
}

// FUNCTION: 0x001F4320 SetAnimation__15PGrimReaperCapeFUi
void PGrimReaperCape::SetAnimation(unsigned int nAnimId)
{
    int nTable;
    switch (nAnimId) {
    case 0x820002E6:
        nTable = 1;
        break;
    case 0x820002E7:
        nTable = 2;
        break;
    case 0x820002FE:
        nTable = 12;
        break;
    case 0x82000339:
        nTable = 8;
        break;
    case 0x8200033A:
        nTable = 7;
        break;
    case 0x820002E3:
        nTable = 6;
        break;
    case 0x820002FF:
        nTable = 11;
        break;
    case 0x820002DF:
        nTable = 9;
        break;
    case 0x820002E0:
        nTable = 10;
        break;
    case 0x820002E2:
        nTable = 3;
        break;
    case 0x820002E5:
        nTable = 4;
        break;
    default:
        nTable = 0;
        break;
    }
    SetAnimation((eGrimCapeTable)nTable);
}

// FUNCTION: 0x001F4620 __dt__15PGrimReaperCapeFv
PGrimReaperCape::~PGrimReaperCape()
{
    __dt__19PDynamicSplinePatchFv(this, 0);
}

// FUNCTION: 0x001F4680 __ct__15PGrimReaperCapeFv
PGrimReaperCape::PGrimReaperCape() : PDynamicSplinePatch()
{
}
