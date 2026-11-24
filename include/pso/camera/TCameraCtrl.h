#ifndef PSO_CAMERA_TCAMERACTRL_H
#define PSO_CAMERA_TCAMERACTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

#include <dolphin/mtx/GeoTypes.h>

class TCameraController;
struct NJS_CAMERA;
struct TObjPlayer;
struct CameraViewParams;
struct CharacterSelectionRequest;

// The request a scripted or event camera hands over (get_params, and the
// buffer set_active_camera_pose_from_params reads): where to put the eye,
// what to look at and the field of view.
struct CameraParams {
    s32 controller_variant; // update_target_from_state selects controller 9 + this
    s32 pad_04;
    s32 pad_08;
    f32 pad_0C;
    f32 eye_rate; // the event camera's eye_rate (TCameraFixed, TCameraWatchPlayer)
    // Field of view: in degrees for the event cameras' apply_camera_params, a turn = 0x10000
    // for set_active_camera_pose_from_params.
    s32 fov;
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
    void setup_default_view(Vec *offset);
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
    TObjPlayer *focus_actor;
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

    // Registry index of the active controller and the pending view requests.
    static CameraViewState view_state;
    // The viewport and projection in use, and the copy restore_full_screen_view
    // keeps while the full screen is shown.
    static CameraViewParams view_params;
    static CameraViewParams saved_view_params;
    static Vec up_vector;
    // The view matrix, and one per split-screen view.
    static CameraMatrix view_matrix;
    static CameraMatrix view_matrices[4];
    // The GX viewport and scissor box.
    static s16 viewport_width;
    static s16 viewport_height;
    static s16 viewport_x;
    static s16 viewport_y;
    static s32 pose_snap_flags;
    static int camera_id;
    static s16 camera_mode;
    // Set when the restored view's center is off the screen center.
    static s16 view_offset_active;
    // The one view split-screen frames run and draw, or -1 for every view.
    static s8 active_view;

    static void reset_up_vector();
    static void clear_pose_snap_flags();
    static s32 is_view_offset();
    // Bit 0x400 of view_state.flags.
    static s32 is_view_override_active();
    // The active controller's registry index.
    static u16 get_active_controller();

    static s32 get_camera_mode();
    static void copy_vec_to_default(const Vec *up);
    static void sync_split_view_slots(s32 view, s32 all_views);
    static s32 get_split_screen_view_index(u16 id);
    static u16 get_nth_view_player_id(s32 n);
    static f32 get_split_offset(s32 view);
    // The horizontal counterpart of get_split_offset: split views are never
    // shifted sideways.
    static f32 get_split_offset_x(s32 view);
    static void set_fullscreen_viewport();
    static void set_split_viewport(s32 views, s32 view);
    static f32 get_fov();
    static f32 get_view_scale();
    static void restore_full_screen_view();
    // Puts back the view restore_full_screen_view saved, after a full-screen 2D pass.
    static void restore_saved_view();
    static u16 get_camera_target_id(s32 view);
    static void apply_split_screen_view_matrix();
    static const f32 (*get_view_matrix())[4];
    static void create();
    static void reset_default_view();
    static void init_default_view();
    static void reset_viewport_scissor();
    Vec *get_target();
    // The controller driving the view is passed along but not read.
    void resolve_anchor_obstruction(TCameraController *controller);
    void clamp_to_target_obstruction(TCameraController *controller);
    void update_target_smoothing();
    void update_position();
    void update_pose_smoothing();
    static s32 release_photon_blast_camera();
    void reset_view_flags();
    CameraParams *get_params();
    // The eye and target of split-screen view `view`.
    Vec *get_split_pos(s32 view);
    Vec *get_split_tgt(s32 view);
    static void set_shake_preset(s32 preset);
    void cycle_spectate_target();
    // The viewport origin, which projected points are made view-relative by.
    static s32 get_viewport_y();
    static s32 get_viewport_x();
    static int get_mode();
    // The mode word at 0x1C of `p` (the main task).
    static s32 get_mode(void *p);
    // Transforms the vector at src into view space, into dst.
    static void transform_to_view(const Vec *src, Vec *dst);
    static s32 get_camera_no();
    static void set_mode(int mode);
    static void reset_mode();
    static void set_camera_id(int id);
    // The one view split-screen frames run and draw, or -1 for every view.
    static s8 get_view_state();
    static void reset_view_state();
    static void reset();
    static void select_active_controller(s8 index);
    static CameraMatrix *copy_view_params(CameraMatrix *dst, const CameraMatrix *src);
    static void calc_axes_from_angles(saddr unused_angle, saddr pitch, saddr yaw);
    // Views on screen: 1, or 2 to 4 in a split-screen game.
    static int get_view_count();
    static int get_camera_id();
    static void set_target_coords(int x, int y);
    static void reset_battle_camera();
    static void set_target(int width, int height);
};

LAYOUT_ASSERT(TCameraCtrl_size, sizeof(TCameraCtrl) == 0x1D4);
// The camera's right axis, which screen tests offset points along.
extern Vec camera_right;
// The camera's up axis after the pitch rotation (calc_rotated_axes).
extern Vec camera_pitch_rotated_up_vector;
// The camera task; NULL until TCameraCtrl::create makes it.
extern TCameraCtrl *camera_ctrl_instance;
// One controller per registry slot, made by the constructor.
extern TCameraController *camera_controller_registry[13];
// The Ninja camera the view matrix is built from each frame: the camera
// position and the direction to its target.
extern NJS_CAMERA ninja_camera;

// Makes registry controller `index` the active one.
void select_camera_controller(s32 index);
// Fixes the view at position, looking at target (quest leti_fixed_camera).
void set_fixed_camera(const Vec *position, const Vec *target);
// Points every controller of the actor's view at the actor.
void reset_cameras_to_actor(TObjPlayer *actor, s32 view_unused);

int is_quest_active();
// Nonzero when value is a NaN or an infinity.
int is_float_nonfinite(f32 value);

extern "C" {
const CharacterSelectionRequest *get_character_select_request_buffer();
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
