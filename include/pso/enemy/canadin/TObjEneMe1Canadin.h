#ifndef PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_H
#define PSO_ENEMY_CANADIN_TOBJENEME1CANADIN_H

#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/enemy/canadin/TObjEneMe1Canadin_EffLight.h"
#include "pso/system/NinjaTypes.h"

class TObjEneMe1Canadin_EffLine;
class TParticleCtrl;

struct TObjEneMe1CanadinMovement {
    f32 m_0;
    f32 m_4;
    s32 m_8;
    s32 m_C;
    s32 m_10;
    s32 m_14;
    s32 m_18;
};

struct TObjEneMe1CanadinParams {
    f32 m_0;
    f32 m_4;
    f32 m_8;
    u8 unk_C[0xC];
    s32 m_18;
    s32 m_1C;
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s32 m_2C;
};

struct TObjEneMe1Canadin : public TObjEneDD_ST {
    TObjEneMe1Canadin(TObject *parent, void *set_data, s32 kind);
    TObjEneMe1Canadin(TObject *parent, TObjEneMe1Canadin *leader, Vec *pos, s32 id, s32 sub_id);
    virtual ~TObjEneMe1Canadin();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual s32 acquire_target(f32);
    virtual void update_body_colliders();
    virtual u8 *move_xz_on_ground(u8 *);
    virtual void check_collisions();
    virtual void select_next_attack_state();
    virtual void select_model();
    virtual void spawn_members();
    virtual s32 check_retreat_trigger();
    virtual int has_no_members();
    virtual void vfunc_110(s32);
    virtual void vfunc_111(s32);
    virtual void state_dead(s32);
    virtual void apply_model_color();
    virtual void update_if_ready();
    virtual void render_canadin_model_with_debug_type();
    virtual int can_member_attack_target(TObjChara *);
    virtual void remove_member(uaddr);
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
    s32 m_40C;
    s32 alt_model_color;
    Vec node_points[7];
    TObjEneMe1CanadinParams *kind_params;
    s32 attack_pattern;
    s32 stage;
    s32 stage_timer;
    s32 stage_counter;
    s32 m_47C;
    s32 orbit_angle_step;
    f32 m_484;
    f32 m_488;
    f32 m_48C;
    Vec m_490;
    TObjEneMe1Canadin_EffLine *eff_line;
    TParticleCtrl *particle_emitter;  // queued for destruction in the dtor
    NJS_ARGB core_color;
    s32 core_color_packed;
    s32 fade_mode;
    s32 fade_sequence;
    s32 fade_step_timer;
    s32 fade_cursor;
    u16 leader_id;
    u8 unk_4CA[0x2];
    void update_by_state(s32 msg);
    void update_walk_animation(s32 msg);
    void run_task(s32 msg);
    void move(s32 msg);
    void action(s32 msg);
    void handle_state(s32 msg);
    void pack_color_rgba();
    void reset_map_core(void *color);
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
    void update_by_field_0x354();
    void copy_pos();
    void run_task();
    void setup_enemy();
    static void *create(void *set_data);
    static void load_resources();
    static void free_resources();
    void fn_8009BFF8(s32 msg);
    void fn_8009C178(s32 msg);
    void fn_8009C2EC(s32 msg);
    // Entered by run_hit_reaction; back to next_mode once the damage motion ends.
    void hurt_state(s32 msg);
    void fn_8009C91C(s32 msg);
    void fn_8009CC74(s32 msg);
    void fn_8009D320(s32 msg);
    void fn_8009DE90(s32 msg);
    s32 fn_8009E76C();
    s32 find_attack_target(f32 *out, f32 squared_range);
    void fn_8009E930();
    void fn_8009E948();
    void fn_8009E258();
    void set_flag3c8_bit4();
    s32 has_status_flag(s32 mask);
    void fn_8009E334();
    void fn_8009E350();
    int fn_8009E36C();
    void start_fade_sequence(s32 sequence);
    void fn_8009E1D4(Vec *pos);
    void fn_8009E2DC();
    TObjChara *fn_8009E300();
    void update_photon_target();
    void hover_toward(f32 height);
    void approach_hover_y(f32 height);
    void set_flag3c8_bit40();
    void set_flag3c8_bit20();
    void set_flag3c8_bit8();
    void set_attack_flag();
    void set_leader_index(TObjChara *target, s32 index);
    void update_fade_sequence();
};

LAYOUT_ASSERT(TObjEneMe1Canadin_size, sizeof(TObjEneMe1Canadin) == 0x4CC);

extern "C" {
void fn_8009BD00(NJS_OBJECT *);
}

#endif
