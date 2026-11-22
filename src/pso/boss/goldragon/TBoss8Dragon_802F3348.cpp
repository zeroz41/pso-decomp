#include "types.h"
#include "pso/boss/TUnk_804E4BF0.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3348.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3638.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_80359A7C.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/object/TObjControl.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/vector.h"

struct Ent_802F33C8 { u8 pad0[0x38]; f32 x, y, z; u8 pad44[0x60 - 0x44]; s32 rot; };

struct Ent_802F376C { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Stack_802F3A48 {
    s32 sp8;
    u8 trailing_storage[0x3C];
};

extern "C" {
extern TObject *tl_04;
// TObjPlayer_80011014.h declares these, but its calc_random_ratio prototype takes no rng.
BOOL is_split_screen(void);
u16 get_entity_id(TObjBase *object);
f32 calc_random_ratio__10TObjPlayerFv(void *);
void subtractive_rng_seed(void *, s32);
}

TUnk_804E4BF0 *boss8_dragon_leader_part;

extern "C" {
s32 TBoss8Dragon__sub_802F3348(s32 arg0) {
    if (boss8_dragon_leader_part == NULL) {
        return 0;
    }
    return (saddr)get_enemy_entity(((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(arg0));
}
}

u16 TBoss8Dragon::get_global_part_count(s32 arg0) {
    if (boss8_dragon_leader_part == NULL) {
        return 0xFFFFU;
    }
    return ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(arg0);
}

void TBoss8Dragon::place_parts_in_ring(s32 arg1, s32 arg2) {
    s32 n = (saddr)this;
    Vec v;
    u8 buf[0xEC];
    s32 ang;
    s32 step;
    s32 i;
    Ent_802F33C8 *e;
    __ct__14SubtractiveRngFv(buf);
    if (n <= 5 && boss8_dragon_leader_part != NULL) {
        subtractive_rng_seed(buf, arg2);
        ang = (s32)(65535.0f * calc_random_ratio__10TObjPlayerFv(buf));
        step = 0x10000 / (n + 1);
        e = (Ent_802F33C8 *)get_enemy_entity(((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(0));
        e->x = 320.0f * sin_table_lookup(ang);
        e->z = 320.0f * cos_table_lookup(ang);
        e->rot = (u16)(ang + 0x8000);
        for (i = 0; i < n; i++) {
            ang += step;
            v.x = 320.0f * sin_table_lookup(ang);
            v.y = e->y;
            v.z = 320.0f * cos_table_lookup(ang);
            ((TBoss8Dragon *)boss8_dragon_leader_part)->spawn_attack_object(&v, (ang + 0x8000) & 0xFFFF, arg1, i + 1);
        }
    }
}

s32 TBoss8Dragon::find_target_enemy() {
    s32 var_r31;

    if (boss8_dragon_leader_part == NULL) {
        return 0;
    }
    var_r31 = 1;
loop_3:
    if (get_enemy_entity(((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(var_r31)) != NULL) {
        return 1;
    }
    var_r31 += 1;
    if (var_r31 >= 6) {
        return 0;
    }
    goto loop_3;
}

s32 TBoss8Dragon::is_any_part_alive() {
    s32 var_r31;

    if (boss8_dragon_leader_part == NULL) {
        return 1;
    }
    var_r31 = 1;
loop_3:
    if (get_enemy_entity(((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(var_r31)) != NULL) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 6) {
        return 1;
    }
    goto loop_3;
}

void TBoss8Dragon::update_all_parts() {
    s32 var_r31;

    if (boss8_dragon_leader_part != NULL) {
        var_r31 = 1;
        do {
            TBoss8Dragon *enemy;
            if ((enemy = (TBoss8Dragon *)get_enemy_entity(((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(var_r31))) != NULL) {
                enemy->set_state_22();
            }
            var_r31 += 1;
        } while (var_r31 < 6);
    }
}

extern "C" {
s32 TBoss8Dragon__sub_802F3638() {
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
        if (get_enemy_entity(((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i)) != NULL) {
            alive++;
        }
    }
    if (alive >= 4) {
        return 0;
    }
    return (alive >= 1) ? 1 : 2;
}
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
        if (get_enemy_entity(((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i)) != NULL) {
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
        u16 id = ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i);
        if (id != get_entity_id(this)) {
            Ent_802F376C *e = (Ent_802F376C *)get_enemy_entity(id);
            if (e != NULL) {
                v.x = e->x - this->position.x;
                v.y = 0.0f;
                v.z = e->z - this->position.z;
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
        u16 id = ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i);
        if (id != get_entity_id(this)) {
            Ent_802F376C *e = (Ent_802F376C *)get_enemy_entity(id);
            if (e != NULL) {
                v.x = e->x - this->position.x;
                v.y = 0.0f;
                v.z = e->z - this->position.z;
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
        u16 id = ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i);
        if (id != get_entity_id(this)) {
            Ent_802F376C *e = (Ent_802F376C *)get_enemy_entity(id);
            if (e != NULL) {
                v.x = e->x - this->position.x;
                v.y = 0.0f;
                v.z = e->z - this->position.z;
                if (!(normalize_vector_xz(&v) >= 120.0f)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TBoss8Dragon::spawn_attack_object(Vec *pos, s32 angle, s32 hp, s32 index) {
    s32 self = (saddr)this;
    Stack_802F3A48 stack;
    if (setup_attack_slot__12TBoss8DragonFiUiiiPv(self, (uaddr)pos, angle, index, (u8 *)&stack.sp8) != 0) {
        return (saddr)new TUnk_804F1A78(tl_04, &stack.sp8, hp);
    }
    return 0;
}

extern "C" {
s32 setup_attack_slot__12TBoss8DragonFiUiiiPv(saddr self, uaddr arg1, s32 arg2, s32 arg3, u8 *dst) {
    if ((arg3 < 0) || (arg3 > 5)) {
        return 0;
    }
    TBoss4DarkFalz__sub_8004B4F0(dst, (void *)(self + 0x1C));
    *(s16 *)((s8 *)dst + 0) = TBoss8Dragon__sub_802F3C94((void *)self, (s32)arg3);
    *(s16 *)((s8 *)dst + 2) = 0;
    *(s16 *)((s8 *)dst + 6) = ((TBoss8Dragon *)self)->get_part_count_plus(arg3);
    if (arg1 != 0U) {
        VecCopy((Vec *)(dst + 0x10), (const Vec *)(arg1));
    }
    *(s32 *)((s8 *)dst + 0x20) = arg2;
    return 1;
}
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
    TBoss4DarkFalz__sub_8004B4F0((void *)((char *)this + 28), arg1p);
}

extern "C" {
void *TBoss8Dragon__sub_802F3C24(void *object, void *set_data) {
    void *o;
    o = (void *)new TUnk_804E4BF0((TObject *)object, (void *)set_data);
    return o;
}

void TBoss8Dragon__sub_802F3C74(void) {  }
}

void clear_boss8_dragon_leader_part(void) { boss8_dragon_leader_part = 0; }

u16 TBoss8Dragon::get_part_count_plus(s32 arg1) {
    return (u16) (*(u16 *)((u8 *)this + 0x22) + arg1);
}

extern "C" {
s32 TBoss8Dragon__sub_802F3C94(void *self, s32 arg1) {
    return *(s16 *)((s8 *)self + 0x1C) + arg1;
}
}
