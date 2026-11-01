#include "types.h"
#include "pso/misc/TLobby.h"
#include "pso/system/GcciRequests.h"

typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);
struct RecoveredGlobal_803CFEA0_lbl_8047DAE4 {
    s32 value;
    u8 remaining[0x14];
};

typedef s32 (*RecoveredCallback_803D0014)(s32, s32 *, s32);
struct S_803D0014 { u8 pad[2]; s8 f; };

struct G_803D0014 { s32 value; u8 remaining[0x14]; };

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
extern RecoveredGlobal_803CFEA0_lbl_8047DAE4 lbl_8047DAE4;
extern s32 lbl_805D7608;
extern RecoveredCallback_4873a87e26d6 lbl_805D760C;
extern RecoveredGlobal_803CFEA0_lbl_8047DAE4 lbl_8047DB30;
s32 TLobby__sub_803D0654(struct File_803D0654 *arg0, s32 arg1, s32 arg2);
s32 DVDOpen(const char *, DVDFileInfo_803D0AE8 *);
s32 DVDClose(DVDFileInfo_803D0AE8 *);
char *strcat(char *, const char *);
char *strcpy(char *, const char *);
u32 strlen(const char *);
extern char lbl_8047DAB8[];
extern char lbl_8047DAFC[];
extern char lbl_8047DB14[];
extern char dvd_default_path_buffer[];
extern GcciStatus dvd_active_request;
s32 DVDGetCommandBlockStatus(void *);
s32 DVDGetDriveStatus(void);
s32 DVDCancel(void *);
u32 OSGetTick(void);
void *memset(void *, int, u32);
extern GcciRequest dvd_request_table[40];
typedef char RecoveredGlobal_803CFEA0_lbl_8047DAE4_size[sizeof(RecoveredGlobal_803CFEA0_lbl_8047DAE4) == 0x18 ? 1 : -1];
s32 TLobby::get_handle_field_20() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) lbl_805D760C) != NULL) {
            lbl_805D760C(lbl_805D7608, &lbl_8047DAE4.value, 0);
        }
        return 0;
    }
    return *(s32 *)((s8 *)arg0 + 0x20);
}
void TLobby__sub_803CFEF4(File_803D0654 *file, s32 unit) {
    s32 old;
    s32 offset;
    if (file == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)lbl_8047DAFC, 0);
        }
        return;
    }
    old = file->unit;
    if (old % 32 != 0) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)lbl_8047DB14, 0);
        }
        return;
    }
    offset = file->pos * old;
    file->unit = unit;
    file->size = (file->length + (file->unit - 1)) / file->unit;
    file->pos = offset / file->unit;
    file->f20 = file->f24 * unit;
}

s32 TLobby::get_field10_or_report() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) lbl_805D760C) != NULL) {
            lbl_805D760C(lbl_805D7608, &lbl_8047DB30.value, 0);
        }
        return 0;
    }
    return *(s32 *)&this->m_up;
}

s32 TLobby::get_handle_value_checked() {
    S_803D0014 *arg0 = (S_803D0014 *)this;
    if (arg0 == 0) {
        if ((*(RecoveredCallback_803D0014 *)&lbl_805D760C) != 0) {
            (*(RecoveredCallback_803D0014 *)&lbl_805D760C)(lbl_805D7608, &(*(G_803D0014 *)&lbl_8047DAE4).value, 0);
        }
        return 0;
    }
    return arg0->f;
}

#pragma push
#pragma dont_inline off
#pragma inline_depth(8)
inline s32 dvd_request_idle(GcciRequest *r) {
    s32 idle = 0;
    if (r->status == 0 || r->status == 10) {
        idle = 1;
    }
    return idle;
}

void TLobby__sub_803D006C(void *arg) {
    GcciRequest *r = (GcciRequest *)arg;
    char *msg = lbl_8047DAB8;
    u32 start;
    u32 now;
    u32 elapsed;
    s32 result;

    if (r == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x2C), 0);
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
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x90), (s32)r);
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
            if (lbl_805D760C != NULL) {
                lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0xAC), (s32)r);
            }
            break;
        }
    }
    r->state = 0;
    dvd_active_request.state = 0;
    DVDGetCommandBlockStatus(r->block);
    DVDGetDriveStatus();
}

#pragma pop

s32 TLobby::get_handle_field_1c() {
    u8 *arg0 = (u8 *)this;
    if (arg0 == NULL) {
        if (((s32 (*)(s32, s32 *, s32)) lbl_805D760C) != NULL) {
            lbl_805D760C(lbl_805D7608, &lbl_8047DAE4.value, 0);
        }
        return 0;
    }
    return *(s32 *)((s8 *)arg0 + 0x1c);
}
extern s32 dvd_synchronous_read_enabled;
void DCInvalidateRange(void *, u32);
s32 DVDGetTransferredSize(void *);
s32 DVDReadAsyncPrio(void *, void *, s32, s32, void (*)(void), s32);
s32 Dolphin_DVDReadPrio(void *, void *, s32, s32, s32);
void TLobby__sub_803CFE9C(void);

#pragma push
#pragma dont_inline off
#pragma inline_depth(8)
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

s32 TLobby__sub_803D0214(void *arg, s32 count, void *buf) {
    GcciRequest *r = (GcciRequest *)arg;
    char *msg = lbl_8047DAB8;
    s32 offset;
    s32 len;
    s32 result;

    if (r == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x2C), 0);
        }
        return 0;
    }
    if (count < 0) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0xCC), (s32)r);
        }
        return 0;
    }
    if (buf == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0xEC), (s32)r);
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
#pragma pop

s32 TLobby__sub_803D0654(struct File_803D0654 *arg0, s32 arg1, s32 arg2) {
    if (arg0 == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, ((s32 *)&lbl_8047DAE4), 0);
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
#pragma push
#pragma dont_inline off
#pragma inline_depth(8)
void TLobby__sub_803D0714(void *arg) {
    GcciRequest *rr;
    GcciRequest *r = (GcciRequest *)arg;
    char *msg = lbl_8047DAB8;
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
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x2C), 0);
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
            if (lbl_805D760C != NULL) {
                lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x90), (s32)rr);
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
                if (lbl_805D760C != NULL) {
                    lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0xAC), (s32)rr);
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

GcciRequest *TLobby__sub_803D08E0(const char *name, s32 arg1, s32 mode) {
    char *msg = lbl_8047DAB8;
    GcciRequest *r;
    s32 i;
    s32 size;
    u32 len;
    u32 j;
    char path[0x100];

    if (name == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x110), 0);
        }
        return NULL;
    }
    if (mode != 0) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x134), 0);
        }
        return NULL;
    }
    r = dvd_find_free_request();
    if (r == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x158), 0);
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
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x188), 0);
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

#pragma pop

typedef s32 (*RecoveredCallback_4873a87e26d6)(s32, s32 *, s32);
s32 TLobby::get_dvd_file_size(const char *name) {
    char *msg = lbl_8047DAB8;
    s32 size;
    u32 len;
    u32 i;
    DVDFileInfo_803D0AE8 info;
    char path[0x100];
    if (name == NULL) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x1AC), 0);
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
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x1D8), 0);
        }
        return 0;
    }
    size = info.length;
    if (size & 0x80000000) {
        size = 0x7FFFFFFF;
    }
    if (DVDClose(&info) == 0) {
        if (lbl_805D760C != NULL) {
            lbl_805D760C(lbl_805D7608, (s32 *)(msg + 0x208), 0);
        }
        return 0;
    }
    return size;
}

}
