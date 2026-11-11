#pragma readonly_strings on
#include "pso/audio/LscStream.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/TLobby.h"
#include <string.h>

static char lsc_repeat_filename[0x28];

extern "C" {
AdxStreamFile *adxstm_open_fname_range_ex_rt__6TLobbyFPviiii(const char *name, s32 mode, s32 offset, s32 length, s32 stream);
s32 set_range__6TLobbyFPvii(u8 *file, s32 min_bytes, s32 capacity);

// The three per-status steps are separate functions inlined into lsc_poll (inferred: CRI lsc_svr shape).
// Entry being read (status 1): follow the stream until it ends.
inline void read_803D1D28(LscStream *lsc_stream) {
    LscQueueEntry *entry;
    s32 status;
    if (lsc_stream->file_handle == 0) {
        TLobby::log_printf("E0007: lsc->fp=NULL");
    } else {
        entry = &lsc_stream->entries[lsc_stream->read_index];
        status = TLobby__sub_803C8B2C((u8 *)lsc_stream->file_handle);
        if (status == 4) {
            lsc_stream->state = 3;
        } else if (status == 2) {
            entry->progress = ((TLobby *)lsc_stream->file_handle)->get_file_offset_relative();
        } else if (status == 3) {
            entry->progress = lsc_stream->file_sector_count;
            entry->status = 2;
        }
    }
}
// Entry finished (status 2): close it, step the queue, requeue it when repeating.
inline void end_803D1D28(LscStream *lsc_stream) {
    LscQueueEntry *entry;
    s32 open_mode = 0;
    s32 range_offset = 0;
    s32 range_length = 0;
    if (lsc_stream->file_handle != 0) {
        TLobby__sub_803C8B38((u8 *)lsc_stream->file_handle);
        lsc_stream->file_handle = 0;
        if ((s32)lsc_stream->repeat == 1) {
            entry = &lsc_stream->entries[lsc_stream->read_index];
            memcpy(lsc_repeat_filename, entry->filename, 0x27);
            open_mode = entry->open_mode;
            range_offset = entry->range_offset;
            range_length = entry->range_length;
        }
        lsc_stream->queued_count--;
        lsc_stream->read_index = (lsc_stream->read_index + 1) % 16;
        if (lsc_stream->queued_count <= 0) {
            lsc_notify_queue_empty();
            lsc_stream->state = 1;
        }
        if ((s32)lsc_stream->repeat == 1) {
            lsc_enqueue_range(lsc_stream, lsc_repeat_filename, open_mode, range_offset, range_length);
        }
    }
}
// Entry waiting (status 0): open its file and start reading.
inline void wait_803D1D28(LscStream *lsc_stream) {
    LscQueueEntry *entry = &lsc_stream->entries[lsc_stream->read_index];
    if (lsc_stream->queued_count > 0) {
        if (lsc_stream->file_handle == 0) {
            lsc_stream->file_handle = (void *)adxstm_open_fname_range_ex_rt__6TLobbyFPviiii(entry->filename, entry->open_mode, entry->range_offset, entry->range_length, (s32)lsc_stream->stream);
            if (lsc_stream->file_handle == 0) {
                TLobby::log_printf("E0004: Can not open '%s'", entry->filename);
            }
            s32 sector_count = (((TLobby *)lsc_stream->file_handle)->get_field_14() + 0x7FF) / 0x800;
            lsc_stream->read_started = 0;
            lsc_stream->file_sector_count = sector_count;
            entry->progress = 0;
        }
        if (lsc_stream->read_started == 0) {
            set_range__6TLobbyFPvii((u8 *)lsc_stream->file_handle, lsc_stream->min_buffer_bytes, lsc_stream->buffer_capacity);
            ((TLobby *)lsc_stream->file_handle)->set_scroll_offset(0);
            ((TLobby *)lsc_stream->file_handle)->init_stream_position();
            lsc_stream->read_started = 1;
        }
        entry->status = 1;
    } else if (lsc_stream->file_handle != 0) {
        TLobby::log_printf("E0006: Illigal member nstm='%d' fp='%08x'h", lsc_stream->queued_count, lsc_stream->file_handle);
    }
}
void lsc_poll(LscStream *lsc_stream) {
    if ((s32)lsc_stream->paused == 1) {
        return;
    }
    if (lsc_stream->state != 2) {
        return;
    }
    if (lsc_stream->queued_count <= 0) {
        return;
    }
    if (lsc_stream->entries[lsc_stream->read_index].status == 1) {
        read_803D1D28(lsc_stream);
    }
    if (lsc_stream->entries[lsc_stream->read_index].status == 2) {
        end_803D1D28(lsc_stream);
    }
    if (lsc_stream->entries[lsc_stream->read_index].status == 0) {
        wait_803D1D28(lsc_stream);
    }
}

}
