#include "types.h"
#include "pso/TAdGameStartLineGC.h"
#include "pso/object/TObjFish.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"

extern "C" {
extern void *lbl_805D6C18;
}

#pragma push
#pragma fp_contract on
void TAdGameStartLineGC::fn_80320DE8() {
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)lbl_805D6C18);
    set_draw_texture_and_color(0, m_158);
    for (u32 i = 0; i < 4; i++) {
        draw_textured_quad_at_depth(&cur[i].x0, 0.0001f * i + 0.795f);
    }
    TWindowSubStatusDisp::get_player();
}
#pragma pop
