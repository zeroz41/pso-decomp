#ifndef PSO_NPC_TOBJNPCMALEBASE_H
#define PSO_NPC_TOBJNPCMALEBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcMaleBase : public TUnk_804A9F50 {
    virtual ~TObjNpcMaleBase();
    static void free_static_data();
    static void load_shared_resource();
};

typedef char TObjNpcMaleBase_size[sizeof(TObjNpcMaleBase) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcMaleBase__create(void *set_data);
TObjNpcMaleBase *TObjNpcMaleBase__ct(TObjNpcMaleBase *npc, TObjControl *control, void *set_data);
}

#endif
