#ifndef PSO_OBJECT_TOBJRADERCOL_H
#define PSO_OBJECT_TOBJRADERCOL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjRaderCol : public TObjBase {
    virtual ~TObjRaderCol();
    u8 unk_90[0x4];
    u32 m_94;
    u32 m_98;
    u32 m_9c;
    virtual void render();
    static void check_local_player_in_range(void *arg0_);
    virtual void run_task();
};

typedef char TObjRaderCol_size[sizeof(TObjRaderCol) == 0xA0 ? 1 : -1];

extern "C" {
u8 *TObjRaderCol__ct(TObjRaderCol *arg0, s32 arg1, s32 arg2);
void *__dt__12TObjRaderColFv(void *arg0, s16 arg1);
}

// --- C functions defined in TObjRaderCol.cpp ---
extern "C" {
u8 *TObjRaderCol__ct(TObjRaderCol *rader_col, s32 arg1, s32 arg2);
void *__dt__12TObjRaderColFv(void *arg0, s16 arg1);
}
// --- end of C functions

#endif
