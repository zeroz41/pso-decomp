#include "types.h"
#include "pso/effect/TDuelEffectNumber.h"
#include "pso/effect/TDuelEffectString.h"

#pragma fp_contract on

const char* TDuelEffectString__class_name = "TDuelEffectString";

// One glyph quad: offset from the effect position (scaled with it), size, texel origin (in 1/256 units).
struct DuelEffectQuad {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
    f32 u;
    f32 v;
};

extern const DuelEffectQuad duel_number_default_layout = { -96.0f, -24.0f, 192.0f, 48.0f, 64.0f, 133.0f };
extern const DuelEffectQuad duel_number_pair_layout[2] = {
    { -121.0f, -24.0f, 192.0f, 48.0f, 64.0f, 85.0f },
    { 37.0f, -24.0f, 192.0f, 48.0f, 64.0f, 181.0f },
};

extern "C" void TDuelEffectNumber__sub_800802F8(TDuelEffectNumber *self, const DuelEffectQuad *quad, f32 scale);

TDuelEffectNumber::TDuelEffectNumber(TObject *object, void *arg2, void *arg3) : TObject(object) {
    m_name = TDuelEffectNumber__class_name;
    pad_1C[0] = ((f32 *)arg2)[0];
    pad_1C[1] = ((f32 *)arg2)[1];
    pad_24 = arg3;
    pad_28 = 0;
}

extern "C" {
void get_camera_no__11TCameraCtrlFv();
f32 get_scale__15TWindowCtrlMainFv();
void draw_textured_quad_at_depth(f32 *, f32);
extern const f32 lbl_805D9308;
extern const f32 lbl_805D930C;
}

void TDuelEffectNumber__sub_800802F8(TDuelEffectNumber *arg0, const DuelEffectQuad *arg1, f32 arg2) {
    f32 q[8];
    get_camera_no__11TCameraCtrlFv();
    f32 scale = get_scale__15TWindowCtrlMainFv();
    f32 ratio = lbl_805D9308 / scale;
    f32 t4 = *(f32 *)((s8 *)arg1 + 0x10);
    f32 t5 = *(f32 *)((s8 *)arg1 + 0x14);
    f32 t6 = t4 + *(f32 *)((s8 *)arg1 + 0x8);
    f32 t7 = t5 + *(f32 *)((s8 *)arg1 + 0xC);
    *(f32 *)&q[0] = *(f32 *)((s8 *)arg1 + 0x0) * arg2 + *(f32 *)((s8 *)arg0 + 0x1C);
    *(f32 *)&q[1] = *(f32 *)((s8 *)arg1 + 0x4) * arg2 + *(f32 *)((s8 *)arg0 + 0x20);
    *(f32 *)&q[2] = (*(f32 *)((s8 *)arg1 + 0x0) + *(f32 *)((s8 *)arg1 + 0x8)) * arg2 + *(f32 *)((s8 *)arg0 + 0x1C);
    *(f32 *)&q[3] = (*(f32 *)((s8 *)arg1 + 0x4) + *(f32 *)((s8 *)arg1 + 0xC)) * arg2 + *(f32 *)((s8 *)arg0 + 0x20);
    *(f32 *)&q[4] = t4;
    *(f32 *)&q[5] = t5;
    *(f32 *)&q[6] = t6;
    *(f32 *)&q[7] = t7;
    *(f32 *)&q[4] = t4 * lbl_805D930C;
    *(f32 *)&q[5] = t5 * lbl_805D930C;
    *(f32 *)&q[6] = t6 * lbl_805D930C;
    *(f32 *)&q[7] = t7 * lbl_805D930C;
    draw_textured_quad_at_depth(q, ratio);
}

void TDuelEffectNumber::render_pair(f32 f) {
    s32 i;
    for (i = 0; i < 2; i++) {
        TDuelEffectNumber__sub_800802F8(this, &duel_number_pair_layout[i], f);
    }
}

void TDuelEffectNumber::render_number_default(f32 farg0) {
    TDuelEffectNumber__sub_800802F8(this, &duel_number_default_layout, farg0);
}
