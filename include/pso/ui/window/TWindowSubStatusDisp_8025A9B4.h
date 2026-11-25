#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025A9B4_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025A9B4_H

#include "types.h"

extern "C" {
void *TWindowSubStatusDisp__sub_8025AF0C(void *window_sub_status_disp, s16 delete_flag);
}
void advance_text_entry_reveal(u8 *text_entry);
u8 *construct_text_entry(u8 *text_entry, u8 *rec, s32 client);
void set_text_entry_string(u8 *text_entry, uaddr str, s32 flags);

// --- C functions defined in TWindowSubStatusDisp_8025A9B4.cpp ---
extern "C" {
void *TWindowSubStatusDisp__sub_8025AF0C(void *window_sub_status_disp, s16 delete_flag);
}
// --- end of C functions

#endif
