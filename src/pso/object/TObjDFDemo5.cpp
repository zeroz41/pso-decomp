#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/object/TObjDFDemo5.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Uro.h"
#include "pso/misc/CameraHelpers.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TCameraCtrl_800687BC.h"
#include "pso/misc/TLobby_802268F4.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_800E2FFC.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80052374.h"
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

extern "C" {
// Dark Falz's three body models (TBoss4Type3's table).
extern s32 lbl_80486FB0[3];

const char *lbl_805D27A0 = "TObjDFDemo5";
TObjFishNodeEntry lbl_80485798[3] = {{0x38}, {0x39}, {-1}};
TObjFishNodeEntry lbl_804857C8[2] = {{0}, {-1}};
// The motions of the three body models.
s32 lbl_804857E8[3] = {0x24, 0x54, 0x55};
}

void *TObjDFDemo5::create(void *arg0, void *arg1, void *arg2) {
    return new TObjDFDemo5((TObject *)arg0, (const Vec *)arg1, (s32)arg2);
}

TObjDFDemo5::TObjDFDemo5(TObject *parent, const Vec *pos, s32 angle) : TObjBase(parent) {
    BmlResource *res;
    int id;
    s32 i;
    m_name = lbl_805D27A0;
    VecCopy(&this->pos, pos);
    this->angle = angle;
    res = (BmlResource *)TBoss4Uro::get_instance_count();
    for (i = 0; i < 3; i++) {
        id = lbl_80486FB0[i];
        parts[i].model = get_bml_model(res, id);
        parts[i].texlist = TObjFish__sub_8001EDB0(res, id);
        parts[i].motion = get_bml_motion(res, lbl_804857E8[i]);
    }
    parts[3].model = get_bml_model(res, 1);
    parts[3].texlist = TObjFish__sub_8001EDB0(res, 1);
    parts[3].motion = get_bml_motion(res, 0x23);
    frame = -0.5f;
    for (s32 j = 0; j < 5; j++) {
        particle_emitters[j] = NULL;
    }
    activate_camera_mode(5);
    {
        CameraPlayback playback = {0, 4, 0, 0.0f, 0.5f};
        CameraAngles angles = {0, this->angle, 0};
        set_scripted_camera_pose(&this->pos, &this->pos, &angles);
        ((TCameraCtrl *)&playback)->cache_target_and_forward(0x416C);
    }
    node_list0 = (TObjFish *)TObjFish__sub_800E3124((u8 *)lbl_80485798, (s32)emitter_positions);
    node_list1 = (TObjFish *)TObjFish__sub_800E3124((u8 *)lbl_804857C8, (s32)&tail_position);
    play_sound_effect(0x4003A835, NULL, 0, 0);
    timer = 0;
}

TObjDFDemo5::~TObjDFDemo5() {
    s32 i;
    if (node_list0 != NULL) {
        TObjFish::init_state_1(node_list0);
        node_list0 = NULL;
    }
    if (node_list1 != NULL) {
        TObjFish::init_state_1(node_list1);
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
        play_cue_stream_file((s32)"dfdeath.adx");
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
        TObjPlayer__sub_80052390(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, angle);
    TObjFish::set_global_param(parts[0].texlist);
    node_list0->set_draw_callback_list();
    draw_model_motion((void *)parts[0].model, parts[0].motion, frame);
    node_list0->clear_render_callback();
    part_frame = (s32)frame % 30;
    TObjFish::set_global_param(parts[1].texlist);
    draw_model_motion((void *)parts[1].model, parts[1].motion, part_frame);
    TObjFish::set_global_param(parts[2].texlist);
    draw_model_motion((void *)parts[2].model, parts[2].motion, part_frame);
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

void TObjDFDemo5::release_subobjects() {
    if (timer >= 0xB4) {
        TObjPlayer__sub_80052390(0.99f);
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&pos.x);
        rotate_matrix_y(NULL, angle);
        TObjFish::set_global_param(parts[3].texlist);
        node_list1->set_draw_callback_list();
        draw_model_motion((void *)parts[3].model, parts[3].motion, frame);
        node_list1->clear_render_callback();
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
