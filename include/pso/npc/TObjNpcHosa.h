#ifndef PSO_NPC_TOBJNPCHOSA_H
#define PSO_NPC_TOBJNPCHOSA_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcHosa : public TObjNpcMale {
    TObjNpcHosa(TObject *parent, void *set_data);
    virtual ~TObjNpcHosa();
    static void destroy_static_instance();
    static void load_static_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_model_resource;
};

LAYOUT_ASSERT(TObjNpcHosa_size, sizeof(TObjNpcHosa) == 0x3B8);

#endif
