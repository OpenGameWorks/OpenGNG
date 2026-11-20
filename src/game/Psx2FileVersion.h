#ifndef PSX2FILEVERSION_H
#define PSX2FILEVERSION_H

// File version selector for pak loaders, shared by every loader header so that
// any of them can be included together. Enumerator values are not recovered
// yet; the name is what the mangled signatures need.
enum ePsx2FileVersion {
    ePsx2FileVersion_Placeholder = 0
};

#endif
