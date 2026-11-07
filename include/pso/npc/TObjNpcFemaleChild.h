#ifndef PSO_NPC_TOBJNPCFEMALECHILD_H
#define PSO_NPC_TOBJNPCFEMALECHILD_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleChild : public TUnk_804A8640 {
    virtual ~TObjNpcFemaleChild();
    static void release_static_instance();
    static void load_shared_resource();
};

typedef char TObjNpcFemaleChild_size[sizeof(TObjNpcFemaleChild) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcFemaleChild__create(void *set_data);
TObjNpcFemaleChild *TObjNpcFemaleChild__ct(TObjNpcFemaleChild *npc, TObjControl *control, void *set_data);
}

#endif
