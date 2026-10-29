#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/misc/TOCapsuleAncient01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct VBase_8015a2b8 { char pad[0x18]; };
struct VObj_8015a2b8 : VBase_8015a2b8 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_8015A418_lbl_804AFE78 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8015A418_lbl_804AFE78_size[sizeof(RecoveredGlobal_8015A418_lbl_804AFE78) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8015A4D0_lbl_804AFE88 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8015A4D0___vt__18TOCapsuleAncient01 {
    s32 value;
    u8 remaining[0x40];
};

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8015A418_lbl_804AFE78 bm_fe_obj_o_capsule01_resource_descriptor;
extern u32 TOCapsuleAncient01__static_model_resource;
s32 is_split_screen();
s32 queue_destruction__7TObjectFv(void *);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_8015A4D0_lbl_804AFE88 capsule_ancient01_collision_body;
extern s32 __vt__18TOCapsuleAncient01[];
extern s32 enable_v2_features;
extern s32 lbl_805D2ECC;
extern const f32 lbl_805DB378;
extern const f32 lbl_805DB37C;
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 free_collision_body_parts(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOCapsuleAncient01::render() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r31;
    u8 *temp_r31_2;

    this->visible = ((VObj_8015a2b8 *) arg0)->m8(this->m_c0, *(f32 *)&this->m_c4);
    if ((s32) this->visible == 1) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        temp_r31 = (unsigned char *) (*(void * *)&this->model);
        translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31 + 8)), (f32) (*(f32 *)((s8 *)temp_r31 + 0xC)), (f32) (*(f32 *)((s8 *)temp_r31 + 0x10)));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        if ((s32) this->active == 1) {
            TParticleCtrl::begin_effect_render();
            temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
            push_matrix();
            translate_matrix(0, (f32) (*(f32 *)((s8 *)temp_r31_2 + 8)), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0xC)), (f32) (*(f32 *)((s8 *)temp_r31_2 + 0x10)));
            rotate_matrix_y(0, (int) (*(s32 *)&this->m_e4));
            draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
            pop_matrix();
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
    }
}

extern void *tl_05;

void *TOCapsuleAncient01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xE8);
    if (o != NULL) {
        o = TOCapsuleAncient01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOCapsuleAncient01::destroy_static_instance() {
    if ((u32) TOCapsuleAncient01__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOCapsuleAncient01__static_model_resource, 1);
        TOCapsuleAncient01__static_model_resource = 0U;
    }
}

void TOCapsuleAncient01::load_resource_instance() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fe_obj_o_capsule01_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOCapsuleAncient01__static_model_resource) = var_r0;
}

void *__dt__18TOCapsuleAncient01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TOCapsuleAncient01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__13TUnk_804B27D8Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

typedef char RecoveredGlobal_8015A4D0_lbl_804AFE88_size[sizeof(RecoveredGlobal_8015A4D0_lbl_804AFE88) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8015A4D0___vt__18TOCapsuleAncient01_size[sizeof(RecoveredGlobal_8015A4D0___vt__18TOCapsuleAncient01) == 0x44 ? 1 : -1];
u8 *TOCapsuleAncient01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__13TUnk_804B27D8FP7TObject(arg0, (TObject *)arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8015A4D0___vt__18TOCapsuleAncient01 *)&__vt__18TOCapsuleAncient01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D2ECC;
    ((TOCapsuleAncient01 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOCapsuleAncient01__static_model_resource) + 0x42C)) + 8);
    ((TOCapsuleAncient01 *)arg0)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOCapsuleAncient01__static_model_resource) + 0x42C)) + 0xC);
    init_collision_body_parts(arg0, &capsule_ancient01_collision_body.value, 1);
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x1288);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TUnk_804B27D8 *)arg0)->read_set_params();
    ((TOCapsuleAncient01 *)arg0)->m_c0 = (f32) lbl_805DB378;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DB37C;
    ((TOCapsuleAncient01 *)arg0)->m_e4 = 0;
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1)) {
        queue_destruction__7TObjectFv(arg0);
    }
    if (is_split_screen() == 1) {
        queue_destruction__7TObjectFv(arg0);
    }
    return arg0;
}

void TOCapsuleAncient01::vfunc_15() {
    this->m_e4 = (this->m_e4 + 0x222);
}

}
