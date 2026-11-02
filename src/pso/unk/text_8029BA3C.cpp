#include "types.h"
#include "pso/TAdBackTxtGC.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"

extern "C" {
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(void *, f32, f32, f32);
void set_draw_texture_and_color(s32 idx, s32 arg1);
extern s32 TAdBackTxtGC__backtext_texture_list;
void TAdBackTxtGC::draw_character_background_frame(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
  f32 buffer_8[8];
  begin_screen_draw(1);
  TObjFish::set_global_param((s32)((void *) TAdBackTxtGC__backtext_texture_list));
  set_draw_texture_and_color(arg1, arg2);
  buffer_8[0] = 0.0f;
  buffer_8[1] = 0.0f;
  buffer_8[2] = 639.0f;
  buffer_8[3] = 479.0f;
  buffer_8[4] = 0.0f;
  buffer_8[5] = 0.0f;
  buffer_8[7] = (buffer_8[6] = 1.0f);
  draw_textured_quad_at_depth(&buffer_8[0], (f32) (*((f32 *) (((s8 *) arg0) + 0x20))), 639.0f, 0.0f);
  TWindowSubStatusDisp::get_player();
}

}
