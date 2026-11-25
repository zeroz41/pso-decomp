#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/ControllerInputState.h"

#include "types.h"
#include "pso/system/ControllerInput.h"

// Window layout constants shared by the TWindowDD files (one definition here, extern elsewhere).
extern const f32 TWindowDD__data_805DFB18 = 0.00390625f;
extern const f32 lbl_805DFB1C = 16.0f;
extern const f32 window_dd_row_height = 20.0f; // inferred: word select rows scroll in steps of it
extern const f32 lbl_805DFB24 = 18.0f;
extern const f32 lbl_805DFB28 = 16.0f;
extern const f32 lbl_805DFB2C = 202.0f;
extern const f32 lbl_805DFB30 = 216.0f;
extern const f32 lbl_805DFB34 = 102.0f;
extern const f32 lbl_805DFB38 = 14.0f;
extern const f32 lbl_805DFB3C = 14.0f;
extern const f32 lbl_805DFB40 = 199.0f;
extern const f32 lbl_805DFB44 = 219.0f;
extern const f32 lbl_805DFB48 = 0.015625f;
extern const f32 lbl_805DFB4C = 18.0f;
extern const s32 window_dd_tween_ticks = 6; // inferred: tween_ticks given to every word select window
extern const f32 window_dd_visible_rows = 6.0f; // inferred: rows of a word page (TWindowDD_WS_Word::create)
extern const f32 window_dd_frame_margin = 4.0f; // inferred: inset of the text inside a word select frame
extern const f32 lbl_805DFB5C = 0.0f;
extern const f32 lbl_805DFB60 = -20.0f;
extern const f32 lbl_805DFB64 = 680.0f;
extern const f32 lbl_805DFB68 = 480.0f;
// inferred: word select page window placement and size.
extern const f32 word_page_x = 50.0f;
extern const f32 word_page_y = 310.0f;
extern const f32 word_page_width = 240.0f;
extern const f32 word_page_height = 120.0f;
extern const f32 lbl_805DFB7C = 480.0f;
extern const f32 lbl_805DFB80 = 370.0f;
extern const f32 lbl_805DFB84 = 310.0f;
extern const f32 lbl_805DFB88 = 240.0f;
extern const f32 lbl_805DFB8C = 120.0f;
extern const f32 lbl_805DFB90 = -260.0f;
extern const f32 lbl_805DFB94 = 660.0f;
extern const f32 lbl_805DFB98 = 310.0f;
extern const f32 lbl_805DFB9C = 240.0f;
extern const f32 lbl_805DFBA0 = 120.0f;
extern const f32 lbl_805DFBA4 = 50.0f;
extern const f32 lbl_805DFBA8 = 290.0f;
extern const f32 lbl_805DFBAC = 168.0f;
extern const f32 lbl_805DFBB0 = 370.0f;
extern const f32 lbl_805DFBB4 = 290.0f;
extern const f32 lbl_805DFBB8 = 166.0f;
extern const f32 lbl_805DFBBC = 18.0f;
extern const f32 lbl_805DFBC0 = 120.0f;
extern const f32 lbl_805DFBC4 = 32.0f;
extern const f32 lbl_805DFBC8 = 310.0f;
extern const f32 lbl_805DFBCC = 2.0f;
extern const f32 lbl_805DFBD0 = 70.0f;
extern const f32 lbl_805DFBD4 = 430.0f;
extern const f32 lbl_805DFBD8 = 120.0f;
extern const f32 lbl_805DFBDC = 30.0f;
extern const f32 lbl_805DFBE0 = 224.0f;
extern const f32 lbl_805DFBE4 = 240.0f;
extern const f32 lbl_805DFBE8 = 40.0f;
extern const f32 lbl_805DFBEC = 244.0f;
extern const f32 lbl_805DFBF0 = 30.0f;
extern const f32 lbl_805DFBF4 = 204.0f;
extern const f32 lbl_805DFBF8 = 30.0f;
extern const f32 TWindowDD__data_805DFBFC = 290.0f;
extern const f32 lbl_805DFC00 = 310.0f;
extern const f32 lbl_805DFC04 = 64.0f;
extern const f32 lbl_805DFC08 = 18.0f;
extern const f32 lbl_805DFC0C = 530.0f;
extern const f32 TWindowDD__data_805DFC10 = 594.0f;
extern const u32 TWindowDD__data_805DFC14 = 0xFFFFFFFF;
extern const u32 lbl_805DFC18 = 0xFF000000;
// inferred: sort depth of the word select page window.
extern const f32 word_page_depth = 50039.0f;
extern const f32 lbl_805DFC20 = 50038.0f;
extern const f32 lbl_805DFC24 = 50040.0f;
extern const f32 lbl_805DFC28 = 50037.0f;
extern const f32 lbl_805DFC2C = 50040.0f;


void reset_window_vertices(WindowVertex *p, f32 depth, s32) {
    s32 i;
    for (i = 0; i < 8; i++) {
        p->x = 0.0f;
        p->y = 0.0f;
        p->depth = depth;
        p->u = 0.0f;
        p->v = 0.0f;
        p->color = -1;
        p++;
    }
}

void fill_window_point_table(NJS_POINT2 *points, f32 x, f32 y, f32 width) {
  f32 inner_right_u;
  f32 inner_left;
  f32 inner_left_u;
  s8 *point_7;
  f32 right_u;
  f32 right;
  float right_scaled;
  f32 bottom_v;
  int offset_30;
  f32 top_v;
  f32 left_u;
  s8 *point_5;
  right = x + width;
  left_u = TWindowDD__data_805DFB18 * x;
  top_v = TWindowDD__data_805DFB18 * y;
  *((f32 *) (((s8 *) points) + 0)) = left_u;
  bottom_v = TWindowDD__data_805DFB18 * (window_dd_row_height + y);
  right_scaled = TWindowDD__data_805DFB18 * right;
  *((f32 *) (((s8 *) points) + 4)) = top_v;
  inner_left = 48.0f + x;
  right_u = right_scaled;
  *((f32 *) (((s8 *) points) + 8)) = left_u;
  inner_left_u = TWindowDD__data_805DFB18 * inner_left;
  *((f32 *) (((s8 *) points) + 0xC)) = bottom_v;
  inner_right_u = inner_left;
  inner_right_u = TWindowDD__data_805DFB18 * (inner_right_u - width);
  point_5 = ((s8 *) points) + 0x28;
  *((f32 *) (((s8 *) points) + 0x10)) = right_u;
  *((f32 *) (((s8 *) points) + 0x14)) = top_v;
  *((f32 *) (((s8 *) points) + 0x18)) = right_u;
  *((f32 *) (((s8 *) points) + 0x1C)) = bottom_v;
  *((f32 *) (((s8 *) points) + 0x20)) = inner_right_u;
  *((f32 *) (((s8 *) points) + 0x24)) = top_v;
  offset_30 = 0x30;
  *((f32 *) point_5) = inner_right_u;
  *((f32 *) (((s8 *) points) + 0x2C)) = bottom_v;
  *((f32 *) (((s8 *) points) + offset_30)) = inner_left_u;
  *((f32 *) (((s8 *) points) + 0x34)) = top_v;
  point_7 = ((s8 *) points) + 0x38;
  *((f32 *) point_7) = inner_left_u;
  *((f32 *) (((s8 *) points) + 0x3C)) = bottom_v;
}

#pragma push
#pragma opt_dead_assignments off
s32 TWindowDD::apply_both_choices(void *unused, saddr buttons) {
  return test_buttons_press_or_repeat(&controller_input_state.controllers[0], buttons, 6, 1) | test_buttons_press_or_repeat(&controller_input_state.keyboard, buttons, 6, 1);
}
#pragma pop

s32 TWindowDD_check_input_mask(void *input_context, s32 mask) {
  return test_pressed_buttons_packed(&controller_input_state.controllers[0], mask) | test_controller_flag_4c_color(&controller_input_state.keyboard, mask);
}
