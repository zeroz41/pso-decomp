#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TODoorBase.h"
#include "pso/misc/TODoorVS2Door01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TODoorAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_80176308_lbl_80442A80 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80176308_lbl_804B4278 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80164340_lbl_804B17F0 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_80164340___vt__15TODoorVS2Door01 {
    s32 value;
    u8 remaining[0x50];
};

struct Node_80163FB4 {
    u8 pad0[4];
    s32 f4;
    u8 mtx[0x2C - 8];
    Node_80163FB4 *child;
    Node_80163FB4 *next;
};

struct VBase_80163FB4 { char pad[0x18]; };

struct VObj_80163FB4 : VBase_80163FB4 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Door_80163FB4 : VObj_80163FB4 {
    u8 pad1c[0x34 - 0x1C];
    Node_80163FB4 *model;
    u8 mtx[0x60 - 0x38];
    s32 f60;
    u8 pad64[0xC0 - 0x64];
    f32 fC0;
    f32 fC4;
    u8 padC8[0xD0 - 0xC8];
    s32 fD0;
    f32 fD4;
};

extern "C" {
u8 *load_resource_from_descriptor(void *, s32, s32 *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern RecoveredGlobal_80176308_lbl_80442A80 lbl_804410E0;
extern RecoveredGlobal_80176308_lbl_804B4278 fs_obj_o_vs2door01l_resource_descriptor;
extern u32 door_vs2_shared_bml_archive;
extern s32 *TODoorVS2Door01__texture_lists;
s32 init_collision_body_parts(void *, void *, int);
void *__ct__10TODoorBaseFP7TObject(void *a0);
extern RecoveredGlobal_80164340_lbl_804B17F0 todoor_vs2_door01_collision_parts;
extern s32 __vt__15TODoorVS2Door01[];
extern s32 TODoorVS2Door01__class_name;
u8 *TODoorVS2Door01__ct(u8 *arg0, s32 arg1, s32 arg2);
u8 is_open__15TODoorVS2Door01Fv(void *arg0);
s32 rotate_matrix_y(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
void *__dt__15TODoorVS2Door01Fv(void *arg0, s16 arg1);
s32 play_sound_effect(s32, void *, s32, s32);
void TLobby__sub_8001FE7C(void*, int);
s32 is_any_player_within_radius_xz__13TObjMapObjectFf(f32);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);
s32 is_in_view_depth__13TObjMapObjectFf();
void mem_free(void *p);

void TODoorVS2Door01::update_demo() {  }

#pragma push
#pragma opt_common_subs off
void TODoorVS2Door01::update_closing() {
    *(f32 *)&this->unk_D4 = (f32) (*(f32 *)&this->unk_D4 - this->m_b8);
    if (*(f32 *)&this->unk_D4 <= (0.0f)) {
        *(f32 *)&this->unk_D4 = (f32) (0.0f);
        this->m_ac = 0;
    }
}
#pragma pop

void TODoorVS2Door01::update_open() {
    u8 *arg0 = (u8 *)this;
    if (!(this->door_flags & 1) || (is_any_player_within_radius_xz__13TObjMapObjectFf((1e+04f)) == 0)) {
        this->m_ac = 3;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
        play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
    }
}

void TODoorVS2Door01::update_opening() {
    f32 lim = 19.0f;
    *(f32 *)&this->unk_D4 = *(f32 *)&this->unk_D4 + this->m_b8;
    if (lim <= *(f32 *)&this->unk_D4) {
        *(f32 *)&this->unk_D4 = lim;
        this->m_ac = 2;
    }
}

void TODoorVS2Door01::update_closed() {
    u8 *arg0 = (u8 *)this;
    if ((this->door_flags & 1) && (is_any_player_within_radius_xz__13TObjMapObjectFf((4.9e+03f)) != 0)) {
        this->m_ac = 1;
        ((TObjCollidable *)arg0)->set_indexed_flags(0, 8);
        play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
    }
}

u8 TODoorVS2Door01::is_open() {
    int var_r31;

    var_r31 = 0;
    if ((is_in_view_depth__13TObjMapObjectFf() != 0) || ((s32) this->m_ac != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

extern void *tl_05;

void TODoorVS2Door01::render() {
    Door_80163FB4 *self = (Door_80163FB4 *)this;
    Node_80163FB4 *n;
    f32 v;
    if (self->m8(self->fC0, self->fC4) != 0 && ((s32 (*)(void *, f32))is_open__15TODoorVS2Door01Fv)(self, 30.0f) != 0) {
        push_matrix();
        post_translate_matrix(self->mtx);
        rotate_matrix_y(0, self->f60);
        TObjFish::set_global_param(TODoorVS2Door01__texture_lists[self->fD0 & 1]);
        n = self->model;
        post_translate_matrix(n->mtx);
        push_matrix();
        v = -self->fD4;
        translate_matrix(0, v, (0.0f), (0.0f));
        draw_ginja_model(n->f4);
        pop_matrix();
        n = n->child;
        push_matrix();
        post_translate_matrix(n->mtx);
        push_matrix();
        v = self->fD4;
        translate_matrix(0, v, (0.0f), (0.0f));
        draw_ginja_model(n->f4);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        n = n->child;
        push_matrix();
        post_translate_matrix(n->mtx);
        push_matrix();
        v = self->fD4;
        translate_matrix(0, v, (0.0f), (0.0f));
        draw_ginja_model(n->f4);
        pop_matrix();
        pop_matrix();
        n = n->next;
        push_matrix();
        post_translate_matrix(n->mtx);
        push_matrix();
        v = self->fD4;
        translate_matrix(0, v, (0.0f), (0.0f));
        draw_ginja_model(n->f4);
        pop_matrix();
        pop_matrix();
        n = self->model->child->next;
        push_matrix();
        post_translate_matrix(n->mtx);
        push_matrix();
        v = -self->fD4;
        translate_matrix(0, v, 0.0f, 0.0f);
        draw_ginja_model(n->f4);
        pop_matrix();
        pop_matrix();
        n = n->next;
        push_matrix();
        post_translate_matrix(n->mtx);
        push_matrix();
        v = -self->fD4;
        translate_matrix(0, v, 0.0f, 0.0f);
        draw_ginja_model(n->f4);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TODoorVS2Door01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TODoorVS2Door01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TODoorVS2Door01::free_resources() {
    if ((s32 *) TODoorVS2Door01__texture_lists != NULL) {
        TObjPlayer::free_if_valid(*TODoorVS2Door01__texture_lists);
        if ((s32 *) TODoorVS2Door01__texture_lists != NULL) {
            mem_free(TODoorVS2Door01__texture_lists);
            TODoorVS2Door01__texture_lists = NULL;
        }
    }
    if ((u32) door_vs2_shared_bml_archive != 0U) {
        TLobby__sub_8001FE7C((void*)door_vs2_shared_bml_archive, 1);
        door_vs2_shared_bml_archive = 0U;
    }
}

typedef char RecoveredGlobal_80176308_lbl_80442A80_size[sizeof(RecoveredGlobal_80176308_lbl_80442A80) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80176308_lbl_804B4278_size[sizeof(RecoveredGlobal_80176308_lbl_804B4278) == 0x10 ? 1 : -1];
void TODoorVS2Door01::load_resources() {
    s32 *temp_r3_2;
    u8 *temp_r3;
    u8 *var_r0;
    temp_r3 = (u8 *)((int)::operator new(0x440));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(load_resource_from_descriptor(temp_r3, 1, &fs_obj_o_vs2door01l_resource_descriptor.value, 0, 0, 0));
    }
    (*(u8 * *)&door_vs2_shared_bml_archive) = var_r0;
    temp_r3_2 = (s32 *)(mem_alloc(8));
    TODoorVS2Door01__texture_lists = temp_r3_2;
    *(s32 *)((s8 *)temp_r3_2 + 4) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_vs2_shared_bml_archive) + 0x42C)) + 0xC);
    *TODoorVS2Door01__texture_lists = (s32)load_gvm_texture_file((s32)&lbl_804410E0.value);
}

void *__dt__15TODoorVS2Door01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__15TODoorVS2Door01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__10TODoorBaseFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80164340_lbl_804B17F0_size[sizeof(RecoveredGlobal_80164340_lbl_804B17F0) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_80164340___vt__15TODoorVS2Door01_size[sizeof(RecoveredGlobal_80164340___vt__15TODoorVS2Door01) == 0x54 ? 1 : -1];
u8 *TODoorVS2Door01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__10TODoorBaseFP7TObject((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_80164340___vt__15TODoorVS2Door01 *)&__vt__15TODoorVS2Door01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TODoorVS2Door01__class_name;
    ((TODoorVS2Door01 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&door_vs2_shared_bml_archive) + 0x42C)) + 8);
    ((TODoorVS2Door01 *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 * *)&TODoorVS2Door01__texture_lists) + 4);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) 30.0f;
    ((TODoorVS2Door01 *)arg0)->m_b8 = (f32) ((19.0f) / *(f32 *)((s8 *)arg0 + 0xB4));
    *(f32 *)((s8 *)arg0 + 0xD4) = (f32) (0.0f);
    init_collision_body_parts(arg0, &todoor_vs2_door01_collision_parts.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TODoorVS2Door01 *)(arg0))->init_door_switch_binding();
    return arg0;
}

}
