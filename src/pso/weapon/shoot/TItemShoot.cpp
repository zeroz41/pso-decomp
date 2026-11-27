// TItemShoot.cpp: the weapon shot objects (TItemShoot and its model, particle,
// gun and rotating-model shots) and the shot creators the weapon tables call.
//
// One TU: the class-name strings of all five classes and the gun's star-light
// parameters share one .rodata block and one .sdata block, the [0.0, 255.0, 1.0]
// .sdata2 pool is shared, and the five vtables sit in one .data block.
// The vtables come out RotZ, Gun, Particle, Model, Shoot (the .text order), so
// the file is built with deferred code generation and written from its last
// function back (configure.py).
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/GinjaMaterialTextureSlot.h"
#include "types.h"
#include "pso/weapon/shoot/TItemShoot.h"
#include "pso/weapon/shoot/TItemShootModel.h"
#include "pso/weapon/shoot/TItemShootModelRotZ.h"
#include "pso/weapon/shoot/TItemShootParticle.h"
#include "pso/weapon/shoot/TItemShootGun.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemMenuCtrl.h"
#include "pso/effect/TEffStarLight2D.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/door/TObjDoorJung.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"
#include "pso/math/AngleUnits.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/MatrixStack.h"


// The task layers (TMainTask.h), tl_07 read-only: the gun shot's constructor
// loads tl_07 ahead of the last store of its star-light parameter copy, which
// CodeWarrior only does for a const object.
extern TObject *tl_05;
extern TObject *const tl_07;

const char *TItemShoot::class_name = "TItemShoot";
const char *TItemShootModel::class_name = "TItemShootModel";
const char *item_shoot_particle_class_name = "TItemShootParticle";
const char *item_shoot_gun_class_name = "TItemShootGun";
// The gun shot's star light; the colour is filled from the weapon's colour.
const StarLightParameters gun_shot_star_light_parameters = {3.0f, 7.0f, {{0, 0, 0, 0}}, 0, 20.0f};
const char *item_shoot_model_rot_z_class_name = "TItemShootModelRotZ";

TItemShootGun::~TItemShootGun() {}

void TItemShootParticle::set_particle_flags(s16 flags) {
    m_effect_flags = flags;
}

void TItemShoot::hook() {}

void TItemShootGun::set_texture_id(s32 id) {
    texture_id = id;
}

TItemShootModelRotZ::~TItemShootModelRotZ() {}

TItemShoot *spawn_shoot_particle_9f(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life) {
    TItemShootParticle *particle = TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (particle != NULL) {
        particle->set_particle_flags(4);
        particle->spawn_slot_emitter(0x9F, 0);
    }
    return particle;
}

TItemShoot *create_shoot_model_with_particles(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life) {
    TItemShoot *model = TObjPlayer::create_shoot_model(owner, pos, dir, life);
    TItemShootParticle *particle = TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (model != NULL && particle != NULL) {
        ((TItemShootModel *)model)->ang = 0x4000;
        particle->spawn_slot_emitter(0x1BB, 0);
        particle->spawn_slot_emitter(0x1BC, 1);
        particle->set_parent(model);
    }
    return model;
}

TItemShoot *TItemShoot::spawn_shoot_particle_attached(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life) {
    TItemShoot *model = TObjPlayer::create_shoot_model(owner, pos, dir, life);
    TItemShootParticle *particle = TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (model != NULL && particle != NULL) {
        particle->spawn_slot_emitter(0x1BD, 0);
        particle->set_parent(model);
    }
    return model;
}

TItemShoot *TItemShoot::spawn_shoot_particle(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life) {
    TItemShootParticle *particle = TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (particle != NULL) {
        particle->spawn_slot_emitter(0x12, 0);
    }
    return particle;
}

TItemShoot::TItemShoot(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TObject(tl_05) {
    m_name = TItemShoot::class_name;
    VecCopy(&m_pos, pos);
    VecCopy(&m_dir, VecCopy(&end_pos, dir));
    m_life = life;
    subtract_vector(&m_dir, pos);
    f32 len = vector_length(&m_dir);
    normalize_vector(&m_dir);
    f32 scale = len / life;
    m_dir.x *= scale;
    m_dir.y *= scale;
    m_dir.z *= scale;
    rot_y = (s32)(RADIANS_TO_ANGLE * atan2_float(m_dir.x, m_dir.z));
    direction_to_rotation_xz((u8 *)&m_dir, &rot_x, &rot_z);
    star_light = NULL;
    m_owner_item_id = ((TItem *)owner)->get_item_id();
    disallow_rendering();
}

TItemShoot::~TItemShoot() {
    if (star_light != NULL) {
        star_light->queue_destruction();
    }
}

void TItemShoot::run_task() {
    if (find_equipped_item(m_owner_item_id) == NULL) {
        disallow_rendering();
        queue_destruction();
    }
    allow_rendering();
    vec3_add_to(&m_pos, &m_dir);
    if (star_light != NULL) {
        star_light->copy_position(&m_pos);
    }
    hook();
    m_life -= 1.0f;
    if (m_life <= 0.0f) {
        queue_destruction();
    }
}

s32 TItemShootModel::is_owner_alive() {
    if (find_equipped_item(m_owner_item_id) == 0U) {
        return 0;
    }
    return all_parents_unqueued_for_destruction() != 0 ? 1 : 0;
}

TItemShoot *TObjPlayer::create_shoot_model(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life) {
    TItemShootModel *model = NULL;
    if (0.0f != life && owner != NULL) {
        model = new TItemShootModel(owner, pos, dir, life);
    }
    return model;
}

TItemShootModel::TItemShootModel(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShoot(owner, pos, dir, life) {
    m_name = TItemShootModel::class_name;
    model = ((TItemWeapon *)owner)->second_model;
    texture_list = (NJS_TEXLIST *)((TObjBase *)owner)->get_texlist();
    if (0.0f != m_dir.y) {
        f32 horiz = newton_sqrtf(m_dir.x * m_dir.x + m_dir.z * m_dir.z);
        rot_x = -(s32)(RADIANS_TO_ANGLE * atan2_float(m_dir.y, horiz));
        rot_z = 0;
    } else {
        rot_z = 0;
        rot_x = 0;
    }
    m_68 = 0;
    m_64 = 0;
    ang = 0;
}

void TItemShootModel::render() {
    if (is_owner_alive()) {
        if (model != NULL) {
            set_texlist(texture_list);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(&m_pos.x);
            rotate_matrix_by_node_angles(&rot_x, 1);
            rotate_matrix_by_node_angles(&ang, 1);
            draw_ginja_object(model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}

TItemShootParticle *TObjPlayer::spawn_shoot_particle(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life) {
    if (0.0f != life && owner != NULL) {
        return new TItemShootParticle(owner, pos, dir, life);
    }
    return NULL;
}

TItemShootParticle::TItemShootParticle(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShoot(owner, pos, dir, life) {
    s32 i;
    m_name = item_shoot_particle_class_name;
    m_effect_flags = 0;
    for (i = 0; i < 2; i++) {
        m_emitters[i] = NULL;
    }
    disallow_rendering();
}

TItemShootParticle::~TItemShootParticle() {
    s32 i;
    for (i = 0; i != 2; i++) {
        TParticleCtrl::release(m_emitters[i]);
    }
}

// The slot's byte offset stays in one register for indexed loads and stores
// (lwzx/stwx off this); m_emitters[slot] compiles to this + slot * 4 instead.
#pragma push
#pragma opt_propagation off
s32 TItemShootParticle::spawn_slot_emitter(s32 effect_id, s32 slot) {
    s32 offset;
    if (slot >= 0 && slot < 2) {
        offset = slot * 4 + 0x58;
        TParticleCtrl::release(*(TParticleCtrl **)((u8 *)this + offset));
        *(TParticleCtrl **)((u8 *)this + offset) = (TParticleCtrl *)spawn_particle_effect_with_rotation(&m_pos, &rot_x, effect_id, (u16)(m_effect_flags | 0x40));
        return *(s32 *)((u8 *)this + offset);
    }
    return 0;
}
#pragma pop

void TItemShootParticle::hook() {
    s32 i;
    for (i = 0; i != 2; i++) {
        if (m_emitters[i] != NULL) {
            m_emitters[i]->set_position(&m_pos);
            if (m_emitters[i]->all_parents_unqueued_for_destruction() == 0) {
                m_emitters[i] = NULL;
            }
        }
    }
}

TItemShoot *create_gun_shot(TItemWeapon *owner, const Vec *pos, const Vec *endpoint, f32 life) {
    spawn_particle_effect(pos, 9);
    return new TItemShootGun(owner, pos, endpoint, life);
}

TItemShoot *TItemShootGun::create(TItemWeapon *owner, const Vec *pos, const Vec *endpoint, f32 life) {
    TItemShootGun *result;

    spawn_particle_effect(pos, 0x1BF);
    result = new TItemShootGun(owner, pos, endpoint, life);
    if (result != 0) {
        result->set_texture_id(4);
    }
    return result;
}

TItemShootGun::TItemShootGun(void *owner, const Vec *pos, const Vec *endpoint, f32 life)
    : TItemShootModel(owner, pos, endpoint, life) {
    TItemWeapon *weapon = (TItemWeapon *)owner;
    m_name = item_shoot_gun_class_name;
    NJS_ARGB color = weapon->get_weapon_color();
    StarLightParameters params = gun_shot_star_light_parameters;
    params.color.channels.r = (u8)(255.0f * color.r);
    params.color.channels.g = (u8)(255.0f * color.g);
    params.color.channels.b = (u8)(255.0f * color.b);
    star_light = spawn_star_light_2d(&m_pos, &params, tl_07);
    TItemLoad::get_item_model(0, &model);
    TItemLoad::get_item_texture_list(0, &texture_list);
    spin = 0;
    texture_id = weapon->get_item_index();
    if ((s32)texture_id < 0 || (s32)texture_id > 4) {
        texture_id = 4;
    }
}

void TItemShootGun::hook() {
    spin += 0x1999;
}

void TItemShootGun::render() {
    if (is_owner_alive()) {
        if (model != NULL) {
            set_ginja_model_texture_slot(model->model, texture_id & 0xFFFF);
            set_texlist(texture_list);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(&m_pos.x);
            rotate_matrix_by_node_angles(&rot_x, 1);
            draw_ginja_object(model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}

TItemShoot *create_shoot_model_rot_z(TItemWeapon *owner, const Vec *pos, const Vec *dir, f32 life) {
    TItemShootModelRotZ *model = NULL;
    if (0.0f != life && owner != NULL) {
        model = new TItemShootModelRotZ(owner, pos, dir, life);
    }
    return model;
}

TItemShootModelRotZ::TItemShootModelRotZ(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    m_name = item_shoot_model_rot_z_class_name;
}

void TItemShootModelRotZ::hook() {
    rot_z += 0xCCC;
}

void TItemShootModelRotZ::render() {
    if (is_owner_alive()) {
        if (model != NULL) {
            set_texlist(texture_list);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(&m_pos.x);
            rotate_matrix_by_node_angles(&rot_x, 1);
            draw_ginja_object(model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}
