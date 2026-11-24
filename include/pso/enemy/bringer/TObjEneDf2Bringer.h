#ifndef PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H
#define PSO_ENEMY_BRINGER_TOBJENEDF2BRINGER_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"

class AreaAttackHistory;
struct BmlResource;
class TUnk_804928CC;
class TObjEneDf2Bringer_Eff_TpAbsorb1;
class TAttackTraceStrip;
class TParticleCtrl;

// The Bringer's tuning row (TLobby::dispatch_shared_handler_a(0xD)).
struct BringerParameters {
    f32 rush_speed;       // the charge's speed, decaying from here once it stops
    f32 walk_speed;       // the approach
    f32 action4_speed;    // play speeds load_resources gives actions 4 and 5
    f32 action5_speed;
    f32 pad_10;
    f32 slash_recover_frames;  // frames update_slash_state waits after the slash
    f32 pad_18;
    s32 stagger_frames;   // a charge that hits something staggers this long
    s32 rush_power;       // the charge's direct-attack power
    s32 shot_speed;       // the shot's speed, raised with the TP drained
    s32 attack_distance;  // closer than this it slashes instead of walking
    s32 rush_distance;    // farther than this it charges
};

struct TObjEneDf2Bringer : public TObjEneDD_ST {
    TObjEneDf2Bringer(TObject *parent, void *set_data);
    virtual ~TObjEneDf2Bringer();
    virtual s32 acquire_target(f32);
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void dispatch_action(u32 state, s32 reason);
    void set_effect_pos_above_self();
    void retarget_attacker();
    void sub_800994F8();
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    void run_task();
    void update_emerge_state(s32 reason);
    void handle_state(s32 reason);
    s32 check_stage_advance();
    void update_death_state(s32 reason);
    void update_damage_state(s32 reason);
    void update_shot_state(s32 reason);
    void update_stagger_state(s32 reason);
    void update_slash_state(s32 reason);
    void update_rush_state(s32 reason);
    void update_walk_state(s32 reason);
    void update_fade_out_state(s32 reason);
    void update_hidden_state(s32 reason);
    void play_move_sound();
    s32 attack_visible_players();
    s32 target_farthest_visible_player();
    s32 update_flag_0x3C0();
    s32 check_rush_hits();
    void update_attack_child();
    void init_enemy();
    static void set_entry_value_clamped(s32 index, f32 speed);
    static void free_resources();
    static void *create(void *set_data);
    static void load_resources();
    static BmlResource *resource_bundle;
    void spawn_offset_particle();
    void spawn_particle_if_in_band();
    void update_if_in_band();
    s32 status_flags;  // bit 0 hidden (init_enemy), 1 body fade, 2 no flinch, 3 hit since the emerge
    TUnk_80490470 body_fade;
    RenderFadeState renderFadeStates[4];
    Vec node_points[4];  // filled by bringer_render_node_callback: sparks [0]/[1], shot [2], TP drain [3]
    s32 twist_angle;     // turns toward the target within +-0x2000; render rotates a node by it
    s32 stagger_timer;   // stagger_frames after a charge hit, counted down
    s32 face_texture;    // texture copied into slot 1: 1, 5 or 6 by hit_count
    s32 combo_count;     // slashes in a row
    s32 rush_count;      // charges since the last slash; the walk charges only below 2
    s32 hit_count;       // hits taken; 5 starts the shot (check_stage_advance)
    TUnk_804928CC *collider;  // built over the Bringer's collision bodies
    AreaAttackHistory *attack_history;
    TObjEneDf2Bringer_Eff_TpAbsorb1 *shot_launcher;
    TAttackTraceStrip *attack_trail;
    s32 texture_scroll;
    s32 step;
    s32 counter;
    s32 drained_tp;      // attack_visible_players
    s32 target_angle;
    f32 speed;           // the charge speed, from rush_speed decaying by 0.95
    f32 pad_4C0;
    TParticleCtrl *emitter;
};

LAYOUT_ASSERT(TObjEneDf2Bringer_size, sizeof(TObjEneDf2Bringer) == 0x4C8);
#endif
