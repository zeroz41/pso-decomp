#ifndef PSO_NPC_TOBJNPCFEMALEBASE_H
#define PSO_NPC_TOBJNPCFEMALEBASE_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcFemaleBase : public TObjNpcFemale {
    TObjNpcFemaleBase(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleBase();
    static void free_static_data();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_resource_obj;
};

LAYOUT_ASSERT(TObjNpcFemaleBase_size, sizeof(TObjNpcFemaleBase) == 0x3B8);

#endif
