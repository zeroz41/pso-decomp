#ifndef PSO_RENDER_GINJAMATERIALTEXTURESLOT_H
#define PSO_RENDER_GINJAMATERIALTEXTURESLOT_H

#include "types.h"

struct GinjaDrawRecord;

extern "C" {
// Selects the texture slot in both material passes of a Ginja model.
void set_ginja_model_texture_slot(void *model, u32 slot);
void set_material_texture_slot(GinjaDrawRecord *draw, u32 slot);
}

#endif
