#ifndef PSO_NPC_TOBJNPCKENKYU2_H
#define PSO_NPC_TOBJNPCKENKYU2_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcKenkyu2 : public TUnk_804A9F50 {
    TObjNpcKenkyu2(TObject *parent, void *set_data);
    virtual ~TObjNpcKenkyu2();
    static void free_static_model();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcKenkyu2_size, sizeof(TObjNpcKenkyu2) == 0x3B8);

extern "C" {
void *TObjNpcHosa2__create(void *set_data);
void *__dt__14TObjNpcKenkyu2Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcKenkyu2.cpp ---
extern "C" {
void *TObjNpcHosa2__create(void *set_data);
void *__dt__14TObjNpcKenkyu2Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
