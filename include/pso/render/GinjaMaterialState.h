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
  u8 reserved0[0xC];
  u32 blend_mode; /* +0x0C: GX blend factors, source in bits 29-31, destination in bits 26-28 (name inferred) */
  u8 reserved10[0x10];
  GinjaTextureList *textures;
  u32 reserved24;
} GinjaSceneState;
#endif
