#ifndef PSO_NPC_TOBJNPCGOVERNORBASE_H
#define PSO_NPC_TOBJNPCGOVERNORBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct BmlResource;

struct TObjNpcGovernorBase : public TUnk_804A9F50 {
    TObjNpcGovernorBase(TObject *parent, void *set_data);
    virtual ~TObjNpcGovernorBase();
    static void free_shared_data();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_resource;
};

LAYOUT_ASSERT(TObjNpcGovernorBase_size, sizeof(TObjNpcGovernorBase) == 0x3B8);

#endif
