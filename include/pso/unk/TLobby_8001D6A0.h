#ifndef PSO_UNK_TLOBBY_8001D6A0_H
#define PSO_UNK_TLOBBY_8001D6A0_H

#include "types.h"

struct player_stats;
struct AttackParams;
struct ActorParamBlock;
union BattleMovementParams;

extern "C" {
void TLobby__sub_8001DE30(void *a0);
}
void set_lobby_instance(s32 instance);
extern "C" {
void TLobby__sub_8001DF58(s32 lobby, saddr data);
}
AttackParams *get_battle_param_attack(int a0, int a1);
player_stats *get_battle_param_stats(int a0, int a1);
s32 parse_two_digit_number(void *text);
extern "C" {
void TLobby__sub_8001E998(f32 x, f32 position1Y, f32 size, f32 fade);
void TLobby__sub_8001EA5C(f32 x, f32 y, f32 size, f32 alpha);
void TLobby__sub_8001ED70(void);
void reset_clock_bar_pulse(void);
}
void alloc_battle_param_tables(void);
extern "C" {
void broadcast_to_players__6TLobbyFii(s32 lobby, saddr data);
void bswap__12player_statsFv(void *stats);
void copy_all_data__6TLobbyFii(s32 lobby, saddr data);
void copy_all_entries__6TLobbyFii(s32 lobby, saddr data);
}
s32 default_clock_offset_frames(void);
extern "C" {
s32 *get_shared_text_buffer(void);
u8 is_valid_player_index__6TLobbyFi(s32 index);
}
void load_battle_param_entry(void);
extern "C" {
void set_difficulty__6TLobbyFi(s32 variant);
}

#endif
