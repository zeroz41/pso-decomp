#ifndef PSO_NPC_TOBJNPCFEMALETALL_H
#define PSO_NPC_TOBJNPCFEMALETALL_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleTall : public TUnk_804A8640 {
    TObjNpcFemaleTall(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleTall();
    static void destroy_instance();
    static void load_resource_instance();
};

typedef char TObjNpcFemaleTall_size[sizeof(TObjNpcFemaleTall) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcFemaleTall__create(void *set_data);
}

#endif
