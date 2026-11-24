#ifndef PSO_NPC_TOBJNPCSOLDIERBASE_H
#define PSO_NPC_TOBJNPCSOLDIERBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct BmlResource;
struct BmlResourceDescriptor;

struct TObjNpcSoldierBase : public TUnk_804A9F50 {
    TObjNpcSoldierBase(TObject *parent, void *set_data);
    virtual ~TObjNpcSoldierBase();
    static void release_static_instance();
    static void load_shared_resource();
    static void *create(void *set_data);
    static BmlResourceDescriptor body_resource_desc;
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcSoldierBase_size, sizeof(TObjNpcSoldierBase) == 0x3B8);

#endif
