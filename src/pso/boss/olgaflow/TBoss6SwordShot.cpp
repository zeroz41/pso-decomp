#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/olgaflow/TBoss6SwordWave.h"
#include "pso/boss/olgaflow/TBoss6SwordShot.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/BattleParameters.h"
#include "pso/player/TObjPlayer.h"

#include "types.h"

#include <stddef.h>
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixOps.h"


const char TBoss6SwordWave__class_name_string[] = "TBoss6SwordWave";
// The arena centre (boss6_arena_center); the wave ring only sparks within the 400-unit arena radius of it.
const Vec sword_wave_arena_center = {-10000.0f, 0.0f, 0.0f};
const char TBoss6SwordShot__class_name_string[] = "TBoss6SwordShot";
const char *TBoss6SwordWave__name = TBoss6SwordWave__class_name_string;
const char *TBoss6SwordShot__name = TBoss6SwordShot__class_name_string;

// Compiled deferred: functions are emitted last-first (the vtables land in .data SwordShot first), so they are
// written last address first.
#pragma defer_codegen on

void Boss6WaveArcMask::clear_all() {
    s32 i;
    for (i = 0; i < 8; i++) {
        words[i] = 0;
    }
}

void Boss6WaveArcMask::set_bit(s32 bit) {
    s32 word;
    s32 shift;
    split_bit_index(bit, &word, &shift);
    words[word] |= 1 << shift;
}

void Boss6WaveArcMask::fill_range(s32 start_angle, s32 end_angle) {
    s32 bit = angle_to_bit(start_angle);
    s32 end = angle_to_bit(end_angle);
    if (bit > end) {
        end += 0x100;
    }
    clear_all();
    while (bit <= end) {
        set_bit(bit);
        bit++;
    }
}

void Boss6WaveArcMask::clear_bit(s32 bit) {
    s32 word;
    s32 shift;
    split_bit_index(bit, &word, &shift);
    words[word] &= ~(1 << shift);
}

s32 Boss6WaveArcMask::angle_to_bit(s32 angle) {
    return (angle >> 8) & 0xFF;
}

void Boss6WaveArcMask::split_bit_index(s32 bit, s32 *word, s32 *shift) {
    bit &= 0xFF;
    *word = bit / 32;
    *shift = bit % 32;
}

s32 Boss6WaveArcMask::test_bit(s32 bit) {
    s32 word;
    s32 shift;
    split_bit_index(bit, &word, &shift);
    return ((1 << shift) & words[word]) != 0;
}

TBoss6SwordWave *TBoss6SwordWave::create(TBoss6Type2 *owner, const Vec *position, s32 start_angle, s32 end_angle, f32 radius) {
    return new TBoss6SwordWave(owner, position, start_angle, end_angle, radius);
}

TBoss6SwordWave::TBoss6SwordWave(TBoss6Type2 *owner, const Vec *position, s32 start_angle, s32 end_angle, f32 radius)
    : TObject(owner) {
    m_name = TBoss6SwordWave__name;
    this->owner = owner;
    VecCopy(&this->position, position);
    this->position.y = 0.0f;
    this->radius = radius;
    arcs.fill_range(start_angle, end_angle);
    inner_radius = 0.0f;
    outer_radius = 0.0f;
    particle_timer = 0.0f;
    f32 param = TLobby::dispatch_shared_handler_a(0x2C)->values.floats[0];
    power = (s32)param;
    if (0.0f == param) {
        power = 0x14;
    }
    f32 scale = TLobby::dispatch_shared_handler_a(0x2F)->values.floats[2];
    power_scale = scale;
    if (0.0f == scale) {
        power_scale = 1.0f;
    }
}

TBoss6SwordWave::~TBoss6SwordWave() {}

#pragma push
#pragma opt_common_subs off
void TBoss6SwordWave::run_task() {
    f32 timer;
    if (TObjEneDD::query_teammate_state() == 0) {
        break_rocks_in_wave();
        check_player_hits();
        if (particle_timer < 6.6666665f) {
            spawn_wave_ring_particles();
        }
        particle_timer += 6.6666665f;
        timer = particle_timer;
        if (timer > 29.9f) {
            particle_timer = timer - 29.9f;
        }
        inner_radius = outer_radius;
        outer_radius += 6.6666665f;
        if (outer_radius > radius) {
            queue_destruction();
        }
    }
}
#pragma pop

void TBoss6SwordWave::render() {}

// The wave's rock bitmap has 256 bit slots (Boss6WaveArcMask::angle_to_bit maps an angle to one); a range that wraps
// is unwrapped by one bitmap length. The code loads it from .sdata2 ahead of run_task's float literals: a file
// constant read through an inlined reference, emitted at its first user (the TBoss6Type2.cpp form).
static const s32 wave_bit_count = 0x100;

inline const s32 &get_wave_bit_count() { return wave_bit_count; }

void TBoss6SwordWave::break_rocks_in_wave() {
    Vec rock;
    Vec offset;
    Vec edge_a;
    Vec edge_b;
    Vec side;
    f32 scale;
    s32 i;
    s32 bit;
    s32 angle_a;
    s32 angle_b;
    s32 lo;
    s32 hi;
    f32 distance;
    for (i = 0; i < 32; i++) {
        if (TBoss6Rock::get_point(i, &rock, &scale) == 0) {
            continue;
        }
        VecCopy(&offset, &rock);
        subtract_vector(&offset, &position);
        offset.y = 0.0f;
        distance = vector_length(&offset);
        if (distance < inner_radius || distance > outer_radius) {
            continue;
        }
        bit = arcs.angle_to_bit((s32)(10430.38043493439 * atan2_float(offset.x, offset.z)));
        if (arcs.test_bit(bit) == 0) {
            continue;
        }
        arcs.clear_bit(bit);
        TBoss6Rock::reset_rock_state(i);
        if (distance <= 1e-05f) {
            continue;
        }
        side.x = -offset.z;
        side.y = 0.0f;
        side.z = offset.x;
        normalize_vector(&side);
        side.x *= scale;
        side.z *= scale;
        VecCopy(&edge_a, &rock);
        vec3_add_to(&edge_a, &side);
        VecCopy(&edge_b, &rock);
        subtract_vector(&edge_b, &side);
        angle_a = (s32)(10430.38043493439 * atan2_float(edge_a.x - position.x, edge_a.z - position.z));
        angle_b = (s32)(10430.38043493439 * atan2_float(edge_b.x - position.x, edge_b.z - position.z));
        lo = arcs.angle_to_bit(angle_a);
        hi = arcs.angle_to_bit(angle_b);
        if (hi < lo) {
            hi += get_wave_bit_count();
        }
        for (; lo <= hi; lo++) {
            arcs.clear_bit(lo);
        }
    }
}

void TBoss6SwordWave::check_player_hits() {
    s32 count;
    s32 i;
    TObjPlayer *player;
    s32 bit;
    s32 damage;
    f32 distance;
    Vec offset;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0) {
            VecCopy(&offset, &player->position);
            subtract_vector(&offset, &position);
            offset.y = 0.0f;
            distance = vector_length(&offset);
            if (distance < inner_radius || distance > outer_radius) {
                continue;
            }
            bit = arcs.angle_to_bit((s32)(10430.38043493439 * atan2_float(offset.x, offset.z)));
            if (arcs.test_bit(bit) == 0) {
                continue;
            }
            damage = power;
            if (owner->get_rotation_timer() != 0) {
                damage = (s32)((f32)damage * power_scale);
            }
            DirectAttackPayload attack;
            s32 varied = TBoss6PlotFalz::rand_vary_count(damage, 0.1f);
            attack.kind = 0;
            attack.power = varied;
            player->receive_direct_attack(owner, attack, 0, -1, -1);
        }
    }
}

void TBoss6SwordWave::spawn_wave_ring_particles() {
    f32 circumference;
    f32 step_turns;
    s32 step;
    s32 angle;
    circumference = 6.28f * outer_radius;
    if (circumference <= 1e-05f) {
        step_turns = 1.0f;
    } else {
        step_turns = 42.158997f / circumference;
    }
    step = (s32)(65536.0f * step_turns);
    for (angle = 0; angle < 0x10000; angle += step) {
        s32 bit = arcs.angle_to_bit(angle);
        if (arcs.test_bit(bit) != 0) {
            Vec v = position;
            v.x += outer_radius * sin_table_lookup(angle);
            v.z += outer_radius * cos_table_lookup(angle);
            if (!(xyz_distance(&v, (Vec *)&sword_wave_arena_center) > 400.0f)) {
                spawn_particle_effect_with_flags(&v, 0x212, 0x40);
                if (owner->get_rotation_timer() == 0) {
                    spawn_particle_effect(&v, 0x213);
                } else {
                    spawn_particle_effect_with_flags(&v, 0x229, 0x2000);
                }
            }
        }
    }
}

TBoss6SwordShot *TBoss6SwordShot::create(TObject *owner, const Vec *position, s32 with_particles, f32 radius) {
    return new TBoss6SwordShot(owner, position, with_particles, radius);
}

#pragma push
#pragma opt_common_subs off
TBoss6SwordShot::TBoss6SwordShot(TObject *owner, const Vec *position, s32 with_particles, f32 radius)
    : TObject(owner) {
    f32 scale;
    f32 v;
    TParticleCtrl *particle;
    m_name = TBoss6SwordShot__name;
    this->owner = owner;
    VecCopy(&this->position, position);
    this->radius = radius;
    age = 0;
    v = *(f32 *)TLobby::dispatch_shared_handler_a(0x2B);
    damage = (s32)v;
    if (0.0f == v) {
        damage = 0x14;
    }
    if (with_particles != 0) {
        scale = 1.0f;
        if (this->radius > 15.0f) {
            scale = this->radius / 15.0f;
        }
        if ((particle = spawn_particle_effect_with_flags(&this->position, 0x212, 0x40)) != NULL) {
            particle->set_scale(scale, 1.0f);
        }
        if ((particle = spawn_particle_effect_with_flags(&this->position, 0x213, 0x40)) != NULL) {
            particle->set_scale(scale, 1.0f);
        }
    }
}
#pragma pop

TBoss6SwordShot::~TBoss6SwordShot() {}

void TBoss6SwordShot::run_task() {
    if (TObjEneDD::query_teammate_state() == 0) {
        damage_players_in_radius();
        age++;
        if (age > 7) {
            queue_destruction();
        }
    }
}

void TBoss6SwordShot::damage_players_in_radius() {
    Vec offset;
    s32 count = TLobby::get_game_mode();
    for (s32 i = 0; i < count; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_active(player) != 0) {
            VecCopy(&offset, &player->position);
            subtract_vector(&offset, &position);
            offset.y = 0.0f;
            if (!(vector_length(&offset) > radius)) {
                s32 power = TBoss6PlotFalz::rand_vary_count(damage, 0.1f);
                DirectAttackPayload attack;
                attack.kind = 0;
                attack.power = (f32)power;
                player->receive_direct_attack(owner, attack, NULL, -1, -1);
            }
        }
    }
}
