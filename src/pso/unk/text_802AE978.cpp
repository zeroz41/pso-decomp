#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"


void TAdSelectCurGC::draw_quads() {
    u32 i;
    for (i = 0; i < entry_count; i++) {
        begin_screen_draw(1);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(menu_selection_cursor_texture_list));
        set_draw_texture_and_color(0, (static_cast<u32>(entry_alpha[i]) << 24) | 0xFFFFFF);
        draw_textured_quad_at_depth(&quads[i].x0, draw_depth);
        draw_textured_quad_at_depth(&quads[i + 16].x0, draw_depth);
        draw_textured_quad_at_depth(&quads[i + 32].x0, draw_depth);
        TWindowSubStatusDisp::get_player();
    }
}
