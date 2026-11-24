#ifndef PSO_NPC_TOBJNPCAHM01_H
#define PSO_NPC_TOBJNPCAHM01_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcAHM01 : public TObjNpcMale {
    TObjNpcAHM01(TObject *parent, void *set_data);
    virtual ~TObjNpcAHM01();
    virtual void play_voice();
    static void free_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **shared_object;
    static NJS_TEXLIST *texture_handle;
};

LAYOUT_ASSERT(TObjNpcAHM01_size, sizeof(TObjNpcAHM01) == 0x3B8);

#endif
