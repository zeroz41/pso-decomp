#ifndef PSO_NPC_TOBJNPCNGCBASE_H
#define PSO_NPC_TOBJNPCNGCBASE_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcNgcBase : public TUnk_804A9F50 {
    TObjNpcNgcBase(TObject *parent, void *set_data, void *resource);
    virtual ~TObjNpcNgcBase();
    static void free_shared_resources();
    static void load_resources();
    static s32 create_variant_13(s32 set_data);
    static s32 create_variant_8(s32 set_data);
    static s32 create_variant_7(s32 set_data);
    static s32 create_variant_6(s32 set_data);
    static s32 create_variant_5(s32 set_data);
};

LAYOUT_ASSERT(TObjNpcNgcBase_size, sizeof(TObjNpcNgcBase) == 0x3B8);

extern "C" {
void *__dt__14TObjNpcNgcBaseFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcNgcBase.cpp ---
extern "C" {
void *__dt__14TObjNpcNgcBaseFv(void *arg0, s16 arg1);
}
// --- end of C functions

extern "C" {
u8 *__ct__14TObjNpcNgcBaseFP7TObjectPvPv(u8 *self, s32 parent, saddr set_data, saddr resource);
}

#endif
