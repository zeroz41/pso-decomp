#pragma readonly_strings on
#include "pso/audio/LscStream.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/TLobby.h"

struct SjHandle;

struct SjInterface {
    void *slots[9];
    s32 (*GetNumData)(SjHandle *, s32);
};

struct SjHandle { SjInterface *vt; };

extern void (*lsc_queue_empty_callback)(void *, void *);
extern void *lsc_queue_empty_object;
extern void *lsc_queue_empty_param;
extern s32 lsc_init_count;
extern const char *volatile lsc_version_string;

extern "C" {
void lsc_set_repeat(LscStream *lsc_stream, u8 repeat) {
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return;
    }
    lsc_stream->repeat = repeat;
}

void lsc_notify_queue_empty(void) {
    if (lsc_queue_empty_callback != NULL) {
        lsc_queue_empty_callback(lsc_queue_empty_object, lsc_queue_empty_param);
    }
}
}

extern "C" {
char *strncpy(char *dest, const char *src, unsigned long num);
void *memset(void *dst, int val, unsigned long n);
extern LscStream lsc_slot_table[];
void notify_dvd_read__6TLobbyFv(void *);
void enter_lock__6TLobbyFv(void *);
s32 lsc_get_min_buffer_bytes(LscStream *p) {
    if (p == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    return p->min_buffer_bytes;
}

void lsc_set_min_buffer_bytes(LscStream *lsc_stream, s32 arg1) {
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return;
    }
    if (arg1 < 0 || arg1 > lsc_stream->buffer_capacity) {
        TLobby::log_printf("E0010: Illigal parameter min=%d");
        return;
    }
    lsc_stream->min_buffer_bytes = arg1;
}

s32 lsc_get_stream_progress(LscStream *lsc_stream, s32 arg1) {
    s32 i;
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return 0;
    }
    for (i = 0; i < 16; i++) {
        if (lsc_stream->entries[i].stream_id == arg1) {
            break;
        }
    }
    if (i == 16) {
        TLobby::log_printf("E0012: Can not find stream ID =%d");
        return 0;
    }
    return lsc_stream->entries[i].progress;
}

s32 lsc_get_stream_status(LscStream *lsc_stream, s32 arg1) {
    s32 i;
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    for (i = 0; i < 16; i++) {
        if (lsc_stream->entries[i].stream_id == arg1) {
            break;
        }
    }
    if (i == 16) {
        TLobby::log_printf("E0012: Can not find stream ID =%d");
        return -1;
    }
    return lsc_stream->entries[i].status;
}

char *lsc_get_stream_filename(LscStream *lsc_stream, s32 arg1) {
    s32 i;
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return 0;
    }
    for (i = 0; i < 16; i++) {
        if (lsc_stream->entries[i].stream_id == arg1) {
            break;
        }
    }
    if (i == 16) {
        TLobby::log_printf("E0012: Can not find stream ID =%d");
        return 0;
    }
    return lsc_stream->entries[i].filename;
}

s32 lsc_get_queued_stream_id(LscStream *lsc_stream, s32 arg1) {
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    if (arg1 < 0 || arg1 >= lsc_stream->queued_count) {
        TLobby::log_printf("E0009: Illigal parameter no=%d");
        return -1;
    }
    return lsc_stream->entries[(lsc_stream->read_index + arg1) % 16].stream_id;
}

s32 lsc_get_queued_stream_count(LscStream *p) {
    if (p == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    return p->queued_count;
}

s32 lsc_get_state(LscStream *lsc_stream) {
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    return lsc_stream->state;
}

void lsc_poll_all(void) {
    u8 sp8[8];
    s32 i;
    ((void (*)(void *))enter_lock__6TLobbyFv)(sp8);
    for (i = 0; i < 16; i++) {
        if ((s32)lsc_slot_table[i].in_use == 1) {
            lsc_poll(&lsc_slot_table[i]);
        }
    }
    ((void (*)(void *))notify_dvd_read__6TLobbyFv)(sp8);
}

void lsc_stop(LscStream *lsc_stream) {
    s32 sp8;
    if (lsc_stream == NULL) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return;
    }
    if ((s8) lsc_stream->state != 0) {
        enter_lock__6TLobbyFv(&sp8);
        lsc_stream->state = 0U;
        if ((u32) (u32)lsc_stream->file_handle != 0U) {
            if ((s32) lsc_stream->read_started == 1) {
                TLobby__sub_803C89C4((u8 *)lsc_stream->file_handle);
                lsc_stream->read_started = 0U;
            }
            TLobby__sub_803C8B38((u8 *)((int) ((u32)lsc_stream->file_handle)));
            lsc_stream->file_handle = 0;
        }
        lsc_stream->file_sector_count = 0;
        if (lsc_stream == NULL) {
            TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        } else if ((s8) lsc_stream->state == 0) {
            lsc_stream->write_index = 0;
            lsc_stream->read_index = 0;
            lsc_stream->queued_count = 0;
        }
        lsc_stream->field_34 = 0;
        notify_dvd_read__6TLobbyFv(&sp8);
    }
}

void lsc_start(LscStream *o) {
    u8 lk0[4];
    u8 lk1[4];
    if (o == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return;
    }
    ((void (*)(void *))enter_lock__6TLobbyFv)(lk0);
    if (o->state != 0) {
        if (o == 0) {
            TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        } else if (o->state != 0) {
            ((void (*)(void *))enter_lock__6TLobbyFv)(lk1);
            o->state = 0;
            if (o->file_handle != 0) {
                if ((s32)o->read_started == 1) {
                    TLobby__sub_803C89C4((u8 *)o->file_handle);
                    o->read_started = 0;
                }
                TLobby__sub_803C8B38((u8 *)o->file_handle);
                o->file_handle = 0;
            }
            o->file_sector_count = 0;
            if (o == 0) {
                TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
            } else if (o->state == 0) {
                o->write_index = 0;
                o->read_index = 0;
                o->queued_count = 0;
            }
            o->field_34 = 0;
            ((void (*)(void *))notify_dvd_read__6TLobbyFv)(lk1);
        }
    }
    if (o->queued_count > 0) {
        o->state = 2;
    } else {
        o->state = 1;
    }
    ((void (*)(void *))notify_dvd_read__6TLobbyFv)(lk0);
}

#pragma push
#pragma dont_inline off
#pragma auto_inline on
#pragma inline_depth(4)
s32 lsc_enqueue_range(LscStream *lsc_stream, const char *filename, s32 open_mode, s32 range_offset, s32 range_length) {
    LscQueueEntry *entry;
    s32 id;
    s32 prev;
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    if (lsc_stream->queued_count >= 16) {
        return -1;
    }
    if (filename == 0) {
        TLobby::log_printf("E0011: Illigal parameter fname=%s", filename);
        return -1;
    }
    prev = lsc_stream->entries[(lsc_stream->write_index + 15) % 16].stream_id;
    if (prev == 0x7FFFFFFF) {
        id = 0;
    } else {
        id = prev + 1;
    }
    entry = &lsc_stream->entries[lsc_stream->write_index];
    entry->stream_id = id;
    strncpy(entry->filename, filename, 0x28);
    entry->range_offset = range_offset;
    entry->range_length = range_length;
    entry->open_mode = open_mode;
    entry->status = 0;
    entry->progress = 0;
    lsc_stream->queued_count++;
    lsc_stream->write_index = (lsc_stream->write_index + 1) % 16;
    if (lsc_stream->state == 1) {
        lsc_stream->state = 2;
    }
    return id;
}

s32 lsc_enqueue_file(LscStream *lsc_stream, const char *filename) {
    AdxStreamFile *file;
    s32 sectors;
    file = TLobby__sub_803C8BAC(filename, (s32)lsc_stream->stream);
    if (file == 0) {
        TLobby::log_printf("E0004: Can not open '%s'", filename);
        return -1;
    }
    sectors = (((TLobby *)file)->get_field_14() + 0x7FF) / 0x800;
    TLobby__sub_803C8B38((u8 *)file);
    return lsc_enqueue_range(lsc_stream, filename, 0, 0, sectors);
}
#pragma pop

#pragma push
#pragma dont_inline off
#pragma inline_depth(4)
inline LscStream *lsc_find_free_slot(void) {
    s32 i;
    LscStream *o = 0;
    for (i = 0; i < 16; i++) {
        if ((s8)lsc_slot_table[i].in_use == 0) {
            o = (LscStream *)&lsc_slot_table[i];
            break;
        }
    }
    return o;
}

void lsc_destroy(LscStream *lsc_stream) {
    s32 spC;
    s32 sp8;
    if (lsc_stream != NULL) {
        enter_lock__6TLobbyFv(&spC);
        if (lsc_stream == NULL) {
            TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        } else if ((s8) lsc_stream->state != 0) {
            enter_lock__6TLobbyFv(&sp8);
            lsc_stream->state = 0U;
            if ((u32) (u32)lsc_stream->file_handle != 0U) {
                if ((s32) lsc_stream->read_started == 1) {
                    TLobby__sub_803C89C4((u8 *)lsc_stream->file_handle);
                    lsc_stream->read_started = 0U;
                }
                TLobby__sub_803C8B38((u8 *)((int) ((u32)lsc_stream->file_handle)));
                lsc_stream->file_handle = 0;
            }
            lsc_stream->file_sector_count = 0;
            if (lsc_stream == NULL) {
                TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
            } else if ((s8) lsc_stream->state == 0) {
                lsc_stream->write_index = 0;
                lsc_stream->read_index = 0;
                lsc_stream->queued_count = 0;
            }
            lsc_stream->field_34 = 0;
            notify_dvd_read__6TLobbyFv(&sp8);
        }
        lsc_stream->in_use = 0;
        memset(lsc_stream, 0, (unsigned long)(0x438));
        notify_dvd_read__6TLobbyFv(&spC);
    }
}

LscStream *lsc_create(void *sj_handle) {
    SjHandle *sj = (SjHandle *)sj_handle;
    u8 lk[4];
    s32 i;
    LscStream *o;
    if (sj == 0) {
        TLobby::log_printf("E0001: Illigal parameter=sj (LSC_Create)");
        return 0;
    }
    ((void (*)(void *))enter_lock__6TLobbyFv)(lk);
    o = lsc_find_free_slot();
    if (o == 0) {
        TLobby::log_printf("E0002: Not enough instance (LSC_Create)");
    } else {
        o->stream = sj;
        o->state = 0;
        o->buffer_capacity = sj->vt->GetNumData(sj, 0) + sj->vt->GetNumData(sj, 1);
        o->min_buffer_bytes = (o->buffer_capacity * 8) / 10;
        for (i = 0; i < 16; i++) {
            o->entries[i].status = 0;
        }
        o->in_use = 1;
    }
    ((void (*)(void *))notify_dvd_read__6TLobbyFv)(lk);
    return o;
}
#pragma pop

void lsc_shutdown(void) {
    u8 lock[8];
    s32 i;
    ((void (*)(void *))enter_lock__6TLobbyFv)(lock);
    if (--lsc_init_count == 0) {
        for (i = 0; i < 16; i++) {
            if ((s32)lsc_slot_table[i].in_use == 1) {
                lsc_destroy(&lsc_slot_table[i]);
            }
        }
        memset(lsc_slot_table, 0, 0x4380);
        TLobby::set_callback(0, 0);
    }
    ((void (*)(void *))notify_dvd_read__6TLobbyFv)(lock);
}

void lsc_init(void) {
    u8 sp8[8];
    lsc_version_string;
    ((void (*)(void *))enter_lock__6TLobbyFv)(sp8);
    if (lsc_init_count == 0) {
        memset(lsc_slot_table, 0, (unsigned long)(0x4380));
        TLobby::set_callback(0, 0);
    }
    lsc_init_count++;
    ((void (*)(void *))notify_dvd_read__6TLobbyFv)(sp8);
}

 LscStream lsc_slot_table[16]; }
