#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/player/TObjPlayer_800EBE2C.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/enemy/TObjEneSlimeTailAttack.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEneSlimeOne.h"

struct Stack_800EBE74 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

extern "C" {
extern const f32 lbl_805DA6B4;
extern int saved_model_render_flags;
extern int saved_chunk_polygon_flags_and_mask;
extern int saved_chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_or_mask;
extern int chunk_polygon_flags_and_mask;
extern int model_render_flags;
extern const f32 lbl_805DA6F8;
s32 find_nearest_hittable_enemy__10TObjPlayerFiPvf(void *, int, f32);
void TObjPlayer::init_render_globals() { chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }

void TObjPlayer__sub_800EBE48(f32 farg0) {
    TObjPlayer::push_material_color_override(farg0, lbl_805DA6B4, lbl_805DA6B4, lbl_805DA6B4);
}

void TObjPlayer::push_material_color_override(f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    Stack_800EBE74 stack;
    (*(s32 *)&saved_model_render_flags) = (*(s32 *)&model_render_flags);
    (*(s32 *)&saved_chunk_polygon_flags_and_mask) = (*(s32 *)&chunk_polygon_flags_and_mask);
    (*(s32 *)&saved_chunk_polygon_flags_or_mask) = (*(s32 *)&chunk_polygon_flags_or_mask);
    (*(s32 *)&model_render_flags) |= 0x20;
    set_chunk_material_override_pair(0xFF00, 0x800);
    stack.spC = farg1;
    stack.sp10 = farg2;
    stack.sp8 = lbl_805DA6F8 + farg0;
    stack.sp14 = farg3;
    ((TUnk_80494AE0 *)(&stack.sp8))->set_chunk_material_color();
}
int TObjEneSlimeTailAttack::find_nearest_enemy_with_flag(f32 farg0) {
    u8 *arg0 = (u8 *)this;
    u16 temp_r3;
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) | 0x02000000);
    temp_r3 = find_nearest_hittable_enemy__10TObjPlayerFiPvf(arg0, 0, farg0);
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) & 0xFDFFFFFF);
    return temp_r3;
}

}
