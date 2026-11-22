#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8Dragon_80359A7C.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_80011014.h"

struct Stack_802F3A48 {
    s32 sp8;
    u8 trailing_storage[0x3C];
};

struct Ent_802F376C { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Ent_802F3878 { u8 pad[0x38]; f32 x; f32 y; f32 z; };

struct Ent_802F3974 { u8 pad[0x38]; f32 x; f32 y; f32 z; };

extern "C" {
extern TObject *tl_04;
extern uaddr boss8_dragon_leader_part;

s32 TBoss8Dragon::is_closest_part() {
    Vec v;
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
    Vec v;
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
    Vec v;
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

s32 TBoss8Dragon::spawn_attack_object(saddr arg1, s32 arg2, s32 hp, s32 arg4) {
    s32 self = (saddr)this;
    Stack_802F3A48 stack;
    if (setup_attack_slot__12TBoss8DragonFiUiiiPv(self, arg1, arg2, arg4, (u8 *)&stack.sp8) != 0) {
        return (saddr)new TUnk_804F1A78(tl_04, &stack.sp8, hp);
    }
    return 0;
}

}
