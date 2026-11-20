#include "types.h"
#include "PTranslateATable.h"
#include "MathAPI.h"

// TODO(header): foreign declarations
void CdsAssert(char *file, int line, char *expr);

// DRAFT: 0x001F1B10 FindASubTableRandomItem__16PTranslateATableFPUiUiPFUi_iPCUi
// note: 72 words differ; branch sense at the count test and the callback loop's register use (item in s4, found in s0) differ. Tried: local order, if/else and || early return (72), nested callback test (72, reverted).
int PTranslateATable::FindASubTableRandomItem(unsigned int *o_pRes, unsigned int nItems, int (*pCallback)(unsigned int), const unsigned int *i_pTable)
{
    unsigned int count;
    const unsigned int *table;
    unsigned int r;
    unsigned int i;
    unsigned int idx;
    unsigned int item;
    int found;

    if (FindASubTable(&table, &count, nItems, i_pTable) != 0 || count == 0) {
        return -1;
    }
    r = MathAPI::RandomIntRange(0, count - 1);
    item = table[r];
    found = 1;
    if (pCallback != 0 && pCallback(item) != 0) {
        found = 0;
        if (count >= 2) {
            for (i = 1; i < count - 1; i++) {
                idx = i + r;
                if (idx >= count) {
                    idx -= count;
                    if (idx >= count) {
                        CdsAssert("PTranslateATable.cpp", 0x1D3, "jj<nItems");
                    }
                }
                item = table[idx];
                if (pCallback(item) == 0) {
                    found = 1;
                    break;
                }
            }
        }
    }
    if (found == 0) {
        return -1;
    }
    if (o_pRes != 0) {
        *o_pRes = item;
    }
    return 0;
}

// FUNCTION: 0x001F1C70 FindASubTable__16PTranslateATableFPPCUiPUiUiPCUi
int PTranslateATable::FindASubTable(const unsigned int **o_ppTable, unsigned int *o_pCount, unsigned int key, const unsigned int *i_pTable)
{
    const unsigned int *p;
    unsigned int k;
    unsigned int count;

    if (i_pTable == 0 || o_ppTable == 0 || o_pCount == 0) {
        return -1;
    }
    p = i_pTable;
    for (;;) {
        k = p[0];
        if (k == 0) {
            break;
        }
        count = p[1];
        p += 2;
        if (k == key) {
            *o_ppTable = p;
            *o_pCount = count;
            return 0;
        }
        p += count;
    }
    return -1;
}

// DRAFT: 0x001F1CE0 TranslateUIntToUInt__16PTranslateATableFPUiUiPCUi
// note: 47 words differ; loop bottom placement and the branch sense of the o_pRes/i_pTable guards differ. Tried: null-check order, && guard (49), in-place p advance (48), reloading key/type (worse).
int PTranslateATable::TranslateUIntToUInt(unsigned int *o_pRes, unsigned int nItems, const unsigned int *i_pTable)
{
    const unsigned int *p;
    unsigned int key;
    unsigned int type;

    if (o_pRes != 0) {
      if (i_pTable != 0) {
        key = i_pTable[0];
        type = i_pTable[1];
        p = i_pTable + 2;
        for (;;) {
            if (p[0] == key) {
                if (type == 1) {
                    *o_pRes = p[1];
                    return 2;
                }
                return 1;
            }
            if (p[0] == nItems) {
                *o_pRes = p[1];
                return 0;
            }
            p += 2;
        }
      }
    }
    if (o_pRes == 0) {
        CdsAssert("PTranslateATable.cpp", 0x65, "o_pRes");
    }
    if (i_pTable == 0) {
        CdsAssert("PTranslateATable.cpp", 0x66, "i_pTable");
    }
    return -1;
}
