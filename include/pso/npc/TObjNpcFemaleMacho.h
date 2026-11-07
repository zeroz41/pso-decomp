#ifndef PSO_NPC_TOBJNPCFEMALEMACHO_H
#define PSO_NPC_TOBJNPCFEMALEMACHO_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

class TObjControl;

struct TObjNpcFemaleMacho : public TUnk_804A8640 {
    virtual ~TObjNpcFemaleMacho();
    static void close_dialog_window();
    static void load_resources();
};

typedef char TObjNpcFemaleMacho_size[sizeof(TObjNpcFemaleMacho) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcFemaleMacho__create(void *set_data);
TObjNpcFemaleMacho *TObjNpcFemaleMacho__ct(TObjNpcFemaleMacho *npc, TObjControl *control, void *set_data);
}

#endif
