#ifndef PSO_ENEMY_TOBJENEMORFOSGROUNDSHOT_H
#define PSO_ENEMY_TOBJENEMORFOSGROUNDSHOT_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;
class TObjChara;
class TObjEneMorfos;

// Morfos's ground shot: flies straight from start along angle (particle 0x213), hits players it passes and
// dies after 500 units or on a wall.
class TObjEneMorfosGroundShot : public TObjCollidable {
public:
    TObjEneMorfosGroundShot(const Vec *start, s32 angle, TObjChara *owner);
    s32 snap_to_ground(Vec *position);
    virtual ~TObjEneMorfosGroundShot();
    virtual void run_task();
    void hit_target_in_range(TObjChara *target, TObjCollidable *owner);
    Vec pos;
    Vec vel;
    u8 pad_C4[0x18];
    f32 distance;              // travelled so far
    TParticleCtrl *effect;
    Vec ground_pos;            // pos snapped to the floor below
    s32 follow_ground;
    s32 ground_timer;          // re-snaps ground_pos every 5 frames
    u16 owner_id;
    u8 pad_FA[0x2];
};
LAYOUT_ASSERT(TObjEneMorfosGroundShot_size, sizeof(TObjEneMorfosGroundShot) == 0xFC);

#endif
