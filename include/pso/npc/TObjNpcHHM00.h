#ifndef PSO_NPC_TOBJNPCHHM00_H
#define PSO_NPC_TOBJNPCHHM00_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcHHM00 : public TUnk_804A9F50 {
    virtual ~TObjNpcHHM00();
    static void free_resources();
    static void load_resources();
};

typedef char TObjNpcHHM00_size[sizeof(TObjNpcHHM00) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcHHM00__create(void *set_data);
TObjNpcHHM00 *TObjNpcHHM00__ct(TObjNpcHHM00 *npc, TObjControl *control, void *set_data);
}

#endif
