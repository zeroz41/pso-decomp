#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#include "pso/effect/particle/TParticleCtrl_800867E4.h"
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

extern "C" {


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

}

void TUnk_8048E1A4::update_freeze_shell_timer() {
    u8 *arg0 = (u8 *)this;
    this->m_340 = (f32) (this->m_340 - 0.4f);
    if (this->m_340 <= -1.0f) {
        *(s32 *)((s8 *)arg0 + 0x334) = 3;
        this->m_340 = (f32) -1.0f;
    }
}

struct Stack_80081CD0 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_80081CD0_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
typedef char RecoveredGlobal_80081CD0_lbl_8058D490_size[sizeof(RecoveredGlobal_80081CD0_lbl_8058D490) == 0x30 ? 1 : -1];

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
u32 find_active_entity_by_id(u16);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
f32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
extern RecoveredGlobal_80081CD0_lbl_8058D490 identity_matrix;
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void *spawn_particle_effect(void *pos, s32 id);
extern s32 freeze_shell_bml_resource;
extern s32 technique_effect_bml;
extern s32 lbl_805D63B0;
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 set_global_param__8TObjFishFl();
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

s32 TUnk_8048E1A4::freeze_shell_hold() {
    s32 p;
    p = find_active_entity_by_id(*(u16 *)((s8 *)this + 0x358));
    if (p == 0) {
        return;
    }
    this->rotation_y += 0x10;
    if (((TObjCollidable *)p)->obj_testFlags30(0x800) == 0) {
        if (((TObjCollidable *)p)->obj_testFlags30(0x20) != 0) {
            return;
        }
    }
    *(s32 *)((s8 *)this + 0x334) = 2;
    p = (s32)spawn_particle_effect((u8 *)this + 0x35C, 0x153);
    if (p != 0) {
        attach_particle_model((u8 *)p, (s32)(get_bml_model(technique_effect_bml, 5)), (s32)lbl_805D63B0, 0, 0, 1.0f);
    }
    p = (s32)spawn_particle_effect((u8 *)this + 0x38, 0x33);
    if (p != 0) {
        attach_particle_model((u8 *)p, (s32)(get_bml_model(freeze_shell_bml_resource, 0)), (s32)(TObjFish__sub_8001EDB0(freeze_shell_bml_resource, 1)), (s32)(get_bml_motion(freeze_shell_bml_resource, 0)), 0, 1.0f);
        ((TParticleCtrl *)p)->set_scale(this->scale.x, this->scale.y);
    }
    this->frame = 0.0f;
}

void TUnk_8048E1A4::freeze_shell_grow() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_80081CD0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80081CD0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80081CD0, sp10) == 0x8) ? 1 : -1];
    Stack_80081CD0 stack;
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
        stack.sp8 = 0.0f;
        stack.spC = 0.0f;
        stack.sp10 = 10.0f * this->scale.x;
        push_matrix_from(&identity_matrix.value);
        rotate_matrix_y(0, (int) (this->rotation_y * 2));
        rotate_vector_by_matrix(0, &stack.sp8, &stack.sp8);
        pop_matrix();
        vec3_add_to(&stack.sp8, (u8 *)&this->position);
        create_timed_particle_emitter((&stack.sp8), 0x12D, 0, 0xA);
    }
}

void TUnk_8048E1A4::run_task() {
    u32 active_entity;
    u16 id = *(u16 *)((s8 *)this + 0x358);
    if ((id != 0xffffU) && (id < 0x4000U)) {
        active_entity = find_active_entity_by_id(id);
    } else {
        active_entity = 0U;
    }
    if (active_entity == 0U) {
        queue_destruction();
        disallow_rendering();
        return;
    }
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0) {
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
    if (p != NULL && all_parents_unqueued_for_destruction__7TObjectFv() != 0) {
        ok = p->m8(400.0f, 20.0f);
    }
    if (ok != 0) {
        TObjFish__sub_8001EDB0((s32)((void *)freeze_shell_bml_resource), 1);
        set_global_param__8TObjFishFl();
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
            set_constant_material((const NJS_ARGB *)((&this->m_340)));
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

}

extern "C" {

s32 __ct__13TUnk_8048E1A4FPUcPUc(u32, u32, s32, s32);
u32 __nw__7TObjectFUl(s32);
u16 get_entity_id(void *);

void create__10TObjPlayerFUiii(u32 arg0, s32 arg1, s32 arg2) {
    u16 temp_r3;

    u32 obj;
    if ((is_current_area_item_enabled() != 0) && (arg0 != 0U)) {
        temp_r3 = get_entity_id((void *)arg0);
        if (((u16) temp_r3 != 0xFFFF) && ((u16) temp_r3 < 0x4000U) && ((obj = __nw__7TObjectFUl(0x368)) != 0U)) {
            __ct__13TUnk_8048E1A4FPUcPUc(obj, arg0, arg1, arg2);
        }
    }
}

}

extern const char *bm_eff_ice_model_names[3];
extern const char *bm_eff_ice_motion_names[2];
extern BmlResourceDescriptor enemy_freeze_ice_resource_descriptor;

struct RecoveredGlobal_80082080_lbl_8048E194 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80082080_lbl_8048E194_size[sizeof(RecoveredGlobal_80082080_lbl_8048E194) == 0x10 ? 1 : -1];

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

struct RecoveredFields_8008213C_temp_r3 {
    u8 unknown_0[0x10];
    f32 field_10;
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 __ct__9TObjCharaFP7TObject(void *, void *);
void *create_particle_emitter(void *pos, s32 id);
extern s32 __vt__13TUnk_8048E1A4[];
extern s32 tl_05;
void free_bin_model_request(void*, int);
void __dl__7TObjectFPv(void *);

void TLobby::destroy_global_singleton() {
    if ((u32) freeze_shell_bml_resource != 0U) {
        free_bin_model_request((void*)freeze_shell_bml_resource, 1);
        freeze_shell_bml_resource = 0U;
    }
}

void TLobby::load_freeze_ice_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &enemy_freeze_ice_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&freeze_shell_bml_resource) = var_r0;
}

}
TUnk_8048E1A4::~TUnk_8048E1A4() {
    if (this->m_350 != NULL) { TParticleCtrl::release(this->m_350); }
}
extern "C" {

#pragma push
#pragma fp_contract on
typedef char RecoveredFields_8008213C_arg0_18_offset[offsetof(RecoveredFields_8008213C_arg0, field_18) == 0x18 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_34_offset[offsetof(RecoveredFields_8008213C_arg0, field_34) == 0x34 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_60_offset[offsetof(RecoveredFields_8008213C_arg0, field_60) == 0x60 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_68_offset[offsetof(RecoveredFields_8008213C_arg0, field_68) == 0x68 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_6C_offset[offsetof(RecoveredFields_8008213C_arg0, field_6C) == 0x6C ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_70_offset[offsetof(RecoveredFields_8008213C_arg0, field_70) == 0x70 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_334_offset[offsetof(RecoveredFields_8008213C_arg0, field_334) == 0x334 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_338_offset[offsetof(RecoveredFields_8008213C_arg0, field_338) == 0x338 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_33C_offset[offsetof(RecoveredFields_8008213C_arg0, field_33C) == 0x33C ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_340_offset[offsetof(RecoveredFields_8008213C_arg0, field_340) == 0x340 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_344_offset[offsetof(RecoveredFields_8008213C_arg0, field_344) == 0x344 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_348_offset[offsetof(RecoveredFields_8008213C_arg0, field_348) == 0x348 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_34C_offset[offsetof(RecoveredFields_8008213C_arg0, field_34C) == 0x34C ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_350_offset[offsetof(RecoveredFields_8008213C_arg0, field_350) == 0x350 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_354_offset[offsetof(RecoveredFields_8008213C_arg0, field_354) == 0x354 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg0_358_offset[offsetof(RecoveredFields_8008213C_arg0, field_358) == 0x358 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg2_C_offset[offsetof(RecoveredFields_8008213C_arg2, field_C) == 0xC ? 1 : -1];
typedef char RecoveredFields_8008213C_arg1_60_offset[offsetof(RecoveredFields_8008213C_arg1, field_60) == 0x60 ? 1 : -1];
typedef char RecoveredFields_8008213C_arg1_A4_offset[offsetof(RecoveredFields_8008213C_arg1, field_A4) == 0xA4 ? 1 : -1];
typedef char RecoveredFields_8008213C_temp_r3_10_offset[offsetof(RecoveredFields_8008213C_temp_r3, field_10) == 0x10 ? 1 : -1];
}
TUnk_8048E1A4::TUnk_8048E1A4(u8 *arg1, u8 *arg2) : TObjChara((TObject *)((void *)tl_05)) {
    u8 *temp_r3;
    ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_34 = get_bml_model(freeze_shell_bml_resource, 1);
    if (arg1 != NULL) {
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_358 = get_entity_id(arg1);
        VecCopy((Vec *)(((u8 *)this) + 0x35C), (const Vec *)(arg1 + 0x38));
        if (arg2 != NULL) {
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg2 + 0x1C));
            ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (0.15f * ((RecoveredFields_8008213C_arg2 *)arg2)->field_C);
        } else if ((void *) ((RecoveredFields_8008213C_arg1 *)arg1)->field_A4 != NULL) {
            ((TObjCollidable *)arg1)->refresh_collision_body_centers();
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(((RecoveredFields_8008213C_arg1 *)arg1)->field_A4 + 0x1C));
            ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (0.15f * *(f32 *)((s8 *)(((RecoveredFields_8008213C_arg1 *)arg1)->field_A4) + 0xC));
        } else {
            VecCopy((Vec *)(((u8 *)this) + 0x38), (const Vec *)(arg1 + 0x2FC));
            temp_r3 = ((TObjChara *)arg1)->get_stats();
            if (temp_r3 != NULL) {
                ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = (f32) (0.075f * ((RecoveredFields_8008213C_temp_r3 *)temp_r3)->field_10);
            } else {
                ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_338 = 1.5f;
            }
        }
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_60 = (s32) ((RecoveredFields_8008213C_arg1 *)arg1)->field_60;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_70 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_6C = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_68 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_334 = 0;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_33C = 0;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_340 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_344 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_348 = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_34C = 0.0f;
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_350 = (s32)create_particle_emitter((((u8 *)this) + 0x38), 0x12E);
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_354 = 0;
    } else {
        ((RecoveredFields_8008213C_arg0 *)((u8 *)this))->field_350 = 0;
        queue_destruction();
    }
}
extern "C" {
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
}

void TUnk_8048E1A4::apply_knockback_from_attacker(u8 *, f32) {  }
void TParticleCtrl::set_scale(f32 a, f32 b) { field_40 = a; field_44 = b; }

f32 TObjMotion::get_frame() { return this->frame; }

s32 TObjPlayer::test_action_mask(s32 arg1) {
    return (u8) (((*(s32 *)&this->unk_31C[4]) & arg1) != 0);
}

extern "C" s32 TObjPlayer__sub_80082300(void* p) { return *(s32*)((char*)p + 0xc); }
