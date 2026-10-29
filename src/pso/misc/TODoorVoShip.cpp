#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TODoorVoShip.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" void *__ct__13TUnk_804AFBF8FP7TObject(void *self);

struct RecoveredGlobal_80163B8C_lbl_804B1760 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80163B8C_lbl_804B1760_size[sizeof(RecoveredGlobal_80163B8C_lbl_804B1760) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80163C44_lbl_804B1770 { s32 value; u8 remaining[0x28]; };

struct RecoveredGlobal_80163C44___vt__12TODoorVoShip { s32 value; u8 remaining[0x38]; };

struct VBase_801639B4 { char pad[0x18]; };

struct VObj_801639B4 : VBase_801639B4 { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80163B8C_lbl_804B1760 bm_o_door_vo_ship_resource_descriptor;
extern u32 TODoorVoShip__shared_bml_archive;
s32 get_bml_motion(void *, s32);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
extern RecoveredGlobal_80163C44_lbl_804B1770 door_vo_ship_collision_body_parts;
extern s32 __vt__12TODoorVoShip[];
extern s32 TODoorVoShip__class_name;
extern const f32 lbl_805DB534;
extern const f32 lbl_805DB53C;
extern const f32 lbl_805DB540;
extern const f32 lbl_805DB544;
extern const f32 lbl_805DB530;
extern const f32 lbl_805DB538;
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
void TObjEneSlimeOne__sub_803E4B54(void *child, void *arg1, void *arg2, f32 farg0);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

#pragma push
#pragma opt_common_subs off
void TODoorVoShip::run_task() {
    u8 *arg0 = (u8 *)this;
    if (this->m_cc & 0xE) {
        ((TUnk_804AFBF8 *)arg0)->update_anim_phase();
        if (this->m_cc & 0x10) {
            *(f32 *)&this->m_dc = (f32) (*(f32 *)&this->m_dc + lbl_805DB530);
            if (lbl_805DB534 <= *(f32 *)&this->m_dc) {
                *(f32 *)&this->m_dc = (f32) lbl_805DB534;
                this->m_cc = (s32) (this->m_cc & 0xFFFFFFEF);
            }
        } else {
            *(f32 *)&this->m_dc = (f32) (*(f32 *)&this->m_dc - lbl_805DB530);
            if (*(f32 *)&this->m_dc <= lbl_805DB538) {
                *(f32 *)&this->m_dc = (f32) lbl_805DB538;
                this->m_cc = (s32) (this->m_cc | 0x10);
            }
        }
        if (get_story_flag(0x2C) != 0) {
            this->m_cc = (s32) (this->m_cc & 0xFFFFFFFD);
        }
        if (get_story_flag(0x2D) != 0) {
            this->m_cc = (s32) (this->m_cc & 0xFFFFFFFB);
        }
        if (get_story_flag(0x2E) != 0) {
            this->m_cc = (s32) (this->m_cc & 0xFFFFFFF7);
        }
        if ((get_story_flag(0x2F) != 0) || (get_main_phase() == 0xF)) {
            this->m_cc = (s32) (this->m_cc & 0xFFFFFFF1);
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, (int)(1U));
        }
    }
}
#pragma pop

void TODoorVoShip::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    u8 *temp_r31_4;
    if ((((VObj_801639B4 *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) && (*(s32 *)&this->m_cc & 0xE)) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        TObjEneSlimeOne__sub_803E4B54((void *)(*(s32 *)&this->model), (void *)(*(s32 *)&this->m_bc), (void *)(*(s32 *)&this->m_d0), this->m_b0);
        TObjFish::set_global_param((int) (*(s32 *)&this->m_d8));
        temp_r4 = model_render_flags;
        saved_model_render_flags = temp_r4;
        model_render_flags = temp_r4 | 0x20;
        set_constant_material((const NJS_ARGB *)((arg0 + 0xDC)));
        TParticleCtrl::begin_effect_render();
        temp_r31 = *(u8 * *)&this->m_d4;
        push_matrix();
        post_translate_matrix(temp_r31 + 8);
        temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x2C);
        if (*(s32 *)&this->m_cc & 4) {
            push_matrix();
            post_translate_matrix(temp_r31_2 + 8);
            draw_chunk_model((void *)(*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
        }
        temp_r31_3 = *(u8 **)((s8 *)temp_r31_2 + 0x30);
        if (*(s32 *)&this->m_cc & 2) {
            push_matrix();
            post_translate_matrix(temp_r31_3 + 8);
            draw_chunk_model((void *)(*(s32 *)((s8 *)temp_r31_3 + 4)));
            pop_matrix();
        }
        temp_r31_4 = *(u8 **)((s8 *)temp_r31_3 + 0x30);
        if (*(s32 *)&this->m_cc & 8) {
            push_matrix();
            post_translate_matrix(temp_r31_4 + 8);
            draw_chunk_model((void *)(*(s32 *)((s8 *)temp_r31_4 + 4)));
            pop_matrix();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
    }
}

void *TODoorVoShip::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xEC);
    if (o != NULL) {
        o = TODoorVoShip__ct((TODoorVoShip *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODoorVoShip::free_static_data() {
    if ((u32) TODoorVoShip__shared_bml_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TODoorVoShip__shared_bml_archive, 1);
        TODoorVoShip__shared_bml_archive = 0U;
    }
}

void TODoorVoShip::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_door_vo_ship_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TODoorVoShip__shared_bml_archive) = var_r0;
}

void *__dt__12TODoorVoShipFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TODoorVoShip;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AFBF8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TODoorVoShip__ct(TODoorVoShip *arg0, s32 arg1, s32 arg2) {
    __ct__13TUnk_804AFBF8FP7TObject(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80163C44___vt__12TODoorVoShip *)&__vt__12TODoorVoShip).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TODoorVoShip__class_name;
    ((TODoorVoShip *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((*(u8 * *)&TODoorVoShip__shared_bml_archive), 1);
    arg0->texlist = TObjFish__sub_8001EDB0((*(u8 * *)&TODoorVoShip__shared_bml_archive), 1);
    arg0->m_bc = get_bml_motion((*(u8 * *)&TODoorVoShip__shared_bml_archive), 0);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)(arg0->m_bc + 4) - lbl_805DB53C);
    arg0->m_b8 = (f32) lbl_805DB53C;
    arg0->m_d0 = get_bml_motion((*(u8 * *)&TODoorVoShip__shared_bml_archive), 1);
    arg0->m_d4 = get_bml_model((*(u8 * *)&TODoorVoShip__shared_bml_archive), 0);
    arg0->m_d8 = TObjFish__sub_8001EDB0((*(u8 * *)&TODoorVoShip__shared_bml_archive), 0);
    init_collision_body_parts(arg0, (s32) &door_vo_ship_collision_body_parts.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    arg0->m_c0 = (f32) lbl_805DB540;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB544;
    arg0->m_cc = 0xE;
    *(f32 *)((s8 *)arg0 + 0xE8) = (f32) lbl_805DB534;
    arg0->m_e4 = (f32) lbl_805DB534;
    *(f32 *)((s8 *)arg0 + 0xE0) = (f32) lbl_805DB534;
    *(f32 *)((s8 *)arg0 + 0xDC) = (f32) lbl_805DB534;
    if (get_story_flag(0x2C) != 0) {
        arg0->m_cc = (s32) (arg0->m_cc & 0xFFFFFFFD);
    }
    if (get_story_flag(0x2D) != 0) {
        arg0->m_cc = (s32) (arg0->m_cc & 0xFFFFFFFB);
    }
    if (get_story_flag(0x2E) != 0) {
        arg0->m_cc = (s32) (arg0->m_cc & 0xFFFFFFF7);
    }
    if (get_story_flag(0x2F) == 0) {
        if (get_main_phase() == 0xF) {
            goto block_8;
        }
    } else {
block_8:
        arg0->m_cc = (s32) (arg0->m_cc & 0xFFFFFFF1);
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
    }
    return (u8 *)arg0;
}

}
