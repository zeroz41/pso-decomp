#ifndef PSO_NPC_TOBJNPCHFW01_H
#define PSO_NPC_TOBJNPCHFW01_H

#include "types.h"
#include "pso/npc/TUnk_804A92A8.h"

struct TObjNpcHFW01 : public TUnk_804A92A8 {
    virtual ~TObjNpcHFW01();
    static void free_static_resources();
    static void load_resources();
};

typedef char TObjNpcHFW01_size[sizeof(TObjNpcHFW01) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcHFW01__create(void *arg0);
u8 *TObjNpcHFW01__ct(u8 *player, s32 arg1, s32 arg2);
}

#endif
