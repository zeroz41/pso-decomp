#ifndef PSO_NPC_TOBJNPCKENKYU_H
#define PSO_NPC_TOBJNPCKENKYU_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcKenkyu : public TUnk_804A9F50 {
    virtual ~TObjNpcKenkyu();
    static void free_static_model();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcKenkyu_size, sizeof(TObjNpcKenkyu) == 0x3B8);

extern "C" {
u8 *TObjNpcKenkyu__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjNpcSoutokufu__create(void *arg0);
void *__dt__13TObjNpcKenkyuFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcKenkyu.cpp ---
extern "C" {
u8 *TObjNpcKenkyu__ct(u8 *player, s32 arg1, s32 arg2);
void *TObjNpcSoutokufu__create(void *arg0);
void *__dt__13TObjNpcKenkyuFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
