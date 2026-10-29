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

struct RecoveredGlobal_80176F50_lbl_804B43A0 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80176F50_lbl_804B43A0_size[sizeof(RecoveredGlobal_80176F50_lbl_804B43A0) == 0x10 ? 1 : -1];

extern "C" {
s32 rotate_matrix_y(int, int);
s32 push_matrix();
f32 post_translate_matrix(void *);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80176F50_lbl_804B43A0 bm_fs_obj_dokanban03_resource_descriptor;
extern u32 TOSignCave03__shared_resource;
extern const char *lbl_805D316C;
extern const f32 lbl_805DB9E0;
extern const f32 lbl_805DB9E4;
void TLobby__sub_8001FE7C(void*, int);

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
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        node1 = ((CaveSignModel *)model);
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
        node5 = ((CaveSignModel *)model)->child->sibling;
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
        node8 = ((CaveSignModel *)model)->child->sibling->sibling;
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
        node10 = ((CaveSignModel *)model)->child->sibling->sibling->sibling;
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
    return new TOSignCave03((TObject *)tl_05, arg0);
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

TOSignCave03::~TOSignCave03() {}

TOSignCave03::TOSignCave03(TObject *parent, void *set_data) : TUnk_804AFBF8(parent) {
    m_name = lbl_805D316C;
    apply_object_set_data(set_data);
    model = (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOSignCave03__shared_resource) + 0x42C)) + 8);
    texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOSignCave03__shared_resource) + 0x42C)) + 0xC);
    m_c0 = (f32) lbl_805DB9E0;
    model_radius = (f32) lbl_805DB9E4;
}
