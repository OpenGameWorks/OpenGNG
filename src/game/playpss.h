#ifndef PLAYPSS_H
#define PLAYPSS_H

#include "types.h"

struct sceMpeg;
struct sceMpegCbData;

struct sceMpegCbDataStr {
    char _pad0[8];
    int m_unk8;
    unsigned int m_unkC;
};

// Resource block passed to playPss; fields inferred from playPss__FPFPvi_iP12PlayPssRsrcsiUi.
struct PlayPssRsrcs {
    int m_unk0;
    int m_unk4;
    void *m_unk8;
    unsigned int *m_unkC;
    int m_unk10;
    int m_unk14;
    int m_unk18;
    int m_unk1C;
    int m_unk20;
    int m_unk24;
    int m_unk28;
    int m_unk2C;
    int m_unk30;
};

#endif
