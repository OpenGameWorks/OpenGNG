// FLAGS: -str readonly
#include "types.h"
#include "BreakableItem.h"

#include "EffectAPI.h"
#include "PMNode.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

struct BreakableItemEntry {
    unsigned int m_unk0;
    unsigned int *m_unk4;
    unsigned int *m_unk8;
    char _pad0C[0x10];
    unsigned int m_unk1C;
    unsigned int m_unk20;
};

extern BreakableItemEntry BreakableItemTable[8];
extern unsigned int Crystalwall_SwordBreak1Seq[11];
extern EffectAPI mEffectAPI__13EntityManager;

// FUNCTION: 0x001D74D0 __dt__13BreakableItemFv
BreakableItem::~BreakableItem() {
}

// FUNCTION: 0x001D7530 GetClassName__13BreakableItemFv
const char *BreakableItem::GetClassName() {
    return "BreakableItem";
}

// FUNCTION: 0x001D7540 SetEditableVars__13BreakableItemFPc
void BreakableItem::SetEditableVars(char *pSrc) {
    memcpy(&m_unk1B0, pSrc, 0xC);
    CheckVariable(m_unk1B0, 8);
}

// FUNCTION: 0x001D7580 OnHitEvent__13BreakableItemFP15EntityBaseClassiUiUi
int BreakableItem::OnHitEvent(EntityBaseClass *pArg, int nHit, unsigned int nFlagsA, unsigned int nFlagsB) {
    BreakableItemEntry *pEntry;

    if (*((unsigned char *)pArg + 0x10C) == 1) {
        if (nHit != 0) {
            switch (m_unk1B0) {
            case 0:
                mEffectAPI__13EntityManager.CreateOneshot(0x01000143, 0x02000296, 0, 0, this, 1.0f, false, 0, false);
                goto block_11;
            case 5:
                if (!(nFlagsA & 0x40)) {
                    PlaySequence(Crystalwall_SwordBreak1Seq);
                    PlaySound(0x18F);
                    return 1;
                }
                goto block_11;
            case 1:
                if (m_unk1C5 == 0) {
                    m_unk1C5 = 1;
                    ((PMNode *)m_unk3C)->EnableAnim(true, true);
                    PlaySound(0x15A);
                    return 1;
                }
                goto block_11;
            default:
            block_11:
                m_unk1C0 += 1;
                m_unk1BC -= nHit;
                pEntry = &BreakableItemTable[m_unk1B0];
                if (pEntry->m_unk1C != 0) {
                    PlaySound(pEntry->m_unk1C);
                }
                if ((m_unk1C0 >= 3U) || (m_unk1BC <= 0)) {
                    SetState(2);
                    return 1;
                } else {
                    switch (m_unk1C0) {
                    case 1:
                        PlaySequence(pEntry->m_unk4);
                        break;
                    case 2:
                        PlaySequence(pEntry->m_unk8);
                        break;
                    default:
                        SetState(2);
                        return 1;
                    }
                }
                break;
            }
        }
    }
    return 1;
}

// FUNCTION: 0x001D7C40 __ct__13BreakableItemFv
BreakableItem::BreakableItem() : EntityBaseClass((LoadClass)2, 2) {
    m_unk1BC = 0x78;
    m_unk1C0 = 0;
    m_unk1C4 = 0;
    m_unk1C5 = 0;
}
