#ifndef PSO_NPC_TOBJNPCMALEMACHO_H
#define PSO_NPC_TOBJNPCMALEMACHO_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcMaleMacho : public TUnk_804A9F50 {
    virtual ~TObjNpcMaleMacho();
    static void close_dialog_window();
    static void load_static_resource();
};

typedef char TObjNpcMaleMacho_size[sizeof(TObjNpcMaleMacho) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcMaleMacho__create(void *set_data);
TObjNpcMaleMacho *TObjNpcMaleMacho__ct(TObjNpcMaleMacho *npc, TObjControl *control, void *set_data);
}

#endif
