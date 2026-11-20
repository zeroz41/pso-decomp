#ifndef PSO_NPC_TOBJNPCHFW00_H
#define PSO_NPC_TOBJNPCHFW00_H

#include "types.h"
#include "pso/npc/TUnk_804A92A8.h"

struct TObjNpcHFW00 : public TUnk_804A92A8 {
    virtual ~TObjNpcHFW00();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TObjNpcHFW00_size, sizeof(TObjNpcHFW00) == 0x3B8);

extern "C" {
void *TObjNpcHFW00__create(void *arg0);
u8 *TObjNpcHFW00__ct(u8 *player, s32 arg1, saddr arg2);
}

#endif
