#ifndef PSO_RENDER_BLOBSHADOW_H
#define PSO_RENDER_BLOBSHADOW_H

#include "types.h"

/* The blob (round ground) shadow: its texture list (ha_u032_kage.gvm), quad and draw call. */
extern uaddr blob_shadow_texture_list;
extern "C" {
void draw_blob_shadow(s32 forceDraw);
}
// Name inferred from the body: frees blob_shadow_texture_list (called from shutdown_and_reset_system).
void release_blob_shadow_texture(void);
void load_ha_u032_kage(void);

// blob_shadow_rect_desc: layout known from its uses only.
struct BlobShadowRectDesc { s32 value; u8 remaining[0x14]; };
extern BlobShadowRectDesc blob_shadow_rect_desc;

#endif
