#ifndef PSO_ENEMY_GYARANZO_TOBJGYARANZOMISSILE_H
#define PSO_ENEMY_GYARANZO_TOBJGYARANZOMISSILE_H

#include "types.h"
#include <dolphin/mtx.h>
#include "pso/object/base/TObjMotion.h"

struct TObjEneGyaranzo;

// How TObjEneGyaranzo::spawn_missile_volley launches one missile.
struct GyaranzoMissileLaunch {
    Vec *position;
    s32 rotation_x;
    s32 rotation_y;
    f32 wobble_speed;   // scaled by 0.5-1.0 at random
    f32 wobble_height;
    f32 pad_14;
};

struct TObjGyaranzoMissile : public TObjCollidable {
    TObjGyaranzoMissile(TObjEneGyaranzo *owner, GyaranzoMissileLaunch *launch, u16 target);
    virtual ~TObjGyaranzoMissile();
    virtual void run_task();
    virtual void render();
    // Hits every hittable player with the parameter-2 damage, then goes off.
    void explode();
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

LAYOUT_ASSERT(TObjGyaranzoMissile_size, sizeof(TObjGyaranzoMissile) == 0xDC);

// Set from the Gyaranzo parameter table (TObjEneGyaranzo::init_params_from_table).
extern f32 TObjGyaranzoMissile__speed_scale;
extern f32 TObjGyaranzoMissile__max_range;
#endif
