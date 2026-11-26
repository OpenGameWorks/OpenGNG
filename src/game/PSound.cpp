// FLAGS: -Cpp_exceptions off -str readonly
#include "PSound.h"
#include "MathAPI.h"
#include "PIOPFile.h"
#include "PCDFile.h"
#include "PMat4.h"

// TODO(header): foreign declarations
void CdsAssert(char *pFile, int nLine, char *pExpr);
extern "C" float atan2f(float, float);
extern "C" float Round180__Ff(float);
extern "C" float sqrtf(float);
extern "C" void SOUND_PlaySFXRelVol(int, unsigned int, int, int, unsigned int);
extern "C" void SOUND_SetChannelPitch(unsigned int, int);
extern "C" void SOUND_SetChanRelVol(unsigned int, int, int);
class Debug {
public:
    // Debug size is unknown; the placeholder keeps gDebug out of small data (threshold 8 bytes).
    char _pad000[0x10];
    void DebugDisp(char *pStr);
    void DebugColorDisp(char *pStr, unsigned char nColor);
    void DebugDispPos(char *pStr, unsigned int nX, unsigned int nY, int nColor);
};
extern Debug gDebug;
extern int fst_bProcessTriglets;
extern "C" void SOUND_StopAllSounds();
extern "C" void SOUND_SetGlobalRelVols(int, int, int, int, int, int, int, int);
extern int fst_ReverbRecProposed[5];
extern int fst_ReverbRecOff[5];
extern int fst_ReverbRecCur[5];
extern int gSOUND_EEControlReq;
extern "C" void SOUND_AllChannelReverbOff(int);
extern "C" void SOUND_ReverbSetAdrs(int, int);
extern "C" void SOUND_ClearIOPBuffer();
extern int gPSndDbg[52];
extern "C" void SOUND_ChangeReverbCore(int, int, int, int, int, int);
extern "C" void SOUND_ChangeReverbMasterVolume(int, int, int);
extern int fst_StartMultiple;
extern "C" int sceWrite(int, char *, int);
extern "C" int strlen(char *);
extern int miRandom__7MathAPI;
extern "C" void ShellSort__FPFPvPv_bPPvi(bool (*pCompare)(void *, void *), void **ppItems, int nCount);
extern "C" void SOUND_StopAllRegularSounds();
extern "C" void SOUND_StopAllMusic();
extern "C" void SOUND_StopAllStreams();
extern signed char fst_bCalledByDebug;
extern "C" void FlushIOPCommand(int, int, int);
extern "C" void SOUND_CopyIOPBuffer();
extern "C" void ProcessAmbientChannels__6PSoundFv(PSound *);
// TODO(header): foreign declarations
extern "C" int CheckAllChannelsMatch__6PSoundFv(PSound *pThis);
// TODO(header): foreign declarations
extern "C" int SOUND_FindFreeSPUChannel(unsigned int, unsigned int, int, unsigned int);
extern "C" void SOUND_CountFreeSPUChannels(unsigned int, unsigned int);
extern "C" int FindASubTableRandomItem__16PTranslateATableFPUiUiPFUi_iPCUi(unsigned int *, unsigned int, int (*)(unsigned int), const unsigned int *);
int SoundInBankStatus(unsigned int nBank);
extern "C" unsigned int MakeSoundRef__6PSoundFv(PSound *pThis);
extern int fst_PSWP_bUseDistCheck;
extern float fst_PSWP_fDistCheckRadSq;
extern int fst_ADSR_Msecs_Attack[16];
extern "C" int CheckOneChannelMatch__6PSoundFPQ26PSound19AmbientChannelState(PSound *pThis, void *pState);
extern "C" void FadeMsecFloatUpdate__14PFadeMsecFloatFUi(void *pThis, unsigned int nArg);
extern "C" void PlayEffect__6PSoundFUiUi(PSound *, unsigned int, unsigned int);
extern "C" void SOUND_GetStatusPatient();
extern "C" void SOUND_ResumeMultipleSounds(unsigned int, unsigned int);
extern "C" void SOUND_PauseMultipleSounds(unsigned int, unsigned int);
extern "C" void SOUND_SimulateCDError(int);
extern "C" unsigned int SOUND_DataDestEEDirect(unsigned int, short, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void FrameMaintenacePartA__7FileSysFv(void);
extern "C" void FrameMaintenacePartB__7FileSysFv(void);
extern unsigned char fst_bCheckFileTransfer;
extern int fst_bUseSimulatedCDErrors;
extern unsigned int fst_DataToEEBuffer[10240];
extern u_long128 gZeroVectorW1;
extern char gEng[105360];
struct DebugTopEntry {
    char *unk0;
    unsigned int *unk4;
    unsigned int unk8;
    unsigned int unkC;
};
extern DebugTopEntry fst_TopDebugTable[35];
extern unsigned int gPad[112];
extern "C" void SOUND_LogWindowInfo(int, int, int);
extern "C" void SOUND_MjlnCall(int, int, int);
extern "C" unsigned int EngGenerateUniqueID__9MaxEngineFv(void *pThis);
extern unsigned char MODE_PAL;
extern "C" void SOUND_FadeOutAllMusic(int);
extern "C" void SOUND_MusicAddExciteHits(int);
extern "C" bool PointInMatrixBoxWSphereCheck__7MathAPIFPfP14tagVuMatrixBoxP10tagFLOAT3D(float *pPos, void *pBox, void *pSphere);
extern int fst_ByPositionTypeReverbTable[40];
extern int dbg_ChangeFromType;
extern int dbg_ChangeToType;
extern int dbg_type;
extern "C" void __ct__14PFadeMsecFloatFv(void *);
extern "C" void __ct__Q26PSound16MusicStreamStateFv(void *);
extern "C" void __ct__Q26PSound19AmbientChannelStateFv(void *);
extern "C" void __ct__Q26PSound12AmbientEntryFv(void *);
extern "C" void __ct__Q26PSound19OneShotChannelStateFv(void *);
extern "C" void __ct__Q26PSound8SpotInfoFv(void *);
extern "C" void __ct__20GameSoundTrigletPawnFv(void *);
extern "C" void FadeMsecFloatPrep__14PFadeMsecFloatFffUiUi(void *pThis, float fStart, float fEnd, unsigned int nArg2, unsigned int nArg3);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void *memcpy(void *pDst, const void *pSrc, unsigned int nSize);
extern "C" void SOUND_SetSPUWriteAddress(unsigned int nAddr);
extern "C" void SOUND_TransferSFX(unsigned int nArg, int nZero, void *pBuf, int nSize);
extern "C" void SOUND_GetStatus(int nArg1, int nArg2);
extern char fst_GeneralBuf[9880];
extern char stADPCM_SpotFXArrayCurrent[9600];
extern int SOUND_STREAM_ON[4];
extern int SOUND_TRANSFER_DATA_BLOCK_TO_EE_STATUS;
extern int SOUND_SFX_TRANSFER_END;
extern "C" void *ApparitionIsValid__15EntityBaseClassFUi(unsigned int nId);
extern "C" int GetWorldMeshCenter__6PMNodeFPf(void *pThis, float *pOut);
extern "C" void *GetWorldPos__20GameSoundTrigletPawnFv(void *pThis);
extern "C" void sceVu0SubVector(float *pDst, float *pA, float *pB);
extern "C" float sceVu0InnerProduct(float *pA, float *pB);
struct tagFLOAT3D;
extern "C" void SOUND_StopMultipleSounds(int nHandle, int nCount);
extern "C" void __dl__FPv(void *pMem);
extern "C" int SOUND_StopStream(unsigned int);
extern "C" void SOUND_CloseStreamBuffer(int);
extern "C" void sceGsSyncV(int);
extern "C" int SOUND_InitIOP();
extern "C" void SOUND_InitSPU();
extern "C" void SOUND_ClearReverbWorkArea(int, int);
extern char gSOUND_EETransferStart[64];
extern char gSOUND_EETransferFinish[64];
extern "C" void SOUND_SetEETransferNotifyAdrs(void *, void *);
extern "C" void SOUND_SetChanUse(int, unsigned int, unsigned int, unsigned int, unsigned int);
extern "C" void SOUND_InitStreamData(int);
extern "C" void SOUND_SetLanguage(unsigned int);
extern "C" void SOUND_AllocateStreamBuffer(int, unsigned int, unsigned int);
extern int fst_ADSR_Translate_Attack[16];
extern int fst_ADSR_Translate_Release[16];
extern int fst_ADSR_Msecs_Release[16];
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
extern "C" int sceCdSync(int mode);
extern "C" void LoadingHangCheckInit__9FileUtilsFv();
extern "C" void LoadingDisplay__9InterfaceFUii(void *pThis, unsigned int nArg0, int nArg1);
extern unsigned char gInterface[2656];
extern "C" int SOUND_MakeSoundStreamRef();
extern "C" unsigned int SOUND_PlayDialogRelVol(unsigned int, unsigned int, unsigned int, short, unsigned int);
extern "C" void SOUND_FadeMusicStream(unsigned int, unsigned int, int, unsigned int);
extern "C" void sceVu0UnitMatrix(float *pMatrix);
extern "C" int sprintf(char *pDst, const char *pFmt, ...);
extern "C" int sceOpen(char *pName, int nFlags);
extern "C" int sceClose(int nFd);
extern "C" char *strcpy(char *pDst, const char *pSrc);
extern "C" char *strcat(char *pDst, const char *pSrc);
extern "C" int printf(const char *pFmt, ...);
extern char gszFilePrefix[128];
extern "C" int IsEBoxWithinEBox__7MathAPIFP6tagBOXP6tagBOX(tagBOX *pA, tagBOX *pB);
extern "C" float SetE_BOX_Radius__7MathAPIFP6tagBOX(tagBOX *pBox);
extern "C" unsigned int SOUND_PlayMusicRelVol(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern short gbMusic;
extern "C" int sceCdStatus();
extern "C" int sceCdDiskReady(int);
extern "C" int sceCdGetDiskType();
extern int SOUND_CD_READY;
extern int SOUND_CD_TRAY_OPEN;
extern int SOUND_IOP_CD_STATUS;
extern int SOUND_IOP_DISK_TYPE;
extern int SOUND_STREAM_ID[4];
extern int SOUND_STREAM_STATUS16[4];
extern unsigned int gSOUND_EEMainSyncCount3Returned;
extern PIOPFile fst_PIOPFileTest;
extern PCDFile fst_PCDFileTest;
extern char fst_ReadBuf[32768];
extern int fst_VBCountC;
extern int fst_VBCountD;
extern int fst_VBCountE;
extern int fst_VBCountF;
extern int fst_diffCD;
extern int fst_diffDE;
extern int fst_diffEF;
extern int fst_TransferUsecs;
extern int gSOUND_AllowSIFTranferTiming;
extern int gSOUND_usecsTotalTransfer;
class PTranslateATable {
public:
    static int FindASubTableRandomItem(unsigned int *pOut, unsigned int nIdx, int (*pfnBank)(unsigned int), const unsigned int *pTable);
    static void TranslateUIntToUInt(unsigned int *pOut, unsigned int nIdx, const unsigned int *pTable);
};
extern "C" void *GetLevelFile__10MaximoMainFi(void *pThis, int nIdx);
extern "C" int PlaySound__6PMNodeFUi(PMNode *pThis, unsigned int nSound);
int SoundInBankStatus(unsigned int nBank);
extern unsigned int gSndSetOfIDsTable[16];
extern "C" void SOUND_SetPauseCategories(unsigned int);
extern "C" void SOUND_LevelRestart();
extern "C" void SOUND_SetMasterRegisterVolumeAbs(int);
extern "C" void SOUND_EnableFeatures(int, int);
extern "C" void SOUND_StreamAfterFlags(int, int, int, int, int, int);

// FUNCTION: 0x001A3CC0 VerifyAmbientEntryList__6PSoundFPQ26PSound12AmbientEntry
unsigned int PSound::VerifyAmbientEntryList(AmbientEntry *pHead) {
    static int st_Calls;
    static char init;
    unsigned int nCount = 0;
    AmbientEntry *pPrev = 0;
    AmbientEntry *pCur = pHead;

    if (!init) {
        st_Calls = 0;
        init = 1;
    }
    st_Calls += 1;
    while (pCur != 0) {
        nCount += 1;
        ((nCount <= 0xC8) ? (void)0 : CdsAssert("PSound.cpp", 0x2578, "0"));
        ((pPrev == pCur->m_unk54) ? (void)0 : CdsAssert("PSound.cpp", 0x257B, "0"));
        pPrev = pCur;
        pCur = pCur->m_unk50;
    }
    return nCount;
}

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

// FUNCTION: 0x001A3EE0 FindFadingAmbientChannel__6PSoundFv
unsigned int PSound::FindFadingAmbientChannel() {
    int *p = (int *)m_unkF8;
    unsigned int idx = m_unk2E28;
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

// DRAFT: 0x001A3F90 DelinkChannelState__6PSoundFPPQ26PSound19AmbientChannelStatePQ26PSound12AmbientEntry
// note: DIFF 24; decl order from 120-permutation sweep (pFound=0,pCur,pNewHead,pPrev=0,pChain) plus unsigned short copy of m_unk04; remaining diff is t1/a3/t0 register swap (original pFound=t1 pPrev=t2 pCur=t0 pNewHead=a3).
int PSound::DelinkChannelState(AmbientChannelState **ppHead, AmbientEntry *pEntry) {
    AmbientChannelState *pHead;
    AmbientChannelState *pFound = 0;
    AmbientChannelState *pCur;
    AmbientChannelState *pNewHead;
    AmbientChannelState *pPrev = 0;
    AmbientEntry *pChain;
    short nKey;

    if (pEntry == 0) {
        goto fail;
    }
    nKey = pEntry->m_unk18;
    pHead = (AmbientChannelState *)pEntry->m_unk4C;
    if (pHead == 0) {
        goto fail;
    }
    pChain = (AmbientEntry *)pHead->m_unk08;
    pNewHead = pHead;
    pCur = pHead;
    while (pCur != 0) {
        if (nKey == pCur->m_unk06) {
            pHead->m_unk10 = pHead->m_unk10 - 1;
            if ((unsigned short)pCur->m_unk04 & 0x4000) {
                pHead->m_unk14 = pHead->m_unk14 - 1;
            }
            if (pPrev != 0) {
                pPrev->m_unk1C = pCur->m_unk1C;
            } else {
                pNewHead = (AmbientChannelState *)pCur->m_unk1C;
                pEntry->m_unk4C = (int)pNewHead;
            }
            pCur->m_unk1C = 0;
            pFound = pCur;
            break;
        }
        pPrev = pCur;
        pCur = (AmbientChannelState *)pCur->m_unk1C;
    }
    if (pFound == 0) {
        goto fail;
    }
    if (pNewHead != pHead) {
        if (pNewHead != 0) {
            *(unsigned short *)&pNewHead->m_unk04 = *(unsigned short *)&pHead->m_unk04;
            pNewHead->m_unk0C = pHead->m_unk0C;
            pNewHead->m_unk10 = pHead->m_unk10;
            pNewHead->m_unk14 = pHead->m_unk14;
            pNewHead->m_unk08 = pHead->m_unk08;
        }
        while (pChain != 0) {
            pChain->m_unk4C = (int)pNewHead;
            pChain = pChain->m_unk50;
        }
    }
    if (ppHead != 0) {
        *ppHead = pFound;
    }
    return 0;
fail:
    return -1;
}

// FUNCTION: 0x001A40C0 GetTrayRelated__6PSoundFPiPiPiPi
void PSound::GetTrayRelated(int *pTrayOpen, int *pStatus, int *pReady, int *pType) {
    int nTrayOpen;
    int nStatus;
    int nReady;
    int nType;
    if (GetEEControlStatus() == 3) {
        nTrayOpen = 0;
        nStatus = sceCdStatus();
        nReady = sceCdDiskReady(1);
        nType = sceCdGetDiskType();
        if (nStatus == 1) {
            nTrayOpen = 1;
        }
    } else {
        nTrayOpen = SOUND_CD_TRAY_OPEN;
        nStatus = SOUND_IOP_CD_STATUS;
        nReady = SOUND_CD_READY;
        nType = SOUND_IOP_DISK_TYPE;
    }
    if (pTrayOpen != 0) {
        *pTrayOpen = nTrayOpen;
    }
    if (pStatus != 0) {
        *pStatus = nStatus;
    }
    if (pReady != 0) {
        *pReady = nReady;
    }
    if (pType != 0) {
        *pType = nType;
    }
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

// DRAFT: 0x001A4200 PlayMultipleAtOnce__6PSoundFUi
// note: 7 words differ: pEnd lands in s2 and nPlayed in s1 (original s1/s2 swapped); tried declaration order (7), unsigned nEnd cursor (12), pEnd from m_unk2EB4 (9), pointer compares with >= break (7), signed nPlayed (7), unsigned pEnd and nPlayed scoped in the guard (7), nPlayed declared before pSpot (12), pEnd declared before nPlayed (7, same registers).
int PSound::PlayMultipleAtOnce(unsigned int nSound) {
    SpotInfo *pSpot = (SpotInfo *)m_unk2EB4;
    unsigned int nPlayed = 0;
    SpotInfo *pEnd = (SpotInfo *)((char *)pSpot + 0x2580);
    if ((unsigned int)pEnd >= (unsigned int)pSpot) {
        do {
            if (!(pSpot->m_unk0C & 2)) {
                PlaySoundUbiquitous(pSpot->m_unk00);
                nPlayed++;
                if (!(nPlayed < nSound)) {
                    break;
                }
            }
            pSpot++;
        } while ((unsigned int)pEnd >= (unsigned int)pSpot);
    }
    return 0;
}

// FUNCTION: 0x001A42A0 TriggerSystemSound__6PSoundFUiUiP6PMNode
int PSound::TriggerSystemSound(unsigned int p0, unsigned int p1, PMNode *pNode) {
    unsigned int nSound = 0;
    int nRet = 0;
    if (pNode == 0) {
        CdsAssert("PSound.cpp", 0x23F5, "i_pNode");
    }
    unsigned int nTable = *(unsigned int *)((char *)GetLevelFile__10MaximoMainFi(gEng, -1) + 0x64);
    if (nTable != 0) {
        PTranslateATable::TranslateUIntToUInt(&nSound, p0, (const unsigned int *)nTable);
    }
    if (nSound != 0) {
        nRet = PlaySound__6PMNodeFUi(pNode, nSound);
    }
    return nRet;
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

// FUNCTION: 0x001A4410 CutSceneLeave__6PSoundFUi
void PSound::CutSceneLeave(unsigned int nArg) {
    KillByCategories(0x20C);
    if (nArg == (unsigned int)m_unk2E64) {
        unsigned int nTrack = m_unk2E68;
        if (nTrack != (unsigned int)m_unk2E6C && !(m_unk2E70 & 0xC0000000)) {
            PlayMusic(nTrack);
        }
        if (m_unk2E70 & 0x80000000) {
            PlayMusic(0);
            *(int *)(gEng + 0x19B48) = 0;
        }
        if (m_unk2E70 & 0x40000000) {
            *(int *)(gEng + 0x19B48) = m_unk2E6C;
        }
    } else {
        CdsAssert("PSound.cpp", 0x238A, "0");
    }
    SetMainMusicSpecialVolume((EnumMusicSpecialVols)0);
    PauseByCategories(0);
}

// FUNCTION: 0x001A44F0 CutSceneEnter__6PSoundFPUiUiUiUi
void PSound::CutSceneEnter(unsigned int *pOut, unsigned int nArg, unsigned int nFlags, unsigned int nVolume) {
    unsigned int nLevel;
    unsigned int nID;
    int bSkip;

    unsigned int nTrack = nFlags & 0x1FFFFFFF;
    m_unk2E68 = m_unk1C;
    m_unk2E6C = m_unk2E68;
    m_unk2E70 = nFlags;
    if (nTrack != 0) {
        m_unk2E6C = nTrack;
        if (m_unk2E6C != m_unk2E68) {
            PlayMusic(m_unk2E6C);
        }
    }
    if (nFlags & 0x20000000) {
        PauseByCategories(0x82);
    } else {
        PauseByCategories(0x80);
        bSkip = 0;
        if (gPSndDbg[20] != 0) {
            nLevel = gPSndDbg[21];
        } else if (nVolume == 0) {
            SetMainMusicSpecialVolume((EnumMusicSpecialVols)1);
            bSkip = 1;
        } else {
            nLevel = nVolume;
        }
        if (bSkip == 0) {
            if (nLevel >= 100) {
                nLevel = 100;
            }
            m_unk40 = nLevel * 10;
            InternalUpdateRelVolumes();
        }
    }
    nID = EngGenerateUniqueID__9MaxEngineFv(gEng);
    if (pOut != 0) {
        *pOut = nID;
    }
    m_unk2E64 = nID;
    StartPreppedDialog(nArg);
}

// FUNCTION: 0x001A4640 StartPreppedDialog__6PSoundFUi
int PSound::StartPreppedDialog(unsigned int nArg) {
    int nReady;

    if ((nArg < 0xC8) || (nArg >= 0xE4)) {
        return -2;
    }
    if (nArg != m_unk2E50[2]) {
        return -3;
    }
    if (m_unk2E50[0] == 0) {
        return -1;
    }
    nReady = GetDialogStreamReadiness(nArg);
    if (nReady == -1) {
        return -1;
    }
    if (nReady != 0) {
        return 1;
    }
    SOUND_StreamAfterFlags(0, m_unk2E50[0], 2, 2, 0, 0);
    return 0;
}

// FUNCTION: 0x001A46F0 GetDialogStreamReadiness__6PSoundFUi
int PSound::GetDialogStreamReadiness(unsigned int nArg) {
    int nRef;

    if ((nArg < 0xC8U) || (nArg >= 0xE4U)) {
        CdsAssert("PSound.cpp", 0x22CD, "0");
        return -1;
    }
    nRef = m_unk2E50[2];
    if (nArg != (unsigned int)nRef) {
        return -1;
    }
    if (m_unk2E50[0] == 0) {
        return -1;
    }
    if (gSOUND_EEMainSyncCount3Returned <= (unsigned int)m_unk2E60) {
        return 1;
    }
    if ((SOUND_STREAM_STATUS16[0] & 0xC000) != 0xC000) {
        return 1;
    }
    if (SOUND_STREAM_ID[0] != nRef) {
        CdsAssert("PSound.cpp", 0x22E7, "0");
    }
    return 0;
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

// FUNCTION: 0x001A49C0 KillByCategories__6PSoundFUi
void PSound::KillByCategories(unsigned int nCategory) {
    if (nCategory & 0x200) {
        unsigned int i = m_unk2E30;
        for (; m_unk2E34 >= i; i++) {
            if (SOUND_SPUKeyStatus[i]) {
                StopOneShot(i);
            }
        }
    }
    if (nCategory & 0x80) {
        AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
        AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
        if (pEntry < pEnd) {
            do {
                if (pEntry->m_unk10 != 0x3FFF && !((unsigned short)pEntry->m_unk14 & 0x400)) {
                    StopAmbientEntry(pEntry, 1);
                }
                pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
            } while (pEntry < pEnd);
        }
    }
    if (nCategory & 0xC) {
        SOUND_StopStream(0);
    }
}

// DRAFT: 0x001A4AB0 ProcessTriglets__6PSoundFv
// note: 88 words differ; loop index/offset regs swapped (s1/s2 vs s7/s6), nOuter mask and pRec+0x136 hoisting differ. Tried: case order, nNow order, nSnd before pRec, hoisted type pointer.
int PSound::ProcessTriglets() {
    if (*((unsigned char *)&gDebug + 0x2C) != 0) {
        return 0;
    }
    if (fst_bProcessTriglets == 0) {
        return 0;
    }
    if (!m_unkD0) {
        return 0;
    }
    if (m_unk68 == 0) {
        return 0;
    }
    if (*(unsigned int *)(gEng + 0x19A7C) & 7) {
        return 0;
    }
    unsigned int i = 0;
    unsigned int nOff = 0;
    unsigned int nNow = m_unk6C;
    for (; i < (unsigned int)m_unk79E0[0]; nOff += 0x150, i++) {
        unsigned int nSnd;
        char *pRec = m_unk79F8 + nOff;
        if (((unsigned char *)pRec)[0x130] != 0 && *(unsigned int *)(pRec + 0x114) == 0 && *(unsigned int *)(pRec + 0x118) != 0) {
            nSnd = *(unsigned int *)(pRec + 0x124);
            int nOuter = PointInEnclosure((float *)m_unk2E90, (tagBOX_OR_SPHERE *)(pRec + 0x40), (tagVuMatrixBox *)(pRec + 0xC0), (EnumEnclosureType)((unsigned char *)pRec)[0x136]) & 0xFF;
            int nInner = nOuter ? (PointInEnclosure((float *)m_unk2E90, (tagBOX_OR_SPHERE *)(pRec + 0x10), (tagVuMatrixBox *)(pRec + 0x70), (EnumEnclosureType)((unsigned char *)pRec)[0x136]) & 0xFF) : 0;
            pRec[0x134] = nInner;
            pRec[0x135] = nOuter;
            switch (*(unsigned int *)(pRec + 0x12C)) {
            case 1:
                if (nOuter == 0) {
                    StartAESoftwareFadeout(nSnd, 0);
                    StopSoundBySoundRef(nSnd);
                    *(unsigned int *)(pRec + 0x124) = 0;
                    *(unsigned int *)(pRec + 0x12C) = 0;
                } else if (nSnd && *(unsigned short *)(pRec + 0x138) && *(unsigned int *)(pRec + 0x140) < nNow && IsAmbientSoundBySoundRef(nSnd) == 0) {
                    *(unsigned int *)(pRec + 0x12C) = 0;
                }
                break;
            case 0:
                if (nInner && (*(unsigned int *)(pRec + 0x148) == 0 || *(unsigned short *)(pRec + 0x13A) == 0 || *(unsigned int *)(pRec + 0x140) < nNow)) {
                    int nPlay = (*(unsigned int *)(pRec + 0x120) & 2) ? PlaySoundTrigletUbiquitous(*(unsigned int *)(pRec + 0x118), 0, (const GameSoundTrigletPawn *)pRec) : PlaySoundTriglet(*(unsigned int *)(pRec + 0x118), 0, (const GameSoundTrigletPawn *)pRec);
                    *(int *)(pRec + 0x124) = nPlay;
                    *(int *)(pRec + 0x148) += 1;
                    *(unsigned int *)(pRec + 0x13C) = nNow;
                    *(unsigned int *)(pRec + 0x140) = nNow + MathAPI::RandomIntRange(*(unsigned short *)(pRec + 0x138), *(unsigned short *)(pRec + 0x13A));
                }
                if (*(unsigned int *)(pRec + 0x124) != 0) {
                    *(unsigned int *)(pRec + 0x12C) = 1;
                }
                break;
            default:
                CdsAssert("PSound.cpp", 0x2163, "0");
                break;
            }
        }
    }
    return 0;
}

// DRAFT: 0x001A4D80 PointInEnclosure__6PSoundFPfP16tagBOX_OR_SPHEREP14tagVuMatrixBox17EnumEnclosureType
// note: DIFF 3; constant 1 on the sphere path is addiu, original daddiu; argument setup for the matrix call places the this adjust before jal, original in its delay slot. Tried: bool nRet with direct return (DIFF 4), function-scope bool and masked bool (4+), bool bIn inside sphere branch with unmasked else (DIFF 14), bool temporary and local MathAPI receiver (no change).
int PSound::PointInEnclosure(float *pPoint, tagBOX_OR_SPHERE *pBox, tagVuMatrixBox *pMatrix, EnumEnclosureType eType) {
    float vDiff[4];
    float vCenter[4];
    int nRet = 0;
    if (eType == ENCLOSURE_SPHERE) {
        memcpy(vCenter, pBox, 0x10);
        sceVu0SubVector(vDiff, pPoint, vCenter);
        if (sceVu0InnerProduct(vDiff, vDiff) <= ((float *)pBox)[3] * ((float *)pBox)[3]) {
            bool bIn = true;
            nRet = bIn;
        }
    } else {
        nRet = ((MathAPI *)((char *)this + 0x2E90))->PointInMatrixBoxWSphereCheck((float *)pMatrix, (tagVuMatrixBox *)pBox, (tagFLOAT3D *)pMatrix) & 0xFF;
    }
    return nRet;
}

// FUNCTION: 0x001A4E20 EnableTrigletByInstanceID__6PSoundFUib
int PSound::EnableTrigletByInstanceID(unsigned int nInstanceID, bool bEnable) {
    for (unsigned int i = 0, nOff = 0; i < (unsigned int)m_unk79E0[0]; nOff += 0x150, i++) {
        char *pTrig = m_unk79F8 + nOff;
        if (((unsigned char *)pTrig)[0x131] != 0 && nInstanceID == *(unsigned int *)(pTrig + 0x128)) {
            pTrig[0x132] = bEnable;
            pTrig[0x130] = ((unsigned char *)pTrig)[0x132];
            if (!bEnable) {
                unsigned int nSnd = *(unsigned int *)(pTrig + 0x124);
                if (nSnd != 0) {
                    StopSoundBySoundRef(nSnd);
                    *(unsigned int *)(pTrig + 0x12C) = 0;
                }
            }
            return 0;
        }
    }
    return -1;
}

// DRAFT: 0x001A4ED0 RegisterSoundTrigletPawn__6PSoundFP15EntityBaseClass24EnumSoundTrigletPawnType
// note: DIFF 12; type-2 memcpy arg order (a0=pRec+0x10 before a1) and sprintf/assert string placement at 0x228-0x258 differ. Tried: case order, nTime order, lhu bounds (16->12), hoisted memcpy source (12).
int PSound::RegisterSoundTrigletPawn(EntityBaseClass *pEntity, EnumSoundTrigletPawnType eType) {
    bool bValid = true;
    float mat[4][4];
    char buf[0x80];
    int bWithin;
    unsigned int nInstanceID = *(unsigned int *)((char *)pEntity + 0xC);
    unsigned int nCount;
    int nTime = 0;

    sceVu0UnitMatrix((float *)mat);
    nCount = m_unk79E0[0];
    if (nCount >= 0xC8) {
        CdsAssert("PSound.cpp", 0x2021, "0");
        return -1;
    }
    char *pRec = m_unk79F8 + nCount * 0x150;
    pRec[0x131] = 0;
    pRec[0x132] = 0;
    pRec[0x130] = 0;
    *(unsigned int *)(pRec + 0x128) = nInstanceID;
    *(int *)(pRec + 0x110) = eType;
    *(int *)(pRec + 0x114) = 0;
    *(int *)(pRec + 0x124) = 0;
    pRec[0x137] = 0;
    *(int *)(pRec + 0x144) = 1000;
    *(int *)(pRec + 0x148) = 0;
    *(int *)(pRec + 0x11C) = 1000;

    switch (eType) {
    case SOUND_TRIGLET_PAWN_TYPE_1: {
        char *pSrc = (char *)pEntity + 0x1B0;
        *(int *)(pRec + 0x120) = *(int *)((char *)pEntity + 0x1E0);
        pRec[0x136] = 0;
        *(int *)(pRec + 0x118) = *(int *)((char *)pEntity + 0x1D0);
        *(int *)(pRec + 0x114) = 0;
        nTime = *(int *)((char *)pEntity + 0x1D4);
        *(short *)(pRec + 0x138) = *(unsigned short *)((char *)pEntity + 0x1D8);
        *(short *)(pRec + 0x13A) = *(unsigned short *)((char *)pEntity + 0x1DC);
        memcpy(pRec + 0x10, pSrc, 0x30);
        memcpy(pRec + 0x40, pSrc + 0x10, 0x30);
        memcpy(pRec, pRec + 0x10, 0x10);
        bWithin = MathAPI::IsESphereWithinESphere((tagSPHERE *)(pRec + 0x10), (tagSPHERE *)(pRec + 0x40));
        break;
    }
    case SOUND_TRIGLET_PAWN_TYPE_2:
        *(int *)(pRec + 0x120) = *(int *)((char *)pEntity + 0x220);
        pRec[0x136] = 1;
        *(int *)(pRec + 0x118) = *(int *)((char *)pEntity + 0x210);
        *(int *)(pRec + 0x114) = 0;
        nTime = *(int *)((char *)pEntity + 0x214);
        *(short *)(pRec + 0x138) = *(unsigned short *)((char *)pEntity + 0x218);
        *(short *)(pRec + 0x13A) = *(unsigned short *)((char *)pEntity + 0x21C);
        memcpy(pRec + 0x10, (char *)pEntity + 0x1B0, 0x30);
        memcpy(pRec + 0x40, (char *)pEntity + 0x1E0, 0x30);
        SetE_BOX_Radius__7MathAPIFP6tagBOX((tagBOX *)(pRec + 0x10));
        SetE_BOX_Radius__7MathAPIFP6tagBOX((tagBOX *)(pRec + 0x40));
        memcpy(pRec, pRec + 0x10, 0x10);
        ((PMat4 *)mat)->InverseByRT((float *)(pRec + 0x30), (float *)(pRec + 0x10));
        sceVu0CopyMatrix((float (*)[4])(pRec + 0x70), mat);
        *(u_long128 *)(pRec + 0xB0) = *(u_long128 *)(pRec + 0x20);
        ((PMat4 *)mat)->InverseByRT((float *)(pRec + 0x60), (float *)(pRec + 0x40));
        sceVu0CopyMatrix((float (*)[4])(pRec + 0xC0), mat);
        *(u_long128 *)(pRec + 0x100) = *(u_long128 *)(pRec + 0x50);
        bWithin = IsEBoxWithinEBox__7MathAPIFP6tagBOXP6tagBOX((tagBOX *)(pRec + 0x10), (tagBOX *)(pRec + 0x40));
        break;
    default:
        CdsAssert("PSound.cpp", 0x206D, "0");
        bValid = false;
        break;
    }

    if (bValid) {
        if (bWithin == 0) {
            sprintf(buf, "Apparition %d inner not within outer\n", nInstanceID);
        }
        ((bWithin) ? (void)0 : CdsAssert("PSound.cpp", 0x2075, "bInnerWithinOuter"));
        pRec[0x131] = 1;
        pRec[0x132] = 1;
        pRec[0x130] = 1;
        pRec[0x133] = 1;
        *(int *)(pRec + 0x12C) = 0;
        pRec[0x134] = 0;
        pRec[0x135] = 0;
        *(int *)(pRec + 0x11C) = nTime * 10;
        *(int *)(pRec + 0x140) = 0;
        m_unk79E0[0] += 1;
    }
    return 0;
}

// FUNCTION: 0x001A51C0 RegisterSoundEntityAmounts__6PSoundFUiUiUiUi
void PSound::RegisterSoundEntityAmounts(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3) {
    ((m_unk544C == 0) ? (void)0 : CdsAssert("PSound.cpp", 0x1FFE, "0 == mNSoundRooms"));
    ((m_unk79E0[0] == 0) ? (void)0 : CdsAssert("PSound.cpp", 0x1FFF, "0 == mNTrigletPawns"));
    ((m_unk79E0[4] == 0) ? (void)0 : CdsAssert("PSound.cpp", 0x2000, "0 == mNTrigletMasters"));
    m_unk5450 = p0;
    m_unk79E0[1] = p1;
    m_unk79E0[3] = p2;
    m_unk79E0[5] = p3;
    m_unk79E0[0] = 0;
    m_unk79E0[4] = 0;
    m_unk79E0[2] = 0;
}

// DRAFT: 0x001A5290 RegisterRoom__6PSoundFP9SoundRoom
// note: 38 words; frame 0x50 vs 0x40 (pRoom+0x1B0 hoisted to s0, extra s3); third MakeMatrixBox arg is an uninit local that lands on pRoom reg, original leaves a3 untouched; dead lw pRoom+0xC missing (keeps pRoom in s0). Tried block-scope/function-scope uninit, literal 0, unsigned compare, volatile pRoom (57).
int PSound::RegisterRoom(SoundRoom *pRoom) {
    tagBOX *pUnset;
    if (!((unsigned int)m_unk544C < 0x28)) {
        CdsAssert("PSound.cpp", 0x1FE7, "0");
        return -1;
    }
    char *pRec = m_unk5460 + m_unk544C * 0xF0;
    memcpy(pRec + 0xA0, (char *)pRoom + 0x1B0, 0x40);
    *(int *)(pRec + 0xE0) = ((MathAPI *)pRec)->MakeMatrixBox((tagVuMatrixBox *)(pRec + 0xA0), (tagBOX *)((char *)pRoom + 0x1B0), pUnset, 0.0f);
    ((MathAPI *)(pRec + 0x50))->MakeMatrixBox(0, (tagBOX *)((char *)pRoom + 0x1B0), pUnset, 1.0f);
    m_unk544C += 1;
    return 0;
}

// DRAFT: 0x001A5360 SetReverbByPosition__6PSoundFPf
// note: 114 words differ. Frame 0x70 with s5 vs 0x60 with s0..s4; first-check and hit-path gp/table load order differs; table base folds differ; tail loop order differs. Tried: local order, unsigned compares, rec pointer, indexed fields.
void PSound::SetReverbByPosition(float *pPos)
{
    int i;
    unsigned int off;
    char *rec;
    int prev = m_unk5444;
    if (!((unsigned int)prev < (unsigned int)m_unk544C && (rec = m_unk5460 + prev * 0xF0,PointInMatrixBoxWSphereCheck__7MathAPIFPfP14tagVuMatrixBoxP10tagFLOAT3D(pPos, rec + 0x50, rec + 0xA0)))) {
        m_unk5444 = -1;
        for (i = 0, off = 0; i < m_unk544C; off += 0xF0, i++) {
            char *rec = m_unk5460 + off;
            if (PointInMatrixBoxWSphereCheck__7MathAPIFPfP14tagVuMatrixBoxP10tagFLOAT3D(pPos, rec + 0x50, rec + 0xA0)) {
                m_unk5444 = i;
                unsigned int p1 = *(unsigned int *)(m_unk5460 + i * 0xF0 + 0xD0);
                unsigned int v = *(unsigned int *)(m_unk5460 + i * 0xF0 + 0xD4);
                unsigned int d8 = *(unsigned int *)(m_unk5460 + i * 0xF0 + 0xD8);
                unsigned int dc = *(unsigned int *)(m_unk5460 + i * 0xF0 + 0xDC);
                if (dbg_ChangeFromType == (int)p1) {
                    p1 = dbg_ChangeToType;
                }
                if (dbg_type == (int)p1) {
                    v = fst_ByPositionTypeReverbTable[1 + p1 * 4];
                    d8 = fst_ByPositionTypeReverbTable[2 + p1 * 4];
                    dc = fst_ByPositionTypeReverbTable[3 + p1 * 4];
                }
                SetProposedReverbParams(p1, v << 8, v << 8, d8, dc);
                break;
            }
        }
    }
    if ((unsigned int)m_unk5444 >= (unsigned int)m_unk544C) {
        SetProposedReverbParams(fst_ReverbRecOff[0], fst_ReverbRecOff[1], fst_ReverbRecOff[2], fst_ReverbRecOff[3], fst_ReverbRecOff[4]);
    }
    if (prev != m_unk5444) {
        ChangeReverb();
    }
    if ((unsigned int)m_unk5444 < (unsigned int)m_unk544C) {
        if (gPSndDbg[39]) {
            m_unk18080 = 0x62;
            m_unk18084 = 1;
        }
    } else {
        if (gPSndDbg[40]) {
            m_unk18080 = 0xE9;
            m_unk18084 = 1;
        }
    }
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

// FUNCTION: 0x001A55F0 ChangeReverb__6PSoundFv
void PSound::ChangeReverb() {
    int bChanged = 0;
    if (gPSndDbg[32] != 0) {
        if (fst_ReverbRecCur[0] != fst_ReverbRecProposed[0]) {
            bChanged = 1;
        } else if ((unsigned int)fst_ReverbRecCur[0] >= 7 && (fst_ReverbRecCur[3] != fst_ReverbRecProposed[3] || fst_ReverbRecCur[4] != fst_ReverbRecProposed[4])) {
            bChanged = 1;
        }
        if (bChanged != 0) {
            memcpy(fst_ReverbRecCur, fst_ReverbRecProposed, 0x14);
            SOUND_ChangeReverbCore(0, fst_ReverbRecCur[0], fst_ReverbRecCur[1], fst_ReverbRecCur[2], fst_ReverbRecCur[3], fst_ReverbRecCur[4]);
            SOUND_ChangeReverbCore(1, fst_ReverbRecCur[0], fst_ReverbRecCur[1], fst_ReverbRecCur[2], fst_ReverbRecCur[3], fst_ReverbRecCur[4]);
        } else if (fst_ReverbRecCur[1] != fst_ReverbRecProposed[1] || fst_ReverbRecCur[2] != fst_ReverbRecProposed[2]) {
            memcpy(fst_ReverbRecCur, fst_ReverbRecProposed, 0x14);
            SOUND_ChangeReverbMasterVolume(0, fst_ReverbRecCur[1], fst_ReverbRecCur[2]);
            SOUND_ChangeReverbMasterVolume(1, fst_ReverbRecCur[1], fst_ReverbRecCur[2]);
        }
        m_unk5434 = 1;
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

// FUNCTION: 0x001A57B0 CheckOneChannelMatch__6PSoundFPQ26PSound19AmbientChannelState
void PSound::CheckOneChannelMatch(AmbientChannelState *pState) {
    CheckOneChannelMatchSub(pState);
}

// FUNCTION: 0x001A57C0 CheckAllChannelsMatch__6PSoundFv
void PSound::CheckAllChannelsMatch() {
    CheckAllChannelsMatchSub();
}

// DRAFT: 0x001A57D0 CheckAllChannelsMatchSub__6PSoundFv
// note: DIFF 12; top-tested while inner walks best (do-while DIFF 21/18); extra nop after inner-loop lw and outer-loop branch targets differ.
int PSound::CheckAllChannelsMatchSub() {
    AmbientChannelState *pState = (AmbientChannelState *)m_unkF8;
    AmbientChannelState *pEnd = (AmbientChannelState *)(m_unkF8 + (*(int *)((char *)this + 0xE4) << 5));
    while (pState < pEnd) {
        AmbientChannelState *pV = pState;
        void *pA = (void *)pState->m_unk08;
        if (pA != 0) {
            if (pState != 0) {
                while (pV != 0) {
                    pV = (AmbientChannelState *)pV->m_unk1C;
                }
            }
            if (pA != 0) {
                while (pA != 0) {
                    pA = *(void **)((char *)pA + 0x50);
                }
            }
        }
        pState++;
    }
    return 0;
}

// DRAFT: 0x001A5870 CheckOneChannelMatchSub__6PSoundFPQ26PSound19AmbientChannelState
// note: DIFF 23: original has 5 nops after each inner-loop lw (ours 4), so the else branch and loop offsets are one word off; tried do-while and top-tested while forms. Under `// COMPILER: mwcps2-3.0-011126` (probe in src/scratch/PSound-d862789/probe/) it MATCHES, so the file's compiler is a coordinator decision.
int PSound::CheckOneChannelMatchSub(AmbientChannelState *pState) {
    int nResult = 0;
    if (pState != 0) {
        void *pA = (void *)pState->m_unk08;
        if (pA != 0) {
            if (pState != 0) {
                do {
                    pState = (AmbientChannelState *)pState->m_unk1C;
                } while (pState != 0);
            }
            if (pA != 0) {
                do {
                    pA = *(void **)((char *)pA + 0x50);
                } while (pA != 0);
            }
        }
    } else {
        nResult = -1;
        CdsAssert("PSound.cpp", 0x1E23, "0");
    }
    return nResult;
}

// FUNCTION: 0x001A5920 ErrorRecovery__6PSoundFv
void PSound::ErrorRecovery() {
    bool bSaved = m_unkD0;

    PSoundRestart();
    EnableProcessTriglets(bSaved);
}

// DRAFT: 0x001A5960 OneFrameHasElapsed_R__6PSoundFPffRiRi
// note: DIFF 6 words; rA/rB global order fixed (8 to 6); m_unk68 reload lands in v1 and t in v0 (original v0/v1); tried int t split, base local, if/else split, != 0 vs truthiness, t declared then assigned, 0 != m_unk68, unsigned t, t declared at function top (all 6, reloaded m_unk68 still lands in v1)
int PSound::OneFrameHasElapsed_R(float *pElapsed, float fFrame, int &rA, int &rB) {
    m_unk68 = *(int *)(gEng + 0x1883C);
    m_unk6C = *(int *)(gEng + 0x19B74);
    if (m_unk68 != 0) {
        int t = *(int *)(m_unk68 + 0x3C);
        *(u_long128 *)&m_unk2E90 = *(u_long128 *)(t ? t + 0x80 : m_unk68 + 0x190);
    } else {
        *(u_long128 *)&m_unk2E90 = gZeroVectorW1;
    }
    if (m_unk00 == 0) {
        return 0;
    }
    *(u_long128 *)&m_unk2EA0 = *(u_long128 *)pElapsed;
    m_unk2EB0 = fFrame;
    if (!*(unsigned char *)&m_unkD1) {
        return 0;
    }
    m_unk2E7C++;
    SOUND_GetStatusPatient();
    if (m_unk543C != m_unk5440) {
        SOUND_EnableFeatures(m_unk543C, -1);
        m_unk5440 = m_unk543C;
    }
    ProcessMusic();
    ProcessTriglets();
    ProcessSFXChannels();
    ProcessAmbientChannels__6PSoundFv(this);
    if (m_unkC0[0] || m_unkC0[1]) {
        SOUND_ResumeMultipleSounds(m_unkC0[0], m_unkC0[1]);
        m_unkC0[0] = 0;
        m_unkC0[1] = 0;
    }
    if (m_unkB8[0] || m_unkB8[1]) {
        SOUND_PauseMultipleSounds(m_unkB8[0], m_unkB8[1]);
        m_unkB8[0] = 0;
        m_unkB8[1] = 0;
    }
    SendStops();
    static int incrementingRoomType;
    static char init;
    if (!init) {
        incrementingRoomType = 1;
        init = 1;
    }
    SetReverbByPosition((float *)&m_unk2E90);
    if (fst_bCheckFileTransfer) {
        SOUND_MakeSoundStreamRef();
        if (m_unk2E7C == 0xC8) {
            memset(fst_DataToEEBuffer, 0, 0xA000);
            fst_DataToEEBuffer[0] = 0x12345678;
            int a2 = SOUND_MakeSoundStreamRef();
            SOUND_DataDestEEDirect(2, 0xC0, a2, 0, 0x800, (unsigned int)fst_DataToEEBuffer, 0x800);
        }
    }
    if (fst_bUseSimulatedCDErrors && (unsigned int)m_unk2E7C % 0x4B0 == 0) {
        SOUND_SimulateCDError(*(int *)(gEng + 0x137A4));
    }
    FrameMaintenacePartA__7FileSysFv();
    PSoundFlushIOPCommandsWaitFinish();
    FrameMaintenacePartB__7FileSysFv();
    int a1 = m_unk18080;
    if (a1) {
        PlayEffect__6PSoundFUiUi(this, a1, m_unk18084);
        m_unk18080 = 0;
    }
    rA = SOUND_CD_TRAY_OPEN;
    rB = SOUND_IOP_CD_STATUS;
    return 1;
}

// FUNCTION: 0x001A5BF0 AmbientFadeToFree__6PSoundFPQ26PSound19AmbientChannelState
void PSound::AmbientFadeToFree(AmbientChannelState *pState) {
    m_unk0EC -= 1;
    m_unk0F0 += 1;
    return pState->ReInit();
}

// FUNCTION: 0x001A5C10 FadeAmbientChannel__6PSoundFPQ26PSound19AmbientChannelStateUi
void PSound::FadeAmbientChannel(AmbientChannelState *pState, unsigned int nChan) {
    if (pState != 0) {
        if (pState->m_unk00 != 0x3FFE) {
            short nSaved = pState->m_unk06;
            pState->ReInit();
            pState->m_unk00 = 0x3FFE;
            m_unk0EC += 1;
            AddChanToMultipleStops(nSaved);
            return;
        }
        CdsAssert("PSound.cpp", 0x1CB0, "0");
    }
}

// DRAFT: 0x001A5CB0 CalculatePositionalVolume__6PSoundFRfRfRfPCfUibUiPQ26PSound8SpotInfoUiUi
// note: compiles; the reconstructed flow matches the asm but the register and branch shapes differ (see fncmp)
void PSound::CalculatePositionalVolume(float &fA, float &fB, float &fC, const float *pPos, unsigned int nFlags, bool bFlag, unsigned int nHandle, SpotInfo *pSpot, unsigned int nArg1C, unsigned int nArg20) {
    float fDx = pPos[0] - m_unk2EA0;
    float fDz = pPos[2] - m_unk2EA8;
    float fAng = Round180__Ff(57.295776f * atan2f(-fDx, -fDz) - m_unk2EB0);
    float fDy = pPos[1] - m_unk2EA4;
    float fDist = sqrtf(fDx * fDx + fDy * fDy + fDz * fDz);

    if (fAng < -90.0f) {
        fAng = -(180.0f + fAng);
    } else if (!(fAng <= 90.0f)) {
        fAng = 180.0f - fAng;
    }
    ((fAng >= -90.0f && fAng <= 90.0f) ? (void)0 : CdsAssert("PSound.cpp", 0x1BF8, "fAlpha >= -90.0f && fAlpha <= 90.0f"));

    bool bNear = false;
    float fRange;
    if (fDist <= 15.0f) {
        fRange = 0.0f;
        bNear = true;
    } else {
        fRange = fDist - 15.0f;
    }

    float fRaw = 0.01f * (fRange * (float)(unsigned int)pSpot->m_unk14);
    if (pSpot->m_unk13 == 2) {
        fRaw = 0.01f * (fRaw * (float)(unsigned int)gPSndDbg[9]);
    }

    unsigned int nScale = nFlags;
    float fDen = 0.0f;
    bool bOverride = false;
    if (nArg20 & 0x40) {
        char *pChan = (char *)nArg1C;
        nScale = (nFlags * *(unsigned int *)(pChan + 0x11C)) / 1000;
        if (*(unsigned int *)(pChan + 0x120) & 1) {
            unsigned int nKind = *(unsigned int *)(pChan + 0x110);
            bOverride = true;
            if (nKind == 1) {
                fDen = *(float *)(pChan + 0x1C);
            } else if (nKind == 2) {
                fDen = *(float *)(pChan + 0x2C);
            } else {
                bOverride = false;
            }
        }
    }

    float fRatio;
    if (bOverride) {
        fRatio = fRaw / fDen;
    } else if (bFlag) {
        fRatio = fRaw / m_unk5C;
    } else {
        fRatio = fRaw / m_unk58;
    }

    float fT = 1.0f - fRatio;
    if (fT < 0.0f) {
        fT = 0.0f;
    }
    float fCurve = m_unk64 * fT * fT + m_unk60 * fT;
    if (fCurve < 0.003f) {
        fCurve = 0.003f;
    }
    if (!(fCurve <= 1.0f)) {
        fCurve = 1.0f;
    }

    float fOut = 0.001f * (fCurve * (float)nScale);
    if (nHandle == 2) {
        fOut = 0.001f * (float)nFlags;
    }
    if (fOut >= 1.0f) {
        fOut = bNear ? 1.0f : 0.9f;
    }
    ((fOut >= 0.0f) ? (void)0 : CdsAssert("PSound.cpp", 0x1C63, "fVol >= 0"));

    float fPan = fAng / 180.0f;
    ((fPan >= -1.0f && fPan <= 1.0f) ? (void)0 : CdsAssert("PSound.cpp", 0x1C69, "fPan >= -1.0f && fPan <= 1.0f"));

    float fLeft = fOut;
    float fRight = fOut;
    if (fAng < 0.0f) {
        fLeft = fOut * (1.0f + fPan);
    } else {
        fRight = fOut * (1.0f - fPan);
    }

    fA = fDist;
    fB = 1000.0f * fLeft;
    fC = 1000.0f * fRight;
}

// DRAFT: 0x001A6260 AdjustEffectVolumes__6PSoundFRUiRUiRfRf
// note: 5 words; the three flag compares use $v1/$a0 where the original uses $at. Tried: nested bLowA variant (5), no-local variant (5), ternary clamps (11), bool bLowA (5, diff moves to nB flag), unsigned bLowA (5), ternary-initialised bLowA (20+).
void PSound::AdjustEffectVolumes(unsigned int &nOutA, unsigned int &nOutB, float &fInA, float &fInB) {
    unsigned int nA = (unsigned int)fInA;
    unsigned int nB = (unsigned int)fInB;
    int bLowA = nA < 0x3E9U;
    if (m_unk30 != 0) {
        if (nA < nB) {
            nA = nB;
        } else {
            nB = nA;
        }
        bLowA = nA < 0x3E9U;
    }
    if (bLowA == 0) {
        nA = 0x3E8;
    }
    if (nB >= 0x3E9U) {
        nB = 0x3E8;
    }
    nOutA = nA;
    nOutB = nB;
}

// DRAFT: 0x001A6340 ProcessMusic__6PSoundFv
// note: 38 words; CSE of this+0x78 keeps row pointer in s0 across the call so this moves to s1 (orig keeps this in s0, frame 0x20 vs 0x30); blocking the CSE with separate row pointers in each block gave 57/64; 8 attempts used

int PSound::ProcessMusic() {
    unsigned int idx = m_unk28;
    if (idx < 2) {
        char *pRow = (char *)this + 0x78;
        int nHits = *(int *)(pRow + (idx << 5));
        if (nHits > 0 && gPSndDbg[10] != 0) {
            SOUND_MusicAddExciteHits(nHits);
        }
        char *pRow2 = (char *)this + 0x78;
        *(int *)(pRow2 + (m_unk28 << 5)) = 0;
    }
    if (m_unkCD != 0) {
        if (MODE_PAL != 0) {
            m_unkDC = m_unkDC - 20.0f;
        } else {
            m_unkDC = m_unkDC - 16.666666f;
        }
        if (m_unkDC < 0.0f) {
            m_unkCD = 0;
            if (m_unk1C != 0 && m_unk1C < 0x21) {
                m_unkCD = 0;
                MusicSwitchToPrimary(m_unkE0);
            }
        }
    }
    return 0;
}

// DRAFT: 0x001A6450 ProcessAmbientChannels__6PSoundFv
// note: first draft from m2c structure; not yet compared (asm uses a 0x80+ frame and hoisted channel end)

int PSound::ProcessAmbientChannels() {
    AmbientChannelState *s;
    AmbientChannelState *s2;
    AmbientChannelState *pChEnd;
    AmbientEntry *e;
    AmbientEntry *eHead;
    AmbientEntry *eNext;
    AmbientEntry *eA;
    AmbientEntry *eB;
    AmbientEntry *eSel;
    AmbientEntry *eTmp;
    unsigned int i;
    unsigned int nIdx;
    unsigned int nCnt;
    unsigned int nCur;
    unsigned int nLvl;
    unsigned int nAux;
    int k;
    int nHit;
    int nBest;
    int nDelta;
    float fA;
    float fB;
    float fC;
    float fD;
    float fE;
    unsigned int spF8;
    unsigned int spFC;
    float spF0;
    float spF4;
    float spE0;
    int nState;

    pChEnd = (AmbientChannelState *)((char *)this + 0xF8 + (m_unkE4 << 5));
    if (CheckAllChannelsMatch__6PSoundFv(this) < 0) {
        goto fail;
    }

    i = m_unk2E28;
    s = (AmbientChannelState *)&m_unkF8[0];
    while (m_unk2E2C >= i) {
        if ((unsigned int)s->m_unk00 >= 0x3FFD) {
            if (s->m_unk08 != 0) {
                ((s->m_unk08 == 0) ? (void)0 : CdsAssert("PSound.cpp", 0x19A9, "!pState2->mpAmbientEntryHead"));
            }
            if (s->m_unk1C != 0) {
                ((s->m_unk1C == 0) ? (void)0 : CdsAssert("PSound.cpp", 0x19AA, "!pState2->mpAmbientChannelStateNext"));
            }
            nIdx = m_unk2E28;
            s2 = (AmbientChannelState *)&m_unkF8[0];
            while (m_unk2E2C >= nIdx) {
                ((s != (AmbientChannelState *)s2->m_unk1C) ? (void)0 : CdsAssert("PSound.cpp", 0x19B0, "0"));
                nIdx += 1;
                s2 = (AmbientChannelState *)((char *)s2 + 0x20);
            }
        }
        i += 1;
        s = (AmbientChannelState *)((char *)s + 0x20);
    }

    if (CheckAllChannelsMatch__6PSoundFv(this) < 0) {
        goto fail;
    }

    e = (AmbientEntry *)((char *)this + 0x380);
    nCur = 0;
    do {
        if (e->m_unk10 != 0x3FFF) {
            if (e->m_unk48 != 0) {
                nLvl = ((SpotInfo *)e->m_unk48)->m_unk10;
                if (nLvl >= 0x65U) {
                    nLvl = 0x64;
                }
            } else {
                nLvl = 0x64;
                ((e->m_unk48 != 0) ? (void)0 : CdsAssert("PSound.cpp", 0x19D3, "0"));
            }
            if ((*((unsigned char *)e + 0x38) != 0) && (FadeMsecFloatUpdate__14PFadeMsecFloatFUi((void *)((char *)e + 0x20), m_unk6C), (*((unsigned char *)e + 0x38) == 0)) && (e->m_unk44 == 1)) {
                StopAmbientEntry(e, 0);
            } else {
                if (e->m_unk14 & 0x200) {
                    *(float *)&e->m_unk5C = 0.0f;
                    nDelta = (nLvl * 10 * m_unk48) / 1000;
                    *(float *)&e->m_unk64 = (float)nDelta;
                    *(float *)&e->m_unk60 = (float)nDelta;
                } else {
                    nAux = (nLvl * 10 * m_unk44) / 1000;
                    if (*((unsigned char *)e + 0x38) != 0) {
                        fA = (float)nAux * *(float *)((char *)e + 0x20);
                    }
                    if (GetOriginatorPos(&spE0, e->m_unk14 & 0xFFFF, e->m_unk1C, e->m_unk3C) >= 0) {
                        CalculatePositionalVolume(*(float *)&e->m_unk5C, *(float *)&e->m_unk60, *(float *)&e->m_unk64, &spE0, e->m_unk14 & 0xFFFF, *((unsigned char *)e + 0x38) != 0, e->m_unk1C, (SpotInfo *)e->m_unk48, e->m_unk3C, e->m_unk40);
                        if (e->m_unk16 & 3) {
                            *(float *)&e->m_unk60 = 0.0f;
                            *(float *)&e->m_unk64 = 0.0f;
                        }
                    } else {
                        StopAmbientEntry(e, 0);
                    }
                }
            }
        }
        nCur += 1;
        e = (AmbientEntry *)((char *)e + 0x70);
    } while (nCur < 0x47);

    i = m_unk2E28;
    s = (AmbientChannelState *)&m_unkF8[0];
    while (m_unk2E2C >= i) {
        if (SOUND_SPUKeyStatus[i] != 3 && SOUND_SPUKeyStatus[i] == 0) {
            if (s->m_unk00 != 0x3FFF) {
                nState = 0;
                if (s->m_unk00 == 0x3FFE) {
                    nState = 1;
                }
                if (nState != 0) {
                    AmbientFadeToFree(s);
                    s2 = (AmbientChannelState *)&m_unkF8[0];
                    *(int *)((char *)this + 0xEC) -= 1;
                    *(int *)((char *)this + 0xF0) += 1;
                    if ((char *)s2 < (char *)pChEnd) {
                        do {
                            ((s2 != (AmbientChannelState *)s2->m_unk1C) ? (void)0 : CdsAssert("PSound.cpp", 0x1A2A, "0"));
                            s2 = (AmbientChannelState *)((char *)s2 + 0x20);
                        } while ((char *)s2 < (char *)pChEnd);
                    }
                }
            }
        }
        i += 1;
        s = (AmbientChannelState *)((char *)s + 0x20);
    }

    if (CheckAllChannelsMatch__6PSoundFv(this) < 0) {
        goto fail;
    }

    s = (AmbientChannelState *)&m_unkF8[0];
    while ((char *)s < (char *)pChEnd) {
        if ((unsigned int)s->m_unk00 >= 0x3FFD) {
            goto next;
        }
        eHead = (AmbientEntry *)s->m_unk08;
        if (eHead == 0) {
            goto next;
        }
        VerifyAmbientEntryList(eHead);
        if (CheckOneChannelMatch__6PSoundFPQ26PSound19AmbientChannelState(this, s) < 0) {
            goto fail;
        }
        nCnt = s->m_unk14;
        nCur = s->m_unk10;
        if (nCnt == 0) {
            eSel = eHead;
            eA = eHead;
            k = 0;
            if (eHead != 0) {
                do {
                    eNext = eA->m_unk50;
                    if (eNext != 0) {
                        if (!(eA->m_unk5C <= eNext->m_unk5C)) {
                            if (eA == eHead) {
                                eSel = eNext;
                            }
                            if (k == (int)(nCur - 1)) {
                                nHit = eNext->m_unk18;
                                eNext->m_unk18 = eA->m_unk18;
                                eA->m_unk18 = nHit;
                                eNext->m_unk14 |= 8;
                                *((char *)eA + 0x6C) = 0;
                            }
                            SwapLinksAmbientEntry(eA, eNext);
                        }
                        eA = eNext;
                        k += 1;
                    }
                } while (eNext != 0);
            }
            s->m_unk08 = (int)eSel;
            eHead = eSel;
        } else {
            k = 0;
            while (k < (int)nCnt) {
                eB = eHead;
                eA = eHead;
                nBest = 0;
                while (eA != 0 && nBest < (int)(nCur - 1)) {
                    eNext = eB->m_unk50;
                    if (eNext != 0) {
                        if (!(eB->m_unk5C <= eNext->m_unk5C)) {
                            if (eB == eHead) {
                                eA = eNext;
                            }
                            SwapLinksAmbientEntry(eB, eNext);
                            eNext = eB;
                        }
                        eB = eNext;
                        nBest += 1;
                    } else {
                        break;
                    }
                }
                s->m_unk08 = (int)eA;
                eHead = eA;
                k += 1;
            }
        }
        s->m_unk08 = (int)eHead;
        VerifyAmbientEntryList(eHead);
        spF0 = 0.0f;
        nAux = 1;
        spF4 = 0.0f;
        nBest = 0;
        nHit = 0;
        nDelta = 0;
        if ((int)s->m_unk10 == 0) {
            CdsAssert("PSound.cpp", 0x1AE2, "uNActiveChannelsInChain >= 1");
        }
        eA = eHead;
        while (eA != 0 && nHit == 0) {
            eB = eA;
            break;
        }
        e = eHead;
        while (e != 0) {
            e = e->m_unk50;
        }
        VerifyAmbientEntryList(s->m_unk08 != 0 ? (AmbientEntry *)s->m_unk08 : 0);
        goto next;
next:
        s = (AmbientChannelState *)((char *)s + 0x20);
    }

    if (CheckAllChannelsMatch__6PSoundFv(this) >= 0) {
        return 0;
    }
fail:
    ErrorRecovery();
    return -1;
}

// DRAFT: 0x001A6D40 ProcessSFXChannels__6PSoundFv
// note: DIFF 117 words: frame 0xC0 vs 0xB0, sll s2 vs s0, key-table reloc (lui/addiu 0x4B3E50), lbu/lh register choice, assert+Init block order; tried unsigned char key and fPos moved into branch, no change
void PSound::ProcessSFXChannels() {
    unsigned int nOff = m_unk2E30 << 6;
    OneShotChannelState *pChan = (OneShotChannelState *)((char *)this + nOff + 0x2220);
    for (unsigned int nIdx = m_unk2E30; nIdx <= m_unk2E34; nIdx++, nOff += 0x40, pChan = (OneShotChannelState *)((char *)pChan + 0x40)) {
        float fPos[3];
        float fA, fB, fC;
        unsigned int nVolA, nVolB, nS5;
        if (pChan->m_unk2C != 0) {
            pChan->m_unk2C--;
        }
        int nKey = SOUND_SPUKeyStatus[nIdx];
        if (nKey == 0 && !(pChan->m_unk14 & 0x8000) && pChan->m_unk2C == 0) {
            pChan->Init();
            continue;
        }
        if (nKey == 1 || (pChan->m_unk14 & 0x8000)) {
            SpotInfo *pSpot = (SpotInfo *)pChan->m_unk28;
            if (pSpot == 0) {
                pChan->Init();
                continue;
            }
            if (pChan->m_unk10 != pSpot->m_unk00) {
                pChan->Init();
                continue;
            }
            ((pSpot) ? (void)0 : CdsAssert("PSound.cpp", 0x1929, "pSpot"));
            unsigned int nVol = (unsigned char)pSpot->m_unk10;
            if (nVol > 100) {
                nVol = 100;
            }
            if (pChan->m_unk14 & 0x200) {
                unsigned int nDiv = (unsigned int)(m_unk48 * (int)(nVol * 10)) / 1000u;
                if (nDiv >= 1001) {
                    nDiv = 1000;
                }
                nVolA = nDiv;
                nVolB = nDiv;
            } else {
                nS5 = (unsigned int)(m_unk44 * (int)(nVol * 10)) / 1000u;
                if (GetOriginatorPos(fPos, (unsigned short)pChan->m_unk14, pChan->m_unk18, pChan->m_unk1C) < 0) {
                    continue;
                }
                CalculatePositionalVolume(fA, fB, fC, fPos, nS5, false, pChan->m_unk10, pSpot, pChan->m_unk1C, pChan->m_unk20);
                AdjustEffectVolumes(nVolA, nVolB, fB, fC);
            }
            if (pChan->m_unk14 & 0x8000) {
                nS5 = TranslateIntoADSR((unsigned char)pSpot->m_unk12);
                SendStops();
                SOUND_PlaySFXRelVol(pChan->m_unk10, nIdx, nVolA, nVolB, nS5);
                pChan->m_unk2C = 3;
                if (pSpot != 0) {
                    int nPitch;
                    if ((unsigned short)pChan->m_unk16 == 0) {
                        nPitch = pSpot->PossiblyRandomPitch();
                    } else {
                        nPitch = (unsigned short)pChan->m_unk16;
                    }
                    SOUND_SetChannelPitch(nIdx, nPitch);
                }
            } else {
                SOUND_SetChanRelVol(nIdx, nVolA, nVolB);
            }
        }
        *(unsigned short *)((char *)this + nOff + 0x2234) &= 0x7FFF;
    }
}

// DRAFT: 0x001A7060 GetOriginatorPos__6PSoundFPfUiUiUi
// note: DIFF 56 (best of 4 variants: v1 69, v2 56, v3 58, v4 74); original shares an addiu v0,-1 delay-slot exit at the pSrc failure path, ours is one instruction longer.
int PSound::GetOriginatorPos(float *pOut, unsigned int nFlags, unsigned int nOriginator, unsigned int nNode) {
    if (nFlags & 0x10) {
        if (nOriginator != 0x80000000) {
            void *pOrig = ApparitionIsValid__15EntityBaseClassFUi(nOriginator);
            if (pOrig != 0) {
                int nSub = *(int *)((char *)pOrig + 0x3C);
                char *pSrc = (nSub != 0) ? ((char *)nSub + 0x80) : ((char *)pOrig + 0x190);
                if (pSrc != 0) {
                    memcpy(pOut, pSrc, 0x10);
                    return 0;
                }
            }
            return -1;
        }
        return 0;
    }
    if (nFlags & 0x20) {
        if (nOriginator == 0x80000000) {
            return 0;
        }
        float vLocal[4];
        if (nNode != 0 && GetWorldMeshCenter__6PMNodeFPf((void *)nNode, vLocal) >= 0) {
            *(u_long128 *)pOut = *(u_long128 *)vLocal;
            return 0;
        }
        return -1;
    }
    if (nFlags & 0x40) {
        if (nOriginator == 0x80000000) {
            return 0;
        }
        if (nNode != 0) {
            void *pWorld = GetWorldPos__20GameSoundTrigletPawnFv((void *)nNode);
            if (pWorld != 0) {
                memcpy(pOut, pWorld, 0x10);
                return 0;
            }
        }
        return -1;
    }
    return -1;
}

// FUNCTION: 0x001A7190 PlayEffect__6PSoundFUiUi
void PSound::PlayEffect(unsigned int nID, unsigned int nFlags) {
    PlaySoundApparition(nID, nFlags);
}

// FUNCTION: 0x001A71A0 PlaySoundNonPositional__6PSoundFUi
void PSound::PlaySoundNonPositional(unsigned int nID) {
    PlaySoundUbiquitous(nID);
}

// FUNCTION: 0x001A71B0 PlaySoundUbiquitous__6PSoundFUi
int PSound::PlaySoundUbiquitous(unsigned int nSound) {
    return PlaySoundWPitch(nSound, 0x80000000, 0, 0x200, 0);
}

// FUNCTION: 0x001A71D0 PlaySoundTrigletUbiquitous__6PSoundFUiUiPC20GameSoundTrigletPawn
int PSound::PlaySoundTrigletUbiquitous(unsigned int p0, unsigned int p1, const GameSoundTrigletPawn *pPawn) {
    if (pPawn != 0) {
        return PlaySoundWPitch(p0, p1, (unsigned int)pPawn, 0x240, 0);
    }
    return 0;
}

// FUNCTION: 0x001A7200 PlaySoundTriglet__6PSoundFUiUiPC20GameSoundTrigletPawn
int PSound::PlaySoundTriglet(unsigned int p0, unsigned int p1, const GameSoundTrigletPawn *pPawn) {
    if (pPawn == 0) {
        return 0;
    }
    if (gPSndDbg[51] != 0 && fst_StartMultiple == (int)p0) {
        PlayMultipleAtOnce(gPSndDbg[26]);
    }
    return PlaySoundWPitch(p0, p1, (unsigned int)pPawn, 0x40, 0);
}

// FUNCTION: 0x001A7290 PlaySoundPMNode__6PSoundFUiUiPC6PMNode
int PSound::PlaySoundPMNode(unsigned int p0, unsigned int p1, const PMNode *pNode) {
    if (pNode != 0) {
        return PlaySoundWPitch(p0, p1, (unsigned int)pNode, 0x20, 0);
    }
    return 0;
}

// DRAFT: 0x001A72D0 PlaySoundWPitch__6PSoundFUiUiUiUiUi
// note: 850 words; INCOMPLETE: the ambient channel-state search (spAC->unkC & 2) is missing and the distance check is simplified; frame 0x190 vs 0xE0. Needs the missing logic before tuning.
int PSound::PlaySoundWPitch(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4) {
    static unsigned int st_uLastIDOutOfRange;
    static signed char bInitIDOut;
    static unsigned int st_uLastVBCOutOfRange;
    static signed char bInitVBC;
    int nErr = 0;
    int bDbg = 0;
    int bInRange;
    unsigned int nSpot = p0;
    unsigned int nTable = 0;
    unsigned int nFlags = p3;
    unsigned int nOrigin = p1;
    unsigned int nPawn = p2;
    int nIdx = 0;
    SpotInfo *pSpot = 0;
    int *pUsage = 0;
    float vPos[4];

    if (!bInitIDOut) {
        bInitIDOut = 1;
        st_uLastIDOutOfRange = 0x12D687;
    }
    bInRange = p0 < 0x4E20U;
    if (!bInitVBC) {
        st_uLastVBCOutOfRange = 0;
        bInitVBC = 1;
        bInRange = p0 < 0x4E20U;
    }
    if (!bInRange && p0 < 0x4E74U) {
        nSpot = 0x3FFD;
        if (FindASubTableRandomItem__16PTranslateATableFPUiUiPFUi_iPCUi(&nTable, p0, SoundInBankStatus, gSndSetOfIDsTable) == 0) {
            nSpot = nTable;
        } else {
            nErr = 5;
        }
    }

    if (nErr == 0) {
        if (nSpot == 0) {
            nErr = 3;
        } else {
            pSpot = GetSpotInfo(nSpot);
            if (pSpot != 0 && (gPSndDbg[13] != 0 || gPSndDbg[14] != 0)) {
                nSpot = 0x3FFD;
            }
        }
    }
    if (nErr == 0) {
        if (nSpot == 0x3FFD) {
            nErr = 2;
        } else if (nSpot > 0x3FFD) {
            nErr = 3;
        } else if (pSpot == 0) {
            nErr = 4;
        }
    }

    if (nErr != 0) {
        if (gPSndDbg[15] != 0) {
            nSpot = 2;
            pSpot = GetSpotInfo(2);
            bDbg = 1;
        } else if (nErr == 3 && (st_uLastIDOutOfRange != nSpot || st_uLastVBCOutOfRange + 0x258 < (unsigned int)gCDSVBlankCount)) {
            st_uLastIDOutOfRange = nSpot;
            st_uLastVBCOutOfRange = gCDSVBlankCount;
        }
    }

    if (nErr == 0 || bDbg) {
        pUsage = UsageFind(nSpot);
        if (fst_bCalledByDebug == 0 && gPSndDbg[22] == 0 && pUsage != 0) {
            pUsage[1]++;
        }
        CheckAllChannelsMatch__6PSoundFv(this);

        if (nOrigin == 0x80000000U) {
            nFlags = 0x200;
        } else if ((nFlags & 0x70) == 0x30) {
            nErr = 8;
        } else if (nFlags & 0x10) {
            if (nOrigin == 0 || ApparitionIsValid__15EntityBaseClassFUi(nOrigin) == 0) {
                nErr = 6;
            }
        } else if (nFlags & 0x20) {
            if (nOrigin == 0 || nPawn == 0) {
                nErr = 6;
            } else if (nOrigin != *(unsigned int *)((char *)nPawn + 0xE8)) {
                nErr = 6;
            }
        } else if (nFlags & 0x40) {
            if (nPawn == 0) {
                nErr = 6;
            }
        } else {
            nErr = 9;
        }

        if (nErr == 0) {
            if (nFlags & 0x70) {
                if (GetOriginatorPos(vPos, nFlags, nOrigin, p4) < 0) {
                    nErr = 7;
                } else if (nSpot != 0x82 && fst_PSWP_bUseDistCheck) {
                    float fDist = vPos[0] * vPos[0] + vPos[1] * vPos[1] + vPos[2] * vPos[2];
                    if (!(fDist <= fst_PSWP_fDistCheckRadSq)) {
                        nErr = 0xC;
                    }
                }
            }
        }

        if (nErr == 0) {
            // SPU fallback only; the ambient channel-state search (unkC & 2) is not written yet.
            SOUND_CountFreeSPUChannels(m_unk2E28, m_unk2E2C);
            nIdx = SOUND_FindFreeSPUChannel(m_unk2E30, m_unk2E34, m_unk2E40, 0);
            if (nIdx >= 0) {
                *(unsigned int *)((char *)this + nIdx * 0x40 + 0x2220) = p0;
            }
            CheckAllChannelsMatch__6PSoundFv(this);
            *(int *)((char *)this + 0xC) = 0;
            return nIdx;
        }
    }

    if (pUsage != 0) {
        if (nErr == 0xC) {
            pUsage[3]++;
        } else if (nErr == 4) {
            pUsage[4]++;
        } else {
            pUsage[2]++;
        }
    }
    *(int *)((char *)this + 0xC) = nErr;
    *(int *)((char *)this + 0x8) = nErr;
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

// FUNCTION: 0x001A8090 IsObjectPlayingAmbientByID__6PSoundFUiUiUi
int PSound::IsObjectPlayingAmbientByID(unsigned int nID, unsigned int nOriginator, unsigned int nFlags) {
    if (IsAmbientSoundByID(nID) == 0) {
        return 0;
    }
    if (nOriginator != 0) {
        if (nOriginator != 0x80000000) {
            AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
            AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
            if (pEntry < pEnd) {
                do {
                    if (nOriginator == pEntry->m_unk1C && ((unsigned short)pEntry->m_unk14 & nFlags) && nID == pEntry->m_unk10) {
                        return 1;
                    }
                    pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
                } while (pEntry < pEnd);
            }
        }
    }
    return 0;
}

// FUNCTION: 0x001A8150 StopSoundsByOriginatorRef__6PSoundFUiUiUi
int PSound::StopSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nArg1, unsigned int nFlags) {
    CheckAllChannelsMatch();
    int nStopped = 0;
    if (nOriginator != 0 && nOriginator != 0x80000000) {
        if (nFlags & 2) {
            nStopped = StopAmbientSoundsByOriginatorRef(nOriginator, nArg1);
        }
        if (nFlags & 1) {
            unsigned int i = m_unk2E30;
            char *pEnt = (char *)this + (i << 6) + 0x2220;
            for (; m_unk2E34 >= i; i++, pEnt += 0x40) {
                if (nOriginator == *(unsigned int *)(pEnt + 0x18)) {
                    StopOneShot(i);
                    nStopped++;
                }
            }
        }
    }
    CheckAllChannelsMatch();
    return nStopped;
}

// FUNCTION: 0x001A8230 StopAmbientSoundsByOriginatorRef__6PSoundFUiUi
int PSound::StopAmbientSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nFlags) {
    int nCount = 0;
    if (nOriginator != 0) {
        if (nOriginator != 0x80000000) {
            AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
            AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
            if (pEntry < pEnd) {
                do {
                    if (nOriginator == pEntry->m_unk1C && ((unsigned short)pEntry->m_unk14 & nFlags)) {
                        StartAESoftwareFadeout(pEntry, 0);
                        nCount++;
                    }
                    pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
                } while (pEntry < pEnd);
            }
        }
    }
    return nCount;
}

// FUNCTION: 0x001A82F0 DebugStopAllSoundsBySoundID__6PSoundFUi
int PSound::DebugStopAllSoundsBySoundID(unsigned int nArg) {
    int nCount;
    unsigned int nIdx;
    char *pEnt;
    CheckAllChannelsMatch();
    nCount = DebugStopAmbientSoundsBySoundID(nArg);
    nIdx = m_unk2E30;
    pEnt = (char *)this + (nIdx << 6) + 0x2220;
    for (; m_unk2E34 >= nIdx; nIdx++, pEnt += 0x40) {
        if (nArg == *(unsigned int *)(pEnt + 0x10)) {
            StopOneShot(nIdx);
            nCount++;
        }
    }
    CheckAllChannelsMatch();
    return nCount;
}

// FUNCTION: 0x001A83B0 DebugStopAmbientSoundsBySoundID__6PSoundFUi
int PSound::DebugStopAmbientSoundsBySoundID(unsigned int nSound) {
    int nCount = 0;
    AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
    AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
    if (pEntry < pEnd) {
        do {
            if (nSound == pEntry->m_unk10 && ((unsigned short)pEntry->m_unk14 & 0x800)) {
                StopAmbientEntry(pEntry, 0);
                nCount++;
            }
            pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
        } while (pEntry < pEnd);
    }
    return nCount;
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

// FUNCTION: 0x001A84B0 ResumeAmbientSoundsByOriginatorRef__6PSoundFUiUi
int PSound::ResumeAmbientSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nFlags) {
    int nCount = 0;
    if (nOriginator != 0) {
        if (nOriginator != 0x80000000) {
            AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
            AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
            if (pEntry < pEnd) {
                do {
                    if (nOriginator == pEntry->m_unk1C && ((unsigned short)pEntry->m_unk14 & nFlags)) {
                        ResumeAmbientEntry(pEntry);
                        nCount++;
                    }
                    pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
                } while (pEntry < pEnd);
            }
        }
    }
    return nCount;
}

// FUNCTION: 0x001A8560 PauseAmbientSoundsByOriginatorRef__6PSoundFUiUi
int PSound::PauseAmbientSoundsByOriginatorRef(unsigned int nOriginator, unsigned int nFlags) {
    int nCount = 0;
    if (nOriginator != 0) {
        if (nOriginator != 0x80000000) {
            AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
            AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
            if (pEntry < pEnd) {
                do {
                    if (nOriginator == pEntry->m_unk1C && ((unsigned short)pEntry->m_unk14 & nFlags)) {
                        PauseAmbientEntry(pEntry, 0);
                        nCount++;
                    }
                    pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
                } while (pEntry < pEnd);
            }
        }
    }
    return nCount;
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

// FUNCTION: 0x001A8660 PauseAmbientEntry__6PSoundFPQ26PSound12AmbientEntryUi
int PSound::PauseAmbientEntry(AmbientEntry *pEntry, unsigned int nFlag) {
    if (pEntry == 0) {
        return 0;
    }
    if (pEntry->m_unk10 > 0x3FFC) {
        return 0;
    }
    pEntry->m_unk16 |= 1;
    return 0;
}

// FUNCTION: 0x001A86A0 ResumeAllAmbientSounds__6PSoundFv
int PSound::ResumeAllAmbientSounds() {
    int nCount = 0;
    AmbientEntry *pEntry = (AmbientEntry *)((char *)this + 0x380);
    AmbientEntry *pEnd = (AmbientEntry *)((char *)this + 0x2220);
    if (pEntry < pEnd) {
        do {
            unsigned short nFlags = pEntry->m_unk16;
            if (nFlags & 2) {
                nFlags = nFlags & 0xFFFD;
                pEntry->m_unk16 = nFlags;
                short nChan = pEntry->m_unk18;
                if (nChan >= 0 && *((unsigned char *)this + nChan + 0x1808C) != 0 && !(nFlags & 2)) {
                    nCount++;
                    AddChanToMultipleResumes(nChan);
                }
            }
            pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
        } while (pEntry < pEnd);
    }
    return nCount;
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
// note: 15 words differ; original keeps &m_unkC0[idx] in a2, ours spills it to t0 and computes this+idx*4 before adding 0xC0; lui at,1 fills the beqz slot in the original. Applied `nBit & *pWord` (17 to 16) and pWord declared before nBit (16 to 15). Flag store as this+nChan+0x1808C stays 15. Earlier tried: indexed form, shift-in-branch, if/else split, 1u literal, m_unkC0 + nIdx pointer, flag-base pointer (all 15 or worse).
int PSound::AddChanToMultipleResumes(unsigned int nChan) {
    int nRet = 0;
    unsigned int nIdx = 0;
    unsigned int nShift = nChan;
    if (nChan >= 0x18) {
        nShift -= 0x18;
        nIdx = 1;
    }
    unsigned int *pWord = &m_unkC0[nIdx];
    unsigned int nBit = 1u << nShift;
    if (nBit & *pWord) {
        nRet = -1;
    }
    *pWord |= nBit;
    *((char *)this + 0x1808C + nChan) = 0;
    return nRet;
}

// DRAFT: 0x001A8850 AddChanToMultiplePauses__6PSoundFUi
// note: 14 words differ; index*4 scaled before the shift, base 0xB8 added to a register, and the flag store uses a2 for the constant (original uses a0). Applied `nBit & *pWord` and pWord before nBit (16 to 14). Unsigned nIdx stays 14. Earlier tried: indexed, pointer, shift-in-var, flag-base pointer, base-cast pointer (14 to 18).
int PSound::AddChanToMultiplePauses(unsigned int nChan) {
    int nRet = 0;
    int nIdx = 0;
    unsigned int nShift = nChan;
    if (nChan >= 0x18) {
        nShift -= 0x18;
        nIdx = 1;
    }
    unsigned int *pWord = (unsigned int *)((char *)this + 0xB8) + nIdx;
    unsigned int nBit = 1u << nShift;
    if (nBit & *pWord) {
        nRet = -1;
    }
    *pWord |= nBit;
    *((char *)this + 0x1808C + nChan) = 1;
    return nRet;
}

// DRAFT: 0x001A88C0 AddChanToMultipleStops__6PSoundFUi
// note: 15 words differ; same shape as AddChanToMultiplePauses with base 0xB0 and a 0 flag store. Applied `nBit & *pWord` and pWord before nBit (17 to 15). Residual: pointer register choice and the this+idx*4 scaling order, as in Resumes.
int PSound::AddChanToMultipleStops(unsigned int nChan) {
    int nRet = 0;
    unsigned int nIdx = 0;
    unsigned int nShift = nChan;
    if (nChan >= 0x18) {
        nShift -= 0x18;
        nIdx = 1;
    }
    unsigned int *pWord = (unsigned int *)((char *)this + 0xB0) + nIdx;
    unsigned int nBit = 1u << nShift;
    if (nBit & *pWord) {
        nRet = -1;
    }
    *pWord |= nBit;
    *((char *)this + 0x1808C + nChan) = 0;
    return nRet;
}

// FUNCTION: 0x001A8930 StopSoundBySoundRef__6PSoundFUi
int PSound::StopSoundBySoundRef(unsigned int nSoundRef) {
    if (nSoundRef != 0) {
        AmbientEntry *pEntry = FindAmbientEntry(nSoundRef);
        if (pEntry != 0) {
            StartAESoftwareFadeout(pEntry, 0);
            return 1;
        }
        char *pEnt = (char *)this + (m_unk2E30 << 6) + 0x2220;
        for (unsigned int i = m_unk2E30; i <= m_unk2E34; i++, pEnt += 0x40) {
            if (*(unsigned int *)(pEnt + 0x24) == nSoundRef) {
                StopOneShot(i);
                return 1;
            }
        }
    }
    return 0;
}

// FUNCTION: 0x001A89E0 FindAmbientEntry__6PSoundFUi
PSound::AmbientEntry *PSound::FindAmbientEntry(unsigned int nID) {
    AmbientEntry *pEntry;
    AmbientEntry *pEnd;
    if (nID != 0) {
        pEntry = (AmbientEntry *)(m_unkF8 + (0x380 - 0xF8));
        pEnd = (AmbientEntry *)(m_unkF8 + (0x2220 - 0xF8));
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

// FUNCTION: 0x001A8A30 IsAmbientSoundBySoundRef__6PSoundFUi
int PSound::IsAmbientSoundBySoundRef(unsigned int nSoundRef) {
    AmbientEntry *pEntry;
    AmbientEntry *pEnd;
    if (nSoundRef != 0) {
        pEntry = (AmbientEntry *)(m_unkF8 + (0x380 - 0xF8));
        pEnd = (AmbientEntry *)(m_unkF8 + (0x2220 - 0xF8));
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

// DRAFT: 0x001A8B80 StartAESoftwareFadeout__6PSoundFPQ26PSound12AmbientEntryUi
// note: 53 words differ; nCount in v0 instead of s4 (orig bFound is a bool, daddiu 1), no top guard before the loop; tried do-while, while, for, declaration-at-use, pointer-split, reorder (while 57, for 57, split 55), bool bFound with test (53), bool without test (60)
int PSound::StartAESoftwareFadeout(AmbientEntry *pEntry, unsigned int nArg) {
    int bFound = 0;
    int nRet;
    AmbientEntry *pNode;
    char *pACSMain;
    AmbientEntry *pHead;

    if (pEntry == 0) {
        CdsAssert("PSound.cpp", 0x1169, "0");
        return -1;
    }
    pACSMain = (char *)pEntry->m_unk4C;
    if (pACSMain == 0) {
        CdsAssert("PSound.cpp", 0x1174, "pACSMain");
    }
    if (pACSMain == 0) {
        return -1;
    }
    pHead = *(AmbientEntry **)(pACSMain + 8);
    if (pHead == 0) {
        CdsAssert("PSound.cpp", 0x117A, "pAEHead");
    }
    VerifyAmbientEntryList(pHead);
    if (pACSMain == 0 || pHead == 0) {
        return -1;
    }
    int nCount = 0;
    pNode = pHead;
    do {
        nCount += 1;
        if (pNode == pEntry) {
            bFound = 1;
        }
        pNode = pNode->m_unk50;
    } while (pNode != 0);
    if (bFound == 0) {
        CdsAssert("PSound.cpp", 0x118B, "bFound");
        return -1;
    }
    nRet = 0;
    if (nCount < 2) {
        nRet = StopAmbientEntry(pEntry, nArg);
    } else {
        int nIdx = 1;
        if (pEntry->m_unk48 != 0) {
            nIdx = ((unsigned char *)pEntry->m_unk48)[0x12] & 0xF;
        }
        FadeMsecFloatPrep__14PFadeMsecFloatFffUiUi(pEntry->m_unk20, 1.0f, 0.0f, m_unk6C, fst_ADSR_Msecs_Release[nIdx]);
        pEntry->m_unk44 = 1;
    }
    return nRet;
}

// DRAFT: 0x001A8D30 StopAmbientEntry__6PSoundFPQ26PSound12AmbientEntryUi
// note: DIFF 151 words (85 with the wrong two-argument ApparitionIsValid; the original passes only a0); this/pEntry/nFlag in s2/s1/s0 vs original s1/s0/s6, so the walk and 0x1808C index differ; if-form asserts kept (ternary form 141, reordered locals 117)
int PSound::StopAmbientEntry(PSound::AmbientEntry *pEntry, unsigned int nFlag) {
    PSound::AmbientChannelState *pState;
    char *pAcs;
    PSound::AmbientEntry *pHead;
    PSound::AmbientEntry *pCur;
    PSound::AmbientEntry *pNextHead;
    short nVol;
    int bFound;
    int bNeedCh;
    int nRet;
    unsigned int nUnset;

    if (pEntry == 0) {
        CdsAssert("PSound.cpp", 0x10D0, "0");
        return -1;
    }
    pAcs = (char *)pEntry->m_unk4C;
    if (pAcs == 0) {
        CdsAssert("PSound.cpp", 0x10DF, "pACSMain");
    }
    if (pAcs == 0) {
        return -1;
    }
    pHead = *(PSound::AmbientEntry **)(pAcs + 8);
    if (pHead == 0) {
        CdsAssert("PSound.cpp", 0x10E8, "pAEHead");
    }
    VerifyAmbientEntryList(pHead);
    if (pAcs == 0 || pHead == 0) {
        return -1;
    }
    nVol = pEntry->m_unk18;
    pNextHead = pHead->m_unk50;
    bFound = 0;
    pState = 0;
    CheckAllChannelsMatch();
    pCur = pHead;
    if (pCur != 0) {
        while (1) {
            if (pCur == pEntry) {
                bFound = 1;
                break;
            }
            pCur = pCur->m_unk50;
            if (pCur == 0) {
                break;
            }
        }
    }
    if (bFound != 0) {
        if (nVol >= 0) {
            pCur = pEntry->m_unk50;
            bNeedCh = 1;
            if (pCur != 0) {
                while (1) {
                    if (pCur->m_unk18 < 0) {
                        pCur->m_unk18 = nVol;
                        bNeedCh = 0;
                        pCur->m_unk14 |= 8;
                        break;
                    }
                    pCur = pCur->m_unk50;
                    if (pCur == 0) {
                        break;
                    }
                }
            }
            if (bNeedCh != 0) {
                DelinkChannelState(&pState, pEntry);
                if (pEntry->m_unk14 & 0x4000) {
                    if (pState != 0) {
                        pState->ReInit();
                        *(&m_unk1808C + nVol) = 0;
                    }
                    m_unk0F0 += 1;
                } else {
                    FadeAmbientChannel(pState, nFlag);
                }
            }
        }
        DelinkAmbientEntry(pEntry);
        AddAEToFreeList(pEntry);
        if (pEntry == pHead && pEntry->m_unk4C != 0) {
            *(PSound::AmbientEntry **)((char *)pEntry->m_unk4C + 8) = pNextHead;
        }
        nRet = 0;
        if (pEntry->m_unk4C != 0) {
            VerifyAmbientEntryList(*(PSound::AmbientEntry **)((char *)pEntry->m_unk4C + 8));
            nRet = 0;
        }
    } else {
        nRet = 1;
        ApparitionIsValid__15EntityBaseClassFUi((unsigned int)pEntry->m_unk1C);
    }
    CheckAllChannelsMatch();
    return nRet;
}

// FUNCTION: 0x001A8FA0 GetSpotInfo__6PSoundFUi
PSound::SpotInfo *PSound::GetSpotInfo(unsigned int nID) {
    SpotInfo *p = (SpotInfo *)m_unk2EB4;
    SpotInfo *pEnd = p + 400;
    SpotInfo *pFound = 0;
    for (; p < pEnd; p++) {
        if (nID == p->m_unk00) {
            pFound = p;
            break;
        }
    }
    return pFound;
}

// FUNCTION: 0x001A8FE0 SetLevelParameters__6PSoundFUiUiUiUi
int PSound::SetLevelParameters(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3) {
    int nRet = 0;
    if (SetStandardSecondaryMusicFileID(p0) < 0) {
        nRet = -1;
    }
    SetPositionalRangeOneshot(p1);
    SetPositionalRangeAmbient(p2);
    SetDistLinearPercent(p3);
    m_unkD4 = *(int *)(gEng + 0x19A80);
    m_unkD8 = *(int *)(gEng + 0x137A4);
    return nRet;
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

// FUNCTION: 0x001A91A0 SetMonoOut__6PSoundFb
void PSound::SetMonoOut(bool bMono) {
    if ((unsigned int)m_unk30 != (unsigned int)bMono) {
        m_unk30 = bMono;
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

// DRAFT: 0x001A9250 SetDistLinearPercent__6PSoundFUi
// note: DIFF 12; nPercent/this swapped (original nPercent=s0, this=s1; ours the reverse), gPSndDbg store and swc1 offsets follow. Tried: ternary assert, hoisted fScale (0x3C23D70A before the sign test, matches), plain cast, store-first order (22), local copy of nPercent (12), local PSound* alias for this (12).
void PSound::SetDistLinearPercent(unsigned int nPercent) {
    float fScale = 0.01f;
    ((nPercent < 0x65) ? (void)0 : CdsAssert("PSound.cpp", 0x100F, "i_distLinearPercent <= 100"));
    gPSndDbg[17] = nPercent;
    m_unk60 = fScale * (float)nPercent;
    m_unk64 = 1.0f - m_unk60;
}

// FUNCTION: 0x001A9300 SetUbiquitousFactorRelVol__6PSoundFUi
void PSound::SetUbiquitousFactorRelVol(unsigned int nFactor) {
    gPSndDbg[8] = nFactor;
    m_unk48 = nFactor * 10;
    InternalUpdateRelVolumes();
}

// FUNCTION: 0x001A9320 SetPositionalFactorRelVol__6PSoundFUi
void PSound::SetPositionalFactorRelVol(unsigned int nFactor) {
    gPSndDbg[7] = nFactor;
    m_unk44 = nFactor * 10;
    InternalUpdateRelVolumes();
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
// note: 3 words after permuter (spelling from build/permuter/001A9470/best.cpp). Earlier: DIFF 12; the second loop increment (addiu s1) lands in the bnez delay slot, original keeps slti/bnez/nop. Tried for-loop, offset-bounded while, reordered increments, unsigned counters; none closed the gap.
void PSound::StopMusic() {
    SOUND_StopAllMusic();
    unsigned char i = 0;
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
// note: 24 words differ; original builds table as sll; addiu v0,s1,0x70; addu; lw 0, one insn more than ours, which folds 0x70 into the lw offset, so later branches are one word off. Tried m_unk70[idx][0], char* table+idx<<5, pSlot struct, pBase+=0x70, int nRet=-1, separate char* pTable base, precomputed nOff local (all 24)
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

// FUNCTION: 0x001A95A0 FadeMusicOnStream__6PSoundFUiUiUi
void PSound::FadeMusicOnStream(unsigned int nStream, unsigned int nArg, unsigned int nFrames) {
    if (nStream < 2) {
        unsigned int n = nFrames;
        if (n > 0x64) {
            n = 0x64;
        }
        int ticks = n * 10;
        SOUND_FadeMusicStream(nStream, nArg, ticks, n);
        char *pState = (char *)this + (nStream << 5);
        int *pTicks = (int *)(pState + 0x7C);
        *pTicks = ticks;
        MusicStreamState *pMusic = (MusicStreamState *)(pState + 0x70);
        if (ticks == 0) {
            pMusic->ReInit();
        }
    }
}

// DRAFT: 0x001A9630 FadeOutAllMusic__6PSoundFUi
// note: DIFF 10 words; the loop increment `addiu s2,0x20` sits before the slti in the original (with a nop in the bnez slot), ours moves it into the slot. Tried: do-while, for with increment in header or body, while, swapped increment order (all 10). The 0.8333f * (float)n form matches the float path; SOUND_FadeOutAllMusic takes int.
void PSound::FadeOutAllMusic(unsigned int nArg) {
    unsigned int n = nArg;
    if (MODE_PAL != 0) {
        float t = 0.8333333f * (float)n;
        n = (unsigned int)t;
    }
    SOUND_FadeOutAllMusic(n);
    int i = 0;
    int off = 0;
    while (i < 2) {
        ((MusicStreamState *)((char *)this + off + 0x70))->ReInit();
        i++;
        off += 0x20;
    }
}

// FUNCTION: 0x001A9720 PlayMusicOnStream__6PSoundFUiUiUi
int PSound::PlayMusicOnStream(unsigned int arg0, unsigned int arg1, unsigned int arg2) {
    if (arg2 > 100U) {
        arg2 = 100;
    }
    if (arg0 < 2U && arg1 < 0x21U) {
        unsigned int *pState = m_unk70[arg0];
        pState[0] = arg1;
        if (arg1 == 0) {
            SOUND_StopStream(arg0);
            return 1;
        }
        unsigned int nVol = arg2 * 10;
        pState[3] = nVol;
        pState[1] = SOUND_MakeSoundStreamRef();
        if (gbMusic == 0) {
            return 1;
        }
        if (arg1 >= 3U) {
            SOUND_PlayMusicRelVol(arg0, arg1, pState[1], nVol, 0);
        }
        return 1;
    }
    return 0;
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

// DRAFT: 0x001A9880 LoadPrimarySoundBank__6PSoundFUi
// note: DIFF 92 words; size 0x248 vs 0x24C; this/nArg in s1/s0 vs s2/s1; loop condition tail order and gp/lui global forms at 0x0144 differ; local order and nArg copy tried, no change
int PSound::LoadPrimarySoundBank(unsigned int nArg) {
    unsigned int nDone;
    unsigned int nCount;
    unsigned int nValue;
    unsigned int nIdx;
    unsigned int nId;
    char *pSrc;
    char *pDst;

    if (nArg < 0x64 || nArg >= 0x73) {
        return 0;
    }
    if (nArg == m_unk10) {
        return 1;
    }
    SOUND_TRANSFER_DATA_BLOCK_TO_EE_STATUS = 1;
    SOUND_SetSPUWriteAddress(0x50010);
    memset(fst_GeneralBuf + 0x2100, 0, 0x2698);
    memset(stADPCM_SpotFXArrayCurrent + 0x5B10, 0, 0x2580);
    SOUND_TransferSFX(nArg, 0, fst_GeneralBuf + 0x2100, 0x2698);
    nDone = 0;
    for (nCount = 0; !nDone || SOUND_STREAM_ON[0] != 0 || SOUND_TRANSFER_DATA_BLOCK_TO_EE_STATUS != 0; nCount++) {
        WaitOnVSync();
        SOUND_GetStatus(-1, 0);
        PSoundFlushIOPCommandsWaitFinish();
        SOUND_CopyIOPBuffer();
        nDone = 0;
        nValue = 0;
        if (((unsigned int *)(fst_GeneralBuf + 0x2100))[1] < 0x191) {
            nValue = *(unsigned int *)(fst_GeneralBuf + 0x2120 + ((unsigned int *)(fst_GeneralBuf + 0x2100))[1] * 0x18);
        }
        if (((unsigned int *)(fst_GeneralBuf + 0x2100))[0] != 0 && ((unsigned int *)(fst_GeneralBuf + 0x2100))[1] != 0 && nValue != 0) {
            nDone = 1;
        }
    }
    ((SOUND_SFX_TRANSFER_END != 1) ? (void)0 : CdsAssert("PSound.cpp", 0xDE6, "SOUND_SFX_TRANSFER_END != 1"));
    if (SOUND_SFX_TRANSFER_END == 2) {
        return 0;
    }
    m_unk10 = nArg;
    memset(m_unk2EB4, 0, 0x2580);
    m_unk14 = 0;
    pSrc = fst_GeneralBuf + 0x2120;
    pDst = m_unk2EB4;
    for (nIdx = 0; nIdx < 0x190; nIdx++) {
        nId = *(unsigned int *)pSrc;
        if (nId == 0 || nId >= 0x3FFD) {
            break;
        }
        m_unk14++;
        UsageAdd(nId);
        memcpy(pDst, pSrc, 0x18);
        pSrc += 0x18;
        pDst += 0x18;
    }
    if (m_unk14 < 0x190) {
        *(int *)(m_unk2EB4 + m_unk14 * 0x18) = -1;
    }
    return 1;
}

// FUNCTION: 0x001A9AE0 EnableLevelProcessing__6PSoundFb
void PSound::EnableLevelProcessing(bool bEnable) {
    EnableProcessTriglets(bEnable);
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

// FUNCTION: 0x001A9B90 ReturnControlOfIOPToMjln__6PSoundFv
void PSound::ReturnControlOfIOPToMjln() {
    LoadingHangCheckInit__9FileUtilsFv();
    while (1) {
        if (sceCdSync(0x11) == 0) {
            break;
        }
        LoadingDisplay__9InterfaceFUii(gInterface, 0, 0);
    }
    LoadingHangCheckInit__9FileUtilsFv();
    SetEEControlOfIOP(1);
    m_unkD1 = 1;
    do {
        LoadingDisplay__9InterfaceFUii(gInterface, 0, 0);
        GetEEControlStatus();
    } while (gSOUND_EEControl != 0);
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

// FUNCTION: 0x001A9E10 RestartSuffix__6PSoundFv
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
    return 1;
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

// FUNCTION: 0x001AA070 PSoundDestroyLevel__6PSoundFv
void PSound::PSoundDestroyLevel() {
    PSoundLevelClear();
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

// DRAFT: 0x001AA1F0 PSoundReInitRegularSounds__6PSoundFv
// note: 59 words differ: gPSndDbg addend (ours lui 0 + 0x44, original lui 0x24 + 0x7C44), sltu operand order, pShotEnd register (original s1), store order around memset.
void PSound::PSoundReInitRegularSounds() {
    AmbientEntry *pPrev;
    AmbientEntry *pEntry;
    AmbientEntry *pEnd;
    AmbientChannelState *pChan;
    OneShotChannelState *pShot;
    OneShotChannelState *pShotEnd;
    short nIdx;

    m_unkE4 = (m_unk2E2C - m_unk2E28) + 1;
    m_unk0F0 = m_unkE4;
    m_unk0EC = 0;
    m_unkF4 = 0;
    pEntry = (AmbientEntry *)((char *)this + 0x380);
    pEnd = (AmbientEntry *)((char *)this + 0x2220);
    m_unkF4 = pEntry;
    pPrev = 0;
    if (pEntry < pEnd) {
        do {
            pEntry->Init();
            pEntry->m_unk54 = pPrev;
            pEntry->m_unk50 = pEntry + 1;
            pPrev = pEntry;
            pEntry = (AmbientEntry *)((char *)pEntry + 0x70);
        } while (pEntry < pEnd);
    }
    pPrev->m_unk50 = 0;

    pChan = (AmbientChannelState *)m_unkF8;
    for (nIdx = (short)m_unk2E28; m_unk2E2C >= nIdx; nIdx += 1) {
        pChan->Init();
        pChan->m_unk06 = nIdx;
        pChan++;
    }

    pShot = (OneShotChannelState *)((char *)this + 0x2220);
    pShotEnd = (OneShotChannelState *)((char *)this + 0x2E20);
    if (pShot < pShotEnd) {
        do {
            pShot->Init();
            pShot++;
        } while (pShot < pShotEnd);
    }

    m_unk0C = 0;
    m_unk08 = 0;
    m_unkB0 = 0;
    m_unkB4 = 0;
    m_unkB8[0] = 0;
    m_unkB8[1] = 0;
    memset(&m_unk1808C, 0, 0x30);
    m_unk2E40 = 0;
    m_unk543C = 0;
    m_unk5440 = 0;
    m_unk2E48 &= ~0x80;
    m_unk2E4C = m_unk2E48;
    DebugRestartValues();
    SetDistLinearPercent(gPSndDbg[17]);
    SetPositionalRangeOneshot(gPSndDbg[18]);
    SetPositionalRangeAmbient(gPSndDbg[19]);
}

// FUNCTION: 0x001AA3A0 PSoundReInitSub__6PSoundFUi
void PSound::PSoundReInitSub(unsigned int nMode) {
    fst_bCalledByDebug = 0;
    m_unk68 = 0;
    m_unk6C = 0;
    PSoundLevelClear();
    PSoundReInitMusic();
    StopAllSounds();
    SOUND_AllChannelReverbOff(0);
    SOUND_AllChannelReverbOff(1);
    SOUND_ReverbSetAdrs(0x1FFFFF, 0x1DFFFF);
    memcpy(fst_ReverbRecProposed, fst_ReverbRecOff, 0x14);
    memcpy(fst_ReverbRecCur, fst_ReverbRecOff, 0x14);
    if (nMode != 0) {
        SOUND_ClearIOPBuffer();
    }
    memset(&m_unk1808C, 0, 0x30);
    m_unk00 = 0;
    m_unkCE = 0;
    m_unkD1 = 1;
    m_unk2E74 = 0;
    gSOUND_EEControlReq = 0;
    gSOUND_EEControlReqCallCnt = 0;
}

// FUNCTION: 0x001AA490 __dt__6PSoundFv
PSound::~PSound() {
}

// DRAFT: 0x001AA4E0 __ct__6PSoundFv
// note: DIFF 131 words; loop 1 tail lacks the nop between sltu and bnez, loop 6 pointer register (s2 vs s1), m_unk79F8 store form; unsigned-cast loop end and float block tried, no change
PSound::PSound() {
    char *pElem;

    pElem = (char *)this + 0x70;
    do {
        __ct__Q26PSound16MusicStreamStateFv(pElem);
        pElem += 0x20;
    } while (pElem < (char *)this + 0xB0);
    pElem = (char *)this + 0xF8;
    do {
        __ct__Q26PSound19AmbientChannelStateFv(pElem);
        pElem += 0x20;
    } while (pElem < (char *)this + 0x378);
    pElem = (char *)this + 0x380;
    do {
        __ct__Q26PSound12AmbientEntryFv(pElem);
        pElem += 0x70;
    } while (pElem < (char *)this + 0x2220);
    pElem = (char *)this + 0x2220;
    do {
        __ct__Q26PSound19OneShotChannelStateFv(pElem);
        pElem += 0x40;
    } while (pElem < (char *)this + 0x2E20);
    pElem = (char *)this + 0x2EB4;
    do {
        __ct__Q26PSound8SpotInfoFv(pElem);
        pElem += 0x18;
    } while (pElem < (char *)this + 0x5434);
    pElem = (char *)this + 0x7A00;
    do {
        __ct__20GameSoundTrigletPawnFv(pElem);
        pElem += 0x150;
    } while (pElem < (char *)this + 0x18080);

    m_unk00 = 0;
    m_unk79F8 = (char *)((unsigned int)this + 0x7A00);
    m_unk2E20 = 4;
    m_unk2E24 = 5;
    m_unk2E28 = 6;
    m_unk2E2C = 0xF;
    m_unk2E30 = 0x10;
    m_unk2E34 = 0x2B;
    m_unk2E38 = 0x2C;
    m_unk2E3C = 0x2F;
    m_unk30 = 0;
    m_unk2E80 = 0x100;
    m_unkCC = 1;
    m_unk10 = 0;
    m_unk14 = 0;
    m_unk18080 = 0;
    m_unk18084 = 0;
    m_unk34 = gPSndDbg[4] * 10;
    m_unk3C = gPSndDbg[5] * 10;
    m_unk40 = 10;
    m_unk38 = gPSndDbg[6] * 10;
    m_unk44 = gPSndDbg[7] * 10;
    m_unk48 = gPSndDbg[8] * 10;
    {
        float fZero = 0.0f;
        m_unk60 = fZero;
        m_unk64 = 1.0f - fZero;
    }
    UsageInit();
    PSoundReInitSub(1);
    SOUND_ClearIOPBuffer();
}

// FUNCTION: 0x001AA720 ReInit__Q26PSound16MusicStreamStateFv
void PSound::MusicStreamState::ReInit() {
    m_unk00 = 0;
    m_unk04 = 0;
    m_unk0C = 1000;
    m_unk08 = 0;
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

// DRAFT: 0x001AA820 SetInitialPitch__Q26PSound12AmbientEntryFv
// note: DIFF 206; list walk restructured to head-then-do-while (211 before); lo/hi/out register layout and bnez target (0xB2 vs 0xD6) still differ; 5 attempts, 2 variants with the early-return store bug were rejected
void PSound::AmbientEntry::SetInitialPitch() {
    unsigned int aItems[52];
    int nCount = 0;
    if ((unsigned short)m_unk1A == 0) {
        unsigned short lo = *(unsigned short *)((char *)m_unk48 + 8);
        unsigned short hi = *(unsigned short *)((char *)m_unk48 + 0xA);
        int out = lo;
        if (lo < hi) {
            miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
            int v = lo + (int)((unsigned int)miRandom__7MathAPI % (unsigned int)(hi - lo));
            out = v;
            if (*((unsigned char *)m_unk48 + 0xE) >= 2) {
                int last = 0;
                AmbientEntry *pHead = (AmbientEntry *)m_unk4C;
                if (pHead != 0) {
                    AmbientEntry *pNode = *(AmbientEntry **)((char *)pHead + 8);
                    if (pNode != 0) {
                        do {
                            if (pNode != this && !((unsigned short)pNode->m_unk14 & 0x8000)) {
                                aItems[nCount + 1] = (unsigned short)pNode->m_unk1A;
                                nCount++;
                                last = (unsigned short)pNode->m_unk1A;
                            }
                            pNode = pNode->m_unk50;
                        } while (pNode != 0);
                    }
                }
                if (nCount == 1) {
                    int mid = (lo + hi) >> 1;
                    if (mid < last) {
                        if (mid < v) {
                            v = lo + (int)((unsigned int)miRandom__7MathAPI % (unsigned int)(mid - lo));
                        }
                    } else if (last < mid) {
                        if (v < mid) {
                            v = mid + (int)((unsigned int)miRandom__7MathAPI % (unsigned int)(hi - mid));
                        }
                    }
                    out = v;
                }
                float r1 = (float)v / (float)hi;
                float r2 = (float)v / (float)lo;
                if (nCount != 1 && nCount != 0) {
                    aItems[0] = lo;
                    aItems[nCount + 1] = hi;
                    ShellSort__FPFPvPv_bPPvi(0, (void **)aItems, nCount + 2);
                    unsigned int mn = aItems[0];
                    unsigned int mx = aItems[nCount + 1];
                    unsigned int gap = mx - mn;
                    for (int i = 1; i < nCount + 2; i++) {
                        unsigned int d = aItems[i] - aItems[i - 1];
                        if (gap < d) {
                            gap = d;
                            mn = aItems[i - 1];
                            mx = aItems[i];
                        }
                    }
                    ((gap != 0) ? (void)0 : CdsAssert("PSound.cpp", 0x9E9, "maxRange > 0"));
                    out = (int)((mx + mn) >> 1);
                } else if (!(r1 <= 0.98f)) {
                    out = hi;
                } else if (r2 < 1.02f) {
                    out = lo;
                }
            }
        }
        m_unk1A = (short)out;
    }
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

// FUNCTION: 0x001AACB0 PossiblyRandomPitch__Q26PSound8SpotInfoFv
int PSound::SpotInfo::PossiblyRandomPitch() {
    unsigned int nLo = m_unk08;
    unsigned int nHi = m_unk0A;
    unsigned int nRet = (unsigned short)nLo;
    if (nLo < nHi) {
        if (gPSndDbg[16] != 0) {
            miRandom__7MathAPI = miRandom__7MathAPI * 0x343FD + 0x269EC3;
            nRet = (unsigned short)(nLo + (unsigned int)miRandom__7MathAPI % (nHi - nLo));
        } else {
            nRet = nLo;
            nRet += nHi;
            nRet >>= 1;
        }
    }
    return (unsigned short)nRet;
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

// FUNCTION: 0x001AADA0 UsageFindNextHigherID__6PSoundFPPQ26PSound11PSoundUsage
int PSound::UsageFindNextHigherID(PSound::PSoundUsage **ppUsage) {
    PSoundUsage *pCur = (PSoundUsage *)fst_Usage;
    PSoundUsage *pEnd = (PSoundUsage *)(fst_Usage + 24000);
    PSoundUsage *pBest = 0;
    PSoundUsage *pSkip = 0;
    unsigned int nBest = 0xFFFFFFFF;
    unsigned int nPrev = 0;

    if (ppUsage != 0) {
        pSkip = *ppUsage;
        if (pSkip != 0) {
            nPrev = pSkip->m_unk0;
        }
    }
    if (pCur < pEnd) {
        do {
            unsigned int nId = pCur->m_unk0;
            if (nId == 0xFFFFFFFF) {
                break;
            }
            if (pSkip != pCur && nId < nBest && nPrev < nId) {
                nBest = nId;
                pBest = pCur;
            }
            pCur++;
        } while (pCur < pEnd);
    }
    if (ppUsage != 0) {
        *ppUsage = pBest;
        if (pBest != 0) {
            return 0;
        }
    }
    return -1;
}

// DRAFT: 0x001AAF20 UsageInit__6PSoundFv
// note: DIFF 6 words; original has three scheduling nops between the loop sltu and bnez and the guard beqz targets one slot further; tried int*, char*, unsigned cursors (15), int stride 5 (6), for-loop (11), while form (6), end as int* + 6000 (6), end declared before cursor (12)
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

// FUNCTION: 0x001AAF70 Test2__6PSoundFv
void PSound::Test2() {
    unsigned int nSize;
    unsigned int nRemain;
    unsigned int nChunk;

    fst_VBCountC = gCDSVBlankCount;
    fst_PCDFileTest.Open("PSXDATA\\GAME\\LOGO.PAK", OPEN_READ);
    nSize = fst_PCDFileTest.GetSize();
    if (nSize != 0) {
        nRemain = nSize;
        do {
            nChunk = nRemain;
            if (nRemain > 0x8000) {
                nChunk = 0x8000;
            }
            fst_PCDFileTest.Read(fst_ReadBuf, nChunk);
            nRemain -= nChunk;
        } while (nRemain != 0);
    }
    fst_VBCountD = gCDSVBlankCount;
    fst_diffCD = fst_VBCountD - fst_VBCountC;
    fst_PCDFileTest.Close();
    fst_PCDFileTest.Open("PSXDATA\\GAME\\TITLE.PAK", OPEN_READ);
    nSize = fst_PCDFileTest.GetSize();
    if (nSize != 0) {
        nRemain = nSize;
        do {
            nChunk = nRemain;
            if (nRemain > 0x8000) {
                nChunk = 0x8000;
            }
            fst_PCDFileTest.Read(fst_ReadBuf, nChunk);
            nRemain -= nChunk;
        } while (nRemain != 0);
    }
    fst_VBCountE = gCDSVBlankCount;
    fst_diffDE = fst_VBCountE - fst_VBCountD;
    fst_PCDFileTest.Close();
    fst_PCDFileTest.Open("PSXDATA\\MUSIC\\FRST1.VGM", OPEN_READ);
    nSize = fst_PCDFileTest.GetSize();
    if (nSize != 0) {
        nRemain = nSize;
        do {
            nChunk = nRemain;
            if (nRemain > 0x8000) {
                nChunk = 0x8000;
            }
            fst_PCDFileTest.Read(fst_ReadBuf, nChunk);
            nRemain -= nChunk;
        } while (nRemain != 0);
    }
    fst_VBCountF = gCDSVBlankCount;
    fst_diffEF = fst_VBCountF - fst_VBCountE;
    fst_PCDFileTest.Close();
}

// FUNCTION: 0x001AB150 Test1__6PSoundFv
void PSound::Test1() {
    unsigned int nSize;
    unsigned int nRemain;
    unsigned int nChunk;

    gSOUND_AllowSIFTranferTiming = 1;
    fst_VBCountC = gCDSVBlankCount;
    fst_PIOPFileTest.OpenByFileID(0xC2);
    nSize = fst_PIOPFileTest.GetSize();
    if (nSize != 0) {
        nRemain = nSize;
        do {
            nChunk = nRemain;
            if (nRemain > 0x8000) {
                nChunk = 0x8000;
            }
            fst_PIOPFileTest.Read(fst_ReadBuf, nChunk);
            nRemain -= nChunk;
        } while (nRemain != 0);
    }
    fst_VBCountD = gCDSVBlankCount;
    fst_diffCD = fst_VBCountD - fst_VBCountC;
    fst_PIOPFileTest.Close();
    fst_PIOPFileTest.OpenByFileID(0xC3);
    nSize = fst_PIOPFileTest.GetSize();
    if (nSize != 0) {
        nRemain = nSize;
        do {
            nChunk = nRemain;
            if (nRemain > 0x8000) {
                nChunk = 0x8000;
            }
            fst_PIOPFileTest.Read(fst_ReadBuf, nChunk);
            nRemain -= nChunk;
        } while (nRemain != 0);
    }
    fst_VBCountE = gCDSVBlankCount;
    fst_diffDE = fst_VBCountE - fst_VBCountD;
    fst_PIOPFileTest.Close();
    fst_PIOPFileTest.OpenByFileID(0xC4);
    nSize = fst_PIOPFileTest.GetSize();
    if (nSize != 0) {
        nRemain = nSize;
        do {
            nChunk = nRemain;
            if (nRemain > 0x8000) {
                nChunk = 0x8000;
            }
            fst_PIOPFileTest.Read(fst_ReadBuf, nChunk);
            nRemain -= nChunk;
        } while (nRemain != 0);
    }
    fst_VBCountF = gCDSVBlankCount;
    fst_diffEF = fst_VBCountF - fst_VBCountE;
    fst_TransferUsecs = gSOUND_usecsTotalTransfer;
    fst_PIOPFileTest.Close();
    gSOUND_AllowSIFTranferTiming = 0;
}

// FUNCTION: 0x001AB330 DebugClearPlayedInGame__6PSoundFv
void PSound::DebugClearPlayedInGame() {
    int *p = (int *)fst_Usage;
    int *end = (int *)(fst_Usage + 24000);
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

// FUNCTION: 0x001AB430 DebugRestartValues__6PSoundFv
void PSound::DebugRestartValues() {
    unsigned int nID = m_unk10;
    if (nID >= 0x64 && nID < 0x72) {
        SpotInfo *pSpot = GetSpotInfo(0x1C);
        if (pSpot != 0) {
            pSpot->m_unk0E = *(unsigned char *)&gPSndDbg[12];
            pSpot->m_unk0F = *(unsigned char *)&gPSndDbg[12];
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

// FUNCTION: 0x001AB4F0 WriteSoundFileToPC__6PSoundFv
int PSound::WriteSoundFileToPC() {
    char spB0[0x100];
    char sp1B0[0x80];
    char sp230[0x20];
    char sp250[0x20];
    PSoundUsage *sp27C;
    int nRet;
    bool bErr;
    int nFd;
    unsigned int nIdx;
    SpotInfo *pSpot;
    int nLevel;
    char *pBankName;

    nRet = 0;
    sp27C = 0;
    bErr = false;
    strcpy(spB0, gszFilePrefix);
    strcat(spB0, "Tools\\Reports\\SoundReportFromPS2.txt");
    FlushCache(0);
    nFd = sceOpen(spB0, 0x602);
    if (nFd >= 0) {
        nLevel = *(int *)(gEng + 0x19A78);
        GetLevelFile__10MaximoMainFi(gEng, -1);
        pBankName = "UnknownBankName";
        strcpy(sp230, pBankName);
        sprintf(sp1B0, "; idx     id vol loPch hiPch use chn pri Vol SPri ARidx Flg spuOff\r\n");
        if (WriteLineToPCFile(nFd, sp1B0) != 0) {
            bErr = true;
            goto block_end;
        }
        sprintf(sp1B0, "[LEVEL %d %d %s]\r\n", m_unk10, nLevel, sp230);
        if (WriteLineToPCFile(nFd, sp1B0) != 0) {
            bErr = true;
            goto block_end;
        }
        pSpot = (SpotInfo *)m_unk2EB4;
        nIdx = 0;
        while (nIdx < m_unk14) {
            unsigned int nVol = pSpot->m_unk10;
            if (nVol > 100) {
                nVol = 100;
            }
            sprintf(sp1B0, "  %6d %3d %5d %5d  %2d  %2d %3d  %3d   %2d  %02x %06x\r\n",
                    pSpot->m_unk00, nVol,
                    ((unsigned int)pSpot->m_unk08 * 0xBB80u) >> 12,
                    ((unsigned int)pSpot->m_unk0A * 0xBB80u) >> 12,
                    pSpot->m_unk0E, pSpot->m_unk0F,
                    pSpot->m_unk11, pSpot->m_unk15, pSpot->m_unk12,
                    pSpot->m_unk0C, pSpot->m_unk04);
            if (WriteLineToPCFile(nFd, sp1B0) != 0) {
                bErr = true;
                goto block_end;
            }
            pSpot++;
            nIdx++;
        }
        sprintf(sp1B0, "[\\LEVEL %d %d %s]\r\n\r\n\r\n", m_unk10, nLevel, sp230);
        if (WriteLineToPCFile(nFd, sp1B0) != 0) {
            bErr = true;
            goto block_end;
        }
        sprintf(sp1B0, ";   id   all  dropped outOfBank far\r\n");
        if (WriteLineToPCFile(nFd, sp1B0) != 0) {
            bErr = true;
            goto block_end;
        }
        WaitOnVSync();
        sprintf(sp1B0, "[CALLUSAGE]\r\n");
        if (WriteLineToPCFile(nFd, sp1B0) != 0) {
            bErr = true;
            goto block_end;
        }
        sp27C = 0;
usage_loop:
        UsageFindNextHigherID(&sp27C);
        if (sp27C != 0) {
            sprintf(sp1B0, " %6d %5d %5d %5d %5d\r\n", sp27C->m_unk0, sp27C->m_unk4,
                    sp27C->m_unk8, sp27C->m_unk10, sp27C->m_unkC);
            if (WriteLineToPCFile(nFd, sp1B0) != 0) {
                bErr = true;
                goto block_end;
            }
            goto usage_loop;
        }
        sprintf(sp1B0, "[\\CALLUSAGE]\r\n\r\n");
        if (WriteLineToPCFile(nFd, sp1B0) != 0) {
            bErr = true;
            goto block_end;
        }
    }
block_end:
    if (nFd < 0) {
        sprintf(sp1B0, "Could not open file %s\n", spB0);
        nRet = -1;
    } else {
        sceClose(nFd);
        if (bErr) {
            sprintf(sp1B0, "Error writing sound changes to %s\n", spB0);
            nRet = -1;
        } else {
            pBankName = "New file";
            strcpy(sp250, pBankName);
            sprintf(sp1B0, "Sound changes written to %s OK (%s)\n", spB0, sp250);
        }
    }
    printf(sp1B0);
    return nRet;
}

// DRAFT: 0x001AB880 DebugInterfaceEditASound__6PSoundFUi
// note: 949 words differ (statics/branch offsets in ID-nav, switch args, display block); tried nFrame local, ++x>=y, unsigned nPad/nPitch, operand flips, movz ternary flip
void PSound::DebugInterfaceEditASound(unsigned int nArg) {
    static int st_tSoundRef = 0;
    static int st_tAutoSoundRef = 0;
    static unsigned int st_lastPlayedSoundID = -1;
    static unsigned int st_lastPlayedSoundAutoID = -1;
    static unsigned int st_delayCnt = 0;
    static unsigned int st_delayCntTrg = 0;
    static signed char st_bHadFirstDelay = 0;
    static unsigned int st_lastCallFrame = 0;
    static unsigned int st_lastActiveTrg = 0;
    static int st_lastNewButton = 0;
    static unsigned int st_nRepeats = 0;
    static unsigned int st_delayCntTrgInitial = 0xC;
    static unsigned int st_delayCntTrgThereafter = 4;
    static int st_FramesSinceAction = 0;
    static int st_AutoMode = 0;
    static unsigned int st_AutoDelayCnt = 0;
    static int st_EditSoundBank = 0;
    static int st_AutoSoundBank = 0;
    char sp70[0x80];
    unsigned int nIdx = 0;
    unsigned int nTrg = nArg;
    unsigned int nPad = *(unsigned short *)&gPad[67];
    unsigned int spF8, spFC, sp100, sp104, sp108, sp10C, sp110, sp114, sp118, sp11C;
    unsigned char *pRec;
    unsigned char *pDisp;
    int nOff;

    sprintf(sp70, "\n\n");
    gDebug.DebugDisp(sp70);
    unsigned int nFrame = *(unsigned int *)(gEng + 0x137A4);
    if (st_lastCallFrame + 1 < nFrame) {
        st_lastActiveTrg = 0;
        st_delayCnt = 0;
        st_nRepeats = 0;
        st_FramesSinceAction = 0;
        st_delayCntTrg = st_delayCntTrgInitial;
    } else {
        st_FramesSinceAction++;
    }
    st_lastCallFrame = nFrame;
    if (gPSndDbg[0] != 0) {
        if (st_EditSoundBank != (int)m_unk10) {
            st_EditSoundBank = m_unk10;
            if (gPSndDbg[3] != 0) {
                DebugFindFirstID(&spF8, &spFC);
                gPSndDbg[41] = spFC;
            } else {
                gPSndDbg[41] = 0;
            }
        }
        if ((unsigned int)gPSndDbg[41] >= 0x190) {
            gPSndDbg[41] = 0;
        }
        if ((unsigned int)gPSndDbg[41] >= m_unk14) {
            gPSndDbg[41] = 0;
        }
        if ((unsigned int)gPSndDbg[43] > 0xA) {
            gPSndDbg[43] = 0;
        }
        pRec = (unsigned char *)this + gPSndDbg[41] * 0x18 + 0x2EB4;
        if (nTrg != 0) {
            st_lastActiveTrg = nTrg;
            st_delayCnt = 0;
            st_delayCntTrg = st_delayCntTrgInitial;
        } else if (st_lastActiveTrg != 0) {
            st_lastActiveTrg &= nPad;
            if (st_lastActiveTrg != 0) {
                if (++st_delayCnt >= st_delayCntTrg) {
                    nTrg = st_lastActiveTrg;
                    st_delayCnt = 0;
                    st_delayCntTrg = st_delayCntTrgThereafter;
                    st_nRepeats++;
                }
            } else {
                st_nRepeats = 0;
                st_delayCnt = 0;
                st_delayCntTrg = st_delayCntTrgInitial;
            }
        }
        if (nTrg & 0x100) {
            gPSndDbg[0] = 0;
            if (st_lastPlayedSoundID != 0) {
                DebugStopAllSoundsBySoundID(st_lastPlayedSoundID);
                st_lastPlayedSoundID = 0;
            }
        } else if (nTrg & 0x1000) {
            DebugStopAllSoundsBySoundID(st_lastPlayedSoundID);
            st_lastPlayedSoundID = 0;
        } else if (nTrg & 0x4000) {
            unsigned int nPitch = 0;
            if (gPSndDbg[43] == 1) {
                nPitch = *(unsigned short *)(pRec + 8);
            } else if (gPSndDbg[43] == 2) {
                nPitch = *(unsigned short *)(pRec + 0xA);
            }
            st_tSoundRef = DebugPlaySoundWPitch(*(unsigned int *)pRec, *(unsigned int *)((char *)this + 0x18088), nPitch);
            st_lastPlayedSoundID = *(unsigned int *)pRec;
        } else if (nTrg & 0x50) {
            if (st_lastPlayedSoundID != 0) {
                DebugStopAllSoundsBySoundID(st_lastPlayedSoundID);
                st_lastPlayedSoundID = 0;
            }
            if (gPSndDbg[3] != 0) {
                if (nTrg & 0x10) {
                    DebugFindPrevID(&sp100, &sp104, *(unsigned int *)pRec);
                } else {
                    DebugFindNextID(&sp100, &sp104, *(unsigned int *)pRec);
                }
                if (sp104 > m_unk14 - 1) {
                    sp104 = 0;
                }
                gPSndDbg[41] = sp104;
            } else {
                int nDir = (nTrg & 0x40) ? 1 : -1;
                unsigned int nNew = gPSndDbg[41] + nDir;
                gPSndDbg[41] = nNew;
                if ((unsigned int)gPSndDbg[41] > m_unk14 - 1) {
                    gPSndDbg[41] = ((nTrg & 0x40) != 0) ? 0 : m_unk14 - 1;
                }
            }
            pRec = (unsigned char *)this + gPSndDbg[41] * 0x18 + 0x2EB4;
            if (nPad & 0x4000) {
                unsigned int nPitch = 0;
                if (gPSndDbg[43] == 1) {
                    nPitch = *(unsigned short *)(pRec + 8);
                } else if (gPSndDbg[43] == 2) {
                    nPitch = *(unsigned short *)(pRec + 0xA);
                }
                st_tSoundRef = DebugPlaySoundWPitch(*(unsigned int *)pRec, *(unsigned int *)((char *)this + 0x18088), nPitch);
                st_lastPlayedSoundID = *(unsigned int *)pRec;
            }
        } else if (nTrg & 0xA000) {
            int nDir = ((nTrg & 0x2000) != 0) ? 1 : -1;
            gPSndDbg[43] = gPSndDbg[43] + nDir;
            if ((unsigned int)gPSndDbg[43] > 0xA) {
                gPSndDbg[43] = ((nTrg & 0x2000) == 0) ? 0xA : 0;
            }
        } else if (nTrg & 0xA0) {
            int nDir = !(nTrg & 0x20) ? -1 : 1;
            int nStepA, nStepB;
            unsigned int nRate;
            if (st_nRepeats >= 0x3D) {
                nStepA = nDir * 8;
                nStepB = nDir * 3;
                nRate = 0x12;
            } else if (st_nRepeats >= 0x1F) {
                nStepA = nDir * 4;
                nStepB = nDir * 2;
                nRate = 9;
            } else {
                nStepA = nDir;
                nStepB = nDir;
                nRate = 1;
            }
            switch (gPSndDbg[43]) {
            case 0:
                pRec[0x10] = DebugChangeParam(pRec[0x10], nStepB, 0, 0, 0x64, false);
                break;
            case 1:
                *(unsigned short *)(pRec + 8) = DebugChangeParam(*(unsigned short *)(pRec + 8), nStepA, nRate, 0x19, *(unsigned short *)(pRec + 0xA), false);
                break;
            case 2:
                *(unsigned short *)(pRec + 0xA) = DebugChangeParam(*(unsigned short *)(pRec + 0xA), nStepA, nRate, *(unsigned short *)(pRec + 8), 0xFFFF, false);
                break;
            case 3:
                pRec[0xE] = DebugChangeParam(pRec[0xE], nDir, 0, 1, 0x1E, false);
                break;
            case 4:
                pRec[0xF] = DebugChangeParam(pRec[0xF], nDir, 0, 1, 0x14, false);
                break;
            case 5:
                pRec[0x11] = DebugChangeParam(pRec[0x11], nStepB, 0, 0, 0x64, false);
                break;
            case 6:
                pRec[0x15] = DebugChangeParam(pRec[0x15], nStepB, 0, 0, 0x64, false);
                break;
            case 7:
                pRec[0x12] = (pRec[0x12] & 0xF) | ((DebugChangeParam((pRec[0x12] & 0xF0) >> 4, nDir, 0, 0, 0xF, false) & 0xF) << 4);
                break;
            case 8:
                pRec[0x12] = (pRec[0x12] & 0xF0) | (DebugChangeParam(pRec[0x12] & 0xF, nDir, 0, 0, 0xF, false) & 0xF);
                break;
            case 9:
                pRec[0x13] = DebugChangeParam(pRec[0x13], nDir, 0, 0, 0x32, false);
                break;
            case 10:
                pRec[0x14] = DebugChangeParam(pRec[0x14], nStepA, 0, 0, 0xFF, false);
                break;
            }
        }
        nIdx = gPSndDbg[41];
    } else if (gPSndDbg[2] != 0 || gPSndDbg[1] != 0) {
        int bNext = 0;
        int bMoved = 0;
        if (st_AutoSoundBank != (int)m_unk10) {
            st_AutoSoundBank = m_unk10;
            if (gPSndDbg[3] != 0) {
                DebugFindFirstID(&sp108, &sp10C);
                gPSndDbg[47] = sp10C;
            } else {
                gPSndDbg[47] = 0;
            }
        }
        pRec = (unsigned char *)this + gPSndDbg[47] * 0x18 + 0x2EB4;
        if (nTrg & 0x100) {
            gPSndDbg[2] = 0;
            gPSndDbg[1] = 0;
            if (st_lastPlayedSoundAutoID != 0) {
                DebugStopAllSoundsBySoundID(st_lastPlayedSoundID);
                st_lastPlayedSoundAutoID = 0;
            }
        }
        if (nTrg & 0x50) {
            bNext = 1;
            if (st_lastPlayedSoundID != 0) {
                DebugStopAllSoundsBySoundID(st_lastPlayedSoundID);
                st_lastPlayedSoundID = 0;
            }
            if (gPSndDbg[3] != 0) {
                if (nTrg & 0x10) {
                    DebugFindPrevID(&sp110, &sp114, *(unsigned int *)pRec);
                } else {
                    DebugFindNextID(&sp110, &sp114, *(unsigned int *)pRec);
                }
                if (sp114 > m_unk14 - 1) {
                    sp114 = 0;
                }
                gPSndDbg[47] = sp114;
            } else {
                int nDir = (nTrg & 0x40) ? 1 : -1;
                gPSndDbg[47] = gPSndDbg[47] + nDir;
                if ((unsigned int)gPSndDbg[47] > m_unk14 - 1) {
                    gPSndDbg[47] = ((nTrg & 0x40) != 0) ? 0 : m_unk14 - 1;
                }
            }
            bMoved = 1;
            if ((unsigned int)gPSndDbg[47] >= 0x190) {
                gPSndDbg[47] = 0;
            }
        }
        pRec = (unsigned char *)this + gPSndDbg[47] * 0x18 + 0x2EB4;
        if (st_FramesSinceAction == 0) {
            st_AutoMode = 0;
            st_AutoDelayCnt = 0;
            if (st_lastPlayedSoundAutoID != 0) {
                DebugStopAllSoundsBySoundID(st_lastPlayedSoundAutoID);
                st_lastPlayedSoundAutoID = -1;
            }
            if ((unsigned int)gPSndDbg[47] >= 0x190) {
                gPSndDbg[47] = 0;
            }
            if ((unsigned int)gPSndDbg[47] >= m_unk14) {
                gPSndDbg[47] = 0;
            }
            pRec = (unsigned char *)this + gPSndDbg[47] * 0x18 + 0x2EB4;
        } else if (bNext == 0) {
            switch (st_AutoMode) {
            case 0:
                st_AutoDelayCnt++;
                if (st_AutoDelayCnt >= 4) {
                    st_AutoMode++;
                }
                break;
            case 1: {
                unsigned int nPitch = 0;
                if ((unsigned int)gPSndDbg[47] >= 0x190) {
                    gPSndDbg[47] = 0;
                }
                if ((unsigned int)gPSndDbg[47] >= m_unk14) {
                    gPSndDbg[47] = 0;
                }
                pRec = (unsigned char *)this + gPSndDbg[47] * 0x18 + 0x2EB4;
                if (gPSndDbg[43] == 1) {
                    nPitch = *(unsigned short *)(pRec + 8);
                } else if (gPSndDbg[43] == 2) {
                    nPitch = *(unsigned short *)(pRec + 0xA);
                }
                st_tAutoSoundRef = DebugPlaySoundWPitch(*(unsigned int *)pRec, *(unsigned int *)((char *)this + 0x18088), nPitch);
                st_lastPlayedSoundAutoID = *(unsigned int *)pRec;
                st_AutoDelayCnt = 0;
                st_AutoMode++;
                break;
            }
            case 2:
                st_AutoDelayCnt++;
                if (st_AutoDelayCnt >= 4) {
                    st_AutoMode++;
                }
                break;
            case 3:
                if (!(nPad & 0x4000)) {
                    if (gPSndDbg[2] != 0) {
                        st_AutoDelayCnt++;
                        if ((unsigned int)gPSndDbg[35] < st_AutoDelayCnt) {
                            st_AutoMode++;
                            bNext = 1;
                        }
                    } else if (pRec[0xC] & 2) {
                        st_AutoDelayCnt++;
                        if ((unsigned int)gPSndDbg[37] < st_AutoDelayCnt) {
                            st_AutoMode++;
                            bNext = 1;
                        }
                    }
                }
                if (!(pRec[0xC] & 2) && SOUND_SPUKeyStatus[m_unk2E40] == 0) {
                    bNext = 1;
                }
                break;
            default:
                CdsAssert("PSound.cpp", 0x5FC, "0");
                break;
            }
        }
        if (bNext != 0) {
            if (st_lastPlayedSoundAutoID != 0) {
                DebugStopAllSoundsBySoundID(st_lastPlayedSoundAutoID);
                st_lastPlayedSoundAutoID = -1;
            }
            st_AutoDelayCnt = 0;
            st_AutoMode = 0;
            if (bMoved == 0 && !(nPad & 0x4000)) {
                if (gPSndDbg[3] != 0) {
                    DebugFindNextID(&sp118, &sp11C, *(unsigned int *)pRec);
                    if (sp11C > m_unk14 - 1) {
                        sp11C = 0;
                    }
                    gPSndDbg[47] = sp11C;
                } else {
                    gPSndDbg[47] = gPSndDbg[47] + 1;
                }
            }
            if ((unsigned int)gPSndDbg[47] >= 0x190) {
                gPSndDbg[47] = 0;
            }
            if ((unsigned int)gPSndDbg[47] >= m_unk14) {
                gPSndDbg[47] = 0;
            }
        }
        nIdx = gPSndDbg[47];
    }
    nOff = nIdx * 3;
    pDisp = (unsigned char *)this + nOff * 8 + 0x2EB4;
    sprintf(sp70, "idx     id Vol loPch hiPch use chn pri SPri ARidx\n");
    sp70[0x7F] = 0;
    gDebug.DebugColorDisp(sp70, 5);
    sprintf(sp70, "%3d %6d", nIdx, *(unsigned int *)pDisp);
    gDebug.DebugColorDisp(sp70, 7);
    {
        unsigned char nV = pDisp[0x10];
        if (nV >= 0x65) {
            nV = 0x64;
        }
        sprintf(sp70, " %3d", nV);
        gDebug.DebugColorDisp(sp70, (gPSndDbg[43] != 0) ? 7 : 6);
    }
    sprintf(sp70, " %5d", (*(unsigned short *)(pDisp + 8) * 0xBB80) >> 0xC);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 1) ? 6 : 7);
    sprintf(sp70, " %5d", (*(unsigned short *)(pDisp + 0xA) * 0xBB80) >> 0xC);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 2) ? 6 : 7);
    sprintf(sp70, "  %2d", pDisp[0xE]);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 3) ? 6 : 7);
    sprintf(sp70, "  %2d", pDisp[0xF]);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 4) ? 6 : 7);
    sprintf(sp70, " %3d", pDisp[0x11]);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 5) ? 6 : 7);
    sprintf(sp70, "  %3d", pDisp[0x15]);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 6) ? 6 : 7);
    sprintf(sp70, "    %x", (pDisp[0x12] & 0xF0) >> 4);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 7) ? 6 : 7);
    sprintf(sp70, "%x", pDisp[0x12] & 0xF);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 8) ? 6 : 7);
    sprintf(sp70, "\n");
    gDebug.DebugColorDisp(sp70, 5);
    sprintf(sp70, "      grp Dst Flg1 Flg2\n");
    sp70[0x7F] = 0;
    gDebug.DebugColorDisp(sp70, 5);
    sprintf(sp70, "      %3d", pDisp[0x13]);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 9) ? 6 : 7);
    sprintf(sp70, " %3d", pDisp[0x14]);
    gDebug.DebugColorDisp(sp70, (gPSndDbg[43] == 10) ? 6 : 7);
    sprintf(sp70, "  %02x", pDisp[0xC]);
    gDebug.DebugColorDisp(sp70, 7);
    sprintf(sp70, "  %02x\n", pDisp[0xD]);
    gDebug.DebugColorDisp(sp70, 7);
    sprintf(sp70, "\n calls drops outBank  far        spu\n");
    sp70[0x7F] = 0;
    gDebug.DebugColorDisp(sp70, 5);
    {
        int *pUsage = UsageFind(*(unsigned int *)pDisp);
        if (pUsage != 0) {
            sprintf(sp70, " %5d", pUsage[1]);
            gDebug.DebugColorDisp(sp70, 7);
            sprintf(sp70, " %5d", pUsage[2]);
            gDebug.DebugColorDisp(sp70, 7);
            sprintf(sp70, " %5d", pUsage[4]);
            gDebug.DebugColorDisp(sp70, 7);
            sprintf(sp70, " %5d", pUsage[3]);
            gDebug.DebugColorDisp(sp70, 7);
            sprintf(sp70, "      %6x", *(int *)(pDisp + 4) + 0x50010);
            gDebug.DebugColorDisp(sp70, 7);
        }
    }
    if (gPSndDbg[0] != 0 && (unsigned int)gPSndDbg[44] >= 3) {
        sprintf(sp70, "\n\nConfirm ***File Write***  yes (square) / no (circle)\n");
        gDebug.DebugDisp(sp70);
    }
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

// FUNCTION: 0x001ACD00 DebugChangeParam__6PSoundFUiiUiUiUib
unsigned int PSound::DebugChangeParam(unsigned int nValue, int nStep, unsigned int nRate, unsigned int nLo, unsigned int nHi, bool bWrap) {
    unsigned int nQ = (nValue * nRate) / 1000;
    unsigned int nVal = nValue + nStep;
    if (nStep < 0) {
        nVal -= nQ;
    } else if (nStep > 0) {
        nVal += nQ;
    }
    if (bWrap) {
        if (nStep < 0) {
            if (nValue < nVal) return nLo;
        } else {
            if (nVal < nValue) return nHi;
        }
    }
    if (nLo <= nVal && nVal <= nHi) {
        return nVal;
    }
    if (nStep < 0) {
        return nHi;
    }
    return nLo;
}

// DRAFT: 0x001ACDA0 DebugInterface__6PSoundFUi
// note: 605 differing words; frame 0xF0 vs 0xB0 (sp70 0x40 extra), body 0xA10 vs 0x9F4, static guards and gPSndDbg/gDebug relocs differ; not matched
void PSound::DebugInterface(unsigned int nArg) {
    static int miDebugTopMenu = 0;
    static int st_tSoundRef = 0;
    static unsigned int st_lastPlayedSoundID = 0;
    static int st_lastCallFrame = 0;
    static signed char st_bHadBreak = 0;
    static unsigned int st_frameSinceRead = 0;
    static int st_frameSincePush = 0;
    char sp70[0x40];
    unsigned int nPad = nArg;
    int bEdit = 0;
    char *pTemp;

    *(unsigned int *)((char *)this + 0x18088) = 0x80000000;
    pTemp = *(char **)(gEng + 0x1883C);
    if (pTemp != 0) {
        *(unsigned int *)((char *)this + 0x18088) = *(unsigned int *)(pTemp + 4);
    } else {
        CdsAssert("PSound.cpp", 0x1E5, "0");
    }

    if (gPSndDbg[0] || gPSndDbg[2] || gPSndDbg[1]) {
        bEdit = 1;
    } else {
        if (st_lastCallFrame + 1 == *(int *)(gEng + 0x137A4)) {
            if (nArg != 0) {
                st_frameSinceRead = 0;
                st_bHadBreak = 1;
                st_frameSincePush = 0;
            } else {
                st_frameSinceRead++;
                if (gPad[67] != 0) {
                    if (st_frameSinceRead >= 8) {
                        st_frameSinceRead = 0;
                        if (fst_TopDebugTable[miDebugTopMenu].unkC >= 0xB) {
                            nPad |= gPad[67];
                        }
                    }
                } else {
                    st_frameSincePush++;
                }
            }
        } else {
            st_bHadBreak = 0;
            nPad = 0;
            st_frameSinceRead = 0;
            st_frameSincePush = 0;
        }
        st_lastCallFrame = *(int *)(gEng + 0x137A4);

        if (gPSndDbg[49] != 0) {
            int bDone = 0;
            if (nPad & 0xA0F0) {
                if (nPad & 0xF0) {
                    bDone = 1;
                    nPad &= 0xF0;
                } else if (gPSndDbg[45] == 0 || (unsigned int)gPSndDbg[46] >= 3) {
                    if (nPad & 0xA000) {
                        if (nPad & 0x8000) {
                            switch (miDebugTopMenu) {
                            case 25:
                                if (gPSndDbg[22] != 0) {
                                    gPSndDbg[51] = 1;
                                }
                                break;
                            case 30:
                                if (gPSndDbg[22] != 0) {
                                    SOUND_MjlnCall(gPSndDbg[22], 0, 0);
                                }
                                break;
                            case 29:
                                if (gPSndDbg[22] != 0) {
                                    SOUND_LogWindowInfo(gPSndDbg[22], 0, 0);
                                }
                                break;
                            case 28:
                                gDebug.DebugDispPos("Writing", 5, 4, 6);
                                WriteSoundFileToPC();
                                break;
                            case 34:
                                Test2();
                                break;
                            case 33:
                                Test1();
                                break;
                            case 22:
                                if (gPSndDbg[22] == 1) {
                                    DebugClearPlayedInGame();
                                }
                                break;
                            }
                        }
                        nPad = 0;
                        bDone = 1;
                    }
                }
            }
            if (bDone) {
                gPSndDbg[49] = 0;
                gPSndDbg[45] = 0;
                gPSndDbg[46] = 0;
            }
        }

        if (nArg != 0 && gPSndDbg[45] != 0) {
            if (nArg & 0x200) {
                gPSndDbg[46]++;
            } else {
                gPSndDbg[46] = 0;
            }
        }

        if (miDebugTopMenu == 6) {
            if (nPad & 0x4000) {
                st_tSoundRef = DebugPlaySoundWPitch(0x1C, *(unsigned int *)((char *)this + 0x18088), 0);
                nPad = 0;
                st_lastPlayedSoundID = 0x1C;
            }
        } else if (st_lastPlayedSoundID != 0) {
            DebugStopAllSoundsBySoundID(st_lastPlayedSoundID);
            st_lastPlayedSoundID = 0;
        }

        if (nPad & 0x4000) {
            if (miDebugTopMenu == 0x17) {
                if ((unsigned int)gPSndDbg[23] >= 3 && (unsigned int)gPSndDbg[23] < 0x21) {
                    PlayMusic(gPSndDbg[23]);
                    nPad = 0;
                }
            }
        }
        if (nPad & 0x1000) {
            if (miDebugTopMenu == 0x1B) {
                AddChanToMultipleStops(0x2F);
            }
        }

        if ((nPad & 0xA0) == 0 && (nPad & 0x50)) {
            if (nPad & 0x10) {
                miDebugTopMenu--;
                if (miDebugTopMenu < 0) {
                    miDebugTopMenu = 0x22;
                }
            } else if (nPad & 0x40) {
                miDebugTopMenu++;
                if (miDebugTopMenu == 0x23) {
                    miDebugTopMenu = 0;
                }
            }
            gPSndDbg[49] = 0;
            gPSndDbg[45] = 0;
            gPSndDbg[46] = 0;
        }

        if (miDebugTopMenu == 0x18 && pTemp != 0) {
            *fst_TopDebugTable[miDebugTopMenu].unk4 = *(unsigned int *)(pTemp + 0x23C4);
        }

        if ((nPad & 0xA0) != 0) {
            unsigned int nS3;
            int nDelta = (nPad & 0x20) ? 1 : -1;
            int nStep = (nPad & 0x20) ? 5 : -5;
            int s1 = 0;
            unsigned int nCur;
            gPSndDbg[49] = 0;
            gPSndDbg[45] = 0;
            gPSndDbg[46] = 0;
            nCur = *fst_TopDebugTable[miDebugTopMenu].unk4;
            nS3 = nCur + nDelta;
            if (fst_TopDebugTable[miDebugTopMenu].unkC >= 0x65 && (unsigned int)(nCur + nStep) >= 0x65) {
                nS3 = ((nCur + nStep) / 5) * 5;
            }
            if (fst_TopDebugTable[miDebugTopMenu].unkC < nS3) {
                nS3 = (nPad & 0x20) ? fst_TopDebugTable[miDebugTopMenu].unk8 : fst_TopDebugTable[miDebugTopMenu].unkC;
            }
            *fst_TopDebugTable[miDebugTopMenu].unk4 = nS3;

            switch (miDebugTopMenu) {
            case 34:
            case 28:
                if (nS3 != 0) s1 = 1;
                break;
            case 33:
                if (nS3 != 0) gPSndDbg[49] = 1;
                break;
            case 27:
                if (nS3 != 0) {
                    gPSndDbg[50] = (gPSndDbg[50] == 0x1E) ? 0x1F : 0x1E;
                    SOUND_PlaySFXRelVol(gPSndDbg[50], 0x2F, 0x3E8, 0x3E8, 0x36FF1FCE);
                }
                break;
            case 25:
                if (nS3 != 0) {
                    s1 = 1;
                } else {
                    gPSndDbg[51] = 0;
                }
                break;
            case 24:
                if (pTemp != 0) {
                    *(unsigned int *)(pTemp + 0x23C4) = nS3;
                }
                break;
            case 30:
            case 29:
                if (nS3 != 0) s1 = 1;
                break;
            case 22:
                if (gPSndDbg[39] == 1) gPSndDbg[49] = 1;
                break;
            case 19:
                SetPositionalRangeAmbient(gPSndDbg[39]);
                break;
            case 18:
                SetPositionalRangeOneshot(gPSndDbg[39]);
                break;
            case 17:
                SetDistLinearPercent(gPSndDbg[39]);
                break;
            case 8:
                SetUbiquitousFactorRelVol(gPSndDbg[39]);
                break;
            case 7:
                SetPositionalFactorRelVol(gPSndDbg[39]);
                break;
            case 6:
                SetEffectsRelVolume(gPSndDbg[39]);
                break;
            case 4:
                SetMasterRelVolume(gPSndDbg[39]);
                break;
            case 5:
                SetMainMusicRelVolume(gPSndDbg[39]);
                break;
            case 12:
                {
                    char *pSpot = (char *)GetSpotInfo(0x1C);
                    if (pSpot != 0) {
                        *(unsigned char *)(pSpot + 0xE) = (unsigned char)nS3;
                        *(unsigned char *)(pSpot + 0xF) = (unsigned char)nS3;
                    }
                }
                break;
            case 11:
                gPSndDbg[39] = (nS3 != 0);
                gPSndDbg[40] = gPSndDbg[39];
                break;
            case 10:
                SetMusicPitchBend(nS3 != 0);
                break;
            }
            if (s1) {
                gPSndDbg[46] = 0;
                gPSndDbg[49] = 1;
                gPSndDbg[45] = 1;
            }
        }

        bEdit = bEdit;
    }

    sprintf(sp70, "%s %d\n", fst_TopDebugTable[miDebugTopMenu].unk0, *fst_TopDebugTable[miDebugTopMenu].unk4);
    gDebug.DebugDisp(sp70);
    if (miDebugTopMenu == 0x1B) {
        sprintf(sp70, "%d\n", SOUND_SPUKeyStatus[0x2F]);
        gDebug.DebugDispPos(sp70, 4, 3, 7);
    }
    if (gPSndDbg[49] != 0 && (gPSndDbg[45] == 0 || (unsigned int)gPSndDbg[46] >= 3)) {
        gDebug.DebugDispPos("Confirm?  yes (square) / no (circle)", 4, 3, 6);
    }
    if (bEdit) {
        if (gPSndDbg[0] == 0) {
            if (gPSndDbg[2] || gPSndDbg[1]) {
                DebugInterfaceEditASound(nPad);
            }
        } else {
            DebugInterfaceEditASound(nPad);
        }
    }
}

// FUNCTION: 0x001A9F10 PSoundInit__6PSoundFUi
int PSound::PSoundInit(unsigned int nFlag) {
    if (m_unk00 != 0) {
        return 0;
    }
    if (SOUND_InitIOP() < 0) {
        return 0;
    }
    SOUND_InitSPU();
    SOUND_ReverbSetAdrs(0x1FFFFF, 0x1DFFFF);
    SOUND_ClearReverbWorkArea(0, 5);
    SOUND_ClearReverbWorkArea(1, 5);
    SOUND_SetEETransferNotifyAdrs(gSOUND_EETransferStart, gSOUND_EETransferFinish);
    SOUND_SetChanUse(0, m_unk2E20, m_unk2E28, m_unk2E30, m_unk2E38);
    SOUND_InitStreamData(0);
    SOUND_SetLanguage(nFlag);
    SOUND_AllocateStreamBuffer(0, 0x5010, 0x19000);
    SOUND_AllocateStreamBuffer(1, 0x1E010, 0x19000);
    SOUND_AllocateStreamBuffer(2, 0x37010, 0x10000);
    PSoundFlushIOPCommandsWaitFinish();
    PSoundReInitSubWSoundCalls();
    m_unk00 = 2;
    return 1;
}
