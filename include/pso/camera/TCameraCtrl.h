#ifndef PSO_CAMERA_TCAMERACTRL_H
#define PSO_CAMERA_TCAMERACTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

#include <dolphin/mtx/GeoTypes.h>

class TUnk_80488A28;

// The request a scripted or event camera hands over (get_params, and the
// buffer set_active_camera_pose_from_params reads): where to put the eye,
// what to look at and the field of view.
struct CameraParams {
    s32 controller_variant; // update_target_from_state selects controller 9 + this
    s32 pad_04;
    s32 pad_08;
    f32 pad_0C;
    f32 pad_10;
    s32 projection_angle;
    f32 pad_18;
    Vec position;
    Vec target;
    f32 pad_34;
    f32 pad_38;
    f32 pad_3C;
    u8 pad_40[0x4];
    s16 pad_44;
    u8 pad_46[0x2];
};

// Which registered controller drives the view and the requests pending on it.
struct CameraViewState {
    u8 controller;          // registry index of the active controller
    u8 previous_controller; // put back when a forced camera mode ends
    u16 spectate_client;    // client cycle_spectate_target last switched to
    s32 controller_count;   // registry slots the constructor filled
    s32 flags;
};

// A 3x4 view matrix, as the camera builds it each frame for each view.
struct CameraMatrix {
    f32 m[3][4];
};

class TCameraCtrl : public TObject {
public:
    TCameraCtrl(TObject *parent);
    virtual ~TCameraCtrl();
    virtual void run_task();
    virtual void render();
    void setup_default_view(void *offset);
    void calc_rotated_axes();
    void update_target_from_state();
    void update_active_controller();
    void update_shake();
    // Set by run_task once the view is computed; render falls back to the
    // default view on frames where it is still clear.
    u8 view_updated;
    u8 pad_1D[0x3];
    CameraParams params;
    Vec shake_offset;
    f32 pad_74;
    f32 pad_78;
    f32 pad_7C;
    f32 pad_80;
    u8 pad_84[0x8];
    s32 pad_8C;
    void *focus_actor; // the actor the controllers follow (reset_cameras_to_actor)
    // Per split-screen view: the yaw and position saved by sync_split_view_slots,
    // and each view's own eye, target and look point.
    s32 view_yaw[4];
    Vec view_pos[4];
    Vec split_pos[4];
    Vec split_tgt[4];
    Vec split_look[4];
    s32 split_obstructed[4];
    // Set by resolve_anchor_obstruction when the line from look to eye hits
    // the map; gates clamp_to_target_obstruction.
    s32 obstructed;
    // Camera position and the point it looks at; each frame they approach
    // eye and at (approach_camera_vector), or snap to them.
    Vec pos;
    Vec tgt;
    // View angles fed to rotate_matrix_x/y/z, and the field of view given to
    // set_perspective_projection_from_fov (0x3555 = 75 degrees at reset).
    s32 pitch;
    s32 yaw;
    s32 roll;
    s32 fov;
    Vec eye;
    Vec at;
    f32 eye_rate; // rate pos approaches eye with (approach_camera_vector)
    f32 at_rate;  // rate tgt approaches at with
    // Frames of screen shake left and its strength (set_shake_preset, update_shake).
    u32 shake_timer;
    f32 shake_amplitude;
    // Copy of pos taken whenever the position snaps.
    Vec look;

    static s32 get_camera_mode();
    void*get_target_ptr();
    static void copy_vec_to_default(const Vec *up);
    static void sync_split_view_slots(s32 view, s32 all_views);
    static s32 get_split_screen_view_index(u16 id);
    static u16 get_nth_view_player_id(s32 n);
    static f32 get_split_offset(s32 view);
    static void set_fullscreen_viewport();
    static void set_split_viewport(s32 views, s32 view);
    static f32 get_fov();
    static f32 get_view_scale();
    static void restore_full_screen_view();
    static u16 get_camera_target_id(s32 view);
    static void apply_split_screen_view_matrix();
    static s32 *get_view_matrix();
    static void create();
    static void reset_default_view();
    static void init_default_view();
    static void reset_viewport_scissor();
    static void set_viewport_scissor(int mode, void *rect);
    Vec *get_target();
    // The controller driving the view is passed along but not read.
    void resolve_anchor_obstruction(TUnk_80488A28 *controller);
    void clamp_to_target_obstruction(TUnk_80488A28 *controller);
    void update_target_smoothing();
    void update_position();
    void update_pose_smoothing();
    static s32 release_photon_blast_camera();
    void reset_view_flags();
    CameraParams *get_params();
    static void set_shake_preset(s32 preset);
    void cycle_spectate_target();
    static void update_active_player();
    static void update_battle_camera();
    static void create(saddr goal, s32 frames, s32 arg2);
    void *destroy(s16 arg1);
    static void reset_to_local_player();
    static void set_override_position_and_angle(u8 *position, s16 angle);
    static void set_fixed_position_and_target(u8 *position, u8 *target);
    static void set_active_camera_flag();
    void set_field_100(s32 v);
    static s32 get_screen_width();
    static s32 get_screen_height();
    static s32 should_update();
    void copy_position_vectors(void *first, void *second);
    void update_single_screen();
    static int get_mode();
    // The mode word at 0x1C of `p` (the main task).
    static s32 get_mode(void *p);
    // Transforms the vector at src into view space, into dst.
    static void transform_to_view(const Vec *src, Vec *dst);
    static Vec get_target_position();
    static void target_player0(int controller);
    static s32 get_camera_no();
    static void set_mode(int mode);
    static void update_camera_state(f32 x, f32 y, f32 z);
    static void look_at_position(f32 x, f32 y, f32 z);
    static s32 translate_view_negated(f32 x, f32 y, f32 z);
    static void set_clamped_offsets(f32 near_clip, f32 far_clip);
    void update_projection_params();
    static void concat_matrix(uaddr target, uaddr matrix);
    static void update();
    static void reset_view_state();
    static void reset();
    static void select_active_controller(s8 index);
    static CameraMatrix *copy_view_params(CameraMatrix *dst, const CameraMatrix *src);
    static void calc_axes_from_angles(saddr unused_angle, saddr pitch, saddr yaw);
    static int get_instance();
    static int get_camera_id();
    static void set_target_coords(int x, int y);
    static void reset_battle_camera();
    u8 *init_conversation_camera(s32 arg1, s32 arg2, saddr parent);
    static s32 clamp_distance(s32 yaw, s32 to, s32 arg2);
    static void free_entries();
    static void load_camera_banks();
    static void init_projection_state();
    static void set_target(int width, int height);
};

LAYOUT_ASSERT(TCameraCtrl_size, sizeof(TCameraCtrl) == 0x1D4);
// The camera's right axis, which screen tests offset points along.
extern f32 camera_right[3];

extern "C" {
int is_quest_active(void);
// The active controller's registry index.
u16 TCameraCtrl__sub_8006A5DC(void);
void TCameraCtrl__sub_800687C8(void);
void TCameraCtrl__sub_800689E8(void);
s32 TCameraCtrl__sub_800689F4(void);
f32 TCameraCtrl__sub_80068A04(s32 view);
s32 TCameraCtrl__sub_80069304(void);
// Forces registry controller `index` until restore_player_cameras; 0 if a
// mode is already forced.
s32 activate_camera_mode(s32 index);
s32 restore_player_cameras(void);
// Moves the forced controller's eye and target (and, from params, its angle).
void set_active_camera_pose(Vec *position, Vec *target);
void set_active_camera_pose_from_params(CameraParams *params);
void start_camera_shake(s32 frames, f32 amplitude);
}
void calc_projection_screen_offset(f32 *x, f32 *y);

#endif
