#ifndef PSO_CAMERA_TOBJLIVECAMERACTRL_H
#define PSO_CAMERA_TOBJLIVECAMERACTRL_H

#include "pso/system/task/TObject.h"
#include "pso/system/SubtractiveRng.h"
#include "types.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TLiveCameraView;

// A live camera of the Gol Dragon floor: it picks a random shot every few
// seconds and moves its TLiveCameraView, whose picture the arena's monitors
// show. The camera is switched off while Gol Dragon's live monitor count is
// at or below its slot.
class TObjLiveCameraCtrl : public TObject {
public:
    enum Shot {
        SHOT_NONE,
        // Circle the local player 30 units out, height_offset above them.
        SHOT_PLAYER_ORBIT,
        // From behind the local player, turning with them.
        SHOT_BEHIND_PLAYER,
        // From behind Gol Dragon, turning with it.
        SHOT_BEHIND_BOSS,
        // The arena from 360 units out and 250 up, looking at its centre.
        SHOT_ARENA,
        // The arena entrance, held until Gol Dragon appears.
        SHOT_OPENING
    };

    TObjLiveCameraCtrl(TObject *parent);
    virtual ~TObjLiveCameraCtrl();
    // Turns orbit_angle toward angle, at most 0x280 a call.
    void turn_orbit_toward(int angle);
    virtual void run_task();
    // The three steps run_task calls on this.
    void update_toggle_state();
    void update_live_camera();
    void choose_next_camera_shot();
    // The local player's client id, and the entity id of Gol Dragon's first
    // part: the targets of the player and boss shots.
    u16 get_player_target();
    u16 get_boss_target();
    // Makes the view's picture the current texture.
    void load_view_texture();
    s32 is_enabled();
    // The camera in slot, or NULL. Slots 0 and 1 are accepted, but only
    // slot 0 has room in instances.
    static TObjLiveCameraCtrl *get_instance(s32 slot);

    s16 shot;        // a Shot
    s16 shot_frames; // until the next shot is picked; -1 holds the shot
    s32 enabled;
    u16 target_id;   // the followed player's client id or the boss part's entity id
    u8 pad_26[0x2];
    s32 orbit_angle; // around the followed player or enemy
    s32 orbit_speed;
    f32 height_offset;
    Vec eye;
    Vec target;
    s32 slot;
    TLiveCameraView *view;
    SubtractiveRng rng;

    static s32 next_slot;
    static TObjLiveCameraCtrl *instances[1];
};

LAYOUT_ASSERT(TObjLiveCameraCtrl_eye_offset, offsetof(TObjLiveCameraCtrl, eye) == 0x34);
LAYOUT_ASSERT(TObjLiveCameraCtrl_target_offset, offsetof(TObjLiveCameraCtrl, target) == 0x40);
LAYOUT_ASSERT(TObjLiveCameraCtrl_slot_offset, offsetof(TObjLiveCameraCtrl, slot) == 0x4c);
LAYOUT_ASSERT(TObjLiveCameraCtrl_view_offset, offsetof(TObjLiveCameraCtrl, view) == 0x50);
// create_boss8_demo_objects allocates 0x13C for it.
LAYOUT_ASSERT(TObjLiveCameraCtrl_size, sizeof(TObjLiveCameraCtrl) == 0x13C);

#endif
