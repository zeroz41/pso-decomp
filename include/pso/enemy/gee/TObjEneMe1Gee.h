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
    void sub_800CBF58(f32);
    void sub_800CBE6C(f32 y);
    void update_hover_height();
    void update_animation_frame();
    void update_fade_sequence();
    void update_packed_color();
    void destroy_subobj(const NJS_ARGB *color);
    void sub_800CB60C();
    void sub_800CB5F0();
    void sub_800CB5D4();
    void sub_800CB5B8();
    void set_flag3c8_bit2();
    void state_attack_loop(s32);
    void render();
    void run_task();
    TObjEneMe1Gee *m_3c0;
    s32 m_3c4;
    s32 m_3c8;
    TUnk_80494938 fade;
    f32 m_3e8;
    f32 m_3ec;
    f32 m_3f0;
    f32 m_3f4;
    f32 m_3f8;
    f32 m_3fc;
    f32 m_400;
    s32 m_404;
    s32 m_408;
    s32 m_40c;
    s32 m_410;
    Vec m_414[2];
    TObjEneMe1GeeParams *m_42c;
    s32 m_430;
    s32 m_434;
    s32 m_438;
    s32 m_43c;
    s32 m_440;
    s32 m_444;
    f32 m_448;
    f32 m_44c;
    f32 m_450;
    Vec m_454;
    TObject *m_460;
    TObject *m_464;
    NJS_ARGB m_468;
    s32 m_478;
    s32 m_47c;
    s32 m_480;
    s32 m_484;
    s32 m_488;
    u16 m_48c;
    u8 unk_48e[0x2];
    static void load_resources();
    static void cache_result_805D6660();
    static void queue_debug_text(s32 arg0, char *arg1);
    static void advance_camera_ctrl_step(NJS_OBJECT *);
    void state_orbit(s32 arg1);
    void handle_event(s32 arg1);
    void state_return_home(s32 mode);
    void state_attack(s32 arg1);
    void state_hover(s32 mode);
    void state_move(s32 arg1);
    void set_flag3c8_bit40();
    void set_flag3c8_bit8();
    void update_photon_target();
    s32 handle_message(s32 id);
    s32 check_death_trigger();
    s32 check_can_attack();
    void update_angle();
    void update_from_float_sum();
    void set_move_speed_x();
    static void free_globals();
    static TObjEneMe1Gee *create(TObjEneMe1Gee *leader, Vec *pos, u16 id, s32 index);
    static void *create(void *set_data);
    void set_flag3c8_bit4();
    void set_state_flag(TObjChara *target, s32 arg2);
    void update();
    void sub_800C9580(s32 mode);
    void sub_800C96B4(s32 arg1);
    void sub_800C9964(s32 mode);
    void sub_800C9A94(s32 mode);
    void sub_800C9DF8(s32 mode);
    void sub_800CA454(s32 mode);
    void sub_800CAFD8(s32 mode);
    void sub_800CB4DC();
    void sub_800CB560();
    TObjChara *sub_800CB584();
    s32 sub_800CB5A0(s32 mask);
    int sub_800CB628();
    void sub_800CB968();
    s32 sub_800CBA80();
    s32 find_attack_target(f32 *out, f32 range);
    void sub_800CBC04();
    void sub_800CBC1C();
    void sub_800CBDBC(f32 y);
    void approach_target_value(f32 target);
    void calc_position(Vec *out);
    static BmlResource *sub_800CC2BC();
};

LAYOUT_ASSERT(TObjEneMe1Gee_size, sizeof(TObjEneMe1Gee) == 0x490);
#endif
