#ifndef PSO_UNK_TEXT_80222C28_H
#define PSO_UNK_TEXT_80222C28_H

#include "types.h"

const char *get_appraisal_text(s32 index);
const char *get_guild_text(s32 index);
const char *get_quest_list_text(s32 group, s32 index);
const char *get_shop_text(s32 index);

// The client's own slot when the screen is split, else slot 0.
u16 get_client_split_screen_slot(u16 client);

#endif
