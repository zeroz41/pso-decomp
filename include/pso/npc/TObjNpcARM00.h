#ifndef PSO_NPC_TOBJNPCARM00_H
#define PSO_NPC_TOBJNPCARM00_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcARM00 : public TUnk_804A9F50 {
    TObjNpcARM00(TObject *parent, void *set_data);
    virtual ~TObjNpcARM00();
    virtual void play_voice();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TObjNpcARM00_size, sizeof(TObjNpcARM00) == 0x3B8);

extern "C" {
void *TObjNpcARW00__create(void *set_data);
void *__dt__12TObjNpcARM00Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcARM00.cpp ---
extern "C" {
void *TObjNpcARW00__create(void *set_data);
void *__dt__12TObjNpcARM00Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
