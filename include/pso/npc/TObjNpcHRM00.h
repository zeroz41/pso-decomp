#ifndef PSO_NPC_TOBJNPCHRM00_H
#define PSO_NPC_TOBJNPCHRM00_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct TObjNpcHRM00 : public TObjNpcMale {
    TObjNpcHRM00(TObject *parent, void *set_data);
    virtual ~TObjNpcHRM00();
    static void destroy_resources();
    static void load_resources();
    static void *create(void *set_data);
    static const char *name;
    static void **named_object_resource;
    static NJS_TEXLIST *body_texture_gvm;
};

LAYOUT_ASSERT(TObjNpcHRM00_size, sizeof(TObjNpcHRM00) == 0x3B8);

#endif
