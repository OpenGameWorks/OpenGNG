#include "types.h"
#include "PShader.h"
#include "PSTAnim.h"

// TODO(header): foreign declarations
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);
extern "C" void __dla__FPv(void *pMem);
extern "C" void __dl__FPv(void *pMem);
extern "C" void __dt__7PSTAnimFv(void *pThis, short nFlag);
extern "C" void UnloadDynamicTexture__15PTextureManagerFi(void *pThis, int nId);
extern char gGfxEng[1504384];

// FUNCTION: 0x00196F80 Animate__7PShaderFfb
void PShader::Animate(float fTime, bool bFlag) {
    if (m_unk4 & 1) {
        for (unsigned int i = 0; i < m_unk8; i++) {
            PSTAnim *p = m_unk30[i];
            if (p) {
                p->Animate(fTime, bFlag);
            }
        }
    }
}

// FUNCTION: 0x00197010 SetSTAnimOptions__7PShaderFb
void PShader::SetSTAnimOptions(bool bFlag) {
    if (m_unk4 & 1) {
        for (unsigned int i = 0; i < m_unk8; i++) {
            PSTAnim *p = m_unk30[i];
            if (p) {
                p->m_unk3 = bFlag;
            }
        }
    }
}

// FUNCTION: 0x00197300 Destroy__7PShaderFv
void PShader::Destroy() {
    if (m_unk0) {
        __dla__FPv(m_unk0);
        m_unk0 = 0;
    }
    for (unsigned int i = 0; i < m_unk8; i++) {
        if (m_unk30[i]) {
            __dt__7PSTAnimFv(m_unk30[i], 1);
            m_unk30[i] = 0;
        }
        if (m_unk54[i]) {
            if (m_unk20[i]) {
                UnloadDynamicTexture__15PTextureManagerFi(gGfxEng + 0x154C90, m_unk20[i]);
                m_unk54[i] = 0;
                m_unk54[i] = 0;
            }
        }
    }
}

// FUNCTION: 0x001973D0 __dt__7PShaderFv
extern "C" void *__dt__7PShaderFv(PShader *pThis, short nFlag) {
    if (pThis) {
        pThis->Destroy();
        if (nFlag > 0) {
            __dl__FPv(pThis);
        }
    }
    return pThis;
}

// FUNCTION: 0x00197430 __ct__7PShaderFv
PShader::PShader() {
    m_unk0 = 0;
    m_unk4 = 0;
    m_unk8 = 0;
    m_unkC = 0;
    memset(_pad10, 0, 0x10);
    memset(m_unk20, 0, 0x10);
    memset(&m_unk50, 0, 4);
    memset(m_unk30, 0, 0x10);
    memset(_pad40, 0, 0x10);
    memset(m_unk54, 0, 4);
}
