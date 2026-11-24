#ifndef PSO_NPC_TOBJNPCFEMALEOLD_H
#define PSO_NPC_TOBJNPCFEMALEOLD_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcFemaleOld : public TObjNpcFemale {
    TObjNpcFemaleOld(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleOld();
    static void destroy_static_instance();
    static void load_resource_instance();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_instance;
};

LAYOUT_ASSERT(TObjNpcFemaleOld_size, sizeof(TObjNpcFemaleOld) == 0x3B8);

#endif
