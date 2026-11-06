#ifndef PSO_SYSTEM_GSL_ARCHIVE_H
#define PSO_SYSTEM_GSL_ARCHIVE_H

#include "types.h"
#include <stddef.h>

struct GslArchiveEntry {
    char name[0x20];
    s32 archive_offset;
    s32 file_size;
    s32 decoded_size;
    u8 field_2C[4];
};
typedef char GslArchiveEntryExtent[sizeof(GslArchiveEntry) == 0x30 ? 1 : -1];
typedef char GslArchiveOffsetOffset[offsetof(GslArchiveEntry, archive_offset) == 0x20 ? 1 : -1];
typedef char GslArchiveFileSizeOffset[offsetof(GslArchiveEntry, file_size) == 0x24 ? 1 : -1];
typedef char GslArchiveDecodedSizeOffset[offsetof(GslArchiveEntry, decoded_size) == 0x28 ? 1 : -1];

// The second argument is unused (callers pass 0 and 1).
GslArchiveEntry *find_gsl_entry(void *name, s32 unused);
extern "C" {
void open_gsl_archive(char *name);
void close_gsl_archive(void);
}
extern GslArchiveEntry gsl_archive_entries[256];
extern char gsl_archive_filename[32];

#endif
