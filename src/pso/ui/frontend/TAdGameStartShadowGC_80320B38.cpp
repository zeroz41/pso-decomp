#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/frontend/TAdGameStartShadowGC.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

struct Q_80320B38 { u8 b[0x20]; };

struct W_80320B38 { u8 pad[0x1C]; Q_80320B38 q[5]; s32 tex; };

extern s32 TAdGameStartShadowGC__texture_list;
void TAdGameStartShadowGC::sub_80320B38() {
    W_80320B38 *arg0 = (W_80320B38 *)this;
    u32 i;
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)((void *)TAdGameStartShadowGC__texture_list));
    set_draw_texture_and_color(0, arg0->tex);
    for (i = 0; i < 5; i++) {
        draw_textured_quad_at_depth((f32 *)&arg0->q[i], 0.74f);
    }
    TWindowSubStatusDisp::get_player();
}
