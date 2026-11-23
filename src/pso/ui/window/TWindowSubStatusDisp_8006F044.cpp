#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/quest/challenge/ChallengeModeState.h"

s32 TWindowSubStatusDisp::calc_layout_hash(s32 slot) {
    return TWindowSubStatusDisp::get_layout_id(slot) * 0x8C9F;
}

s32 TWindowSubStatusDisp::calc_entry_offset(s32 slot) {
    return TWindowSubStatusDisp::get_layout_id(slot) * 0x12C;
}


#pragma fp_contract on


extern "C" {
extern const char lbl_80438570[11] = "TChallenge";
extern const char lbl_8043857C[5] = "... ";
extern const s32 challenge_record_rank_slots[3] = { 0, 1, 2 };
extern const s32 challenge_record_time_offsets[3] = { 0, 9, 14 };
extern const s32 challenge_record_stage_counts[3] = { 9, 5, 9 };

s32 TWindowSubStatusDisp::get_layout_id(s32 slot) {
    slot = TWindowSubStatusDisp::resolve_player_slot(slot);
    if (slot < 3) {
        return challenge_record_stage_counts[TWindowSubStatusDisp::resolve_player_slot(slot)];
    }
    return 5;
}

#pragma optimize_for_size off

s32 *TWindowSubStatusDisp__sub_8006F0D8(ChallengeRecord *record, s32 slot) {
    s32 idx = TWindowSubStatusDisp::resolve_player_slot(slot);
    if (idx < 3) {
        return &record->stage_times[challenge_record_time_offsets[idx]];
    }
    return record->ep2_split_stage_times;
}

ChallengeStageRank *TWindowSubStatusDisp__sub_8006F134(ChallengeRecord *record, s32 slot) {
    s32 idx = TWindowSubStatusDisp::resolve_player_slot(slot);
    if (idx < 3) {
        return &record->ranks[challenge_record_rank_slots[idx]];
    }
    return &record->ep2_split_rank;
}

s32 TWindowSubStatusDisp::resolve_player_slot(s32 slot) {
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

s32 TLobby::get_flagged_table_entry(s32 client) {
    if (TLobby::is_flag_set() != 0) {
        return challenge_mode_state.client_died[client];
    }
    return 0;
}

s32 TLobby::get_flag_value_if_set() {
    if (TLobby::is_flag_set() != 0) {
        return challenge_mode_state.retry_menu_disabled;
    }
    return 0;
}

}
