#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOMonitorMachine01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"

struct Node_80172220 { u8 pad0[4]; s32 f4; u8 pad8[0x30 - 8]; Node_80172220 *next; };

struct NodeHead_80172220 { u8 pad[0x2C]; Node_80172220 *root; };

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
extern s32 TOMonitorMachine01__name;
extern s32 tl_05;
extern const f32 lbl_805DB90C;
extern const f32 lbl_805DB910;
}

void TOMonitorMachine01::run_task() {
    if (TOMonitorMachine01__last_update_tick != actor_frame_tick) {
        TOMonitorMachine01__last_update_tick = actor_frame_tick;
        scroll_ginja_mesh_uvs(TOMonitorMachine01__scroll_mesh_ptrs[0], 1, 0, 1, 1);
        scroll_ginja_mesh_uvs(TOMonitorMachine01__scroll_mesh_ptrs[1], 1, 0, 1, 1);
    }
    switch (m_ac) {
    default:
        hold_timer += lbl_805DB8F0;
        if (lbl_805DB8F4 <= hold_timer) {
            m_ac = 1;
            hold_timer = 0.0f;
            set_params[0]++;
            if (set_params[0] >= 4) {
                set_params[0] = 0;
            }
        }
        break;
    case 1:
        slide += lbl_805DB8FC;
        screen_scale += lbl_805DB900;
        if (lbl_805DB904 <= slide) {
            m_ac = 2;
            slide = lbl_805DB904;
            screen_scale = lbl_805DB8F0;
        }
        break;
    case 2:
        hold_timer += lbl_805DB8F0;
        if (lbl_805DB908 <= hold_timer) {
            m_ac = 3;
            hold_timer = 0.0f;
        }
        break;
    case 3:
        slide -= lbl_805DB8FC;
        screen_scale -= lbl_805DB900;
        if (slide <= 0.0f) {
            m_ac = 0;
            screen_scale = 0.0f;
            slide = 0.0f;
        }
        break;
    }
}

void TOMonitorMachine01::render() {
    Node_80172220 *n;
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjFish::set_global_param(texlist);
        n = ((NodeHead_80172220 *)model)->root;
        push_matrix();
        translate_matrix(0, -slide, 0.0f, 0.0f);
        draw_ginja_model(n->f4);
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        n = n->next;
        if (set_params[0] == 2) {
            push_matrix();
            scale_matrix(0, screen_scale, screen_scale, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        n = n->next;
        if (set_params[0] == 1) {
            push_matrix();
            scale_matrix(0, screen_scale, screen_scale, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        TParticleCtrl::end_effect_render();
        n = n->next;
        push_matrix();
        translate_matrix(0, slide, 0.0f, 0.0f);
        draw_ginja_model(n->f4);
        pop_matrix();
        TParticleCtrl::begin_effect_render();
        n = n->next;
        if (set_params[0] == 0) {
            push_matrix();
            scale_matrix(0, screen_scale, screen_scale, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        n = n->next;
        if (set_params[0] == 3) {
            push_matrix();
            scale_matrix(0, screen_scale, screen_scale, lbl_805DB8F0);
            draw_ginja_model(n->f4);
            pop_matrix();
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOMonitorMachine01::create(void *set_data) {
    return new TOMonitorMachine01(set_data);
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

TOMonitorMachine01::~TOMonitorMachine01() {}

#pragma push
#pragma opt_common_subs off
TOMonitorMachine01::TOMonitorMachine01(void *set_data) : TObjMapObject((TObject *)tl_05) {
    m_name = (const char *)TOMonitorMachine01__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(TOMonitorMachine01__shared_bml_archive, 0);
    texlist = TObjFish__sub_8001EDB0(TOMonitorMachine01__shared_bml_archive, 0);
    m_c0 = lbl_805DB90C;
    model_radius = lbl_805DB910;
    actorFlags |= 0x40000000;
    m_ac = 0;
    slide = 0.0f;
    screen_scale = 0.0f;
    hold_timer = 0.0f;
    if (set_params[0] < 0) {
        set_params[0] = 0;
    } else if (set_params[0] >= 4) {
        set_params[0] = 3;
    }
}
#pragma pop
