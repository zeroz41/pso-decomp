#ifndef PSO_NPC_TOBJNPCNFM00_H
#define PSO_NPC_TOBJNPCNFM00_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcNFM00 : public TObjNpcMale {
    TObjNpcNFM00(TObject *parent, void *set_data);
    virtual ~TObjNpcNFM00();
    static void free_resources();
    static void load_assets();
    static void *create(void *set_data);
    static const char *name;
    static void **shared_named_model_object;
    static NJS_TEXLIST *texture_gvm_handle;
};

LAYOUT_ASSERT(TObjNpcNFM00_size, sizeof(TObjNpcNFM00) == 0x3B8);

#endif
