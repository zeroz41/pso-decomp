#include "types.h"
#include "pso/item/TObjContainerJungEx_8018D900.h"
#include "pso/unk/text_80158360.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjDoaEx01.h"
#include "pso/item/TObjContainerJungEx.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjDoaEx01_8018DFFC.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TODoorAncient01.h"

struct RecoveredGlobal_8018D9B0_lbl_804B7158 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8018D9B0_lbl_804B7158_size[sizeof(RecoveredGlobal_8018D9B0_lbl_804B7158) == 0x10 ? 1 : -1];

struct O_8018DB94 { u8 pad[0xac]; s32 state; f32 pos; f32 max; f32 speed; };

struct Obj_8018DA54 {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0xAC - 0x44];
    s32 state;
    u8 padb0[0xD0 - 0xB0];
    u32 flags;
};

struct Obj_8018DBCC {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0xAC - 0x44];
    s32 state;
    u8 padb0[0xD0 - 0xB0];
    u32 flags;
    u8 padd4[0xD8 - 0xD4];
    f32 xd8;
};

extern "C" {
u8 * TObjFish__sub_8001EDB0(void *, int);
extern u32 TObjContainerJungEx__resource_bundle;
u8 * get_bml_model(void *, int);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8018D9B0_lbl_804B7158 fe_obj_hako02_resource_descriptor;

void play_sound_effect(s32, void *, s32, s32);

void TLobby__sub_8001FE7C(void*, int);

u8 *TObjContainerJungEx__sub_8018D900(s32 arg0) {
    if ((void *) (*(u8 * *)&TObjContainerJungEx__resource_bundle) != NULL) {
        return TObjFish__sub_8001EDB0((*(u8 * *)&TObjContainerJungEx__resource_bundle), arg0);
    }
    return NULL;
}

u8 *TObjContainerJungEx::get_model(s32 arg0) {
    if ((void *) (*(u8 * *)&TObjContainerJungEx__resource_bundle) != NULL) {
        return get_bml_model((*(u8 * *)&TObjContainerJungEx__resource_bundle), arg0);
    }
    return NULL;
}

void TObjContainerJungEx::free_data() {
    if ((u32) TObjContainerJungEx__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjContainerJungEx__resource_bundle, 1);
        TObjContainerJungEx__resource_bundle = 0U;
    }
}
void TObjContainerJungEx::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 5, &fe_obj_hako02_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TObjContainerJungEx__resource_bundle) = var_r0;
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjDoaEx01::vfunc_18() {
    u8 *arg0 = (u8 *)this;
    this->m_b0 = (f32) (this->m_b0 - this->m_b8);
    if (this->m_b0 < 0.0f) {
        this->m_b0 = (f32) 0.0f;
        this->m_ac = 0;
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 8);
    }
}
#pragma pop

void TObjDoaEx01::vfunc_17() {
    Obj_8018DA54 *self = (Obj_8018DA54 *)this;
    if (self->flags & 1) {
        if (is_any_player_within_radius_xz((u8 *)self, (f32)1e+04f) == 0) {
            self->state = 3;
            switch (TOKeyMachine01::get_global_state()) {
            case 19:
            case 20:
                play_sound_effect(0x4BF0B, self->pos, 0, 0);
                break;
            case 21:
            case 22:
                play_sound_effect(0x4004AA0B, self->pos, 0, 0);
                break;
            default:
                play_sound_effect(0x4004AA0B, self->pos, 0, 0);
                break;
            }
        }
    } else {
        self->state = 3;
        switch (TOKeyMachine01::get_global_state()) {
        case 19:
        case 20:
            play_sound_effect(0x4BF0B, self->pos, 0, 0);
            break;
        case 21:
        case 22:
            play_sound_effect(0x4004AA0B, self->pos, 0, 0);
            break;
        default:
            play_sound_effect(0x4004AA0B, self->pos, 0, 0);
            break;
        }
    }
}

void TObjDoaEx01::vfunc_16() {
    O_8018DB94 *self = (O_8018DB94 *)this;
    self->pos += self->speed;
    if (self->pos > self->max - 1.0f) {
        self->pos = self->max - 1.0f;
        self->state = 2;
    }
}
void TObjDoaEx01::play_proximity_sound() {
    Obj_8018DBCC *self = (Obj_8018DBCC *)this;
    if (self->flags & 1) {
        if (is_any_player_within_radius_xz((u8 *)self, (f32)4.9e+03f) == 1) {
            self->state = 1;
            ((TUnk_804AF8A0 *)self)->set_indexed_flags(0, 8);
            switch (TOKeyMachine01::get_global_state()) {
            case 19:
            case 20:
                play_sound_effect(0x4BF0B, self->pos, 0, 0);
                break;
            case 21:
            case 22:
                play_sound_effect(0x4004AA0B, self->pos, 0, 0);
                break;
            default:
                play_sound_effect(0x4004AA0B, self->pos, 0, 0);
                break;
            }
        }
    } else if (self->flags & 0x100000) {
        self->xd8 += 0.1f;
        if (1.0f <= self->xd8) {
            self->flags &= ~0x100000;
        }
    } else {
        self->xd8 -= 0.1f;
        if (self->xd8 <= 0.0f) {
            self->flags |= 0x100000;
        }
    }
}

}

struct NjObj_8018DD0C {
    u32 evalflags;
    u32 model;
    f32 pos[3];
    s32 ang[3];
    f32 scl[3];
    NjObj_8018DD0C *child;
    NjObj_8018DD0C *sibling;
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

extern "C" {
s32 rotate_matrix_by_node_angles(void *, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern u8 *TObjDoaEx01__alpha_model_node;
extern u8 *TObjDoaEx01__alpha_model_sibling;
extern s32 model_render_flags;
s32 get_bml_motion(s32, s32);

s32 rotate_matrix_y(s32, s32);
s32 set_global_param__8TObjFishFl();
s32 draw_ginja_model_with_motion(s32, s32, f32);
extern s32 TObjDoaEx01__resource_bundle;

struct TObjDoaEx01_base { char pad[0x18]; };
struct TObjDoaEx01_VObj : TObjDoaEx01_base {
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

s32 TObjDoaEx01::draw_object_tree(s32 arg1) {
    NjObj_8018DD0C *obj = (NjObj_8018DD0C *)arg1;
    u32 flags = obj->evalflags;
    push_matrix();
    if (!(flags & 1)) {
        post_translate_matrix(obj->pos);
    }
    if (!(flags & 2)) {
        rotate_matrix_by_node_angles(obj->ang, flags & 0x20);
    }
    if (!(flags & 4)) {
        scale_current_matrix(obj->scl);
    }
    if (!(flags & 8) && obj->model != 0) {
        if ((u8 *)obj == TObjDoaEx01__alpha_model_node || (u8 *)obj == TObjDoaEx01__alpha_model_sibling) {
            TParticleCtrl::begin_effect_render();
            saved_model_render_flags = model_render_flags;
            model_render_flags = model_render_flags | 0x10;
            set_constant_material((const NJS_ARGB *)(((u8 *)this + 0xD4)));
            draw_ginja_model(obj->model);
            set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
            model_render_flags = saved_model_render_flags;
            TParticleCtrl::end_effect_render();
        } else {
            draw_ginja_model(obj->model);
        }
    }
    if (obj->child != 0) {
        draw_object_tree((s32)obj->child);
    }
    pop_matrix();
    if (obj->sibling != 0) {
        draw_object_tree((s32)obj->sibling);
    }
}

void TObjDoaEx01::try_open() {
    s32 bml_model;

    bml_model = (s32)get_bml_model((void *)TObjDoaEx01__resource_bundle, 0);
    if (((TObjDoaEx01_VObj*)((u8 *)this))->m8(4e+02f, 2e+01f) != 0) {
        ((TObjDoorJung *)(*(s32 *)((s8 *)TObjDoaEx01__alpha_model_node + 4)))->free_children((void *)1);
        ((TObjDoorJung *)(*(s32 *)((s8 *)TObjDoaEx01__alpha_model_sibling + 4)))->free_children((void *)1);
        TObjFish__sub_8001EDB0((void *)TObjDoaEx01__resource_bundle, 0);
        set_global_param__8TObjFishFl();
        push_matrix();
        post_translate_matrix(((u8 *)this) + 0x38);
        rotate_matrix_y(0, this->rotation_y);
        this->draw_object_tree(bml_model);
        pop_matrix();
    }
}
void TObjDoaEx01::draw_model() {
    f32 temp_f31;
    s32 temp_r31;
    s32 temp_r31_2;
    if (((VObj_18_26a62c *)(this))->m8(4e+02f, 2e+01f) != 0) {
        ((TObjDoorJung *)(*(s32 *)((s8 *)TObjDoaEx01__alpha_model_node + 4)))->free_children((void *)0);
        ((TObjDoorJung *)(*(s32 *)((s8 *)TObjDoaEx01__alpha_model_sibling + 4)))->free_children((void *)0);
        temp_r31 = (s32)get_bml_model((void *)(TObjDoaEx01__resource_bundle), 0);
        TObjFish__sub_8001EDB0((void *)(TObjDoaEx01__resource_bundle), 0);
        set_global_param__8TObjFishFl();
        push_matrix();
        post_translate_matrix((void *) (((u8 *)this) + 0x38));
        rotate_matrix_y(0, (this->rotation_y));
        temp_f31 = this->m_b0;
        if (temp_f31 > 0.0f) {
            temp_r31 = get_bml_motion((TObjDoaEx01__resource_bundle), 0);
            draw_ginja_model_with_motion((s32)get_bml_model((void *)(TObjDoaEx01__resource_bundle), 0), temp_r31, temp_f31);
        } else {
            this->draw_object_tree((temp_r31));
        }
        pop_matrix();
    }
}

}

extern "C" {

s32 try_open__11TObjDoaEx01Fv();
s32 draw_model__11TObjDoaEx01Fv();

void TObjDoaEx01::render() {
    if (this->m_d0 & 1) {
        draw_model__11TObjDoaEx01Fv();
        return;
    }
    try_open__11TObjDoaEx01Fv();
}

}

extern char lbl_80445450[];
extern char lbl_80445464[];
extern char lbl_80445478[];
extern const char *fs_obj_ex_doa01_model_names[2];
extern const char *fs_obj_ex_doa01_motion_names[2];
extern BmlResourceDescriptor TObjDoaEx01__resource_descriptor;

struct RecoveredGlobal_8018E1E0_lbl_804B7588 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8018E1E0_lbl_804B7588_size[sizeof(RecoveredGlobal_8018E1E0_lbl_804B7588) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8018E064_lbl_804B7598 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8018E064___vt__11TObjDoaEx01 {
    s32 value;
    u8 remaining[0x50];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 init_collision_body_parts(void *, void *, int);
void *init_door_base(void *a0);
extern RecoveredGlobal_8018E064_lbl_804B7598 TObjDoaEx01__collision_body_parts;
extern s32 __vt__11TObjDoaEx01[];
extern s32 TObjDoaEx01__name;

void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void *__dt__11TObjDoaEx01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__11TObjDoaEx01;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B0BB8 *)arg0)->destroy_ancient_door_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_05;

typedef char RecoveredGlobal_8018E064_lbl_804B7598_size[sizeof(RecoveredGlobal_8018E064_lbl_804B7598) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8018E064___vt__11TObjDoaEx01_size[sizeof(RecoveredGlobal_8018E064___vt__11TObjDoaEx01) == 0x54 ? 1 : -1];
u8 *TObjDoaEx01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    init_door_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018E064___vt__11TObjDoaEx01 *)&__vt__11TObjDoaEx01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TObjDoaEx01__name;
    ((TObjDoaEx01 *)(arg0))->apply_object_set_data((void *)arg2);
    ((TObjDoaEx01 *)(arg0))->init_door_switch_binding();
    init_collision_body_parts(arg0, &TObjDoaEx01__collision_body_parts.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TObjDoaEx01 *)arg0)->m_b0 = (f32) 0.0f;
    ((TObjDoaEx01 *)arg0)->m_b8 = (f32) 0.5f;
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) *(u32 *)((s8 *)(get_bml_motion((*(s32 *)&TObjDoaEx01__resource_bundle), 0)) + 4);
    ((TObjDoaEx01 *)arg0)->m_d0 = 0x100001;
    *(f32 *)((s8 *)arg0 + 0xD4) = (f32) 1.0f;
    ((TObjDoaEx01 *)arg0)->m_d8 = (f32) 1.0f;
    *(f32 *)((s8 *)arg0 + 0xDC) = (f32) 1.0f;
    ((TObjDoaEx01 *)arg0)->m_e0 = (f32) 1.0f;
    return arg0;
}

void *TObjDoaEx01__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE4);
    if (o != NULL) {
        o = TObjDoaEx01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TObjDoaEx01::free_resource() {
    if ((u32) TObjDoaEx01__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TObjDoaEx01__resource_bundle, 1);
        TObjDoaEx01__resource_bundle = 0U;
    }
}
void TObjDoaEx01::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    u8 *temp_r3_2;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TObjDoaEx01__resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TObjDoaEx01__resource_bundle) = (unsigned char *) ((void *) var_r0);
    temp_r3_2 = (u8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(get_bml_model((void *) var_r0, 0)) + 0x2C)) + 0x30)) + 0x2C)) + 0x2C));
    TObjDoaEx01__alpha_model_node = temp_r3_2;
    TObjDoaEx01__alpha_model_sibling = (u8 *)*(s32 *)((s8 *)temp_r3_2 + 0x30);
}

__declspec(section ".data") const char *fs_obj_ex_doa01_model_names[2] = { lbl_80445450, NULL };
__declspec(section ".data") const char *fs_obj_ex_doa01_motion_names[2] = { lbl_80445464, NULL };
BmlResourceDescriptor TObjDoaEx01__resource_descriptor = { lbl_80445478, fs_obj_ex_doa01_model_names, fs_obj_ex_doa01_motion_names, 1, 1 };
}
