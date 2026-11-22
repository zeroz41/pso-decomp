#ifndef PSO_CAMERA_TCAMERACONTROLLER_H
#define PSO_CAMERA_TCAMERACONTROLLER_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TObjPlayer;

// One camera behaviour of TCameraCtrl (an entry of camera_controller_registry).
// Each frame TCameraCtrl runs the active controller, then copies its pose into the
// view with apply_camera_controller_pose.
class TCameraController : public TObject {
public:
    TCameraController();
    virtual ~TCameraController();
    void set_target(TObjPlayer *actor);
    void set_target_pos(Vec *pos);
    s32 predict_obstruction();
    // Called the first frame after a view reset (pass 0) and two frames later (pass 1).
    virtual void apply_camera_params(s32 pass);
    virtual void reset_state();
    // reset_cameras_to_actor: put the camera behind the actor.
    virtual void reset_to_actor(TObjPlayer *actor);
    virtual void reset_to_actor_offset(TObjPlayer *actor, Vec *offset);
    virtual void init_pose();
    virtual void post_update_view();
    virtual void run_task();
    u16 get_actor_id();

    TObjPlayer *actor;  // set_target; looked up again by actor_id
    u16 actor_id;       // get_entity_id(actor)
    s32 state;
    s32 pad_28;
    s32 pitch;
    s32 yaw;
    s32 roll;  // third of the angle triple the ctor clears with pitch and yaw
    // 1: obstruction checks, 4: smooth the pose, 8: smooth the target,
    // 0x10: keep the target height (read by TCameraCtrl).
    s32 flags;
    Vec position;
    Vec target;
    s32 fov;  // copied to TCameraCtrl::fov
    f32 eye_rate;  // copied to TCameraCtrl::eye_rate
    f32 at_rate;   // copied to TCameraCtrl::at_rate
    Vec obstruction_point;  // predict_obstruction: where the line to the actor is blocked
};

LAYOUT_ASSERT(TCameraController_size, sizeof(TCameraController) == 0x6C);

// Copies the controller's pose into TCameraCtrl's view.
void apply_camera_controller_pose(TCameraController *controller);

// Empty hooks: TCameraCtrl::reset and TCameraCtrl::reset_view_state call them.
void on_camera_reset();
void on_view_state_reset();

#endif
