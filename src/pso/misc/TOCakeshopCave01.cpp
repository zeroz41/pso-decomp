#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjMapObject.h"
#include "pso/misc/TOCakeshopCave01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8015A108_lbl_804AFDF8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8015A108_lbl_804AFDF8_size[sizeof(RecoveredGlobal_8015A108_lbl_804AFDF8) == 0x10 ? 1 : -1];

struct Model_80159F78 {
    u8 pad0[4];
    s32 m4;
    u8 m8[0x24];
    Model_80159F78 *child;
    Model_80159F78 *next;
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8015A108_lbl_804AFDF8 bm_fs_obj_cakeya_resource_descriptor;
extern u32 TOCakeshopCave01__model_resource;
s32 rand(void);
extern const f32 lbl_805DB358;
extern const f32 lbl_805DB35C;
extern const f32 TOCakeshopCave01__data_805DB360;
extern const f32 lbl_805DB364;
s32 init_collision_body_parts(void *, void *, int);
extern s32 cakeshop_cave01_collision_body_part[];
extern const char *lbl_805D2EC4;
extern void *tl_05;
extern const f32 lbl_805DB36C;
extern const f32 lbl_805DB370;
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern const f32 lbl_805DB368;
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
}

void TOCakeshopCave01::update_blink_state(void *arg1) {
    s32 i = (s32)arg1;
    switch (m_ec[i]) {
    default:
        m_cc[i] += lbl_805DB358;
        if (lbl_805DB35C * (f32)rand() < m_cc[i]) {
            m_ec[i] = 1;
            m_cc[i] = TOCakeshopCave01__data_805DB360;
        }
        break;
    case 1:
        m_cc[i] -= lbl_805DB358;
        if (m_cc[i] <= lbl_805DB364) {
            m_ec[i] = 2;
            m_cc[i] = lbl_805DB364;
        }
        break;
    case 2:
        m_cc[i] += lbl_805DB358;
        if (TOCakeshopCave01__data_805DB360 < m_cc[i]) {
            m_ec[i] = 0;
        }
        break;
    }
}

void TOCakeshopCave01::run_task() { { int i; for (i = 0; i < 8; i++) { update_blink_state((void *)((void*)i)); } } }

void TOCakeshopCave01::render() {
    Model_80159F78 *m;
    s32 i;
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        m = *(Model_80159F78 * *)&this->model;
        post_translate_matrix(m->m8);
        draw_ginja_model(m->m4);
        m = m->child;
        TParticleCtrl::begin_effect_render();
        for (i = 0; i < 8; i++) {
            if (m_cc[i] < TOCakeshopCave01__data_805DB360) {
                push_matrix();
                post_translate_matrix(m->m8);
                scale_matrix(0, lbl_805DB368 - m_cc[i], lbl_805DB368 - m_cc[i], TOCakeshopCave01__data_805DB360);
                draw_ginja_model(m->m4);
                pop_matrix();
            }
            m = m->next;
        }
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOCakeshopCave01::create() {
    return new TOCakeshopCave01(this);
}

void TOCakeshopCave01::close_dialog_window() {
    if ((u32) TOCakeshopCave01__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOCakeshopCave01__model_resource, 1);
        TOCakeshopCave01__model_resource = 0U;
    }
}

void TOCakeshopCave01::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_cakeya_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOCakeshopCave01__model_resource) = var_r0;
}

// The destructor is still written out by hand: compiled, its vtable would
// open the unit's .data, which the original fills first with the object's
// resource and collision tables (not owned by this unit yet).
extern "C" {
extern void *__vt__16TOCakeshopCave01[];
void __dl__7TObjectFPv(void *);

void *__dt__16TOCakeshopCave01Fv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__16TOCakeshopCave01;
        free_collision_body_parts((TOCakeshopCave01 *)self);
        ((TOCakeshopCave01 *)self)->unregister_object_by_id();
        __dt__13TObjMapObjectFv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

TOCakeshopCave01::TOCakeshopCave01(void *set_data) : TObjMapObject((TObject *)tl_05) {
    s32 i;
    m_name = lbl_805D2EC4;
    apply_object_set_data(set_data);
    model = (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)TOCakeshopCave01__model_resource + 0x42C)) + 8);
    texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)TOCakeshopCave01__model_resource + 0x42C)) + 0xC);
    m_c0 = lbl_805DB36C;
    model_radius = lbl_805DB370;
    actorFlags |= 0x40000000;
    init_collision_body_parts(this, cakeshop_cave01_collision_body_part, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    for (i = 0; i < 8; i++) {
        m_cc[i] = TOCakeshopCave01__data_805DB360;
        m_ec[i] = 0;
    }
}
