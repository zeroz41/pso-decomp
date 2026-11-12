#include "types.h"
#include <stddef.h>
#include <dolphin/mtx.h>
#include "pso/system/vector.h"
#include "pso/map/CsnQuery.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightning.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningWing.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningHorn.h"

#pragma readonly_strings on

const char *TBoss5GryphonLightningHorn__name = "TBoss5GryphonLightningHorn";

typedef struct Vec_80325D58 { f32 x; f32 y; f32 z; } Vec_80325D58;

struct Vec_80325F7C { f32 x, y, z; };

struct Ray_80325F7C { Vec_80325F7C o; Vec_80325F7C d; };

struct Ctl_80325F7C { u8 pad[0x38]; Vec_80325F7C pos; };

typedef struct Vec_80326074 { f32 x; f32 y; f32 z; } Vec_80326074;

typedef struct Seg_80326074 { Vec_80326074 pos; f32 pad; } Seg_80326074;

typedef struct Hit_80326074 { u8 pad[4]; f32 *pos; } Hit_80326074;

typedef struct Wing_80326074 {
    u8 pad0[0x48];
    Seg_80326074 segs[4];
    u8 pad88[8];
    s32 n;
    u8 pad94[4];
    Vec_80326074 vel;
} Wing_80326074;

extern "C" {
f32 vec3_dot(void *, void *);
void normalize_vector(void *);
int queue_destruction__7TObjectFv(void *);
void TBoss8Dragon__sub_80063FB8(s32, void *, f32);
Ctl_80325F7C *get_player_by_client_id(s32);
void get_wing_position__26TBoss5GryphonLightningWingFl(void *, void *);
void copy_position__12TBoss8DragonFl(void *, void *);
void project_point_onto_line(void *, void *, void *);
s32 rand(void);
void vec3_add_to(void *, void *);
void subtract_vector(void *, void *);
extern const f32 lbl_805D8D48;
s32 TBoss5GryphonLightning__ct(f32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int, f32, f32);
extern s32 __vt__26TBoss5GryphonLightningHorn[];
u8 *__ct__26TBoss5GryphonLightningHornFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
s32 __nw__7TObjectFUl(int);

int TBoss8Dragon::queue_destruction() { return queue_destruction__7TObjectFv(this); }

#pragma push
#pragma fp_contract on
#define STEP_80325D58() \
    { \
        f32 xx = d.x * d.x; \
        f32 yy = d.y * d.y; \
        f32 zz = d.z * d.z; \
        if (newton_sqrtf(zz + (xx + yy)) <= dist) { \
            return 0; \
        } \
        to->x = dir->x * dist + from->x; \
        to->y = dir->y * dist + from->y; \
        to->z = dir->z * dist + from->z; \
        return 1; \
    }
s32 TObjPlayer__sub_80325D58(void *arg0, Vec_80325D58 *from, Vec_80325D58 *dir, Vec_80325D58 *to, f32 dist) {
    Vec_80325D58 d;
    Vec_80325D58 n;
    f32 t;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    t = vec3_dot(dir, &d);
    if (0.0f > t) {
        VecCopy((Vec *)to, (const Vec *)from);
        return 1;
    }
    if (1.0f != t) {
        VecCopy((Vec *)&n, (const Vec *)&d);
        normalize_vector(&n);
        if (1.0f != vec3_dot(dir, &n)) {
            STEP_80325D58()
        }
        STEP_80325D58()
    }
    STEP_80325D58()
}
#undef STEP_80325D58
#pragma pop

void fn_80325F7C(void *arg0) {
    Ray_80325F7C ray;
    Vec_80325F7C pos;
    Vec_80325F7C wing;
    Vec_80325F7C hit;
    Vec_80325F7C dir;
    s32 inst;
    s32 i;
    Ctl_80325F7C *c;
    inst = TBoss8Dragon::get_instance_count();
    if (inst != 0) {
        i = 0;
        do {
            c = get_player_by_client_id(i);
            if (c != 0) {
                copy_position__12TBoss8DragonFl(arg0, &pos);
                get_wing_position__26TBoss5GryphonLightningWingFl(arg0, &wing);
                ray.o.x = pos.x;
                ray.o.y = c->pos.y;
                ray.o.z = pos.z;
                ray.d.x = wing.x - pos.x;
                ray.d.y = 0.0f;
                ray.d.z = wing.z - pos.z;
                project_point_onto_line(&c->pos, &ray, &hit);
                dir.x = ray.d.x;
                dir.y = ray.d.y;
                dir.z = ray.d.z;
                TObjPlayer__sub_80325D58(arg0, (Vec_80325D58 *)&pos, (Vec_80325D58 *)&dir, (Vec_80325D58 *)&hit,
                                         ((TObjBoss2Tunnel *)(&dir))->update_scale());
                TBoss8Dragon__sub_80063FB8(inst, &hit, 6.0f);
            }
            i++;
        } while (i < 4);
    }
}
}

#pragma push
#pragma fp_contract on
void TBoss5GryphonLightningHorn::rebuild_lightning_segments() {
    Wing_80326074 *self = (Wing_80326074 *)this;
    Vec_80326074 q;
    Vec_80326074 p;
    Vec_80326074 d;
    Hit_80326074 *hit;
    f32 h;
    f32 len;
    s32 i;
    f32 r;
    get_wing_position__26TBoss5GryphonLightningWingFl(self, &p);
    p.x += self->vel.x;
    p.y += self->vel.y;
    p.z += self->vel.z;
    p.y = 60.0f;
    hit = (Hit_80326074 *)csnVecterUnder((s32)&p, 0x16EF);
    if (hit == NULL || (h = hit->pos[1]) > lbl_805D8D48) {
        get_wing_position__26TBoss5GryphonLightningWingFl(self, &p);
        self->vel.x *= 0.5f;
        self->vel.y *= 0.5f;
        self->vel.z *= 0.5f;
    } else {
        p.y = h;
    }
    copy_position__12TBoss8DragonFl(self, &q);
    VecCopy((Vec *)&d, (const Vec *)&p);
    subtract_vector(&d, &q);
    len = ((TObjBoss2Tunnel *)(&d))->update_scale() / (self->n - 1);
    d.x *= len;
    d.y *= len;
    d.z *= len;
    VecCopy((Vec *)&p, (const Vec *)&q);
    for (i = 0; i < self->n; i++) {
        VecCopy((Vec *)&self->segs[i].pos, (const Vec *)&p);
        vec3_add_to(&p, &d);
    }
    r = 25.0f * ((1.0f / 32768.0f) * (f32)rand()) + 10.0f;
    for (i = 1; i < self->n - 1; i++) {
        self->segs[i].pos.y += r;
    }
    ((TBoss5GryphonLightningWing *)self)->update_wing_segments();
}
#pragma pop

void TBoss5GryphonLightningHorn::render() {}

void TBoss5GryphonLightningHorn::run_task() {
    rebuild_lightning_segments();
    fn_80325F7C(this);
    spawn_gryphon_lightning();
}

TBoss5GryphonLightningHorn::~TBoss5GryphonLightningHorn() {}

extern "C" {
u8 *__ct__26TBoss5GryphonLightningHornFv(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 temp_f1;
    TBoss5GryphonLightning__ct(10.0f);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TBoss5GryphonLightningHorn;
    *(const char **)((s8 *)arg0 + 0) = TBoss5GryphonLightningHorn__name;
    *(s32 *)((s8 *)arg0 + 0xA4) = arg3;
    temp_f1 = 5.0f * sin_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0xA4)));
    *(f32 *)((s8 *)arg0 + 0x98) = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x9C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xA0) = (f32) (5.0f * cos_table_lookup((int) (*(s32 *)((s8 *)arg0 + 0xA4)), temp_f1, 5.0f));
    *(f32 *)((s8 *)arg0 + 0x8C) = 1.0f;
    *(s32 *)((s8 *)arg0 + 0x90) = 4;
    return arg0;
}
}

s32 TBoss8Dragon::spawn_ground_lightning(s32 arg0, s32 arg1, s32 arg2) {
    Vec position;
    f32 ground_height;
    s32 allocation;
    s32 effect;
    u8* collision;
    VecCopy(&position, (const Vec *)arg1);
    collision = (u8 *)csnVecterUnder((s32)((s32*)&position), 0x16EF);
    if (collision == NULL) {
        position.y = lbl_805D8D48;
    } else {
        ground_height = *(f32*)((s8 *)(*(u8**)((s8 *)collision + 4)) + 4);
        if (ground_height > lbl_805D8D48) {
            position.y = lbl_805D8D48;
        } else {
            position.y = ground_height;
        }
    }
    position.y += 12.0f;
    allocation = __nw__7TObjectFUl(0xA8);
    effect = allocation;
    if (effect != 0) {
        effect = (s32)__ct__26TBoss5GryphonLightningHornFv((u8*)allocation, arg0, (s32)&position, arg2);
    }
    return effect;
}
