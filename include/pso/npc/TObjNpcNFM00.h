#ifndef PSO_NPC_TOBJNPCNFM00_H
#define PSO_NPC_TOBJNPCNFM00_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcNFM00 : public TUnk_804A9F50 {
    virtual ~TObjNpcNFM00();
    static void free_resources();
    static void load_assets();
};

typedef char TObjNpcNFM00_size[sizeof(TObjNpcNFM00) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcNFM00__create(void *set_data);
TObjNpcNFM00 *TObjNpcNFM00__ct(TObjNpcNFM00 *npc, TObjControl *control, void *set_data);
}

#endif
