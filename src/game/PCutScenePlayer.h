#ifndef PCUTSCENEPLAYER_H
#define PCUTSCENEPLAYER_H

#include "types.h"

class PArray;

class PCutScenePlayer {
public:
    ~PCutScenePlayer();
    void KillActorFx();
    void Abort();
    void ResetCutScene();
    void UpdatePlayer();
    void Unload(bool bFlag);
    void SetBgNodesOpacity(PArray *pArray, float fOpacity);

    char m_unk00[0x5C];
    int m_unk5C;
    char m_unk60[0x10];
    char m_unk70[0x10];
    char m_unk80[0x10];
    char m_unk90[0x10];
    char m_unkA0[0x10];
    unsigned int m_unkB0;
    unsigned int m_unkB4;
    void **m_unkB8;
    char m_unkBC[0x44];
    char m_unk100[0x2130 - 0x100];
    int m_unk2130;
    char m_unk2134[0x8];
    signed char m_unk213C;
    signed char m_unk213D;
};

#endif
