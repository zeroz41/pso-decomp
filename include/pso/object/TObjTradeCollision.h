#ifndef PSO_OBJECT_TOBJTRADECOLLISION_H
#define PSO_OBJECT_TOBJTRADECOLLISION_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjTradeCollision : public TObjCollidable {
    virtual ~TObjTradeCollision();
    bool is_player_outside_trade_radius(u32);
    virtual void run_task();
    virtual void render();
    u8 unk_AC[0x4];
};

typedef char TObjTradeCollision_size[sizeof(TObjTradeCollision) == 0xB0 ? 1 : -1];

extern "C" {
void *TObjTradeCollision__create(void *arg0);
u8 *TObjTradeCollision__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__18TObjTradeCollisionFv(void *arg0, s16 arg1);
void run_task__18TObjTradeCollisionFv(s32 arg0);
}

// --- C functions defined in TObjTradeCollision.cpp ---
extern "C" {
void *TObjTradeCollision__create(void *arg0);
u8 *TObjTradeCollision__ct(u8 *trade_collision, s32 arg1, s32 arg2);
void *__dt__18TObjTradeCollisionFv(void *arg0, s16 arg1);
void run_task__18TObjTradeCollisionFv(s32 arg0);
}
// --- end of C functions

#endif
