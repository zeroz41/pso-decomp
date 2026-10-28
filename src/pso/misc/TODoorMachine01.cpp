#include "pso/system/ChunkMaterialState.h"
#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TODoorMachine01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

extern char lbl_80440ED0[];
extern char lbl_80440EE4[];
extern char lbl_80440F10[];
extern const char *bm_fs_obj_ki_doa_a_model_names[2];
extern const char *bm_fs_obj_ki_doa_a_motion_names[2];
extern BmlResourceDescriptor todoormachine01_resource_descriptor;

struct RecoveredGlobal_80163158_lbl_804B1608 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80163158___vt__15TODoorMachine01 {
    s32 value;
    u8 remaining[0x50];
};

typedef struct Door_80162A70 {
    u8 pad0[0xC8];
    s32 fC8;
    s32 fCC;
    u32 fD0;
    s32 fD4;
    s32 fD8;
} Door_80162A70;

struct Node_80162D7C {
    u8 pad0[4];
    s32 f4;
    f32 x;
    f32 y;
    f32 z;
    u8 pad14[0x2C - 0x14];
    Node_80162D7C *child;
    Node_80162D7C *next;
};

struct Model_80162D7C { u8 pad[0x2C]; Node_80162D7C *root; };

struct VBase_80162D7C { char pad[0x18]; };

struct VObj_80162D7C : VBase_80162D7C {
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

struct Door_80162D7C : VObj_80162D7C {
    u8 pad1C[0x34 - 0x1C];
    Model_80162D7C *model;
    u8 pad38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xAC - 0x64];
    s32 fAC;
    f32 fB0;
    u8 padB4[0xBC - 0xB4];
    s32 fBC;
    f32 fC0;
    f32 fC4;
    u8 padC8[0xD0 - 0xC8];
    u32 fD0;
};

extern "C" {
s32 is_any_player_within_radius_xz(f32);
s32 play_sound_effect(s32, void *, s32, s32);
extern const f32 lbl_805DB4F4;
extern const f32 lbl_805DB4F8;
extern const f32 lbl_805DB4FC;
extern const f32 lbl_805DB500;
s32 init_collision_body_parts(void *, void *, int);
void *init_door_base(void *a0);
extern RecoveredGlobal_80163158_lbl_804B1608 TODoorMachine01__collision_body_parts;
extern s32 __vt__15TODoorMachine01[];
extern s32 TODoorMachine01__class_name;
extern u32 TODoorMachine01__model_resource;
extern const f32 lbl_805DB508;
u8 *TODoorMachine01__ct(TODoorMachine01 *arg0, s32 arg1, s32 arg2);
u8 is_current_floor_switch_set(u16);
int rotate_matrix_y(int, int);
int push_matrix();
s32 pop_matrix(void);
int post_translate_matrix(void *);
void draw_ginja_model(s32 model);
int draw_ginja_model_with_motion(void *, int, f32);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
extern s32 *TODoorMachine01__global_param_id_array;
extern const f32 lbl_805DB504;
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
u32 load_resource_from_descriptor(void *, int, void *, int, int, int);
void *alloc__23TAdSinglePlyChrSelectGCFv(s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern u8 lbl_80440F38[];
extern u8 lbl_80440F50[];
extern u8 bm_fs_obj_ki_doa_resource_descriptor[];
extern s32 enable_v2_features;
void *__dt__15TODoorMachine01Fv(void *arg0, s16 arg1);
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);

void TODoorMachine01::vfunc_20() {  }

extern const f32 lbl_805DB4F0;

void TODoorMachine01::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if (!(this->m_d0 & 1) || (is_any_player_within_radius_xz(lbl_805DB4F0) != 1)) {
        this->m_ac = 3;
        ((TUnk_804AF8A0 *)arg0)->clear_player_status_flag(0, 8);
        play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
    }
}

extern void *tl_05;

void TODoorMachine01::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if ((this->m_d0 & 1) && (is_any_player_within_radius_xz(lbl_805DB4F4) == 1)) {
        this->m_ac = 1;
        ((TUnk_804AF8A0 *)arg0)->set_indexed_flags(0, 8);
        play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
    }
    if (this->m_d0 & 0x100000) {
        this->m_e0 = (f32) (this->m_e0 + lbl_805DB4F8);
        if (lbl_805DB4FC <= this->m_e0) {
            this->m_d0 = (s32) (this->m_d0 & 0xFFEFFFFF);
        }
    } else {
        this->m_e0 = (f32) (this->m_e0 - lbl_805DB4F8);
        if (this->m_e0 <= lbl_805DB500) {
            this->m_d0 = (s32) (this->m_d0 | 0x100000);
        }
    }
}

void TODoorMachine01::update_door_switch_state() {
    Door_80162A70 *self = (Door_80162A70 *)this;
    s32 i;
    s32 j;
    s32 k;
    switch (self->fCC) {
    case 1:
        ((TUnk_804B0BB8 *)self)->play_door_sound();
        self->fD0 |= 0xF0001;
        self->fD4 = 4;
        break;
    case 2:
        self->fD0 &= ~0xF0000;
        if (self->fD8 == 1) {
            if (is_current_floor_switch_set(self->fC8) == 1) {
                self->fD4 = 4;
                self->fD0 |= 0xF0000;
            } else {
                self->fD4 = 0;
            }
        } else {
            self->fD4 = 4 - self->fD8;
            for (i = 0; i < self->fD8; i++) {
                if (is_current_floor_switch_set(self->fC8 + i) == 1) {
                    self->fD4++;
                }
            }
            for (j = 0; j < self->fD4; j++) {
                self->fD0 |= 1 << (j + 16);
            }
        }
        if (self->fD4 == 4) {
            ((TUnk_804B0BB8 *)self)->play_door_sound();
            self->fD0 |= 1;
        } else {
            self->fD0 &= ~1;
        }
        break;
    case 3:
        if (self->fD8 == 1) {
            if (is_current_floor_switch_set(self->fC8) == 1) {
                self->fD4 = 4;
                self->fD0 |= 0xF0000;
            } else {
                self->fD4 = 0;
            }
        } else {
            self->fD4 = 4 - self->fD8;
            for (k = 0; k < self->fD8; k++) {
                if (is_current_floor_switch_set(self->fC8 + k) == 1) {
                    self->fD4++;
                    self->fD0 |= 1 << (k + 16);
                }
            }
        }
        if (self->fD4 == 4) {
            ((TUnk_804B0BB8 *)self)->play_door_sound();
            self->fD0 |= 1;
        }
        break;
    default:
        self->fD0 &= ~0xF0001;
        break;
    }
}

void TODoorMachine01::draw_part_models(u8 *arg1, s32 arg2) {
    s32 arg0 = (s32)this;
    u8 *p = arg1;
    s32 temp_r4;
    if (arg2 != 1) {
        temp_r4 = model_render_flags;
        saved_model_render_flags = temp_r4;
        model_render_flags = temp_r4 | 0x10;
        ((void (*)(void *, s32))set_constant_material)((void *)(arg0 + 0xDC), temp_r4);
    }
    TParticleCtrl::begin_effect_render();
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)p + 8)), (f32) (*(f32 *)((s8 *)p + 0xC)), (f32) (*(f32 *)((s8 *)p + 0x10)));
    draw_ginja_model((*(s32 *)((s8 *)p + 4)));
    p = *(u8 **)((s8 *)p + 0x2C);
    push_matrix();
    translate_matrix(0, (f32) (*(f32 *)((s8 *)p + 8)), (f32) (*(f32 *)((s8 *)p + 0xC)), (f32) (*(f32 *)((s8 *)p + 0x10)));
    draw_ginja_model((*(s32 *)((s8 *)p + 4)));
    pop_matrix();
    pop_matrix();
    TParticleCtrl::end_effect_render();
    if (arg2 != 1) {
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
    }
}

void TODoorMachine01::render() {
    Door_80162D7C *self = (Door_80162D7C *)this;
    u32 bit;
    Node_80162D7C *n;
    u32 fl;
    if (self->m8(self->fC0, self->fC4) != 0 && ((TUnk_804AFBF8 *)self)->is_in_view_depth(lbl_805DB504) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)self + 0x38);
        rotate_matrix_y(0, self->f60);
        if (self->fAC == 0) {
            bit = self->fD0;
            n = self->model->root;
            fl = (bit >> 16) & 1;
            TObjFish::set_global_param(TODoorMachine01__global_param_id_array[fl]);
            push_matrix();
            translate_matrix(0, n->x, n->y, n->z);
            draw_ginja_model(n->f4);
            draw_part_models((u8 *)n->child, (s32)fl);
            pop_matrix();
            n = self->model->root->next;
            fl = (self->fD0 >> 17) & 1;
            TObjFish::set_global_param(TODoorMachine01__global_param_id_array[fl]);
            push_matrix();
            translate_matrix(0, n->x, n->y, n->z);
            draw_ginja_model(n->f4);
            n = n->child;
            draw_part_models((u8 *)n, (s32)fl);
            n = n->next;
            fl = (self->fD0 >> 18) & 1;
            TObjFish::set_global_param(TODoorMachine01__global_param_id_array[fl]);
            draw_part_models((u8 *)n, (s32)fl);
            pop_matrix();
            n = self->model->root->next->next;
            fl = (self->fD0 >> 19) & 1;
            TObjFish::set_global_param(TODoorMachine01__global_param_id_array[fl]);
            push_matrix();
            translate_matrix(0, n->x, n->y, n->z);
            draw_ginja_model(n->f4);
            draw_part_models((u8 *)n->child, (s32)fl);
            pop_matrix();
        } else {
            TObjFish::set_global_param(TODoorMachine01__global_param_id_array[1]);
            draw_ginja_model_with_motion(self->model, self->fBC, self->fB0);
        }
        pop_matrix();
    }
}

void *TODoorMachine01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xEC);
    if (o != NULL) {
        o = TODoorMachine01__ct((TODoorMachine01 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODoorMachine01::free_resources() {
    if ((s32 *) TODoorMachine01__global_param_id_array != NULL) {
        TObjPlayer::free_if_valid(*TODoorMachine01__global_param_id_array);
        if ((s32 *) TODoorMachine01__global_param_id_array != NULL) {
            mem_free(TODoorMachine01__global_param_id_array);
            TODoorMachine01__global_param_id_array = NULL;
        }
    }
    if ((u32) TODoorMachine01__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TODoorMachine01__model_resource, 1);
        TODoorMachine01__model_resource = 0U;
    }
}

void TODoorMachine01::load_resources() {
    void *p;
    TODoorMachine01__global_param_id_array = (s32 *)mem_alloc(8);
    if (enable_v2_features == 1 && TLobby::is_online_ready() != 0) {
        p = alloc__23TAdSinglePlyChrSelectGCFv(0x440);
        if (p != NULL) {
            p = (void *)load_resource_from_descriptor(p, 1, &todoormachine01_resource_descriptor, 0, 0, 0);
        }
        TODoorMachine01__model_resource = (u32)p;
        TODoorMachine01__global_param_id_array[0] = (s32)load_gvm_texture_file((s32)lbl_80440F38);
    } else {
        p = alloc__23TAdSinglePlyChrSelectGCFv(0x440);
        if (p != NULL) {
            p = (void *)load_resource_from_descriptor(p, 1, bm_fs_obj_ki_doa_resource_descriptor, 0, 0, 0);
        }
        TODoorMachine01__model_resource = (u32)p;
        TODoorMachine01__global_param_id_array[0] = (s32)load_gvm_texture_file((s32)lbl_80440F50);
    }
    TODoorMachine01__global_param_id_array[1] = *(s32 *)(*(u8 **)(TODoorMachine01__model_resource + 0x42C) + 0xC);
}

void *__dt__15TODoorMachine01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TODoorMachine01;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B0BB8 *)arg0)->destroy_ancient_door_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80163158_lbl_804B1608_size[sizeof(RecoveredGlobal_80163158_lbl_804B1608) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80163158___vt__15TODoorMachine01_size[sizeof(RecoveredGlobal_80163158___vt__15TODoorMachine01) == 0x54 ? 1 : -1];
u8 *TODoorMachine01__ct(TODoorMachine01 *arg0, s32 arg1, s32 arg2) {
    s32 temp_r0;
    init_door_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80163158___vt__15TODoorMachine01 *)&__vt__15TODoorMachine01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TODoorMachine01__class_name;
    ((TODoorMachine01 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorMachine01__model_resource) + 0x42C)) + 8);
    arg0->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorMachine01__model_resource) + 0x42C)) + 0xC);
    *(u8 **)((s8 *)arg0 + 0xBC) = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TODoorMachine01__model_resource) + 0x430)) + 4));
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - lbl_805DB4FC);
    arg0->m_b8 = (f32) lbl_805DB508;
    init_collision_body_parts(arg0, &TODoorMachine01__collision_body_parts.value, 1);
    ((TUnk_804AF8A0 *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->reset_photon_effect();
    ((TODoorMachine01 *)(arg0))->init_door_switch_binding();
    temp_r0 = *(s32 *)((s8 *)arg0 + 0x88);
    if (temp_r0 < 0) {
        *(s32 *)((s8 *)arg0 + 0x88) = 0;
    } else if (temp_r0 > 4) {
        *(s32 *)((s8 *)arg0 + 0x88) = 4;
    }
    arg0->m_d4 = (s32) *(s32 *)((s8 *)arg0 + 0x88);
    arg0->m_d8 = (s32) (4 - arg0->m_d4);
    *(f32 *)((s8 *)arg0 + 0xDC) = (f32) lbl_805DB4FC;
    arg0->m_e0 = (f32) lbl_805DB4FC;
    *(f32 *)((s8 *)arg0 + 0xE4) = (f32) lbl_805DB4FC;
    arg0->m_e8 = (f32) lbl_805DB4FC;
    return (u8 *)arg0;
}

__declspec(section ".data") const char *bm_fs_obj_ki_doa_a_model_names[2] = { lbl_80440ED0, NULL };
__declspec(section ".data") const char *bm_fs_obj_ki_doa_a_motion_names[2] = { lbl_80440EE4, NULL };
BmlResourceDescriptor todoormachine01_resource_descriptor = { lbl_80440F10, bm_fs_obj_ki_doa_a_model_names, bm_fs_obj_ki_doa_a_motion_names, 1, 1 };
}
