#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TItem.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/technique/TSlicerHistory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecSlicer.h"
#include "pso/system/task/TObject.h"

extern "C" {
extern const f32 lbl_805DC950;
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
typedef struct { f32 r, g, b, a; } Col_8023B220;
extern Col_8023B220 chunk_material_color_half_alpha_f32;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;

void TSlicerHistory::render() {
    u8 *arg0 = (u8 *)this;
    if (all_parents_unqueued_for_destruction__7TObjectFv() == 0 || find_equipped_item((int) (*(s32 *)((s8 *)arg0 + 0x58))) == 0U) {
        return;
    }
    {
        saved_model_render_flags = model_render_flags;
        Col_8023B220 col = *(Col_8023B220 *)((s8 *)arg0 + 0x3C);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x5C) != 0) {
            model_render_flags |= 0x10;
        } else {
            model_render_flags |= 0x20;
            col.r -= 1.0f;
        }
        if (((u32) *(u32 *)((s8 *)arg0 + 0x38) != 0U) && ((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U)) {
            set_texlist(*(u32 *)((s8 *)arg0 + 0x38));
            TParticleCtrl::begin_effect_render();
            push_matrix();
            post_translate_matrix(arg0 + 0x28);
            rotate_matrix_y(0, (int) (*(s32 *)((s8 *)arg0 + 0x20)));
            rotate_matrix_z(0, (int) (*(s32 *)((s8 *)arg0 + 0x24)));
            rotate_matrix_x(0, (int) (*(s32 *)((s8 *)arg0 + 0x1C)));
            scale_current_matrix(arg0 + 0x4C);
            set_constant_material((const NJS_ARGB *)(((f32 *)&col)));
            draw_ginja_object((void *)(*(u32 *)((s8 *)arg0 + 0x34)));
            set_constant_material((const NJS_ARGB *)(((f32 *)&chunk_material_color_half_alpha_f32)));
            TParticleCtrl::end_effect_render();
        }
        pop_matrix();
        model_render_flags = saved_model_render_flags;
    }
}

void TSlicerHistory::run_task() {
    u8 *arg0 = (u8 *)this;
  const f32 *new_var;
  *((f32 *) (((s8 *) arg0) + 0x3c)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x3c))) - 0.2f);
  if ((*((f32 *) (((s8 *) arg0) + 0x3c))) < (*(new_var = &lbl_805DC950)))
  {
    *((f32 *) (((s8 *) arg0) + 0x3c)) = (f32) (*new_var);
    ((TObject *)arg0)->queue_destruction();
  }
}

}

extern "C" {

s32 __ct__7TObjectFP7TObject();

extern s32 __vt__14TSlicerHistory[];
extern s32 TSlicerHistory__name;
extern const f32 lbl_805DC950;

u8 *__ct__14TSlicerHistoryFv(u8 *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    __ct__7TObjectFP7TObject();
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TSlicerHistory;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TSlicerHistory__name;
    copy_xyz(arg0 + 0x1C, (void *)(arg1 + 0x5C));
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)(arg1 + 0x38));
    *(s32 *)((s8 *)arg0 + 0x38) = arg2;
    if (arg3 != 0U) {
        *(s32 *)((s8 *)arg0 + 0x5C) = 1;
        copy_argb((NJS_ARGB *)(arg0 + 0x3C), (NJS_ARGB *)arg3);
    } else {
        *(s32 *)((s8 *)arg0 + 0x5C) = 0;
        *(f32 *)((s8 *)arg0 + 0x3C) = 1.0f;
        *(f32 *)((s8 *)arg0 + 0x40) = (f32) lbl_805DC950;
        *(f32 *)((s8 *)arg0 + 0x44) = (f32) lbl_805DC950;
        *(f32 *)((s8 *)arg0 + 0x48) = (f32) lbl_805DC950;
    }
    *(s32 *)((s8 *)arg0 + 0x34) = ((TTecSlicer *)arg1)->get_field_110();
    VecCopy((Vec *)(arg0 + 0x4C), (const Vec *)(arg1 + 0x68));
    *(s32 *)((s8 *)arg0 + 0x58) = arg4;
    return arg0;
}

}
