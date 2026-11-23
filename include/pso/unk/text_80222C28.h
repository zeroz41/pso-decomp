#ifndef PSO_UNK_TEXT_80222C28_H
#define PSO_UNK_TEXT_80222C28_H

#include "types.h"

saddr get_appraisal_text(s32 index);
saddr get_guild_text(s32 index);
extern "C" {
saddr get_quest_list_text(s32 group, s32 index);
saddr get_shop_text(s32 index);
}

extern "C" {
u16 TShopGenerator__sub_80222DAC(u16 client);
}

#endif
