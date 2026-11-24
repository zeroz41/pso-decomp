#ifndef PSO_NPC_TOBJNPCMALEDWARF_H
#define PSO_NPC_TOBJNPCMALEDWARF_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcMaleDwarf : public TObjNpcMale {
    TObjNpcMaleDwarf(TObject *parent, void *set_data);
    virtual ~TObjNpcMaleDwarf();
    static void unload_static_data();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcMaleDwarf_size, sizeof(TObjNpcMaleDwarf) == 0x3B8);

#endif
