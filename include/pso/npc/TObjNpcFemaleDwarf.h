#ifndef PSO_NPC_TOBJNPCFEMALEDWARF_H
#define PSO_NPC_TOBJNPCFEMALEDWARF_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleDwarf : public TUnk_804A8640 {
    virtual ~TObjNpcFemaleDwarf();
    static void unload_static_data();
    static void load_static_resource();
};

typedef char TObjNpcFemaleDwarf_size[sizeof(TObjNpcFemaleDwarf) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcFemaleDwarf__create(void *set_data);
TObjNpcFemaleDwarf *TObjNpcFemaleDwarf__ct(TObjNpcFemaleDwarf *npc, TObjControl *control, void *set_data);
}

#endif
