#ifndef PSO_NPC_TOBJNPCMALETALL_H
#define PSO_NPC_TOBJNPCMALETALL_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcMaleTall : public TUnk_804A9F50 {
    virtual ~TObjNpcMaleTall();
    static void destroy_instance();
    static void load_resource_instance();
};

typedef char TObjNpcMaleTall_size[sizeof(TObjNpcMaleTall) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcMaleTall__create(void *set_data);
TObjNpcMaleTall *TObjNpcMaleTall__ct(TObjNpcMaleTall *npc, TObjControl *control, void *set_data);
}

#endif
