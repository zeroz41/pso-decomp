#include "types.h"
#include "pso/render/render_util.h"

#include "pso/boss/TBoss6Tube.h"
#include "pso/boss/TBoss6PlotFalz.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/object/TObjFish.h"

typedef struct TBoss6Tube_802B1020 {
    u8 pad[0x28];
    s32 f28;
    s32 f2c;
} TBoss6Tube_802B1020;

extern "C" {
f32 fabs_float(f32);
s32 rand(void);
void TBoss6Tube__sub_802B129C(u8 *arg0);
extern s32 TBoss6Tube__previous_scroll_phase;
extern f32 TBoss6Tube__scroll_delta;
void get_bml_model(s32, s32);
s32 query_teammate_state__9TObjEneDDFv(void);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
void push_matrix(void);
s32 pop_matrix(void);
void draw_ginja_object(void);
extern s32 lbl_80470A54[];
extern s32 boss6_tube_bml_resource;
extern s32 boss6_tube_texture_list;
s32 play_sound_effect(s32, s32, s32, s32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);

void TBoss6Tube::render() {
    TBoss6Tube_802B1020 *o = (TBoss6Tube_802B1020 *)this;
    f32 lo = (-1.6e+03f);
    f32 hi = (2.4e+03f);
    s32 mode;
    f32 start;
    f32 y;
    s32 i;
    if (query_teammate_state__9TObjEneDDFv() != 0) {
        return;
    }
    mode = 0;
    switch (((TObjFish *)(o->f2c))->get_phase()) {
    case 2: {
        f32 v = TBoss6PlotFalz::get_value();
        if (v < (-1e+01f)) {
            mode = 1;
        } else if (v > (1e+02f)) {
            mode = 2;
        }
        break;
    }
    case 1:
    case 3:
        mode = 3;
        break;
    }
    switch (mode) {
    case 0:
        break;
    case 1:
        lo = (-4.8e+03f);
        hi = (1.6e+03f);
        break;
    case 2:
        lo = (-8e+02f);
        hi = (5.6e+03f);
        break;
    case 3:
        lo = (-4.8e+03f);
        hi = (5.6e+03f);
        break;
    }
    start = lo - TBoss6Tube::scale_by_const(TBoss6Tube::calc_tube_progress(o->f28));
    TObjFish::set_global_param(boss6_tube_texture_list);
    set_draw_list_mask(3);
    for (i = 0; i < 3; i++) {
        for (y = start; y < hi; y += (8e+02f)) {
            push_matrix();
            translate_matrix(0, 0.0f, y, 0.0f);
            get_bml_model(boss6_tube_bml_resource, lbl_80470A54[i]);
            draw_ginja_object();
            pop_matrix();
        }
    }
    restore_draw_list_mask();
}

f32 TBoss6Tube::scale_by_const(f32 farg0) {
    return (8e+02f) * farg0;
}

f32 TBoss6Tube::calc_tube_progress(s32 arg0) {
    return (1.0f) - ((f32) (arg0 & 0x7FFFF) / (524288.0f));
}

void TBoss6Tube::sub_802B1218() {
    if (((0.0f) == TBoss6Tube__scroll_delta) && ((s32) TBoss6Tube__previous_scroll_phase == 0)) {
        TBoss6Tube__previous_scroll_phase = this->m_28;
        return;
    }
    TBoss6Tube__scroll_delta = TBoss6Tube::scale_by_const(TBoss6Tube::calc_tube_progress(TBoss6Tube__previous_scroll_phase - this->m_28));
    TBoss6Tube__previous_scroll_phase = this->m_28;
}

void TBoss6Tube::reset_state() {
    TBoss6Tube__previous_scroll_phase = 0;
    TBoss6Tube__scroll_delta = (0.0f);
}

#pragma fp_contract on
void TBoss6Tube__sub_802B129C(u8 *arg0) {
  f32 temp_f31;
  *((s32 *) (((s8 *) arg0) + 0x24)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x24))) + 0x3A);
  if (((s32) (*((s32 *) (((s8 *) arg0) + 0x24)))) > 0x3333)
  {
    *((s32 *) (((s8 *) arg0) + 0x24)) = 0x3333;
  }
  ;
  *((s32 *) (((s8 *) arg0) + 0x24)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x24))) + ((s32) (((0.075f) * ((2.0f) * (((3.0517578e-05f) * ((f32) rand())) - (0.5f)))) * fabs_float((f32) (*((s32 *) (((s8 *) arg0) + 0x24)))))));
  *((s32 *) (((s8 *) arg0) + 0x28)) = (s32) ((*((s32 *) (((s8 *) arg0) + 0x28))) + (*((s32 *) (((s8 *) arg0) + 0x24))));
}

#pragma push
#pragma fp_contract on
void TBoss6Tube::update_wobble() {
    *(s32 *)&this->m_24 = (s32) (*(s32 *)&this->m_24 + (s32) (((-464.0f) * ((3.0517578e-05f) * (f32) rand())) + (-116.0f)));
    if ((f32) *(s32 *)&this->m_24 <= (0.0f)) {
        *(s32 *)&this->m_24 = 0;
        *(s32 *)&this->m_28 = (s32) ((f32) *(s32 *)&this->m_28 + (((13107.0f) * ((3.0517578e-05f) * (f32) rand())) - (6553.0f)));
    }
    *(s32 *)&this->m_28 = (s32) (*(s32 *)&this->m_28 + *(s32 *)&this->m_24);
    TBoss6Tube__scroll_delta = (0.0f);
    TBoss6Tube__previous_scroll_phase = *(s32 *)&this->m_28;
}
#pragma pop

void TBoss6Tube::spawn_trap() {
    s32 arg0 = (s32)this;
    TBoss6Tube__sub_802B129C((u8 *)arg0);
    play_persistent_sound(0x40033520, arg0, 0, 0, 0);
}

void TBoss6Tube::update_timer() {
    this->m_20 = (this->m_20 + 1);
    if ((s32) this->m_20 >= 0x10E) {
        this->m_20 = 0;
        this->m_1c = 1;
        play_sound_effect(0x4003351F, 0, 0, 0);
        TCameraCtrl::set_shake_preset(2);
    }
}

}
