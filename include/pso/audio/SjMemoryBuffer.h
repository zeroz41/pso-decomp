#ifndef PSO_AUDIO_SJMEMORYBUFFER_H
#define PSO_AUDIO_SJMEMORYBUFFER_H
#include "pso/audio/SjRingBuffer.h"

struct SjMemoryBuffer;
struct SjMemoryBufferInterface {
    void* field_00;
    void* field_04;
    void* field_08;
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
typedef char SjMemoryBuffer_size[sizeof(SjMemoryBuffer)==0x24 ? 1 : -1];
typedef char SjMemoryBufferInterface_size[sizeof(SjMemoryBufferInterface)==0x30 ? 1 : -1];

extern "C" {
s32 sj_memory_buffer_is_chunk_available(SjMemoryBuffer* arg0, s32 arg1, s32 arg2, s32* arg3);
void sj_memory_buffer_unget_chunk(SjMemoryBuffer* arg0, s32 arg1, SjChunk* arg2);
void sj_memory_buffer_put_chunk(SjMemoryBuffer* arg0, u32 arg1, SjChunk* arg2);
void sj_memory_buffer_get_chunk(SjMemoryBuffer* arg0, s32 arg1, s32 arg2, SjChunk* arg3);
s32 sj_memory_buffer_get_available(SjMemoryBuffer* arg0, s32 arg1);
void sj_memory_buffer_reset(SjMemoryBuffer* arg0);
void sj_memory_buffer_set_error_callback(SjMemoryBuffer* arg0, SjErrorCallback arg1, void* arg2);
const u8* sj_memory_buffer_get_uuid(SjMemoryBuffer* arg0);
void sj_memory_buffer_destroy(SjMemoryBuffer* arg0);
SjMemoryBuffer* sj_memory_buffer_create(void* arg0, s32 arg1);
void sj_memory_buffer_shutdown(void);
void sj_memory_buffer_init(void);
}

extern "C" {
SjMemoryBuffer *sj_memory_buffer_create(void *arg0, s32 arg1);
void sj_memory_buffer_destroy(SjMemoryBuffer *arg0);
void sj_memory_buffer_error_halt(void *, s32);
s32 sj_memory_buffer_get_available(SjMemoryBuffer *arg0, s32 arg1);
void sj_memory_buffer_get_chunk(SjMemoryBuffer *arg0, s32 arg1, s32 arg2, SjChunk *arg3);
const u8 *sj_memory_buffer_get_uuid(SjMemoryBuffer *arg0);
void sj_memory_buffer_init(void);
s32 sj_memory_buffer_is_chunk_available(SjMemoryBuffer *arg0, s32 arg1, s32 arg2, s32 *arg3);
void sj_memory_buffer_put_chunk(SjMemoryBuffer *arg0, u32 arg1, SjChunk *arg2);
void sj_memory_buffer_reset(SjMemoryBuffer *arg0);
void sj_memory_buffer_shutdown(void);
void sj_memory_buffer_unget_chunk(SjMemoryBuffer *arg0, s32 arg1, SjChunk *arg2);
}

// --- C functions defined in SjMemoryBuffer.cpp ---
extern "C" {
SjMemoryBuffer *sj_memory_buffer_create(void *arg0, s32 arg1);
void sj_memory_buffer_destroy(SjMemoryBuffer *sj_memory_buffer);
void sj_memory_buffer_error_halt(void *, s32);
s32 sj_memory_buffer_get_available(SjMemoryBuffer *sj_memory_buffer, s32 arg1);
void sj_memory_buffer_get_chunk(SjMemoryBuffer *sj_memory_buffer, s32 arg1, s32 arg2, SjChunk *sj_chunk);
const u8 *sj_memory_buffer_get_uuid(SjMemoryBuffer *sj_memory_buffer);
void sj_memory_buffer_init(void);
s32 sj_memory_buffer_is_chunk_available(SjMemoryBuffer *sj_memory_buffer, s32 arg1, s32 arg2, s32 *arg3);
void sj_memory_buffer_put_chunk(SjMemoryBuffer *sj_memory_buffer, u32 arg1, SjChunk *sj_chunk);
void sj_memory_buffer_reset(SjMemoryBuffer *sj_memory_buffer);
void sj_memory_buffer_shutdown(void);
void sj_memory_buffer_unget_chunk(SjMemoryBuffer *sj_memory_buffer, s32 arg1, SjChunk *sj_chunk);
}
// --- end of C functions

#endif
