#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/TMainTask.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MaterialAlphaCompare.h"
#include "pso/unk/text_80141550.h"
#include "pso/unk/text_80193524.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/depth_buffer.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/misc/CameraDistanceFade.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TLazerFenceSw.h"
#include "pso/object/TObjLazerFence4.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/misc/TOKey.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

extern "C" { void rotate_matrix_y(int, void *); s32 pop_matrix(void); void draw_ginja_object(void *); s32 get_bml_motion(s32, s32); s32 get_bml_model(s32, s32); }
extern s32 model_render_flags;

extern char lbl_80445C00[];
extern char lbl_80445C18[];
extern char lbl_80445C34[];
extern char lbl_80445C54[];
extern char lbl_80445C6C[];
extern char lbl_80445C88[];
extern const char *fe_obj_switch_laz_model_names[4];
extern const char *fe_obj_switch_laz_motion_names[3];
extern BmlResourceDescriptor laser_fence_switch_resource_descriptor;

struct RecoveredGlobal_80193A84_lbl_8050DCF0 {
    s32 value;
    u8 remaining[0x14];
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

struct VBase_14_aa9368 { char pad[0x14]; };

struct VObj_14_aa9368 : VBase_14_aa9368 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
};

struct RecoveredGlobal_80193B4C_lbl_8050DCF0 {
    u8 * value;
    u8 remaining[0x14];
};

struct Sw_80193978 { u8 pad0[0x8C]; s32 f8C; u8 pad90[0x58]; u16 fE8; };

struct Node_80193CA4 {
    u8 pad0[4];
    u32 f4;
    u8 pad8[0x30 - 0x8];
    Node_80193CA4 *next;
};

extern "C" {

void debug_draw_key_id__5TOKeyFv();
void debug_printf_at(int, void *, ...);
extern u16 lbl_80445CB8[];
extern u8 lbl_80445CD8[];
void TLazerFenceSw__vt24(Sw_80193978 *arg0);
s32 init_collision_body_parts(void *, void *, int);
s32 init_key__5TOKeyFPv(void *, void *);
void *__ct__5TOKeyFP7TObject(TOKey *arg0);
extern u8 lazer_fence_sw_collision_body_part[];
extern s32 __vt__13TLazerFenceSw[];
extern s32 lbl_805D33B0;

void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
u8 *load_gvm_texture_file(s32 arg0);

extern void *lazer_fence_switch_bml_resource;
extern s32 TLazerFenceSw__texture_list;
extern u8 *lazer_fence_switch_scroll_node;
extern s32 game_difficulty_selection;
extern u8 fe_obj_switch_laz_j_resource_descriptor[];
extern u8 lbl_80445CF0[];
extern u8 lbl_80445D08[];
extern u8 lbl_80445D20[];
s32 TLobby__sub_8001FE7C(void *, s32);
void free_collision_body_parts(void *);
void *__dt__5TOKeyFv(void *arg0, s16 arg1);
void *__ct__18CameraDistanceFadeFv(void *self);

__declspec(section ".data") u32 lazer_fence_sw_ginja_model_table[2];
__declspec(section ".data") u32 lazer_fence_beam_motions[2];
__declspec(section ".data") u32 lazer_fence_beam_node_table[3];
#define lazer_fence_beam_motions (*(RecoveredGlobal_80193A84_lbl_8050DCF0 *)lazer_fence_beam_motions)

#pragma push
#pragma opt_common_subs off
struct Sw_801936E0 {
    u8 pad0[0x38];
    u8 pos[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xB0 - 0x64];
    f32 fB0;
    u8 padB4[0xD4 - 0xB4];
    s32 fD4;
    u8 padD8[0xE8 - 0xD8];
    u16 fE8;
    u8 padEA[0xEC - 0xEA];
    f32 fEC;
    u8 padF0[0x110 - 0xF0];
    f32 f110;
    u32 f114;
};
void scroll_ginja_mesh_uvs(u32, s32, s32, u16, s32);
void PPCSync(void);
void push_matrix(void);
void post_translate_matrix(void *);

s32 draw_ginja_model_with_motion(s32, s32, f32);
extern u32 actor_frame_tick;

void TLazerFenceSw::draw_laser_beam() {
    Sw_801936E0 *self = (Sw_801936E0 *)this;
    s32 i;

    for (i = 0; i < 3; i++) {
        ((TObjDoorJung *)(lazer_fence_beam_node_table[i]))->free_children((void *)self->fE8);
    }
    TObjFish::set_global_param(TLazerFenceSw__texture_list);
    if (actor_frame_tick != self->f114 && self->f110 >= 1.0f) {
        self->f114 = actor_frame_tick;
        scroll_ginja_mesh_uvs(*(u32 *)(lazer_fence_switch_scroll_node + 4), 0, (s32)self->f110, 5, 1);
        PPCSync();
        self->f110 = self->f110 - (f32)(s32)self->f110;
    }
    switch (self->fD4) {
    case 0:
        push_matrix();
        post_translate_matrix(self->pos);
        rotate_matrix_y(0, (void *)self->f60);
        draw_ginja_object((void *)lazer_fence_sw_ginja_model_table[1]);
        TParticleCtrl::begin_effect_render();
        model_render_flags |= 0x01000000;
        draw_ginja_model_with_motion(lazer_fence_sw_ginja_model_table[0], ((u32 *)&lazer_fence_beam_motions)[0], self->fB0);
        model_render_flags &= ~0x01000000;
        TParticleCtrl::end_effect_render();
        pop_matrix();
        break;
    case 1:
        push_matrix();
        post_translate_matrix(self->pos);
        rotate_matrix_y(0, (void *)self->f60);
        draw_ginja_model_with_motion(lazer_fence_sw_ginja_model_table[1], ((u32 *)&lazer_fence_beam_motions)[1], self->fEC);
        TParticleCtrl::begin_effect_render();
        model_render_flags |= 0x01000000;
        draw_ginja_model_with_motion(lazer_fence_sw_ginja_model_table[0], ((u32 *)&lazer_fence_beam_motions)[0], self->fB0);
        model_render_flags &= ~0x01000000;
        TParticleCtrl::end_effect_render();
        pop_matrix();
        break;
    }
}
void TLazerFenceSw::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_18_26a62c *)(arg0))->m8(4e+02f, 2e+01f) != 0) {
        if (TMainTask::get_render_pass() != 1) {
            set_depth_buffer_settings_id(3);
            set_material_alpha_compare_reference(0x80);
            if (((CameraDistanceFade *)(arg0 + 0xF0))->update_visibility(&this->position) != 0) {
                if (((CameraDistanceFade *)(arg0 + 0xF0))->is_translucent() != 0) {
                    ((VObj_14_aa9368 *)(arg0 + (240)))->m6();
                    draw_laser_beam();
                    ((VObj_14_aa9368 *)(arg0 + (240)))->m7();
                } else {
                    draw_laser_beam();
                }
            }
            set_material_alpha_compare_reference(0x8F);
            restore_draw_list_mask();
        }
    }
}
#pragma pop

__declspec(section ".rodata") u8 lbl_80445CD8[16] = "<- SELECT COLOR";
void TLazerFenceSw__vt24(Sw_80193978 *arg0) {
    debug_draw_key_id__5TOKeyFv();
    if (arg0->f8C < 0) {
        arg0->f8C = 0;
    }
    arg0->fE8 = lbl_80445CB8[arg0->f8C % 4];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130022, lbl_80445CD8);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TLazerFenceSw__vt16(void *lazer_fence_sw) {
    ((TOKey *)lazer_fence_sw)->TOKey::trigger_activate_sound();
    ((TLazerFenceSw *)lazer_fence_sw)->m_b0 = 0.0f;
    *(f32 *)((s8 *)lazer_fence_sw + 0xEC) = 0.0f;
}

void TLazerFenceSw__vt17(void *arg0) {
    ((TOKey *)arg0)->TOKey::trigger_deactivate_sound();
    ((TLazerFenceSw *)arg0)->m_b0 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0xEC) = 0.0f;
}

typedef char RecoveredGlobal_80193A84_lbl_8050DCF0_size[sizeof(RecoveredGlobal_80193A84_lbl_8050DCF0) == 0x18 ? 1 : -1];
void TLazerFenceSw::update_switch_on() {
    u32 temp_r4;
    u32 temp_r4_2;
    this->m_b0 = (f32) (this->m_b0 + this->m_b8);
    temp_r4 = *(s32 *)((s8 *)(*(u8 **)((s8 *)&lazer_fence_beam_motions.value + 0)) + 4) - 1;
    if (this->m_b0 > (f32) temp_r4) {
        this->m_b0 = (f32) temp_r4;
    }
    *(f32 *)((s8 *)((u8 *)this) + 0xEC) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0xEC) + this->m_b8);
    temp_r4_2 = *(s32 *)((s8 *)(*(u8 **)((s8 *)&lazer_fence_beam_motions.value + 4)) + 4) - 1;
    if (*(f32 *)((s8 *)((u8 *)this) + 0xEC) > (f32) temp_r4_2) {
        *(f32 *)((s8 *)((u8 *)this) + 0xEC) = (f32) temp_r4_2;
    }
}

typedef char RecoveredGlobal_80193B4C_lbl_8050DCF0_size[sizeof(RecoveredGlobal_80193B4C_lbl_8050DCF0) == 0x18 ? 1 : -1];
void TLazerFenceSw::update_switch_off() {
    this->m_b0 = (f32) (this->m_b0 + this->m_b8);
    if (this->m_b0 > (f32) (u32) (*(s32 *)((s8 *)((*(RecoveredGlobal_80193B4C_lbl_8050DCF0 *)&lazer_fence_beam_motions).value) + 4) - 1)) {
        this->m_b0 = (f32) 0.0f;
    }
    this->submit_cursor_target();
}

void TLazerFenceSw::run_task() {
    u8 *arg0 = (u8 *)this;
    ((CameraDistanceFade *)(arg0 + 0xF0))->step_fade();
    ((TOKey *)arg0)->TOKey::run_task();
    *(f32 *)((s8 *)arg0 + 0x110) += 0.2f;
}

void *TLazerFenceSw::create() {
    void *o = TObject::operator new(0x118);
    if (o != NULL) {
        o = TLazerFenceSw__ct(o, tl_05, this);
    }
    return o;
}

void TLazerFenceSw__sub_80193C5C(void) {
    if (lazer_fence_switch_bml_resource != 0) {
        TLobby__sub_8001FE7C(lazer_fence_switch_bml_resource, 1);
        lazer_fence_switch_bml_resource = 0;
    }
    TObjPlayer::free_if_valid(TLazerFenceSw__texture_list);
    TLazerFenceSw__texture_list = 0;
}

#pragma push
#pragma opt_propagation off
void TLazerFenceSw::load_resources() {
    s32 area;
    void *obj;
    s32 j;
    s32 i;
    Node_80193CA4 *n;
    lazer_fence_switch_bml_resource = 0;
    area = get_current_floor_area();
    if (TContainerAncient01::is_global_state_in_table() == 1 || area == AREA_SEABED_UPPER || area == AREA_SEABED_LOWER) {
        obj = ::operator new(0x440);
        if (obj != NULL) {
            obj = load_resource_from_descriptor(obj, 5, fe_obj_switch_laz_j_resource_descriptor, 0, 0, 0);
        }
        lazer_fence_switch_bml_resource = obj;
        TLazerFenceSw__texture_list = (s32)load_gvm_texture_file((s32)lbl_80445CF0);
    } else {
        obj = ::operator new(0x440);
        if (obj != NULL) {
            obj = load_resource_from_descriptor(obj, 5, &laser_fence_switch_resource_descriptor, 0, 0, 0);
        }
        lazer_fence_switch_bml_resource = obj;
        if (game_difficulty_selection == 3) {
            TLazerFenceSw__texture_list = (s32)load_gvm_texture_file((s32)lbl_80445D08);
        } else {
            TLazerFenceSw__texture_list = (s32)load_gvm_texture_file((s32)lbl_80445D20);
        }
    }
    lazer_fence_sw_ginja_model_table[0] = (s32)get_bml_model((s32)lazer_fence_switch_bml_resource, 0);
    lazer_fence_sw_ginja_model_table[1] = (s32)get_bml_model((s32)lazer_fence_switch_bml_resource, 1);
    ((u32 *)&lazer_fence_beam_motions)[0] = get_bml_motion((s32)lazer_fence_switch_bml_resource, 0);
    ((u32 *)&lazer_fence_beam_motions)[1] = get_bml_motion((s32)lazer_fence_switch_bml_resource, 1);
    for (j = 0; j < 3; j++) {
        lazer_fence_beam_node_table[j] = 0;
    }
    i = 0;
    n = *(Node_80193CA4 **)(lazer_fence_sw_ginja_model_table[0] + 0x2C);
    if (n != NULL) {
        lazer_fence_beam_node_table[i] = n->f4;
        i++;
        n = n->next;
        while (n != NULL && i < 3) {
            lazer_fence_beam_node_table[i] = n->f4;
            i++;
            n = n->next;
        }
    }
    lazer_fence_switch_scroll_node = (u8 *)find_object_node((NJS_OBJECT *)lazer_fence_sw_ginja_model_table[1], 3);
}
#pragma pop

void *__dt__13TLazerFenceSwFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TLazerFenceSw;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((CameraDistanceFade *)((s8 *)arg0 + 0xF0))->CameraDistanceFade::~CameraDistanceFade();
        __dt__5TOKeyFv(arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma opt_common_subs off
void *TLazerFenceSw__ct(void *arg0, void *arg1, void *arg2) {
    __ct__5TOKeyFP7TObject((TOKey *)arg0);
    *(u8 **)((s8 *)arg0 + 0x18) = ((u8 *)&__vt__13TLazerFenceSw);
    __ct__18CameraDistanceFadeFv((u8 *)arg0 + 0xF0);
    *(s32 *)((s8 *)arg0 + 0) = lbl_805D33B0;
    init_key__5TOKeyFPv(arg0, arg2);
    if (*(s32 *)((s8 *)arg0 + 0x8C) < 0) {
        *(s32 *)((s8 *)arg0 + 0x8C) = 0;
    }
    *(u16 *)((s8 *)arg0 + 0xE8) = lbl_80445CB8[*(s32 *)((s8 *)arg0 + 0x8C) % 4];
    *(f32 *)((s8 *)arg0 + 0xB8) = 2.0f;
    *(f32 *)((s8 *)arg0 + 0xEC) = 0.0f;
    init_collision_body_parts(arg0, lazer_fence_sw_collision_body_part, 1);
    *(s32 *)((s8 *)arg0 + 0x30) |= 0x40000000;
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((CameraDistanceFade *)((u8 *)arg0 + 0xF0))->reset();
    TLazerFenceSw__sub_8018A554((u8 *)arg0 + 0xF0, 2.9e+02f);
    *(f32 *)((s8 *)arg0 + 0x110) = 0.0f;
    *(s32 *)((s8 *)arg0 + 0x114) = 0;
    return arg0;
}
#pragma pop

__declspec(section ".data") const char *fe_obj_switch_laz_model_names[4] = { lbl_80445C00, lbl_80445C18, lbl_80445C34, NULL };
__declspec(section ".data") const char *fe_obj_switch_laz_motion_names[3] = { lbl_80445C54, lbl_80445C6C, NULL };
BmlResourceDescriptor laser_fence_switch_resource_descriptor = { lbl_80445C88, fe_obj_switch_laz_model_names, fe_obj_switch_laz_motion_names, 3, 2 };
}
