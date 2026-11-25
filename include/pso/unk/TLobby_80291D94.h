#ifndef PSO_UNK_TLOBBY_80291D94_H
#define PSO_UNK_TLOBBY_80291D94_H

#include "types.h"

struct TLobby;
extern "C" {
void challenge_set_min_clear_time(s32 v);
void challenge_set_boss_warp_disabled(s32 arg0);
s32 TLobby__sub_80291F9C(void);
s32 challenge_get_time_record(void);
void challenge_set_time_record(s32 seed);
int challenge_set_rank_override(void);
s32 challenge_check_rank_time(s32 seed, s32 card);
s32 challenge_set_rank_threshold(s32 idx, s32 value, s32 arg);
s32 challenge_create_reward_item(s32 arg0, u16 slot_index);
s32 challenge_check_any_player_dead(void);
s32 challenge_check_all_players_dead(void);
s32 TLobby__sub_80292AB4(s32 total, u16 card, s32 slot);
s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id);
s32 TLobby__sub_80292DA0(s32 seed, u16 card);
s32 TLobby__sub_80292F34(s32 limit);
int get_camera_view_count(void *p);
void clear_challenge_and_split_screen_flags(void);
int load_tombstone_resources(void *p);
void TLobby__sub_80293218(s32 client);
s32 count_card_layout_entries(s32 client);
void enable_split_screen_challenge_mode(void);
s32 is_challenge_mode_active(void);
void set_split_screen_name__6TLobbyFv(s32 arg0);
}
void setup_split_screen(void);

#endif
