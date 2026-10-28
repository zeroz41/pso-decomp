#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/misc/TOCapsuleLabo.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOHealGeneral.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjSeabedSuisoBrakable.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern char lbl_80470790[];
extern char lbl_804707AC[];
extern const char *bm_obj_labo_infocapsule_model_names[2];
extern BmlResourceDescriptor TOCapsuleLabo__resource_descriptor;
extern const char *bm_obj_labo_infocapsule_motion_names[1];

struct VBase802AF370_802af370_802AF2C8 { char pad[0x18]; };
struct VObj802AF370_802af370_802AF2C8 : VBase802AF370_802af370_802AF2C8 {
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

struct RecoveredGlobal_802AF300_lbl_804DE440 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_802AF300_lbl_804DE440_size[sizeof(RecoveredGlobal_802AF300_lbl_804DE440) == 0x10 ? 1 : -1];

struct RecoveredGlobal_802AF4F4_lbl_804DE450 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_802AF4F4___vt__13TOCapsuleLabo {
    s32 value;
    u8 remaining[0x40];
};

extern "C" {
s32 get_bml_model(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern u32 TOCapsuleLabo__model_resource;
extern s32 *capsule_labo_switch_flags_ptr;
s32 is_split_screen();
s32 queue_destruction__7TObjectFv(void *);
s32 TObjFish__sub_8001EDB0(int, int);
s32 init_collision_body_parts(void *, void *, int);
extern RecoveredGlobal_802AF4F4_lbl_804DE450 TOCapsuleLabo__collision_parts;
extern s32 __vt__13TOCapsuleLabo[];
extern s32 enable_v2_features;
extern s32 lbl_805D3E7C;
extern const f32 lbl_805DE1E8;
extern const f32 lbl_805DE1EC;
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
void free_collision_body_parts(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void __dl__7TObjectFPv(void *);

void TOCapsuleLabo::unload_static_data() {
    if ((u32) TOCapsuleLabo__model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOCapsuleLabo__model_resource, 1);
        TOCapsuleLabo__model_resource = 0U;
    }
}

void TOCapsuleLabo::load_resources() {
    s32 temp_r3;
    s32 var_r0;
    u32 bml_model;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &TOCapsuleLabo__resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TOCapsuleLabo__model_resource) = (unsigned char *) ((void *) var_r0);
    bml_model = get_bml_model((void *) var_r0, 0);
    if (bml_model != 0) {
        (*(s32 *)&capsule_labo_switch_flags_ptr) = (s32)find_object_node((NJS_OBJECT *)bml_model, 3);
    }
}

void TOCapsuleLabo::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31_3;
    u8 *temp_r31;
    u8 *temp_r31_2;

    this->m_e0 = ((VObj802AF370_802af370_802AF2C8 *) arg0)->m8(this->m_c0, *(f32 *)&this->m_c4);
    if ((s32) this->m_e0 == 1) {
        TObjFish::set_global_param(this->texlist);
        if ((s32) this->m_cc == 1) {
            if ((s32 *) capsule_labo_switch_flags_ptr != NULL) {
                *capsule_labo_switch_flags_ptr &= 0xFFFFFFF7;
            }
        } else if ((s32 *) capsule_labo_switch_flags_ptr != NULL) {
            *capsule_labo_switch_flags_ptr |= 8;
        }
        temp_r31 = (unsigned char *) (*(void * *)&this->model);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        post_translate_matrix(temp_r31 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        temp_r31_2 = (unsigned char *) (*(void **)((s8 *)temp_r31 + 0x2C));
        push_matrix();
        post_translate_matrix(temp_r31_2 + 8);
        rotate_matrix_y(0, (int) (*(s32 *)&this->m_e4));
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
        temp_r31_3 = *(s32 *)((s8 *)temp_r31_2 + 0x2C);
        TParticleCtrl::begin_effect_render();
        post_translate_matrix((void *)(temp_r31_3 + 8));
        draw_ginja_object((void *)temp_r31_3);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
}

void TOCapsuleLabo::vfunc_15() {
    this->m_e4 = (this->m_e4 + 0x222);
}

void *__dt__13TOCapsuleLaboFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TOCapsuleLabo;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804B27D8 *)arg0)->destroy_key_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef char RecoveredGlobal_802AF4F4_lbl_804DE450_size[sizeof(RecoveredGlobal_802AF4F4_lbl_804DE450) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_802AF4F4___vt__13TOCapsuleLabo_size[sizeof(RecoveredGlobal_802AF4F4___vt__13TOCapsuleLabo) == 0x44 ? 1 : -1];
u8 *TOCapsuleLabo__ct(u8 *arg0, s32 arg1, s32 arg2) {
    ((TUnk_804B27D8 *)arg0)->init();
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_802AF4F4___vt__13TOCapsuleLabo *)&__vt__13TOCapsuleLabo).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) lbl_805D3E7C;
    ((TOCapsuleLabo *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((void *)((int) ((*(s32 *)&TOCapsuleLabo__model_resource))), 0);
    ((TOCapsuleLabo *)arg0)->texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOCapsuleLabo__model_resource)), 0);
    init_collision_body_parts(arg0, &TOCapsuleLabo__collision_parts.value, 1);
    ((TObjCollidable *)arg0)->set_indexed_flags(0, 0x1288);
    ((TObjCollidable *)arg0)->refresh_collision_body_centers();
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TOHealGeneral *)arg0)->update_heal_gauge_state();
    ((TOCapsuleLabo *)arg0)->m_c0 = (f32) lbl_805DE1E8;
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) lbl_805DE1EC;
    ((TOCapsuleLabo *)arg0)->m_e4 = 0;
    if (((s32) enable_v2_features == 1) && (get_game_play_mode() == 1)) {
        queue_destruction__7TObjectFv(arg0);
    }
    if (is_split_screen() == 1) {
        queue_destruction__7TObjectFv(arg0);
    }
    return arg0;
}

__declspec(section ".data") const char *bm_obj_labo_infocapsule_model_names[2] = { lbl_80470790, NULL };
BmlResourceDescriptor TOCapsuleLabo__resource_descriptor = { lbl_804707AC, bm_obj_labo_infocapsule_model_names, bm_obj_labo_infocapsule_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_obj_labo_infocapsule_motion_names[1] = { NULL };
}
