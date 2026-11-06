#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/TAdSelectTxtSubGC.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

extern void *status_disp_texture_handle;

void TAdSelectTxtSubGC::render_status() {
    begin_screen_draw(1);
    TObjFish::set_global_param((s32)status_disp_texture_handle);
    set_draw_texture_and_color((s32)(*(void * *)&(*(s16 *)((u8 *)this + 0x20))), (s32)(*(void **)((s8 *)this + 0x80)));
    draw_textured_quad_at_depth((f32 *)((char *)this + 68), 0.25f);
    TWindowSubStatusDisp::get_player();
}
