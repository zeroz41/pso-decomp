#include "pso/npc/TNpcPlayer_800D87A8.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/TObjFreezeShell.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/network/TLobby.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/TextureState.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"
#include "pso/render/model_render_state.h"
#include "pso/render/gjSystem.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/system/task/TMainTask.h"


__declspec(section ".data") const char *bm_eff_ice_model_names[3] = { "ice_break_root.gj", "ice_root.gj", NULL };
__declspec(section ".data") const char *bm_eff_ice_motion_names[2] = { "ice_break_root.njm", NULL };
BmlResourceDescriptor enemy_freeze_ice_resource_descriptor = { "bm_eff_ice.bml", bm_eff_ice_model_names, bm_eff_ice_motion_names, 2, 1 };

// The bm_eff_ice.bml models and motion every freeze shell draws with.
BmlResource *freeze_shell_bml_resource;

f32 TObjFreezeShell::receive_physical_attack(TObjChara *attacker, f32) {
    if (attacker != NULL) {
        this->hit_count = (this->hit_count + 1);
        if ((s32) this->hit_count >= 3) {
            this->state = 2;
        }
    }
    return 0.0f;
}

void TObjPlayer::queue_destruction() { TObject::queue_destruction(); }


void TObjFreezeShell::update_freeze_shell_timer() {
    this->color.a = (f32) (this->color.a - 0.4f);
    if (this->color.a <= -1.0f) {
        this->state = 3;
        this->color.a = (f32) -1.0f;
    }
}

void TObjFreezeShell::freeze_shell_hold() {
    TObjCollidable *owner;
    TParticleCtrl *effect;
    owner = find_active_entity_by_id(this->owner_id);
    if (owner == NULL) {
        return;
    }
    this->rotation_y += 0x10;
    if (owner->test_actor_flags(0x800) == 0) {
        if (owner->test_actor_flags(0x20) != 0) {
            return;
        }
    }
    this->state = 2;
    effect = spawn_particle_effect(&this->owner_position, 0x153);
    if (effect != NULL) {
        attach_particle_model(effect, get_bml_model(technique_effect_bml, 5), technique_texture_list, 0, 0, 1.0f);
    }
    effect = spawn_particle_effect(&this->position, 0x33);
    if (effect != NULL) {
        attach_particle_model(effect, get_bml_model(freeze_shell_bml_resource, 0), get_bml_texlist(freeze_shell_bml_resource, 1), get_bml_motion(freeze_shell_bml_resource, 0), 0, 1.0f);
        effect->set_scale(this->scale.x, this->scale.y);
    }
    this->frame = 0.0f;
}

void TObjFreezeShell::freeze_shell_grow() {
    Vec mist_pos;
    f32 size;
    this->rotation_y = (this->rotation_y + 0x1000);
    this->scale.z += 0.1f;
    size = this->scale.z;
    this->scale.y = size;
    this->scale.x = size;
    if (this->max_scale < this->scale.x) {
        this->state = 1;
    }
    this->grow_frames = (this->grow_frames + 1);
    if ((this->grow_frames % 3) == 0) {
        mist_pos.x = 0.0f;
        mist_pos.y = 0.0f;
        mist_pos.z = 10.0f * this->scale.x;
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, (int) (this->rotation_y * 2));
        rotate_vector_by_matrix(0, &mist_pos, &mist_pos);
        pop_matrix();
        vec3_add_to(&mist_pos, &this->position);
        create_timed_particle_emitter(&mist_pos, 0x12D, 0, 0xA);
    }
}

void TObjFreezeShell::run_task() {
    TObject *active_entity;
    u16 id = this->owner_id;
    if ((id != 0xffffU) && (id < 0x4000U)) {
        active_entity = find_active_entity_by_id(id);
    } else {
        active_entity = NULL;
    }
    if (active_entity == NULL) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    if (active_entity->all_parents_unqueued_for_destruction() == 0) {
        disallow_rendering();
        queue_destruction();
        return;
    }
    switch (this->state) {
    case 0:
        freeze_shell_grow();
        return;
    case 1:
        freeze_shell_hold();
        return;
    case 2:
        update_freeze_shell_timer();
        return;
    case 3:
        ((TObjPlayer *)this)->queue_destruction();
        return;
    }
}
void TObjFreezeShell::render() {
    s32 visible;
    TObjCollidable *owner;
    visible = 1;
    owner = find_active_entity_by_id(this->owner_id);
    if (owner != NULL && owner->all_parents_unqueued_for_destruction() != 0) {
        visible = owner->update_object_view_visibility(400.0f, 20.0f);
    }
    if (visible != 0) {
        set_texture_list(get_bml_texlist(freeze_shell_bml_resource, 1));
        push_matrix();
        post_translate_matrix(&this->position.x);
        rotate_matrix_y(0, this->rotation_y);
        scale_current_matrix(&this->scale.x);
        switch (this->state) {
        case 0:
        case 1:
            draw_ginja_object(this->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8820;
            set_constant_material(&this->color);
            draw_ginja_object(this->model);
            model_render_flags &= 0xFFFF77DF;
            set_chunk_material_override_pair(0xFF00, 0);
            set_constant_material(&chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
    }
}

void TObjFreezeShell::create(TObjChara *chara, CollisionBody *body, s32 duration) {
    u16 entity_id;

    if ((is_current_area_item_enabled() != 0) && (chara != NULL)) {
        entity_id = chara->get_entity_id();
        if ((entity_id != 0xFFFF) && (entity_id < 0x4000U)) {
            new TObjFreezeShell(chara, body, duration);
        }
    }
}

void TObjFreezeShell::free_freeze_ice_resource() {
    if (freeze_shell_bml_resource != NULL) {
        delete freeze_shell_bml_resource;
        freeze_shell_bml_resource = NULL;
    }
}

void TObjFreezeShell::load_freeze_ice_resource() {
    freeze_shell_bml_resource = new BmlResource(5, &enemy_freeze_ice_resource_descriptor, 0, 0, NULL);
}

TObjFreezeShell::~TObjFreezeShell() {
    if (this->emitter != NULL) { TParticleCtrl::release(this->emitter); }
}


#pragma push
#pragma fp_contract on
TObjFreezeShell::TObjFreezeShell(TObjChara *chara, CollisionBody *body, s32) : TObjChara(tl_05) {
    player_stats *stats;
    this->model = get_bml_model(freeze_shell_bml_resource, 1);
    if (chara != NULL) {
        this->owner_id = chara->get_entity_id();
        VecCopy(&this->owner_position, &chara->position);
        if (body != NULL) {
            VecCopy(&this->position, &body->center);
            this->max_scale = (f32) (0.15f * body->radius);
        } else if (chara->bodies != NULL) {
            chara->refresh_collision_body_centers();
            VecCopy(&this->position, &chara->bodies->center);
            this->max_scale = (f32) (0.15f * chara->bodies->radius);
        } else {
            VecCopy(&this->position, &chara->body_center);
            stats = chara->get_stats();
            if (stats != NULL) {
                this->max_scale = (f32) (0.075f * stats->proportions);
            } else {
                this->max_scale = 1.5f;
            }
        }
        this->rotation_y = chara->rotation_y;
        this->scale.z = 0.0f;
        this->scale.y = 0.0f;
        this->scale.x = 0.0f;
        this->state = 0;
        this->grow_frames = 0;
        this->color.a = 0.0f;
        this->color.r = 0.0f;
        this->color.g = 0.0f;
        this->color.b = 0.0f;
        this->emitter = create_particle_emitter(&this->position, 0x12E);
        this->hit_count = 0;
    } else {
        this->emitter = NULL;
        queue_destruction();
    }
}

#pragma pop

s32 TObjFreezeShell::select_melee_contact_body(TObjChara *, f32) { return 1; }
int TObjFreezeShell::calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float) { return 1; }

f32 TObjFreezeShell::receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32) {
    return 0.0f;
}

f32 TObjFreezeShell::receive_weapon_special_attack(TObjChara *, CollisionBody *) {
    return 0.0f;
}


void TObjFreezeShell::apply_knockback_from_attacker(TObjBase *, f32) {  }
void TParticleCtrl::set_scale(f32 a, f32 b) { scale_x = a; scale_y = b; }

f32 TObjChara::get_frame() { return this->frame; }

s32 TObjPlayer::test_action_mask(s32 bits) {
    return (u8) ((mode_mask & bits) != 0);
}

s32 PlayerTechniqueState::get_state() { return state; }
