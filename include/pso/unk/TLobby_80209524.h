#ifndef PSO_UNK_TLOBBY_80209524_H
#define PSO_UNK_TLOBBY_80209524_H

#include "types.h"

struct EventShuffleTable;

struct ChallengeRandomEvent;

// --- C functions defined in TLobby_80209524.cpp ---
extern "C" {
EventShuffleTable *TLobby__sub_80209584(EventShuffleTable *table, s32 capacity);
void select_event_shuffle_table(s16 id);
void TLobby__sub_8020A2AC(void);
void bswap_event_table_entry(void *p);
void copy_event_table_entry(void *arg0, void *arg1);
void bswap_item_data_record(void *p);
void bswap_table_header(void *p);
void TLobby__sub_8020A618(ChallengeRandomEvent *dst, ChallengeRandomEvent *src);
void TLobby__sub_8020A6B0(s32 player);
s32 get_total_object_set_count(void);
s32 pick_random_slot__6TLobbyFPv(s16 *arg0);
}
// --- end of C functions

// Id counters of the map set loaders; TLobby::setup_quest_list resets them.
extern s32 map_set_object_id_counter;
extern s32 next_enemy_set_actor_id;
extern s32 map_object_id_counter;
extern s32 map_set_enemy_id_counter;
extern saddr item_drop_server_seed;


#endif
