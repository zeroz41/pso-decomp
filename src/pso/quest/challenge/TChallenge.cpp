#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/quest/TObjTagChallenge.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/object/TObjWarnChime.h"
#include "pso/network/client_id.h"
#include "pso/quest/challenge/ChallengeModeData.h"
#include "pso/ui/chat/ChatLogLastLine.h"
#include "pso/ui/frontend/TAdPlayerLoadGCMemCard.h"
#include "pso/system/task/TMainTask.h"
#include "pso/quest/challenge/ChallengeCommands.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TObjSoloPlayWin.h"
#include "pso/map/FloorArea.h"
#include "types.h"
#include "pso/player/PlayerSlots.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/quest/challenge/TChallenge.h"
#include <stddef.h>
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/ui/window/TObjBagWarnWin.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/object/TObjTombstone.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include <stdlib.h>
#include <string.h>
#include "pso/ui/window/ChallengeRank.h"
#include "pso/ui/window/TObjResultWin.h"
#include "pso/system/date.h"
#include "pso/system/vector.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/quest/challenge/ChallengeStageLoadouts.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/chat/ChatLogText.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/network/LobbyName.h"

extern const char TChallenge_name_text[] = "TChallenge";
const char *TChallenge::class_name = TChallenge_name_text;
static const char ellipsis[] = "... ";
static const s32 challenge_record_rank_slots[3] = { 0, 1, 2 };
static const s32 challenge_record_time_offsets[3] = { 0, 9, 14 };
static const s32 challenge_record_stage_counts[3] = { 9, 5, 9 };

s32 get_challenge_record_window_mode() {
    return challenge_mode_state.record_window_mode;
}

s32 run_challenge_frame() { return 1; }

ChallengeStageStart *get_challenge_stage_start(s32 class_type, s32 stage) {
    switch (class_type) {
    case 0:
        return &hunter_stage_start_parameters[stage];
    case 1:
        return &ranger_stage_start_parameters[stage];
    case 2:
        return &force_stage_start_parameters[stage];
    default:
        return &hunter_stage_start_parameters[stage];
    }
}

s32 current_challenge_stage() {
    s32 active = is_challenge_mode();
    s32 stage = -1;
    if (active) {
        stage = challenge_mode_state.stage;
    }
    return stage;
}


s32 challenge_set_max_time(s32 slot) {
    return challenge_set_stage_count(slot) * 0x8C9F;
}

s32 challenge_set_min_time(s32 slot) {
    return challenge_set_stage_count(slot) * 0x12C;
}


#pragma fp_contract on



s32 challenge_set_stage_count(s32 slot) {
    slot = resolve_challenge_record_set(slot);
    if (slot < 3) {
        return challenge_record_stage_counts[resolve_challenge_record_set(slot)];
    }
    return 5;
}

#pragma optimize_for_size off

s32 *challenge_set_stage_times(ChallengeRecord *record, s32 slot) {
    s32 idx = resolve_challenge_record_set(slot);
    if (idx < 3) {
        return &record->stage_times[challenge_record_time_offsets[idx]];
    }
    return record->ep2_split_stage_times;
}

ChallengeStageRank *challenge_set_rank(ChallengeRecord *record, s32 slot) {
    s32 idx = resolve_challenge_record_set(slot);
    if (idx < 3) {
        return &record->ranks[challenge_record_rank_slots[idx]];
    }
    return &record->ep2_split_rank;
}

s32 resolve_challenge_record_set(s32 slot) {
    switch (slot) {
    case RECORD_SET_CURRENT:
        if (is_split_screen()) {
            s32 inst = TLobby::get_instance();
            s32 r = RECORD_SET_EP1_SPLIT;
            if (inst == 1) {
                r = RECORD_SET_EP2_SPLIT;
            }
            return r;
        }
        return (TLobby::get_instance() == 1) ? RECORD_SET_EP2 : RECORD_SET_EP1;
    }
    return slot;
}

s32 challenge_client_died(s32 client) {
    if (is_challenge_mode() != 0) {
        return challenge_mode_state.client_died[client];
    }
    return 0;
}

s32 is_challenge_retry_menu_disabled() {
    if (is_challenge_mode() != 0) {
        return challenge_mode_state.retry_menu_disabled;
    }
    return 0;
}

#pragma optimize_for_size reset
#pragma fp_contract reset


s32 challenge_min_clear_time() {
    s32 time;

    if (is_challenge_mode() == 0) {
        return 300;
    }
    time = decode_challenge_time(challenge_mode_state.min_clear_time);
    if ((time < 60) || (time > 3600)) {
        time = 300;
    }
    return time;
}

void confirm_challenge_retry() {
    if (is_challenge_mode() != 0) {
        switch (challenge_mode_state.retry_confirmed) {
        case 0:
            challenge_mode_state.retry_confirmed = 1;
            break;
        }
    }
}

char area_title[0x20];

s32 is_challenge_time_invalid(s32 clear_time) {
    if ((clear_time < challenge_min_clear_time()) || (clear_time > 35999)) {
        return 1;
    }
    return 0;
}

s32 is_challenge_time_out_of_range(s32 time) {
    if ((time < 60) || (time > 35999)) {
        return 1;
    }
    return 0;
}

s32 challenge_rank_for_total(s32 total) {
    s32 min_total;
    s32 max_total;
    ChallengeStageRank *rank;
    s32 i;
    ChallengeRankThreshold *threshold;
    ChallengeRecord *record;

    min_total = challenge_set_min_time(RECORD_SET_CURRENT);
    max_total = challenge_set_max_time(RECORD_SET_CURRENT);
    if (get_character_save_record(0xFFFF) == NULL) {
        return -4;
    }
    if (total < min_total || total > max_total) {
        return -4;
    }
    record = &(get_character_save_record(0xFFFF))->challenge;
    rank = challenge_set_rank(record, RECORD_SET_CURRENT);
    for (i = 2, threshold = &challenge_mode_state.rank_thresholds[2]; i >= 0; i--, threshold--) {
        if (threshold->time != 0 && threshold->time >= total) {
            if (threshold->time < min_total || threshold->time > max_total) {
                return -4;
            }
            if ((rank->award_flags & threshold->award_flags) == 0) {
                break;
            }
        }
    }
    if (i < 0) {
        return -2;
    }
    return i;
}

void apply_challenge_rank_title() {
    char title[12];
    char match[12];
    CharacterSaveRecord *record;
    s32 i;
    ChallengeRankOverride *entry;

    record = get_character_save_record(0xFFFF);
    if (resolve_challenge_record_set(RECORD_SET_CURRENT) != 0) {
        return;
    }
    if (challenge_mode_state.rank_result_title[0] == 0) {
        return;
    }
    if (challenge_mode_state.rank_override_count > 0) {
        decode_obfuscated_string(title, record->challenge.rank_title, 12);
        for (i = 0; i < challenge_mode_state.rank_override_count; i++) {
            entry = &challenge_mode_state.rank_overrides[i];
            decode_obfuscated_string(match, entry->match, 12);
            if (strncmp(match, title, 12) == 0) {
                strncpy(record->challenge.rank_title, entry->title, 11);
                record->challenge.rank_title[11] = 0;
                record->challenge.title_color = argb_to_rgb555(entry->color);
                return;
            }
        }
    }
    strncpy(record->challenge.rank_title, challenge_mode_state.rank_result_title, 11);
    record->challenge.rank_title[11] = 0;
    record->challenge.title_color = argb_to_rgb555(challenge_mode_state.rank_result_color);
}

s32 record_challenge_stage_time(s32 clear_time) {
    s32 stage_count;
    s32 *times;
    s32 best;
    s32 improved;
    CharacterSaveRecord *record;

    record = get_character_save_record(0xFFFF);
    stage_count = challenge_set_stage_count(RECORD_SET_CURRENT);
    if ((record == NULL) || (challenge_mode_state.stage < 0) || (challenge_mode_state.stage >= stage_count)) {
        return 0;
    }
    times = challenge_set_stage_times(&record->challenge, RECORD_SET_CURRENT);
    improved = 0;
    const s32 stage = challenge_mode_state.stage;
    if (times[stage] == 0) {
        if (resolve_challenge_record_set(RECORD_SET_CURRENT) == 0) {
            apply_challenge_rank_title();
        }
        improved = 1;
    } else {
        best = decode_challenge_time(times[stage]);
        if (is_challenge_time_out_of_range(best) != 0) {
            times[stage] = 0;
            return 0;
        }
        if (clear_time < best) {
            improved = 1;
        }
    }
    if (improved == 0) {
        return 0;
    }
    times[stage] = encode_challenge_time(clear_time);
    return 1;
}

s32 show_challenge_result(s32 clear_time) {
    s32 next_rank;
    s32 rank;
    s32 total;
    ChallengeRecord *own;
    ChallengeRecord *client;
    ChallengeRecord *saved;
    ChallengeStageRank *stage_rank;
    s32 *best_time;
    s32 result;
    ChallengeResultRecord rec;

    rank = -4;
    record_challenge_stage_time(clear_time);
    total = get_challenge_set_time(0xFFFF, RECORD_SET_CURRENT);
    if (total != 0) {
        own = &(get_character_save_record(0xFFFF))->challenge;
        total -= decode_challenge_time(challenge_set_stage_times(own, RECORD_SET_CURRENT)[challenge_mode_state.stage]);
        total += clear_time;
        rank = challenge_rank_for_total(total);
        next_rank = rank + 1;
        stage_rank = challenge_set_rank(own, RECORD_SET_CURRENT);
        if (decode_challenge_count(stage_rank->rank) < next_rank) {
            stage_rank->rank = encode_challenge_value(next_rank);
        }
    }
    rec.summary.stage_index = challenge_mode_state.stage;
    rec.summary.reserved = 0;
    rec.summary.total_time = total;
    client = &challenge_mode_state.client_records[local_client_id].records;
    best_time = &challenge_set_stage_times(client, RECORD_SET_CURRENT)[challenge_mode_state.stage];
    stage_rank = challenge_set_rank(client, RECORD_SET_CURRENT);
    rec.previous.time = decode_challenge_time(*best_time);
    decode_obfuscated_string(rec.previous.award_name, client->rank_title, 12);
    rec.previous.rank = decode_challenge_count(stage_rank->rank);
    saved = &(get_character_save_record(0xFFFF))->challenge;
    stage_rank = challenge_set_rank(saved, RECORD_SET_CURRENT);
    rec.current.time = clear_time;
    decode_obfuscated_string(rec.current.award_name, saved->rank_title, 12);
    rec.current.rank = decode_challenge_count(stage_rank->rank);
    TObjResultWin::create(&rec);
    result = rank;
    if (total == 0) {
        result = -1;
    }
    return result;
}

void set_area_title(const char *title) {
    strncpy(area_title, title, 0x1F);
    area_title[0x1F] = 0;
}

void decode_obfuscated_string(char *dst, const void *src, int length) {
    u8 *out = (u8 *)dst;
    const u8 *in = (const u8 *)src;
    s32 n = length;
    u8 c;
    s32 i;
    if (n < 1) {
        n = 1;
    } else if (n > 0x20) {
        n = 0x20;
    }
    for (i = 0; i < n - 1; i++, in++, out++) {
        c = *in;
        if ((s8)c == 0) {
            *out = 0;
            return;
        }
        if (i == 0) {
            *out = c ^ 0x7F;
        } else {
            *out = out[-1] + (s8)(c ^ 0x7F);
        }
    }
    *out = 0;
}

void encode_obfuscated_string(char *dst, const char *src, s32 length) {
    u8 c;
    s32 i;
    if (length < 1) {
        length = 1;
    } else if (length > 0x20) {
        length = 0x20;
    }
    for (i = 0; i < length - 1; i++, src++, dst++) {
        c = *src;
        if ((s8)c == 0) {
            *dst = 0;
            return;
        }
        if (i == 0) {
            *dst = c ^ 0x7F;
        } else {
            *dst = (c - src[-1]) ^ 0x7F;
        }
    }
    *dst = 0;
}

s32 decode_challenge_time(s32 code) {
    s32 time;
    if (code == 0) {
        return 0;
    }
    time = decode_challenge_value(code);
    return is_challenge_time_out_of_range(time) ? 0 : time;
}

s32 encode_challenge_time(s32 time) {
    if ((time == 0) || (is_challenge_time_out_of_range(time) != 0)) {
        return 0;
    }
    return encode_challenge_value(time);
}

s32 decode_challenge_count(u32 code) {
    s32 count;

    count = decode_challenge_value(code);
    if (count < 0) {
        count = 0;
    }
    return count;
}

s32 decode_challenge_value(u32 code) {
    s32 bits;
    u32 key;

    key = code >> 16;
    bits = count_set_bits(key);
    if ((bits < 4) || (bits > 12)) {
        return -1;
    }
    return (u16)(key ^ code);
}

s32 encode_challenge_value(s32 value) {
    s32 key;

    key = random_challenge_key();
    return (key << 16) | (key ^ (value & 0xFFFF));
}

s32 random_challenge_key() {
    s32 bits;
    s32 key;
    s32 tries;

    tries = 0;
    do {
        key = (s32)(65535.0f * (3.0517578e-05f * (f32)rand())) & 0xFFFF;
        bits = count_set_bits(key);
        if ((bits >= 4) && (bits <= 12)) {
            break;
        }
        tries++;
        key = 0x3938;
    } while (tries < 8);
    return key;
}

void mark_solo_play_notice_shown() {
    if (is_challenge_mode() != 0) {
        challenge_mode_state.solo_play_notice_shown = 1;
    }
}

s32 count_challenge_players() {
    s32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0U) {
            count++;
        }
    }
    return count;
}

void split_challenge_time(s32 time, s32 *hours, s32 *minutes, s32 *seconds) {
    *hours = time / 3600;
    if (*hours > 99) {
        *hours = 99;
    }
    *minutes = (time / 60) % 60;
    *seconds = time % 60;
}

void TChallenge::update_card_save_info() {
    char line[0x60];
    char name[0x20];
    DateStamp date;
    CharacterSaveRecord *record;
    TObjPlayer *player;
    s32 year;
    s32 stamp;
    u8 day;
    u8 hour;
    u16 attacker;
    TObjEnemy *enemy;
    char *chat;
    char *unit_name;
    s32 rt_index;
    if (get_character_save_record(0xFFFF) == NULL) {
        return;
    }
    record = get_character_save_record(0xFFFF);
    player = static_cast<TObjPlayer *>(get_player_by_client_id(local_client_id));
    if (player == NULL) {
        return;
    }
    record->challenge.tombstone.phase = resolve_challenge_record_set(-1);
    record->challenge.tombstone.layout = challenge_mode_state.stage;
    record->challenge.tombstone.floor = get_current_floor();
    if (record->challenge.tombstone.deaths < 0) {
        record->challenge.tombstone.deaths = 9999;
    }
    if (++record->challenge.tombstone.deaths > 9999) {
        record->challenge.tombstone.deaths = 9999;
    }
    VecCopy((Vec *)&record->challenge.tombstone.position, (const Vec *)&player->position);
    getDateStamp(&date);
    if (date.year / 100 != 20) {
        stamp = 15;
    } else {
        year = date.year % 100;
        stamp = year;
        if (year > 15) {
            stamp = 15;
        }
    }
    stamp <<= 4;
    stamp |= date.month;
    stamp <<= 8;
    stamp |= (day = date.day);
    stamp <<= 8;
    stamp |= (hour = date.hour);
    stamp <<= 8;
    stamp |= date.minute;
    record->challenge.tombstone.date = stamp;
    strncpy(record->challenge.tombstone.display_name, get_lobby_name(), 0x13);
    record->challenge.tombstone.display_name[0x13] = 0;
    unit_name = record->challenge.tombstone.unit_name;
    record->challenge.tombstone.unit_name[0] = 0;
    chat = get_chat_last_line();
    if (chat != NULL) {
        strncpy(line, chat, 0x5F);
        line[0x5F] = 0;
        year = strlen(line);
        if (year != 0) {
            if (year <= 0x1F) {
                strncpy(name, line, 0x1F);
            } else {
                strncpy(name, ellipsis, 4);
                copy_clipped_text(name + 4, line, 0x1B);
            }
            name[0x1F] = 0;
            strcpy(unit_name, name);
        }
    }
    rt_index = -1;
    attacker = player->get_attacker_id();
    if ((attacker & 0xF000) == 0x1000) {
        enemy = static_cast<TObjEnemy *>(find_entity_by_id(attacker));
        if (enemy != NULL) {
            rt_index = enemy->rt_index;
        }
    }
    record->challenge.tombstone.rt_index = rt_index;
}

void spawn_challenge_tombstones() {
    saddr i;
    ChallengeClientRecords *rec;
    TObjTombstoneRecord *info;
    reset_tombstone_values();
    for (i = 0; i < 4; i++) {
        rec = &challenge_mode_state.client_records[i];
        if (rec->present != 0 && get_player_by_client_id(i) != NULL) {
            info = &rec->records.tombstone;
            if (info->deaths > 0 && info->phase == resolve_challenge_record_set(-1)
                && info->layout == challenge_mode_state.stage && static_cast<s8>(info->floor) == challenge_mode_state.current_floor) {
                TObjTombstone::create(tl_07, i, info);
            }
        }
    }
}




LAYOUT_ASSERT(TChallenge_state_offset, offsetof(TChallenge, state) == 0x1C);
LAYOUT_ASSERT(TChallenge_frame_offset, offsetof(TChallenge, frame_count) == 0x20);
LAYOUT_ASSERT(TChallenge_size, sizeof(TChallenge) == 0x30);

TChallenge *challenge_task;
s32 challenge_task_created;
s32 lobby_challenge_mode;

typedef void (TChallenge::*Step_80070674)(void);

ChallengeModeState challenge_settings_defaults = {
    -1, 1.0f, -1, 0, 0x39383814, -10, -1, 0, 0, -1,
};
ChallengeModeState challenge_mode_state = challenge_settings_defaults;




#pragma defer_codegen on

// The area title challenge mode opens with.
static const char challenge_start_area_title[] = "Area00";

void start_challenge_mode() {
    challenge_task_created = 0;
    if (challenge_task == NULL) {
        if (get_main_phase() != 0xF) {
            lobby_challenge_mode = 0;
            return;
        }
        start_lobby_name_request();
        if (lobby_challenge_mode != 0) {
            challenge_task = static_cast<TChallenge *>(TChallenge::create());
            challenge_task_created = 1;
            TObjTombstone::load_resources();
            set_area_title(challenge_start_area_title);
        }
    }
}

void *TChallenge::create() {
    return new TChallenge(tl_su);
}

TChallenge::TChallenge(TObject *parent) : TObject(parent) {
    m_name = class_name;
    challenge_mode_state = challenge_settings_defaults;
    restore_challenge_from_save();
    TLobby::send_challenge_records(this);
    frame_count = 0;
    missing_records_timer = 0;
    records_save_pending = 1;
    quest_send_timer = 0;
    state = 0;
}

TChallenge::~TChallenge() {
    TObjTombstone::destroy();
    clear_four_slots();
    challenge_mode_state = challenge_settings_defaults;
    challenge_task = NULL;
}

void TChallenge::run_task() {
    if (get_card_wait_state() == 1) {
        return;
    }
    request_missing_challenge_records();
    static Step_80070674 table[3] = {
        &TChallenge::initialize_windows,
        &TChallenge::wait_for_quest,
        &TChallenge::update_active,
    };
    Step_80070674 step = table[state];
    if (step) {
        (this->*step)();
    } else {
        return;
    }
    frame_count++;
}

void *challenge_mode_label_table[22] = {
    (void *)0x6368616c, (void *)0x6c656e67, (void *)0x65000000, (void *)0x53004300,
    (void *)0x51000000, (void *)&challenge_label_N, (void *)&challenge_label_C, (void *)&challenge_label_0,
    (void *)&challenge_label_1, (void *)&challenge_label_2, (void *)&challenge_label_3, (void *)&challenge_label_4,
    (void *)&challenge_label_5, (void *)&challenge_label_6, (void *)&challenge_label_7, (void *)&challenge_label_8,
    (void *)&challenge_label_E, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};

void TChallenge::initialize_windows() {
    s32 flag = 0;
    switch (get_main_phase()) {
    case 0xf:
        if (get_current_floor_area() != AREA_LOBBY) {
            flag = 1;
        }
        break;
    default:
        flag = 1;
        break;
    }
    if (flag != 0) {
        create_obj_tag_challenge(tl_07);
        TObjBagWarnWin::create(tl_07);
        state = 1;
    }
}

void TChallenge::wait_for_quest() {
    if (destroy_on_phase_change() == 0) {
        update_quest_challenge_state();
        if (is_quest_active() != 0) {
            ((s32)TAdSinglePlyChrSelectGC::init());
            clear_challenge_record_window();
            free_chat_last_line();
            TObjWarnChime::create(this);
            this->state = 2;
        }
    }
}

void TChallenge::update_active() {
    if (destroy_on_phase_change() == 0) {
        refresh_challenge_windows();
        update_battle_cleanup_flag();
    }
}

void TChallenge::render() {  }

s32 TChallenge::destroy_on_phase_change() {
    switch (get_main_phase()) {
    case 15:
        if (get_current_floor_area() == AREA_LOBBY) {
            queue_destruction();
            return 1;
        }
        break;
    case 14:
        queue_destruction();
        return 1;
    default:
        queue_destruction();
        return 1;
    }
    return 0;
}

void TChallenge::restore_challenge_from_save() {
    ChallengeClientRecords *own;
    clear_four_slots();
    own = &challenge_mode_state.client_records[local_client_id];
    if (get_character_save_record(0xFFFF) != NULL) {
        own->present = 1;
        own->records = get_character_save_record(0xFFFF)->challenge;
    }
}

void TChallenge::clear_four_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        challenge_mode_state.client_records[i].present = 0;
    }
}

void TChallenge::request_missing_challenge_records() {
    s32 found;
    s32 i;
    s32 *p;
    found = 0;
    for (i = 0; i < 4; i++) {
        if (i != local_client_id) {
            p = &challenge_mode_state.client_records[i].present;
            if (get_player_by_client_id(i) == NULL) {
                if (*p != 0) {
                    *p = 0;
                }
            } else if (*p == 0) {
                found = 1;
            }
        }
    }
    if (found != 0) {
        missing_records_timer++;
        if (missing_records_timer % 30 == 0) {
            send_6x7c_reset();
        }
    } else {
        missing_records_timer = 0;
    }
}

void TChallenge::refresh_challenge_windows() {
    s32 old;
    s32 v;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        old = challenge_mode_state.current_floor;
        challenge_mode_state.current_floor = -1;
        if (old != -1) {
            create_obj_tag_challenge(tl_07);
            if (challenge_mode_state.failed == 0) {
                create_ch_time_win(tl_07);
            }
        }
        break;
    case AREA_LOBBY:
        challenge_mode_state.current_floor = -1;
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        challenge_mode_state.current_floor = -1;
        break;
    default:
        v = get_current_floor();
        if (challenge_mode_state.current_floor != v) {
            challenge_mode_state.current_floor = v;
            create_time_window();
        }
        break;
    }
}

void TChallenge::update_quest_challenge_state() {
    s32 id;
    s32 n;

    n = 0;
    if (local_client_id == designated_client_id) {
        switch (TQuestListOnline::get_list_state()) {
        case 1:
            break;
        case 2:
            id = TLobby::get_selected_quest_id();
            n = 1;
            if (id >= 0x33 && id <= 0x3B) {
                n = id - 0x30;
            }
            break;
        case 3:
            id = TLobby::get_selected_quest_id();
            n = 2;
            if (id >= 0x3D && id <= 0x41) {
                n = id - 0x31;
            }
            break;
        }
        if (n == 0) {
            if (--quest_send_timer < 0) {
                quest_send_timer = 0;
            }
        } else {
            quest_send_timer = 30;
        }
        if ((quest_send_timer <= 0 || n != 0) && n != challenge_mode_state.record_window_mode) {
            TLobby::send_challenge_with_value(this, n);
        }
    }
}

void TChallenge::set_challenge_record_page(s32 mode) {
    if (mode < 0 || mode >= 0x11) {
        return;
    }
    if (challenge_mode_state.record_window_mode != mode) {
        show_challenge_record_window(mode);
        challenge_mode_state.record_window_mode = mode;
    }
}

void TChallenge::update_battle_cleanup_flag() {
    TObjPlayer *player = get_player_by_client_id(local_client_id);
    if (player == NULL) {
        records_save_pending = 0;
        return;
    }
    if (player->check_player_state_flag_2() != 0) {
        if (records_save_pending != 0 && challenge_mode_state.retry_menu_disabled == 0) {
            update_card_save_info();
            send_challenge_dead_flag(local_client_id);
            send_own_challenge_records();
        }
        records_save_pending = 0;
    }
}

void TChallenge::create_time_window() {
    spawn_challenge_tombstones();
    create_ch_time_win(tl_07);
    ((TLobby *)tl_07)->create_new_floor_windows();
    if (challenge_mode_state.solo_play_notice_shown == 0) {
        TObjSoloPlayWin::create((TObject*)tl_07);
    }
}