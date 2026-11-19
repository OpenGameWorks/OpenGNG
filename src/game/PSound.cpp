// FLAGS: -Cpp_exceptions off
#include "PSound.h"

// TODO(header): foreign declarations
extern "C" void SOUND_StopAllSounds();
extern "C" void SOUND_SetGlobalRelVols(int, int, int, int, int, int, int, int);
extern int fst_ReverbRecProposed[5];
extern int gPSndDbg[52];
extern "C" void SOUND_StopAllRegularSounds();
extern "C" void SOUND_StopAllStreams();
extern signed char fst_bCalledByDebug;

// FUNCTION: 0x001A3E60 LinkAmbientEntry__6PSoundFPQ26PSound12AmbientEntryPQ26PSound12AmbientEntry
void PSound::LinkAmbientEntry(AmbientEntry *pEntry, AmbientEntry *pNext) {
    AmbientEntry *pTemp;

    if (pNext != 0 && pEntry != 0) {
        pTemp = pEntry->m_unk50;
        pNext->m_unk54 = pEntry;
        pNext->m_unk50 = pTemp;
        pEntry->m_unk50 = pNext;
        if (pTemp != 0) {
            pTemp->m_unk54 = pNext;
        }
    }
}

// FUNCTION: 0x001A5780 SetProposedReverbParams__6PSoundFUiUiUiUiUi
void PSound::SetProposedReverbParams(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4) {
    fst_ReverbRecProposed[1] = p1;
    fst_ReverbRecProposed[2] = p2;
    fst_ReverbRecProposed[3] = p3;
    fst_ReverbRecProposed[4] = p4;
    fst_ReverbRecProposed[0] = p0;
    m_unk5438 = p0;
}

// FUNCTION: 0x001A5BF0 AmbientFadeToFree__6PSoundFPQ26PSound19AmbientChannelState
void PSound::AmbientFadeToFree(AmbientChannelState *pState) {
    m_unk0EC -= 1;
    m_unk0F0 += 1;
    return pState->ReInit();
}

// FUNCTION: 0x001A71D0 PlaySoundTrigletUbiquitous__6PSoundFUiUiPC20GameSoundTrigletPawn
int PSound::PlaySoundTrigletUbiquitous(unsigned int p0, unsigned int p1, const GameSoundTrigletPawn *pPawn) {
    if (pPawn != 0) {
        return PlaySoundWPitch(p0, p1, (unsigned int)pPawn, 0x240, 0);
    }
    return 0;
}

// FUNCTION: 0x001A7290 PlaySoundPMNode__6PSoundFUiUiPC6PMNode
int PSound::PlaySoundPMNode(unsigned int p0, unsigned int p1, const PMNode *pNode) {
    if (pNode != 0) {
        return PlaySoundWPitch(p0, p1, (unsigned int)pNode, 0x20, 0);
    }
    return 0;
}

// FUNCTION: 0x001A8040 StopAllSounds__6PSoundFv
int PSound::StopAllSounds() {
    SOUND_StopAllSounds();
    return 0;
}

// FUNCTION: 0x001A8060 StopAllRegularSounds__6PSoundFv
int PSound::StopAllRegularSounds() {
    SOUND_StopAllRegularSounds();
    PSoundReInitRegularSounds();
    return 0;
}

// DRAFT: 0x001A91A0 SetMonoOut__6PSoundFb
// note: 3 words differ; original keeps the bool in v1 and loads the field into a1 (MWCC swaps them); swapped compare operands cut 4 to 3; direct bool compare, cached load and ternary bool-to-int did not reduce it (ternary gave exit 2)
void PSound::SetMonoOut(bool bMono) {
    int nMono = bMono;

    if (nMono != m_unk30) {
        m_unk30 = nMono;
        InternalUpdateRelVolumes();
    }
}

// FUNCTION: 0x001A9400 InternalUpdateRelVolumes__6PSoundFv
void PSound::InternalUpdateRelVolumes() {
    SOUND_SetGlobalRelVols(m_unk34, m_unk38, m_unk3C, m_unk40, 1000, 1000, 1000, m_unk30);
}

// FUNCTION: 0x001A9440 SetMainMusicRelVolume__6PSoundFUi
void PSound::SetMainMusicRelVolume(unsigned int nVolume) {
    unsigned int nClamped = nVolume;

    if (nClamped > 0x64) {
        nClamped = 0x64;
    }
    gPSndDbg[5] = nClamped;
    m_unk3C = nClamped * 10;
    InternalUpdateRelVolumes();
}

// FUNCTION: 0x001A94E0 SetStandardSecondaryMusicFileID__6PSoundFUi
int PSound::SetStandardSecondaryMusicFileID(unsigned int id) {
    m_unk024 = id;
    return (m_unk024 >= 0x21) ? -1 : 0;
}

// FUNCTION: 0x001A9B60 StopStreamsAndRequestEEControl__6PSoundFv
void PSound::StopStreamsAndRequestEEControl() {
    SOUND_StopAllStreams();
    SetEEControlOfIOP(2);
}

// FUNCTION: 0x001AA0D0 PSoundReInitTriglets__6PSoundFv
void PSound::PSoundReInitTriglets() {
    m_unk79E0[0] = 0;
    m_unk79E0[1] = 0;
    m_unk79E0[2] = 0;
    m_unk79E0[3] = 0;
    m_unk79E0[4] = 0;
    m_unk79E0[5] = 0;
    EnableLevelProcessing(false);
}

// FUNCTION: 0x001AA750 __ct__Q26PSound16MusicStreamStateFv
PSound::MusicStreamState::MusicStreamState() {
    Init();
}

// FUNCTION: 0x001AA7C0 Init__Q26PSound19AmbientChannelStateFv
void PSound::AmbientChannelState::Init() {
    m_unk00 = 0x3FFF;
    m_unk04 = 0;
    m_unk0C = 0;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk08 = 0;
    m_unk1C = 0;
}

// FUNCTION: 0x001AA7F0 __ct__Q26PSound19AmbientChannelStateFv
PSound::AmbientChannelState::AmbientChannelState() {
    Init();
}

// FUNCTION: 0x001AAC50 Init__Q26PSound19OneShotChannelStateFv
void PSound::OneShotChannelState::Init() {
    m_unk10 = 0x3FFF;
    m_unk14 = 0;
    m_unk16 = 0;
    m_unk18 = 0;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk24 = 0;
    m_unk28 = 0;
    m_unk2C = 0;
}

// FUNCTION: 0x001AAC80 __ct__Q26PSound19OneShotChannelStateFv
PSound::OneShotChannelState::OneShotChannelState() {
    Init();
}

// FUNCTION: 0x001AAD70 __ct__Q26PSound8SpotInfoFv
PSound::SpotInfo::SpotInfo() {
    Init();
}

// FUNCTION: 0x001AB400 DebugPlaySoundWPitch__6PSoundFUiUiUi
int PSound::DebugPlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2) {
    int nRet;

    fst_bCalledByDebug = 1;
    nRet = PlaySoundWPitch(p0, p1, 0, 0x810, p2);
    fst_bCalledByDebug = 0;
    return nRet;
}
