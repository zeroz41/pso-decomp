#ifndef PSO_NPC_TOBJNPCNFW00_H
#define PSO_NPC_TOBJNPCNFW00_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct TObjNpcNFW00 : public TObjNpcFemale {
    TObjNpcNFW00(TObject *parent, void *set_data);
    virtual ~TObjNpcNFW00();
    static void free_resources();
    static void load_assets();
    static void *create(void *set_data);
    static const char *name;
    static void **named_object_resource;
    static NJS_TEXLIST *texture_gvm_handle;
};

LAYOUT_ASSERT(TObjNpcNFW00_size, sizeof(TObjNpcNFW00) == 0x3B8);

#endif
