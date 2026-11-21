#ifndef PSO_NPC_TOBJNPCFEMALEBASE_H
#define PSO_NPC_TOBJNPCFEMALEBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleBase : public TUnk_804A8640 {
    TObjNpcFemaleBase(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleBase();
    static void free_static_data();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcFemaleBase_size, sizeof(TObjNpcFemaleBase) == 0x3B8);

extern "C" {
void *TObjNpcFemaleBase__create(void *set_data);
}

#endif
