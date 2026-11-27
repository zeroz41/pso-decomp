#include "types.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/quest/challenge/TChallenge.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TObjDeadListWin.h"
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/network/TLobby.h"
#include "pso/ui/chat/ChatLogText.h"
#include "pso/ui/chat/ChatLogLastLine.h"
#include "pso/object/TObjTombstone.h"
#include "pso/object/TObjChallengeRetry.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/PlayerSlots.h"
#include "libc/ctype.h"
#include "pso/network/LobbyName.h"

#pragma readonly_strings on

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

s32 is_challenge_mode() {
    return (u8)(challenge_task != NULL);
}

char *get_chat_last_line() {
    return chat_last_line_buffer;
}

char *get_lobby_name() {
    return lobby_name;
}

u32 to_upper_char(s32 c) {
    if (c == -1) {
        return -1U;
    }
    return __upper_map[(u8)c];
}

void disable_challenge_retry_menu() {
    if (is_challenge_mode() != 0) {
        challenge_mode_state.retry_menu_disabled = 1;
    }
}

void set_challenge_min_clear_time(s32 time) {
    if (is_challenge_mode() != 0) {
        if (time < 60 || time > 3600) {
            return;
        }
        challenge_mode_state.min_clear_time = encode_challenge_time(time);
    }
}

s32 is_challenge_boss_warp_disabled() {
    if (is_challenge_mode() == 0) {
        return 0;
    }
    if ((challenge_mode_state.boss_warp_disabled != 1) && (challenge_mode_state.boss_warp_disabled != 0)) {
        challenge_mode_state.boss_warp_disabled = 0;
    }
    return challenge_mode_state.boss_warp_disabled;
}

void set_challenge_boss_warp_disabled(s32 disabled) {
    if (is_challenge_mode() == 0) {
        challenge_mode_state.boss_warp_disabled = 0;
        return;
    }
    if ((disabled != 1) && (disabled != 0)) {
        disabled = 0;
    }
    challenge_mode_state.boss_warp_disabled = disabled;
}

void reset_challenge_map() {
    s32 i;
    TChallenge *task = challenge_task;

    if (task != NULL) {
        challenge_mode_state.base_time = 0;
        challenge_mode_state.failed = 0;
        challenge_mode_state.retry_choice = -1;
        challenge_mode_state.retry_confirmed = 0;
        challenge_mode_state.solo_play_notice_shown = 0;
        for (i = 0; i < 4; i++) {
            challenge_mode_state.client_died[i] = 0;
            challenge_mode_state.client_time_records[i] = 0;
        }
        task->frame_count = 0;
        challenge_task->missing_records_timer = 0;
        task = challenge_task;
        task->records_save_pending = 1;
        free_chat_last_line();
    }
}

void show_challenge_dead_player_list() {
    if ((is_challenge_mode() != 0) && (is_ready_to_draw() != 0) && (challenge_task != NULL)) {
        TObjDeadListWin::create(challenge_task);
    }
}

void create_challenge_retry_menu() {
    if ((is_challenge_mode() != 0) && (is_ready_to_draw() != 0) && (challenge_task != NULL)) {
        TObjChallengeRetry::create(challenge_task);
    }
}

s32 get_challenge_retry_choice() {
    s32 choice;

    choice = get_challenge_failure_choice();
    if (choice == 1) {
        choice = -1;
        if (challenge_mode_state.retry_confirmed != 0) {
            choice = 1;
        }
    }
    return choice;
}

s32 get_challenge_failure_choice() {
    if (challenge_mode_state.failed != 0) {
        return challenge_mode_state.retry_choice;
    }
    return 0;
}

// The shortest clear time any challenge allows, less one: below every valid time.
s32 challenge_time_limit_sentinel;
s8 challenge_time_limit_initialized;

s32 get_challenge_time_record() {
    s32 times[4];
    s32 i;
    s32 best;
    s32 time;

    for (i = 0; i < 4; i++) {
        times[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0) {
            s32 code = challenge_mode_state.client_time_records[i];
            if (code == 0) {
                return -1;
            }
            time = decode_challenge_time(code);
            if (is_challenge_time_invalid(time) != 0) {
                return -2;
            }
            times[i] = time;
        }
    }
    if (challenge_time_limit_initialized == 0) {
        challenge_time_limit_sentinel = challenge_min_clear_time() - 1;
        challenge_time_limit_initialized = 1;
    }
    best = challenge_time_limit_sentinel;
    for (i = 0; i < 4; i++) {
        if (times[i] != 0 && best < times[i]) {
            best = times[i];
        }
    }
    if (best == challenge_time_limit_sentinel) {
        return -2;
    }
    return best;
}

void set_challenge_time_record(s32 clear_time) {
    is_challenge_time_invalid(clear_time);
    fabs_float((f32)(clear_time - challenge_mode_state.base_time));
    send_challenge_time(clear_time);
}

s32 challenge_any_player_dead() {
    s32 i;
    TObjPlayer *player;

    if (challenge_task == NULL || challenge_task->state != 2) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        player = (TObjPlayer *)get_player_by_client_id(i);
        if ((player != NULL) && (player->check_player_state_flag_2() != 0)) {
            challenge_mode_state.failed = 1;
            return 1;
        }
    }
    return 0;
}

s32 challenge_all_players_dead() {
    s32 i;
    TObjPlayer *player;

    if (challenge_task == NULL || challenge_task->state != 2) {
        return 0;
    }
    for (i = 0; i < 4; i++) {
        player = (TObjPlayer *)get_player_by_client_id(i);
        if ((player != NULL) && (player->check_player_state_flag_2() == 0)) {
            return 0;
        }
    }
    challenge_mode_state.failed = 1;
    return 1;
}

void set_challenge_base_time(s32 time) {
    if (is_challenge_mode() != 0) {
        fabs_float((f32)(time - challenge_mode_state.base_time));
        challenge_mode_state.base_time = time;
        set_challenge_time_window_timer(time);
    }
}

s32 award_challenge_item(TItemData *item) {
    ChallengeRankThreshold *threshold;
    ChallengeRecord *record;
    ChallengeStageRank *rank;

    if ((challenge_mode_state.result_rank < 0) || (challenge_mode_state.result_rank > 2)) {
        return 0;
    }
    if (get_character_save_record(0xFFFF) == NULL) {
        return 0;
    }
    if (TAdSinglePlyChrSelectGC::forward_to_global_instance(item) != 0) {
        threshold = &challenge_mode_state.rank_thresholds[challenge_mode_state.result_rank];
        record = &(get_character_save_record(0xFFFF))->challenge;
        rank = challenge_set_rank(record, RECORD_SET_CURRENT);
        rank->award_flags |= threshold->award_flags;
        return 1;
    }
    return 0;
}

s32 check_challenge_rank_time(s32 clear_time) {
    s32 rank;

    if ((is_challenge_mode() == 0) || (challenge_mode_state.stage == -1) ||
        (get_character_save_record(0xFFFF) == NULL)) {
        challenge_mode_state.result_rank = -4;
        return -4;
    }
    fabs_float((f32)(clear_time - challenge_mode_state.base_time));
    if (is_challenge_time_invalid(clear_time) != 0) {
        clear_time = 35999;
    }
    rank = show_challenge_result(clear_time);
    if (rank == -1) {
        challenge_mode_state.result_rank = -1;
        return -1;
    }
    if (rank < 0) {
        challenge_mode_state.result_rank = -2;
        return -2;
    }
    if (count_free_inventory_slots() == 0) {
        challenge_mode_state.result_rank = -3;
        return -3;
    }
    challenge_mode_state.result_rank = rank;
    return rank;
}

s32 set_challenge_rank_threshold(s32 rank, s32 time, u32 award_flags) {
    s32 prev;
    ChallengeRankThreshold *threshold;
    ChallengeRankThreshold *p;
    ChallengeRankThreshold *end;

    if (rank < 0 || rank >= 3 || time < challenge_set_min_time(RECORD_SET_CURRENT)) {
        return 0;
    }
    if (rank == 0) {
        time = challenge_set_max_time(RECORD_SET_CURRENT);
    }
    threshold = &challenge_mode_state.rank_thresholds[rank];
    if (threshold->time != 0) {
        return 0;
    }
    threshold->time = time;
    threshold->award_flags = award_flags;
    prev = 0x7FFFFFFF;
    end = &challenge_mode_state.rank_thresholds[3];
    for (p = challenge_mode_state.rank_thresholds; p < end; p++) {
        s32 t = p->time;
        if (t != 0) {
            if (prev <= t) {
                return 0;
            }
            prev = t;
        }
    }
    return 1;
}

char challenge_rank_title[0xC];
char active_challenge_title[0xC];

char *decode_active_challenge_title() {
    CharacterSaveRecord *record;

    record = get_character_save_record(0xFFFF);
    decode_obfuscated_string(active_challenge_title, record->challenge.rank_title, 0xC);
    return active_challenge_title;
}

s32 add_challenge_rank_override(const char *match, const char *title, s32 color) {
    ChallengeRankOverride *entry;

    if ((is_challenge_mode() == 0) || (challenge_mode_state.rank_override_count < 0) ||
        (challenge_mode_state.rank_override_count >= 16)) {
        return 0;
    }
    entry = &challenge_mode_state.rank_overrides[challenge_mode_state.rank_override_count];
    encode_obfuscated_string(entry->match, match, 0xC);
    encode_obfuscated_string(entry->title, title, 0xC);
    entry->color = color;
    challenge_mode_state.rank_override_count++;
    return 1;
}

void set_challenge_rank_result(const char *title, s32 color) {
    encode_obfuscated_string(challenge_mode_state.rank_result_title, title, 0xC);
    challenge_mode_state.rank_result_color = color | 0xFF000000;
}

void set_challenge_stage(s32 stage) {
    s32 stage_count;

    stage_count = challenge_set_stage_count(RECORD_SET_CURRENT);
    if ((stage < 0) || (stage >= stage_count)) {
        stage = 0;
    }
    challenge_mode_state.stage = stage;
}

s32 count_free_inventory_slots() {
    s32 free;

    free = 30 - TAdSinglePlyChrSelectGC::get_char_index(0xFFFF)->m_inventory.m_num_items;
    if (free < 0) {
        free = 0;
    }
    return free;
}

s32 set_exp_multiplier(f32 multiplier) {
    if (is_challenge_mode() == 0) {
        return 0;
    }
    if ((multiplier < 0.01f) || (multiplier > 10000.0f)) {
        return 0;
    }
    challenge_mode_state.exp_multiplier = multiplier;
    return 1;
}

s32 set_challenge_difficulty(s32 difficulty) {
    if (is_challenge_mode() == 0) {
        return 0;
    }
    game_difficulty_selection = difficulty;
    return 1;
}

u32 argb_to_rgb555(u32 color) {
    return ((color >> 9) & 0x7C00) | ((color >> 6) & 0x3E0) | ((color >> 3) & 0x1F);
}

s32 rgb555_to_argb(s32 color) {
    return ((color * 8) & 0xF8) | (((color << 9) & 0xF80000) | 0xFF000000 | ((color << 6) & 0xF800));
}

s32 count_set_bits(u32 bits) {
    s32 count = 0;
    while (bits != 0) {
        if (bits & 1) {
            count++;
        }
        bits >>= 1;
    }
    return count;
}

s32 party_min_cleared_stages(s32 slot) {
    s32 fewest;
    s32 i;
    s32 cleared;

    fewest = challenge_set_stage_count(slot);
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0U) {
            if (challenge_mode_state.client_records[i].present == 0) {
                return -1;
            }
            cleared = client_cleared_stages(i, slot);
            if (fewest > cleared) {
                fewest = cleared;
            }
        }
    }
    return fewest;
}
