#ifndef PSO_UNK_TLOBBY_8001D6A0_H
#define PSO_UNK_TLOBBY_8001D6A0_H

#include "types.h"

struct player_stats;
struct AttackParams;
struct ActorParamBlock;
union BattleMovementParams;

void set_enemy_movement_data(BattleMovementParams *params);
void set_enemy_resist_data(ActorParamBlock *params);
void set_enemy_attack_data(AttackParams *params);
void set_enemy_physical_data(player_stats *stats);
void set_override_enemy_bp_index(s32 index);
void set_battle_param_movement(s32 index, BattleMovementParams *src);
void set_battle_param_resistance(s32 index, ActorParamBlock *src);
void set_battle_param_attack(s32 index, AttackParams *src);
void set_battle_param_stats(s32 index, player_stats *src);
s32 is_valid_battle_param_index(s32 index);
BattleMovementParams *get_battle_param_movement(int difficulty, int index);
ActorParamBlock *get_battle_param_resistance(int difficulty, int index);
AttackParams *get_battle_param_attack(int difficulty, int index);
player_stats *get_battle_param_stats(int difficulty, int index);
void set_battle_param_episode(s32 episode);
s32 parse_two_digit_number(void *text);
// Draws the "ship:block-lobby" location text built by TLobby::close_result_windows.
void draw_lobby_location_text(f32 x, f32 y, f32 size, f32 alpha);
void draw_play_time_clock(f32 x, f32 y, f32 size, f32 alpha);
extern "C" {
void TLobby__sub_8001ED70(void);
void reset_clock_bar_pulse(void);
}
void alloc_battle_param_tables(void);
extern "C" {
void bswap__12player_statsFv(void *stats);
}
s32 default_clock_offset_frames(void);
extern "C" {
s32 *get_shared_text_buffer(void);
}
void load_battle_param_entry(void);

#endif
