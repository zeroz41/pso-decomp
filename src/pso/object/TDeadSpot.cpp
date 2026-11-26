#pragma defer_codegen on

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/ParticleStrip.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/TDeadSpot.h"
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803DA798.h"
#include "pso/system/vector.h"
#include "pso/unk/TDeadSpotGroundEmitter.h"
#include "pso/unk/TDeadSpotEmitter.h"
#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include <stddef.h>
#include "pso/system/task/TMainTask.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/unk/text_803D8DE0.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/boss/derolle/RandomAngle.h"
#include "pso/render/model_render_state.h"

struct CornerRow {
    u8 pad[0x88];
    Vec corners[4];
};

extern "C" {
extern const f32 lbl_805DA380;

#pragma push
#pragma readonly_strings on
const char *dead_spot_class_name = "TDeadSpot";
}
#pragma pop



#pragma push
#pragma fp_contract on
#pragma opt_common_subs off

TDeadSpot::TDeadSpot(TObject *parent, const Vec *point, NJS_TEXLIST *texture, s32 selector, s32 delay, f32 maxScale) : TObject(parent) {
    Vec basis[2];
    Vec probe;
    Vec tmp;
    s32 yaw;
    s32 pitch;
    CsnHit *ground;
    f32 n1x, n1y, n1z;
    f32 scale;
    f32 first;
    f32 second;
    f32 b0x, b0y, b0z, b1x, b1y, b1z;
    s32 bad;
    s32 i;
    m_name = dead_spot_class_name;
    this->texture = texture;
    this->selector = selector;
    max_scale = maxScale;
    this->scale = -(0.2f * (f32)delay);
    verts[0].u = 0.0f;
    verts[0].v = 0.0f;
    verts[0].color = -1;
    verts[1].u = 0.0f;
    verts[1].v = 1.0f;
    verts[1].color = -1;
    verts[2].u = 1.0f;
    verts[2].v = 0.0f;
    verts[2].color = -1;
    verts[3].u = 1.0f;
    verts[3].v = 1.0f;
    verts[3].color = -1;
    VecCopy(&probe, point);
    probe.y += 5.0f;
    ground = csnVecterUnder(&probe, 0x16EF);
    if (ground == NULL) {
        (this)->queue_destruction();
        return;
    }
    VecCopy(&center, &ground->contact->point);
    center.y += 0.5f * (3.0517578125e-05f * (f32)rand()) + 0.213456f;
    basis[0].x = 0.0f;
    basis[0].y = 0.0f;
    basis[0].z = 1.0f;
    basis[1].x = 0.0f;
    basis[1].y = 1.0f;
    basis[1].z = 0.0f;
    direction_to_rotation_yx((u8 *)&ground->contact->normal, &yaw, &pitch);
    if (pitch < 0x3000 || pitch > 0x5000) {
        (this)->queue_destruction();
        return;
    }
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y(0, yaw);
    rotate_matrix_z(0, pitch);
    rotate_matrix_x(0, random_angle());
    mult_vec_array_sr(0, basis, basis, 2);
    pop_matrix();
    b0x = basis[0].x;
    b0y = basis[0].y;
    b0z = basis[0].z;
    b1x = basis[1].x;
    b1y = basis[1].y;
    b1z = basis[1].z;
    first = random_range(0.35f, 1.55f);
    second = random_range(0.35f, 1.55f);
    corners[0].x = b1x * second + b0x * first;
    corners[0].y = b1y * second + b0y * first;
    corners[0].z = b1z * second + b0z * first;
    first = random_range(0.35f, 1.55f);
    second = random_range(0.35f, 1.55f);
    corners[1].x = b1x * second - b0x * first;
    corners[1].y = b1y * second - b0y * first;
    corners[1].z = b1z * second - b0z * first;
    first = random_range(0.35f, 1.55f);
    second = random_range(0.35f, 1.55f);
    n1x = -b1x;
    n1y = -b1y;
    n1z = -b1z;
    corners[2].x = n1x * second + b0x * first;
    corners[2].y = n1y * second + b0y * first;
    corners[2].z = n1z * second + b0z * first;
    first = random_range(0.35f, 1.55f);
    second = random_range(0.35f, 1.55f);
    corners[3].x = n1x * second - b0x * first;
    corners[3].y = n1y * second - b0y * first;
    corners[3].z = n1z * second - b0z * first;
    scale = max_scale;
    if (scale > 5.0f) {
        for (i = 0; i < 4; i++) {
            VecCopy(&tmp, &center);
            // Row i of the corners, reached from this + 12 * i as the original does.
            CornerRow *c = (CornerRow *)((u8 *)this + i * 12);
            tmp.x += c->corners[0].x * scale;
            tmp.y += c->corners[0].y * scale;
            tmp.z += corners[i].z * scale;
            bad = 0;
            ground = csnVecterUnder(&tmp, 0x16EF);
            if (ground != NULL) {
                if (ground->contact->point.y - tmp.y < -3.0f) {
                    bad = 1;
                }
            } else {
                bad = 1;
            }
            if (bad != 0) {
                corners[i].x *= 0.2f;
                corners[i].y *= 0.2f;
                corners[i].z *= 0.2f;
            }
        }
    }
}

TDeadSpot::~TDeadSpot() {}
#pragma pop
#pragma push
#pragma fp_contract on
void TDeadSpot::run_task() {
    ParticleStripVertex *p;
    s32 i;
    f32 bx, by, bz;
    if (scale <= max_scale) {
        scale += 0.2f;
        if (scale <= 0.0f) {
            return;
        }
        p = verts;
        bx = center.x;
        by = center.y;
        bz = center.z;
        for (i = 0; i < 4; i++) {
            p->x = corners[i].x * scale + bx;
            p->y = corners[i].y * scale + by;
            p->z = corners[i].z * scale + bz;
            p++;
        }
    }
}
#pragma pop
void TDeadSpot::render() {
    if ((TMainTask::get_render_pass() != 1) && (scale > 0.0f) && (horizontal_distance_squared(&center, &camera_ctrl_instance->pos) < 22500.0f)) {
        saved_model_render_flags = model_render_flags;
        set_default_alpha_blend();
        setup_alpha_test_render_state(0x8F);
        TObjFish::set_global_param(texture);
        set_texture_num(selector);
        draw_particle_strip(verts, 4, 1);
        restore_saved_depth_alpha_state();
        model_render_flags = saved_model_render_flags;
    }
}
#pragma push
#pragma fp_contract on
TUnk_80494A10::TUnk_80494A10(TObject *parent, const Vec *point, NJS_TEXLIST *texture, s32 selector, s32 delay, f32 maxScale) : TDeadSpot(parent, point, texture, selector, delay, maxScale) {
    ParticleStripVertex *p;
    s32 i;
    f32 bx, by, bz, s;
    p = verts;
    alpha = 0.0f;
    s = max_scale;
    bx = center.x;
    by = center.y;
    bz = center.z;
    for (i = 0; i < 4; i++) {
        p->x = corners[i].x * s + bx;
        p->y = corners[i].y * s + by;
        p->z = corners[i].z * s + bz;
        p->color = 0xFFFFFF;
        p++;
    }
}
#pragma pop
TUnk_80494A10::~TUnk_80494A10() {}

void TUnk_80494A10::run_task() {
    ParticleStripVertex *p;
    s32 i;
    u32 c;
    if (scale <= max_scale) {
        scale += 0.2f;
        if (scale <= 0.0f) {
            return;
        }
    }
    if (alpha < 1.0f) {
        alpha += 0.05f;
        if (alpha > 1.0f) {
            alpha = 1.0f;
        }
        p = verts;
        c = (u32)(255.0f * alpha) << 24 | 0xFF0000 | 0xFFFF;
        for (i = 0; i < 4; i++) {
            p->color = c;
            p++;
        }
    }
}
#pragma push
#pragma fp_contract on
TDeadSpotEmitter::TDeadSpotEmitter(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius) : TObject(parent) {
    VecCopy(&this->position, position);
    this->radius = radius;
    timer = 0;
    interval = 2;
    this->emitter = emitter;
}
#pragma pop
TDeadSpotEmitter::~TDeadSpotEmitter() {}

void TDeadSpotEmitter::place_emitter() {
  Vec stack;
  f32 x;
  s32 angle;
  angle = random_angle();
  x = radius * sin_table_lookup((int) (angle & 0xFFFFFFFFu));
  stack.y = lbl_805DA380;
  stack.x = x;
  stack.z = radius * cos_table_lookup((int) angle);
  vec3_add_to(&stack, &position);
  emitter->set_position(&stack.x);
}

void TDeadSpotEmitter::run_task() {
    if (emitter == NULL || emitter->all_parents_unqueued_for_destruction() == 0) {
        queue_destruction();
        return;
    }
    timer++;
    if (timer >= interval) {
        timer = 0;
        place_emitter();
    }
}

TDeadSpotGroundEmitter::TDeadSpotGroundEmitter(TObject *parent, Vec *position, TParticleCtrl *emitter, f32 radius) : TDeadSpotEmitter(parent, position, emitter, radius) {
    interval = 8;
}

TDeadSpotGroundEmitter::~TDeadSpotGroundEmitter() {}
#pragma push
#pragma opt_common_subs off
void TDeadSpotGroundEmitter::place_emitter() {
    Vec stack;
    f32 x;
    s32 angle;
    angle = random_angle();
    x = radius * sin_table_lookup(angle);
    stack.y = lbl_805DA380;
    stack.x = x;
    stack.z = radius * cos_table_lookup(angle);
    vec3_add_to(&stack, &position);
    TObjBoss2Tunnel::adjust_to_ground(&stack, &stack);
    emitter->set_position(&stack.x);
}

#pragma pop
