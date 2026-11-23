#define PSO_SDK_COMPACT_MATH
#include <dolphin/dvd.h>
#undef PSO_SDK_COMPACT_MATH
#include "pso/render/GinjaMaterialState.h"
#include "pso/render/GinjaTexture.h"
#include "pso/render/GinjaTextureInput.h"
#include "pso/render/GvmTextureArchive.h"
#include "pso/render/RenderSbssGlobals.h"
#include "types.h"
#include <string.h>
#include <dolphin/os/OSCache.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DA798.h"
#include "pso/unk/text_803DD5E0.h"
#include "pso/system/memory.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby_803DE778.h"

s32 gvm_stream_cursor;

// The texture loaders load_texture_entry picks from an entry's format bits.
s32 (*texture_loaders[4])(NJS_TEXLIST *, s32) = {
    read_gvrt_file_header, load_texture_from_memory, create_texture_from_input, reference_texture_by_global_index,
};

extern s32 ginja_draw_flags;

void set_ginja_draw_flags(s32 flags) {
    ginja_draw_flags = flags;
}

void TObjPlayer__sub_803DD5E8(NJS_TEXLIST *list, NJS_TEXNAME *entries, uaddr names, s32 count) {
    int i;

    for (i = 0; i < count; ++i) {
        entries[i].filename = (char *)(names + i * 0x1C);
    }
    list->textures = entries;
}

s32 load_texture_entry(NJS_TEXLIST *list, s32 index) {
    s32 loader;

    switch (list->textures[index].attr & 0x5C000000) {
    case 0x0:
        loader = 0;
        break;
    case 0x40000000:
        loader = 1;
        break;
    case 0x8000000:
        loader = 2;
        break;
    case 0x4000000:
        loader = 3;
        break;
    default:
        loader = 2;
        break;
    }
    return texture_loaders[loader](list, index);
}

s32 gvm_stream_base;

#pragma push
#pragma optimize_for_size off
#pragma use_lmw_stmw off
s32 read_gvrt_file_header(NJS_TEXLIST *list, s32 index) {
    s32 global_index;
    s32 id;
    s32 tlut_name;
    s32 slot;
    GvrTextureDesc desc;
    char name[32];
    DVDFileInfo file;
    u32 chunk;
    s32 r;
    uaddr header = (uaddr)gvrt_header_read_buffer;
    DVDFileInfo *pfile;
    u32 size;
    reset_texture_error();
    r = TObjPlayer__sub_803D9E38((s32 *)list, index, &id, (u32 *)&tlut_name);
    if (r != 0) {
        return r;
    }
    ((TAdSinglePlyChrSelectGC *)name)->append_extension_if_missing(list->textures[index].filename, ".GVR");
    pfile = &file;
    if (DVDOpen(name, pfile) == 0) {
        lbl_8058D470.code = 2;
        return -1;
    }
    size = (file.length + 0x1F) & ~0x1F;
    if (DVDReadPrio(pfile, (void *)header, 0x20, 0, 2) == -1) {
        DVDClose(pfile);
        return -1;
    }
    chunk = (uaddr)find_gvrt_texture_chunk((TLobby *)&desc, (u32 *)&global_index, (u32 *)header);
    if (chunk == 0) {
        DVDClose(pfile);
        return -1;
    }
    if ((u32)id != 0xFFFFFFFF) {
        global_index = id;
    }
    r = TObjPlayer__sub_803DAC48(list, index, global_index, tlut_name, &desc, &slot);
    if (r != 0) {
        DVDClose(pfile);
        return r;
    }
    chunk -= header;
    DVDReadPrio(pfile, record_array_ptr[slot].surface->header.pixels, size - chunk, chunk, 2);
    DVDClose(pfile);
    return 1;
}
#pragma pop

s32 load_texture_from_memory(NJS_TEXLIST *list, s32 index) {
    s32 global_index;
    s32 id;
    s32 tlut_name;
    s32 slot;
    GvrTextureDesc desc;
    s32 r;
    u32 chunk;
    GinjaTextureInput *input;
    reset_texture_error();
    r = TObjPlayer__sub_803D9E38((s32 *)list, index, &id, (u32 *)&tlut_name);
    if (r != 0) {
        return r;
    }
    chunk = (uaddr)find_gvrt_texture_chunk((TLobby *)&desc, (u32 *)&global_index, (u32 *)list->textures[index].filename);
    if (chunk == 0) {
        chunk = (uaddr)find_gvrt_texture_chunk((TLobby *)&desc, (u32 *)&global_index,
                                               (u32 *)reinterpret_cast<GinjaTextureInput *>(list->textures[index].filename)->data);
        if (chunk == 0) {
            input = reinterpret_cast<GinjaTextureInput *>(list->textures[index].filename);
            desc.width = input->width;
            desc.height = input->height;
            desc.format = input->format;
            chunk = (uaddr)input->data;
        }
    }
    if ((u32)id != 0xFFFFFFFF) {
        global_index = id;
    }
    r = TObjPlayer__sub_803DAC48(list, index, global_index, tlut_name, &desc, &slot);
    if (r != 0) {
        return r;
    }
    if (TObjPlayer__sub_803DAB9C(slot, chunk) < 0) {
        TObjPlayer__sub_803DAC1C(slot);
        return -1;
    }
    while (TObjPlayer::is_gvm_load_ok() != 1) {
    }
    return 1;
}

s32 create_texture_from_input(NJS_TEXLIST *list, s32 index) {
    s32 id;
    GvrTextureDesc desc;
    s32 tlut_name;
    s32 slot;
    s32 r;
    s32 global_index;
    GinjaTextureInput *input;
    reset_texture_error();
    r = TObjPlayer__sub_803D9E38((s32 *)list, index, &id, (u32 *)&tlut_name);
    if (r != 0) {
        return r;
    }
    input = reinterpret_cast<GinjaTextureInput *>(list->textures[index].filename);
    desc.width = input->width;
    desc.height = input->height;
    desc.format = input->format;
    global_index = list->textures[index].global_index;
    if ((u32)id != 0xFFFFFFFF) {
        global_index = id;
    }
    if (TObjPlayer__sub_803DAC48(list, index, global_index, tlut_name, &desc, &slot) >= 0) {
        return 1;
    }
    return -1;
}

s32 reference_texture_by_global_index(NJS_TEXLIST *list, s32 index) {
    s32 id;
    s32 tlut_name;
    s32 slot;
    GinjaTextureState *texture;
    GinjaSurfaceState *surface;
    s32 r;
    s32 global_index;
    reset_texture_error();
    r = TObjPlayer__sub_803D9E38((s32 *)list, index, &id, (u32 *)&tlut_name);
    if (r != 0) {
        return r;
    }
    global_index = list->textures[index].global_index;
    if ((u32)id != 0xFFFFFFFF) {
        global_index = id;
    }
    switch (TObjPlayer__sub_803DA8E4(global_index, tlut_name, 0, &slot)) {
    case -1:
        return -1;
    case 0:
        slot = TObjPlayer::find_free_slot(&texture, &surface);
        if (slot < 0) {
            return -1;
        }
        texture->surface = surface;
        if ((u32)global_index != 0xFFFFFFFF) {
            texture->surface->id = global_index;
        }
        player_ref_entry_active_count++;
        TObjPlayer__sub_803DAB7C(list, index, slot);
        break;
    }
    return 1;
}

s32 load_texture_list(NJS_TEXLIST *list) {
    u32 i;
    if (list->nbTexture == 0) {
        lbl_8058D470.code = 1;
        return -1;
    }
    for (i = 0; i < list->nbTexture; i++) {
        if (load_texture_entry(list, i) < 0) {
            lbl_8058D470.entry_index = i;
            return -1;
        }
    }
    return 1;
}

#pragma push
#pragma scheduling off
#pragma peephole off
void TLobby::bswap32_in_place(u32 *p) {
    u32 v = *p;
    *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}
#pragma pop

void gvm_stream_begin(s32 buf) {
    gvm_stream_base = buf;
    gvm_stream_cursor = buf;
}

saddr gvm_stream_read(s32 stride) {
    s32 prevCursor;
    prevCursor = gvm_stream_cursor;
    gvm_stream_cursor = prevCursor + stride;
    return prevCursor;
}

void gvm_stream_seek(s32 offset, s32 whence) {
    switch (whence) {
    case 1:
        gvm_stream_cursor += offset;
        return;
    case 0:
        gvm_stream_cursor = gvm_stream_base + offset;
        return;
    }
}
#pragma push
#pragma scheduling off
#pragma peephole off
void copy_u16_bytes(s8 *dst, s8 *src) {
    s32 hi = src[0];
    dst[0] = hi;
    s32 lo = src[1];
    dst[1] = lo;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void TLobby::copy_4word_struct(void *dst, void *src) {
    s8 *d = (s8 *)dst;
    s8 *s = (s8 *)src;
    s32 t;
    t = s[0];
    d[0] = t;
    t = s[1];
    d[1] = t;
    t = s[2];
    d[2] = t;
    t = s[3];
    d[3] = t;
}
#pragma pop

#pragma push
#pragma use_lmw_stmw off
void replace_gvm_texture_directory(NJS_TEXLIST* list, s32 stride, const GvmTextureHeader* header) {
    u16 image;
    s32 off;
    u16 flags;
    s32 names;
    s32 formats;
    s32 dimensions;
    s32 alternateGlobal;
    s32 globals;
    s32 count;
    u8* record;
    NJS_TEXNAME* texture;
    s32 index;
    index = 0;
    off = 0;
    flags = header->flags;
    names = flags & 1;
    formats = flags & 2;
    dimensions = flags & 4;
    alternateGlobal = flags & 0x400;
    globals = flags & 8;
    count = header->texture_count;
    while (index < count) {
        record = (u8*)gvm_stream_read(stride);
        texture = (NJS_TEXNAME*)((u8*)list->textures + off);
        copy_u16_bytes((s8 *)&image, (s8 *)record);
        texture->attr = (texture->attr & 0xFFFF0000) | image;
        record += 2;
        if (names) {
            s32 length = strlen((char*)record);
            if (length > 0) {
                move_data(texture->filename, record, length);
            }
            record += 0x1C;
        }
        if (formats) record += 2;
        if (dimensions) record += 2;
        if (alternateGlobal) {
            if (globals) {
                TLobby::copy_4word_struct(&texture->global_index, record);
                texture->attr |= 0x01000000;
            }
        } else if (globals) {
            TLobby::copy_4word_struct(&texture->global_index, record);
            texture->attr |= 0x00800000;
        }
        off += 0xC;
        index++;
    }
}
#pragma pop

s32 calc_gvm_entry_stride(u16 flags) {
    s32 r = 2;
    if (flags & 1) r = 0x1E;
    if (flags & 2) r += 2;
    if (flags & 4) r += 2;
    if (flags & 8) r += 4;
    return r;
}

void TLobby::seek_gvrt_chunk() {
    s32 magic;
    s32 size;
    do {
        magic = *(s32 *)gvm_stream_read(4);
        TLobby::bswap32_in_place((u32 *)&magic);
        switch (magic) {
        case 0x4D4D4F43:
        case 0x564E4F43:
        case 0x4E4C444D:
        case 0x494D5650:
        case 0x4C505647:
        case 0x43474D49:
            size = *(s32 *)gvm_stream_read(4);
            TLobby::bswap32_in_place((u32 *)&size);
            gvm_stream_seek(size, 1);
            break;
        case 0x54525647:
            gvm_stream_seek(-4, 1);
            break;
        default:
            size = *(s32 *)gvm_stream_read(4);
            TLobby::bswap32_in_place((u32 *)&size);
            gvm_stream_seek(size, 1);
            break;
        }
    } while (magic != 0x54525647);
}

#pragma push
#pragma use_lmw_stmw off
s32 load_gvm_texture_archive(void *buf, NJS_TEXLIST *list) {
    s32 id;
    s32 tlut_name;
    s32 slot;
    GvrTextureChunk *chunk;
    s32 r;
    s32 i;
    s32 k;
    s32 data;
    GvmTextureHeader *header;
    s32 n;
    tlut_name = -1;
    reset_texture_error();
    if (buf == NULL) {
        lbl_8058D470.code = 1;
        return -1;
    }
    gvm_stream_begin((saddr)buf);
    header = (GvmTextureHeader *)gvm_stream_read(sizeof(GvmTextureHeader));
    TLobby::bswap32_in_place(&header->magic);
    TLobby::bswap32_in_place(&header->size);
    if (header->magic != 0x484D5647) {
        lbl_8058D470.code = 4;
        return -1;
    }
    list->nbTexture = header->texture_count;
    replace_gvm_texture_directory(list, calc_gvm_entry_stride(header->flags), header);
    gvm_stream_seek(header->size + 8, 0);
    TLobby::seek_gvrt_chunk();
    n = list->nbTexture;
    for (i = 0; i < n; i++) {
        for (k = 0; k < n; k++) {
            if (i == (list->textures[k].attr & 0xFFFF)) {
                break;
            }
        }
        r = TObjPlayer__sub_803D9E38((s32 *)list, k, &id, (u32 *)&tlut_name);
        if (r == -1) {
            lbl_8058D470.code = 7;
            return -1;
        }
        chunk = (GvrTextureChunk *)gvm_stream_read(sizeof(GvrTextureChunk));
        TLobby::bswap32_in_place(&chunk->magic);
        TLobby::bswap32_in_place(&chunk->size);
        if (chunk->magic != 0x54525647) {
            lbl_8058D470.code = 4;
            return -1;
        }
        data = gvm_stream_read(chunk->size - 8);
        if (r == 0) {
            switch (TObjPlayer__sub_803DAC48(list, k, id, tlut_name, &chunk->desc, &slot)) {
            case -1:
                lbl_8058D470.code = 6;
                return -1;
            case 0:
                if (TObjPlayer__sub_803DAB9C(slot, data) == -1) {
                    TObjPlayer__sub_803DAC1C(slot);
                    return -1;
                }
                do {
                } while (TObjPlayer::is_gvm_load_ok() != 1);
                break;
            }
        }
    }
    return 1;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
void TLobby::bswap_u32(u32 *p) {
    u32 v = *p;
    *p = ((v & 0xFF000000) >> 24) | ((v & 0xFF0000) >> 8) | ((v & 0xFF00) << 8) | ((v & 0xFF) << 24);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma peephole off
u32 TLobby::bswap32_value(u32 v) {
    return ((v & 0xFF) << 24) | ((v & 0xFF00) << 8) | ((v & 0xFF0000) >> 8) | ((v & 0xFF000000) >> 24);
}
#pragma pop

void *load_nj_chunk_model_resource(u8 *base, u32 *off, u32 *out) {
    u32 magic;
    u32 size;
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 *src;
    u8 *buf;
    u32 pos;
    u32 v;
    pos = 0;
    src = base + *off;
    move_data((void *)((&magic)), (const void *)(src), 4);
    TLobby::bswap_u32(&magic);
    move_data((void *)((&size)), (const void *)(src + 4), 4);
    TLobby::bswap_u32(&size);
    src += 8;
    *off += 8;
    magic = TLobby::bswap32_value(magic);
    switch ((s32) magic) {
    case 0x4E4A494E:
        *out = 0x4E4A494E;
        break;
    case 0x4E4A434D:
    case 0x474A434D:
        *out = 0x4E4A434D;
        break;
    case 0x474A424D:
        *out = 0x4E4A424D;
        break;
    case 0x4E4A544C:
    case 0x474A544C:
        *out = 0x4E4A544C;
        break;
    case 0x4E4A4C49:
        *out = 0x4E4A4C49;
        break;
    case 0x4E4A4341:
        *out = 0x4E4A4341;
        break;
    case 0x4E4D444D:
    case 0x474D444D:
        *out = 0x4E4D444D;
        break;
    case 0x474C494D:
        *out = 0x4E4C494D;
        break;
    case 0x4743414D:
        *out = 0x4E43414D;
        break;
    case 0x4E53534D:
    case 0x4753534D:
        *out = 0x4E53534D;
        break;
    default:
        goto unknown;
    }
    buf = (u8 *) xmalloc(size);
    if (buf == NULL) {
        return NULL;
    }
    move_data((void *)(buf), (const void *)(src), size);
    DCFlushRange(buf, size);
    src += size;
    *off += size;
    goto relocate;
unknown:
    *out = 0x2A2A2A2A;
    return NULL;
relocate:
    move_data((void *)((&magic)), (const void *)(src), 4);
    TLobby::bswap_u32(&magic);
    *off += 4;
    magic = TLobby::bswap32_value(magic);
    if (magic == 0x504F4630) {
        move_data((void *)((&size)), (const void *)(src + 4), 4);
        TLobby::bswap_u32(&size);
        src += 8;
        *off += 4;
        while (size != 0) {
            move_data((void *)((&b0)), (const void *)(src), 1);
            src++;
            (*off)++;
            size--;
            switch (b0 & 0xC0) {
            case 0x40:
                v = b0 & 0x3F;
                break;
            case 0x80:
                move_data((void *)((&b1)), (const void *)(src), 1);
                src++;
                size--;
                (*off)++;
                v = ((b0 & 0x3F) << 8) | b1;
                break;
            case 0xC0:
                move_data((void *)((&b1)), (const void *)(src), 1);
                size--;
                move_data((void *)((&b2)), (const void *)(src + 1), 1);
                size--;
                move_data((void *)((&b3)), (const void *)(src + 2), 1);
                src += 3;
                size--;
                *off += 3;
                v = ((b0 & 0x3F) << 24) | (b1 << 16) | (b2 << 8) | b3;
                break;
            case 0:
            default:
                continue;
            }
            pos += v * 4;
            if (*(u32 *)(buf + pos) != 0) {
                *(u32 *)(buf + pos) += (uaddr) buf;
            }
        }
    }
    return buf;
}

s32 gx_light_objects[0x50];
s16 *chunk_polygon_list_cache[0x7E];
u8 gvrt_header_read_buffer[0x20];
