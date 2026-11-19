#ifndef MAXENGINE_H
#define MAXENGINE_H

class PScrollingTrees;

class MaxEngine {
public:
    int EngGenerateUniqueID();
    void DestroyScrollingTrees();
    void IncrementSecondarySyncCounts();
    void SoundOneFrameHasElapsed_R(int &nA, int &nB);
    void EngineInit();

    char _pad000[0xD0];
    /* 0x0000D0 */ float m_unkD0;
    char _pad0D4[0x137A0 - 0x0D4];
    /* 0x137A0 */ int m_unk137A0;
    /* 0x137A4 */ int m_unk137A4;
    char _pad137A8[0x137D4 - 0x137A8];
    /* 0x137D4 */ int m_unk137D4;
    char _pad137D8[0x137DC - 0x137D8];
    /* 0x137DC */ PScrollingTrees *m_unk137DC;
    char _pad137E0[0x19784 - 0x137E0];
    /* 0x19784 */ float m_unk19784;
    char _pad19788[0x19B50 - 0x19788];
};

#endif
