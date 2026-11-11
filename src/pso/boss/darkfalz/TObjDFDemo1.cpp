#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/darkfalz/TObjDFDemo1.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/boss/darkfalz/TBoss4Uro.h"
#include "pso/enemy/sorcerer/TObjEneRe4Sorcerer_801E3F14.h"
#include "pso/math/AngleLookup.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80052374.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/PadRumble.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/vector.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"

#pragma readonly_strings on
// Built with deferred code generation: functions come out in reverse order
// (sub_8004E068 first in .text).
#pragma defer_codegen on

// A particle emitter of the scene: live from frame `start` to frame `end`,
// placed at `offset` turned by the object's angle.
struct DFDemo1Emitter {
    s32 effect;
    s32 start;
    s32 end;
    Vec offset;
};

// A colour of a zanzo model node whose alpha fades in.
struct DFDemo1NodeColor {
    s32 part;   // index into zanzo_parts
    s32 node;   // find_model_node index
    s32 slot;   // s16 index into the node's chunk polygon list
};

// TBoss4Type1's body models and TBoss4Zanzo's model table.
extern s32 lbl_80485EB0[6];
extern s32 boss4_zanzo_bml_index_table[];
#include "pso/render/model_render_state.h"
// Defined after the constructor: it follows the constructor's angle template in .rodata.
extern const ModelNodeSpec lbl_80437328[6];

const char *TObjDFDemo1__name = "TObjDFDemo1";
DFDemo1Emitter lbl_80485590[4] = {
    {0x144, 0x2C, 0x7C, {130.0f, 10.0f, 0.0f}},
    {0x144, 0x2C, 0x7C, {0.0f, 10.0f, 130.0f}},
    {0x144, 0x2C, 0x7C, {-130.0f, 10.0f, 0.0f}},
    {0x14F, 0x90, 0xAA, {0.0f, 40.0f, 0.0f}},
};
// The motions of the body models and of the zanzo models.
s32 lbl_804855F0[6] = {0x50, 0x4E, 0x1B, 0x1B, 0x1B, 0x1A};
s32 lbl_80485608[2] = {0x1D, 0x1C};
CameraPlayback lbl_80485610 = {0, 2, 0, 0.0f, 0.5f};
DFDemo1NodeColor lbl_8048561C[3] = {{0, 2, 5}, {1, 6, 5}, {1, 0x69, 3}};
void *TBoss4DarkFalz::create_demo1(void *parent, void *pos, void *angle) {
    return new TObjDFDemo1((TObject *)parent, (const Vec *)pos, (s32)angle);
}

TObjDFDemo1::TObjDFDemo1(TObject *parent, const Vec *pos, s32 angle) : TObjBase(parent) {
    BmlResource *res;
    s32 i;
    m_name = TObjDFDemo1__name;
    VecCopy(&this->pos, pos);
    this->angle = angle;
    res = (BmlResource *)TBoss4Uro::get_instance_count();
    for (i = 0; i < 6; i++) {
        int id = lbl_80485EB0[i];
        body_parts[i].model = get_bml_model(res, id);
        body_parts[i].texlist = TObjFish__sub_8001EDB0(res, id);
        body_parts[i].motion = get_bml_motion(res, lbl_804855F0[i]);
    }
    for (i = 0; i < 2; i++) {
        int id = boss4_zanzo_bml_index_table[i];
        zanzo_parts[i].model = get_bml_model(res, id);
        zanzo_parts[i].texlist = TObjFish__sub_8001EDB0(res, id);
        zanzo_parts[i].motion = get_bml_motion(res, lbl_80485608[i]);
    }
    frame = -0.5f;
    for (s32 j = 0; j < 4; j++) {
        particle_emitters[j] = NULL;
    }
    activate_camera_mode(5);
    {
        CameraAngles angles = {0, this->angle, 0};
        set_scripted_camera_pose(&this->pos, &this->pos, &angles);
    }
    lbl_80485610.cache_target_and_forward(0x4000);
    play_sound_effect(0x4003A324, &position, 0, 1);
    scroll = 0.0f;
    strips.init(lbl_80437328, 6);
    timer = 0;
}

// The nodes ModelNodeTables::init builds the strips on.
const ModelNodeSpec lbl_80437328[6] = {
    {0xB, 3, 0}, {0xA, 5, 0}, {0xA, 0x60, 0}, {0xA, 0x63, 0}, {0xA, 0x65, 0}, {0xA, 0x68, 0},
};

TObjDFDemo1::~TObjDFDemo1() {
    s32 i;
    strips.destroy();
    for (i = 0; i < 4; i++) {
        if (particle_emitters[i] != NULL) {
            TParticleCtrl::release(particle_emitters[i]);
            particle_emitters[i] = NULL;
        }
    }
    restore_player_cameras();
}

#pragma push
#pragma fp_contract on
void TObjDFDemo1::run_task() {
    DFDemo1Emitter *e;
    s32 i;
    for (i = 0; i < 4; i++) {
        e = &lbl_80485590[i];
        if (timer >= e->end) {
            if (particle_emitters[i] != NULL) {
                TParticleCtrl::release(particle_emitters[i]);
                particle_emitters[i] = NULL;
            }
        } else if (timer >= e->start) {
            if (particle_emitters[i] == NULL) {
                f32 s = sin_table_lookup(-angle);
                f32 c = cos_table_lookup(-angle);
                Vec p;
                p.x = c * e->offset.x + s * e->offset.z;
                p.z = -s * e->offset.x + c * e->offset.z;
                p.y = e->offset.y;
                vec3_add_to(&p, &pos);
                particle_emitters[i] = create_particle_emitter(&p, lbl_80485590[i].effect);
                if (particle_emitters[i] != NULL) {
                    particle_emitters[i]->set_flags(0x40);
                }
            }
        }
    }
    if (timer >= 0x46 && timer <= 0x82) {
        TParticleCtrl *fx = (TParticleCtrl *)spawn_particle_effect(&pos, 0x14E);
        if (fx != NULL) {
            fx->set_flags(0x40);
        }
    }
    if (timer == 0x46 || timer == 0x2C) {
        start_pad_rumble_all(0xC0, 0xF);
    }
    if (timer == 0x7C) {
        play_sound_effect(0x4003AA26, &pos, 0, 1);
    }
    if ((frame += 0.5f) > 149.0f) {
        frame = 149.0f;
    }
    if ((scroll += 1.0f / 45.0f) >= 1.0f) {
        scroll -= 1.0f;
    }
    strips.scroll_strips();
    if (++timer >= 300) {
        queue_destruction();
    }
}
#pragma pop

void TObjDFDemo1::render() {
    draw_fading_model();
    sub_8004E068();
}

void TObjDFDemo1::draw_fading_model() {
    f32 max;
    f32 alpha;
    f32 f;
    s32 i;
    alpha = 1.0f;
    if (timer >= 0x88) {
        return;
    }
    if (timer > 0x7C) {
        alpha = (f32)(0x88 - timer) / 12.0f;
    }
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, angle);
    max = 30.0f;
    for (i = 0; i < 6; i++) {
        TObjFish::set_global_param(body_parts[i].texlist);
        f = frame;
        switch (i) {
        case 0:
        case 1:
            if (f > max) {
                f = max;
            }
            break;
        }
        draw_model_motion((void *)body_parts[i].model, body_parts[i].motion, f);
    }
    clear_motion_packed_rotation();
    pop_matrix();
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}

void TObjDFDemo1::sub_8004E068() {
    f32 alpha;
    s32 i;
    s16 *col;
    f32 f;
    DFDemo1NodeColor *e;
    s32 j;
    alpha = 1.0f;
    if (timer <= 0x7C) {
        return;
    }
    if (timer < 0x88) {
        alpha = (timer - 0x7C) / 12.0f;
    }
    col = ((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(zanzo_parts[1].model, 0x6A))->model)->polygon_list;
    f = 0.0f;
    if (timer >= 0xF0) {
        f = 1.0f;
    } else if (timer > 0xE6) {
        f = (timer - 0xE6) / 10.0f;
    }
    col[3] = (col[3] & 0xFF) | ((s32)(255.0f * f) << 8);
    f = 0.0f;
    if (timer >= 0x104) {
        f = 1.0f;
    } else if (timer > 0xF0) {
        f = (timer - 0xF0) / 20.0f;
    }
    for (i = 0; i < 3; i++) {
        e = &lbl_8048561C[i];
        col = ((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(zanzo_parts[e->part].model, e->node))->model)->polygon_list;
        s32 old = col[e->slot];
        col[e->slot] = (old & 0xFF) | ((s32)(255.0f * f) << 8);
    }
    if (alpha < 1.0f) {
        TObjPlayer__sub_80052390(alpha);
    }
    model_render_flags |= 0x20000;
    TObjEneRe4Sorcerer__sub_801E3F1C(0.0f, scroll);
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, angle);
    for (j = 0; j < 2; j++) {
        TObjFish::set_global_param(zanzo_parts[j].texlist);
        draw_model_motion((void *)zanzo_parts[j].model, zanzo_parts[j].motion, frame);
    }
    clear_motion_packed_rotation();
    pop_matrix();
    model_render_flags &= ~0x20000;
    if (alpha < 1.0f) {
        TObjPlayer::sync_player_globals();
    }
}
