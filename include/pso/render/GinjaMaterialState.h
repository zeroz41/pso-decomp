#ifndef PSO_RENDER_GINJAMATERIALSTATE_H
#define PSO_RENDER_GINJAMATERIALSTATE_H
#ifndef TYPES_H
#include "types.h"
#endif
typedef struct GinjaMaterialCache {
  u8 prefix[8];
  u32 parameters[11];
  u32 dirty[11];
  u8 reserved60[12];
  u32 inherited_flags;
  u8 reserved70[12];
  u32 blend_valid;
  u32 blend;
  u32 textured;
  u32 texture;
} GinjaMaterialCache;
typedef struct GinjaParameter {
  u8 kind;
  u8 reserved[3];
  u32 value;
} GinjaParameter;
typedef struct GinjaSurfaceState {
  u32 id;
  u32 format;
  u8 reserved8[0x14];
  u32 flags;
  u32 *pixels; /* +0x20: texel buffer the menu font clears and draws glyphs into (name inferred) */
  s32 ref_count; /* +0x24: textures sharing this surface; freed at 0 (name inferred) */
} GinjaSurfaceState;
typedef struct GinjaTextureState {
  u8 reserved0[12];
  GinjaSurfaceState *surface;
  s32 ref_count; /* +0x10: decremented on release, entry cleared at 0 (name inferred) */
  u32 reserved14;
} GinjaTextureState;
typedef struct GinjaTextureEntry {
  char *name;
  u32 value04;
  GinjaTextureState *texture;
} GinjaTextureEntry;
typedef struct GinjaTextureList {
  GinjaTextureEntry *entries;
  u32 count;
} GinjaTextureList;
typedef struct GinjaSceneState {
  u8 reserved0[0x20];
  GinjaTextureList *textures;
} GinjaSceneState;
typedef char
    GinjaMaterialCacheSize[(sizeof(GinjaMaterialCache) == 0x8c) ? 1 : -1];
#endif
