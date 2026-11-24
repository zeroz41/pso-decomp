#ifndef PSO_UNK_TEXT_802D298C_H
#define PSO_UNK_TEXT_802D298C_H

#include "types.h"

u8 *get_trade_list_items(void);
u8 *get_trade_offer_items(void);
s32 clear_trade_message_controller_if_owner(uaddr window);
int set_trade_message_controller(saddr a0);
s32 release_trade_main_window(uaddr window);
s32 claim_trade_main_window(uaddr window);
s32 release_trade_sub_window(uaddr window);
s32 claim_trade_sub_window(uaddr window);
s32 *get_trade_window_state(void);

#endif
