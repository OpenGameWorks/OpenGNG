#ifndef PSOUND_H
#define PSOUND_H

// Forward declarations of foreign classes named by PSound member parameters.
class GameSoundTrigletPawn;
class PMNode;
class SoundRoom;
struct tagBOX_OR_SPHERE;
struct tagVuMatrixBox;
enum EnumEnclosureType {
    ENCLOSURE_SPHERE = 0,
    ENCLOSURE_MATRIX_BOX = 1
};
class EntityBaseClass;
enum EnumSoundTrigletPawnType {
    SOUND_TRIGLET_PAWN_TYPE_1 = 1,
    SOUND_TRIGLET_PAWN_TYPE_2 = 2
};

class PSound {
public:
    PSound();
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

        int m_unk00;        // 0x00, ReInit sets 0
        int m_unk04;        // 0x04, ReInit sets 0
        int m_unk08;        // 0x08, ReInit sets 0
        int m_unk0C;        // 0x0C, ReInit sets 1000
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
        int PossiblyRandomPitch();
        void Init();

        int m_unk00;            // 0x00, Init sets 0x3FFF
        int m_unk04;            // 0x04
        unsigned short m_unk08; // 0x08
        unsigned short m_unk0A; // 0x0A
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

    class PSoundUsage {
    public:
        unsigned int m_unk0;    // 0x00, record ID; 0xFFFFFFFF marks an unused record
        char _pad04[0x14 - 0x04];
    };

    enum EnumMusicSpecialVols {
        MUSIC_SPECIAL_VOLS_NONE = 0
    };

    void ErrorRecovery();
    unsigned char PSoundRestart();
    int RestartSuffix();
    void AbilityScreenEnter();
    void AbilityScreenLeave();
    void CutSceneLeave(unsigned int nArg);
    void CutSceneEnter(unsigned int *pOut, unsigned int nArg, unsigned int nFlags, unsigned int nVolume);
    void SetMainMusicSpecialVolume(EnumMusicSpecialVols eVol);
    int PointInEnclosure(float *pPoint, tagBOX_OR_SPHERE *pBox, tagVuMatrixBox *pMatrix, EnumEnclosureType eType);
    int CheckAllChannelsMatchSub();
    void CheckAllChannelsMatch();
    int CheckOneChannelMatchSub(AmbientChannelState *pState);
    int PlayMusicOnStream(unsigned int p0, unsigned int p1, unsigned int p2);
    void SetPositionalRangeAmbient(unsigned int nRange);
    void SetDistLinearPercent(unsigned int nPercent);
    void SetPositionalRangeOneshot(unsigned int nRange);
    int PlayMusic(unsigned int nTrack);
    void RegisterSoundEntityAmounts(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3);
    int RegisterRoom(SoundRoom *pRoom);
    int RegisterSoundTrigletPawn(EntityBaseClass *pEntity, EnumSoundTrigletPawnType eType);
    void PSoundReInitSoundRooms();
    void PSoundReInitSub(unsigned int nMode);
    void PSoundReInitSubWSoundCalls();
    void FadeOutAllMusic(unsigned int nArg);
    int IsAmbientSoundByID(unsigned int nID);
    SpotInfo *GetSpotInfoPtrByPublicID(unsigned int nID);
    SpotInfo *GetSpotInfo(unsigned int nID);
    void InternalUpdateRelVolumes();
    void SetMasterRelVolume(unsigned int nVolume);
    void SetEffectsRelVolume(unsigned int nVolume);
    void SetUbiquitousFactorRelVol(unsigned int nFactor);
    void SetPositionalFactorRelVol(unsigned int nFactor);
    int StopSoundBySoundRefIfAmbient(unsigned int nSoundRef);
    unsigned int FindFreeAmbientChannel();
    int DelinkChannelState(AmbientChannelState **ppHead, AmbientEntry *pEntry);
    int GetOriginatorPos(float *pOut, unsigned int nFlags, unsigned int nOriginator, unsigned int nNode);
    int PSoundInit(unsigned int nFlag);
    int StartAndHoldDialog(unsigned int nArg);
    int PrepDialog(unsigned int nArg);
    int StartPreppedDialog(unsigned int nArg);
    int GetDialogStreamReadiness(unsigned int nArg);
    int GetDialogPlayingStatus();
    void GetTrayRelated(int *pTrayOpen, int *pStatus, int *pReady, int *pType);
    void FadeMusicOnStream(unsigned int nStream, unsigned int nArg, unsigned int nFrames);
    void AmbientFadeToFree(AmbientChannelState *pState);
    void FadeAmbientChannel(AmbientChannelState *pState, unsigned int nChan);
    void AdjustEffectVolumes(unsigned int &nOutA, unsigned int &nOutB, float &fInA, float &fInB);
    int ProcessMusic();
    int PauseAllAmbientSounds();
    int ResumeAllAmbientSounds();
    int StopAllSounds();
    int SetStandardSecondaryMusicFileID(unsigned int id);
    int MusicSwitchToPrimary(unsigned int nArg);
    void PSoundReInitTriglets();
    void EnableLevelProcessing(bool bEnable);
    void EnableProcessTriglets(bool bEnable);
    int ProcessTriglets();
    void LinkAmbientEntry(AmbientEntry *pEntry, AmbientEntry *pNext);
    void InsertAEAtHead(AmbientEntry **ppHead, AmbientEntry *pEntry);
    void AddAEToFreeList(AmbientEntry *pEntry);
    unsigned int VerifyAmbientEntryList(AmbientEntry *pHead);
    void SwapLinksAmbientEntry(AmbientEntry *pA, AmbientEntry *pB);
    void DelinkAmbientEntry(AmbientEntry *pEntry);
    int PauseAmbientEntry(AmbientEntry *pEntry, unsigned int nFlag);
    int StopAmbientEntry(AmbientEntry *pEntry, unsigned int nFlag);
    AmbientEntry *FindAmbientEntry(unsigned int nID);
    int StartAESoftwareFadeout(unsigned int nID, unsigned int nArg);
    int StartAESoftwareFadeout(AmbientEntry *pEntry, unsigned int nArg);
    int IsAmbientSoundBySoundRef(unsigned int nSoundRef);
    int TranslateIntoADSR(unsigned int nArg);
    void PSoundLevelClear();
    void PSoundStopDialog();
    void UsageInit();
    void SetProposedReverbParams(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
    void ChangeReverb();
    void SetReverbByPosition(float *pPos);
    void SetMonoOut(bool bMono);
    void SetMainMusicRelVolume(unsigned int nVolume);
    int PlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4);
    int PlaySoundTrigletUbiquitous(unsigned int p0, unsigned int p1, const GameSoundTrigletPawn *pPawn);
    int PlaySoundTriglet(unsigned int p0, unsigned int p1, const GameSoundTrigletPawn *pPawn);
    int PlayMultipleAtOnce(unsigned int nSound);
    int PlaySoundUbiquitous(unsigned int nSound);
    int PlaySoundPMNode(unsigned int p0, unsigned int p1, const PMNode *pNode);
    int StopAllRegularSounds();
    void StopStreamsAndRequestEEControl();
    int PSoundShutdown();
    int GetEEControlStatus();
    int DebugPlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2);
    void DebugClearPlayedInGame();
    void PSoundReInitRegularSounds();
    void SetEEControlOfIOP(unsigned int nMode);
    void Resume();
    void Pause();
    void ResumeAmbientEntry(AmbientEntry *pEntry);
    int ResumeAmbientSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nFlags);
    int IsObjectPlayingAmbientByID(unsigned int nID, unsigned int nOriginator, unsigned int nFlags);
    int StopAmbientSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nFlags);
    int StopSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nArg1, unsigned int nFlags);
    int PauseAmbientSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nFlags);
    int AddChanToMultipleResumes(unsigned int nChan);
    int AddChanToMultiplePauses(unsigned int nChan);
    int AddChanToMultipleStops(unsigned int nChan);
    int RestartAndLoadInterfaceTypeBank(unsigned int nArg);
    int RestartAndLoadPrimarySoundBank(unsigned int nArg);
    void ReturnControlOfIOPToMjln();
    int OneFrameHasElapsed_R(float *pElapsed, float fFrame, int &rA, int &rB);
    int LoadPrimarySoundBank(unsigned int nArg);
    int SetLevelParameters(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3);
    void PSoundFlushIOPCommandsWaitFinish();
    void KillByCategories(unsigned int nCategory);
    void PauseByCategories(unsigned int nCategory);
    int DebugStopAllDebugAmbients();
    int DebugStopAmbientSoundsBySoundID(unsigned int nSound);
    int DebugStopAllSoundsBySoundID(unsigned int nArg);
    void SendStops();
    void SoundEditLeave();
    void SoundEditEnter();
    unsigned int FindFadingAmbientChannel();
    void WaitOnVSync();
    int TriggerSystemSound(unsigned int p0, unsigned int p1, PMNode *pNode);
    int EnableTrigletByInstanceID(unsigned int nInstanceID, bool bEnable);
    int StopSoundBySoundRef(unsigned int nSoundRef);
    void StopOneShot(unsigned int nIndex);
    void SetMusicPitchBend(bool bBend);
    void PSoundReInitMusic();
    void StopMusic();
    int UsageFindNextHigherID(PSoundUsage **ppUsage);
    int *UsageFind(unsigned int nID);
    int UsageAdd(unsigned int nID);
    void Test1();
    void Test2();
    void DebugRestartValues();
    int DebugFindLastID(unsigned int *pValue, unsigned int *pIndex);
    int DebugFindFirstID(unsigned int *pValue, unsigned int *pIndex);
    int DebugFindPrevID(unsigned int *pValue, unsigned int *pIndex, unsigned int nBound);
    int DebugFindNextID(unsigned int *pValue, unsigned int *pIndex, unsigned int nBound);
    unsigned int DebugChangeParam(unsigned int nValue, int nStep, unsigned int nRate, unsigned int nLo, unsigned int nHi, bool bWrap);
    int WriteLineToPCFile(int nFd, char *pLine);

    int m_unk00;            // 0x000, GetEEControlStatus tests it
    char _pad004[0x008 - 0x004];
    int m_unk08;            // 0x008, PSoundReInitRegularSounds clears it
    int m_unk0C;            // 0x00C, PSoundReInitRegularSounds clears it
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
    int m_unk44;           // 0x044, SetPositionalFactorRelVol sets it to 10x its arg
    int m_unk48;            // 0x048, SetUbiquitousFactorRelVol sets it to 10x its arg
    int m_unk4C;           // 0x04C, SetMasterRelVolume arg 3
    int m_unk50;            // 0x050, SetEffectsRelVolume arg 3
    char _pad054[0x058 - 0x054];
    float m_unk58;         // 0x058, SetPositionalRangeOneshot sets it
    float m_unk5C;          // 0x05C, SetPositionalRangeAmbient sets it
    float m_unk60;         // 0x060, SetDistLinearPercent sets it
    float m_unk64;         // 0x064, SetDistLinearPercent sets it to 1 - m_unk60
    int m_unk68;            // 0x068, PSoundReInitSub clears it
    int m_unk6C;            // 0x06C, PSoundReInitSub clears it
    unsigned int m_unk70[2][8]; // 0x070, music stream state table, 0x20 bytes per stream; word 0 is the music id
    int m_unkB0;            // 0x0B0, SendStops clears it
    int m_unkB4;            // 0x0B4, SendStops clears it
    unsigned int m_unkB8[2];// 0x0B8, AddChanToMultiplePauses bit masks (index 1 for channels 0x18 and up)
    unsigned int m_unkC0[2];// 0x0C0, AddChanToMultipleResumes bit masks (index 1 for channels 0x18 and up)
    int m_unkC8;           // 0x0C8, SoundEditEnter sets 1, SoundEditLeave clears it
    char m_unkCC;           // 0x0CC, PSound constructor stores 1
    unsigned char m_unkCD;  // 0x0CD, PSoundReInitMusic clears it
    char m_unkCE;           // 0x0CE, PSoundReInitMusic clears it
    char m_unkCF;           // 0x0CF, PSoundStopDialog clears it
    bool m_unkD0;           // 0x0D0, ErrorRecovery reads it before PSoundRestart
    char m_unkD1;           // 0x0D1, RestartSuffix sets 1
    char _padD2[0x0D4 - 0x0D2];
    int m_unkD4;            // 0x0D4, RestartSuffix copies gEng+0x19A80 here
    int m_unkD8;            // 0x0D8, RestartSuffix copies gEng+0x137A4 here

    float m_unkDC;          // 0x0DC, PSoundReInitMusic clears it, ProcessMusic counts it down by a frame time
    int m_unkE0;            // 0x0E0, PSoundReInitMusic sets 0x3E8
    int m_unkE4;            // 0x0E4, PSoundReInitRegularSounds computes it from 0x2E2C and 0x2E28
    char _padE8[0x0EC - 0x0E8];
    int m_unk0EC;          // 0x0EC
    int m_unk0F0;           // 0x0F0
    AmbientEntry *m_unkF4;  // 0x0F4, head of the ambient entry list (AddAEToFreeList passes &m_unkF4)
    char m_unkF8[0x2E20 - 0x0F8];   // 0x0F8, AmbientChannelState array of stride 0x20, FindFadingAmbientChannel scans it
    unsigned int m_unk2E20; // 0x2E20, PSoundInit passes it to SOUND_SetChanUse
    int m_unk2E24;          // 0x2E24, PSound constructor stores 5
    unsigned int m_unk2E28; // 0x2E28, FindFadingAmbientChannel start index
    unsigned int m_unk2E2C; // 0x2E2C, FindFadingAmbientChannel limit
    unsigned int m_unk2E30; // 0x2E30, StopSoundBySoundRef loop start index
    unsigned int m_unk2E34; // 0x2E34, StopSoundBySoundRef loop limit (inclusive)
    unsigned int m_unk2E38; // 0x2E38, PSoundInit passes it to SOUND_SetChanUse
    int m_unk2E3C;          // 0x2E3C, PSound constructor stores 0x2F
    int m_unk2E40;          // 0x2E40, PSoundReInitRegularSounds clears it
    char _pad2E44[0x2E48 - 0x2E44];
    int m_unk2E48;          // 0x2E48, SoundEditLeave copies 0x2E4C here
    int m_unk2E4C;          // 0x2E4C, SoundEditLeave/Enter category mask
    int m_unk2E50[4];       // 0x2E50, PSoundStopDialog zeroes 0x2E50..0x2E5C
    int m_unk2E60;          // 0x2E60, StartAndHoldDialog stores its value
    int m_unk2E64;          // 0x2E64, CutSceneLeave compares its argument with this
    unsigned int m_unk2E68; // 0x2E68, CutSceneLeave plays this track
    int m_unk2E6C;          // 0x2E6C, CutSceneLeave compares m_unk2E68 with this
    unsigned int m_unk2E70; // 0x2E70, CutSceneLeave flag bits 0x80000000/0x40000000/0xC0000000
    int m_unk2E74;          // 0x2E74, GetEEControlStatus stores its result
    char _pad2E78[0x2E7C - 0x2E78];
    int m_unk2E7C;          // 0x2E7C, RestartSuffix clears it
    int m_unk2E80;          // 0x2E80, PSound constructor stores 0x100
    char _pad2E84[0x2E90 - 0x2E84];
    char m_unk2E90[0x10];   // 0x2E90, OneFrameHasElapsed_R stores 16 bytes here
    float m_unk2EA0;       // 0x2EA0, RestartAndLoadPrimarySoundBank passes its address to OneFrameHasElapsed_R
    char _pad2EA4[0x2EB0 - 0x2EA4];
    float m_unk2EB0;        // 0x2EB0, RestartAndLoadPrimarySoundBank passes it as the float argument
    char m_unk2EB4[0x2580]; // 0x2EB4, 400 SpotInfo records of 0x18 bytes, GetSpotInfo scans them
    char m_unk5434;         // 0x5434, RestartSuffix clears it
    char _pad5435[0x5438 - 0x5435];
    unsigned int m_unk5438; // 0x5438, SetProposedReverbParams arg 0
    int m_unk543C;          // 0x543C, SetMusicPitchBend bit 0
    int m_unk5440;          // 0x5440, PSoundRestart copies 0x543C here
    int m_unk5444;          // 0x5444, PSoundReInitSoundRooms sets -1
    char _pad5448[0x544C - 0x5448];
    int m_unk544C;          // 0x544C, PSoundReInitSoundRooms clears it
    unsigned int m_unk5450; // 0x5450, RegisterSoundEntityAmounts sets it
    char _pad5454[0x5460 - 0x5454];
    char m_unk5460[0x2580]; // 0x5460, PSoundReInitSoundRooms clears it
    int m_unk79E0[6];       // 0x79E0
    char *m_unk79F8;        // 0x79F8, triglet table base (0x150-byte records)
    char _pad79FC[0x18080 - 0x79FC];
    int m_unk18080;         // 0x18080, SetReverbByPosition writes 0x62 or 0xE9
    int m_unk18084;         // 0x18084, SetReverbByPosition writes 1
    char _pad18088[0x1808C - 0x18088];
    char m_unk1808C;        // 0x1808C, AddChanToMultiplePauses/Stops write here at this + 0x1808C + channel
};

#endif
