#ifndef PPAKFILE_H
#define PPAKFILE_H

#include "types.h"
#include "PCDFile.h"

class PPakFile : public PCDFile {
public:
    ~PPakFile();
    int GetFileType();
    int IsValidFileType(int iType);
    PPakFile *GetData(const char *pFileName);
};

#endif
