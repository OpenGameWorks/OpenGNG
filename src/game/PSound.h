#ifndef PSOUND_H
#define PSOUND_H

class PSound {
public:
    class AmbientChannelState {
    public:
        void Init();
        void ReInit();

        int m_unk00;        // 0x00, Init sets 0x3FFF
        short m_unk04;      // 0x04
        char _pad06[0x02];
        int m_unk08;        // 0x08
        int m_unk0C;        // 0x0C
        int m_unk10;        // 0x10
        int m_unk14;        // 0x14
        char _pad18[0x04];
        int m_unk1C;        // 0x1C
    };

    void AmbientFadeToFree(AmbientChannelState *pState);
    int StopAllSounds();
    int SetStandardSecondaryMusicFileID(unsigned int id);
    void PSoundReInitTriglets();
    void EnableLevelProcessing(bool bEnable);

    char _pad000[0x024];
    unsigned int m_unk024;  // 0x024
    char _pad028[0x0EC - 0x028];
    int m_unk0EC;           // 0x0EC
    int m_unk0F0;           // 0x0F0
    char _pad0F4[0x79E0 - 0x0F4];
    int m_unk79E0[6];       // 0x79E0
};

#endif
