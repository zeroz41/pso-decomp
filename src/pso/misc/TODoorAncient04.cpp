#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TODoorAncient04.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80440A88[];
extern char lbl_80440A9C[];
extern char lbl_80440AB4[];
extern const char *bm_fe_obj_o_door04l_model_names[2];
extern const char *bm_fe_obj_o_door04l_motion_names[2];
extern BmlResourceDescriptor door_ancient04_resource_descriptor;

struct VBase { char pad[0x18]; };

struct VObj : VBase { virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7(); virtual s32 m8(f32, f32); };

struct RecoveredGlobal_8016BF68_lbl_80441B4C {
    s32 value;
    u8 remaining[0x8C];
};

struct RecoveredGlobal_8016C010_lbl_80441B4C {
    s32 value;
    u8 remaining[0x8C];
};

struct RecoveredGlobal_8016BC84_lbl_80441ACC {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8016BC84_lbl_804B2B30 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8015EAE0_lbl_804B0EA8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015EAE0___vt__15TODoorAncient04 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
s32 draw_ginja_model_with_motion(void *, int, f32);
extern void *TODoorAncient04__texture_lists;
extern const f32 lbl_805DB408;
u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern RecoveredGlobal_8016BC84_lbl_80441ACC lbl_80440ADC;
extern u32 TODoorAncient04__bml_resource;
s32 init_collision_body_parts(void *, void *, int);
void *init_door_base(void *a0);
extern RecoveredGlobal_8015EAE0_lbl_804B0EA8 TODoorAncient04__collision_body;
extern s32 __vt__15TODoorAncient04[];
extern s32 lbl_805D2F30;
extern const f32 lbl_805DB40C;
u8 *TODoorAncient04__ct(u8 *arg0, s32 arg1, s32 arg2);
void *__dt__15TODoorAncient04Fv(void *arg0, s16 arg1);
s32 play_sound_effect(s32, void *, s32, s32);
void TLobby__sub_8001FE7C(void*, int);
s32 is_any_player_within_radius_xz(f32);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);

void TODoorAncient04::vfunc_20() {  }

extern const f32 lbl_805DB400;

void TODoorAncient04::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if (!(this->m_d0 & 1) || (is_any_player_within_radius_xz(lbl_805DB400) == 0)) {
        this->m_ac = 3;
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 8);
        play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
    }
}

extern const f32 lbl_805DB404;

void TODoorAncient04::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if ((this->m_d0 & 1) && (is_any_player_within_radius_xz(lbl_805DB404) != 0)) {
        this->m_ac = 1;
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 8);
        play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
    }
}

extern void *tl_05;

void TODoorAncient04::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    u8 *temp_r31_4;
    if ((((VObj *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) && (((TUnk_804AFBF8 *)arg0)->is_in_view_depth(lbl_805DB408) != 0)) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)(*(s32 *)&TODoorAncient04__texture_lists) + ((this->m_d0 * 4) & 4))));
        if ((s32) *(s32 *)&this->m_ac == 0) {
            temp_r31 = *(u8 * *)&this->model;
            post_translate_matrix(temp_r31 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
            temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x2C);
            push_matrix();
            post_translate_matrix(temp_r31_2 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
            TParticleCtrl::begin_effect_render();
            temp_r31_3 = *(u8 **)((s8 *)temp_r31_2 + 0x30);
            push_matrix();
            post_translate_matrix(temp_r31_3 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
            pop_matrix();
            temp_r31_4 = *(u8 **)((s8 *)temp_r31_3 + 0x30);
            push_matrix();
            post_translate_matrix(temp_r31_4 + 8);
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_4 + 4)));
            pop_matrix();
            TParticleCtrl::end_effect_render();
        } else {
            draw_ginja_model_with_motion((void *) (*(u8 * *)&this->model), (int) (*(s32 *)&this->m_bc), this->m_b0);
        }
        pop_matrix();
    }
}

void *TODoorAncient04::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD4);
    if (o != NULL) {
        o = TODoorAncient04__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODoorAncient04::cleanup_refs() {
    if ((void *) TODoorAncient04__texture_lists != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TODoorAncient04__texture_lists + 4));
        if ((void *) TODoorAncient04__texture_lists != NULL) {
            mem_free(TODoorAncient04__texture_lists);
            TODoorAncient04__texture_lists = NULL;
        }
    }
    if ((u32) TODoorAncient04__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TODoorAncient04__bml_resource, 1);
        TODoorAncient04__bml_resource = 0U;
    }
}

typedef char RecoveredGlobal_8016BC84_lbl_80441ACC_size[sizeof(RecoveredGlobal_8016BC84_lbl_80441ACC) == 0x18 ? 1 : -1];
typedef char RecoveredGlobal_8016BC84_lbl_804B2B30_size[sizeof(RecoveredGlobal_8016BC84_lbl_804B2B30) == 0x10 ? 1 : -1];
void TODoorAncient04::load_resources() {
    s32 *temp_r3_2;
    u8 *temp_r3;
    u8 *var_r0;
    temp_r3 = (u8 *)((int)::operator new(0x440));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(load_resource_from_descriptor(temp_r3, 1, &door_ancient04_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TODoorAncient04__bml_resource) = var_r0;
    temp_r3_2 = (s32 *)(mem_alloc(8));
    (*(s32 * *)&TODoorAncient04__texture_lists) = temp_r3_2;
    *temp_r3_2 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorAncient04__bml_resource) + 0x42C)) + 0xC);
    *(s32 *)((s8 *)(*(s32 * *)&TODoorAncient04__texture_lists) + 4) = (s32)load_gvm_texture_file((s32)&lbl_80440ADC.value);
}
typedef char RecoveredGlobal_8016BF68_lbl_80441B4C_size[sizeof(RecoveredGlobal_8016BF68_lbl_80441B4C) == 0x90 ? 1 : -1];
typedef char RecoveredGlobal_8016C010_lbl_80441B4C_size[sizeof(RecoveredGlobal_8016C010_lbl_80441B4C) == 0x90 ? 1 : -1];

void *__dt__15TODoorAncient04Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TODoorAncient04;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B0BB8 *)arg0)->destroy_ancient_door_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8015EAE0_lbl_804B0EA8_size[sizeof(RecoveredGlobal_8015EAE0_lbl_804B0EA8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015EAE0___vt__15TODoorAncient04_size[sizeof(RecoveredGlobal_8015EAE0___vt__15TODoorAncient04) == 0x54 ? 1 : -1];
u8 *TODoorAncient04__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_door_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8015EAE0___vt__15TODoorAncient04 *)&__vt__15TODoorAncient04).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2F30;
    ((TODoorAncient04 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorAncient04__bml_resource) + 0x42C)) + 8);
    ((TODoorAncient04 *)arg0)->texture_id = (s32) *(s32 *)((s8 *)(*(u8 * *)&TODoorAncient04__texture_lists) + 4);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorAncient04__bml_resource) + 0x430)) + 4));
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - lbl_805DB40C);
    ((TODoorAncient04 *)arg0)->m_b8 = (f32) (*(f32 *)((s8 *)arg0 + 0xB4) / lbl_805DB408);
    init_collision_body_parts(arg0, &TODoorAncient04__collision_body.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TODoorAncient04 *)(arg0))->init_door_switch_binding();
    return arg0;
}

__declspec(section ".data") const char *bm_fe_obj_o_door04l_model_names[2] = { lbl_80440A88, NULL };
__declspec(section ".data") const char *bm_fe_obj_o_door04l_motion_names[2] = { lbl_80440A9C, NULL };
BmlResourceDescriptor door_ancient04_resource_descriptor = { lbl_80440AB4, bm_fe_obj_o_door04l_model_names, bm_fe_obj_o_door04l_motion_names, 1, 1 };
}
