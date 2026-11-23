#ifndef PSO_AUDIO_SJRINGBUFFER_H
#define PSO_AUDIO_SJRINGBUFFER_H
#include "types.h"

struct SjRingBuffer;
struct SjChunk { u8* data; s32 size; };
typedef void (*SjErrorCallback)(void* context, s32 error);
struct SjRingBufferInterface {
    void* pad_00;
    void* pad_04;
    void* pad_08;
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
LAYOUT_ASSERT(SjRingBuffer_size, sizeof(SjRingBuffer)==0x30);
LAYOUT_ASSERT(SjRingBufferInterface_size, sizeof(SjRingBufferInterface)==0x30);

// --- C functions defined in SjRingBuffer.cpp ---
extern "C" {
SjRingBuffer* sj_ring_buffer_create(void* buffer, s32 buffer_size, s32 extra_buffer_size);
void sj_ring_buffer_destroy(SjRingBuffer* buffer);
void sj_ring_buffer_error_halt(void* context, s32 error);
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
s32 sj_ring_buffer_get_extra_buffer_size(SjRingBuffer* buffer);
s32 sj_ring_buffer_get_buffer_size(SjRingBuffer* buffer);
u8* sj_ring_buffer_get_buffer(SjRingBuffer* buffer);
}
// --- end of C functions

#endif
