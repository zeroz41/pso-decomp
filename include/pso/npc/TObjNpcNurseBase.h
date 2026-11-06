#ifndef PSO_NPC_TOBJNPCNURSEBASE_H
#define PSO_NPC_TOBJNPCNURSEBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcNurseBase : public TUnk_804A8640 {
    virtual ~TObjNpcNurseBase();
    static void free_shared_data();
    static void load_shared_data();
};

typedef char TObjNpcNurseBase_size[sizeof(TObjNpcNurseBase) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcNurseBase__create(void *set_data);
TObjNpcNurseBase *TObjNpcNurseBase__ct(TObjNpcNurseBase *npc, TObjControl *control, void *set_data);
}

#endif
