#ifndef PSO_RENDER_BLOBSHADOW_H
#define PSO_RENDER_BLOBSHADOW_H

#include "types.h"

/* The blob (round ground) shadow: its texture list (ha_u032_kage.gvm), quad and draw call. */
extern "C" {
extern u32 blob_shadow_texture_list;
void draw_blob_shadow(s32 arg0);
// Name inferred from the body: frees blob_shadow_texture_list (called from shutdown_and_reset_system).
void release_blob_shadow_texture(void);
}
void load_ha_u032_kage(void);

#endif
