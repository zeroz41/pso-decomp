#ifndef PSO_NPC_TOBJNPCMALEDWARF_H
#define PSO_NPC_TOBJNPCMALEDWARF_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcMaleDwarf : public TUnk_804A9F50 {
    virtual ~TObjNpcMaleDwarf();
    static void unload_static_data();
    static void load_shared_resource();
};

typedef char TObjNpcMaleDwarf_size[sizeof(TObjNpcMaleDwarf) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcMaleDwarf__create(void *set_data);
TObjNpcMaleDwarf *TObjNpcMaleDwarf__ct(TObjNpcMaleDwarf *npc, TObjControl *control, void *set_data);
}

#endif
