#ifndef PSO_UI_COUNTERTEXTLOOKUP_H
#define PSO_UI_COUNTERTEXTLOOKUP_H

#include "types.h"

saddr get_appraisal_text(s32 index);
saddr get_guild_text(s32 index);
saddr get_quest_list_text(s32 group, s32 index);
saddr get_shop_text(s32 index);

// The client's own slot when the screen is split, else slot 0.
u16 get_client_split_screen_slot(u16 client);

#endif
