#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Demo21_TYPE2_DEAD.h"
#include "pso/boss/olgaflow/TBoss6Zanzo.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"

struct EmitterSchedule { s32 start; s32 end; s32 id; };

extern "C" const char TBoss6Demo21_TYPE2_DEAD__class_name_string[] = "TBoss6Demo21_TYPE2_DEAD";
extern "C" const Vec boss6_type2_dead_origin = {-10000.0f, 0.0f, 0.0f};
extern "C" const Vec boss6_type2_dead_burst_offset = {0.0f, 0.0f, -142.0f};
extern "C" const Vec boss6_type2_dead_final_offset = {0.0f, -2.0f, 6.4f};
extern "C" const ModelNodePositionEntry boss6_type2_death_effect_desc_a[] = {{0x24}, {-1}};
extern "C" const ModelNodePositionEntry boss6_type2_death_effect_desc_b[] = {{0x19}, {-1}};
extern "C" const ModelNodePositionEntry boss6_type2_death_effect_desc_c[] = {{2}, {3}, {-1}};
extern "C" const CameraAngles boss6_type2_dead_camera_angles = {0, 0, 0};
extern "C" const CameraPlayback boss6_type2_dead_camera_script = {1, 1, 0, 0.0f, 0.7f};
extern "C" const EmitterSchedule boss6_type2_death_emitter_ranges[4] = {{0, 0x8E, 0x228}, {0xFA, 0x13A, 0x22A}, {0x11D, 0x1AC, 0x22E}, {0xF2, 0x13A, 0x179}};
extern "C" const u32 boss6_type2_dead_trail_colors[3] = {0xffff4000, 0xffffff60, 0xffff4000};
extern "C" const char *TBoss6Demo21_TYPE2_DEAD__name = TBoss6Demo21_TYPE2_DEAD__class_name_string;
#pragma pool_data off
void TBoss6Demo21_TYPE2_DEAD::draw_model_13() {
    if (timer >= 0x1AC) {
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(models[3].texture));
        capture_13->install();
        draw_model_motion(models[3].model, models[3].motion, frame);
        capture_13->clear();
        clear_motion_packed_rotation();
        pop_matrix();
    }
}
void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_8() {
    f32 f;
    s32 t;
    f = 0.0f;
    t = timer;
    if (t > 0x11D && t < 0x1AC) {
        if (t >= 0x12C && t <= 0x1AC) {
            f = 1.0f;
        } else if (t > 0x11D && t < 0x12C) {
            f = (f32)(t - 0x11D) / 15.0f;
        }
    }
    if (0.0f != f) {
        if (f < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(f);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(models[2].texture));
        capture_8->install();
        draw_model_motion(models[2].model, models[2].motion, frame);
        capture_8->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (f < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_5() {

    f32 f;
    s32 t;

    f = 0.0f;
    t = timer;
    if (t > 0x101 && t < 0x12C) {
        if (t >= 0x10F && t <= 0x11D) {
            f = 1.0f;
        } else if (t > 0x101 && t < 0x10F) {
            f = (f32)(t - 0x101) / 14.0f;
        } else if (t > 0x11D && t < 0x12C) {
            f = (f32) (0x12C - t) / 15.0f;
        }
    }
    if (0.0f != f) {
        if (f < 1.0f) {
            TBoss6PlotFalz::set_fade_material_color(f);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(models[1].texture));
        capture_5->install();
        draw_model_motion(models[1].model, models[1].motion, frame);
        capture_5->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (f < 1.0f) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo21_TYPE2_DEAD::draw_fading_model_4() {
    f32 fade;
    s32 t;
    t = timer;
    if (t < 0x101) {
        fade = (1.0f);
    } else if (t >= 0x10F) {
        fade = (0.0f);
    } else {
        fade = (f32) (0x10F - t) / (14.0f);
    }
    if ((0.0f) != fade) {
        if (fade < (1.0f)) {
            TBoss6PlotFalz::set_fade_material_color(fade);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&camera_position.x);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(models[0].texture));
        capture_5->install();
        draw_model_motion(models[0].model, models[0].motion, frame);
        capture_5->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        if (fade < (1.0f)) {
            TObjFish::reset_fish_globals();
        }
    }
}

void TBoss6Demo21_TYPE2_DEAD::render() {
    draw_fading_model_4();
    draw_fading_model_5();
    draw_fading_model_8();
    draw_model_13();
}

#pragma push
#pragma pool_data off
void TBoss6Demo21_TYPE2_DEAD::run_task() {
    Vec points[3];
    if ((frame += 0.7f) > 499.0f) {
        frame = 499.0f;
    }
    switch (timer) {
    case 0x0:
        play_sound_effect(0x4003232C, 0, 0, 0);
        break;
    case 0xAE:
    case 0xCF:
        play_sound_effect(0x4003942D, 0, 0, 0);
        break;
    case 0x23B:
        play_sound_effect(0x40032830, 0, 0, 0);
        break;
    }
    if (timer >= 0x12C && timer <= 0x1AC) {
        play_persistent_sound(0x4003352E, this, NULL, 0, 0);
    }
    if (timer >= 0x1D7 && timer <= 0x23A) {
        play_persistent_sound(0x32D2F, this, NULL, 0, 0);
    }
    switch (timer) {
    case 0xAE:
    case 0xCF: {
        Vec p = camera_position;
        vec3_add_to(&p, &boss6_type2_dead_burst_offset);
        spawn_particle_effect_with_flags(&p, 0x221, 0x40);
        spawn_particle_effect_with_flags(&p, 0x22F, 0x40);
        break;
    }
    case 0x1AC:
        spawn_particle_effect_with_flags(&effect_position_8, 0x223, 0x40);
        break;
    case 0x23A: {
        Vec p = camera_position;
        vec3_add_to(&p, &boss6_type2_dead_final_offset);
        spawn_particle_effect_with_flags(&p, 0xA4, 0x40);
        spawn_particle_effect_with_flags(&p, 0xE3, 0x40);
        break;
    }
    }
    if (timer >= 0x12C && timer < 0x1BA) {
        spawn_particle_effect_with_flags(&effect_position_8, 0x22E, 0x40);
    }
    {
        Vec *ptrs[4];
        s32 i;
        ptrs[0] = &camera_position;
        ptrs[1] = &effect_position_5;
        ptrs[2] = &effect_position_8;
        ptrs[3] = &effect_position_5;
        for (i = 0; i < 4; i++) {
            if (timer >= boss6_type2_death_emitter_ranges[i].start && timer < boss6_type2_death_emitter_ranges[i].end) {
                if (emitters[i] == 0) {
                    emitters[i] = create_particle_emitter(ptrs[i], boss6_type2_death_emitter_ranges[i].id);
                    if (emitters[i] != 0) {
                        emitters[i]->set_flags(0x40);
                    }
                } else {
                    emitters[i]->set_position(ptrs[i]);
                }
            } else if (emitters[i] != 0) {
                TParticleCtrl::release(emitters[i]);
                emitters[i] = 0;
            }
        }
    }
    if (timer >= 0x1AE) {
        VecCopy(&points[0], &trail_positions[0]);
        VecCopy(&points[2], &trail_positions[1]);
        VecCopy(&points[1], &points[0]);
        vec3_add_to(&points[1], &points[2]);
        points[1].x *= 0.5f;
        points[1].y *= 0.5f;
        points[1].z *= 0.5f;
        trail_effect->set_effect_points(points, boss6_type2_dead_trail_colors);
    }
    if (timer == 0x23A) {
        s32 n = TLobby::get_game_mode();
        Vec c;
        s32 i;
        VecCopy(&c, &camera_position);
        vec3_add_to(&c, &boss6_type2_dead_final_offset);
        for (i = 0; i < n; i++) {
            TObjPlayer *p = TObjPlayer::get_player_data(i);
            if (TObjPlayer::is_locally_controlled(p) != 0 && TBoss6PlotFalz::is_state_1f(p) != 0) {
                Vec d;
                VecCopy(&d, &p->position);
                subtract_vector(&d, &c);
                d.y = (0.0f);
                if (!(vector_length(&d) > (0.25f))) {
                    p->actorFlags |= 0x600;
                }
            }
        }
    }
    switch (timer) {
    case 0x5F:
    case 0x82:
    case 0xB1:
    case 0xCD:
    case 0xFA:
    case 0x10E:
    case 0x23C:
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    timer++;
    if (timer >= 0x2CA || plot->get_scene_state() != 7) {
        queue_destruction();
    }
}
#pragma pop
TBoss6Demo21_TYPE2_DEAD::~TBoss6Demo21_TYPE2_DEAD() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (emitters[i] != NULL) {
            TParticleCtrl::release(emitters[i]);
            emitters[i] = NULL;
        }
    }
    restore_player_cameras();
    TBoss6PlotFalz::refresh_players_equipment();
    if (capture_5 != NULL) {
        ModelNodePositionCapture::destroy(capture_5);
        capture_5 = NULL;
    }
    if (capture_8 != NULL) {
        ModelNodePositionCapture::destroy(capture_8);
        capture_8 = NULL;
    }
    if (capture_13 != NULL) {
        ModelNodePositionCapture::destroy(capture_13);
        capture_13 = NULL;
    }
}
#pragma push
#pragma opt_common_subs off
TBoss6Demo21_TYPE2_DEAD::TBoss6Demo21_TYPE2_DEAD(TBoss6PlotFalz *plot, const Vec *target) : TObject(plot) {
    Vec delta;
    s32 i;
    m_name = TBoss6Demo21_TYPE2_DEAD__name;
    this->plot = plot;
    VecCopy(&camera_position, &boss6_type2_dead_origin);
    VecCopy(&delta, target);
    subtract_vector(&delta, &boss6_type2_dead_origin);
    delta.y = 0.0f;
    if (vector_length(&delta) > 60.0f) {
        normalize_vector(&delta);
        delta.x *= 60.0f;
        delta.z *= 60.0f;
    }
    vec3_add_to(&camera_position, &delta);
    BmlResource *archive = TBoss6PlotFalz::get_scene_archive();
    models[0].model = (NJS_OBJECT *)get_bml_model(archive, 4);
    models[0].texture = get_bml_texlist(archive, 4);
    models[0].motion = get_bml_motion(archive, 7);
    models[1].model = (NJS_OBJECT *)get_bml_model(archive, 5);
    models[1].texture = get_bml_texlist(archive, 5);
    models[1].motion = get_bml_motion(archive, 7);
    models[2].model = (NJS_OBJECT *)get_bml_model(archive, 8);
    models[2].texture = get_bml_texlist(archive, 8);
    models[2].motion = get_bml_motion(archive, 8);
    models[3].model = (NJS_OBJECT *)get_bml_model(archive, 0xD);
    models[3].texture = get_bml_texlist(archive, 0xD);
    models[3].motion = get_bml_motion(archive, 0x3D);
    capture_5 = ModelNodePositionCapture::create(boss6_type2_death_effect_desc_a, &effect_position_5);
    capture_8 = ModelNodePositionCapture::create(boss6_type2_death_effect_desc_b, &effect_position_8);
    capture_13 = ModelNodePositionCapture::create(boss6_type2_death_effect_desc_c, trail_positions);
    activate_camera_mode(5);
    set_scripted_camera_origin(&camera_position, &camera_position, &boss6_type2_dead_camera_angles);
    boss6_type2_dead_camera_script.play(0x416C);
    for (i = 0; i < 4; i++) {
        emitters[i] = NULL;
    }
    trail_effect = TBoss6Zanzo::create(this, 3, 0xF);
    frame = 0.0f;
    timer = 0;
}
#pragma pop

TBoss6Demo21_TYPE2_DEAD *TBoss6Demo21_TYPE2_DEAD::create(TBoss6PlotFalz *plot, const Vec *target) {
    return new TBoss6Demo21_TYPE2_DEAD(plot, target);
}
