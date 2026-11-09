#include "types.h"
#include "pso/effect/TDuelEffectNumber.h"
#include "pso/effect/TDuelEffectString.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

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

// Draws one glyph quad of the number at the effect position, scaled by `scale`.
void TDuelEffectNumber__sub_800802F8(TDuelEffectNumber *self, const DuelEffectQuad *quad, f32 scale) {
    f32 q[8];
    f32 depth;

    TCameraCtrl::get_camera_no();
    depth = -1.0f / TWindowCtrlMain::get_scale();
    q[0] = quad->x * scale + self->pad_1C[0];
    q[1] = quad->y * scale + self->pad_1C[1];
    q[2] = scale * (quad->x + quad->w) + self->pad_1C[0];
    q[3] = scale * (quad->y + quad->h) + self->pad_1C[1];
    q[4] = quad->u;
    q[5] = quad->v;
    q[6] = quad->u + quad->w;
    q[7] = quad->v + quad->h;
    q[4] *= 0.00390625f;
    q[5] *= 0.00390625f;
    q[6] *= 0.00390625f;
    q[7] *= 0.00390625f;
    draw_textured_quad_at_depth(q, depth);
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
