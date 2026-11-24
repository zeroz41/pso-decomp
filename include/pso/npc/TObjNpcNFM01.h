#ifndef PSO_NPC_TOBJNPCNFM01_H
#define PSO_NPC_TOBJNPCNFM01_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcNFM01 : public TObjNpcMale {
    TObjNpcNFM01(TObject *parent, void *set_data);
    virtual ~TObjNpcNFM01();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **model_object;
    static NJS_TEXLIST *texture_handle;
};

LAYOUT_ASSERT(TObjNpcNFM01_size, sizeof(TObjNpcNFM01) == 0x3B8);

#endif
