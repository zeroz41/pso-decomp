#ifndef PSO_NPC_TOBJNPCMALEOLD_H
#define PSO_NPC_TOBJNPCMALEOLD_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcMaleOld : public TUnk_804A9F50 {
    virtual ~TObjNpcMaleOld();
    static void destroy_static_instance();
    static void load_resource_instance();
};

typedef char TObjNpcMaleOld_size[sizeof(TObjNpcMaleOld) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcMaleOld__create(void *set_data);
TObjNpcMaleOld *TObjNpcMaleOld__ct(TObjNpcMaleOld *npc, TObjControl *control, void *set_data);
}

#endif
