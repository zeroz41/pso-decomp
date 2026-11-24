#ifndef PSO_NPC_TOBJNPCHOSA2_H
#define PSO_NPC_TOBJNPCHOSA2_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;

struct TObjNpcHosa2 : public TObjNpcMale {
    TObjNpcHosa2(TObject *parent, void *set_data);
    virtual ~TObjNpcHosa2();
    static void close_dialog_window();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_model_resource;
};

LAYOUT_ASSERT(TObjNpcHosa2_size, sizeof(TObjNpcHosa2) == 0x3B8);

#endif
