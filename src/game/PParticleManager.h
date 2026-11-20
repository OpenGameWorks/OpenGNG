#ifndef PPARTICLEMANAGER_H
#define PPARTICLEMANAGER_H

#include "types.h"

class PParticleSystem;
class PParticleRain;
class PMovingFog;
class PParticleFog;
class PStaticInstanceGroup;
class PParticleOneShot;
class PFrozenFx;
class PParticleBlowingLeaves;
class PMNode;
class PParticleSystem;
class PFrustrum;
struct tagVuParticle;
struct tagParticleRainParams;
class PParticleGas;
struct tagParticleGasParams;
struct tagParticleMovingFogParams;
struct tagParticleFogData;
class PPakFile;
class Camera;

// Effect type selector for EnableFxByType. Enumerator values are not yet
// recovered; the placeholder only gives the enum a definition.
enum ePSType {
    ePSType_Unknown = 0
};

// Layer selector for RemoveAllParticleSystems(ePSLayer). Same enum as MaxEngine.h;
// no TU includes both headers yet, so the duplicate is harmless until they merge.
enum ePSLayer {
    ePSLayer_2 = 2
};

// File version selector for pak loaders. Enumerator values are not yet
// recovered; same placeholder as PWorld.h.
enum ePsx2FileVersion {
    ePsx2FileVersion_Placeholder = 0
};

class PParticleManager {
public:
    void EnableFxByType(ePSType eType, bool bFlag);
    void *AllocAuraParticle();
    void FreeAuraParticle(tagVuParticle *pParticle);
    void DestroyMovingFog();
    void CreateMovingFog(tagParticleMovingFogParams *pParams);
    int CreateFog(tagParticleFogData *pData);
    int LoadFogObjects(PPakFile *pFile, ePsx2FileVersion nVersion);
    void SetLightningDensity(float fDensity);
    void SetRainDensity(float fDensity, bool bFlag);
    void SetRainDensity(unsigned int hRain, float fDensity, bool bFlag);
    void DestroyRain();
    void CreateRain(float fDensity);
    PParticleRain *CreateRain(tagParticleRainParams *pParams);
    int CreateEweedReaction(float *pPos);
    int CreateSulphurReaction(float *pPos, float fUnused);
    int CreateGroundDust(float *pPos, float fScale);
    PFrozenFx *CreateFrozenFx(PMNode *pNode, float fA, float fB);
    PParticleBlowingLeaves *CreateBlowingLeaves(float *pA, float *pB, float *pC, int nA, float fF, bool bFlag);
    void InitHeatHazeBuffer();
    void UpdateHeatHazeBuffer();
    void RenderAuraParticles();
    void AnimateEweedReactionFx(PFrustrum *pFrustrum, float fDt);
    void RenderEweedReactionFx();
    void InitEweedReactionFx();
    void DestroyEweedReactionFx();
    void InitSulphurReactionFx();
    void AnimateSulphurReactionFx(PFrustrum *pFrustrum, float fDt);
    void RenderSulphurReactionFx();
    void DestroySulphurReactionFx();
    void RenderGroundDustFx();
    void DestroyGroundDustFx();
    void InitGroundDustFx();
    int GetFxTexture(unsigned int hFx);
    PParticleOneShot *Create(unsigned int hFx, float fA, float fB, float fC, PMNode *pNode, bool bFlag);
    PParticleOneShot *CreateOneShot(unsigned int hFx, float fA, float fB, float fC);
    PParticleGas *CreateGasFx(tagParticleGasParams *pParams, float fA, float fB, float fC);
    int IsValid(PParticleSystem *pSystem);
    void RenderParticleInstanceGroups(bool bFlag);
    void AddParticleInstanceGroup(PStaticInstanceGroup *pGroup);
    void AddMasterParticleInstance(PParticleSystem *pFx);
    void RemoveAll();
    void Stop(unsigned int hSystem);
    void StopFx(unsigned int hSystem);
    void Destroy(unsigned int hSystem);
    void Shutdown();
    int Init();
    PParticleManager();
    ~PParticleManager();

    void Add(PParticleSystem *pSystem);
    void Remove(PParticleSystem *pSystem);
    void RemoveAllParticleSystems();
    void RemoveAllParticleSystems(ePSLayer eLayer);
    void RemoveAllFogObjects();
    void UpdateMasterParticleInstances(float fDt, PFrustrum *pFrustrum);
    void Update(float fDt, Camera *pCamera, PFrustrum *pFrustrum, ePSLayer eLayer);
    void *InitRingMeshPacket(int &nOut, int nCount, bool bFlag, float fA, float fB, int nC, int nD);
    int CreateRingTriStrip(int nCount, float fA, float fB, float fC, float fD, int nE, int nF, float (*pA)[4], float (*pB)[4], float (*pC)[4]);
    void InitShockwaveRings();
    void RenderShockwaveRings();
    void AnimateGroundDustFx(PFrustrum *pFrustrum, float fDt);

    unsigned int m_unk0;        // 0x00 list count
    unsigned int m_unk4;        // 0x04 list index
    void **m_unk8;              // 0x08 list storage of PParticleSystem pointers
    char _pad00C[0x10 - 0x0C];
    unsigned int m_unk10;       // 0x10 second list count
    unsigned int m_unk14;       // 0x14 second list index
    void **m_unk18;             // 0x18 second list storage (elements have a virtual dtor, slot 8)
    char _pad01C[0x20 - 0x1C];
    unsigned int m_unk20;       // 0x20
    unsigned int m_unk24;       // 0x24
    PParticleFog **m_unk28;     // 0x28
    char _pad02C[0x30 - 0x2C];
    char m_unk30[0x10];         // 0x30 memset target in Init
    void *m_unk40;              // 0x40 PResourceManager, passed to LoadGlobalResource
    char _pad44[0x50 - 0x44];
    char m_unk50[0x620];        // 0x50 GS frame buffer copy packet, sent with size 0x620
    int m_unk670;               // 0x670
    char _pad674[0x680 - 0x674];
    float m_unk680[4];          // 0x680 camera matrix row block, copied from pCamera
    float m_unk690[4];          // 0x690 camera matrix row block, copied from pCamera + 0x20
    int m_unk6A0;               // 0x6A0 float constant, stored by Init
    int m_unk6A4;               // 0x6A4 float constant, stored by Init
    PParticleRain *m_pRain;     // 0x6A8
    char _pad6AC[0x9B0 - 0x6AC];
    unsigned char m_unk9B0;     // 0x9B0
    char _pad9B1[0x9B4 - 0x9B1];
    PMovingFog *m_unk9B4;       // 0x9B4
    char _pad9B8[0x9C0 - 0x9B8];
    char m_unk9C0[0x500];       // 0x9C0 memset target in Init
    int m_unkEC0;               // 0xEC0
    int m_unkEC4;               // 0xEC4
    char _padEC8[0xED0 - 0xEC8];
    char m_unkED0[0x10];        // 0xED0 PParticleRipples object, Init(6, 1, 1)
    int m_unkEE0;               // 0xEE0
    char _padEE4[0x1790 - 0xEE4];
    char m_unk1790[0x10];       // 0x1790 PParticleRipples object, Init(6, 0, 0)
    int m_unk17A0;              // 0x17A0 GetFxTexture(0x8400000D) result
    char _pad17A4[0x2050 - 0x17A4];
    void *m_unk2050;            // 0x2050
    unsigned int m_unk2054;     // 0x2054
    void *m_unk2058;            // 0x2058
    unsigned int m_unk205C;     // 0x205C
    unsigned int m_unk2060;     // 0x2060
    unsigned int m_unk2064;     // 0x2064
    unsigned int m_unk2068;     // 0x2068
    unsigned int m_unk206C;     // 0x206C
    PStaticInstanceGroup **m_unk2070; // 0x2070
    char _pad2074[0x2078 - 0x2074];
    unsigned int m_unk2078;     // 0x2078
    unsigned int m_unk207C;     // 0x207C
    PParticleSystem **m_unk2080; // 0x2080
    char _pad2084[0x20FC - 0x2084];
    PParticleSystem *m_unk20FC; // 0x20FC
};

#endif
