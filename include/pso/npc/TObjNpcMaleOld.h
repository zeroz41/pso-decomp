#ifndef PSO_NPC_TOBJNPCMALEOLD_H
#define PSO_NPC_TOBJNPCMALEOLD_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcMaleOld : public TObjNpcMale {
    TObjNpcMaleOld(TObject *parent, void *set_data);
    virtual ~TObjNpcMaleOld();
    static void destroy_static_instance();
    static void load_resource_instance();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcMaleOld_size, sizeof(TObjNpcMaleOld) == 0x3B8);

#endif
