#ifndef PSO_NPC_TOBJNPCMALEMACHO_H
#define PSO_NPC_TOBJNPCMALEMACHO_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcMaleMacho : public TObjNpcMale {
    TObjNpcMaleMacho(TObject *parent, void *set_data);
    virtual ~TObjNpcMaleMacho();
    static void close_dialog_window();
    static void load_static_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_model_resource;
};

LAYOUT_ASSERT(TObjNpcMaleMacho_size, sizeof(TObjNpcMaleMacho) == 0x3B8);

#endif
