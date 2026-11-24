#ifndef PSO_NPC_TOBJNPCKENKYU_H
#define PSO_NPC_TOBJNPCKENKYU_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct BmlResource;

struct TObjNpcKenkyu : public TUnk_804A9F50 {
    TObjNpcKenkyu(TObject *parent, void *set_data);
    virtual ~TObjNpcKenkyu();
    static void free_static_model();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_model;
};

LAYOUT_ASSERT(TObjNpcKenkyu_size, sizeof(TObjNpcKenkyu) == 0x3B8);

#endif
