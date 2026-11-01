#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/misc/TWindowSubComCard_80265410.h"
#include "pso/ui/TAdEnterBaseGC_8032B38C.h"
#include "pso/ui/TAdEnterSerialAccessGC_8032AD30.h"
#include "pso/unk/text_8032AC9C.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowMakeTeam.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct Lim_8032B1A4 { u32 n[4]; };

struct B4_8032AD30 { u8 b[4]; };

extern char lbl_80477188[];
extern char lbl_80477190[];
extern "C" {
s32 update_window_mode_from_progress__6TLobbyFPv(void *, void *);
extern u8 lbl_80477178[];
extern u8 lbl_80477180[];
int sprintf(char *, const char *, ...);
void sscanf(int, const char *, ...);
s32 memset(s32, s32, s32);
extern char lbl_80477260[];
extern char lbl_80477268[];
extern char serial_access_hex_string_buf[];
u8 *get_access_key_input_buffer();
u8 *get_raw_serial_input_buffer();
u8 *TAdEnterPasswordGC__sub_8013ADE4();
u32 get_field_118__22TAdEnterSerialAccessGCFv();
extern u32 serial_access_entered_value_table[];
extern u8 lbl_805DF77C[4];
s32 TAdEndText__sub_8001B3BC(int);
s32 TAdEndText__sub_8001B3EC(int);
u32 strlen(const char *);
extern Lim_8032B1A4 serial_input_max_length_table;
extern Lim_8032B1A4 serial_access_input_limits;
s32 TKeyBoardControl__ct(void *, s32, s32, s32, s32, s32);
void *__nw__7TObjectFUl(s32);
int get_keyboard_field_6c__15TWindowMakeTeamFv(void* p);
extern s32 serial_keyboard_field_width_table[];
extern u8 serial_keyboard_position_table[][8];
extern s32 local_client_id;
extern B4_8032AD30 lbl_805DF770;
s32 strncpy(s32, s32, s32);

u32 TAdEnterSerialAccessGC::create_keyboard_control(s32 arg0, s32 arg1) {
    u8 *kb;
    if (arg1 < 0 || arg1 >= 4) {
        return 0;
    }
    B4_8032AD30 sp8 = lbl_805DF770;
    kb = (u8 *)__nw__7TObjectFUl(0x2C);
    if (kb != NULL) {
        kb = (u8 *)TKeyBoardControl__ct(kb, arg0, serial_keyboard_field_width_table[arg1], 0, sp8.b[arg1], local_client_id);
    }
    if (kb == NULL) {
        return 0;
    }
    ((TWindowMakeTeam *)kb)->set_sub_position(serial_keyboard_position_table[arg1]);
    if (((s32 (*)(s32, s32))has_serial_input__22TAdEnterSerialAccessGCFv)(arg0, arg1) != 0) {
        ((int (*)(void *, u8 *))get_keyboard_field_6c__15TWindowMakeTeamFv)(kb, get_serial_text__22TAdEnterSerialAccessGCFii(arg0, arg1));
    }
    if (arg1 != 3) {
        update_chat_window(kb);
    }
    return (u32)kb;
}

void TAdEnterSerialAccessGC::create_default_callback() {
    TAdEnterSerialAccessGC::create_callback(lbl_80477188, lbl_80477190, (void *)fn_8032AC9C);
}

s32 TAdEnterSerialAccessGC::show_message_window(void *arg0, void *arg1) {
    s32 r = update_window_mode_from_progress__6TLobbyFPv(lbl_80477178, lbl_80477180);
    ((TWindowMessage *)r)->append_line(get_localized_text_entry(0x17, (s32)arg1), 1);
    return r;
}

u8 *get_serial_text__22TAdEnterSerialAccessGCFii(s32 arg0, s32 arg1) {
    if (arg1 == 3) {
        return lbl_805DF77C;
    }
    if (arg1 == 2 && TAdPsoPassSaveGC__sub_8032B584() == 0) {
        return lbl_805DF77C;
    }
    if (*(s8 *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1152C) != 0) {
        switch (arg1) {
        case 0:
            return (u8 *) TAdEnterSerialAccessGC::serial_to_hex_string(TAdSinglePlyChrSelectGC::get_instance() + 0x1152C);
        case 1:
            return (u8 *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1153C);
        case 2:
            return (u8 *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1154C);
        }
    } else if (serial_access_entered_value_table[arg1] == get_field_118__22TAdEnterSerialAccessGCFv()) {
        switch (arg1) {
        case 0:
            return get_raw_serial_input_buffer();
        case 1:
            return get_access_key_input_buffer();
        case 2:
            return TAdEnterPasswordGC__sub_8013ADE4();
        }
    }
    return lbl_805DF77C;
}

s32 has_serial_input__22TAdEnterSerialAccessGCFv(void) {
    return (s8) *((u8 *(*)(void))get_serial_text__22TAdEnterSerialAccessGCFii)() ? 1 : 0;
}

void TAdEnterSerialAccessGC::clear_serial_buffer() {
    u32 instance;

    instance = TAdSinglePlyChrSelectGC::get_instance();
    if (instance != 0U) {
        memset(instance + 0x1154C, 0, 0x10);
    }
}
}

void clear_state(void) {
    s32 instance;

    instance = TAdSinglePlyChrSelectGC::get_instance();
    if (instance != 0) {
        memset(instance + 0x1152C, 0, 0x10);
        memset(instance + 0x1153C, 0, 0x10);
        memset(instance + 0x1154C, 0, 0x10);
    }
}

void TAdEnterSerialAccessGC::store_serial_access_key(s32 arg0, s32 arg1, s32 arg2) {
    s32 instance;

    instance = TAdSinglePlyChrSelectGC::get_instance();
    if (instance != 0) {
        strncpy(instance + 0x1152C, arg0, 0xF);
        strncpy(instance + 0x1153C, arg1, 0xF);
        if (TAdPsoPassSaveGC__sub_8032B584() != 0) {
            strncpy(instance + 0x1154C, arg2, 0xF);
        }
    }
}

char *TAdEnterSerialAccessGC::serial_to_hex_string(int arg0) {
    u32 v = 0;
    sscanf(arg0, lbl_80477260, &v);
    memset((s32)((s32)serial_access_hex_string_buf), 0, 0x40);
    if (v != 0) {
        sprintf(serial_access_hex_string_buf, lbl_80477268, v);
    }
    return serial_access_hex_string_buf;
}

int validate_input__22TAdEnterSerialAccessGCFPviPv(void *arg0, s32 arg1, char *arg2) {
    s32 i;
    s32 n;

    Lim_8032B1A4 max = serial_input_max_length_table;
    max.n[2] = strlen(arg2);
    max.n[3] = strlen(arg2);
    Lim_8032B1A4 min = serial_access_input_limits;
    if (strlen(arg2) < min.n[arg1]) {
        return 0;
    }
    switch (arg1) {
    case 0:
    case 1:
        n = max.n[arg1];
        for (i = 0; i < n; i++, arg2++) {
            if (TAdEndText__sub_8001B3BC(*arg2) == 0) {
                return 0;
            }
        }
        break;
    case 2:
        n = max.n[arg1];
        for (i = 0; i < n; i++, arg2++) {
            if (TAdEndText__sub_8001B3EC(*arg2) == 0) {
                return 0;
            }
        }
        break;
    case 3:
        break;
    }
    return 1;
}

int TAdEnterSerialAccessGC::forward_input(void* p) { return ((int (*)(void *))validate_input__22TAdEnterSerialAccessGCFPviPv)(p); }
