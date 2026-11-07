#ifndef PSO_NPC_TOBJNPCSOLDIERMACHO_H
#define PSO_NPC_TOBJNPCSOLDIERMACHO_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcSoldierMacho : public TUnk_804A9F50 {
    virtual ~TObjNpcSoldierMacho();
    static void unload_static_data();
    static void load_shared_resource();
};

typedef char TObjNpcSoldierMacho_size[sizeof(TObjNpcSoldierMacho) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcSoldierMacho__create(void *set_data);
TObjNpcSoldierMacho *TObjNpcSoldierMacho__ct(TObjNpcSoldierMacho *npc, TObjControl *control, void *set_data);
}

#endif
