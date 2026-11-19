#ifndef PSOUND_H
#define PSOUND_H

// Forward declarations of foreign classes named by PSound member parameters.
class GameSoundTrigletPawn;
class PMNode;

class PSound {
public:
    class AmbientChannelState {
    public:
        AmbientChannelState();
        void Init();
        void ReInit();

        int m_unk00;        // 0x00, Init sets 0x3FFF
        short m_unk04;      // 0x04
        short m_unk06;      // 0x06, ReInit keeps it across Init
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
        AmbientEntry();
        void Init();

        char _pad00[0x10];
        unsigned int m_unk10;   // 0x10, Resume skips entries at or above 0x3FFD
        char _pad14[0x02];
        unsigned short m_unk16; // 0x16, bit 0 is cleared on Resume
        char _pad18[0x20 - 0x18];
        char m_unk20[0x50 - 0x20];  // 0x20, PFadeMsecFloat built by the ctor
        AmbientEntry *m_unk50;  // 0x50
        AmbientEntry *m_unk54;  // 0x54
    };

    class SpotInfo {
    public:
        SpotInfo();
        void Init();

        int m_unk00;            // 0x00, Init sets 0x3FFF
        int m_unk04;            // 0x04
        short m_unk08;          // 0x08
        short m_unk0A;          // 0x0A
        unsigned char m_unk0C;  // 0x0C, IsAmbientSoundByID tests bit 1
        char _pad0D[0x01];
        char m_unk0E;           // 0x0E
        char m_unk0F;           // 0x0F
        char m_unk10;           // 0x10
        char m_unk11;           // 0x11
        char m_unk12;           // 0x12, Init sets 0x11
        char _pad13[0x02];
        char m_unk15;           // 0x15
    };

    enum EnumMusicSpecialVols {
        MUSIC_SPECIAL_VOLS_NONE = 0
    };

    void ErrorRecovery();
    void PSoundRestart();
    void AbilityScreenEnter();
    void AbilityScreenLeave();
    void SetMainMusicSpecialVolume(EnumMusicSpecialVols eVol);
    int PlayMusicOnStream(unsigned int p0, unsigned int p1, unsigned int p2);
    void SetPositionalRangeAmbient(unsigned int nRange);
    void SetPositionalRangeOneshot(unsigned int nRange);
    int PlayMusic(unsigned int nTrack);
    void PSoundReInitSoundRooms();
    void PSoundReInitSub(unsigned int nMode);
    void PSoundReInitSubWSoundCalls();
    int IsAmbientSoundByID(unsigned int nID);
    SpotInfo *GetSpotInfoPtrByPublicID(unsigned int nID);
    SpotInfo *GetSpotInfo(unsigned int nID);
    void InternalUpdateRelVolumes();
    void AmbientFadeToFree(AmbientChannelState *pState);
    int StopAllSounds();
    int SetStandardSecondaryMusicFileID(unsigned int id);
    void PSoundReInitTriglets();
    void EnableLevelProcessing(bool bEnable);
    void EnableProcessTriglets(bool bEnable);
    void LinkAmbientEntry(AmbientEntry *pEntry, AmbientEntry *pNext);
    void InsertAEAtHead(AmbientEntry **ppHead, AmbientEntry *pEntry);
    void AddAEToFreeList(AmbientEntry *pEntry);
    void DelinkAmbientEntry(AmbientEntry *pEntry);
    int PauseAmbientEntry(AmbientEntry *pEntry, unsigned int nFlag);
    void SetProposedReverbParams(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
    void SetMonoOut(bool bMono);
    void SetMainMusicRelVolume(unsigned int nVolume);
    int PlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
    int PlaySoundTrigletUbiquitous(unsigned int p0, unsigned int p1, const GameSoundTrigletPawn *pPawn);
    int PlaySoundPMNode(unsigned int p0, unsigned int p1, const PMNode *pNode);
    int StopAllRegularSounds();
    void StopStreamsAndRequestEEControl();
    int DebugPlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2);
    void PSoundReInitRegularSounds();
    void SetEEControlOfIOP(unsigned int nMode);
    void Resume();
    void Pause();
    void ResumeAmbientEntry(AmbientEntry *pEntry);
    void PSoundFlushIOPCommandsWaitFinish();
    void KillByCategories(unsigned int nCategory);
    void PauseByCategories(unsigned int nCategory);

    char _pad000[0x01C];
    unsigned int m_unk1C;   // 0x01C, PlayMusic stores its argument
    char _pad020[0x024 - 0x020];
    unsigned int m_unk024;  // 0x024
    unsigned int m_unk28;   // 0x028, PlayMusic passes it to PlayMusicOnStream
    char _pad02C[0x030 - 0x02C];
    int m_unk30;            // 0x030, RelVolumes arg 8
    int m_unk34;            // 0x034, RelVolumes arg 1
    int m_unk38;            // 0x038, RelVolumes arg 2
    int m_unk3C;            // 0x03C, RelVolumes arg 3
    int m_unk40;            // 0x040, RelVolumes arg 4
    char _pad044[0x058 - 0x044];
    float m_unk58;          // 0x058, SetPositionalRangeOneshot sets it
    float m_unk5C;          // 0x05C, SetPositionalRangeAmbient sets it
    char _pad060[0x0D0 - 0x060];
    bool m_unkD0;           // 0x0D0, ErrorRecovery reads it before PSoundRestart
    char _pad0D1[0x0EC - 0x0D1];
    int m_unk0EC;           // 0x0EC
    int m_unk0F0;           // 0x0F0
    AmbientEntry *m_unkF4;  // 0x0F4, head of the ambient entry list (AddAEToFreeList passes &m_unkF4)
    char _pad0F8[0x2EB4 - 0x0F8];
    char m_unk2EB4[0x2580]; // 0x2EB4, 400 SpotInfo records of 0x18 bytes, GetSpotInfo scans them
    char _pad5434[0x5438 - 0x5434];
    unsigned int m_unk5438; // 0x5438, SetProposedReverbParams arg 0
    char _pad543C[0x5444 - 0x543C];
    int m_unk5444;          // 0x5444, PSoundReInitSoundRooms sets -1
    char _pad5448[0x544C - 0x5448];
    int m_unk544C;          // 0x544C, PSoundReInitSoundRooms clears it
    char _pad5450[0x5460 - 0x5450];
    char m_unk5460[0x2580]; // 0x5460, PSoundReInitSoundRooms clears it
    int m_unk79E0[6];       // 0x79E0
};

#endif
