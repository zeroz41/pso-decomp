// ---- pso/unk/text_800A0320
#include "types.h"
#include "pso/render/ProjectedStripDraw.h"
#include "pso/render/MaterialShadeFade.h"
#include "pso/player/TObjPlayer.h"


s32 MaterialShadeFade::has_visible_opacity() {
    return phase > 0.0f;
}

void MaterialShadeFade::set_flags_and_apply_damage_color() { MaterialColorFade::set_flags_and_apply_damage_color(); set_chunk_blend(7424); }
s32 MaterialShadeFade::advance_toward_max() {
    f32 current;
    current = phase;
    phase = (f32) (current + this->rate);
    this->calc_recoil_offsets();
    return phase >= 2.0f;
}
s32 MaterialShadeFade::decay_value_toward_floor() {
    f32 phase;
    phase = this->phase;
    this->phase = (f32) (phase - this->rate);
    this->calc_recoil_offsets();
    return this->phase <= 0.0f;
}


// ---- pso/player/TObjPlayer_800A0408

#include "pso/object/TObjControl.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/system/memory.h"


void MaterialShadeFade::calc_recoil_offsets() {
    f32 current;
    f32 shade;

    current = phase;
    if (current > 1.0f) {
        if (current > 2.0f) {
            this->color.a = 0.0f;
        } else {
            this->color.a = (f32) (current - 2.0f);
        }
        this->color.r = 0.0f;
        this->color.g = 0.0f;
        this->color.b = 0.0f;
        return;
    }
    this->color.a = -1.0f;
    shade = phase - 1.0f;
    if (shade < (-1.0f)) {
        shade = (-1.0f);
    }
    this->color.r = shade;
    this->color.g = shade;
    this->color.b = shade;
}

    
    
void MaterialShadeFade::reset_obstruction_fade() { phase = 0.0f; this->color.a = (-1.0f); this->color.r = (-1.0f); this->color.g = (-1.0f); this->color.b = (-1.0f); }

    
void MaterialShadeFade::reset_color() { phase = 2.0f; this->color.a = 0.0f; this->color.r = 0.0f; this->color.g = 0.0f; this->color.b = 0.0f; }

void MaterialShadeFade::set_rate_from_divisor(s32 divisor) {
    this->rate = (f32) (2.0f / (f32) divisor);
}
#pragma push
#pragma fp_contract on
void MaterialShadeFade::start_fade_out() {
    set_rate_from_divisor(10);
    phase = 1e+01f * rate + 2.0f;
    color.a = 1.0f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
}
#pragma pop

void MaterialShadeFade::start_fade_in() {
    set_rate_from_divisor(10);
    phase = -(2e+01f * rate);
    color.a = 0.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}


MaterialShadeFade::~MaterialShadeFade() {}


MaterialShadeFade::MaterialShadeFade() : MaterialColorFade(), phase(0.0f) {}
