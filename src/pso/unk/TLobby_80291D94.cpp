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
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TObjSoloPlayWin.h"
#include "types.h"
#include "pso/network/TLobby.h"
#include "pso/quest/challenge/ChallengeMode.h"
#include "pso/quest/challenge/ChallengeModeState.h"
#include "pso/quest/challenge/TChallenge4P.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_8026A328.h"
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
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/player/PlayerSlots.h"
#include "pso/unk/TLobby_80291D94.h"
#include "pso/ui/TLevelSelect.h"

ChallengeModeState challenge_default_settings = {
    -1, 1.0f, -1, 0, 0x39383814, -10, -1, 0, 0, -1,
};
ChallengeModeState challenge4p_mode_state = {0};
__declspec(section ".data") char lbl_804DB880[] = "theBest";


s32 is_challenge_mode_active(void);
void challenge_set_min_clear_time(s32 v);

void TLobby::update_screen() { if (is_challenge_mode_active() != 0) { TLobby::is_multi_ready(); } }
void TLobby::set_challenge_split_flag() {
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

s32 TLobby::get_normalized_mode() {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    if ((challenge4p_mode_state.boss_warp_disabled != 1) && (challenge4p_mode_state.boss_warp_disabled != 0)) {
        challenge4p_mode_state.boss_warp_disabled = 0;
    }
    return challenge4p_mode_state.boss_warp_disabled;
}
void challenge_set_boss_warp_disabled(s32 disabled) {
    s32 var_r31;
    var_r31 = disabled;
    if (is_challenge_mode_active() == 0) {
        challenge4p_mode_state.boss_warp_disabled = 0;
        return;
    }
    if ((var_r31 != 1) && (var_r31 != 0)) {
        var_r31 = 0;
    }
    challenge4p_mode_state.boss_warp_disabled = var_r31;
}






extern "C" {
s32 TLobby__sub_80291F9C(void);
char split_screen_player_name[0x20];
}
void challenge_set_time_record(s32 seed);
extern "C" {
s32 TLobby__sub_80292DA0(s32 seed, u16 card);
}
#define TLobby__sub_80292DA0 ((s32 (*)(s32, s32))TLobby__sub_80292DA0)
s32 challenge_check_rank_time(s32 seed, s32 card);
s32 challenge_get_time_record(void);
extern "C" {


void TLobby::draw_if_ready2() {
    if ((is_challenge_mode_active() != 0) && (TLobby::is_multi_ready() != 0) && (challenge_retry_object != NULL)) {
        TObjChallenge4PRetry::create(challenge_retry_object);
    }
}

s32 TLobby::check_ready_status() {
    s32 var_r3;

    var_r3 = TLobby__sub_80291F9C();
    if (var_r3 == 1) {
        var_r3 = -1;
        if (challenge4p_mode_state.retry_confirmed != 0) {
            var_r3 = 1;
        }
    }
    return var_r3;
}

s32 TLobby__sub_80291F9C(void) {
    if (challenge4p_mode_state.failed != 0) {
        return challenge4p_mode_state.retry_choice;
    }
    return 0;
}
}

void TLobby::reset_menu_state_globals() {
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
        challenge_retry_object->pad_20 = 0;
        challenge_retry_object->pad_24 = 1;
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

void TLobby::store_challenge_seeds(s32 seed) {
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
    TLobby::store_challenge_seeds(seed);
}
extern "C" {

s32 challenge_set_rank_override(const char *match, const char *title, s32 color) { return 1; }
}


s32 challenge_check_rank_time(s32 seed, s32 card) {
    s32 r;
    if (is_challenge_mode_active() == 0 || challenge4p_mode_state.stage == -1 ||
        (u32)get_character_save_record((u16)card) == 0) {
        challenge4p_mode_state.result_rank = -4;
        return -4;
    }
    fabs_float(seed - challenge4p_mode_state.base_time);
    if (TLobby::is_value_out_of_range(seed) != 0) {
        seed = 0x8C9F;
    }
    r = TLobby__sub_80292DA0(seed, card);
    if (r == -1) {
        challenge4p_mode_state.result_rank = -1;
        return -1;
    }
    if (r < 0) {
        challenge4p_mode_state.result_rank = -2;
        return -2;
    }
    CharacterSaveRecord *record = (CharacterSaveRecord *)get_character_save_record((u16)card);
    if ((uaddr)record != 0 && record->is_bank_full() != 0) {
        challenge4p_mode_state.result_rank = -3;
        return -3;
    }
    challenge4p_mode_state.result_rank = r;
    return r;
}
#undef TLobby__sub_80292DA0

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
    record = (CharacterSaveRecord *)get_character_save_record(slot_index);
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
extern "C" {
void TLobby::set_split_screen_name() {
    saddr arg0 = (saddr)this;
    strncpy(split_screen_player_name, (const char *)arg0, 0x20);
    split_screen_player_name[0x1F] = 0;
}
void TLobby::update_challenge_timer(s32 time) {
    if (is_challenge_mode_active() != 0) {
        fabs_float((f32) (time - challenge4p_mode_state.base_time));
        challenge4p_mode_state.base_time = time;
        set_challenge_time_window_timer(time);
    }
}
}


struct RebuildPlayersForStageHdr { u32 w[2]; };

struct RebuildPlayersForStageInfo { u8 pad0[0x31]; u8 cls; u8 pad32[2]; u32 flags; u8 pad38[0x50 - 0x38]; };


extern "C" {
void copy_player_visual_record(void *, void *);


s32 TLobby::set_camera_height_if_valid(f32 multiplier) {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    if ((multiplier < 0.01f) || (multiplier > 10000.0f)) {
        return 0;
    }
    challenge4p_mode_state.exp_multiplier = multiplier;
    return 1;
}


s32 TLobby::try_set_split_screen(s32 difficulty) {
    if (is_challenge_mode_active() == 0) {
        return 0;
    }
    game_difficulty_selection = difficulty;
    return 1;
}
void TLobby::rebuild_players_for_stage(s32 stage) {
    RebuildPlayersForStageInfo info;
    Vec pos;
    RebuildPlayersForStageHdr hdr;
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
        ((TObjPlayer *)(&hdr))->clear_header_struct();
        if (p != NULL) {
            VecCopy((Vec *)&pos, (const Vec *)((u8 *)p + 0x38));
            copy_player_visual_record(&info, (u8 *)p + 0x85C);
            ((TLobby *)(&hdr))->copy_header_struct((u8 *)p + 0xDAC);
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
            ((TLobby *)((u8 *)p + 0xDAC))->copy_header_struct(&hdr);
            p->set_position_from(&pos);
            p->save_previous_position();
            p->reset_motion_fields();
            p->technique_state.set_all_technique_levels(0xFF);
            if (tbl->techniques != NULL) {
                for (e = tbl->techniques; e->level != 0xFF; e++) {
                    TObjPlayer::set_technique_level_clamped(p, e->level, e->technique);
                }
            }
            *(s32 *)((s8 *)p + 0xD58) = 0;
        }
    }
}

}


extern "C" {
void TLobby__sub_80293218(s32);
}
s32 challenge_check_any_player_dead(void);
s32 challenge_check_all_players_dead(void);
extern "C" {
s32 TLobby__sub_80292F34(s32 limit);
s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id);
s32 TLobby__sub_80292AB4(s32 total, u16 card, s32 slot);
}

void TLobby::clamp_and_store_layout_index(s32 stage) {
    s32 layout_id;
    s32 var_r31;

    var_r31 = stage;
    layout_id = challenge_set_stage_count(-1);
    if ((var_r31 < 0) || (var_r31 >= layout_id)) {
        var_r31 = 0;
    }
    challenge4p_mode_state.stage = var_r31;
}

s32 challenge_check_any_player_dead(void) {
    s32 var_r31;
    u32 i;
    u8 *player;
    if (challenge_retry_object == NULL) {
        return 0;
    }
    var_r31 = 0;
    i = 0;
    do {
        player = (u8 *)(((saddr)get_player_by_client_id(i)));
        if ((player != NULL) && (((int)((TObjPlayer *)player)->check_player_state_flag_2()) != 0)) {
            TLobby__sub_80293218((s32) i);
            var_r31 = 1;
        }
        i += 1;
    } while ((s32) i < 4);
    if (var_r31 != 0) {
        challenge4p_mode_state.failed = 1;
        return 1;
    }
    return 0;
}
s32 challenge_check_all_players_dead(void) {
    s32 var_r31;
    u8 *player;
    if (challenge_retry_object == NULL) {
        return 0;
    }
    var_r31 = 0;
loop_3:
    player = (u8 *)(((u8 *)get_player_by_client_id(var_r31)));
    if ((player != NULL) && (((int)((TObjPlayer *)player)->check_player_state_flag_2()) == 0)) {
        return 0;
    }
    var_r31 += 1;
    if (var_r31 >= 4) {
        challenge4p_mode_state.failed = 1;
        return 1;
    }
    goto loop_3;
}
extern "C" {

s32 TLobby__sub_80292AB4(s32 total, u16 card, s32 slot) {
    s32 lo;
    s32 hi;
    ChallengeStageRank *rank;
    s32 i;
    ChallengeRankThreshold *e;
    saddr w;
    lo = challenge_set_min_time(slot);
    hi = challenge_set_max_time(slot);
    if (reinterpret_cast<const void *>(get_character_save_record(card)) == NULL) {
        return -4;
    }
    if (total < lo || total > hi) {
        return -4;
    }
    w = get_character_save_record(card) + 0x21C4;
    rank = challenge_set_rank((ChallengeRecord *)w, slot);
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

s32 TLobby__sub_80292BB8(s32 seed, u16 card, s32 id) {
    u8 *win = (u8 *)get_character_save_record(card);
    s32 layout = challenge_set_stage_count(id);
    s32 *arr;
    s32 idx;
    s32 limit;
    s32 ok;
    if (win == NULL || challenge4p_mode_state.stage < 0 || challenge4p_mode_state.stage >= layout) {
        return 0;
    }
    arr = challenge_set_stage_times((ChallengeRecord *)(win + 0x21C4), id);
    ok = 0;
    idx = challenge4p_mode_state.stage * 4;
    if (*(s32 *)((u8 *)arr + idx) == 0) {
        ok = 1;
    } else {
        limit = decode_challenge_time(*(s32 *)((u8 *)arr + idx));
        if (TLobby__sub_80292F34(limit) != 0) {
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
}

s32 count_card_layout_entries(s32 client) {
    u8 *win = (u8 *)get_character_save_record(client);
    s32 layout;
    s32 id;
    s32 *arr;
    s32 n;
    s32 i;
    if (win == NULL) {
        return 0;
    }
    id = resolve_challenge_record_set(-1);
    arr = challenge_set_stage_times((ChallengeRecord *)(win + 0x21C4), id);
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



extern "C" {
s32 TLobby__sub_80292BB8(s32, u16, s32);

s32 TLobby::calc_min_challenge_progress() {
    s32 temp_r3;
    s32 var_r31;
    s32 i;

    var_r31 = challenge_set_stage_count(resolve_challenge_record_set(-1));
    i = 0;
    do {
        if (get_player_by_client_id(i) != NULL) {
            temp_r3 = count_card_layout_entries(i);
            if (var_r31 > temp_r3) {
                var_r31 = temp_r3;
            }
        }
        i += 1;
    } while (i < 4);
    return var_r31;
}
s32 TLobby__sub_80292DA0(s32 seed, u16 card) {
    s32 result;
    s32 total;
    s32 id;
    ChallengeRecord *record;
    s32 next;
    ChallengeStageRank *e;
    id = resolve_challenge_record_set(RECORD_SET_CURRENT);
    result = -4;
    TLobby__sub_80292BB8(seed, card, id);
    total = get_challenge_set_time(card, id);
    if (total != 0) {
        record = (ChallengeRecord *)(get_character_save_record(card) + 0x21C4);
        total -= decode_challenge_time(challenge_set_stage_times(record, id)[challenge4p_mode_state.stage]);
        total += seed;
        result = TLobby__sub_80292AB4(total, card, id);
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

}



extern "C" {
int get_camera_view_count(void* p);

s32 TLobby::is_value_out_of_range(s32 seed) {
    if ((seed < TLobby::get_clamped_time_limit()) || (seed > 0x8C9F)) {
        return 1;
    }
    return 0;
}
s32 TLobby__sub_80292F34(s32 limit) {
    if ((limit < 0x3C) || (limit > 0x8C9F)) {
        return 1;
    }
    return 0;
}
int get_camera_view_count(void* p) { return TCameraCtrl::get_view_count(); }
}
#pragma push
#pragma fp_contract on
s32 TLobby::get_challenge_mode_flag() {
    if (is_challenge_mode_active() != 0) {
        return challenge4p_mode_state.retry_menu_disabled;
    }
    return 0;
}
#pragma pop

void TLobby::start_challenge_countdown() {
    if (is_challenge_mode_active() != 0) {
        switch (challenge4p_mode_state.retry_confirmed) {
        case 0:
            challenge4p_mode_state.retry_confirmed = 1;
            break;
        }
    }
}


void TLobby::set_retry_selection(s32 choice) {
    s32 var_r31;

    var_r31 = choice;
    if (is_challenge_mode_active() != 0) {
        if ((var_r31 < 0) || (var_r31 > 1)) {
            var_r31 = 0;
        }
        challenge4p_mode_state.retry_choice = var_r31;
    }
}

void TLobby::destroy_global() {
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

void clear_challenge_and_split_screen_flags(void);
void enable_split_screen_challenge_mode(void);

void clear_challenge_and_split_screen_flags(void) { challenge_mode_active_flag = 0; split_screen_flag = 0; }

void enable_split_screen_challenge_mode(void) { challenge_mode_active_flag = 1; split_screen_flag = 1; }

const char *challenge4p_class_name = "TChallenge4P";

TChallenge4P *TChallenge4P::create() {
    return new TChallenge4P(tl_su);
}

void TLobby::destroy_tombstone() { TObjTombstone::destroy(); }
void load_tombstone_resources() { TObjTombstone::load_resources(); }


struct ByteBlock_690 { u8 bytes[0x690]; };







extern "C" {
void TLobby__sub_80293218(s32 client);

}
void setup_split_screen(void);


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
        ((TLobby *)((saddr)"Area00"))->set_split_screen_name();
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
extern "C" {

void TLobby__sub_80293218(s32 client) {
    TObjPlayer *p = get_player_by_client_id(client);
    if (p != NULL) {
        ChallengeClientRecords *r = &challenge4p_mode_state.client_records[client];
        if (r->present != 0) {
            TObjTombstoneSpot *spot = &r->records.tombstone_spot;
            spot->phase = resolve_challenge_record_set(-1);
            spot->layout = challenge4p_mode_state.stage;
            spot->floor = challenge4p_mode_state.current_floor;
            VecCopy(&spot->position, &p->position);
            u8 *w = reinterpret_cast<u8 *>(get_character_save_record(client)) + 0x2274;
            copy_tombstone_spot(reinterpret_cast<TObjTombstoneSpot *>(w), spot);
        }
    }
}

#pragma push
#pragma scheduling off
extern "C++" void copy_tombstone_spot(TObjTombstoneSpot *destination, const TObjTombstoneSpot *source) {
    volatile TObjTombstoneSpot *output = destination;
    const volatile TObjTombstoneSpot *input = source;
    output->phase = input->phase;
    output->layout = input->layout;
    output->floor = input->floor;
    output->unk_3 = input->unk_3;
#ifdef __MWERKS__
    __memcpy(&destination->position, &source->position, sizeof(Vec));
#else
    destination->position = source->position;
#endif
}

#pragma pop

void TLobby::spawn_player_tombstones2() {
    saddr i;
    ChallengeClientRecords *r;
    const TObjTombstoneSpot *t;
    TLobby::reset_tombstone_values();
    for (i = 0; i < 4; i++) {
        r = &challenge4p_mode_state.client_records[i];
        if (r->present != 0 && get_player_by_client_id(i) != NULL) {
            t = &r->records.tombstone_spot;
            if (t->phase == resolve_challenge_record_set(-1) &&
                t->layout == challenge4p_mode_state.stage &&
                t->floor == challenge4p_mode_state.current_floor) {
                TLobby::create_tombstone(tl_07, i, t);
            }
        }
    }
}

void TChallenge4P::create_time_window() {
    TLobby::spawn_player_tombstones2();
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
            create_obj_tag_challenge((void *)tl_07);
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
        if (get_player_by_client_id(i) != NULL && (u8 *)get_character_save_record(i) != NULL) {
            ChallengeClientRecords *r = &challenge4p_mode_state.client_records[i];
            r->present = 1;
            r->records = *(ChallengeRecord *)(get_character_save_record(i) + 0x21C4);
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

}

// The constructor and destructor address the vtable from the unit's data block,
// so they are compiled after it.
#pragma defer_codegen on
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma inline_max_size(16)
void TLobby::copy_global_value_block() {
    *(ByteBlock_690 *)&challenge4p_mode_state = *(const ByteBlock_690 *)&challenge_default_settings;
}

TChallenge4P::TChallenge4P(TObject *parent) : TObject(parent) {
    m_name = challenge4p_class_name;
    challenge4p_mode_state = challenge_default_settings;
    restore_challenge_from_save();
    frame_count = 0;
    pad_20 = 0;
    pad_24 = 1;
    pad_28 = 0;
    TObjWarnChime::create(this);
}

TChallenge4P::~TChallenge4P() {
    challenge4p_mode_state = challenge_default_settings;
    challenge_retry_object = NULL;
}

__declspec(section ".ctors") static void *const __sinit_TLobby_80291D94_cpp_ref = (void *)TLobby::copy_global_value_block;
