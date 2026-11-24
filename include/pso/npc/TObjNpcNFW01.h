#ifndef PSO_NPC_TOBJNPCNFW01_H
#define PSO_NPC_TOBJNPCNFW01_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct TObjNpcNFW01 : public TObjNpcFemale {
    TObjNpcNFW01(TObject *parent, void *set_data);
    virtual ~TObjNpcNFW01();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **shared_object_resource;
    static NJS_TEXLIST *texture_gvm;
};

LAYOUT_ASSERT(TObjNpcNFW01_size, sizeof(TObjNpcNFW01) == 0x3B8);

#endif
