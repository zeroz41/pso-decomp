#ifndef PSO_NPC_TOBJNPCNURSEBASE_H
#define PSO_NPC_TOBJNPCNURSEBASE_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcNurseBase : public TObjNpcFemale {
    TObjNpcNurseBase(TObject *parent, void *set_data);
    virtual ~TObjNpcNurseBase();
    static void free_shared_data();
    static void load_shared_data();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcNurseBase_size, sizeof(TObjNpcNurseBase) == 0x3B8);

#endif
