#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/memory.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/render/render_util.h"
#include "pso/boss/olgaflow/TBoss6Tube.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include <stdlib.h>
#include "pso/unk/text_803D96A8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"

const char *boss06_tube_dat_model_names[4] = { "boss06_light01.gj", "boss06_light02.gj", "boss06_tube01.gj", NULL };
const char *boss06_tube_dat_motion_names[1] = { NULL };
BmlResourceDescriptor boss06_tube_dat_resource_descriptor = { "boss06_tube_dat.bml", boss06_tube_dat_model_names, boss06_tube_dat_motion_names, 3, 0 };
const char *TBoss6Tube__name = "TBoss6Tube";
// The model drawn on each of render's three passes (name inferred).
const s32 boss6_tube_model_order[3] = { 2, 0, 1 };
BmlResource *boss6_tube_bml_resource;
NJS_TEXLIST *boss6_tube_texture_list;

extern "C" {
s32 TBoss6Tube__previous_scroll_phase;
f32 TBoss6Tube__scroll_delta;
}

// run_task's state 1: spawn the trap and run update_scroll_delta.
void TBoss6Tube::activate_warp() {
    state = 1;
    play_sound_effect(0x4003351F, 0, 0, 0);
}

void TBoss6Tube::start_wobble() {
    timer = 0;
    state = 2;
}

s32 TBoss6Tube::sub_802B1018() { return 0; }

void TBoss6Tube::render() {
    f32 lo = (-1.6e+03f);
    f32 hi = (2.4e+03f);
    s32 mode;
    f32 start;
    f32 y;
    s32 i;
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    mode = 0;
    switch (plot_falz->get_scene_state()) {
    case 2: {
        f32 v = TBoss6PlotFalz::get_value();
        if (v < (-1e+01f)) {
            mode = 1;
        } else if (v > (1e+02f)) {
            mode = 2;
        }
        break;
    }
    case 1:
    case 3:
        mode = 3;
        break;
    }
    switch (mode) {
    case 0:
        break;
    case 1:
        lo = (-4.8e+03f);
        hi = (1.6e+03f);
        break;
    case 2:
        lo = (-8e+02f);
        hi = (5.6e+03f);
        break;
    case 3:
        lo = (-4.8e+03f);
        hi = (5.6e+03f);
        break;
    }
    start = lo - TBoss6Tube::scale_by_const(TBoss6Tube::calc_tube_progress(scroll_phase));
    TObjFish::set_global_param(boss6_tube_texture_list);
    set_draw_list_mask(3);
    for (i = 0; i < 3; i++) {
        for (y = start; y < hi; y += (8e+02f)) {
            push_matrix();
            translate_matrix(0, 0.0f, y, 0.0f);
            draw_ginja_object(get_bml_model(boss6_tube_bml_resource, boss6_tube_model_order[i]));
            pop_matrix();
        }
    }
    restore_draw_list_mask();
}

f32 TBoss6Tube::scale_by_const(f32 value) {
    return (8e+02f) * value;
}

f32 TBoss6Tube::calc_tube_progress(s32 phase) {
    return (1.0f) - ((f32) (phase & 0x7FFFF) / (524288.0f));
}

void TBoss6Tube::update_scroll_delta() {
    if (((0.0f) == TBoss6Tube__scroll_delta) && ((s32) TBoss6Tube__previous_scroll_phase == 0)) {
        TBoss6Tube__previous_scroll_phase = this->scroll_phase;
        return;
    }
    TBoss6Tube__scroll_delta = TBoss6Tube::scale_by_const(TBoss6Tube::calc_tube_progress(TBoss6Tube__previous_scroll_phase - this->scroll_phase));
    TBoss6Tube__previous_scroll_phase = this->scroll_phase;
}

void TBoss6Tube::reset_state() {
    TBoss6Tube__previous_scroll_phase = 0;
    TBoss6Tube__scroll_delta = (0.0f);
}

#pragma fp_contract on
// Speeds the scroll up by 0x3A per frame (capped at 0x3333) with a +-7.5% jitter.
void TBoss6Tube::accelerate_scroll() {
    scroll_speed = scroll_speed + 0x3A;
    if (scroll_speed > 0x3333) {
        scroll_speed = 0x3333;
    }
    scroll_speed = scroll_speed + (s32)((0.075f * (2.0f * ((3.0517578e-05f * (f32)rand()) - 0.5f))) * fabs_float((f32)scroll_speed));
    scroll_phase = scroll_phase + scroll_speed;
}

#pragma push
#pragma fp_contract on
void TBoss6Tube::update_wobble() {
    scroll_speed = (s32)(scroll_speed + (s32)(((-464.0f) * ((3.0517578e-05f) * (f32)rand())) + (-116.0f)));
    if ((f32)scroll_speed <= (0.0f)) {
        scroll_speed = 0;
        scroll_phase = (s32)((f32)scroll_phase + (((13107.0f) * ((3.0517578e-05f) * (f32)rand())) - (6553.0f)));
    }
    scroll_phase = scroll_phase + scroll_speed;
    TBoss6Tube__scroll_delta = (0.0f);
    TBoss6Tube__previous_scroll_phase = scroll_phase;
}
#pragma pop

void TBoss6Tube::spawn_trap() {
    accelerate_scroll();
    play_persistent_sound(0x40033520, this, NULL, 0, 0);
}

void TBoss6Tube::update_timer() {
    timer = timer + 1;
    if ((s32) timer >= 0x10E) {
        timer = 0;
        state = 1;
        play_sound_effect(0x4003351F, 0, 0, 0);
        TCameraCtrl::set_shake_preset(2);
    }
}


void TBoss6Tube::run_task() {

    if ((sub_802B1018() == 0) && (TObjEneDD::query_teammate_state() == 0)) {
        switch (state) {
        case 0:
            update_timer();
            return;
        case 1:
            spawn_trap();
            update_scroll_delta();
            return;
        case 2:
            update_wobble();
            break;
        }
    }
}

TBoss6Tube::~TBoss6Tube() {
    TBoss6Tube::reset_state();
}

TBoss6Tube::TBoss6Tube(TObject *parent) : TObject(parent) {
    m_name = TBoss6Tube__name;
    plot_falz = static_cast<TBoss6PlotFalz *>(parent);
    scroll_speed = 0;
    scroll_phase = 0;
    TBoss6Tube::reset_state();
    timer = 0;
    state = 0;
}

TBoss6Tube *TBoss6Tube::create(void *parent) {
    return new TBoss6Tube((TObject *)parent);
}

void TBoss6Tube::free_resources() {
    if (boss6_tube_bml_resource != NULL) {
        delete boss6_tube_bml_resource;
        boss6_tube_bml_resource = NULL;
    }
    if (boss6_tube_texture_list != NULL) {
        release_texture_list(boss6_tube_texture_list);
        safe_free(boss6_tube_texture_list);
        boss6_tube_texture_list = NULL;
    }
    TBoss6Tube::reset_state();
}
void TBoss6Tube::load_resources() {
    TBoss6Tube::reset_state();
    boss6_tube_bml_resource = new BmlResource(5, &boss06_tube_dat_resource_descriptor, 0, 0, NULL);
    boss6_tube_texture_list = load_gvm_texture_file("boss06_tube_dat.gvm");
    if (boss6_tube_bml_resource != NULL && boss6_tube_texture_list != NULL) {
        return;
    }
}

