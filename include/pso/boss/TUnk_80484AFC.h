#ifndef PSO_BOSS_TUNK_80484AFC_H
#define PSO_BOSS_TUNK_80484AFC_H

#include "types.h"
#include "pso/object/TObjMotion.h"
#include <dolphin/mtx.h>

// A homing missile of Vol Opt: it steers towards a player and explodes on
// contact, on the floor or when its time runs out, damaging what it hits.
class TUnk_80484AFC : public TObjCollidable {
public:
    s32 model;
    s32 textures;
    Vec velocity;
    u8 pad_c0[0xC];
    s32 target_id;
    s32 age;
    u8 pad_d4[0xC];
    void *trail;
    s32 trail_rotation[3];

    TUnk_80484AFC(TObject *parent, Vec *pos, s32 angle, s32 target);
    virtual ~TUnk_80484AFC();
    virtual void run_task();
    virtual void render();

    void explode_and_destroy();
};

typedef char TUnk_80484AFC_size[sizeof(TUnk_80484AFC) == 0xF0 ? 1 : -1];


#endif
