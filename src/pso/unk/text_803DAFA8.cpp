#define PSO_SDK_COMPACT_MATH
#include <dolphin/gx/GXTexture.h>
#include <dolphin/os/OSAlloc.h>
#undef PSO_SDK_COMPACT_MATH
#include "types.h"
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/RenderSbssGlobals.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803DAF30.h"
#include "pso/unk/text_803DAFA8.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_803DE778.h"

s32 load_gvpl_palette(GvplChunk *chunk, GvplPalette *palette) {
    s32 word;
    reset_texture_error();
    word = chunk->magic;
    fn_803DAF30((u32 *)&word);
    switch (word) {
    case 0x4C505647:
        word = chunk->size;
        fn_803DAF30((u32 *)&word);
        move_data(palette->data, chunk->data, word - 8);
        palette->pad_06 = chunk->pad_0A;
        palette->pad_08 = chunk->pad_0C;
        palette->entry_count = chunk->entry_count;
        palette->format = chunk->format;
        break;
    default:
        return -1;
    }
    return 1;
}

void init_and_load_tlut(s32 tlut_name, s32 format, s32 entry_count, void *entries) {
    GXTlutObj tlut_obj;
    GXInitTlutObj(&tlut_obj, entries, (GXTlutFmt)format, entry_count);
    GXLoadTlut(&tlut_obj, tlut_name);
}

s32 init_ginja_texture_header(GinjaTextureHeader *header, u32 width, u32 height, u32 format) {
    s32 ret = 0;
    u32 flags = 0;
    header->format = (u8)format;
    header->width = width;
    header->height = height;
    if ((format & 0x100) && width != height) {
        ret = 4;
    }
    header->flags = 0;
    if (format & 0x100) {
        flags |= 0x80000000;
    }
    if (format & 0x200) {
        flags |= 0x8000;
    }
    if (format & 0x800) {
        flags |= 0x40000000;
    }
    header->flags |= flags;
    header->size = get_texture_buffer_size(header);
    return ret;
}

u32 get_texture_buffer_size(GinjaTextureHeader *header) {
    GXBool mipmap;
    if (header->flags & 0x80000000) {
        mipmap = 1;
    } else {
        mipmap = 0;
    }
    return GXGetTexBufferSize(header->width, header->height, header->format, mipmap, 100);
}

s32 alloc_buffer_from_heap(GinjaTextureHeader *header) {
    s32 ret = 0;
    void *pixels = OSAllocFromHeap(locked_cache_heap_handle, header->size);
    if (pixels == 0) {
        ret = 3;
    } else {
        header->pixels = (u32 *)pixels;
    }
    return ret;
}

#pragma push
#pragma scheduling off
#pragma peephole off
s32 free_texture_pixels(GinjaTextureHeader *header) {
    OSFreeToHeap(locked_cache_heap_handle, header->pixels);
    return 0;
}
#pragma pop
