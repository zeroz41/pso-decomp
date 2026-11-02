#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/TAdGameStartShineGC.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

extern s32 lbl_805D6E88;

void TAdGameStartShineGC::render_status_box() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(lbl_805D6E88);
    set_draw_texture_and_color(0, ((*(s32 *)((s8 *)arg0 + 0x74) << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x54), 0.899f);
    TWindowSubStatusDisp::get_player();
}
