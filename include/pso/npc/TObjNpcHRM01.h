#ifndef PSO_NPC_TOBJNPCHRM01_H
#define PSO_NPC_TOBJNPCHRM01_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcHRM01 : public TObjNpcMale {
    TObjNpcHRM01(TObject *parent, void *set_data);
    virtual ~TObjNpcHRM01();
    static void free_shared_objects();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **shared_object_resource;
    static NJS_TEXLIST *body_texture_gvm_handle;
};

LAYOUT_ASSERT(TObjNpcHRM01_size, sizeof(TObjNpcHRM01) == 0x3B8);

#endif
