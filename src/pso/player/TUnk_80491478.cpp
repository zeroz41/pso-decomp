#include "types.h"
#include "pso/player/TUnk_80491478.h"
#include "pso/enemy/dubchik/TObjEneDubchik.h"
#include "pso/effect/enemy/TeneFakeTecThunderEff.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/map/CsnQuery.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/model_render_state.h"
#include "pso/object/ambient/TObjFish.h"

// The model node of each of the three parts in the dubchik's model.
static const s32 part_model_nodes[3] = {0x14, 0x2B, 0x17};

// Written last-to-first: the TU was compiled with deferred codegen, which emits the
// functions (and the vtables, by key function) in reverse definition order.
#pragma defer_codegen on

TUnk_80491478::TUnk_80491478(s32 index, TObjEneDubchik *parent, NJS_TEXLIST *texlist, Vec *offset) : TObjCollidable(tl_06) {
    Vec v;
    Vec out;
    TObject *effect;
    CsnHit *hit;
    s32 node;
    part_index = index;
    parent_id = get_entity_id(parent);
    m_ae = 0;
    node = part_model_nodes[index];
    m_d8 = texlist;
    m_c8 = find_model_node(dubchik_resource->mdl[1].f8, node);
    target = &parent->part_offsets[index];
    VecCopy(&pos, VecCopy(&origin, offset));
    m_e8 = 3.0f + parent->position.y;
    push_matrix_from(&identity_matrix);
    v.x = v.y = 0.0f;
    v.z = -2.0f;
    rotate_matrix_y(0, parent->rotation_y + ((index - 1) << 0xD));
    rotate_vector_by_matrix(0, &v, &velocity);
    v.z = range = 30.0f;
    rotate_vector_by_matrix(0, &v, &out);
    vec3_add_to(&out, &pos);
    hit = csnLookAt(&pos, &out);
    if (hit != NULL) {
        range = (10.0f > vec_xz_distance(&pos, &hit->contact->point) - 5.0f) ? 10.0f : vec_xz_distance(&pos, &hit->contact->point) - 5.0f;
    }
    pop_matrix();
    velocity.y = 0.0f;
    effect = (TObject *)TObject::operator new(0x348);
    if (effect != NULL) {
        effect = (TObject *)TObjPlayer__sub_800A4204((u8 *)effect, (u8 *)this, (s32)target, (s32)&pos, 0x10);
    }
    m_d0 = effect;
    if (m_d0 != NULL) {
        ((TObjPlayer *)m_d0)->clear_counter();
    }
}

TUnk_80491478::~TUnk_80491478() {
    if (m_d0 != NULL) {
        m_d0->queue_destruction();
        m_d0 = NULL;
    }
}

#pragma push
#pragma fp_contract on
void TUnk_80491478::run_task() {
    f32 t;
    f32 step;
    f32 dist_sq;
    switch (m_ae) {
    case 0: {
        Vec v = pos;
        v.x += velocity.x;
        v.z += velocity.z;
        v.y += 5.0f;
        if (project_actor_to_ground((TObjChara *)this, &v, 0) == 1) {
            pos.x = v.x;
            pos.z = v.z;
            if (pos.y < v.y) {
                pos.y = v.y;
                velocity.y = 0.6f * fabs_float(velocity.y);
            }
            if ((v.y - m_e8) > 2.0f) {
                m_ae = 1;
            } else {
                m_e8 = v.y;
            }
        }
        if (xz_distance_squared(&pos, &origin) >= range * range) {
            m_ae = 1;
        }
    }
    case 1:
        pos.y += velocity.y;
        velocity.y += -0.10888889f;
        if (pos.y < m_e8) {
            pos.y = m_e8;
            velocity.y = 0.0f;
        }
        break;
    case 2:
        VecCopy(&velocity, target);
        subtract_vector(&velocity, &pos);
        dist_sq = velocity.x * velocity.x + velocity.z * velocity.z;
        if (dist_sq > 25.0f) {
            t = 0.8f / newton_sqrtf(dist_sq);
            pos.x = velocity.x * t + pos.x;
            pos.z = velocity.z * t + pos.z;
        } else if (fabs_float(velocity.y) > 5.0f) {
            if (velocity.y > 0.0f) {
                step = 0.8f;
            } else {
                step = -0.8f;
            }
            pos.y += step;
        } else {
            m_ae = 3;
        }
        break;
    case 3:
        VecCopy(&pos, target);
        break;
    }
}
#pragma pop

void TUnk_80491478::render() {
    TObjFish::set_global_param((s32)dubchik_texlist);
    TObjFish::set_global_param((s32)m_d8);
    push_matrix();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(0, rot_y);
    scale_matrix(0, 1.3f, 1.3f, 1.3f);
    model_render_flags &= 0xFFFFFBFF;
    draw_chunk_object((void *)m_c8);
    pop_matrix();
}

s32 TUnk_80491478::get_action_priority() {
    if (m_ae == 3) {
        return 1;
    }
    return 0;
}

void TUnk_80491478::cancel_action() {
    if (get_action_priority() != 1) {
        if (m_d0 != NULL) {
            ((TObjPlayer *)m_d0)->set_cancel_flag();
        }
        m_ae = 2;
    }
}
