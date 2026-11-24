#include "pso/system/vector.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/derolle/TBoss2Tentacle.h"

#include "types.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"

#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2F28.h"

static const int TBoss2Tentacle__rest_angles[] = {-2048, 2048, -4864, 4864};
static const s32 boss2_tentacle_angle_limit_table[] = {4096, -4096, 6144, -6144};
const char *TBoss2Tentacle__name = "TBoss2Tentacle";

// Shared by the four tentacles, set up by load_shared_model.
NJS_OBJECT *boss2_tentacle_model;
AnimationMotion *TBoss2Tentacle__motion_data;
NJS_TEXLIST *boss2_tentacle_texlist;

// The working copy of the model nodes drawn while striking, and the rest pose read from the model;
// defined below with load_shared_model.
extern NJS_OBJECT tentacle_model_nodes[];
extern Vec TBoss2Tentacle__segment_points[];
extern s32 TBoss2Tentacle__segment_point_defaults[];

void TBoss2Tentacle::render() {
    s32 i;
    set_motion_packed_rotation();
    TObjFish::set_global_param(boss2_tentacle_texlist);
    push_matrix();
    switch (state) {
    case 0:
        ::concat_matrix(NULL, joint);
        rotate_matrix_y(0, yaw);
        draw_model_motion(boss2_tentacle_model, TBoss2Tentacle__motion_data, frame);
        break;
    case 1:
    case 4:
    case 5:
        ::concat_matrix(NULL, joint);
        rotate_matrix_x(0, pitch);
        rotate_matrix_y(0, yaw);
        draw_model_motion(boss2_tentacle_model, TBoss2Tentacle__motion_data, frame);
        break;
    case 2:
        ::concat_matrix(NULL, joint);
        rotate_matrix_x(0, pitch);
        rotate_matrix_y(0, yaw);
        draw_chunk_object(boss2_tentacle_model);
        break;
    case 3:
        post_translate_matrix(&position.x);
        scale_matrix(0, 2.0f, 2.0f, 2.0f);
        rotate_matrix_y(0, yaw);
        rotate_matrix_z(0, pitch);
        for (i = 0; i < 14; i++) {
            tentacle_model_nodes[i].pos[0] = segment_pos[i].x;
            tentacle_model_nodes[i].pos[1] = segment_pos[i].y;
            tentacle_model_nodes[i].pos[2] = segment_pos[i].z;
            tentacle_model_nodes[i].ang[2] = segment_ang[i];
        }
        draw_chunk_object(tentacle_model_nodes);
        break;
    }
    pop_matrix();
    clear_motion_packed_rotation();
}

#pragma pool_data off
void TBoss2Tentacle::run_task() {
    if (next_state != state) {
        switch (next_state) {
        case 0:
            enter_sway();
            break;
        case 1:
            enter_raise();
            break;
        case 4:
            enter_turn_to_rest();
            break;
        case 2:
            init_motion_from_table();
            break;
        case 3:
            reset();
            break;
        case 5:
            enter_drop_back();
            break;
        }
        state = next_state;
    }
    switch (state) {
    case 0:
        advance_motion_position();
        sway_phase += sway_speed;
        yaw = 1365.0f * (1.0f + sin_table_lookup(sway_phase));
        if (!(index & 1)) {
            yaw = -yaw;
        }
        break;
    case 1:
        advance_motion_position();
        pitch = approach_angle_limited(pitch, 0x4000, 0x280);
        break;
    case 2:
        yaw = approach_angle_limited(yaw, 0, 0x80);
        if (yaw == 0) {
            request_strike();
        }
        break;
    case 3: {
        Vec pos;
        Vec v;
        f32 len;
        v.z = v.y = v.x = 0.0f;
        push_matrix();
        set_matrix_identity(0);
        ::concat_matrix(NULL, joint);
        matrix_mult_vec(0, &v, &position);
        pop_matrix();
        VecCopy(&v, &target);
        subtract_vector(&v, &position);
        len = normalize_vector_xz(&v);
        yaw = (s32)(10430.38043493439 * atan2_float(v.x, v.z)) + 0x8000;
        VecCopy(&pos, &target);
        switch (attack_phase) {
        case 0: {
            s32 i;
            segment_scale -= 0.1f;
            if (segment_scale <= 0.1f) {
                segment_scale = 0.1f;
                timer = 0;
                attack_phase = 1;
            }
            for (i = 2; i < 12; i++) {
                segment_pos[i].x = segment_scale * TBoss2Tentacle__segment_points[i].x;
            }
            segment_ang[2] = 0x4000;
            break;
        }
        case 1:
            reach += 8.0f;
            if (reach > len) {
                TBoss2DeRolLe *boss;
                reach = len;
                timer = 0;
                attack_phase = 2;
                boss = TBoss2DeRolLe::get_instance();
                if (boss != NULL) {
                    boss->emit_effect_and_step(&pos);
                }
                play_sound_effect(0x4003A507, &pos, 0, 0);
            }
            if (reach >= 0.4f * len) {
                bend = 1.0f;
            } else {
                bend = reach / (0.4f * len);
            }
            pitch = approach_angle_limited(pitch, boss2_tentacle_angle_limit_table[index], 0x100);
            shape_strike_arc(len);
            break;
        case 2:
            timer++;
            if (timer > hold_time) {
                timer = 0;
                segment_scale = 1.0f;
                attack_phase = 3;
            }
            sub_8003998C();
            break;
        case 3:
            reach -= 8.0f;
            if (reach < 20.0f) {
                reach = 20.0f;
                attack_phase = 2;
                request_turn_to_rest();
            }
            if (reach >= 0.4f * len) {
                bend = 1.0f;
            } else {
                bend = reach / (0.4f * len);
            }
            pitch = approach_angle_limited(pitch, 0, 0x100);
            shape_strike_arc(len);
            break;
        }
        break;
    }
    case 4:
        advance_motion_position();
        yaw = approach_angle_limited(yaw, TBoss2Tentacle__rest_angles[index], 0x80);
        break;
    case 5:
        advance_motion_position();
        pitch = approach_angle_limited(pitch, 0, 0x280);
        if (pitch == 0) {
            request_sway();
        }
        break;
    }
}
#pragma pool_data reset

void TBoss2Tentacle::sub_8003998C() {  }
void TBoss2Tentacle::sub_80039990() {  }

#pragma push
#pragma fp_contract on
void TBoss2Tentacle::shape_strike_arc(f32 length) {
    s32 i;
    s32 prev, ang;
    s32 j;
    f32 scale = 0.5f;
    f32 half = scale * length;
    f32 h = 60.0f - position.y;
    f32 a;
    f32 step = reach;
    a = -(h / (half * half));
    step /= 9.0f;
    f32 dx, dy, px, py, w, k;
    for (i = 0; i < 10; i++) {
        f32 t = step * (f32)i;
        f32 d = t - half;
        Vec *pt = (Vec *)((u8 *)segment_pos + (i + 2) * sizeof(Vec));
        pt->x = scale * t;
        pt->y = scale * (d * (a * d) + h);
    }
    sub_80039990();
    segment_pos[2].x = 0.0f;
    segment_pos[2].y = 0.0f;
    segment_pos[2].z = 0.0f;
    px = 0.0f;
    py = 0.0f;
    prev = 0;
    for (j = 3; j <= 11; j++) {
        f32 x = segment_pos[j].x;
        f32 y = segment_pos[j].y;
        dx = x - px;
        dy = y - py;
        px = x;
        py = y;
        ang = (s32)(10430.38043493439 * atan2_float(dy, dx));
        segment_ang[j - 1] = ang - prev;
        prev = ang;
        segment_pos[j].x = newton_sqrtf(dy * dy + dx * dx);
        segment_pos[j].y = 0.0f;
        segment_pos[j].z = 0.0f;
    }
    segment_ang[11] = segment_ang[10];
    sub_80039990();
    w = bend;
    if (w < 1.0f) {
        k = 1.0f - w;
        k *= segment_scale;
        for (i = 2; i < 12; i++) {
            segment_pos[i].x = segment_pos[i].x * w + k * TBoss2Tentacle__segment_points[i].x;
        }
        segment_ang[2] = (s32)(16384.0f * (1.0f - bend) + (f32)segment_ang[2] * w);
        for (i = 3; i < 12; i++) {
            segment_ang[i] = (s32)((f32)segment_ang[i] * w);
        }
    }
}
#pragma pop

void TBoss2Tentacle::advance_motion_position() {
    f32 lim = (TBoss2Tentacle__motion_data->frameCount - 1);
    frame += frame_speed;
    if (frame >= lim) {
        frame -= lim;
    }
}

// The boss polls this through a declaration returning s32 (it tests the whole register), so it stays a
// free function under its own name.
s32 TBoss2Tentacle::is_turning_to_rest() { return state == 4; }

void TBoss2Tentacle::enter_drop_back() {
    yaw = 0;
    pitch = 0x4000;
}

void TBoss2Tentacle::reset() {
    yaw = 0;
    pitch = 0;
    attack_phase = 0;
    reset_segment_points();
    reach = 20.0f;
    timer = 0;
    bend = 0.0f;
    segment_scale = 1.0f;
}

void TBoss2Tentacle::init_motion_from_table() {
    yaw = TBoss2Tentacle__rest_angles[index];
    pitch = 0x4000;
    attack_phase = 0;
}

void TBoss2Tentacle::enter_turn_to_rest() {
    yaw = 0;
    pitch = 0x4000;
}

void TBoss2Tentacle::enter_raise() {
    yaw = TBoss2Tentacle__rest_angles[index];
    pitch = 0;
}

void TBoss2Tentacle::enter_sway() {
    pitch = 0;
    yaw = 0;
}

void TBoss2Tentacle::request_drop_back() { next_state = 5; }
void TBoss2Tentacle::request_strike() { next_state = 3; }
void TBoss2Tentacle::request_aim() { next_state = 2; }
void TBoss2Tentacle::request_turn_to_rest() { next_state = 4; }
void TBoss2Tentacle::request_raise() { next_state = 1; }
void TBoss2Tentacle::request_sway() { next_state = 0; }

void TBoss2Tentacle::reset_segment_points() {
    s32 i;
    for (i = 0; i < 14; i++) {
        VecCopy(&segment_pos[i], &TBoss2Tentacle__segment_points[i]);
        segment_ang[i] = TBoss2Tentacle__segment_point_defaults[i];
    }
}

void TBoss2Tentacle::speed_up_sway() {
    frame_speed = 1.6f;
    sway_speed = 3038;
}

void TBoss2Tentacle::drop_back() { request_drop_back(); }

void TBoss2Tentacle::start_attack_at_target(const Vec *target_pos, s32 hold_time) {
    if ((hold_time <= 0) || (hold_time >= 0x258)) {
        hold_time = 0x78;
    }
    this->hold_time = hold_time;
    VecCopy(&target, target_pos);
    request_aim();
}

void TBoss2Tentacle::raise() { request_raise(); }

TBoss2Tentacle::~TBoss2Tentacle() {}

TBoss2Tentacle::TBoss2Tentacle(TObject *parent, const f32 (*joint)[4], s32 index) : TObject(parent) {
    s32 i;
    m_name = TBoss2Tentacle__name;
    this->joint = joint;
    this->index = index;
    state = 0;
    next_state = 0;
    attack_phase = 0;
    for (i = 0; i < 14; i++) {
        VecCopy(&segment_pos[i], &TBoss2Tentacle__segment_points[i]);
        segment_ang[i] = TBoss2Tentacle__segment_point_defaults[i];
    }
    frame = (TBoss2Tentacle__motion_data->frameCount - 1) * (3.0517578125e-05f * (f32)rand());
    frame_speed = 0.8f;
    yaw = 0;
    pitch = 0;
    sway_speed = 0x5EF;
    sway_phase = TObjPlayer::calc_random_scaled();
    reach = 0.0f;
    bend = 0.0f;
    timer = 0;
    hold_time = 0x78;
    target.x = 0.0f;
    target.y = 0.0f;
    target.z = 0.0f;
}

void TBoss2Tentacle::release_shared_model() {  }


NJS_OBJECT tentacle_model_nodes[14];
Vec TBoss2Tentacle__segment_points[14];
s32 TBoss2Tentacle__segment_point_defaults[14];

void TBoss2Tentacle::load_shared_model() {
    NJS_OBJECT *src;
    NJS_OBJECT *dst;
    s32 i;
    dst = tentacle_model_nodes;
    boss2_tentacle_model = boss2_derolle_resource->models[4].model;
    src = boss2_tentacle_model;
    TBoss2Tentacle__motion_data = boss2_derolle_resource->motions[17].motion;
    boss2_tentacle_texlist = boss2_derolle_resource->models[2].texlist;
    for (i = 0; i < 12; i++) {
        copy_model_node(dst, src);
        dst->child = dst + 1;
        dst++;
        src = src->child;
    }
    copy_model_node(dst, src);
    dst->sibling = dst + 1;
    copy_model_node(&dst[1], src->sibling);
    for (i = 0; i < 14; i++) {
        tentacle_model_nodes[i].evalflags &= ~3;
        TBoss2Tentacle__segment_points[i].x = (f64)tentacle_model_nodes[i].pos[0];
        TBoss2Tentacle__segment_points[i].y = tentacle_model_nodes[i].pos[1];
        TBoss2Tentacle__segment_points[i].z = tentacle_model_nodes[i].pos[2];
        TBoss2Tentacle__segment_point_defaults[i] = tentacle_model_nodes[i].ang[2];
    }
}
