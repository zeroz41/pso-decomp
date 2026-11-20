#ifndef PSO_NPC_TOBJNPCARM00_H
#define PSO_NPC_TOBJNPCARM00_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcARM00 : public TUnk_804A9F50 {
    virtual ~TObjNpcARM00();
    virtual void play_voice();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TObjNpcARM00_size, sizeof(TObjNpcARM00) == 0x3B8);

extern "C" {
u8 *TObjNpcARM00__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjNpcARW00__create(void *arg0);
void *__dt__12TObjNpcARM00Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcARM00.cpp ---
extern "C" {
u8 *TObjNpcARM00__ct(u8 *player, s32 arg1, s32 arg2);
void *TObjNpcARW00__create(void *arg0);
void *__dt__12TObjNpcARM00Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
