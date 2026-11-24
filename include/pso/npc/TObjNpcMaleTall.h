#ifndef PSO_NPC_TOBJNPCMALETALL_H
#define PSO_NPC_TOBJNPCMALETALL_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcMaleTall : public TObjNpcMale {
    TObjNpcMaleTall(TObject *parent, void *set_data);
    virtual ~TObjNpcMaleTall();
    static void destroy_instance();
    static void load_resource_instance();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcMaleTall_size, sizeof(TObjNpcMaleTall) == 0x3B8);

#endif
