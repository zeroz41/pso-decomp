#ifndef PSO_NPC_TOBJNPCKENKYU2_H
#define PSO_NPC_TOBJNPCKENKYU2_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;
struct BmlResourceDescriptor;

struct TObjNpcKenkyu2 : public TObjNpcMale {
    TObjNpcKenkyu2(TObject *parent, void *set_data);
    virtual ~TObjNpcKenkyu2();
    static void free_static_model();
    static void load_shared_resource();
    static void *create(void *set_data);
    static BmlResourceDescriptor resource_descriptor;
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcKenkyu2_size, sizeof(TObjNpcKenkyu2) == 0x3B8);

#endif
