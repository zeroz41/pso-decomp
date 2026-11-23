#define PSO_SDK_COMPACT_MATH
#include "types.h"
#include <string.h>
#include <dolphin/os.h>
#include <dolphin/os/OSCache.h>
#include <dolphin/os/OSTime.h>
#include "pso/system/CvFsStreamHandle.h"
#include "pso/unk/TLobby.h"
#include "pso/system/GcciRequests.h"
#include "pso/system/movie/Gcci.h"
#include "pso/system/movie/CvFsErrorBridge.h"
#undef PSO_SDK_COMPACT_MATH

extern const char gcci_version_string[] = "\nGCCI Ver.1.07 Build:Jun 13 2002 19:00:24\n";


extern "C" {
s32 fileio_error_context;
CvFsErrorCallback fileio_error_callback;
volatile s32 gcci_init_guard;
s32 fileio_seek(void *context, s32 sectors, s32 origin);
extern char dvd_default_path_buffer[0x100];
extern GcciStatus dvd_active_request;
extern GcciRequest dvd_request_table[40];
s32 gcci_get_num_transferred(void *context) {
    GcciRequest *handle = static_cast<GcciRequest *>(context);
    if (handle == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    return handle->done;
}
void set_fileio_unit_size(void *context, s32 unit) {
    GcciRequest *file = static_cast<GcciRequest *>(context);
    s32 old;
    s32 offset;
    if (file == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0040302:handl is null.", 0);
        }
        return;
    }
    old = file->unit;
    if (old % 32 != 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0040303:invalidate size.", 0);
        }
        return;
    }
    offset = file->pos * old;
    file->unit = unit;
    file->sector_count = (file->file_size + (file->unit - 1)) / file->unit;
    file->pos = offset / file->unit;
    file->done = file->count * unit;
}

s32 get_field10_or_report(void *context) {
    GcciRequest *handle = static_cast<GcciRequest *>(context);
    if (handle == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0040301:handl is null.", 0);
        }
        return 0;
    }
    return handle->unit;
}


s32 get_handle_value_checked(void *context) {
    GcciRequest *handle = static_cast<GcciRequest *>(context);
    if (handle == 0) {
        if (fileio_error_callback != 0) {
            fileio_error_callback(fileio_error_context, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    return handle->state;
}

inline s32 dvd_request_idle(GcciRequest *r) {
    s32 idle = 0;
    if (r->status == 0 || r->status == 10) {
        idle = 1;
    }
    return idle;
}

void cancel_dvd_request(void *arg) {
    GcciRequest *r = (GcciRequest *)arg;
    u32 start;
    u32 now;
    u32 elapsed;
    s32 result;

    if (r == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092912:handl is null.", 0);
        }
        return;
    }
    if (r->state == 1 || r->state == 0) {
        return;
    }
    DVDGetCommandBlockStatus(&r->block.cb);
    DVDGetDriveStatus();
    dvd_active_request.unknown08 = 1;
    result = DVDCancel(&r->block.cb);
    dvd_active_request.unknown08 = 0;
    if (result < 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092917:DVDCancel failed.", r);
        }
        return;
    }
    start = OSTicksToMilliseconds(OSGetTick());
    while (!dvd_request_idle(r)) {
        r->status = DVDGetCommandBlockStatus(&r->block.cb);
        dvd_active_request.status = r->status;
        now = OSTicksToMilliseconds(OSGetTick());
        if (now >= start) {
            elapsed = now - start;
        } else {
            elapsed = -1 - start + now;
        }
        if (elapsed > 2000) {
            if (fileio_error_callback != NULL) {
                fileio_error_callback(fileio_error_context, "E0092918:DVDCancel time out.", r);
            }
            break;
        }
    }
    r->state = 0;
    dvd_active_request.state = 0;
    DVDGetCommandBlockStatus(&r->block.cb);
    DVDGetDriveStatus();
}


// Explicitly zeroed: the flag sits in .sdata, not .sbss.
#pragma explicit_zero_data on
s32 dvd_synchronous_read_enabled = 0;
#pragma explicit_zero_data off

inline s32 dvd_request_ready(GcciRequest *r) {
    s32 ready = 0;
    if (r->state == 1 || r->state == 0) {
        ready = 1;
    }
    return ready;
}

inline s32 dvd_any_request_busy(void) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if ((s8)dvd_request_table[i].active == 1 && dvd_request_table[i].state == 2) {
            return 1;
        }
    }
    return 0;
}

inline void dvd_poll_requests(void) {
    GcciRequest *r;
    s32 i;
    s32 n;
    for (i = 0; i < 40; i++) {
        r = &dvd_request_table[i];
        if ((s32)r->active == 1 && (s32)r->state == 2) {
            r->status = DVDGetCommandBlockStatus(&r->block.cb);
            dvd_active_request.status = r->status;
            switch (r->status) {
            case -1:
            case 11:
                r->state = 3;
                dvd_active_request.state = 3;
                break;
            case 0:
                n = r->count * r->unit;
                DCInvalidateRange(r->buf, n);
                r->done = n;
                r->pos += r->count;
                r->state = dvd_active_request.state = 1;
                break;
            case 10:
                n = DVDGetTransferredSize(&r->block);
                DCInvalidateRange(r->buf, n);
                r->done = r->unit * (n / r->unit);
                r->pos += n / r->unit;
                r->state = dvd_active_request.state = 0;
                break;
            }
        }
    }
}

s32 gcCiReqRd(void *arg, s32 count, void *buf) {
    GcciRequest *r = (GcciRequest *)arg;
    s32 offset;
    s32 len;
    s32 result;

    if (r == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    if (count < 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092913:nsct < 0.(gcCiReqRd)", r);
        }
        return 0;
    }
    if (buf == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092914:buf is null.(gcCiReqRd)", r);
        }
        return 0;
    }
    if (!dvd_request_ready(r)) {
        return 0;
    }
    if (!dvd_request_idle(r)) {
        return 0;
    }
    if (dvd_any_request_busy()) {
        return 0;
    }
    if (count == 0) {
        r->state = 1;
        dvd_active_request.state = 1;
        return 0;
    }
    r->done = 0;
    r->buf = buf;
    r->count = count;
    dvd_poll_requests();
    offset = r->pos * r->unit;
    len = r->count * r->unit;
    if (offset + len > r->file_size) {
        len = r->file_size - offset;
        if (len < 0) {
            r->state = 1;
            dvd_active_request.state = 1;
            return count;
        }
    }
    len = (len + 31) & ~31;
    DCInvalidateRange(buf, len);
    if (dvd_synchronous_read_enabled == 0) {
        result = DVDReadAsyncPrio(&r->block, buf, len, offset, gcci_dvd_async_callback, 2);
    } else {
        result = DVDReadPrio(&r->block, buf, len, offset, 2);
    }
    if (result == 0) {
        return 0;
    }
    r->state = 2;
    dvd_active_request.state = 2;
    return r->count;
}

s32 gcci_get_position(void *context) {
    GcciRequest *handle = static_cast<GcciRequest *>(context);
    if (handle == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    return handle->pos;
}

s32 fileio_seek(void *context, s32 sectors, s32 origin) {
    GcciRequest *request = static_cast<GcciRequest *>(context);
    if (request == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    if (origin == 0) {
        request->pos = sectors;
    } else if (origin == 2) {
        request->pos = request->sector_count + sectors;
    } else if (origin == 1) {
        request->pos = request->pos + sectors;
    }
    request->pos = (request->pos < request->sector_count) ? request->pos : request->sector_count;
    request->pos = (request->pos > 0) ? request->pos : 0;
    return request->pos;
}
void close_dvd_request(void *arg) {
    GcciRequest *rr;
    GcciRequest *r = (GcciRequest *)arg;
    u32 start;
    s32 neg1;
    u32 now;
    u32 elapsed;
    s32 result;

    if (r == NULL) {
        return;
    }
    rr = (GcciRequest *)arg;
    if (rr == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092912:handl is null.", 0);
        }
    } else {
        if (rr->state == 1 || rr->state == 0) {
            goto close_req;
        }
        DVDGetCommandBlockStatus(&rr->block.cb);
        DVDGetDriveStatus();
        dvd_active_request.unknown08 = 1;
        result = DVDCancel(&rr->block.cb);
        dvd_active_request.unknown08 = 0;
        if (result < 0) {
            if (fileio_error_callback != NULL) {
                fileio_error_callback(fileio_error_context, "E0092917:DVDCancel failed.", rr);
            }
            goto close_req;
        }
        start = OSTicksToMilliseconds(OSGetTick());
        neg1 = -1 - start;
        if (&rr->block && &rr->block) { }
        while (!dvd_request_idle(rr)) {
            rr->status = DVDGetCommandBlockStatus(&rr->block.cb);
            dvd_active_request.status = rr->status;
            now = OSTicksToMilliseconds(OSGetTick());
            if (now >= start) {
                elapsed = now - start;
            } else {
                elapsed = neg1 + now;
            }
            if (elapsed > 2000) {
                if (fileio_error_callback != NULL) {
                    fileio_error_callback(fileio_error_context, "E0092918:DVDCancel time out.", rr);
                }
                break;
            }
        }
        rr->state = 0;
        dvd_active_request.state = 0;
        DVDGetCommandBlockStatus(&rr->block.cb);
        DVDGetDriveStatus();
    }
close_req:
    DVDClose(&r->block);
    r->active = 0;
    memset(r, 0, sizeof(GcciRequest));
}

inline GcciRequest *dvd_find_free_request(void) {
    GcciRequest *found = NULL;
    s32 i;
    for (i = 0; i < 40; i++) {
        if ((s8)dvd_request_table[i].active == 0) {
            found = &dvd_request_table[i];
            break;
        }
    }
    return found;
}

void *gcCiOpen(const char *name, s32 entry, s32 mode) {
    GcciRequest *r;
    s32 size;
    u32 len;
    u32 j;
    char path[0x100];

    if (name == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092908:fname is null.(gcCiOpen)", 0);
        }
        return NULL;
    }
    if (mode != 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092909:rw is illigal.(gcCiOpen)", 0);
        }
        return NULL;
    }
    r = dvd_find_free_request();
    if (r == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092910:not enough handle resource.(gcCiOpen)", 0);
        }
        return NULL;
    }
    strcpy(path, dvd_default_path_buffer);
    strcat(path, name);
    len = strlen(path);
    for (j = 0; j < len; j++) {
        if (path[j] == '\\') {
            path[j] = '/';
        }
    }
    if (DVDOpen(path, &r->block) == 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092911:DVDOpen fail.(gcCiOpen)", 0);
        }
        memset(r, 0, sizeof(GcciRequest));
        return NULL;
    }
    r->unit = 0x800;
    size = r->block.length;
    if (size & 0x80000000) {
        size = 0x7FFFFFFF;
    }
    r->file_size = size;
    r->sector_count = (r->unit - 1 + r->file_size) / r->unit;
    r->pos = 0;
    r->buf = NULL;
    r->count = 0;
    r->done = 0;
    r->state = 0;
    r->active = 1;
    return r;
}


s32 gcCiGetFileSize(char *name) {
    s32 size;
    u32 len;
    u32 i;
    DVDFileInfo info;
    char path[0x100];
    if (name == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0092901:fname is null.(gcCiGetFileSize)", 0);
        }
        return 0;
    }
    strcpy(path, dvd_default_path_buffer);
    strcat(path, name);
    len = strlen(path);
    for (i = 0; i < len; i++) {
        if (path[i] == '\\') {
            path[i] = '/';
        }
    }
    if (DVDOpen(path, &info) == 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0040201:can't open a file.(gcCiGetFileSize)", 0);
        }
        return 0;
    }
    size = info.length;
    if (size & 0x80000000) {
        size = 0x7FFFFFFF;
    }
    if (DVDClose(&info) == 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, "E0040202:can't close a file.(gcCiGetFileSize)", 0);
        }
        return 0;
    }
    return size;
}

// Installs the error callback and its context (inferred: CRI's gcCiEntryErrFunc, by its device interface slot).
void set_fileio_error_callback(CvFsErrorCallback callback, s32 context) {
    fileio_error_callback = callback;
    fileio_error_context = context;
}

void poll_dvd_requests(void) {
    GcciRequest *r;
    s32 i;
    s32 n;
    for (i = 0; i < 40; i++) {
        r = &dvd_request_table[i];
        if ((s32)r->active == 1 && (s32)r->state == 2) {
            r->status = DVDGetCommandBlockStatus(&r->block.cb);
            dvd_active_request.status = r->status;
            switch (r->status) {
            case -1:
            case 11:
                r->state = 3;
                dvd_active_request.state = 3;
                break;
            case 0:
                n = r->count * r->unit;
                DCInvalidateRange(r->buf, n);
                r->done = n;
                r->pos += r->count;
                r->state = dvd_active_request.state = 1;
                break;
            case 10:
                n = DVDGetTransferredSize(&r->block);
                DCInvalidateRange(r->buf, n);
                r->done = r->unit * (n / r->unit);
                r->pos += n / r->unit;
                r->state = dvd_active_request.state = 0;
                break;
            }
        }
    }
}
}

// The "GCD" device's entry points, in the slots the cvFs layer calls (cvFsAddDev registers
// initialize_dvd_file_driver, which returns this table).
CvFsDeviceInterface dvd_file_driver_interface = {
    poll_dvd_requests, set_fileio_error_callback, gcCiGetFileSize, 0, gcCiOpen, close_dvd_request, fileio_seek,
    gcci_get_position, gcCiReqRd, 0, cancel_dvd_request, get_handle_value_checked, get_field10_or_report,
    set_fileio_unit_size, gcci_get_num_transferred,
};

CvFsDeviceInterface *initialize_dvd_file_driver(void) {
    gcci_init_guard = gcci_init_guard;
    memset(dvd_default_path_buffer, 0, sizeof(dvd_default_path_buffer));
    fileio_error_callback = 0;
    fileio_error_context = 0;
    memset(&dvd_active_request, 0, sizeof(dvd_active_request));
    return &dvd_file_driver_interface;
}

#pragma push
#pragma scheduling off
void set_dvd_synchronous_read_mode(s32 unused0, s32 unused1, s32 unused2, s32 enabled) {
    dvd_synchronous_read_enabled = enabled;
}
#pragma pop
extern "C" {
GcciStatus dvd_active_request;
GcciRequest dvd_request_table[40];
char dvd_default_path_buffer[0x100] ATTRIBUTE_ALIGN(8);
}
