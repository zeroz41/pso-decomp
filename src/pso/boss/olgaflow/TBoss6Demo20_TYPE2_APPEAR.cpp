#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/PadRumble.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/olgaflow/Boss6Type2Appearance.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/olgaflow/TBoss6Demo20_TYPE2_APPEAR.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"


extern const Vec boss6_type2_appear_origin;
extern Vec boss6_type2_appear_offset_particle_origin;

typedef struct Ent_8033D6DC { s32 start; s32 end; s32 id; s32 src; } Ent_8033D6DC;

extern "C" {
const char TBoss6Demo20_TYPE2_APPEAR__class_name[] = "TBoss6Demo20_TYPE2_APPEAR";
}
const Vec boss6_type2_appear_origin = {-10000.0f, 0.0f, 0.0f};
extern "C" {
const ModelNodePositionEntry boss6_type2_appear_model_node_descriptors[9] = {
    {0x24}, {0x30}, {0x36}, {0x3A}, {0x48}, {0x4B}, {0x4E}, {0x52}, {-1},
};
const Ent_8033D6DC boss6_type2_appear_particle_schedule[9] = {
    {42, 142, 554, -1},
    {135, 385, 552, -1},
    {148, 200, 557, 1},
    {185, 228, 557, 2},
    {185, 228, 557, 6},
    {214, 257, 557, 3},
    {214, 257, 557, 7},
    {294, 357, 556, 0},
    {100, 157, 377, -2}
};
const Vec boss6_type2_appear_camera_position = {-10000.0f, 0.0f, 0.0f};
const CameraAngles boss6_type2_appear_camera_angles = {0, 0, 0};
const CameraPlayback boss6_type2_appear_camera_script = {1, 3, 0, 0.0f, 0.7f};

void TBoss6Demo20_TYPE2_APPEAR::draw_model_12() {
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&boss6_type2_appear_origin.x);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(model12.texture));
    draw_model_motion(model12.model, model12.motion, frame);
    clear_motion_packed_rotation();
    pop_matrix();
}

void TBoss6Demo20_TYPE2_APPEAR::draw_fading_model_1_pair() {
    f32 fade;
    union { f64 d; u32 w[2]; } cvt;
    s32 t;
    t = timer;
    if (t < 0x181) {
        fade = 0.0f;
    } else if (t >= 0x190) {
        fade = 1.0f;
    } else {
        fade = (t - 0x181) / (-15.0f);
    }
    if (0.0f != fade) {
        if (fade < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(fade);
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(model1.texture));
        set_motion_packed_rotation();
        push_matrix();
        post_translate_matrix(&effect_positions[4].x);
        draw_model_motion(model1.model, model1.motion, secondary_frame);
        pop_matrix();
        push_matrix();
        post_translate_matrix(&effect_positions[5].x);
        draw_model_motion(model1.model, model1.motion, secondary_frame);
        pop_matrix();
        clear_motion_packed_rotation();
        if (fade < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo20_TYPE2_APPEAR::draw_fading_model_4() {
    f32 fade;
    s32 t;
    union { f64 d; u32 w[2]; } cvt;

    t = timer;
    if (t < 0x72) {
        fade = 0.0f;
    } else if (t >= 0x8E) {
        fade = 1.0f;
    } else {
        fade = (t - 0x72) / 28.0f;
    }
    if ((0.0f != fade) && (capture != NULL)) {
        if (fade < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(fade);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&boss6_type2_appear_origin.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(model4.texture));
        capture->install();
        draw_model_motion(model4.model, model4.motion, frame);
        capture->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (fade < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo20_TYPE2_APPEAR::draw_fading_model_pair() {
    f32 fade;
    s32 t;
    t = timer;
    if (t < 0x72) {
        fade = 1.0f;
    } else if (t >= 0x8E) {
        fade = 0.0f;
    } else {
        fade = (f32) (0x8E - t) / 28.0f;
    }
    if (0.0f != fade) {
        if (fade < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(fade);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&boss6_type2_appear_origin.x);
        s32 i = 0;
        do {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(opening_parts[i].texture));
            draw_model_motion(opening_parts[i].model, opening_parts[i].motion, frame);
            i++;
        } while (i < 2);
        clear_motion_packed_rotation();
        pop_matrix();
        if (fade < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

}

void TBoss6Demo20_TYPE2_APPEAR::render() {
    draw_model_12();
    draw_fading_model_4();
    draw_fading_model_pair();
    draw_fading_model_1_pair();
}

void TBoss6Demo20_TYPE2_APPEAR::run_task() {
    s32 i;
    if ((frame += 0.7f) > 284.0f) {
        frame = 284.0f;
    }
    secondary_frame += 0.8f;
    if (secondary_frame >= 30.0f) {
        secondary_frame -= 30.0f;
    }
    switch (timer) {
    case 0xE:
        play_sound_effect(0x40039E28, 0, 0, 0);
        break;
    case 0x72:
        play_sound_effect(0x4003A129, 0, 0, 0);
        break;
    case 0xEE:
        play_sound_effect(0x4003972A, 0, 0, 0);
        break;
    case 0x11D:
        play_sound_effect(0x40031C2B, 0, 0, 0);
        break;
    }
    play_persistent_sound(0x4003C627, this, NULL, 0, 0);
    switch (timer) {
    case 0xB9:
        spawn_particle_effect_with_flags(&effect_positions[3], 0x220, 0x40);
        spawn_particle_effect_with_flags(&effect_positions[7], 0x220, 0x40);
        break;
    case 0xED:
        spawn_particle_effect_with_flags(&boss6_type2_appear_origin, 0x221, 0x40);
        spawn_particle_effect_with_flags(&boss6_type2_appear_origin, 0x225, 0x40);
        break;
    }
    for (i = 0; i < 9; i++) {
        const Ent_8033D6DC *e = &boss6_type2_appear_particle_schedule[i];
        if (timer >= e->start && timer < e->end) {
            const Vec *p = &boss6_type2_appear_origin;
            if (e->src == -2) {
                p = &boss6_type2_appear_offset_particle_origin;
            } else if (e->src >= 0) {
                p = &effect_positions[e->src];
            }
            if (emitters[i] == NULL) {
                emitters[i] = create_particle_emitter(p, e->id);
                if (emitters[i] != NULL) {
                    emitters[i]->set_flags(0x40);
                }
            } else {
                emitters[i]->set_position(const_cast<Vec *>(p));
            }
        } else if (emitters[i] != NULL) {
            TParticleCtrl::release(emitters[i]);
            emitters[i] = NULL;
        }
    }
    switch (timer) {
    case 5:
    case 0x32:
    case 0x78:
    case 0x8C:
    case 0xEB:
    case 0x122:
    case 0x136:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    timer++;
    if (timer >= 0x197 || plot->get_scene_state() != 5) {
        queue_destruction();
    }
}

TBoss6Demo20_TYPE2_APPEAR::~TBoss6Demo20_TYPE2_APPEAR() {
    s32 i;
    for (i = 0; i < 9; i++) {
        if (emitters[i] != 0) {
            TParticleCtrl::release(emitters[i]);
            emitters[i] = 0;
        }
    }
    restore_player_cameras();
    TBoss6PlotFalz::refresh_players_equipment();
    if (capture != 0) {
        ModelNodePositionCapture::destroy(capture);
        capture = 0;
    }
}


extern "C" {
__declspec(section ".data") extern s32 boss6_type2_appear_motion_indices[];
struct AppearanceClassTag { const char *value; u32 padding; };
__declspec(section ".sdata") extern AppearanceClassTag TBoss6Demo20_TYPE2_APPEAR__name;
}

#pragma push
#pragma opt_lifetimes off
#pragma pool_data off
#pragma opt_loop_invariants off
#pragma opt_common_subs off
#pragma opt_propagation off
TBoss6Demo20_TYPE2_APPEAR::TBoss6Demo20_TYPE2_APPEAR(TBoss6PlotFalz *plot) : TObject(plot) {
    s32 v;
    BmlResource *archive;
    saddr i;
    m_name = TBoss6Demo20_TYPE2_APPEAR__name.value;
    this->plot = plot;
    archive = TBoss6PlotFalz::get_scene_archive();
    for (i = 0; i < 2; i++) {
        {
            s32 t = boss6_type1_part_model_ids[i];
            v = t;
            opening_parts[i].model = (NJS_OBJECT *)get_bml_model(archive, t);
        }
        opening_parts[i].texture = get_bml_texlist(archive, v);
        opening_parts[i].motion = get_bml_motion(archive, boss6_type2_appear_motion_indices[i]);
    }
    model4.model = (NJS_OBJECT *)get_bml_model(archive, 4);
    model4.texture = get_bml_texlist(archive, 4);
    model4.motion = get_bml_motion(archive, 0x20);
    model1.model = (NJS_OBJECT *)get_bml_model(archive, 1);
    model1.texture = get_bml_texlist(archive, 1);
    model1.motion = get_bml_motion(archive, 0x36);
    model12.model = (NJS_OBJECT *)get_bml_model(archive, 0xC);
    model12.texture = get_bml_texlist(archive, 0xC);
    model12.motion = get_bml_motion(archive, 0x22);
    capture = ModelNodePositionCapture::create(boss6_type2_appear_model_node_descriptors, effect_positions);
    for (i = 0; i < 9; i++) {
        emitters[i] = 0;
    }
    activate_camera_mode(5);
    set_scripted_camera_origin(&boss6_type2_appear_camera_position, &boss6_type2_appear_camera_position, &boss6_type2_appear_camera_angles);
    boss6_type2_appear_camera_script.play(0x416C);
    frame = 0.0f;
    secondary_frame = 0.0f;
    timer = 0;
}
#pragma pop

TBoss6Demo20_TYPE2_APPEAR *TBoss6Demo20_TYPE2_APPEAR::create(TBoss6PlotFalz *plot) {
    return new TBoss6Demo20_TYPE2_APPEAR(plot);
}

void initialize_boss6_type2_appear_particle_origin(void) {
    boss6_type2_appear_offset_particle_origin.x = boss6_type2_appear_origin.x;
    boss6_type2_appear_offset_particle_origin.y = 50.0f + boss6_type2_appear_origin.y;
    boss6_type2_appear_offset_particle_origin.z = boss6_type2_appear_origin.z;
}
extern "C" {
__declspec(section ".ctors") static void *const __sinit_text_8033DA94_cpp_ref = (void *)initialize_boss6_type2_appear_particle_origin;

}
__declspec(section ".data") Vec boss6_type2_appear_offset_particle_origin = {0.0f, 0.0f, 0.0f};
extern "C" {
__declspec(section ".data") s32 boss6_type2_appear_motion_indices[2] = {31, 33};
__declspec(section ".sdata") AppearanceClassTag TBoss6Demo20_TYPE2_APPEAR__name = {TBoss6Demo20_TYPE2_APPEAR__class_name, 0};
}
