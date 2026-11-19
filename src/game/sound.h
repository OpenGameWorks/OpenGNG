#ifndef SOUND_H
#define SOUND_H

void SOUND_MakeStreamTransactionID(void);
void SOUND_MakeSoundStreamRef(void);
void SOUND_Set_EE_Control(int arg0);
void SOUND_InitWaitUpdate(void);
void SOUND_SetChanUse(short arg0, short arg1, short arg2, short arg3, short arg4);
void SOUND_EnableFeatures(unsigned int arg0, unsigned int arg1);
void SOUND_FadeMusicStream(short arg0, short arg1, short arg2);
void SOUND_ChangeReverbMasterVolume(short arg0, short arg1, short arg2);
void SOUND_ReverbSetAdrs(unsigned int arg0, unsigned int arg1);
void SOUND_SetSPUWriteAddress(unsigned int arg0);

#endif
