#include "types.h"
#include "pso/system/PadRumble.h"
#include "pso/object/TObjFish_800E2FFC.h"
#include "pso/boss/Boss6Type2Death.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/TBoss6Demo21_TYPE2_DEAD.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/boss/TBoss6Type1.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"

struct O_8033E5A8 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x70 - 0x1C];
    void *f70;
    u8 pad74[0x80 - 0x74];
    void *f80;
    u8 pad84[0x9C - 0x84];
    void *f9c;
    void *fa0[4];
};

struct Vec_8033E0F0 { f32 x, y, z; };

struct Rng_8033E0F0 { s32 start; s32 end; s32 id; };

struct Fish_8033E0F0 {
    u8 pad0[0x4C];
    f32 f4c;
    s32 timer;
    s32 f54;
    Vec_8033E0F0 pos;
    Vec_8033E0F0 f64;
    u8 pad70[0x74 - 0x70];
    Vec_8033E0F0 f74;
    u8 pad80[0x84 - 0x80];
    Vec_8033E0F0 f84;
    Vec_8033E0F0 f90;
    u8 pad9C[0xA0 - 0x9C];
    void *emit[4];
    void *fb0;
};

struct Pl_8033E0F0 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x38 - 0x34];
    Vec_8033E0F0 pos;
};

extern "C" {
void *__nw__7TObjectFUl(int);
s32 refresh_players_equipment__14TBoss6PlotFalzFPv();
extern void *__vt__23TBoss6Demo21_TYPE2_DEAD[];
void clear_render_callback__8TObjFishFv(int);
void push_matrix();
void post_translate_matrix(void *);
s32 get_bml_motion(void *, int);
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
void set_scripted_camera_pose(void *, void *, void *);
void __ct__7TObjectFP7TObject(void *);
void *get_fish_count__8TObjFishFv(void);
s32 create_zanzo__11TBoss6Type1FPvPvPv(void *, int, int);
void vec3_add_to(void *, void *);
f32 vector_length(void *);
void subtract_vector(void *, void *);
void normalize_vector(void *);
#define __vt__23TBoss6Demo21_TYPE2_DEAD ((u8 *)__vt__23TBoss6Demo21_TYPE2_DEAD)
s32 play_sound_effect(int, void *, int, int);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
int get_player_data__10TObjPlayerFi(int a0);
s32 is_locally_controlled__10TObjPlayerFPv(void *);
s32 is_state_1f__14TBoss6PlotFalzFUi(u32 arg0);
void run_task__23TBoss6Demo21_TYPE2_DEADFv(Fish_8033E0F0 *arg0);

}
extern "C" const char lbl_80478088[] = "TBoss6Demo21_TYPE2_DEAD";
extern "C" const u32 lbl_804780A0[3] = {0xc61c4000, 0x0, 0x0};
extern "C" const u32 lbl_804780AC[3] = {0x0, 0x0, 0xc30e0000};
extern "C" const u32 lbl_804780B8[3] = {0x0, 0xc0000000, 0x40cccccd};
extern "C" const u32 boss6_type2_death_effect_desc_a[8] = {0x24, 0x0, 0x0, 0x0, 0xffffffff, 0x0, 0x0, 0x0};
extern "C" const u32 boss6_type2_death_effect_desc_b[8] = {0x19, 0x0, 0x0, 0x0, 0xffffffff, 0x0, 0x0, 0x0};
extern "C" const u32 boss6_type2_death_effect_desc_c[12] = {0x2, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0x0, 0xffffffff, 0x0, 0x0, 0x0};
extern "C" const u32 lbl_80478134[3] = {0x0, 0x0, 0x0};
extern "C" const u32 lbl_80478140[3] = {0x1010000, 0x0, 0x3f333333};
extern "C" const u32 boss6_type2_death_emitter_ranges[12] = {0x0, 0x8e, 0x228, 0xfa, 0x13a, 0x22a, 0x11d, 0x1ac, 0x22e, 0xf2, 0x13a, 0x179};
extern "C" const u32 lbl_8047817C[3] = {0xffff4000, 0xffffff60, 0xffff4000};
extern "C" const char *TBoss6Demo21_TYPE2_DEAD__name = lbl_80478088;
#define lbl_804780A0 ((u8 *)lbl_804780A0)
#define lbl_804780AC ((Vec_8033E0F0 *)lbl_804780AC)
#define lbl_804780B8 ((Vec_8033E0F0 *)lbl_804780B8)
#define boss6_type2_death_effect_desc_a ((u8 *)boss6_type2_death_effect_desc_a)
#define boss6_type2_death_effect_desc_b ((u8 *)boss6_type2_death_effect_desc_b)
#define boss6_type2_death_effect_desc_c ((u8 *)boss6_type2_death_effect_desc_c)
#define lbl_80478134 ((u8 *)lbl_80478134)
#define lbl_80478140 ((u8 *)lbl_80478140)
#define boss6_type2_death_emitter_ranges ((Rng_8033E0F0 *)boss6_type2_death_emitter_ranges)
#define lbl_8047817C ((u8 *)lbl_8047817C)
#pragma pool_data off
extern "C" {
void TBoss6Demo21_TYPE2_DEAD::draw_model_13() {
    if ((s32) this->m_50 >= 0x1AC) {
        push_matrix();
        TObjPlayer::set_global_flag();
        post_translate_matrix((void *) (((u8 *)this) + 0x58));
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)((u8 *)this) + 0x44)));
        ((TObjFish *)(this->m_9c))->set_draw_callback_list();
        draw_model_motion((void *)this->m_40, (void *)this->m_48, (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x4C)));
        clear_render_callback__8TObjFishFv(this->m_9c);
        TObjPlayer::clear_global_state();
        pop_matrix();
    }
}

#define arg0 ((u8 *) p)

#undef arg0

#define arg0 ((u8 *) p)

#define arg0 ((u8 *) p)
void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_8(void *p) {
    f32 f;
    s32 t;
    f = 0.0f;
    t = *(s32 *)(arg0 + 0x50);
    if (t > 0x11D && t < 0x1AC) {
        if (t >= 0x12C && t <= 0x1AC) {
            f = 1.0f;
        } else if (t > 0x11D && t < 0x12C) {
            f = (f32)(t - 0x11D) / 15.0f;
        }
    }
    if (0.0f != f) {
        if (f < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(f);
        }
        push_matrix();
        TObjPlayer::set_global_flag();
        post_translate_matrix(arg0 + 0x58);
        TObjFish::set_global_param(*(s32 *)(arg0 + 0x38));
        ((TObjFish *)(*(s32 *)(arg0 + 0x80)))->set_draw_callback_list();
        draw_model_motion((void *)(*(s32 *)(arg0 + 0x34)), (void *)(*(s32 *)(arg0 + 0x3C)), *(f32 *)(arg0 + 0x4C));
        clear_render_callback__8TObjFishFv(*(s32 *)(arg0 + 0x80));
        TObjPlayer::clear_global_state();
        pop_matrix();
        if (f < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_5(void *p) {

    f32 f;
    s32 t;

    f = 0.0f;
    t = *(s32 *)(arg0 + 0x50);
    if (t > 0x101 && t < 0x12C) {
        if (t >= 0x10F && t <= 0x11D) {
            f = 1.0f;
        } else if (t > 0x101 && t < 0x10F) {
            f = (f32)(t - 0x101) / 14.0f;
        } else if (t > 0x11D && t < 0x12C) {
            f = (f32) (0x12C - t) / 15.0f;
        }
    }
    if (0.0f != f) {
        if (f < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(f);
        }
        push_matrix();
        TObjPlayer::set_global_flag();
        post_translate_matrix(arg0 + 0x58);
        TObjFish::set_global_param(*(s32 *)(arg0 + 0x2C));
        ((TObjFish *)(*(s32 *)(arg0 + 0x70)))->set_draw_callback_list();
        draw_model_motion((void *)(*(s32 *)(arg0 + 0x28)), (void *)(*(s32 *)(arg0 + 0x30)), *(f32 *)(arg0 + 0x4C));
        clear_render_callback__8TObjFishFv(*(s32 *)(arg0 + 0x70));
        TObjPlayer::clear_global_state();
        pop_matrix();
        if (f < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}
#undef arg0

void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_4() {
    f32 var_f31;
    s32 temp_r0;
    temp_r0 = this->m_50;
    if (temp_r0 < 0x101) {
        var_f31 = (1.0f);
    } else if (temp_r0 >= 0x10F) {
        var_f31 = (0.0f);
    } else {
        var_f31 = (f32) (0x10F - temp_r0) / (14.0f);
    }
    if ((0.0f) != var_f31) {
        if (var_f31 < (1.0f)) {
            TBoss6PlotFalz::set_fade_material_color(var_f31);
        }
        push_matrix();
        TObjPlayer::set_global_flag();
        post_translate_matrix(((u8 *)this) + 0x58);
        TObjFish::set_global_param(this->m_20);
        ((TObjFish *)(this->m_70))->set_draw_callback_list();
        draw_model_motion((void *)(*(s32 *)((s8 *)((u8 *)this) + 0x1C)), (void *)(*(s32 *)((s8 *)((u8 *)this) + 0x24)), *(f32 *)((s8 *)((u8 *)this) + 0x4C));
        clear_render_callback__8TObjFishFv(this->m_70);
        TObjPlayer::clear_global_state();
        pop_matrix();
        if (var_f31 < (1.0f)) {
            TObjFish::reset_fish_globals();
        }
    }
}

void render__23TBoss6Demo21_TYPE2_DEADFv(void* p) { ((TBoss6Demo21_TYPE2_DEAD *)p)->draw_fading_model_4(); TBoss6Demo21_TYPE2_DEAD::draw_fading_model_5(p); TBoss6Demo21_TYPE2_DEAD::draw_fading_model_8(p); ((TBoss6Demo21_TYPE2_DEAD *)p)->draw_model_13(); }

#pragma push
#pragma pool_data off
void run_task__23TBoss6Demo21_TYPE2_DEADFv(Fish_8033E0F0 *arg0) {
    Vec_8033E0F0 b;
    Vec_8033E0F0 mid;
    Vec_8033E0F0 a;
    if ((arg0->f4c += 0.7f) > 499.0f) {
        arg0->f4c = 499.0f;
    }
    switch (arg0->timer) {
    case 0x0:
        play_sound_effect(0x4003232C, 0, 0, 0);
        break;
    case 0xAE:
    case 0xCF:
        play_sound_effect(0x4003942D, 0, 0, 0);
        break;
    case 0x23B:
        play_sound_effect(0x40032830, 0, 0, 0);
        break;
    }
    if (arg0->timer >= 0x12C && arg0->timer <= 0x1AC) {
        play_persistent_sound(0x4003352E, (s32)arg0, 0, 0, 0);
    }
    if (arg0->timer >= 0x1D7 && arg0->timer <= 0x23A) {
        play_persistent_sound(0x32D2F, (s32)arg0, 0, 0, 0);
    }
    switch (arg0->timer) {
    case 0xAE:
    case 0xCF: {
        Vec_8033E0F0 p = arg0->pos;
        vec3_add_to(&p, lbl_804780AC);
        spawn_particle_effect_with_flags(&p, 0x221, 0x40);
        spawn_particle_effect_with_flags(&p, 0x22F, 0x40);
        break;
    }
    case 0x1AC:
        spawn_particle_effect_with_flags(&arg0->f74, 0x223, 0x40);
        break;
    case 0x23A: {
        Vec_8033E0F0 p = arg0->pos;
        vec3_add_to(&p, lbl_804780B8);
        spawn_particle_effect_with_flags(&p, 0xA4, 0x40);
        spawn_particle_effect_with_flags(&p, 0xE3, 0x40);
        break;
    }
    }
    if (arg0->timer >= 0x12C && arg0->timer < 0x1BA) {
        spawn_particle_effect_with_flags(&arg0->f74, 0x22E, 0x40);
    }
    {
        Vec_8033E0F0 *ptrs[4];
        s32 i;
        ptrs[0] = &arg0->pos;
        ptrs[1] = &arg0->f64;
        ptrs[2] = &arg0->f74;
        ptrs[3] = &arg0->f64;
        for (i = 0; i < 4; i++) {
            if (arg0->timer >= boss6_type2_death_emitter_ranges[i].start && arg0->timer < boss6_type2_death_emitter_ranges[i].end) {
                if (arg0->emit[i] == 0) {
                    arg0->emit[i] = create_particle_emitter(ptrs[i], boss6_type2_death_emitter_ranges[i].id);
                    if (arg0->emit[i] != 0) {
                        ((TParticleCtrl *)(arg0->emit[i]))->set_flags(0x40);
                    }
                } else {
                    ((TParticleCtrl *)arg0->emit[i])->set_position(ptrs[i]);
                }
            } else if (arg0->emit[i] != 0) {
                TParticleCtrl::release(arg0->emit[i]);
                arg0->emit[i] = 0;
            }
        }
    }
    if (arg0->timer >= 0x1AE) {
        s32 pb;
        s32 pm;
        VecCopy((Vec *)&a, (const Vec *)&arg0->f84);
        pb = (s32)&b;
        VecCopy((Vec *)pb, (const Vec *)&arg0->f90);
        pm = (s32)&mid;
        VecCopy((Vec *)pm, (const Vec *)&a);
        vec3_add_to((void *)pm, (void *)pb);
        mid.x *= (0.5f);
        mid.y *= (0.5f);
        mid.z *= (0.5f);
        ((TBoss6Type1 *)(arg0->fb0))->set_effect_points((f32 *)&a, (u32 *)lbl_8047817C);
    }
    if (arg0->timer == 0x23A) {
        s32 n = TLobby::get_game_mode();
        Vec_8033E0F0 c;
        s32 i;
        VecCopy((Vec *)&c, (const Vec *)&arg0->pos);
        vec3_add_to(&c, lbl_804780B8);
        for (i = 0; i < n; i++) {
            Pl_8033E0F0 *p = (Pl_8033E0F0 *)get_player_data__10TObjPlayerFi(i);
            if (is_locally_controlled__10TObjPlayerFPv(p) != 0 && is_state_1f__14TBoss6PlotFalzFUi((u32)p) != 0) {
                Vec_8033E0F0 d;
                VecCopy((Vec *)&d, (const Vec *)&p->pos);
                subtract_vector(&d, &c);
                d.y = (0.0f);
                if (!(vector_length(&d) > (0.25f))) {
                    p->f30 |= 0x600;
                }
            }
        }
    }
    switch (arg0->timer) {
    case 0x5F:
    case 0x82:
    case 0xB1:
    case 0xCD:
    case 0xFA:
    case 0x10E:
    case 0x23C:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    arg0->timer++;
    if (arg0->timer >= 0x2CA || ((TObjFish *)(arg0->f54))->get_phase() != 7) {
        queue_destruction__7TObjectFv(arg0);
    }
}
#pragma pop

}
TBoss6Demo21_TYPE2_DEAD::~TBoss6Demo21_TYPE2_DEAD() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (((O_8033E5A8 *)this)->fa0[i] != NULL) {
            TParticleCtrl::release(((O_8033E5A8 *)this)->fa0[i]);
            ((O_8033E5A8 *)this)->fa0[i] = NULL;
        }
    }
    restore_player_cameras();
    refresh_players_equipment__14TBoss6PlotFalzFPv();
    if (((O_8033E5A8 *)this)->f70 != NULL) {
        TObjFish::init_state_1(((O_8033E5A8 *)this)->f70);
        ((O_8033E5A8 *)this)->f70 = NULL;
    }
    if (((O_8033E5A8 *)this)->f80 != NULL) {
        TObjFish::init_state_1(((O_8033E5A8 *)this)->f80);
        ((O_8033E5A8 *)this)->f80 = NULL;
    }
    if (((O_8033E5A8 *)this)->f9c != NULL) {
        TObjFish::init_state_1(((O_8033E5A8 *)this)->f9c);
        ((O_8033E5A8 *)this)->f9c = NULL;
    }
}
#pragma push
#pragma opt_common_subs off
typedef struct { f32 x, y, z; } Vec_8033E688;
typedef struct {
    u8 pad[0xA0];
    s32 arr[4];
} Fish_8033E688;
#define arg0 ((u8 *)arg0p)
extern "C" {
void *TBoss6Demo21_TYPE2_DEAD__ct(void *arg0p, void *arg1, void *arg2) {
    Vec_8033E688 v;
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    *(u8 **)((s8 *)arg0 + 0x18) = __vt__23TBoss6Demo21_TYPE2_DEAD;
    *(s32 *)((s8 *)arg0 + 0) = (*(s32 *)&TBoss6Demo21_TYPE2_DEAD__name);
    *(void **)((s8 *)arg0 + 0x54) = arg1;
    VecCopy((Vec *)(arg0 + 0x58), (const Vec *)lbl_804780A0);
    VecCopy((Vec *)&v, (const Vec *)arg2);
    subtract_vector(&v, lbl_804780A0);
    v.y = (0.0f);
    if (vector_length(&v) > 60.0f) {
        normalize_vector(&v);
        v.x *= 60.0f;
        v.z *= 60.0f;
    }
    vec3_add_to(arg0 + 0x58, &v);
    void *count = get_fish_count__8TObjFishFv();
    *(s32 *)((s8 *)arg0 + 0x1C) = get_bml_model(count, 4);
    *(s32 *)((s8 *)arg0 + 0x20) = TObjFish__sub_8001EDB0(count, 4);
    ((TBoss6Type1 *)arg0)->texlist = get_bml_motion(count, 7);
    *(s32 *)((s8 *)arg0 + 0x28) = get_bml_model(count, 5);
    *(s32 *)((s8 *)arg0 + 0x2C) = TObjFish__sub_8001EDB0(count, 5);
    ((TBoss6Type1 *)arg0)->actorFlags = get_bml_motion(count, 7);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model(count, 8);
    *(s32 *)((s8 *)arg0 + 0x38) = TObjFish__sub_8001EDB0(count, 8);
    *(s32 *)((s8 *)arg0 + 0x3C) = get_bml_motion(count, 8);
    *(s32 *)((s8 *)arg0 + 0x40) = get_bml_model(count, 0xD);
    *(s32 *)&((TBoss6Type1 *)arg0)->prev_position.x = TObjFish__sub_8001EDB0(count, 0xD);
    *(s32 *)&((TBoss6Type1 *)arg0)->prev_position.y = get_bml_motion(count, 0x3D);
    *(s32 *)&((TBoss6Type1 *)arg0)->scale.z = TObjFish__sub_800E3124(boss6_type2_death_effect_desc_a, (s32)(arg0 + 0x64));
    *(s32 *)((s8 *)arg0 + 0x80) = TObjFish__sub_800E3124(boss6_type2_death_effect_desc_b, (s32)(arg0 + 0x74));
    *(s32 *)((s8 *)arg0 + 0x9C) = TObjFish__sub_800E3124(boss6_type2_death_effect_desc_c, (s32)(arg0 + 0x84));
    activate_camera_mode(5);
    set_scripted_camera_pose(arg0 + 0x58, arg0 + 0x58, lbl_80478134);
    ((TCameraCtrl *)lbl_80478140)->cache_target_and_forward(0x416C);
    for (i = 0; i < 4; i++) {
        ((Fish_8033E688 *)arg0)->arr[i] = 0;
    }
    ((TBoss6Type1 *)arg0)->motion_flags = create_zanzo__11TBoss6Type1FPvPvPv(arg0, 3, 0xF);
    *(f32 *)((s8 *)arg0 + 0x4C) = (0.0f);
    *(s32 *)((s8 *)arg0 + 0x50) = 0;
    return arg0;
}
}
#undef arg0
#pragma pop

void * create_boss6_type2_death(void *arg0, void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TBoss6Demo21_TYPE2_DEAD__ct(o, arg0, arg1);
    }
    return o;
}
#undef __vt__23TBoss6Demo21_TYPE2_DEAD
