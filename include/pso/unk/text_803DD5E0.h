#ifndef PSO_UNK_TEXT_803DD5E0_H
#define PSO_UNK_TEXT_803DD5E0_H

#include "types.h"
#include "pso/render/ChunkPolygonList.h"
#include "pso/unk/text_803DA798.h"

struct NJS_TEXLIST;

// The GVMH chunk at the start of a GVM texture archive; the texture directory follows it.
struct GvmTextureHeader {
    u32 magic;
    u32 size;
    u16 flags;
    s16 texture_count;
};

// A GVRT chunk header inside a GVM archive or a GVR file; the image data follows it.
struct GvrTextureChunk {
    u32 magic;
    u32 size;
    GvrTextureDesc desc;
};

extern "C" {
s32 load_texture_entry(NJS_TEXLIST *list, s32 index);
s32 read_gvrt_file_header(NJS_TEXLIST *list, s32 index);
s32 load_texture_from_memory(NJS_TEXLIST *list, s32 index);
s32 create_texture_from_input(NJS_TEXLIST *list, s32 index);
s32 reference_texture_by_global_index(NJS_TEXLIST *list, s32 index);
s32 load_texture_list(NJS_TEXLIST *list);
void gvm_stream_begin(s32 buf);
saddr gvm_stream_read(s32 stride);
void gvm_stream_seek(s32 offset, s32 whence);
void copy_u16_bytes(s8 *dst, s8 *src);
void replace_gvm_texture_directory(NJS_TEXLIST *list, s32 stride, const GvmTextureHeader *header);
void *load_nj_chunk_model_resource(u8 *base, u32 *off, u32 *out);
}
s32 calc_gvm_entry_stride(u16 flags);

// The five GX light objects (0x40 bytes each), one per light slot: 0 is the scene light, 2..4 the point lights.
extern s32 gx_light_objects[0x50];

// read_gvrt_file_header reads the first 0x20 bytes of a GVR file here.
extern u8 gvrt_header_read_buffer[0x20];
void set_ginja_draw_flags(s32 flags);

#endif
