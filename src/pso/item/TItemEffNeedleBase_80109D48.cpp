#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/item/TItemEffNeedleBase_80109D48.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/object/TObject_8001A448.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/item/TItem.h"
#include "pso/TItemEffNeedleBase.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

struct Needle_80109D48 {
    u8 pad0[0x1C];
    u8 m_1c[0x10];
    u8 m_2c[4];
    u8 m_30[0xC];
    void *m_3c;
    u32 m_40;
    u8 m_44[4];
};

extern "C" {
extern const f32 lbl_805DAB50;
extern const f32 lbl_805DAB54;
void rotate_matrix_by_node_angles(void *, s32);
void push_matrix();
void post_translate_matrix(void *);
extern u8 saved_model_draw_color[];
extern u8 model_material_color[];
extern u32 saved_model_render_flags;
extern u32 model_render_flags;
s32 __ct__7TObjectFP7TObject();

extern s32 __vt__18TItemEffNeedleBase[];
extern s32 TItemEffNeedleBase__class_name;
extern const f32 lbl_805DAB4C;

void TItemEffNeedleBase::render() {
    Needle_80109D48 *self = (Needle_80109D48 *)this;
    if (((TObject *)self)->all_parents_unqueued_for_destruction() == 0 ||
        find_equipped_item(*(int *)self->m_2c) == 0) {
        return;
    }
    if (self->m_3c != NULL) {
        saved_model_render_flags = model_render_flags;
        model_render_flags = saved_model_render_flags | 0x20;
        ((TRaderMapCore *)saved_model_draw_color)->copy_vec4(model_material_color);
        set_constant_material((const NJS_ARGB *)(((f32 *)self->m_1c)));
        TObjPlayer::notify_fish_if_valid(self->m_40);
        TParticleCtrl::begin_effect_render();
        push_matrix();
        post_translate_matrix(self->m_30);
        rotate_matrix_by_node_angles(self->m_44, 1);
        draw_ginja_object(self->m_3c);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
    }
}

void TItemEffNeedleBase::run_task() {
    u8 *arg0 = (u8 *)this;
    if (find_equipped_item((int) (*(s32 *)((s8 *)arg0 + 0x2C))) == 0U) {
        queue_destruction__7TObjectFv((arg0));
        disallow_rendering__7TObjectFv((TObject *)(arg0));
        return;
    }
    allow_rendering__7TObjectFv((TObject *)(arg0));
    if (this->vfunc_6() != 0) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) - lbl_805DAB50);
        if (*(f32 *)((s8 *)arg0 + 0x1C) <= lbl_805DAB54) {
            queue_destruction__7TObjectFv((arg0));
        }
    }
}

u8 *__ct__18TItemEffNeedleBaseFv(u8 *object, void *arg1, u8 *item) {

    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)object + 0x18) = __vt__18TItemEffNeedleBase;
    *(s32 *)((s8 *)object + 0) = (s32) TItemEffNeedleBase__class_name;
    *(s32 *)((s8 *)object + 0x2C) = ((TItem *)item)->get_item_id();
    *(s32 *)((s8 *)object + 0x48) = (((TItem *)item)->rotation_y);
    *(s32 *)((s8 *)object + 0x4C) = 0;
    *(s32 *)((s8 *)object + 0x44) = 0;
    *(s32 *)((s8 *)object + 0x3C) = 0;
    *(s32 *)((s8 *)object + 0x40) = 0;
    *(f32 *)((s8 *)object + 0x28) = (f32) lbl_805DAB4C;
    *(f32 *)((s8 *)object + 0x24) = (f32) lbl_805DAB4C;
    *(f32 *)((s8 *)object + 0x20) = (f32) lbl_805DAB4C;
    *(f32 *)((s8 *)object + 0x1C) = (f32) lbl_805DAB4C;
    disallow_rendering__7TObjectFv((TObject *)object);
    return object;
}

}
