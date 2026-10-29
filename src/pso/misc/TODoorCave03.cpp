#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/object/TObjMapObject.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TODoorCave03.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
extern char lbl_80440E60[];
extern char lbl_80440E74[];
extern char lbl_80440E88[];
extern char lbl_80440EA0[];
__declspec(section ".data") const char *bm_fs_obj_do_doa03_model_names[2] = { lbl_80440E60, NULL };
__declspec(section ".data") const char *bm_fs_obj_do_doa03_motion_names[2] = { lbl_80440E74, NULL };
BmlResourceDescriptor TODoorCave03__resource_descriptor = { lbl_80440E88, bm_fs_obj_do_doa03_model_names, bm_fs_obj_do_doa03_motion_names, 1, 1 };
__declspec(section ".data") const char *bm_fs_obj_do_doa03_a_model_names[2] = { lbl_80440E60, NULL };
__declspec(section ".data") const char *bm_fs_obj_do_doa03_a_motion_names[2] = { lbl_80440E74, NULL };
BmlResourceDescriptor door_cave03_resource_descriptor = { lbl_80440EA0, bm_fs_obj_do_doa03_a_model_names, bm_fs_obj_do_doa03_a_motion_names, 1, 1 };
}

struct RecoveredGlobal_80162740_lbl_804B1518 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80162740_lbl_804B1518_size[sizeof(RecoveredGlobal_80162740_lbl_804B1518) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80162740_lbl_804B1538 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80162740_lbl_804B1538_size[sizeof(RecoveredGlobal_80162740_lbl_804B1538) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80162848_lbl_804B1548 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80162848___vt__12TODoorCave03 {
    s32 value;
    u8 remaining[0x50];
};

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
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

struct Model_801625AC {
    u8 pad0[4];
    s32 m4;
    u8 m8[0x24];
    Model_801625AC *child;
    Model_801625AC *next;
};

extern "C" {
extern const f32 lbl_805DB4D8;
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
extern const f32 lbl_805DB4D0;
extern const f32 TODoorCave03__data_805DB4D4;
extern const f32 lbl_805DB4DC;
extern const f32 lbl_805DB4E0;
extern const f32 lbl_805DB4E4;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);

extern s32 enable_v2_features;
extern u32 TODoorCave03__model_resource;
s32 init_collision_body_parts(void *, void *, int);
void *__ct__13TUnk_804B0BB8FP7TObject(void *a0);
extern RecoveredGlobal_80162848_lbl_804B1548 lbl_804B1548;
extern s32 __vt__12TODoorCave03[];
extern s32 TODoorCave03__class_name;
u8 *TODoorCave03__ct(u8 *arg0, s32 arg1, s32 arg2);
void rotate_matrix_y(s32, s32);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(void *);
void draw_ginja_model(s32);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805DB4E8;
void render__12TODoorCave03Fv(u8 *arg0);
void *__dt__12TODoorCave03Fv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TODoorCave03::vfunc_20() {  }

extern void *tl_05;

void TODoorCave03::vfunc_18() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    f32 temp_f3;
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x3C);
    temp_f3 = *(f32 *)((s8 *)arg0 + 0x54);
    if ((temp_f2 - temp_f3) <= lbl_805DB4D0) {
        *(f32 *)((s8 *)arg0 + 0x3C) = temp_f3;
        *(s32 *)((s8 *)arg0 + 0xAC) = 0;
    } else {
        *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (temp_f2 - TODoorCave03__data_805DB4D4);
    }
    play_persistent_sound(0x42807, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
}

void TODoorCave03::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if (this->m_d0 & 1) {
        if (((TObjMapObject *)arg0)->is_any_player_within_radius_xz(lbl_805DB4D8) != 1) {
            this->m_ac = 3;
            ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8U);
        }
    } else {
        this->m_ac = 3;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8U);
    }
}

void TODoorCave03::vfunc_16() {
    u8 *arg0 = (u8 *)this;
  f32 temp_f1;
  f32 temp_f3;
  temp_f1 = *((f32 *) (((s8 *) arg0) + 0x3C));
  temp_f3 = *((f32 *) (((s8 *) arg0) + 0x54));
  if (lbl_805DB4DC <= ((*((f32 *) (((s8 *) arg0) + 0x3C))) - temp_f3))
  {
    *((f32 *) (((s8 *) arg0) + 0x3C)) = (f32) (lbl_805DB4DC + temp_f3);
    *((s32 *) (((s8 *) arg0) + 0xAC)) = 2;
  }
  else
  {
    *((f32 *) (((s8 *) arg0) + 0x3C)) = (f32) (temp_f1 + TODoorCave03__data_805DB4D4);
  }
  play_persistent_sound(0x42807, (s32)arg0, (u32)(arg0 + 0x38), 0, 0);
}

void TODoorCave03::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = this->m_d0;
    if (temp_r4 & 1) {
        if (((TObjMapObject *)arg0)->is_any_player_within_radius_xz(lbl_805DB4E0) == 1) {
            this->m_ac = 1;
            ((TObjCollidable *)arg0)->set_indexed_flags(0, 8);
        }
    } else if (temp_r4 & 0x10000) {
        *(f32 *)((s8 *)arg0 + 0xD8) = (f32) (*(f32 *)((s8 *)arg0 + 0xD8) + lbl_805DB4E4);
        if (TODoorCave03__data_805DB4D4 <= *(f32 *)((s8 *)arg0 + 0xD8)) {
            this->m_d0 = (s32) (this->m_d0 & 0xFFFEFFFF);
        }
    } else {
        *(f32 *)((s8 *)arg0 + 0xD8) = (f32) (*(f32 *)((s8 *)arg0 + 0xD8) - lbl_805DB4E4);
        if (*(f32 *)((s8 *)arg0 + 0xD8) <= lbl_805DB4D0) {
            this->m_d0 = (s32) (this->m_d0 | 0x10000);
        }
    }
}

void render__12TODoorCave03Fv(u8 *arg0) {
    Model_801625AC *m;
    if (((VObj_18_26a62c *)(arg0))->m8(*(f32 *)(arg0 + 0xC0), *(f32 *)(arg0 + 0xC4)) != 0 &&
        ((TObjMapObject *)arg0)->is_in_view_depth(lbl_805DB4E8) != 0) {
        TObjFish::set_global_param(*(s32 *)(arg0 + 0x24));
        push_matrix();
        post_translate_matrix(arg0 + 0x38);
        rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
        m = *(Model_801625AC **)(arg0 + 0x34);
        post_translate_matrix(m->m8);
        draw_ginja_model(m->m4);
        TParticleCtrl::begin_effect_render();
        saved_model_render_flags = model_render_flags;
        model_render_flags |= 0x10;
        set_constant_material((const NJS_ARGB *)((arg0 + 0xD4)));
        if (*(s32 *)(arg0 + 0xD0) & 1) {
            m = (*(Model_801625AC **)(arg0 + 0x34))->child->next;
        } else {
            m = (*(Model_801625AC **)(arg0 + 0x34))->child;
        }
        post_translate_matrix(m->m8);
        draw_ginja_model(m->m4);
        m = m->child;
        post_translate_matrix(m->m8);
        draw_ginja_model(m->m4);
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TODoorCave03::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE4);
    if (o != NULL) {
        o = TODoorCave03__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODoorCave03::free_shared_data() {
    if ((u32) TODoorCave03__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TODoorCave03__model_resource, 1);
        TODoorCave03__model_resource = 0U;
    }
}

void TODoorCave03::load_resources() {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    if (((s32) enable_v2_features == 1) && (TLobby::is_online_ready() != 0)) {
        temp_r3 = (int)::operator new(0x440);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &door_cave03_resource_descriptor, 0, 0, 0));
        }
        (*(s32 *)&TODoorCave03__model_resource) = var_r0;
        return;
    }
    temp_r3_2 = (int)::operator new(0x440);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = (long) (load_resource_from_descriptor((void *) temp_r3_2, 1, &TODoorCave03__resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TODoorCave03__model_resource) = var_r0_2;
}

void *__dt__12TODoorCave03Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TODoorCave03;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804B0BB8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80162848_lbl_804B1548_size[sizeof(RecoveredGlobal_80162848_lbl_804B1548) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80162848___vt__12TODoorCave03_size[sizeof(RecoveredGlobal_80162848___vt__12TODoorCave03) == 0x54 ? 1 : -1];
u8 *TODoorCave03__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__13TUnk_804B0BB8FP7TObject((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80162848___vt__12TODoorCave03 *)&__vt__12TODoorCave03).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TODoorCave03__class_name;
    ((TODoorCave03 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorCave03__model_resource) + 0x42C)) + 8);
    ((TODoorCave03 *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorCave03__model_resource) + 0x42C)) + 0xC);
    init_collision_body_parts(arg0, &lbl_804B1548.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TODoorCave03 *)(arg0))->init_door_switch_binding();
    *(f32 *)((s8 *)arg0 + 0xD4) = (f32) TODoorCave03__data_805DB4D4;
    *(f32 *)((s8 *)arg0 + 0xD8) = (f32) TODoorCave03__data_805DB4D4;
    ((TODoorCave03 *)arg0)->m_dc = (f32) TODoorCave03__data_805DB4D4;
    *(f32 *)((s8 *)arg0 + 0xE0) = (f32) TODoorCave03__data_805DB4D4;
    return arg0;
}

}
