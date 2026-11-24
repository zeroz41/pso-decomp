#ifndef PSO_ENEMY_MORFOS_TOBJENEMORFOS_H
#define PSO_ENEMY_MORFOS_TOBJENEMORFOS_H

#include "types.h"

struct BmlResource;
struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/render/TUnk_80494938.h"

class TObject;
class TParticleCtrl;

// The Morfos row TLobby::dispatch_shared_handler_a returns (TObjEneMorfos__param_table).
struct MorfosParams {
    f32 projectile_speed;    // copied to morfos_projectile_speed
    f32 projectile_speed_b;  // copied to morfos_param_table_speed_copy
    u8 pad_8[0x10];
    s32 turn_step;           // approach_value step while walking (state 4)
    s32 attack_turn_step;    // approach_value step of the attack states, the burst's turn per shot
    s32 retreat_wait;        // frames state 6 waits before it turns back
    s32 charge_frames;       // frames the burst spins before it fires
    s32 charge_spin_step;    // rotation the burst adds per charging frame
};

struct EnemyPlacement;

struct TObjEneMorfos : public TObjEneDD_ST {
    TObjEneMorfos(TObject *parent, EnemyPlacement *set_data);
    virtual ~TObjEneMorfos();
    virtual f32 receive_physical_attack(void *attacker, f32 scale);
    virtual void dispatch_action(u32 state, s32 reason);
    s32 render_model_if_visible();
    virtual void refresh_target();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void update_body_colliders();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual void render();
    virtual void run_task();
    u32 morfos_flags;         // 1 hidden, 2 fading out, 4 hits only clear, 0x10 wall raised, 0x20 wall broken
    u32 ground_attributes;    // first word of the collision face under it (0x4000: no shadow)
    Vec reflection_point;     // push_reflection_matrix mirrors the body about it
    s32 texture_scroll;       // 0..12, scrolls the body and wall textures each frame
    f32 walk_speed;           // 0.28 + parameters[0]: walk step and walk_timer increment
    f32 walk_duration;        // 20 + parameters[1]: walk_timer limit
    f32 wall_chance;          // check_low_hp_trigger's roll for raising the wall (flag 0x10)
    f32 burst_chance;         // try_enter_low_hp_state's roll for the burst (state 9)
    s32 can_walk;             // variant <= 0
    TUnk_80490470 body_fade;
    TUnk_80494938 wall_fade;  // draw_body fades the wall model with it
    RenderFadeState part_fades[4];
    TParticleCtrl *burst_emitter; // the burst's charge particles
    Vec node_points[2];       // record_camera_path_point stores two model nodes here
    static BmlResource *get_instance();
    void draw_body();
    static void record_camera_path_point(NJS_OBJECT *);
    static void load_static_data();  // the floor table's loader, paired with unload_static_data
    void state_death(s32 ev);
    void state_patrol(s32 ev);
    void state_appear(s32 ev);
    void handle_event_transition(s32 ev);
    void play_sound_in_band();
    void init_target_offsets();
    void set_hover_target_position();
    s32 approach_value(s32 goal, s32 max_step);
    s32 try_enter_low_hp_state();
    s32 check_low_hp_trigger();
    void init_instance();
    static void unload_static_data();
    static void *create(void *set_data);
    static s32 snap_to_ground(s32 arg0, saddr origin);
    // The state handlers dispatch_action picks (names from the motions they request).
    void state_damage(s32 ev);    // 10: damage_kabe_body
    void state_attack(s32 ev);    // 5: attack_kabe_body, spawns the arm
    void state_beam(s32 ev);      // 6: beam_kabe_body, fires TUnk_804EF130 shots
    void state_walk(s32 ev);      // 4: turns toward the target and walks
    void state_fade_out(s32 ev);  // 7: no target for 60 frames, fades out
    void state_hidden(s32 ev);    // 2: hidden at home until a target comes in range
    void state_fade_in(s32 ev);   // 1: fades the body and wall in
    s32 check_confused();         // is_confused() as 0/1: holds the state transitions
    void load_params();           // copies the param table's projectile speeds
    Vec *get_arm_point();         // node_points[1]: where TObjEneMorfosArm sits
    s32 get_rotation_y();
    void update_ground_probe();
    static u8 check_value_in_range(void *, u16 start, u16 end, u16 value);
    s32 step;                 // state work variables
    s32 counter;
    s32 step_timer;
    s32 target_angle;
    s32 burst_start_angle;    // rotation_y when the burst turn started
    f32 accum;                // walk timer, then the dying texture scroll
    f32 unk_4C8;
    Vec walk_dir;             // sin, 0, cos of rotation_y when the walk starts
    void render_part(s32 idx, s32 mode);
    void state_rotating_projectile_burst(s32 ev);
    s32 select_target_in_view();
};

#include <stddef.h>
LAYOUT_ASSERT(TObjEneMorfos_size, sizeof(TObjEneMorfos) == 0x4D8);
LAYOUT_ASSERT(TObjEneMorfos_fades, offsetof(TObjEneMorfos, body_fade) == 0x3EC);

extern MorfosParams *TObjEneMorfos__param_table;

// What TObjEneMorfos::load_static_data fetches from TLobby; reset_hp reads one entry of each.
extern player_stats *morfos_base_params[1];        // register_boss(0x40)
extern AttackParams *morfos_attack_params[3];      // dispatch_shared_handler_b(morfos_attack_param_ids[i])
extern ActorParamBlock *morfos_resistance_params[1];  // register_object(0x40)
extern const s32 morfos_attack_param_ids[2];
extern const s32 morfos_base_params_index[2];  // the entries reset_hp passes
extern const s32 morfos_attack_params_index[2];
extern const s32 morfos_resistance_params_index[2];
// The body and wall polygon lists run_task scrolls by texture_scroll, once per actor_frame_tick.
extern s16 *morfos_body_scroll_polygons;
extern s16 *morfos_wall_scroll_polygons;
extern s32 morfos_body_scroll_tick;
extern s32 morfos_wall_scroll_tick;

#endif
