#ifndef PSOUND_H
#define PSOUND_H

class PSound {
public:
    class AmbientChannelState {
    public:
        AmbientChannelState();
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

    class MusicStreamState {
    public:
        MusicStreamState();
        void Init();
    };

    class OneShotChannelState {
    public:
        OneShotChannelState();
        void Init();

        char _pad00[0x10];
        int m_unk10;        // 0x10, Init sets 0x3FFF
        short m_unk14;      // 0x14
        short m_unk16;      // 0x16
        int m_unk18;        // 0x18
        int m_unk1C;        // 0x1C
        int m_unk20;        // 0x20
        int m_unk24;        // 0x24
        int m_unk28;        // 0x28
        int m_unk2C;        // 0x2C
    };

    class AmbientEntry {
    public:
        char _pad00[0x50];
        AmbientEntry *m_unk50;  // 0x50
        AmbientEntry *m_unk54;  // 0x54
    };

    class SpotInfo {
    public:
        SpotInfo();
        void Init();
    };

    void InternalUpdateRelVolumes();
    void AmbientFadeToFree(AmbientChannelState *pState);
    int StopAllSounds();
    int SetStandardSecondaryMusicFileID(unsigned int id);
    void PSoundReInitTriglets();
    void EnableLevelProcessing(bool bEnable);
    void LinkAmbientEntry(AmbientEntry *pEntry, AmbientEntry *pNext);
    void SetProposedReverbParams(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
    void SetMonoOut(bool bMono);
    void SetMainMusicRelVolume(unsigned int nVolume);

    char _pad000[0x024];
    unsigned int m_unk024;  // 0x024
    char _pad028[0x030 - 0x028];
    int m_unk30;            // 0x030, RelVolumes arg 8
    int m_unk34;            // 0x034, RelVolumes arg 1
    int m_unk38;            // 0x038, RelVolumes arg 2
    int m_unk3C;            // 0x03C, RelVolumes arg 3
    int m_unk40;            // 0x040, RelVolumes arg 4
    char _pad044[0x0EC - 0x044];
    int m_unk0EC;           // 0x0EC
    int m_unk0F0;           // 0x0F0
    char _pad0F4[0x5438 - 0x0F4];
    unsigned int m_unk5438; // 0x5438, SetProposedReverbParams arg 0
    char _pad543C[0x79E0 - 0x543C];
    int m_unk79E0[6];       // 0x79E0
};

#endif
