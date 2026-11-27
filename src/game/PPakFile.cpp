// FLAGS: -str readonly
#include "types.h"
#include "Debug.h"
#include "PPakFile.h"

// TODO(header): foreign declarations

// The game's assert evaluates the condition at runtime, so assert(!"msg") keeps the literal-address test.
#define CDS_ASSERT(line, cond) ((cond) ? (void)0 : CdsAssert("PPakFile.cpp", line, #cond))

// FUNCTION: 0x001D5ED0 GetFileType__8PPakFileFv
int PPakFile::GetFileType() {
    int v;
    if (Read(&v, 4) != 4) {
        CDS_ASSERT(0x43, !"Wrong file type in Pak file");
        return 0;
    }
    return v;
}

// FUNCTION: 0x001D5F40 IsValidFileType__8PPakFileFi
int PPakFile::IsValidFileType(int iType) {
    int v;
    if (Read(&v, 4) != 4) {
        CDS_ASSERT(0x35, !"Wrong file type in Pak file");
        return 0;
    }
    return v == iType;
}

// FUNCTION: 0x001D5FC0 GetData__8PPakFileFPCc
PPakFile *PPakFile::GetData(const char *pFileName) {
    int aHeader[6];
    CDS_ASSERT(0x16, pFileName);
    if (Open(pFileName, OPEN_READ) == 0) {
        CDS_ASSERT(0x19, !"Unable to open PAK file!");
        return 0;
    }
    if (Read(aHeader, 0x18) != 0x18) {
        CDS_ASSERT(0x21, !"Error reading pak file header!");
        return 0;
    }
    if (aHeader[0] != 0xDECAFA) {
        CDS_ASSERT(0x27, !"PAK file corrupt. Magic number mismatch!");
        return 0;
    }
    return this;
}

// FUNCTION: 0x001D6100 __dt__8PPakFileFv
PPakFile::~PPakFile() {
    Close();
}
