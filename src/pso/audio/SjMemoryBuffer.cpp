#include "pso/system/MiddlewareInterruptLock.h"
#include "pso/audio/SjMemoryBuffer.h"
extern "C" {
s32 memset(void*, int, int);
extern SjMemoryBuffer sj_memory_buffer_pool[32];
extern s32 sj_memory_buffer_init_count;
extern SjMemoryBufferInterface sj_memory_buffer_interface;
__declspec(section ".rodata") extern const u8 sj_memory_buffer_uuid[16];
void sj_memory_buffer_set_error_callback(SjMemoryBuffer* arg0, SjErrorCallback arg1, void* arg2);

s32 sj_memory_buffer_is_chunk_available(SjMemoryBuffer* sj_memory_buffer, s32 arg1, s32 arg2, s32* arg3) {
    s32 n;
    middleware_interrupt_lock_enter();
    if (arg1 == 0) {
        n = 0;
    } else if (arg1 == 1) {
        n = sj_memory_buffer->readable_bytes < arg2 ? sj_memory_buffer->readable_bytes : arg2;
    } else {
        n = 0;
        if (sj_memory_buffer->error_callback != 0) {
            sj_memory_buffer->error_callback(sj_memory_buffer->error_context, -3);
        }
    }
    *arg3 = n;
    middleware_interrupt_lock_leave();
    { u32 r = (u32)__cntlzw(arg2 - n) >> 5; return r; }
}

void sj_memory_buffer_unget_chunk(SjMemoryBuffer* sj_memory_buffer, s32 arg1, SjChunk* sj_chunk) {
  s32 d;
  s32 len;
  s32 n;
  s32 lim;
  s32 p;
  if ((sj_chunk->size <= 0) || (sj_chunk->data == 0))
  {
    return;
  }
  middleware_interrupt_lock_enter();
  if (arg1 == 0)
  {
    if (sj_memory_buffer->error_callback != 0)
    {
      sj_memory_buffer->error_callback(sj_memory_buffer->error_context, -3);
    }
  }
  else
    if (arg1 == 1)
  {
 dummy_label_788039: ;
    len = sj_chunk->size;
    d = sj_memory_buffer->read_position;
    if (((!sj_chunk) && (!sj_chunk)) && (!sj_chunk))
    {
    }
    d -= len;
    n = d & (((s32) ((-d) & (~d))) >> 31);
    sj_memory_buffer->read_position = n;
    p = sj_memory_buffer->readable_bytes + sj_chunk->size;
    lim = sj_memory_buffer->buffer_size;
    if (lim < p)
    {
      p = lim;
    }
    sj_memory_buffer->readable_bytes = p;
    if (n != ((s32) (sj_chunk->data - sj_memory_buffer->buffer)))
    {
      if (sj_memory_buffer->error_callback != 0)
      {
        sj_memory_buffer->error_callback(sj_memory_buffer->error_context, -3);
      }
    }
  }
  else
  {
    sj_chunk->size = 0;
    sj_chunk->data = 0;
    if (sj_memory_buffer->error_callback != 0)
    {
      sj_memory_buffer->error_callback(sj_memory_buffer->error_context, -3);
    }
  }
  middleware_interrupt_lock_leave();
}

void sj_memory_buffer_put_chunk(SjMemoryBuffer* sj_memory_buffer, u32 arg1, SjChunk* sj_chunk) {
    if (sj_chunk->size <= 0 || sj_chunk->data == 0) {
        return;
    }
    middleware_interrupt_lock_enter();
    if (arg1 > 1) {
        sj_chunk->size = 0;
        sj_chunk->data = 0;
        if (sj_memory_buffer->error_callback != 0) {
            sj_memory_buffer->error_callback(sj_memory_buffer->error_context, -3);
        }
    }
    middleware_interrupt_lock_leave();
}

void sj_memory_buffer_get_chunk(SjMemoryBuffer* sj_memory_buffer, s32 arg1, s32 arg2, SjChunk* sj_chunk) {
    middleware_interrupt_lock_enter();
    if (arg1 == 0) {
        sj_chunk->size = 0;
        sj_chunk->data = 0;
    } else if (arg1 == 1) {
        sj_chunk->size = sj_memory_buffer->readable_bytes < arg2 ? sj_memory_buffer->readable_bytes : arg2;
        sj_chunk->data = sj_memory_buffer->buffer + sj_memory_buffer->read_position;
        sj_memory_buffer->read_position += sj_chunk->size;
        sj_memory_buffer->readable_bytes -= sj_chunk->size;
    } else {
        sj_chunk->size = 0;
        sj_chunk->data = 0;
        if (sj_memory_buffer->error_callback != 0) {
            sj_memory_buffer->error_callback(sj_memory_buffer->error_context, -3);
        }
    }
    middleware_interrupt_lock_leave();
}

#pragma optimize_for_size on

s32 sj_memory_buffer_get_available(SjMemoryBuffer* sj_memory_buffer, s32 arg1) {
    SjErrorCallback temp_r12;

    if (arg1 == 1) {
        return sj_memory_buffer->readable_bytes;
    }
    if (arg1 == 0) {
        return 0;
    }
    temp_r12 = sj_memory_buffer->error_callback;
    if (temp_r12 != NULL) {
        temp_r12(sj_memory_buffer->error_context, -3);
    }
    return 0;
}

void sj_memory_buffer_reset(SjMemoryBuffer* sj_memory_buffer) {
    sj_memory_buffer->readable_bytes = (s32) sj_memory_buffer->buffer_size;
    sj_memory_buffer->read_position = 0;
}

void sj_memory_buffer_set_error_callback(SjMemoryBuffer* sj_memory_buffer, SjErrorCallback arg1, void* arg2) {
    sj_memory_buffer->error_callback = arg1;
    sj_memory_buffer->error_context = arg2;
}

const u8* sj_memory_buffer_get_uuid(SjMemoryBuffer* sj_memory_buffer) {
    return sj_memory_buffer->type_uuid;
}

void sj_memory_buffer_destroy(SjMemoryBuffer* sj_memory_buffer) {
    if (sj_memory_buffer != NULL) {
        memset(sj_memory_buffer, 0, 0x24);
        sj_memory_buffer->in_use = 0;
    }
}

#pragma push
#pragma optimize_for_size off
SjMemoryBuffer* sj_memory_buffer_create(void* arg0, s32 arg1) {
    s32 i;
    SjMemoryBuffer *s;
    for (i = 0; i < 32; i++) {
        if (((SjMemoryBuffer *)&sj_memory_buffer_pool)[i].in_use == 0) {
            break;
        }
    }
    if (i == 32) {
        return NULL;
    }
    s = &((SjMemoryBuffer *)&sj_memory_buffer_pool)[i];
    s->in_use = 1;
    s->interface = &sj_memory_buffer_interface;
    s->buffer = (u8*)arg0;
    s->buffer_size = arg1;
    s->type_uuid = sj_memory_buffer_uuid;
    s->error_callback = sj_memory_buffer_error_halt;
    s->error_context = s;
    s->readable_bytes = s->buffer_size;
    s->read_position = 0;
    return s;
}
#pragma pop

void sj_memory_buffer_shutdown(void) {
    s32 temp_r0;
    temp_r0 = sj_memory_buffer_init_count - 1;
    sj_memory_buffer_init_count = temp_r0;
    if (temp_r0 == 0) {
        memset(&sj_memory_buffer_pool, 0, 0x480);
    }
}

void sj_memory_buffer_init(void) {
    if ((s32) sj_memory_buffer_init_count == 0) {
        memset(sj_memory_buffer_pool, 0, 0x480);
    }
    sj_memory_buffer_init_count += 1;
}

void sj_memory_buffer_error_halt(void*, s32) {
    while (1) {
    }
}

SjMemoryBuffer sj_memory_buffer_pool[32];
s32 sj_memory_buffer_init_count;
__declspec(section ".rodata") extern const u8 sj_memory_buffer_uuid[16] = {0xDD, 0x9E, 0xEE, 0x41, 0x16, 0x79, 0x11, 0xD2, 0x93, 0x6C, 0x00, 0x60, 0x08, 0x94, 0x48, 0xBC};
SjMemoryBufferInterface sj_memory_buffer_interface = {
    0,
    0,
    0,
    sj_memory_buffer_destroy,
    sj_memory_buffer_get_uuid,
    sj_memory_buffer_reset,
    sj_memory_buffer_get_chunk,
    sj_memory_buffer_unget_chunk,
    sj_memory_buffer_put_chunk,
    sj_memory_buffer_get_available,
    sj_memory_buffer_is_chunk_available,
    sj_memory_buffer_set_error_callback
};
}
