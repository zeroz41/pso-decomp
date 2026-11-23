#ifndef PSO_AUDIO_LSCSTREAM_H
#define PSO_AUDIO_LSCSTREAM_H
#include "types.h"
#include <stddef.h>

struct AdxStreamFile;
struct SjHandle;

struct SjInterface {
    void *slots[9];
    s32 (*GetNumData)(SjHandle *, s32);
};

struct SjHandle {
    SjInterface *vt;
};

struct LscQueueEntry {
    s32 stream_id;
    char filename[0x28];
    s32 open_mode;
    s32 range_offset;
    s32 range_length;
    s32 status;
    s32 progress;
};

struct LscStream {
    u8 in_use;
    s8 state;
    s8 read_started;
    u8 repeat;
    u8 paused;
    void* stream;
    u8 pad_0C[8];
    s32 min_buffer_bytes;
    s32 buffer_capacity;
    s32 write_index;
    s32 read_index;
    s32 queued_count;
    AdxStreamFile *file_handle;
    s32 file_sector_count;
    u8 pad_30[4];
    s32 bytes_transferred;
    LscQueueEntry entries[16];
};
LAYOUT_ASSERT(LscQueueEntry_size, sizeof(LscQueueEntry)==0x40);
LAYOUT_ASSERT(LscStream_size, sizeof(LscStream)==0x438);
LAYOUT_ASSERT(LscQueueEntry_stream_id_offset, offsetof(LscQueueEntry, stream_id)==0x0);
LAYOUT_ASSERT(LscQueueEntry_filename_offset, offsetof(LscQueueEntry, filename)==0x4);
LAYOUT_ASSERT(LscQueueEntry_open_mode_offset, offsetof(LscQueueEntry, open_mode)==0x2C);
LAYOUT_ASSERT(LscQueueEntry_range_offset_offset, offsetof(LscQueueEntry, range_offset)==0x30);
LAYOUT_ASSERT(LscQueueEntry_range_length_offset, offsetof(LscQueueEntry, range_length)==0x34);
LAYOUT_ASSERT(LscQueueEntry_status_offset, offsetof(LscQueueEntry, status)==0x38);
LAYOUT_ASSERT(LscQueueEntry_progress_offset, offsetof(LscQueueEntry, progress)==0x3C);
LAYOUT_ASSERT(LscStream_in_use_offset, offsetof(LscStream, in_use)==0x0);
LAYOUT_ASSERT(LscStream_state_offset, offsetof(LscStream, state)==0x1);
LAYOUT_ASSERT(LscStream_read_started_offset, offsetof(LscStream, read_started)==0x2);
LAYOUT_ASSERT(LscStream_repeat_offset, offsetof(LscStream, repeat)==0x3);
LAYOUT_ASSERT(LscStream_paused_offset, offsetof(LscStream, paused)==0x4);
LAYOUT_ASSERT(LscStream_stream_offset, offsetof(LscStream, stream)==0x8);
LAYOUT_ASSERT(LscStream_min_buffer_bytes_offset, offsetof(LscStream, min_buffer_bytes)==0x14);
LAYOUT_ASSERT(LscStream_buffer_capacity_offset, offsetof(LscStream, buffer_capacity)==0x18);
LAYOUT_ASSERT(LscStream_write_index_offset, offsetof(LscStream, write_index)==0x1C);
LAYOUT_ASSERT(LscStream_read_index_offset, offsetof(LscStream, read_index)==0x20);
LAYOUT_ASSERT(LscStream_queued_count_offset, offsetof(LscStream, queued_count)==0x24);
LAYOUT_ASSERT(LscStream_file_handle_offset, offsetof(LscStream, file_handle)==0x28);
LAYOUT_ASSERT(LscStream_file_sector_count_offset, offsetof(LscStream, file_sector_count)==0x2C);
LAYOUT_ASSERT(LscStream_bytes_transferred_offset, offsetof(LscStream, bytes_transferred)==0x34);
LAYOUT_ASSERT(LscStream_entries_offset, offsetof(LscStream, entries)==0x38);

// --- C functions defined in LscStream.cpp / LscInit.cpp / LscServer.cpp ---
extern "C" {
extern LscStream lsc_slot_table[16];
extern const char *const volatile lsc_version_string;
extern s32 lsc_init_count;
void lsc_set_repeat(LscStream* stream, u8 repeat);
void lsc_notify_queue_empty(void);
s32 lsc_get_min_buffer_bytes(LscStream* stream);
void lsc_set_min_buffer_bytes(LscStream* stream, s32 bytes);
s32 lsc_get_stream_progress(LscStream* stream, s32 stream_id);
s32 lsc_get_stream_status(LscStream* stream, s32 stream_id);
char* lsc_get_stream_filename(LscStream* stream, s32 stream_id);
s32 lsc_get_queued_stream_id(LscStream* stream, s32 ordinal);
s32 lsc_get_queued_stream_count(LscStream* stream);
s32 lsc_get_state(LscStream* stream);
void lsc_poll_all(void);
void lsc_stop(LscStream* stream);
void lsc_start(LscStream* stream);
s32 lsc_enqueue_range(LscStream* stream, const char* filename,
    s32 open_mode, s32 range_offset, s32 range_length);
s32 lsc_enqueue_file(LscStream* stream, const char* filename);
void lsc_destroy(LscStream* stream);
LscStream* lsc_create(void* sj_handle);
void lsc_shutdown(void);
void lsc_init(void);
void lsc_poll(LscStream* stream);
void lsc_interrupt_lock_leave(void* lock);
void lsc_interrupt_lock_enter(void* lock);
}
// --- end of C functions

#endif
