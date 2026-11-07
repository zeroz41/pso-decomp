#ifndef PSO_NPC_TOBJNPCSOLDIERBASE_H
#define PSO_NPC_TOBJNPCSOLDIERBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcSoldierBase : public TUnk_804A9F50 {
    virtual ~TObjNpcSoldierBase();
    static void release_static_instance();
    static void load_shared_resource();
};

typedef char TObjNpcSoldierBase_size[sizeof(TObjNpcSoldierBase) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcSoldierBase__create(void *set_data);
TObjNpcSoldierBase *TObjNpcSoldierBase__ct(TObjNpcSoldierBase *npc, TObjControl *control, void *set_data);
}

#endif
