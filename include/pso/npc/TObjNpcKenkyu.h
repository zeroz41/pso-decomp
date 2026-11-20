#ifndef PSO_NPC_TOBJNPCKENKYU_H
#define PSO_NPC_TOBJNPCKENKYU_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcKenkyu : public TUnk_804A9F50 {
    TObjNpcKenkyu(TObject *parent, void *set_data);
    virtual ~TObjNpcKenkyu();
    static void free_static_model();
    static void load_shared_resource();
};

typedef char TObjNpcKenkyu_size[sizeof(TObjNpcKenkyu) == 0x3B8 ? 1 : -1];

extern "C" {
void *TObjNpcSoutokufu__create(void *arg0);
void *__dt__13TObjNpcKenkyuFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcKenkyu.cpp ---
extern "C" {
void *TObjNpcSoutokufu__create(void *arg0);
void *__dt__13TObjNpcKenkyuFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
