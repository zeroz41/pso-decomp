#include "pso/misc/TOSignCave03.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804AFBF8.h"

#include "types.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

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

struct RecoveredGlobal_80176F50_lbl_804B43A0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80176F50_lbl_804B43A0_size[sizeof(RecoveredGlobal_80176F50_lbl_804B43A0) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80176FF8___vt__12TOSignCave03 {
    s32 value;
    u8 remaining[0x34];
};

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
f32 post_translate_matrix(void *);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80176F50_lbl_804B43A0 bm_fs_obj_dokanban03_resource_descriptor;
extern u32 TOSignCave03__shared_resource;
s32 __ct__13TUnk_804AFBF8FP7TObject(void *, void *);
extern s32 __vt__12TOSignCave03[];
extern s32 lbl_805D316C;
extern const f32 lbl_805DB9E0;
extern const f32 lbl_805DB9E4;
void TLobby__sub_8001FE7C(void*, int);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

}

void TOSignCave03::render() {
    CaveSignModel *node1;
    CaveSignModel *node10;
    CaveSignModel *node11;
    CaveSignModel *node12;
    CaveSignModel *node2;
    CaveSignModel *node3;
    CaveSignModel *node4;
    CaveSignModel *node5;
    CaveSignModel *node6;
    CaveSignModel *node7;
    CaveSignModel *node8;
    CaveSignModel *node9;
    if (((VObj_18_26a62c *)(this))->m8(m_c0, (*(f32 *)&this->m_c4)) != 0) {
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        node1 = (*(CaveSignModel * *)&this->model);
        translate_matrix(0, node1->x, node1->y, node1->z);
        draw_ginja_model(node1->model);
        push_matrix();
        node2 = node1->child;
        translate_matrix(0, node2->x, node2->y, node2->z);
        draw_ginja_model(node2->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node3 = node2->child;
        translate_matrix(0, node3->x, node3->y, node3->z);
        draw_ginja_model(node3->model);
        push_matrix();
        node4 = node3->child;
        translate_matrix(0, node4->x, node4->y, node4->z);
        draw_ginja_model(node4->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node5 = (*(CaveSignModel * *)&this->model)->child->sibling;
        translate_matrix(0, node5->x, node5->y, node5->z);
        draw_ginja_model(node5->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node6 = node5->child;
        translate_matrix(0, node6->x, node6->y, node6->z);
        draw_ginja_model(node6->model);
        push_matrix();
        node7 = node6->child;
        translate_matrix(0, node7->x, node7->y, node7->z);
        draw_ginja_model(node7->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node8 = (*(CaveSignModel * *)&this->model)->child->sibling->sibling;
        translate_matrix(0, node8->x, node8->y, node8->z);
        draw_ginja_model(node8->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node9 = node8->child;
        translate_matrix(0, node9->x, node9->y, node9->z);
        draw_ginja_model(node9->model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        push_matrix();
        node10 = (*(CaveSignModel * *)&this->model)->child->sibling->sibling->sibling;
        translate_matrix(0, node10->x, node10->y, node10->z);
        draw_ginja_model(node10->model);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        node11 = node10->child;
        translate_matrix(0, node11->x, node11->y, node11->z);
        draw_ginja_model(node11->model);
        push_matrix();
        node12 = node11->child;
        translate_matrix(0, node12->x, node12->y, node12->z);
        draw_ginja_model(node12->model);
        pop_matrix();
        pop_matrix();
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
}

void *TOSignCave03::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = TOSignCave03__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOSignCave03::close_dialog_window() {
    if ((u32) TOSignCave03__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOSignCave03__shared_resource, 1);
        TOSignCave03__shared_resource = 0U;
    }
}

void TOSignCave03::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_dokanban03_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOSignCave03__shared_resource) = var_r0;
}

void *__dt__12TOSignCave03Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TOSignCave03;
        __dt__13TUnk_804AFBF8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80176FF8___vt__12TOSignCave03_size[sizeof(RecoveredGlobal_80176FF8___vt__12TOSignCave03) == 0x38 ? 1 : -1];
u8 *TOSignCave03__ct(u8 *sign_cave03, s32 arg1, s32 arg2) {
    __ct__13TUnk_804AFBF8FP7TObject((void *)sign_cave03, (void *)arg1);
    *(s32 **)((s8 *)sign_cave03 + 0x18) = &(*(RecoveredGlobal_80176FF8___vt__12TOSignCave03 *)&__vt__12TOSignCave03).value;
    *(s32 *)((s8 *)sign_cave03 + 0) = (s32) lbl_805D316C;
    ((TOSignCave03 *)(sign_cave03))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)sign_cave03 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOSignCave03__shared_resource) + 0x42C)) + 8);
    ((TOSignCave03 *)sign_cave03)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOSignCave03__shared_resource) + 0x42C)) + 0xC);
    ((TOSignCave03 *)sign_cave03)->m_c0 = (f32) lbl_805DB9E0;
    *(f32 *)((s8 *)sign_cave03 + 0xC4) = (f32) lbl_805DB9E4;
    return sign_cave03;
}
