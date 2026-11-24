#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaModel.h"
#include "pso/render/GinjaMaterialState.h"
#include "types.h"

void set_material_texture_slot(GinjaDrawRecord *draw, u32 slot) {
    GinjaParameter *p;
    u32 i;
    if (draw != NULL) {
        p = static_cast<GinjaParameter *>(draw->parameters);
        for (i = 0; i < draw->parameter_count; i++, p++) {
            if (p->kind == 8) {
                p->value = p->value & 0xFFFFE000;
                p->value = p->value | (slot & 0x1FFF);
            }
        }
    }
}
