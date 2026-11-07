#ifndef PSO_NPC_TOBJNPCFEMALEOLD_H
#define PSO_NPC_TOBJNPCFEMALEOLD_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleOld : public TUnk_804A8640 {
    virtual ~TObjNpcFemaleOld();
    static void destroy_static_instance();
    static void load_resource_instance();
};

typedef char TObjNpcFemaleOld_size[sizeof(TObjNpcFemaleOld) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcFemaleOld__create(void *set_data);
TObjNpcFemaleOld *TObjNpcFemaleOld__ct(TObjNpcFemaleOld *npc, TObjControl *control, void *set_data);
}

#endif
