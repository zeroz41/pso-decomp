#include "types.h"
#include "pso/item/TItem.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/TSlicerHistory.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
extern const f32 lbl_805DC950;
extern const f32 lbl_805DC94C;
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
extern const f32 lbl_805DC948;

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
            col.r -= lbl_805DC948;
        }
        if (((u32) *(u32 *)((s8 *)arg0 + 0x38) != 0U) && ((u32) *(u32 *)((s8 *)arg0 + 0x34) != 0U)) {
            TObjPlayer::notify_fish_if_valid(*(u32 *)((s8 *)arg0 + 0x38));
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
  *((f32 *) (((s8 *) arg0) + 0x3c)) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x3c))) - lbl_805DC94C);
  if ((*((f32 *) (((s8 *) arg0) + 0x3c))) < (*(new_var = &lbl_805DC950)))
  {
    *((f32 *) (((s8 *) arg0) + 0x3c)) = (f32) (*new_var);
    queue_destruction__7TObjectFv(arg0);
  }
}

}
