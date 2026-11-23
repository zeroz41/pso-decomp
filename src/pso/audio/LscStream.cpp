#pragma readonly_strings on
#include <string.h>
#include "pso/audio/LscStream.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/TLobby.h"

void (*lsc_queue_empty_callback)(void *, void *);
void *lsc_queue_empty_object;
void *lsc_queue_empty_param;

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

s32 lsc_get_min_buffer_bytes(LscStream *p) {
    if (p == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    return p->min_buffer_bytes;
}

void lsc_set_min_buffer_bytes(LscStream *lsc_stream, s32 bytes) {
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return;
    }
    if (bytes < 0 || bytes > lsc_stream->buffer_capacity) {
        TLobby::log_printf("E0010: Illigal parameter min=%d");
        return;
    }
    lsc_stream->min_buffer_bytes = bytes;
}

s32 lsc_get_stream_progress(LscStream *lsc_stream, s32 stream_id) {
    s32 i;
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return 0;
    }
    for (i = 0; i < 16; i++) {
        if (lsc_stream->entries[i].stream_id == stream_id) {
            break;
        }
    }
    if (i == 16) {
        TLobby::log_printf("E0012: Can not find stream ID =%d");
        return 0;
    }
    return lsc_stream->entries[i].progress;
}

s32 lsc_get_stream_status(LscStream *lsc_stream, s32 stream_id) {
    s32 i;
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    for (i = 0; i < 16; i++) {
        if (lsc_stream->entries[i].stream_id == stream_id) {
            break;
        }
    }
    if (i == 16) {
        TLobby::log_printf("E0012: Can not find stream ID =%d");
        return -1;
    }
    return lsc_stream->entries[i].status;
}

char *lsc_get_stream_filename(LscStream *lsc_stream, s32 stream_id) {
    s32 i;
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return 0;
    }
    for (i = 0; i < 16; i++) {
        if (lsc_stream->entries[i].stream_id == stream_id) {
            break;
        }
    }
    if (i == 16) {
        TLobby::log_printf("E0012: Can not find stream ID =%d");
        return 0;
    }
    return lsc_stream->entries[i].filename;
}

s32 lsc_get_queued_stream_id(LscStream *lsc_stream, s32 ordinal) {
    if (lsc_stream == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return -1;
    }
    if (ordinal < 0 || ordinal >= lsc_stream->queued_count) {
        TLobby::log_printf("E0009: Illigal parameter no=%d");
        return -1;
    }
    return lsc_stream->entries[(lsc_stream->read_index + ordinal) % 16].stream_id;
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
    u8 lock[8];
    s32 i;
    lsc_interrupt_lock_enter(lock);
    for (i = 0; i < 16; i++) {
        if ((s32)lsc_slot_table[i].in_use == 1) {
            lsc_poll(&lsc_slot_table[i]);
        }
    }
    lsc_interrupt_lock_leave(lock);
}

void lsc_stop(LscStream *lsc_stream) {
    s32 lock;
    if (lsc_stream == NULL) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return;
    }
    if ((s8) lsc_stream->state != 0) {
        lsc_interrupt_lock_enter(&lock);
        lsc_stream->state = 0U;
        if (lsc_stream->file_handle != NULL) {
            if ((s32) lsc_stream->read_started == 1) {
                stop_adx_stream(lsc_stream->file_handle);
                lsc_stream->read_started = 0U;
            }
            adxstm_close(lsc_stream->file_handle);
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
        lsc_stream->bytes_transferred = 0;
        lsc_interrupt_lock_leave(&lock);
    }
}

void lsc_start(LscStream *o) {
    u8 lk0[4];
    u8 lk1[4];
    if (o == 0) {
        TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        return;
    }
    lsc_interrupt_lock_enter(lk0);
    if (o->state != 0) {
        if (o == 0) {
            TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        } else if (o->state != 0) {
            lsc_interrupt_lock_enter(lk1);
            o->state = 0;
            if (o->file_handle != 0) {
                if ((s32)o->read_started == 1) {
                    stop_adx_stream(o->file_handle);
                    o->read_started = 0;
                }
                adxstm_close(o->file_handle);
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
            o->bytes_transferred = 0;
            lsc_interrupt_lock_leave(lk1);
        }
    }
    if (o->queued_count > 0) {
        o->state = 2;
    } else {
        o->state = 1;
    }
    lsc_interrupt_lock_leave(lk0);
}

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
    file = ADXSTM_OpenFnameEx(filename, (saddr)lsc_stream->stream);
    if (file == 0) {
        TLobby::log_printf("E0004: Can not open '%s'", filename);
        return -1;
    }
    sectors = (get_field_14__6TLobbyFv(file) + 0x7FF) / 0x800;
    adxstm_close(file);
    return lsc_enqueue_range(lsc_stream, filename, 0, 0, sectors);
}

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
    s32 outer_lock;
    s32 inner_lock;
    if (lsc_stream != NULL) {
        lsc_interrupt_lock_enter(&outer_lock);
        if (lsc_stream == NULL) {
            TLobby::log_printf("E0003: Illigal parameter lsc=NULL");
        } else if ((s8) lsc_stream->state != 0) {
            lsc_interrupt_lock_enter(&inner_lock);
            lsc_stream->state = 0U;
            if (lsc_stream->file_handle != NULL) {
                if ((s32) lsc_stream->read_started == 1) {
                    stop_adx_stream(lsc_stream->file_handle);
                    lsc_stream->read_started = 0U;
                }
                adxstm_close(lsc_stream->file_handle);
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
            lsc_stream->bytes_transferred = 0;
            lsc_interrupt_lock_leave(&inner_lock);
        }
        lsc_stream->in_use = 0;
        memset(lsc_stream, 0, (unsigned long)(0x438));
        lsc_interrupt_lock_leave(&outer_lock);
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
    lsc_interrupt_lock_enter(lk);
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
    lsc_interrupt_lock_leave(lk);
    return o;
}
}

