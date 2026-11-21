#ifndef PSO_NPC_TOBJNPCNHW00_H
#define PSO_NPC_TOBJNPCNHW00_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcNHW00 : public TUnk_804A8640 {
    TObjNpcNHW00(TObject *parent, void *set_data);
    virtual ~TObjNpcNHW00();
    static void free_static_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TObjNpcNHW00_size, sizeof(TObjNpcNHW00) == 0x3B8);

class TObjControl;

extern "C" {
void *TObjNpcNHW00__create(void *set_data);
}

#endif
