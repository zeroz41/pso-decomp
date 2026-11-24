#ifndef PSO_NPC_TOBJNPCFEMALETALL_H
#define PSO_NPC_TOBJNPCFEMALETALL_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct BmlResource;

struct TObjNpcFemaleTall : public TUnk_804A8640 {
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
