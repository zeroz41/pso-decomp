#ifndef PSO_BOSS_VOLOPT_TBOSS3VOLOPTMISSILE_H
#define PSO_BOSS_VOLOPT_TBOSS3VOLOPTMISSILE_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjMotion.h"
#include <dolphin/mtx.h>

// A homing missile of Vol Opt: it steers towards a player and explodes on
// contact, on the floor or when its time runs out, damaging what it hits.
class TParticleCtrl;
class TBoss3VoloptMissile : public TObjCollidable {
public:
    NJS_OBJECT *model;
    NJS_TEXLIST *textures;
    Vec velocity;
    u8 pad_c0[0xC];
    s32 target_id;
    s32 age;
    u8 pad_d4[0xC];
    TParticleCtrl *trail;
    Angle3 trail_rotation;

    TBoss3VoloptMissile(TObject *parent, Vec *pos, s32 angle, s32 target);
    virtual ~TBoss3VoloptMissile();
    virtual void run_task();
    virtual void render();

    void explode_and_destroy();
};

LAYOUT_ASSERT(TBoss3VoloptMissile_size, sizeof(TBoss3VoloptMissile) == 0xF0);


#endif
