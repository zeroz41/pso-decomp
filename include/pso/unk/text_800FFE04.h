#ifndef PSO_UNK_TEXT_800FFE04_H
#define PSO_UNK_TEXT_800FFE04_H

#include "types.h"

struct GslArchiveEntry;

// Empty stubs (each returns 0); fn_800F93B4, the GSL archive close hook,
// hands the closed archive's entries to fn_800FFE14.
extern "C" {
int fn_800FFE04(void);
int fn_800FFE14(s32, GslArchiveEntry *, s32);
}

#endif
