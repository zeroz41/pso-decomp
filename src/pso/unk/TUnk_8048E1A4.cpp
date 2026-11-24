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
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject_8001A448.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/TUnk_8048E1A4.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/TObjChara.h"
#include "pso/map/FloorArea.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/TLobby.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/unk/TLobby_8001EF5C.h"
#include "pso/player/TPlyDispData.h"
#include "pso/object/base/TObjBase.h"
#include "pso/npc/TNpcPlayer_800D87A8.h"


f32 TUnk_8048E1A4::receive_physical_attack(void *arg1, f32) {
    if (arg1 != 0U) {
        this->m_354 = (this->m_354 + 1);
        if ((s32) this->m_354 >= 3) {
            *(s32 *)((s8 *)this + 0x334) = 2;
        }
    }
    return 0.0f;
}

void TObjPlayer::queue_destruction() { TObject::queue_destruction(); }


void TUnk_8048E1A4::update_freeze_shell_timer() {
    u8 *arg0 = (u8 *)this;
    this->color = (f32) (this->color - 0.4f);
    if (this->color <= -1.0f) {
        *(s32 *)((s8 *)arg0 + 0x334) = 3;
        this->color = (f32) -1.0f;
    }
}

struct RecoveredGlobal_80081CD0_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
LAYOUT_ASSERT(RecoveredGlobal_80081CD0_lbl_8058D490_size, sizeof(RecoveredGlobal_80081CD0_lbl_8058D490) == 0x30);

struct VBase_80081EA4 { u8 pad[0x18]; };

struct VObj_80081EA4 : VBase_80081EA4 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
extern RecoveredGlobal_80081CD0_lbl_8058D490 identity_matrix;


saddr freeze_shell_bml_resource;
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

void TUnk_8048E1A4::freeze_shell_hold() {
    TObjCollidable *owner;
    TParticleCtrl *effect;
    owner = find_active_entity_by_id(*(u16 *)((s8 *)this + 0x358));
    if (owner == NULL) {
        return;
    }
    this->rotation_y += 0x10;
    if (owner->test_actor_flags(0x800) == 0) {
        if (owner->test_actor_flags(0x20) != 0) {
            return;
        }
    }
    *(s32 *)((s8 *)this + 0x334) = 2;
    effect = spawn_particle_effect((const Vec *)((u8 *)this + 0x35C), 0x153);
    if (effect != NULL) {
        attach_particle_model(effect, get_bml_model(technique_effect_bml, 5), technique_texture_list, 0, 0, 1.0f);
    }
    effect = spawn_particle_effect((const Vec *)((u8 *)this + 0x38), 0x33);
    if (effect != NULL) {
        attach_particle_model(effect, get_bml_model((BmlResource *)freeze_shell_bml_resource, 0), get_bml_texlist((BmlResource *)freeze_shell_bml_resource, 1), get_bml_motion((BmlResource *)freeze_shell_bml_resource, 0), 0, 1.0f);
        effect->set_scale(this->scale.x, this->scale.y);
    }
    this->frame = 0.0f;
}

void TUnk_8048E1A4::freeze_shell_grow() {
    u8 *arg0 = (u8 *)this;
    Vec stack;
    f32 temp_f0;
    this->rotation_y = (this->rotation_y + 0x1000);
    this->scale.z += 0.1f;
    temp_f0 = this->scale.z;
    this->scale.y = temp_f0;
    this->scale.x = temp_f0;
    if (this->m_338 < this->scale.x) {
        *(s32 *)((s8 *)arg0 + 0x334) = 1;
    }
    *(s32 *)((s8 *)arg0 + 0x33C) = (s32) (*(s32 *)((s8 *)arg0 + 0x33C) + 1);
    if ((*(s32 *)((s8 *)arg0 + 0x33C) % 3) == 0) {
        stack.x = 0.0f;
        stack.y = 0.0f;
        stack.z = 10.0f * this->scale.x;
        push_matrix_from(&identity_matrix.value);
        rotate_matrix_y(0, (int) (this->rotation_y * 2));
        rotate_vector_by_matrix(0, &stack.x, &stack.x);
        pop_matrix();
        vec3_add_to(&stack.x, (u8 *)&this->position);
        create_timed_particle_emitter((&stack.x), 0x12D, 0, 0xA);
    }
}

void TUnk_8048E1A4::run_task() {
    TObject *active_entity;
    u16 id = *(u16 *)((s8 *)this + 0x358);
    if ((id != 0xffffU) && (id < 0x4000U)) {
        active_entity = (TObject *)find_active_entity_by_id(id);
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
    switch (*(s32 *)((s8 *)this + 0x334)) {
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
void TUnk_8048E1A4::render() {
    u8 *arg0 = (u8 *)this;
    s32 ok;
    VObj_80081EA4 *p;
    ok = 1;
    p = (VObj_80081EA4 *)find_active_entity_by_id(*(u16 *)((s8 *)arg0 + 0x358));
    if (p != NULL && ((TObject *)p)->all_parents_unqueued_for_destruction() != 0) {
        ok = p->m8(400.0f, 20.0f);
    }
    if (ok != 0) {
        TObjFish::set_global_param(get_bml_texlist((BmlResource *)(saddr)((void *)freeze_shell_bml_resource), 1));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        scale_current_matrix((u8 *)&this->scale);
        switch (*(s32 *)((s8 *)arg0 + 0x334)) {
        case 0:
        case 1:
            draw_ginja_object(this->model);
            break;
        case 2:
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x8820;
            set_constant_material((const NJS_ARGB *)((&this->color)));
            draw_ginja_object(this->model);
            model_render_flags &= 0xFFFF77DF;
            set_chunk_material_override_pair(0xFF00, 0);
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
            break;
        }
        pop_matrix();
    }
}

s32 __ct__13TUnk_8048E1A4FPUcPUc(u32, u32, s32, s32);

void create__10TObjPlayerFUiii(uaddr base, s32 arg1, s32 arg2) {
    u16 entity_id;

    u32 obj;
    if ((is_current_area_item_enabled() != 0) && (base != 0U)) {
        entity_id = ((TObjBase *)base)->get_entity_id();
        if (((u16) entity_id != 0xFFFF) && ((u16) entity_id < 0x4000U) && ((obj = (uaddr)TObject::operator new(0x368)) != 0U)) {
            __ct__13TUnk_8048E1A4FPUcPUc(obj, base, arg1, arg2);
        }
    }
}

}

extern const char *bm_eff_ice_model_names[3];
extern const char *bm_eff_ice_motion_names[2];
extern BmlResourceDescriptor enemy_freeze_ice_resource_descriptor;

struct RecoveredFields_8008213C_arg0 {
    u8 unknown_0[0x18];
    s32 * field_18;
    u8 unknown_1C[0x18];
    s32 field_34;
    u8 unknown_38[0x28];
    s32 field_60;
    u8 unknown_64[0x4];
    f32 field_68;
    f32 field_6C;
    f32 field_70;
    u8 unknown_74[0x2C0];
    s32 field_334;
    f32 field_338;
    s32 field_33C;
    f32 field_340;
    f32 field_344;
    f32 field_348;
    f32 field_34C;
    s32 field_350;
    s32 field_354;
    s16 field_358;
};

struct RecoveredFields_8008213C_arg2 {
    u8 unknown_0[0xC];
    f32 field_C;
};

struct RecoveredFields_8008213C_arg1 {
    u8 unknown_0[0x60];
    s32 field_60;
    u8 unknown_64[0x40];
    u8 * field_A4;
};

extern "C" {
extern saddr tl_05;

void TLobby::destroy_global_singleton() {
    if ((u32) freeze_shell_bml_resource != 0U) {
        delete (BmlResource *)freeze_shell_bml_resource;
        freeze_shell_bml_resource = 0U;
    }
}

void TLobby::load_freeze_ice_resource() {
    saddr temp_r3;
    s32 var_r0;
    var_r0 = (saddr)new BmlResource(5, &enemy_freeze_ice_resource_descriptor, 0, 0, NULL);
    (*(s32 *)&freeze_shell_bml_resource) = var_r0;
}

}
TUnk_8048E1A4::~TUnk_8048E1A4() {
    if (this->emitter != NULL) { TParticleCtrl::release(this->emitter); }
}


#pragma push
#pragma fp_contract on
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_18_offset, offsetof(RecoveredFields_8008213C_arg0, field_18) == 0x18);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_34_offset, offsetof(RecoveredFields_8008213C_arg0, field_34) == 0x34);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_60_offset, offsetof(RecoveredFields_8008213C_arg0, field_60) == 0x60);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_68_offset, offsetof(RecoveredFields_8008213C_arg0, field_68) == 0x68);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_6C_offset, offsetof(RecoveredFields_8008213C_arg0, field_6C) == 0x6C);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_70_offset, offsetof(RecoveredFields_8008213C_arg0, field_70) == 0x70);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_334_offset, offsetof(RecoveredFields_8008213C_arg0, field_334) == 0x334);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_338_offset, offsetof(RecoveredFields_8008213C_arg0, field_338) == 0x338);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_33C_offset, offsetof(RecoveredFields_8008213C_arg0, field_33C) == 0x33C);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_340_offset, offsetof(RecoveredFields_8008213C_arg0, field_340) == 0x340);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_344_offset, offsetof(RecoveredFields_8008213C_arg0, field_344) == 0x344);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_348_offset, offsetof(RecoveredFields_8008213C_arg0, field_348) == 0x348);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_34C_offset, offsetof(RecoveredFields_8008213C_arg0, field_34C) == 0x34C);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_350_offset, offsetof(RecoveredFields_8008213C_arg0, field_350) == 0x350);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_354_offset, offsetof(RecoveredFields_8008213C_arg0, field_354) == 0x354);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg0_358_offset, offsetof(RecoveredFields_8008213C_arg0, field_358) == 0x358);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg2_C_offset, offsetof(RecoveredFields_8008213C_arg2, field_C) == 0xC);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg1_60_offset, offsetof(RecoveredFields_8008213C_arg1, field_60) == 0x60);
LAYOUT_ASSERT(RecoveredFields_8008213C_arg1_A4_offset, offsetof(RecoveredFields_8008213C_arg1, field_A4) == 0xA4);
TUnk_8048E1A4::TUnk_8048E1A4(u8 *chara, u8 *arg2) : TObjChara((TObject *)((void *)tl_05)) {
    player_stats *temp_r3;
    ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_34 = (saddr)get_bml_model((BmlResource *)freeze_shell_bml_resource, 1);
    if (chara != NULL) {
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_358 = ((TObjBase *)(chara))->get_entity_id();
        VecCopy((Vec *)(((u8 *)this) + 0x35C), (const Vec *)(chara + 0x38));
        if (arg2 != NULL) {
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg2 + 0x1C));
            ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (0.15f * ((RecoveredFields_8008213C_arg2 *)arg2)->field_C);
        } else if ((void *) ((RecoveredFields_8008213C_arg1 *)chara)->field_A4 != NULL) {
            ((TObjCollidable *)chara)->refresh_collision_body_centers();
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((RecoveredFields_8008213C_arg1 *)chara)->field_A4 + 0x1C));
            ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (0.15f * *(f32 *)((s8 *)(((RecoveredFields_8008213C_arg1 *)chara)->field_A4) + 0xC));
        } else {
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(chara + 0x2FC));
            temp_r3 = ((TObjChara *)chara)->get_stats();
            if (temp_r3 != NULL) {
                ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (0.075f * temp_r3->proportions);
            } else {
                ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = 1.5f;
            }
        }
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_60 = (s32) ((RecoveredFields_8008213C_arg1 *)chara)->field_60;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_70 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_6C = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_68 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_334 = 0;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_33C = 0;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_340 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_344 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_348 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_34C = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_350 = (saddr)create_particle_emitter((((u8 *)this) + 0x38), 0x12E);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_354 = 0;
    } else {
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_350 = 0;
        queue_destruction();
    }
}

#pragma pop

s32 TUnk_8048E1A4::select_melee_contact_body(void *, f32) { return 1; }
int TUnk_8048E1A4::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

f32 TUnk_8048E1A4::receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32) {
    return 0.0f;
}

f32 TUnk_8048E1A4::receive_weapon_special_attack(void *, void *) {
    return 0.0f;
}

__declspec(section ".data") const char *bm_eff_ice_model_names[3] = { "ice_break_root.gj", "ice_root.gj", NULL };
__declspec(section ".data") const char *bm_eff_ice_motion_names[2] = { "ice_break_root.njm", NULL };
BmlResourceDescriptor enemy_freeze_ice_resource_descriptor = { "bm_eff_ice.bml", bm_eff_ice_model_names, bm_eff_ice_motion_names, 2, 1 };

void TUnk_8048E1A4::apply_knockback_from_attacker(u8 *, f32) {  }
void TParticleCtrl::set_scale(f32 a, f32 b) { scale_x = a; scale_y = b; }

f32 TObjChara::get_frame() { return this->frame; }

s32 TObjPlayer::test_action_mask(s32 arg1) {
    return (u8) (((*(s32 *)this->unk_320) & arg1) != 0);
}

extern "C" s32 TObjPlayer__sub_80082300(void* p) { return *(s32*)((char*)p + 0xc); }
