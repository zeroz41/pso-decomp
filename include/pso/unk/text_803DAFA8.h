#ifndef PSO_UNK_TEXT_803DAFA8_H
#define PSO_UNK_TEXT_803DAFA8_H

#include "types.h"

struct GinjaTextureHeader;

// A GVPL palette chunk: the palette's GX format and entry count, then its entries.
struct GvplChunk {
    u32 magic;
    u32 size;
    u16 format;
    s16 pad_0A;
    s16 pad_0C;
    s16 entry_count;
    u8 data[1];
};

// Where fn_803DAFA8 copies a palette's entries, and the layout it records for them.
struct GvplPalette {
    void *data;
    u16 format;
    s16 pad_06;
    s16 pad_08;
    s16 entry_count;
};

extern "C" {
s32 fn_803DAFA8(GvplChunk *chunk, GvplPalette *palette);
void init_and_load_tlut(s32 tlut_name, s32 format, s32 entry_count, void *entries);
s32 init_ginja_texture_header(GinjaTextureHeader *header, u32 width, u32 height, u32 format);
u32 fn_803DB15C(GinjaTextureHeader *header);
s32 alloc_buffer_from_heap(GinjaTextureHeader *header);
s32 fn_803DB20C(GinjaTextureHeader *header);
}

#endif
