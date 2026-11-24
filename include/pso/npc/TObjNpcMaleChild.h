#ifndef PSO_NPC_TOBJNPCMALECHILD_H
#define PSO_NPC_TOBJNPCMALECHILD_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcMaleChild : public TObjNpcMale {
    TObjNpcMaleChild(TObject *parent, void *set_data);
    virtual ~TObjNpcMaleChild();
    static void release_static_instance();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcMaleChild_size, sizeof(TObjNpcMaleChild) == 0x3B8);

#endif
