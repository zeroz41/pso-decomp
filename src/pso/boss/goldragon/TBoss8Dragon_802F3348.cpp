#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3348.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"

struct Vec_802F33C8 { f32 x, y, z; };

struct Ent_802F33C8 { u8 pad0[0x38]; f32 x, y, z; u8 pad44[0x60 - 0x44]; s32 rot; };

extern "C" {
s32 get_enemy_entity();
extern u8 *boss8_dragon_leader_part;
f32 calc_random_ratio__10TObjPlayerFv(void *);
void subtractive_rng_seed(void *, s32);
void spawn_attack_object__12TBoss8DragonFllll(void *, Vec_802F33C8 *, u16, s32, s32);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);
s32 TBoss8Dragon__sub_802F3348(s32 arg0) {
    if ((void *) boss8_dragon_leader_part == NULL) {
        return 0;
    }
    ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(arg0);
    return get_enemy_entity();
}
u16 TBoss8Dragon::get_global_part_count(s32 arg0) {
    if ((void *) boss8_dragon_leader_part == NULL) {
        return 0xFFFFU;
    }
    return ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(arg0);
}
void TBoss8Dragon::place_parts_in_ring(s32 arg1, s32 arg2) {
    s32 n = (s32)this;
    Vec_802F33C8 v;
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
        ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(0);
        e = (Ent_802F33C8 *)get_enemy_entity();
        e->x = 320.0f * sin_table_lookup(ang);
        e->z = 320.0f * cos_table_lookup(ang);
        e->rot = (u16)(ang + 0x8000);
        for (i = 0; i < n; i++) {
            ang += step;
            v.x = 320.0f * sin_table_lookup(ang);
            v.y = e->y;
            v.z = 320.0f * cos_table_lookup(ang);
            spawn_attack_object__12TBoss8DragonFllll(boss8_dragon_leader_part, &v, ang + 0x8000, arg1, i + 1);
        }
    }
}

}
