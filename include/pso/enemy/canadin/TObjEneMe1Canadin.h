#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLight.h"
#include "pso/system/NinjaTypes.h"

class TObjEneMe1Canadin_EffLine;
class TParticleCtrl;

// What TObjEnemy::movementParameters points at for the Canadin (MojaMovementParameters layout).
struct TObjEneMe1CanadinMovement {
    f32 target_range;
    f32 move_speed;
    s32 turn_speed;
    u32 unknown_0C[4];
};

// The kind's parameter block (kind_params, from TLobby::dispatch_shared_handler_a); the field layout is
// shared with TObjEneMe1GeeParams.
struct TObjEneMe1CanadinParams {
    f32 melee_speed;          // chase step of the melee attack
    f32 ranged_power;         // power of the discharge (deliver_discharge_attack)
    f32 self_destruct_power;  // power of the self-destruct blast
    u8 pad_c[0xC];
    s32 aim_time;             // ranged attack: frames the beam tracks the target
    s32 fire_delay;           // ranged attack: frames from the end of the aim to the discharge
    s32 shot_interval;        // ranged attack: frames after a shot before the next aim
    s32 shots_per_attack;     // ranged attack: shots before the attack ends
    s32 hurt_wait_time;       // hurt state: frames of the last stage
    s32 group_size;           // members per attack group (spawn_members, remove_member)
};

struct TObjEneMe1Canadin : public TObjEneDD_ST {
    TObjEneMe1Canadin(TObject *parent, void *set_data, s32 kind);
    TObjEneMe1Canadin(TObject *parent, TObjEneMe1Canadin *leader, Vec *pos, s32 id, s32 sub_id);
    virtual ~TObjEneMe1Canadin();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual s32 acquire_target(f32);
    virtual void update_body_colliders();
    virtual CsnHit *move_xz_on_ground(const Vec *);
    virtual void check_collisions();
    virtual void select_next_attack_state();
    virtual void select_model();
    virtual void spawn_members();
    virtual s32 check_retreat_trigger();
    virtual int has_no_members();
    virtual void state_activate(s32);
    virtual void state_rise(s32);
    virtual void state_dead(s32);
    virtual void apply_model_color();
    virtual void run_demo_task();
    virtual void render_demo();
    virtual int can_member_attack_target(TObjChara *);
    virtual void remove_member(TObjEneMe1Canadin *member);
    void run_death_reaction();
    void run_hit_reaction();
    void run_miss_reaction();
    void refresh_target();
    void render();
    TObjEneMe1Canadin *leader;
    s32 kind;
    u32 status_flags;
    TUnk_80494938 fade;
    f32 upper_hover_height;
    f32 hover_height;
    f32 random_hover_height;
    f32 hover_offset;
    f32 hover_y;
    s32 move_action;
    s32 attack_delay;
    s32 attack_count;
    TObjEneMe1Canadin_EffLight *eff_light;  // created in setup_enemy, queued in the dtor
    s32 pad_40c;
    s32 alt_model_color;
    Vec node_points[7];
    TObjEneMe1CanadinParams *kind_params;
    s32 attack_pattern;
    s32 stage;
    s32 stage_timer;
    s32 stage_counter;
    s32 pad_47c;
    s32 orbit_angle_step;
    // Scratch of the attack states, shared with the TObjEneMe1Gee twin at the same place.
    f32 work_speed;         // melee: approach step; orbit: climb step; hurt: fall speed; move forward: x step
    f32 orbit_radius;       // orbit: radius; melee: climb step; hurt: fall acceleration; move forward: z step
    f32 orbit_radius_step;  // orbit: radius step towards 70
    Vec work_point;         // ranged attack: aim point; orbit: direction from the target
    TObjEneMe1Canadin_EffLine *eff_line;
    TParticleCtrl *particle_emitter;  // queued for destruction in the dtor
    NJS_ARGB core_color;
    s32 core_color_packed;
    s32 fade_mode;
    s32 fade_sequence;
    s32 fade_step_timer;
    s32 fade_cursor;
    u16 leader_id;
    u8 pad_4ca[0x2];
    void state_move_forward(s32 msg);
    void state_motion_test(s32 msg);
    void state_regroup(s32 msg);
    void state_formation(s32 msg);
    void state_hover(s32 msg);
    void state_spawn(s32 msg);
    void pack_color_rgba();
    void set_core_color(const NJS_ARGB *color);
    s32 try_trigger_action();
    void advance_state_4_to_5();
    s32 check_target();
    void update_move();
    void advance_state_5_to_4();
    void calc_move_vector(Vec *out);
    void noop();
    void update_angle();
    void update_upper_hover_height();
    void update_hover_height();
    void approach_upper_hover_height();
    void apply_parameters();
    void copy_pos();
    void run_task();
    void setup_enemy();
    static void *create(void *set_data);
    static void load_resources();
    static void free_resources();
    void state_return_home(s32 msg);
    void state_vanish(s32 msg);
    void state_self_destruct(s32 msg);
    // Entered by run_hit_reaction; back to next_mode once the damage motion ends.
    void hurt_state(s32 msg);
    void state_orbit(s32 msg);
    void state_melee_attack(s32 msg);
    void state_ranged_attack(s32 msg);
    void state_appear(s32 msg);
    s32 is_hover_low();  // hover_offset < 20; gates the melee contact checks (name inferred)
    s32 find_attack_target(f32 *out, f32 squared_range);
    void clear_melee_body_flags();
    void set_melee_body_flags();
    void release_from_formation();
    void order_attack();
    s32 has_status_flag(s32 mask);
    void set_out_fighter();
    void set_in_fighter();
    int is_activated();
    void start_fade_sequence(s32 sequence);
    void deliver_discharge_attack(Vec *pos);
    void order_activation_now();
    TObjChara *get_attacking_target();  // current_target while status 0x40000 (set by the attack states) is on, else NULL; the leader counts members on its target (name inferred)
    void wake_leader();
    void hover_toward(f32 height);
    void approach_hover_y(f32 height);
    void set_flag3c8_bit40();
    void set_flag3c8_bit20();
    void set_flag3c8_bit8();
    void start_formation();
    void order_activation(TObjChara *target, s32 delay);
    void update_fade_sequence();
};

// Stat ids of the three kinds (CanadinData); load_resources registers them with TLobby.
extern const u32 canadin_base_stat_ids[3];
extern const u32 canadin_attack_stat_ids[3];
extern const u32 canadin_resist_stat_ids[3];
extern const u32 canadin_param_ids[3];

LAYOUT_ASSERT(TObjEneMe1Canadin_size, sizeof(TObjEneMe1Canadin) == 0x4CC);

extern "C" {
void canadin_capture_node_points(NJS_OBJECT *);
}

#endif
