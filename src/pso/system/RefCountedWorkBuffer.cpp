#include "types.h"
#include <string.h>
#include "pso/system/RefCountedWorkBuffer.h"
#include "pso/audio/SjRingBuffer.h"

u8 ref_counted_load_buffer[0xC00];
s32 lobby_buffer_refcount;

void ref_counted_work_buffer_finish(void) {
    if (--lobby_buffer_refcount == 0) {
        memset(ref_counted_load_buffer, 0, 0xC00);
    }
}

void ref_counted_work_buffer_init(void) {
    if (lobby_buffer_refcount == 0) {
        memset(ref_counted_load_buffer, 0, 0xC00);
    }
    lobby_buffer_refcount += 1;
}

u32 hex_digit_values[112] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
    0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#define HEX_DIGIT_VALUE(p, i) hex_digit_values[(s8)(p)[i]]
extern "C" {
inline s32 parse_hex_size(u8 *p) {
    s32 v = HEX_DIGIT_VALUE(p, 8);
    v = (v << 4) + HEX_DIGIT_VALUE(p, 9);
    v = (v << 4) + HEX_DIGIT_VALUE(p, 10);
    v = (v << 4) + HEX_DIGIT_VALUE(p, 11);
    v = (v << 4) + HEX_DIGIT_VALUE(p, 12);
    v = (v << 4) + HEX_DIGIT_VALUE(p, 13);
    v = (v << 4) + HEX_DIGIT_VALUE(p, 14);
    return v;
}
}
u8 *find_archive_entry(SjChunk *arc, const char *name, const char *stop, SjChunk *out) {
    u8 *p;
    u8 *end;
    out->data = NULL;
    out->size = 0;
    p = arc->data;
    end = arc->data + arc->size;
    while (p < end) {
        if (strncmp((char *)p, name, 7) == 0) {
            out->data = p + 0x10;
            out->size = parse_hex_size(p);
            break;
        }
        if (stop != NULL && strncmp((char *)p, stop, 7) == 0) {
            return NULL;
        }
        p += parse_hex_size(p) + 0x10;
    }
    if (p < end) {
        return p;
    }
    return NULL;
}

#pragma push
#pragma scheduling off
extern "C" {
void sj_split_chunk(const SjChunk *chunk, s32 size, SjChunk *prefix, SjChunk *remainder) {
    __memcpy(prefix, chunk, sizeof(SjChunk));
    remainder->size = prefix->size;
    if (prefix->size > size) {
        prefix->size = size;
    }
    remainder->size = remainder->size - prefix->size;
    if (remainder->size == 0) {
        remainder->data = NULL;
        return;
    }
    remainder->data = prefix->data + prefix->size;
}
}
#pragma pop
