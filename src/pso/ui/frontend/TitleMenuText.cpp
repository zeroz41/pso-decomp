#include "pso/ui/MenuText.h"
#include "types.h"
#include "pso/ui/frontend/TitleMenuText.h"
#include "pso/object/warp/TObjWarpString.h"

void draw_title_text(s32 unused, f32 *position, s32 title, s32 color, const char *text) {
    draw_menu_text(position[0], position[1], text, color);
}
