#ifndef BREAKABLEITEM_H
#define BREAKABLEITEM_H

#include "types.h"
#include "EntityBaseClass.h"

// EntityBaseClass occupies 0x000..0x18F; BreakableItem adds its fields from 0x190 on.
class BreakableItem : public EntityBaseClass {
public:
    virtual ~BreakableItem();
    const char *GetClassName();
    void Execute();

};

#endif
