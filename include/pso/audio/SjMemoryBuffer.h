#ifndef PSO_AUDIO_SJMEMORYBUFFER_H
#define PSO_AUDIO_SJMEMORYBUFFER_H
#include "pso/audio/SjRingBuffer.h"

struct SjMemoryBuffer;
struct SjMemoryBufferInterface {
    void* pad_00;
    void* pad_04;
    void* pad_08;
    void (*destroy)(SjMemoryBuffer*);
    const u8* (*get_uuid)(SjMemoryBuffer*);
    void (*reset)(SjMemoryBuffer*);
    void (*get_chunk)(SjMemoryBuffer*, s32, s32, SjChunk*);
    void (*unget_chunk)(SjMemoryBuffer*, s32, SjChunk*);
    void (*put_chunk)(SjMemoryBuffer*, u32, SjChunk*);
    s32 (*get_available)(SjMemoryBuffer*, s32);
    s32 (*is_chunk_available)(SjMemoryBuffer*, s32, s32, s32*);
    void (*set_error_callback)(SjMemoryBuffer*, SjErrorCallback, void*);
};
struct SjMemoryBuffer {
    const SjMemoryBufferInterface* interface;
    s32 in_use;
    const u8* type_uuid;
    s32 readable_bytes;
    s32 read_position;
    u8* buffer;
    s32 buffer_size;
    SjErrorCallback error_callback;
    void* error_context;
};
LAYOUT_ASSERT(SjMemoryBuffer_size, sizeof(SjMemoryBuffer)==0x24);
LAYOUT_ASSERT(SjMemoryBufferInterface_size, sizeof(SjMemoryBufferInterface)==0x30);

// --- C functions defined in SjMemoryBuffer.cpp ---
extern "C" {
s32 sj_memory_buffer_is_chunk_available(SjMemoryBuffer* buffer, s32 side, s32 requested_size, s32* available_size);
void sj_memory_buffer_unget_chunk(SjMemoryBuffer* buffer, s32 side, SjChunk* chunk);
void sj_memory_buffer_put_chunk(SjMemoryBuffer* buffer, u32 side, SjChunk* chunk);
void sj_memory_buffer_get_chunk(SjMemoryBuffer* buffer, s32 side, s32 requested_size, SjChunk* chunk);
s32 sj_memory_buffer_get_available(SjMemoryBuffer* buffer, s32 side);
void sj_memory_buffer_reset(SjMemoryBuffer* buffer);
void sj_memory_buffer_set_error_callback(SjMemoryBuffer* buffer, SjErrorCallback callback, void* context);
const u8* sj_memory_buffer_get_uuid(SjMemoryBuffer* buffer);
void sj_memory_buffer_destroy(SjMemoryBuffer* buffer);
SjMemoryBuffer* sj_memory_buffer_create(void* data, s32 buffer_size);
void sj_memory_buffer_shutdown(void);
void sj_memory_buffer_init(void);
void sj_memory_buffer_error_halt(void* context, s32 error);
}
// --- end of C functions

#endif
