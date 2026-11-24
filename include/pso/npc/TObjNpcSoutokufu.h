#ifndef PSO_NPC_TOBJNPCSOUTOKUFU_H
#define PSO_NPC_TOBJNPCSOUTOKUFU_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcSoutokufu : public TObjNpcMale {
    TObjNpcSoutokufu(TObject *parent, void *set_data);
    virtual ~TObjNpcSoutokufu();
    static void close_dialog_window();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcSoutokufu_size, sizeof(TObjNpcSoutokufu) == 0x3B8);

#endif
