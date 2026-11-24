#ifndef PSO_NPC_TOBJNPCNHW01_H
#define PSO_NPC_TOBJNPCNHW01_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct TObjNpcNHW01 : public TObjNpcFemale {
    TObjNpcNHW01(TObject *parent, void *set_data);
    virtual ~TObjNpcNHW01();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **model_object;
    static NJS_TEXLIST *texture_handle;
};

LAYOUT_ASSERT(TObjNpcNHW01_size, sizeof(TObjNpcNHW01) == 0x3B8);

#endif
