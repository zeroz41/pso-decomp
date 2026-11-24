#ifndef PSO_QUEST_CHALLENGE_CHALLENGEMODE_H
#define PSO_QUEST_CHALLENGE_CHALLENGEMODE_H

#include "types.h"
#include "pso/quest/challenge/ChallengeModeState.h"

struct ChallengeStageStart;

// The challenge-mode session (challenge_mode_state) and the quest opcodes that drive it.

// The challenge record window's mode (ChallengeModeState::record_window_mode).
s32 get_challenge_record_window_mode();
// Called once per frame by both main loops; does nothing.
s32 run_challenge_frame();
// The starting level and kit of `stage` for a hunter (class_type 0), ranger (1) or force (2).
ChallengeStageStart *get_challenge_stage_start(s32 class_type, s32 stage);
// The current challenge stage, -1 outside challenge mode.
s32 current_challenge_stage();

// Times are stored encoded: the high half is a random key with 4..12 bits set, the low half
// the value xored with it.
s32 count_set_bits(u32 bits);
s32 random_challenge_key();
s32 encode_challenge_value(s32 value);
s32 decode_challenge_value(u32 code);
s32 decode_challenge_count(u32 code);
s32 is_challenge_time_out_of_range(s32 time);
s32 encode_challenge_time(s32 time);
s32 decode_challenge_time(s32 code);
// Splits a time in seconds into hours (at most 99), minutes and seconds.
void split_challenge_time(s32 time, s32 *hours, s32 *minutes, s32 *seconds);

// Obfuscated names: each byte is the difference to the previous character, xored with 0x7F.
void encode_obfuscated_string(char *dst, const char *src, s32 length);
// Decodes src into dst, at most length - 1 characters plus a terminator.
void decode_obfuscated_string(char *dst, const void *src, int length);

u32 argb_to_rgb555(u32 color);
s32 rgb555_to_argb(s32 color);

// The area title the set_area_title quest opcode shows.
extern char area_title[0x20];
void set_area_title(const char *title);

// Set from the lobby join packet: the lobby plays challenge mode.
extern s32 lobby_challenge_mode;
// Set when start_challenge_mode created challenge_task.
extern s32 challenge_task_created;

// Whether a challenge-mode game is running (challenge_task exists).
s32 is_challenge_mode();
// Creates challenge_task when the main phase is the challenge game.
void start_challenge_mode();
void reset_challenge_mode_state();
s32 count_challenge_players();
char *get_chat_last_line();
u32 to_upper_char(s32 c);

// Clear times.
s32 challenge_min_clear_time();
void set_challenge_min_clear_time(s32 time);
s32 is_challenge_time_invalid(s32 clear_time);
void set_challenge_base_time(s32 time);
s32 get_challenge_time_record();
void set_challenge_time_record(s32 clear_time);
// Sends this client's clear time to the others (subcommand 6x95).
void send_challenge_time(s32 clear_time);
s32 record_challenge_stage_time(s32 clear_time);

// Ranks and titles.
s32 challenge_rank_for_total(s32 total);
s32 show_challenge_result(s32 clear_time);
s32 check_challenge_rank_time(s32 clear_time);
s32 set_challenge_rank_threshold(s32 rank, s32 time, u32 award_flags);
s32 add_challenge_rank_override(const char *match, const char *title, s32 color);
void set_challenge_rank_result(const char *title, s32 color);
// The split-screen challenge's set_challenge_rank_result.
void set_challenge4p_rank_result(const char *title, s32 color);
void apply_challenge_rank_title();
// The challenge rank title of a character record, decoded for display.
extern char challenge_rank_title[0xC];
char *decode_active_challenge_title();
s32 award_challenge_item(int item);
s32 count_free_inventory_slots();

// Players dying, the retry menu and the boss warp.
s32 challenge_client_died(s32 client);
s32 challenge_any_player_dead();
s32 challenge_all_players_dead();
void show_challenge_dead_player_list();
void disable_challenge_retry_menu();
s32 is_challenge_retry_menu_disabled();
void create_challenge_retry_menu();
s32 get_challenge_failure_choice();
s32 get_challenge_retry_choice();
void confirm_challenge_retry();
s32 is_challenge_boss_warp_disabled();
void set_challenge_boss_warp_disabled(s32 disabled);
void mark_solo_play_notice_shown();
// Puts a tombstone where each present player last died on the current stage and floor.
void spawn_challenge_tombstones();

void reset_challenge_map();
void set_challenge_stage(s32 stage);
s32 set_exp_multiplier(f32 multiplier);
s32 set_challenge_difficulty(s32 difficulty);
// The stages of record set `slot` that client `client` has cleared, in order.
s32 client_cleared_stages(s32 client, s32 slot);
// The fewest stages of record set `slot` any present player has cleared.
s32 party_min_cleared_stages(s32 slot);

#endif
