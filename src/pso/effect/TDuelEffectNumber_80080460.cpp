#pragma push

#include "types.h"
#include "pso/effect/TDuelEffectNumber_80080460.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/effect/TDuelEffectString.h"
#include "pso/effect/TDuelEffectNumber.h"
#include "pso/render/render_util.h"
#pragma fp_contract on

extern "C" {
s32 __cvt_fp2unsigned(f32);
extern s32 lbl_805D63F0;

void TDuelEffectNumber::calc_digit_transform(s32 arg0, f32 *arg1, f32 *arg2, s32 arg3) {
    if (arg3 < 0xA) {
        *arg1 = 2.5f - 1.5f * ((f32) arg3 / 10.0f);
    } else {
        *arg1 = 1.0f + 0.2f * ((arg3 - 0xA) / 20.0f);
    }
    if (arg3 < 5) {
        *arg2 = (f32) (arg3 / 5);
        return;
    }
    *arg2 = 1.0f - ((arg3 - 5) / 25.0f);
}

}

#pragma pop

#pragma push

#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

f64 pow();


#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void render__17TDuelEffectStringFv(u8 *duel_effect_number) {
    f32 spC;
    f32 sp8;
    s32 temp_r31;
    TDuelEffectNumber::calc_digit_transform((s32)((s32) duel_effect_number), &spC, &sp8, (s32)(*(s32 *)((s8 *)duel_effect_number + 0x28)));
    temp_r31 = __cvt_fp2unsigned(4278190080.0f * sp8) | 0xFF0000 | 0xFFFF;
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
    if ((f32) *(s32 *)((s8 *)arg0 + 0x28) >= 30.0f) {
        queue_destruction__7TObjectFv(arg0);
    }
}

TDuelEffectString::~TDuelEffectString() {}
}
TDuelEffectString::TDuelEffectString(TObject *object, void *arg2, void *arg3) : TObject(object) {
    m_name = TDuelEffectString__class_name;
    pad_1C[0] = ((f32 *)arg2)[0];
    pad_1C[1] = ((f32 *)arg2)[1];
    pad_24 = arg3;
    pad_28 = 0;
}

f32 TBoss8Dragon__sub_8008072C(void) {
    return (f32) pow();
}

#pragma pop
