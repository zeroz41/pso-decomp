#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/unk/text_802A0A30.h"
#include "pso/object/warp/TObjWarpString.h"

void fn_802A0A30(s32 window, u8 *pos, s32 title, s32 color, saddr text) {
    draw_menu_text((f32)((f32) (*(f32 *)((s8 *)pos + 0))), (f32)((f32) (*(f32 *)((s8 *)pos + 4))), (const char *)text, color);
}
