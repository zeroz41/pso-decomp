#ifndef PSO_SYSTEM_MOVIE_CVFSERRORBRIDGE_H
#define PSO_SYSTEM_MOVIE_CVFSERRORBRIDGE_H

#include "types.h"

struct DVDFileInfo;

void gcci_dvd_async_callback(s32 result, DVDFileInfo *file);

void cvfs_forward_error(s32, const char *message, void *handle);

#endif
