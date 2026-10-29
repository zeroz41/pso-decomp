#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_801F43B4.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TODoorVoShip.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80163B8C_lbl_804B1760 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80163B8C_lbl_804B1760_size[sizeof(RecoveredGlobal_80163B8C_lbl_804B1760) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80163C44_lbl_804B1770 { s32 value; u8 remaining[0x28]; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80163B8C_lbl_804B1760 bm_o_door_vo_ship_resource_descriptor;
extern u32 TODoorVoShip__shared_bml_archive;
s32 get_bml_motion(void *, s32);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u32 init_collision_body_parts(void *, s32, s32);
extern RecoveredGlobal_80163C44_lbl_804B1770 door_vo_ship_collision_body_parts;
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
}

extern void *tl_05;

#pragma push
#pragma opt_common_subs off
void TODoorVoShip::run_task() {
    if (this->light_flags & 0xE) {
        update_anim_phase();
        if (this->light_flags & 0x10) {
            this->light_color[0] = (f32) (this->light_color[0] + lbl_805DB530);
            if (lbl_805DB534 <= this->light_color[0]) {
                this->light_color[0] = (f32) lbl_805DB534;
                this->light_flags = (s32) (this->light_flags & 0xFFFFFFEF);
            }
        } else {
            this->light_color[0] = (f32) (this->light_color[0] - lbl_805DB530);
            if (this->light_color[0] <= lbl_805DB538) {
                this->light_color[0] = (f32) lbl_805DB538;
                this->light_flags = (s32) (this->light_flags | 0x10);
            }
        }
        if (get_story_flag(0x2C) != 0) {
            this->light_flags = (s32) (this->light_flags & 0xFFFFFFFD);
        }
        if (get_story_flag(0x2D) != 0) {
            this->light_flags = (s32) (this->light_flags & 0xFFFFFFFB);
        }
        if (get_story_flag(0x2E) != 0) {
            this->light_flags = (s32) (this->light_flags & 0xFFFFFFF7);
        }
        if ((get_story_flag(0x2F) != 0) || (get_main_phase() == 0xF)) {
            this->light_flags = (s32) (this->light_flags & 0xFFFFFFF1);
            clear_player_status_flag(0, (int)(1U));
        }
    }
}
#pragma pop

void TODoorVoShip::render() {
    s32 temp_r4;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    u8 *temp_r31_4;
    if ((update_object_view_visibility(this->m_c0, this->model_radius) != 0) && (*(s32 *)&this->light_flags & 0xE)) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        TObjEneSlimeOne__sub_803E4B54((void *)(*(s32 *)&this->model), (void *)(*(s32 *)&this->m_bc), (void *)(*(s32 *)&this->light_motion), this->m_b0);
        TObjFish::set_global_param((int) (*(s32 *)&this->light_texlist));
        temp_r4 = model_render_flags;
        saved_model_render_flags = temp_r4;
        model_render_flags = temp_r4 | 0x20;
        set_constant_material((const NJS_ARGB *)&this->light_color[0]);
        TParticleCtrl::begin_effect_render();
        temp_r31 = *(u8 * *)&this->light_model;
        push_matrix();
        post_translate_matrix(temp_r31 + 8);
        temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x2C);
        if (*(s32 *)&this->light_flags & 4) {
            push_matrix();
            post_translate_matrix(temp_r31_2 + 8);
            draw_chunk_model((void *)(*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
        }
        temp_r31_3 = *(u8 **)((s8 *)temp_r31_2 + 0x30);
        if (*(s32 *)&this->light_flags & 2) {
            push_matrix();
            post_translate_matrix(temp_r31_3 + 8);
            draw_chunk_model((void *)(*(s32 *)((s8 *)temp_r31_3 + 4)));
            pop_matrix();
        }
        temp_r31_4 = *(u8 **)((s8 *)temp_r31_3 + 0x30);
        if (*(s32 *)&this->light_flags & 8) {
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
    return new TODoorVoShip((TObject *)tl_05, arg0);
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

// The destructor is still written out by hand: compiled, its vtable would
// open the unit's .data, which the original fills first with the object's
// resource and collision tables (not owned by this unit yet).
extern "C" {
extern void *__vt__12TODoorVoShip[];
void __dl__7TObjectFPv(void *);

void *__dt__12TODoorVoShipFv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__12TODoorVoShip;
        ((TODoorVoShip *)self)->unregister_object_by_id();
        free_collision_body_parts((TODoorVoShip *)self);
        __dt__13TObjMapObjectFv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

TODoorVoShip::TODoorVoShip(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = (const char *)TODoorVoShip__class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model((*(u8 * *)&TODoorVoShip__shared_bml_archive), 1);
    texlist = TObjFish__sub_8001EDB0((*(u8 * *)&TODoorVoShip__shared_bml_archive), 1);
    m_bc = get_bml_motion((*(u8 * *)&TODoorVoShip__shared_bml_archive), 0);
    animation_end_frame = (f32) ((f32) *(u32 *)(m_bc + 4) - lbl_805DB53C);
    m_b8 = (f32) lbl_805DB53C;
    light_motion = get_bml_motion((*(u8 * *)&TODoorVoShip__shared_bml_archive), 1);
    light_model = get_bml_model((*(u8 * *)&TODoorVoShip__shared_bml_archive), 0);
    light_texlist = TObjFish__sub_8001EDB0((*(u8 * *)&TODoorVoShip__shared_bml_archive), 0);
    init_collision_body_parts(this, (s32) &door_vo_ship_collision_body_parts.value, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    m_c0 = (f32) lbl_805DB540;
    model_radius = (f32) lbl_805DB544;
    light_flags = 0xE;
    light_color[3] = (f32) lbl_805DB534;
    light_color[2] = (f32) lbl_805DB534;
    light_color[1] = (f32) lbl_805DB534;
    light_color[0] = (f32) lbl_805DB534;
    if (get_story_flag(0x2C) != 0) {
        light_flags = (s32) (light_flags & 0xFFFFFFFD);
    }
    if (get_story_flag(0x2D) != 0) {
        light_flags = (s32) (light_flags & 0xFFFFFFFB);
    }
    if (get_story_flag(0x2E) != 0) {
        light_flags = (s32) (light_flags & 0xFFFFFFF7);
    }
    if ((get_story_flag(0x2F) != 0) || (get_main_phase() == 0xF)) {
        light_flags = (s32) (light_flags & 0xFFFFFFF1);
        clear_player_status_flag(0, 1);
    }
}
