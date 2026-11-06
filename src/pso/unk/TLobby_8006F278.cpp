#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowSubStatusDisp_80071774.h"
#include "pso/ui/window/TObjResultWin.h"

struct RecoveredGlobal_8006F5B0_lbl_8048C9D8 { s32 value; u8 remaining[0x744]; };
typedef char RecoveredGlobal_8006F5B0_lbl_8048C9D8_size[sizeof(RecoveredGlobal_8006F5B0_lbl_8048C9D8) == 0x748 ? 1 : -1];

struct G_8006F2CC { u8 pad[0x28]; s32 x28; };

extern "C" {
extern RecoveredGlobal_8006F5B0_lbl_8048C9D8 challenge_mode_state;
s32 is_flag_set__6TLobbyFv();
s32 TLobby::calc_challenge_time_limit() {
    s32 valid_slot;

    if (is_flag_set__6TLobbyFv() == 0) {
        return 0x12C;
    }
    valid_slot = TLobby::get_valid_slot(*(s32 *)((s8 *)&challenge_mode_state + 0x10));
    if ((valid_slot < 0x3C) || (valid_slot > 0xE10)) {
        valid_slot = 0x12C;
    }
    return valid_slot;
}
void TLobby::advance_state_if_flag_set() {
    if (is_flag_set__6TLobbyFv() != 0) {
        switch ((*(G_8006F2CC *)&challenge_mode_state).x28) {
        case 0:
            (*(G_8006F2CC *)&challenge_mode_state).x28 = 1;
            break;
        }
    }
}

}

struct RecoveredGlobal_8006F848_lbl_804FF800 {
    s32 value;
    u8 remaining[0x1C];
};

struct Entry_8006F48C {
    char key[12];
    char name[12];
    s32 id;
};

struct Table_8006F48C {
    u8 pad0[0x18];
    s32 defaultId;
    s32 count;
    u8 pad20[0x30];
    char defaultName[12];
    Entry_8006F48C entries[1];
};

struct Win_8006F48C {
    u8 pad0[0x21C4];
    s16 id;
    u8 pad21C6[0x229C - 0x21C6];
    char name[11];
    char term;
};

struct Entry_8006F38C {
    s32 value;
    u32 mask;
    u8 pad[0x14];
};

struct Table_8006F38C {
    u8 pad[0x21C];
    Entry_8006F38C entries[3];
};

extern "C" {
s32 get_layout_id__20TWindowSubStatusDispFv(int);
s32 TWindowSubStatusDisp__sub_8006F0D8(void *, int);
s32 is_id_out_of_range__6TLobbyFi(s32 arg0);
s32 mix_seed_checked__6TLobbyFi(s32);
u32 get_character_save_record(int);
s32 TLobby__sub_8006F5B0(s32 arg0);
s32 strncpy(void *, void *, int);
RecoveredGlobal_8006F848_lbl_804FF800 lobby_name_string_buffer;
s32 decode_slot__6TLobbyFUi(u32 id);
u32 TLobby__sub_80071640(u32 c);
s32 strncmp(void *, void *, int);
void TLobby__sub_8006F48C(void);
s32 calc_layout_hash__20TWindowSubStatusDispFv(int);
s32 calc_entry_offset__20TWindowSubStatusDispFv(int);
u32 *TWindowSubStatusDisp__sub_8006F134(void *, s32);
s32 TLobby__sub_8006F38C(s32 arg0);
s32 TLobby::check_challenge_time_range(s32 arg0) {
    if ((arg0 < TLobby::calc_challenge_time_limit()) || (arg0 > 0x8C9F)) {
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

#define TBL_8006F48C (*(Table_8006F48C *)&challenge_mode_state)

#define TBL_8006F38C (*(Table_8006F38C *)&challenge_mode_state)
s32 TLobby__sub_8006F38C(s32 arg0) {
    s32 lo;
    s32 hi;
    u32 *flags;
    s32 i;
    Entry_8006F38C *e;
    u32 w;
    lo = calc_entry_offset__20TWindowSubStatusDispFv(-1);
    hi = calc_layout_hash__20TWindowSubStatusDispFv(-1);
    if (get_character_save_record(0xFFFF) == 0) {
        return -4;
    }
    if (arg0 < lo || arg0 > hi) {
        return -4;
    }
    w = get_character_save_record(0xFFFF) + 0x21C4;
    flags = TWindowSubStatusDisp__sub_8006F134((void *)w, -1);
    for (i = 2, e = &TBL_8006F38C.entries[2]; i >= 0; i--, e--) {
        if (e->value != 0 && e->value >= arg0) {
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
    Entry_8006F48C *e;
    win = (Win_8006F48C *)get_character_save_record(0xFFFF);
    if (TWindowSubStatusDisp::resolve_player_slot(-1) != 0) {
        return;
    }
    if (TBL_8006F48C.defaultName[0] == 0) {
        return;
    }
    if (TBL_8006F48C.count > 0) {
        ((TLobby *)cur)->decode_obfuscated_string(win->name, 12);
        for (i = 0; i < TBL_8006F48C.count; i++) {
            e = &TBL_8006F48C.entries[i];
            ((TLobby *)key)->decode_obfuscated_string(e, 12);
            if (strncmp(key, cur, 12) == 0) {
                strncpy(win->name, e->name, 11);
                win->term = 0;
                win->id = TLobby__sub_80071640(e->id);
                return;
            }
        }
    }
    strncpy(win->name, TBL_8006F48C.defaultName, 11);
    win->term = 0;
    win->id = TLobby__sub_80071640(TBL_8006F48C.defaultId);
}

s32 TLobby__sub_8006F5B0(s32 arg0) {
    s32 temp_r30;
    s32 temp_r3;
    s32 temp_r3_2;
    s32 temp_r3_3;
    s32 valid_slot;
    s32 var_r28;
    u32 character_save_record;
    character_save_record = get_character_save_record(0xFFFF);
    temp_r3 = get_layout_id__20TWindowSubStatusDispFv(-1);
    if ((character_save_record == 0U) || ((s32) challenge_mode_state.value < 0) || ((s32) challenge_mode_state.value >= temp_r3)) {
        return 0;
    }
    temp_r3_2 = TWindowSubStatusDisp__sub_8006F0D8((void *)(character_save_record + 0x21C4), -1);
    var_r28 = 0;
    temp_r30 = challenge_mode_state.value * 4;
    temp_r3_3 = *(s32 *)((s8 *)temp_r3_2 + temp_r30);
    if (temp_r3_3 == 0) {
        if (TWindowSubStatusDisp::resolve_player_slot(-1) == 0) {
            TLobby__sub_8006F48C();
        }
        var_r28 = 1;
        goto block_12;
    }
    valid_slot = TLobby::get_valid_slot(temp_r3_3);
    if (is_id_out_of_range__6TLobbyFi(valid_slot) != 0) {
        *(s32 *)((s8 *)temp_r3_2 + temp_r30) = 0;
        return 0;
    }
    if (arg0 < valid_slot) {
        var_r28 = 1;
    }
block_12:
    if (var_r28 == 0) {
        return 0;
    }
    *(s32 *)((s8 *)temp_r3_2 + temp_r30) = ((s32 (*)(void *))mix_seed_checked__6TLobbyFi)((void *)arg0);
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
    total = TWindowSubStatusDisp__sub_80071988(0xFFFF, -1);
    if (total != 0) {
        local_data = (u8 *)get_character_save_record(0xFFFF) + 0x21C4;
        total -= TLobby::get_valid_slot(((s32 *)TWindowSubStatusDisp__sub_8006F0D8(local_data, -1))[challenge_mode_state.value]);
        total += clear_time;
        result = TLobby__sub_8006F38C(total);
        next = result + 1;
        flags = TWindowSubStatusDisp__sub_8006F134(local_data, -1);
        if (((s32 (*)(u32))TLobby::get_slot_clamped)(flags[1]) < next) {
            flags[1] = ((s32 (*)(s32))mix_seed__6TLobbyFUs)(next);
        }
    }
    rec.summary.stage_index = challenge_mode_state.value;
    rec.summary.reserved = 0;
    rec.summary.total_time = total;
    client_data = (u8 *)&challenge_mode_state + local_client_id * 0x104 + 0x274;
    best_time = &((s32 *)TWindowSubStatusDisp__sub_8006F0D8(client_data, -1))[challenge_mode_state.value];
    flags = TWindowSubStatusDisp__sub_8006F134(client_data, -1);
    rec.previous.time = TLobby::get_valid_slot(*best_time);
    ((TLobby *)rec.previous.award_name)->decode_obfuscated_string(client_data + 0xD8, 12);
    rec.previous.rank = ((s32 (*)(u32))TLobby::get_slot_clamped)(flags[1]);
    record_data = (u8 *)get_character_save_record(0xFFFF) + 0x21C4;
    flags = TWindowSubStatusDisp__sub_8006F134(record_data, -1);
    rec.current.time = clear_time;
    ((TLobby *)rec.current.award_name)->decode_obfuscated_string(record_data + 0xD8, 12);
    rec.current.rank = ((s32 (*)(u32))TLobby::get_slot_clamped)(flags[1]);
    TObjResultWin::create(&rec);
    ret = result;
    if (total == 0) {
        ret = -1;
    }
    return ret;
}
typedef char RecoveredGlobal_8006F848_lbl_804FF800_size[sizeof(RecoveredGlobal_8006F848_lbl_804FF800) == 0x20 ? 1 : -1];
void TLobby::set_name_string() {
    s32 arg0 = (s32)this;
    strncpy((void *)&lobby_name_string_buffer.value, (void *)arg0, 0x1F);
    *(s8 *)((s8 *)&lobby_name_string_buffer.value + 0x1F) = 0;
}

void TLobby::decode_obfuscated_string(void *arg1, int arg2) {
    u8 *dst = (u8 *)this;
    u8 *src = (u8 *)arg1;
    s32 n = arg2;
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
            *dst = dst[-1] + (s8)(c ^ 0x7F);
        }
    }
    *dst = 0;
}

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
    slot = decode_slot__6TLobbyFUi(id);
    return is_id_out_of_range__6TLobbyFi(slot) ? 0 : slot;
}

s32 mix_seed_checked__6TLobbyFi(s32 arg0);
s32 mix_seed__6TLobbyFUs(u16);

s32 mix_seed_checked__6TLobbyFi(s32 arg0) {
    if ((arg0 == 0) || (((s32 (*)())is_id_out_of_range__6TLobbyFi)() != 0)) {
        return 0;
    }
    return ((s32 (*)(s32))mix_seed__6TLobbyFUs)(arg0);
}

s32 TLobby::get_slot_clamped() {
    s32 var_r3;

    var_r3 = ((s32 (*)())decode_slot__6TLobbyFUi)();
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    return var_r3;
}

s32 decode_slot__6TLobbyFUi(u32 arg0);

s32 decode_slot__6TLobbyFUi(u32 arg0) {
    s32 temp_r3;
    u32 temp_r31;

    temp_r31 = arg0 >> 0x10U;
    temp_r3 = TLobby::count_set_bits(temp_r31);
    if ((temp_r3 < 4) || (temp_r3 > 0xC)) {
        return -1;
    }
    return (u16) (temp_r31 ^ arg0);
}

s32 TLobby__sub_8006FBE4(void);
s32 mix_seed__6TLobbyFUs(u16 arg0);
u16 TLobby__sub_8006FAE4(void);
void *get_player_by_client_id(s32 i);

s32 mix_seed__6TLobbyFUs(u16 arg0) {
    s32 temp_r3;

    temp_r3 = ((s32 (*)(void))TLobby__sub_8006FAE4)();
    return (temp_r3 << 0x10) | (temp_r3 ^ arg0);
}

s32 rand();

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
    if (is_flag_set__6TLobbyFv() != 0) {
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
