#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/quest/challenge/ChallengeStageLoadouts.h"
#include "pso/object/quest/TObjTagChallenge.h"
#include <string.h>
#include "pso/ui/window/TObjCHTimeWin.h"
#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/object/TObjWarnChime.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/ChallengeRank.h"
#include "pso/ui/window/TObjSoloPlayWin.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/chat/ChatLogLastLine.h"
#include "pso/object/TObjChallenge4PRetry.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyCharData.h"
#include "pso/object/TObjTombstone.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/FloorArea.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_MemCard.h"
#include "pso/player/PlayerSlots.h"
#include "pso/ui/TLevelSelect.h"

ChallengeModeState challenge_default_settings = {
    -1, 1.0f, -1, 0, 0x39383814, -10, -1, 0, 0, -1,
};
ChallengeModeState challenge4p_mode_state = {0};
__declspec(section ".data") char the_best_text[] = "theBest";



void update_screen() { if (is_challenge_mode_active() != 0) { is_multi_ready(); } }
void set_challenge_split_flag() {
    if (is_challenge_mode_active() != 0) {
        challenge4p_mode_state.retry_menu_disabled = 1;
    }
}
void challenge_set_min_clear_time(s32 v) {
    if (is_challenge_mode_active() != 0) {
        if (v < 0x3c || v > 0xe10) {
            return;
        }
        challenge4p_mode_state.min_clear_time = encode_challenge_time(v);
    }
}

s32 get_normalized_mode() {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    if ((challenge4p_mode_state.boss_warp_disabled != 1) && (challenge4p_mode_state.boss_warp_disabled != 0)) {
        challenge4p_mode_state.boss_warp_disabled = 0;
    }
    return challenge4p_mode_state.boss_warp_disabled;
}
void challenge_set_boss_warp_disabled(s32 disabled) {
    s32 value;
    value = disabled;
    if (is_challenge_mode_active() == 0) {
        challenge4p_mode_state.boss_warp_disabled = 0;
        return;
    }
    if ((value != 1) && (value != 0)) {
        value = 0;
    }
    challenge4p_mode_state.boss_warp_disabled = value;
}






char split_screen_player_name[0x20];
// challenge_check_rank_time passes card unextended: it saw an int card, the definition takes u16.
s32 record_challenge_stage_clear(s32 seed, u16 card);
#define record_challenge_stage_clear ((s32 (*)(s32, s32))record_challenge_stage_clear)
void draw_if_ready2() {
    if ((is_challenge_mode_active() != 0) && (is_multi_ready() != 0) && (challenge_retry_object != NULL)) {
        TObjChallenge4PRetry::create(challenge_retry_object);
    }
}

s32 check_ready_status() {
    s32 status;

    status = get_challenge4p_retry_choice();
    if (status == 1) {
        status = -1;
        if (challenge4p_mode_state.retry_confirmed != 0) {
            status = 1;
        }
    }
    return status;
}

s32 get_challenge4p_retry_choice(void) {
    if (challenge4p_mode_state.failed != 0) {
        return challenge4p_mode_state.retry_choice;
    }
    return 0;
}

void reset_menu_state_globals() {
    s32 i;
    if (challenge_retry_object != NULL) {
        challenge4p_mode_state.base_time = 0;
        challenge4p_mode_state.failed = 0;
        challenge4p_mode_state.retry_choice = -1;
        challenge4p_mode_state.retry_confirmed = 0;
        challenge4p_mode_state.solo_play_notice_shown = 0;
        for (i = 0; i < 4; i++) {
            challenge4p_mode_state.client_died[i] = 0;
            challenge4p_mode_state.client_time_records[i] = 0;
        }
        challenge_retry_object->frame_count = 0;
        challenge_retry_object->missing_records_timer = 0;
        challenge_retry_object->records_save_pending = 1;
        free_chat_last_line();
    }
}

s32 challenge_get_time_record(void) {
    s32 arr[4];
    s32 i;
    s32 v;
    s32 best;
    for (i = 0; i < 4; i++) {
        arr[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != NULL) {
            v = challenge4p_mode_state.client_time_records[i];
            if (v == 0) {
                return -1;
            }
            v = decode_challenge_time(v);
            if (TLobby::is_value_out_of_range(v) != 0) {
                return -2;
            }
            arr[i] = v;
        }
    }
    static s32 time_limit_floor = TLobby::get_clamped_time_limit() - 1; // only card values above it count
    best = time_limit_floor;
    for (i = 0; i < 4; i++) {
        if (arr[i] != 0 && best < arr[i]) {
            best = arr[i];
        }
    }
    if (best == time_limit_floor) {
        return -2;
    }
    return best;
}
TChallenge4P *challenge_retry_object;
extern "C" {
s32 split_screen_challenge_created; // setup_split_screen sets it once it has created the TChallenge4P
s32 split_screen_flag;
s32 challenge_mode_active_flag;
}

void store_challenge_seeds(s32 seed) {
    s32 i;
    if (is_challenge_mode_active() != 0) {
        for (i = 0; i < 4; i++) {
            if (get_player_by_client_id(i) != NULL) {
                s32 v = encode_challenge_time(seed);
                if (TLobby::is_value_out_of_range(seed) != 0) {
                    v = encode_challenge_time(0x8C9F);
                }
                challenge4p_mode_state.client_time_records[i] = v;
            }
        }
    }
}

void challenge_set_time_record(s32 seed) {
    TLobby::is_value_out_of_range(seed);
    fabs_float((f32) (seed - challenge4p_mode_state.base_time));
    store_challenge_seeds(seed);
}
s32 challenge_set_rank_override(const char *match, const char *title, s32 color) { return 1; }


s32 challenge_check_rank_time(s32 seed, s32 card) {
    s32 r;
    if (is_challenge_mode_active() == 0 || challenge4p_mode_state.stage == -1 ||
        get_character_save_record((u16)card) == NULL) {
        challenge4p_mode_state.result_rank = -4;
        return -4;
    }
    fabs_float(seed - challenge4p_mode_state.base_time);
    if (TLobby::is_value_out_of_range(seed) != 0) {
        seed = 0x8C9F;
    }
    r = record_challenge_stage_clear(seed, card);
    if (r == -1) {
        challenge4p_mode_state.result_rank = -1;
        return -1;
    }
    if (r < 0) {
        challenge4p_mode_state.result_rank = -2;
        return -2;
    }
    CharacterSaveRecord *record = get_character_save_record((u16)card);
    if (record != 0 && record->is_bank_full() != 0) {
        challenge4p_mode_state.result_rank = -3;
        return -3;
    }
    challenge4p_mode_state.result_rank = r;
    return r;
}
#undef record_challenge_stage_clear

s32 challenge_set_rank_threshold(s32 idx, s32 value, s32 arg) {
    s32 prev;
    ChallengeRankThreshold *e;
    ChallengeRankThreshold *p;
    ChallengeRankThreshold *end;
    if (idx < 0 || idx >= 3 || value < challenge_set_min_time(-1)) {
        return 0;
    }
    if (idx == 0) {
        value = challenge_set_max_time(-1);
    }
    e = &challenge4p_mode_state.rank_thresholds[idx];
    if (e->time != 0) {
        return 0;
    }
    e->time = value;
    e->award_flags = arg;
    prev = 0x7FFFFFFF;
    end = &challenge4p_mode_state.rank_thresholds[3];
    for (p = challenge4p_mode_state.rank_thresholds; p < end; p++) {
        s32 v = p->time;
        if (v != 0) {
            if (prev <= v) {
                return 0;
            }
            prev = v;
        }
    }
    return 1;
}

s32 challenge_create_reward_item(TItemData *item, u16 slot_index) {
    CharacterSaveRecord *record;
    ChallengeRankThreshold *threshold;
    s32 set;
    if ((challenge4p_mode_state.result_rank < 0) || (challenge4p_mode_state.result_rank > 2)) {
        return 0;
    }
    record = get_character_save_record(slot_index);
    if (record == NULL) {
        return 0;
    }
    if (record->register_in_free_room_slot(item) != 0) {
        threshold = &challenge4p_mode_state.rank_thresholds[challenge4p_mode_state.result_rank];
        set = resolve_challenge_record_set(-1);
        challenge_set_rank(&record->challenge, set)->award_flags |= threshold->award_flags;
        return 1;
    }
    return 0;
}
void set_challenge4p_rank_result(const char *title, s32 color) {
    encode_obfuscated_string(challenge4p_mode_state.rank_result_title, title, 0xC);
    challenge4p_mode_state.rank_result_color = color | 0xFF000000;
}
void set_split_screen_name(const char *name) {
    strncpy(split_screen_player_name, name, 0x20);
    split_screen_player_name[0x1F] = 0;
}
void update_challenge_timer(s32 time) {
    if (is_challenge_mode_active() != 0) {
        fabs_float((f32) (time - challenge4p_mode_state.base_time));
        challenge4p_mode_state.base_time = time;
        set_challenge_time_window_timer(time);
    }
}





extern "C" {
void copy_player_visual_record(void *, void *);


}
s32 set_camera_height_if_valid(f32 multiplier) {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    if ((multiplier < 0.01f) || (multiplier > 10000.0f)) {
        return 0;
    }
    challenge4p_mode_state.exp_multiplier = multiplier;
    return 1;
}

s32 try_set_split_screen(s32 difficulty) {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    game_difficulty_selection = difficulty;
    return 1;
}
void rebuild_players_for_stage(s32 stage) {
    RebuildPlayersForStageInfo info;
    Vec pos;
    s32 i;
    TObjPlayer *p;
    ChallengeStageStart *tbl;
    s32 map;
    ChallengeTechniqueLevel *e;
    if (stage < 0 || stage >= 0x10) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        PlayerGuildCardTag hdr;
        if (p != NULL) {
            VecCopy(&pos, &p->position);
            copy_player_visual_record(&info, &p->appearance);
            hdr.copy_from(&p->guild_card_tag);
            map = (p)->get_controller_port();
            delete p;
            switch (info.flags & 0xE0) {
            case 0x20:
                tbl = get_challenge_stage_start(0, stage);
                break;
            case 0x40:
                tbl = get_challenge_stage_start(1, stage);
                break;
            case 0x80:
                tbl = get_challenge_stage_start(2, stage);
                break;
            default:
                tbl = get_challenge_stage_start(0, stage);
                break;
            }
            {
                TPlyCharData cd;
                copy_player_visual_record(&cd.m_disp_part2, &info);
                TObjPlayer::begin_action_state(&cd);
                TNpcPlayer::send_command(info.cls, tbl->item_count, tbl->items, tbl->level, &cd);
                p = create_player_object(i, map, &cd);
                if (p == NULL) {
                    return;
                }
            }
            p->guild_card_tag.copy_from(&hdr);
            p->set_position_from(&pos);
            p->save_previous_position();
            p->reset_motion_fields();
            p->technique_state.set_all_technique_levels(0xFF);
            if (tbl->techniques != NULL) {
                for (e = tbl->techniques; e->level != 0xFF; e++) {
                    TObjPlayer::set_technique_level_clamped(p, e->level, e->technique);
                }
            }
            p->base_stats.meseta = 0;
        }
    }
}


void save_challenge_tombstone_spot(s32);
s32 challenge_check_any_player_dead(void);
s32 challenge_check_all_players_dead(void);
s32 is_challenge_time_limit_invalid(s32 limit);

void clamp_and_store_layout_index(s32 stage) {
    s32 layout_id;
    s32 index;

    index = stage;
    layout_id = challenge_set_stage_count(-1);
    if ((index < 0) || (index >= layout_id)) {
        index = 0;
    }
    challenge4p_mode_state.stage = index;
}

s32 challenge_check_any_player_dead(void) {
    s32 found;
    u32 i;
    TObjPlayer *player;
    if (challenge_retry_object == NULL) {
        return 0;
    }
    found = 0;
    i = 0;
    do {
        player = get_player_by_client_id(i);
        if ((player != NULL) && (((int)player->check_player_state_flag_2()) != 0)) {
            save_challenge_tombstone_spot((s32) i);
            found = 1;
        }
        i += 1;
    } while ((s32) i < 4);
    if (found != 0) {
        challenge4p_mode_state.failed = 1;
        return 1;
    }
    return 0;
}
s32 challenge_check_all_players_dead(void) {
    s32 i;
    TObjPlayer *player;
    if (challenge_retry_object == NULL) {
        return 0;
    }
    i = 0;
    do {
        player = get_player_by_client_id(i);
        if ((player != NULL) && (((int)player->check_player_state_flag_2()) == 0)) {
            return 0;
        }
        i += 1;
    } while (i < 4);
    challenge4p_mode_state.failed = 1;
    return 1;
}

s32 get_challenge_award_rank(s32 total, u16 card, s32 slot) {
    s32 lo;
    s32 hi;
    ChallengeStageRank *rank;
    s32 i;
    ChallengeRankThreshold *e;
    ChallengeRecord *record;
    lo = challenge_set_min_time(slot);
    hi = challenge_set_max_time(slot);
    if (get_character_save_record(card) == NULL) {
        return -4;
    }
    if (total < lo || total > hi) {
        return -4;
    }
    record = &(get_character_save_record(card))->challenge;
    rank = challenge_set_rank(record, slot);
    e = &challenge4p_mode_state.rank_thresholds[2];
    for (i = 2; i >= 0; i--, e--) {
        if (e->time != 0 && e->time >= total) {
            if (e->time < lo || e->time > hi) {
                return -4;
            }
            if ((rank->award_flags & e->award_flags) == 0) {
                break;
            }
        }
    }
    if (i < 0) {
        return -2;
    }
    return i;
}

s32 record_challenge_stage_time(s32 seed, u16 card, s32 id) {
    CharacterSaveRecord *win = get_character_save_record(card);
    s32 layout = challenge_set_stage_count(id);
    s32 *arr;
    s32 idx;
    s32 limit;
    s32 ok;
    if (win == NULL || challenge4p_mode_state.stage < 0 || challenge4p_mode_state.stage >= layout) {
        return 0;
    }
    arr = challenge_set_stage_times(&win->challenge, id);
    ok = 0;
    idx = challenge4p_mode_state.stage * 4;
    if (*(s32 *)((u8 *)arr + idx) == 0) {
        ok = 1;
    } else {
        limit = decode_challenge_time(*(s32 *)((u8 *)arr + idx));
        if (is_challenge_time_limit_invalid(limit) != 0) {
            *(s32 *)((u8 *)arr + idx) = 0;
            return 0;
        }
        if (seed < limit) {
            ok = 1;
        }
    }
    if (ok == 0) {
        return 0;
    }
    *(s32 *)((u8 *)arr + idx) = encode_challenge_time(seed);
    return 1;
}

s32 count_card_layout_entries(s32 client) {
    CharacterSaveRecord *win = get_character_save_record(client);
    s32 layout;
    s32 id;
    s32 *arr;
    s32 n;
    s32 i;
    if (win == NULL) {
        return 0;
    }
    id = resolve_challenge_record_set(-1);
    arr = challenge_set_stage_times(&win->challenge, id);
    layout = challenge_set_stage_count(id);
    n = 0;
    for (i = 0; i < layout; i++) {
        if (arr[i] == 0) {
            break;
        }
        n++;
    }
    return n;
}



s32 calc_min_challenge_progress() {
    s32 progress;
    s32 min_progress;
    s32 i;

    min_progress = challenge_set_stage_count(resolve_challenge_record_set(-1));
    i = 0;
    do {
        if (get_player_by_client_id(i) != NULL) {
            progress = count_card_layout_entries(i);
            if (min_progress > progress) {
                min_progress = progress;
            }
        }
        i += 1;
    } while (i < 4);
    return min_progress;
}
s32 record_challenge_stage_clear(s32 seed, u16 card) {
    s32 result;
    s32 total;
    s32 id;
    ChallengeRecord *record;
    s32 next;
    ChallengeStageRank *e;
    id = resolve_challenge_record_set(RECORD_SET_CURRENT);
    result = -4;
    record_challenge_stage_time(seed, card, id);
    total = get_challenge_set_time(card, id);
    if (total != 0) {
        record = &(get_character_save_record(card))->challenge;
        total -= decode_challenge_time(challenge_set_stage_times(record, id)[challenge4p_mode_state.stage]);
        total += seed;
        result = get_challenge_award_rank(total, card, id);
        next = result + 1;
        e = challenge_set_rank(record, id);
        if ((s32)decode_challenge_count((u32)(e->rank)) < next) {
            e->rank = encode_challenge_value(next);
        }
    }
    {
        s32 r = result;
        if (total == 0) {
            r = -1;
        }
        return r;
    }
}



s32 TLobby::get_clamped_time_limit() {
    s32 valid_slot;

    if (is_challenge_mode_active() == 0) {
        return 0x12C;
    }
    valid_slot = decode_challenge_time(challenge4p_mode_state.min_clear_time);
    if ((valid_slot < 0x3C) || (valid_slot > 0xE10)) {
        valid_slot = 0x12C;
    }
    return valid_slot;
}




s32 TLobby::is_value_out_of_range(s32 seed) {
    if ((seed < TLobby::get_clamped_time_limit()) || (seed > 0x8C9F)) {
        return 1;
    }
    return 0;
}
s32 is_challenge_time_limit_invalid(s32 limit) {
    if ((limit < 0x3C) || (limit > 0x8C9F)) {
        return 1;
    }
    return 0;
}
int get_camera_view_count(void) { return TCameraCtrl::get_view_count(); }
#pragma push
#pragma fp_contract on
s32 get_challenge_mode_flag() {
    if (is_challenge_mode_active() != 0) {
        return challenge4p_mode_state.retry_menu_disabled;
    }
    return 0;
}
#pragma pop

void start_challenge_countdown() {
    if (is_challenge_mode_active() != 0) {
        switch (challenge4p_mode_state.retry_confirmed) {
        case 0:
            challenge4p_mode_state.retry_confirmed = 1;
            break;
        }
    }
}


void set_retry_selection(s32 choice) {
    s32 selection;

    selection = choice;
    if (is_challenge_mode_active() != 0) {
        if ((selection < 0) || (selection > 1)) {
            selection = 0;
        }
        challenge4p_mode_state.retry_choice = selection;
    }
}

void destroy_global() {
    if (challenge_retry_object != NULL) {
        challenge_retry_object->queue_destruction();
    }
}

s32 is_challenge_mode_active(void) {
    if ((challenge_mode_active_flag == 1) || (challenge_retry_object != NULL)) {
        return 1;
    }
    return 0;
}


void clear_challenge_and_split_screen_flags(void) { challenge_mode_active_flag = 0; split_screen_flag = 0; }

void enable_split_screen_challenge_mode(void) { challenge_mode_active_flag = 1; split_screen_flag = 1; }

const char *challenge4p_class_name = "TChallenge4P";

TChallenge4P *TChallenge4P::create() {
    return new TChallenge4P(tl_su);
}

void destroy_tombstone() { TObjTombstone::destroy(); }
void load_tombstone_resources() { TObjTombstone::load_resources(); }











void setup_split_screen(void) {
    u32 i;
    TObjPlayer *player;
    TPlyCharData *char_data;

    split_screen_flag = 1;
    split_screen_challenge_created = 0;
    if (challenge_retry_object != NULL) {
        split_screen_flag = 0;
        return;
    }
    if (is_split_screen() == 0) {
        split_screen_flag = 0;
        return;
    }
    if (split_screen_flag != 0) {
        challenge_retry_object = TChallenge4P::create();
        split_screen_challenge_created = 1;
        split_screen_flag = 0;
        set_split_screen_name("Area00");
        i = 0U;
        do {
            player = get_player_by_client_id(i);
            char_data = TAdSinglePlyChrSelectGC::get_char_index(i);
            if ((player != NULL) && (char_data != NULL)) {
                player->export_character_data(char_data);
            }
            i += 1;
        } while (i != 4U);
    }
}
void save_challenge_tombstone_spot(s32 client) {
    TObjPlayer *p = get_player_by_client_id(client);
    if (p != NULL) {
        ChallengeClientRecords *r = &challenge4p_mode_state.client_records[client];
        if (r->present != 0) {
            TObjTombstoneSpot *spot = &r->records.tombstone_spot;
            spot->phase = resolve_challenge_record_set(-1);
            spot->layout = challenge4p_mode_state.stage;
            spot->floor = challenge4p_mode_state.current_floor;
            VecCopy(&spot->position, &p->position);
            TObjTombstoneSpot *saved = &(get_character_save_record(client))->challenge.tombstone_spot;
            copy_tombstone_spot(saved, spot);
        }
    }
}

#pragma push
#pragma scheduling off
extern "C" {
extern "C++" void copy_tombstone_spot(TObjTombstoneSpot *destination, const TObjTombstoneSpot *source) {
    volatile TObjTombstoneSpot *output = destination;
    const volatile TObjTombstoneSpot *input = source;
    output->phase = input->phase;
    output->layout = input->layout;
    output->floor = input->floor;
    output->pad_3 = input->pad_3;
#ifdef __MWERKS__
    __memcpy(&destination->position, &source->position, sizeof(Vec));
#else
    destination->position = source->position;
#endif
}
}

#pragma pop

void spawn_player_tombstones2() {
    saddr i;
    ChallengeClientRecords *r;
    const TObjTombstoneSpot *t;
    reset_tombstone_values();
    for (i = 0; i < 4; i++) {
        r = &challenge4p_mode_state.client_records[i];
        if (r->present != 0 && get_player_by_client_id(i) != NULL) {
            t = &r->records.tombstone_spot;
            if (t->phase == resolve_challenge_record_set(-1) &&
                t->layout == challenge4p_mode_state.stage &&
                t->floor == challenge4p_mode_state.current_floor) {
                TObjTombstone::create_tombstone(tl_07, i, t);
            }
        }
    }
}

void TChallenge4P::create_time_window() {
    spawn_player_tombstones2();
    create_ch_time_win(tl_07);
    ((TLobby *)tl_07)->create_new_floor_windows();
    if (challenge4p_mode_state.solo_play_notice_shown == 0) {
        TObjSoloPlayWin::create(tl_07);
    }
}

void TChallenge4P::refresh_challenge_windows() {
    s32 old;
    s32 v;
    switch (get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
    case AREA_PIONEER2_EP2:
        old = challenge4p_mode_state.current_floor;
        challenge4p_mode_state.current_floor = -1;
        if (old != -1) {
            create_obj_tag_challenge(tl_07);
            if (challenge4p_mode_state.failed == 0) {
                create_ch_time_win(tl_07);
            }
        }
        break;
    case AREA_LOBBY:
        challenge4p_mode_state.current_floor = -1;
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        challenge4p_mode_state.current_floor = -1;
        break;
    default:
        v = get_current_floor();
        if (challenge4p_mode_state.current_floor != v) {
            challenge4p_mode_state.current_floor = v;
            create_time_window();
        }
        break;
    }
}

void TChallenge4P::clear_four_slots() {
    s32 i;
    for (i = 0; i < 4; i++) challenge4p_mode_state.client_records[i].present = 0;
}

void TChallenge4P::restore_challenge_from_save() {
    s32 i;
    clear_four_slots();
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != NULL && get_character_save_record(i) != NULL) {
            ChallengeClientRecords *r = &challenge4p_mode_state.client_records[i];
            r->present = 1;
            r->records = (get_character_save_record(i))->challenge;
        }
    }
}

s32 TChallenge4P::destroy_on_phase_change() {
    switch (get_main_phase()) {
    case 15:
        queue_destruction();
        return 1;
    case 14:
        return is_split_screen() != 1 ? 1 : 0;
    default:
        queue_destruction();
        return 1;
    }
}

void TChallenge4P::update_active() {
    if (destroy_on_phase_change() == 0) {
        refresh_challenge_windows();
    }
}

void TChallenge4P::run_task() {
    if (get_card_wait_state() != 1) {
        if (destroy_on_phase_change() == 1) {
            queue_destruction();
        }
        update_active();
        frame_count++;
    }
}

// The constructor and destructor address the vtable from the unit's data block,
// so they are compiled after it.
#pragma defer_codegen on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_max_size(16)
// Copies the default settings into challenge4p_mode_state, spelled out because the original's static initializer
// precedes this file's deferred constructor and destructor.
void __sinit_TChallenge4P_cpp() {
    __memcpy(&challenge4p_mode_state, &challenge_default_settings, sizeof(ChallengeModeState));
}

TChallenge4P::TChallenge4P(TObject *parent) : TObject(parent) {
    m_name = challenge4p_class_name;
    challenge4p_mode_state = challenge_default_settings;
    restore_challenge_from_save();
    frame_count = 0;
    missing_records_timer = 0;
    records_save_pending = 1;
    quest_send_timer = 0;
    TObjWarnChime::create(this);
}

TChallenge4P::~TChallenge4P() {
    challenge4p_mode_state = challenge_default_settings;
    challenge_retry_object = NULL;
}

__declspec(section ".ctors") static void *const challenge4p_global_initializer = (void *)__sinit_TChallenge4P_cpp;
