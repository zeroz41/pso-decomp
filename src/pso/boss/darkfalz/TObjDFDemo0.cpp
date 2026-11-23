#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/ModelNodeTables.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TObjDFDemo0.h"
#include "pso/boss/darkfalz/TBoss4Type1.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"


#pragma defer_codegen on

const char *TObjDFDemo0__name = "TObjDFDemo0";
const ModelNodeSpec TObjDFDemo0__model_node_entries[7] = {
    {9, 1, 0}, {7, 1, 0}, {5, 2, 0}, {4, 2, 0}, {6, 2, 0}, {3, 5, 0}, {3, 0x5E, 0},
};

extern "C" {
DFDemo0Emitter TObjDFDemo0__entry_table[5] = {
    {0x14B, 0, 0x82, {0.0f, 0.0f, -120.0f}},
    {0x14C, 0x50, 0x8C, {0.0f, 0.0f, 10.0f}},
    {0x14C, 0x64, 0x8C, {130.0f, 0.0f, -120.0f}},
    {0x14C, 0x78, 0x8C, {-130.0f, 0.0f, -120.0f}},
    {0x14D, 0x92, 0xC8, {0.0f, 0.0f, -120.0f}},
};
// The motions of the six body models.
s32 df_demo0_body_motion_ids[6] = {0x50, 0x4E, 0x19, 0x19, 0x19, 0x18};
// Where the demo plays out: the camera looks from it, effects gather on it and sounds play from it.
Vec df_demo0_center = {0.0f, 0.0f, -120.0f};
CameraAngles df_demo0_camera_angles = {0, 0, 0};
CameraPlayback df_demo0_camera_playback = {0, 1, 0, 0.0f, 0.5f};
// Offsets from df_demo0_center of the bursts spawned on frames 0x8C-0x90, one per frame.
Vec df_demo0_burst_offsets[5] = {
    {0.0f, 0.0f, 0.0f}, {30.0f, 0.0f, 60.0f}, {0.0f, 60.0f, 0.0f}, {-30.0f, 0.0f, 60.0f}, {0.0f, 120.0f, 0.0f},
};
}

extern "C" {
// The translation applied before drawing the body models.
Vec df_demo0_model_offset = {0.0f, 0.0f, -120.0f};
}

TObjDFDemo0 *TObjDFDemo0::create(TObject *parent) {
    return new TObjDFDemo0(parent);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
TObjDFDemo0::TObjDFDemo0(TObject *parent) : TObjBase(parent) {
    s32 k;
    BmlResource *h;
    s32 i;
    s32 j;

    m_name = TObjDFDemo0__name;
    h = TBoss4Uro::get_instance_count();
    for (i = 0; i < 6; i++) {
        {
            s32 t = boss4_type1_model_ids[i];
            k = t;
            models[i] = get_bml_model(h, t);
        }
        texture_lists[i] = get_bml_texlist(h, k);
        motions[i] = (AnimationMotion *)get_bml_motion(h, df_demo0_body_motion_ids[i]);
    }
    loop_frame = (-0.5f);
    motion_frame = (-0.5f);
    for (j = 0; j < 5; j++) {
        particle_emitters[j] = NULL;
    }
    strips.init(TObjDFDemo0__model_node_entries, 7);
    activate_camera_mode(5);
    set_scripted_camera_origin(&df_demo0_center, &df_demo0_center, &df_demo0_camera_angles);
    df_demo0_camera_playback.play(0x416C);
    fade = (0.0f);
    play_sound_effect(0x40039E21, &df_demo0_center, 0, 1);
    timer = 0;
}
#pragma pop

TObjDFDemo0::~TObjDFDemo0() {
    s32 i;
    strips.destroy();
    for (i = 0; i < 5; i++) {
        if (particle_emitters[i] != NULL) {
            TParticleCtrl::release(particle_emitters[i]);
            particle_emitters[i] = NULL;
        }
    }
    restore_player_cameras();
}

void TObjDFDemo0::run_task() {
    s32 i;
    f32 v;
    for (i = 0; i < 5; i++) {
        DFDemo0Emitter *e = &TObjDFDemo0__entry_table[i];
        s32 t = timer;
        if (t >= e->end) {
            if (particle_emitters[i] != NULL) {
                TParticleCtrl::release(particle_emitters[i]);
                particle_emitters[i] = NULL;
            }
        } else if (t >= e->start) {
            if (particle_emitters[i] == NULL) {
                particle_emitters[i] = create_particle_emitter(&e->position, e->effect_id);
                if (particle_emitters[i] != NULL) {
                    particle_emitters[i]->set_flags(0x40);
                }
            }
            switch (i) {
            case 1: case 2: case 3: {
                TParticleCtrl *p = particle_emitters[i];
                if (p != NULL) {
                    Vec a = p->position;
                    Vec b = df_demo0_center;
                    subtract_vector(&b, &a);
                    b.y = (0.0f);
                    normalize_vector(&b);
                    b.x *= (1.95f);
                    b.z *= (1.95f);
                    vec3_add_to(&a, &b);
                    particle_emitters[i]->set_position(&a);
                }
            }
            break;
            }
        }
    }
    {
        s32 t = timer;
        if (t >= 0x8C && t < 0x91) {
            TParticleCtrl *p;
            Vec c = df_demo0_center;
            vec3_add_to(&c, &df_demo0_burst_offsets[t - 0x8C]);
            p = spawn_particle_effect(&c, 0x14A);
            if (p != NULL) {
                p->set_flags(0x40);
            }
        }
    }
    if (timer >= 0xAA) {
        v = (0.1f); v = fade + v;
        fade = v;
        if (v > 1.0f) {
            fade = 1.0f;
        }
    }
    v = (0.5f); v = loop_frame + v;
    loop_frame = v;
    if (v >= (3e+01f)) {
        loop_frame = (0.0f);
    }
    v = (0.5f); v = motion_frame + v;
    motion_frame = v;
    if (v > 139.0f) {
        motion_frame = 139.0f;
    }
    switch (timer) {
    case 0:
        play_sound_effect(0x4003BC07, &df_demo0_center, 0, 1);
        play_sound_effect(0x3C604, &df_demo0_center, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    case 0x50:
        play_sound_effect(0x3A805, 0, 0, 0);
    case 0x64:
    case 0x78:
        play_sound_effect(0x4003D006, &df_demo0_center, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    case 0x8C:
        play_sound_effect(0x36408, &df_demo0_center, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    case 0x92:
        play_sound_effect(0x3DA03, &df_demo0_center, 0, 1);
        break;
    case 0xAA:
        play_sound_effect(0x40039E09, &df_demo0_center, 0, 1);
        break;
    case 0xC8:
        play_sound_effect(0x40039E21, &df_demo0_center, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
        break;
    }
    strips.scroll_strips();
    if (++timer >= 0x118) {
        queue_destruction();
    }
}

void TObjDFDemo0::render() {
    s32 i;
    f32 frame;

    if ((0.0f) != fade) {
        if (fade < (1.0f)) {
            TObjPlayer::begin_alpha_blend(fade);
        }
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix((f32 *)&df_demo0_model_offset);
        for (i = 0; i < 6; i++) {
            frame = motion_frame;
            if (i == 0 || i == 1) {
                frame = loop_frame;
            }
            TObjFish::set_global_param(texture_lists[i]);
            draw_model_motion(models[i], motions[i], frame);
        }
        clear_motion_packed_rotation();
        pop_matrix();
        if (fade < (1.0f)) {
            TObjPlayer::sync_player_globals();
        }
    }
}
