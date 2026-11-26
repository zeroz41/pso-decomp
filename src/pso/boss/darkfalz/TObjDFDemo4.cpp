#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/boss/darkfalz/TObjDFDemo4.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/PadRumble.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/darkfalz/TBoss4Zanzo.h"

#pragma readonly_strings on
// Built with deferred code generation (-inline deferred): functions come out in reverse
// order (draw_body_parts first in .text).

// Dark Falz's afterimage (zanzo) models.

const char *TObjDFDemo4::name = "TObjDFDemo4";
// The motions of the afterimage and body models.
s32 df_demo4_zanzo_motion_ids[2] = {0x12, 0x11};
s32 df_demo4_body_motion_ids[3] = {0x20, 0x21, 0x22};
ModelNodePositionEntry df_demo4_node_capture_entries[3] = {{0x34}, {0x35}, {-1}};

TObjDFDemo4 *TObjDFDemo4::create(TObject *parent, const Vec *position, s32 angle) {
    return new TObjDFDemo4(parent, position, angle);
}

// The nodes ModelNodeTables::init builds the strips on.
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
    m_name = TObjDFDemo4::name;
    VecCopy(&this->pos, pos);
    this->angle = angle;
    res = TBoss4Uro::get_instance_count();
    for (i = 0; i < 2; i++) {
        int id = boss4_zanzo_bml_index_table[i];
        zanzo_parts[i].model = get_bml_model(res, id);
        zanzo_parts[i].texlist = get_bml_texlist(res, id);
        zanzo_parts[i].motion = get_bml_motion(res, df_demo4_zanzo_motion_ids[i]);
    }
    for (i = 0; i < 3; i++) {
        int id = boss4_type3_model_ids[i];
        body_parts[i].model = get_bml_model(res, id);
        body_parts[i].texlist = get_bml_texlist(res, id);
        body_parts[i].motion = get_bml_motion(res, df_demo4_body_motion_ids[i]);
    }
    frame = -0.5f;
    node_tables.init(strip_nodes(), 2);
    for (s32 j = 0; j < 2; j++) {
        particle_emitters[j] = NULL;
    }
    activate_camera_mode(5);
    {
        CameraPlayback playback = *intro_camera_playback();
        CameraAngles angles = *intro_camera_angles();
        angles.yaw = this->angle;
        set_scripted_camera_origin(&this->pos, &this->pos, &angles);
        playback.play(0x416C);
    }
    node_list = ModelNodePositionCapture::create(df_demo4_node_capture_entries, node_positions);
    timer = 0;
}

TObjDFDemo4::~TObjDFDemo4() {
    s32 i;
    node_tables.destroy();
    if (node_list != NULL) {
        ModelNodePositionCapture::destroy(node_list);
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
    if (timer <= 0x3C && (fx = spawn_particle_effect(&pos, 0x14E)) != NULL) {
        fx->set_flags(0x40);
    }
    if (timer == 0x44) {
        if ((fx = spawn_particle_effect(&pos, 0x17B)) != NULL) {
            fx->set_flags(0x40);
        }
        if ((fx = spawn_particle_effect(&pos, 0x17C)) != NULL) {
            fx->set_flags(0x40);
        }
    }
    if (timer == 0x48) {
        if ((fx = spawn_particle_effect(&pos, 0x17A)) != NULL) {
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
        set_scripted_camera_origin(&pos, &pos, &angles);
    }
    if ((frame += 0.5f) > 119.0f) {
        frame = 119.0f;
    }
    node_tables.scroll_strips();
    if (++timer >= 0xF0) {
        queue_destruction();
    }
}

void TObjDFDemo4::render() {
    draw_zanzo_parts();
    draw_body_parts();
}

void TObjDFDemo4::draw_zanzo_parts() {
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
        begin_alpha_blend(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, angle);
    for (i = 0; i < 2; i++) {
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(zanzo_parts[i].texlist));
        draw_model_motion(zanzo_parts[i].model, zanzo_parts[i].motion, 120.0f);
    }
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        end_alpha_blend();
    }
}

void TObjDFDemo4::draw_body_parts() {
    s32 i;
    if (timer >= 0x44) {
        push_matrix();
        set_motion_packed_rotation();
        post_translate_matrix(&pos.x);
        rotate_matrix_y(NULL, angle);
        for (i = 0; i < 3; i++) {
            set_texture_list(reinterpret_cast<NJS_TEXLIST *>(body_parts[i].texlist));
            if (i == 0) {
                node_list->install();
            }
            draw_model_motion(body_parts[i].model, body_parts[i].motion, frame);
            if (i == 0) {
                node_list->clear();
            }
        }
        clear_motion_packed_rotation();
        pop_matrix();
    }
}
