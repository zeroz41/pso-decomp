#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include <stdlib.h>
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
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D853C.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixTransforms.h"

#pragma readonly_strings on

const char *TBoss5GryphonLightningHorn__name = "TBoss5GryphonLightningHorn";

struct Ray_80325F7C { Vec o; Vec d; };

struct Ctl_80325F7C { u8 pad[0x38]; Vec pos; };

typedef struct Seg_80326074 { Vec pos; f32 pad; } Seg_80326074;

typedef struct Hit_80326074 { u8 pad[4]; f32 *pos; } Hit_80326074;

typedef struct Wing_80326074 {
    u8 pad0[0x48];
    Seg_80326074 segs[4];
    u8 pad88[8];
    s32 n;
    u8 pad94[4];
    Vec vel;
} Wing_80326074;

extern "C" {
void apply_lightning_hit(s32, void *, f32);
Ctl_80325F7C *get_player_by_client_id(s32);
void project_point_onto_line(void *, void *, void *);
extern const f32 lbl_805D8D48;
f32 sin_table_lookup(int);
f32 cos_table_lookup(int, f32, f32);

void TBoss5GryphonLightningHorn::queue_destruction() { TObject::queue_destruction(); }

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
s32 TObjPlayer__sub_80325D58(void *self, Vec *from, Vec *dir, Vec *to, f32 dist) {
    Vec d;
    Vec n;
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

void fn_80325F7C(void *self) {
    Ray_80325F7C ray;
    Vec pos;
    Vec wing;
    Vec hit;
    Vec dir;
    s32 inst;
    s32 i;
    Ctl_80325F7C *c;
    inst = TBoss8Dragon::get_instance_count();
    if (inst != 0) {
        i = 0;
        do {
            c = get_player_by_client_id(i);
            if (c != 0) {
                ((TBoss5GryphonLightningWing *)self)->copy_position(&pos);
                ((TBoss5GryphonLightningWing *)self)->get_wing_position(&wing);
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
                TObjPlayer__sub_80325D58(self, (Vec *)&pos, (Vec *)&dir, (Vec *)&hit,
                                         normalize_vector_safe(&dir));
                apply_lightning_hit(inst, &hit, 6.0f);
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
    Vec q;
    Vec p;
    Vec d;
    Hit_80326074 *hit;
    f32 h;
    f32 len;
    s32 i;
    f32 r;
    ((TBoss5GryphonLightningWing *)self)->get_wing_position(&p);
    p.x += self->vel.x;
    p.y += self->vel.y;
    p.z += self->vel.z;
    p.y = 60.0f;
    hit = (Hit_80326074 *)csnVecterUnder(&p, 0x16EF);
    if (hit == NULL || (h = hit->pos[1]) > lbl_805D8D48) {
        ((TBoss5GryphonLightningWing *)self)->get_wing_position(&p);
        self->vel.x *= 0.5f;
        self->vel.y *= 0.5f;
        self->vel.z *= 0.5f;
    } else {
        p.y = h;
    }
    ((TBoss5GryphonLightningWing *)self)->copy_position(&q);
    VecCopy((Vec *)&d, (const Vec *)&p);
    subtract_vector(&d, &q);
    len = normalize_vector_safe(&d) / (self->n - 1);
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


TBoss5GryphonLightningHorn::TBoss5GryphonLightningHorn(TObject *parent, Vec *pos, s32 rotation_y) : TBoss5GryphonLightning(parent, pos, 10.0f) {
    f32 temp_f1;
    m_name = TBoss5GryphonLightningHorn__name;
    this->rotation_y = rotation_y;
    temp_f1 = 5.0f * sin_table_lookup(this->rotation_y);
    this->velocity.x = temp_f1;
    this->velocity.y = 0.0f;
    this->velocity.z = 5.0f * cos_table_lookup(this->rotation_y, temp_f1, 5.0f);
    this->grow_progress = 1.0f;
    this->segment_count = 4;
}

TBoss5GryphonLightningHorn *TBoss5GryphonLightningHorn::spawn_ground_lightning(TObject *parent, Vec *pos, s32 rotation_y) {
    Vec position;
    f32 ground_height;
    u8* collision;
    VecCopy(&position, pos);
    collision = (u8 *)csnVecterUnder(&position, 0x16EF);
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
    return new TBoss5GryphonLightningHorn(parent, &position, rotation_y);
}
