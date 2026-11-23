#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/NinjaTypes.h"
#include "pso/render/ChunkMaterialState.h"
#include "types.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/weapon/TItemWeaponGuardianna.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/item/TItemWpnCardEffect.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/vector.h"
#include "pso/weapon/TItemAttackCol.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/model_render_state.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/item/TItemEquipBase.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

const char *TItemWpnCardEffect::class_name = "TItemWpnCardEffect";


#pragma fp_contract on

void TObjPlayer::create_network_object(s32 item_id, u32 *hit, saddr direction) {
    if ((hit != NULL) && ((u32) *hit != 0U)) {
        new TItemWpnCardEffect(tl_05, (ActorBodyHit *)hit, (f32 *)direction, 0, item_id);
    }
}

void start_wall_card(s32 item_id, saddr position, saddr direction) {
    new TItemWpnCardEffect(tl_05, (f32 *)position, (f32 *)direction, 0, item_id);
}

void TObjPlayer::create_aux_object(s32 item_id, u32 *hit, saddr direction) {
    if ((hit != NULL) && ((u32) *hit != 0U)) {
        new TItemWpnCardEffect(tl_05, (ActorBodyHit *)hit, (f32 *)direction, 0xFFFF0000, item_id);
    }
}

void start_red_wall_card(s32 item_id, saddr position, saddr direction) {
    new TItemWpnCardEffect(tl_05, (f32 *)position, (f32 *)direction, 0xFFFF0000, item_id);
}

void TObjPlayer::start_guardianna_hit_card(s32 item_id, u32 *hit, saddr direction) {
    if ((hit != NULL) && ((u32) *hit != 0U)) {
        new TItemWpnCardEffect(tl_05, (ActorBodyHit *)hit, (f32 *)direction, -0x100, item_id);
    }
}

void start_guardianna_wall_card(s32 item_id, saddr position, saddr direction) {
    new TItemWpnCardEffect(tl_05, (f32 *)position, (f32 *)direction, -0x100, item_id);
}

TItemWpnCardEffect::TItemWpnCardEffect(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id) : TObject(parent) {
    target_id = hit->target->get_entity_id();
    this->item_id = item_id;
    copy_actor_body_hit(&hit_target, hit);
    VecCopy(&this->direction, (const Vec *)direction);
    VecCopy(&position, &hit->target->bodies[hit->body].center);
    rotation[1] = (65536.0 / (2.0 * 3.141592f)) * atan2_float(direction[0], direction[2]);
    this->tint = tint;
    init();
}

TItemWpnCardEffect::TItemWpnCardEffect(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id) : TObject(parent) {
    hit_target.target = NULL;
    hit_target.body = 0;
    target_id = 0xFFFF;
    this->item_id = item_id;
    VecCopy(&this->direction, (const Vec *)direction);
    VecCopy(&this->position, (const Vec *)position);
    rotation[1] = (s32)((65536.0 / (2.0 * 3.141592f)) * atan2_float(direction[0], direction[2]));
    this->tint = tint;
    init();
}


void TItemWpnCardEffect::init() {
    f32 radius;
    m_name = class_name;
    age = 0;
    particles[0] = NULL;
    particles[1] = NULL;
    particles[2] = NULL;
    rotation[0] = 0;
    rotation[2] = 0;
    normalize_vector(&direction);
    if (target_id != 0xFFFF) {
        radius = hit_target.target->bodies[hit_target.body].radius;
        anchor_offset.x = direction.x * radius;
        anchor_offset.y = direction.y * radius;
        anchor_offset.z = direction.z * radius;
    } else {
        anchor_offset.x = 0.0f;
        anchor_offset.y = 0.0f;
        anchor_offset.z = 0.0f;
    }
    anchor_card_effect();
}

TItemWpnCardEffect::~TItemWpnCardEffect() {
    destroy_effect_objects();
}


void TItemWpnCardEffect::run_task() {
    s32 i;
    TItem *card = find_item_by_id(item_id);
    if (card == NULL) {
        queue_destruction();
        return;
    }
    if (card->get_mode() != 2) {
        queue_destruction();
        return;
    }
    anchor_card_effect();
    for (i = 0; i != 3; i++) {
        if (particles[i] != NULL) {
            ((TParticleCtrl *)particles[i])->set_position((u8 *)&position);
        }
    }
    if (age == 0) {
        start_card_effect_flash();
    } else if (age == 6) {
        destroy_effect_objects();
        start_card_effect_trail();
    } else if (age == 12) {
        queue_destruction();
        return;
    }
    update_fade();
    age++;
}
#pragma push
#pragma fp_contract on
void TItemWpnCardEffect::start_card_effect_flash() {
    particles[0] = spawn_particle_effect_with_rotation(&position, rotation, 0x1B9, 0x104);
    if (particles[0] != NULL) {
        ((TParticleCtrl *)particles[0])->set_scale(1.5f, 1.5f);
        if (tint != 0) {
            ((TParticleCtrl *)particles[0])->set_tint_color(tint);
        }
    }
    spawn_particle_effect(&position, 0x30);
}
#pragma pop
#pragma push
#pragma fp_contract on
void TItemWpnCardEffect::start_card_effect_trail() {
    particles[2] = create_particle_emitter(&position, 0x1B6);
    if (particles[2] != NULL) {
        ((TParticleCtrl *)(particles[2]))->set_tint_color(-0x78);
    }
}
#pragma pop
void TItemWpnCardEffect::update_fade() {  }
void TItemWpnCardEffect::destroy_effect_objects() {
    s32 i;
    for (i = 0; i != 3; i++) {
        if (particles[i] != 0) {
            ((TObject *)particles[i])->queue_destruction();
            particles[i] = 0;
        }
    }
}
void TItemWpnCardEffect::anchor_card_effect() {
    CollisionBody *body;
    if (target_id != 0xFFFF) {
        if (find_entity_by_id(target_id) != NULL) {
            body = &hit_target.target->bodies[hit_target.body];
            position.x = body->center.x - anchor_offset.x;
            position.y = body->center.y - anchor_offset.y;
            position.z = body->center.z - anchor_offset.z;
        }
    }
}
void TObjPlayer::create_and_init_effect(s32 item_id, u32 *hit, saddr direction) {
    if ((hit != NULL) && ((u32) *hit != 0U)) {
        new TItemWpnCardModelEffect(tl_05, (ActorBodyHit *)hit, (f32 *)direction, 0, item_id);
    }
}
void TObjPlayer::alloc_and_init(s32 item_id, saddr position, saddr direction) {
    new TItemWpnCardModelEffect(tl_05, (f32 *)position, (f32 *)direction, 0, item_id);
}
TItemWpnCardModelEffect::TItemWpnCardModelEffect(TObject *parent, ActorBodyHit *hit, f32 *direction, s32 tint, s32 item_id)
    : TItemWpnCardEffect(parent, hit, direction, tint, item_id) {
    init_offset_vectors();
}
TItemWpnCardModelEffect::TItemWpnCardModelEffect(TObject *parent, f32 *position, f32 *direction, s32 tint, s32 item_id)
    : TItemWpnCardEffect(parent, position, direction, tint, item_id) {
    init_offset_vectors();
}
void TItemWpnCardModelEffect::init_offset_vectors() {
    card_flags = 0;
    scale.x = 4.0f;
    scale.y = 4.0f;
    scale.z = 4.0f;
    color.a = -1.0f;
    color.r = 0.0f;
    color.g = 0.0f;
    color.b = 0.0f;
}
void TItemWpnCardModelEffect::start_card_effect_flash() { card_flags |= 1; }
void TItemWpnCardModelEffect::start_card_effect_trail() { card_flags &= ~1; }
#pragma push
#pragma opt_common_subs off
void TItemWpnCardModelEffect::update_fade() {
    if (card_flags & 1) {
        color.a += 0.25f;
        if (color.a > 0.0f) {
            color.a = 0.0f;
        }
    } else {
        color.a = color.a - 0.25f;
        if (color.a < -1.0f) {
            color.a = -1.0f;
        }
    }
}
#pragma pop
void TItemWpnCardModelEffect::render() {
    TItem *equipped_item;
    NJS_OBJECT *model;
    if (!(color.a <= -1.0f) && all_parents_unqueued_for_destruction() != 0) {
        equipped_item = find_equipped_item(item_id);
        if (equipped_item != NULL) {
            model = ((TItemEquipBase *)equipped_item)->second_model;
            if (model != NULL) {
                saved_model_render_flags = model_render_flags;
                copy_argb(&saved_model_draw_color, &model_material_color);
                model_render_flags |= 0x20;
                set_constant_material(&color);
                set_texlist(equipped_item->get_texlist());
                push_matrix();
                post_translate_matrix(&position.x);
                rotate_matrix_y(NULL, rotation[1]);
                scale_current_matrix(&scale.x);
                draw_ginja_object(model);
                pop_matrix();
                copy_argb(&model_material_color, &saved_model_draw_color);
                model_render_flags = saved_model_render_flags;
            }
        }
    }
}

TItemWpnCardModelEffect::~TItemWpnCardModelEffect() {}

TItemWeaponGuardianna::~TItemWeaponGuardianna() {}

TItem *create_guardianna(u8 *item) {
    if (item != NULL) {
        return new TItemWeaponGuardianna(tl_05, item);
    }
    return NULL;
}


TItemWeaponGuardianna::TItemWeaponGuardianna(TObject *parent, u8 *item) : TItemWeapon(parent, item) {
    set_weapon_flags(2);
}
void TItemWeaponGuardianna::emit_marker_effects() {
    Vec origin;

    get_joint_position(4, &origin);
    if (owner->attack_state.get_validated_attack_stage() == 2) {
        fire_shot_at_target(&origin, item_model, 0);
        fire_shot_at_target(&origin, item_model, 0x1555);
        fire_shot_at_target(&origin, item_model, -0x1555);
    } else {
        fire_shot_at_target(&origin, item_model, 0);
    }
    if (get_attack_stage() == 0) {
        ((TObjPlayer *)tl_05)->spawn_cane_effect(this, 4);
    }
}
void TItemWeaponGuardianna::init_weapon_effect_descriptor(Desc_8011E5C4 *desc) {
    desc->particle = 0x176;
    desc->hit_effect = (void *)TObjPlayer::start_guardianna_hit_card;
    desc->wall_effect = (void *)start_guardianna_wall_card;
}
