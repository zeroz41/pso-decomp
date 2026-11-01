#ifndef PSO_MISC_TWINDOWSUBCOMCARD_80244774_H
#define PSO_MISC_TWINDOWSUBCOMCARD_80244774_H

#include "types.h"

struct TWindowSubComCard;
extern "C" {
int TWindowSubComCard__sub_80244774(void);
f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *arg0);
bool TWindowSubComCard__sub_80245558(s32 arg0, f32 *arg1, f32 *arg2);
void TWindowSubTradeMain__sub_802448E4(void *arg0);
}
void draw_selection_bar(u8 *arg0, u8 *arg1, s32 arg2);
void draw_window_scanlines(u8 *arg0, u8 *arg1);
extern "C" {
void fn_8024491C(void *arg0);
void fn_80244958(void *arg0);
void fn_802449E0(u8 *arg0);
}
bool is_balloon_overlapping(u8 *arg0, u8 *arg1, u8 *arg2);
void window_request_refresh(u8 *arg0);
void window_request_show(void *arg0);

#endif
