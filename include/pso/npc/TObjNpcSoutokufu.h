#ifndef PSO_NPC_TOBJNPCSOUTOKUFU_H
#define PSO_NPC_TOBJNPCSOUTOKUFU_H

#include "types.h"
#include "pso/npc/TUnk_804A9F50.h"

struct TObjNpcSoutokufu : public TUnk_804A9F50 {
    TObjNpcSoutokufu(TObject *parent, void *set_data);
    virtual ~TObjNpcSoutokufu();
    static void close_dialog_window();
    static void load_shared_resource();
};

LAYOUT_ASSERT(TObjNpcSoutokufu_size, sizeof(TObjNpcSoutokufu) == 0x3B8);

extern "C" {
void *__dt__16TObjNpcSoutokufuFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjNpcSoutokufu.cpp ---
extern "C" {
void *__dt__16TObjNpcSoutokufuFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
