// FLAGS: -str readonly
#include "CEifInstance.h"
#include "types.h"

// TODO(header): foreign declarations
class PPakFile;
class tagEditableVariableData;
extern "C" void CdsAssert__FPciPc(char *pFile, int nLine, char *pExpr);
extern "C" int Read__7PCDFileFPvUi(void *pThis, void *pBuffer, unsigned int nSize);
extern "C" void __ct__23tagEditableVariableDataFv(void *pThis);
extern "C" void __dla__FPv(void *pBlock);
extern "C" void *__nwa__FUi(unsigned int nSize);
extern "C" void *__construct_new_array(void *pArray, void (*pCtor)(void *), void (*pDtor)(void *), unsigned int nElemSize, int nCount);
extern "C" void *memset(void *pDst, int nValue, unsigned int nSize);

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert__FPciPc("CEifInstance.cpp", line, #cond))

// FUNCTION: 0x00172A20 SetStartPosition__12CEifInstanceFfff
void CEifInstance::SetStartPosition(float fA, float fB, float fC) {
    m_unk10C = fA;
    m_unk110 = fB;
    m_unk114 = fC;
}

// FUNCTION: 0x00172A30 GetInstanceID__12CEifInstanceFv
int CEifInstance::GetInstanceID() {
    return *(int *)((char *)this + 0x108);
}

// FUNCTION: 0x00172A40 GetFlags__12CEifInstanceFv
int CEifInstance::GetFlags() {
    return *(int *)((char *)this + 0x100);
}

// FUNCTION: 0x172A50 GetEditVarData__12CEifInstanceFi
tagEditableVariableData *CEifInstance::GetEditVarData(int nIndex)
{
    if (nIndex >= m_unk124) {
        CdsAssert__FPciPc("CEifInstance.cpp", 0x104, "iVarIndex < mData.iNumEditVars");
    }
    return (tagEditableVariableData *)((char *)m_unk128 + nIndex * 0x38);
}

// FUNCTION: 0x00172AC0 GetNumEditVars__12CEifInstanceFv
int CEifInstance::GetNumEditVars() {
    return m_unk124;
}

// FUNCTION: 0x172AD0 GetStartOrientation__12CEifInstanceFRfRfRf
void CEifInstance::GetStartOrientation(float &fX, float &fY, float &fZ)
{
    fX = m_unk118;
    fY = m_unk11C;
    fZ = m_unk120;
}

// FUNCTION: 0x172AF0 GetStartPosition__12CEifInstanceFRfRfRf
void CEifInstance::GetStartPosition(float &fX, float &fY, float &fZ)
{
    fX = m_unk10C;
    fY = m_unk110;
    fZ = m_unk114;
}

// FUNCTION: 0x00172B20 GetEntityID__12CEifInstanceFv
int CEifInstance::GetEntityID() {
    return *(int *)((char *)this + 0x104);
}

// FUNCTION: 0x172B30 Read__12CEifInstanceFP8PPakFileUi
int CEifInstance::Read(PPakFile *pFile, unsigned int nVersion)
{
    int nCount;

    if (pFile == 0) {
        CdsAssert__FPciPc("CEifInstance.cpp", 0x2B, "pFile");
    }
    if (m_unk128 != 0) {
        if (m_unk128 != 0) {
            __dla__FPv((char *)m_unk128 - 0x10);
        }
        m_unk128 = 0;
    }
    if (Read__7PCDFileFPvUi(pFile, this, 0x104) != 0x104) {
        return 0;
    }
    if (Read__7PCDFileFPvUi(pFile, (char *)this + 0x104, 0x24) != 0x24) {
        return 0;
    }
    nCount = m_unk124;
    if (nCount != 0) {
        m_unk128 = (tagEditableVariableData *)__construct_new_array(
            __nwa__FUi(nCount * 0x38 + 0x10), __ct__23tagEditableVariableDataFv, 0, 0x38, nCount);
        if (m_unk128 == 0) {
            CdsAssert__FPciPc("CEifInstance.cpp", 0x6F, "mpEditVarsData");
        }
        memset(m_unk128, 0, m_unk124 * 0x38);
        if (nVersion < 0x10003) {
            CDS_ASSERT(0x76, !"Out of date EIF. Re-save EIF with latest runtime.");
        } else {
            unsigned int nBytes = m_unk124 * 0x38;
            if (nBytes != Read__7PCDFileFPvUi(pFile, m_unk128, nBytes)) {
                if (m_unk128 != 0) {
                    __dla__FPv((char *)m_unk128 - 0x10);
                }
                m_unk128 = 0;
                return 0;
            }
        }
    }
    return 1;
}
