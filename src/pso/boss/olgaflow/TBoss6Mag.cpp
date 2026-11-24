#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/olgaflow/TBoss6Mag.h"
#include "pso/boss/olgaflow/TBoss6MagMine.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/task/TObject.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/math/InverseTrig.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/effect/particle/ParticleFactory.h"

// The particle effect each emitter slot plays, and the node it follows (-1 for the mag's position).
struct TBoss6MagEmitter {
    s32 effect_id;
    s32 node;
};

// Motion table row: the play mode, the row change_motion moves to when a one-shot motion ends, the motion's
// index in the scene archive and its speed.
struct TBoss6MagMotionEntry {
    s32 mode;
    s32 next;
    s32 motion;
    f32 speed;
};

struct TBoss6MagMotionBlend {
    AnimationMotion *from;
    AnimationMotion *to;
    f32 from_frame;
    f32 to_frame;
};

// The record exchange_object_state reads and writes.
struct TBoss6MagStateRecord {
    s32 flags;
    s16 pad_04;
    s16 value;
    s32 pad_08;
};

// copy_vec3 copies the motion track as one block of words, which a struct with float members does not give.
struct TBoss6MagMotionWords {
    s32 index;
    s32 mode;
    struct {
        s32 words[7];
    } track;
};

extern "C" s32 is_local_client_floor_leader();

#pragma defer_codegen on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma readonly_strings on

const char *boss6_mag_name = "TBoss6Mag";
extern const TBoss6MagEmitter TBoss6Type2__effect_emitter_id_table[4] = { {555, -1}, {556, -1}, {537, -1}, {542, 0} };
extern const ModelNodePositionEntry boss6_mag_capture_nodes[2] = {{3}, {-1}};
extern const TBoss6MagTarget boss6_mag_initial_target = { 0xFFFF, 1 };
extern const TBoss6MagMotion boss6_type2_zero_vec3_block = { 0 };
extern const TBoss6MagMotionTrack boss6_type2_initial_state = { NULL, 0.0f, 0.0f, 0.0f, 0.06666667f, NULL, 0.0f };
extern const s32 boss6_mag_rock_spread_angles[3] = { -0x2000, 0, 0x2000 };
extern const TBoss6MagRamp boss6_mag_zero_ramp = { 0.0f, 0.0f };
CollisionBody TBoss6Mag__collision_body_parts[1] = {
    { { 0.0f, 0.0f, 0.0f }, 30.0f, 0.0f, 0, 0x807B, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
TBoss6MagMotionEntry boss6_type2_motion_table[5] = {
    {0x0, 0x0, 0x36, 0.8f},
    {0x0, 0x1, 0x31, 0.8f},
    {0x2, 0x3, 0x3, 0.4f},
    {0x0, 0x3, 0x32, 0.4f},
    {0x2, 0x0, 0xc, 0.5f},
};
__declspec(section ".data") TBoss6Mag *TBoss6Type2__instance_slots[2] = {
    NULL, NULL,
};

void copy_mag_target(TBoss6MagTarget *dst, TBoss6MagTarget *src) {
    dst->client_id = src->client_id;
    dst->on_shoulder = src->on_shoulder;
}

TBoss6Mag::TBoss6Mag(TObject *parent, TBoss6MagSpawnParams *params) : TObjEnemy(parent) {
    TBoss6MagStateRecord record;
    f32 *tuning;
    s32 param_index;
    m_name = boss6_mag_name;
    owner = params->owner;
    VecCopy(&position, &params->origin);
    rotation_y = params->rotation_y;
    index = params->index;
    TBoss6Type2__instance_slots[index] = this;
    apply_set_data(params);
    if (exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.value = 0;
        exchange_object_state(&record, 0);
    }
    scene_archive = TBoss6PlotFalz::get_scene_archive();
    partner = NULL;
    texlist = 0;
    model = NULL;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    init_collision_body_parts(this, TBoss6Mag__collision_body_parts, 1);
    VecCopy(&body_center, &position);
    velocity.z = 0.0f;
    velocity.y = 0.0f;
    velocity.x = 0.0f;
    target = NULL;
    bind_enemy_combat_stats(TLobby::register_boss(0x2E), TLobby::dispatch_shared_handler_b(0x2E), TLobby::register_object(0x2E));
    referenceHp = hp;
    initial_hp = hp;
    register_by_id();
    param_index = 0x55;
    if (index == 1) {
        param_index = 0x56;
    }
    set_param(param_index);
    add_flags_2e4(params->flags);
    segment_variant = params->variant;
    init_segment_angle_range();
    init_motion_state();
    capture = ModelNodePositionCapture::create(boss6_mag_capture_nodes, node_positions);
    copy_mag_target(&chase_target, (TBoss6MagTarget *)&boss6_mag_initial_target);
    tuning = (f32 *)TLobby::dispatch_shared_handler_a(0x2E);
    dead_duration = (s32)tuning[0];
    if ((f32)dead_duration <= 0.0f) {
        dead_duration = 0x96;
    }
    chase_speed_scale = tuning[1];
    if (chase_speed_scale <= 0.0f) {
        chase_speed_scale = 2.0f;
    }
    init_with_global_table();
    hit_flash = 0.0f;
    hp_ratio = 1.0f;
    fade = 0.0f;
    sync_hp();
    clear_particle_emitters();
    set_action(0);
}

TBoss6Mag::~TBoss6Mag() {
    update_all_parts();
    if (capture != NULL) {
        ModelNodePositionCapture::destroy(capture);
        capture = NULL;
    }
    free_collision_body_parts(this);
    TBoss6Type2__instance_slots[index] = NULL;
}

void TBoss6Mag::run_task() {
    s32 marker_color;

    if (TObjPlayer::check_demo_mode() == 0) {
        if (TBoss6PlotFalz::is_boss_active() == 0) {
            owner = NULL;
            queue_destruction();
            return;
        }
        VecCopy(&prev_position, &position);
        {
            void (TBoss6Mag::*update)() = boss6_type2_action_table[action].update;
            if (update) {
                (this->*update)();
            }
        }
        update_rotation_ramp();
        update_motion_playback();
        save_position();
        if (attackable != 0) {
            update_collisions();
            submit_cursor_candidate(this, -1);
        }
        TBoss6Rock::break_rocks_in_radius(&position, 10.0f);
        marker_color = 0xFF7F5126;
        if (attackable != 0) {
            marker_color = -0x5DB4;
        }
        add_radar_scaled_marker(&position, marker_color, 1, 1, 2.0f);
        decay_glow_and_calc_hp_ratio();
        sync_hp_apply_damage();
        spawn_trap_by_stat();
        update_state_effects();
        update_effect_positions();
        frame_counter = frame_counter + 1;
    }
}

void TBoss6Mag::render() { render_body_effects(); }

void TBoss6Mag::spawn_trap_by_stat() {
    s32 sound_id;

    sound_id = 0x4006C919;
    if (ramp.aim > 0.0f) {
        sound_id = 0x6B015;
        if (ramp.charge > 0.0f) {
            sound_id = 0x6B518;
        }
    }
    play_persistent_sound(sound_id, this, &position, 0, 0);
}

void TBoss6Mag::render_body_effects() {
    f32 flash;
    f32 fade_amount;
    s32 tinted;
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    flash = hit_flash;
    tinted = 0;
    if (flash > 0.0f) {
        TBoss6PlotFalz__sub_802AC008(flash, hp_ratio);
        tinted = 1;
    } else {
        fade_amount = fade;
        if (fade_amount > 0.0f) {
            TBoss6PlotFalz::apply_fade_material_color(fade_amount, 0.5f, 0.5f, 0.5f);
            tinted = 1;
        }
    }
    draw_model_motion_blend();
    if (tinted != 0) {
        TBoss6PlotFalz::update_camera_target();
    }
    pop_matrix();
    TParticleCtrl::end_effect_render();
}

void TBoss6Mag::save_position() {
    VecCopy(&body_center, &position);
}

void TBoss6Mag::run_hit_reaction() {
    hit_flash = 1.0f;
    actorFlags &= 0xFFFFFDFF;
    play_sound_effect(0x6A816, &position, 0, 0);
    ramp.charge = 0.0f;
}

void TBoss6Mag::run_death_reaction() {
    switch (action) {
    case 3:
    case 4:
    case 5:
        return;
    default:
        owner->on_mag_dead();
        hit_flash = 1.0f;
        set_action(4);
        play_sound_effect(0x69E17, &position, 0, 0);
        break;
    }
}

f32 TBoss6Mag::receive_physical_attack(void *attacker, f32 scale) {
    if (attackable != 0) {
        return TObjChara::receive_physical_attack(attacker, scale);
    }
    return 0.0f;
}

f32 TBoss6Mag::receive_direct_attack(void *attacker, DirectAttackPayload payload, void *collision, s32 tech, s32 flags) {
    while (attackable == 0) {
        if (payload.kind != 0x14 && TObjEneDD::query_teammate_state() == 0) {
            return 0.0f;
        }
        break;
    }
    return TObjChara::receive_direct_attack(attacker, payload, collision, tech, flags);
}

void TBoss6Mag::set_action(s32 action) {
    void (TBoss6Mag::*enter)();
    TBoss6MagAction *entry;
    this->action = action;
    entry = &boss6_type2_action_table[this->action];
    change_motion(entry->motion);
    attackable = entry->attackable;
    enter = entry->enter;
    if (enter != NULL) {
        (this->*enter)();
    }
}

TBoss6MagMotion *TBoss6MagMotion::copy_from(const TBoss6MagMotion *src) {
    TBoss6MagMotionWords *d = (TBoss6MagMotionWords *)this;
    const TBoss6MagMotionWords *s = (const TBoss6MagMotionWords *)src;
    d->index = s->index;
    d->mode = s->mode;
    d->track = s->track;
    return this;
}

void TBoss6MagMotionTrack::copy_state(TBoss6MagMotionTrack *src) {
    motion = src->motion;
    frame = src->frame;
    speed = src->speed;
    blend = src->blend;
    blend_step = src->blend_step;
    prev_motion = src->prev_motion;
    prev_frame = src->prev_frame;
}

void TBoss6Mag::init_motion_state() {
    AnimationMotion *bml_motion;
    motion_state.copy_from(&boss6_type2_zero_vec3_block);
    motion_state.track.copy_state((TBoss6MagMotionTrack *)&boss6_type2_initial_state);
    bml_motion = get_bml_motion(scene_archive, boss6_type2_motion_table[0].motion);
    motion_state.track.prev_motion = bml_motion;
    motion_state.track.motion = bml_motion;
    motion_state.track.speed = boss6_type2_motion_table[0].speed;
}

void TBoss6Mag::update_motion_playback() {
    f32 n;
    f32 lim;

    n = (f32)motion_state.track.motion->frameCount;
    motion_state.track.frame += motion_state.track.speed;
    switch (motion_state.mode) {
    case 0:
        if (motion_state.track.frame >= n) {
            motion_state.track.frame -= n;
        }
        break;
    case 1:
        break;
    case 2:
        lim = n - 1.0f;
        if (motion_state.track.frame >= lim) {
            motion_state.track.frame = lim;
            change_motion(boss6_type2_motion_table[motion_state.index].next);
        }
        break;
    }
    if (0.0f != motion_state.track.blend) {
        if ((motion_state.track.blend += motion_state.track.blend_step) >= 1.0f) {
            motion_state.track.blend = 0.0f;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Mag::change_motion(s32 motion) {
    s32 row;
    AnimationMotion *bml_motion;
    if ((motion != -1) && (motion != motion_state.index)) {
        motion_state.index = motion;
        row = motion * sizeof(TBoss6MagMotionEntry);
        motion_state.mode = ((TBoss6MagMotionEntry *)((u8 *)boss6_type2_motion_table + row))->mode;
        bml_motion = get_bml_motion(scene_archive, ((TBoss6MagMotionEntry *)((u8 *)boss6_type2_motion_table + row))->motion);
        motion_state.track.blend = motion_state.track.blend_step;
        motion_state.track.prev_motion = motion_state.track.motion;
        motion_state.track.prev_frame = motion_state.track.frame;
        motion_state.track.speed = ((TBoss6MagMotionEntry *)((u8 *)boss6_type2_motion_table + row))->speed;
        motion_state.track.motion = bml_motion;
        motion_state.track.frame = 0.0f;
    }
}
#pragma pop

void TBoss6Mag::draw_model_motion_blend() {
    TBoss6MagMotionBlend blend;
    NJS_TEXLIST *texlist;
    NJS_OBJECT *model;
    set_motion_packed_rotation();
    texlist = get_bml_texlist(scene_archive, 1);
    model = get_bml_model(scene_archive, 1);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    if (0.0f == motion_state.track.blend) {
        capture->install();
        draw_model_motion(model, motion_state.track.motion, motion_state.track.frame);
        capture->clear();
    } else {
        blend.from = motion_state.track.prev_motion;
        blend.from_frame = motion_state.track.prev_frame;
        blend.to = motion_state.track.motion;
        blend.to_frame = motion_state.track.frame;
        capture->install();
        draw_model_blend_motion(model, &blend, motion_state.track.blend);
        capture->clear();
    }
    clear_motion_packed_rotation();
}

void TBoss6Mag::sync_hp() {
    synced_hp = hp;
}

void TBoss6Mag::sync_hp_apply_damage() {
    s16 current;
    s32 synced;
    synced = synced_hp;
    current = hp;
    if (synced != current) {
        if (synced < current) {
            sync_hp();
            return;
        }
        owner->apply_damage(synced - current);
        synced_hp = hp;
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Mag::decay_glow_and_calc_hp_ratio() {
    hit_flash += -0.06666667f;
    if (hit_flash < 0.0f) {
        hit_flash = 0.0f;
    }
    hp_ratio = (f32)hp / (f32)referenceHp;
}
#pragma pop

void TBoss6Mag::init_segment_angle_range() {
    ActorParamBlock *params = param_block;
    s32 lo;
    s32 hi;
    hi = params->values[1];
    lo = hi;
    if (lo > params->values[2]) {
        lo = params->values[2];
    } else if (hi < params->values[2]) {
        hi = params->values[2];
    }
    if (lo > params->values[3]) {
        lo = params->values[3];
    } else if (hi < params->values[3]) {
        hi = params->values[3];
    }
    if (lo > params->values[4]) {
        lo = params->values[4];
    } else if (hi < params->values[4]) {
        hi = params->values[4];
    }
    if (lo > params->values[5]) {
        lo = params->values[5];
    } else if (hi < params->values[5]) {
        hi = params->values[5];
    }
    value_min = lo;
    value_max = hi;
    ((TLobby *)&param_copy)->copy_entry(param_block);
    param_block = &param_copy;
    update_segment_angles();
}

void TBoss6Mag::update_segment_angles() {
    s16 value;
    value = value_max;
    param_copy.values[5] = value;
    param_copy.values[4] = value;
    param_copy.values[3] = value;
    param_copy.values[2] = value;
    param_copy.values[1] = value;
    switch (segment_variant) {
    case 1:
        param_copy.values[1] = value_min;
        break;
    case 2:
        param_copy.values[2] = value_min;
        break;
    case 3:
        param_copy.values[3] = value_min;
        break;
    case 4:
        param_copy.values[4] = value_min;
        break;
    case 5:
        param_copy.values[5] = value_min;
        break;
    }
    m_2f2 = param_copy.values[1];
    m_2f4 = param_copy.values[3];
    m_2f6 = param_copy.values[2];
    m_2f8 = param_copy.values[5];
    m_2fa = param_copy.values[4];
}

s32 TBoss6Mag::snap_to_shoulder() {
    Vec v;
    s32 t;
    if (owner == NULL) {
        return 0;
    }
    owner->get_shoulder_point(index, &v, &t);
    v.y += 35.0f;
    VecCopy(&position, &v);
    rotation_y = t;
    return 1;
}

#pragma push
#pragma fp_contract on
s32 TBoss6Mag::fly_toward_target() {
    Vec tgt;
    Vec d;
    Vec h;
    Vec a;
    Vec r;
    s32 t;
    s32 rx;
    s32 ry;
    f32 len;
    if (owner == NULL) {
        return 0;
    }
    owner->get_shoulder_point(index, &tgt, &t);
    tgt.y += 35.0f;
    VecCopy(&d, &tgt);
    subtract_vector(&d, &position);
    if (!(vector_length(&d) > 30.0f)) {
        d.x *= 0.25f;
        d.y *= 0.25f;
        d.z *= 0.25f;
        if (vector_length(&d) > 4.4444447f) {
            normalize_vector(&d);
            d.x *= 4.4444447f;
            d.y *= 4.4444447f;
            d.z *= 4.4444447f;
        }
        vec3_add_to(&position, &d);
        rotation_y = step_angle_toward(rotation_y, t, 0x5B0);
        rotation_x = approach_angle_limited(rotation_x, 0, 0x5B0);
        return 1;
    }
    VecCopy(&h, &d);
    h.y = 0.0f;
    len = vector_length(&h);
    if (!(len < 100.0f)) {
        f32 dy;
        rotation_y = step_angle_toward(rotation_y, (s32)((10430.38043493439) * atan2_float(d.x, d.z)), 0x5B0);
        rotation_x = approach_angle_limited(rotation_x, 0, 0x5B0);
        VecCopy(&a, &position);
        a.x += 4.4444447f * sin_table_lookup(rotation_y);
        a.z += 4.4444447f * cos_table_lookup(rotation_y);
        if (project_actor_to_ground(this, &a, 0) == 0) {
            position.x = a.x;
            position.z = a.z;
            return 0;
        }
        a.y += 50.0f;
        position.x = a.x;
        position.z = a.z;
        dy = 0.25f * (a.y - position.y);
        if (dy < -4.4444447f) {
            dy = -4.4444447f;
        } else if (dy > 4.4444447f) {
            dy = 4.4444447f;
        }
        position.y += dy;
        return 0;
    }
    if (len < 10.0f) {
        s32 ang;
        rotation_y = step_angle_toward(rotation_y, t, 0x5B0);
        ang = 0x7FFF;
        if (tgt.y > position.y) {
            ang *= -1;
        }
        rotation_x = approach_angle_limited(rotation_x, ang, 0x5B0);
    } else {
        calc_dir_angles(&rx, &ry, &d);
        rotation_y = step_angle_toward(rotation_y, rx, 0x5B0);
        rotation_x = approach_angle_limited(rotation_x, ry, 0x5B0);
    }
    compute_random_dir_vec(&r, rotation_y, rotation_x);
    r.x *= 4.4444447f;
    r.y *= 4.4444447f;
    r.z *= 4.4444447f;
    vec3_add_to(&position, &r);
    return 0;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss6Mag::turn_toward_target() {
    Vec v;
    s32 yaw;
    s32 pitch;
    s32 turn;
    TObjPlayer *player;
    u16 id;
    player = NULL;
    id = chase_target.client_id;
    if (id != 0xFFFF) {
        player = get_player_by_client_id(id);
    }
    if (player == NULL) {
        if (owner == NULL) {
            VecCopy(&v, &home_position);
        } else {
            s32 ang;
            ang = (s32)(12288.0f * apply_direction_sign(1.0f) + (f32)owner->rotation_y);
            VecCopy(&v, &owner->position);
            v.x += 50.0f * sin_table_lookup(ang);
            v.z += 50.0f * cos_table_lookup(ang);
        }
        v.y = 30.0f;
    } else {
        VecCopy(&v, &player->position);
        v.y = 30.0f;
    }
    if (project_actor_to_ground(this, &v, 0) != 0) {
        v.y += 30.0f;
    }
    subtract_vector(&v, &position);
    turn = 0x1B4;
    if (owner->get_state() == 0xE) {
        turn = 0x6D0;
    }
    calc_dir_angles(&yaw, &pitch, &v);
    rotation_y = step_angle_toward(rotation_y, yaw, turn);
    rotation_x = approach_angle_limited(rotation_x, pitch, 0x1B4);
}
#pragma pop

void TBoss6Mag::apply_random_drift() {
    Vec v;
    f32 k;
    compute_random_dir_vec(&v, rotation_y, rotation_x);
    k = 1.3333334f;
    if (owner->get_state() == 0xE) {
        k *= chase_speed_scale;
    }
    v.x = v.x * k;
    v.y = v.y * k;
    v.z = v.z * k;
    vec3_add_to(&position, &v);
}

void TBoss6Mag::revive() {
    actorFlags &= ~0xA00;
    hp = initial_hp;
    sync_hp();
}

#pragma push
#pragma fp_contract on
void TBoss6Mag::spawn_falling_rocks() {
    Vec pts[3];
    Vec *p;
    s32 i;
    s32 ang;
    f32 r;
    for (i = 0; i < 3; i++) {
        ang = rotation_y + boss6_mag_rock_spread_angles[i] + (s32)(4096.0f * (0.5f - 3.0517578e-05f * (f32)rand()));
        r = 40.0f * (3.0517578e-05f * (f32)rand()) + 80.0f;
        p = &pts[i];
        VecCopy(p, &node_positions[0]);
        p->x = r * sin_table_lookup(ang) + p->x;
        p->y = 0.0f;
        p->z = r * cos_table_lookup(ang) + p->z;
        TBoss6Rock::push_out_of_rocks(p, 10.0f);
    }
    TBoss6Type2::send_6xAD_grid_positions(index, (saddr)pts, 3);
}
#pragma pop

void TBoss6Mag::set_path_points_by_index(s32 index, Vec *points, s32 count) {
    TBoss6Mag *mag = TBoss6Type2__instance_slots[index];
    if (mag != NULL) {
        mag->set_path_points(points, count);
    }
}

void TBoss6Mag::set_path_points(Vec *points, s32 count) {
    s32 i;
    s32 n = count;
    mines_spawned = 0;
    if (n > 3) {
        n = 3;
    }
    for (i = 0; i < n; i++) {
        VecCopy(&mine_targets[i], &points[i]);
    }
    mine_count = n;
    set_action(3);
}

void TBoss6Mag::spawn_mag_mines() {
    const Vec *origin = &node_positions[0];
    s32 i;
    for (i = 0; i < mine_count; i++) {
        TBoss6MagMine::spawn_mag_mine_at(origin, &mine_targets[i]);
    }
}

void copy_mag_ramp(TBoss6MagRamp *dst, TBoss6MagRamp *src) {
    dst->aim = src->aim;
    dst->charge = src->charge;
}

void TBoss6Mag::init_with_global_table() {
    copy_mag_ramp(&ramp, (TBoss6MagRamp *)&boss6_mag_zero_ramp);
}

void TBoss6Mag::update_rotation_ramp() {
    if ((is_action_ready() == 0) || (is_target_in_front_range() == 0)) {
        ramp.charge = 0.0f;
        ramp.aim += -0.06666667f;
        if (ramp.aim < 0.0f) {
            ramp.aim = 0.0f;
        }
    } else if (1.0f == ramp.aim) {
        ramp.charge += 0.033333335f;
        if (ramp.charge > 1.0f) {
            ramp.charge = 1.0f;
        }
        if (1.0f == ramp.charge) {
            if (is_local_client_floor_leader() != 0) {
                if (owner != NULL) {
                    if (owner->get_rotation_timer() == 0) {
                        spawn_falling_rocks();
                    }
                }
            }
            ramp.aim = 0.0f;
            ramp.charge = 0.0f;
        }
    } else {
        ramp.charge = 0.0f;
        ramp.aim += 0.06666667f;
        if (ramp.aim > 1.0f) {
            ramp.aim = 1.0f;
        }
    }
}

s32 TBoss6Mag::is_action_ready() {
    if (action == 2 && chase_target.client_id != 0xFFFF && position.y <= 75.0f) {
        return 1;
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 TBoss6Mag::is_target_in_front_range() {
    TObjPlayer *player = NULL;
    if (chase_target.client_id != 0xFFFF) {
        player = get_player_by_client_id(chase_target.client_id);
    }
    if (player == NULL) {
        return 0;
    }
    Vec a;
    VecCopy(&a, &player->position);
    a.y = 0.0f;
    Vec b = node_positions[0];
    if (0.0f == ramp.aim) {
        if (angle_difference_abs(rotation_y, (s32)((10430.38043493439) * atan2_float(a.x - b.x, a.z - b.z))) > 0x2000) {
            return 0;
        }
    }
    Vec c;
    VecCopy(&c, &b);
    c.x += 90.0f * sin_table_lookup(rotation_y);
    c.y = 0.0f;
    c.z += 90.0f * cos_table_lookup(rotation_y);
    if (xyz_distance(&c, &a) <= 100.0f) {
        return 1;
    }
    return 0;
}
#pragma pop

s32 TBoss6Mag::calc_dir_angles(s32 *yaw, s32 *pitch, Vec *dir) {
    Vec v;
    VecCopy(&v, dir);
    if (vector_length(&v) <= 1e-05f) {
        return 0;
    }
    normalize_vector(&v);
    if (v.y < -0.99999f) {
        *yaw = 0;
        *pitch = 0x7FFF;
        return 1;
    }
    if (v.y > 0.99999f) {
        *yaw = 0;
        *pitch = -0x7FFF;
        return 1;
    }
    *yaw = (10430.38043493439) * atan2_float(v.x, v.z);
    *pitch = (10430.38043493439) * asinf(-v.y);
    return 1;
}

void TBoss6Mag::compute_random_dir_vec(Vec *out, s32 yaw, s32 pitch) {
    f32 y;
    f32 radius;

    y = -sin_table_lookup(pitch);
    radius = 1.0f - fabs_float(y);
    out->x = radius * sin_table_lookup(yaw);
    out->y = y;
    out->z = radius * cos_table_lookup(yaw);
}

void TBoss6Mag::push_out_from_target() {
    Vec b;
    Vec a;
    Vec c;
    Vec d;
    f32 dist;
    f32 len;
    if (owner == NULL) {
        return;
    }
    owner->copy_pos_59c(&a);
    VecCopy(&b, &position);
    subtract_vector(&b, &a);
    len = vector_length(&b);
    if (len >= 50.0f) {
        return;
    }
    if (len <= 1e-05f) {
        b.x = 1.0f;
    }
    normalize_vector(&b);
    b.x *= 50.0f;
    b.y *= 50.0f;
    b.z *= 50.0f;
    vec3_add_to(&b, &a);
    VecCopy(&c, &position);
    subtract_vector(&c, &prev_position);
    dist = vector_length(&c);
    VecCopy(&d, &b);
    subtract_vector(&d, &prev_position);
    len = vector_length(&d);
    if (dist <= 1e-05f || len <= 1e-05f) {
        VecCopy(&position, &b);
        return;
    }
    normalize_vector(&c);
    normalize_vector(&d);
    vec3_add_to(&d, &c);
    if (vector_length(&d) <= 1e-05f) {
        VecCopy(&position, &b);
        return;
    }
    normalize_vector(&d);
    d.x *= dist;
    d.y *= dist;
    d.z *= dist;
    vec3_add_to(&d, &prev_position);
    VecCopy(&position, &d);
}

void TBoss6Mag::push_out_from_points() {
    Vec v;
    Vec pts[2];
    s32 i;
    f32 len;
    f32 f;
    if (owner != NULL) {
        owner->get_push_points(&pts[0], &pts[1]);
        for (i = 0; i < 2; i++) {
            VecCopy(&v, &pts[i]);
            subtract_vector(&v, &position);
            if (v.y < 0.0f || v.y > 50.0f) {
                continue;
            }
            v.y = 0.0f;
            len = vector_length(&v);
            if (len > 50.0f) {
                continue;
            }
            if (len <= 0.00001f) {
                v.x = 1.0f;
            }
            normalize_vector(&v);
            f = 50.0f - len;
            if (f > 1.0f) {
                f *= 0.25f;
            }
            v.x *= f;
            v.z *= f;
            subtract_vector(&position, &v);
        }
    }
}

void TBoss6Mag::enforce_min_distance() {
    Vec offset;
    f32 len;
    if (partner != NULL) {
        VecCopy(&offset, &position);
        subtract_vector(&offset, &partner->position);
        len = vector_length(&offset);
        if (!(len >= 40.0f)) {
            if (len <= 1e-05f) {
                offset.x = apply_direction_sign(1.0f);
            }
            normalize_vector(&offset);
            offset.x *= 40.0f;
            offset.y = 0.0f;
            offset.z *= 40.0f;
            vec3_add_to(&offset, &partner->position);
            VecCopy(&position, &offset);
        }
    }
}

f32 TBoss6Mag::apply_direction_sign(f32 value) {
    if (index != 0) {
        return -value;
    }
    return value;
}

s32 TBoss6Mag::apply_direction_sign(s32 turn) {
    if (index == 0) {
        return turn;
    }
    return -turn;
}

s32 TBoss6Mag::step_angle_toward(s32 from, s32 to, s32 turn) {
    s32 next;
    apply_direction_sign(turn);
    if (angle_difference_abs(to, from) <= turn) {
        return to;
    }
    next = from + apply_direction_sign(turn);
    if (angle_difference_abs(to, next) <= turn) {
        return to;
    }
    return next;
}

void TBoss6Mag::clear_particle_emitters() {
    s32 i;
    for (i = 0; i < 4; i++) {
        emitters[i] = NULL;
    }
}

void TBoss6Mag::update_all_parts() {
    s32 i;
    i = 0;
    do {
        destroy_part_object(i);
        i += 1;
    } while (i < 4);
}

void TBoss6Mag::update_state_effects() {
    switch (owner->get_state()) {
    case 14:
    case 24:
    case 25:
    case 26:
        if (is_phase_active() != 0) {
            ensure_particle_emitter(1);
        } else {
            destroy_part_object(1);
        }
        destroy_part_object(2);
        break;
    case 5:
    case 9:
    case 10:
    case 11:
        destroy_part_object(1);
        ensure_particle_emitter(2);
        break;
    default:
        destroy_part_object(1);
        destroy_part_object(2);
        break;
    }
    if (!(frame_counter & 0x1F) && owner->is_active() != 0) {
        spawn_particle_effect_with_flags(&position, 0x224, 0x2040);
    }
}

void TBoss6Mag::update_effect_positions() {
    s32 i;
    const TBoss6MagEmitter *table = TBoss6Type2__effect_emitter_id_table;
    for (i = 0; i < 4; i++) {
        Vec pos = position;
        const TBoss6MagEmitter *entry = &table[i];
        if (emitters[i] != NULL) {
            if (entry->node >= 0) {
                VecCopy(&pos, &node_positions[entry->node]);
            }
            emitters[i]->set_position(&pos);
        }
    }
}

void TBoss6Mag::ensure_particle_emitter(s32 index) {
    if (emitters[index] == NULL) {
        Vec pos = position;
        emitters[index] = create_particle_emitter(&pos, TBoss6Type2__effect_emitter_id_table[index].effect_id);
        if (emitters[index] != NULL) {
            emitters[index]->set_flags(0x40);
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss6Mag::destroy_part_object(s32 index) {
    u8 *base = (u8 *)this + index * 4;
    TParticleCtrl *emitter = *(TParticleCtrl **)(base + offsetof(TBoss6Mag, emitters));
    if (emitter != NULL) {
        TParticleCtrl::release(emitter);
        *(TParticleCtrl **)(base + offsetof(TBoss6Mag, emitters)) = NULL;
    }
}
#pragma pop

s32 TBoss6Mag::is_phase_active() {
    switch (action) {
    case 4:
    case 5:
        return 0;
    }
    return 1;
}

void TBoss6Mag::set_anim_frame(TBoss6Mag *partner) { this->partner = partner; }

void TBoss6Mag::set_target_nodes(u32 flags, s32 variant) { target_attribute_mask = flags; segment_variant = variant; update_segment_angles(); }

void TBoss6Mag::set_action_field_0x408(u16 client_id) { chase_target.client_id = client_id; }

void TBoss6Mag::set_on_shoulder(s32 on_shoulder) { chase_target.on_shoulder = on_shoulder; }
