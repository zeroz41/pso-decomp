#ifndef PSO_ENEMY_NANODRAGO_TOBJNANODRAGOTARGETEDBEAM_H
#define PSO_ENEMY_NANODRAGO_TOBJNANODRAGOTARGETEDBEAM_H
#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/render_util.h"

class TParticleCtrl;

// The NanoDrago's homing beam (TObjEneNanoDrago::spawn_targeted_beam): it waits at the
// firing origin for `delay` frames, then steers toward the target for up to 90 frames.
class TObjNanoDragoTargetedBeam : public TObjCollidable {
public:
    TObjNanoDragoTargetedBeam(Vec *origin, u16 target_id, Angle3 *rotation, s32 delay, u16 shooter_id);
    virtual ~TObjNanoDragoTargetedBeam();
    virtual void run_task();
    Vec beam_pos;
    Vec prev_pos;
    Vec velocity;
    u8 pad_D0[0x18];
    f32 distance;
    s32 timer;            // the delay counted down, then the frames in flight
    Vec *origin;          // the NanoDrago's beam origin the beam waits at
    f32 homing;           // the steering pull toward the target, grown every frame
    TParticleCtrl *effect;
    s32 state;            // 0 waiting at the origin, 1 in flight
    u16 target_id;
    u16 shooter_id;
};
LAYOUT_ASSERT(TObjNanoDragoTargetedBeam_size, sizeof(TObjNanoDragoTargetedBeam) == 0x104);
LAYOUT_ASSERT(TObjNanoDragoTargetedBeam_timer, offsetof(TObjNanoDragoTargetedBeam, timer) == 0xEC);
LAYOUT_ASSERT(TObjNanoDragoTargetedBeam_target_id, offsetof(TObjNanoDragoTargetedBeam, target_id) == 0x100);

#endif
