#include "types.h"
#include "pso/render/RenderFadeState.h"

extern "C" void matrix_mult_vec(int, const f32*, f32*);

#pragma push
#pragma opt_common_subs off
void RenderFadeState::update_fast() {
    f32 v = color.a;
    if (restoring == 0) {
        v -= 0.23333333f;
        if (v < -0.7f) {
            v = -0.7f;
        }
    } else {
        v += 0.23333333f;
        if (v > 0.0f) {
            v = 0.0f;
        }
    }
    color.a = v;
}
#pragma pop

s32 RenderFadeState::updateFromCamera(const f32* position) {
    f32 cameraPosition[3];
    matrix_mult_vec(0, position, cameraPosition);
    if (-cameraPosition[2] < 28.0f) {
        fadeOut();
    } else {
        restore();
    }
    return isFading();
}

s32 RenderFadeState::isFading() const {
    return color.a < 0.0f;
}

void RenderFadeState::restore() {
    restoring = 1;
}

void RenderFadeState::fadeOut() {
    restoring = 0;
}

void RenderFadeState::update() {
    f32 adjustment = color.a;
    if (restoring == 0) {
        adjustment -= 0.04f;
        if (adjustment < -0.7f) {
            adjustment = -0.7f;
        }
    } else {
        adjustment += 0.04f;
        if (adjustment > 0.0f) {
            adjustment = 0.0f;
        }
    }
    color.a = adjustment;
}
