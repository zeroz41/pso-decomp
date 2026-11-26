#ifndef PSO_SYSTEM_FILEEXTENSION_H
#define PSO_SYSTEM_FILEEXTENSION_H

#include "types.h"

// Debug log of the file loaders; empty in the release build.
void file_debug_printf(const char *format, ...);
s32 change_file_extension(char *dest, char *filename, char *ext);
s32 replace_file_extension(char *dest, char *filename, char *suffix);
int compare_file_extension(const char *path, const char *ext);

#endif
