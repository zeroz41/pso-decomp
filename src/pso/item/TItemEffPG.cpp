#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/item/TUnk_804F0BF0.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/item/TItemEffPG_8034FF4C.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/depth_buffer.h"
#include "pso/system/vector.h"
#include "pso/player/TUnk_804F0AF8.h"
#include "pso/item/TUnk_804F0C08.h"

#include "pso/item/TItemEffPG.h"
#include "pso/TParticleCtrl.h"
#include "pso/object/TObjFish.h"

struct RecoveredGlobal_8034FCF0_lbl_804F0BF0 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
extern const f32 lbl_805DFE08;
extern const f32 lbl_805DFE0C;
u8 *__nw__5TItemFUl(s32);
extern s32 tl_05;
void *create_particle_emitter(void *pos, s32 id);
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804F0BF0[];
extern const f32 lbl_805DFE10;
s32 get_render_pass__9TMainTaskFv();
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
void __ct__11TItemWeaponFP7TObjectPUc(void *);
void __dl__7TObjectFPv(void *);

extern s32 lbl_804F0AF8[];

void *TUnk_804F0AF8::init_fields(s32 _w1, void *_w2) {
    __ct__11TItemWeaponFP7TObjectPUc(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_804F0AF8;
    set_weapon_flags(1);
    *(u32 *)((s8 *)this + 0x1F8) = -30947;
    this->m_1fc = -7281;
    return this;
}

u8 *TItemEffPG::create() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;
    u8 *var_r0;
    if (arg0 != NULL) {
        temp_r3 = (u8 *)(__nw__5TItemFUl(0x200));
        var_r0 = temp_r3;
        if (var_r0 != NULL) {
            var_r0 = (u8 *)(((u8 *)((TUnk_804F0AF8 *)temp_r3)->init_fields(tl_05, arg0)));
        }
        return var_r0;
    }
    return NULL;
}

void TItemEffPG__begin_visual_fade(void* p) { *(s32*)((char*)p + 0x58) = 1; }

void TUnk_804F0BF0::render() {
    u8 *arg0 = (u8 *)this;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0 || find_equipped_item((int) (*(s32 *)((s8 *)arg0 + 0x1C))) == 0U) {
        return;
    }
    {
        if (((void *) this->m_20 != NULL) && (get_render_pass__9TMainTaskFv() == 1)) {
            set_depth_buffer_settings_id(3);
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            copy_argb((NJS_ARGB *)saved_model_draw_color, (NJS_ARGB *)model_material_color);
            model_render_flags |= 0x20;
            set_constant_material((const NJS_ARGB *)((arg0 + 0x28)));
            TParticleCtrl::begin_effect_render();
            TObjFish::set_global_param((int) (*(s32 *)((s8 *)arg0 + 0x24)));
            push_matrix();
            post_translate_matrix((u8 *)&this->unk_5C);
            push_matrix();
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x3C)));
            scale_current_matrix((u8 *)&this->m_48);
            draw_ginja_model((*(s32 *)(this->m_20 + 4)));
            pop_matrix();
            push_matrix();
            rotate_matrix_y(0, this->m_40);
            scale_current_matrix((u8 *)&this->m_48);
            draw_ginja_model((*(s32 *)((s8 *)(*(void **)(this->m_20 + 0x2C)) + 4)));
            pop_matrix();
            pop_matrix();
            TParticleCtrl::end_effect_render();
            copy_argb((NJS_ARGB *)model_material_color, (NJS_ARGB *)saved_model_draw_color);
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
            model_render_flags = saved_model_render_flags;
        }
    }
}

void TUnk_804F0BF0::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) + 0x71C);
    *(s32 *)((s8 *)arg0 + 0x40) = (s32) (*(s32 *)((s8 *)arg0 + 0x40) - 0xE38);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x58) == 0) {
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x50);
        if (temp_f1 < *(f32 *)((s8 *)arg0 + 0x44)) {
            *(f32 *)((s8 *)arg0 + 0x50) = (f32) (temp_f1 + *(f32 *)((s8 *)arg0 + 0x54));
            temp_f1_2 = *(f32 *)((s8 *)arg0 + 0x44);
            if (temp_f1_2 < *(f32 *)((s8 *)arg0 + 0x50)) {
                *(f32 *)((s8 *)arg0 + 0x50) = temp_f1_2;
            }
        }
        temp_f0 = *(f32 *)((s8 *)arg0 + 0x50);
        *(f32 *)((s8 *)arg0 + 0x4C) = temp_f0;
        *(f32 *)((s8 *)arg0 + 0x48) = temp_f0;
    } else {
        temp_f1_3 = *(f32 *)((s8 *)arg0 + 0x28);
        if (temp_f1_3 <= lbl_805DFE08) {
            queue_destruction__7TObjectFv(arg0);
            disallow_rendering__7TObjectFv((TObject *)arg0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x28) = (f32) (temp_f1_3 - lbl_805DFE0C);
        }
    }
    play_persistent_sound(0x4001A343, (s32)arg0, (u32)(arg0 + 0x5C), 0, 0);
}

}
TUnk_804F0BF0::~TUnk_804F0BF0() {
    if (this->m_38 != NULL) { queue_destruction__7TObjectFv(this->m_38); *(s32 *)((s8 *)this + 0x38) = 0; }
}


typedef char RecoveredGlobal_8034FCF0_lbl_804F0BF0_size[sizeof(RecoveredGlobal_8034FCF0_lbl_804F0BF0) == 0x18 ? 1 : -1];
u8 *TItemEffPG__visual_ct(u8 *arg0, u8 *arg1, u8 *arg2) {
    f32 temp_f1;
    __ct__7TObjectFP7TObject(arg0, arg1);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8034FCF0_lbl_804F0BF0 *)&__vt__13TUnk_804F0BF0).value;
    *(s32 *)((s8 *)arg0 + 0x1C) = (s32) *(s32 *)((s8 *)arg2 + 0x18);
    *(s32 *)((s8 *)arg0 + 0x20) = (s32) *(s32 *)((s8 *)arg2 + 0x34);
    *(s32 *)((s8 *)arg0 + 0x24) = (s32) *(s32 *)((s8 *)arg2 + 0x38);
    *(f32 *)((s8 *)arg0 + 0x54) = (f32) *(f32 *)((s8 *)arg2 + 0x30);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) *(f32 *)((s8 *)arg2 + 0x28);
    VecCopy((Vec *)(arg0 + 0x5C), (const Vec *)arg2);
    temp_f1 = *(f32 *)((s8 *)arg2 + 0xC);
    ((TUnk_804F0BF0 *)arg0)->m_50 = temp_f1;
    *(f32 *)((s8 *)arg0 + 0x4C) = temp_f1;
    ((TUnk_804F0BF0 *)arg0)->m_48 = temp_f1;
    *(s32 *)((s8 *)arg0 + 0x3C) = 0;
    ((TUnk_804F0BF0 *)arg0)->m_40 = 0;
    ((TUnk_804F0BF0 *)arg0)->m_28 = (f32) lbl_805DFE10;
    *(f32 *)((s8 *)arg0 + 0x2C) = (f32) lbl_805DFE10;
    ((TUnk_804F0BF0 *)arg0)->m_30 = (f32) lbl_805DFE10;
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) lbl_805DFE10;
    *(s32 *)((s8 *)arg0 + 0x38) = (s32)create_particle_emitter((arg0 + 0x5C), 0x83);
    ((TUnk_804F0BF0 *)arg0)->m_58 = 0;
    return arg0;
}

s32 TUnk_804F0C08::vfunc_7() {
    s32 temp_r4;

    temp_r4 = *(s32 *)((s8 *)this + 0xD4);
    if (temp_r4 > 0) {
        *(s32 *)((s8 *)this + 0xD4) = (temp_r4 - 1);
        return 1;
    }
    return 0;
}

extern s32 lbl_804F0C08[];

void *TUnk_804F0C08::destroy(s16 arg1) {
    if (this != NULL) {
        *(s32 **)((s8 *)this + 0x18) = lbl_804F0C08;
        __dt__10TItemEffPGFv(this, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

