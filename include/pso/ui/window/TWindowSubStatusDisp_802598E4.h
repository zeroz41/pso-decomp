#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802598E4_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_802598E4_H

#include "types.h"

extern "C" {
void TWindowSubStatusDisp__sub_80259CE0(void);
void *TWindowSubStatusDisp__sub_80259CE4(void *arg0, s16 arg1);
u8 *TWindowSubStatusDisp__sub_80259D3C(u8 *arg0, u8 *arg1, s32 arg2);
void *TWindowSubStatusDisp__sub_8025A04C(void *arg0, s16 arg1);
void draw_right_aligned_number(void *arg0);
}
void render_numeric_digit_entries(u8 *arg0, u8 *arg1);
void set_status_entry_target(void *arg0, s32 arg1);

// --- C functions defined in TWindowSubStatusDisp_802598E4.cpp ---
extern "C" {
void TWindowSubStatusDisp__sub_80259CE0(void);
void *TWindowSubStatusDisp__sub_80259CE4(void *window_sub_status_disp, s16 arg1);
u8 *TWindowSubStatusDisp__sub_80259D3C(u8 *arg0, u8 *arg1, s32 arg2);
void *TWindowSubStatusDisp__sub_8025A04C(void *window_sub_status_disp, s16 arg1);
void draw_right_aligned_number(void *arg0);
}
// --- end of C functions

#endif
