#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/unk/text_802A0A30.h"
#include "pso/object/warp/TObjWarpString.h"

void fn_802A0A30(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    draw_menu_text((f32)((f32) (*(f32 *)((s8 *)arg1 + 0))), (f32)((f32) (*(f32 *)((s8 *)arg1 + 4))), (const char *)arg4, arg3);
}
