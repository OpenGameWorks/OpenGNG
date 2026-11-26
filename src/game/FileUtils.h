#ifndef FILEUTILS_H
#define FILEUTILS_H

// Loading-hang watchdog: the vblank counter snapshot at load start and the hung flag.
class FileUtils {
public:
    static int GetHung();
    static void LoadingHangCheckInit();

    static int mst_bGameHung;
};

#endif
