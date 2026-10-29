#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TODoorCave02.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/misc/TODoorCave02_8016206C.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TODoorAncient01.h"

extern "C" {
s32 play_sound_effect(s32, void *, s32, s32);

s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
struct Base_80161D38 { char pad[0x18]; };
struct VObj_80161D38 : Base_80161D38 {
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

s32 draw_ginja_model_with_motion(void *, s32, f32);
s32 rotate_matrix_y(s32, s32);

void TODoorCave02::vfunc_20() {  }

extern u8 *cave_door02_resources;

void TODoorCave02::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if (this->m_d0 & 1) {
        this->texlist = (s32) *(s32 *)((s8 *)cave_door02_resources + 4);
        if (((TUnk_804AFBF8 *)arg0)->is_any_player_within_radius_xz(1e+04f) != 1) {
            this->m_ac = 3;
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
            play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
        }
    } else {
        this->m_ac = 3;
        this->texlist = (s32) *(s32 *)((s8 *)cave_door02_resources + 0);
        ((TObjCollidable *)arg0)->clear_player_status_flag((s32)NULL, 8);
        play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
    }
}

void TODoorCave02::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if (this->m_d0 & 0x100000) {
        this->m_d8 += 0.1f;
        if (1.0f <= this->m_d8) {
            this->m_d0 = (s32) (this->m_d0 & 0xFFEFFFFF);
        }
    } else {
        this->m_d8 = (f32) (this->m_d8 - 0.1f);
        if (this->m_d8 <= 0.0f) {
            this->m_d0 = (s32) (this->m_d0 | 0x100000);
        }
    }
    if ((this->m_d0 & 1) && (((TUnk_804AFBF8 *)arg0)->is_any_player_within_radius_xz(4.9e+03f) == 1)) {
        this->m_ac = 1;
        ((TObjCollidable *)arg0)->set_indexed_flags(0, 8);
        play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
    }
}

s32 TODoorCave02::draw_parts(void *arg1_) {
    u8 *arg0 = (u8 *)this;
    u8 *arg1 = (u8 *)arg1_;
    s32 temp_r4;
    u8 *temp_r31;
    u8 *temp_r31_2;
    push_matrix();
    post_translate_matrix(arg1 + 8);
    draw_ginja_model((*(s32 *)((s8 *)arg1 + 4)));
    TParticleCtrl::begin_effect_render();
    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x10;
    set_constant_material((const NJS_ARGB *)((arg0 + 0xD4)));
    push_matrix();
    temp_r31 = *(u8 **)((s8 *)arg1 + 0x2C);
    post_translate_matrix(temp_r31 + 8);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
    pop_matrix();
    push_matrix();
    temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x30);
    post_translate_matrix(temp_r31_2 + 8);
    draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
    pop_matrix();
    set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TODoorCave02::render() {
    u8 *arg0 = (u8 *)this;
    if ((((VObj_80161D38 *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) && (((TUnk_804AFBF8 *)arg0)->is_in_view_depth(3e+01f) != 0)) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) *(s32 *)&this->m_ac == 0) {
            TObjFish::set_global_param(*(s32 *)(cave_door02_resources + ((this->m_d0 * 4) & 4)));
            draw_parts((void *)(*(void **)((s8 *)(*(void * *)&this->model) + 0x2C)));
            draw_parts((void *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void * *)&this->model) + 0x2C)) + 0x30)));
        } else {
            TObjFish::set_global_param(*(s32 *)((s8 *)cave_door02_resources + 4));
            draw_ginja_model_with_motion(*(void * *)&this->model, *(s32 *)&this->m_bc, this->m_b0);
        }
        pop_matrix();
    }
}

}

extern "C" {
extern char lbl_80440DB8[];
extern char lbl_80440DCC[];
extern char lbl_80440DE0[];
extern char lbl_80440DF8[];
__declspec(section ".data") const char *bm_fs_obj_do_doa02_model_names[2] = { lbl_80440DB8, NULL };
__declspec(section ".data") const char *bm_fs_obj_do_doa02_motion_names[2] = { lbl_80440DCC, NULL };
BmlResourceDescriptor TODoorCave02__resource_descriptor = { lbl_80440DE0, bm_fs_obj_do_doa02_model_names, bm_fs_obj_do_doa02_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_fs_obj_do_doa02_a_model_names[2] = { lbl_80440DB8, NULL };
__declspec(section ".data") const char *bm_fs_obj_do_doa02_a_motion_names[2] = { lbl_80440DCC, NULL };
BmlResourceDescriptor TODoorCave02_resource_descriptor = { lbl_80440DF8, bm_fs_obj_do_doa02_a_model_names, bm_fs_obj_do_doa02_a_motion_names, 1, 1 };
}

struct RecoveredGlobal_8016226C_lbl_804B1488 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8016226C___vt__12TODoorCave02 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
s32 init_collision_body_parts(void *, void *, int);
void *__ct__13TUnk_804B0BB8FP7TObject(void *a0);
extern RecoveredGlobal_8016226C_lbl_804B1488 TODoorCave02__collision_body_parts;
extern s32 __vt__12TODoorCave02[];
extern s32 lbl_805D2F68;
extern u32 cave_door02_model_resource;

void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_80440E24[];
extern u8 lbl_80440E3C[];

extern s32 enable_v2_features;

void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);

extern void *tl_05;

void *TODoorCave02::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE4);
    if (o != NULL) {
        o = TODoorCave02__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODoorCave02::free_globals() {
    if ((s32 *) cave_door02_resources != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)cave_door02_resources);
        if ((s32 *) cave_door02_resources != NULL) {
            mem_free(cave_door02_resources);
            cave_door02_resources = NULL;
        }
    }
    if ((u32) cave_door02_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)cave_door02_model_resource, 1);
        cave_door02_model_resource = 0U;
    }
}

void TODoorCave02::load_resources() {
    void *o;
    cave_door02_resources = (u8 *)mem_alloc(8);
    if (enable_v2_features == 1 && TLobby::is_online_ready() != 0) {
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &TODoorCave02_resource_descriptor, 0, 0, 0);
        }
        cave_door02_model_resource = (u32)o;
        ((s32 *)cave_door02_resources)[0] = (s32)load_gvm_texture_file((s32)lbl_80440E24);
    } else {
        o = ::operator new(0x440);
        if (o != NULL) {
            o = load_resource_from_descriptor(o, 1, &TODoorCave02__resource_descriptor, 0, 0, 0);
        }
        cave_door02_model_resource = (u32)o;
        ((s32 *)cave_door02_resources)[0] = (s32)load_gvm_texture_file((s32)lbl_80440E3C);
    }
    ((s32 *)cave_door02_resources)[1] = *(s32 *)(*(u8 **)(cave_door02_model_resource + 0x42C) + 0xC);
}

void *__dt__12TODoorCave02Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TODoorCave02;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804B0BB8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8016226C_lbl_804B1488_size[sizeof(RecoveredGlobal_8016226C_lbl_804B1488) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8016226C___vt__12TODoorCave02_size[sizeof(RecoveredGlobal_8016226C___vt__12TODoorCave02) == 0x54 ? 1 : -1];
u8 *TODoorCave02__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__13TUnk_804B0BB8FP7TObject((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8016226C___vt__12TODoorCave02 *)&__vt__12TODoorCave02).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2F68;
    ((TODoorCave02 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&cave_door02_model_resource) + 0x42C)) + 8);
    ((TODoorCave02 *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&cave_door02_model_resource) + 0x42C)) + 0xC);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&cave_door02_model_resource) + 0x430)) + 4));
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - 1.0f);
    ((TODoorCave02 *)arg0)->m_b8 = (f32) 0.5f;
    init_collision_body_parts(arg0, &TODoorCave02__collision_body_parts.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TODoorCave02 *)(arg0))->init_door_switch_binding();
    *(f32 *)((s8 *)arg0 + 0xD4) = (f32) 1.0f;
    ((TODoorCave02 *)arg0)->m_d8 = (f32) 1.0f;
    *(f32 *)((s8 *)arg0 + 0xDC) = (f32) 1.0f;
    ((TODoorCave02 *)arg0)->m_e0 = (f32) 1.0f;
    return arg0;
}

}
