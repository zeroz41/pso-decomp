#ifndef PSO_NPC_TOBJNPCFEMALEFAT_H
#define PSO_NPC_TOBJNPCFEMALEFAT_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcFemaleFat : public TObjNpcFemale {
    TObjNpcFemaleFat(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleFat();
    static void free_static_model();
    static void load_static_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_model;
};

LAYOUT_ASSERT(TObjNpcFemaleFat_size, sizeof(TObjNpcFemaleFat) == 0x3B8);

#endif
