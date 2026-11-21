#ifndef PSO_AUDIO_ADXSTREAMFILE_H
#define PSO_AUDIO_ADXSTREAMFILE_H

#include "types.h"
#include "pso/audio/SjRingBuffer.h"
#include <stddef.h>

struct CvFsHandle;
typedef void (*AdxStreamCompletion)(void *context);

struct AdxStreamFile {
    s8 used;
    s8 b1;
    s8 b2;
    s8 retry;
    union {
        s32 arg;
        SjRingBuffer *buffer;
    };
    CvFsHandle *handle;
    s32 fC;
    s32 f10;
    s32 size;
    s32 read_chunk_size;
    s32 read_threshold;
    s32 sectors_read;
    SjChunk pending_read;
    s32 max_read_sectors;
    s32 sectors;
    s32 field34;
    AdxStreamCompletion on_completion;
    void *completion_context;
};
typedef char AdxStreamFileHandleOffset[offsetof(AdxStreamFile, handle) == 8 ? 1 : -1];
typedef char AdxStreamFilePendingReadOffset[offsetof(AdxStreamFile, pending_read) == 0x24 ? 1 : -1];
typedef char AdxStreamFileCompletionOffset[offsetof(AdxStreamFile, on_completion) == 0x38 ? 1 : -1];
typedef char AdxStreamFile_size[sizeof(AdxStreamFile) == 0x40 ? 1 : -1];
typedef char AdxStreamFile_field34_offset[offsetof(AdxStreamFile, field34) == 0x34 ? 1 : -1];

extern "C" {
void set_adx_stream_completion(AdxStreamFile *file, AdxStreamCompletion callback, void *context);
void update_adx_stream_read(AdxStreamFile *file);
void set_field_10_and_notify__6TLobbyFl(AdxStreamFile *file, s32 offset);
void set_buffer__6TLobbyFPPv(AdxStreamFile *file, SjRingBuffer *buffer);
s32 get_field_14__6TLobbyFv(AdxStreamFile *file);
void set_scroll_position__6TLobbyFl(AdxStreamFile *file, s32 sector);
s32 init_stream_position__6TLobbyFv(AdxStreamFile *file);
s32 get_file_offset_relative__6TLobbyFv(AdxStreamFile *file);
s32 set_scroll_offset__6TLobbyFl(AdxStreamFile *file, s32 offset);
}

#endif
