#include "types.h"
#include "pso/render/RenderFadeState.h"
#include "pso/render/DebugFont.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/render/ProjectedStripDraw.h"
#include "pso/system/memory.h"

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

s32 RenderFadeState::updateFromCamera(const Vec *position) {
    Vec cameraPosition;
    matrix_mult_vec(NULL, position, &cameraPosition);
    if (-cameraPosition.z < 28.0f) {
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


void RenderFadeState::activate_and_dispatch() {
    restoring = 1;
    reset_color();
}

void RenderFadeState::set_flags_and_apply_damage_color() {
    MaterialColorFade::set_flags_and_apply_damage_color();
    set_chunk_blend(9472);
}

RenderFadeState::~RenderFadeState() {}

RenderFadeState::RenderFadeState() {
    activate_and_dispatch();
}

__declspec(section ".data") u32 lbl_804949A0[2] = { 0 };
