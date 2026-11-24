#include "types.h"
#include <stdlib.h>
#include <string.h>
#include "pso/unk/TLobby_8006F278.h"
#include "pso/unk/TLobby_80070A00.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TObjResultWin.h"
#include "pso/player/PlayerSlots.h"


struct RecoveredGlobal_8006F5B0_lbl_8048C9D8 { s32 value; u8 remaining[0x744]; };
LAYOUT_ASSERT(RecoveredGlobal_8006F5B0_lbl_8048C9D8_size, sizeof(RecoveredGlobal_8006F5B0_lbl_8048C9D8) == 0x748);

extern RecoveredGlobal_8006F5B0_lbl_8048C9D8 challenge_mode_state;
s32 TLobby::calc_challenge_time_limit() {
    s32 valid_slot;

    if (TLobby::is_flag_set() == 0) {
        return 0x12C;
    }
    valid_slot = TLobby::get_valid_slot(*(s32 *)((s8 *)&challenge_mode_state + 0x10));
    if ((valid_slot < 0x3C) || (valid_slot > 0xE10)) {
        valid_slot = 0x12C;
    }
    return valid_slot;
}
void TLobby::advance_state_if_flag_set() {
    if (TLobby::is_flag_set() != 0) {
        switch (((ChallengePhaseView *)&challenge_mode_state)->phase) {
        case 0:
            ((ChallengePhaseView *)&challenge_mode_state)->phase = 1;
            break;
        }
    }
}


struct Win_8006F48C {
    u8 pad0[0x21C4];
    s16 id;
    u8 pad21C6[0x229C - 0x21C6];
    char name[11];
    char term;
};

extern "C" {
saddr TWindowSubStatusDisp__sub_8006F0D8(void *, int);
s32 is_id_out_of_range__6TLobbyFi(s32 arg0);
s32 mix_seed_checked__6TLobbyFi(s32);
uaddr get_character_save_record(int);
s32 TLobby__sub_8006F5B0(saddr clear_time);
}

LobbyNameStringBuffer lobby_name_string_buffer;

extern "C" {
s32 decode_slot__6TLobbyFUi(u32 id);
void TLobby__sub_8006F48C(void);
u32 *TWindowSubStatusDisp__sub_8006F134(void *, s32);
s32 TLobby__sub_8006F38C(s32 total);
s32 TLobby::check_challenge_time_range(s32 clear_time) {
    if ((clear_time < TLobby::calc_challenge_time_limit()) || (clear_time > 0x8C9F)) {
        return 1;
    }
    return 0;
}

s32 is_id_out_of_range__6TLobbyFi(s32 arg0) {
    if ((arg0 < 0x3C) || (arg0 > 0x8C9F)) {
        return 1;
    }
    return 0;
}

s32 TLobby__sub_8006F38C(s32 total) {
    s32 lo;
    s32 hi;
    u32 *flags;
    s32 i;
    ChallengeRankEntry *e;
    uaddr w;
    lo = TWindowSubStatusDisp::calc_entry_offset(-1);
    hi = TWindowSubStatusDisp::calc_layout_hash(-1);
    if (get_character_save_record(0xFFFF) == 0) {
        return -4;
    }
    if (total < lo || total > hi) {
        return -4;
    }
    w = get_character_save_record(0xFFFF) + 0x21C4;
    flags = TWindowSubStatusDisp__sub_8006F134((void *)w, -1);
    for (i = 2, e = &((ChallengeRankTableView *)&challenge_mode_state)->entries[2]; i >= 0; i--, e--) {
        if (e->value != 0 && e->value >= total) {
            if (e->value < lo || e->value > hi) {
                return -4;
            }
            if ((*flags & e->mask) == 0) {
                break;
            }
        }
    }
    if (i < 0) {
        return -2;
    }
    return i;
}

void TLobby__sub_8006F48C(void) {
    char cur[12];
    char key[12];
    Win_8006F48C *win;
    s32 i;
    ChallengeStageEntry *e;
    win = (Win_8006F48C *)get_character_save_record(0xFFFF);
    if (TWindowSubStatusDisp::resolve_player_slot(-1) != 0) {
        return;
    }
    if (((ChallengeStageTableView *)&challenge_mode_state)->defaultName[0] == 0) {
        return;
    }
    if (((ChallengeStageTableView *)&challenge_mode_state)->count > 0) {
        decode_obfuscated_string(cur, win->name, 12);
        for (i = 0; i < ((ChallengeStageTableView *)&challenge_mode_state)->count; i++) {
            e = &((ChallengeStageTableView *)&challenge_mode_state)->entries[i];
            decode_obfuscated_string(key, e, 12);
            if (strncmp(key, cur, 12) == 0) {
                strncpy(win->name, e->name, 11);
                win->term = 0;
                win->id = TLobby__sub_80071640(e->id);
                return;
            }
        }
    }
    strncpy(win->name, ((ChallengeStageTableView *)&challenge_mode_state)->defaultName, 11);
    win->term = 0;
    win->id = TLobby__sub_80071640(((ChallengeStageTableView *)&challenge_mode_state)->defaultId);
}

s32 TLobby__sub_8006F5B0(saddr clear_time) {
    s32 temp_r30;
    s32 layout_id;
    saddr temp_r3_2;
    s32 id;
    s32 valid_slot;
    s32 var_r28;
    uaddr character_save_record;
    character_save_record = get_character_save_record(0xFFFF);
    layout_id = TWindowSubStatusDisp::get_layout_id(-1);
    if ((character_save_record == 0U) || ((s32) challenge_mode_state.value < 0) || ((s32) challenge_mode_state.value >= layout_id)) {
        return 0;
    }
    temp_r3_2 = TWindowSubStatusDisp__sub_8006F0D8((void *)(character_save_record + 0x21C4), -1);
    var_r28 = 0;
    temp_r30 = challenge_mode_state.value * 4;
    id = *(s32 *)((s8 *)temp_r3_2 + temp_r30);
    if (id == 0) {
        if (TWindowSubStatusDisp::resolve_player_slot(-1) == 0) {
            TLobby__sub_8006F48C();
        }
        var_r28 = 1;
        goto block_12;
    }
    valid_slot = TLobby::get_valid_slot(id);
    if (TLobby::is_id_out_of_range(valid_slot) != 0) {
        *(s32 *)((s8 *)temp_r3_2 + temp_r30) = 0;
        return 0;
    }
    if (clear_time < valid_slot) {
        var_r28 = 1;
    }
block_12:
    if (var_r28 == 0) {
        return 0;
    }
    *(s32 *)((s8 *)temp_r3_2 + temp_r30) = ((s32 (*)(void *))mix_seed_checked__6TLobbyFi)((void *)clear_time);
    return 1;
}
extern s32 local_client_id;
s32 mix_seed__6TLobbyFUs(u16);

s32 TLobby__sub_8006F6B0(s32 clear_time) {
    s32 next;
    s32 result;
    s32 total;
    u8 *local_data;
    u8 *client_data;
    u8 *record_data;
    u32 *flags;
    s32 *best_time;
    s32 ret;
    ChallengeResultRecord rec;

    result = -4;
    TLobby__sub_8006F5B0(clear_time);
    total = TWindowSubStatusDisp__sub_80071988(0xFFFF, TWindowSubStatusDisp::RECORD_SET_CURRENT);
    if (total != 0) {
        local_data = (u8 *)get_character_save_record(0xFFFF) + 0x21C4;
        total -= TLobby::get_valid_slot(((s32 *)TWindowSubStatusDisp__sub_8006F0D8(local_data, TWindowSubStatusDisp::RECORD_SET_CURRENT))[challenge_mode_state.value]);
        total += clear_time;
        result = TLobby__sub_8006F38C(total);
        next = result + 1;
        flags = TWindowSubStatusDisp__sub_8006F134(local_data, TWindowSubStatusDisp::RECORD_SET_CURRENT);
        if (((s32 (*)(u32))TLobby::get_slot_clamped)(flags[1]) < next) {
            flags[1] = ((s32 (*)(s32))mix_seed__6TLobbyFUs)(next);
        }
    }
    rec.summary.stage_index = challenge_mode_state.value;
    rec.summary.reserved = 0;
    rec.summary.total_time = total;
    client_data = (u8 *)&challenge_mode_state + local_client_id * 0x104 + 0x274;
    best_time = &((s32 *)TWindowSubStatusDisp__sub_8006F0D8(client_data, TWindowSubStatusDisp::RECORD_SET_CURRENT))[challenge_mode_state.value];
    flags = TWindowSubStatusDisp__sub_8006F134(client_data, TWindowSubStatusDisp::RECORD_SET_CURRENT);
    rec.previous.time = TLobby::get_valid_slot(*best_time);
    decode_obfuscated_string(rec.previous.award_name, client_data + 0xD8, 12);
    rec.previous.rank = ((s32 (*)(u32))TLobby::get_slot_clamped)(flags[1]);
    record_data = (u8 *)get_character_save_record(0xFFFF) + 0x21C4;
    flags = TWindowSubStatusDisp__sub_8006F134(record_data, TWindowSubStatusDisp::RECORD_SET_CURRENT);
    rec.current.time = clear_time;
    decode_obfuscated_string(rec.current.award_name, record_data + 0xD8, 12);
    rec.current.rank = ((s32 (*)(u32))TLobby::get_slot_clamped)(flags[1]);
    TObjResultWin::create(&rec);
    ret = result;
    if (total == 0) {
        ret = -1;
    }
    return ret;
}
void TLobby::set_name_string() {
    saddr arg0 = (saddr)this;
    strncpy((char *)&lobby_name_string_buffer.value, (const char *)arg0, 0x1F);
    *(s8 *)((s8 *)&lobby_name_string_buffer.value + 0x1F) = 0;
}

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

extern "C" {

void TLobby::encode_name_xor(u8 *dst, u8 *src, s32 n) {
    u8 c;
    s32 i;
    if (n < 1) {
        n = 1;
    } else if (n > 0x20) {
        n = 0x20;
    }
    for (i = 0; i < n - 1; i++, src++, dst++) {
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

s32 TLobby::get_valid_slot(int id) {
    s32 slot;
    if (id == 0) {
        return 0;
    }
    slot = TLobby::decode_slot(id);
    return TLobby::is_id_out_of_range(slot) ? 0 : slot;
}

s32 mix_seed_checked__6TLobbyFi(s32 arg0);

s32 mix_seed_checked__6TLobbyFi(s32 seed) {
    if ((seed == 0) || (((s32 (*)())is_id_out_of_range__6TLobbyFi)() != 0)) {
        return 0;
    }
    return ((s32 (*)(s32))mix_seed__6TLobbyFUs)(seed);
}

s32 TLobby::get_slot_clamped(u32 id) {
    s32 var_r3;

    var_r3 = TLobby::decode_slot(id);
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    return var_r3;
}

s32 decode_slot__6TLobbyFUi(u32 id);

s32 decode_slot__6TLobbyFUi(u32 id) {
    s32 temp_r3;
    u32 x;

    x = id >> 0x10U;
    temp_r3 = TLobby::count_set_bits(x);
    if ((temp_r3 < 4) || (temp_r3 > 0xC)) {
        return -1;
    }
    return (u16) (x ^ id);
}

s32 TLobby__sub_8006FBE4(void);
s32 mix_seed__6TLobbyFUs(u16 arg0);
u16 TLobby__sub_8006FAE4(void);

s32 mix_seed__6TLobbyFUs(u16 arg0) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(void))TLobby__sub_8006FAE4)();
    return (temp_r3 << 0x10) | (temp_r3 ^ arg0);
}


u16 TLobby__sub_8006FAE4(void) {
    f32 temp_f31;
    f32 temp_f30;
    s32 temp_r3;
    u16 var_r30;
    s32 var_r29;

    var_r29 = 0;
loop_1:
    var_r30 = (u16) (s32) (65535.0f * (3.0517578e-05f * (f32) rand()));
    temp_r3 = TLobby::count_set_bits(var_r30);
    if ((temp_r3 < 4) || (temp_r3 > 0xC)) {
        var_r29 += 1;
        var_r30 = 0x3938;
        if (var_r29 < 8) {
            goto loop_1;
        }
    }
    return var_r30;
}
void TLobby::mark_solo_win_closing() {
    if (TLobby::is_flag_set() != 0) {
        *(s32 *)((s8 *)&challenge_mode_state.value + 0x30) = 1;
    }
}

s32 TLobby__sub_8006FBE4(void) {
    s32 count;
    s32 i;

    count = 0;
    for (i = 0; i < 4; i += 1) {
        if (get_player_by_client_id(i) != 0U) {
            count += 1;
        }
    }
    return count;
}

}
