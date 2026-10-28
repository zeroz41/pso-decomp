#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TPlyPhotonChair_80142524.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_801424DC.h"

struct Stack_801424DC {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};

void fn_801424DC(s32 arg0, f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    Stack_801424DC stack;
    stack.sp8 = farg0;
    stack.spC = farg1;
    stack.sp10 = farg2;
    stack.sp14 = farg3;
    set_global_draw_flag_bits(arg0, 0x810);
    set_chunk_material_override_pair(-1, 0x800);
    set_constant_material((const NJS_ARGB *)((&stack.sp8)));
}
