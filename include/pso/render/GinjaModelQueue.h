#ifndef PSO_RENDER_GINJAMODELQUEUE_H
#define PSO_RENDER_GINJAMODELQUEUE_H

#include "types.h"

struct GinjaTextureHeader;

extern "C" {
// Texture transfers are synchronous on GameCube: nothing is ever started or left pending.
s32 start_texture_header_transfer(struct GinjaTextureHeader *header);
s32 texture_transfer_pending(void);
}
void draw_queued_models(u32 count);
void flush_model_draw_queue(void);

#endif
