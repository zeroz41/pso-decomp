#ifndef PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_CARRYFLY_H
#define PSO_ENEMY_FLY_TOBJENEBM3FLYNEST_CARRYFLY_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/animation/ActorAnimationState.h"

// One of the six flies a TObjEneBm3FlyNest sends out (vtable __vt__26TObjEneBm3FlyNest_CarryFly):
// it waits at its offset from origin until *arrived reaches its index, then flies in an arc to
// target and bursts there. Field names are inferred from run_task/render/the ctor.
class TObjEneBm3FlyNest_CarryFly : public TObject {
public:
    TObjEneBm3FlyNest_CarryFly(TObject *parent, Vec *origin, Vec *target, Vec *unused, s32 *arrived, s32 index);
    virtual ~TObjEneBm3FlyNest_CarryFly();
    virtual void run_task();
    virtual void render();

    Vec offset;     // 0x1C, drawn relative to origin (state 0) or target
    s32 index;      // 0x28
    s32 state;      // 0x2C
    Vec *origin;    // 0x30
    Vec *target;    // 0x34
    s32 *arrived;   // 0x38
    f32 unk_3C;     // 0x3C, set to 1.0f
    s32 angle;      // 0x40
    s32 unk_44;     // 0x44, set to 0
    AnimationMotion *motion;  // 0x48, drawn with draw_model_motion
    f32 frame;      // 0x4C
    Vec velocity;   // 0x50
    f32 distance;   // 0x5C
    f32 arc;        // 0x60
    f32 height;     // 0x64
};
typedef char TObjEneBm3FlyNest_CarryFly_size[sizeof(TObjEneBm3FlyNest_CarryFly) == 0x68 ? 1 : -1];

#endif
