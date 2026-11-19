#ifndef SOUND_H
#define SOUND_H

void SOUND_Set_EE_Control(int arg0);
void SOUND_InitWaitUpdate(void);
void SOUND_FadeMusicStream(short arg0, short arg1, short arg2);
void SOUND_ChangeReverbMasterVolume(short arg0, short arg1, short arg2);
void SOUND_SetSPUWriteAddress(unsigned int arg0);

#endif
