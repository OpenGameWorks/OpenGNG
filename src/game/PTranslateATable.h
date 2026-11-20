#ifndef PTRANSLATEATABLE_H
#define PTRANSLATEATABLE_H

#include "types.h"

class PTranslateATable {
public:
    static int FindASubTableRandomItem(unsigned int *o_pRes, unsigned int nItems, int (*pCallback)(unsigned int), const unsigned int *i_pTable);
    static int FindASubTable(const unsigned int **o_ppTable, unsigned int *o_pCount, unsigned int key, const unsigned int *i_pTable);
    static int TranslateUIntToUInt(unsigned int *o_pRes, unsigned int nItems, const unsigned int *i_pTable);
};

#endif
