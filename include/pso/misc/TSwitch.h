#ifndef PSO_MISC_TSWITCH_H
#define PSO_MISC_TSWITCH_H

#include "types.h"

void clear_current_floor_switch(s32 id);
void clear_floor_switch_flag(u32 id, s16 floor);
void clear_switch_table(void);
u32 copy_switch_table(void *destination);
s32 get_floor_switch_flag(u32 id, s16 floor);
void init_switch_table(void);
extern "C" {
u8 is_current_floor_switch_set(s32 id);
}
u8 is_floor_switch_set(u32 id, s16 floor);
void restore_switch_table(s32 arg0, s32 arg1);
void set_current_floor_switch(s32 id);
void set_floor_switch_flag(u32 id, s16 floor);

#endif
