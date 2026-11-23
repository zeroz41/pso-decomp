#ifndef PSO_OBJECT_COLLISION_TOBJRADERCOL_H
#define PSO_OBJECT_COLLISION_TOBJRADERCOL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjRaderCol : public TObjBase {
    TObjRaderCol(TObject *parent, void *set_data);
    virtual ~TObjRaderCol();
    u8 unk_90[0x4];
    u32 id;
    u32 m_98;
    u32 m_9c;
    virtual void render();
    static void check_local_player_in_range(void *arg0_);
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjRaderCol_size, sizeof(TObjRaderCol) == 0xA0);

extern "C" {
void *__dt__12TObjRaderColFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjRaderCol.cpp ---
extern "C" {
void *__dt__12TObjRaderColFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
