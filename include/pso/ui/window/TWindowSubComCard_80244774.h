#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80244774_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80244774_H

#include "types.h"

struct TWindowSubComCard;
struct WindowDrawContext;
class TWindowFukidasi;
extern "C" {
int TWindowSubComCard__sub_80244774(void);
f32 TWindowSubComCard__sub_80244784(TWindowSubComCard *window_sub_com_card);
bool TWindowSubComCard__sub_80245558(s32 ctx, f32 *arg1, f32 *arg2);
void TWindowSubTradeMain__sub_802448E4(void *arg0);
}
void draw_selection_bar(WindowDrawContext *context, u8 *entry, s32 active);
void draw_window_scanlines(u8 *card, u8 *arg1);
extern "C" {
void fn_8024491C(void *arg0);
void fn_80244958(void *arg0);
void fn_802449E0(u8 *object);
}
bool is_balloon_overlapping(u8 *arg0, u8 *arg1, u8 *arg2);
void window_request_refresh(u8 *help);
void window_request_show(void *object);

#endif
