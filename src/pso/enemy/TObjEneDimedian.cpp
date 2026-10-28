#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800A7764.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEneDimedian.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/misc/obj_band.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/misc/TLobby.h"
#include "pso/enemy/TObjEneBeast.h"
#include "pso/enemy/TObjEnePanarms.h"

struct VBase_14_800A7BEC { char pad[0x14]; };

struct VObj_14_800A7BEC : VBase_14_800A7BEC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual s32 m5();
};

struct Obj_800A7BEC { u8 pad0[0x38]; u8 sub38[0x326 - 0x38]; s16 f326; s16 state; u8 pad32a[0x390 - 0x32A]; s32 f390; };

typedef struct Vec_800A7A14 {
    f32 x, y, z;
} Vec_800A7A14;

struct VBase_800A7A14 { char pad[0x18]; };

struct VObj_800A7A14 : VBase_800A7A14 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(Vec_800A7A14 *, Vec_800A7A14 *);
};

typedef struct Obj_800A7A14 {
    u8 pad0[0x38];
    Vec_800A7A14 pos;
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
s32 copy_target_state__14TObjEnePanarmsFPv(s32, s32);
s32 TObjPlayer__sub_800A0554(void *);
s32 advance_animation_playback();
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern s32 dimedian_type3_object;
extern s32 lbl_805D5088;

s32 is_split_screen();
s32 get_camera_mode__11TCameraCtrlFv();
s32 update_obstruction_fade(void *);
s32 restore_scene_lighting();
s32 select_actor_lighting(void *);
s32 defer_render__7TObjectFv(void *);
s32 TObjPlayer__sub_8023DEE0(int, int, int, int);
s32 draw_chunk_object(void *);
extern s32 dimedian_resource_handles[];
extern s32 dimedian_last_draw_tick[];
extern s32 actor_frame_tick;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

void draw_actor_model__10TObjPlayerFPv(Player_800A7CA4 *self);
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

void TObjEnemy::sub_800A7798(f32 farg0) {
    this->m_d0 = farg0;
    this->set_flags_B0((u32)(0x100U));
}

void TObjEnemy::set_flags_B0(u32 v) { this->animationFlags |= v; }
void TObjEneDimedian::vfunc_101() {  }

void TObjEneDimedian::vfunc_99() {
    s32 arg0 = (s32)this;
    play_sound_effect((s32)((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD40)))), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::vfunc_98() {
    s32 arg0 = (s32)this;
    play_sound_effect((s32)((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD3D)))), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::vfunc_97() {
    s32 arg0 = (s32)this;
    play_sound_effect((s32)((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A83E)))), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::vfunc_96() {
    s32 arg0 = (s32)this;
    play_sound_effect((s32)((void *) (((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003A83F)))), arg0 + 0x38, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::vfunc_95() {
    s32 arg0 = (s32)this;
    s32 temp_r3;
    if (TObjPlayer::calc_boss4_scale((s32)this) < 0.5f) {
        temp_r3 = copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B23B);
        play_sound_effect(temp_r3, arg0 + 0x38, 0, 0);
    } else {
        temp_r3 = copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003B23C);
        play_sound_effect(temp_r3, arg0 + 0x38, 0, 0);
    }
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::vfunc_94() {
    s32 arg0 = (s32)this;
    s32 global_state;
    TObjPlayer::apply_effect_variant_a(arg0 + 0x38, 0);
    ((TObjPlayer *)(arg0 + 0x2FC))->request_two_effects();
    global_state = TOKeyMachine01::get_global_state();
    if ((global_state == 0x13) || (global_state == 0x14)) {
        play_sound_effect(0x3AD3F, arg0 + 0x38, 0, 0);
        return;
    }
    play_sound_effect((s32)(((s32)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD25))), arg0 + 0x38, 0, 0);
}

void TObjEneDimedian::vfunc_93() {
    Obj_800A7A14 *o = (Obj_800A7A14 *)this;
    Vec_800A7A14 b;
    Vec_800A7A14 a;
    u32 e;
    s32 idx;
    VObj_800A7A14 *eff;
    if (!(this->m_c0 < 12.0f)) {
        return;
    }
    switch (this->m_b8) {
    case 3:
        e = TObjPlayer::lookup_entry_by_value((void *)dimedian_type3_object, this->m_c0);
        idx = 0;
        break;
    case 4:
        e = TObjPlayer::lookup_entry_by_value((void *)lbl_805D5088, this->m_c0);
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
    mult_vec_array__10TObjPlayerFUll(0, e, &a, 2);
    pop_matrix();
    eff = o->effs[idx];
    if (eff != NULL) {
        eff->m4(&a, &b);
    }
}

int TObjEneDimedian::beast_retire_corpse() {
    u8 *arg0 = (u8 *)this;
    this->m_390 = 1;
    if (((A7B00Obj_800a7b00_800A7764*)(arg0 + 0x3A8))->m4() == 1) {
        queue_destruction__7TObjectFv(arg0);
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
void TObjEneDimedian::vfunc_83() {
    Obj_800A7BEC *arg0 = (Obj_800A7BEC *)this;
    advance_animation_playback();
    switch (this->phase) {
    case 0:
    default:
        if (this->m_390 == 1) {
            this->phase = 1;
            ((TBoss3Volopt *)(arg0->sub38))->play_area_se_with_particle();
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
void draw_actor_model__10TObjPlayerFPv(Player_800A7CA4 *self) {
    s16 saved;
    s32 vis;
    s32 fading;
    s32 mode;
    s32 d;
    s32 doDraw;
    f32 pos[3];
    if (actor_frame_tick != dimedian_last_draw_tick[self->f368]) {
        dimedian_last_draw_tick[self->f368] = actor_frame_tick;
        TObjPlayer__sub_8023DEE0(dimedian_resource_handles[self->f368], 0xE, 0, 0);
    }
    mode = 0;
    if (is_split_screen() != 0) {
        mode = get_camera_mode__11TCameraCtrlFv();
    }
    vis = self->visible(2e+02f, 4e+02f, 3e+01f);
    if (vis == 0) {
        return;
    }
    fading = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        update_obstruction_fade(&self->fades[mode]);
        fading = ((RenderFadeState *)(&self->fades[mode]))->updateFromCamera((const f32*)(self->cam));
    }
    select_actor_lighting(self);
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
            if (self->sub.active() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                self->sub.begin();
                d = 1;
                if (defer_render__7TObjectFv(self) != 0) {
                    d = 0;
                }
                if (d != 0) {
                    ((TObjMotion *)self)->draw();
                }
                self->sub.end();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else {
            doDraw = 1;
            if (fading != 0) {
                self->fades[mode].begin();
                if (defer_render__7TObjectFv(self) != 0) {
                    doDraw = 0;
                }
            }
            if (doDraw != 0) {
                if (vis == 1) {
                    ((TObjMotion *)self)->draw();
                } else {
                    ((TObjEnemy *)self)->render_world_model();
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
        pos[0] = 1.5f;
        pos[1] = 1.0f;
        pos[2] = 2.0f;
        ((TObjEnemy *)self)->render_with_position_override((u8 *)pos, 0);
        break;
    }
}

}

extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
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
extern "C" const u8 dimedian_class_name[16] = "TObjEneDimedian";

typedef struct O_800A846C {
    u8 pad0[0x18];
    void *vptr;
    u8 pad1c[0x3C4 - 0x1C];
    void *objs[2];
} O_800A846C;

struct VBase_18_c99286 { char pad[0x18]; };
struct VObj_18_c99286 : VBase_18_c99286 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78();
    virtual s32 m79(s32);
    virtual s32 m80();
};

struct Anim_800A8118 { s32 motions; void *actions; s32 initial_action; s32 counts; };
struct Pair_800A8118 { s32 a; s32 b; };
struct Bodies_800A8118 { s32 a; s32 b; s32 model; s32 textures; };
struct Res_800A8118 { u8 pad[0x42C]; Bodies_800A8118 *bodies; Pair_800A8118 *motions; };
struct Act_800A8118 { s32 a; s32 idx; f32 c; s32 d; };
struct Part_800A8118 { u8 pad[0xC]; f32 radius; u8 pad10[0x1C]; };
struct Sub_800A8530 { u8 b[0x1C]; };
struct Self_800A8530 { u8 pad[0x3CC]; Sub_800A8530 subs[4]; };

extern "C" {
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
u8 *load_enemy_bml_resource_named(void *, void *);
u8 *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
void draw_trail_with_colors(void *, s32, s32, s32, s32);
void *init_trail_buffer__11TBoss4Type3FPvifff(void *, s32, f32, f32, f32);
s32 *mem_alloc(s32);
void spawn_npc_enemy__6TLobbyFslllff(int, int, int, void *, f32, f32);
extern u8 lbl_8043AAA4[];
extern s32 dimedian_resource_handles[];
extern s32 dimedian_last_draw_tick[];

void init_enemy_base__13TUnk_80493450Fv(void *);
s32 create__12TObjEneSaverFPvPv(s32, s32);
}
int initialize_enemy_photon_effect(void *p);
extern "C" {
void init_collision_body_parts(void *, void *, s32);
void __construct_array(void *, void *, void *, int, int);
void init_and_activate__10TObjPlayerFv();
extern s32 TObjEneDimedian_name_ref;

void __dt__13TUnk_80493450Fv(void *, int);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
void __destroy_arr(void *, void *, int, int);
void __dt__13TUnk_80490470Fv(void *, int);
extern u8 __dt__13TUnk_804949A8Fv[];
O_800A846C *TObjPlayer__sub_800A846C(O_800A846C *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
void *TObjControl__ct(void *, void *);
void __dt__11TBoss4Type3FPvs(void*, int);
void *__nw__7TObjectFUl(int);
void mem_free(void*);

extern void *tl_04;

extern "C" void vfunc_6__13TUnk_804B9870FPsl();
extern "C" void vfunc_29__13TUnk_804806E8Fv();
extern "C" void vfunc_73__13TUnk_804806E8Fv();
extern "C" void consume_timer_field__13TUnk_804806E8Fl();
extern "C" void vfunc_67__13TUnk_804806E8Ff();
extern "C" void vfunc_66__13TUnk_804806E8Fv();
extern "C" void get_anim_node_position__13TUnk_804806E8FlP3Vec();
extern "C" void apply_slow_status__13TUnk_804806E8Fv();
extern "C" void update_shock_clock__13TUnk_804806E8Fv();
extern "C" void vfunc_43__13TUnk_804806E8Fv();
extern "C" void vfunc_18__13TUnk_804806E8FPUc();
extern "C" void vfunc_13__13TUnk_804AF8A0Fl();
extern "C" void vfunc_100__13TUnk_80493450Fv();
extern "C" void vfunc_101__15TObjEneDimedianFv();
extern "C" void vfunc_99__15TObjEneDimedianFv();
extern "C" void vfunc_98__15TObjEneDimedianFv();
extern "C" void vfunc_97__15TObjEneDimedianFv();
extern "C" void vfunc_96__15TObjEneDimedianFv();
extern "C" void vfunc_94__15TObjEneDimedianFv();
extern "C" void vfunc_93__15TObjEneDimedianFv();
extern "C" void vfunc_83__15TObjEneDimedianFv();

extern "C" void vfunc_89__13TUnk_80493450Fv();
extern "C" void update_turn_toward_target__13TUnk_80493450Fv();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__13TUnk_804806E8Fl();
extern "C" void apply_action_hold_status__13TUnk_804806E8Ff();
extern "C" void apply_anti_technique__13TUnk_804806E8Fl();
extern "C" void apply_attack_stat_status__13TUnk_804806E8FPv();
extern "C" void apply_confusion_status__13TUnk_804806E8Fv();
extern "C" void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
extern "C" void apply_movement_ailment__13TUnk_804806E8Fl();
extern "C" void apply_object_set_data__13TUnk_804B9870FPv();
extern "C" void apply_paralysis__13TUnk_804806E8Fv();
extern "C" void apply_poison_status__13TUnk_804806E8Fv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_shock_status__13TUnk_804806E8Fv();
extern "C" void apply_switch_attack__13TUnk_804806E8Fv();
extern "C" void vfunc_59__13TUnk_80493450Fv();
extern "C" void beast_idle_update__13TUnk_80493450Fv();
extern "C" void beast_select_target();
extern "C" void vfunc_60__13TUnk_80493450Fv();
extern "C" void beast_update_approach__13TUnk_80493450Fv();
extern "C" void beast_update_attack__13TUnk_80493450Fv();
extern "C" void beast_update_dead__13TUnk_80493450Fv();
extern "C" void beast_update_group_chase__13TUnk_80493450Fv();
extern "C" void beast_update_hurt__13TUnk_80493450Fv();
extern "C" void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
extern "C" void vfunc_79__9TObjEnemyFv();
extern "C" void classify_actor_view_detail__13TUnk_804B9870Ffff();
extern "C" void clear_all_status_effects__13TUnk_804806E8Fv();
extern "C" void vfunc_61__13TUnk_80493450Fv();
extern "C" void clear_harmful_statuses__13TUnk_804806E8Fv();
extern "C" void cure_paralysis__13TUnk_804806E8Fv();
extern "C" void cure_poison_ailment__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
extern "C" void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
extern "C" void vfunc_62__13TUnk_80493450Fv();
extern "C" void enter_state_8__10TObjPlayerFv();
extern "C" void vfunc_78__13TUnk_804806E8Fl();
extern "C" void vfunc_77__13TUnk_804806E8Fv();
extern "C" void vfunc_76__13TUnk_804806E8Fv();
extern "C" void vfunc_75__13TUnk_804806E8Ff();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void vfunc_9__13TUnk_804806E8Fv();
extern "C" void get_actor_level_index__13TUnk_804806E8Fv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__13TUnk_804806E8Fl();
extern "C" void is_actor_cadence_frame__13TUnk_804806E8Fl();
extern "C" void is_target_in_attack_range__13TUnk_804806E8Fv();

extern "C" void vfunc_95__15TObjEneDimedianFv();
extern "C" void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__13TUnk_804806E8FPvf();
extern "C" void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
extern "C" void apply_defense_stat_status__13TUnk_804806E8FPv();
extern "C" void render_shadows__9TObjEnemyFv();
extern "C" void request_stand_action__13TUnk_80493450Fv();
extern "C" void reset_motion_fields__13TUnk_804806E8Fv();
extern "C" void reset_pose__13TUnk_804806E8Fv();
extern "C" void roll_physical_accuracy__13TUnk_804806E8FPvlf();
extern "C" void run_task__13TUnk_80493450Fv();
extern "C" void select_melee_contact_body__13TUnk_804806E8FPvf();
extern "C" void beast_retire_corpse__15TObjEneDimedianFv();
extern "C" void update_movement_status__13TUnk_80493450Fv();
extern "C" void tick_freeze_state__10TObjPlayerFv();
extern "C" void trigger_switch_attack__13TUnk_804806E8Fv();
extern "C" void try_start_action__13TUnk_804806E8Fll();
extern "C" void update_action_hold_status__13TUnk_80493450Fv();
extern "C" void vfunc_37__13TUnk_804806E8Fv();
extern "C" void update_actor_ground_y__13TUnk_804806E8Fv();
extern "C" void update_attack_stat_status__13TUnk_804806E8Fv();
extern "C" void update_defense_stat_status__13TUnk_804806E8Fv();
extern "C" void update_flag30_timer__13TUnk_804806E8Fv();
extern "C" void update_object_view_visibility__13TUnk_804B9870Fff();
extern "C" void update_poison_status__13TUnk_804806E8Fv();
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
void *__vt__15TObjEneDimedian[103] = {
    (void *)0x0, (void *)0x0, (void *)&TObjPlayer__sub_800A846C, (void *)&run_task__13TUnk_80493450Fv,
    (void *)&draw_actor_model__10TObjPlayerFPv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&vfunc_9__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&vfunc_13__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&beast_select_target, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_80493450Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_80493450Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_80493450Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&tick_freeze_state__10TObjPlayerFv, (void *)&vfunc_59__13TUnk_80493450Fv,
    (void *)&vfunc_60__13TUnk_80493450Fv, (void *)&vfunc_61__13TUnk_80493450Fv, (void *)&vfunc_62__13TUnk_80493450Fv, (void *)&enter_state_8__10TObjPlayerFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&vfunc_73__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEnemyFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__15TObjEneDimedianFv,
    (void *)&beast_idle_update__13TUnk_80493450Fv, (void *)&update_turn_toward_target__13TUnk_80493450Fv, (void *)&beast_update_approach__13TUnk_80493450Fv, (void *)&beast_update_group_chase__13TUnk_80493450Fv,
    (void *)&beast_update_attack__13TUnk_80493450Fv, (void *)&vfunc_89__13TUnk_80493450Fv, (void *)&beast_update_hurt__13TUnk_80493450Fv, (void *)&beast_update_dead__13TUnk_80493450Fv,
    (void *)&beast_retire_corpse__15TObjEneDimedianFv, (void *)&vfunc_93__15TObjEneDimedianFv, (void *)&vfunc_94__15TObjEneDimedianFv, (void *)&vfunc_95__15TObjEneDimedianFv,
    (void *)&vfunc_96__15TObjEneDimedianFv, (void *)&vfunc_97__15TObjEneDimedianFv, (void *)&vfunc_98__15TObjEneDimedianFv, (void *)&vfunc_99__15TObjEneDimedianFv,
    (void *)&vfunc_100__13TUnk_80493450Fv, (void *)&vfunc_101__15TObjEneDimedianFv, (void *)&request_stand_action__13TUnk_80493450Fv,
};
#define __vt__15TObjEneDimedian ((u8 *)__vt__15TObjEneDimedian)

void *TObjEneDimedian::create(void *arg2_) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = TObjControl__ct(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x43C);
    if (o2 != NULL) {
        o2 = TObjEneDimedian__ct(o2, o, arg2_);
    }
    return o2;
}

extern u32 dimedian_boss_object_buf;
extern u32 lbl_805D5074;
extern u32 TObjEneDimedian__boss_objects;
extern u32 dimedian_buffer_ptr;
extern u32 dimedian_resource_ptr;

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
        __dt__11TBoss4Type3FPvs((void*)lbl_805D5088, 1);
        lbl_805D5088 = 0U;
    }
    if ((u32) dimedian_type3_object != 0U) {
        __dt__11TBoss4Type3FPvs((void*)dimedian_type3_object, 1);
        dimedian_type3_object = 0U;
    }
    if ((u32) dimedian_resource_ptr != 0U) {
        TLobby__sub_8001FE7C((void*)dimedian_resource_ptr, 1);
        dimedian_resource_ptr = 0U;
    }
}

#define RES_800A8118 ((Res_800A8118 *)dimedian_resource_ptr)
#define dimedian_resource_descriptor ((u8 *)dimedian_resource_descriptor)
#define dimedian_action_table ((Act_800A8118 *)dimedian_action_table)
#define dimedian_collision_body_table ((Part_800A8118 *)dimedian_collision_body_table)
#define CHAIN_800A8118(p) (*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)((s8 *)(*(u8 **)(p + 0x2C)) + 0x30)) + 0x30)) + 4)) + 4))

void TLobby::load_dimedian_resources() {
    u8 *r;
    void *p;
    s32 i;
    if (TObjEneDD::check_v2_mode() != 0) {
        (*(u8 **)&dimedian_resource_ptr) = load_enemy_bml_resource_named(dimedian_resource_descriptor, lbl_8043AAA4);
    } else {
        p = alloc__23TAdSinglePlyChrSelectGCFv(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, dimedian_resource_descriptor, 0, 0, 0);
        }
        (*(u8 **)&dimedian_resource_ptr) = (u8 *)p;
    }
    r = *(u8 **)((s8 *)(*(u8 **)&dimedian_resource_ptr) + 0x42C);
    dimedian_resource_handles[0] = CHAIN_800A8118(*(u8 **)((s8 *)r + 0x8));
    dimedian_resource_handles[1] = CHAIN_800A8118(*(u8 **)((s8 *)r + 0x18));
    dimedian_resource_handles[2] = CHAIN_800A8118(*(u8 **)((s8 *)r + 0x28));
    dimedian_last_draw_tick[0] = 0;
    dimedian_last_draw_tick[1] = 0;
    dimedian_last_draw_tick[2] = 0;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, 7.0f, 12.0f, 1.0f);
    }
    (*(void **)&dimedian_type3_object) = p;
    p = alloc__23TAdSinglePlyChrSelectGCFv(0x18);
    if (p != NULL) {
        p = init_trail_buffer__11TBoss4Type3FPvifff(p, 2, 7.0f, 12.0f, 1.0f);
    }
    (*(void **)&lbl_805D5088) = p;
    draw_trail_with_colors((*(void **)&dimedian_type3_object), RES_800A8118->bodies->model,
        RES_800A8118->motions[dimedian_action_table[3].idx].b, 5, 8);
    draw_trail_with_colors((*(void **)&lbl_805D5088), RES_800A8118->bodies->model,
        RES_800A8118->motions[dimedian_action_table[4].idx].b, 0xA, 0xD);
    (*(s32 **)&dimedian_boss_object_buf) = mem_alloc(0xC);
    (*(s32 **)&lbl_805D5074) = mem_alloc(0xC);
    (*(s32 **)&TObjEneDimedian__boss_objects) = mem_alloc(0xC);
    (*(s32 **)&dimedian_buffer_ptr) = mem_alloc(0xC);
    (*(s32 **)&dimedian_boss_object_buf)[0] = register_boss__6TLobbyFl(0x53);
    (*(s32 **)&dimedian_boss_object_buf)[1] = register_boss__6TLobbyFl(0x54);
    (*(s32 **)&dimedian_boss_object_buf)[2] = register_boss__6TLobbyFl(0x55);
    (*(s32 **)&lbl_805D5074)[0] = dispatch_shared_handler_b__6TLobbyFl(0x5A);
    (*(s32 **)&lbl_805D5074)[1] = dispatch_shared_handler_b__6TLobbyFl(0x5B);
    (*(s32 **)&lbl_805D5074)[2] = dispatch_shared_handler_b__6TLobbyFl(0x5C);
    (*(s32 **)&TObjEneDimedian__boss_objects)[0] = register_object__6TLobbyFl(0x52);
    (*(s32 **)&TObjEneDimedian__boss_objects)[1] = register_object__6TLobbyFl(0x53);
    (*(s32 **)&TObjEneDimedian__boss_objects)[2] = register_object__6TLobbyFl(0x54);
    (*(s32 **)&dimedian_buffer_ptr)[0] = dispatch_shared_handler_a__6TLobbyFl(0x52);
    (*(s32 **)&dimedian_buffer_ptr)[1] = dispatch_shared_handler_a__6TLobbyFl(0x53);
    (*(s32 **)&dimedian_buffer_ptr)[2] = dispatch_shared_handler_a__6TLobbyFl(0x54);
    {
        s16 ids[3] = { 0x1B, 0x1C, 0x1D };
        Anim_800A8118 anim = { (s32)RES_800A8118->motions, dimedian_action_table, 2, 0xC0000 };
        for (i = 0; i < 3; i++) {
            u8 *b = *(u8 **)((s8 *)(*(u8 **)&dimedian_resource_ptr) + 0x42C) + i * 0x10;
            spawn_npc_enemy__6TLobbyFslllff(ids[i], *(s32 *)((s8 *)b + 8), *(s32 *)((s8 *)b + 0xC), &anim,
                dimedian_collision_body_table[i].radius, 0.0f);
        }
    }
}
#undef CHAIN_800A8118
#undef RES_800A8118
#undef dimedian_resource_descriptor
#undef dimedian_action_table
#undef dimedian_collision_body_table

O_800A846C *TObjPlayer__sub_800A846C(O_800A846C *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vptr = __vt__15TObjEneDimedian;
        for (i = 0; i < 2; i++) {
            if (arg0->objs[i] != NULL) {
                queue_destruction__7TObjectFv(arg0->objs[i]);
                arg0->objs[i] = NULL;
            }
        }
        ((TUnk_80493450 *)arg0)->unlink_enemy_group_relations();
        free_collision_body_parts(arg0);
        __destroy_arr((u8 *)arg0 + 0x3CC, __dt__13TUnk_804949A8Fv, 0x1C, 4);
        __dt__13TUnk_80490470Fv((u8 *)arg0 + 0x3A8, -1);
        __dt__13TUnk_80493450Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#define dimedian_action_table ((u8 *)dimedian_action_table)
#define dimedian_movement_params ((u8 *)dimedian_movement_params)
#define dimedian_collision_body_table ((u8 *)dimedian_collision_body_table)
#define arg0 ((u8 *)arg0_)
#define arg1 ((s32)arg1_)
#define arg2 ((s32)arg2_)
void *TObjEneDimedian__ct(void *arg0_, void *arg1_, void *arg2_) {
    s32 color;
    s32 i;
    ((void (*)(void *, s32, s32))init_enemy_base__13TUnk_80493450Fv)(arg0, arg1, arg2);
    *(u8 **)((s8 *)arg0 + 0x18) = __vt__15TObjEneDimedian;
    ((TUnk_80490470 *)(arg0 + 0x3A8))->init_vtable_and_field18();
    __construct_array(arg0 + 0x3CC, (void *)&init_and_activate__10TObjPlayerFv, (void *)&__dt__13TUnk_804949A8Fv, 0x1C, 4);
    *(s32 *)((s8 *)arg0 + 0) = TObjEneDimedian_name_ref;
    ((VObj_18_c99286 *)arg0)->m79(arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x334) = *(s32 *)((s8 *)arg0 + 0x368);
    ((TObjEneDimedian *)arg0)->sub_800A7B54();
    ((TObjEneDimedian *)arg0)->load_dimedian_param_entry(*(s32 *)((s8 *)arg0 + 0x368));
    *(u8 **)((s8 *)arg0 + 0xD8) = dimedian_action_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)(*(u8 **)((s8 *)arg0 + 0xD8)));
    *(s32 *)((s8 *)arg0 + 0xDC) = *(s32 *)((s8 *)(*(u8 **)&dimedian_resource_ptr) + 0x430);
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(*(s16 *)((s8 *)arg0 + 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(*(s16 *)((s8 *)arg0 + 0xB8));
    init_collision_body_parts(arg0, dimedian_collision_body_table + *(s32 *)((s8 *)arg0 + 0x334) * 0x2C, 1);
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)((*(s32 **)&dimedian_boss_object_buf)[*(s32 *)((s8 *)arg0 + 0x334)]), (u8 *)((*(s32 **)&lbl_805D5074)[*(s32 *)((s8 *)arg0 + 0x334)]), (u8 *)((*(s32 **)&TObjEneDimedian__boss_objects)[*(s32 *)((s8 *)arg0 + 0x334)]));
    *(u8 **)((s8 *)arg0 + 0x350) = dimedian_movement_params + *(s32 *)((s8 *)arg0 + 0x334) * 0x1C;
    *(s16 *)((s8 *)arg0 + 0x33E) = *(s16 *)((s8 *)arg0 + 0x32C);
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    initialize_enemy_photon_effect(arg0);
    *(s32 *)((s8 *)arg0 + 0x2AC) = (s32)(182.04445f * (3.6e+02f * TObjPlayer::calc_boss4_scale((s32)arg0)));
    *(s16 *)((s8 *)arg0 + 0x33A) = 0xF;
    *(s16 *)((s8 *)arg0 + 0x33C) = *(s16 *)((s8 *)arg0 + 0x33A);
    *(s16 *)((s8 *)arg0 + 0x328) = 0;
    *(s16 *)((s8 *)arg0 + 0x374) = 0;
    *(s16 *)((s8 *)arg0 + 0x376) = 0;
    *(s32 *)((s8 *)arg0 + 0x378) = 0;
    *(s32 *)((s8 *)arg0 + 0x37C) = 0;
    ((TUnk_804806E8 *)arg0)->add_flags_2e4(8);
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
    *(s32 *)((s8 *)arg0 + 0x3C4) = create__12TObjEneSaverFPvPv(0xA0303030, color);
    *(s32 *)((s8 *)arg0 + 0x3C8) = create__12TObjEneSaverFPvPv(0xA0303030, color);
    *(s32 *)((s8 *)arg0 + 0x390) = 1;
    *(f32 *)((s8 *)arg0 + 0x398) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][0];
    *(f32 *)((s8 *)arg0 + 0x3A0) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][1];
    *(f32 *)((s8 *)arg0 + 0x39C) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][2];
    *(f32 *)((s8 *)arg0 + 0x3A4) = ((f32 **)(*(s32 **)&dimedian_buffer_ptr))[*(s32 *)((s8 *)arg0 + 0x334)][3];
    for (i = 0; i < 4; i++) {
        ((TObjPlayer *)(&((Self_800A8530 *)arg0)->subs[i]))->activate_and_dispatch();
    }
    ((VObj_18_c99286 *)arg0)->m80();
    return arg0;
}
}
#undef arg0
#undef arg1
#undef arg2
