#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOMonitorMachine01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"

typedef struct Mon_8017205C {
    u8 pad0[0x84];
    s32 f84;
    u8 pad88[0xAC - 0x88];
    s32 fAC;
    u8 padB0[0xCC - 0xB0];
    f32 fCC;
    f32 fD0;
    f32 fD4;
} Mon_8017205C;

struct Node_80172220 { u8 pad0[4]; s32 f4; u8 pad8[0x30 - 8]; Node_80172220 *next; };

struct NodeHead_80172220 { u8 pad[0x2C]; Node_80172220 *root; };

struct VBase_80172220 { char pad[0x18]; };

struct VObj_80172220 : VBase_80172220 {
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

struct Mon_80172220 : VObj_80172220 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    NodeHead_80172220 *model;
    u8 pad38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x84 - 0x64];
    s32 f84;
    u8 pad88[0xC0 - 0x88];
    f32 fC0;
    f32 fC4;
    u8 padC8[0xCC - 0xC8];
    f32 fCC;
    f32 fD0;
};

struct Obj_80172550 {
    s32 f0;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u8 pad1c[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x30 - 0x28];
    u32 f30;
    s32 f34;
    u8 pad38[0x84 - 0x38];
    s32 f84;
    u8 pad88[0xAC - 0x88];
    s32 fAC;
    u8 padB0[0xC0 - 0xB0];
    f32 fC0;
    f32 fC4;
    u8 padC8[0xCC - 0xC8];
    f32 fCC;
    f32 fD0;
    f32 fD4;
};

extern "C" {
void TLobby__sub_8001FE7C(void *, s32);
extern s32 TOMonitorMachine01__scroll_mesh_ptrs[];
extern s32 TOMonitorMachine01__last_update_tick;
extern void *TOMonitorMachine01__shared_bml_archive;
void scroll_ginja_mesh_uvs(s32, s32, s32, s32, s32);
extern s32 actor_frame_tick;
extern const f32 lbl_805DB8F0;
extern const f32 lbl_805DB8F4;
extern const f32 lbl_805DB8FC;
extern const f32 lbl_805DB900;
extern const f32 lbl_805DB904;
extern const f32 lbl_805DB908;
int rotate_matrix_y(int, int);
int push_matrix();
int post_translate_matrix(void *);
void scale_matrix(s32, f32, f32, f32);
u32 load_resource_from_descriptor(void *, int, void *, int, int, int);
extern u8 monitor_machine01_resource_desc[];
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
s32 init_map_object_base(void *, s32);
extern s32 __vt__18TOMonitorMachine01[];
extern s32 TOMonitorMachine01__name;
extern s32 tl_05;
extern const f32 lbl_805DB90C;
extern const f32 lbl_805DB910;
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOMonitorMachine01::run_task() {
    Mon_8017205C *self = (Mon_8017205C *)this;
    if (TOMonitorMachine01__last_update_tick != actor_frame_tick) {
        TOMonitorMachine01__last_update_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(TOMonitorMachine01__scroll_mesh_ptrs[0], 1, 0, 1, 1);
        scroll_ginja_mesh_uvs(TOMonitorMachine01__scroll_mesh_ptrs[1], 1, 0, 1, 1);
    }
    switch (self->fAC) {
    default:
        self->fD4 += lbl_805DB8F0;
        if (lbl_805DB8F4 <= self->fD4) {
            self->fAC = 1;
            self->fD4 = 0.0f;
            self->f84++;
            if (self->f84 >= 4) {
                self->f84 = 0;
            }
        }
        break;
    case 1:
        self->fCC += lbl_805DB8FC;
        self->fD0 += lbl_805DB900;
        if (lbl_805DB904 <= self->fCC) {
            self->fAC = 2;
            self->fCC = lbl_805DB904;
            self->fD0 = lbl_805DB8F0;
        }
        break;
    case 2:
        self->fD4 += lbl_805DB8F0;
        if (lbl_805DB908 <= self->fD4) {
            self->fAC = 3;
            self->fD4 = 0.0f;
        }
        break;
    case 3:
        self->fCC -= lbl_805DB8FC;
        self->fD0 -= lbl_805DB900;
        if (self->fCC <= 0.0f) {
            self->fAC = 0;
            self->fD0 = 0.0f;
            self->fCC = 0.0f;
        }
        break;
    }
}

void TOMonitorMachine01::render() {
    Mon_80172220 *self = (Mon_80172220 *)this;
    Node_80172220 *n;
    if (self->m8(self->fC0, self->fC4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)self + 0x38);
        rotate_matrix_y(0, self->f60);
        TObjFish::set_global_param(self->f24);
        n = self->model->root;
        push_matrix();
        translate_matrix(0, -self->fCC, 0.0f, 0.0f);
        draw_ginja_model(n->f4);
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        n = n->next;
        if (self->f84 == 2) {
            push_matrix();
            scale_matrix(0, self->fD0, self->fD0, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        n = n->next;
        if (self->f84 == 1) {
            push_matrix();
            scale_matrix(0, self->fD0, self->fD0, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        TParticleCtrl::end_effect_render();
        n = n->next;
        push_matrix();
        translate_matrix(0, self->fCC, 0.0f, 0.0f);
        draw_ginja_model(n->f4);
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        n = n->next;
        if (self->f84 == 0) {
            push_matrix();
            scale_matrix(0, self->fD0, self->fD0, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        n = n->next;
        if (self->f84 == 3) {
            push_matrix();
            scale_matrix(0, self->fD0, self->fD0, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOMonitorMachine01::create() {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TOMonitorMachine01__ct(o, this);
    }
    return o;
}

void TOMonitorMachine01::reset_static_state() {
    s32 i;
    TOMonitorMachine01__last_update_tick = 0;
    for (i = 0; i < 2; i++) {
        TOMonitorMachine01__scroll_mesh_ptrs[i] = 0;
    }
    if (TOMonitorMachine01__shared_bml_archive != 0) {
        TLobby__sub_8001FE7C(TOMonitorMachine01__shared_bml_archive, 1);
        TOMonitorMachine01__shared_bml_archive = 0;
    }
}

void TOMonitorMachine01::load_resources() {
    void *temp_r5;
    void *p;
    p = ::operator new(0x440);
    if (p != NULL) {
        p = (void *)load_resource_from_descriptor(p, 1, monitor_machine01_resource_desc, 0, 0, 0);
    }
    TOMonitorMachine01__shared_bml_archive = p;
    temp_r5 = *(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)p + 0x42C)) + 8)) + 0x2C)) + 0x30)) + 0x30);
    TOMonitorMachine01__scroll_mesh_ptrs[1] = *(s32 *)((s8 *)temp_r5 + 4);
    TOMonitorMachine01__scroll_mesh_ptrs[0] = *(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)temp_r5 + 0x30)) + 0x30)) + 4);
    TOMonitorMachine01__last_update_tick = 0;
}

void *__dt__18TOMonitorMachine01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TOMonitorMachine01;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma opt_common_subs off
void *TOMonitorMachine01__ct(void *arg0_, void *arg1) {
#define self ((Obj_80172550 *)arg0_)
    init_map_object_base(arg0_, tl_05);
    self->vt = __vt__18TOMonitorMachine01;
    self->f0 = TOMonitorMachine01__name;
    ((TOMonitorMachine01 *)(arg0_))->apply_object_set_data((void *)((s32)arg1));
    self->f34 = get_bml_model(TOMonitorMachine01__shared_bml_archive, 0);
    self->f24 = TObjFish__sub_8001EDB0(TOMonitorMachine01__shared_bml_archive, 0);
    self->fC0 = lbl_805DB90C;
    self->fC4 = lbl_805DB910;
    self->f30 |= 0x40000000;
    self->fAC = 0;
    self->fCC = 0.0f;
    self->fD0 = 0.0f;
    self->fD4 = 0.0f;
    if (self->f84 < 0) {
        self->f84 = 0;
    } else if (self->f84 >= 4) {
        self->f84 = 3;
    }
    return arg0_;
#undef self
}
#pragma pop

}
