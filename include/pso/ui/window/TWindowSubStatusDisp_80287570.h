#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80287570_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80287570_H

#include "types.h"

struct WindowDrawContext;

extern "C" {
void draw_window_tab(WindowDrawContext *context, f32 *position, u8 style, f32 width);
f32 TWindowSubStatusDisp__sub_80287570(void *heading);
f32 TWindowSubStatusDisp__sub_802877A4(f32 text_width);
struct HeadingEntry;
void TWindowSubStatusDisp__sub_802878B8(HeadingEntry *heading, WindowDrawContext *context);
void TWindowSubStatusDisp__sub_802879B0(void *heading);
u8 TWindowSubStatusDisp__sub_80287AC4(u8 *heading);
u8 *init_heading_entry__20TWindowSubStatusDispFPvPvici(u8 *window_sub_status_disp, u8 *position, saddr title, s8 entry_state, s32 client_id);
}

#endif
