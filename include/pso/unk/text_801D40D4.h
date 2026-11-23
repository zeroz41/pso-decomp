#ifndef PSO_UNK_TEXT_801D40D4_H
#define PSO_UNK_TEXT_801D40D4_H

#include "types.h"

class TPlyItem;
class TPlyInventoryItem;

extern "C" {
s32 fn_801D40D4(s32 count, const TPlyInventoryItem *source, TPlyInventoryItem *slots);
void TObjPlayer__sub_801D45B0(s32 *rec, saddr arg1);
s32 TObjPlayer__sub_801D47EC(TPlyItem *inventory, s32 first_key, s32 second_key);
s32 check_player_action_allowed(void);
s32 fn_801D4270(s32 id);
}
void remove_list_entry_by_id(s32 arg0);
extern "C" {
saddr reset(void *p);
}

#endif
