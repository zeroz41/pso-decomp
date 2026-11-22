#include "pso/render/GinjaMaterialTextureSlot.h"
#include "pso/render/GinjaModel.h"
#include "types.h"
#include <string.h>
#include "pso/render/GinjaTexture.h"


s32 find_texture_entry_by_name(const GinjaTextureList *list, const char *name) {
    const GinjaTextureEntry *ents;
    u32 i;
    if (list != NULL) {
        ents = list->entries;
        if (ents != NULL) {
            for (i = 0; i < list->count; i++) {
                if (strcmp(name, ents[i].name) == 0) {
                    return i;
                }
            }
        }
    }
    return -1;
}

void set_ginja_model_texture_slot(void *model, u32 slot) {
    GinjaModel *mesh = static_cast<GinjaModel *>(model);
    if (mesh->primary != NULL) {
        set_material_texture_slot(mesh->primary, slot);
    }
    if (mesh->secondary != NULL) {
        set_material_texture_slot(mesh->secondary, slot);
    }
}

