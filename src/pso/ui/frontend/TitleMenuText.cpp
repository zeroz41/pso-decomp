#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/ui/frontend/TitleMenuText.h"
#include "pso/object/warp/TObjWarpString.h"

void draw_title_menu_text(s32 unused, u8 *position, s32 title, s32 color, saddr text) {
    draw_menu_text((f32)((f32) (*(f32 *)((s8 *)position + 0))), (f32)((f32) (*(f32 *)((s8 *)position + 4))), (const char *)text, color);
}
