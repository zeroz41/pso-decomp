#ifndef PSO_ENEMY_GYARANZO_TOBJGYARANZOMISSILE_H
#define PSO_ENEMY_GYARANZO_TOBJGYARANZOMISSILE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/object/base/TObjMotion.h"

struct TObjGyaranzoMissile : public TObjCollidable {
    TObjGyaranzoMissile(u8 *arg1, u8 *arg2, u16 arg3);
    virtual ~TObjGyaranzoMissile();
    virtual void run_task();
    virtual void render();
    void sub_800D47B4();
    Vec velocity;
    u8 pad_B8[0xC];
    u16 target_id;
    u8 pad_C6[0x2];
    s32 timer;
    s32 wobble_phase;
    s32 wobble_speed;
    f32 wobble_height;
    u16 owner_id;
    u8 pad_DA[0x2];
};

typedef char TObjGyaranzoMissile_size[sizeof(TObjGyaranzoMissile) == 0xDC ? 1 : -1];
#endif
