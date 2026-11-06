#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/SjRingBuffer.h"

#pragma optimize_for_size off

extern "C" {
s32 sj_ring_buffer_get_extra_buffer_size(SjRingBuffer* buffer) { return buffer->extra_buffer_size; }
s32 sj_ring_buffer_get_buffer_size(SjRingBuffer* buffer) { return buffer->buffer_size; }
u8* sj_ring_buffer_get_buffer(SjRingBuffer* buffer) { return buffer->buffer; }
void *memcpy(void *, const void *, unsigned long);
#define MIN_803D2A14(a, b) ((a) < (b) ? (a) : (b))

#define MIN_803D2640(a, b) ((a) < (b) ? (a) : (b))
bool sj_ring_buffer_is_chunk_available(SjRingBuffer *o, s32 mode, s32 n, s32 *out) {
    s32 t;
    middleware_interrupt_lock_enter();
    if (mode == 0) {
        t = MIN_803D2640(o->writable_bytes, o->extra_buffer_size + (o->buffer_size - o->write_position));
        mode = MIN_803D2640(t, n);
    } else if (mode == 1) {
        t = MIN_803D2640(o->readable_bytes, o->extra_buffer_size + (o->buffer_size - o->read_position));
        mode = MIN_803D2640(t, n);
    } else {
        mode = 0;
        if (o->error_callback != 0) {
            o->error_callback(o->error_context, -3);
        }
    }
    *out = mode;
    middleware_interrupt_lock_leave();
    return !(n - mode);
}

void sj_ring_buffer_unget_chunk(SjRingBuffer *sj_ring_buffer, s32 arg1, SjChunk *sj_chunk) {
    SjErrorCallback temp_r12;
    SjErrorCallback temp_r12_2;
    SjErrorCallback temp_r12_3;
    s32 temp_r4;
    s32 temp_r4_2;
    s32 temp_r6;
    s32 temp_r6_2;
    if ((s32) sj_chunk->size <= 0 || sj_chunk->data == NULL) {
        return;
    }
        middleware_interrupt_lock_enter();
        if (arg1 == 0) {
            temp_r6 = sj_ring_buffer->buffer_size;
            temp_r4 = ((sj_ring_buffer->write_position + temp_r6) - sj_chunk->size) % temp_r6;
            if (temp_r4 == ((sj_chunk->data - sj_ring_buffer->buffer) % temp_r6)) {
                sj_ring_buffer->write_position = temp_r4;
                sj_ring_buffer->writable_bytes = (s32) (sj_ring_buffer->writable_bytes + sj_chunk->size);
            } else {
                temp_r12 = sj_ring_buffer->error_callback;
                if (temp_r12 != NULL) {
                    temp_r12(sj_ring_buffer->error_context, -3);
                }
            }
        } else if (arg1 == 1) {
            temp_r6_2 = sj_ring_buffer->buffer_size;
            temp_r4_2 = ((sj_ring_buffer->read_position + temp_r6_2) - sj_chunk->size) % temp_r6_2;
            if (temp_r4_2 == ((sj_chunk->data - sj_ring_buffer->buffer) % temp_r6_2)) {
                sj_ring_buffer->read_position = temp_r4_2;
                sj_ring_buffer->readable_bytes = (s32) (sj_ring_buffer->readable_bytes + sj_chunk->size);
            } else {
                temp_r12_2 = sj_ring_buffer->error_callback;
                if (temp_r12_2 != NULL) {
                    temp_r12_2(sj_ring_buffer->error_context, -3);
                }
            }
        } else {
            sj_chunk->size = 0;
            sj_chunk->data = 0;
            temp_r12_3 = sj_ring_buffer->error_callback;
            if (temp_r12_3 != NULL) {
                temp_r12_3(sj_ring_buffer->error_context, -3);
            }
        }
        middleware_interrupt_lock_leave();
    }

#define MIN_803D28D8(a, b) ((a) < (b) ? (a) : (b))
void sj_ring_buffer_put_chunk(SjRingBuffer *o, s32 mode, SjChunk *b) {
    s32 d;
    s32 n;
    s32 e;
    if (b->size <= 0 || b->data == 0) {
        return;
    }
    middleware_interrupt_lock_enter();
    if (mode == 1) {
        o->readable_bytes += b->size;
        d = b->data - o->buffer;
        if (d < o->extra_buffer_size) {
            n = MIN_803D28D8(b->size, o->extra_buffer_size - d);
            memcpy(o->buffer + (o->buffer_size + d), b->data, n);
        }
        e = (b->data - o->buffer) + b->size;
        if (e > o->buffer_size) {
            n = MIN_803D28D8(b->size, e - o->buffer_size);
            memcpy(o->buffer, o->buffer + (e - n), n);
        }
    } else if (mode == 0) {
        o->writable_bytes += b->size;
    } else {
        b->size = 0;
        b->data = 0;
        if (o->error_callback != 0) {
            o->error_callback(o->error_context, -3);
        }
    }
    middleware_interrupt_lock_leave();
}

void sj_ring_buffer_get_chunk(SjRingBuffer *r, s32 which, s32 max, SjChunk *out) {
    middleware_interrupt_lock_enter();
    if (which == 0) {
        out->size = MIN_803D2A14(r->writable_bytes, r->extra_buffer_size + (r->buffer_size - r->write_position));
        out->size = MIN_803D2A14(out->size, max);
        out->data = r->buffer + r->write_position;
        r->write_position = (r->write_position + out->size) % r->buffer_size;
        r->writable_bytes -= out->size;
    } else if (which == 1) {
        out->size = MIN_803D2A14(r->readable_bytes, r->extra_buffer_size + (r->buffer_size - r->read_position));
        out->size = MIN_803D2A14(out->size, max);
        out->data = r->buffer + r->read_position;
        r->read_position = (r->read_position + out->size) % r->buffer_size;
        r->readable_bytes -= out->size;
    } else {
        out->size = 0;
        out->data = 0;
        if (r->error_callback != NULL) {
            r->error_callback(r->error_context, -3);
        }
    }
    middleware_interrupt_lock_leave();
}

#pragma optimize_for_size on
void sj_ring_buffer_set_error_callback(SjRingBuffer *arg0, SjErrorCallback arg1, void* arg2);
s32 memset(void *, int, int);

s32 sj_ring_buffer_get_available(SjRingBuffer *sj_ring_buffer, s32 arg1) {
    SjErrorCallback temp_r12;

    if (arg1 == 1) {
        return sj_ring_buffer->readable_bytes;
    }
    if (arg1 == 0) {
        return sj_ring_buffer->writable_bytes;
    }
    temp_r12 = sj_ring_buffer->error_callback;
    if (temp_r12 != NULL) {
        temp_r12(sj_ring_buffer->error_context, -3);
    }
    return 0;
}

void sj_ring_buffer_reset(SjRingBuffer *sj_ring_buffer) {
    sj_ring_buffer->readable_bytes = 0;
    sj_ring_buffer->writable_bytes = (s32) sj_ring_buffer->buffer_size;
    sj_ring_buffer->write_position = 0;
    sj_ring_buffer->read_position = 0;
}

void sj_ring_buffer_set_error_callback(SjRingBuffer *sj_ring_buffer, SjErrorCallback arg1, void* arg2) {
    sj_ring_buffer->error_callback = arg1;
    sj_ring_buffer->error_context = arg2;
}

const u8* sj_ring_buffer_get_uuid(SjRingBuffer *sj_ring_buffer) {
    return sj_ring_buffer->type_uuid;
}

void sj_ring_buffer_destroy(SjRingBuffer *sj_ring_buffer) {
    middleware_interrupt_lock_enter();
    if (sj_ring_buffer != NULL) {
        memset(sj_ring_buffer, 0, 0x30);
        sj_ring_buffer->in_use = 0;
    }
    middleware_interrupt_lock_leave();
}

#pragma optimize_for_size off
extern SjRingBuffer sj_ring_buffer_pool[256];
extern s32 sj_ring_buffer_init_count;

extern SjRingBufferInterface sj_ring_buffer_interface;
__declspec(section ".rodata") extern const u8 sj_ring_buffer_uuid[16];
__declspec(section ".sdata2") extern const char *const volatile sj_version_pointer;
SjRingBuffer *sj_ring_buffer_create(void* data, s32 bsize, s32 x24) {
    SjRingBuffer *s;
    s32 i;
    middleware_interrupt_lock_enter();
    for (i = 0; i < 256; i++) {
        if (((SjRingBuffer *)&sj_ring_buffer_pool)[i].in_use == 0) {
            break;
        }
    }
    if (i == 256) {
        s = 0;
    } else {
        s = &((SjRingBuffer *)&sj_ring_buffer_pool)[i];
        s->in_use = 1;
        s->interface = &sj_ring_buffer_interface;
        s->buffer = (u8*)data;
        s->buffer_size = bsize;
        s->extra_buffer_size = x24;
        s->type_uuid = sj_ring_buffer_uuid;
        s->error_callback = sj_ring_buffer_error_halt;
        s->error_context = s;
        s->readable_bytes = 0;
        s->writable_bytes = s->buffer_size;
        s->write_position = 0;
        s->read_position = 0;
    }
    middleware_interrupt_lock_leave();
    return s;
}

void sj_ring_buffer_shutdown(void) {
    s32 temp_r0;
    temp_r0 = sj_ring_buffer_init_count - 1;
    sj_ring_buffer_init_count = temp_r0;
    if (temp_r0 == 0) {
        memset(&sj_ring_buffer_pool, 0, 0x3000);
    }
}

void sj_ring_buffer_init(void) {
    const char *ver = sj_version_pointer;
    if (sj_ring_buffer_init_count == 0) {
        memset(&sj_ring_buffer_pool, 0, 0x3000);
    }
    sj_ring_buffer_init_count += 1;
}

void sj_ring_buffer_error_halt(void*, s32) {
    while (1) {
    }
}

SjRingBuffer sj_ring_buffer_pool[256];
s32 sj_ring_buffer_init_count;
extern const char sj_version_string[] = "\nSJ/GC Ver.6.07 Build:Jun 13 2002 19:00:23\n";
__declspec(section ".rodata") extern const u8 sj_ring_buffer_uuid[16] = {0x3B,0x9A,0x9E,0x81,0x0D,0xBB,0x11,0xD2,0xA6,0xBF,0x44,0x45,0x53,0x54,0x00,0x00};
__declspec(section ".sdata2") extern const char* const volatile sj_version_pointer = sj_version_string;
SjRingBufferInterface sj_ring_buffer_interface = {
    0,0,0,
    sj_ring_buffer_destroy,
    sj_ring_buffer_get_uuid,
    sj_ring_buffer_reset,
    sj_ring_buffer_get_chunk,
    sj_ring_buffer_unget_chunk,
    sj_ring_buffer_put_chunk,
    sj_ring_buffer_get_available,
    sj_ring_buffer_is_chunk_available,
    sj_ring_buffer_set_error_callback
};
}
