#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025A9B4_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_8025A9B4_H

#include "types.h"

class WindowTextEntry;
struct TextLayoutRecord;

extern "C" {
void *TWindowSubStatusDisp__sub_8025AF0C(void *window_sub_status_disp, s16 arg1);
}
void advance_text_entry_reveal(WindowTextEntry *entry);
WindowTextEntry *construct_text_entry(WindowTextEntry *entry, TextLayoutRecord *rec, s32 client);
void set_text_entry_string(u8 *arg0, uaddr str, s32 arg2);

// --- C functions defined in TWindowSubStatusDisp_8025A9B4.cpp ---
extern "C" {
void *TWindowSubStatusDisp__sub_8025AF0C(void *window_sub_status_disp, s16 arg1);
}
// --- end of C functions

#endif
