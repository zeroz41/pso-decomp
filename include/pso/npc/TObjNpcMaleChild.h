#ifndef PSO_NPC_TOBJNPCMALECHILD_H
#define PSO_NPC_TOBJNPCMALECHILD_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcMaleChild : public TUnk_804A9F50 {
    virtual ~TObjNpcMaleChild();
    static void release_static_instance();
    static void load_shared_resource();
};

typedef char TObjNpcMaleChild_size[sizeof(TObjNpcMaleChild) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcMaleChild__create(void *set_data);
TObjNpcMaleChild *TObjNpcMaleChild__ct(TObjNpcMaleChild *npc, TObjControl *control, void *set_data);
}

#endif
