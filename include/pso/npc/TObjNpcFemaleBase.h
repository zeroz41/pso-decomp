#ifndef PSO_NPC_TOBJNPCFEMALEBASE_H
#define PSO_NPC_TOBJNPCFEMALEBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcFemaleBase : public TUnk_804A8640 {
    virtual ~TObjNpcFemaleBase();
    static void free_static_data();
    static void load_shared_resource();
};

typedef char TObjNpcFemaleBase_size[sizeof(TObjNpcFemaleBase) == 0x3B8 ? 1 : -1];
#endif
