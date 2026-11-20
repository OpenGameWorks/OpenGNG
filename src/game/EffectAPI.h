#ifndef EFFECTAPI_H
#define EFFECTAPI_H

#include "types.h"

class EntityBaseClass;
class EffectNode;
class GhostEffect;
class PLightManager;
class PMeshNode;
class PlingEffect;
class PMat4;
class PMNode;
class MotionBlurEffect;

// EffectAPI derives from PArray at offset 0; the base is not declared here,
// so the constructor reaches it through the .cpp foreign declarations.
class EffectAPI {
public:
    EffectAPI();
    EffectNode *FindPling(EntityBaseClass *arg0);
    void CreatePling(EntityBaseClass *arg0, float arg1, unsigned int arg2, unsigned int arg3, bool arg4);
    PlingEffect *CreatePling(EntityBaseClass *arg0, float (*arg1)[4], unsigned int arg2, unsigned int arg3, bool arg4);
    GhostEffect *CreateGhost(PMeshNode *arg0);
    MotionBlurEffect *CreateMotionBlurEffect(PMNode *arg0, unsigned int arg1, int arg2);
    int CreateOneshot(unsigned int arg0, unsigned int arg1, PMat4 *arg2, EntityBaseClass *arg3, float arg4, int arg5, bool arg6);
    int CreateOneshot(unsigned int arg0, unsigned int arg1, float (*arg2)[4], float (*arg3)[4], EntityBaseClass *arg4, float arg5, bool arg6, int arg7, bool arg8);
    EffectNode *EffectValid(unsigned int arg0);
    void DeleteEffect(EffectNode *arg0);
    void DeleteEffect(EntityBaseClass *arg0);
    void DeleteEffect(unsigned int arg0);
    int Render(PLightManager *arg0);
    void Reset();
    void Animate(float arg0);
    void EnableParticleFx(bool arg0);

    unsigned int m_unk0;        // 0x000 effect count (PArray base region)
    unsigned int m_unk4;        // 0x004 scan index used by EffectValid
    EffectNode **m_ppEntries;   // 0x008 entry array
    char _pad00C[4];
    int m_unk10;                // 0x010 next effect id
};

class EffectNode {
public:
    EffectNode() { m_unk4 = 0; m_unkC = 0; }
    virtual ~EffectNode();
    void SendDeleteEvent(int arg0);
    int Update(float arg0);
    int Render(PLightManager *arg0);

    int m_unk4;                 // 0x004 object whose virtual slot 3 draws the node
    int m_unk8;                 // 0x008 argument forwarded to SendDeleteEvent
    unsigned char m_unkC;       // 0x00C flag; gates the light pointer in Render
};

class PlingEffect : public EffectNode {
public:
    PlingEffect(EntityBaseClass *arg0, float (*arg1)[4], unsigned int arg2, unsigned int arg3, bool arg4);
    virtual ~PlingEffect();
    int Update(float arg0);

    EntityBaseClass *m_unk10;   // 0x010 owner entity
    int m_unk14;                // 0x014 cleared when an existing pling is reused
    int m_unk18;                // 0x018 owner's word at +4, or 0 without an owner
    char _pad01C[4];
    float m_unk20[3];           // 0x020 first three floats of the float[4] argument (16-byte copy)
    int m_unk2C;                // 0x02C zeroed after the copy
};

class GhostEffect : public EffectNode {
public:
    GhostEffect(PMeshNode *arg0);
    virtual ~GhostEffect();
    int Update(float arg0);
    int Render(PLightManager *arg0);

    u_long128 m_unk10[8];       // 0x010 per-slot matrix rows (world translation in row 3)
    unsigned char m_unk90[8];   // 0x090 per-slot visibility flags
    void *m_unk98;              // 0x098 PMesh pointer
    short m_unk9C;              // 0x09C slot count
    unsigned char m_unk9E;      // 0x09E parity byte
    unsigned char m_unk9F;      // 0x09F wrap flag
};

class OneshotEffect : public EffectNode {
public:
    OneshotEffect(unsigned int arg0, unsigned int arg1, PMat4 *arg2, EntityBaseClass *arg3, float arg4, int arg5, bool arg6);
    OneshotEffect(unsigned int arg0, unsigned int arg1, float (*arg2)[4], float (*arg3)[4], EntityBaseClass *arg4, float arg5, bool arg6, int arg7, bool arg8);
    virtual ~OneshotEffect();
    int Update(float arg0);

    int m_unk10;                // 0x010
    EntityBaseClass *m_unk14;   // 0x014 owner entity
    unsigned int m_unk18;       // 0x018
    unsigned char m_unk1C;      // 0x01C
};

class PMotionBlur {
public:
    PMotionBlur();
    ~PMotionBlur();

    char _pad[0xB0];
};

class MotionBlurEffect : public EffectNode {
public:
    virtual ~MotionBlurEffect();

    PMotionBlur m_unk10;        // 0x010 PMotionBlur member
};

#endif
