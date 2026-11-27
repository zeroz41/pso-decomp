#ifndef PSO_SYSTEM_MOVIE_GCCI_H
#define PSO_SYSTEM_MOVIE_GCCI_H

#include "types.h"
#include "pso/system/CvFsStreamHandle.h"

void set_dvd_synchronous_read_mode(s32 unused0, s32 unused1, s32 unused2, s32 enabled);
struct CvFsDeviceInterface *initialize_dvd_file_driver(void);

void set_fileio_error_callback(CvFsErrorCallback callback, s32 context);

void cancel_dvd_request(void *arg);
void close_dvd_request(void *arg);
s32 fileio_seek(void *context, s32 sectors, s32 origin);
s32 gcCiGetFileSize(char *name);
void *gcCiOpen(const char *name, s32 entry, s32 mode);
s32 gcCiReqRd(void *arg, s32 count, void *buf);
s32 gcci_get_num_transferred(void *context);
s32 gcci_get_position(void *context);
s32 get_field10_or_report(void *context);
s32 get_handle_value_checked(void *context);
void poll_dvd_requests(void);
void set_fileio_unit_size(void *context, s32 unit);

// The directory gcCiOpen and gcCiGetFileSize put in front of a file name.
extern char dvd_default_path_buffer[0x100];

#endif
