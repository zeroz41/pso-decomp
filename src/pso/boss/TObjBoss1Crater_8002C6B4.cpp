#include "types.h"
#include "pso/boss/TObjBoss1Crater_8002C6B4.h"
#include "pso/boss/TObjBoss1Crater.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/misc/TLobby.h"

struct Ent_8002C730 { u8 pad0[0x38]; f32 f38; u8 pad3c[4]; f32 f40; };

struct Obj_8002C730 { f32 x; u8 pad[4]; f32 z; };

extern s32 TObjBoss1Crater__instance_count;
extern s32 TObjBoss1Crater__instance_list[];
extern "C" {
f32 newton_sqrtf(f32);
f32 calc_nearest_crater_distance(Obj_8002C730 *self);
void *TObjBoss1Crater__ct(void *, void *, void *, void *);
void *__nw__7TObjectFUl(int);
void *get_instance__12TBoss1DragonFv(void);
int is_count_below_limit__15TObjBoss1CraterFv(void *, void *);

void *TObjBoss1Crater::create(void *arg1) {
    void *x1;
    void *o;
    if (is_count_below_limit__15TObjBoss1CraterFv(this, arg1) == 0) {
        return NULL;
    }
    x1 = get_instance__12TBoss1DragonFv();
    if (x1 == NULL) {
        return NULL;
    }
    o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = TObjBoss1Crater__ct(o, this, x1, arg1);
    }
    return o;
}

#pragma push
#pragma fp_contract on
f32 calc_nearest_crater_distance(Obj_8002C730 *self) {
    f32 best;
    s32 i;
    f32 x;
    f32 z;
    f32 d;
    f32 dx;
    f32 dz;
    best = 100000000.0f;
    if (TObjBoss1Crater__instance_count == 0) {
        return 0.0f;
    }
    x = self->x;
    z = self->z;
    for (i = 0; i < TObjBoss1Crater__instance_count; i++) {
        Ent_8002C730 *e = (Ent_8002C730 *)TObjBoss1Crater__instance_list[i];
        dx = e->f38 - x;
        dz = e->f40 - z;
        d = dx * dx + dz * dz;
        if (d < best) {
            best = d;
        }
    }
    return newton_sqrtf(best);
}
#pragma pop

void TObjBoss1Crater__sub_8002C7B4(void) {  }

void TObjBoss1Crater__sub_8002C7B8(void) {
    s32 i;
    TObjBoss1Crater__instance_count = 0;
    for (i = 0; i < 20; i++) {
        TObjBoss1Crater__instance_list[i] = 0;
    }
}

s32 TObjBoss1Crater__sub_8002C7E4(void* p) { return *(s32*)((char*)p + 0x8); }
}
void attack_target_list_remove(u8 *arg0, s32 arg1) {
    s32 temp_r5;
    s32 temp_r5_2;
    if (arg1 >= 0) {
        temp_r5 = *(s32 *)((s8 *)arg0 + 8);
        if (arg1 < temp_r5) {
            *(s32 *)((s8 *)arg0 + 8) = (temp_r5 - 1);
            temp_r5_2 = *(s32 *)((s8 *)arg0 + 0);
            *(s32 *)((s8 *)temp_r5_2 + (arg1 * 4)) = *(s32 *)((s8 *)temp_r5_2 + (*(s32 *)((s8 *)arg0 + 8) * 4));
            *(s32 *)((s8 *)(*(s32 *)((s8 *)arg0 + 0)) + (*(s32 *)((s8 *)arg0 + 8) * 4)) = *(s32 *)((s8 *)arg0 + 4);
        }
    }
}
