#include "types.h"
#include "pso/object/door/TObjDoorJung.h"

struct Ent_8023DBEC { const char *name; u32 a; u32 b; };

struct List_8023DBEC { Ent_8023DBEC *ents; u32 count; };

extern "C" {
s32 strcmp(const char *, const char *);
void set_material_texture_slot(void *);

s32 TObjDoorJung::find_entry_by_name(const char *name) {
    Ent_8023DBEC *ents;
    u32 i;
    if (this != NULL) {
        ents = ((List_8023DBEC *)this)->ents;
        if (ents != NULL) {
            for (i = 0; i < ((List_8023DBEC *)this)->count; i++) {
                if (strcmp(name, ents[i].name) == 0) {
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
