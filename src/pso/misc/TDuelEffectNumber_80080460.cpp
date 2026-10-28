#pragma push

#include "types.h"
#include "pso/misc/TDuelEffectNumber_80080460.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/TDuelEffectString.h"
#include "pso/TDuelEffectNumber.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#pragma fp_contract on

extern "C" {
extern const f32 lbl_805D9330;
s32 __cvt_fp2unsigned(f32);
extern s32 lbl_805D63F0;
extern const f32 lbl_805D932C;
extern const f32 lbl_805D9310;
extern const f32 lbl_805D9314;
extern const f32 lbl_805D9318;
extern const f32 lbl_805D931C;
extern const f32 lbl_805D9320;
extern const f32 lbl_805D9324;
extern const f32 lbl_805D9328;

void TDuelEffectNumber::calc_digit_transform(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    if (arg3 < 0xA) {
        *arg1 = -(lbl_805D9314 * ((f32) arg3 / lbl_805D9318) - lbl_805D9310);
    } else {
        *arg1 = lbl_805D9320 * ((arg3 - 0xA) / lbl_805D9324) + lbl_805D931C;
    }
    if (arg3 < 5) {
        *arg2 = (f32) (arg3 / 5);
        return;
    }
    *arg2 = lbl_805D931C - ((arg3 - 5) / lbl_805D9328);
}

}

#pragma pop

#pragma push

#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

f64 pow();

extern void *TDuelEffectString__class_name;

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void render__17TDuelEffectStringFv(u8 *duel_effect_number) {
    f32 spC;
    f32 sp8;
    s32 temp_r31;
    TDuelEffectNumber::calc_digit_transform((s32)((s32) duel_effect_number), &spC, &sp8, (s32)(*(s32 *)((s8 *)duel_effect_number + 0x28)));
    temp_r31 = __cvt_fp2unsigned(lbl_805D932C * sp8) | 0xFF0000 | 0xFFFF;
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(6, temp_r31);
    switch (*(s32 *)((s8 *)duel_effect_number + 0x24)) {
    case 0:
        ((TDuelEffectNumber *)duel_effect_number)->render_number_default(spC);
        break;
    case 1:
        ((TDuelEffectNumber *)duel_effect_number)->render_pair(spC);
        break;
    }
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
#pragma pop

void TDuelEffectString::run_task() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) (*(s32 *)((s8 *)arg0 + 0x28) + 1);
    if ((f32) *(s32 *)((s8 *)arg0 + 0x28) >= lbl_805D9330) {
        queue_destruction__7TObjectFv(arg0);
    }
}

TDuelEffectString::~TDuelEffectString() {}
}
TDuelEffectString::TDuelEffectString(TObject *object, void *arg2, void *arg3) : TObject(object) {
    *(void * *)&this->m_name = TDuelEffectString__class_name;
    *(f32 *)((s8 *)this + 0x1C) = *(f32 *)((s8 *)arg2 + 0x0);
    *(f32 *)((s8 *)this + 0x20) = *(f32 *)((s8 *)arg2 + 0x4);
    *(void **)((s8 *)this + 0x24) = arg3;
    *(u32 *)((s8 *)this + 0x28) = 0;
}

f32 TBoss8Dragon__sub_8008072C(void) {
    return (f32) pow();
}

#pragma pop
