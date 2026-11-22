#ifndef PSO_ENEMY_GEE_TOBJENEME1GEE_H
#define PSO_ENEMY_GEE_TOBJENEME1GEE_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/render/TUnk_80494938.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx.h>

struct BmlResource;
struct BmlMotionEntry;
struct TObjMotionAction;
class TParticleCtrl;

// The motion-binding block TLobby::spawn_npc_enemy takes (same layout as
// DelDepthAnimationBinding).
struct GeeAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    u32 unknown_08;
    u16 actionCount;
    u16 unknown_0E;
};

// What TObjEnemy::movementParameters points at for the Gee.
struct GeeMovementParameters {
    f32 unknown_00;
    f32 unknown_04;
    s32 unknown_08;
    u32 unknown_0C[4];
};

struct TObjEneMe1GeeParams {
    f32 m_0;
    f32 m_4;
    u8 unk_8[0x10];
    s32 m_18;
    u8 unk_1c[0x4];
    s32 m_20;
    s32 m_24;
    s32 m_28;
    s32 m_2c;
};

struct TObjEneMe1Gee : public TObjEneDD_ST {
    TObjEneMe1Gee(TObject *parent, TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index);
    TObjEneMe1Gee(TObject *parent, void *set_data, s32 kind);
    virtual ~TObjEneMe1Gee();
    virtual s32 acquire_target(f32);
    virtual void dispatch_action(u32 state, s32 reason);
    void init_state();
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
    virtual void run_demo_task();
    virtual void render_demo();
    virtual int can_member_attack_target(TObjChara *target);
    virtual void remove_member(uaddr);
    virtual void refresh_target();
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    void copy_pos();
    void sub_800CC0C4();
    void approach_hover_y(f32 height);
    void hover_toward(f32 height);
    void update_hover_height();
    void update_upper_hover_height();
    void update_fade_sequence();
    void update_packed_color();
    void destroy_subobj(const NJS_ARGB *color);
    void start_fade_sequence(s32 sequence);
    void sub_800CB60C();
    void sub_800CB5F0();
    void sub_800CB5D4();
    void sub_800CB5B8();
    void set_flag3c8_bit2();
    void state_attack_loop(s32);
    void render();
    void run_task();
    TObjEneMe1Gee *leader;
    s32 kind;
    s32 status_flags;
    TUnk_80494938 fade;
    f32 upper_hover_height;
    f32 hover_height;
    f32 random_hover_height;
    f32 hover_offset;
    f32 hover_y;
    f32 needle_speed;
    f32 climb_speed;
    s32 attack_delay;
    s32 attack_count;
    s32 m_40c;
    s32 alt_model_color;
    Vec node_points[2];
    TObjEneMe1GeeParams *kind_params;
    s32 attack_pattern;
    s32 stage;
    s32 stage_timer;
    s32 stage_counter;
    s32 m_440;
    s32 orbit_angle_step;
    f32 m_448;
    f32 m_44c;
    f32 m_450;
    Vec m_454;
    TObject *eff_line;
    TParticleCtrl *particle_emitter;
    NJS_ARGB core_color;
    s32 core_color_packed;
    s32 fade_mode;
    s32 fade_sequence;
    s32 fade_step_timer;
    s32 fade_cursor;
    u16 leader_id;
    u8 unk_48e[0x2];
    static void load_resources();
    static void cache_result_805D6660();
    static void queue_debug_text(s32 arg0, char *arg1);
    static void advance_camera_ctrl_step(NJS_OBJECT *);
    void state_orbit(s32 msg);
    void handle_event(s32 msg);
    void state_return_home(s32 mode);
    void state_attack(s32 msg);
    void state_hover(s32 mode);
    void state_move(s32 msg);
    void set_flag3c8_bit40();
    void set_flag3c8_bit8();
    void update_photon_target();
    s32 handle_message(s32 id);
    s32 check_death_trigger();
    s32 check_can_attack();
    void update_angle();
    void climb_to_hover_height();
    void approach_upper_hover_height();
    static void free_globals();
    static TObjEneMe1Gee *create(TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index);
    static void *create(void *set_data);
    void set_flag3c8_bit4();
    void set_state_flag(TObjChara *target, s32 arg2);
    void update();
    void sub_800C9580(s32 mode);
    // Entered by run_hit_reaction; back to next_mode once the damage motion ends.
    void hurt_state(s32 mode);
    void sub_800C9964(s32 mode);
    void sub_800C9A94(s32 mode);
    void sub_800C9DF8(s32 mode);
    void sub_800CA454(s32 mode);
    void sub_800CAFD8(s32 mode);
    void sub_800CB4DC();
    void sub_800CB560();
    TObjChara *sub_800CB584();
    s32 has_status_flag(s32 mask);
    int sub_800CB628();
    void sub_800CB968();
    s32 sub_800CBA80();
    s32 find_attack_target(f32 *out, f32 range);
    void sub_800CBC04();
    void sub_800CBC1C();
    void climb_toward(f32 height);
    void climb_hover_y(f32 height);
    void calc_position(Vec *out);
    static BmlResource *sub_800CC2BC();
};

LAYOUT_ASSERT(TObjEneMe1Gee_size, sizeof(TObjEneMe1Gee) == 0x490);
#endif
