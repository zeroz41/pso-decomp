#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/TObjEneDelDepth.h"

struct Stack_80315D60 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

extern const f32 TObjEneDelDepth__data_805DF258;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805DF2E0;
void TObjEneDelDepth::reset_globals() {
    model_render_flags &= 0xFFFF77DF;
    set_chunk_material_override_pair(0xFF00, 0);
    set_chunk_blend(0x2500);
    set_chunk_blend(0x2500);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}

    extern int TObjEneDelDepth__shared_resource;

void TObjEneDelDepth::setup_draw_material_default(f32 farg0) {
    TObjEneDelDepth::setup_draw_material(farg0, TObjEneDelDepth__data_805DF258, TObjEneDelDepth__data_805DF258, TObjEneDelDepth__data_805DF258);
}

void TObjEneDelDepth::setup_draw_material(f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    Stack_80315D60 stack;
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x8820;
    set_chunk_material_override_pair(0xFF00, 0x800);
    set_chunk_blend(0x2100);
    stack.spC = farg1;
    stack.sp10 = farg2;
    stack.sp8 = lbl_805DF2E0 + farg0;
    stack.sp14 = farg3;
    ((TUnk_80494AE0 *)(&stack.sp8))->set_chunk_material_color();
}

int TObjEneDelDepth::get_data() {  return TObjEneDelDepth__shared_resource; }
