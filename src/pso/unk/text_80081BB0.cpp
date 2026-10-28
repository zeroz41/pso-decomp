#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss8Dragon_80065C90.h"
#include "pso/misc/TParticleCtrl_800867E4.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_8048E1A4.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
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
extern const f32 lbl_805D9378;
extern const f32 lbl_805D9388;
extern const f32 lbl_805D938C;
s32 obj_testFlags30__13TUnk_804AF8A0FUl(s32, s32);
s32 get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(s32, s32);
s32 get_bml_model(s32, s32);
void *spawn_particle_effect(void *pos, s32 id);
extern s32 freeze_shell_bml_resource;
extern s32 technique_effect_bml;
extern s32 lbl_805D63B0;
extern const f32 lbl_805D9384;
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 set_global_param__8TObjFishFl();
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9390;
extern const f32 lbl_805D9394;

s32 TUnk_8048E1A4::freeze_shell_hold() {
    s32 p;
    p = find_active_entity_by_id(*(u16 *)((s8 *)this + 0x358));
    if (p == 0) {
        return;
    }
    this->rotation_y += 0x10;
    if (obj_testFlags30__13TUnk_804AF8A0FUl(p, 0x800) == 0) {
        if (obj_testFlags30__13TUnk_804AF8A0FUl(p, 0x20) != 0) {
            return;
        }
    }
    *(s32 *)((s8 *)this + 0x334) = 2;
    p = (s32)spawn_particle_effect((u8 *)this + 0x35C, 0x153);
    if (p != 0) {
        attach_particle_model((u8 *)p, (s32)(get_bml_model(technique_effect_bml, 5)), (s32)lbl_805D63B0, 0, 0, (f32)lbl_805D9384);
    }
    p = (s32)spawn_particle_effect((u8 *)this + 0x38, 0x33);
    if (p != 0) {
        attach_particle_model((u8 *)p, (s32)(get_bml_model(freeze_shell_bml_resource, 0)), (s32)(TObjFish__sub_8001EDB0(freeze_shell_bml_resource, 1)), (s32)(get_bml_motion(freeze_shell_bml_resource, 0)), 0, (f32)lbl_805D9384);
        ((TObjPlayer *)p)->set_position_xy(this->scale.x, this->scale.y);
    }
    this->m_c0 = lbl_805D9378;
}

void TUnk_8048E1A4::freeze_shell_grow() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_80081CD0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80081CD0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80081CD0, sp10) == 0x8) ? 1 : -1];
    Stack_80081CD0 stack;
    f32 temp_f0;
    this->rotation_y = (this->rotation_y + 0x1000);
    this->scale.z = (f32) (this->scale.z + lbl_805D9388);
    temp_f0 = this->scale.z;
    this->scale.y = temp_f0;
    this->scale.x = temp_f0;
    if (this->m_338 < this->scale.x) {
        *(s32 *)((s8 *)arg0 + 0x334) = 1;
    }
    *(s32 *)((s8 *)arg0 + 0x33C) = (s32) (*(s32 *)((s8 *)arg0 + 0x33C) + 1);
    if ((*(s32 *)((s8 *)arg0 + 0x33C) % 3) == 0) {
        stack.sp8 = lbl_805D9378;
        stack.spC = lbl_805D9378;
        stack.sp10 = lbl_805D938C * this->scale.x;
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
        queue_destruction__7TObjectFv(this);
        disallow_rendering__7TObjectFv(this);
        return;
    }
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0) {
        disallow_rendering__7TObjectFv(this);
        queue_destruction__7TObjectFv(this);
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
        ok = p->m8(lbl_805D9390, lbl_805D9394);
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
