#ifndef PSO_SYSTEM_GSLARCHIVESTUBS_H
#define PSO_SYSTEM_GSLARCHIVESTUBS_H

#include "types.h"

struct GslArchiveEntry;

// Empty stubs (each returns 0); fn_800F93B4, the GSL archive close hook,
// hands the closed archive's entries to fn_800FFE14.
int fn_800FFE04(void);
void fn_800FFE0C(void);
void fn_800FFE10(void);
int fn_800FFE14(s32, GslArchiveEntry *, s32);

#endif
