#ifndef PPARTICLEBUBBLES_H
#define PPARTICLEBUBBLES_H

#include "types.h"
#include "PParticleSystem.h"

// Eight bytes of padding with an empty destructor. Embedding it makes
// CodeWarrior keep 'this' in a stack slot in the constructor.
struct PBubblePad {
    char _pad[8];
    ~PBubblePad() {}
};

// Parameter block for PParticleBubbles::Create, 0x60 bytes. The first three
// vectors are copied to the emitter's m_unk120 block.
struct tagParticleBubblesParams {
    float m_unk00[4];
    float m_unk10[4];
    float m_unk20[4];
    unsigned int m_unk30;       // bubble count passed to PParticleSystem::Create
    char _pad34[0x10];
    unsigned int m_unk44;       // resource id passed to GetResource
    char _pad48[0x18];
};

// Bubble emitter. The PParticleSystem base occupies the first 0xE0 bytes.
class PParticleBubbles : public PParticleSystem {
public:
    // One bubble, 0x30 bytes. The array at m_unk188 holds m_unk04 of them.
    struct tagBubble {
        float m_unk00;
        float m_unk04;
        float m_unk08;
        int m_unk0C;
        int m_unk10;
        int m_unk14;
        int m_unk18;
        int m_unk1C;
        float m_unk20;          // rise speed, multiplied by the frame delta
        float m_unk24;          // accumulated rise
        float m_unk28;          // remaining life
        int m_unk2C;
    };

    PParticleBubbles();
    int Create(tagParticleBubblesParams *pParams, float fX, float fY, float fZ);
    void Render();
    void Animate(float fDelta);
    void SpawnBubble(tagBubble *pBubble);

    PBubblePad m_unkE0;         // 8 bytes; its destructor makes the constructor spill 'this'
    char _padE8[8];
    float m_unkF0[4];
    int m_unk100;
    int m_unk104;
    int m_unk108;
    float m_unk10C;             // set to 1.0f by the constructor
    int m_unk110;
    int m_unk114;
    int m_unk118;
    float m_unk11C;             // set to 1.0f by the constructor
    float m_unk120[4];          // emitter origin, copied from the parameter block
    float m_unk130[4];          // second parameter vector
    float m_unk140[4];          // third parameter vector; w is scaled by Create
    char _pad150[4];
    float m_unk154;
    float m_unk158;
    float m_unk15C;
    float m_unk160;
    char _pad164[4];
    unsigned char m_unk168;     // Render negates m_unk114 into a vector lane when set
    char _pad169[0x17];
    char _pad180[4];
    int m_unk184;               // cleared by the constructor
    tagBubble *m_unk188;        // bubble array, released by the destructor
    unsigned int m_unk18C;      // number of bubbles spawned so far
    int m_unk190;               // spawn countdown
};

#endif
