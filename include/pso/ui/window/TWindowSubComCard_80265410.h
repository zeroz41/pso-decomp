#ifndef PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H
#define PSO_UI_WINDOW_TWINDOWSUBCOMCARD_80265410_H

#include "types.h"
#include "pso/ui/window/WindowMenuFactory.h"

struct TWindowMenu;
extern "C" {
void TWindowSubComCard__sub_80265500(u8 *menu_window);
void TWindowSubComCard__sub_80265680(u8 *arg0, s16 arg1);
}
saddr create_titled_window_menu(saddr arg0, s32 arg1, saddr title, s32 client_id);
extern "C" {
saddr create_window_menu_default(saddr pos, s32 entries);
saddr create_titled_window_menu_default(saddr pos, s32 entries, saddr title);
u8 *create_yes_no_window(s32 position, s32 id, uaddr yes_text, uaddr no_text);
void fn_80266378(s32 arg0);
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
u8 *init_shop_judgment_window(void *p);
void render__11TWindowMenuFv(TWindowMenu *arg0);
}

#endif
