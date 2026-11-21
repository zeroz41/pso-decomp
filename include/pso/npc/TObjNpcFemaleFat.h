#ifndef PSO_NPC_TOBJNPCFEMALEFAT_H
#define PSO_NPC_TOBJNPCFEMALEFAT_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleFat : public TUnk_804A8640 {
    TObjNpcFemaleFat(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleFat();
    static void free_static_model();
    static void load_static_resource();
};

LAYOUT_ASSERT(TObjNpcFemaleFat_size, sizeof(TObjNpcFemaleFat) == 0x3B8);

extern "C" {
void *TObjNpcFemaleFat__create(void *set_data);
}

#endif
