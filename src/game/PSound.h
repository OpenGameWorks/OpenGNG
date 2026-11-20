#ifndef PSOUND_H
#define PSOUND_H

// Forward declarations of foreign classes named by PSound member parameters.
class GameSoundTrigletPawn;
class PMNode;

class PSound {
public:
    ~PSound();

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
        void ReInit();
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
        unsigned int m_unk10;   // 0x10, Resume skips entries at or above 0x3FFD, Init sets 0x3FFF
        short m_unk14;          // 0x14, Init sets 0x400
        unsigned short m_unk16; // 0x16, bit 0 is cleared on Resume
        short m_unk18;          // 0x18, Init sets -1
        short m_unk1A;          // 0x1A
        int m_unk1C;            // 0x1C
        char m_unk20[0x3C - 0x20];  // 0x20, PFadeMsecFloat built by the ctor
        int m_unk3C;            // 0x3C
        int m_unk40;            // 0x40
        unsigned int m_unk44;   // 0x44, FindAmbientEntry and IsAmbientSoundBySoundRef compare it
        int m_unk48;            // 0x48
        int m_unk4C;            // 0x4C
        AmbientEntry *m_unk50;  // 0x50
        AmbientEntry *m_unk54;  // 0x54
        char _pad58[0x5C - 0x58];
        int m_unk5C;            // 0x5C, Init sets 0x7F7FFFFF
        int m_unk60;            // 0x60
        int m_unk64;            // 0x64
        int m_unk68;            // 0x68
        char m_unk6C;           // 0x6C
        char _pad6D[0x70 - 0x6D];   // entries of the ambient table are 0x70 apart
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
    void SetMasterRelVolume(unsigned int nVolume);
    void SetEffectsRelVolume(unsigned int nVolume);
    int StopSoundBySoundRefIfAmbient(unsigned int nSoundRef);
    unsigned int FindFreeAmbientChannel();
    int StartAndHoldDialog(unsigned int nArg);
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
    AmbientEntry *FindAmbientEntry(unsigned int nID);
    int StartAESoftwareFadeout(unsigned int nID, unsigned int nArg);
    int StartAESoftwareFadeout(AmbientEntry *pEntry, unsigned int nArg);
    int IsAmbientSoundBySoundRef(unsigned int nSoundRef);
    int TranslateIntoADSR(unsigned int nArg);
    void PSoundLevelClear();
    void PSoundStopDialog();
    void UsageInit();
    void SetProposedReverbParams(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
    void SetMonoOut(bool bMono);
    void SetMainMusicRelVolume(unsigned int nVolume);
    int PlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
    int PlaySoundTrigletUbiquitous(unsigned int p0, unsigned int p1, const GameSoundTrigletPawn *pPawn);
    int PlaySoundPMNode(unsigned int p0, unsigned int p1, const PMNode *pNode);
    int StopAllRegularSounds();
    void StopStreamsAndRequestEEControl();
    int GetEEControlStatus();
    int DebugPlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2);
    void DebugClearPlayedInGame();
    void PSoundReInitRegularSounds();
    void SetEEControlOfIOP(unsigned int nMode);
    void Resume();
    void Pause();
    void ResumeAmbientEntry(AmbientEntry *pEntry);
    int AddChanToMultipleResumes(unsigned int nChan);
    int AddChanToMultiplePauses(unsigned int nChan);
    int AddChanToMultipleStops(unsigned int nChan);
    int RestartAndLoadInterfaceTypeBank(unsigned int nArg);
    int RestartAndLoadPrimarySoundBank(unsigned int nArg);
    int SetLevelParameters(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3);
    void PSoundFlushIOPCommandsWaitFinish();
    void KillByCategories(unsigned int nCategory);
    void PauseByCategories(unsigned int nCategory);
    void DebugStopAllDebugAmbients();
    void SendStops();
    void SoundEditLeave();
    void SoundEditEnter();
    unsigned int FindFadingAmbientChannel();
    void WaitOnVSync();
    void SetMusicPitchBend(bool bBend);
    void PSoundReInitMusic();
    void StopMusic();
    int *UsageFind(unsigned int nID);
    int UsageAdd(unsigned int nID);
    void DebugRestartValues();
    int DebugFindLastID(unsigned int *pValue, unsigned int *pIndex);
    int DebugFindFirstID(unsigned int *pValue, unsigned int *pIndex);

    int m_unk00;            // 0x000, GetEEControlStatus tests it
    char _pad004[0x010 - 0x004];
    unsigned int m_unk10;   // 0x010, DebugRestartValues range check
    unsigned int m_unk14;   // 0x014, record count for DebugFindLastID/DebugFindFirstID
    char _pad018[0x01C - 0x018];
    unsigned int m_unk1C;   // 0x01C, PlayMusic stores it, PSoundReInitMusic clears it
    int m_unk20;            // 0x020, PSoundReInitMusic clears it
    unsigned int m_unk024;  // 0x024
    unsigned int m_unk28;   // 0x028, PlayMusic passes it to PlayMusicOnStream
    int m_unk2C;            // 0x02C, PSoundReInitMusic clears it
    int m_unk30;            // 0x030, RelVolumes arg 8
    int m_unk34;            // 0x034, RelVolumes arg 1
    int m_unk38;            // 0x038, RelVolumes arg 2
    int m_unk3C;            // 0x03C, RelVolumes arg 3
    int m_unk40;            // 0x040, RelVolumes arg 4
    char _pad044[0x04C - 0x044];
    int m_unk4C;            // 0x04C, SetMasterRelVolume arg 3
    int m_unk50;            // 0x050, SetEffectsRelVolume arg 3
    char _pad054[0x058 - 0x054];
    float m_unk58;         // 0x058, SetPositionalRangeOneshot sets it
    float m_unk5C;          // 0x05C, SetPositionalRangeAmbient sets it
    char _pad060[0x0B0 - 0x060];
    int m_unkB0;            // 0x0B0, SendStops clears it
    int m_unkB4;            // 0x0B4, SendStops clears it
    unsigned int m_unkB8[2];// 0x0B8, AddChanToMultiplePauses bit masks (index 1 for channels 0x18 and up)
    unsigned int m_unkC0[2];// 0x0C0, AddChanToMultipleResumes bit masks (index 1 for channels 0x18 and up)
    int m_unkC8;           // 0x0C8, SoundEditEnter sets 1, SoundEditLeave clears it
    char _padCC[0x0CD - 0x0CC];
    char m_unkCD;           // 0x0CD, PSoundReInitMusic clears it
    char m_unkCE;           // 0x0CE, PSoundReInitMusic clears it
    char m_unkCF;           // 0x0CF, PSoundStopDialog clears it
    bool m_unkD0;           // 0x0D0, ErrorRecovery reads it before PSoundRestart
    char _pad0D1[0x0DC - 0x0D1];
    int m_unkDC;            // 0x0DC, PSoundReInitMusic clears it
    int m_unkE0;            // 0x0E0, PSoundReInitMusic sets 0x3E8
    char _pad0E4[0x0EC - 0x0E4];
    int m_unk0EC;           // 0x0EC
    int m_unk0F0;           // 0x0F0
    AmbientEntry *m_unkF4;  // 0x0F4, head of the ambient entry list (AddAEToFreeList passes &m_unkF4)
    char m_unkF8[0x2E28 - 0x0F8];   // 0x0F8, AmbientChannelState array of stride 0x20, FindFadingAmbientChannel scans it
    unsigned int m_unk2E28; // 0x2E28, FindFadingAmbientChannel start index
    unsigned int m_unk2E2C; // 0x2E2C, FindFadingAmbientChannel limit
    char _pad2E30[0x2E48 - 0x2E30];
    int m_unk2E48;          // 0x2E48, SoundEditLeave copies 0x2E4C here
    int m_unk2E4C;          // 0x2E4C, SoundEditLeave/Enter category mask
    int m_unk2E50[4];       // 0x2E50, PSoundStopDialog zeroes 0x2E50..0x2E5C
    int m_unk2E60;          // 0x2E60, StartAndHoldDialog stores its value
    char _pad2E64[0x2E74 - 0x2E64];
    int m_unk2E74;          // 0x2E74, GetEEControlStatus stores its result
    char _pad2E78[0x2EB4 - 0x2E78];
    char m_unk2EB4[0x2580]; // 0x2EB4, 400 SpotInfo records of 0x18 bytes, GetSpotInfo scans them
    char _pad5434[0x5438 - 0x5434];
    unsigned int m_unk5438; // 0x5438, SetProposedReverbParams arg 0
    int m_unk543C;          // 0x543C, SetMusicPitchBend bit 0
    char _pad5440[0x5444 - 0x5440];
    int m_unk5444;          // 0x5444, PSoundReInitSoundRooms sets -1
    char _pad5448[0x544C - 0x5448];
    int m_unk544C;          // 0x544C, PSoundReInitSoundRooms clears it
    char _pad5450[0x5460 - 0x5450];
    char m_unk5460[0x2580]; // 0x5460, PSoundReInitSoundRooms clears it
    int m_unk79E0[6];       // 0x79E0
    char _pad79F8[0x1808C - 0x79F8];
    char m_unk1808C;        // 0x1808C, AddChanToMultiplePauses/Stops write here at this + 0x1808C + channel
};

#endif
