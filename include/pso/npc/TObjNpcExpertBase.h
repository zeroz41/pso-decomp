#ifndef PSO_NPC_TOBJNPCEXPERTBASE_H
#define PSO_NPC_TOBJNPCEXPERTBASE_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcExpertBase : public TObjNpcMale {
    TObjNpcExpertBase(TObject *parent, void *set_data);
    virtual ~TObjNpcExpertBase();
    static void free_shared_data();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_resource;
};

LAYOUT_ASSERT(TObjNpcExpertBase_size, sizeof(TObjNpcExpertBase) == 0x3B8);

#endif
