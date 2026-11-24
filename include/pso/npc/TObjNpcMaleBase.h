#ifndef PSO_NPC_TOBJNPCMALEBASE_H
#define PSO_NPC_TOBJNPCMALEBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct BmlResource;

struct TObjNpcMaleBase : public TUnk_804A9F50 {
    TObjNpcMaleBase(TObject *parent, void *set_data);
    virtual ~TObjNpcMaleBase();
    static void free_static_data();
    static void load_shared_resource();
    static void *create(void *set_data);
    static const char *name;
    static BmlResource *shared_bml_archive;
};

LAYOUT_ASSERT(TObjNpcMaleBase_size, sizeof(TObjNpcMaleBase) == 0x3B8);

#endif
