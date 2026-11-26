#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80287570_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80287570_H

#include "types.h"

struct WindowDrawContext;

void draw_window_tab(WindowDrawContext *context, f32 *position, u8 style, f32 width);
f32 calc_title_overflow_width(f32 text_width);
struct HeadingEntry;
f32 get_heading_frame_width(HeadingEntry *heading);
void draw_heading_text(HeadingEntry *heading, WindowDrawContext *context);
void advance_heading_reveal(void *heading);
extern "C" {
u8 TWindowSubStatusDisp__sub_80287AC4(u8 *heading);
u8 *init_heading_entry__20TWindowSubStatusDispFPvPvici(u8 *window_sub_status_disp, u8 *position, saddr title, s8 entry_state, s32 client_id);
}

#endif
