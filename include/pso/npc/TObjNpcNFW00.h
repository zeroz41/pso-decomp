#ifndef PSO_NPC_TOBJNPCNFW00_H
#define PSO_NPC_TOBJNPCNFW00_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcNFW00 : public TUnk_804A8640 {
    TObjNpcNFW00(TObject *parent, void *set_data);
    virtual ~TObjNpcNFW00();
    static void free_resources();
    static void load_assets();
};

typedef char TObjNpcNFW00_size[sizeof(TObjNpcNFW00) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcNFW00__create(void *set_data);
}

#endif
