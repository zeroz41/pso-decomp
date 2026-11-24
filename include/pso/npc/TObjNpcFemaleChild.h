#ifndef PSO_NPC_TOBJNPCFEMALECHILD_H
#define PSO_NPC_TOBJNPCFEMALECHILD_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcFemaleChild : public TObjNpcFemale {
    TObjNpcFemaleChild(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleChild();
    static void release_static_instance();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_instance;
};

LAYOUT_ASSERT(TObjNpcFemaleChild_size, sizeof(TObjNpcFemaleChild) == 0x3B8);

#endif
