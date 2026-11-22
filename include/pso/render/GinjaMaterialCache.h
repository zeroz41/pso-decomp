#ifndef PSO_RENDER_GINJAMATERIALCACHE_H
#define PSO_RENDER_GINJAMATERIALCACHE_H

#include "types.h"
#include <dolphin/gx/GXStruct.h>

// The material parameters the Ginja draw last sent to GX, so that each draw
// record only reloads what changed (update_ginja_cached_parameter).
typedef struct GinjaMaterialCache {
  u32 prefix[2];
  u32 parameters[11];
  u32 dirty[11];
  GXColor material_color; /* +0x60: parameter 5 */
  GXColor global_color; /* +0x64: parameter 6, set_global_color_rgba */
  GXColor global_color_alt_b; /* +0x68: parameter 7, set_global_color_rgba_alt_b */
  u32 inherited_flags;
  // Channels, texture coordinate generators and TEV stages: the material's
  // own counts, the slots the pre callbacks keep in front of them, the slots
  // the post callbacks add after them, and the total sent to GX.
  u8 material_channel_count;
  u8 material_texgen_count;
  u8 material_tev_stage_count;
  u8 channel_offset;
  u8 texgen_offset; /* +0x74: added to the selected texture coordinate */
  u8 tev_stage_offset; /* +0x75: added to the selected TEV stage */
  u8 post_channel_count;
  u8 post_texgen_count; /* +0x77: set_ginja_post_texgen_count */
  u8 post_tev_stage_count; /* +0x78: set_ginja_post_tev_stage_count */
  u8 channel_total;
  u8 texgen_total;
  u8 tev_stage_total;
  u32 blend_valid; /* +0x7C: bit 0 blend, bit 1 texture, bit 2 texture coordinates set */
  u32 blend;
  u32 textured; /* +0x84: the material's texture coordinate count */
  u32 texture;
} GinjaMaterialCache;
LAYOUT_ASSERT(GinjaMaterialCacheSize, sizeof(GinjaMaterialCache) == 0x8c);

#endif
