#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/boss/olgaflow/TBoss6Mine.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/ui/hud/TNowLoading.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/AngleLookup.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/math/InverseTrig.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma readonly_strings on
// The record exchange_object_state reads and writes.
struct TBoss6MineStateRecord { s32 flags; s16 pad_04; s16 value; s32 pad_08; };

static CollisionBody TBoss6Mine__collision_body_template[1] = {
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x801B, {0.0f, 0.0f, 0.0f}, 0.0f},
};

extern "C" {
const char *lbl_805D4178 = "TBoss6Mine";

void TBoss6Mine::render_shadows() {
    if (position.y >= 0.0f) {
        TObjEnemy::render_shadows();
    }
}

void TBoss6Mine::run_death_reaction() {
    if (this->state != 7) {
        this->state = 7;
    }
}

void TBoss6Mine::run_hit_reaction() { this->actorFlags = (this->actorFlags & 0xfffffdff); this->fade_amount = 1.0f; }

void TBoss6Mine::copy_pos() {
    VecCopy(&body_center, &position);
}

void TBoss6Mine::draw() {
    s32 texlist;
    AnimationMotion *bml_motion;
    saddr bml_model;

    set_motion_packed_rotation();
    texlist = (saddr)get_bml_texlist(scene_archive, 2);
    bml_model = (saddr)get_bml_model(scene_archive, 2);
    bml_motion = get_bml_motion(scene_archive, 0);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    TBoss6PlotFalz__sub_802AC008(this->fade_amount, 0.0f);
    draw_model_motion((void *)bml_model, (void *)bml_motion, this->anim_frame);
    TBoss6PlotFalz::update_camera_target();
    clear_motion_packed_rotation();
}

void TBoss6Mine::render() {
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, yaw);
    rotate_matrix_x(NULL, pitch);
    rotate_matrix_y(NULL, spin);
    draw();
    pop_matrix();
}

void TBoss6Mine::update_facing_angles() {
    Vec v;
    s32 a;
    s32 b;
    switch (this->state) {
    case 5:
    case 6:
        VecCopy(&v, &position);
        subtract_vector(&v, &prev_position);
        if (vector_length(&v) <= 0.00001f) {
            a = 0;
            b = 0;
        } else {
            normalize_vector(&v);
            a = (10430.38043493439) * atan2_float(-v.x, -v.z);
            b = (10430.38043493439) * asinf(v.y);
            if (b < -0x2000) {
                b = -0x2000;
            } else if (b > 0x2000) {
                b = 0x2000;
            }
        }
        yaw = approach_angle_limited(yaw, a, 0x1111);
        pitch = approach_angle_limited(pitch, b, 0x444);
        spin += 0x888;
        break;
    }
}

s32 TBoss6Mine::is_far_from_origin() {
    return vector_length(&position) > 500.0f;
}

void TBoss6Mine::explode_damage_players() {
    s32 count = TLobby::get_game_mode();
    for (s32 i = 0; i < count; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0) {
            Vec v = position;
            subtract_vector(&v, &player->position);
            v.y = 0.0f;
            if (!(vector_length(&v) > 22.5f)) {
                DirectAttackPayload h;
                s32 damage = TBoss6PlotFalz::rand_vary_count(this->damage, 0.1f);
                h.kind = 1;
                h.power = damage;
                player->receive_direct_attack(this, h, 0, -1, -1);
            }
        }
    }
    play_sound_effect(0x4003BA1E, &this->position, 0, 0);
}

void TBoss6Mine::state_7() {
    spawn_particle_effect_with_flags(&this->position, 0xFC, 0x40);
    queue_destruction();
}

void TBoss6Mine::state_6() {
    explode_damage_players();
    spawn_particle_effect_with_flags(&this->position, 0xFB, 0x40);
    spawn_particle_effect_with_flags(&this->position, 0xFC, 0x40);
    TBoss6PlotFalz::apply_radial_effect_to_players(&this->position, (s16)0xC0, (s16)0xF, 100.0f);
    queue_destruction();
}

#pragma push
#pragma opt_common_subs off
void TBoss6Mine::state_5() {
    Vec step;
    Vec ground;
    f32 ground_y;
    VecCopy(&step, &this->target_pos);
    subtract_vector(&step, &this->position);
    if (vector_length(&step) <= 8.333333f) {
        this->state_frames = 0;
        this->state = 6;
        return;
    }
    normalize_vector(&step);
    step.x *= 8.333333f;
    step.y *= 8.333333f;
    step.z *= 8.333333f;
    vec3_add_to(&this->position, &step);
    VecCopy(&ground, &this->position);
    ground_y = ground.y - 10.0f;
    ground.y = ground_y;
    if ((project_actor_to_ground(this, &ground, 0) != 0) && (ground_y < ground.y)) {
        ground.y += 10.0f;
        VecCopy(&this->position, &ground);
        this->state_frames = 0;
        this->state = 6;
    }
}
#pragma pop

void TBoss6Mine::state_4() {
    s32 frames = this->state_frames + 1;
    this->state_frames = frames;
    if (frames > (s32)this->arm_delay) {
        this->state_frames = 0;
        this->state = 5;
        play_sound_effect(0x4003B51D, &this->position, 0, 0);
    }
}

void TBoss6Mine::state_3() {
    Vec v;
    f32 len;
    f32 remaining;
    f32 radius;
    remaining = (f32)((s32)this->spread_frames - this->state_frames + 1);
    VecCopy((Vec *)&v, &this->position);
    v.y = 0.0f;
    len = vector_length(&v);
    if (len > 0.00001f) {
        normalize_vector(&v);
    }
    radius = len + (120.0f - len) / remaining;
    this->position.x = radius * v.x;
    this->position.z = radius * v.z;
    this->anim_frame += 0.8333334f;
    if (this->anim_frame >= 9.0f) {
        this->anim_frame = 9.0f;
    }
    if (++this->state_frames > (s32)this->spread_frames) {
        this->state_frames = 0;
        this->state = 4;
    }
}

void TBoss6Mine::state_2() {
    this->anim_frame += 0.33333334f;
    if (this->anim_frame >= 10.0f) {
        this->anim_frame -= 10.0f;
    }
    this->position.y += 0.6944444f;
    if (this->position.y >= 75.0f) {
        this->position.y = 75.0f;
        this->state_frames = 0;
        this->state = 3;
    }
    play_persistent_sound(0x4003B21C, this, &this->position, 0, 0);
}

void TBoss6Mine::state_1() {
    s32 frames = this->state_frames + 1;
    this->state_frames = frames;
    if (frames > (s32)this->rise_delay) {
        this->state_frames = 0;
        this->state = 2;
    }
}

#pragma push
#pragma fp_contract on
void TBoss6Mine::state_0() {
    f32 step;
    f32 height;
    s32 frames;
    s32 left;
    frames = this->state_frames;
    step = this->travel_distance / 30.0f;
    if (frames > 0xF) {
        left = 0x1E - frames;
        if (left > 0) {
            height = this->start_pos.y;
            this->start_pos.y = (f32)(height + ((-50.0f - height) / (f32)left));
        }
    }
    this->position.x = (f32)((step * sin_table_lookup(this->heading)) + this->position.x);
    this->position.z = (f32)((step * cos_table_lookup(this->heading)) + this->position.z);
    this->position.y = (f32)((-100.0f * sin_table_lookup((s32)(this->state_frames << 0xF) / 30)) + this->start_pos.y);
    frames = this->state_frames + 1;
    this->state_frames = frames;
    if (frames > 0x1E) {
        this->state_frames = 0;
        this->state = 1;
    }
}
#pragma pop


void TBoss6Mine::run_task() {
    u32 color;
    if (TObjPlayer::check_demo_mode() != 0) {
        return;
    }
    if (TBoss6PlotFalz::is_type1_active() == 0) {
        this->owner = NULL;
        queue_destruction();
        return;
    }
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    VecCopy(&this->prev_position, &this->position);
    static void (TBoss6Mine::*const handlers[8])() = {
        &TBoss6Mine::state_0, &TBoss6Mine::state_1, &TBoss6Mine::state_2, &TBoss6Mine::state_3,
        &TBoss6Mine::state_4, &TBoss6Mine::state_5, &TBoss6Mine::state_6, &TBoss6Mine::state_7,
    };
    void (TBoss6Mine::*handler)() = handlers[this->state];
    if (handler != 0) {
        (this->*handler)();
    }
    copy_pos();
    if (this->state == 2) {
        update_collisions();
        submit_cursor_candidate(this, -1);
    }
    color = 0xFF7F5126;
    if (this->state == 2) {
        color = 0xFFFFA24C;
    }
    add_radar_scaled_marker(&this->position, color, 1, 1, 1.0f);
    update_facing_angles();
    this->fade_amount += -0.06666667f;
    if (this->fade_amount < 0.0f) {
        this->fade_amount = 0.0f;
    }
    if (this->emitter != 0) {
        this->emitter->set_position(&this->position);
    }
    if (is_far_from_origin() != 0) {
        queue_destruction();
    }
}

}
TBoss6Mine::~TBoss6Mine() {
    if (this->emitter != NULL) { TParticleCtrl::release(this->emitter); this->emitter = 0; }
    free_collision_body_parts(this);
    if (this->owner != NULL) { this->owner->tick_timer(); }
}


extern saddr tl_04;

#pragma push
#pragma fp_contract on
TBoss6Mine::TBoss6Mine(TObject *parent, TBoss6MineSetData *set_data) : TObjEnemy(parent) {
    TBoss6MineStateRecord record;
    f32 f;
    m_name = lbl_805D4178;
    owner = set_data->owner;
    VecCopy(&position, &set_data->origin);
    VecCopy(&target_pos, &set_data->offset);
    heading = set_data->heading;
    seed = set_data->seed;
    add_flags_2e4(8);
    apply_set_data(set_data);
    if (exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.value = 0;
        exchange_object_state(&record, 0);
    }
    scene_archive = TBoss6PlotFalz::get_scene_archive();
    texlist = 0;
    model = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    init_collision_body_parts(this, TBoss6Mine__collision_body_template, 1);
    VecCopy(&body_center, &position);
    velocity.z = 0.0f;
    velocity.y = 0.0f;
    velocity.x = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x2D), TLobby::dispatch_shared_handler_b(0x2D), TLobby::register_object(0x2D));
    referenceHp = hp;
    register_by_id();
    set_param(0);
    rise_delay = (s32)(136.0f * next_random_float(&seed) + 7.0f);
    spread_frames = 0x96 - rise_delay;
    arm_delay = (s32)(57.0f * next_random_float(&seed) + 3.0f);
    travel_distance = 80.0f * next_random_float(&seed) + 120.0f;
    f = TLobby::dispatch_shared_handler_a(0x2D)->values.floats[0];
    damage = f;
    if (0.0f == f) {
        damage = 0x14;
    }
    fade_amount = 0.0f;
    VecCopy(&start_pos, &position);
    anim_frame = 1.0f;
    yaw = 0;
    pitch = 0;
    spin = 0;
    state_frames = 0;
    state = 0;
    emitter = create_particle_emitter(&position, 0x146);
    if (emitter != NULL) {
        emitter->set_flags(0x40);
    }
}
#pragma pop

TBoss6Mine *TBoss6Mine::create(TBoss6MineSetData *set_data) {
    return new TBoss6Mine(new TObjControl((TObject *)tl_04), set_data);
}


f32 asinf(f32 x) {
    return asin(x);
}
