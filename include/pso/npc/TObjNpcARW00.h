#ifndef PSO_NPC_TOBJNPCARW00_H
#define PSO_NPC_TOBJNPCARW00_H

#include "types.h"
#include "pso/npc/TUnk_804A8640.h"

struct TObjNpcARW00 : public TUnk_804A8640 {
    TObjNpcARW00(TObject *parent, void *set_data);
    virtual ~TObjNpcARW00();
    virtual void play_voice();
    static void free_resources();
    static void load_resources();
};

LAYOUT_ASSERT(TObjNpcARW00_size, sizeof(TObjNpcARW00) == 0x3B8);

extern "C" {
void *__dt__12TObjNpcARW00Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcARW00.cpp ---
extern "C" {
void *__dt__12TObjNpcARW00Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
