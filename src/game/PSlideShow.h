#ifndef PSLIDESHOW_H
#define PSLIDESHOW_H

#include "types.h"

class PSlideShow {
public:
    struct tagTile {
        char _pad000[0x2C];
        float m_fUnk2C;                         // 0x02C
    };

    struct tagGsPoly {
        char _pad000[0xC];
        int m_unkC;                             // 0x00C
        char _pad010[0x1D];
        unsigned char m_ucUnk2D;                // 0x02D
        char _pad02E[0x1F];
        unsigned char m_ucUnk4D;                // 0x04D
        char _pad04E[0x42];                     // 0x04E; the 16-byte stores at 0x20, 0x40, 0x60, 0x80 end at 0x90
    };

    PSlideShow();
    ~PSlideShow();
    void SetGsPolyPos(tagGsPoly *pPoly, tagTile *pTile, float *pA, float *pB);
    void Animate(float fTime);
    void SetNextImage(int nImage);
    void AnimateFallingTiles(float fTime);
    void AnimateFadingTiles(float fTime);
    void AnimateVanishingTiles(float fTime);

    char _pad000[0x4];
    int m_unk04;                                // 0x004
    int m_nNextImage;                           // 0x008
    void *m_unkC;                               // 0x00C
    void *m_unk10;                              // 0x010
    int m_unk14;                                // 0x014
    int m_unk18;                                // 0x018
    int m_unk1C;                                // 0x01C
    int m_unk20;                                // 0x020
    void *m_unk24;                              // 0x024
    void *m_unk28;                              // 0x028
    int m_unk2C;                                // 0x02C
    int m_nMode;                                // 0x030
    int m_unk34;                                // 0x034
    char _pad038[0x8];
    unsigned char m_ucUnk40;                    // 0x040
    unsigned char m_ucUnk41;                    // 0x041
    unsigned char m_ucUnk42;                    // 0x042
};

#endif
