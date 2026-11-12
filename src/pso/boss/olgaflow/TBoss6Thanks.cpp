#include "types.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/olgaflow/TBoss6Thanks.h"

#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"

typedef char Thanks_current_motion[offsetof(TBoss6Thanks,current_motion)==0x20?1:-1];
typedef char Thanks_frame0[offsetof(TBoss6Thanks,frame0)==0x28?1:-1];
typedef char Thanks_frame1[offsetof(TBoss6Thanks,frame1)==0x2c?1:-1];
typedef char Thanks_opacity[offsetof(TBoss6Thanks,opacity)==0x30?1:-1];
typedef char Thanks_model0[offsetof(TBoss6Thanks,model0)==0x38?1:-1];
typedef char Thanks_model1[offsetof(TBoss6Thanks,model1)==0x3c?1:-1];
typedef char Thanks_texture0[offsetof(TBoss6Thanks,texture0)==0x40?1:-1];
typedef char Thanks_texture1[offsetof(TBoss6Thanks,texture1)==0x44?1:-1];
typedef char Thanks_motions[offsetof(TBoss6Thanks,motions)==0x48?1:-1];
typedef char Thanks_motion1[offsetof(TBoss6Thanks,motion1)==0x50?1:-1];
struct ThanksMotionHeader
{
  u32 x0;
  u32 count;
};

extern "C" {

s32 scale_matrix(int, f32, f32, f32);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern u8 TBoss6Thanks__data_80479BA8[];

}

struct RecoveredGlobal_8035D10C___vt__12TBoss6Thanks { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_8035D10C___vt__12TBoss6Thanks_size[sizeof(RecoveredGlobal_8035D10C___vt__12TBoss6Thanks) == 0x18 ? 1 : -1];

struct RecoveredGlobal_8035D0A4___vt__12TBoss6Thanks { s32 value; u8 remaining[0x14]; };

struct O_8035CCAC { u8 pad[0x54]; s32 arr[4]; };

struct E_8035CC50 { void *p; };

struct W_8035CC50 { u8 pad0[0x54]; E_8035CC50 e[4]; };

struct Ent_8035CB88 { s32 id; s32 lo; s32 hi; };

struct Obj_8035CB88 { u8 pad[0x34]; s32 x30; u8 pad38[0x1C]; void *p[4]; };

extern "C" {
s32 get_bml_motion(void *, s32);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_8035D10C___vt__12TBoss6Thanks __vt__12TBoss6Thanks;
extern s32 TBoss6Thanks__class_name;
u8 *TBoss6Thanks__ct(TBoss6Thanks *arg0, u8 *arg1);
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
int TBoss6Thanks__sub_8035CB40(void);
u8 *__dt__12TBoss6ThanksFv(u8 *arg0, s16 arg1);
void TBoss6Thanks__sub_8035CCAC(s32 arg0);
extern Ent_8035CB88 boss6_thanks_particle_emitter_table[];
f32 xyz_distance(void *, void *);
u8 fn_8035CAE0(void);
int dispatch_by_main_phase__14TBoss4DarkFalzFUs(void*);

u8 fn_8035CAE0(void) {
    return (u8) (get_story_flag(0x9A) != 0);
}
u8 TBoss6Thanks::check_ship_door() {
    return (u8) (get_story_flag(0x98) != 0);
}
int TBoss6Thanks__sub_8035CB40(void) { return dispatch_by_main_phase__14TBoss4DarkFalzFUs((void*)(154)); }
int TBoss6Thanks::dispatch_darkfalz_phase() { return dispatch_by_main_phase__14TBoss4DarkFalzFUs((void*)(152)); }

void TBoss6Thanks::update_particle_emitters() {
    Obj_8035CB88 *o = (Obj_8035CB88 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        Ent_8035CB88 *e = &boss6_thanks_particle_emitter_table[i];
        if (*(s32 *)&this->m_34 >= e->lo && *(s32 *)&this->m_34 <= e->hi) {
            if (o->p[i] == NULL) {
                o->p[i] = create_particle_emitter(TBoss6Thanks__data_80479BA8, e->id);
                if (o->p[i] != NULL) {
                    ((TParticleCtrl *)(o->p[i]))->set_flags(0x40);
                }
            }
        } else {
            if (o->p[i] != NULL) {
                TParticleCtrl::release(o->p[i]);
                o->p[i] = NULL;
            }
        }
    }
}

void TBoss6Thanks::destroy_effects() {
    W_8035CC50 *arg0 = (W_8035CC50 *)this;
    s32 i;
    for (i = 0; i < 4; i++) {
        if (arg0->e[i].p != NULL) {
            TParticleCtrl::release(arg0->e[i].p);
            arg0->e[i].p = NULL;
        }
    }
}

void TBoss6Thanks__sub_8035CCAC(s32 arg0) {
    O_8035CCAC *self = (O_8035CCAC *)arg0;
    s32 i;
    for (i = 0; i < 4; i++) {
        self->arr[i] = 0;
    }
}

int TBoss6Thanks::is_player_near(void *arg0) {
    s32 i;
    s32 n;
    u8 *p;
    f32 r;
    n = TLobby::get_game_mode();
    r = 30.0f;
    for (i = 0; i < n; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && ((TBoss6PlotFalz *)p)->is_active() != 0 &&
            xyz_distance(p + 0x38, TBoss6Thanks__data_80479BA8) <= r) {
            return 1;
        }
    }
    return 0;
}

}

void TBoss6Thanks::render() {
    TBoss6Thanks *o = this;
    if (0.0f == o->opacity) {
        return;
    }
    TBoss6PlotFalz::set_fade_material_color(o->opacity);
    set_motion_packed_rotation();
    push_matrix();
    post_translate_matrix(TBoss6Thanks__data_80479BA8);
    TObjFish::set_global_param(o->texture0);
    scale_matrix(0, 1.2f, 1.2f, 1.2f);
    draw_model_motion(o->model0, o->motions[o->current_motion], o->frame0);
    pop_matrix();
    push_matrix();
    post_translate_matrix(TBoss6Thanks__data_80479BA8);
    TObjFish::set_global_param(o->texture1);
    scale_matrix(0, 1.2f, 1.2f, 1.2f);
    draw_model_motion(o->model1, o->motion1, o->frame1);
    pop_matrix();
    clear_motion_packed_rotation();
    TObjFish::reset_fish_globals();
}

extern "C" {

void TBoss6Thanks::update_fade_out() {
    s32 temp_r3;

    if ((s32) this->current_motion != 1) {
        if ((s32) *(s32 *)&this->m_34 == 0) {
            play_sound_effect(0x40033231, 0, 0, 0);
        }
        update_particle_emitters();
        this->opacity = (f32) (0.99f * (1.0f - ((f32) *(s32 *)&this->m_34 / 120.0f)));
        temp_r3 = *(s32 *)&this->m_34;
        if (temp_r3 == 0x78) {
            play_sound_effect(0x40033232, 0, 0, 0);
            queue_destruction__7TObjectFv(this);
            return;
        }
        *(s32 *)&this->m_34 = (temp_r3 + 1);
    }
}

void TBoss6Thanks::advance_thanks_state() {
    if ((s32) this->current_motion == 1) {
        this->m_24 = 0;
        this->m_1c = 2;
    }
}

void TBoss6Thanks::mark_done() { if (TBoss6Thanks::is_player_near(this) != 0) { this->m_24 = 1; this->m_1c = 1; } }

typedef struct ThanksMotionHeader ThanksMotionHeader;
typedef struct Thanks_8035CF78 Thanks_8035CF78;
void TBoss6Thanks::run_task() {
  f32 lim;
  s32 *new_var;
  TBoss6Thanks *o = this;
  switch (o->m_1c)
  {
    case 0:
      ((TBoss6Thanks *)o)->mark_done();
      break;
    case 1:
      ((TBoss6Thanks *)o)->advance_thanks_state();
      break;
    case 2:
      ((TBoss6Thanks *)o)->update_fade_out();
      break;
  }
  o->frame0 += 0.6f;
  lim = ((f32) ((ThanksMotionHeader *)o->motions[o->current_motion])->count) - 1.0f;
  if (o->frame0 >= lim)
  {
    o->frame0 -= lim;
    if ((*(new_var = &o->m_24)) != o->current_motion)
    {
      o->current_motion = *new_var;
    }
  }
  o->frame1 += 0.6f;
  lim = ((f32) ((ThanksMotionHeader *)o->motion1)->count) - 1.0f;
  if (o->frame1 >= lim)
  {
    o->frame1 -= lim;
  }
}

u8 *__dt__12TBoss6ThanksFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8035D0A4___vt__12TBoss6Thanks *)&__vt__12TBoss6Thanks).value;
        TBoss6Thanks__sub_8035CB40();
        ((TBoss6Thanks *)arg0)->destroy_effects();
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

u8 *TBoss6Thanks__ct(TBoss6Thanks *boss6_thanks, u8 *arg1) {
    u8 *fish_count;
    __ct__7TObjectFP7TObject(boss6_thanks, arg1);
    *(s32 **)((s8 *)boss6_thanks + 0x18) = &__vt__12TBoss6Thanks.value;
    *(s32 *)((s8 *)boss6_thanks + 0) = (s32) TBoss6Thanks__class_name;
    fish_count = (u8 *)(TObjFish::get_fish_count());
    *(s32 *)((s8 *)boss6_thanks + 0x38) = get_bml_model(fish_count, 7);
    boss6_thanks->texture0 = TObjFish__sub_8001EDB0(fish_count, 7);
    *(s32 *)((s8 *)boss6_thanks + 0x48) = get_bml_motion(fish_count, 9);
    *(s32 *)((s8 *)boss6_thanks + 0x4C) = get_bml_motion(fish_count, 0xB);
    *(s32 *)((s8 *)boss6_thanks + 0x3C) = get_bml_model(fish_count, 9);
    boss6_thanks->texture1 = TObjFish__sub_8001EDB0(fish_count, 9);
    *(s32 *)((s8 *)boss6_thanks + 0x50) = get_bml_motion(fish_count, 0xA);
    TBoss6Thanks__sub_8035CCAC((s32)((s32) boss6_thanks));
    boss6_thanks->m_1c = 0;
    boss6_thanks->m_24 = 0;
    boss6_thanks->current_motion = 0;
    boss6_thanks->frame0 = 0.0f;
    boss6_thanks->frame1 = 0.0f;
    boss6_thanks->opacity = 0.99f;
    boss6_thanks->m_34 = 0;
    return (u8 *)boss6_thanks;
}

}
