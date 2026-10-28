#ifndef PSO_OBJECT_TOBJGYARANZOMISSILE_H
#define PSO_OBJECT_TOBJGYARANZOMISSILE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/object/TObjMotion.h"

struct TObjGyaranzoMissile : public TObjCollidable {
    virtual ~TObjGyaranzoMissile();
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
    virtual void render();
    virtual void run_task();
    u8 pad_DA[0x2];
    void copy_from(void* q);
};

typedef char TObjGyaranzoMissile_size[sizeof(TObjGyaranzoMissile) == 0xDC ? 1 : -1];
#endif
