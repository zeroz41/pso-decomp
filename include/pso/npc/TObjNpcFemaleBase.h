#ifndef PSO_NPC_TOBJNPCFEMALEBASE_H
#define PSO_NPC_TOBJNPCFEMALEBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleBase : public TUnk_804A8640 {
    virtual ~TObjNpcFemaleBase();
    static void free_static_data();
    static void load_shared_resource();
};

typedef char TObjNpcFemaleBase_size[sizeof(TObjNpcFemaleBase) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcFemaleBase__create(void *set_data);
TObjNpcFemaleBase *TObjNpcFemaleBase__ct(TObjNpcFemaleBase *npc, TObjControl *control, void *set_data);
}

#endif
