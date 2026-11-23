#ifndef PSO_OBJECT_WARP_TOBJCITYMAINWARPCHALLENGE_H
#define PSO_OBJECT_WARP_TOBJCITYMAINWARPCHALLENGE_H

#include "types.h"
#include "pso/object/warp/TObjAreaWarp.h"

struct AnimationMotion;

struct TObjCityMainWarpChallenge : public TObjAreaWarp {
    TObjCityMainWarpChallenge(TObject *parent, void *set_data);
    virtual ~TObjCityMainWarpChallenge();
    void sub_801875F8();
    void close_windows();
    virtual void debug_print_area_num();
    void count_players_in_warp_radius();
    void update_challenge_state();
    void update_warp_sequence();
    void trigger_warp_effect(s32);
    void send_6x6A_set_boss_warp_flags(u16);
    s32 are_all_players_in_range();
    f32 frame;  // motion frame: run_task steps it by 4 and wraps at the motion's frame count
    u8 pad_c8[0x8];
    s32 model;                // city common model 0 (draw_ginja_model_with_motion)
    AnimationMotion *motion;  // city common motion 5
    u8 _padD8[0x4];
    s16 next_state;
    s16 state;
    s16 state_step;   // step inside state: update_state runs once with -1 to leave it, then from 0 (run_task)
    s16 state_flags;  // bit 0: run_task does not switch state to next_state while it is set
    char player_names[4][0x18];
    s32 player_in_range[4];
    s32 player_count;
    s32 players_in_range;
    s32 player_on_dest_floor;
    s32 warp_countdown;  // 300 when the warp sequence starts; at 0 it warps without waiting for every player
    void *player_list_window;
    void *yes_no_window;
    s32 key_id;  // set_params[1] if 0..0xFF, else -1 ("<- KEY ID : %d")
    void update_state();
    void render();
    void run_task();
    s32 warp_triggered;     // 1 once trigger_warp_effect ran for the local player in this state
    s32 warp_effect_timer;  // 300 when trigger_warp_effect starts the player's warp effect
    u8 unk_178[0x8];
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCityMainWarpChallenge_size, sizeof(TObjCityMainWarpChallenge) == 0x180);
LAYOUT_ASSERT(TObjCityMainWarpChallenge_m_d0, offsetof(TObjCityMainWarpChallenge, model) == 0xD0);
LAYOUT_ASSERT(TObjCityMainWarpChallenge_warp_effect_timer, offsetof(TObjCityMainWarpChallenge, warp_effect_timer) == 0x174);


#endif
