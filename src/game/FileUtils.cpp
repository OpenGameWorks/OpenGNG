#include "types.h"
#include "FileUtils.h"

// TODO(header): gCDSVBlankCount belongs to the vblank handler's header.
extern unsigned int gCDSVBlankCount;

int FileUtils::mst_bGameHung;
static unsigned int fst_uHangFrameStart;
static unsigned int fst_uHangFrameReStart;

// FUNCTION: 0x00214200 GetHung__9FileUtilsFv
int FileUtils::GetHung() {
    return mst_bGameHung;
}

// FUNCTION: 0x00214210 LoadingHangCheckInit__9FileUtilsFv
void FileUtils::LoadingHangCheckInit() {
    fst_uHangFrameStart = gCDSVBlankCount;
    fst_uHangFrameReStart = fst_uHangFrameStart;
}
