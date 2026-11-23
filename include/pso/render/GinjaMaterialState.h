#ifndef PSO_RENDER_GINJAMATERIALSTATE_H
#define PSO_RENDER_GINJAMATERIALSTATE_H
#ifndef TYPES_H
#include "types.h"
#endif
typedef struct GinjaParameter {
  u8 kind;
  u8 reserved[3];
  u32 value;
} GinjaParameter;
// A texture's GX image: init_ginja_texture_header fills it from the format word of the texture's source.
typedef struct GinjaTextureHeader {
  u32 format;
  u8 reserved04[8];
  u32 width;
  u32 height;
  u32 size; /* GXGetTexBufferSize of the image */
  u32 flags; /* 0x80000000 mipmapped, 0x8000 colour-indexed */
  u32 *pixels; /* texel buffer, allocated from the locked cache heap */
} GinjaTextureHeader;
typedef struct GinjaSurfaceState {
  u32 id;
  GinjaTextureHeader header;
  s32 ref_count; /* textures sharing this surface; freed at 0 */
} GinjaSurfaceState;
typedef struct GinjaTextureState {
  u8 reserved0[8];
  u32 tlut_name; /* palette bank for GXInitTexObjCI */
  GinjaSurfaceState *surface;
  s32 ref_count; /* decremented on release, entry cleared at 0 */
  u32 reserved14;
} GinjaTextureState;
typedef struct GinjaTextureEntry {
  char *name;
  u32 value04;
  union {
    GinjaTextureState *texture;
    u32 global_index;
  };
} GinjaTextureEntry;
typedef struct GinjaTextureList {
  GinjaTextureEntry *entries;
  u32 count;
} GinjaTextureList;
// A render context: render_contexts holds six, select_render_context makes one current.
typedef struct GinjaSceneState {
  u8 reserved0[8];
  GinjaTextureHeader *texture_header; /* image of the texture set_texture_num selected */
  u32 blend_mode; /* +0x0C: GX blend factors, source in bits 29-31, destination in bits 26-28 */
  u32 reserved10;
  s32 cached_texture; /* -1 when none; freeing a texture surface resets it */
  u32 tlut_name; /* palette bank of the selected texture */
  u32 reserved1C;
  GinjaTextureList *textures;
  u32 reserved24;
} GinjaSceneState;
#endif
