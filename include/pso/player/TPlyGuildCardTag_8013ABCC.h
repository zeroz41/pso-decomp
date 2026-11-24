#ifndef PSO_PLAYER_TPLYGUILDCARDTAG_8013ABCC_H
#define PSO_PLAYER_TPLYGUILDCARDTAG_8013ABCC_H

#include "types.h"

struct gc_tag;

void copy_guild_card_tag_triplet(gc_tag *dst, gc_tag *src);
void set_quest_list_online_state(s32 state);
void set_item_drop_server_seed(int a0);

extern "C" {
void __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *to, void *from);
}

#endif
