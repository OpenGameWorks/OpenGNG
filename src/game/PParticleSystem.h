#ifndef PPARTICLESYSTEM_H
#define PPARTICLESYSTEM_H

#include "types.h"

class PMat4;
class PFrustrum;

class PParticleSystem {
public:
    void Stop();
    PParticleSystem();
    // Declared so derived constructors spill `this` to the stack and derived
    // destructors call it implicitly, as the original code does.
    ~PParticleSystem();
    void UpdateLoopDelay(float fDelta);
    void UpdateLoopCounter();
    void ComputeBoundingBox();
    void Cleanup();
    void FadeAndDie(unsigned int nUnused);
    void FrustrumTest(PFrustrum *pFrustrum, float *pVec, float fNear, float fFar);
    void ModifyPosition(PMat4 *pMat);
    void Render();
    int Create(unsigned int nNum, bool bAlloc);

    // 0x000 vtable pointer (__vt__15PParticleSystem), stored by the destructor.
    void SetPosition(float *, float *);
    char _pad000[4];
    unsigned int m_unk04;       // 0x004 element count walked by ComputeBoundingBox
    void *m_unk08;              // 0x008 buffer released by Cleanup; 0x20-byte elements
    int m_unk0C;                // 0x00C
    int m_unk10;                // 0x010
    unsigned char m_unk14;      // 0x014
    unsigned char m_unk15;      // 0x015 active flag tested by FadeAndDie
    unsigned char m_unk16;      // 0x016
    unsigned char m_unk17;      // 0x017
    unsigned char m_unk18;      // 0x018
    unsigned char m_unk19;      // 0x019 cleared by the constructor
    unsigned char m_unk1A;      // 0x01A
    unsigned char m_unk1B;      // 0x01B cleared by the constructor
    unsigned char m_unk1C;      // 0x01C flag tested by FrustrumTest
    char _pad01D[3];
    int m_unk20;                // 0x020 cleared by the constructor
    int m_unk24;                // 0x024 cleared by the constructor
    int m_unk28;                // 0x028 cleared by the constructor
    int m_unk2C;                // 0x02C cleared by the constructor
    long long m_unk30;          // 0x030 set to 0x44 as one 64-bit store by the constructor
    char _pad38[8];
    u_long128 m_unk40;          // 0x040 copied from PMat4 rows by ModifyPosition
    u_long128 m_unk50;          // 0x050
    u_long128 m_unk60;          // 0x060
    u_long128 m_unk70;          // 0x070
    float m_unk80;              // 0x080 bounding box centre X
    float m_unk84;              // 0x084 bounding box centre Y
    float m_unk88;              // 0x088 bounding box centre Z
    int m_unk8C;                // 0x08C set to 1.0f bits by ComputeBoundingBox
    float m_unk90;              // 0x090 bounding box extent X
    float m_unk94;              // 0x094 bounding box extent Y
    float m_unk98;              // 0x098 bounding box extent Z
    float m_unk9C;              // 0x09C bounding radius
    float m_unkA0;              // 0x0A0 bounding box size input
    int m_unkA4;                // 0x0A4 IntersectBox result stored by FrustrumTest
    int m_unkA8;                // 0x0A8
    int m_unkAC;                // 0x0AC
    float m_unkB0;              // 0x0B0 loop delay reload value
    float m_unkB4;              // 0x0B4 loop delay countdown
    float m_unkB8;              // 0x0B8 set to 1.0f by the constructor
    float m_unkBC;              // 0x0BC set to 1.0f by the constructor
    float m_unkC0;              // 0x0C0 set to 1.0f by the constructor
    float m_unkC4;              // 0x0C4 set to 1.0f by the constructor
    float m_unkC8;              // 0x0C8 set to 1.0f by the constructor
    float m_unkCC;              // 0x0CC frustum test factor
    int m_unkD0;                // 0x0D0
    int m_unkD4;                // 0x0D4 set to 2 by the constructor
};

#endif
