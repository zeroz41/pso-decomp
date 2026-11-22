#ifndef PSO_CAMERA_TCAMERAFOLLOW_H
#define PSO_CAMERA_TCAMERAFOLLOW_H

#include "types.h"
#include "pso/camera/TCameraController.h"

// Four records the constructor clears; nothing else reads or writes them.
struct FollowCameraSlot {
    void clear();
    f32 pad_0[6];
    s32 pad_18;
};

// Camera modes 0-3, the default camera, one per view: follows the actor from
// eye_offset behind it, turned by yaw, and looks at target_offset in front of it.
class TCameraFollow : public TCameraController {
public:
    TCameraFollow();
    virtual ~TCameraFollow();
    virtual void run_task();
    static TCameraController *create();
    s32 get_target_yaw();
    void clear_follow_flags();
    void set_close_up(s32 on);
    // Sets both offsets (follow_flags 8 keeps them from select_follow_camera_offsets)
    // and the yaw to turn to.
    void set_pos_target(Vec *target_offset, Vec *eye_offset, s32 yaw);
    void update_manual_camera();
    s32 apply_override_pose();
    // The keyboard pad holds the button that hands the camera to update_manual_camera
    // (never in split screen).
    s32 is_manual_camera_held();
    void rotate_heading_by_stick();
    // The eye turned to heading beside the actor is cut off by collision from the current
    // eye or from the target.
    s32 is_side_obstructed(s32 heading);
    void update_follow_motion_state();
    void calc_follow_position();
    void compute_follow_target();
    // Each frame: the controller flags, the easing rates, the follow_flags and the offsets.
    virtual void update_follow_settings();
    virtual void select_follow_camera_offsets();
    virtual void set_target_yaw(s32 yaw);
    virtual void reset_to_actor_offset(TObjPlayer *actor, Vec *offset);
    virtual void init_pose();
    virtual void reset_to_actor(TObjPlayer *actor);
    virtual void apply_camera_params(s32 pass);

    FollowCameraSlot slots[4];
    Vec eye_offset;     // calc_follow_position: the eye is the actor plus this, turned by yaw
    Vec target_offset;  // compute_follow_target: the look point, turned by the actor's facing
    s32 idle_frames;    // cleared whenever the actor acts; over 250 the camera recenters
    s32 motion_state;   // update_follow_motion_state: 0 still, 1 moving, 2 recentering
    // 1: obstruction predicted, 4: eye 23 or more from the target, 8: offsets requested,
    // 0x10: obstruction close to the eye.
    s32 follow_flags;
    s32 close_up;            // begin_conversation_camera: narrow view, lowered target
    s32 recenter_requested;  // request_follow_camera_recenter
    f32 target_y_offset;
    s32 target_yaw;
};

LAYOUT_ASSERT(TCameraFollow_size, sizeof(TCameraFollow) == 0x110);

// Pose overrides the quest camera opcodes set (bit 1: fixed position and target,
// bit 2: position looking at camera_override_client_id's player).
extern u8 camera_override_flags;
extern Vec camera_override_position;
extern Vec camera_fixed_target_position;
extern u16 camera_override_client_id;

// The quest camera opcodes' overrides: back to following the local
// player, an eye looking at client_id's player, a fixed eye and target.
void reset_camera_to_local_player();
void set_locked_camera_override(const Vec *position, u16 client_id);
void set_fixed_camera_override(const Vec *position, const Vec *target);
// Turns the follow camera back behind its player while it is the active controller
// (the quest cam_adj opcode).
void request_follow_camera_recenter();

void end_conversation_camera();
void begin_conversation_camera();
// The pad button that turns the follow camera back behind client_id's player; which of
// the two depends on that player's card flag 2.
s32 get_camera_reset_button(s32 client_id);
// Eases the follow camera to these offsets from the player, turned by the player's
// facing (the local player's, or client_id's in split screen).
void request_follow_camera_offsets(Vec *target_offset, Vec *eye_offset, u16 client_id);
// Hands the offsets to the follow camera of each view (client_id 0xFFFF: every view, each
// turned by its player's facing plus angle).
void apply_follow_camera_offsets(Vec *target_offset, Vec *eye_offset, s32 angle, u16 client_id);

#endif
