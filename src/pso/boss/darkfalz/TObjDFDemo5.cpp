#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/ModelNodePositionCapture.h"
#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemo5.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/PadRumble.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"

#pragma readonly_strings on
// Built with deferred code generation: functions come out in reverse order
// (update_particle_emitters first in .text), and the ctor's initializer
// copies land in .rodata before the literal pool of the draw/run_task code.
#pragma defer_codegen on


const char *TObjDFDemo5__name = "TObjDFDemo5";
ModelNodePositionEntry df_demo5_emitter_node_entries[3] = {{0x38}, {0x39}, {-1}};
ModelNodePositionEntry df_demo5_tail_node_entries[2] = {{0}, {-1}};
// The motions of the three body models.
s32 df_demo5_part_motion_ids[3] = {0x24, 0x54, 0x55};

TObjDFDemo5 *TObjDFDemo5::create(TObject *parent, const Vec *position, s32 angle) {
    return new TObjDFDemo5(parent, position, angle);
}

TObjDFDemo5::TObjDFDemo5(TObject *parent, const Vec *pos, s32 angle) : TObjBase(parent) {
    BmlResource *res;
    int id;
    s32 i;
    m_name = TObjDFDemo5__name;
    VecCopy(&this->pos, pos);
    this->angle = angle;
    res = TBoss4Uro::get_instance_count();
    for (i = 0; i < 3; i++) {
        id = boss4_type3_model_ids[i];
        parts[i].model = (NJS_OBJECT *)get_bml_model(res, id);
        parts[i].texlist = get_bml_texlist(res, id);
        parts[i].motion = get_bml_motion(res, df_demo5_part_motion_ids[i]);
    }
    parts[3].model = (NJS_OBJECT *)get_bml_model(res, 1);
    parts[3].texlist = get_bml_texlist(res, 1);
    parts[3].motion = get_bml_motion(res, 0x23);
    frame = -0.5f;
    for (s32 j = 0; j < 5; j++) {
        particle_emitters[j] = NULL;
    }
    activate_camera_mode(5);
    {
        CameraPlayback playback = {0, 4, 0, 0.0f, 0.5f};
        CameraAngles angles = {0, this->angle, 0};
        set_scripted_camera_origin(&this->pos, &this->pos, &angles);
        playback.play(0x416C);
    }
    node_list0 = ModelNodePositionCapture::create(df_demo5_emitter_node_entries, emitter_positions);
    node_list1 = ModelNodePositionCapture::create(df_demo5_tail_node_entries, &tail_position);
    play_sound_effect(0x4003A835, NULL, 0, 0);
    timer = 0;
}

TObjDFDemo5::~TObjDFDemo5() {
    s32 i;
    if (node_list0 != NULL) {
        ModelNodePositionCapture::destroy(node_list0);
        node_list0 = NULL;
    }
    if (node_list1 != NULL) {
        ModelNodePositionCapture::destroy(node_list1);
        node_list1 = NULL;
    }
    for (i = 0; i < 5; i++) {
        if (particle_emitters[i] != NULL) {
            TParticleCtrl::release(particle_emitters[i]);
            particle_emitters[i] = NULL;
        }
    }
    if (TBoss4DarkFalz::is_ending_or_split_screen() == 0) {
        restore_player_cameras();
    }
}

void TObjDFDemo5::run_task() {
    update_particle_emitters();
    if (timer == 0x8C) {
        play_cue_stream_file("dfdeath.adx");
        start_pad_rumble_all(0xC0, 0xF);
    }
    if ((frame += 0.5f) > 149.0f) {
        frame = 149.0f;
    }
    if (++timer >= 0x12C) {
        queue_destruction();
    }
}

void TObjDFDemo5::render() {
    draw_fading_motion();
    release_subobjects();
}

void TObjDFDemo5::draw_fading_motion() {
    f32 alpha;
    f32 part_frame;
    s32 t;
    alpha = 1.0f;
    t = timer;
    if (t >= 0xF0) {
        return;
    }
    if (t > 0xA0) {
        alpha = (f32)(0xF0 - t) / 80.0f;
    }
    if (alpha < 1.0f) {
        TObjPlayer::begin_alpha_blend(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, angle);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(parts[0].texlist));
    node_list0->install();
    draw_model_motion((void *)parts[0].model, parts[0].motion, frame);
    node_list0->clear();
    part_frame = (s32)frame % 30;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(parts[1].texlist));
    draw_model_motion((void *)parts[1].model, parts[1].motion, part_frame);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(parts[2].texlist));
    draw_model_motion((void *)parts[2].model, parts[2].motion, part_frame);
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

void TObjDFDemo5::release_subobjects() {
    if (timer >= 0xB4) {
        TObjPlayer::begin_alpha_blend(0.99f);
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&pos.x);
        rotate_matrix_y(NULL, angle);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(parts[3].texlist));
        node_list1->install();
        draw_model_motion((void *)parts[3].model, parts[3].motion, frame);
        node_list1->clear();
        clear_motion_packed_rotation();
        pop_matrix();
        TObjPlayer::sync_player_globals();
    }
}

void TObjDFDemo5::update_particle_emitters() {
    TParticleCtrl **emitter;
    s32 i;
    if (timer > 0x104) {
        if (particle_emitters[0] != NULL) {
            TParticleCtrl::release(particle_emitters[0]);
            particle_emitters[0] = NULL;
        }
    } else if (timer >= 0xA0 && particle_emitters[0] == NULL) {
        particle_emitters[0] = create_particle_emitter(&pos, 0x178);
        if (particle_emitters[0] != NULL) {
            particle_emitters[0]->set_flags(0x40);
        }
    }
    if (timer >= 0x104 && particle_emitters[1] == NULL) {
        particle_emitters[1] = create_particle_emitter(&pos, 0x179);
        if (particle_emitters[1] != NULL) {
            particle_emitters[1]->set_flags(0x40);
        }
    }
    if (timer >= 0xB4) {
        if (particle_emitters[2] == NULL) {
            particle_emitters[2] = create_particle_emitter(&tail_position, 0x146);
            if (particle_emitters[2] != NULL) {
                particle_emitters[2]->set_flags(0x40);
            }
        } else {
            particle_emitters[2]->set_position(&tail_position);
        }
    }
    emitter = &particle_emitters[3];
    for (i = 0; i < 2; i++) {
        if (timer >= 0x2D) {
            if (*emitter != NULL) {
                TParticleCtrl::release(*emitter);
                *emitter = NULL;
            }
        } else {
            Vec *at = &emitter_positions[i];
            if (*emitter == NULL) {
                *emitter = create_particle_emitter(at, 0x147);
                if (*emitter != NULL) {
                    (*emitter)->set_flags(0x40);
                }
            } else {
                (*emitter)->set_position(at);
            }
        }
        emitter = &particle_emitters[4];
    }
}
