#ifndef PSO_RENDER_TEXTURESTATE_H
#define PSO_RENDER_TEXTURESTATE_H

#include "types.h"

struct GinjaTextureHeader;
struct NJS_TEXLIST;
struct GinjaTextureState;

// The image description at the start of a GVRT chunk: GX format and attribute bits, then the size.
typedef struct GvrTextureDesc {
    u32 format;
    u16 width;
    u16 height;
} GvrTextureDesc;

#ifdef __cplusplus
extern "C" {
#endif
void reset_texture_error(void);
void copy_texture_data_and_flush(void *buf, const void *src, u32 size);
s32 copy_texture_pixel_range(struct GinjaTextureHeader *header, const void *src, s32 offset, s32 length);
s32 copy_texture_pixels(struct GinjaTextureHeader *header, const void *src);
s32 reference_loaded_texture(u32 id, u32 tlut_name, s32 format, s32 *slot);
s32 create_texture_state(u32 id, u32 tlut_name, GvrTextureDesc *desc);
void set_texlist_texture(struct NJS_TEXLIST *list, s32 index, s32 slot);
s32 reload_texture_slot_pixels(s32 slot, const void *src);
void release_texture_slot(s32 slot);
s32 bind_texlist_texture(struct NJS_TEXLIST *list, s32 index, u32 id, u32 tlut_name, GvrTextureDesc *desc, s32 *slot);
void notify_texture_state_ready(struct GinjaTextureState *texture);
s32 select_texture_by_surface_id(u32 id);
s32 reload_texture_state_pixels(struct GinjaTextureState *texture, const void *src, u32 use_header);
s32 reload_list_texture_pixels(s32 index, const void *src, u32 use_header);
#ifdef __cplusplus
}
// Makes texlist the current texture list, the one set_texture_num selects from; returns 1.
s32 set_texture_list(NJS_TEXLIST *texlist);
s32 set_texture_num(s32 i);
#endif

#endif
