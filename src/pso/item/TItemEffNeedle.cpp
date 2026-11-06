// The needle effects a weapon leaves where it hits. Built with deferred code
// generation, so its functions come out in reverse source order.
#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/item/TItemEffNeedle.h"
#include "pso/TMainTask.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TParticleCtrl_800867E4.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/model_render_state.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include <stdlib.h>

const char *TItemEffNeedleBase__class_name = "TItemEffNeedleBase";
const char *TItemEffNeedle__class_name = "TItemEffNeedle";
const char *TItemEffNeedlePos__class_name = "TItemEffNeedlePos";

int TItemEffNeedleBase::update_attachment() {
    return 1;
}

TItemEffNeedleBase::~TItemEffNeedleBase() {}

TItemEffNeedle::~TItemEffNeedle() {}

TItemEffNeedleBase::TItemEffNeedleBase(TObject *parent, TItem *item) : TObject(parent) {
    m_name = TItemEffNeedleBase__class_name;
    item_id = item->get_item_id();
    rotation[1] = item->rotation_y;
    rotation[2] = 0;
    rotation[0] = 0;
    model = NULL;
    texlist = 0;
    material_color.b = 0.0f;
    material_color.g = 0.0f;
    material_color.r = 0.0f;
    material_color.a = 0.0f;
    disallow_rendering();
}

void TItemEffNeedleBase::run_task() {
    if (find_equipped_item(item_id) == NULL) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    allow_rendering();
    if (update_attachment() != 0) {
        material_color.a -= 1.0f / 30.0f;
        if (material_color.a <= -1.0f) {
            queue_destruction();
        }
    }
}

void TItemEffNeedleBase::render() {
    if (all_parents_unqueued_for_destruction() == 0 || find_equipped_item(item_id) == NULL) {
        return;
    }
    if (model != NULL) {
        saved_model_render_flags = model_render_flags;
        model_render_flags = saved_model_render_flags | 0x20;
        copy_argb(&saved_model_draw_color, &model_material_color);
        set_constant_material(&material_color);
        set_texlist(texlist);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_by_node_angles(rotation, 1);
        draw_ginja_object(model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
    }
}

void spawn_target_needle(TObject *parent, TItemEquipBase *weapon, u16 target_id, s32 body_index) {
    if (target_id != 0xFFFF && weapon != NULL) {
        TItemEffNeedle *needle = new TItemEffNeedle(parent, weapon, target_id, body_index);
        if (needle != NULL) {
            needle->model = weapon->second_model;
            needle->texlist = weapon->get_texlist();
        }
    }
}

void create_needle_effect(s32 item_id, ActorBodyHit *hit) {
    TItem *item = find_item_by_id(item_id);
    // The needle is given the target's body count as its body, not hit->body.
    TItemEffNeedle *needle = new TItemEffNeedle(tl_05, item, get_entity_id(hit->target), hit->target->body_count);
    if (needle != NULL) {
        needle->model = item->get_item_model();
        needle->texlist = item->get_texlist();
        needle->rotation[0] += 0x8000;
    }
    create_timed_particle_emitter(&hit->target->bodies[hit->body].center, 0x180, 0, 60);
}

TItemEffNeedle::TItemEffNeedle(TObject *parent, TItem *item, u16 target_id, s32 body_index)
    : TItemEffNeedleBase(parent, item) {
    m_name = TItemEffNeedle__class_name;
    this->target_id = target_id;
    this->body_index = body_index;
    TObjCollidable *target = find_entity_by_id(this->target_id);
    if (target != NULL) {
        VecCopy(&position, &target->bodies[this->body_index].center);
        copy_xyz(rotation_offset, rotation);
        rotation_offset[1] -= target->rotation_y;
    }
}

int TItemEffNeedle::update_attachment() {
    TObjCollidable *target = find_entity_by_id(target_id);
    if (target == NULL) {
        queue_destruction();
        return 0;
    }
    VecCopy(&position, &target->bodies[body_index].center);
    rotation[1] = rotation_offset[1] + target->rotation_y;
    return 1;
}

void spawn_needle_wall_impact(TObject *parent, TItemEquipBase *weapon, const Vec *from, Vec *hit) {
    if (parent != NULL && from != NULL && weapon != NULL && hit != NULL) {
        Vec dir = *hit;
        subtract_vector(&dir, from);
        TItemEffNeedlePos *needle = new TItemEffNeedlePos(parent, weapon, hit, &dir);
        if (needle != NULL) {
            needle->model = weapon->second_model;
            needle->texlist = weapon->get_texlist();
        }
    }
}

void create_needle_pos_effect(s32 item_id, const Vec *pos, Vec *dir) {
    TItem *item = find_item_by_id(item_id);
    TItemEffNeedlePos *needle = new TItemEffNeedlePos(tl_05, item, pos, dir);
    if (needle != NULL) {
        needle->model = item->get_item_model();
        needle->texlist = item->get_texlist();
        needle->rotation[0] += 0x8000;
    }
    Vec at = *pos;
    create_timed_particle_emitter(&at, 0x180, 0, 60);
}

#pragma fp_contract on
TItemEffNeedlePos::TItemEffNeedlePos(TObject *parent, TItem *item, const Vec *pos, Vec *dir)
    : TItemEffNeedleBase(parent, item) {
    m_name = TItemEffNeedlePos__class_name;
    VecCopy(&position, pos);
    position.x += (1.0f / 32768.0f) * rand();
    position.y += (1.0f / 32768.0f) * rand();
    position.z += (1.0f / 32768.0f) * rand();
    rotation[1] = 10430.38043493439 * atan2_float(dir->x, dir->z);
    if (0.0f != dir->y) {
        rotation[0] = 10430.38043493439 * atan2_float(dir->y, newton_sqrtf(dir->x * dir->x + dir->z * dir->z));
        rotation[2] = 0;
    } else {
        rotation[2] = 0;
        rotation[0] = 0;
    }
}
