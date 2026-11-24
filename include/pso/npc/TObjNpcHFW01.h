#ifndef PSO_NPC_TOBJNPCHFW01_H
#define PSO_NPC_TOBJNPCHFW01_H

#include "types.h"
#include "pso/npc/TObjNpcFomarl.h"

struct TObjNpcHFW01 : public TObjNpcFomarl {
    TObjNpcHFW01(TObject *parent, void *set_data);
    virtual ~TObjNpcHFW01();
    static void free_static_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **resource_node;
    static NJS_TEXLIST *texture_handle;
};

LAYOUT_ASSERT(TObjNpcHFW01_size, sizeof(TObjNpcHFW01) == 0x3B8);

#endif
