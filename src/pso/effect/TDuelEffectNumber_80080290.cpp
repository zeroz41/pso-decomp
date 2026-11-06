#include "types.h"
#include "pso/effect/TDuelEffectNumber.h"
#include "pso/effect/TDuelEffectString.h"

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

void TDuelEffectNumber::render_pair(f32 f) {
    s32 i;
    for (i = 0; i < 2; i++) {
        TDuelEffectNumber__sub_800802F8(this, &duel_number_pair_layout[i], f);
    }
}

void TDuelEffectNumber::render_number_default(f32 farg0) {
    TDuelEffectNumber__sub_800802F8(this, &duel_number_default_layout, farg0);
}
