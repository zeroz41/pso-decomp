#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800A7764.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dimedian/TObjEneDimedian.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/unk/text_803D853C.h"

struct VBase_14_800A7BEC { char pad[0x14]; };

struct VObj_14_800A7BEC : VBase_14_800A7BEC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual s32 m5();
};

struct Obj_800A7BEC { u8 pad0[0x38]; u8 sub38[0x326 - 0x38]; s16 f326; s16 state; u8 pad32a[0x390 - 0x32A]; s32 f390; };

struct VBase_800A7A14 { char pad[0x18]; };

struct VObj_800A7A14 : VBase_800A7A14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec *, Vec *);
};

typedef struct Obj_800A7A14 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C4 - 0xC4];
    VObj_800A7A14 *effs[2];
} Obj_800A7A14;

struct VBase14_800A7CA4 { u8 pad[0x14]; };

struct Fade_800A7CA4 : VBase14_800A7CA4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5();
    virtual void begin();
    virtual void end();
    virtual s32 active();
    u8 pad18[4];
};

struct VBase18_800A7CA4 { u8 pad[0x18]; };

struct Node_800A7CA4 { u8 pad[6]; s16 f6; };

struct L4_800A7CA4 { u8 pad[4]; Node_800A7CA4 *n; };

struct L3_800A7CA4 { u8 pad[4]; L4_800A7CA4 *n; };

struct L2_800A7CA4 { u8 pad[0x30]; L3_800A7CA4 *n; };

struct L1_800A7CA4 { u8 pad[0x2C]; L2_800A7CA4 *n; };

struct Player_800A7CA4 : VBase18_800A7CA4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8();
    virtual s32 visible(f32, f32, f32);
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    L1_800A7CA4 *f34;
    u8 pos[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    u8 cam[0x326 - 0x2FC];
    s16 f326;
    u8 pad328[0x368 - 0x328];
    s32 f368;
    u8 pad36C[0x390 - 0x36C];
    s32 f390;
    u8 pad394[0x3A8 - 0x394];
    Fade_800A7CA4 sub;
    u8 pad3C4[8];
    Fade_800A7CA4 fades[2];
};

extern "C" {
s32 play_sound_effect(s32, s32, s32, s32);
s32 TObjPlayer__sub_800A0554(void *);
s32 post_translate_matrix(void *);
extern saddr dimedian_type3_object;
extern saddr lbl_805D5088;

void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
extern saddr dimedian_resource_handles[];
extern s32 dimedian_last_draw_tick[];
extern s32 actor_frame_tick;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

struct A7B00Base_800a7b00_800A7764 { char pad[0x14]; };
struct A7B00Obj_800a7b00_800A7764 : A7B00Base_800a7b00_800A7764 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
};

int VecCopy__FP3VecPC3Vec(void*);

s16 TObjPlayer::get_field_2c8() { return this->m_2c8; }
s16 TObjPlayer__sub_800A776C(void* p) { return *(s16*)((char*)p + 0x2ca); }
int TObjPlayer__sub_800A7774(void* p) { return VecCopy__FP3VecPC3Vec((char*)p + 0x38); }

void TObjMotion::sub_800A7798(f32 farg0) {
    this->override_speed = farg0;
    this->set_flags_B0((u32)(0x100U));
}

void TObjMotion::set_flags_B0(u32 v) { this->motion_flags |= v; }
void TObjEneDimedian::run_demo_task() {  }

void TObjEneDimedian::play_group_chase_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003AD40), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_death_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003AD3D), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_hurt_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A83E), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_attack_sound() {
    saddr arg0 = (saddr)this;
    play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A83F), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_alert_sound() {
    saddr arg0 = (saddr)this;
    s32 temp_r3;
    if (random_ratio() < 0.5f) {
        temp_r3 = ((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003B23B);
        play_sound_effect(temp_r3, arg0 + 0x38, 0, 0);
    } else {
        temp_r3 = ((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003B23C);
        play_sound_effect(temp_r3, arg0 + 0x38, 0, 0);
    }
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::spawn_death_effect() {
    saddr arg0 = (saddr)this;
    s32 area;
    TObjPlayer::apply_effect_variant_a(arg0 + 0x38, 0);
    fn_800D911C((Vec *)(arg0 + 0x2FC));
    area = get_current_floor_area();
    if ((area == AREA_VR_TEMPLE_ALPHA) || (area == AREA_VR_TEMPLE_BETA)) {
        play_sound_effect(0x3AD3F, arg0 + 0x38, 0, 0);
        return;
    }
    play_sound_effect((s32)(((s32)((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003AD25))), arg0 + 0x38, 0, 0);
}

void TObjEneDimedian::update_attack_trail() {
    Obj_800A7A14 *o = (Obj_800A7A14 *)this;
    Vec b;
    Vec a;
    Vec *e;
    s32 idx;
    VObj_800A7A14 *eff;
    if (!(this->frame < 12.0f)) {
        return;
    }
    switch (this->requested_action) {
    case 3:
        e = ((SampledMotionPoints *)((void *)dimedian_type3_object))->lookup(this->frame);
        idx = 0;
        break;
    case 4:
        e = ((SampledMotionPoints *)((void *)lbl_805D5088))->lookup(this->frame);
        idx = 1;
        break;
    default:
        e = 0;
        break;
    }
    if (e == 0) {
        return;
    }
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&o->pos);
    rotate_matrix_y(0, this->rotation_y);
    matrix_mult_vec_array(NULL, e, &a, 2);
    pop_matrix();
    eff = o->effs[idx];
    if (eff != NULL) {
        eff->m4(&a, &b);
    }
}

void TObjEneDimedian::beast_retire_corpse() {
    u8 *arg0 = (u8 *)this;
    this->m_390 = 1;
    if (((A7B00Obj_800a7b00_800A7764*)(arg0 + 0x3A8))->m4() == 1) {
        ((TObject *)arg0)->queue_destruction();
    }
}
void TObjEneDimedian::sub_800A7B54() {
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
        *(s32 *)((s8 *)arg0 + 0x368) = 0;
        ((TObjEnemy *)arg0)->set_param(0x2B);
        return;
    case 1:
        *(s32 *)((s8 *)arg0 + 0x368) = 1;
        ((TObjEnemy *)arg0)->set_param(0x2A);
        return;
    default:
        *(s32 *)((s8 *)arg0 + 0x368) = 2;
        ((TObjEnemy *)arg0)->set_param(0x29);
        return;
    }
}
void TObjEneDimedian::beast_update_appear() {
    Obj_800A7BEC *arg0 = (Obj_800A7BEC *)this;
    advance_animation();
    switch (this->phase) {
    case 0:
    default:
        if (this->m_390 == 1) {
            this->phase = 1;
            play_area_se_with_particle((Vec *)(arg0->sub38));
            TObjPlayer__sub_800A0554((u8 *)arg0 + 0x3A8);
        } else {
            this->phase = 2;
        }
        break;
    case 1:
        if (((VObj_14_800A7BEC *)((u8 *)arg0 + 0x3A8))->m5() == 1) {
            this->phase = 2;
            this->m_390 = 0;
        }
        break;
    case 2:
        this->mode = 1;
        break;
    }
}
#define self ((Player_800A7CA4 *)this)
void TObjEneDimedian::render() {
    s16 saved;
    s32 vis;
    s32 fading;
    s32 mode;
    s32 d;
    s32 doDraw;
    Vec pos;
    if (actor_frame_tick != dimedian_last_draw_tick[self->f368]) {
        dimedian_last_draw_tick[self->f368] = actor_frame_tick;
        TObjPlayer__sub_8023DEE0((s16 *)dimedian_resource_handles[self->f368], 0xE, 0, 0);
    }
    mode = 0;
    if (is_split_screen() != 0) {
        mode = TCameraCtrl::get_camera_mode();
    }
    vis = self->visible(2e+02f, 4e+02f, 3e+01f);
    if (vis == 0) {
        return;
    }
    fading = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        ((RenderFadeState *)(&self->fades[mode]))->update();
        fading = ((RenderFadeState *)(&self->fades[mode]))->updateFromCamera((const f32*)(self->cam));
    }
    select_actor_lighting((saddr)self);
    TObjFish::set_global_param(self->f24);
    push_matrix();
    post_translate_matrix(self->pos);
    rotate_matrix_y(0, self->f60);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(self->f34);
    } else {
        switch (self->f326) {
        case 0:
        case 1:
        case 8: {
            Node_800A7CA4 *n = self->f34->n->n->n->n;
            saved = n->f6;
            n->f6 = (u8)n->f6;
            break;
        }
        }
        TObjPlayer::toggle_particle_effect();
        if (self->f390 == 1) {
            if (m_3a8.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                m_3a8.set_flags_and_apply_damage_color();
                d = 1;
                if (((TObject *)self)->defer_render() != 0) {
                    d = 0;
                }
                if (d != 0) {
                    ((TObjMotion *)self)->draw();
                }
                m_3a8.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else {
            doDraw = 1;
            if (fading != 0) {
                self->fades[mode].begin();
                if (((TObject *)self)->defer_render() != 0) {
                    doDraw = 0;
                }
            }
            if (doDraw != 0) {
                if (vis == 1) {
                    ((TObjMotion *)self)->draw();
                } else {
                    ((TObjEnemy *)self)->draw_motion_model();
                }
            }
            if (fading != 0) {
                self->fades[mode].end();
            }
        }
        TParticleCtrl::end_effect_render();
        switch (self->f326) {
        case 0:
        case 1:
        case 8:
            self->f34->n->n->n->n->f6 = saved;
            break;
        }
    }
    pop_matrix();
    restore_scene_lighting();
    switch (self->f326) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default:
        pos.x = 1.5f;
        pos.y = 1.0f;
        pos.z = 2.0f;
        ((TObjEnemy *)self)->draw_ground_shadow(&pos, 0);
        break;
    }
}
#undef self

}

extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__13TUnk_80493450Fv();

extern "C" const u8 dimedian_sl_body_model_filename[20] = "df3_sl_wala_body.nj";
extern "C" const u8 dimedian_ssl_body_model_filename[24] = "df3_ssl_wala_body.nj";
extern "C" const u8 dimedian_s_body_model_filename[20] = "df3_s_wala_body.nj";
extern "C" const u8 dimedian_appear_motion_filename[28] = "appear_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_attack_left_motion_filename[28] = "atackl_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_attack_right_motion_filename[28] = "atackr_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_damage_motion_filename[28] = "damage_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_deadb_motion_filename[28] = "deadb_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_dead_motion_filename[28] = "dead_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_leader_motion_filename[28] = "leader_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_mihari_motion_filename[28] = "mihari_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_run_motion_filename[24] = "run_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_stund_motion_filename[28] = "stund_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_wakeup_motion_filename[28] = "wakeup_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_walk_motion_filename[28] = "walk_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_bml_filename[24] = "bm_ene_df3_dimedian.bml";
extern "C" const char dimedian_class_name[16] = "TObjEneDimedian";



struct Pair_800A8118 { s32 a; NJS_MOTION *b; };
struct Bodies_800A8118 { s32 a; s32 b; NJS_OBJECT *model; s32 textures; };
struct Res_800A8118 { u8 pad[0x42C]; Bodies_800A8118 *bodies; Pair_800A8118 *motions; };
struct Act_800A8118 { s32 a; s32 idx; f32 c; s32 d; };
struct Part_800A8118 { u8 pad[0xC]; f32 radius; u8 pad10[0x1C]; };

extern "C" {
extern const u8 lbl_8043AAA4[26];
}
int initialize_enemy_photon_effect(void *p);
extern "C" {
void init_collision_body_parts(void *, void *, s32);
extern const char *TObjEneDimedian_name_ref;

void free_collision_body_parts(void *);

extern void *tl_04;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void has_no_target__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void deliver_attack_hits__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void select_post_attack_mode__13TUnk_80493450Fv();

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
extern "C" void run_move_action__13TUnk_80493450Fv();
extern "C" void beast_idle_update__13TUnk_80493450Fv();
extern "C" void refresh_target__13TUnk_80493450Fv();
extern "C" void run_attack_action__13TUnk_80493450Fv();
extern "C" void beast_update_approach__13TUnk_80493450Fv();
extern "C" void beast_update_attack__13TUnk_80493450Fv();
extern "C" void beast_update_dead__13TUnk_80493450Fv();
extern "C" void beast_update_group_chase__13TUnk_80493450Fv();
extern "C" void beast_update_hurt__13TUnk_80493450Fv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void apply_enemy_state__9TObjEnemyFPl();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void run_miss_reaction__13TUnk_80493450Fv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void run_hit_reaction__13TUnk_80493450Fv();
extern "C" void run_death_reaction__13TUnk_80493450Fv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void gain_photon_blast_chain_charge__9TObjCharaFv();
extern "C" void spend_photon_blast_charge__9TObjCharaFf();
extern "C" void gain_photon_blast_charge__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();

extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_shadows__9TObjEnemyFv();
extern "C" void request_stand_action__13TUnk_80493450Fv();
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void run_task__13TUnk_80493450Fv();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void update_movement_status__13TUnk_80493450Fv();
extern "C" void run_idle_action__13TUnk_80493450Fv();
extern "C" void trigger_switch_attack__9TObjCharaFv();
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__13TUnk_80493450Fv();
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" void update_defense_stat_status__9TObjCharaFv();
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *dimedian_model_name_table[4];
extern void *dimedian_motion_name_table[13];
void *dimedian_model_name_table[4] = {
    (void *)&dimedian_sl_body_model_filename, (void *)&dimedian_ssl_body_model_filename, (void *)&dimedian_s_body_model_filename, (void *)0x0,
};
void *dimedian_motion_name_table[13] = {
    (void *)&dimedian_appear_motion_filename, (void *)&dimedian_attack_left_motion_filename, (void *)&dimedian_attack_right_motion_filename, (void *)&dimedian_damage_motion_filename,
    (void *)&dimedian_deadb_motion_filename, (void *)&dimedian_dead_motion_filename, (void *)&dimedian_leader_motion_filename, (void *)&dimedian_mihari_motion_filename,
    (void *)&dimedian_run_motion_filename, (void *)&dimedian_stund_motion_filename, (void *)&dimedian_wakeup_motion_filename, (void *)&dimedian_walk_motion_filename,
    (void *)0x0,
};
void *dimedian_resource_descriptor[4] = {
    (void *)&dimedian_bml_filename, (void *)&dimedian_model_name_table, (void *)&dimedian_motion_name_table, (void *)0x3000c,
};
void *dimedian_action_table[44] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f19999a, (void *)0x1,
    (void *)0x20000, (void *)0x7, (void *)0x3f19999a, (void *)0x20,
    (void *)0x10002, (void *)0xb, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x1, (void *)0x3f800000, (void *)0x4,
    (void *)0x20000, (void *)0x2, (void *)0x3f800000, (void *)0x4,
    (void *)0x10000, (void *)0x8, (void *)0x3f800000, (void *)0x1,
    (void *)0x20000, (void *)0x3, (void *)0x3f800000, (void *)0x8,
    (void *)0x20000, (void *)0xa, (void *)0x3f4ccccd, (void *)0x20,
    (void *)0x30000, (void *)0x5, (void *)0x3f19999a, (void *)0x10,
    (void *)0x30000, (void *)0x4, (void *)0x3f19999a, (void *)0x10,
    (void *)0x20000, (void *)0x6, (void *)0x3f19999a, (void *)0x20,
};
void *dimedian_movement_params[21] = {
    (void *)0x43610000, (void *)0x3f400000, (void *)0x400, (void *)0x0,
    (void *)0x1e0000, (void *)0x1, (void *)0x0, (void *)0x437a0000,
    (void *)0x3f666666, (void *)0x400, (void *)0x0, (void *)0x1e0000,
    (void *)0x1, (void *)0x0, (void *)0x43960000, (void *)0x3f800000,
    (void *)0x400, (void *)0x0, (void *)0x1e0000, (void *)0x1,
    (void *)0x0,
};
void *dimedian_collision_body_table[33] = {
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

void *TObjEneDimedian::create(void *arg2_) {
    TObjControl *control = new TObjControl((TObject *)tl_04);
    return new TObjEneDimedian(control, arg2_);
}

uaddr dimedian_boss_object_buf;
uaddr lbl_805D5074;
uaddr TObjEneDimedian__boss_objects;
uaddr dimedian_buffer_ptr;
struct E_800A884C { u8 pad[8]; s32 x8; s32 xc; };

struct G_800A884C { u8 pad[0x42c]; E_800A884C *tbl; };

extern G_800A884C *dimedian_resource_ptr;

void TObjEneDimedian::free_boss_objects() {
    if ((u32) dimedian_boss_object_buf != 0U) {
        mem_free((void*)dimedian_boss_object_buf);
        dimedian_boss_object_buf = 0U;
    }
    if ((u32) lbl_805D5074 != 0U) {
        mem_free((void*)lbl_805D5074);
        lbl_805D5074 = 0U;
    }
    if ((u32) TObjEneDimedian__boss_objects != 0U) {
        mem_free((void*)TObjEneDimedian__boss_objects);
        TObjEneDimedian__boss_objects = 0U;
    }
    if ((u32) dimedian_buffer_ptr != 0U) {
        mem_free((void*)dimedian_buffer_ptr);
        dimedian_buffer_ptr = 0U;
    }
    if ((u32) lbl_805D5088 != 0U) {
        delete (SampledMotionPoints *)lbl_805D5088;
        lbl_805D5088 = 0U;
    }
    if ((u32) dimedian_type3_object != 0U) {
        delete (SampledMotionPoints *)dimedian_type3_object;
        dimedian_type3_object = 0U;
    }
    if ((uaddr) dimedian_resource_ptr != 0U) {
        delete (BmlResource *)dimedian_resource_ptr;
        dimedian_resource_ptr = 0U;
    }
}

#define RES_800A8118 ((Res_800A8118 *)dimedian_resource_ptr)
#define dimedian_action_table ((Act_800A8118 *)dimedian_action_table)
#define dimedian_collision_body_table ((Part_800A8118 *)dimedian_collision_body_table)
#define CHAIN_800A8118(p) (*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)(p + 0x2C)) + 0x30)) + 0x30)) + 4)) + 4))

void TLobby::load_dimedian_resources() {
    u8 *r;
    void *p;
    s32 i;
    if (TObjEneDD::check_v2_mode() != 0) {
        (*(u8 **)&dimedian_resource_ptr) = (u8 *)load_enemy_bml_resource_named((BmlResourceDescriptor *)dimedian_resource_descriptor, (const char *)lbl_8043AAA4);
    } else {
        p = new BmlResource(1, (BmlResourceDescriptor *)dimedian_resource_descriptor, 0, 0, NULL);
        (*(u8 **)&dimedian_resource_ptr) = (u8 *)p;
    }
    r = *(u8 **)((s8 *)(*(u8 **)&dimedian_resource_ptr) + 0x42C);
    dimedian_resource_handles[0] = CHAIN_800A8118(*(u8 **)((s8 *)r + 0x8));
    dimedian_resource_handles[1] = CHAIN_800A8118(*(u8 **)((s8 *)r + 0x18));
    dimedian_resource_handles[2] = CHAIN_800A8118(*(u8 **)((s8 *)r + 0x28));
    dimedian_last_draw_tick[0] = 0;
    dimedian_last_draw_tick[1] = 0;
    dimedian_last_draw_tick[2] = 0;
    p = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    (*(void **)&dimedian_type3_object) = p;
    p = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    (*(void **)&lbl_805D5088) = p;
    ((SampledMotionPoints *)(*(void **)&dimedian_type3_object))->sample_two_nodes(RES_800A8118->bodies->model, RES_800A8118->motions[dimedian_action_table[3].idx].b, 5, 8);
    ((SampledMotionPoints *)(*(void **)&lbl_805D5088))->sample_two_nodes(RES_800A8118->bodies->model, RES_800A8118->motions[dimedian_action_table[4].idx].b, 0xA, 0xD);
    (*(s32 **)&dimedian_boss_object_buf) = (s32 *)mem_alloc(0xC);
    (*(s32 **)&lbl_805D5074) = (s32 *)mem_alloc(0xC);
    (*(s32 **)&TObjEneDimedian__boss_objects) = (s32 *)mem_alloc(0xC);
    (*(s32 **)&dimedian_buffer_ptr) = (s32 *)mem_alloc(0xC);
    (*(s32 **)&dimedian_boss_object_buf)[0] = (saddr)TLobby::register_boss(0x53);
    (*(s32 **)&dimedian_boss_object_buf)[1] = (saddr)TLobby::register_boss(0x54);
    (*(s32 **)&dimedian_boss_object_buf)[2] = (saddr)TLobby::register_boss(0x55);
    (*(s32 **)&lbl_805D5074)[0] = (saddr)TLobby::dispatch_shared_handler_b(0x5A);
    (*(s32 **)&lbl_805D5074)[1] = (saddr)TLobby::dispatch_shared_handler_b(0x5B);
    (*(s32 **)&lbl_805D5074)[2] = (saddr)TLobby::dispatch_shared_handler_b(0x5C);
    (*(s32 **)&TObjEneDimedian__boss_objects)[0] = (saddr)TLobby::register_object(0x52);
    (*(s32 **)&TObjEneDimedian__boss_objects)[1] = (saddr)TLobby::register_object(0x53);
    (*(s32 **)&TObjEneDimedian__boss_objects)[2] = (saddr)TLobby::register_object(0x54);
    (*(s32 **)&dimedian_buffer_ptr)[0] = (saddr)TLobby::dispatch_shared_handler_a(0x52);
    (*(s32 **)&dimedian_buffer_ptr)[1] = (saddr)TLobby::dispatch_shared_handler_a(0x53);
    (*(s32 **)&dimedian_buffer_ptr)[2] = (saddr)TLobby::dispatch_shared_handler_a(0x54);
    {
        s16 ids[3] = { 0x1B, 0x1C, 0x1D };
        NpcAnimationBinding anim = { reinterpret_cast<BmlMotionEntry *>(RES_800A8118->motions), reinterpret_cast<TObjMotionAction *>(dimedian_action_table), 0, 2, 12 };
        for (i = 0; i < 3; i++) {
            u8 *b = *(u8 **)((s8 *)(*(u8 **)&dimedian_resource_ptr) + 0x42C) + i * 0x10;
            NpcModelRegistry::register_animated_chunk(ids[i], reinterpret_cast<void *>(*(s32 *)((s8 *)b + 8)), reinterpret_cast<void *>(*(s32 *)((s8 *)b + 0xC)), &anim,
                dimedian_collision_body_table[i].radius, 0.0f);
        }
    }
}
extern "C" __declspec(section ".rodata") const u8 lbl_8043AAA4[26] = "bm_ene_df3_dimedian_a.bml";
#undef CHAIN_800A8118
#undef RES_800A8118
#undef dimedian_action_table
#undef dimedian_collision_body_table
}

extern "C" {
saddr dimedian_resource_handles[3];
s32 dimedian_last_draw_tick[3];

const char *TObjEneDimedian_name_ref = dimedian_class_name;

G_800A884C *dimedian_resource_ptr;
saddr dimedian_type3_object;
saddr lbl_805D5088;
}

#pragma defer_codegen on
struct O_800A884C { u8 pad[0x24]; s32 x24; u8 pad2[0xc]; s32 x34; };

void TObjEneDimedian::load_dimedian_param_entry(s32 i) {
    O_800A884C *self = (O_800A884C *)this;
    self->x34 = dimedian_resource_ptr->tbl[i].x8;
    self->x24 = dimedian_resource_ptr->tbl[i].xc;
}

#define dimedian_action_table ((u8 *)dimedian_action_table)
#define dimedian_movement_params ((u8 *)dimedian_movement_params)
#define dimedian_collision_body_table ((u8 *)dimedian_collision_body_table)
#define arg0 ((u8 *)this)
TObjEneDimedian::TObjEneDimedian(TObject *parent, void *set_data) : TUnk_80493450(parent) {
    s32 color;
    s32 i;
    *(const char **)((s8 *)arg0 + 0) = TObjEneDimedian_name_ref;
    apply_set_data(set_data);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x334) = *(s32 *)((s8 *)arg0 + 0x368);
    ((TObjEneDimedian *)arg0)->sub_800A7B54();
    ((TObjEneDimedian *)arg0)->load_dimedian_param_entry(*(s32 *)((s8 *)arg0 + 0x368));
    *(u8 **)((s8 *)arg0 + 0xD8) = dimedian_action_table;
    ((TObjMotion *)arg0)->set_field_d8((saddr)(*(u8 **)((s8 *)arg0 + 0xD8)));
    *(s32 *)((s8 *)arg0 + 0xDC) = *(s32 *)((s8 *)(*(u8 **)&dimedian_resource_ptr) + 0x430);
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(*(s16 *)((s8 *)arg0 + 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    init_collision_body_parts(arg0, dimedian_collision_body_table + *(s32 *)((s8 *)arg0 + 0x334) * 0x2C, 1);
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)((*(saddr **)&dimedian_boss_object_buf)[*(s32 *)((s8 *)arg0 + 0x334)]), (u8 *)((*(saddr **)&lbl_805D5074)[*(s32 *)((s8 *)arg0 + 0x334)]), (u8 *)((*(saddr **)&TObjEneDimedian__boss_objects)[*(s32 *)((s8 *)arg0 + 0x334)]));
    *(u8 **)((s8 *)arg0 + 0x350) = dimedian_movement_params + *(s32 *)((s8 *)arg0 + 0x334) * 0x1C;
    *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    initialize_enemy_photon_effect(arg0);
    *(s32 *)((s8 *)arg0 + 0x2AC) = (s32)(182.04445f * (3.6e+02f * ((TObjChara *)arg0)->random_ratio()));
    *(s16 *)((s8 *)arg0 + 0x33A) = 0xF;
    *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33A);
    *(s16 *)((s8 *)arg0 + 0x328) = 0;
    *(s16 *)((s8 *)arg0 + 0x374) = 0;
    *(s16 *)((s8 *)arg0 + 0x376) = 0;
    *(s32 *)((s8 *)arg0 + 0x378) = 0;
    *(s32 *)((s8 *)arg0 + 0x37C) = 0;
    ((TObjChara *)arg0)->add_flags_2e4(8);
    *(u32 *)((s8 *)arg0 + 0x30) |= 0x40000;
    *(f32 *)((s8 *)arg0 + 0x388) = (-4.0f);
    if (TObjEneDD::check_v2_mode() != 0) {
        switch (*(s32 *)((s8 *)arg0 + 0x334)) {
        case 0:
        default:
            color = 0xFF20FF20;
            break;
        case 1:
            color = 0xFFFF0040;
            break;
        case 2:
            color = 0xFFFFFF00;
            break;
        }
    } else {
        switch (*(s32 *)((s8 *)arg0 + 0x334)) {
        default:
            color = 0xFF0000FF;
            break;
        case 1:
            color = 0xFFFF0000;
            break;
        case 2:
            color = 0xFFFFFF00;
            break;
        }
    }
    m_3c4[0] = TUnk_80494968::create(0xA0303030, color);
    m_3c4[1] = TUnk_80494968::create(0xA0303030, color);
    *(s32 *)((s8 *)arg0 + 0x390) = 1;
    *(f32 *)((s8 *)arg0 + 0x398) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][0];
    *(f32 *)((s8 *)arg0 + 0x3A0) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][1];
    *(f32 *)((s8 *)arg0 + 0x39C) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][2];
    *(f32 *)((s8 *)arg0 + 0x3A4) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][3];
    for (i = 0; i < 4; i++) {
        m_3cc[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}
#undef arg0

TObjEneDimedian::~TObjEneDimedian() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (m_3c4[i] != NULL) {
            m_3c4[i]->queue_destruction();
            m_3c4[i] = NULL;
        }
    }
    unlink_enemy_group_relations();
    free_collision_body_parts(this);
}
