#ifndef PSO_OBJECT_WARP_TOBJWARPBOSS_H
#define PSO_OBJECT_WARP_TOBJWARPBOSS_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"
#include <stddef.h>

struct AnimationMotion;
struct NJS_OBJECT;

// Same field layout as TObjCityMainWarpChallenge up to 0x178.
struct TObjWarpBoss : public TObjAreaWarp {
    TObjWarpBoss(TObject *parent, void *set_data);
    virtual ~TObjWarpBoss();
    void close_windows();
    void update();
    virtual void debug_print_area_num();
    void update_warp_dialogs();
    void update_warp_occupants();
    void update_warp_state();
    void update_state();
    void warp_boss_handle_window();
    void update_floor_switch_state();
    void warp_player(s32);
    void send_cmd_6A(u16);
    s32 are_all_players_in_range();
    s32 sub_8019E418();
    void update_warp_boss_visibility();
    void update_warp_confirmation();
    void render();
    void run_task();
    static void *create(void *set_data);
    f32 frame;  // motion frame: run_task steps it by 4 and wraps at the motion's frame count
    u8 pad_c8[0x8];
    NJS_OBJECT *model;        // optional animated warp model
    AnimationMotion *motion;  // get_boss_warp_motion / get_boss_warp_bml_motion
    u8 pad_d8[0x4];
    s16 next_state;
    s16 state;
    s16 state_step;   // step inside state: update runs once with -1 to leave it, then from 0 (run_task)
    s16 state_flags;  // bit 0: run_task does not switch state to next_state while it is set
    char player_names[4][0x18];
    s32 player_in_range[4];
    s32 player_count;
    s32 players_in_range;
    s32 player_on_dest_floor;
    s32 warp_countdown;  // 300 when the warp state starts; at 0 it warps without waiting for every player
    void *player_list_window;
    void *yes_no_window;
    s32 key_id;             // set_params[1] if 0..0xFF, else -1 ("<- KEY ID : %d")
    s32 warp_triggered;     // 1 once warp_player ran for the local player in this state
    s32 warp_effect_timer;  // 300 when warp_player starts the player's warp effect
    u8 pad_178[0x4];
    s32 state_timer;            // 150 when update_state starts; at 0 it moves on without a player
    s32 local_player_in_range;  // the local player stands within warp_range + 25 (update_warp_occupants)
};

LAYOUT_ASSERT(TObjWarpBoss_size, sizeof(TObjWarpBoss) == 0x184);
LAYOUT_ASSERT(TObjWarpBoss_model, offsetof(TObjWarpBoss, model) == 0xD0);
LAYOUT_ASSERT(TObjWarpBoss_local_player_in_range, offsetof(TObjWarpBoss, local_player_in_range) == 0x180);
#endif
