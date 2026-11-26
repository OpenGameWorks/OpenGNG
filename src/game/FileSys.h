#ifndef FILESYS_H
#define FILESYS_H

#include "types.h"

// Static facade over the IOP transaction manager and the open-file list.
class FileSys {
public:
    static void FrameMaintenacePartA();
    static void FrameMaintenacePartB();

    static unsigned char mst_bIncludeIOP;
};

#endif
