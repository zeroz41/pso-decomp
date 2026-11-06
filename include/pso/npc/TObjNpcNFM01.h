#ifndef PSO_NPC_TOBJNPCNFM01_H
#define PSO_NPC_TOBJNPCNFM01_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcNFM01 : public TUnk_804A9F50 {
    virtual ~TObjNpcNFM01();
    static void free_resources();
    static void load_resources();
};

typedef char TObjNpcNFM01_size[sizeof(TObjNpcNFM01) == 0x3B8 ? 1 : -1];

class TObjControl;

extern "C" {
void *TObjNpcNFM01__create(void *set_data);
TObjNpcNFM01 *TObjNpcNFM01__ct(TObjNpcNFM01 *npc, TObjControl *control, void *set_data);
}

#endif
