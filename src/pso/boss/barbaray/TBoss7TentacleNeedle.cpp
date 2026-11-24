#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/barbaray/TBoss7Tentacle.h"
#include "pso/boss/barbaray/TBoss7DeRolLeC.h"
#include "pso/boss/barbaray/TBoss7TentacleNeedle.h"
#include "pso/boss/barbaray/Boss7TentacleData.h"
#include "pso/boss/barbaray/TBoss7Joint.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/system/NinjaTypes.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"

// Unit-owned .bss banks (0x80541528-0x80541928), defined in address order: the tentacle's working
// copy of its model nodes 0x310, segment_offsets +0x310 (0xA8), needle_offsets +0x3B8 (0x38).
// Defined in this unit (as in the twin TBoss2Tentacle) so the code hoists their base into r31.
NJS_OBJECT boss7_tentacle_model_nodes[14];
Vec TBoss7Tentacle__segment_offsets[14];
u32 TBoss7Tentacle__needle_offsets[14];
AnimationMotion *boss7_tentacle_needle_motions[4];
NJS_OBJECT *boss7_tentacle_needle_model;

// Written last-to-first: built with -inline off,deferred, which emits functions in reverse source order
// (the Needle vtable 0x804E4830 precedes the Tentacle one although every Needle virtual comes first).

void TBoss7Tentacle::load_static_resource() {
    NJS_OBJECT *src;
    NJS_OBJECT *dst;
    s32 i;

    src = TBoss7DeRolLeC::get_archive_model(1);
    get_boss7_motion(0x11);
    dst = boss7_tentacle_model_nodes;
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
        boss7_tentacle_model_nodes[i].evalflags &= ~3;
        TBoss7Tentacle__segment_offsets[i].x = (f64)boss7_tentacle_model_nodes[i].pos[0];
        TBoss7Tentacle__segment_offsets[i].y = boss7_tentacle_model_nodes[i].pos[1];
        TBoss7Tentacle__segment_offsets[i].z = boss7_tentacle_model_nodes[i].pos[2];
        TBoss7Tentacle__needle_offsets[i] = (u32)boss7_tentacle_model_nodes[i].ang[2];
    }
}

void TBoss7Tentacle::destroy_instance() {}

TBoss7Tentacle::TBoss7Tentacle(TObject *parent, const f32 (*joint)[4], s32 index) : TObject(parent) {
    m_name = TBoss7Tentacle__name;
    model = TBoss7DeRolLeC::get_archive_model(1);
    motion = get_boss7_motion(0x11);
    this->joint = joint;
    this->index = index;
    state = 0;
    next_state = 0;
    attack_phase = 0;
    init_segments();
    frame = (f32)(motion->frameCount - 1) * (3.0517578e-05f * (f32)rand());
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
    flags = 0;
    scale.x = 1.0f;
    scale.y = 1.0f;
    scale.z = 1.0f;
}

TBoss7Tentacle::~TBoss7Tentacle() {}

void TBoss7Tentacle::enable_extend() { flags &= ~HIDDEN; }

void TBoss7Tentacle::enable_retract() { flags |= HIDDEN; }

void TBoss7Tentacle::raise() {
    next_state = 1;
    flags &= ~HIDDEN;
}

void TBoss7Tentacle::start_attack_at_position(const Vec *target, s32 hold_time) {
    if ((hold_time <= 0) || (hold_time >= 0x258)) {
        hold_time = 0x78;
    }
    this->hold_time = hold_time;
    VecCopy(&this->target, target);
    request_aim();
}

void TBoss7Tentacle::drop_back() {
    next_state = 5;
    flags &= ~HIDDEN;
}

void TBoss7Tentacle::speed_up_sway() {
    frame_speed = 1.6f;
    sway_speed = 3038;
    pitch = 0;
    next_state = 0;
}

void TBoss7Tentacle::init_segments() {
    s32 i;
    for (i = 0; i < 14; i++) {
        VecCopy(&segment_pos[i], &TBoss7Tentacle__segment_offsets[i]);
        segment_ang[i] = TBoss7Tentacle__needle_offsets[i];
    }
}

void TBoss7Tentacle::request_sway() {
    next_state = 0;
    flags &= ~HIDDEN;
}

void TBoss7Tentacle::request_turn_to_rest() {
    next_state = 4;
    flags &= ~HIDDEN;
}

void TBoss7Tentacle::request_aim() {
    next_state = 2;
    flags &= ~HIDDEN;
}

void TBoss7Tentacle::request_strike() {
    next_state = 3;
    flags &= ~HIDDEN;
}

void TBoss7Tentacle::enter_sway() {
    pitch = 0;
    yaw = 0;
}

void TBoss7Tentacle::enter_raise() {
    yaw = TBoss7Tentacle__target_angle_table[index];
    pitch = 0;
}

void TBoss7Tentacle::enter_turn_to_rest() {
    yaw = 0;
    pitch = 0x4000;
}

void TBoss7Tentacle::setup_state() {
    yaw = TBoss7Tentacle__target_angle_table[index];
    pitch = 0x4000;
    attack_phase = 0;
}

void TBoss7Tentacle::reset_state() {
    yaw = 0;
    pitch = 0;
    attack_phase = 0;
    init_segments();
    reach = 20.0f;
    timer = 0;
    bend = 0.0f;
    segment_scale = 1.0f;
}

void TBoss7Tentacle::enter_drop_back() {
    yaw = 0;
    pitch = 0x4000;
}

s32 TBoss7Tentacle::is_attack_finished() {
    return state == 4;
}

void TBoss7Tentacle::advance_path_position() {
    f32 lim = (f32)(motion->frameCount - 1);
    frame = frame + frame_speed;
    if (frame >= lim) {
        frame = frame - lim;
    }
}

#pragma push
#pragma fp_contract on
void TBoss7Tentacle::shape_strike_arc(f32 length) {
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
    w = bend;
    if (w < 1.0f) {
        k = 1.0f - w;
        k *= segment_scale;
        for (i = 2; i < 12; i++) {
            segment_pos[i].x = segment_pos[i].x * w + k * TBoss7Tentacle__segment_offsets[i].x;
        }
        segment_ang[2] = (s32)(16384.0f * (1.0f - bend) + (f32)segment_ang[2] * w);
        for (i = 3; i < 12; i++) {
            segment_ang[i] = (s32)((f32)segment_ang[i] * w);
        }
    }
}
#pragma pop

void TBoss7Tentacle::run_task() {
    switch_state();
    switch (state) {
    case 0:
        advance_path_position();
        sway_phase = sway_phase + sway_speed;
        yaw = (s32)(1365.0f * (1.0f + sin_table_lookup(sway_phase)));
        if (!(index & 1)) {
            yaw = -yaw;
        }
        break;
    case 1:
        advance_path_position();
        pitch = approach_angle_limited(pitch, 0x4000, 0x280);
        break;
    case 2:
        yaw = approach_angle_limited(yaw, 0, 0x80);
        if (yaw == 0) {
            request_strike();
        }
        break;
    case 3: {
        Vec p;
        Vec v;
        f32 len;
        s32 i;
        v.x = 0.0f;
        v.y = 0.0f;
        v.z = 0.0f;
        push_matrix();
        set_matrix_identity(0);
        ::concat_matrix(NULL, joint);
        transform_point_by_current_matrix(&v.x, &position);
        pop_matrix();
        VecCopy(&v, &target);
        subtract_vector(&v, &position);
        len = normalize_vector_xz(&v);
        yaw = (s32)(10430.38043493439 * atan2_float(v.x, v.z)) + 0x8000;
        VecCopy(&p, &target);
        switch (attack_phase) {
        case 0:
            segment_scale -= 0.1f;
            if (segment_scale <= 0.1f) {
                segment_scale = 0.1f;
                timer = 0;
                attack_phase = 1;
            }
            for (i = 2; i < 12; i++) {
                segment_pos[i].x = segment_scale * TBoss7Tentacle__segment_offsets[i].x;
            }
            segment_ang[2] = 0x4000;
            break;
        case 1:
            reach += 8.0f;
            if (reach > len) {
                reach = len;
                timer = 0;
                attack_phase = 2;
                {
                    TBoss7DeRolLeC *boss = TBoss7Joint::get_state();
                    if (boss != NULL) {
                        boss->emit_hit_effect(&p);
                    }
                }
                play_sound_effect(0x3A809, &p, 0, 0);
            }
            if (reach >= 0.4f * len) {
                bend = 1.0f;
            } else {
                bend = reach / (0.4f * len);
            }
            pitch = approach_angle_limited(pitch, boss7_tentacle_angle_table[index], 0x100);
            shape_strike_arc(len);
            break;
        case 2:
            timer = timer + 1;
            if (timer > hold_time) {
                timer = 0;
                segment_scale = 1.0f;
                attack_phase = 3;
            }
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
        advance_path_position();
        yaw = approach_angle_limited(yaw, TBoss7Tentacle__target_angle_table[index], 0x80);
        break;
    case 5:
        advance_path_position();
        pitch = approach_angle_limited(pitch, 0, 0x280);
        if (pitch == 0) {
            request_sway();
        }
        break;
    }
    update_extend_amount();
}

void TBoss7Tentacle::switch_state() {
    s32 state = next_state;
    if (state != this->state) {
        switch (state) {
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
            setup_state();
            break;
        case 3:
            reset_state();
            break;
        case 5:
            enter_drop_back();
            break;
        }
        this->state = next_state;
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss7Tentacle::update_extend_amount() {
    if (flags & HIDDEN) {
        scale.z = scale.z - 0.1f;
        if (scale.z < 0.0f) {
            scale.z = 0.0f;
        }
    } else {
        scale.z += 0.2f;
        if (scale.z > 1.0f) {
            scale.z = 1.0f;
        }
    }
}
#pragma pop

void TBoss7Tentacle::render() {
    s32 i;
    TObjPlayer::draw_effect();
    push_matrix();
    switch (state) {
    case 0:
        set_motion_packed_rotation();
        ::concat_matrix(NULL, joint);
        rotate_matrix_y(0, yaw);
        scale_current_matrix(&scale.x);
        draw_model_motion(model, motion, frame);
        clear_motion_packed_rotation();
        break;
    case 1:
    case 4:
    case 5:
        set_motion_packed_rotation();
        ::concat_matrix(NULL, joint);
        rotate_matrix_zyx(0, pitch, yaw, 0);
        scale_current_matrix(&scale.x);
        draw_model_motion(model, motion, frame);
        clear_motion_packed_rotation();
        break;
    case 2:
        ::concat_matrix(NULL, joint);
        rotate_matrix_zyx(0, pitch, yaw, 0);
        scale_current_matrix(&scale.x);
        draw_chunk_object(model);
        break;
    case 3:
        post_translate_matrix(&position.x);
        scale_current_matrix(boss7_tentacle_draw_scale);
        rotate_matrix_zyx(0, 0, yaw, pitch);
        for (i = 0; i < 14; i++) {
            boss7_tentacle_model_nodes[i].pos[0] = segment_pos[i].x;
            boss7_tentacle_model_nodes[i].pos[1] = segment_pos[i].y;
            boss7_tentacle_model_nodes[i].pos[2] = segment_pos[i].z;
            boss7_tentacle_model_nodes[i].ang[2] = segment_ang[i];
        }
        scale_current_matrix(&scale.x);
        draw_chunk_object(boss7_tentacle_model_nodes);
        break;
    }
    pop_matrix();
}

void TBoss7TentacleNeedle::load_static_resource() {
    boss7_tentacle_needle_model = TBoss7DeRolLeC::get_archive_model(5);
    boss7_tentacle_needle_motions[0] = get_boss7_motion(0x13);
    boss7_tentacle_needle_motions[1] = get_boss7_motion(0x14);
    boss7_tentacle_needle_motions[2] = get_boss7_motion(0x12);
}

void TBoss7TentacleNeedle::destroy_instance() {
    boss7_tentacle_needle_motions[0] = NULL;
    boss7_tentacle_needle_model = NULL;
    boss7_tentacle_needle_motions[1] = NULL;
    boss7_tentacle_needle_motions[2] = NULL;
}

#pragma push
#pragma fp_contract on
TBoss7TentacleNeedle::TBoss7TentacleNeedle(TObject *parent, Vec *pos) : TObject(parent) {
    m_name = boss7_tentacle_needle_name_ptr;
    unk_34 = 1e-05f;
    rotation[0] = 0;
    rotation[1] = (s32)(65536.0f * (3.0517578e-05f * (f32)rand()));
    rotation[2] = 0;
    position.x = 5.0f * (3.0517578e-05f * (f32)rand()) + pos->x - 2.5f;
    position.y = pos->y;
    position.z = 5.0f * (3.0517578e-05f * (f32)rand()) + pos->z - 2.5f;
    state = 0;
    timer = 0;
    s32 w0; s32 w1; s32 w2; s32 v[3];
    w2 = ((s32 *)pos)[0];
    w0 = w2;
    w1 = ((s32 *)pos)[1];
    w2 = ((s32 *)pos)[2];
    v[0] = w0;
    v[1] = w1;
    v[2] = w2;
    particle_emitter = create_particle_emitter(v, 0x212);
    for (s32 i = 0; i < 12; i++) {
        player_hit[i] = 0;
    }
    motion = boss7_tentacle_needle_motions[0];
    frame = 0.0f;
}
#pragma pop

TBoss7TentacleNeedle::~TBoss7TentacleNeedle() {
    if (particle_emitter != NULL) {
        particle_emitter->queue_destruction();
        particle_emitter = NULL;
    }
}

void TBoss7TentacleNeedle::run_task() {
    switch (state) {
    case 0:
        advance_needle_timer();
        return;
    case 1:
        update_retract_state();
        return;
    case 2:
        damage_nearby_players();
        return;
    case 3:
        update_sink();
        return;
    }
}

void TBoss7TentacleNeedle::render() {
    TObjPlayer::draw_effect();
    set_motion_packed_rotation();
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_by_node_angles(rotation, 1);
    draw_model_motion(boss7_tentacle_needle_model, motion, frame);
    pop_matrix();
    clear_motion_packed_rotation();
}

void TBoss7TentacleNeedle::advance_needle_timer() {
    if (timer == 30) {
        state = 1;
        frame = 14.0f;
        return;
    }
    timer = timer + 1;
}

void TBoss7TentacleNeedle::update_retract_state() {
    if ((24.5f < frame) && (frame <= 25.5f)) {
        restart_particle_effect();
    }
    if (advance_toward_limit(1.0f) != 0) {
        state = 2;
        timer = 0;
        motion = boss7_tentacle_needle_motions[1];
        frame = 0.0f;
    }
}

void TBoss7TentacleNeedle::damage_nearby_players() {
    s32 i;
    TObjPlayer *player;
    advance_anim_time_wrapped(0.6f);
    for (i = 0; (u16)i != 12; i++) {
        player = get_player_by_client_id((u16)i);
        if (player != NULL && horizontal_distance_squared(&player->position, &position) < 100.0f) {
            if (timer == 0 && player->roll_physical_accuracy(m_up, 0, 10.0f) != 0) {
                player->receive_physical_attack(m_up, 1.0f);
            }
            if (player->test_actor_flags(0x801) == 0) {
                DirectAttackPayload hit;
                hit.kind = 15;
                hit.power = 100.0f;
                player->receive_direct_attack(m_up, hit, NULL, -1, -1);
                if (player_hit[(u16)i] == 0) {
                    spawn_particle_effect(&player->body_center, 0x214);
                    player_hit[(u16)i] = 1;
                }
            }
        }
    }
    if (timer == 0x3C) {
        state = 3;
        timer = 0;
        motion = boss7_tentacle_needle_motions[2];
        frame = 0.0f;
    } else {
        timer += 1;
    }
}

void TBoss7TentacleNeedle::update_sink() {
    if (advance_toward_limit(1.0f) != 0) {
        queue_destruction();
        disallow_rendering();
    }
}

s32 TBoss7TentacleNeedle::advance_toward_limit(f32 step) {
    if (frame < (f32)motion->frameCount - 1.0f) {
        frame = frame + step;
        return 0;
    }
    frame = 0.0f;
    return 1;
}

void TBoss7TentacleNeedle::advance_anim_time_wrapped(f32 step) {
    f32 lim = (f32)motion->frameCount - 1.0f;
    frame += step;
    if (lim <= frame) {
        frame -= lim;
    }
}

void TBoss7TentacleNeedle::restart_particle_effect() {
    TParticleCtrl *effect;
    if (particle_emitter != NULL) {
        particle_emitter->queue_destruction();
        particle_emitter = NULL;
    }
    effect = spawn_particle_effect(&position, 0x215);
    if (effect != NULL) {
        attach_particle_model(effect, TBoss7DeRolLeC::get_archive_model(4), TBoss7DeRolLeC::get_archive_textures(), 0, 0, 1.0f);
    }
    play_sound_effect(0x3A809, &position, 0, 0);
}
