#include "pso/ui/window/TObjDeadListWin.h"
#include "pso/unk/TLobby.h"
#include "pso/object/TObjTombstone.h"

#include "types.h"

#pragma readonly_strings on

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_690 { u8 bytes[0x690]; };

struct RecoveredGlobal_80070A78_lbl_8048C348 {
    s32 value;
    u8 remaining[0x68C];
};

struct RecoveredGlobal_80070A78_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

extern RecoveredGlobal_80070A78_lbl_8048C348 challenge_settings_defaults;
extern s32 challenge_mode_state[];
#define challenge_mode_state (*(RecoveredGlobal_80070A78_lbl_8048C9D8 *)challenge_mode_state)

extern "C" {

u32 create__10TChallengeFv();

s32 get_main_phase();
extern u32 challenge_task;
extern s32 challenge_task_created;
extern s32 TLobby__data_805D4E30;

void TLobby::init_on_main_phase() {
    challenge_task_created = 0;
    if ((u32) challenge_task == 0U) {
        if (get_main_phase() != 0xF) {
            TLobby__data_805D4E30 = 0;
            return;
        }
        TLobby::start_lobby_name_request();
        if ((s32) TLobby__data_805D4E30 != 0) {
            challenge_task = create__10TChallengeFv();
            challenge_task_created = 1;
            TObjTombstone::load_resources();
            ((TLobby *)(s32 *)"Area00")->set_name_string();
        }
    }
}
typedef char RecoveredGlobal_80070A78_lbl_8048C348_size[sizeof(RecoveredGlobal_80070A78_lbl_8048C348) == 0x690 ? 1 : -1];
typedef char RecoveredGlobal_80070A78_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070A78_lbl_8048C9D8) == 0x748 ? 1 : -1];
void TLobby::copy_state_block() {
    *(ByteBlock_690 *)(&challenge_mode_state.value) = *(const ByteBlock_690 *)(&challenge_settings_defaults.value);
}

}

__declspec(section ".ctors") static void *const __sinit_TLobby_80070A00_80070A00_cpp_ref = (void *)TLobby::copy_state_block;

extern "C" {
s32 challenge_time_limit_sentinel;
s8 challenge_time_limit_initialized;
}


#undef challenge_mode_state

struct RecoveredGlobal_80070ACC_lbl_8048D208 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_8039994C_lbl_804F5800 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_80399904_lbl_804F5A00 {
    s32 value;
    u8 remaining[0xFC];
};

struct RecoveredGlobal_80399928_lbl_804F5900 {
    s32 value;
    u8 remaining[0xFC];
};

struct G_80070B34 { u8 pad[0x10]; s32 x10; u8 pad2[0x34 - 0x14]; s32 x34; };

extern "C" {
extern RecoveredGlobal_80070ACC_lbl_8048D208 lbl_8048D208;
s32 *TLobby__sub_80070ACC(void);
extern RecoveredGlobal_80399904_lbl_804F5A00 lbl_804F5A00;
u32 TLobby__sub_80070AD8(s32 arg0);
#define challenge_mode_state (*(G_80070B34 *)challenge_mode_state)
u8 is_flag_set__6TLobbyFv(void);
s32 mix_seed_checked__6TLobbyFi(s32);
void TLobby__sub_80070B34(s32 v);
void set_split_screen_flag__6TLobbyFv(void);

u8 is_flag_set__6TLobbyFv(void) {
    return (u8) ((*(s32 *)&challenge_task) != 0);
}

    extern int chat_last_line_buffer;
int TLobby::get_unit_list() {  return chat_last_line_buffer; }
typedef char RecoveredGlobal_80070ACC_lbl_8048D208_size[sizeof(RecoveredGlobal_80070ACC_lbl_8048D208) == 0x18 ? 1 : -1];
s32 *TLobby__sub_80070ACC(void) {
    return &lbl_8048D208.value;
}
typedef char RecoveredGlobal_8039994C_lbl_804F5800_size[sizeof(RecoveredGlobal_8039994C_lbl_804F5800) == 0x100 ? 1 : -1];
typedef char RecoveredGlobal_80399904_lbl_804F5A00_size[sizeof(RecoveredGlobal_80399904_lbl_804F5A00) == 0x100 ? 1 : -1];
u32 TLobby__sub_80070AD8(s32 arg0) {
    if (arg0 == -1) {
        return -1U;
    }
    return *(u8 *)((s8 *)((u8 *)&lbl_804F5A00.value + (u8) arg0) + 0);
}
void set_split_screen_flag__6TLobbyFv(void) {
    if (((s32 (*)(void))is_flag_set__6TLobbyFv)() != 0) {
        challenge_mode_state.x34 = 1;
    }
}
void TLobby__sub_80070B34(s32 v) {
    if (((s32 (*)(void))is_flag_set__6TLobbyFv)() != 0) {
        if (v < 0x3c || v > 0xe10) {
            return;
        }
        challenge_mode_state.x10 = mix_seed_checked__6TLobbyFi(v);
    }
}

typedef char RecoveredGlobal_80399928_lbl_804F5900_size[sizeof(RecoveredGlobal_80399928_lbl_804F5900) == 0x100 ? 1 : -1];

}

#undef challenge_mode_state

struct RecoveredGlobal_80070BE8_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct G_80070C50 { u8 pad[0xC]; s32 fc; u8 padc[0x10]; s32 f20; s32 f24; s32 f28; u8 pad2c[4]; s32 f30; u8 pad34[4]; s32 a38[4]; u8 pad48[0x680 - 0x48]; s32 a680[4]; u8 rest[0x100]; };

struct H_80070C50 { u8 pad[0x20]; s32 f20; s32 f24; s32 f28; };

extern "C" {

void TLobby__sub_80070BE8(s32 arg0);
void TLobby__sub_8026A328(void *);
void TLobby__sub_80070C50(void);
s32 TLobby::get_state() {
    if (((s32 (*)(void))is_flag_set__6TLobbyFv)() == 0) {
        return 0;
    }
    if (((s32) *(s32 *)((s8 *)challenge_mode_state + 0x2C) != 1) && ((s32) *(s32 *)((s8 *)challenge_mode_state + 0x2C) != 0)) {
        *(s32 *)((s8 *)challenge_mode_state + 0x2C) = 0;
    }
    return *(s32 *)((s8 *)challenge_mode_state + 0x2C);
}
typedef char RecoveredGlobal_80070BE8_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070BE8_lbl_8048C9D8) == 0x748 ? 1 : -1];
void TLobby__sub_80070BE8(s32 arg0) {
    s32 var_r31;
    var_r31 = arg0;
    if (((s32 (*)(void))is_flag_set__6TLobbyFv)() == 0) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80070BE8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x2C) = 0;
        return;
    }
    if ((var_r31 != 1) && (var_r31 != 0)) {
        var_r31 = 0;
    }
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80070BE8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x2C) = var_r31;
}
void TLobby__sub_80070C50(void) {
    s32 i;
    H_80070C50 *q;
    H_80070C50 *p = (*(H_80070C50 **)&challenge_task);
    if (p != NULL) {
        (*(G_80070C50 *)&challenge_mode_state).fc = 0;
        (*(G_80070C50 *)&challenge_mode_state).f20 = 0;
        (*(G_80070C50 *)&challenge_mode_state).f24 = -1;
        (*(G_80070C50 *)&challenge_mode_state).f28 = 0;
        (*(G_80070C50 *)&challenge_mode_state).f30 = 0;
        for (i = 0; i < 4; i++) {
            (*(G_80070C50 *)&challenge_mode_state).a38[i] = 0;
            (*(G_80070C50 *)&challenge_mode_state).a680[i] = 0;
        }
        p->f20 = 0;
        (*(H_80070C50 **)&challenge_task)->f24 = 0;
        q = (*(H_80070C50 **)&challenge_task);
        q->f28 = 1;
        TLobby__sub_8026A328(q);
    }
}

}

struct RecoveredGlobal_80070F4C_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_80070FD8_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_800713C8_lbl_804FF82C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80070DA8_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_80071064_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_80070EE4_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_8007119C_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct RecoveredGlobal_800710D8_lbl_8048C9D8 {
    s32 value;
    u8 remaining[0x744];
};

struct Entry_800712D8 {
    s32 value;
    s32 arg;
    u8 pad[0x14];
};

struct Table_800712D8 {
    u8 pad[0x21C];
    Entry_800712D8 entries[3];
};

struct Tbl_80070DCC { u8 pad[0x680]; s32 f680[4]; };

extern "C" {
void *get_player_by_client_id(s32 i);
s32 TLobby__sub_80070F4C(void);
s32 TLobby__sub_80070FD8(void);
s32 get_character_save_record(u32);
s32 decode_obfuscated_string__6TLobbyFPvi(void *, void *, int, int);
u8 lbl_804FF820[0xC];
RecoveredGlobal_800713C8_lbl_804FF82C lbl_804FF82C;
s32 *TLobby__sub_800713C8(void);
s32 TLobby__sub_80070DA8(void);
f32 fabs_float(f32);
}

void set_challenge_time_window_timer(int a0);
extern "C" {
void TLobby__sub_80071064(s32 arg0);
void TLobby__sub_80070EE4(s32 arg0);
s32 TLobby__sub_8006F6B0(int);

s32 TLobby__sub_8007119C(s32 arg0);
s32 **TWindowSubStatusDisp__sub_8006F134(s32, s32);
s32 forward_to_global_instance__23TAdSinglePlyChrSelectGCFi(s32 arg0);
s32 TLobby__sub_800710D8(s32 arg0);
s32 calc_layout_hash__20TWindowSubStatusDispFv(int);
s32 calc_entry_offset__20TWindowSubStatusDispFv(int);
s32 TLobby__sub_800712D8(s32 idx, s32 value, s32 arg);
extern s32 challenge_time_limit_sentinel;
extern s8 challenge_time_limit_initialized;
void *fn_800733C4(void *parent);

void TLobby::update_dead_list_win() {
    if ((((s32 (*)(void))is_flag_set__6TLobbyFv)() != 0) && (TLobby::is_ready_to_draw() != 0) && ((u32) challenge_task != 0U)) {
        TObjDeadListWin::create((TObject*)challenge_task);
    }
}

void TLobby::draw_if_ready() {
    if ((((s32 (*)(void))is_flag_set__6TLobbyFv)() != 0) && (TLobby::is_ready_to_draw() != 0) && ((u32) challenge_task != 0U)) {
        fn_800733C4((void *)challenge_task);
    }
}

s32 TLobby::check_ready_state() {
    s32 var_r3;

    var_r3 = TLobby__sub_80070DA8();
    if (var_r3 == 1) {
        var_r3 = -1;
        if ((s32) *(s32 *)((s8 *)challenge_mode_state + 0x28) != 0) {
            var_r3 = 1;
        }
    }
    return var_r3;
}
typedef char RecoveredGlobal_80070F4C_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070F4C_lbl_8048C9D8) == 0x748 ? 1 : -1];

typedef char RecoveredGlobal_80070DA8_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070DA8_lbl_8048C9D8) == 0x748 ? 1 : -1];
s32 TLobby__sub_80070DA8(void) {
    if ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_80070DA8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x20) != 0) {
        return *(s32 *)((s8 *)(&(*(RecoveredGlobal_80070DA8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x24);
    }
    return 0;
}

typedef char RecoveredGlobal_80070EE4_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070EE4_lbl_8048C9D8) == 0x748 ? 1 : -1];

s32 TLobby::get_max_challenge_time() {
    s32 times[4];
    s32 i;
    s32 best;
    s32 t;
    for (i = 0; i < 4; i++) {
        times[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0) {
            s32 v = ((Tbl_80070DCC *)challenge_mode_state)->f680[i];
            if (v == 0) {
                return -1;
            }
            t = TLobby::get_valid_slot(v);
            if (TLobby::check_challenge_time_range(t) != 0) {
                return -2;
            }
            times[i] = t;
        }
    }
    if (challenge_time_limit_initialized == 0) {
        challenge_time_limit_sentinel = TLobby::calc_challenge_time_limit() - 1;
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

void TLobby__sub_80070EE4(s32 arg0) {
    TLobby::check_challenge_time_range(arg0);
    fabs_float((f32) (arg0 - *(s32 *)((s8 *)(&(*(RecoveredGlobal_80070EE4_lbl_8048C9D8 *)&challenge_mode_state).value) + 0xC)));
    ((TLobby *)arg0)->send_seed_state();
}

s32 TLobby__sub_80070F4C(void) {
    u32 var_r31;
    u8 *player;
    if (((void *) (*(u8 * *)&challenge_task) == NULL) || ((s32) *(s32 *)((s8 *)(*(u8 * *)&challenge_task) + 0x1C) != 2)) {
        return 0;
    }
    var_r31 = 0;
loop_4:
    player = (u8 *)(get_player_by_client_id(var_r31));
    if ((player != NULL) && (((TLobby *)player)->check_player_state_flag_2() != 0)) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80070F4C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x20) = 1;
        return 1;
    }
    var_r31 += 1;
    if ((s32) var_r31 >= 4) {
        return 0;
    }
    goto loop_4;
}
typedef char RecoveredGlobal_80070FD8_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80070FD8_lbl_8048C9D8) == 0x748 ? 1 : -1];
s32 TLobby__sub_80070FD8(void) {
    u32 var_r31;
    u8 *player;
    if (((void *) (*(u8 * *)&challenge_task) == NULL) || ((s32) *(s32 *)((s8 *)(*(u8 * *)&challenge_task) + 0x1C) != 2)) {
        return 0;
    }
    var_r31 = 0;
loop_4:
    player = (u8 *)(get_player_by_client_id(var_r31));
    if ((player != NULL) && (((TLobby *)player)->check_player_state_flag_2() == 0)) {
        return 0;
    }
    var_r31 += 1;
    if ((s32) var_r31 >= 4) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80070FD8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x20) = 1;
        return 1;
    }
    goto loop_4;
}
typedef char RecoveredGlobal_800713C8_lbl_804FF82C_size[sizeof(RecoveredGlobal_800713C8_lbl_804FF82C) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_80071064_lbl_8048C9D8_size[sizeof(RecoveredGlobal_80071064_lbl_8048C9D8) == 0x748 ? 1 : -1];
void TLobby__sub_80071064(s32 arg0) {
    if (((s32 (*)(void))is_flag_set__6TLobbyFv)() != 0) {
        fabs_float((f32) (arg0 - *(s32 *)((s8 *)(&(*(RecoveredGlobal_80071064_lbl_8048C9D8 *)&challenge_mode_state).value) + 0xC)));
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_80071064_lbl_8048C9D8 *)&challenge_mode_state).value) + 0xC) = arg0;
        set_challenge_time_window_timer((arg0));
    }
}

typedef char RecoveredGlobal_8007119C_lbl_8048C9D8_size[sizeof(RecoveredGlobal_8007119C_lbl_8048C9D8) == 0x748 ? 1 : -1];

typedef char RecoveredGlobal_800710D8_lbl_8048C9D8_size[sizeof(RecoveredGlobal_800710D8_lbl_8048C9D8) == 0x748 ? 1 : -1];
s32 TLobby__sub_800710D8(s32 arg0) {
    s32 **temp_r3;
    s32 *var_r31;
    s32 *var_r4;
    s32 var_r30;
    s32 var_r3;
    s32 var_r5;
    var_r4 = (s32 *)(&(*(RecoveredGlobal_800710D8_lbl_8048C9D8 *)&challenge_mode_state).value);
    var_r31 = (s32 *)(&(*(RecoveredGlobal_800710D8_lbl_8048C9D8 *)&challenge_mode_state).value);
    var_r30 = arg0;
    if (((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_800710D8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) < 0) || ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_800710D8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) > 2)) {
        var_r3 = 0;
        return 0;
    }
    var_r3 = 0x10000;
    var_r3 = 0xFFFF;
    if (((u32)get_character_save_record((u32)(0xFFFF))) == 0U) {
        var_r3 = 0;
        return 0;
    }
    var_r3 = var_r30;
    if (forward_to_global_instance__23TAdSinglePlyChrSelectGCFi((var_r3)) != 0) {
        var_r4 = (s32 *)(&(*(RecoveredGlobal_800710D8_lbl_8048C9D8 *)&challenge_mode_state).value);
        var_r3 = 0x10000;
        var_r5 = *(s32 *)((s8 *)(&(*(RecoveredGlobal_800710D8_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) * 0x1C;
        var_r3 = 0xFFFF;
        var_r4 = (s32 *)((u8 *)(&(*(RecoveredGlobal_800710D8_lbl_8048C9D8 *)&challenge_mode_state).value) + var_r5);
        var_r31 = (s32 *)((u8 *)var_r4 + 0x21C);
        var_r3 = ((u32)get_character_save_record((u32)(0xFFFF))) + 0x21C4;
        var_r4 = (s32 *)((u8 *)((s32 *)-1));
        temp_r3 = (s32 **)(TWindowSubStatusDisp__sub_8006F134(var_r3, -1));
        var_r4 = (s32 *)(*(s32 **)((s8 *)temp_r3 + 0));
        *(s32 **)((s8 *)temp_r3 + 0) = (s32 *) ((s32) var_r4 | *(s32 *)((s8 *)var_r31 + 4));
        var_r3 = 1;
        return 1;
    }
    var_r3 = 0;
    return 0;
}

s32 TLobby__sub_8007119C(s32 arg0) {
    s32 temp_r3;
    s32 var_r31;
    var_r31 = arg0;
    if ((((s32 (*)(void))is_flag_set__6TLobbyFv)() == 0) || ((s32) *(s32 *)((s8 *)(&(*(RecoveredGlobal_8007119C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0) == -1) || (((u32)get_character_save_record((u32)(0xFFFF))) == 0U)) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_8007119C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) = -4;
        return -4;
    }
    fabs_float((f32) (var_r31 - *(s32 *)((s8 *)(&(*(RecoveredGlobal_8007119C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0xC)));
    if (TLobby::check_challenge_time_range(var_r31) != 0) {
        var_r31 = 0x8C9F;
    }
    temp_r3 = TLobby__sub_8006F6B0(var_r31);
    if (temp_r3 == -1) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_8007119C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) = -1;
        return -1;
    }
    if (temp_r3 < 0) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_8007119C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) = -2;
        return -2;
    }
    if (TLobby::calc_remaining_char_slots() == 0) {
        *(s32 *)((s8 *)(&(*(RecoveredGlobal_8007119C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) = -3;
        return -3;
    }
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_8007119C_lbl_8048C9D8 *)&challenge_mode_state).value) + 0x14) = temp_r3;
    return temp_r3;
}

#define TBL_800712D8 (*(Table_800712D8 *)challenge_mode_state)
s32 TLobby__sub_800712D8(s32 idx, s32 value, s32 arg) {
    s32 prev;
    Entry_800712D8 *e;
    Entry_800712D8 *p;
    Entry_800712D8 *end;
    if (idx < 0 || idx >= 3 || value < calc_entry_offset__20TWindowSubStatusDispFv(-1)) {
        return 0;
    }
    if (idx == 0) {
        value = calc_layout_hash__20TWindowSubStatusDispFv(-1);
    }
    e = &TBL_800712D8.entries[idx];
    if (e->value != 0) {
        return 0;
    }
    e->value = value;
    e->arg = arg;
    prev = 0x7FFFFFFF;
    end = &TBL_800712D8.entries[3];
    for (p = TBL_800712D8.entries; p < end; p++) {
        s32 v = p->value;
        if (v != 0) {
            if (prev <= v) {
                return 0;
            }
            prev = v;
        }
    }
    return 1;
}

s32 *TLobby__sub_800713C8(void) {
    s32 character_save_record;
    character_save_record = get_character_save_record(0xFFFFU);
    decode_obfuscated_string__6TLobbyFPvi((void *)&lbl_804FF82C.value, (void *)(character_save_record + 0x229C), 0xC, character_save_record);
    return &lbl_804FF82C.value;
}
}

struct RecoveredGlobal_80292574_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_80291F9C_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_802925C4_lbl_80540968 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_80292200_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

struct RecoveredGlobal_80292604_lbl_804DB1F0 {
    s32 value;
    u8 remaining[0x6AC];
};

extern "C" {
#define challenge_mode_state (*(s8 (*)[1])challenge_mode_state)
s32 add_entry__6TLobbyFiii(s32 arg0, s32 arg1, s32 arg2);

s32 add_entry__6TLobbyFiii(s32 src, s32 arg1, s32 arg2) {
    u8 *dst;

    if ((((s32 (*)(void))is_flag_set__6TLobbyFv)() == 0) || ((s32) *(s32 *)((s8 *)challenge_mode_state + 0x1C) < 0) || ((s32) *(s32 *)((s8 *)challenge_mode_state + 0x1C) >= 0x10)) {
        return 0;
    }
    dst = (unsigned char *) (challenge_mode_state + (*(s32 *)((s8 *)challenge_mode_state + 0x1C) * 0x1C) + 0x5C);
    TLobby::encode_name_xor((u8 *)dst, (u8 *)src, 0xC);
    TLobby::encode_name_xor(dst + 0xC, (u8 *)arg1, 0xC);
    *(s32 *)((s8 *)dst + 0x18) = arg2;
    *(s32 *)((s8 *)challenge_mode_state + 0x1C) = (s32) (*(s32 *)((s8 *)challenge_mode_state + 0x1C) + 1);
    return 1;
}
typedef char RecoveredGlobal_80291F9C_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80291F9C_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
typedef char RecoveredGlobal_80292200_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80292200_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
typedef char RecoveredGlobal_80292574_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80292574_lbl_804DB1F0) == 0x6B0 ? 1 : -1];
void TLobby::set_player_name_and_color(s32 arg1) {
    TLobby::encode_name_xor((u8 *)((u8 *)&(*(RecoveredGlobal_80292574_lbl_804DB1F0 *)&challenge_mode_state).value + 0x50), (u8 *)this, 0xC);
    *(s32 *)((s8 *)(&(*(RecoveredGlobal_80292574_lbl_804DB1F0 *)&challenge_mode_state).value) + 0x18) = (s32) (arg1 | 0xFF000000);
}
typedef char RecoveredGlobal_802925C4_lbl_80540968_size[sizeof(RecoveredGlobal_802925C4_lbl_80540968) == 0x20 ? 1 : -1];
typedef char RecoveredGlobal_80292604_lbl_804DB1F0_size[sizeof(RecoveredGlobal_80292604_lbl_804DB1F0) == 0x6B0 ? 1 : -1];

#undef challenge_mode_state
u8 *get_char_index__23TAdSinglePlyChrSelectGCFUi(s32);
s32 get_layout_id__20TWindowSubStatusDispFv(s32);

void TLobby::set_selected_layout(s32 arg0) {
    s32 temp_r3;
    s32 var_r31;

    var_r31 = arg0;
    temp_r3 = get_layout_id__20TWindowSubStatusDispFv(-1);
    if ((var_r31 < 0) || (var_r31 >= temp_r3)) {
        var_r31 = 0;
    }
    challenge_mode_state[0] = var_r31;
}

s32 TLobby::calc_remaining_char_slots() {
    s32 var_r3;

    var_r3 = 0x1E - *get_char_index__23TAdSinglePlyChrSelectGCFUi(0xFFFF);
    if (var_r3 < 0) {
        var_r3 = 0;
    }
    return var_r3;
}

}

struct E_80071698 { s32 f0; u8 pad[0x100]; };

struct G_80071698 { u8 pad[0x270]; E_80071698 e[4]; };

extern "C" {
u32 TLobby__sub_80071640(u32 c);

s32 TLobby__sub_80071B30(s32, s32);

s32 TLobby__sub_80071654(s32 arg0);


s32 TLobby::try_set_value(f32 farg0) {
    if (((s32 (*)(void))is_flag_set__6TLobbyFv)() == 0) {
        return 0;
    }
    if ((farg0 < 0.01f) || (farg0 > 10000.0f)) {
        return 0;
    }
    *(f32 *)((s8 *)&challenge_mode_state + 4) = farg0;
    return 1;
}

extern s32 game_difficulty_selection;

s32 TLobby::set_split_screen_flag(s32 arg0) {
    if (((s32 (*)(void))is_flag_set__6TLobbyFv)() == 0) {
        return 0;
    }
    game_difficulty_selection = arg0;
    return 1;
}

u32 TLobby__sub_80071640(u32 c) {
    return ((c >> 9) & 0x7C00) | ((c >> 6) & 0x3E0) | ((c >> 3) & 0x1F);
}

s32 TLobby__sub_80071654(s32 arg0) {
    return ((arg0 * 8) & 0xF8) | (((arg0 << 9) & 0xF80000) | 0xFF000000 | ((arg0 << 6) & 0xF800));
}
s32 TLobby::count_set_bits(u32 x) {
    s32 n = 0;
    while (x != 0) {
        if (x & 1) {
            n++;
        }
        x >>= 1;
    }
    return n;
}
s32 TLobby::get_party_min_tier(s32 arg0) {
    s32 best;
    s32 i;
    s32 t;
    best = ((s32 (*)(void))get_layout_id__20TWindowSubStatusDispFv)();
    for (i = 0; i < 4; i++) {
        if (get_player_by_client_id(i) != 0U) {
            if (((G_80071698 *)challenge_mode_state)->e[i].f0 == 0) {
                return -1;
            }
            t = TLobby__sub_80071B30(i, arg0);
            if (best > t) {
                best = t;
            }
        }
    }
    return best;
}

}
