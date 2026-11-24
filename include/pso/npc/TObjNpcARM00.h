#ifndef PSO_NPC_TOBJNPCARM00_H
#define PSO_NPC_TOBJNPCARM00_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcARM00 : public TObjNpcMale {
    TObjNpcARM00(TObject *parent, void *set_data);
    virtual ~TObjNpcARM00();
    virtual void play_voice();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **model_resource;
    static NJS_TEXLIST *texture_list;
};

LAYOUT_ASSERT(TObjNpcARM00_size, sizeof(TObjNpcARM00) == 0x3B8);

#endif
