#ifndef PSO_NPC_TOBJNPCSOUTOKUFU_H
#define PSO_NPC_TOBJNPCSOUTOKUFU_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcSoutokufu : public TUnk_804A9F50 {
    virtual ~TObjNpcSoutokufu();
    static void close_dialog_window();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcSoutokufu_size, sizeof(TObjNpcSoutokufu) == 0x3B8);

extern "C" {
u8 *TObjNpcSoutokufu__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__16TObjNpcSoutokufuFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcSoutokufu.cpp ---
extern "C" {
u8 *TObjNpcSoutokufu__ct(u8 *player, s32 arg1, s32 arg2);
void *__dt__16TObjNpcSoutokufuFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
