#ifndef PSO_NPC_TOBJNPCSECRETARYBASE_H
#define PSO_NPC_TOBJNPCSECRETARYBASE_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcSecretaryBase : public TObjNpcFemale {
    TObjNpcSecretaryBase(TObject *parent, void *set_data);
    virtual ~TObjNpcSecretaryBase();
    static void free_static_data();
    static void load_static_data();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_model_resource;
};

LAYOUT_ASSERT(TObjNpcSecretaryBase_size, sizeof(TObjNpcSecretaryBase) == 0x3B8);

#endif
