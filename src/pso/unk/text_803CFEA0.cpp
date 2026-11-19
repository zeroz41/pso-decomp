#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/GcciRequests.h"
#include "pso/unk/TLobby_803D0C28.h"
#include "pso/unk/text_803D0C34.h"

extern const char gcci_version_string[] = "\nGCCI Ver.1.07 Build:Jun 13 2002 19:00:24\n";

typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);



struct File_803D0654 {
    u8 pad[0x10];
    s32 unit;
    s32 length;
    s32 size;
    s32 pos;
    s32 f20;
    s32 f24;
};

struct DVDFileInfo_803D0AE8 {
    u8 pad[0x34];
    u32 length;
    u8 pad38[4];
};

extern "C" {
s32 fileio_error_context;
RecoveredCallback_4873a87e26d6 fileio_error_callback;
volatile s32 lbl_805D7610;
s32 fileio_seek(struct File_803D0654 *arg0, s32 arg1, s32 arg2);
s32 DVDOpen(const char *, DVDFileInfo_803D0AE8 *);
s32 DVDClose(DVDFileInfo_803D0AE8 *);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
u32 strlen(const char *);
extern char dvd_default_path_buffer[0x100];
extern GcciStatus dvd_active_request;
s32 DVDGetCommandBlockStatus(void *);
s32 DVDGetDriveStatus(void);
s32 DVDCancel(void *);
u32 OSGetTick(void);
void *memset(void *, int, u32);
extern GcciRequest dvd_request_table[40];
s32 get_handle_field_20(GcciRequest *handle) {
    if (handle == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092912:handl is null.", 0);
        }
        return 0;
    }
    return handle->done;
}
void set_fileio_unit_size(File_803D0654 *file, s32 unit) {
    s32 old;
    s32 offset;
    if (file == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0040302:handl is null.", 0);
        }
        return;
    }
    old = file->unit;
    if (old % 32 != 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0040303:invalidate size.", 0);
        }
        return;
    }
    offset = file->pos * old;
    file->unit = unit;
    file->size = (file->length + (file->unit - 1)) / file->unit;
    file->pos = offset / file->unit;
    file->f20 = file->f24 * unit;
}

s32 get_field10_or_report(GcciRequest *handle) {
    if (handle == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0040301:handl is null.", 0);
        }
        return 0;
    }
    return handle->unit;
}


s32 get_handle_value_checked(GcciRequest *handle) {
    if (handle == 0) {
        if (fileio_error_callback != 0) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092912:handl is null.", 0);
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
            fileio_error_callback(fileio_error_context, (s32 *)"E0092912:handl is null.", 0);
        }
        return;
    }
    if (*(s8 *)&r->state == 1 || *(s8 *)&r->state == 0) {
        return;
    }
    DVDGetCommandBlockStatus(r->block);
    DVDGetDriveStatus();
    dvd_active_request.unknown08 = 1;
    result = DVDCancel(r->block);
    dvd_active_request.unknown08 = 0;
    if (result < 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092917:DVDCancel failed.", (s32)r);
        }
        return;
    }
    start = OSGetTick() / (*(u32 *)0x800000F8 / 4 / 1000);
    while (!dvd_request_idle(r)) {
        r->status = DVDGetCommandBlockStatus(r->block);
        dvd_active_request.status = r->status;
        now = OSGetTick() / (*(u32 *)0x800000F8 / 4 / 1000);
        if (now >= start) {
            elapsed = now - start;
        } else {
            elapsed = -1 - start + now;
        }
        if (elapsed > 2000) {
            if (fileio_error_callback != NULL) {
                fileio_error_callback(fileio_error_context, (s32 *)"E0092918:DVDCancel time out.", (s32)r);
            }
            break;
        }
    }
    r->state = 0;
    dvd_active_request.state = 0;
    DVDGetCommandBlockStatus(r->block);
    DVDGetDriveStatus();
}


// Explicitly zeroed: the flag sits in .sdata, not .sbss.
#pragma explicit_zero_data on
s32 dvd_synchronous_read_enabled = 0;
#pragma explicit_zero_data off
void DCInvalidateRange(void *, u32);
s32 DVDGetTransferredSize(void *);
s32 DVDReadAsyncPrio(void *, void *, s32, s32, void (*)(void), s32);
s32 Dolphin_DVDReadPrio(void *, void *, s32, s32, s32);
void TLobby__sub_803CFE9C(void);

inline s32 dvd_request_ready(GcciRequest *r) {
    s32 ready = 0;
    if (*(s8 *)&r->state == 1 || *(s8 *)&r->state == 0) {
        ready = 1;
    }
    return ready;
}

inline s32 dvd_any_request_busy(void) {
    s32 i;
    for (i = 0; i < 40; i++) {
        if (*(s8 *)&dvd_request_table[i].active == 1 && *(s8 *)&dvd_request_table[i].state == 2) {
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
            r->status = DVDGetCommandBlockStatus(r->block);
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
                n = DVDGetTransferredSize(r->block);
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
            fileio_error_callback(fileio_error_context, (s32 *)"E0092912:handl is null.", 0);
        }
        return 0;
    }
    if (count < 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092913:nsct < 0.(gcCiReqRd)", (s32)r);
        }
        return 0;
    }
    if (buf == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092914:buf is null.(gcCiReqRd)", (s32)r);
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
    if (offset + len > *(s32 *)&r->unknown14[0]) {
        len = *(s32 *)&r->unknown14[0] - offset;
        if (len < 0) {
            r->state = 1;
            dvd_active_request.state = 1;
            return count;
        }
    }
    len = (len + 31) & ~31;
    DCInvalidateRange(buf, len);
    if (dvd_synchronous_read_enabled == 0) {
        result = DVDReadAsyncPrio(r->block, buf, len, offset, TLobby__sub_803CFE9C, 2);
    } else {
        result = Dolphin_DVDReadPrio(r->block, buf, len, offset, 2);
    }
    if (result == 0) {
        return 0;
    }
    r->state = 2;
    dvd_active_request.state = 2;
    return r->count;
}

s32 get_handle_field_1c(GcciRequest *handle) {
    if (handle == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092912:handl is null.", 0);
        }
        return 0;
    }
    return handle->pos;
}

s32 fileio_seek(struct File_803D0654 *arg0, s32 arg1, s32 arg2) {
    if (arg0 == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092912:handl is null.", 0);
        }
        return 0;
    }
    if (arg2 == 0) {
        arg0->pos = arg1;
    } else if (arg2 == 2) {
        arg0->pos = arg0->size + arg1;
    } else if (arg2 == 1) {
        arg0->pos = arg0->pos + arg1;
    }
    arg0->pos = (arg0->pos < arg0->size) ? arg0->pos : arg0->size;
    arg0->pos = (arg0->pos > 0) ? arg0->pos : 0;
    return arg0->pos;
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
            fileio_error_callback(fileio_error_context, (s32 *)"E0092912:handl is null.", 0);
        }
    } else {
        if (*(s8 *)&rr->state == 1 || *(s8 *)&rr->state == 0) {
            goto close_req;
        }
        DVDGetCommandBlockStatus(rr->block);
        DVDGetDriveStatus();
        dvd_active_request.unknown08 = 1;
        result = DVDCancel(rr->block);
        dvd_active_request.unknown08 = 0;
        if (result < 0) {
            if (fileio_error_callback != NULL) {
                fileio_error_callback(fileio_error_context, (s32 *)"E0092917:DVDCancel failed.", (s32)rr);
            }
            goto close_req;
        }
        start = OSGetTick() / (*(u32 *)0x800000F8 / 4 / 1000);
        neg1 = -1 - start;
        if (rr->block && rr->block) { }
        while (!dvd_request_idle(rr)) {
            rr->status = DVDGetCommandBlockStatus(rr->block);
            dvd_active_request.status = rr->status;
            now = OSGetTick() / (*(u32 *)0x800000F8 / 4 / 1000);
            if (now >= start) {
                elapsed = now - start;
            } else {
                elapsed = neg1 + now;
            }
            if (elapsed > 2000) {
                if (fileio_error_callback != NULL) {
                    fileio_error_callback(fileio_error_context, (s32 *)"E0092918:DVDCancel time out.", (s32)rr);
                }
                break;
            }
        }
        rr->state = 0;
        dvd_active_request.state = 0;
        DVDGetCommandBlockStatus(rr->block);
        DVDGetDriveStatus();
    }
close_req:
    DVDClose((DVDFileInfo_803D0AE8 *)r->block);
    r->active = 0;
    memset(r, 0, sizeof(GcciRequest));
}

inline GcciRequest *dvd_find_free_request(void) {
    GcciRequest *found = NULL;
    s32 i;
    for (i = 0; i < 40; i++) {
        if (*(s8 *)&dvd_request_table[i].active == 0) {
            found = &dvd_request_table[i];
            break;
        }
    }
    return found;
}

GcciRequest *gcCiOpen(const char *name, s32 arg1, s32 mode) {
    GcciRequest *r;
    s32 size;
    u32 len;
    u32 j;
    char path[0x100];

    if (name == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092908:fname is null.(gcCiOpen)", 0);
        }
        return NULL;
    }
    if (mode != 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092909:rw is illigal.(gcCiOpen)", 0);
        }
        return NULL;
    }
    r = dvd_find_free_request();
    if (r == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092910:not enough handle resource.(gcCiOpen)", 0);
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
    if (DVDOpen(path, (DVDFileInfo_803D0AE8 *)r->block) == 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092911:DVDOpen fail.(gcCiOpen)", 0);
        }
        memset(r, 0, sizeof(GcciRequest));
        return NULL;
    }
    r->unit = 0x800;
    size = ((DVDFileInfo_803D0AE8 *)r->block)->length;
    if (size & 0x80000000) {
        size = 0x7FFFFFFF;
    }
    *(s32 *)&r->unknown14[0] = size;
    *(s32 *)&r->unknown14[4] = (r->unit - 1 + *(s32 *)&r->unknown14[0]) / r->unit;
    r->pos = 0;
    r->buf = NULL;
    r->count = 0;
    r->done = 0;
    r->state = 0;
    r->active = 1;
    return r;
}


typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);
s32 gcCiGetFileSize(const char *name) {
    s32 size;
    u32 len;
    u32 i;
    DVDFileInfo_803D0AE8 info;
    char path[0x100];
    if (name == NULL) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0092901:fname is null.(gcCiGetFileSize)", 0);
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
            fileio_error_callback(fileio_error_context, (s32 *)"E0040201:can't open a file.(gcCiGetFileSize)", 0);
        }
        return 0;
    }
    size = info.length;
    if (size & 0x80000000) {
        size = 0x7FFFFFFF;
    }
    if (DVDClose(&info) == 0) {
        if (fileio_error_callback != NULL) {
            fileio_error_callback(fileio_error_context, (s32 *)"E0040202:can't close a file.(gcCiGetFileSize)", 0);
        }
        return 0;
    }
    return size;
}

}

extern "C" {
// Installs the error callback and its context (inferred: CRI's gcCiEntryErrFunc, by its device interface slot).
void set_fileio_error_callback(RecoveredCallback_4873a87e26d6 callback, s32 context) {
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
            r->status = DVDGetCommandBlockStatus(r->block);
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
                n = DVDGetTransferredSize(r->block);
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
struct DvdFileDriverInterface {
    void (*exec_server)(void);
    void (*entry_err_func)(RecoveredCallback_4873a87e26d6 callback, s32 context);
    s32 (*get_file_size)(const char *name);
    void *pad_0C;
    GcciRequest *(*open)(const char *name, s32 arg1, s32 mode);
    void (*close)(void *handle);
    s32 (*seek)(File_803D0654 *handle, s32 offset, s32 whence);
    s32 (*tell)(GcciRequest *handle);
    s32 (*request_read)(void *handle, s32 count, void *buf);
    void *pad_24;
    void (*stop_transfer)(void *handle);
    s32 (*get_status)(GcciRequest *handle);
    s32 (*get_sector_length)(GcciRequest *handle);
    void (*set_sector_length)(File_803D0654 *handle, s32 unit);
    s32 (*get_transferred)(GcciRequest *handle);
    void *pad_3C[11];
};

DvdFileDriverInterface dvd_file_driver_interface = {
    poll_dvd_requests, set_fileio_error_callback, gcCiGetFileSize, 0, gcCiOpen, close_dvd_request, fileio_seek,
    get_handle_field_1c, gcCiReqRd, 0, cancel_dvd_request, get_handle_value_checked, get_field10_or_report,
    set_fileio_unit_size, get_handle_field_20,
};

DvdFileDriverInterface *initialize_dvd_file_driver(void) {
    lbl_805D7610 = lbl_805D7610;
    memset(dvd_default_path_buffer, 0, sizeof(dvd_default_path_buffer));
    fileio_error_callback = 0;
    fileio_error_context = 0;
    memset(&dvd_active_request, 0, sizeof(dvd_active_request));
    return &dvd_file_driver_interface;
}

#pragma push
#pragma scheduling off
void set_dvd_synchronous_read_mode(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    dvd_synchronous_read_enabled = arg3;
}
#pragma pop
extern "C" {
GcciStatus dvd_active_request;
GcciRequest dvd_request_table[40];
char dvd_default_path_buffer[0x100] ATTRIBUTE_ALIGN(8);
}
