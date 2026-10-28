#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TUnk_804B2578.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOHangerMachine01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Base { char pad[0x18]; };

struct VObj : Base {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_80168F94_lbl_804B26C8 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_80168F94_lbl_804B26C8_size[sizeof(RecoveredGlobal_80168F94_lbl_804B26C8) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8016904C_lbl_804B26D8 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8016904C___vt__17TOHangerMachine01 {
    s32 value;
    u8 remaining[0x38];
};

extern "C" {
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 post_translate_matrix(void *);
extern const f32 lbl_805DB6A8;
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_80168F94_lbl_804B26C8 bm_fs_obj_hanger_moto_resource_descriptor;
extern u32 TOHangerMachine01__bml_resource;
s32 init_collision_body_parts(void *, void *, int);
s32 init_map_object_base(void *, int);
extern RecoveredGlobal_8016904C_lbl_804B26D8 hanger_machine01_collision_body_parts;
extern s32 __vt__17TOHangerMachine01[];
extern s32 TOHangerMachine01__class_name;
extern s32 tl_05;
extern const f32 lbl_805DB6AC;
extern const f32 lbl_805DB6B0;
void TLobby__sub_8001FE7C(void*, int);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOHangerMachine01::run_task() {
    this->m_c8 = (this->m_c8 + 0x888);
}

#pragma push
#pragma fp_contract on
void TOHangerMachine01::render() {
    u8 *arg0 = (u8 *)this;
    u8 *p;
    if (((VObj *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        p = (u8 *)(*(u8 * *)&this->model);
        post_translate_matrix(p + 8);
        draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        p = (u8 *)(*(u8 **)((s8 *)p + 0x2C));
        if (lbl_805DB6A8 < this->target_scale) {
            post_translate_matrix(p + 8);
            draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        }
        p = (u8 *)(*(u8 **)((s8 *)p + 0x30));
        post_translate_matrix(p + 8);
        draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        p = (u8 *)(*(u8 **)((s8 *)p + 0x30));
        post_translate_matrix(p + 8);
        draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        p = (u8 *)(*(u8 **)((s8 *)p + 0x2C));
        push_matrix();
        post_translate_matrix(p + 8);
        rotate_matrix_z(0, (int) (*(s32 *)((s8 *)p + 0x1C)));
        rotate_matrix_x(0, (int) (*(s32 *)((s8 *)p + 0x14)));
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)p + 0x18) + *(s32 *)&this->m_c8));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        TParticleCtrl::end_effect_render();
        pop_matrix();
        p = (u8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 * *)&this->model) + 0x2C)) + 0x30)) + 0x30)) + 0x30));
        post_translate_matrix(p + 8);
        draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        p = (u8 *)(*(u8 **)((s8 *)p + 0x2C));
        push_matrix();
        post_translate_matrix(p + 8);
        rotate_matrix_z(0, (int) (*(s32 *)((s8 *)p + 0x1C)));
        rotate_matrix_x(0, (int) (*(s32 *)((s8 *)p + 0x14)));
        rotate_matrix_y(0, (int) (*(s32 *)((s8 *)p + 0x18) + *(s32 *)&this->m_c8));
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        TParticleCtrl::end_effect_render();
        pop_matrix();
        p = (u8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(u8 * *)&this->model) + 0x2C)) + 0x30)) + 0x30)) + 0x30)) + 0x30));
        if (lbl_805DB6A8 < this->scale) {
            post_translate_matrix(p + 8);
            draw_ginja_model((*(s32 *)((s8 *)p + 4)));
        }
        pop_matrix();
    }
}
#pragma pop

void *TOHangerMachine01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xCC);
    if (o != NULL) {
        o = TOHangerMachine01__ct((TOHangerMachine01 *)((u8 *)o), (s32)arg0);
    }
    return o;
}

void TOHangerMachine01::free_static_model() {
    if ((u32) TOHangerMachine01__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOHangerMachine01__bml_resource, 1);
        TOHangerMachine01__bml_resource = 0U;
    }
}

void TOHangerMachine01::load_shared_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_hanger_moto_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOHangerMachine01__bml_resource) = var_r0;
}

void *__dt__17TOHangerMachine01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TOHangerMachine01;
        ((TUnk_804AF8A0 *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern s32 local_client_id;

typedef char RecoveredGlobal_8016904C_lbl_804B26D8_size[sizeof(RecoveredGlobal_8016904C_lbl_804B26D8) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8016904C___vt__17TOHangerMachine01_size[sizeof(RecoveredGlobal_8016904C___vt__17TOHangerMachine01) == 0x3C ? 1 : -1];
u8 *TOHangerMachine01__ct(TOHangerMachine01 *hanger_machine01, s32 arg1) {
    init_map_object_base(hanger_machine01, tl_05);
    *(s32 **)((s8 *)hanger_machine01 + 0x18) = &(*(RecoveredGlobal_8016904C___vt__17TOHangerMachine01 *)&__vt__17TOHangerMachine01).value;
    *(s32 *)((s8 *)hanger_machine01 + 0) = (s32) TOHangerMachine01__class_name;
    ((TOHangerMachine01 *)(hanger_machine01))->apply_object_set_data((void *)arg1);
    *(s32 *)((s8 *)hanger_machine01 + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOHangerMachine01__bml_resource) + 0x42C)) + 8);
    hanger_machine01->texture_id = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOHangerMachine01__bml_resource) + 0x42C)) + 0xC);
    hanger_machine01->m_c0 = (f32) lbl_805DB6AC;
    *(f32 *)((s8 *)hanger_machine01 + 0xC4) = (f32) lbl_805DB6B0;
    hanger_machine01->actorFlags = (s32) (hanger_machine01->actorFlags | 0x40000000);
    init_collision_body_parts(hanger_machine01, &hanger_machine01_collision_body_parts.value, 1);
    ((TUnk_804AF8A0 *)hanger_machine01)->refresh_collision_body_centers();
    ((TObjPlayer *)hanger_machine01)->reset_photon_effect();
    hanger_machine01->m_c8 = 0;
    return (u8 *)hanger_machine01;
}

s32 TOHangerMachine01::is_valid_slot(int arg0, u16 arg1) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return 1;
    }
    return (u32)__cntlzw((u32)(local_client_id - (u16)arg1)) >> 5;
}

void TOHangerMachine01__sub_80169168(void *self) {  }

}
