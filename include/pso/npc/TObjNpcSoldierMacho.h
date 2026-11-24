#ifndef PSO_NPC_TOBJNPCSOLDIERMACHO_H
#define PSO_NPC_TOBJNPCSOLDIERMACHO_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;
struct BmlResourceDescriptor;

struct TObjNpcSoldierMacho : public TObjNpcMale {
    TObjNpcSoldierMacho(TObject *parent, void *set_data);
    virtual ~TObjNpcSoldierMacho();
    static void unload_static_data();
    static void load_shared_resource();
    static void *create(void *set_data);
    static BmlResourceDescriptor body_resource_desc;
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcSoldierMacho_size, sizeof(TObjNpcSoldierMacho) == 0x3B8);

#endif
