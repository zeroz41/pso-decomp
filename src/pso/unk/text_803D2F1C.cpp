#include "types.h"
#include <string.h>
#include "pso/unk/text_803D2F1C.h"
#include "pso/audio/SjRingBuffer.h"

struct ByteBlock_8 { u8 bytes[0x8]; };

extern "C" {
u32 lbl_804F9E60[112] = {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0,
    0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 10, 11, 12, 13, 14, 15, 0, 0, 0, 0, 0, 0, 0, 0, 0,
};

#define HEX_803D2F1C(p, i) lbl_804F9E60[(s8)(p)[i]]
inline s32 size_803D2F1C(u8 *p) {
    s32 v = HEX_803D2F1C(p, 8);
    v = (v << 4) + HEX_803D2F1C(p, 9);
    v = (v << 4) + HEX_803D2F1C(p, 10);
    v = (v << 4) + HEX_803D2F1C(p, 11);
    v = (v << 4) + HEX_803D2F1C(p, 12);
    v = (v << 4) + HEX_803D2F1C(p, 13);
    v = (v << 4) + HEX_803D2F1C(p, 14);
    return v;
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
            out->size = size_803D2F1C(p);
            break;
        }
        if (stop != NULL && strncmp((char *)p, stop, 7) == 0) {
            return NULL;
        }
        p += size_803D2F1C(p) + 0x10;
    }
    if (p < end) {
        return p;
    }
    return NULL;
}

#pragma push
#pragma scheduling off
void TLobby__sub_803D3130(const SjChunk *chunk, s32 size, SjChunk *prefix, SjChunk *remainder) {
    *(ByteBlock_8 *)(prefix) = *(const ByteBlock_8 *)(chunk);
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
#pragma pop

}
