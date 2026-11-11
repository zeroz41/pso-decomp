#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemo4.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_800E2FFC.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/PadRumble.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"

#pragma readonly_strings on
// Built with deferred code generation (-inline deferred): functions come out in reverse
// order (sub_8004F1FC first in .text).

extern "C" {
// Dark Falz's afterimage (zanzo) models.
extern s32 boss4_zanzo_bml_index_table[2];
}

const char *TObjDFDemo4__name = "TObjDFDemo4";
// The motions of the afterimage and body models.
s32 lbl_80485720[2] = {0x12, 0x11};
s32 lbl_80485728[3] = {0x20, 0x21, 0x22};
TObjFishNodeEntry lbl_80485734[3] = {{0x34}, {0x35}, {-1}};

void *TObjDFDemo4::create(void *arg0, void *arg1, void *arg2) {
    return new TObjDFDemo4((TObject *)arg0, (const Vec *)arg1, (s32)arg2);
}

// The nodes init_model_node_tables builds the strips on.
inline const ModelNodeSpec *strip_nodes() {
    static const ModelNodeSpec lbl_804373C4[2] = {{0xC, 0x4A, 1}, {0xE, 0x4A, 1}};
    return lbl_804373C4;
}
// The intro camera: its playback and angles (the yaw is the object's).
inline const CameraPlayback *intro_camera_playback() {
    static const CameraPlayback lbl_804373DC = {0, 3, 0, 0.0f, 0.5f};
    return &lbl_804373DC;
}
inline const CameraAngles *intro_camera_angles() {
    static const CameraAngles lbl_804373E8 = {0, 0, 0};
    return &lbl_804373E8;
}

TObjDFDemo4::TObjDFDemo4(TObject *parent, const Vec *pos, s32 angle) : TObjBase(parent) {
    BmlResource *res;
    s32 i;
    m_name = TObjDFDemo4__name;
    VecCopy(&this->pos, pos);
    this->angle = angle;
    res = (BmlResource *)TBoss4Uro::get_instance_count();
    for (i = 0; i < 2; i++) {
        int id = boss4_zanzo_bml_index_table[i];
        zanzo_parts[i].model = get_bml_model(res, id);
        zanzo_parts[i].texlist = TObjFish__sub_8001EDB0(res, id);
        zanzo_parts[i].motion = get_bml_motion(res, lbl_80485720[i]);
    }
    for (i = 0; i < 3; i++) {
        int id = lbl_80486FB0[i];
        body_parts[i].model = get_bml_model(res, id);
        body_parts[i].texlist = TObjFish__sub_8001EDB0(res, id);
        body_parts[i].motion = get_bml_motion(res, lbl_80485728[i]);
    }
    frame = -0.5f;
    init_model_node_tables(&node_tables, strip_nodes(), 2);
    for (s32 j = 0; j < 2; j++) {
        particle_emitters[j] = NULL;
    }
    activate_camera_mode(5);
    {
        CameraPlayback playback = *intro_camera_playback();
        CameraAngles angles = *intro_camera_angles();
        angles.yaw = this->angle;
        set_scripted_camera_pose(&this->pos, &this->pos, &angles);
        ((TCameraCtrl *)&playback)->cache_target_and_forward(0x416C);
    }
    node_list = (TObjFish *)TObjFish__sub_800E3124((u8 *)lbl_80485734, (s32)node_positions);
    timer = 0;
}

TObjDFDemo4::~TObjDFDemo4() {
    s32 i;
    fn_8004AA04(&node_tables);
    if (node_list != NULL) {
        TObjFish::init_state_1(node_list);
        node_list = NULL;
    }
    for (i = 0; i < 2; i++) {
        if (particle_emitters[i] != NULL) {
            TParticleCtrl::release(particle_emitters[i]);
            particle_emitters[i] = NULL;
        }
    }
    restore_player_cameras();
}

void TObjDFDemo4::run_task() {
    TParticleCtrl *fx;
    if (timer <= 0x3C && (fx = (TParticleCtrl *)spawn_particle_effect(&pos, 0x14E)) != NULL) {
        fx->set_flags(0x40);
    }
    if (timer == 0x44) {
        if ((fx = (TParticleCtrl *)spawn_particle_effect(&pos, 0x17B)) != NULL) {
            fx->set_flags(0x40);
        }
        if ((fx = (TParticleCtrl *)spawn_particle_effect(&pos, 0x17C)) != NULL) {
            fx->set_flags(0x40);
        }
    }
    if (timer == 0x48) {
        if ((fx = (TParticleCtrl *)spawn_particle_effect(&pos, 0x17A)) != NULL) {
            fx->set_flags(0x40);
        }
        play_sound_effect(0x40039E09, &pos, 0, 1);
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (timer == 0x72) {
        play_sound_effect(0x4003B227, &pos, 0, 1);
    }
    if (timer >= 0xAA) {
        TParticleCtrl **p = &particle_emitters[0];
        s32 i;
        for (i = 0; i < 2; i++) {
            Vec *v = &node_positions[i];
            if (*p == NULL) {
                *p = create_particle_emitter(v, 0x147);
                if (*p != NULL) {
                    (*p)->set_flags(0x40);
                }
            } else {
                (*p)->set_position(v);
            }
            p = &particle_emitters[1];
        }
    }
    if (timer == 0x72) {
        Vec p = {10000.0f, -10.0f, 0.0f};
        CameraAngles angles = {0, 0, 0};
        VecCopy(&pos, &p);
        angle = 0;
        set_scripted_camera_pose(&pos, &pos, &angles);
    }
    if ((frame += 0.5f) > 119.0f) {
        frame = 119.0f;
    }
    ((TBoss4Type2 *)&node_tables)->scroll_strips();
    if (++timer >= 0xF0) {
        queue_destruction();
    }
}

void TObjDFDemo4::render() {
    sub_8004F2A8();
    sub_8004F1FC();
}

void TObjDFDemo4::sub_8004F2A8() {
    f32 alpha;
    s32 i;
    alpha = 1.0f;
    if (timer > 0x4C) {
        return;
    }
    if (timer > 0x44) {
        alpha = (f32)(0x4C - timer) / 8.0f;
    }
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, angle);
    for (i = 0; i < 2; i++) {
        TObjFish::set_global_param(zanzo_parts[i].texlist);
        draw_model_motion((void *)zanzo_parts[i].model, zanzo_parts[i].motion, 120.0f);
    }
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

void TObjDFDemo4::sub_8004F1FC() {
    s32 i;
    if (timer >= 0x44) {
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&pos.x);
        rotate_matrix_y(NULL, angle);
        for (i = 0; i < 3; i++) {
            TObjFish::set_global_param(body_parts[i].texlist);
            if (i == 0) {
                node_list->set_draw_callback_list();
            }
            draw_model_motion((void *)body_parts[i].model, body_parts[i].motion, frame);
            if (i == 0) {
                node_list->clear_render_callback();
            }
        }
        clear_motion_packed_rotation();
        pop_matrix();
    }
}
