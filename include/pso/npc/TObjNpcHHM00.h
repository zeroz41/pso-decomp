#ifndef PSO_NPC_TOBJNPCHHM00_H
#define PSO_NPC_TOBJNPCHHM00_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcHHM00 : public TObjNpcMale {
    TObjNpcHHM00(TObject *parent, void *set_data);
    virtual ~TObjNpcHHM00();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **model_object;
    static NJS_TEXLIST *body_texture_gvm_handle;
};

LAYOUT_ASSERT(TObjNpcHHM00_size, sizeof(TObjNpcHHM00) == 0x3B8);

#endif
