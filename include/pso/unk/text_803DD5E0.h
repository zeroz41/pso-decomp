#ifndef PSO_UNK_TEXT_803DD5E0_H
#define PSO_UNK_TEXT_803DD5E0_H

#include "types.h"
#include "pso/render/ChunkPolygonList.h"
#include "pso/unk/text_803DA798.h"

struct GinjaTextureList;

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
s32 TObjPlayer__sub_803DD6DC(GinjaTextureList *list, s32 index);
s32 read_gvrt_file_header(GinjaTextureList *list, s32 index);
s32 TObjPlayer__sub_803DD91C(GinjaTextureList *list, s32 index);
s32 TObjPlayer__sub_803DDA68(GinjaTextureList *list, s32 index);
s32 TObjPlayer__sub_803DDB34(GinjaTextureList *list, s32 index);
s32 load_texture_list(GinjaTextureList *list);
void TLobby__sub_803DDD20(s32 buf);
saddr TLobby__sub_803DDD2C(s32 stride);
void TLobby__sub_803DDD40(s32 offset, s32 whence);
void TLobby__sub_803DDD78(s8 *dst, s8 *src);
void replace_gvm_texture_directory(GinjaTextureList *list, s32 stride, const GvmTextureHeader *header);
void *load_nj_chunk_model_resource(u8 *base, u32 *off, u32 *out);
}
s32 calc_gvm_entry_stride(u16 flags);

// read_gvrt_file_header reads the first 0x20 bytes of a GVR file here.
extern u8 gvrt_header_read_buffer[0x20];
void set_ginja_draw_flags(s32 flags);

#endif
