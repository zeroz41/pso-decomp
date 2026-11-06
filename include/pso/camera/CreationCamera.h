#ifndef PSO_CAMERA_CREATION_CAMERA_H
#define PSO_CAMERA_CREATION_CAMERA_H

#include "types.h"
#include "pso/unk/TUnk_80488A28.h"
#include <stddef.h>

// What the character creation camera is doing (creation_camera_mode).
enum CreationCameraMode {
    // Frame the part of the character the selected menu entry edits.
    CREATION_CAMERA_AUTO,
    // Start close to the finished character and ease back out over 120 frames.
    CREATION_CAMERA_BEGIN_REVIEW,
    CREATION_CAMERA_REVIEW,
    // Drift slowly around the character until a stick or button is used.
    CREATION_CAMERA_IDLE,
    // Turned and zoomed by the player; returns to idle when left alone.
    CREATION_CAMERA_MANUAL
};

// The camera controller of the character creation screens: it circles the
// character at `distance`, looking at `target` from `pitch` and `yaw`.
class CreationCamera : public TUnk_80488A28 {
public:
    f32 distance;
    s32 pitch;
    s32 yaw;
    // The framing the menu wants (0 whole body, 1 face, 2 wide) and how long
    // the selected entry has asked for another one.
    s32 shot;
    s32 shot_timer;
    f32 review_start_distance;
    s32 timer;
    f32 distance_speed;
    f32 height_speed;

    CreationCamera();
    virtual ~CreationCamera();
    virtual void run_task();

    void calc_spherical_camera_position();
    void approach_target(s32 pitch, s32 yaw, f32 distance, f32 height);
    void update_idle();
    void advance_review();
    void begin_review();
    void frame_menu_selection();
    void update_auto();
    void advance_manual();

    static CreationCamera *create();
};
typedef char CreationCamera_size[sizeof(CreationCamera) == 0x90 ? 1 : -1];
typedef char CreationCamera_distance[offsetof(CreationCamera, distance) == 0x6C ? 1 : -1];

extern s32 creation_camera_mode;
// How far the creation view is shifted aside for an open panel (0 to 1).
extern f32 creation_view_shift;

void set_creation_projection_center(f32 shift);
void begin_creation_view();
void end_creation_view();
u32 get_character_creation_selected_entry_id();
char *get_split_screen_character_name();

#endif
