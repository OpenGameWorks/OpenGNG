// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "Fog.h"
#include "PZBufferFog.h"

// TODO(header): foreign declarations
extern char gEng[105360];
extern "C" void memcpy(void *, const void *, unsigned int);
extern "C" void memset(void *, int, unsigned int);

// Float to byte through an unsigned int conversion: CodeWarrior's cvt.w.s path,
// with the 2^31 subtraction and bit-31 or for values at or above 2^31, then sb.
#define FOG_BYTE(x) ((unsigned char)(unsigned int)(x))

// FUNCTION: 0x001CF160 OutputDebug__3FogFv
void Fog::OutputDebug() {
}

// FUNCTION: 0x001CF170 GetClassName__3FogFv
const char *Fog::GetClassName() {
    return "Fog";
}

// DRAFT: 0x001CF180 SetEditableVars__3FogFPc
// note: 488 words differ (of 0xAA0 bytes): the loop-invariant constants (255.0f, 2^31, 0x8000, 128.0f, 32.0f) and tbl/col addresses are hoisted into different registers at 0x258-0x27C; SetClutFogTable call sits 0x10 bytes early (0xA70 vs 0xA80); gEng addend differs (lui 0x2E/addiu -0x7E40 vs lui 0x1/addiu -0x78B0). Tried FOG_BYTE forms (ternary, statement macro, unsigned-int cast = best), operand swap, and p = tbl + i*4 (no change).
void Fog::SetEditableVars(char *pSrc) {
    float col[4];
    unsigned char tbl[0x400];
    unsigned char *p;
    float t;
    float r;
    float g;
    float b;
    float a;
    int i;

    memcpy(&m_unk1B0, pSrc, 0x6C);
    m_unk21C = (PZBufferFog *)(gEng + 0x8750);
    if (m_unk21C == 0) {
        CdsAssert("Fog.cpp", 0x34, "m_FogObj");
    }
    m_unk21C->m_unk17A9 = 1;
    col[0] = 255.0f * m_unk1B4;
    col[1] = 255.0f * m_unk1B8;
    col[2] = 255.0f * m_unk1BC;
    m_unk21C->SetColor(col, false, 15.0f);
    m_unk21C->SetDensity(m_unk1B0, false, 15.0f);
    m_unk21C->m_unk17AA = m_unk1C4 != 0;
    m_unk21C->SetClutFogAlpha(m_unk218);
    memset(tbl, 0, 0x400);

    r = m_unk208 * 255.0f;
    tbl[0] = FOG_BYTE(r);
    g = 255.0f * m_unk20C;
    tbl[1] = FOG_BYTE(g);
    b = 255.0f * m_unk210;
    tbl[2] = FOG_BYTE(b);
    a = 128.0f * m_unk214;
    tbl[3] = FOG_BYTE(a);

    i = 1;
    do {
        t = (float)i / 32.0f;
        r = m_unk208;
        col[0] = r + t * (m_unk1F8 - r);
        g = m_unk20C;
        col[1] = g + t * (m_unk1FC - g);
        b = m_unk210;
        col[2] = b + t * (m_unk200 - b);
        a = m_unk214;
        col[3] = a + t * (m_unk204 - a);
        p = &tbl[i * 4];
        r = 255.0f * col[0];
        p[0] = FOG_BYTE(r);
        g = 255.0f * col[1];
        p[1] = FOG_BYTE(g);
        b = 255.0f * col[2];
        p[2] = FOG_BYTE(b);
        a = 128.0f * col[3];
        p[3] = FOG_BYTE(a);
        i += 1;
    } while (i < 0x20);

    i = 0x20;
    do {
        t = (float)(i - 0x20) / 32.0f;
        r = m_unk1F8;
        col[0] = r + t * (m_unk1E8 - r);
        g = m_unk1FC;
        col[1] = g + t * (m_unk1EC - g);
        b = m_unk200;
        col[2] = b + t * (m_unk1F0 - b);
        a = m_unk204;
        col[3] = a + t * (m_unk1F4 - a);
        p = &tbl[i * 4];
        r = 255.0f * col[0];
        p[0] = FOG_BYTE(r);
        g = 255.0f * col[1];
        p[1] = FOG_BYTE(g);
        b = 255.0f * col[2];
        p[2] = FOG_BYTE(b);
        a = 128.0f * col[3];
        p[3] = FOG_BYTE(a);
        i += 1;
    } while (i < 0x40);

    i = 0x40;
    do {
        t = (float)(i - 0x40) / 32.0f;
        r = m_unk1E8;
        col[0] = r + t * (m_unk1D8 - r);
        g = m_unk1EC;
        col[1] = g + t * (m_unk1DC - g);
        b = m_unk1F0;
        col[2] = b + t * (m_unk1E0 - b);
        a = m_unk1F4;
        col[3] = a + t * (m_unk1E4 - a);
        p = &tbl[i * 4];
        r = 255.0f * col[0];
        p[0] = FOG_BYTE(r);
        g = 255.0f * col[1];
        p[1] = FOG_BYTE(g);
        b = 255.0f * col[2];
        p[2] = FOG_BYTE(b);
        a = 128.0f * col[3];
        p[3] = FOG_BYTE(a);
        i += 1;
    } while (i < 0x60);

    i = 0x60;
    do {
        t = (float)(i - 0x60) / 32.0f;
        r = m_unk1D8;
        col[0] = r + t * (m_unk1C8 - r);
        g = m_unk1DC;
        col[1] = g + t * (m_unk1CC - g);
        b = m_unk1E0;
        col[2] = b + t * (m_unk1D0 - b);
        a = m_unk1E4;
        col[3] = a + t * (m_unk1D4 - a);
        p = &tbl[i * 4];
        r = 255.0f * col[0];
        p[0] = FOG_BYTE(r);
        g = 255.0f * col[1];
        p[1] = FOG_BYTE(g);
        b = 255.0f * col[2];
        p[2] = FOG_BYTE(b);
        a = 128.0f * col[3];
        p[3] = FOG_BYTE(a);
        i += 1;
    } while (i < 0x7F);

    r = 255.0f * m_unk1C8;
    tbl[0x1FC] = FOG_BYTE(r);
    g = 255.0f * m_unk1CC;
    tbl[0x1FD] = FOG_BYTE(g);
    b = 255.0f * m_unk1D0;
    tbl[0x1FE] = FOG_BYTE(b);
    a = 128.0f * m_unk1D4;
    tbl[0x1FF] = FOG_BYTE(a);

    m_unk21C->SetClutFogTable((GsRGBA *)tbl);
}

// FUNCTION: 0x001CFC20 Execute__3FogFv
void Fog::Execute() {
    switch (m_unk20) {
    case -1:
        SetState(0);
        break;
    case 0:
        break;
    case -2:
        if (m_unk21C == 0) {
            CdsAssert("Fog.cpp", 0x25, "m_FogObj");
        }
        m_unk21C->m_unk17A9 = 0;
        break;
    }
}

// FUNCTION: 0x001CFCA0 __dt__3FogFv
Fog::~Fog() {
    if (m_unk21C != 0) {
        m_unk21C->m_unk17A9 = 0;
    }
}

// FUNCTION: 0x001CFD10 __ct__3FogFv
Fog::Fog() : EntityBaseClass((LoadClass)5, 0) { EnableSleep(false, false); }
