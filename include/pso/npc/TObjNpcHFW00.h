#ifndef PSO_NPC_TOBJNPCHFW00_H
#define PSO_NPC_TOBJNPCHFW00_H

#include "types.h"
#include "pso/npc/TObjNpcFomarl.h"

struct TObjNpcHFW00 : public TObjNpcFomarl {
    TObjNpcHFW00(TObject *parent, void *set_data);
    virtual ~TObjNpcHFW00();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **shared_resource_obj;
    static NJS_TEXLIST *texture_handle;
};

LAYOUT_ASSERT(TObjNpcHFW00_size, sizeof(TObjNpcHFW00) == 0x3B8);

#endif
