#ifndef PSO_NPC_TOBJNPCNHW00_H
#define PSO_NPC_TOBJNPCNHW00_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcNHW00 : public TUnk_804A8640 {
    virtual ~TObjNpcNHW00();
    static void free_static_resources();
    static void load_resources();
};

typedef char TObjNpcNHW00_size[sizeof(TObjNpcNHW00) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcNHW00__create(void *set_data);
TObjNpcNHW00 *TObjNpcNHW00__ct(TObjNpcNHW00 *npc, TObjControl *control, void *set_data);
}

#endif
