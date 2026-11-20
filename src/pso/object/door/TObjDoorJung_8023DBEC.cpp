#include "types.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/render/GinjaTexture.h"

extern "C" {
s32 strcmp(const char *, const char *);
void set_material_texture_slot(void *);

s32 find_texture_entry_by_name(GinjaTextureList *texlist, const char *name) {
    GinjaTextureEntry *entries;
    u32 i;
    if (texlist != NULL) {
        entries = texlist->entries;
        if (entries != NULL) {
            for (i = 0; i < texlist->count; i++) {
                if (strcmp(name, entries[i].name) == 0) {
                    return i;
                }
            }
        }
    }
    return -1;
}

void TObjDoorJung::free_children(void *arg1) {
    if (this->m_prev != NULL) {
        set_material_texture_slot(this->m_prev);
    }
    if (this->m_next != NULL) {
        ((void (*)(void *, void *))set_material_texture_slot)(this->m_next, arg1);
    }
}

}
