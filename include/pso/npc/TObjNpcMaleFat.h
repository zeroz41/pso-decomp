#ifndef PSO_NPC_TOBJNPCMALEFAT_H
#define PSO_NPC_TOBJNPCMALEFAT_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcMaleFat : public TObjNpcMale {
    TObjNpcMaleFat(TObject *parent, void *set_data);
    virtual ~TObjNpcMaleFat();
    static void free_static_model();
    static void load_static_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_model_resource;
};

LAYOUT_ASSERT(TObjNpcMaleFat_size, sizeof(TObjNpcMaleFat) == 0x3B8);

#endif
