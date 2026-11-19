#include "types.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

void TAdSubPlyItemGC::render_status_line(f32 x, f32 y, f32 scale, const char *text, u32 color) {
    draw_menu_font_string(text, color, 0, x, y, scale);
}
