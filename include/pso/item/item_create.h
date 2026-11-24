#ifndef PSO_ITEM_ITEM_CREATE_H
#define PSO_ITEM_ITEM_CREATE_H

#include "types.h"

void set_boss_buf_entry(int value, u16 index);
s32 get_item_data(u32 item);
void forward_message(saddr buf, uaddr item);
int get_drop_flag();
void handle_select_confirm();

#endif
