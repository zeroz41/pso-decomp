#ifndef PSO_NPC_TOBJNPCKENKYUW_H
#define PSO_NPC_TOBJNPCKENKYUW_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct BmlResource;

struct TObjNpcKenkyuW : public TUnk_804A9F50 {
    TObjNpcKenkyuW(TObject *parent, void *set_data);
    virtual ~TObjNpcKenkyuW();
    static void destroy_instance();
    static void load_resource_instance();
    static const char *class_name;
    static BmlResource *model_resource;
};

LAYOUT_ASSERT(TObjNpcKenkyuW_size, sizeof(TObjNpcKenkyuW) == 0x3B8);

#endif
