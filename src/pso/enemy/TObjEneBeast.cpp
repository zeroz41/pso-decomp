#include "pso/unk/TUnk_80494968.h"
#include "types.h"
#include "pso/enemy/TObjEneBalClaw.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneBalClawClaw.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
#include "pso/object/TObjMotion.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"

#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TLobby.h"

#include <stddef.h>
extern "C" {
void obj_clearFlags30__8TObjBaseFUl(void *, u32);
void obj_setFlags30(void *, u32);
void advance_animation_playback(void *);
s32 post_translate_matrix(void *);
s32 draw_chunk_object(s32);
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 rotate_matrix_y(s32, s32);
s32 translate_matrix(s32, f32, f32, f32);
s32 push_matrix();
s32 pop_matrix();
s32 set_global_param__8TObjFishFl(s32);
s32 defer_render__7TObjectFv(void *);
extern s32 model_render_flags;
void play_sound_effect(int, void *, int, int);
}
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/misc/RenderFadeState.h"
struct Stack_80091E08 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};
struct RecoveredGlobal_80091E08_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
struct Vec_80091EA4 { f32 x, y, z; };
struct VBase_80091EA4 { char pad[0x18]; };
struct VObj_80091EA4 : VBase_80091EA4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec_80091EA4 *, Vec_80091EA4 *);
};
struct Obj_80091EA4 {
    u8 pad0[0x38];
    Vec_80091EA4 pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 state;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x3A8 - 0xC4];
    VObj_80091EA4 *effects[2];
};
struct VBase_14 { char pad[0x14]; };
struct VObj_14 : VBase_14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    u32 pad18;
};
struct VBase_18 { char pad[0x18]; };
struct VObj_18 : VBase_18 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual s32 m9(f32, f32, f32);
};
struct Vec_8009211C { f32 x, y, z; };
struct Obj_8009211C : VObj_18 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    Vec_8009211C f2FC;
    u8 pad308[0x326 - 0x308];
    s16 f326;
    u8 pad328[0x380 - 0x328];
    f32 f380;
    u8 pad384[0x3B0 - 0x384];
    VObj_14 fades[4];
};
extern "C" {
s32 init_collision_body_parts(void *, void *, int);
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 push_matrix_from(void *);
extern RecoveredGlobal_80091E08_lbl_8058D490 identity_matrix;
void mult_vec_array__10TObjPlayerFUll(int, u32, void *, int);
void set_matrix_identity(u8 *arg0);
extern void *beast_claw_trail_instance;
extern void *boss4_type3_instance;
s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 update__15RenderFadeStateFv(void *);
extern s32 saved_model_render_flags;
#define play_sound_effect (*(s32 (*)(s32, s32, s32, s32))&play_sound_effect)
extern "C" void render_shadows__9TObjEnemyFv(u8 *arg0);
void TObjEneBeast::vfunc_101() {  }
void TObjEneBeast::vfunc_99() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4003E431, arg0 + 0x38, 0, 0);
}
void TObjEneBeast::vfunc_98() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4003AB2D, arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
}
void TObjEneBeast::vfunc_97() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4003A32E, arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}
void TObjEneBeast::vfunc_96() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4003A62F, arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}
void TObjEneBeast::vfunc_95() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4003A82C, arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
}

void TObjEneBeast::vfunc_94() {
    typedef char sp8_offset[(offsetof(Stack_80091E08, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80091E08, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80091E08, sp10) == 0x8) ? 1 : -1];
    Stack_80091E08 stack;
    stack.sp8 = 0.0f;
    stack.spC = 1e+01f;
    stack.sp10 = 0.5f * *(f32 *)(this->m_2b0 + 0x10);
    push_matrix_from(&identity_matrix.value);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, &stack.sp8, &stack.sp8);
    pop_matrix();
    vec3_add_to(&stack.sp8, (u8 *)&this->position);
    ((TObjPlayer *)(&stack.sp8))->spawn_effect_at_ground(0x23);
    TObjPlayer::spawn_dead_spot_type2((s32)&stack.sp8, 0xF);
}

void TObjEneBeast::vfunc_93() {
    Obj_80091EA4 *self = (Obj_80091EA4 *)this;
    Vec_80091EA4 dir;
    Vec_80091EA4 pos;
    u32 entry;
    s32 idx;
    VObj_80091EA4 *eff;
    if (this->frame < 12.0f) {
        switch (this->requested_action) {
        case 3:
            entry = TObjPlayer::lookup_entry_by_value(beast_claw_trail_instance, this->frame);
            idx = 0;
            break;
        case 4:
            entry = TObjPlayer::lookup_entry_by_value(boss4_type3_instance, this->frame);
            idx = 1;
            break;
        default:
            entry = 0;
            break;
        }
        if (entry != 0) {
            push_matrix();
            set_matrix_identity(0);
            post_translate_matrix(&self->pos);
            rotate_matrix_y(0, this->rotation_y);
            mult_vec_array__10TObjPlayerFUll(0, entry, &pos, 2);
            pop_matrix();
            eff = self->effects[idx];
            if (eff != NULL) {
                eff->m4(&pos, &dir);
            }
        }
    }
}

void TObjEneBeast::select_subtype() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x334);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)arg0 + 0x334) = 0;
    } else if (temp_r0 > 2) {
        *(s32 *)((s8 *)arg0 + 0x334) = 2;
    }
    switch (*(s32 *)((s8 *)arg0 + 0x334)) {
    case 2:
        *(s32 *)((s8 *)arg0 + 0x368) = 1;
        ((TObjEnemy *)arg0)->set_param(0xB);
        return;
    case 1:
        *(s32 *)((s8 *)arg0 + 0x368) = 2;
        ((TObjEnemy *)arg0)->set_param(0xA);
        return;
    default:
        *(s32 *)((s8 *)arg0 + 0x368) = 0;
        ((TObjEnemy *)arg0)->set_param(9);
        return;
    }
}
void TObjEneBeast::vfunc_83() {
    u8 *arg0 = (u8 *)this;
    switch (*(s16 *)((s8 *)arg0 + 0x328)) {
    case 0:
    default:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x390) != 1) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
        } else {
            *(s16 *)((s8 *)arg0 + 0x328) = 1;
            *(s16 *)((s8 *)arg0 + 0xB8) = 0xB;
            ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x0A000000);
            obj_setFlags30(arg0, 0x04000000);
            play_sound_effect(0x4003AB32, (s32)(arg0 + 0x38), 0, 0);
        }
        break;
    case 1:
        if ((u32) *(u32 *)((s8 *)arg0 + 0xB4) != 0x20U) {
            *(s16 *)((s8 *)arg0 + 0x328) = 2;
            *(s32 *)((s8 *)arg0 + 0x390) = 0;
            *(s16 *)((s8 *)arg0 + 0xB8) = 0;
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 0x0A000000);
            obj_clearFlags30__8TObjBaseFUl(arg0, 0x04000000);
        }
        break;
    case 2:
        *(s16 *)((s8 *)arg0 + 0x326) = 1;
        break;
    }
    advance_animation_playback(arg0);
}
void render__12TObjEneBeastFPv(Obj_8009211C *o) {
    s32 drawMode;
    s32 fade;
    s32 cam;
    s32 doDraw;

    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    drawMode = o->m9(2e+02f, 4e+02f, 3e+01f);
    if (drawMode == 0) {
        return;
    }
    fade = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        fade = (s32)&o->fades[cam];
        update__15RenderFadeStateFv((void *)fade);
        fade = ((RenderFadeState *)fade)->updateFromCamera((const f32*)(&o->f2FC));
    }
    saved_model_render_flags = model_render_flags;
    select_actor_lighting(o);
    set_global_param__8TObjFishFl(o->f24);
    push_matrix();
    translate_matrix(0, 0.0f, o->f380, 0.0f);
    post_translate_matrix(o->f38);
    rotate_matrix_y(0, o->f60);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(o->f34);
    } else {
        TObjPlayer::toggle_particle_effect();
        doDraw = 1;
        if (fade != 0) {
            o->fades[cam].m6();
            if (defer_render__7TObjectFv(o) != 0) {
                doDraw = 0;
            }
        }
        if (doDraw != 0) {
            if (drawMode == 1) {
                ((TObjMotion *)o)->draw();
            } else {
                ((TObjEnemy *)o)->draw_motion_model();
            }
        }
        TParticleCtrl::end_effect_render();
        if (fade != 0) {
            o->fades[cam].m7();
        }
    }
    pop_matrix();
    restore_scene_lighting();
    if (o->f326 >= 10 || o->f326 < 8) {
        Vec_8009211C v;
        v.x = 1.5f;
        v.y = 1.0f;
        v.z = 2.0f;
        ((TObjEnemy *)o)->render_with_position_override((u8 *)&v, 0);
    }
}

}

#undef clear_attack_flag__14TObjEneBalClawFv
#undef TObjEneBalClawClaw__sub_80090824
#undef rotate_matrix_y
#undef pop_matrix
#undef sub_80090798__18TObjEneBalClawClawFv
#undef update_drop__18TObjEneBalClawClawFPv
#undef update_move_to_target__18TObjEneBalClawClawFPv
#undef update_follow_parent__18TObjEneBalClawClawFPv
#undef sub_80090D3C__18TObjEneBalClawClawFv
#undef TObjEneBalClawClaw__sub_80090ECC
#undef TObjEneBalClawClaw__sub_80091134
#undef TObjEneBalClawClaw__sub_80091200
#undef update_chase__18TObjEneBalClawClawFPv
#undef push_matrix
#undef post_translate_matrix
#undef obj_clearFlags30__8TObjBaseFUl
#undef obj_setFlags30
#undef advance_animation_playback
#undef play_sound_effect
#undef translate_matrix
#undef set_global_param__8TObjFishFl
#undef draw_chunk_object
#undef update_if_active__15TObjEneMe1GiGueFl
#undef TObjEneBalClawClaw__sub_800914A4
#undef find_active_entity_by_id
#undef reset_active_state__18TObjEneBalClawClawFPv

#include "types.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/enemy/TObjEneSaver.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/misc/obj_band.h"
#include "pso/object/TObject_80019A50.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();

extern "C" void vfunc_101__12TObjEneBeastFv();
extern "C" void test_flag_256__13TUnk_80493450Fv();
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEnePanarms.h"

struct Ent_8009241C { u8 pad0[0xC]; f32 radius; u8 pad10[0x2C - 0x10]; };
struct Mdl_8009241C { u8 pad0[8]; s32 f8; s32 fC; };
struct Mot_8009241C { u8 pad0[4]; s32 f4; };
struct Data_8009241C { u8 pad0[0x42C]; Mdl_8009241C *f42c; Mot_8009241C *f430; };
struct Quad_8009241C { s32 a; s32 b; s32 c; s32 d; };
struct Ids_8009241C { s16 id[3]; };

struct O_80092724 { u8 pad0[0x18]; void *vptr; u8 pad1c[0x38c]; void *objs[2]; };

extern "C" {
void *__dt__13TUnk_80493450Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, int, int);
extern u8 __dt__15RenderFadeStateFv[];
O_80092724 *TObjPlayer__sub_80092724(O_80092724 *arg0, s16 arg1);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_resource_from_descriptor(void *, int, void *, int, int, int);
u8 *load_enemy_bml_resource_named(void *, void *);
void draw_trail_with_colors(u8 *boss4_type3, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
u8 *init_trail_buffer__11TBoss4Type3FPvifff(void *, int, f32, f32, f32);
void *mem_alloc(u32 size);
s32 spawn_npc_enemy__6TLobbyFslllff(int, s32, s32, Quad_8009241C *, f32, f32);
extern Ids_8009241C lbl_80439D68[];
extern Quad_8009241C lbl_80439D70[];
extern s32 lbl_80439D80[];
void TLobby__sub_8001FE7C(void*, int);
void *__ct__11TObjControlFP7TObject(void *, void *);
s32 *__dt__11TBoss4Type3FPvs(s32 *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);
void mem_free(void*);

extern void *tl_04;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_99__12TObjEneBeastFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_100__13TUnk_80493450Fv();
extern "C" void vfunc_89__13TUnk_80493450Fv();
extern "C" void update_turn_toward_target__13TUnk_80493450Fv();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUcf();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void vfunc_59__13TUnk_80493450Fv();
extern "C" void beast_idle_update__13TUnk_80493450Fv();
extern "C" void beast_retire_corpse__13TUnk_80493450Fv();
extern "C" void beast_select_target();
extern "C" void vfunc_60__13TUnk_80493450Fv();
extern "C" void beast_update_approach__13TUnk_80493450Fv();
extern "C" void beast_update_attack__13TUnk_80493450Fv();
extern "C" void beast_update_dead__13TUnk_80493450Fv();
extern "C" void beast_update_group_chase__13TUnk_80493450Fv();
extern "C" void beast_update_hurt__13TUnk_80493450Fv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFPl();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void vfunc_61__13TUnk_80493450Fv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_62__13TUnk_80493450Fv();
extern "C" void enter_state_8__10TObjPlayerFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" u8 beast_body_model_filename[];
extern "C" u8 beast_red_body_model_filename[];
extern "C" u8 beast_super_red_body_model_filename[];
extern "C" u8 beast_appear_motion_filename[];
extern "C" u8 beast_attack_left_motion_filename[];
extern "C" u8 beast_attack_right_motion_filename[];
extern "C" u8 beast_damage_motion_filename[];
extern "C" u8 beast_deadb_motion_filename[];
extern "C" u8 beast_dead_motion_filename[];
extern "C" u8 beast_leader_motion_filename[];
extern "C" u8 beast_mihari_motion_filename[];
extern "C" u8 beast_run_motion_filename[];
extern "C" u8 beast_stund_motion_filename[];
extern "C" u8 beast_wakeup_motion_filename[];
extern "C" u8 beast_walk_motion_filename[];
extern "C" u8 beast_bml_filename[];
extern "C" void vfunc_95__12TObjEneBeastFv();
extern "C" void vfunc_97__12TObjEneBeastFv();
extern "C" void vfunc_98__12TObjEneBeastFv();
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();

extern "C" void request_stand_action__13TUnk_80493450Fv();
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void run_task__13TUnk_80493450Fv();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void vfunc_96__12TObjEneBeastFv();
extern "C" void vfunc_94__12TObjEneBeastFv();
extern "C" void update_movement_status__13TUnk_80493450Fv();
extern "C" void tick_freeze_state__10TObjPlayerFv();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__13TUnk_80493450Fv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *player);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" void vfunc_83__12TObjEneBeastFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *player);
extern "C" void vfunc_93__12TObjEneBeastFv();
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *player);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *beast_model_name_table[4];
extern void *beast_motion_name_table[13];
void *beast_model_name_table[4] = {
    (void *)&beast_body_model_filename, (void *)&beast_red_body_model_filename, (void *)&beast_super_red_body_model_filename, (void *)0x0,
};
void *beast_motion_name_table[13] = {
    (void *)&beast_appear_motion_filename, (void *)&beast_attack_left_motion_filename, (void *)&beast_attack_right_motion_filename, (void *)&beast_damage_motion_filename,
    (void *)&beast_deadb_motion_filename, (void *)&beast_dead_motion_filename, (void *)&beast_leader_motion_filename, (void *)&beast_mihari_motion_filename,
    (void *)&beast_run_motion_filename, (void *)&beast_stund_motion_filename, (void *)&beast_wakeup_motion_filename, (void *)&beast_walk_motion_filename,
    (void *)0x0,
};
void *beast_resource_descriptor[4] = {
    (void *)&beast_bml_filename, (void *)&beast_model_name_table, (void *)&beast_motion_name_table, (void *)0x3000c,
};
void *beast_action_table[48] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20000, (void *)0x7, (void *)0x3f19999a, (void *)0x20,
    (void *)0x10002, (void *)0xb, (void *)0x3f000000, (void *)0x1,
    (void *)0x20000, (void *)0x1, (void *)0x3f266666, (void *)0x4,
    (void *)0x20000, (void *)0x2, (void *)0x3f59999a, (void *)0x4,
    (void *)0x10000, (void *)0x8, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x3, (void *)0x3fc00000, (void *)0x8,
    (void *)0x20000, (void *)0xa, (void *)0x3f4ccccd, (void *)0x20,
    (void *)0x30000, (void *)0x5, (void *)0x3f19999a, (void *)0x10,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x20000, (void *)0x6, (void *)0x3f19999a, (void *)0x20,
    (void *)0x20000, (void *)0x0, (void *)0x3f000000, (void *)0x20,
};
void *beast_movement_params[21] = {
    (void *)0x43610000, (void *)0x3ecccccd, (void *)0x400, (void *)0x0,
    (void *)0x1e0000, (void *)0x1, (void *)0x0, (void *)0x437a0000,
    (void *)0x3f0ccccd, (void *)0x400, (void *)0x0, (void *)0x1e0000,
    (void *)0x1, (void *)0x0, (void *)0x43960000, (void *)0x3f333333,
    (void *)0x400, (void *)0x0, (void *)0x1e0000, (void *)0x1,
    (void *)0x0,
};
void *beast_collision_body_table[33] = {
    (void *)0x0, (void *)0x41480000, (void *)0x0, (void *)0x40e00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41480000, (void *)0x0, (void *)0x40e00000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x41000000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *__vt__12TObjEneBeast[103] = {
    (void *)0x0, (void *)0x0, (void *)&TObjPlayer__sub_80092724, (void *)&run_task__13TUnk_80493450Fv,
    (void *)&render__12TObjEneBeastFPv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&beast_select_target, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__13TUnk_80493450Fv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__13TUnk_80493450Fv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__13TUnk_80493450Fv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&tick_freeze_state__10TObjPlayerFv, (void *)&vfunc_59__13TUnk_80493450Fv,
    (void *)&vfunc_60__13TUnk_80493450Fv, (void *)&vfunc_61__13TUnk_80493450Fv, (void *)&vfunc_62__13TUnk_80493450Fv, (void *)&enter_state_8__10TObjPlayerFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneBeastFv,
    (void *)&beast_idle_update__13TUnk_80493450Fv, (void *)&update_turn_toward_target__13TUnk_80493450Fv, (void *)&beast_update_approach__13TUnk_80493450Fv, (void *)&beast_update_group_chase__13TUnk_80493450Fv,
    (void *)&beast_update_attack__13TUnk_80493450Fv, (void *)&vfunc_89__13TUnk_80493450Fv, (void *)&beast_update_hurt__13TUnk_80493450Fv, (void *)&beast_update_dead__13TUnk_80493450Fv,
    (void *)&beast_retire_corpse__13TUnk_80493450Fv, (void *)&vfunc_93__12TObjEneBeastFv, (void *)&vfunc_94__12TObjEneBeastFv, (void *)&vfunc_95__12TObjEneBeastFv,
    (void *)&vfunc_96__12TObjEneBeastFv, (void *)&vfunc_97__12TObjEneBeastFv, (void *)&vfunc_98__12TObjEneBeastFv, (void *)&vfunc_99__12TObjEneBeastFv,
    (void *)&vfunc_100__13TUnk_80493450Fv, (void *)&vfunc_101__12TObjEneBeastFv, (void *)&request_stand_action__13TUnk_80493450Fv,
};
#define __vt__12TObjEneBeast ((u8 *)__vt__12TObjEneBeast)

void *TObjEneBeast::create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x420);
    if (o2 != NULL) {
        o2 = TObjEneBeast__ct(o2, o, arg0);
    }
    return o2;
}

extern u32 ene_beast_boss_id_buffer;
extern u32 TObjEneBeast__boss4_rock_handler_ids;
extern u32 boss4_rock_pool;
extern u32 boss4_rock_shared_handler_ids;
extern u32 ene_beast_bml_resource;

void free_boss4_rock_pool(void) {
    if ((u32) ene_beast_boss_id_buffer != 0U) {
        mem_free((void*)ene_beast_boss_id_buffer);
        ene_beast_boss_id_buffer = 0U;
    }
    if ((u32) TObjEneBeast__boss4_rock_handler_ids != 0U) {
        mem_free((void*)TObjEneBeast__boss4_rock_handler_ids);
        TObjEneBeast__boss4_rock_handler_ids = 0U;
    }
    if ((u32) boss4_rock_pool != 0U) {
        mem_free((void*)boss4_rock_pool);
        boss4_rock_pool = 0U;
    }
    if ((u32) boss4_rock_shared_handler_ids != 0U) {
        mem_free((void*)boss4_rock_shared_handler_ids);
        boss4_rock_shared_handler_ids = 0U;
    }
    if ((u32) boss4_type3_instance != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)boss4_type3_instance, 1);
        boss4_type3_instance = 0U;
    }
    if ((u32) beast_claw_trail_instance != 0U) {
        __dt__11TBoss4Type3FPvs((s32 *)beast_claw_trail_instance, 1);
        beast_claw_trail_instance = 0U;
    }
    if ((u32) ene_beast_bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)ene_beast_bml_resource, 1);
        ene_beast_bml_resource = 0U;
    }
}

#pragma push
#pragma opt_propagation off
void TObjEneBeast::load_resources() {
    u8 *p;
    s32 i;

    if (TObjEneDD::check_v2_mode() != 0) {
        ene_beast_bml_resource = (u32)load_enemy_bml_resource_named(beast_resource_descriptor, lbl_80439D80);
        ((Ent_8009241C *)beast_collision_body_table)[0].radius = 1e+01f;
        ((Ent_8009241C *)beast_collision_body_table)[1].radius = 1e+01f;
        ((Ent_8009241C *)beast_collision_body_table)[2].radius = 9.0f;
    } else {
        p = (u8 *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, beast_resource_descriptor, 0, 0, 0);
        }
        ene_beast_bml_resource = (u32)p;
        ((Ent_8009241C *)beast_collision_body_table)[0].radius = 7.0f;
        ((Ent_8009241C *)beast_collision_body_table)[1].radius = 7.0f;
        ((Ent_8009241C *)beast_collision_body_table)[2].radius = 8.0f;
    }
    p = (u8 *)::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, 7.0f, 12.0f, 1.0f);
    }
    beast_claw_trail_instance = (void *)p;
    p = (u8 *)::operator new(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, 7.0f, 12.0f, 1.0f);
    }
    boss4_type3_instance = (void *)p;
    draw_trail_with_colors((u8 *)beast_claw_trail_instance, (s32)(((Data_8009241C *)ene_beast_bml_resource)->f42c->f8), (s32)(((Data_8009241C *)ene_beast_bml_resource)->f430[((s32 *)beast_action_table)[13]].f4), 5, 8);
    draw_trail_with_colors((u8 *)boss4_type3_instance, (s32)(((Data_8009241C *)ene_beast_bml_resource)->f42c->f8), (s32)(((Data_8009241C *)ene_beast_bml_resource)->f430[((s32 *)beast_action_table)[17]].f4), 10, 13);
    ene_beast_boss_id_buffer = (u32)mem_alloc(0xC);
    TObjEneBeast__boss4_rock_handler_ids = (u32)mem_alloc(0xC);
    boss4_rock_pool = (u32)mem_alloc(0xC);
    boss4_rock_shared_handler_ids = (u32)mem_alloc(0xC);
    ((s32 *)ene_beast_boss_id_buffer)[0] = register_boss__6TLobbyFl(0x4B);
    ((s32 *)ene_beast_boss_id_buffer)[1] = register_boss__6TLobbyFl(0x4C);
    ((s32 *)ene_beast_boss_id_buffer)[2] = register_boss__6TLobbyFl(0x4D);
    ((s32 *)TObjEneBeast__boss4_rock_handler_ids)[0] = dispatch_shared_handler_b__6TLobbyFl(0x4E);
    ((s32 *)TObjEneBeast__boss4_rock_handler_ids)[1] = dispatch_shared_handler_b__6TLobbyFl(0x4F);
    ((s32 *)TObjEneBeast__boss4_rock_handler_ids)[2] = dispatch_shared_handler_b__6TLobbyFl(0x50);
    ((s32 *)boss4_rock_pool)[0] = register_object__6TLobbyFl(0x4A);
    ((s32 *)boss4_rock_pool)[1] = register_object__6TLobbyFl(0x4B);
    ((s32 *)boss4_rock_pool)[2] = register_object__6TLobbyFl(0x4C);
    ((s32 *)boss4_rock_shared_handler_ids)[0] = dispatch_shared_handler_a__6TLobbyFl(0x4A);
    ((s32 *)boss4_rock_shared_handler_ids)[1] = dispatch_shared_handler_a__6TLobbyFl(0x4B);
    ((s32 *)boss4_rock_shared_handler_ids)[2] = dispatch_shared_handler_a__6TLobbyFl(0x4C);
    {
        Ids_8009241C ids = lbl_80439D68[0];
        Quad_8009241C q = lbl_80439D70[0];
        q.a = (s32)((Data_8009241C *)ene_beast_bml_resource)->f430;
        for (i = 0; i < 3; i++) {
            spawn_npc_enemy__6TLobbyFslllff(ids.id[i], ((Data_8009241C *)ene_beast_bml_resource)->f42c[i].f8,
                                            ((Data_8009241C *)ene_beast_bml_resource)->f42c[i].fC, &q,
                                            ((Ent_8009241C *)beast_collision_body_table)[i].radius, 0.0f);
        }
    }
}

#pragma pop
O_80092724 *TObjPlayer__sub_80092724(O_80092724 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vptr = __vt__12TObjEneBeast;
        for (i = 0; i < 2; i++) {
            if (arg0->objs[i] != NULL) {
                queue_destruction__7TObjectFv(arg0->objs[i]);
                arg0->objs[i] = NULL;
            }
        }
        ((TUnk_80493450 *)arg0)->unlink_enemy_group_relations();
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x3B0, __dt__15RenderFadeStateFv, 0x1C, 4);
        __dt__13TUnk_80493450Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#define F(o, T, off) (*(T *)(o + (off)))
struct VBase_800927DC { char pad[0x18]; };
struct VObj_800927DC : VBase_800927DC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78();
    virtual void m79(void *);
    virtual void m80();
};

f32 random_ratio__9TObjCharaFv(s32 arg0);
void obj_setFlags30(void *, u32);
void init_enemy_base__13TUnk_80493450Fv(void *, void *);
// init_collision_body_parts: declared once above (s32 return, int arg)
void __construct_array(void *, void *, void *, int, int);
extern u8 __ct__15RenderFadeStateFv[];
struct Rec2C_800927DC { u8 b[0x2C]; };
struct Rec1C_800927DC { u8 b[0x1C]; };
struct Elem_800927DC { u8 b[0x1C]; };
struct Obj_800927DC { u8 pad[0x3B0]; Elem_800927DC arr[4]; };
extern s32 lbl_805D2980;

#define arg0 ((u8 *)arg0v)

void *TObjEneBeast__ct(void *arg0v, void *arg1, void *arg2) {
    s32 i;

    init_enemy_base__13TUnk_80493450Fv(arg0, arg1);
    F(arg0, u8 *, 0x18) = (u8 *)__vt__12TObjEneBeast;
    __construct_array(arg0 + 0x3B0, __ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 0x1C, 4);
    F(arg0, s32, 0) = lbl_805D2980;
    ((VObj_800927DC *)arg0)->m79(arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    F(arg0, s32, 0x334) = F(arg0, s32, 0x368);
    ((TObjEneBeast *)arg0)->select_subtype();
    ((TObjEneBeast *)arg0)->select_model_record(F(arg0, s32, 0x368));
    F(arg0, u8 *, 0xD8) = (u8 *)beast_action_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)(F(arg0, u8 *, 0xD8)));
    F(arg0, u32, 0xDC) = F(ene_beast_bml_resource, u32, 0x430);
    F(arg0, s16, 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(F(arg0, s16, 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(F(arg0, s16, 0xB8));
    init_collision_body_parts(arg0, &((Rec2C_800927DC *)beast_collision_body_table)[F(arg0, s32, 0x334)], 1);
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(((u32 *)ene_beast_boss_id_buffer)[F(arg0, s32, 0x334)]), (u8 *)(((u32 *)TObjEneBeast__boss4_rock_handler_ids)[F(arg0, s32, 0x334)]), (u8 *)(((u32 *)boss4_rock_pool)[F(arg0, s32, 0x334)]));
    F(arg0, void *, 0x350) = &((Rec1C_800927DC *)beast_movement_params)[F(arg0, s32, 0x334)];
    F(arg0, s16, 0x33E) = F(arg0, s16, 0x32C);
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    ((TObjPlayer *)arg0)->register_object_by_id();
    F(arg0, s32, 0x2AC) = (s32)(182.04445f * (3.6e+02f * random_ratio__9TObjCharaFv((s32)arg0)));
    F(arg0, s16, 0x33A) = 0xF;
    F(arg0, s16, 0x33C) = F(arg0, s16, 0x33A);
    F(arg0, s16, 0x328) = 0;
    F(arg0, s16, 0x374) = 0;
    F(arg0, s16, 0x376) = 0;
    F(arg0, s32, 0x378) = 0;
    F(arg0, s32, 0x37C) = 0;
    ((TObjChara *)arg0)->add_flags_2e4(1);
    obj_setFlags30(arg0, 0x40000);
    F(arg0, f32, 0x380) = 0.0f;
    F(arg0, void *, 0x3A8) = TUnk_80494968::create((u32)0xA0303030, (u32)0xFF303030);
    F(arg0, void *, 0x3AC) = TUnk_80494968::create((u32)0xA0303030, (u32)0xFF303030);
    F(arg0, f32, 0x398) = ((f32 **)boss4_rock_shared_handler_ids)[F(arg0, s32, 0x334)][0];
    F(arg0, f32, 0x3A0) = ((f32 **)boss4_rock_shared_handler_ids)[F(arg0, s32, 0x334)][1];
    F(arg0, f32, 0x39C) = ((f32 **)boss4_rock_shared_handler_ids)[F(arg0, s32, 0x334)][2];
    F(arg0, f32, 0x3A4) = ((f32 **)boss4_rock_shared_handler_ids)[F(arg0, s32, 0x334)][3];
    F(arg0, s32, 0x390) = 1;
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(&((Obj_800927DC *)arg0)->arr[i]))->activate_and_dispatch();
    }
    ((VObj_800927DC *)arg0)->m80();
    return arg0;
}
#undef arg0
#undef F

}
