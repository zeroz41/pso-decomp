#ifndef PSO_NPC_TOBJNPCNHW00_H
#define PSO_NPC_TOBJNPCNHW00_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct TObjNpcNHW00 : public TObjNpcFemale {
    TObjNpcNHW00(TObject *parent, void *set_data);
    virtual ~TObjNpcNHW00();
    static void free_static_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **shared_named_model_object;
    static NJS_TEXLIST *texture_gvm_handle;
};

LAYOUT_ASSERT(TObjNpcNHW00_size, sizeof(TObjNpcNHW00) == 0x3B8);

#endif
