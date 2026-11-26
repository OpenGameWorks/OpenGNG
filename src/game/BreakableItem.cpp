// FLAGS: -str readonly
#include "types.h"
#include "BreakableItem.h"

// TODO(header): foreign declarations
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nBytes);

// FUNCTION: 0x001D74D0 __dt__13BreakableItemFv
BreakableItem::~BreakableItem() {
}

// FUNCTION: 0x001D7530 GetClassName__13BreakableItemFv
const char *BreakableItem::GetClassName() {
    return "BreakableItem";
}
