#ifndef PSO_AUDIO_SJRINGBUFFER_H
#define PSO_AUDIO_SJRINGBUFFER_H
#include "types.h"

struct SjRingBuffer;
struct SjChunk { u8* data; s32 size; };
typedef void (*SjErrorCallback)(void* context, s32 error);
struct SjRingBufferInterface {
    void* field_00;
    void* field_04;
    void* field_08;
    void (*destroy)(SjRingBuffer*);
    const u8* (*get_uuid)(SjRingBuffer*);
    void (*reset)(SjRingBuffer*);
    void (*get_chunk)(SjRingBuffer*, s32, s32, SjChunk*);
    void (*unget_chunk)(SjRingBuffer*, s32, SjChunk*);
    void (*put_chunk)(SjRingBuffer*, s32, SjChunk*);
    s32 (*get_available)(SjRingBuffer*, s32);
    bool (*is_chunk_available)(SjRingBuffer*, s32, s32, s32*);
    void (*set_error_callback)(SjRingBuffer*, SjErrorCallback, void*);
};
struct SjRingBuffer {
    const SjRingBufferInterface* interface;
    s32 in_use;
    const u8* type_uuid;
    s32 readable_bytes;
    s32 writable_bytes;
    s32 write_position;
    s32 read_position;
    u8* buffer;
    s32 buffer_size;
    s32 extra_buffer_size;
    SjErrorCallback error_callback;
    void* error_context;
};
typedef char SjRingBuffer_size[sizeof(SjRingBuffer)==0x30 ? 1 : -1];
typedef char SjRingBufferInterface_size[sizeof(SjRingBufferInterface)==0x30 ? 1 : -1];

extern "C" {
SjRingBuffer* sj_ring_buffer_create(void* buffer, s32 buffer_size, s32 extra_buffer_size);
void sj_ring_buffer_destroy(SjRingBuffer* buffer);
void sj_ring_buffer_reset(SjRingBuffer* buffer);
void sj_ring_buffer_get_chunk(SjRingBuffer* buffer, s32 side, s32 requested_size, SjChunk* chunk);
void sj_ring_buffer_unget_chunk(SjRingBuffer* buffer, s32 side, SjChunk* chunk);
void sj_ring_buffer_put_chunk(SjRingBuffer* buffer, s32 side, SjChunk* chunk);
s32 sj_ring_buffer_get_available(SjRingBuffer* buffer, s32 side);
bool sj_ring_buffer_is_chunk_available(SjRingBuffer* buffer, s32 side, s32 requested_size, s32* available_size);
void sj_ring_buffer_set_error_callback(SjRingBuffer* buffer, SjErrorCallback callback, void* context);
const u8* sj_ring_buffer_get_uuid(SjRingBuffer* buffer);
void sj_ring_buffer_init(void);
void sj_ring_buffer_shutdown(void);
}
extern "C" {
s32 sj_ring_buffer_get_extra_buffer_size(SjRingBuffer* buffer);
s32 sj_ring_buffer_get_buffer_size(SjRingBuffer* buffer);
u8* sj_ring_buffer_get_buffer(SjRingBuffer* buffer);
}

extern "C" {
SjRingBuffer *sj_ring_buffer_create(void *data, s32 bsize, s32 x24);
void sj_ring_buffer_destroy(SjRingBuffer *arg0);
void sj_ring_buffer_error_halt(void *, s32);
s32 sj_ring_buffer_get_available(SjRingBuffer *arg0, s32 arg1);
u8 *sj_ring_buffer_get_buffer(SjRingBuffer *buffer);
s32 sj_ring_buffer_get_buffer_size(SjRingBuffer *buffer);
void sj_ring_buffer_get_chunk(SjRingBuffer *r, s32 which, s32 max, SjChunk *out);
s32 sj_ring_buffer_get_extra_buffer_size(SjRingBuffer *buffer);
const u8 *sj_ring_buffer_get_uuid(SjRingBuffer *arg0);
void sj_ring_buffer_init(void);
bool sj_ring_buffer_is_chunk_available(SjRingBuffer *o, s32 mode, s32 n, s32 *out);
void sj_ring_buffer_put_chunk(SjRingBuffer *o, s32 mode, SjChunk *b);
void sj_ring_buffer_reset(SjRingBuffer *arg0);
void sj_ring_buffer_shutdown(void);
void sj_ring_buffer_unget_chunk(SjRingBuffer *arg0, s32 arg1, SjChunk *arg2);
}

// --- C functions defined in SjRingBuffer.cpp ---
extern "C" {
SjRingBuffer *sj_ring_buffer_create(void *data, s32 bsize, s32 x24);
void sj_ring_buffer_destroy(SjRingBuffer *sj_ring_buffer);
void sj_ring_buffer_error_halt(void *, s32);
s32 sj_ring_buffer_get_available(SjRingBuffer *sj_ring_buffer, s32 arg1);
u8 *sj_ring_buffer_get_buffer(SjRingBuffer *buffer);
s32 sj_ring_buffer_get_buffer_size(SjRingBuffer *buffer);
void sj_ring_buffer_get_chunk(SjRingBuffer *r, s32 which, s32 max, SjChunk *out);
s32 sj_ring_buffer_get_extra_buffer_size(SjRingBuffer *buffer);
const u8 *sj_ring_buffer_get_uuid(SjRingBuffer *sj_ring_buffer);
void sj_ring_buffer_init(void);
bool sj_ring_buffer_is_chunk_available(SjRingBuffer *o, s32 mode, s32 n, s32 *out);
void sj_ring_buffer_put_chunk(SjRingBuffer *o, s32 mode, SjChunk *b);
void sj_ring_buffer_reset(SjRingBuffer *sj_ring_buffer);
void sj_ring_buffer_shutdown(void);
void sj_ring_buffer_unget_chunk(SjRingBuffer *sj_ring_buffer, s32 arg1, SjChunk *sj_chunk);
}
// --- end of C functions

#endif
