#ifndef PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80257BC0_H
#define PSO_UI_WINDOW_TWINDOWSUBSTATUSDISP_80257BC0_H

#include "types.h"

extern "C" {
void TWindowSubStatusDisp__sub_80258A28(u8 *window_sub_status_disp, s32 arg1, s32 arg2);
void init_status_entry__20TWindowSubStatusDispFPvcUii(u8 *window_sub_status_disp, s8 arg1, u32 src, s32 arg3);
saddr replace_owned_string__20TWindowSubStatusDispFPviiii(void *window_sub_status_disp, saddr src, saddr buf, s32 mask, s32 copy);
void select_item_icon__20TWindowSubStatusDispFPviUcUci(void *arg0, s32 item_data, u8 arg2, u8 arg3, s32 arg4);
void update_stat_line__20TWindowSubStatusDispFPvi(void *window_sub_status_disp, s32 arg1);
void update_stat_line_if_positive__20TWindowSubStatusDispFPvi(void *arg0, s32 arg1);
}

#endif
