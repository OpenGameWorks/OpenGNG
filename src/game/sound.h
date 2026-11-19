#ifndef SOUND_H
#define SOUND_H

void SOUND_MakeStreamTransactionID(void);
void SOUND_MakeSoundStreamRef(void);
void SOUND_Set_EE_Control(int arg0);
void SOUND_InitWaitUpdate(void);
void SOUND_SetChanUse(short arg0, short arg1, short arg2, short arg3, short arg4);
void SOUND_SetGlobalRelVols(short arg0, short arg1, short arg2, short arg3, short arg4, short arg5, short arg6, short arg7);
void SOUND_EnableFeatures(unsigned int arg0, unsigned int arg1);
void SOUND_LevelRestart(void);
void SOUND_StopAllSounds(void);
void SOUND_FadeMusicStream(short arg0, short arg1, short arg2);
void SOUND_ChangeReverbMasterVolume(short arg0, short arg1, short arg2);
void SOUND_ReverbSetAdrs(unsigned int arg0, unsigned int arg1);
void SOUND_SetSPUWriteAddress(unsigned int arg0);
void SOUND_AllocateStreamBuffer(short arg0, unsigned int arg1, unsigned int arg2);
int SOUND_SetChannelPitch(unsigned int arg0, short arg1);
int SOUND_SetChanRelVol(unsigned int arg0, short arg1, short arg2);
int SOUND_PlaySFXRelVol(short arg0, unsigned int arg1, short arg2, short arg3, unsigned int arg4);
void SOUND_ChangeReverbCore(short arg0, short arg1, short arg2, short arg3, short arg4, short arg5);
int SOUND_CountFreeSPUChannels(unsigned int arg0, unsigned int arg1);
void SOUND_ResumeMultipleSounds(unsigned int arg0, unsigned int arg1);
void SOUND_PauseMultipleSounds(unsigned int arg0, unsigned int arg1);
void SOUND_StopMultipleSounds(unsigned int arg0, unsigned int arg1);
int SOUND_StopStream(unsigned int arg0);
void SOUND_StreamAfterFlags(unsigned int arg0, unsigned int arg1, unsigned int arg2, unsigned int arg3, unsigned int arg4, unsigned int arg5);
void SOUND_TransferSFX(short arg0, short arg1, unsigned int arg2, unsigned int arg3);

#endif
