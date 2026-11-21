#ifndef PSO_NPC_TOBJNPCSOLDIERMACHO_H
#define PSO_NPC_TOBJNPCSOLDIERMACHO_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcSoldierMacho : public TUnk_804A9F50 {
    TObjNpcSoldierMacho(TObject *parent, void *set_data);
    virtual ~TObjNpcSoldierMacho();
    static void unload_static_data();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcSoldierMacho_size, sizeof(TObjNpcSoldierMacho) == 0x3B8);

class TObjControl;

extern "C" {
void *TObjNpcSoldierMacho__create(void *set_data);
}

#endif
