#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/misc/TOComputerMachine01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOHealGeneral.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
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

struct RecoveredGlobal_8015B350_TOComputerMachine01__data_8050DB50 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8015B644_lbl_804AFFF8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015B644___vt__19TOComputerMachine01 {
    s32 value;
    u8 remaining[0x40];
};

struct Node_8015B544 { u8 pad[4]; s32 val; u8 pad8[0x28]; Node_8015B544 *next; };

struct Res_8015B544 { u8 pad[0x2C]; Node_8015B544 *head; };

struct Mdl_8015B544 { u8 pad[8]; Res_8015B544 *res; };

struct Obj_8015B544 { u8 pad[0x42C]; Mdl_8015B544 *model; };

extern "C" {
s32 scroll_ginja_mesh_uvs(int, int, int, int, int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern RecoveredGlobal_8015B350_TOComputerMachine01__data_8050DB50 TOComputerMachine01__scroll_mesh_ptrs;
extern s32 actor_frame_tick;
extern s32 TOComputerMachine01__last_render_frame_tick;
s32 init_collision_body_parts(void *, void *, int);
s32 init__13TUnk_804B27D8Fv(void *, int);
extern RecoveredGlobal_8015B644_lbl_804AFFF8 computer_machine01_collision_body;
extern s32 __vt__19TOComputerMachine01[];
extern s32 lbl_805D2EEC;
extern u8 *TOComputerMachine01__model_resource;
extern s32 tl_05;
extern const f32 lbl_805DB390;
extern const f32 lbl_805DB394;
void TLobby__sub_8001FE7C(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern s32 bm_fs_obj_kenkyu_com_resource_descriptor[];
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

typedef char RecoveredGlobal_8015B350_TOComputerMachine01__data_8050DB50_size[sizeof(RecoveredGlobal_8015B350_TOComputerMachine01__data_8050DB50) == 0x10 ? 1 : -1];
void TOComputerMachine01::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    u8 *temp_r31_4;
    this->m_e0 = ((VObj_18_26a62c *)(arg0))->m8(this->m_c0, *(f32 *)&this->m_c4);
    if ((s32) this->m_e0 == 1) {
        if ((s32) TOComputerMachine01__last_render_frame_tick != (s32) actor_frame_tick) {
            TOComputerMachine01__last_render_frame_tick = actor_frame_tick;
            scroll_ginja_mesh_uvs((int) (*(s32 *)((s8 *)&TOComputerMachine01__scroll_mesh_ptrs.value + 0)), 0, 2, 7, 1);
            scroll_ginja_mesh_uvs((int) (*(s32 *)((s8 *)&TOComputerMachine01__scroll_mesh_ptrs.value + 4)), 0, -2, 7, 1);
            scroll_ginja_mesh_uvs((int) (*(s32 *)((s8 *)&TOComputerMachine01__scroll_mesh_ptrs.value + 8)), 0, 1, 7, 1);
            scroll_ginja_mesh_uvs((int) (*(s32 *)((s8 *)&TOComputerMachine01__scroll_mesh_ptrs.value + 0xC)), 0, -1, 7, 1);
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        temp_r31 = (u8 *)(*(u8 * *)&this->model);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        TParticleCtrl::begin_effect_render();
        temp_r31_2 = (u8 *)(*(u8 **)((s8 *)temp_r31 + 0x2C));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
        temp_r31_3 = (u8 *)(*(u8 **)((s8 *)temp_r31_2 + 0x30));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
        temp_r31_4 = (u8 *)(*(u8 **)((s8 *)temp_r31_3 + 0x30));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_4 + 4)));
        draw_ginja_model((*(s32 *)((s8 *)(*(u8 **)((s8 *)temp_r31_4 + 0x30)) + 4)));
        TParticleCtrl::end_effect_render();
        pop_matrix();
    }
}

void *TOComputerMachine01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE8);
    if (o != NULL) {
        o = TOComputerMachine01__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

void TOComputerMachine01::reset_state() {
    s32 i;
    TOComputerMachine01__last_render_frame_tick = 0;
    for (i = 0; i < 0x4; i++) {
        ((s32 *)&TOComputerMachine01__scroll_mesh_ptrs)[i] = 0;
    }
    if ((*(void * *)&TOComputerMachine01__model_resource) != 0) {
        TLobby__sub_8001FE7C((*(void * *)&TOComputerMachine01__model_resource), 1);
        (*(void * *)&TOComputerMachine01__model_resource) = 0;
    }
}

void TOComputerMachine01::load_model_resource() {
    u8 *o;
    Node_8015B544 *n;
    o = (u8 *)::operator new(0x440);
    if (o != NULL) {
        o = load_resource_from_descriptor(o, 1, bm_fs_obj_kenkyu_com_resource_descriptor, 0, 0, 0);
    }
    TOComputerMachine01__model_resource = o;
    n = ((Obj_8015B544 *)o)->model->res->head;
    ((s32 *)&TOComputerMachine01__scroll_mesh_ptrs)[3] = n->val;
    ((s32 *)&TOComputerMachine01__scroll_mesh_ptrs)[2] = n->next->val;
    ((s32 *)&TOComputerMachine01__scroll_mesh_ptrs)[1] = n->next->next->val;
    ((s32 *)&TOComputerMachine01__scroll_mesh_ptrs)[0] = n->next->next->next->val;
    TOComputerMachine01__last_render_frame_tick = 0;
}

void *__dt__19TOComputerMachine01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TOComputerMachine01;
        free_collision_body_parts(arg0);
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        ((TUnk_804B27D8 *)arg0)->destroy_key_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_8015B644_lbl_804AFFF8_size[sizeof(RecoveredGlobal_8015B644_lbl_804AFFF8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015B644___vt__19TOComputerMachine01_size[sizeof(RecoveredGlobal_8015B644___vt__19TOComputerMachine01) == 0x44 ? 1 : -1];
u8 *TOComputerMachine01__ct(u8 *arg0, s32 arg1) {
    init__13TUnk_804B27D8Fv(arg0, tl_05);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8015B644___vt__19TOComputerMachine01 *)&__vt__19TOComputerMachine01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2EEC;
    ((TOComputerMachine01 *)(arg0))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TOComputerMachine01__model_resource + 0x42C)) + 8);
    ((TOComputerMachine01 *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TOComputerMachine01__model_resource + 0x42C)) + 0xC);
    ((TOComputerMachine01 *)arg0)->m_c0 = (f32) lbl_805DB390;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB394;
    ((TOComputerMachine01 *)arg0)->actorFlags = (s32) (((TOComputerMachine01 *)arg0)->actorFlags | 0x40000000);
    init_collision_body_parts(arg0, &computer_machine01_collision_body.value, 1);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TOHealGeneral *)arg0)->update_heal_gauge_state();
    return arg0;
}

}
