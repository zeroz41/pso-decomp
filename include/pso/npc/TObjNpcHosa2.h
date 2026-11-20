#ifndef PSO_NPC_TOBJNPCHOSA2_H
#define PSO_NPC_TOBJNPCHOSA2_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcHosa2 : public TUnk_804A9F50 {
    virtual ~TObjNpcHosa2();
    static void close_dialog_window();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcHosa2_size, sizeof(TObjNpcHosa2) == 0x3B8);

extern "C" {
u8 *TObjNpcHosa2__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__12TObjNpcHosa2Fv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcHosa2.cpp ---
extern "C" {
u8 *TObjNpcHosa2__ct(u8 *player, s32 arg1, s32 arg2);
void *__dt__12TObjNpcHosa2Fv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
