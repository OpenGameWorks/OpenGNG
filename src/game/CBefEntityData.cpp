// FLAGS: -str readonly
#include "CBefEntityData.h"
#include "types.h"

// TODO(header): foreign declarations
class PPakFile;
class tagBefEditableVariableData;
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuffer, unsigned int nSize);
extern "C" void __ct__26tagBefEditableVariableDataFv(void *pThis);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *__construct_new_array(void *pArray, void (*pCtor)(void *), void (*pDtor)(void *), unsigned int nElemSize, int nCount);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("CBefEntityData.cpp", line, #cond))

// FUNCTION: 0x00173330 Read__14CBefEntityDataFP8PPakFileUi
int CBefEntityData::Read(PPakFile *pFile, unsigned int nVersion)
{
    int nCount;
    int nBytes;

    if (pFile == 0) {
        CdsAssert__FPciPc("CBefEntityData.cpp", 0x49, "pFile");
    }
    if (Read__7PCDFileFPvUi(pFile, this, 4) != 4) {
        return 0;
    }
    if (Read__7PCDFileFPvUi(pFile, &m_unk4, 4) != 4) {
        return 0;
    }
    if (Read__7PCDFileFPvUi(pFile, _pad008, 0x80) != 0x80) {
        return 0;
    }
    if (Read__7PCDFileFPvUi(pFile, &m_unk88, 4) != 4) {
        return 0;
    }
    nCount = m_unk88;
    if (nCount > 0) {
        m_unk8C = (tagBefEditableVariableData *)__construct_new_array(
            __nwa__FUi(nCount * 0x58 + 0x10), __ct__26tagBefEditableVariableDataFv, 0, 0x58, nCount);
        if (m_unk8C == 0) {
            CdsAssert__FPciPc("CBefEntityData.cpp", 0x77, "mpEditVarsData");
        }
        memset(m_unk8C, 0, m_unk88 * 0x58);
        if (nVersion < 0x10001) {
            CDS_ASSERT(0x7E, !"Out of date BEF. Re-save EIF with latest runtime.");
        } else {
            nBytes = m_unk88 * 0x58;
            if (Read__7PCDFileFPvUi(pFile, m_unk8C, nBytes) != nBytes) {
                if (m_unk8C != 0) {
                    __dla__FPv((char *)m_unk8C - 0x10);
                }
                m_unk8C = 0;
                return 0;
            }
        }
    }
    return 1;
}
