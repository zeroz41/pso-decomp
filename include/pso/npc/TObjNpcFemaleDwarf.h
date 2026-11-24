#ifndef PSO_NPC_TOBJNPCFEMALEDWARF_H
#define PSO_NPC_TOBJNPCFEMALEDWARF_H

#include "types.h"
#include "pso/npc/TObjNpcFemale.h"

struct BmlResource;

struct TObjNpcFemaleDwarf : public TObjNpcFemale {
    TObjNpcFemaleDwarf(TObject *parent, void *set_data);
    virtual ~TObjNpcFemaleDwarf();
    static void unload_static_data();
    static void load_static_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *static_data;
};

LAYOUT_ASSERT(TObjNpcFemaleDwarf_size, sizeof(TObjNpcFemaleDwarf) == 0x3B8);

#endif
