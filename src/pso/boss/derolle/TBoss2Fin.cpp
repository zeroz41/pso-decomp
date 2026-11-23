#include "pso/boss/derolle/TBoss2Fin.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResource.h"
#include "pso/object/TObjEZRopeBase.h"
#include "pso/object/ambient/TObjFish.h"
#include "types.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/InverseTrig.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"

const char *TBoss2Fin__name = "TBoss2Fin";
// The pull run_task() hands to the rope update every frame.
extern const Vec boss2_fin_gravity = { 0.0f, 0.0f, -2.0f };

void TBoss2Fin::render() {
    TObjEZRopeSegment *seg;
    TObjEZRopeEnd *end;
    Vec *pt;
    s32 j;
    s32 yaw;
    Vec v;
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(boss2_derolle_resource->models[2].texlist));
    seg = segments;
    end = ends;
    pt = points;
    for (; seg->count >= 2; pt++, seg++, end++) {
        for (j = seg->count - 1; j > 0; j--, pt++) {
            push_matrix();
            translate_matrix_vec3(NULL, (u8 *)pt);
            VecCopy(&v, pt + 1);
            subtract_vector(&v, pt);
            if (0.0f == vector_length(&v)) {
                v.x = 0.0f;
                v.y = -1.0f;
                v.z = 0.0f;
            } else {
                normalize_vector(&v);
            }
            yaw = 0;
            if (0.0f != fabs_float(v.x) + fabs_float(v.z)) {
                yaw = (65536.0 / (2.0 * 3.141592f)) * atan2_float(-v.x, -v.z);
                rotate_matrix_y(0, yaw);
            }
            rotate_matrix_x(0, (65536.0 / (2.0 * 3.141592f)) * acosf(-v.y));
            rotate_matrix_y(0, end->twist - yaw);
            push_matrix();
            scale_matrix(0, boss2_model_scale, boss2_model_scale, boss2_model_scale);
            rotate_matrix_x(0, -0x4000);
            if (j == 1) {
                if (seg->tip_model != NULL) {
                    draw_chunk_object(seg->tip_model);
                }
            } else if (seg->body_model != NULL) {
                draw_chunk_object(seg->body_model);
            }
            pop_matrix();
            pop_matrix();
        }
    }
    current_scene_light->sub_801337F8();
}

void TBoss2Fin::run_task() {
    init_link_points();
    Vec gravity = boss2_fin_gravity;
    update_ropes(&gravity);
}

void TBoss2Fin::init_link_points() {
    rope_ends[0].twist = 0;
    VecCopy(&rope_ends[0].pos, anchor_a);
    VecCopy(&rope_colliders[0].center, anchor_a);
    rope_colliders[0].center.y -= 7.07f;
    rope_colliders[0].center.z += 7.07f;
    rope_ends[1].twist = 0;
    VecCopy(&rope_ends[1].pos, anchor_b);
    VecCopy(&rope_colliders[1].center, anchor_b);
    rope_colliders[1].center.y -= 7.07f;
    rope_colliders[1].center.z += 7.07f;
}

TBoss2Fin::~TBoss2Fin() {}

// The fins' two ropes (six points each), then the end marker.
TObjEZRopeSegment TBoss2Fin__effect_table[3];

TBoss2Fin::TBoss2Fin(TObject *parent, Vec *first_anchor, Vec *second_anchor) : TObjEZRopeBase(parent) {
    s32 i;
    TObjEZRopeCollider *collider;
    m_name = TBoss2Fin__name;
    anchor_a = first_anchor;
    anchor_b = second_anchor;
    collider = rope_colliders;
    for (i = 0; i < 2; i++, collider++) {
        collider->radius = 10.0f;
        collider->center.x = 0.0f;
        collider->center.y = 0.0f;
        collider->center.z = 0.0f;
    }
    collider->radius = -1.0f;
    init_link_points();
    init_ropes(TBoss2Fin__effect_table, rope_ends, rope_colliders);
}

void TBoss2Fin::release_effect_table() {}

void TBoss2Fin::init_effect_table() {
    TObjEZRopeSegment *seg = TBoss2Fin__effect_table;
    s32 i;
    for (i = 0; i < 2; i++) {
        seg->count = 6;
        seg->step.x = 0.0f;
        seg->step.y = 0.0f;
        seg->step.z = -5.0f;
        seg->body_model = boss2_derolle_resource->models[1].model;
        seg->tip_model = boss2_derolle_resource->models[0].model;
        seg++;
    }
    seg->count = -1;
}

f32 acosf(f32 x) {
    return acos(x);
}
