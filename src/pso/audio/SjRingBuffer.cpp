#include <string.h>
#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/SjRingBuffer.h"

#pragma optimize_for_size off

extern "C" {
s32 sj_ring_buffer_get_extra_buffer_size(SjRingBuffer* buffer) { return buffer->extra_buffer_size; }
s32 sj_ring_buffer_get_buffer_size(SjRingBuffer* buffer) { return buffer->buffer_size; }
u8* sj_ring_buffer_get_buffer(SjRingBuffer* buffer) { return buffer->buffer; }
#define SJ_MIN(a, b) ((a) < (b) ? (a) : (b))

bool sj_ring_buffer_is_chunk_available(SjRingBuffer *buffer, s32 side, s32 requested_size, s32 *available_size) {
    s32 t;
    middleware_interrupt_lock_enter();
    if (side == 0) {
        t = SJ_MIN(buffer->writable_bytes, buffer->extra_buffer_size + (buffer->buffer_size - buffer->write_position));
        side = SJ_MIN(t, requested_size);
    } else if (side == 1) {
        t = SJ_MIN(buffer->readable_bytes, buffer->extra_buffer_size + (buffer->buffer_size - buffer->read_position));
        side = SJ_MIN(t, requested_size);
    } else {
        side = 0;
        if (buffer->error_callback != 0) {
            buffer->error_callback(buffer->error_context, -3);
        }
    }
    *available_size = side;
    middleware_interrupt_lock_leave();
    return !(requested_size - side);
}

void sj_ring_buffer_unget_chunk(SjRingBuffer *sj_ring_buffer, s32 side, SjChunk *sj_chunk) {
    SjErrorCallback err_cb_w;
    SjErrorCallback err_cb_r;
    SjErrorCallback err_cb_bad;
    s32 write_pos;
    s32 read_pos;
    s32 buf_size_w;
    s32 buf_size_r;
    if ((s32) sj_chunk->size <= 0 || sj_chunk->data == NULL) {
        return;
    }
        middleware_interrupt_lock_enter();
        if (side == 0) {
            buf_size_w = sj_ring_buffer->buffer_size;
            write_pos = ((sj_ring_buffer->write_position + buf_size_w) - sj_chunk->size) % buf_size_w;
            if (write_pos == ((sj_chunk->data - sj_ring_buffer->buffer) % buf_size_w)) {
                sj_ring_buffer->write_position = write_pos;
                sj_ring_buffer->writable_bytes = (s32) (sj_ring_buffer->writable_bytes + sj_chunk->size);
            } else {
                err_cb_w = sj_ring_buffer->error_callback;
                if (err_cb_w != NULL) {
                    err_cb_w(sj_ring_buffer->error_context, -3);
                }
            }
        } else if (side == 1) {
            buf_size_r = sj_ring_buffer->buffer_size;
            read_pos = ((sj_ring_buffer->read_position + buf_size_r) - sj_chunk->size) % buf_size_r;
            if (read_pos == ((sj_chunk->data - sj_ring_buffer->buffer) % buf_size_r)) {
                sj_ring_buffer->read_position = read_pos;
                sj_ring_buffer->readable_bytes = (s32) (sj_ring_buffer->readable_bytes + sj_chunk->size);
            } else {
                err_cb_r = sj_ring_buffer->error_callback;
                if (err_cb_r != NULL) {
                    err_cb_r(sj_ring_buffer->error_context, -3);
                }
            }
        } else {
            sj_chunk->size = 0;
            sj_chunk->data = 0;
            err_cb_bad = sj_ring_buffer->error_callback;
            if (err_cb_bad != NULL) {
                err_cb_bad(sj_ring_buffer->error_context, -3);
            }
        }
        middleware_interrupt_lock_leave();
    }

void sj_ring_buffer_put_chunk(SjRingBuffer *buffer, s32 side, SjChunk *chunk) {
    s32 d;
    s32 n;
    s32 e;
    if (chunk->size <= 0 || chunk->data == 0) {
        return;
    }
    middleware_interrupt_lock_enter();
    if (side == 1) {
        buffer->readable_bytes += chunk->size;
        d = chunk->data - buffer->buffer;
        if (d < buffer->extra_buffer_size) {
            n = SJ_MIN(chunk->size, buffer->extra_buffer_size - d);
            memcpy(buffer->buffer + (buffer->buffer_size + d), chunk->data, n);
        }
        e = (chunk->data - buffer->buffer) + chunk->size;
        if (e > buffer->buffer_size) {
            n = SJ_MIN(chunk->size, e - buffer->buffer_size);
            memcpy(buffer->buffer, buffer->buffer + (e - n), n);
        }
    } else if (side == 0) {
        buffer->writable_bytes += chunk->size;
    } else {
        chunk->size = 0;
        chunk->data = 0;
        if (buffer->error_callback != 0) {
            buffer->error_callback(buffer->error_context, -3);
        }
    }
    middleware_interrupt_lock_leave();
}

void sj_ring_buffer_get_chunk(SjRingBuffer *buffer, s32 side, s32 requested_size, SjChunk *chunk) {
    middleware_interrupt_lock_enter();
    if (side == 0) {
        chunk->size = SJ_MIN(buffer->writable_bytes, buffer->extra_buffer_size + (buffer->buffer_size - buffer->write_position));
        chunk->size = SJ_MIN(chunk->size, requested_size);
        chunk->data = buffer->buffer + buffer->write_position;
        buffer->write_position = (buffer->write_position + chunk->size) % buffer->buffer_size;
        buffer->writable_bytes -= chunk->size;
    } else if (side == 1) {
        chunk->size = SJ_MIN(buffer->readable_bytes, buffer->extra_buffer_size + (buffer->buffer_size - buffer->read_position));
        chunk->size = SJ_MIN(chunk->size, requested_size);
        chunk->data = buffer->buffer + buffer->read_position;
        buffer->read_position = (buffer->read_position + chunk->size) % buffer->buffer_size;
        buffer->readable_bytes -= chunk->size;
    } else {
        chunk->size = 0;
        chunk->data = 0;
        if (buffer->error_callback != NULL) {
            buffer->error_callback(buffer->error_context, -3);
        }
    }
    middleware_interrupt_lock_leave();
}

#pragma optimize_for_size on

s32 sj_ring_buffer_get_available(SjRingBuffer *sj_ring_buffer, s32 side) {
    SjErrorCallback error_callback;

    if (side == 1) {
        return sj_ring_buffer->readable_bytes;
    }
    if (side == 0) {
        return sj_ring_buffer->writable_bytes;
    }
    error_callback = sj_ring_buffer->error_callback;
    if (error_callback != NULL) {
        error_callback(sj_ring_buffer->error_context, -3);
    }
    return 0;
}

void sj_ring_buffer_reset(SjRingBuffer *sj_ring_buffer) {
    sj_ring_buffer->readable_bytes = 0;
    sj_ring_buffer->writable_bytes = (s32) sj_ring_buffer->buffer_size;
    sj_ring_buffer->write_position = 0;
    sj_ring_buffer->read_position = 0;
}

void sj_ring_buffer_set_error_callback(SjRingBuffer *sj_ring_buffer, SjErrorCallback callback, void* context) {
    sj_ring_buffer->error_callback = callback;
    sj_ring_buffer->error_context = context;
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
SjRingBuffer *sj_ring_buffer_create(void* buffer, s32 buffer_size, s32 extra_buffer_size) {
    SjRingBuffer *s;
    s32 i;
    middleware_interrupt_lock_enter();
    for (i = 0; i < 256; i++) {
        if (sj_ring_buffer_pool[i].in_use == 0) {
            break;
        }
    }
    if (i == 256) {
        s = 0;
    } else {
        s = &sj_ring_buffer_pool[i];
        s->in_use = 1;
        s->interface = &sj_ring_buffer_interface;
        s->buffer = (u8*)buffer;
        s->buffer_size = buffer_size;
        s->extra_buffer_size = extra_buffer_size;
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
    s32 ref_count;
    ref_count = sj_ring_buffer_init_count - 1;
    sj_ring_buffer_init_count = ref_count;
    if (ref_count == 0) {
        memset(sj_ring_buffer_pool, 0, sizeof(sj_ring_buffer_pool));
    }
}

void sj_ring_buffer_init(void) {
    const char *ver = sj_version_pointer;
    if (sj_ring_buffer_init_count == 0) {
        memset(sj_ring_buffer_pool, 0, sizeof(sj_ring_buffer_pool));
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
