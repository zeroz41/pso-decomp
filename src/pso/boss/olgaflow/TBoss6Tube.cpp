#include "types.h"
#include "pso/render/render_util.h"
#include "pso/boss/olgaflow/TBoss6Tube.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp_802B0E2C.h"
#include "pso/boss/olgaflow/TBoss6Tube_802B15F4.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

const char *boss06_tube_dat_model_names[4] = { "boss06_light01.gj", "boss06_light02.gj", "boss06_tube01.gj", NULL };
const char *boss06_tube_dat_motion_names[1] = { NULL };
BmlResourceDescriptor boss06_tube_dat_resource_descriptor = { "boss06_tube_dat.bml", boss06_tube_dat_model_names, boss06_tube_dat_motion_names, 3, 0 };
const char *TBoss6Tube__name = "TBoss6Tube";
// The model drawn on each of render's three passes (name inferred).
const s32 boss6_tube_model_order[3] = { 2, 0, 1 };
u32 boss6_tube_bml_resource;
u32 boss6_tube_texture_list;

typedef struct TBoss6Tube_802B1020 {
    u8 pad[0x28];
    s32 f28;
    s32 f2c;
} TBoss6Tube_802B1020;

extern "C" {
void TBoss6Tube__sub_802B129C(u8 *arg0);
s32 TBoss6Tube__previous_scroll_phase;
f32 TBoss6Tube__scroll_delta;
void get_bml_model(s32, s32);
s32 query_teammate_state__9TObjEneDDFv(void);
void push_matrix(void);
void draw_ginja_object(void);
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
            get_bml_model(boss6_tube_bml_resource, boss6_tube_model_order[i]);
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

extern "C" {

s32 query_teammate_state__9TObjEneDDFv();

void TBoss6Tube::run_task() {

    if ((TBoss6EmptyWarp__sub_802B1018() == 0) && (query_teammate_state__9TObjEneDDFv() == 0)) {
        switch (this->m_1c) {
        case 0:
            update_timer();
            return;
        case 1:
            spawn_trap();
            sub_802B1218();
            return;
        case 2:
            update_wobble();
            break;
        }
    }
}

}

struct RecoveredGlobal_802B1654___vt__10TBoss6Tube { s32 value; u8 remaining[0x14]; };
typedef char RecoveredGlobal_802B1654___vt__10TBoss6Tube_size[sizeof(RecoveredGlobal_802B1654___vt__10TBoss6Tube) == 0x18 ? 1 : -1];

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__10TBoss6Tube[];

}
TBoss6Tube::~TBoss6Tube() {
    TBoss6Tube::reset_state();
}

u8 *TBoss6Tube__ct(TBoss6Tube *boss6_tube, u8 *arg1) {
    __ct__7TObjectFP7TObject(boss6_tube, arg1);
    *(s32 **)((s8 *)boss6_tube + 0x18) = &(*(RecoveredGlobal_802B1654___vt__10TBoss6Tube *)&__vt__10TBoss6Tube).value;
    boss6_tube->m_name = TBoss6Tube__name;
    *(u8 **)((s8 *)boss6_tube + 0x2C) = arg1;
    boss6_tube->m_24 = 0;
    boss6_tube->m_28 = 0;
    TBoss6Tube::reset_state();
    boss6_tube->m_20 = 0;
    boss6_tube->m_1c = 0;
    return (u8 *)boss6_tube;
}

extern "C" {
s32 load_resource_from_descriptor(s32, int, void *, int, int, int);
u8 *load_gvm_texture_file(s32 arg0);
void free_bin_model_request(void*, int);
s32 release_texture_list(void*);
void *__nw__7TObjectFUl(int);

void *TBoss6Tube::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x30);
    if (o != NULL) {
        o = TBoss6Tube__ct((TBoss6Tube *)((u8 *)o), (u8 *)arg0);
    }
    return o;
}

void TBoss6Tube::free_resources() {
    if ((u32) boss6_tube_bml_resource != 0U) {
        free_bin_model_request((void*)boss6_tube_bml_resource, 1);
        boss6_tube_bml_resource = 0U;
    }
    if ((u32) boss6_tube_texture_list != 0U) {
        release_texture_list((void*)boss6_tube_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(boss6_tube_texture_list);
        boss6_tube_texture_list = 0U;
    }
    TBoss6Tube::reset_state();
}
void TBoss6Tube::load_resources() {
    s32 r;
    TBoss6Tube::reset_state();
    r = (int)::operator new(0x440);
    if (r != 0) {
        r = load_resource_from_descriptor(r, 5, &boss06_tube_dat_resource_descriptor, 0, 0, 0);
    }
    boss6_tube_bml_resource = r;
    boss6_tube_texture_list = (u32)load_gvm_texture_file((s32)"boss06_tube_dat.gvm");
    if (boss6_tube_bml_resource != 0 && boss6_tube_texture_list != 0) {
        return;
    }
}

}

