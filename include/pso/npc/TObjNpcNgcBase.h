#ifndef PSO_NPC_TOBJNPCNGCBASE_H
#define PSO_NPC_TOBJNPCNGCBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcNgcBase : public TUnk_804A9F50 {
    virtual ~TObjNpcNgcBase();
    static void free_shared_resources();
    static void load_resources();
    static s32 create_variant_13(s32 arg0);
    static s32 create_variant_8(s32 arg0);
    static s32 create_variant_7(s32 arg0);
    static s32 create_variant_6(s32 arg0);
    static s32 create_variant_5(s32 arg0);
};

typedef char TObjNpcNgcBase_size[sizeof(TObjNpcNgcBase) == 0x3B8 ? 1 : -1];

extern "C" {
void *__dt__14TObjNpcNgcBaseFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcNgcBase.cpp ---
extern "C" {
void *__dt__14TObjNpcNgcBaseFv(void *arg0, s16 arg1);
}
// --- end of C functions

extern "C" {
u8 *TObjNpcNgcBase__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
}

#endif
