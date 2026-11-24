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
#include "pso/unk/text_8011B328.h"
#include "pso/unk/text_8011B620.h"
#include "pso/unk/text_8011BE50.h"
#include "pso/unk/text_8011BEF0.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemLoad.h"
#include "pso/item/TItemMenuCtrl_80115AF0.h"
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
#include "pso/unk/text_803D96A8.h"

// The weapon's colour as TItemWeapon::get_weapon_color returns it
// (WeaponAttackActions.cpp, which has no header declaration of it yet).
struct WeaponArgb {
    f32 alpha, red, green, blue;
};

extern "C" {
WeaponArgb get_weapon_color__11TItemWeaponFPv(void *weapon);
}

// The task layers (TMainTask.h), tl_07 read-only: the gun shot's constructor
// loads tl_07 ahead of the last store of its star-light parameter copy, which
// CodeWarrior only does for a const object.
extern TObject *tl_05;
extern TObject *const tl_07;

const char *TItemShoot__class_name = "TItemShoot";
const char *TItemShootModel__class_name = "TItemShootModel";
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
    m_70 = id;
}

TItemShootModelRotZ::~TItemShootModelRotZ() {}

s32 spawn_shoot_particle_9f(u32 owner, s32 pos, s32 dir, f32 life) {
    TItemShootParticle *particle = (TItemShootParticle *)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (particle != NULL) {
        particle->set_particle_flags(4);
        particle->spawn_slot_emitter(0x9F, 0);
    }
    return (saddr)particle;
}

s32 create_shoot_model_with_particles(u32 owner, s32 pos, s32 dir, f32 life) {
    saddr model = TObjPlayer::create_shoot_model(owner, pos, dir, life);
    TItemShootParticle *particle = (TItemShootParticle *)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if ((u32)model != 0U && particle != NULL) {
        ((TItemShootModel *)model)->ang = 0x4000;
        particle->spawn_slot_emitter(0x1BB, 0);
        particle->spawn_slot_emitter(0x1BC, 1);
        particle->set_parent((TObject *)model);
    }
    return model;
}

u32 TItemShoot::spawn_shoot_particle_attached(u32 owner, s32 pos, s32 dir, f32 life) {
    uaddr model = TObjPlayer::create_shoot_model(owner, pos, dir, life);
    uaddr particle = (uaddr)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (model != 0U && particle != 0U) {
        ((TItemShootParticle *)particle)->spawn_slot_emitter(0x1BD, 0);
        ((TObject *)particle)->set_parent((TObject *)model);
    }
    return model;
}

s32 TItemShoot::spawn_shoot_particle(u32 owner, s32 pos, s32 dir, f32 life) {
    TItemShootParticle *particle = (TItemShootParticle *)TObjPlayer::spawn_shoot_particle(owner, pos, dir, life);
    if (particle != NULL) {
        particle->spawn_slot_emitter(0x12, 0);
    }
    return (saddr)particle;
}

TItemShoot::TItemShoot(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TObject(tl_05) {
    m_name = TItemShoot__class_name;
    VecCopy(&m_pos, pos);
    VecCopy(&m_dir, VecCopy(&m_44, dir));
    m_life = life;
    subtract_vector(&m_dir, pos);
    f32 len = vector_length(&m_dir);
    normalize_vector(&m_dir);
    f32 scale = len / life;
    m_dir.x *= scale;
    m_dir.y *= scale;
    m_dir.z *= scale;
    m_count = (s32)(RADIANS_TO_ANGLE * atan2_float(m_dir.x, m_dir.z));
    direction_to_rotation_xz((u8 *)&m_dir, &m_28, &rot_b);
    m_50 = NULL;
    m_owner_item_id = ((TItem *)owner)->get_item_id();
    disallow_rendering();
}

TItemShoot::~TItemShoot() {
    if (m_50 != NULL) {
        m_50->queue_destruction();
    }
}

void TItemShoot::run_task() {
    if (find_equipped_item(m_owner_item_id) == NULL) {
        disallow_rendering();
        queue_destruction();
    }
    allow_rendering();
    vec3_add_to(&m_pos, &m_dir);
    if (m_50 != NULL) {
        ((TEffStarLight2D *)m_50)->copy_position(&m_pos);
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

saddr TObjPlayer::create_shoot_model(uaddr owner, saddr pos, saddr dir, f32 life) {
    TItemShootModel *model = NULL;
    if (0.0f != life && owner != 0U) {
        model = new TItemShootModel((void *)owner, (const Vec *)pos, (const Vec *)dir, life);
    }
    return (saddr)model;
}

TItemShootModel::TItemShootModel(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShoot(owner, pos, dir, life) {
    m_name = TItemShootModel__class_name;
    model = *(NJS_OBJECT **)((u8 *)owner + 0x188);
    texture_list = (NJS_TEXLIST *)((TObjBase *)owner)->get_texlist();
    if (0.0f != m_dir.y) {
        f32 horiz = newton_sqrtf(m_dir.x * m_dir.x + m_dir.z * m_dir.z);
        m_28 = -(s32)(RADIANS_TO_ANGLE * atan2_float(m_dir.y, horiz));
        rot_b = 0;
    } else {
        rot_b = 0;
        m_28 = 0;
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
            rotate_matrix_by_node_angles(&m_28, 1);
            rotate_matrix_by_node_angles(&ang, 1);
            draw_ginja_object(model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}

void *TObjPlayer::spawn_shoot_particle(uaddr owner, saddr pos, saddr dir, f32 life) {
    if (0.0f != life && owner != 0U) {
        return new TItemShootParticle((void *)owner, (const Vec *)pos, (const Vec *)dir, life);
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
        *(TParticleCtrl **)((u8 *)this + offset) = (TParticleCtrl *)spawn_particle_effect_with_rotation(&m_pos, &m_28, effect_id, (u16)(m_effect_flags | 0x40));
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

s32 create_gun_shot(saddr owner, saddr pos, saddr endpoint, f32 life) {
    spawn_particle_effect((const Vec *)pos, 9);
    return (saddr)new TItemShootGun((void *)owner, (const Vec *)pos, (const Vec *)endpoint, life);
}

u32 TItemShootGun::create(saddr owner, saddr pos, saddr endpoint, f32 life) {
    TItemShootGun *result;

    spawn_particle_effect((const Vec *)pos, 0x1BF);
    result = new TItemShootGun((void *)owner, (const Vec *)pos, (const Vec *)endpoint, life);
    if (result != 0) {
        result->set_texture_id(4);
    }
    return (uaddr)result;
}

TItemShootGun::TItemShootGun(void *owner, const Vec *pos, const Vec *endpoint, f32 life)
    : TItemShootModel(owner, pos, endpoint, life) {
    TItem *item = (TItem *)owner;
    m_name = item_shoot_gun_class_name;
    WeaponArgb color = get_weapon_color__11TItemWeaponFPv(item);
    StarLightParameters params = gun_shot_star_light_parameters;
    params.color.channels.r = (u8)(255.0f * color.red);
    params.color.channels.g = (u8)(255.0f * color.green);
    params.color.channels.b = (u8)(255.0f * color.blue);
    m_50 = spawn_star_light_2d(&m_pos, &params, tl_07);
    TItemLoad::get_item_model(0, &model);
    TItemLoad::get_item_texture_list(0, &texture_list);
    m_6C = 0;
    m_70 = item->get_item_index();
    if ((s32)m_70 < 0 || (s32)m_70 > 4) {
        m_70 = 4;
    }
}

void TItemShootGun::hook() {
    m_6C += 0x1999;
}

void TItemShootGun::render() {
    if (is_owner_alive()) {
        if (model != NULL) {
            set_ginja_model_texture_slot(model->model, m_70 & 0xFFFF);
            set_texlist(texture_list);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(&m_pos.x);
            rotate_matrix_by_node_angles(&m_28, 1);
            draw_ginja_object(model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}

s32 create_shoot_model_rot_z(uaddr owner, saddr pos, saddr dir, f32 life) {
    TItemShootModelRotZ *model = NULL;
    if (0.0f != life && owner != 0U) {
        model = new TItemShootModelRotZ((void *)owner, (const Vec *)pos, (const Vec *)dir, life);
    }
    return (saddr)model;
}

TItemShootModelRotZ::TItemShootModelRotZ(void *owner, const Vec *pos, const Vec *dir, f32 life)
    : TItemShootModel(owner, pos, dir, life) {
    m_name = item_shoot_model_rot_z_class_name;
}

void TItemShootModelRotZ::hook() {
    rot_b += 0xCCC;
}

void TItemShootModelRotZ::render() {
    if (is_owner_alive()) {
        if (model != NULL) {
            set_texlist(texture_list);
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(&m_pos.x);
            rotate_matrix_by_node_angles(&m_28, 1);
            draw_ginja_object(model);
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
    }
}
