#ifndef PSO_SYSTEM_GSLARCHIVESTUBS_H
#define PSO_SYSTEM_GSLARCHIVESTUBS_H

#include "types.h"

struct GslArchiveEntry;

// Empty stubs (each returns 0); on_gsl_archive_close, the GSL archive close hook,
// hands the closed archive's entries to gsl_archive_close_stub.
int gsl_archive_owner_stub(void);
void system_shutdown_stub(void);
void system_init_stub(void);
int gsl_archive_close_stub(s32, GslArchiveEntry *, s32);

#endif
