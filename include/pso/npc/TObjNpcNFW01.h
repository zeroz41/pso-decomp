#ifndef PSO_NPC_TOBJNPCNFW01_H
#define PSO_NPC_TOBJNPCNFW01_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcNFW01 : public TUnk_804A8640 {
    virtual ~TObjNpcNFW01();
    static void free_resources();
    static void load_resources();
};

typedef char TObjNpcNFW01_size[sizeof(TObjNpcNFW01) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcNFW01__create(void *set_data);
TObjNpcNFW01 *TObjNpcNFW01__ct(TObjNpcNFW01 *npc, TObjControl *control, void *set_data);
}

#endif
