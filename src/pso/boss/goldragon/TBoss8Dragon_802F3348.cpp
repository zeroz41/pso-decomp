#include "pso/system/SubtractiveRng.h"
#include "types.h"
#include "pso/boss/TUnk_804E4BF0.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_80359A7C.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/object/TObjControl.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/vector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
// TObjPlayer_80011014.h declares these, but its calc_random_ratio prototype takes no rng.
BOOL is_split_screen(void);
void subtractive_rng_seed(void *, s32);
}

TUnk_804E4BF0 *boss8_dragon_leader_part;

TBoss8Dragon *TBoss8Dragon::get_part(s32 index) {
    if (boss8_dragon_leader_part == NULL) {
        return NULL;
    }
    return (TBoss8Dragon *)get_enemy_entity(boss8_dragon_leader_part->get_part_entity_id(index));
}

u16 TBoss8Dragon::get_part_entity_id(s32 index) {
    if (boss8_dragon_leader_part == NULL) {
        return 0xFFFFU;
    }
    return boss8_dragon_leader_part->get_part_entity_id(index);
}

void TBoss8Dragon::place_parts_in_ring(s32 n, s32 hp, s32 seed) {
    Vec v;
    u8 buf[0xEC];
    s32 ang;
    s32 step;
    s32 i;
    TBoss8Dragon *leader;
    __ct__14SubtractiveRngFv(buf);
    if (n <= 5 && boss8_dragon_leader_part != NULL) {
        subtractive_rng_seed(buf, seed);
        ang = (s32)(65535.0f * calc_random_ratio__10TObjPlayerFv(reinterpret_cast<SubtractiveRng *>(buf)));
        step = 0x10000 / (n + 1);
        leader = (TBoss8Dragon *)get_enemy_entity(boss8_dragon_leader_part->get_part_entity_id(0));
        leader->position.x = 320.0f * sin_table_lookup(ang);
        leader->position.z = 320.0f * cos_table_lookup(ang);
        leader->rotation_y = (u16)(ang + 0x8000);
        for (i = 0; i < n; i++) {
            ang += step;
            v.x = 320.0f * sin_table_lookup(ang);
            v.y = leader->position.y;
            v.z = 320.0f * cos_table_lookup(ang);
            boss8_dragon_leader_part->spawn_attack_object(&v, (ang + 0x8000) & 0xFFFF, hp, i + 1);
        }
    }
}

s32 TBoss8Dragon::find_target_enemy() {
    s32 i;

    if (boss8_dragon_leader_part == NULL) {
        return 0;
    }
    for (i = 1; i < 6; i++) {
        if (get_enemy_entity(boss8_dragon_leader_part->get_part_entity_id(i)) != NULL) {
            return 1;
        }
    }
    return 0;
}

s32 TBoss8Dragon::is_any_part_alive() {
    s32 i;

    if (boss8_dragon_leader_part == NULL) {
        return 1;
    }
    for (i = 1; i < 6; i++) {
        if (get_enemy_entity(boss8_dragon_leader_part->get_part_entity_id(i)) != NULL) {
            return 0;
        }
    }
    return 1;
}

void TBoss8Dragon::update_all_parts() {
    s32 i;

    if (boss8_dragon_leader_part != NULL) {
        for (i = 1; i < 6; i++) {
            TBoss8Dragon *part = (TBoss8Dragon *)get_enemy_entity(boss8_dragon_leader_part->get_part_entity_id(i));
            if (part != NULL) {
                part->set_state_22();
            }
        }
    }
}

s32 TBoss8Dragon::get_live_monitor_count() {
    s32 i;
    s32 alive;

    if (is_split_screen()) {
        return -1;
    }
    if (boss8_dragon_leader_part == NULL) {
        return 1;
    }
    alive = 0;
    for (i = 0; i < 6; i++) {
        if (get_enemy_entity(boss8_dragon_leader_part->get_part_entity_id(i)) != NULL) {
            alive++;
        }
    }
    if (alive >= 4) {
        return 0;
    }
    return (alive >= 1) ? 1 : 2;
}

s32 TBoss8Dragon::has_enough_enemies() {
    s32 i;
    s32 count;

    if (is_split_screen() != 0) {
        return 1;
    }
    if (boss8_dragon_leader_part == NULL) {
        return 0;
    }
    count = 0;
    i = 0;
    do {
        if (get_enemy_entity(boss8_dragon_leader_part->get_part_entity_id(i)) != NULL) {
            count += 1;
        }
        i += 1;
    } while (i < 6);
    return (count >= 3) ? 1 : 0;
}

s32 TBoss8Dragon::is_closest_part() {
    Vec v;
    f32 len;
    s32 i;
    if (boss8_dragon_leader_part == NULL) {
        return 1;
    }
    v.x = this->position.x - this->position.x;
    v.y = 0.0f;
    v.z = this->position.z - this->position.z;
    len = normalize_vector_xz(&v);
    for (i = 1; i < 6; i++) {
        u16 id = boss8_dragon_leader_part->get_part_entity_id(i);
        if (id != this->get_entity_id()) {
            TBoss8Dragon *part = (TBoss8Dragon *)get_enemy_entity(id);
            if (part != NULL) {
                v.x = part->position.x - this->position.x;
                v.y = 0.0f;
                v.z = part->position.z - this->position.z;
                if (!(normalize_vector_xz(&v) >= len)) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

#pragma push
#pragma fp_contract on
s32 TBoss8Dragon::push_apart_from_parts() {
    Vec v;
    f32 d;
    s32 i;
    if (boss8_dragon_leader_part == NULL) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        u16 id = boss8_dragon_leader_part->get_part_entity_id(i);
        if (id != this->get_entity_id()) {
            TBoss8Dragon *part = (TBoss8Dragon *)get_enemy_entity(id);
            if (part != NULL) {
                v.x = part->position.x - this->position.x;
                v.y = 0.0f;
                v.z = part->position.z - this->position.z;
                d = normalize_vector_xz(&v) - 120.0f;
                if (!(d >= 0.0f)) {
                    this->position.x = v.x * d + this->position.x;
                    this->position.z = v.z * d + this->position.z;
                    return 1;
                }
            }
        }
    }
    return 0;
}
#pragma pop

s32 TBoss8Dragon::is_near_other_part() {
    Vec v;
    s32 i;
    if (boss8_dragon_leader_part == NULL) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        u16 id = boss8_dragon_leader_part->get_part_entity_id(i);
        if (id != this->get_entity_id()) {
            TBoss8Dragon *part = (TBoss8Dragon *)get_enemy_entity(id);
            if (part != NULL) {
                v.x = part->position.x - this->position.x;
                v.y = 0.0f;
                v.z = part->position.z - this->position.z;
                if (!(normalize_vector_xz(&v) >= 120.0f)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TUnk_804E4BF0::spawn_attack_object(Vec *pos, s32 angle, s32 hp, s32 index) {
    TUnk_804E4BF0SetEntry entry;
    if (this->setup_attack_slot(pos, angle, index, &entry) != 0) {
        return (saddr)new TUnk_804F1A78(tl_04, &entry, hp);
    }
    return 0;
}

s32 TUnk_804E4BF0::setup_attack_slot(Vec *pos, s32 angle, s32 index, TUnk_804E4BF0SetEntry *dst) {
    if ((index < 0) || (index > 5)) {
        return 0;
    }
    copy_set_entry(dst, &this->set_entry);
    dst->set_index = this->get_part_set_index(index);
    dst->kind = 0;
    dst->entity_id = this->get_part_entity_id(index);
    if (pos != NULL) {
        VecCopy(&dst->position, pos);
    }
    dst->angle = angle;
    return 1;
}

void TUnk_804E4BF0::render() {  }

void TUnk_804E4BF0::run_task() {  }

TUnk_804E4BF0::~TUnk_804E4BF0() {
    if (boss8_dragon_leader_part == this) {
        boss8_dragon_leader_part = NULL;
    }
}

TUnk_804E4BF0::TUnk_804E4BF0(TObject *object, void *arg1p) : TObject(object) {
    if (boss8_dragon_leader_part == NULL) {
        boss8_dragon_leader_part = this;
    }
    copy_set_entry(&this->set_entry, arg1p);
}

TUnk_804E4BF0 *create_boss8_dragon_leader_part(TObject *parent, void *set_data) {
    return new TUnk_804E4BF0(parent, set_data);
}

void release_boss8_dragon_leader_part(void) {  }

void clear_boss8_dragon_leader_part(void) { boss8_dragon_leader_part = 0; }

u16 TUnk_804E4BF0::get_part_entity_id(s32 index) {
    return this->set_entry.entity_id + index;
}

s32 TUnk_804E4BF0::get_part_set_index(s32 index) {
    return this->set_entry.set_index + index;
}
