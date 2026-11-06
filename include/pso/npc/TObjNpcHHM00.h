#ifndef PSO_NPC_TOBJNPCHHM00_H
#define PSO_NPC_TOBJNPCHHM00_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcHHM00 : public TUnk_804A9F50 {
    virtual ~TObjNpcHHM00();
    static void free_resources();
    static void load_resources();
};

typedef char TObjNpcHHM00_size[sizeof(TObjNpcHHM00) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcHHM00__create(void *arg0);
u8 *TObjNpcHHM00__ct(u8 *arg0, s32 arg1, s32 arg2);
void *TObjNpcHRM00__create(void *arg0);
void *__dt__12TObjNpcHHM00Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcHHM00.cpp ---
extern "C" {
u8 *TObjNpcHHM00__ct(u8 *player, s32 arg1, s32 arg2);
void *TObjNpcHRM00__create(void *arg0);
void *__dt__12TObjNpcHHM00Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
