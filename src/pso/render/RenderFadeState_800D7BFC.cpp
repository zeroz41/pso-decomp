#include "pso/render/RenderFadeState.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/memory.h"

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
