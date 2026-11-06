#include "types.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/object/TObjFish.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/reflection.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneRecon_8029E89C.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/enemy/TObjEneRecon_8031BE8C.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/vector.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneGibbles.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneRecobox.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEneRecon_8031D780.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/player/TObjChara.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRecon_8031E574.h"
#include "pso/enemy/TUnk_80494938.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEneRecon_8031BC38.h"
#include "pso/enemy/TObjEneRecon_8031FCB0.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 TObjFish__sub_8001EDB0(u32, s32);
s32 get_bml_model(u32, s32);
s32 scale_matrix(s32, f32, f32, f32);
s32 push_matrix();
extern u8 *TObjEneRecon__recobox_static_instance;
extern const f32 lbl_805DF3B8;
void TObjEneRecon::render_shadows() {
  s32 bml_model;
  if (TObjEneRecon__recobox_static_instance != NULL)
  {
    s32 temp_r30;
    bml_model = get_bml_model((u32)TObjEneRecon__recobox_static_instance, 2);
    temp_r30 = TObjFish__sub_8001EDB0((u32)TObjEneRecon__recobox_static_instance, 2);
    push_matrix();
    translate_matrix(0, *((f32 *) (((s8 *) this) + 0x38)), *((f32 *) (((s8 *) this) + 0x3C)), *((f32 *) (((s8 *) this) + 0x40)));
    rotate_matrix_zyx(0, *((s32 *) (((s8 *) this) + 0x5C)), this->rotation_y, this->rotation_z);
    scale_matrix(0, lbl_805DF3B8, lbl_805DF3B8, lbl_805DF3B8);
    TObjFish::set_global_param(temp_r30);
    draw_chunk_object((void *)bml_model);
    pop_matrix();
  }
}

}

struct VBase800AFB60_8031bd64 { char pad[0x18]; };
struct VObj800AFB60_8031bd64 : VBase800AFB60_8031bd64 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {

s32 post_translate_matrix(void *);

extern const f32 lbl_805DF3BC;
extern const f32 TObjEneRecon__data_805DF3C0;

void TObjEneRecon::vfunc_106() {
    u8 *arg0 = (u8 *)this;
    if (((VObj800AFB60_8031bd64 *) arg0)->m8(lbl_805DF3BC, TObjEneRecon__data_805DF3C0) != 0) {
        ((TObjEneDD *)(arg0))->draw_ground_shadow(0, 0);
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw_chunk_object(this->model);
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

}

extern "C" {

s32 get_mode__11TCameraCtrlFPv(void *);

s32 TObjEneRecon::render_model_if_visible() {
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        if (push_reflection_matrix((Vec *)(((u8 *)this) + 0x41C)) != 0) {
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)((u8 *)this) + 0x24)));
            push_matrix();
            translate_matrix(0, (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x38)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x448)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x40)));
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x60)));
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

}

struct VBase_14_fddec9 { char pad[0x14]; };

struct VObj_14_fddec9 : VBase_14_fddec9 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8();
};

struct VBase_18_1fdb47 { char pad[0x18]; };

struct VObj_18_1fdb47 : VBase_18_1fdb47 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual s32 m104();
};

struct Recon_8031BE8C { u8 pad[0x480]; VObj_14_fddec9 fade; };

extern "C" {
s32 is_main_phase_15__9TObjEneDDFv();
s32 defer_render__7TObjectFv(void *);
extern Vec lbl_804760FC;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 recon_intro_stage;
extern u8 *recon_model_matrix_ptr;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 TObjEneRecon__data_805DF3C4;
#pragma push
#pragma opt_common_subs off
void render__12TObjEneReconFv(u8 *ene_recon) {
    s32 var_r29;
    s32 var_r31;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18_1fdb47 *)(ene_recon))->m104();
        return;
    }
    if (!(*(s32 *)((s8 *)ene_recon + 0x444) & 1)) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            var_r31 = ((VObj_18_1fdb47 *)(ene_recon))->m9(lbl_805D9E88, lbl_805D9E84, TObjEneRecon__data_805DF3C0);
        } else if (((VObj_18_1fdb47 *)(ene_recon))->m8(lbl_805DF3BC, TObjEneRecon__data_805DF3C0) != 0) {
            var_r31 = 1;
        } else {
            var_r31 = 0;
        }
        if (var_r31 != 0) {
            var_r29 = 1;
            if (((TObjEneRecon *)ene_recon)->render_model_if_visible() == 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                if (((s16) *(s16 *)((s8 *)ene_recon + 0x326) == 5) && (((Recon_8031BE8C *)ene_recon)->fade.m8() != 0)) {
                    ((Recon_8031BE8C *)ene_recon)->fade.m6();
                    if (defer_render__7TObjectFv(ene_recon) != 0) {
                        var_r29 = 0;
                    }
                }
                if (var_r29 != 0) {
                    if ((*(s32 *)((s8 *)ene_recon + 0x444) & 2) && !(*(s32 *)((s8 *)ene_recon + 0x418) & 0x4000)) {
                        Vec v = lbl_804760FC;
                        ((TObjEneDD *)(ene_recon))->draw_ground_shadow(&v, 0);
                    }
                    ((TObjEneDD *)ene_recon)->update_secondary_light();
                    TObjFish::set_global_param((int) (*(s32 *)((s8 *)ene_recon + 0x24)));
                    push_matrix();
                    translate_matrix(0, (f32) (*(f32 *)((s8 *)ene_recon + 0x38)), (f32) (*(f32 *)((s8 *)ene_recon + 0x448)), (f32) (*(f32 *)((s8 *)ene_recon + 0x40)));
                    rotate_matrix_y(0, (int) (*(s32 *)((s8 *)ene_recon + 0x60)));
                    TObjEneDD::clear_global_flag_400();
                    recon_intro_stage = 0;
                    recon_model_matrix_ptr = ene_recon + 0x40C;
                    *(f32 *)((s8 *)ene_recon + 0x40C) = (f32) TObjEneRecon__data_805DF3C4;
                    *(f32 *)((s8 *)ene_recon + 0x410) = (f32) TObjEneRecon__data_805DF3C4;
                    *(f32 *)((s8 *)ene_recon + 0x414) = (f32) TObjEneRecon__data_805DF3C4;
                    set_chunk_model_node_callback((s32)((void *)TObjEneRecon::advance_intro_stage));
                    TObjPlayer::toggle_particle_effect();
                    model_render_flags |= 0x01000000;
                    if (var_r31 == 1) {
                        ((TObjMotion *)ene_recon)->draw();
                    } else {
                        ((TObjEnemy *)ene_recon)->draw_motion_model();
                    }
                    model_render_flags &= 0xFEFFFFFF;
                    TParticleCtrl::end_effect_render();
                    set_chunk_model_node_callback(NULL);
                    pop_matrix();
                    ((TObjEneDD *)ene_recon)->update_primary_light();
                }
                if (((s16) *(s16 *)((s8 *)ene_recon + 0x326) == 5) && (((Recon_8031BE8C *)ene_recon)->fade.m8() != 0)) {
                    ((Recon_8031BE8C *)ene_recon)->fade.m7();
                }
                model_render_flags = saved_model_render_flags;
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            }
        }
    }
}
#pragma pop

}

extern "C" {

s32 update_camera_sequence__9TObjEneDDFv();


void TObjEneRecon::advance_intro_stage() {
    switch ((s32) recon_intro_stage) {
    case 0:
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        matrix_mult_vec(0, (Vec *)recon_model_matrix_ptr, (Vec *)recon_model_matrix_ptr);
        pop_matrix();
        break;
    case 10:
        TParticleCtrl::begin_effect_render();
        break;
    }
    recon_intro_stage += 1;
}

}

void TObjEneRecon::vfunc_105() {  }

struct Stack_8031C190 {
    s32 sp8;
    f32 spC;
};

extern s32 actor_frame_tick;
void TObjEneRecon::update_ground_probe() {
    u8 *arg0 = (u8 *)this;
    Stack_8031C190 stack;
    u8 *temp_r3;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy((Vec *)&stack.sp8, (const Vec *)&this->position);
        stack.spC += TObjEneRecon__data_805DF3C0;
        temp_r3 = (u8 *)(csnVectorUnder((Vec *)&stack.sp8, (u32 *)&this->m_120, 0x4000));
        if (temp_r3 != NULL) {
            *(s32 *)((s8 *)arg0 + 0x418) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 0x18);
            VecCopy((Vec *)&this->m_438, (const Vec *)(*(u8 **)((s8 *)temp_r3 + 4)));
        } else {
            VecCopy((Vec *)&this->m_438, (const Vec *)&this->position);
        }
    }
    if (*(s32 *)((s8 *)arg0 + 0x418) & 0x4000) {
        TObjEneRecon::set_active();
    }
}

u8 TObjEneRecon::is_anim_5() {
    return (u8) (this->mode == 5);
}

struct T_8031C250 { u8 pad[0x326]; s16 state; };

#define F(T, o) (*(T *)(arg0 + (o)))
struct Pair_8031CF30 { s32 a; f32 b; };

struct VB_8031CF30 {
    u8 pad[0x18];
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20();
    virtual void m21(void *, Pair_8031CF30 *, s32, s32, s32);
    virtual void m22();
    virtual void m23(void *, f32);
    virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30();
    virtual s32 m31();
    virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86();
    virtual void m87();
    virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93();
    virtual void m94();
};

struct Data_8031CF30 { u8 pad[0x1C]; s32 f1C; };

extern "C" {
extern f32 *TObjEneRecon__data_805D6AFC;
f32 TObjEneRecon__sub_8031C2BC(void);
f32 TObjEneRecon__sub_8031C2C8(void);
f32 TObjEneRecon__sub_8031C2D4(void);
extern const f32 lbl_805DF3C8;
u8 TObjEneRecon__sub_8031C250(T_8031C250 *self);
s16 get_attack_params_atp_min(void *p);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
void *spawn_particle_effect(void *pos, s32 id);
void enemy_clear_target__12TObjEneDD_STFUs(void *);
f32 horizontal_distance_squared(void *, void *);
void play_sound_effect(s32, void *, s32, s32);
s32 is_valid_and_active__10TObjPlayerFUl();
s32 TObjEneRecon__sub_8031DA90(u8 *arg0);
f32 approach_value__12TObjEneReconFff(void *, f32, f32);
extern s32 lbl_805D5868;
extern const f32 lbl_805DF3FC;
extern const f32 lbl_805DF400;
extern const f32 lbl_805DF404;
extern const f32 lbl_805DF408;
extern const f32 lbl_805DF40C;
void TObjEneRecon__sub_8031CF30(u8 *arg0, s32 arg1);

u8 TObjEneRecon__sub_8031C250(T_8031C250 *self) {
    return self->state == 8 || self->state == 7;
}

s32 TObjEneRecon::calc_scaled_value() {
    return (s32) (lbl_805DF3C8 * (f32) *(s32 *)((s8 *)TObjEneRecon__data_805D6AFC + 0x18));
}

f32 TObjEneRecon__sub_8031C2BC(void) {
    return *(f32 *)((s8 *)TObjEneRecon__data_805D6AFC + 0xC);
}
f32 TObjEneRecon__sub_8031C2C8(void) {
    return *(f32 *)((s8 *)TObjEneRecon__data_805D6AFC + 8);
}
f32 TObjEneRecon__sub_8031C2D4(void) {
    return *(f32 *)((s8 *)TObjEneRecon__data_805D6AFC + 4);
}

void *find_entity_by_id(u16 id);
void queue_destruction__7TObjectFv(void *);
void transition_enemy_state__9TObjEneDDFl(void *, s32);
void select_next_target__12TObjEneReconFv(void *, s32);
void TObjEneRecon::handle_message(s32 arg1) {
    u32 temp;
    switch (arg1) {
    case 4:
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 1);
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
        if ((temp = (u32)find_entity_by_id(*(u16 *)((s8 *)this + 0x434))) != 0U) {
            ((TObjEneRecon *)temp)->remove_child_entity((u8 *)this);
        }
        break;
    case 5:
    case 0:
        break;
    case 3:
        ((s32 (*)()) queue_destruction__7TObjectFv)();
        break;
    }
}

}

struct VBase_18_414afc { char pad[0x18]; };

struct VObj_18_414afc : VBase_18_414afc {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual s32 m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual s32 m102(f32);
};

#define F(T, o) (*(T *)(arg0 + (o)))
struct Vec_8031C364 { f32 x, y, z; };

extern "C" {
f32 normalize_vector_xz__FP3Vec(void *, s32);
void clear_attack_receipts__9TObjEneDDFv(void);
void noop__12TBoss8DragonFv(void *);
void set_flag2__12TObjEneReconFv(void *, f32, f32, f32);
void TObjEneRecon__sub_8031C624(u8 *arg0, s32 arg1);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
void TBoss8Dragon__sub_800BB7D8(void *, int, f32);
void TBoss8Dragon__sub_800BB7DC(void *);
s32 project_actor_to_ground(void *, void *, void *);
extern u8 recon_breakup_params[];
extern struct VObj_8031E650 *boss3_volopt_instance;
extern const f32 lbl_805DF3CC;
extern const f32 TObjEneRecon__data_805DF3D0;
extern const f32 TObjEneRecon__data_805DF3D4;
void TObjEneRecon__sub_8031C364(u8 *arg0, s32 arg1);

void TObjEneRecon__sub_8031C364(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 5;
        ((TObjEneDD *)(arg0))->vfunc_96();
        F(s32, 0x444) &= ~3;
        F(s32, 0x80) = 0;
        ((TObjPlayer *)arg0)->refresh_lobby_state();
        TBoss8Dragon__sub_800BB7DC(arg0);
        TBoss8Dragon__sub_800BB7D8(arg0, 0xF1, lbl_805DF3CC);
        F(s32, 0x3C0) = 0;
        F(f32, 0x3E0) = TObjEneRecon__data_805DF3C4;
        F(f32, 0x44C) = F(f32, 0x308);
        F(f32, 0x454) = F(f32, 0x310);
        F(f32, 0x3E4) = ((f32 (*)(void *))normalize_vector_xz__FP3Vec)(arg0 + 0x44C);
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80C), arg0 + 0x38, 0, 0);
        break;
    case 3:
        if (F(s32, 0x3C0) == 3) {
            transition_enemy_state__9TObjEneDDFl(arg0, 8);
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (F(s32, 0x3C0)) {
        case 0:
        case 1:
            set_flag2__12TObjEneReconFv(arg0, F(f32, 0x44C), F(f32, 0x454), F(f32, 0x3E4));
            {
                Vec_8031C364 v = F(Vec_8031C364, 0x38);
                v.y += F(f32, 0x448);
                if (project_actor_to_ground(arg0, &v, arg0 + 0x248) != 0) {
                    F(f32, 0x3C) = v.y;
                }
            }
            F(f32, 0x3E0) -= TObjEneRecon__data_805DF3D0;
            F(f32, 0x448) += F(f32, 0x3E0);
            if (F(f32, 0x448) < TObjEneRecon__data_805DF3D4 + F(f32, 0x3C)) {
                F(f32, 0x448) = TObjEneRecon__data_805DF3D4 + F(f32, 0x3C);
                if (F(s32, 0x3C0) == 0) {
                    F(s32, 0x3C0) = 1;
                    F(f32, 0x3E0) = lbl_805DF3CC;
                    F(f32, 0x3E4) *= 0.98f;
                    if (F(f32, 0x44C) * F(f32, 0x44C) + F(f32, 0x454) * F(f32, 0x454) <= 0.3f) {
                        F(f32, 0x44C) = 0.5f * sin_table_lookup(F(s32, 0x60));
                        F(f32, 0x454) = 0.5f * cos_table_lookup(F(s32, 0x60));
                    }
                } else {
                    F(s32, 0x3C0) = 2;
                }
            }
            F(f32, 0x3E4) *= 0.98f;
            ((TObjEneRecon *)arg0)->clamp_min_height();
            break;
        case 2:
            F(s32, 0x444) |= 1;
            F(s32, 0x3C0) = 3;
            spawn_particle_effect_with_flags(arg0 + 0x38, 0x45, 0x40);
            spawn_particle_effect_with_flags(arg0 + 0x38, 0x46, 0x40);
            play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80D), arg0 + 0x38, 0, 0);
            TBoss3Volopt::create_breakup_mdl((s32)boss3_volopt_instance, (s32)recon_breakup_params, (s32)(F(s32, 0x24)), (s32)(arg0 + 0x2FC), (s32)(F(s32, 0x60)));
            break;
        }
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneRecon__sub_8031C624(u8 *arg0, s32 arg1) {
    s32 n;
    f32 v;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 4;
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x444) &= ~1;
        *(s32 *)((s8 *)arg0 + 0x444) |= 2;
        ((TObjEneDD *)arg0)->set_field_378(*(s16 *)((s8 *)arg0 + 0x326));
        noop__12TBoss8DragonFv(arg0);
        play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003E425), arg0 + 0x38, 0, 0);
        *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0xB0) & 0x10) {
            if (((VObj_18_414afc *)(arg0))->m97() != 0) {
                ((VObj_18_414afc *)(arg0))->m102(200.0f);
            }
            n = *(s32 *)((s8 *)arg0 + 0x378);
            if (n == 2) {
                select_next_target__12TObjEneReconFv(arg0, n);
            } else {
                transition_enemy_state__9TObjEneDDFl(arg0, n);
            }
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        n = *(s32 *)((s8 *)arg0 + 0x3C0);
        *(s32 *)((s8 *)arg0 + 0x3C0) = n + 1;
        *(f32 *)((s8 *)arg0 + 0x44C) = *(f32 *)((s8 *)arg0 + 0x308);
        *(f32 *)((s8 *)arg0 + 0x454) = *(f32 *)((s8 *)arg0 + 0x310);
        v = normalize_vector_xz__FP3Vec(arg0 + 0x44C, n);
        set_flag2__12TObjEneReconFv(arg0, *(f32 *)((s8 *)arg0 + 0x44C), *(f32 *)((s8 *)arg0 + 0x454), v);
        ((TObjEneRecon *)arg0)->clamp_min_height();
        *(f32 *)((s8 *)arg0 + 0x308) *= 0.5f;
        *(f32 *)((s8 *)arg0 + 0x310) *= 0.5f;
        ((TObjEneDD *)(arg0))->vfunc_89();
        break;
    case 5:
        clear_attack_receipts__9TObjEneDDFv();
        break;
    }
}
#pragma pop

}

struct VBase_8031c7bc { char pad[0x18]; };
struct VObj_8031c7bc : VBase_8031c7bc {
#define VM(i) virtual s32 m##i();
    VM(0)VM(1)VM(2)VM(3)VM(4)VM(5)VM(6)VM(7)VM(8)VM(9)VM(10)VM(11)VM(12)VM(13)VM(14)VM(15)
    VM(16)VM(17)VM(18)VM(19)VM(20)VM(21)VM(22)VM(23)VM(24)VM(25)VM(26)VM(27)VM(28)VM(29)VM(30)
    VM(31)VM(32)VM(33)VM(34)VM(35)VM(36)VM(37)VM(38)VM(39)VM(40)VM(41)VM(42)VM(43)VM(44)VM(45)
    VM(46)VM(47)VM(48)VM(49)VM(50)VM(51)VM(52)VM(53)VM(54)VM(55)VM(56)VM(57)VM(58)VM(59)VM(60)
    VM(61)VM(62)VM(63)VM(64)VM(65)VM(66)VM(67)VM(68)VM(69)VM(70)VM(71)VM(72)VM(73)VM(74)VM(75)
    VM(76)VM(77)VM(78)VM(79)VM(80)VM(81)VM(82)VM(83)VM(84)VM(85)VM(86)VM(87)VM(88)VM(89)VM(90)
    VM(91)VM(92)VM(93)VM(94)
#undef VM
};
struct WBase_8031c7bc { char pad[0x14]; };
struct WObj_8031c7bc : WBase_8031c7bc {
#define WM(i) virtual s32 w##i();
    WM(0)WM(1)WM(2)WM(3)WM(4)
#undef WM
};

extern "C" {
s32 is_anim_6__12TObjEneReconFv(TObjEneRecon *);

void run_task__12TObjEneReconFPvi(u8 *arg0, s32 arg1);
void *create_timed_particle_emitter(void *owner, s32 id, s32 b, s32 c);
s32 remove_tracked_target__12TObjEneReconFPvPv(int, void *);

void run_task__12TObjEneReconFPvi(u8 *target, s32 arg1) {
    s32 entity;

    switch (arg1) {
    case 4:
        ((TObjEneRecon *)target)->requested_action = 1;
        ((VObj_8031c7bc *) target)->m94();
        *(s32 *)((s8 *)target + 0x444) = (s32) (*(s32 *)((s8 *)target + 0x444) & 0xFFFFFFFE);
        *(s32 *)((s8 *)target + 0x444) = (s32) (*(s32 *)((s8 *)target + 0x444) | 2);
        ((TObjEneRecon *)target)->actorFlags = (s32) (((TObjEneRecon *)target)->actorFlags | 0x01000000);
        ((WObj_8031c7bc *) (target + 0x480))->w2();
        create_timed_particle_emitter((target + 0x38), 0x79, 0, 0xF);
        return;
    case 3:
        entity = (s32)find_entity_by_id((*(u16 *)((s8 *)target + 0x434)));
        if (entity == 0) {
            queue_destruction__7TObjectFv(target);
            return;
        }
        if (is_anim_6__12TObjEneReconFv((TObjEneRecon *)entity) == 1) {
            transition_enemy_state__9TObjEneDDFl(target, 7);
            return;
        }
        if (((WObj_8031c7bc *) (target + 0x480))->w4() != 0) {
            *(s32 *)((s8 *)target + 0x444) = (s32) (*(s32 *)((s8 *)target + 0x444) | 1);
            remove_tracked_target__12TObjEneReconFPvPv(entity, target);
            queue_destruction__7TObjectFv(target);
        }
    case 5:
        return;
    case 0:
        ((TObjMotion *)target)->advance_animation();
        ((TObjEneDD *)target)->update_velocity();
        ((VObj_8031c7bc *) target)->m86();
        ((TObjEneRecon *)target)->clamp_min_height();
        ((TObjEneDD *)target)->transform_part_positions();
        ((TObjEneRecon *)target)->spawn_trap_b();
        break;
    }
}

}

struct VBase_18_83f71d
{
  char pad[0x18];
};

struct VObj_18_83f71d : VBase_18_83f71d {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual s32 m87(s32);
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual s32 m102(f32);
};

#define F(T, o) (*(T *)(arg0 + (o)))
struct VBase_18_2afebf { char pad[0x18]; };

struct VObj_18_2afebf : VBase_18_2afebf {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual s32 m102(f32);
};

struct Obj_8031C920 { u8 pad[0x38]; f32 x, y, z; };

struct Prm_8031C920 { f32 f0; f32 f4; };

extern "C" {
void TObjEneRecon__sub_8031D380(u8 *arg0, s32 arg1);
f64 atan2_float(f32, f32);
extern const f32 lbl_805DF410;
extern const f32 lbl_805DF414;
extern const f32 lbl_805DF418;
extern const f32 lbl_805DF41C;
s32 approach_angle_limited(s32, s32, s32);
extern const f32 lbl_805DF3F8;
void TObjEneRecon__sub_8031CCFC(u8 *arg0, s32 arg1);
f32 random_ratio__9TObjCharaFv(s32 arg0);
extern const f32 lbl_805DF3E8;
extern const f32 lbl_805DF3EC;
extern const f32 lbl_805DF3F0;
extern const f32 lbl_805DF3F4;
void TObjEneRecon__sub_8031C920(u8 *arg0, s32 arg1);
typedef struct VBase_18_83f71d VBase_18_83f71d;
typedef struct VObj_18_83f71d VObj_18_83f71d;

void TObjEneRecon__sub_8031C920(u8 *arg0, s32 arg1) {
    f32 r;
    f32 h;
    f32 k;
    Obj_8031C920 *t;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 1;
        ((VObj_18_2afebf *)(arg0))->m94();
        F(u32, 0x444) &= ~1;
        F(u32, 0x444) |= 2;
        F(u32, 0x30) |= 0x01000000;
        if (F(s16, 0x326) == 4) {
            F(s32, 0x3C0) = 2;
        } else {
            F(s32, 0x3C0) = 0;
            F(s32, 0x3D0) = F(s32, 0x60) + 0x8000;
            F(s32, 0x3D4) = 0;
            F(s32, 0x3D8) = 0;
        }
        break;
    case 3:
        if (F(u8 *, 0x390) == NULL) {
            ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 5);
        } else if (F(s32, 0x46C) > 0x8000 || F(s32, 0x46C) < -0x8000) {
            ((void (*)(void *)) select_next_target__12TObjEneReconFv)(arg0);
        } else if (F(s32, 0x470) > 0x5000 || F(s32, 0x470) < -0x5000) {
            ((TObjEneRecon *)arg0)->retarget();
        }
        break;
    case 1:
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() != 0 || ((VObj_18_2afebf *)(arg0))->m102(200.0f) != 0) {
            switch (F(s32, 0x3C0)) {
            case 0:
                ((TObjEneRecon *)arg0)->set_orbit_destination(F(s32, 0x3D0));
                ((TObjEneDD *)arg0)->update_velocity();
                k = lbl_805DF3E8 * F(f32, 0x468);
                r = F(Prm_8031C920 *, 0x350)->f4;
                h = TObjEneRecon__data_805DF3C4;
                if (F(f32, 0x3AC) < k * k) {
                    if (random_ratio__9TObjCharaFv((s32)arg0) > 0.5f) {
                        F(s32, 0x3D4) = (lbl_805DF3EC * r) / (lbl_805DF3F0 * F(f32, 0x468));
                    } else {
                        F(s32, 0x3D4) = (lbl_805DF3F4 * r) / (lbl_805DF3F0 * F(f32, 0x468));
                    }
                    F(s32, 0x3C0) = 1;
                }
                break;
            case 1:
                F(s32, 0x3D0) += F(s32, 0x3D4) / 2;
                F(s32, 0x46C) += F(s32, 0x3D4) / 2;
                F(s32, 0x470) += F(s32, 0x3D4) / 2;
                ((TObjEneRecon *)arg0)->set_orbit_destination(F(s32, 0x3D0));
                ((TObjEneDD *)arg0)->update_velocity();
                r = F(Prm_8031C920 *, 0x350)->f4;
                h = TObjEneRecon__data_805DF3C4;
                if (F(f32, 0x3AC) < r) {
                    F(s32, 0x3C0) = 2;
                }
                break;
            case 2:
                F(s32, 0x3D0) += F(s32, 0x3D4);
                F(s32, 0x46C) += F(s32, 0x3D4);
                F(s32, 0x470) += F(s32, 0x3D4);
                ((TObjEneRecon *)arg0)->set_orbit_destination(F(s32, 0x3D0));
                ((TObjEneDD *)arg0)->update_velocity();
                r = F(Prm_8031C920 *, 0x350)->f4;
                h = lbl_805DF3F8 * sin_table_lookup(F(s32, 0x3D8));
                F(s32, 0x3D8) += 0x380;
                break;
            }
            VecCopy((Vec *)(arg0 + 0x44C), (const Vec *)(arg0 + 0x3A0));
            set_flag2__12TObjEneReconFv(arg0, F(f32, 0x44C), F(f32, 0x454), r);
            F(f32, 0x448) = approach_value__12TObjEneReconFff(arg0, F(f32, 0x448), F(f32, 0x398) + h);
            ((TObjEneRecon *)arg0)->clamp_min_height();
            t = F(Obj_8031C920 *, 0x390);
            F(s32, 0x60) = 10430.38043493439 * atan2_float(t->x - F(f32, 0x38), t->z - F(f32, 0x40));
            ((VObj_18_2afebf *)(arg0))->m87();
            ((TObjEneRecon *)arg0)->spawn_trap_b();
        }
        break;
    }
}

void TObjEneRecon__sub_8031CCFC(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneEpsilon *)arg0)->requested_action = 1;
        ((TObjEneDD_ST *)arg0)->vfunc_96();
        *(u32 *)((s8 *)arg0 + 0x444) &= ~1;
        *(u32 *)((s8 *)arg0 + 0x444) |= 2;
        ((TObjEneEpsilon *)arg0)->actorFlags |= 0x01000000;
        *(s32 *)((s8 *)arg0 + 0x474) = 1;
        *(s32 *)((s8 *)arg0 + 0x3C4) = 0;
        *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
        break;
    case 3:
        if (*(f32 *)((s8 *)arg0 + 0x3AC) > lbl_805DF3FC) {
            ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 1);
            break;
        }
        switch (*(s32 *)((s8 *)arg0 + 0x3C0)) {
        case 0:
            if (((TObjEneEpsilon *)arg0)->m_390 == 0) {
                ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 1);
            }
            break;
        case 1:
            break;
        case 2:
            ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 4);
            break;
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0) {
            enemy_clear_target__12TObjEneDD_STFUs(arg0);
        }
        switch (*(s32 *)((s8 *)arg0 + 0x3C0)) {
        case 0:
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            ((TObjEneEpsilon *)arg0)->rotation_y = approach_angle_limited(((TObjEneEpsilon *)arg0)->rotation_y,
                (s32)(10430.38043493439 * atan2_float(((TObjEneEpsilon *)arg0)->m_3a0, *(f32 *)((s8 *)arg0 + 0x3A8))),
                0x400);
            (*(s32 *)((s8 *)arg0 + 0x3C4))++;
            if (*(s32 *)((s8 *)arg0 + 0x3C4) > 0xF) {
                *(s32 *)((s8 *)arg0 + 0x3C0) = 1;
                ((TObjEneEpsilon *)arg0)->requested_action = 3;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A808), arg0 + 0x38, 0, 0);
            }
            break;
        case 1:
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF3F8) != 0) {
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A80A), arg0 + 0x38, 0, 0);
                TObjEneRecon::create_bomb(arg0, arg0, arg0 + 0x40C);
            } else if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x3C0) = 2;
            }
            break;
        }
        break;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x474) = 0;
        break;
    }
}

void TObjEneRecon__sub_8031CF30(u8 *arg0, s32 arg1) {
    s32 i;
    u8 *p;
    f32 d;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 1;
        ((TObjEneDD_ST *)arg0)->vfunc_96();
        F(u32, 0x444) &= ~1;
        F(u32, 0x444) |= 2;
        F(u32, 0x30) &= ~0x01000000;
        F(s32, 0x3C4) = 0;
        F(s32, 0x3C0) = 0;
        F(s32, 0x3C8) = 0;
        F(s32, 0x474) = 1;
        break;
    case 3:
        if (F(f32, 0x3AC) > lbl_805DF3FC) {
            ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 1);
            break;
        }
        switch (F(s32, 0x3C0)) {
        case 0:
        case 1:
            if (F(u32, 0x390) == 0) {
                ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 1);
            }
            break;
        case 2:
            break;
        case 3:
            ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 4);
            break;
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (((TObjEneEpsilon *)arg0)->update_death_check() == 0) {
            enemy_clear_target__12TObjEneDD_STFUs(arg0);
        }
        switch (F(s32, 0x3C0)) {
        case 0:
            if (F(u32, 0x390) != 0) {
                ((TObjEneRecon *)arg0)->advance_field398();
            }
            ((TObjEneDD *)arg0)->update_velocity();
            F(f32, 0x44C) = sin_table_lookup(F(s32, 0x60));
            F(f32, 0x454) = cos_table_lookup(F(s32, 0x60));
            ((TObjEneRecon *)arg0)->update_collide_flag();
            F(f32, 0x448) = approach_value__12TObjEneReconFff(arg0, F(f32, 0x448), F(f32, 0x398));
            ((TObjEneRecon *)arg0)->clamp_min_height();
            if (TObjEneRecon__sub_8031DA90(arg0) != 0) {
                F(s16, 0xB8) = 1;
                F(s32, 0x3C0) = 1;
            }
            break;
        case 1:
            F(s32, 0x3C4)++;
            if (F(s32, 0x3C4) >= ((Data_8031CF30 *)TObjEneRecon__data_805D6AFC)->f1C) {
                F(s32, 0x3C4) = 0;
                F(s32, 0x3C0) = 2;
                F(s16, 0xB8) = 2;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A808), arg0 + 0x38, 0, 0);
            }
            ((TObjEneRecon *)arg0)->update_flag_0x444();
            break;
        case 2:
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF400) != 0 || ((TObjMotion *)arg0)->is_passing_frame((f32)((f32)lbl_805DF404)) != 0) {
                spawn_particle_effect(arg0 + 0x2FC, 0x218);
            }
            if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF408) != 0) {
                F(s32, 0x3C8) = 1;
                play_sound_effect(TObjEneRecobox::remap_area_sound_id(0x4003A809), arg0 + 0x38, 0, 0);
            } else if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805DF40C) != 0) {
                F(s32, 0x3C8) = 0;
            }
            if (F(s32, 0x3C8) == 1) {
                for (i = 0; i < lbl_805D5868; i++) {
                    p = (u8 *)get_player_data__10TObjPlayerFi(i);
                    if (is_valid_and_active__10TObjPlayerFUl() != 0 && p != NULL && get_entity_id(p) < 0x1000 && ((VB_8031CF30 *)p)->m31() == 0) {
                        d = horizontal_distance_squared(p + 0x2FC, arg0 + 0x40C);
                        if (d <= ((AttackParams *)(F(s32, 0x318)))->get_damage_radius() * ((AttackParams *)(F(s32, 0x318)))->get_damage_radius()) {
                            Pair_8031CF30 t;
                            t.a = 0;
                            t.b = (f32)get_attack_params_atp_min((void *)(F(s32, 0x318)));
                            {
                                Pair_8031CF30 dmg = t;
                                ((VB_8031CF30 *)p)->m21(arg0, &dmg, 0, -1, -1);
                            }
                            ((VB_8031CF30 *)p)->m23(arg0, lbl_805DF408);
                        }
                    }
                }
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x3C0) = 3;
            }
            ((TObjEneRecon *)arg0)->update_flag_0x444();
            break;
        }
        ((TObjEneDD_ST *)arg0)->vfunc_89();
        ((TObjEneRecon *)arg0)->spawn_trap_a();
        break;
    case 5:
        F(s32, 0x474) = 0;
        break;
    }
}

void TObjEneRecon__sub_8031D380(u8 *arg0, s32 arg1) {
  s32 temp_r4;
  switch (arg1)
  {
    case 4:
      *((s16 *) (((s8 *) arg0) + 0xB8)) = 1;
      (((VObj_18_83f71d *)(arg0))->m94());
      *((s32 *) (((s8 *) arg0) + 0x444)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x444))) & 0xFFFFFFFE);
      *((s32 *) (((s8 *) arg0) + 0x444)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x444))) | 2);
      *((s32 *) (((s8 *) arg0) + 0x30)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x30))) | 0x01000000);
      return;
    case 3:
      if (((s32) (*((s32 *) (((s8 *) arg0) + 0x3B0)))) >= 0x96)
    {
      ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 5);
    }
    case 5:
      return;
    case 0:
      ((TObjMotion *)arg0)->advance_animation();
      if ((((TObjEneEpsilon *)arg0)->update_death_check() != 0) || ((((VObj_18_83f71d *)(arg0))->m102((200.0f))) != 0))
    {
      ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 4);
    }
    else
    {
      *((s32 *) (((s8 *) arg0) + 0x3B0)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x3B0))) + 1);
    }
      ((TObjEneRecon *)arg0)->sync_height();
      ((TObjEneDD *)arg0)->update_velocity();
      temp_r4 = *((s32 *) (((s8 *) arg0) + 0x60));
      *((s32 *) (((s8 *) arg0) + 0x60)) = (s32) ((u16)(temp_r4 + 0x400));
      (((VObj_18_83f71d *)(arg0))->m87((temp_r4)));
      ((TObjEneRecon *)arg0)->spawn_trap_b();
      break;
  }
  return;
}
void TObjEneRecon::sub_8031D4B0(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f31;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        this->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x444) = (s32) (*(s32 *)((s8 *)arg0 + 0x444) & 0xFFFFFFFE);
        *(s32 *)((s8 *)arg0 + 0x444) = (s32) (*(s32 *)((s8 *)arg0 + 0x444) | 2);
        *(s32 *)((s8 *)arg0 + 0x30) = (*(s32 *)((s8 *)arg0 + 0x30) | 0x01000000);
        *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
        *(s32 *)((s8 *)arg0 + 0x60) = (s32) (10430.38043493439 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x428)), (f32) (*(f32 *)((s8 *)arg0 + 0x430))));
        enemy_clear_target__12TObjEneDD_STFUs(arg0);
        break;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3C0) == 2) {
            ((void (*)(void *, s16)) transition_enemy_state__9TObjEneDDFl)(arg0, 1);
        }
        break;
    case 5:
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x428);
        temp_f2 = *(f32 *)((s8 *)arg0 + 0x430);
        temp_f31 = (temp_f1 * temp_f1) + (temp_f2 * temp_f2);
        ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(temp_f1, temp_f2, temp_f31);
        switch (*(s32 *)((s8 *)arg0 + 0x3C0)) {
        case 0:
            *(f32 *)((s8 *)arg0 + 0x448) = (f32) (*(f32 *)((s8 *)arg0 + 0x448) + *(f32 *)((s8 *)arg0 + 0x42C));
            if (*(f32 *)((s8 *)arg0 + 0x448) == *(f32 *)((s8 *)arg0 + 0x460)) {
                *(s32 *)((s8 *)arg0 + 0x3C0) = 1;
            } else {
                *(f32 *)((s8 *)arg0 + 0x428) = (f32) (*(f32 *)((s8 *)arg0 + 0x428) * lbl_805DF410);
                *(f32 *)((s8 *)arg0 + 0x430) = (f32) (*(f32 *)((s8 *)arg0 + 0x430) * lbl_805DF410);
                if (*(f32 *)((s8 *)arg0 + 0x448) > *(f32 *)((s8 *)arg0 + 0x460)) {
                    temp_f2_2 = *(f32 *)((s8 *)arg0 + 0x42C);
                    if (temp_f2_2 > lbl_805DF414) {
                        *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (temp_f2_2 - TObjEneRecon__data_805DF3D0);
                        if (*(f32 *)((s8 *)arg0 + 0x42C) < lbl_805DF414) {
                            *(f32 *)((s8 *)arg0 + 0x42C) = (f32) lbl_805DF414;
                        }
                    } else {
                        *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (temp_f2_2 * lbl_805DF418);
                        if (*(f32 *)((s8 *)arg0 + 0x42C) > lbl_805DF414) {
                            *(f32 *)((s8 *)arg0 + 0x42C) = (f32) lbl_805DF414;
                        }
                    }
                    temp_f1_2 = *(f32 *)((s8 *)arg0 + 0x448);
                    temp_f2_3 = *(f32 *)((s8 *)arg0 + 0x460);
                    if ((temp_f1_2 + *(f32 *)((s8 *)arg0 + 0x42C)) < temp_f2_3) {
                        *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (temp_f2_3 - temp_f1_2);
                    }
                } else {
                    temp_f2_4 = *(f32 *)((s8 *)arg0 + 0x42C);
                    if (temp_f2_4 < 0.3f) {
                        *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (temp_f2_4 + TObjEneRecon__data_805DF3D0);
                        if (*(f32 *)((s8 *)arg0 + 0x42C) > 0.3f) {
                            *(f32 *)((s8 *)arg0 + 0x42C) = (f32) 0.3f;
                        }
                    } else {
                        *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (temp_f2_4 * lbl_805DF418);
                        if (*(f32 *)((s8 *)arg0 + 0x42C) < 0.3f) {
                            *(f32 *)((s8 *)arg0 + 0x42C) = (f32) 0.3f;
                        }
                    }
                    temp_f1_3 = *(f32 *)((s8 *)arg0 + 0x448);
                    temp_f2_5 = *(f32 *)((s8 *)arg0 + 0x460);
                    if ((temp_f1_3 + *(f32 *)((s8 *)arg0 + 0x42C)) > temp_f2_5) {
                        *(f32 *)((s8 *)arg0 + 0x42C) = (f32) (temp_f2_5 - temp_f1_3);
                    }
                }
            }
            break;
        case 1:
            if (temp_f31 <= lbl_805DF41C) {
                *(s32 *)((s8 *)arg0 + 0x3C0) = 2;
            } else {
                *(f32 *)((s8 *)arg0 + 0x428) = (f32) (*(f32 *)((s8 *)arg0 + 0x428) * lbl_805DF410);
                *(f32 *)((s8 *)arg0 + 0x430) = (f32) (*(f32 *)((s8 *)arg0 + 0x430) * lbl_805DF410);
            }
            break;
        }
        ((TObjEneRecon *)arg0)->update_flag_0x444();
        *(f32 *)((s8 *)arg0 + 0x44) = (f32) *(f32 *)((s8 *)arg0 + 0x2FC);
        *(f32 *)((s8 *)arg0 + 0x4C) = (f32) *(f32 *)((s8 *)arg0 + 0x304);
        ((TObjEneRecon *)arg0)->clamp_min_height();
        this->vfunc_88();
        break;
    }
}

}

struct Base_8031D780 { char pad[0x18]; };
struct VObj_8031D780 : Base_8031D780 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
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
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94(); virtual void m95();
    virtual void m96(); virtual s32 m97();
};

extern "C" {

s32 select_nearest_target__12TObjEneDD_STFf(void *, f32);

s32 TObjEneRecon::vfunc_104(f32 farg0) {
    if (((VObj_8031D780 *)this)->m97() != 0) {
        ((TObjEneDD_ST *)this)->select_and_apply_target(farg0);
        return;
    }
    select_nearest_target__12TObjEneDD_STFf(this, farg0);
}

void TObjEneRecon::spawn_trap_a() {
    s32 arg0 = (s32)this;
    play_persistent_sound((TObjEneRecobox::remap_area_sound_id(0x4003AD07)), (arg0), (arg0 + 0x38), 0, 0);
}

void TObjEneRecon::spawn_trap_b() {
    s32 arg0 = (s32)this;
    play_persistent_sound((TObjEneRecobox::remap_area_sound_id(0x4003B206)), (arg0), (arg0 + 0x38), 0, 0);
}

u16 TObjEneRecon__sub_8031D878(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x474) != 0) {
        return *(u16 *)((s8 *)arg0 + 0x38C);
    }
    return 0xFFFFU;
}

}

struct Hit_8031D898 { u16 id; u8 pad[6]; };

struct Recon_8031D898 {
    u8 pad0[0x38C];
    u16 target;
    u8 pad38E[0x434 - 0x38E];
    u16 owner;
    u8 pad436[0x470 - 0x436];
    s32 f470;
    s32 f474;
};

struct Hit_8031D994 { u16 id; u8 pad[6]; };

struct Recon_8031D994 {
    u8 pad0[0x38C];
    u16 target;
    u8 pad38E[0x434 - 0x38E];
    u16 owner;
    u8 pad436[0x46C - 0x436];
    s32 f46C;
    s32 f470;
    s32 f474;
};

extern "C" {
f32 fabs_float(f32);
extern s32 TObjEneRecon__attack_params;
void enemy_set_target_id(void *, u16);
s32 collect_enemy_target_candidates(void *, void *, f32);
void *find_entity_by_id(u16);
extern const f32 lbl_805DF420;

void TObjEneRecon::retarget() {
    Hit_8031D898 hits[5];
    void *p;
    s32 n;
    u16 id;
    s32 i;
    p = find_entity_by_id(((Recon_8031D898 *)this)->owner);
    if (p == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (((TObjEneRecon *)p)->is_below_child_limit(((Recon_8031D898 *)this)->target) != 0) {
        ((Recon_8031D898 *)this)->f470 = 0;
        transition_enemy_state(3);
        return;
    }
    n = collect_enemy_target_candidates(this, hits, lbl_805DF420);
    for (i = 0; i < n; i++) {
        id = hits[i].id;
        if (id != ((Recon_8031D898 *)this)->target && ((TObjEneRecon *)p)->is_below_child_limit(id) != 0) {
            ((Recon_8031D898 *)this)->f470 = 0;
            enemy_set_target_id(this, id);
            transition_enemy_state(3);
            return;
        }
    }
    transition_enemy_state(4);
    ((Recon_8031D898 *)this)->f474 = 0;
}

void TObjEneRecon::select_next_target() {
    Hit_8031D994 hits[5];
    void *p;
    s32 n;
    u16 id;
    s32 i;
    p = find_entity_by_id(((Recon_8031D994 *)this)->owner);
    if (p == 0) {
        queue_destruction__7TObjectFv(this);
        return;
    }
    if (((TObjEneRecon *)p)->is_below_child_limit(((Recon_8031D994 *)this)->target) != 0) {
        ((Recon_8031D994 *)this)->f46C = 0;
        transition_enemy_state(2);
        return;
    }
    n = collect_enemy_target_candidates(this, hits, lbl_805DF420);
    for (i = 0; i < n; i++) {
        id = hits[i].id;
        if (id != ((Recon_8031D994 *)this)->target && ((TObjEneRecon *)p)->is_below_child_limit(id) != 0) {
            ((Recon_8031D994 *)this)->f46C = 0;
            enemy_set_target_id(this, id);
            transition_enemy_state(2);
            return;
        }
    }
    transition_enemy_state(4);
    ((Recon_8031D994 *)this)->f474 = 0;
}

s32 TObjEneRecon__sub_8031DA90(u8 *arg0) {
    f32 temp_f31;
    if ((*(f32 *)((s8 *)arg0 + 0x3AC) < (TObjEneRecon__data_805DF3D4 + ((AttackParams *)TObjEneRecon__attack_params)->get_attack_range())) && (fabs_float((f32) (*(f32 *)((s8 *)arg0 + 0x448) - *(f32 *)((s8 *)arg0 + 0x398))) < lbl_805DF3CC)) {
        temp_f31 = vec3_dot((Vec *)(arg0 + 0x44C), (Vec *)(arg0 + 0x3A0));
        
        if (temp_f31 >= cos_table_lookup(((AttackParams *)(*(s32 *)((s8 *)arg0 + 0x318)))->get_attack_angle())) {
            return 1;
        }
    }
    return 0;
}

}

extern "C" {


extern const f32 lbl_805DF424;

f32 TObjEneRecon::approach_value(f32 farg0, f32 farg1) {
    f32 temp_f31;
    f32 var_f1;

    temp_f31 = farg1 - farg0;
    if (fabs_float(temp_f31) < lbl_805DF3E8) {
        return farg1;
    }
    var_f1 = TObjEneRecon__data_805DF3D0;
    var_f1 = temp_f31 * var_f1;
    if (var_f1 > lbl_805DF3B8) {
        var_f1 = lbl_805DF3B8;
    } else if (var_f1 < lbl_805DF424) {
        var_f1 = lbl_805DF424;
    }
    return farg0 + var_f1;
}

}

struct Vec_8031DBD8 { f32 x, y, z; };

extern "C" {
void TObjEneRecon::vfunc_88() {
    u8 *arg0 = (u8 *)this;
    f32 d;
    u8 *t = *(u8 **)((s8 *)arg0 + 0x390);
    if (t != NULL && *(s16 *)((s8 *)arg0 + 0x326) == 2) {
        *(f32 *)((s8 *)arg0 + 0x3C) = *(f32 *)((s8 *)t + 0x3C);
    } else {
        Vec_8031DBD8 v = *(Vec_8031DBD8 *)(arg0 + 0x38);
        v.y += *(f32 *)((s8 *)arg0 + 0x448);
        if (project_actor_to_ground(arg0, &v, arg0 + 0x248) != 0) {
            *(f32 *)((s8 *)arg0 + 0x3C) = v.y;
        }
    }
    d = *(f32 *)((s8 *)arg0 + 0x448) - *(f32 *)((s8 *)arg0 + 0x3C);
    if (d >= lbl_805DF3C8) {
        this->vfunc_97();
    } else {
        this->vfunc_98();
    }
    *(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xA4)) + 4) = d;
}

}

struct Base_8031DCCC { char pad[0x18]; };
struct VObj_8031DCCC : Base_8031DCCC {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
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
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86();
};

extern "C" {

s32 vfunc_89__9TObjEneDDFv(void *);

void TObjEneRecon::vfunc_89() {
    struct VObj_8031DCCC *o = (struct VObj_8031DCCC *)this;
    o->m86();
    vfunc_89__9TObjEneDDFv(this);
    this->clamp_min_height();
}

}


#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
void TObjEneRecon::clamp_min_height() {
    u8 *arg0 = (u8 *)this;
  f32 new_var;
  f32 temp_f2;
  new_var = *((f32 *) (((s8 *) arg0) + 0x448));
  temp_f2 = *((f32 *) (((s8 *) arg0) + 0x3C));
  if ((new_var - temp_f2) < TObjEneRecon__data_805DF3D4)
  {
    *((f32 *) (((s8 *) arg0) + 0x448)) = (f32) (TObjEneRecon__data_805DF3D4 + temp_f2);
  }
  *((f32 *) (((s8 *) arg0) + 0x300)) = (f32) (*((f32 *) (((s8 *) arg0) + 0x448)));
}
#pragma pop

extern "C" {

s32 VecCopy__FP3VecPC3Vec(void *, void *, void *);

void TObjEneRecon::update_position_from_offsets() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x2FC) = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x304) = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    VecCopy__FP3VecPC3Vec(arg0 + 0x74, arg0 + 0x2FC, arg0);
}

}

struct Base_8031DE2C { char pad[0x18]; };
struct VObj_8031DE2C : Base_8031DE2C {
    virtual void v0();
#define VV(n) virtual void v##n();
VV(1)VV(2)VV(3)VV(4)VV(5)VV(6)VV(7)VV(8)VV(9)VV(10)
VV(11)VV(12)VV(13)VV(14)VV(15)VV(16)VV(17)VV(18)VV(19)VV(20)
VV(21)VV(22)VV(23)VV(24)VV(25)VV(26)VV(27)VV(28)VV(29)VV(30)
VV(31)VV(32)VV(33)VV(34)VV(35)VV(36)VV(37)VV(38)VV(39)VV(40)
VV(41)VV(42)VV(43)VV(44)VV(45)VV(46)VV(47)VV(48)VV(49)VV(50)
VV(51)VV(52)VV(53)VV(54)VV(55)VV(56)VV(57)VV(58)VV(59)VV(60)
VV(61)VV(62)VV(63)VV(64)VV(65)VV(66)VV(67)VV(68)VV(69)VV(70)
VV(71)VV(72)VV(73)VV(74)VV(75)VV(76)VV(77)VV(78)VV(79)VV(80)
VV(81)VV(82)VV(83)VV(84)VV(85)VV(86)VV(87)VV(88)VV(89)VV(90)
VV(91)VV(92)VV(93)VV(94)VV(95)VV(96)VV(97)VV(98)VV(99)
#undef VV
    virtual u32 v102();
};

extern "C" {

u32 move_with_wall_slide_commit__9TObjEneDDFfff();
u32 TObjEneEpsilon__sub_800B92F8(void *, s32, void *, f32);


void TObjEneRecon::update_collide_flag() {
    void *temp_r5;

    temp_r5 = this->movementParameters;
    if (TObjEneEpsilon__sub_800B92F8(this, *(s32 *)((s8 *)temp_r5 + 8), temp_r5, *TObjEneRecon__data_805D6AFC) != 0U) {
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
}

void TObjEneRecon::set_flag2() {
    if (move_with_wall_slide_commit__9TObjEneDDFfff() != 0U) {
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
}

void TObjEneRecon::update_flag_0x444() {
    if (((VObj_8031DE2C *)this)->v102() != 0U) {
        *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) | 2);
        return;
    }
    *(s32 *)((s8 *)this + 0x444) = (s32) (*(s32 *)((s8 *)this + 0x444) & 0xFFFFFFFD);
}

void enemy_copy_target_destination__12TObjEneDD_STFv(void *);

#pragma push
#pragma fp_contract on
void TObjEneRecon::set_orbit_destination(s32 arg1) {
    enemy_copy_target_destination__12TObjEneDD_STFv(this);
    *(f32 *)((s8 *)((u8 *)this) + 0x394) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x468) * sin_table_lookup(arg1)) + *(f32 *)((s8 *)((u8 *)this) + 0x394));
    *(f32 *)((s8 *)((u8 *)this) + 0x398) = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x460);
    *(f32 *)((s8 *)((u8 *)this) + 0x39C) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x468) * cos_table_lookup(arg1)) + *(f32 *)((s8 *)((u8 *)this) + 0x39C));
}
#pragma pop

void TObjEneRecon::advance_field398() {
    ((s32 (*)())enemy_copy_target_destination__12TObjEneDD_STFv)();
    *(f32 *)((s8 *)this + 0x398) = (f32) (*(f32 *)((s8 *)this + 0x398) + *(f32 *)((s8 *)this + 0x464));
}
void TObjEneRecon::sync_height() {
    ((s32 (*)())enemy_copy_target_destination__12TObjEneDD_STFv)();
    *(f32 *)((s8 *)this + 0x398) = (f32) *(f32 *)((s8 *)this + 0x460);
}
void TObjEneRecon::vfunc_61() {  }
void TObjEneRecon::vfunc_62() { if (this->mode != 6) { transition_enemy_state((s16)((void*)6)); } }

void TObjEneRecon::vfunc_63() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;
    temp_r0 = this->mode;
    if ((temp_r0 != 7) && (temp_r0 != 8)) {
        ((TObjEneDD *)arg0)->transition_enemy_state((s16)((void*)(7)));
    }
}

void TObjEneRecon::vfunc_28() {  }

}

extern "C" {
extern s32 lbl_805D6AF0;
extern s32 TObjEneRecon__resistance_params;
void *TObjEneRecon__ai_parameters[7] = {
    (void *)0x43610000, (void *)0x3f6d097b, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
CollisionBody TObjEneRecon__collision_body_template = {
    {0.0f, 0.0f, 0.0f}, 5.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f
};
void *TObjEneRecon__animation_entries[24] = {
    (void *)0x10000, (void *)0x8, (void *)0x3f333333, (void *)0x0,
    (void *)0x10001, (void *)0x9, (void *)0x3f333333, (void *)0x0,
    (void *)0x30002, (void *)0x4, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30003, (void *)0x5, (void *)0x3f333333, (void *)0x0,
    (void *)0x30004, (void *)0x6, (void *)0x3f19999a, (void *)0x0,
    (void *)0x10005, (void *)0x7, (void *)0x3f333333, (void *)0x0,
};
extern void *__vt__12TObjEneRecon[];
#define __vt__12TObjEneRecon ((s32 *)__vt__12TObjEneRecon)
}

#pragma defer_codegen on
f32 TObjEneRecon::get_field_4d0() { return this->m_4d0; }
f32 TObjEneRecon::get_field_4d4() { return *(f32*)((char*)this + 0x4d4); }

struct Stack_8031E708
{
  s32 sp8;
  s32 spC;
  s32 sp10;
  s32 sp14;
};

struct RecoveredGlobal_8031E708_lbl_804760EC
{
  s32 value;
  u8 remaining[0xC];
};

struct RecoveredFields_8031E708_TObjEneRecon__data_805D6B00
{
  u8 unknown_0[0x42C];
  u8 *field_42C;
  s32 field_430;
};

struct RecoveredFields_8031E708_temp_r5
{
  u8 unknown_0[0x8];
  s32 field_8;
  NJS_TEXLIST *texlist;
};

extern "C" {
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
s32 init_from_model__11TBreakUpMdlFl(int, void *);
extern RecoveredGlobal_8031E708_lbl_804760EC recon_anim_binding;
typedef struct RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 RecoveredFields_8031E708_TObjEneRecon__data_805D6B00;
typedef struct RecoveredFields_8031E708_temp_r5 RecoveredFields_8031E708_temp_r5;
typedef struct RecoveredGlobal_8031E708_lbl_804760EC RecoveredGlobal_8031E708_lbl_804760EC;
typedef struct Stack_8031E708 Stack_8031E708;
typedef char RecoveredGlobal_8031E708_lbl_804760EC_size[((sizeof(RecoveredGlobal_8031E708_lbl_804760EC)) == 0x10) ? (1) : (-1)];
void TObjEneRecon::load_resources() {
  Stack_8031E708 stack;
  s32 temp_r3;
  s32 var_r4;
  u8 *temp_r5;
  TObjEneRecon__recobox_static_instance = (u8 *)TObjEneRecobox__sub_803201D0();
  temp_r3 = (var_r4 = (int)::operator new(0x10));
  if (var_r4 != 0)
  {
    var_r4 = init_from_model__11TBreakUpMdlFl((int) temp_r3, (void *) (*((s32 *) (((s8 *) ((RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 *) TObjEneRecon__recobox_static_instance)->field_42C) + 8))));
  }
  boss3_volopt_instance = (VObj_8031E650 *)var_r4;
  recon_intro_stage = 0;
  recon_model_matrix_ptr = 0;
  lbl_805D6AF0 = register_boss__6TLobbyFl(0x42);
  TObjEneRecon__attack_params = dispatch_shared_handler_b__6TLobbyFl(0x42);
  TObjEneRecon__resistance_params = register_object__6TLobbyFl(0x42);
  TObjEneRecon__data_805D6AFC = (f32 *)dispatch_shared_handler_a__6TLobbyFl(0x42);
  TObjEneRecon__sub_8031BC94();
  stack.sp8 = *((s32 *) (((s8 *)&recon_anim_binding.value) + 0));
  stack.spC = *((s32 *) (((s8 *)&recon_anim_binding.value) + 4));
  stack.sp10 = *((s32 *) (((s8 *)&recon_anim_binding.value) + 8));
  stack.sp14 = *((s32 *) (((s8 *)&recon_anim_binding.value) + 0xC));
  stack.sp8 = ((RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 *) TObjEneRecon__recobox_static_instance)->field_430;
  temp_r5 = (u8 *) ((RecoveredFields_8031E708_TObjEneRecon__data_805D6B00 *) TObjEneRecon__recobox_static_instance)->field_42C;
  TLobby::spawn_npc_enemy((s16)(0xC), (s32)((int) ((RecoveredFields_8031E708_temp_r5 *) temp_r5)->field_8), ((RecoveredFields_8031E708_temp_r5 *) temp_r5)->texlist, &stack.sp8, TObjEneRecon__collision_body_template.radius, (f32)((f32) TObjEneRecon__data_805DF3C0));
}

}

extern "C" {

void *__nw__7TObjectFUl(int);

extern void *tl_04;

void *TObjEneRecon::create(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4) {
    void *o;
    o = __nw__7TObjectFUl(0x4E4);
    if (o != NULL) {
        o = TObjEneRecon__ct((u8 *)o, (s32)tl_04, (s32)arg0, (s32)arg1, (s32)arg2, (s32)arg3, (s32)arg4);
    }
    return o;
}

}

struct Base_8031E650 { char pad[0xC]; };
struct VObj_8031E650 : Base_8031E650 {
    virtual void m0(int);
};


void TObjEneRecon::release_static_instance() {
    TObjEneRecon__sub_8031BC38();
    if (boss3_volopt_instance != 0) {
        if (boss3_volopt_instance != 0) {
            boss3_volopt_instance->m0(1);
        }
        boss3_volopt_instance = 0;
    }
}

extern "C" {

s32 __ct__12TObjEneDD_STFP7TObject();

extern s32 TObjEneRecon_name_ref;

u8 *TObjEneRecon__ct(u8 *ene_recon, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    __ct__12TObjEneDD_STFP7TObject();
    *(s32 **)((s8 *)ene_recon + 0x18) = __vt__12TObjEneRecon;
    __ct__13TUnk_80494938Fv((ene_recon + 0x480));
    *(s32 *)((s8 *)ene_recon + 0) = (s32) TObjEneRecon_name_ref;
    *(s16 *)((s8 *)ene_recon + 0x434) = get_entity_id((void *)arg2);
    ((TObjEneDD *)ene_recon)->init_common_from((u8 *)arg2);
    ((TObjEneRecon *)ene_recon)->entity_id = arg3;
    *(s16 *)((s8 *)ene_recon + 0x2C) = arg4;
    VecCopy((Vec *)(ene_recon + 0x38), (const Vec *)(arg5));
    VecCopy((Vec *)(ene_recon + 0x438), (const Vec *)(arg2 + 0x38));
    VecCopy((Vec *)(ene_recon + 0x428), (const Vec *)(arg6));
    ((TObjEneRecon *)ene_recon)->init_state();
    *(f32 *)((s8 *)ene_recon + 0x460) = (f32) (*(f32 *)((s8 *)ene_recon + 0x460) + ((TObjEneRecon *)arg2)->get_field_4d0());
    *(f32 *)((s8 *)ene_recon + 0x468) = (f32) (*(f32 *)((s8 *)ene_recon + 0x468) + ((TObjEneRecon *)arg2)->get_field_4d4());
    *(s32 *)((s8 *)ene_recon + 0x80) = 0;
    return ene_recon;
}

}


extern "C" {

struct VBase_14_2f517b { char pad[0x14]; };

struct VObj_14_2f517b : VBase_14_2f517b {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
};

struct VBase_18_be4a70 { char pad[0x18]; };

struct VObj_18_be4a70 : VBase_18_be4a70 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual s32 m85(s16, s32);
};

void obj_setFlags30(void *, u32);
void *create_particle_emitter(void *pos, s32 id);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 reset_hp__9TObjEneDDFPUcPUcPUc(void *, void *, int, void *);
s32 initialize_enemy_state__9TObjEneDDFl(void *, int);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
s32 init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, int, int);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
void free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
void run_task__12TObjEneReconFv(TObjEneRecon *arg0);
void * __dt__12TObjEneReconFv(void *arg0, s16 arg1);

extern const f32 lbl_805DF428;
extern const f32 lbl_805DF42C;
extern const f32 lbl_805DF430;
extern const f32 lbl_805DF434;


}
extern "C" {

}

#pragma push
#pragma fp_contract on
extern "C" {
void TObjEneRecon::init_state() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r6;

    ((TObjEneDD *)arg0)->init_position_vectors();
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TObjEneRecon__recobox_static_instance + 0x42C)) + 8);
    temp_r6 = (u8 *)(*(u8 **)((s8 *)TObjEneRecon__recobox_static_instance + 0x42C));
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)temp_r6 + 0xC);
    init_model__9TObjEneDDFP13CollisionBodyl((void *)arg0, (void *)&TObjEneRecon__collision_body_template, 1, (int)temp_r6);
    ((TObjMotion *)arg0)->set_field_d8((s32)((void *) TObjEneRecon__animation_entries));
    ((TObjMotion *)arg0)->set_field_dc((int) (*(s32 *)((s8 *)TObjEneRecon__recobox_static_instance + 0x430)));
    *(s16 *)((s8 *)arg0 + 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation((*(s16 *)((s8 *)arg0 + 0xB8)));
    ((TObjMotion *)arg0)->set_field_b8((int) (*(s16 *)((s8 *)arg0 + 0xB8)));
    reset_hp__9TObjEneDDFPUcPUcPUc((void *)arg0, (void *)lbl_805D6AF0, (int)TObjEneRecon__attack_params, (void *)TObjEneRecon__resistance_params);
    ((TObjEneDD *)arg0)->check_state_flag_4();
    *(void **)((s8 *)arg0 + 0x350) = (void *) TObjEneRecon__ai_parameters;
    initialize_enemy_state__9TObjEneDDFl(arg0, 0x44);
    *(f32 *)((s8 *)arg0 + 0x37C) = (f32) TObjEneRecon__data_805DF3D4;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(0xA);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(0xA);
    ((TObjEneDD_ST *)arg0)->set_active();
    *(s32 *)((s8 *)arg0 + 0x30) = (*(s32 *)((s8 *)arg0 + 0x30) | 0x01000000);
    *(s32 *)((s8 *)arg0 + 0x444) = 2;
    *(f32 *)((s8 *)arg0 + 0x448) = (*(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x44C) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x450) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x454) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x458) = (f32) TObjEneRecon__data_805DF3C4;
    *(s32 *)((s8 *)arg0 + 0x45C) = 0;
    *(f32 *)((s8 *)arg0 + 0x460) = (f32) ((lbl_805DF430 * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + lbl_805DF42C);
    *(f32 *)((s8 *)arg0 + 0x464) = (f32) ((lbl_805DF430 * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + TObjEneRecon__data_805DF3C0);
    *(f32 *)((s8 *)arg0 + 0x468) = (f32) ((TObjEneRecon__data_805DF3D4 * calc_elapsed_scaled__9TObjEneDDFv(arg0)) + lbl_805DF434);
    *(s32 *)((s8 *)arg0 + 0x474) = 0;
    *(s32 *)((s8 *)arg0 + 0x478) = 0;
    *(s32 *)((s8 *)arg0 + 0x47C) = 0;
    *(s32 *)((s8 *)arg0 + 0x418) = 0;
    VecCopy((Vec *)(arg0 + 0x41C), (const Vec *)(arg0 + 0x38));
    ((VObj_14_2f517b *)(arg0 + (1152)))->m2();
    *(s32 *)((s8 *)arg0 + 0x46C) = 0;
    *(s32 *)((s8 *)arg0 + 0x470) = 0;
    VecCopy((Vec *)(arg0 + 0x40C), (const Vec *)(arg0 + 0x38));
    *(s32 *)((s8 *)arg0 + 0x3C0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C4) = 0;
    *(s32 *)((s8 *)arg0 + 0x3C8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3CC) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D0) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D4) = 0;
    *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
    *(s32 *)((s8 *)arg0 + 0x3DC) = 0;
    *(f32 *)((s8 *)arg0 + 0x3E0) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3E4) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3E8) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3EC) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3F0) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3F4) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3F8) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x3FC) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x400) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x404) = (f32) TObjEneRecon__data_805DF3C4;
    *(f32 *)((s8 *)arg0 + 0x408) = (f32) TObjEneRecon__data_805DF3C4;
    *(s16 *)((s8 *)arg0 + 0x326) = 0;
    ((VObj_18_be4a70 *)(arg0))->m85(*(s16 *)((s8 *)arg0 + 0x326), 4);
}

}
#pragma pop
TObjEneRecon::~TObjEneRecon() {
    ((TObjEnemy *)this)->send_entity_set_flags();
    free_collision_body_parts(this);
    if (*(void **)((s8 *)this + 0x478) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x478)); this->m_494 = 0; }
    __dt__13TUnk_80494938Fv((s8 *)this + 0x480, -1);
}

extern "C" {
void run_task__12TObjEneReconFv(TObjEneRecon *ene_recon) {
    f32 temp_f2;
    f32 temp_f31;
    f32 var_f30;
    s16 temp_r0;
    s16 temp_r0_2;
    s32 entity;
    u8 *temp_r3_2;
    u8 *temp_r3_3;
    u8 *temp_r3_4;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TObjEneRecon *)(ene_recon))->vfunc_105();
        return;
    }
    entity = (s32)find_entity_by_id((*(u16 *)((s8 *)ene_recon + 0x434)));
    if ((entity == 0) || (all_parents_unqueued_for_destruction__7TObjectFv() == 0)) {
        queue_destruction__7TObjectFv(ene_recon);
        return;
    }
    temp_r0 = ene_recon->mode;
    if ((temp_r0 != 8) && (temp_r0 != 7) && (is_anim_6__12TObjEneReconFv((TObjEneRecon *)entity) == 1)) {
        ene_recon->m_2dc = (s32) (ene_recon->m_2dc | 4);
        ((TObjPlayer *)ene_recon)->set_hp_clamped(0);
        obj_setFlags30(ene_recon, 0xA00U);
        ((TObjEneRecon *)(ene_recon))->vfunc_74(0);
    }
    if (((TObjEneRecon *)(ene_recon))->vfunc_83() != 4) {
        ((TObjEneRecon *)(ene_recon))->vfunc_85();
        temp_r3_2 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
        if (temp_r3_2 == NULL) {
            *(u8 **)((s8 *)ene_recon + 0x478) = (u8 *)create_particle_emitter((u8 *)ene_recon + 0x2FC, 0x217);
            temp_r3_3 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
            if (temp_r3_3 != NULL) {
                ((TParticleCtrl *)temp_r3_3)->enable();
            }
        } else {
            temp_r0_2 = ene_recon->mode;
            if ((temp_r0_2 == 8) || (temp_r0_2 == 7)) {
                ((TParticleCtrl *)temp_r3_2)->enable();
            } else {
                if ((s32) *(s32 *)((s8 *)ene_recon + 0x47C) == 0) {
                    var_f30 = lbl_805DF400;
                    *(s32 *)((s8 *)ene_recon + 0x47C) = 1;
                } else {
                    var_f30 = lbl_805DF428;
                    *(s32 *)((s8 *)ene_recon + 0x47C) = 0;
                }
                if (TObjEneDD::check_v2_mode() != 0) {
                    var_f30 *= lbl_805DF400;
                }
                temp_f31 = var_f30 * cos_table_lookup(ene_recon->rotation_y);
                temp_f2 = var_f30 * -sin_table_lookup(ene_recon->rotation_y);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x60) = (f32) (ene_recon->m_2fc + temp_f31);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x64) = (f32) (lbl_805DF424 + ene_recon->m_300);
                *(f32 *)((s8 *)(*(u8 **)((s8 *)ene_recon + 0x478)) + 0x68) = (f32) (ene_recon->m_304 + temp_f2);
            }
        }
    } else {
        temp_r3_4 = (u8 *)(*(u8 **)((s8 *)ene_recon + 0x478));
        if (temp_r3_4 != NULL) {
            ((TParticleCtrl *)temp_r3_4)->enable();
        }
    }
    ene_recon->update_position_from_offsets();
    ((TObjEnemy *)ene_recon)->submit_default_cursor_candidate();
    ((TObjEneRecon *)(ene_recon))->vfunc_100();
    ene_recon->update_ground_probe();
}

void TObjEneRecon::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        sub_8031D4B0(reason);
        return;
    case 1:
        TObjEneRecon__sub_8031D380((u8 *)this, reason);
        return;
    case 2:
        TObjEneRecon__sub_8031CF30((u8 *)this, reason);
        return;
    case 3:
        TObjEneRecon__sub_8031CCFC((u8 *)this, reason);
        return;
    case 4:
        TObjEneRecon__sub_8031C920((u8 *)this, reason);
        return;
    case 6:
        TObjEneRecon__sub_8031C624((u8 *)this, reason);
        return;
    case 7:
        TObjEneRecon__sub_8031C364((u8 *)this, reason);
        return;
    case 5:
        run_task__12TObjEneReconFPvi((u8 *)this, reason);
        return;
    case 8:
        handle_message(reason);
    default:
        return;
    }
}

}


