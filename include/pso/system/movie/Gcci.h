#ifndef PSO_SYSTEM_MOVIE_GCCI_H
#define PSO_SYSTEM_MOVIE_GCCI_H

#include "types.h"
#include "pso/system/CvFsStreamHandle.h"

void set_dvd_synchronous_read_mode(s32 unused0, s32 unused1, s32 unused2, s32 enabled);
struct CvFsDeviceInterface *initialize_dvd_file_driver(void);

extern "C" {
void set_fileio_error_callback(CvFsErrorCallback callback, s32 context);
}

#endif
