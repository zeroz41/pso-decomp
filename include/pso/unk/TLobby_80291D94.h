#ifndef PSO_UNK_TLOBBY_80291D94_H
#define PSO_UNK_TLOBBY_80291D94_H

#include "types.h"

struct TLobby;
struct TItemData;
void challenge_set_min_clear_time(s32 v);
void challenge_set_boss_warp_disabled(s32 disabled);
s32 get_challenge4p_retry_choice(void);
s32 challenge_get_time_record(void);
void challenge_set_time_record(s32 seed);
extern "C" {
s32 challenge_set_rank_override(const char *match, const char *title, s32 color);
}
s32 challenge_check_rank_time(s32 seed, s32 card);
s32 challenge_set_rank_threshold(s32 idx, s32 value, s32 arg);
s32 challenge_create_reward_item(TItemData *item, u16 slot_index);
s32 challenge_check_any_player_dead(void);
s32 challenge_check_all_players_dead(void);
extern "C" {
s32 TLobby__sub_80292AB4(s32 total, u16 card, s32 slot);
s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id);
s32 TLobby__sub_80292DA0(s32 seed, u16 card);
}
s32 is_challenge_time_limit_invalid(s32 limit);
int get_camera_view_count(void);
void clear_challenge_and_split_screen_flags(void);
void load_tombstone_resources();
void save_challenge_tombstone_spot(s32 client);
s32 count_card_layout_entries(s32 client);
void enable_split_screen_challenge_mode(void);
s32 is_challenge_mode_active(void);
void setup_split_screen(void);

struct RebuildPlayersForStageHdr { u32 w[2]; };

struct RebuildPlayersForStageInfo { u8 pad0[0x31]; u8 cls; u8 pad32[2]; u32 flags; u8 pad38[0x50 - 0x38]; };

struct ByteBlock_690 { u8 bytes[0x690]; };

#endif
