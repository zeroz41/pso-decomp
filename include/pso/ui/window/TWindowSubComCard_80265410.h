#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H

#include "types.h"

struct TWindowMenu;
extern "C" {
u8 *TWindowMenu__ct(u8 *arg0, u32 arg1, s32 arg2, s32 arg3);
void TWindowSubComCard__sub_80265500(u8 *arg0);
void TWindowSubComCard__sub_80265680(u8 *arg0, s16 arg1);
void *__dt__11TWindowMenuFv(void *arg0, s16 arg1);
}
s32 create_titled_window_menu(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
u8 *create_yes_no_window(s32 arg0, s32 arg1, u32 arg2, u32 arg3);
void fn_80266378(s32 arg0);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 get_selected_entry__11TWindowMenuFv(u8 *arg0);
u8 *init_shop_judgment_window(void *p);
void render__11TWindowMenuFv(TWindowMenu *arg0);
}
void update_chat_window(void *p);

#endif
