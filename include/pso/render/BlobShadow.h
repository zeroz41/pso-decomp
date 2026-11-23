#ifndef PSO_RENDER_BLOBSHADOW_H
#define PSO_RENDER_BLOBSHADOW_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

/* The blob (round ground) shadow: its texture list (ha_u032_kage.gvm), quad and draw call. */
extern NJS_TEXLIST *blob_shadow_texture_list;
extern "C" {
void draw_blob_shadow(s32 forceDraw);
}
// Name inferred from the body: frees blob_shadow_texture_list (called from shutdown_and_reset_system).
void release_blob_shadow_texture(void);
void load_ha_u032_kage(void);

// The shadow's sprite cell: 5x5, uv 5..253 of texture 0.
extern NJS_TEXANIM blob_shadow_rect_desc;

#endif
