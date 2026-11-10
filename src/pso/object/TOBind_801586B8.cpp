#include "types.h"
#include "pso/object/TOBind.h"
#include "pso/object/TOBind_801586B8.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TOBind.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer_801542CC.h"

extern char lbl_80440220[];
extern char lbl_80440234[];
extern char lbl_8044024C[];
extern char lbl_80440268[];
__declspec(section ".data") const char *bm_o_bind_model_names[3] = { lbl_80440220, lbl_80440234, NULL };
__declspec(section ".data") const char *bm_o_bind_motion_names[2] = { lbl_8044024C, NULL };
BmlResourceDescriptor bm_o_bind_resource_descriptor = { lbl_80440268, bm_o_bind_model_names, bm_o_bind_motion_names, 2, 1 };
CollisionBody bind_collision_body_parts[2] = {
    {{0.0f, 20.0f, 0.0f}, 10.0f, 0.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 20.0f, -10.0f}, 5.0f, 10.0f, 1, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

struct RecoveredGlobal_80158890___vt__6TOBind {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TOBind__static_model_resource;
u8 *get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
s32 __ct__14TObjCollidableFP7TObject(void *, int);
extern s32 __vt__6TOBind[];
extern s32 lbl_805D2EA8;
extern s32 tl_05;
struct BindBase_801586B8 { char pad[0x18]; };
struct BindObj_801586B8 : BindBase_801586B8 {
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

void free_bin_model_request(void*, int);
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOBind::render() {
    u8 *arg0 = (u8 *)this;
    if (((BindObj_801586B8*)arg0)->m8(*(f32 *)&this->unk_D0, this->m_d4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        if ((s32) this->m_b0 != 1) {
            TObjFish::set_global_param(this->m_c8);
            TParticleCtrl::begin_effect_render();
            draw_ginja_model_with_motion(this->m_c4, this->m_cc, *(f32 *)((s8 *)arg0 + 0xB8));
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

void *TOBind::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xD8);
    if (o != NULL) {
        o = TOBind__ct((TOBind *)((u8 *)o), (s32)arg0);
    }
    return o;
}

void TOBind::free_static_model() {
    if ((u32) TOBind__static_model_resource != 0U) {
        free_bin_model_request((void*)TOBind__static_model_resource, 1);
        TOBind__static_model_resource = 0U;
    }
}

void TOBind::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_bind_resource_descriptor, 0, 0, 0));
    }
    (*(s32 *)&TOBind__static_model_resource) = var_r0;
}

}
TOBind::~TOBind() {
    ((TObjCollidable *)this)->unregister_object_by_id();
    free_collision_body_parts(this);
}
extern "C" {
typedef char RecoveredGlobal_80158890___vt__6TOBind_size[sizeof(RecoveredGlobal_80158890___vt__6TOBind) == 0x3C ? 1 : -1];
u8 *TOBind__ct(TOBind *bind, s32 arg1) {
    __ct__14TObjCollidableFP7TObject(bind, tl_05);
    *(s32 **)((s8 *)bind + 0x18) = &(*(RecoveredGlobal_80158890___vt__6TOBind *)&__vt__6TOBind).value;
    *(s32 *)((s8 *)bind + 0) = (s32) lbl_805D2EA8;
    ((TOBind *)(bind))->apply_object_set_data((void *)arg1);
    bind->m_b0 = 0;
    *(s32 *)((s8 *)bind + 0x34) = get_bml_model((int) ((*(s32 *)&TOBind__static_model_resource)), 0);
    bind->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOBind__static_model_resource)), 0);
    bind->m_c4 = get_bml_model((int) ((*(s32 *)&TOBind__static_model_resource)), 1);
    bind->m_c8 = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOBind__static_model_resource)), 1);
    *(u8 **)((s8 *)bind + 0xCC) = get_bml_motion((*(s32 *)&TOBind__static_model_resource), 0);
    *(f32 *)((s8 *)bind + 0xB8) = 0.0f;
    bind->m_bc = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)bind + 0xCC)) + 4) - 1.0f);
    *(f32 *)((s8 *)bind + 0xC0) = 1.0f;
    init_collision_body_parts(bind, bind_collision_body_parts, 2);
    ((TObjCollidable *)bind)->refresh_collision_body_centers();
    ((TObjPlayer *)bind)->register_object_by_id();
    bind->actorFlags = (s32) (bind->actorFlags | 0x40000000);
    bind->m_b4 = (s32) bind->set_params[0];
    if ((s32) bind->m_b4 < 0) {
        bind->m_b4 = 0;
    }
    *(f32 *)((s8 *)bind + 0xD0) = 400.0f;
    bind->m_d4 = 40.0f;
    return (u8 *)bind;
}

}
