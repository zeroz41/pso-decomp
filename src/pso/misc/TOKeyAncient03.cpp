#include "types.h"
#include "pso/misc/TOKeyAncient03.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TOKeyCave01.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

struct RecoveredGlobal_8016BD60___vt__14TOKeyAncient03 { s32 value; u8 remaining[0x6C]; };

struct VBase_18_8016BABC { char pad[0x18]; };

struct VObj_18_8016BABC : VBase_18_8016BABC {
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

extern "C" {
s32 is_split_screen();

s32 play_sound_effect(s32, s32, s32, s32);
u8 *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
void *mem_alloc(u32 size);
u8 *load_gvm_texture_file(s32 arg0);
extern const char lbl_80441ACC[];
extern BmlResourceDescriptor bm_fs_obj_o_doorpanel_resource_descriptor;
extern u32 TOKeyAncient03__model_archive;
extern void *TOKeyAncient03__texture_variants;
s32 get_main_phase(void);
u8 * TOKey__ct(void *);
extern s32 __vt__14TOKeyAncient03[];
extern s32 TOKeyAncient03__class_name;

u8 *TOKeyAncient03__ct(TOKeyAncient03 *arg0, s32 arg1, s32 arg2);

s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_ginja_model(s32 model);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
void TLobby__sub_8001FE7C(void*, int);
void *__nw__7TObjectFUl(int);
void mem_free(void *p);

void TOKeyAncient03::vfunc_19() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4004B20D, arg0 + 0x38, 0, 0);
}

void TOKeyAncient03::trigger_activate_sound() {
    s32 arg0 = (s32)this;
    play_sound_effect(0x4004B20D, arg0 + 0x38, 0, 0);
}

extern void *tl_05;

void TOKeyAncient03::vfunc_17() {
    f32 temp_f1;
    if ((s32) this->m_f8 == 1) {
        this->m_ec += 0.1f;
        if (1.0f <= this->m_ec) {
            this->m_f8 = 0;
        }
    } else {
        this->m_ec = (f32) (this->m_ec - 0.1f);
        if (this->m_ec <= 0.0f) {
            this->m_f8 = 1;
        }
    }
    temp_f1 = this->target_scale;
    if (temp_f1 < 0.0f) {
        this->target_scale = (f32) (temp_f1 - (-0.023333333f));
    }
}

void TOKeyAncient03::vfunc_16() {
    TOKeyAncient03 *self = this;
    if ((-0.7f) < self->target_scale) {
        self->target_scale += (-0.023333333f);
    }
}

void TOKeyAncient03::run_task() {
    u8 *arg0 = (u8 *)this;
    this->update_lock_state();
    if ((s32) this->m_d4 != 1) {
        this->vfunc_17();
        if (this->is_confirm_pressed() == 1) {
            ((TOKeyAncient03 *)arg0)->send_switch_changed(1);
            this->trigger_activate_sound();
            this->m_d4 = 1;
        }
    } else {
        this->vfunc_16();
        if (this->is_confirm_pressed() != 1) {
            ((TOKeyAncient03 *)arg0)->send_switch_changed(0);
            this->vfunc_19();
            this->m_d4 = 0;
        }
    }
}

void TOKeyAncient03::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    u8 *temp_r31;
    u8 *temp_r31_2;
    u8 *temp_r31_3;
    if (((VObj_18_8016BABC *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        TObjFish::set_global_param((int) (*(s32 *)((s8 *)TOKeyAncient03__texture_variants + (*(s32 *)&this->m_d4 * 4))));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        temp_r31 = *(u8 * *)&this->model;
        post_translate_matrix(temp_r31 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        if ((s32) *(s32 *)&this->m_d4 != 1) {
            temp_r4 = model_render_flags;
            saved_model_render_flags = temp_r4;
            model_render_flags = temp_r4 | 0x10;
            ((TUnk_80494AE0 *)(&this->m_e8))->set_chunk_material_color();
        }
        temp_r31_2 = *(u8 **)((s8 *)temp_r31 + 0x2C);
        push_matrix();
        post_translate_matrix((u8 *)&this->scale);
        post_translate_matrix(temp_r31_2 + 8);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_2 + 4)));
        temp_r31_3 = *(u8 **)((s8 *)temp_r31_2 + 0x2C);
        push_matrix();
        post_translate_matrix(temp_r31_3 + 8);
        TParticleCtrl::begin_effect_render();
        draw_ginja_model((*(s32 *)((s8 *)temp_r31_3 + 4)));
        TParticleCtrl::end_effect_render();
        pop_matrix();
        pop_matrix();
        if ((s32) *(s32 *)&this->m_d4 != 1) {
            ((TUnk_80494AE0 *)chunk_material_color_half_alpha_f32)->set_chunk_material_color();
            model_render_flags = saved_model_render_flags;
        }
        pop_matrix();
    }
}

void *TOKeyAncient03::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xFC);
    if (o != NULL) {
        o = TOKeyAncient03__ct((TOKeyAncient03 *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TOKeyAncient03::cleanup_refs() {
    if ((void *) TOKeyAncient03__texture_variants != NULL) {
        TObjPlayer::free_if_valid(*(s32 *)((s8 *)TOKeyAncient03__texture_variants + 4));
        if ((void *) TOKeyAncient03__texture_variants != NULL) {
            mem_free(TOKeyAncient03__texture_variants);
            TOKeyAncient03__texture_variants = NULL;
        }
    }
    if ((u32) TOKeyAncient03__model_archive != 0U) {
        TLobby__sub_8001FE7C((void*)TOKeyAncient03__model_archive, 1);
        TOKeyAncient03__model_archive = 0U;
    }
}

void TOKeyAncient03::load_resources() {
    s32 *temp_r3_2;
    u8 *temp_r3;
    u8 *var_r0;
    temp_r3 = (u8 *)(((TAdSinglePlyChrSelectGC *)0x440)->alloc());
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(load_resource_from_descriptor(temp_r3, 1, &bm_fs_obj_o_doorpanel_resource_descriptor, 0, 0, 0));
    }
    (*(u8 * *)&TOKeyAncient03__model_archive) = var_r0;
    temp_r3_2 = (s32 *)(mem_alloc(8));
    (*(s32 * *)&TOKeyAncient03__texture_variants) = temp_r3_2;
    *temp_r3_2 = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOKeyAncient03__model_archive) + 0x42C)) + 0xC);
    *(s32 *)((s8 *)(*(s32 * *)&TOKeyAncient03__texture_variants) + 4) = (s32)load_gvm_texture_file((s32)lbl_80441ACC);
}

}
TOKeyAncient03::~TOKeyAncient03() {

}

u8 *TOKeyAncient03__ct(TOKeyAncient03 *key_ancient03, s32 arg1, s32 arg2) {
    TOKey__ct(key_ancient03);
    *(s32 **)((s8 *)key_ancient03 + 0x18) = &(*(RecoveredGlobal_8016BD60___vt__14TOKeyAncient03 *)&__vt__14TOKeyAncient03).value;
    *(s32 *)((s8 *)key_ancient03 + 0) = (s32) TOKeyAncient03__class_name;
    ((TOKeyAncient03 *)(key_ancient03))->apply_object_set_data((void *)arg2);
    ((TOKey *)key_ancient03)->init_switch_id();
    key_ancient03->texture_id = (s32) *(*(s32 * *)&TOKeyAncient03__texture_variants);
    key_ancient03->model = (unsigned char *) ((void *) *(void **)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TOKeyAncient03__model_archive) + 0x42C)) + 8));
    key_ancient03->m_c0 = (f32) 4e+02f;
    *(f32 *)((s8 *)key_ancient03 + 0xC4) = (f32) *(f32 *)((s8 *)(*(void **)((s8 *)key_ancient03->model + 4)) + 0x14);
    *(f32 *)((s8 *)key_ancient03 + 0xCC) = (f32) 1e+01f;
    if (get_main_phase() != 0xF) {
        if (is_split_screen() == 1) {
            goto block_2;
        }
    } else {
block_2:
        if ((s32) key_ancient03->m_d0 != 2) {
            if ((s32) *(s32 *)((s8 *)key_ancient03 + 0x88) < 0) {
                key_ancient03->m_d0 = 1;
            } else {
                goto block_5;
            }
        } else {
block_5:
            key_ancient03->m_d0 = 0;
        }
    }
    key_ancient03->m_e8 = (f32) 1.0f;
    key_ancient03->m_ec = (f32) 1.0f;
    *(f32 *)((s8 *)key_ancient03 + 0xF0) = (f32) 1.0f;
    key_ancient03->m_f4 = (f32) 1.0f;
    key_ancient03->m_f8 = 0;
    *(f32 *)((s8 *)key_ancient03 + 0x70) = (f32) 0.0f;
    key_ancient03->target_scale = (f32) 0.0f;
    key_ancient03->scale = (f32) 0.0f;
    return (u8 *)key_ancient03;
}
