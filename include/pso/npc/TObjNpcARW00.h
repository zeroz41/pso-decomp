#ifndef PSO_NPC_TOBJNPCARW00_H
#define PSO_NPC_TOBJNPCARW00_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct TObjNpcARW00 : public TObjNpcFemale {
    TObjNpcARW00(TObject *parent, void *set_data);
    virtual ~TObjNpcARW00();
    virtual void play_voice();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **static_model;
    static NJS_TEXLIST *gvm_texture_handle;
};

LAYOUT_ASSERT(TObjNpcARW00_size, sizeof(TObjNpcARW00) == 0x3B8);

#endif
