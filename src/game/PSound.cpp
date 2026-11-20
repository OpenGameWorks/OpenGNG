// FLAGS: -Cpp_exceptions off -str readonly
#include "PSound.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" void SOUND_StopAllSounds();
extern "C" void SOUND_SetGlobalRelVols(int, int, int, int, int, int, int, int);
extern int fst_ReverbRecProposed[5];
extern int gPSndDbg[52];
extern "C" int sceWrite(int, char *, int);
extern "C" int strlen(char *);
extern int miRandom__7MathAPI;
extern "C" void SOUND_StopAllRegularSounds();
extern "C" void SOUND_StopAllMusic();
extern "C" void SOUND_StopAllStreams();
extern signed char fst_bCalledByDebug;
extern "C" void FlushIOPCommand(int, int, int);
extern "C" void SOUND_CopyIOPBuffer();
extern char gEng[105360];
extern "C" void __ct__14PFadeMsecFloatFv(void *);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void SOUND_StopMultipleSounds(int nHandle, int nCount);
extern "C" void __dl__FPv(void *pMem);
extern "C" int SOUND_StopStream(unsigned int);
extern "C" void SOUND_CloseStreamBuffer(int);
extern "C" void sceGsSyncV(int);
extern int fst_ADSR_Translate_Attack[16];
extern int fst_ADSR_Translate_Release[16];
extern char fst_Usage[24000];
extern int fst_dialogSpecialVol;
extern int gSOUND_EEControl;
extern int gSOUND_EEControlReqCallCnt;
extern int gSOUND_uEECallCntReturned;
extern "C" void FlushCache(int nMode);
extern int gCDSVBlankCount;
extern int fst_lastVSyncWaitCount;
extern "C" void SOUND_SetOverallMusicPitch(int, int);
extern unsigned char SOUND_SPUKeyStatus[0x40];
extern "C" int SOUND_MakeSoundStreamRef();
extern "C" unsigned int SOUND_PlayDialogRelVol(unsigned int, unsigned int, unsigned int, short, unsigned int);
extern "C" void SOUND_FadeMusicStream(unsigned int, unsigned int, int, unsigned int);
class PTranslateATable {
public:
    static int FindASubTableRandomItem(unsigned int *pOut, unsigned int nIdx, int (*pfnBank)(unsigned int), const unsigned int *pTable);
};
int SoundInBankStatus(unsigned int nBank);
extern unsigned int gSndSetOfIDsTable[16];
extern "C" void SOUND_SetPauseCategories(unsigned int);
extern "C" void SOUND_LevelRestart();
extern "C" void SOUND_SetMasterRegisterVolumeAbs(int);
extern "C" void SOUND_EnableFeatures(int, int);

// FUNCTION: 0x001A3DD0 SwapLinksAmbientEntry__6PSoundFPQ26PSound12AmbientEntryPQ26PSound12AmbientEntry
void PSound::SwapLinksAmbientEntry(AmbientEntry *pA, AmbientEntry *pB) {
    if (pA != 0 && pB != 0) {
        if (pB != pA->m_unk50) {
            CdsAssert("PSound.cpp", 0x253E, "i_pB == i_pA->mpAmbientEntryNext");
        }
        if (pA != pB->m_unk54) {
            CdsAssert("PSound.cpp", 0x253F, "i_pA == i_pB->mpAmbientEntryPrev");
        }
        AmbientEntry *pTmp = pA->m_unk54;
        pA->m_unk50 = pB->m_unk50;
        pB->m_unk54 = pTmp;
        pA->m_unk54 = pB;
        pB->m_unk50 = pA;
    }
}

// FUNCTION: 0x001A3C70 AddAEToFreeList__6PSoundFPQ26PSound12AmbientEntry
void PSound::AddAEToFreeList(AmbientEntry *pEntry) {
    pEntry->Init();
    InsertAEAtHead(&m_unkF4, pEntry);
}

// FUNCTION: 0x001A3D80 InsertAEAtHead__6PSoundFPPQ26PSound12AmbientEntryPQ26PSound12AmbientEntry
void PSound::InsertAEAtHead(AmbientEntry **ppHead, AmbientEntry *pEntry) {
    if (ppHead != 0 && pEntry != 0) {
        AmbientEntry *pTemp = *ppHead;
        pEntry->m_unk50 = pTemp;
        if (pTemp != 0) {
            pTemp->m_unk54 = pEntry;
        }
        *ppHead = pEntry;
        return;
    }
    CdsAssert("PSound.cpp", 0x2562, "0");
}

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

// FUNCTION: 0x001A3E90 DelinkAmbientEntry__6PSoundFPQ26PSound12AmbientEntry
void PSound::DelinkAmbientEntry(AmbientEntry *pEntry) {
    if (pEntry != 0) {
        AmbientEntry *pNext = pEntry->m_unk50;
        AmbientEntry *pPrev = pEntry->m_unk54;
        if (pNext != 0) {
            pNext->m_unk54 = pPrev;
        }
        if (pPrev != 0) {
            pPrev->m_unk50 = pNext;
        }
        if (m_unkF4 == pEntry) {
            m_unkF4 = pNext;
        }
        pEntry->m_unk50 = 0;
        pEntry->m_unk54 = 0;
    }
}

// DRAFT: 0x001A3EE0 FindFadingAmbientChannel__6PSoundFv
// note: 3 words differ; the 0x3FFE constant and loaded element swap a0/a1 at the compare (int*, unsigned int*, for-loop and while-loop variants tried, all DIFF 3 or worse).
unsigned int PSound::FindFadingAmbientChannel() {
    unsigned int idx = m_unk2E28;
    int *p = (int *)m_unkF8;
    while (idx <= m_unk2E2C) {
        if (*p == 0x3FFE) {
            return idx;
        }
        idx++;
        p += 8;
    }
    return -1U;
}

// FUNCTION: 0x001A3F30 FindFreeAmbientChannel__6PSoundFv
unsigned int PSound::FindFreeAmbientChannel() {
    unsigned int nIdx = m_unk2E28;
    AmbientChannelState *p = (AmbientChannelState *)m_unkF8;
    while (nIdx <= m_unk2E2C) {
        if (p->m_unk00 == 0x3FFF && SOUND_SPUKeyStatus[nIdx] == 0) {
            return nIdx;
        }
        nIdx++;
        p = (AmbientChannelState *)((char *)p + 0x20);
    }
    return -1;
}

// FUNCTION: 0x001A41A0 WaitOnVSync__6PSoundFv
void PSound::WaitOnVSync() {
    int nVBlank = gCDSVBlankCount;
    int nSpins = 0;
    while (nVBlank == gCDSVBlankCount) {
        nSpins++;
        FlushCache(0);
        asm {
            sync
            sync.p
        }
    }
    fst_lastVSyncWaitCount = nSpins;
}

// FUNCTION: 0x001A4340 SetMainMusicSpecialVolume__6PSoundFQ26PSound20EnumMusicSpecialVols
void PSound::SetMainMusicSpecialVolume(EnumMusicSpecialVols eVol) {
    int nVol = 0x3E8;
    if ((int)eVol == 0) {
        m_unk40 = nVol;
    } else {
        if ((int)eVol == 1) {
            nVol = 0x1F4;
        } else if ((int)eVol == 2) {
            nVol = fst_dialogSpecialVol;
        } else if ((int)eVol == 3) {
            nVol = 0x64;
        }
        m_unk40 = nVol;
    }
    InternalUpdateRelVolumes();
}

// FUNCTION: 0x001A4390 AbilityScreenLeave__6PSoundFv
void PSound::AbilityScreenLeave() {
    KillByCategories(0x200);
    PauseByCategories(0);
    SetMainMusicSpecialVolume(MUSIC_SPECIAL_VOLS_NONE);
}

// FUNCTION: 0x001A43D0 AbilityScreenEnter__6PSoundFv
void PSound::AbilityScreenEnter() {
    KillByCategories(0x200);
    PauseByCategories(0x8C);
    SetMainMusicSpecialVolume((EnumMusicSpecialVols)1);
}

// FUNCTION: 0x001A47D0 StartAndHoldDialog__6PSoundFUi
int PSound::StartAndHoldDialog(unsigned int nArg) {
    m_unk2E50[0] = SOUND_MakeSoundStreamRef();
    m_unk2E50[2] = nArg;
    SOUND_PlayDialogRelVol(0, nArg, m_unk2E50[0], 0x3E8, 6);
    m_unk2E60 = *(int *)(gEng + 0x137A4);
    return 0;
}

// FUNCTION: 0x001A4830 PrepDialog__6PSoundFUi
int PSound::PrepDialog(unsigned int nArg) {
    if (nArg < 0xC8 || nArg >= 0xE4) {
        return -1;
    }
    if (nArg == (unsigned int)m_unk2E50[2]) {
        return 0;
    }
    if (GetDialogPlayingStatus() > 0) {
        m_unk2E50[3] = nArg;
        return 1;
    }
    StartAndHoldDialog(nArg);
    return 0;
}

// FUNCTION: 0x001A48D0 SendStops__6PSoundFv
void PSound::SendStops() {
    if (m_unkB0 != 0 || m_unkB4 != 0) {
        SOUND_StopMultipleSounds(m_unkB0, m_unkB4);
        m_unkB0 = 0;
        m_unkB4 = 0;
    }
}

// FUNCTION: 0x001A4940 PauseByCategories__6PSoundFUi
void PSound::PauseByCategories(unsigned int nCategory) {
    unsigned int nOld = m_unk2E48;
    unsigned int nAdded = nCategory & ~nOld;
    if (nOld & ~nCategory & 0x80) {
        ResumeAllAmbientSounds();
    }
    if (nAdded & 0x80) {
        PauseAllAmbientSounds();
    }
    m_unk2E48 = nCategory;
    SOUND_SetPauseCategories(nCategory);
}

// FUNCTION: 0x001A5590 SetMusicPitchBend__6PSoundFb
void PSound::SetMusicPitchBend(bool bBend) {
    if (bBend) {
        if (gPSndDbg[10] != 0) {
            m_unk543C |= 1;
        }
    } else {
        m_unk543C &= ~1;
        SOUND_SetOverallMusicPitch(0x2710, 0);
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

// FUNCTION: 0x001A5920 ErrorRecovery__6PSoundFv
void PSound::ErrorRecovery() {
    bool bSaved = m_unkD0;

    PSoundRestart();
    EnableProcessTriglets(bSaved);
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

// FUNCTION: 0x001A8450 StopSoundBySoundRefIfAmbient__6PSoundFUi
int PSound::StopSoundBySoundRefIfAmbient(unsigned int nSoundRef) {
    if (nSoundRef != 0) {
        AmbientEntry *p = (AmbientEntry *)((char *)this + 0x380);
        AmbientEntry *end = (AmbientEntry *)((char *)this + 0x2220);
        while (p < end) {
            if (nSoundRef == p->m_unk44) {
                StartAESoftwareFadeout(p, 0);
                return 1;
            }
            p = (AmbientEntry *)((char *)p + 0x70);
        }
    }
    return 0;
}

// FUNCTION: 0x001A8620 ResumeAmbientEntry__6PSoundFPQ26PSound12AmbientEntry
void PSound::ResumeAmbientEntry(AmbientEntry *pEntry) {
    if (pEntry != 0 && pEntry->m_unk10 < 0x3FFD) {
        unsigned short nFlags = pEntry->m_unk16;
        if (nFlags & 1) {
            pEntry->m_unk16 = nFlags & 0xFFFE;
        }
    }
}

// DRAFT: 0x001A8660 PauseAmbientEntry__6PSoundFPQ26PSound12AmbientEntryUi
// note: 2 words differ: original keeps the flag compare in at (sltiu at / bnez at, store after inline return 0), ours compares into v0; tried if/else, result variable, nested return, inverted and local-load forms
int PSound::PauseAmbientEntry(AmbientEntry *pEntry, unsigned int nFlag) {
    if (pEntry == 0) {
        return 0;
    }
    if (!(pEntry->m_unk10 < 0x3FFD)) {
        return 0;
    }
    pEntry->m_unk16 |= 1;
    return 0;
}

// FUNCTION: 0x001A8750 PauseAllAmbientSounds__6PSoundFv
int PSound::PauseAllAmbientSounds() {
    AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
    AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
    if (pEntry < pEnd) {
        do {
            pEntry->m_unk16 |= 2;
            short nIdx = pEntry->m_unk18;
            if (nIdx >= 0 && *((unsigned char *)this + nIdx + 0x1808C) == 0) {
                AddChanToMultiplePauses(nIdx);
            }
            pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
        } while (pEntry < pEnd);
    }
    return 0;
}

// DRAFT: 0x001A87E0 AddChanToMultipleResumes__6PSoundFUi
// note: 17 words differ; pointer register allocation (original keeps &m_unkC0[idx] in a2, ours spills it to t0). Tried indexed form, shift-in-branch, if/else split, 1u literal, m_unkC0 + nIdx pointer (all 17 or worse).
int PSound::AddChanToMultipleResumes(unsigned int nChan) {
    int nRet = 0;
    unsigned int nIdx = 0;
    unsigned int nShift = nChan;
    if (nChan >= 0x18) {
        nShift -= 0x18;
        nIdx = 1;
    }
    unsigned int nBit = 1u << nShift;
    unsigned int *pWord = &m_unkC0[nIdx];
    if (*pWord & nBit) {
        nRet = -1;
    }
    *pWord |= nBit;
    *((char *)this + 0x1808C + nChan) = 0;
    return nRet;
}

// DRAFT: 0x001A8850 AddChanToMultiplePauses__6PSoundFUi
// note: 16 words differ; index*4 scaled before the shift, base 0xB8 added to a register, and the flag store uses a2 for the constant (original uses a0). Tried indexed, pointer, shift-in-var, signed index, flag-base pointer, base-cast pointer (16, 16, 16, 16, 18, 16).
int PSound::AddChanToMultiplePauses(unsigned int nChan) {
    int nRet = 0;
    int nIdx = 0;
    unsigned int nShift = nChan;
    if (nChan >= 0x18) {
        nShift -= 0x18;
        nIdx = 1;
    }
    unsigned int nBit = 1u << nShift;
    unsigned int *pWord = (unsigned int *)((char *)this + 0xB8) + nIdx;
    if (*pWord & nBit) {
        nRet = -1;
    }
    *pWord |= nBit;
    *((char *)this + 0x1808C + nChan) = 1;
    return nRet;
}

// DRAFT: 0x001A88C0 AddChanToMultipleStops__6PSoundFUi
// note: 17 words differ; same shape as AddChanToMultiplePauses with base 0xB0 and a 0 flag store; see the Pauses note for the register and order differences.
int PSound::AddChanToMultipleStops(unsigned int nChan) {
    int nRet = 0;
    unsigned int nIdx = 0;
    unsigned int nShift = nChan;
    if (nChan >= 0x18) {
        nShift -= 0x18;
        nIdx = 1;
    }
    unsigned int nBit = 1u << nShift;
    unsigned int *pWord = (unsigned int *)((char *)this + 0xB0) + nIdx;
    if (*pWord & nBit) {
        nRet = -1;
    }
    *pWord |= nBit;
    *((char *)this + 0x1808C + nChan) = 0;
    return nRet;
}

// DRAFT: 0x001A89E0 FindAmbientEntry__6PSoundFUi
// note: DIFF 7 words; original has one extra join nop at 0x3C (fn 0x4C bytes, ours 0x48)
PSound::AmbientEntry *PSound::FindAmbientEntry(unsigned int nID) {
    AmbientEntry *pEntry = (AmbientEntry *)(m_unkF8 + (0x380 - 0xF8));
    AmbientEntry *pEnd = (AmbientEntry *)(m_unkF8 + (0x2220 - 0xF8));
    if (nID != 0) {
        if (pEntry < pEnd) {
            do {
                if (nID == pEntry->m_unk44) {
                    return pEntry;
                }
                pEntry++;
            } while (pEntry < pEnd);
        }
    }
    return 0;
}

// DRAFT: 0x001A8A30 IsAmbientSoundBySoundRef__6PSoundFUi
// note: DIFF 9 words; original has join nop at 0x6C before the return-0 daddu (fn 0x4C bytes, ours 0x48)
int PSound::IsAmbientSoundBySoundRef(unsigned int nSoundRef) {
    AmbientEntry *pEntry = (AmbientEntry *)(m_unkF8 + (0x380 - 0xF8));
    AmbientEntry *pEnd = (AmbientEntry *)(m_unkF8 + (0x2220 - 0xF8));
    if (nSoundRef != 0) {
        if (pEntry < pEnd) {
            do {
                if (nSoundRef == pEntry->m_unk44) {
                    return 1;
                }
                pEntry++;
            } while (pEntry < pEnd);
        }
    }
    return 0;
}

// FUNCTION: 0x001A8A80 IsAmbientSoundByID__6PSoundFUi
int PSound::IsAmbientSoundByID(unsigned int nID) {
    SpotInfo *pInfo = GetSpotInfoPtrByPublicID(nID);

    if (pInfo == 0) {
        return -1;
    }
    return (pInfo->m_unk0C & 2) != 0;
}

// FUNCTION: 0x001A8AC0 GetSpotInfoPtrByPublicID__6PSoundFUi
PSound::SpotInfo *PSound::GetSpotInfoPtrByPublicID(unsigned int nID) {
    unsigned int nOut;
    unsigned int nIdx = nID;

    if (nID >= 0x4E20) {
        if (nID < 0x4E74) {
            if (PTranslateATable::FindASubTableRandomItem(&nOut, nID, SoundInBankStatus, gSndSetOfIDsTable) == 0) {
                nIdx = nOut;
            } else {
                return 0;
            }
        }
    }
    return GetSpotInfo(nIdx);
}

// FUNCTION: 0x001A8B30 StartAESoftwareFadeout__6PSoundFUiUi
int PSound::StartAESoftwareFadeout(unsigned int nID, unsigned int nArg) {
    AmbientEntry *pEntry = FindAmbientEntry(nID);

    if (pEntry != 0) {
        return StartAESoftwareFadeout(pEntry, nArg);
    }
    return 1;
}

// DRAFT: 0x001A8FA0 GetSpotInfo__6PSoundFUi
// note: 13 words differ; original keeps the scan pointer in a0 (in-place addiu from this) and the end in a2, ours puts the pointer in v0 and the end in a0; byte cursor, SpotInfo cursor, for, do-while and while forms tried, best 13
PSound::SpotInfo *PSound::GetSpotInfo(unsigned int nID) {
    char *pCur = m_unk2EB4;
    char *pEnd = pCur + 0x2580;
    if (pCur < pEnd) {
        do {
            if (((SpotInfo *)pCur)->m_unk00 == (int)nID) {
                return (SpotInfo *)pCur;
            }
            pCur += 0x18;
        } while (pCur < pEnd);
    }
    return 0;
}

// FUNCTION: 0x001A9080 Resume__6PSoundFv
void PSound::Resume() {
    KillByCategories(0x200);
    PauseByCategories(0);
}

// FUNCTION: 0x001A90C0 Pause__6PSoundFv
void PSound::Pause() {
    KillByCategories(0x200);
    PauseByCategories(0x82);
}

// FUNCTION: 0x001A9100 SoundEditLeave__6PSoundFv
void PSound::SoundEditLeave() {
    DebugStopAllDebugAmbients();
    KillByCategories(0x200);
    m_unk2E48 = m_unk2E4C;
    PauseByCategories(m_unk2E4C);
    m_unkC8 = 0;
}

// FUNCTION: 0x001A9150 SoundEditEnter__6PSoundFv
void PSound::SoundEditEnter() {
    m_unkC8 = 1;
    m_unk2E4C = m_unk2E48;
    KillByCategories(0x200);
    PauseByCategories(0x9E);
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

// FUNCTION: 0x001A91D0 SetPositionalRangeAmbient__6PSoundFUi
void PSound::SetPositionalRangeAmbient(unsigned int nRange) {
    float fRange;

    int nSigned = nRange;

    gPSndDbg[19] = nRange;
    if (nSigned >= 0) {
        fRange = (float)nSigned;
    } else {
        int nHalf = nRange >> 1;
        nHalf |= nRange & 1;
        fRange = (float)nHalf;
        fRange = fRange + fRange;
    }
    m_unk5C = fRange;
}

// FUNCTION: 0x001A9210 SetPositionalRangeOneshot__6PSoundFUi
void PSound::SetPositionalRangeOneshot(unsigned int nRange) {
    float fRange;
    int nSigned = nRange;

    gPSndDbg[18] = nRange;
    if (nSigned >= 0) {
        fRange = (float)nSigned;
    } else {
        int nHalf = nRange >> 1;
        nHalf |= nRange & 1;
        fRange = (float)nHalf;
        fRange = fRange + fRange;
    }
    m_unk58 = fRange;
}

// FUNCTION: 0x001A9340 SetMasterRelVolume__6PSoundFUi
void PSound::SetMasterRelVolume(unsigned int nVolume) {
    unsigned int nClamped = nVolume;

    if (nClamped > 0x64) {
        nClamped = 0x64;
    }
    gPSndDbg[4] = nClamped;
    m_unk34 = nClamped * 10;
    m_unk4C = (nClamped * 0x3FFF * 10) / 1000;
    InternalUpdateRelVolumes();
}

// FUNCTION: 0x001A93A0 SetEffectsRelVolume__6PSoundFUi
void PSound::SetEffectsRelVolume(unsigned int nVolume) {
    unsigned int nClamped = nVolume;

    if (nClamped > 0x64) {
        nClamped = 0x64;
    }
    gPSndDbg[6] = nClamped;
    m_unk38 = nClamped * 10;
    m_unk50 = (nClamped * 0x3FFF * 10) / 1000;
    InternalUpdateRelVolumes();
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

// DRAFT: 0x001A9470 StopMusic__6PSoundFv
// note: size 0x60 vs 0x64; the second loop increment lands in the bnez delay slot, original keeps slti/bnez/nop. Tried for-loop, offset-bounded while, and reordered increments; none closed the gap.
void PSound::StopMusic() {
    SOUND_StopAllMusic();
    int i = 0;
    int off = 0;
    do {
        ((MusicStreamState *)((char *)this + off + 0x70))->ReInit();
        i++;
        off += 0x20;
    } while (i < 2);
    m_unkCE = 1;
}

// FUNCTION: 0x001A94E0 SetStandardSecondaryMusicFileID__6PSoundFUi
int PSound::SetStandardSecondaryMusicFileID(unsigned int id) {
    m_unk024 = id;
    return (m_unk024 >= 0x21) ? -1 : 0;
}

// DRAFT: 0x001A9500 MusicSwitchToPrimary__6PSoundFUi
// note: 24 words differ; original builds table as addiu v0,s1,0x70 + addu, compiler folds 0x70 into lw offset; first beqz also one insn shorter. Tried m_unk70[idx][0], char* table+idx<<5, pSlot struct, pBase+=0x70, int nRet=-1 (all 24)
int PSound::MusicSwitchToPrimary(unsigned int nArg) {
    if (m_unk1C < 0x21) {
        unsigned int idx = m_unk28;
        if (idx < 2) {
            if (m_unk1C != m_unk70[idx][0]) {
                PlayMusicOnStream(idx, m_unk1C, 1);
            }
            FadeMusicOnStream(m_unk28, nArg, 100);
            m_unkCD = 0;
            return 0;
        }
    }
    return -1;
}

// DRAFT: 0x001A95A0 FadeMusicOnStream__6PSoundFUiUiUi
// note: 14 words differ: original clamp path re-shifts a3 (folded to 0x190 here); compare uses at not v0; sw before bnez. Tried n*10, t=n<<2 clamp, param clamp, store via int*.
void PSound::FadeMusicOnStream(unsigned int nStream, unsigned int nArg, unsigned int nFrames) {
    if (nStream < 2) {
        unsigned int n = nFrames;
        if (n >= 0x65) {
            n = 0x64;
        }
        int ticks = n * 10;
        SOUND_FadeMusicStream(nStream, nArg, ticks, n);
        char *pState = (char *)this + (nStream << 5);
        int *pTicks = (int *)(pState + 0x7C);
        *pTicks = ticks;
        if (ticks == 0) {
            ((MusicStreamState *)(pState + 0x70))->ReInit();
        }
    }
}

// FUNCTION: 0x001A9800 PlayMusic__6PSoundFUi
int PSound::PlayMusic(unsigned int nTrack) {
    if (nTrack < 0x21) {
        m_unk1C = nTrack;
        return (unsigned char)PlayMusicOnStream(m_unk28, nTrack, 100);
    }
    return 0;
}

// FUNCTION: 0x001A9840 PSoundFlushIOPCommandsWaitFinish__6PSoundFv
void PSound::PSoundFlushIOPCommandsWaitFinish() {
    FlushIOPCommand(0, *(int *)(gEng + 0x19A80), *(int *)(gEng + 0x137A4));
    SOUND_CopyIOPBuffer();
}

// FUNCTION: 0x001A9B10 GetEEControlStatus__6PSoundFv
int PSound::GetEEControlStatus() {
    int nStatus = 3;

    if (m_unk00 == 0) {
        m_unk2E74 = nStatus;
    } else if (gSOUND_uEECallCntReturned == 0) {
        m_unk2E74 = 0;
    } else if ((unsigned int)gSOUND_uEECallCntReturned >= (unsigned int)gSOUND_EEControlReqCallCnt) {
        m_unk2E74 = gSOUND_EEControl;
    } else {
        m_unk2E74 = 1;
    }
    return m_unk2E74;
}

// FUNCTION: 0x001A9B60 StopStreamsAndRequestEEControl__6PSoundFv
void PSound::StopStreamsAndRequestEEControl() {
    SOUND_StopAllStreams();
    SetEEControlOfIOP(2);
}

// FUNCTION: 0x001A9C40 PSoundShutdown__6PSoundFv
int PSound::PSoundShutdown() {
    SOUND_StopStream(0);
    SOUND_CloseStreamBuffer(0);
    SOUND_StopStream(1);
    SOUND_CloseStreamBuffer(1);
    SOUND_StopStream(2);
    SOUND_CloseStreamBuffer(2);
    SOUND_StopAllSounds();
    PSoundReInitSub(0);
    PSoundFlushIOPCommandsWaitFinish();
    m_unkD1 = 0;
    sceGsSyncV(0);
    sceGsSyncV(0);
    return 1;
}

// FUNCTION: 0x001A9CD0 RestartAndLoadInterfaceTypeBank__6PSoundFUi
int PSound::RestartAndLoadInterfaceTypeBank(unsigned int nArg) {
    int nRet = 0;
    if (RestartAndLoadPrimarySoundBank(nArg) != 0) {
        nRet = -1;
    }
    if (SetLevelParameters(0, 0x384, 0x384, 0x64) != 0) {
        nRet = -1;
    }
    return nRet;
}

// FUNCTION: 0x001A9D30 RestartAndLoadPrimarySoundBank__6PSoundFUi
int PSound::RestartAndLoadPrimarySoundBank(unsigned int nArg) {
    int nFlagA;
    int nFlagB;
    ReturnControlOfIOPToMjln();
    WaitOnVSync();
    OneFrameHasElapsed_R(&m_unk2EA0, m_unk2EB0, nFlagA, nFlagB);
    PSoundRestart();
    WaitOnVSync();
    OneFrameHasElapsed_R(&m_unk2EA0, m_unk2EB0, nFlagA, nFlagB);
    LoadPrimarySoundBank(nArg);
    return 0;
}

// FUNCTION: 0x001A9DC0 TranslateIntoADSR__6PSoundFUi
int PSound::TranslateIntoADSR(unsigned int nArg) {
    return fst_ADSR_Translate_Attack[(nArg >> 4) & 0xF] + 0xFF1FC0 + fst_ADSR_Translate_Release[nArg & 0xF];
}

// DRAFT: 0x001A9E10 RestartSuffix__6PSoundFv
// note: 2 words differ: the constant 1 goes to a0 instead of v0 (addiu at 0x38, sb at 0x4C); tried char/bool/uchar member, `= true`, moving the m_unk00 store, `return m_unkD1 = 1` (DIFF 10)
int PSound::RestartSuffix() {
    PSoundFlushIOPCommandsWaitFinish();
    WaitOnVSync();
    PSoundReInitSubWSoundCalls();
    WaitOnVSync();
    PSoundFlushIOPCommandsWaitFinish();
    m_unk5434 = 0;
    m_unk5438 = 0;
    m_unk2E7C = 0;
    m_unkD1 = 1;
    m_unkD4 = *(int *)(gEng + 0x19A80);
    m_unkD8 = *(int *)(gEng + 0x137A4);
    m_unk00 = 2;
}

// FUNCTION: 0x001A9E90 PSoundRestart__6PSoundFv
unsigned char PSound::PSoundRestart() {
    SOUND_LevelRestart();
    m_unk543C = 0;
    m_unk5440 = m_unk543C;
    SOUND_SetMasterRegisterVolumeAbs(0x3FFF);
    SOUND_SetGlobalRelVols(m_unk34, m_unk38, m_unk3C, m_unk40, 1000, 1000, 1000, m_unk30);
    SOUND_EnableFeatures(m_unk543C, -1);
    return RestartSuffix();
}

// FUNCTION: 0x001AA030 PSoundReInitSubWSoundCalls__6PSoundFv
void PSound::PSoundReInitSubWSoundCalls() {
    PSoundReInitSub(0);
    InternalUpdateRelVolumes();
    PSoundFlushIOPCommandsWaitFinish();
}

// FUNCTION: 0x001AA080 PSoundLevelClear__6PSoundFv
void PSound::PSoundLevelClear() {
    SOUND_StopAllRegularSounds();
    PSoundReInitRegularSounds();
    PSoundStopDialog();
    SOUND_StopStream(0);
    PSoundReInitSoundRooms();
    PSoundReInitTriglets();
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

// FUNCTION: 0x001AA0F0 PSoundReInitSoundRooms__6PSoundFv
void PSound::PSoundReInitSoundRooms() {
    memset(m_unk5460, 0, 0x2580);
    m_unk544C = 0;
    m_unk5444 = -1;
}

// FUNCTION: 0x001AA130 PSoundStopDialog__6PSoundFv
void PSound::PSoundStopDialog() {
    SOUND_StopStream(0);
    m_unkCF = 0;
    m_unk2E50[0] = 0;
    m_unk2E50[1] = 0;
    m_unk2E50[2] = 0;
    m_unk2E50[3] = 0;
    m_unk2E48 &= ~0xC;
    m_unk2E4C = m_unk2E48;
}

// FUNCTION: 0x001AA190 PSoundReInitMusic__6PSoundFv
void PSound::PSoundReInitMusic() {
    StopMusic();
    m_unk28 = 1;
    m_unk2C = 0;
    m_unk40 = 0x3E8;
    m_unk1C = 0;
    m_unk20 = 0;
    m_unk024 = 0;
    m_unkCD = 0;
    m_unkDC = 0;
    m_unkE0 = 0x3E8;
    m_unkCE = 0;
}

// FUNCTION: 0x001AA490 __dt__6PSoundFv
PSound::~PSound() {
}

// FUNCTION: 0x001AA750 __ct__Q26PSound16MusicStreamStateFv
PSound::MusicStreamState::MusicStreamState() {
    Init();
}

// FUNCTION: 0x001AA780 ReInit__Q26PSound19AmbientChannelStateFv
void PSound::AmbientChannelState::ReInit() {
    short nSaved = m_unk06;
    Init();
    m_unk06 = nSaved;
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

// FUNCTION: 0x001AABB0 Init__Q26PSound12AmbientEntryFv
void PSound::AmbientEntry::Init() {
    m_unk10 = 0x3FFF;
    m_unk14 = 0x400;
    m_unk16 = 0;
    m_unk18 = -1;
    m_unk1A = 0;
    m_unk1C = 0;
    m_unk3C = 0;
    m_unk40 = 0;
    m_unk44 = 0;
    m_unk48 = 0;
    m_unk4C = 0;
    m_unk50 = 0;
    m_unk54 = 0;
    m_unk5C = 0x7F7FFFFF;
    m_unk60 = 0;
    m_unk64 = 0;
    m_unk68 = 0;
    m_unk6C = 0;
}

// FUNCTION: 0x001AAC10 __ct__Q26PSound12AmbientEntryFv
PSound::AmbientEntry::AmbientEntry() {
    __ct__14PFadeMsecFloatFv(m_unk20);
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

// DRAFT: 0x001AACB0 PossiblyRandomPitch__Q26PSound8SpotInfoFv
// note: 27 words differ: nLo&0xFFFF hoisted as ori 0xFFFF + and reg (orig andi), nVal kept in v0 not a2, mult/lui order, gPSndDbg lui reloc; tried unsigned short ret/local (30), masked return (28), direct per-branch assignment (29)
int PSound::SpotInfo::PossiblyRandomPitch() {
    unsigned int nLo = m_unk08;
    unsigned int nHi = m_unk0A;
    int nRet = nLo & 0xFFFF;
    if (nLo < nHi) {
        unsigned int nVal;
        if (gPSndDbg[16] != 0) {
            miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
            nVal = (nLo + (unsigned int)miRandom__7MathAPI % (nHi - nLo)) & 0xFFFF;
        } else {
            nVal = (nLo + nHi) >> 1;
        }
        nRet = nVal & 0xFFFF;
    }
    return nRet;
}

// FUNCTION: 0x001AAD30 Init__Q26PSound8SpotInfoFv
void PSound::SpotInfo::Init() {
    m_unk10 = 0;
    m_unk0C = 0;
    m_unk00 = 0x3FFF;
    m_unk04 = 0;
    m_unk08 = 0;
    m_unk0A = 0;
    m_unk0E = 0;
    m_unk0F = 0;
    m_unk11 = 0;
    m_unk15 = 0;
    m_unk12 = 0x11;
}

// FUNCTION: 0x001AAD70 __ct__Q26PSound8SpotInfoFv
PSound::SpotInfo::SpotInfo() {
    Init();
}

// DRAFT: 0x001AAF20 UsageInit__6PSoundFv
// note: DIFF 6 words; original has three scheduling nops between the loop sltu and bnez and the guard beqz targets one slot further; tried int*, char*, unsigned cursors (15), int stride 5 (6), for-loop (11)
void PSound::UsageInit() {
    int *p = (int *)fst_Usage;
    int *end = (int *)(fst_Usage + 24000);
    if (p < end) {
        do {
            *p = -1;
            p += 5;
        } while (p < end);
    }
}

// FUNCTION: 0x001AAE50 UsageFind__6PSoundFUi
int *PSound::UsageFind(unsigned int nID) {
    int *p = (int *)fst_Usage;
    int *end = (int *)(fst_Usage + 24000);
    if (p < end) {
        do {
            if (p[0] == -1) {
                return 0;
            }
            if (nID == (unsigned int)p[0]) {
                return p;
            }
            p += 5;
        } while (p < end);
    }
    return 0;
}

// FUNCTION: 0x001AAEB0 UsageAdd__6PSoundFUi
int PSound::UsageAdd(unsigned int nID) {
    unsigned int *p = (unsigned int *)fst_Usage;
    unsigned int *end = (unsigned int *)(fst_Usage + 24000);
    if (p < end) {
        do {
            if (p[0] == 0xFFFFFFFF) {
                p[0] = nID;
                return 1;
            }
            if (nID == p[0]) {
                return 0;
            }
            p += 5;
        } while (p < end);
    }
    return -1;
}

// FUNCTION: 0x001AB330 DebugClearPlayedInGame__6PSoundFv
void PSound::DebugClearPlayedInGame() {
    int *p = (int *)fst_Usage;
    int *end = (int *)(fst_Usage + 0x6DC0);
    if (p < end) {
        do {
            if (p[0] == -1) {
                break;
            }
            p[1] = 0;
            p[2] = 0;
            p[4] = 0;
            p[3] = 0;
            p += 5;
        } while (p < end);
    }
}

// FUNCTION: 0x001AB380 DebugStopAllDebugAmbients__6PSoundFv
int PSound::DebugStopAllDebugAmbients() {
    int count = 0;
    AmbientEntry *p;
    AmbientEntry *end = (AmbientEntry *)((char *)this + 0x2220);
    p = (AmbientEntry *)((char *)this + 0x380);
    if (p < end) {
        do {
            if ((unsigned short)p->m_unk14 & 0x800) {
                StopAmbientEntry(p, 0);
                count++;
            }
            p = (AmbientEntry *)((char *)p + 0x70);
        } while (p < end);
    }
    return count;
}

// FUNCTION: 0x001AB400 DebugPlaySoundWPitch__6PSoundFUiUiUi
int PSound::DebugPlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2) {
    int nRet;

    fst_bCalledByDebug = 1;
    nRet = PlaySoundWPitch(p0, p1, 0, 0x810, p2);
    fst_bCalledByDebug = 0;
    return nRet;
}

// DRAFT: 0x001AB430 DebugRestartValues__6PSoundFv
// note: DIFF 5 words; original reloads lui $at,0x24 before each lbu of gPSndDbg+0x30, ours keeps one base in a0. Tried indexed byte (5), cast+offset (5), local byte temp (9).
void PSound::DebugRestartValues() {
    unsigned int nID = m_unk10;
    if (nID >= 0x64 && nID < 0x72) {
        SpotInfo *pSpot = GetSpotInfo(0x1C);
        if (pSpot != 0) {
            pSpot->m_unk0E = ((unsigned char *)gPSndDbg)[0x30];
            pSpot->m_unk0F = ((unsigned char *)gPSndDbg)[0x30];
        }
    }
}

// FUNCTION: 0x001AB480 WriteLineToPCFile__6PSoundFiPc
int PSound::WriteLineToPCFile(int nFd, char *pLine) {
    if (nFd < 0 || pLine == 0) {
        return -1;
    }
    int nLen = strlen(pLine);
    if (nLen != sceWrite(nFd, pLine, nLen)) {
        return -1;
    }
    return 0;
}

// FUNCTION: 0x001ACB40 DebugFindPrevID__6PSoundFPUiPUiUi
int PSound::DebugFindPrevID(unsigned int *pValue, unsigned int *pIndex, unsigned int nBound) {
    unsigned int i;
    unsigned int nIdx = (unsigned int)-1;
    unsigned int nMax = 0;
    unsigned int *pRec = (unsigned int *)m_unk2EB4;
    for (i = 0; i < m_unk14; i++, pRec += 6) {
        unsigned int nID = *pRec;
        if (nID < nBound && nMax < nID) {
            nMax = nID;
            nIdx = i;
        }
    }
    if (nIdx < m_unk14) {
        *pIndex = nIdx;
        *pValue = nMax;
        return 0;
    }
    return DebugFindLastID(pValue, pIndex);
}

// FUNCTION: 0x001ACBC0 DebugFindNextID__6PSoundFPUiPUiUi
int PSound::DebugFindNextID(unsigned int *pValue, unsigned int *pIndex, unsigned int nBound) {
    unsigned int i;
    unsigned int nIdx = (unsigned int)-1;
    unsigned int nMin = (unsigned int)-1;
    unsigned int *pRec = (unsigned int *)m_unk2EB4;
    for (i = 0; i < m_unk14; i++, pRec += 6) {
        unsigned int nID = *pRec;
        if (nBound < nID && nID < nMin) {
            nMin = nID;
            nIdx = i;
        }
    }
    if (nIdx < m_unk14) {
        *pIndex = nIdx;
        *pValue = nMin;
        return 0;
    }
    return DebugFindFirstID(pValue, pIndex);
}

// FUNCTION: 0x001ACC40 DebugFindLastID__6PSoundFPUiPUi
int PSound::DebugFindLastID(unsigned int *pValue, unsigned int *pIndex) {
    unsigned int i;
    unsigned int nIdx = (unsigned int)-1;
    unsigned int nMax = 0;
    unsigned int *pRec = (unsigned int *)m_unk2EB4;
    for (i = 0; i < m_unk14; i++, pRec += 6) {
        unsigned int nID = *pRec;
        if (nMax < nID) {
            nMax = nID;
            nIdx = i;
        }
    }
    int nRet = -1;
    if (nIdx < m_unk14) {
        *pIndex = nIdx;
        nRet = 0;
        *pValue = nMax;
    }
    return nRet;
}

// FUNCTION: 0x001ACCA0 DebugFindFirstID__6PSoundFPUiPUi
int PSound::DebugFindFirstID(unsigned int *pValue, unsigned int *pIndex) {
    unsigned int i;
    unsigned int nIdx = (unsigned int)-1;
    unsigned int nMin = (unsigned int)-1;
    unsigned int *pRec = (unsigned int *)m_unk2EB4;
    for (i = 0; i < m_unk14; i++, pRec += 6) {
        unsigned int nID = *pRec;
        if (nID < nMin) {
            nMin = nID;
            nIdx = i;
        }
    }
    int nRet = -1;
    if (nIdx < m_unk14) {
        *pIndex = nIdx;
        nRet = 0;
        *pValue = nMin;
    }
    return nRet;
}
