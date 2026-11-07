#ifndef PSO_NPC_TOBJNPCGOVERNORBASE_H
#define PSO_NPC_TOBJNPCGOVERNORBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcGovernorBase : public TUnk_804A9F50 {
    virtual ~TObjNpcGovernorBase();
    static void free_shared_data();
    static void load_shared_resource();
};

typedef char TObjNpcGovernorBase_size[sizeof(TObjNpcGovernorBase) == 0x3B8 ? 1 : -1];

extern "C" {
u8 *TObjNpcGovernorBase__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjNpcGovernorBase__create(void *arg0);
void *__dt__19TObjNpcGovernorBaseFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcGovernorBase.cpp ---
extern "C" {
u8 *TObjNpcGovernorBase__ct(u8 *player, s32 arg1, s32 arg2);
void *TObjNpcGovernorBase__create(void *arg0);
void *__dt__19TObjNpcGovernorBaseFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
