#ifndef PSO_SYSTEM_CVFS_STREAM_HANDLE_H
#define PSO_SYSTEM_CVFS_STREAM_HANDLE_H

#include "types.h"

#include <stddef.h>

// The common device interface supplied by the MFS memory and GCD DVD backends.
typedef void (*CvFsErrorCallback)(s32 context, const char *message, void *detail);
struct CvFsDeviceInterface {
    void (*exec_server)();
    void (*set_error_callback)(CvFsErrorCallback callback, s32 context);
    s32 (*get_file_size)(char *name);
    void *reserved_0c;
    void *(*open)(const char *name, s32 mode, s32 extra);
    void (*close)(void *handle);
    s32 (*seek)(void *handle, s32 sector, s32 origin);
    s32 (*tell)(void *handle);
    s32 (*request_read)(void *handle, s32 sector_count, void *buffer);
    void *reserved_24;
    void (*stop_transfer)(void *handle);
    s32 (*get_status)(void *handle);
    s32 (*get_sector_length)(void *handle);
    void (*set_sector_length)(void *handle, s32 length);
    s32 (*get_num_transferred)(void *handle);
    void *reserved_3c[8];
    s32 (*get_file_size_ex)(char *path, s32 mode);
    s32 (*query)(s32, s32, s32, s32);
    void *reserved_64;
};

LAYOUT_ASSERT(CvFsDeviceInterfaceSize, sizeof(CvFsDeviceInterface) == 0x68);
LAYOUT_ASSERT(CvFsDeviceSeekOffset, offsetof(CvFsDeviceInterface, seek) == 0x18);
LAYOUT_ASSERT(CvFsDeviceTellOffset, offsetof(CvFsDeviceInterface, tell) == 0x1C);
LAYOUT_ASSERT(CvFsDeviceStatusOffset, offsetof(CvFsDeviceInterface, get_status) == 0x2C);

typedef CvFsDeviceInterface *(*CvFsDeviceFactory)();
struct CvFsHandle;
extern CvFsErrorCallback cvfs_completion_callback;
extern s32 lbl_805D75FC;
CvFsDeviceInterface *initialize_dvd_file_driver();

extern "C" {
CvFsHandle *cvFsOpen(const char *name, s32 mode, s32 extra);
s32 cvFsGetStat(CvFsHandle *handle);
void cvFsStopTr(CvFsHandle *handle);
s32 cvFsReqRd(CvFsHandle *handle, s32 sector_count, void *buffer);
s32 cvFsSeek(CvFsHandle *handle, s32 sector, s32 origin);
s32 cvFsTell(CvFsHandle *handle);
void cvFsClose(CvFsHandle *handle);
void cvFsSetDefDev(char *name);
void cvFsAddDev(char *name, CvFsDeviceFactory factory, s32 arg);
void cvfs_forward_error(s32 context, const char *message, void *detail);
void cvFsEntryErrFunc(CvFsErrorCallback callback, s32 context);
}

#endif
