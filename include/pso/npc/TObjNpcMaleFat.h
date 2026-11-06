#ifndef PSO_NPC_TOBJNPCMALEFAT_H
#define PSO_NPC_TOBJNPCMALEFAT_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcMaleFat : public TUnk_804A9F50 {
    virtual ~TObjNpcMaleFat();
    static void free_static_model();
    static void load_static_resource();
};

typedef char TObjNpcMaleFat_size[sizeof(TObjNpcMaleFat) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcMaleFat__create(void *set_data);
TObjNpcMaleFat *TObjNpcMaleFat__ct(TObjNpcMaleFat *npc, TObjControl *control, void *set_data);
}

#endif
