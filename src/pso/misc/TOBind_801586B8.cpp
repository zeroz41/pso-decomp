#include "types.h"
#include "pso/misc/TOBind_801586B8.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TOBind.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_801587D8_lbl_804AFC44 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_801587D8_lbl_804AFC44_size[sizeof(RecoveredGlobal_801587D8_lbl_804AFC44) == 0x10 ? 1 : -1];

struct RecoveredGlobal_80158890_lbl_804AFC54 {
    s32 value;
    u8 remaining[0x54];
};

struct RecoveredGlobal_80158890___vt__6TOBind {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_801587D8_lbl_804AFC44 bm_o_bind_resource_descriptor;
extern u32 TOBind__static_model_resource;
u8 *get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
s32 init_collision_body_parts(void *, void *, int);
s32 __ct__13TUnk_804AF8A0FP7TObject(void *, int);
extern RecoveredGlobal_80158890_lbl_804AFC54 bind_collision_body_parts;
extern s32 __vt__6TOBind[];
extern s32 lbl_805D2EA8;
extern s32 tl_05;
extern const f32 lbl_805DB300;
extern const f32 lbl_805DB304;
extern const f32 lbl_805DB308;
extern const f32 lbl_805DB30C;
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

void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 free_collision_body_parts(void *);
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
        TObjFish::set_global_param(this->texture_id);
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
        TLobby__sub_8001FE7C((void*)TOBind__static_model_resource, 1);
        TOBind__static_model_resource = 0U;
    }
}

void TOBind::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_bind_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOBind__static_model_resource) = var_r0;
}

void *__dt__6TOBindFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__6TOBind;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804AF8A0Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_80158890_lbl_804AFC54_size[sizeof(RecoveredGlobal_80158890_lbl_804AFC54) == 0x58 ? 1 : -1];
typedef char RecoveredGlobal_80158890___vt__6TOBind_size[sizeof(RecoveredGlobal_80158890___vt__6TOBind) == 0x3C ? 1 : -1];
u8 *TOBind__ct(TOBind *bind, s32 arg1) {
    __ct__13TUnk_804AF8A0FP7TObject(bind, tl_05);
    *(s32 **)((s8 *)bind + 0x18) = &(*(RecoveredGlobal_80158890___vt__6TOBind *)&__vt__6TOBind).value;
    *(s32 *)((s8 *)bind + 0) = (s32) lbl_805D2EA8;
    ((TOBind *)(bind))->apply_object_set_data((void *)arg1);
    bind->m_b0 = 0;
    *(s32 *)((s8 *)bind + 0x34) = get_bml_model((int) ((*(s32 *)&TOBind__static_model_resource)), 0);
    bind->texture_id = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOBind__static_model_resource)), 0);
    bind->m_c4 = get_bml_model((int) ((*(s32 *)&TOBind__static_model_resource)), 1);
    bind->m_c8 = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOBind__static_model_resource)), 1);
    *(u8 **)((s8 *)bind + 0xCC) = get_bml_motion((*(s32 *)&TOBind__static_model_resource), 0);
    *(f32 *)((s8 *)bind + 0xB8) = (f32) lbl_805DB300;
    bind->m_bc = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)bind + 0xCC)) + 4) - lbl_805DB304);
    *(f32 *)((s8 *)bind + 0xC0) = (f32) lbl_805DB304;
    init_collision_body_parts(bind, &bind_collision_body_parts.value, 2);
    ((TUnk_804AF8A0 *)bind)->refresh_collision_body_centers();
    ((TObjPlayer *)bind)->reset_photon_effect();
    bind->actorFlags = (s32) (bind->actorFlags | 0x40000000);
    bind->m_b4 = (s32) bind->set_params[0];
    if ((s32) bind->m_b4 < 0) {
        bind->m_b4 = 0;
    }
    *(f32 *)((s8 *)bind + 0xD0) = (f32) lbl_805DB308;
    bind->m_d4 = (f32) lbl_805DB30C;
    return (u8 *)bind;
}

}
