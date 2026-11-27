// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PRenderPass.h"
#include "PArray.h"

// TODO(header): foreign declarations
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dt__7PSTAnimFv(void *pThis, short nFlag);
extern "C" void UnloadDynamicTexture__15PTextureManagerFi(void *pThis, int nId);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuf, unsigned int nSize);
extern "C" int Load__7PSTAnimFP8PPakFile(void *pThis, void *pFile);
extern "C" void *__nw__FUi(unsigned int nSize);
extern "C" PSTAnim *__ct__7PSTAnimFv(PSTAnim *pThis);
extern char gGfxEng[1504384];
extern char st1_anim_start[0x10];
extern char st1_copy_anim_start[0x10];
extern char ref_map_start[0x10];
extern char refraction_map_start[0x10];
extern char two_point_lights_start[0x10];
extern char shared_vertices_start[0x10];
extern char apply_multipass_color_on_output_start[0x10];
extern char apply_multipass_color_on_input_start[0x10];
extern char apply_multipass_color_stq_start[0x10];
extern char apply_multipass_color_st1_start[0x10];
extern char apply_multipass_color_st2_start[0x10];
extern char apply_multipass_color_st3_start[0x10];
extern char restore_st1_start[0x10];
extern char restore_st2_start[0x10];
extern char restore_st3_start[0x10];

#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("PRenderPass.cpp", line, #cond))

struct RenderPassU64Table {
    long long v[5];
};

struct RenderPassWordTable {
    unsigned int v[18];
};


struct RenderPassHeader {
    int m_unk0;             // 0x00 index into PArray storage (signed)
    int m_unk4;             // 0x04 type, 5 selects the manager path
    int m_unk8;             // 0x08 index into the u64 table
    int m_unkC;             // 0x0C flags
    unsigned char m_unk10[16];  // 0x10
    int m_unk20[8];         // 0x20 indices into the word table
};

// DRAFT: 0x001963B0 Load__11PRenderPassFP8PPakFileP6PArray
// note: 114 words from 0x1D0; tables are now initializers ({0,0x44,0x48,0x80000000A1,0x46} rodata, zeroed word table in .bss). Original keeps unfolded bases sp+0x94/0x9C (hdr fields) and sp+0xD0/0x100 (tables) in registers; pointer locals and direct indexing both fold them.
int PRenderPass::Load(PPakFile *pFile, PArray *pArr) {
    RenderPassHeader hdr;
    RenderPassU64Table tbl64 = {{0, 0x44, 0x48, 0x80000000A1LL, 0x46}};
    RenderPassWordTable tbl = {{0}};

    tbl.v[1] = (unsigned int)st1_anim_start >> 3;
    tbl.v[2] = (unsigned int)st1_copy_anim_start >> 3;
    tbl.v[3] = (unsigned int)ref_map_start >> 3;
    tbl.v[5] = (unsigned int)refraction_map_start >> 3;
    tbl.v[6] = (unsigned int)two_point_lights_start >> 3;
    tbl.v[7] = (unsigned int)shared_vertices_start >> 3;
    tbl.v[8] = (unsigned int)apply_multipass_color_on_output_start >> 3;
    tbl.v[9] = (unsigned int)apply_multipass_color_on_input_start >> 3;
    tbl.v[10] = (unsigned int)apply_multipass_color_stq_start >> 3;
    tbl.v[11] = (unsigned int)apply_multipass_color_st1_start >> 3;
    tbl.v[12] = (unsigned int)apply_multipass_color_st2_start >> 3;
    tbl.v[13] = (unsigned int)apply_multipass_color_st3_start >> 3;
    tbl.v[15] = (unsigned int)restore_st1_start >> 3;
    tbl.v[16] = (unsigned int)restore_st2_start >> 3;
    tbl.v[17] = (unsigned int)restore_st3_start >> 3;

    CDS_ASSERT(0x7B, pArr);
    CDS_ASSERT(0x7C, pFile);

    if (Read__7PCDFileFPvUi(pFile, &hdr, 0x40) != 0x40) {
        return 0;
    }
    m_unk4 = hdr.m_unk4;
    *(u_long128 *)&m_unk10 = *(u_long128 *)hdr.m_unk10;
    long long *pU64 = tbl64.v;
    unsigned int *pWord = tbl.v;
    m_unk20 = pU64[hdr.m_unk8];
    m_unk3 = (hdr.m_unkC & 2) != 0;
    m_unk2C = pWord[hdr.m_unk20[0]];
    m_unk30 = pWord[hdr.m_unk20[1]];
    m_unk34 = pWord[hdr.m_unk20[2]];
    m_unk38 = pWord[hdr.m_unk20[3]];
    m_unk3C = pWord[hdr.m_unk20[4]];
    m_unk40 = pWord[hdr.m_unk20[5]];
    m_unk44 = pWord[hdr.m_unk20[6]];
    m_unk48 = pWord[hdr.m_unk20[7]];

    if (hdr.m_unk0 >= 0) {
        int nVal = 0;
        if ((unsigned int)hdr.m_unk0 < pArr->m_unk0) {
            nVal = ((int *)pArr->m_unk8)[hdr.m_unk0];
        }
        m_unk8 = nVal;
        if (m_unk8 == 0) {
            return 0;
        }
        m_unk0 = 1;
        m_unk2 = 1;
    } else if (hdr.m_unk4 == 5) {
        char *pMgr = gGfxEng + 0x154F00;
        CDS_ASSERT(0xA6, pMgr);
        m_unk8 = *(int *)(pMgr + 0x670);
        m_unk0 = 0;
        m_unk2 = 1;
    }

    if (hdr.m_unkC & 1) {
        CDS_ASSERT(0xAF, m_unk28 == 0);
        PSTAnim *pAnim = (PSTAnim *)__nw__FUi(0x60);
        if (pAnim == 0) {
            m_unk28 = 0;
        } else {
            m_unk28 = __ct__7PSTAnimFv(pAnim);
        }
        if (m_unk28 == 0) {
            return 0;
        }
        if (Load__7PSTAnimFP8PPakFile(m_unk28, pFile) == 0) {
            return 0;
        }
    }
    m_unk1 = 1;
    return 1;
}

// FUNCTION: 0x001967C0 __dt__11PRenderPassFv
PRenderPass::~PRenderPass() {
    if (m_unk0 != 0) {
        if (m_unk8 != 0) {
            UnloadDynamicTexture__15PTextureManagerFi(gGfxEng + 0x154C90, m_unk8);
            m_unk8 = 0;
            m_unk0 = 0;
        }
    }
    if (m_unk28 != 0) {
        __dt__7PSTAnimFv(m_unk28, 1);
        m_unk28 = 0;
    }
    m_unk4 = 0;
}

// FUNCTION: 0x00196850 __ct__11PRenderPassFv
PRenderPass::PRenderPass() {
    m_unk4 = 0;
    m_unk8 = 0;
    m_unk0 = 0;
    m_unk20 = 0x44;
    m_unk1C = 1.0f;
    m_unk18 = 1.0f;
    m_unk14 = 1.0f;
    m_unk10 = 1.0f;
    m_unk1 = 0;
    m_unk2 = 0;
    m_unk28 = 0;
    m_unk3 = 0;
}
