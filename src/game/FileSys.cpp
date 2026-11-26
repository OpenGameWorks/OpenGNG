#include "FileSys.h"
#include "IOPTransactionManager.h"
#include "PIOPFile.h"

// TODO(header): foreign declarations
extern IOPTransactionManager gIOPTransactionManager;

// FUNCTION: 0x001DA5B0 FrameMaintenacePartB__7FileSysFv
void FileSys::FrameMaintenacePartB() {
    if (mst_bIncludeIOP != 0) {
        gIOPTransactionManager.FrameMaintenacePartB();
        PIOPFile::FrameMaintenacePartB();
    }
}

// FUNCTION: 0x001DA5E0 FrameMaintenacePartA__7FileSysFv
void FileSys::FrameMaintenacePartA() {
    if (mst_bIncludeIOP != 0) {
        gIOPTransactionManager.FrameMaintenacePartA();
        PIOPFile::FrameMaintenacePartA();
    }
}
