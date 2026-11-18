#ifndef PSO_SYSTEM_RESOURCEFILE_H
#define PSO_SYSTEM_RESOURCEFILE_H

#include "types.h"

extern "C" {
s32 get_disc_file_size(const char *filename);
s32 get_resource_file_size(const char *filename);
u8 *load_disc_file(const char *filename);
// A raw sector transfer writes through the final sector boundary.
s32 read_disc_file_sectors(const char *filename, void *destination);
s32 read_disc_file(const char *filename, void *destination);
extern const char *disc_read_filename;
}

#endif
