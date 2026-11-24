#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/BmlResource.h"
#include "pso/boss/olgaflow/TBoss6MagMine.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"

#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801542CC.h"

#pragma readonly_strings on
// The record exchange_object_state reads and writes.
struct TBoss6MagMineStateRecord {
    s32 flags;
    s16 pad_04;
    s16 value;
    s32 pad_08;
};

CollisionBody TBoss6MagMine__collision_body_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x803B, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *TBoss6MagMine__class_name = "TBoss6MagMine";

void TBoss6MagMine::run_death_reaction() {
    if (state != 4) {
        state = 4;
    }
}

void TBoss6MagMine::run_hit_reaction() {
    actorFlags = actorFlags & 0xFFFFFDFF;
    hit_flash = 1.0f;
}

void TBoss6MagMine::copy_pos() {
    VecCopy(&body_center, &position);
}

void TBoss6MagMine::update_linked_state() {
    s32 textures;
    AnimationMotion *motion;
    saddr model;

    set_motion_packed_rotation();
    textures = (saddr)get_bml_texlist(archive, 2);
    model = (saddr)get_bml_model(archive, 2);
    motion = get_bml_motion(archive, 0);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(textures));
    TBoss6PlotFalz__sub_802AC008(hit_flash, 0.0f);
    draw_model_motion((void *)model, (void *)motion, motion_frame);
    TBoss6PlotFalz::update_camera_target();
    clear_motion_packed_rotation();
}

void TBoss6MagMine::render() { push_matrix(); post_translate_matrix(&position.x); rotate_matrix_y(NULL, angle_y); update_linked_state(); pop_matrix(); }

void TBoss6MagMine::damage_player(TObjPlayer *player) {
    DirectAttackPayload attack;
    s32 variant;
    s32 power;
    s32 status;
    TBoss6Type2 *type2;
    status = 0;
    if ((status_count < status_chance) && (TBoss6PlotFalz::get_hp() != 0U) && ((type2 = TBoss6PlotFalz::get_type2()) != NULL)) {
        variant = type2->get_variant();
        switch (variant) {
        case 2:
        case 3:
            status = variant;
            break;
        case 4:
            status = 0x12;
            break;
        }
    }
    switch (status) {
    case 2:
        player->apply_movement_ailment(0);
        return;
    case 3:
        player->apply_shock_status();
        return;
    case 18:
        player->apply_confusion_status();
        return;
    default:
        power = TBoss6PlotFalz::rand_vary_count(attack_power, 0.1f);
        attack.kind = 1;
        attack.power = power;
        player->receive_direct_attack(this, attack, 0, -1, -1);
        return;
    }
}

void TBoss6MagMine::explode() {
    s32 n = TLobby::get_game_mode();
    s32 i;
    for (i = 0; i < n; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0 && TObjPlayer::is_locally_controlled(player) != 0) {
            Vec v = position;
            subtract_vector(&v, &player->position);
            v.y = 0.0f;
            if (!(vector_length(&v) > 22.5f)) {
                damage_player(player);
            }
        }
    }
    play_sound_effect(0x4003BA1E, &position, 0, 0);
}

s32 TBoss6MagMine::is_player_in_range() {
    Vec d;
    s32 n;
    s32 i;
    TObjPlayer *player;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0) {
            VecCopy(&d, &player->position);
            subtract_vector(&d, &destination);
            d.y = 0.0f;
            if (vector_length(&d) <= 22.5f) {
                return 1;
            }
        }
    }
    return 0;
}

void TBoss6MagMine::state_4() { spawn_particle_effect_with_flags(&position, 252, 64); queue_destruction(); }

void TBoss6MagMine::state_3() {
    explode();
    spawn_particle_effect_with_flags(&position, 0xFB, 0x40);
    spawn_particle_effect_with_flags(&position, 0xFC, 0x40);
    TBoss6PlotFalz::apply_radial_effect_to_players(&position, 0xC0, 0xF, 100.0f);
    queue_destruction();
}

#pragma push
#pragma opt_common_subs off
void TBoss6MagMine::state_2() {
    f32 frame;
    if (is_player_in_range() != 0) {
        state_timer = 0x96;
    }
    motion_frame += 0.33333334f;
    frame = motion_frame;
    if (frame >= 10.0f) {
        motion_frame = frame - 10.0f;
    }
    state_timer = state_timer + 1;
    if (state_timer >= 0x96) {
        state = 3;
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TBoss6MagMine::state_1() {
    position.x = destination.x;
    position.z = destination.z;
    position.y += 1.0f;
    if (position.y >= 10.0f) {
        position.y = 10.0f;
        state_timer = 0;
        state = 2;
    }
}
#pragma pop

void TBoss6MagMine::state_0() {
    flight_velocity.y += -0.25f;
    if (flight_velocity.y < -20.0f) {
        flight_velocity.y = -20.0f;
    }
    vec3_add_to(&position, &flight_velocity);
    if (position.y < -20.0f) {
        position.x = destination.x;
        position.z = destination.z;
        state = 1;
    }
}

void TBoss6MagMine::run_task() {
    s32 color;
    if (TObjPlayer::check_demo_mode() != 0) {
        return;
    }
    if (TBoss6PlotFalz::is_boss_active() == 0) {
        state = 4;
    }
    if (TObjEneDD::query_teammate_state() != 0) {
        return;
    }
    VecCopy(&prev_position, &position);
    static void (TBoss6MagMine::*const handlers[5])() = {
        &TBoss6MagMine::state_0, &TBoss6MagMine::state_1, &TBoss6MagMine::state_2,
        &TBoss6MagMine::state_3, &TBoss6MagMine::state_4,
    };
    void (TBoss6MagMine::*handler)() = handlers[state];
    if (handler) {
        (this->*handler)();
    }
    copy_pos();
    if (state == 2) {
        update_collisions();
        submit_cursor_candidate(this, -1);
    }
    if (state != 0) {
        color = 0xFF7F5126;
        if (state == 2) {
            color = 0xFFFFA24C;
        }
        add_radar_scaled_marker(&position, color, 1, 1, 1.0f);
    }
    hit_flash += -0.06666667f;
    if (hit_flash < 0.0f) {
        hit_flash = 0.0f;
    }
    switch (state) {
    case 0:
        angle_y += 0x1111;
        break;
    case 1:
    case 2:
        angle_y += 0x888;
        break;
    }
    if (particle_emitter != 0) {
        particle_emitter->set_position(&position);
    }
}

TBoss6MagMine::~TBoss6MagMine() {
    if (particle_emitter != NULL) { TParticleCtrl::release(particle_emitter); particle_emitter = NULL; }
    free_collision_body_parts(this);
}

#pragma push
#pragma opt_common_subs off
TBoss6MagMine::TBoss6MagMine(TObject *parent, Boss6MagMineSetData *set_data) : TObjEnemy(parent) {
    TBoss6MagMineStateRecord record;
    f32 *params;
    m_name = TBoss6MagMine__class_name;
    VecCopy(&position, &set_data->origin);
    VecCopy(&destination, &set_data->destination);
    add_flags_2e4(8);
    apply_set_data(set_data);
    if (exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.value = 0;
        exchange_object_state(&record, 0);
    }
    archive = TBoss6PlotFalz::get_scene_archive();
    texlist = 0;
    model = 0;
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    init_collision_body_parts(this, TBoss6MagMine__collision_body_parts, 1);
    VecCopy(&body_center, &position);
    velocity.x = velocity.y = velocity.z = 0.0f;
    target = 0;
    bind_enemy_combat_stats(TLobby::register_boss(0x2D), TLobby::dispatch_shared_handler_b(0x2D), TLobby::register_object(0x2D));
    referenceHp = hp;
    register_by_id();
    set_param(0);
    params = (f32 *)TLobby::dispatch_shared_handler_a(0x2D);
    attack_power = (s32)params[1];
    if ((f32) attack_power <= 0.0f) {
        attack_power = 0x14;
    }
    status_chance = (s32)params[2];
    if ((f32) status_chance < 0.0f || status_chance > 0x64) {
        status_chance = 0;
    }
    status_count = (u16) (entity_id + (s32) (10.0f * (position.x + position.z))) % 100;
    hit_flash = 0.0f;
    motion_frame = 1.0f;
    state_timer = 0;
    state = 0;
    VecCopy(&flight_velocity, &destination);
    subtract_vector(&flight_velocity, &position);
    flight_velocity.y = 0.0f;
    if (vector_length(&flight_velocity) <= 1e-05f) {
        flight_velocity.x = 1.0f;
    }
    normalize_vector(&flight_velocity);
    flight_velocity.x *= 4.166667f;
    flight_velocity.z *= 4.166667f;
    particle_emitter = create_particle_emitter(&position, 0x146);
    if (particle_emitter != NULL) {
        particle_emitter->set_flags(0x40);
    }
}
#pragma pop

TBoss6MagMine *TBoss6MagMine::create(Boss6MagMineSetData *set_data) {
    return new TBoss6MagMine(new TObjControl(tl_04), set_data);
}

void TBoss6MagMine::spawn_mag_mine_at(const Vec *origin, const Vec *destination) {
    Boss6MagMineSetData set_data;
    uaddr boss;
    boss = TBoss6PlotFalz::get_hp();
    if (boss == 0 || ((TBoss6PlotFalz *)boss)->get_scene_state() != 6) {
        return;
    }
    copy_set_entry(&set_data, ((TBoss6PlotFalz *)boss)->get_set_entry());
    VecCopy(&set_data.origin, origin);
    VecCopy(&set_data.destination, destination);
    set_data.flags = 1;
    VecCopy(&set_data.position, &set_data.origin);
    if (((TBoss6PlotFalz *)boss)->get_next_point(&set_data.set_index, &set_data.entity_id) != 0) {
        create(&set_data);
    }
}

s32 TBoss6Type2::get_variant() { return variant; }

TBoss6Type2 *TBoss6PlotFalz::get_type2() { return TBoss6PlotFalz__type2_instance; }
