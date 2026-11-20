#ifndef MOVIE_H
#define MOVIE_H

#include "types.h"

class Movie {
public:
    static void BeginFadeMusicVolume(unsigned int msecs, unsigned int target);
    static void MovieOutputCurVol();
    static void MovieVolInit();
    static unsigned int MovieIOPAlloc(unsigned int size, const char *name);
    static int MovieMemAlign64(unsigned int size, const char *name);

    static int mst_bMusicFading;
    static float mst_fMusicRelVolFadeCur;
    static float mst_fMusicRelVolFadeDelta;
    static unsigned int mst_uMusicFadeMsecs;
    static unsigned int mst_uMusicRelVolBase;
    static unsigned int mst_uMusicRelVolCur;
    static unsigned int mst_uMusicRelVolFadeTarget;
    static unsigned int mst_uMusicVolRawCur;
};

#endif
