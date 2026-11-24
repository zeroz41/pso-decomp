#ifndef PSO_ENEMY_NANODRAGO_TUNK_80494E10_H
#define PSO_ENEMY_NANODRAGO_TUNK_80494E10_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;
class TObjChara;
class TObjEneNanoDrago;

// The straight beam TObjEneNanoDrago::update_single_beam_state fires at its target. On the
// ground it also drags a trail effect along the floor under the beam.
class TUnk_80494E10 : public TObjCollidable {
public:
    TUnk_80494E10(Vec *origin, Vec *target_pos, s32 trail, TObjEneNanoDrago *owner);
    virtual ~TUnk_80494E10();
    virtual void run_task();
    // Moves origin onto the ground straight below it; 0 when there is none.
    s32 snap_to_ground(Vec *origin);
    // Hits target when it is within nano_drago_single_beam_speed of the beam.
    void hit_object_in_radius(TObjChara *target, TObjCollidable *shooter);
    Vec pos;
    Vec velocity;
    u8 pad_C4[0x18];
    f32 distance;  // travelled so far; the beam ends at 500
    TParticleCtrl *effect;
    TParticleCtrl *trail_effect;
    Vec trail_pos;  // on the ground under the beam
    s32 trail;
    s32 trail_snap_timer;  // trail_pos is snapped to the ground every fifth update
    u16 owner_id;
    u8 pad_FE[0x2];
};
LAYOUT_ASSERT(TUnk_80494E10_size, sizeof(TUnk_80494E10) == 0x100);

#endif
