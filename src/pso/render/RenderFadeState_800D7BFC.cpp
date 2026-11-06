#include "pso/render/RenderFadeState.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
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
