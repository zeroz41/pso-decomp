#include "pso/TDuelEffectNumber.h"
#include "pso/misc/TDuelEffectNumber.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/object/TObject_80019A50.h"

#include "types.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

struct RecoveredGlobal_800800EC_lbl_80438D7C {
    s32 value;
    u8 remaining[0x30];
};
struct Obj_8007FF28 {
    u8 pad0[0x1C];
    u8 x1C[0xC];
    s32 timer;
};

extern "C" {
s32 __cvt_fp2unsigned(f32);
void fn_8007FE78(Obj_8007FF28 *self, s32 arg1, void *arg2, f32 farg0, f32 farg1, f32 farg2);
extern const char TDuelEffectNumber__class_name_string[] = "TDuelEffectNumber";
extern const RecoveredGlobal_800800EC_lbl_80438D7C duel_number_uv_table = {0, {0x43, 0x2A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
void sub_8007FF28__17TDuelEffectNumberFl(Obj_8007FF28 *self, s32 arg1);
f32 get_scale__15TWindowCtrlMainFv(s32);

extern s32 lbl_805D63F0;

void fn_8007FE78(Obj_8007FF28 *self, s32 arg1, void *arg2, f32 farg0, f32 farg1, f32 farg2) {
    f32 *src = (f32 *)arg2;
    farg1 *= (0.5);
    *(f32 *)((s8 *)arg1 + 0) = src[0] - 64.0f * farg1;
    *(f32 *)((s8 *)arg1 + 4) = src[1] - 85.0f * farg1;
    *(f32 *)((s8 *)arg1 + 8) = src[0] + 64.0f * farg1;
    *(f32 *)((s8 *)arg1 + 0xC) = src[1] + 85.0f * farg1;
    set_constant_material_color(__cvt_fp2unsigned(4278190080.0f * farg2) | 0xFF0000 | 0xFFFF);
    draw_textured_quad_at_depth((f32 *)arg1, farg0);
}

#pragma push
#pragma fp_contract on
void TDuelEffectNumber::sub_8007FF28(s32 arg1) {
    f32 scale;
    f32 b;
    f32 c;

    if (((Obj_8007FF28 *)this)->timer >= 5 && ((Obj_8007FF28 *)this)->timer < 20) {
        scale = (-1.0f) / get_scale__15TWindowCtrlMainFv(TCameraCtrl::get_camera_no());
        c = (0.5f);
        b = c * ((((Obj_8007FF28 *)this)->timer - 5) / (15.0f)) + (1.0f);
        fn_8007FE78((Obj_8007FF28 *)(((Obj_8007FF28 *)this)), arg1, ((Obj_8007FF28 *)this)->x1C, scale, b, ((Obj_8007FF28 *)this)->timer < 10 ? c : c - c * ((((Obj_8007FF28 *)this)->timer - 10) / (1e+01f)));
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TDuelEffectNumber::sub_8007FFF4(s32 arg1) {
    f32 scale;
    f32 b;
    f32 c;

    scale = (-1.0f) / get_scale__15TWindowCtrlMainFv(TCameraCtrl::get_camera_no());
    if (((Obj_8007FF28 *)this)->timer < 5) {
        b = (2.0f) - ((f32) ((Obj_8007FF28 *)this)->timer / (5.0f));
        c = (0.5f);
        c = c * (f32) (((Obj_8007FF28 *)this)->timer / 5) + c;
    } else if (((Obj_8007FF28 *)this)->timer < 25) {
        c = b = (1.0f);
    } else {
        b = (1.0f);
        c = b - ((f32) (((Obj_8007FF28 *)this)->timer - 25) / (5.0f));
    }
    fn_8007FE78((Obj_8007FF28 *)(((Obj_8007FF28 *)this)), arg1, (void *)(((Obj_8007FF28 *)this)->x1C), scale, b, c);
}
}
#pragma pop

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_800800EC_lbl_80438D7C_size[sizeof(RecoveredGlobal_800800EC_lbl_80438D7C) == 0x34 ? 1 : -1];
void calc_duel_number_uv(s32 arg0, u8 *arg1, s32 arg2) {
    s32 temp_r0;
    temp_r0 = arg2 * 8;
    *(f32 *)((s8 *)arg1 + 0x10) = (f32) *(f32 *)((s8 *)((u8 *)&duel_number_uv_table.value + temp_r0) + 0);
    *(f32 *)((s8 *)arg1 + 0x14) = (f32) *(f32 *)((s8 *)((u8 *)&duel_number_uv_table.value + temp_r0) + 4);
    *(f32 *)((s8 *)arg1 + 0x18) = (f32) ((64.0f) + *(f32 *)((s8 *)arg1 + 0x10));
    *(f32 *)((s8 *)arg1 + 0x1C) = (f32) ((85.0f) + *(f32 *)((s8 *)arg1 + 0x14));
    *(f32 *)((s8 *)arg1 + 0x10) *= (0.00390625f);
    *(f32 *)((s8 *)arg1 + 0x14) *= (0.00390625f);
    *(f32 *)((s8 *)arg1 + 0x18) *= (0.00390625f);
    *(f32 *)((s8 *)arg1 + 0x1C) *= (0.00390625f);
}
#pragma pop

void TDuelEffectNumber::render() {
    char sp8[0x20];

    ((s32 (*)(void *, void *, s32))calc_duel_number_uv)(this, &sp8, *(s32 *)((s8 *)this + 0x24));
    set_additive_blend();
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D63F0);
    set_draw_texture_and_color(6, -1);
    sub_8007FFF4((s32)((s32 *)&sp8));
    ((s32 (*)(void *, s32 *))sub_8007FF28__17TDuelEffectNumberFl)(this, (s32 *)&sp8);
    TWindowSubStatusDisp::get_player();
    set_default_alpha_blend();
}
void TDuelEffectNumber::run_task() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) (*(s32 *)((s8 *)arg0 + 0x28) + 1);
    if ((f32) *(s32 *)((s8 *)arg0 + 0x28) >= (3e+01f)) {
        queue_destruction__7TObjectFv(arg0);
    }
}

TDuelEffectNumber::~TDuelEffectNumber() {}
