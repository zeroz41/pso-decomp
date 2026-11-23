#ifndef PSO_SYSTEM_MOVIE_CVFSERRORBRIDGE_H
#define PSO_SYSTEM_MOVIE_CVFSERRORBRIDGE_H

#include "types.h"

struct DVDFileInfo;

extern "C" {
void gcci_dvd_async_callback(s32 result, DVDFileInfo *file);
}

#endif
