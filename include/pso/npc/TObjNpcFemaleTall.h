#ifndef PSO_NPC_TOBJNPCFEMALETALL_H
#define PSO_NPC_TOBJNPCFEMALETALL_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcFemaleTall : public TObjNpcFemale {
    TObjNpcFemaleTall(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleTall();
    static void destroy_instance();
    static void load_resource_instance();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *instance;
};

LAYOUT_ASSERT(TObjNpcFemaleTall_size, sizeof(TObjNpcFemaleTall) == 0x3B8);

#endif
