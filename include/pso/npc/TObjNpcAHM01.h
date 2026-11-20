#ifndef PSO_NPC_TOBJNPCAHM01_H
#define PSO_NPC_TOBJNPCAHM01_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcAHM01 : public TUnk_804A9F50 {
    virtual ~TObjNpcAHM01();
    virtual void play_voice();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TObjNpcAHM01_size, sizeof(TObjNpcAHM01) == 0x3B8);

extern "C" {
u8 *TObjNpcAHM01__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjNpcARM00__create(void *arg0);
void *__dt__12TObjNpcAHM01Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcAHM01.cpp ---
extern "C" {
u8 *TObjNpcAHM01__ct(u8 *player, s32 arg1, s32 arg2);
void *TObjNpcARM00__create(void *arg0);
void *__dt__12TObjNpcAHM01Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
