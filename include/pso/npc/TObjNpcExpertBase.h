#ifndef PSO_NPC_TOBJNPCEXPERTBASE_H
#define PSO_NPC_TOBJNPCEXPERTBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct BmlResource;

struct TObjNpcExpertBase : public TUnk_804A9F50 {
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
