#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/TAdScrollWinGC.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

extern s32 scroll_win_texture_handle;

void TAdScrollWinGC::render_status_value() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(scroll_win_texture_handle);
    set_draw_texture_and_color(0, ((this->m_3c << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x1C), 0.1f);
    TWindowSubStatusDisp::get_player();
}
