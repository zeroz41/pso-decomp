#include "pso/ui/window/WindowVertexBufferAbi.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/system/ControllerInputState.h"

#include "types.h"
#include "pso/system/ControllerInput.h"

// Window layout constants shared by the TWindowDD files (one definition here, extern elsewhere).
// inferred: names come from the fields, positions and texture coordinates the users give them.
extern const f32 window_dd_texel_scale = 0.00390625f;
extern const f32 window_dd_cap_width = 16.0f;
extern const f32 window_dd_row_height = 20.0f; // inferred: word select rows scroll in steps of it
extern const f32 scroll_bar_tile_width = 18.0f;
extern const f32 scroll_bar_tile_height = 16.0f;
extern const f32 scroll_arrow_up_u = 202.0f;
extern const f32 scroll_arrow_down_u = 216.0f;
extern const f32 scroll_arrow_v = 102.0f;
extern const f32 scroll_arrow_size = 14.0f;
extern const f32 scroll_arrow_texture_height = 14.0f;
extern const f32 word_row_strip_v = 199.0f;
extern const f32 word_row_strip2_v = 219.0f;
extern const f32 mode_texel_scale = 0.015625f;
extern const f32 mode_row_texture_height = 18.0f;
extern const s32 window_dd_tween_ticks = 6; // inferred: tween_ticks given to every word select window
extern const f32 window_dd_visible_rows = 6.0f; // inferred: rows of a word page (TWindowDD_WS_Word::create)
extern const f32 window_dd_frame_margin = 4.0f; // inferred: inset of the text inside a word select frame
extern const f32 window_dd_frame_margin_y = 0.0f;
extern const f32 word_label_hidden_x = -20.0f;
extern const f32 word_label_hidden_right_x = 680.0f;
extern const f32 word_prompt_hidden_y = 480.0f;
// inferred: word select page window placement and size.
extern const f32 word_page_x = 50.0f;
extern const f32 word_page_y = 310.0f;
extern const f32 word_page_width = 240.0f;
extern const f32 word_page_height = 120.0f;
extern const f32 wide_word_page_width = 480.0f;
extern const f32 next_word_page_x = 370.0f;
extern const f32 next_word_page_y = 310.0f;
extern const f32 next_word_page_width = 240.0f;
extern const f32 next_word_page_height = 120.0f;
extern const f32 word_page_exit_x = -260.0f;
extern const f32 last_word_page_x = 660.0f;
extern const f32 last_word_page_y = 310.0f;
extern const f32 last_word_page_width = 240.0f;
extern const f32 last_word_page_height = 120.0f;
extern const f32 word_page_label_x = 50.0f;
extern const f32 word_page_label_y = 290.0f;
extern const f32 word_page_label_width = 168.0f;
extern const f32 next_word_page_label_x = 370.0f;
extern const f32 next_word_page_label_y = 290.0f;
extern const f32 next_word_page_label_width = 166.0f;
extern const f32 scroll_bar_width = 18.0f;
extern const f32 scroll_bar_height = 120.0f;
extern const f32 scroll_bar_x = 32.0f;
extern const f32 scroll_bar_y = 310.0f;
extern const f32 scroll_arrow_margin = 2.0f;
extern const f32 word_prompt_x = 70.0f;
extern const f32 word_prompt_y = 430.0f;
extern const f32 word_prompt_width = 120.0f;
extern const f32 cursor_label_x = 30.0f;
extern const f32 cursor_label_y = 224.0f;
extern const f32 cursor_label_width = 240.0f;
extern const f32 cursor_label2_x = 40.0f;
extern const f32 cursor_label2_y = 244.0f;
extern const f32 message_label_x = 30.0f;
extern const f32 message_label_y = 204.0f;
extern const f32 message_label_width = 30.0f;
extern const f32 mode_window_x = 290.0f;
extern const f32 mode_window_y = 310.0f;
extern const f32 mode_window_placement_x = 64.0f;
extern const f32 mode_window_placement_y = 18.0f;
extern const f32 wide_mode_window_x = 530.0f;
extern const f32 wide_next_word_page_x = 594.0f;
extern const u32 window_dd_color_white = 0xFFFFFFFF;
extern const u32 window_dd_color_black = 0xFF000000;
// inferred: sort depth of the word select page window.
extern const f32 word_page_depth = 50039.0f;
extern const f32 word_label_depth = 50038.0f;
extern const f32 scroll_bar_depth = 50040.0f;
extern const f32 word_cursor_depth = 50037.0f;
extern const f32 mode_window_depth = 50040.0f;


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
  left_u = window_dd_texel_scale * x;
  top_v = window_dd_texel_scale * y;
  *((f32 *) (((s8 *) points) + 0)) = left_u;
  bottom_v = window_dd_texel_scale * (window_dd_row_height + y);
  right_scaled = window_dd_texel_scale * right;
  *((f32 *) (((s8 *) points) + 4)) = top_v;
  inner_left = 48.0f + x;
  right_u = right_scaled;
  *((f32 *) (((s8 *) points) + 8)) = left_u;
  inner_left_u = window_dd_texel_scale * inner_left;
  *((f32 *) (((s8 *) points) + 0xC)) = bottom_v;
  inner_right_u = inner_left;
  inner_right_u = window_dd_texel_scale * (inner_right_u - width);
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
