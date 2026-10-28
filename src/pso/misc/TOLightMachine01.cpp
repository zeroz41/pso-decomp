#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOLightMachine01.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/object/TObjMotion.h"

struct Base_8016E9F4_8016E998 { char pad[0x18]; };
struct VObj_8016E9F4_8016E998 : Base_8016E9F4_8016E998 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_8016EB3C_lbl_804B2EC4 { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8016EB3C_lbl_804B2EC4_size[sizeof(RecoveredGlobal_8016EB3C_lbl_804B2EC4) == 0x10 ? 1 : -1];

struct RecoveredGlobal_8016EC04___vt__16TOLightMachine01 { s32 value; u8 remaining[0x30]; };

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8016EB3C_lbl_804B2EC4 light_machine01_resource_desc;
extern u32 TOLightMachine01__shared_bml_archive;
extern s32 light_machine_ginja_model_handle;
extern s32 light_machine_ginja_param;
s32 __ct__13TUnk_804B9870FP7TObject(void *, int);
s32 rand();
f32 sin_table_lookup(s32);
extern s32 __vt__16TOLightMachine01[];
extern s32 TOLightMachine01__name;
extern s32 tl_05;
extern const f32 lbl_805DB82C;
extern const f32 lbl_805DB830;
extern const f32 lbl_805DB834;
extern const f32 lbl_805DB838;
extern const f32 lbl_805DB83C;
extern const f32 lbl_805DB840;
extern const f32 lbl_805DB844;
extern const f32 lbl_805DB848;
void TLobby__sub_8001FE7C(void*, int);
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOLightMachine01::run_task() {
    this->m_a8 = (s32) (this->m_a8 + this->m_a4);
    this->m_9c = (f32) (*(f32 *)&this->unk_98 * sin_table_lookup(*(s32 *)&this->m_a8));
    this->m_ac = (s32) (this->m_ac + this->set_params[2]);
}

extern const f32 lbl_805DB828;

void TOLightMachine01::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_8016E9F4_8016E998 *)arg0)->m8(*(f32 *)&this->unk_90, this->m_94) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        draw_ginja_model(*(s32 *)((s8 *)this->model + 4));
        push_matrix();
        translate_matrix(0, lbl_805DB828, this->m_9c, lbl_805DB828);
        rotate_matrix_y(0, this->m_ac);
        draw_ginja_model(*(s32 *)((s8 *)(*(void **)((s8 *)this->model + 0x2C)) + 4));
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(light_machine_ginja_param);
        draw_ginja_object((void *)light_machine_ginja_model_handle);
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
    }
}

void *TOLightMachine01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB0);
    if (o != NULL) {
        o = TOLightMachine01__ct((TOLightMachine01 *)((u8 *)o), (s32)arg0);
    }
    return o;
}

void TOLightMachine01::destroy_instance() {
    if ((u32) TOLightMachine01__shared_bml_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TOLightMachine01__shared_bml_archive, 1);
        TOLightMachine01__shared_bml_archive = 0U;
    }
}

void TOLightMachine01::load_assets() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &light_machine01_resource_desc.value, 0, 0, 0));
    }
    (*(u8 * *)&TOLightMachine01__shared_bml_archive) = (unsigned char *) ((void *) var_r0);
    light_machine_ginja_model_handle = get_bml_model((void *) var_r0, 0);
    light_machine_ginja_param = TObjFish__sub_8001EDB0((*(u8 * *)&TOLightMachine01__shared_bml_archive), 0);
}

void *__dt__16TOLightMachine01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOLightMachine01;
        __dt__13TUnk_804B9870Fv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
#pragma push
#pragma fp_contract on
u8 *TOLightMachine01__ct(TOLightMachine01 *light_machine01, s32 arg1) {
    __ct__13TUnk_804B9870FP7TObject(light_machine01, tl_05);
    *(s32 **)((s8 *)light_machine01 + 0x18) = &(*(RecoveredGlobal_8016EC04___vt__16TOLightMachine01 *)&__vt__16TOLightMachine01).value;
    *(s32 *)((s8 *)light_machine01 + 0) = (s32) TOLightMachine01__name;
    ((TOLightMachine01 *)(light_machine01))->apply_object_set_data((void *)arg1);
    light_machine01->model = ((u8 *)get_bml_model((void *)((*(s32 *)&TOLightMachine01__shared_bml_archive)), 1));
    light_machine01->texture_id = TObjFish__sub_8001EDB0((void *)((int) ((*(s32 *)&TOLightMachine01__shared_bml_archive))), 1);
    *(f32 *)((s8 *)light_machine01 + 0x90) = (f32) lbl_805DB82C;
    light_machine01->m_94 = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)light_machine01->model + 4)) + 0x14);
    light_machine01->actorFlags = (s32) (light_machine01->actorFlags | 0x40000000);
    *(f32 *)((s8 *)light_machine01 + 0xA0) = (f32) ((lbl_805DB834 * (f32) light_machine01->set_params[0]) + lbl_805DB830);
    light_machine01->m_a4 = (s32) (lbl_805DB838 * (lbl_805DB83C / (lbl_805DB840 / *(f32 *)((s8 *)light_machine01 + 0xA0))));
    light_machine01->m_a8 = (s32) (lbl_805DB838 * (lbl_805DB83C * (lbl_805DB844 * (f32) rand())));
    *(f32 *)((s8 *)light_machine01 + 0x98) = (f32) ((lbl_805DB834 * (f32) *(s32 *)((s8 *)light_machine01 + 0x88)) + lbl_805DB848);
    light_machine01->m_9c = (f32) (*(f32 *)((s8 *)light_machine01 + 0x98) * sin_table_lookup(light_machine01->m_a8));
    light_machine01->m_ac = 0;
    return (u8 *)light_machine01;
}
#pragma pop

}
