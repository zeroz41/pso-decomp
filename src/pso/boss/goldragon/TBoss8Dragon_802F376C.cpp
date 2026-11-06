#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"

struct Stack_802F3A48 {
    s32 sp8;
    u8 trailing_storage[0x3C];
};

struct Vec_802F376C { f32 x, y, z; };

struct Ent_802F376C { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Vec_802F3878 { f32 x, y, z; };

struct Ent_802F3878 { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Vec_802F3974 { f32 x, y, z; };

struct Ent_802F3974 { u8 pad[0x38]; f32 x; f32 y; f32 z; };

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 ct_attack_object__12TBoss8DragonFlll(int, int, void *, void *);
extern s32 tl_04;
u16 get_entity_id(void *);
u8 *get_enemy_entity(u16 arg0);
extern u32 boss8_dragon_leader_part;

s32 TBoss8Dragon::is_closest_part() {
    Vec_802F376C v;
    f32 len;
    s32 i;
    if (boss8_dragon_leader_part == 0) {
        return 1;
    }
    v.x = ((Ent_802F376C *)this)->x - ((Ent_802F376C *)this)->x;
    v.y = 0.0f;
    v.z = ((Ent_802F376C *)this)->z - ((Ent_802F376C *)this)->z;
    len = normalize_vector_xz((Vec *)(&v));
    for (i = 1; i < 6; i++) {
        u16 id = ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i);
        if (id != get_entity_id(this)) {
            Ent_802F376C *e = (Ent_802F376C *)get_enemy_entity(id);
            if (e != NULL) {
                v.x = e->x - ((Ent_802F376C *)this)->x;
                v.y = 0.0f;
                v.z = e->z - ((Ent_802F376C *)this)->z;
                if (!(normalize_vector_xz((Vec *)(&v)) >= len)) {
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
    Vec_802F3878 v;
    f32 d;
    s32 i;
    if (boss8_dragon_leader_part == 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        u16 id = ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i);
        if (id != get_entity_id(this)) {
            Ent_802F3878 *e = ((Ent_802F3878 *)get_enemy_entity(id));
            if (e != NULL) {
                v.x = e->x - ((Ent_802F3878 *)this)->x;
                v.y = 0.0f;
                v.z = e->z - ((Ent_802F3878 *)this)->z;
                d = normalize_vector_xz((Vec *)(&v)) - 120.0f;
                if (!(d >= 0.0f)) {
                    ((Ent_802F3878 *)this)->x = v.x * d + ((Ent_802F3878 *)this)->x;
                    ((Ent_802F3878 *)this)->z = v.z * d + ((Ent_802F3878 *)this)->z;
                    return 1;
                }
            }
        }
    }
    return 0;
}
#pragma pop

s32 TBoss8Dragon::is_near_other_part() {
    Vec_802F3974 v;
    s32 i;
    if (boss8_dragon_leader_part == 0) {
        return 0;
    }
    for (i = 0; i < 6; i++) {
        u16 id = ((TBoss8Dragon *)boss8_dragon_leader_part)->get_part_count_plus(i);
        if (id != get_entity_id(this)) {
            Ent_802F3974 *e = ((Ent_802F3974 *)get_enemy_entity(id));
            if (e != NULL) {
                v.x = e->x - ((Ent_802F3974 *)this)->x;
                v.y = 0.0f;
                v.z = e->z - ((Ent_802F3974 *)this)->z;
                if (!(normalize_vector_xz((Vec *)(&v)) >= 120.0f)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

s32 TBoss8Dragon::spawn_attack_object(s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 arg0 = (s32)this;
    Stack_802F3A48 stack;
    s32 temp_r3;
    s32 var_r0;
    if (setup_attack_slot__12TBoss8DragonFiUiiiPv(arg0, arg1, arg2, arg4, (u8 *)&stack.sp8) != 0) {
        temp_r3 = __nw__7TObjectFUl(0x8A4);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = ct_attack_object__12TBoss8DragonFlll((int)temp_r3, (int)tl_04, &stack.sp8, (void *)arg3);
        }
        return var_r0;
    }
    return 0;
}

}
