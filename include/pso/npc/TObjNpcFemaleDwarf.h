#ifndef PSO_NPC_TOBJNPCFEMALEDWARF_H
#define PSO_NPC_TOBJNPCFEMALEDWARF_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleDwarf : public TUnk_804A8640 {
    TObjNpcFemaleDwarf(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleDwarf();
    static void unload_static_data();
    static void load_static_resource();
};

LAYOUT_ASSERT(TObjNpcFemaleDwarf_size, sizeof(TObjNpcFemaleDwarf) == 0x3B8);

extern "C" {
void *TObjNpcFemaleDwarf__create(void *set_data);
}

#endif
