#ifndef PSO_AUDIO_LSCSTREAM_H
#define PSO_AUDIO_LSCSTREAM_H
#include "types.h"
#include <stddef.h>

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
    u8 unknown_0C[8];
    s32 min_buffer_bytes;
    s32 buffer_capacity;
    s32 write_index;
    s32 read_index;
    s32 queued_count;
    void* file_handle;
    s32 file_sector_count;
    u8 unknown_30[4];
    s32 field_34;
    LscQueueEntry entries[16];
};
typedef char LscQueueEntry_size[sizeof(LscQueueEntry)==0x40 ? 1 : -1];
typedef char LscStream_size[sizeof(LscStream)==0x438 ? 1 : -1];
typedef char LscQueueEntry_stream_id_offset[offsetof(LscQueueEntry, stream_id)==0x0 ? 1 : -1];
typedef char LscQueueEntry_filename_offset[offsetof(LscQueueEntry, filename)==0x4 ? 1 : -1];
typedef char LscQueueEntry_open_mode_offset[offsetof(LscQueueEntry, open_mode)==0x2C ? 1 : -1];
typedef char LscQueueEntry_range_offset_offset[offsetof(LscQueueEntry, range_offset)==0x30 ? 1 : -1];
typedef char LscQueueEntry_range_length_offset[offsetof(LscQueueEntry, range_length)==0x34 ? 1 : -1];
typedef char LscQueueEntry_status_offset[offsetof(LscQueueEntry, status)==0x38 ? 1 : -1];
typedef char LscQueueEntry_progress_offset[offsetof(LscQueueEntry, progress)==0x3C ? 1 : -1];
typedef char LscStream_in_use_offset[offsetof(LscStream, in_use)==0x0 ? 1 : -1];
typedef char LscStream_state_offset[offsetof(LscStream, state)==0x1 ? 1 : -1];
typedef char LscStream_read_started_offset[offsetof(LscStream, read_started)==0x2 ? 1 : -1];
typedef char LscStream_repeat_offset[offsetof(LscStream, repeat)==0x3 ? 1 : -1];
typedef char LscStream_paused_offset[offsetof(LscStream, paused)==0x4 ? 1 : -1];
typedef char LscStream_stream_offset[offsetof(LscStream, stream)==0x8 ? 1 : -1];
typedef char LscStream_min_buffer_bytes_offset[offsetof(LscStream, min_buffer_bytes)==0x14 ? 1 : -1];
typedef char LscStream_buffer_capacity_offset[offsetof(LscStream, buffer_capacity)==0x18 ? 1 : -1];
typedef char LscStream_write_index_offset[offsetof(LscStream, write_index)==0x1C ? 1 : -1];
typedef char LscStream_read_index_offset[offsetof(LscStream, read_index)==0x20 ? 1 : -1];
typedef char LscStream_queued_count_offset[offsetof(LscStream, queued_count)==0x24 ? 1 : -1];
typedef char LscStream_file_handle_offset[offsetof(LscStream, file_handle)==0x28 ? 1 : -1];
typedef char LscStream_file_sector_count_offset[offsetof(LscStream, file_sector_count)==0x2C ? 1 : -1];
typedef char LscStream_field_34_offset[offsetof(LscStream, field_34)==0x34 ? 1 : -1];
typedef char LscStream_entries_offset[offsetof(LscStream, entries)==0x38 ? 1 : -1];
extern "C" {
extern LscStream lsc_slot_table[16];
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
}

extern "C" {
LscStream *lsc_create(void *sj_handle);
void lsc_destroy(LscStream *arg0);
s32 lsc_get_min_buffer_bytes(LscStream *p);
s32 lsc_get_queued_stream_count(LscStream *p);
s32 lsc_get_queued_stream_id(LscStream *arg0, s32 arg1);
s32 lsc_get_state(LscStream *arg0);
char *lsc_get_stream_filename(LscStream *arg0, s32 arg1);
s32 lsc_get_stream_progress(LscStream *arg0, s32 arg1);
s32 lsc_get_stream_status(LscStream *arg0, s32 arg1);
void lsc_init(void);
void lsc_poll_all(void);
void lsc_set_min_buffer_bytes(LscStream *arg0, s32 arg1);
void lsc_shutdown(void);
void lsc_start(LscStream *o);
void lsc_stop(LscStream *arg0);
}

// --- C functions defined in LscStream.cpp ---
extern "C" {
void lsc_set_repeat(LscStream *lsc_stream, u8 repeat);
void lsc_notify_queue_empty(void);
LscStream *lsc_create(void *sj_handle);
void lsc_destroy(LscStream *lsc_stream);
s32 lsc_enqueue_range(LscStream *lsc_stream, const char *filename, s32 open_mode, s32 range_offset, s32 range_length);
s32 lsc_get_min_buffer_bytes(LscStream *p);
s32 lsc_get_queued_stream_count(LscStream *p);
s32 lsc_get_queued_stream_id(LscStream *lsc_stream, s32 arg1);
s32 lsc_get_state(LscStream *lsc_stream);
char *lsc_get_stream_filename(LscStream *lsc_stream, s32 arg1);
s32 lsc_get_stream_progress(LscStream *lsc_stream, s32 arg1);
s32 lsc_get_stream_status(LscStream *lsc_stream, s32 arg1);
void lsc_init(void);
void lsc_poll_all(void);
void lsc_set_min_buffer_bytes(LscStream *lsc_stream, s32 arg1);
void lsc_shutdown(void);
void lsc_start(LscStream *o);
void lsc_stop(LscStream *lsc_stream);
}
// --- end of C functions

#endif
