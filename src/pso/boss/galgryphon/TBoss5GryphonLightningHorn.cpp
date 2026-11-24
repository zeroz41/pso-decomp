#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
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
#include "pso/math/AngleLookup.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_803E18C0.h"

#pragma readonly_strings on

const char *TBoss5GryphonLightningHorn__name = "TBoss5GryphonLightningHorn";

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
s32 TBoss5GryphonLightningHorn::clamp_to_segment(Vec *from, Vec *dir, Vec *to, f32 dist) {
    Vec d;
    Vec n;
    f32 t;
    d.x = to->x - from->x;
    d.y = to->y - from->y;
    d.z = to->z - from->z;
    t = vec3_dot(dir, &d);
    if (0.0f > t) {
        VecCopy(to, from);
        return 1;
    }
    if (1.0f != t) {
        VecCopy(&n, &d);
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

void TBoss5GryphonLightningHorn::apply_lightning_effect() {
    Line ray;
    Vec pos;
    Vec wing;
    Vec hit;
    Vec dir;
    TBoss5Gryphon *inst;
    s32 i;
    TObjPlayer *c;
    inst = TBoss5Gryphon::get_instance();
    if (inst != NULL) {
        i = 0;
        do {
            c = get_player_by_client_id(i);
            if (c != 0) {
                get_start_position(&pos);
                get_end_position(&wing);
                ray.o.x = pos.x;
                ray.o.y = c->position.y;
                ray.o.z = pos.z;
                ray.d.x = wing.x - pos.x;
                ray.d.y = 0.0f;
                ray.d.z = wing.z - pos.z;
                project_point_onto_line(&c->position, &ray, &hit);
                dir.x = ray.d.x;
                dir.y = ray.d.y;
                dir.z = ray.d.z;
                clamp_to_segment(&pos, &dir, &hit, normalize_vector_safe(&dir));
                TBoss5Gryphon::apply_lightning_hit(inst, &hit, 6.0f);
            }
            i++;
        } while (i < 4);
    }
}

#pragma push
#pragma fp_contract on
void TBoss5GryphonLightningHorn::rebuild_lightning_segments() {
    Vec q;
    Vec p;
    Vec d;
    CsnHit *hit;
    f32 h;
    f32 len;
    s32 i;
    f32 r;
    this->get_end_position(&p);
    p.x += velocity.x;
    p.y += velocity.y;
    p.z += velocity.z;
    p.y = 60.0f;
    hit = csnVecterUnder(&p, 0x16EF);
    if (hit == NULL || (h = hit->contact->point.y) > gryphon_max_floor_height) {
        this->get_end_position(&p);
        velocity.x *= 0.5f;
        velocity.y *= 0.5f;
        velocity.z *= 0.5f;
    } else {
        p.y = h;
    }
    this->get_start_position(&q);
    VecCopy(&d, &p);
    subtract_vector(&d, &q);
    len = normalize_vector_safe(&d) / (segment_count - 1);
    d.x *= len;
    d.y *= len;
    d.z *= len;
    VecCopy(&p, &q);
    for (i = 0; i < segment_count; i++) {
        VecCopy(&segments[i].pos, &p);
        vec3_add_to(&p, &d);
    }
    r = 25.0f * ((1.0f / 32768.0f) * (f32)rand()) + 10.0f;
    for (i = 1; i < segment_count - 1; i++) {
        segments[i].pos.y += r;
    }
    this->update_endpoints();
}
#pragma pop

void TBoss5GryphonLightningHorn::render() {}

void TBoss5GryphonLightningHorn::run_task() {
    rebuild_lightning_segments();
    apply_lightning_effect();
    spawn_gryphon_lightning();
}

TBoss5GryphonLightningHorn::~TBoss5GryphonLightningHorn() {}


TBoss5GryphonLightningHorn::TBoss5GryphonLightningHorn(TObject *parent, Vec *pos, s32 rotation_y) : TBoss5GryphonLightning(parent, pos, 10.0f) {
    m_name = TBoss5GryphonLightningHorn__name;
    this->rotation_y = rotation_y;
    velocity.x = 5.0f * sin_table_lookup(this->rotation_y);
    velocity.y = 0.0f;
    velocity.z = 5.0f * cos_table_lookup(this->rotation_y);
    this->grow_progress = 1.0f;
    this->segment_count = 4;
}

TBoss5GryphonLightningHorn *TBoss5GryphonLightningHorn::spawn_ground_lightning(TObject *parent, Vec *pos, s32 rotation_y) {
    Vec position;
    f32 ground_height;
    CsnHit *hit;
    VecCopy(&position, pos);
    hit = csnVecterUnder(&position, 0x16EF);
    if (hit == NULL) {
        position.y = gryphon_max_floor_height;
    } else {
        ground_height = hit->contact->point.y;
        if (ground_height > gryphon_max_floor_height) {
            position.y = gryphon_max_floor_height;
        } else {
            position.y = ground_height;
        }
    }
    position.y += 12.0f;
    return new TBoss5GryphonLightningHorn(parent, &position, rotation_y);
}
