#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/ModelNodePositionCapture.h"
#include "pso/enemy/EnemyTargeting.h"
#include "types.h"
#include "pso/enemy/panarms/TObjEnePanarmsAtkColli.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaMirage.h"

#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjControl.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/object/base/CollisionActorLookup.h"

// Stored in the object name field by the constructor.
const char *TObjEnePanarmsAtkColli_class_name = "TObjEnePanarmsAtkColli";

__declspec(section ".data") s32 TObjEnePanarmsAtkColli__type_index_table[2] = {1, 2};
Vec panarms_atk_zero_vec = {0.0f, 0.0f, 0.0f};


extern "C" {
__declspec(section ".rodata") DirectAttackPayload lbl_8043CDF0[] = { 0 };
__declspec(section ".rodata") DirectAttackPayload lbl_8043CDF8[] = { 0 };
}

ModelNodePositionCapture::ModelNodePositionCapture(const ModelNodePositionEntry *entries, Vec *positions) {
    this->entries = entries;
    this->positions = positions;
    const ModelNodePositionEntry *entry = this->entries;
    Vec *point = this->positions;
    while (entry->node_index != -1) {
        VecCopy(point, &panarms_atk_zero_vec);
        entry++;
        point++;
    }
}

// Moves the volume to point for one nearest-enemy search and hits what it
// finds there, unless that is the Panarms that spawned it.
void TObjEnePanarmsAtkColli::hit_enemy_near(Vec *point) {
    Vec saved = position;
    s32 id;
    TObjChara *enemy;
    VecCopy(&position, point);
    if ((id = find_nearest_hittable_enemy(this, NULL, radius)) != 0xFFFF) {
        if ((enemy = get_enemy_entity(id)) != NULL && enemy != m_up) {
            hit_enemy(enemy);
        }
    }
    VecCopy(&position, &saved);
}

void TObjEnePanarmsAtkColli::hit_enemy(TObjChara *enemy) {
    DirectAttackPayload attack = lbl_8043CDF8[0];
    attack.power = attack_power;
    if (last_hit_enemy != enemy) {
        f32 damage = enemy->receive_direct_attack(m_up, attack, NULL, -1, -1);
        if (0.0f != damage) {
            enemy->apply_knockback_from_attacker((u8 *)this, damage);
        }
        last_hit_enemy = enemy;
    }
}

void TObjEnePanarmsAtkColli::hit_player(TObjChara *player) {
    DirectAttackPayload attack = lbl_8043CDF0[0];
    attack.power = attack_power;
    if (last_hit_player != player) {
        f32 damage = player->receive_direct_attack(m_up, attack, NULL, -1, -1);
        if (0.0f != damage) {
            player->apply_knockback_from_attacker((u8 *)this, damage);
        }
        last_hit_player = player;
    }
}

#pragma push
#pragma opt_loop_invariants off
void TObjEnePanarmsAtkColli::sweep_segment_collisions() {
    Vec step;
    f32 len;
    f32 lim;
    f32 dist;
    s32 i;
    TObjPlayer *player;

    lim = radius * radius;
    VecCopy(&step, &prev_position);
    subtract_vector(&step, &position);
    len = vector_length(&step);
    if (0.0f == len) {
        step.x = 1.0f;
    }
    normalize_vector(&step);
    step.x *= radius;
    step.z *= radius;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player != NULL && !(player->actorFlags & 0x02000A00)) {
            Vec point = position;
            for (dist = 0.0f; dist < len; ) {
                if (!(horizontal_distance_squared(&point, &player->body_center) > lim)) {
                    hit_player(player);
                    break;
                }
                dist += radius;
                vec3_add_to(&point, &step);
            }
        }
    }
    {
    Vec point = position;
    f32 dist2;
    for (dist2 = 0.0f; dist2 < len; ) {
        hit_enemy_near(&point);
        dist2 += radius;
        vec3_add_to(&point, &step);
    }
    }
}

#pragma pop

void TObjEnePanarmsAtkColli::check_radius_collisions() {
    s32 i;
    TObjPlayer *player;
    f32 lim = radius * radius;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player != NULL && !(player->actorFlags & 0x02000A00) && !(horizontal_distance_squared(&position, &player->body_center) > lim)) {
            hit_player(player);
        }
    }
    hit_enemy_near(&position);
}

void TObjEnePanarmsAtkColli::run_task() {
    if (--lifetime < 0) {
        queue_destruction();
        return;
    }
    VecCopy(&prev_position, &position);
    vec3_add_to(&position, &velocity);
    radius += radius_growth;
    switch (type) {
    case 0:
        check_radius_collisions();
        return;
    case 1:
        play_persistent_sound(remap_sound_for_area(0x4003BA2A), this, &position, 0, 0);
        sweep_segment_collisions();
        return;
    }
}

TObjEnePanarmsAtkColli *TObjEnePanarmsAtkColli::create(TObject *parent, Vec *position, Vec *velocity, s32 type) {
    return new TObjEnePanarmsAtkColli(parent, position, velocity, type);
}

TObjEnePanarmsAtkColli::~TObjEnePanarmsAtkColli() {

}

extern const f32 lbl_805DA5A8 = 10.0f;
extern const f32 lbl_805DA5AC = 2.8f;
TObjEnePanarmsAtkColli::TObjEnePanarmsAtkColli(TObject *parent, Vec *position, Vec *velocity, s32 type) : TObjEnemy(parent) {
    f32 speed;
    m_name = TObjEnePanarmsAtkColli_class_name;
    VecCopy(&this->position, position);
    VecCopy(&this->velocity, velocity);
    this->type = type;
    last_hit_player = NULL;
    last_hit_enemy = NULL;
    set_param(0x15);
    attack_power = ((f32 *)TLobby::dispatch_shared_handler_a(0x31))[TObjEnePanarmsAtkColli__type_index_table[this->type]];
    if (attack_power < 0.0f) {
        attack_power = 0.0f;
    }
    this->velocity.y = 0.0f;
    if (0.0f == vector_length(&this->velocity)) {
        this->velocity.x = 1.0f;
    }
    normalize_vector(&this->velocity);
    switch (this->type) {
    case 0:
        play_sound_effect(remap_sound_for_area(0x4003BC2B), &this->position, 0, 0);
        radius = 5.0f;
        radius_growth = 1.0416666f;
        lifetime = 12;
        speed = *(const volatile f32 *)&lbl_805DA5AC;
        break;
    case 1:
        radius = 5.0f;
        radius_growth = 0.0f;
        lifetime = 12;
        speed = *(const volatile f32 *)&lbl_805DA5A8;
        break;
    }
    this->velocity.x *= speed;
    this->velocity.z *= speed;
}
