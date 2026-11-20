#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"

#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/task/TObject.h"

#include "pso/system/task/TObject_80019A50.h"

#include "pso/ui/frontend/TAdEnterBaseGC.h"

#include "pso/ui/frontend/TAdEnterBaseGC_8032B38C.h"

#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

#include "pso/ui/frontend/TAdEnterSerialAccessGC_8032AD30.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/ui/frontend/TAdSubPlyItemGC.h"

#include "pso/ui/window/TWindowMakeTeam.h"

#include "pso/ui/window/TWindowMessage.h"

#include "pso/ui/window/TWindowSubComCard_80265410.h"

#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

#include "pso/unk/TLobby.h"

#include "pso/unk/TLobby_80132ED0.h"

#include "pso/unk/text_8032AACC.h"

#include "pso/unk/text_8032AC9C.h"
#include "pso/system/NinjaTypes.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

struct Plate_8032AACC { u8 data[0x3B4]; };

struct Word_8032AACC { s32 v; };

struct Arg_8032AACC { f32 x, y; u8 pad[8]; };

struct Plate_8032AC24 { u8 data[0x3B4]; };

struct Word_8032AC24 { s32 v; };

struct Arg_8032AC24 { f32 x, y; u8 pad[8]; };

struct Lim_8032B1A4 { u32 n[4]; };

struct B4_8032AD30 { u8 b[4]; };

// The TU's .rodata starts at 0x80477178, right after TAdMcSelectMcGC's int->float double; only this file uses these.
// show_message_window: position and size of the message window it opens.
const f32 lbl_80477178[2] = {46.0f, 110.0f};

const f32 lbl_80477180[2] = {548.0f, 120.0f};

// create_default_callback: the two rects passed to TAdEnterSerialAccessGC::create_callback.
const f32 lbl_80477188[2] = {73.0f, 220.0f};

const f32 lbl_80477190[2] = {494.0f, 60.0f};

// create_parts: TAdSelectCurGC rects; entry mode 3 starts at the third position and the second size.
const TAdEnterBaseGC::Position lbl_80477198[4] = {{155.0f, 231.0f}, {155.0f, 251.0f}, {87.0f, 231.0f}, {87.0f, 251.0f}};

const TAdEnterBaseGC::Position lbl_804771B8[2] = {{330.0f, 20.0f}, {466.0f, 18.0f}};

const s32 serial_keyboard_field_width_table[4] = {10, 12, 8, 31};

// fn_8032B318: anchor of the centred text.
const f32 lbl_804771D8[2] = {320.0f, 250.0f};

const f32 serial_keyboard_position_table[4][2] = {{234.0f, 500.0f}, {234.0f, 500.0f}, {256.0f, 230.0f}, {87.0f, 500.0f}};

// inferred: names follow the users. fn_8032AC24 and draw_masked_password_field each draw a box
// (TAdEnterSerialAccessGC__sub_802C4B64: position, 4-byte vertex color) on a TAdPlyChrSelPlateGC of the given size.
const f32 entry_field_box_pos[2] = {256.0f, 230.0f};

const f32 entry_field_box_size[2] = {120.0f, 18.0f};

const f32 password_field_box_pos[2] = {87.0f, 230.0f};

const f32 password_field_box_size[2] = {466.0f, 18.0f};

const f32 password_field_text_pos[2] = {87.0f, 230.0f};

const Word_8032AC24 entry_field_box_color = {0xFF};

const Word_8032AACC password_field_box_color = {0xFF};

// inferred: per-field mode passed to the TKeyBoardControl ctor by create_keyboard_control.
const B4_8032AD30 serial_keyboard_mode_table = {3, 3, 2, 0};

const char *TAdEnterBaseGC__class_name = "TAdEnterBaseGC";

TAdEnterBaseGC::Position password_screen_status_line_position[1] = {0.0f, 0.0f};

u32 serial_access_entered_value_table[4] = {0};

// The TU's .sbss, in this order; TAdEnterPasswordGC and TAdEnterPPPPassGC share the first two.
void *password_entry_keyboard_control;

s32 password_entry_dispatch_state;

s32 TAdEnterBaseGC__entry_mode;

extern "C" {



void fn_8025DE10(void *arg0, void *arg1);

void TAdEnterSerialAccessGC__sub_802C4B64(void *, const void *, const void *, int);

void __dt__19TAdPlyChrSelPlateGCFv(void *, int);

void *__ct__19TAdPlyChrSelPlateGCFv(void *, s32, void *);

void *memset(void *, int, u32);

u32 strlen(const char *);

void draw_window_frame__11TWindowBaseFPv();



int sprintf(char *, const char *, ...);

void sscanf(int, const char *, ...);

extern char serial_access_hex_string_buf[];

u8 *get_access_key_input_buffer();

u8 *get_raw_serial_input_buffer();

u8 *TAdEnterPasswordGC__sub_8013ADE4();

u32 get_field_118__22TAdEnterSerialAccessGCFv();

s32 TAdEndText__sub_8001B3BC(int);

s32 TAdEndText__sub_8001B3EC(int);


u32 __nw__7TObjectFUl(int);


extern s32 local_client_id;

s32 strncpy(s32, s32, s32);
}
extern s32 tl_clipout;
char serial_access_hex_string_buf[0x40];

extern "C" {

s32 __ct__9TAdBackGCFv(int, void *);

s32 __ct__12TAdBackTxtGCFv(int, void *);

u32 __ct__14TAdSelectCurGCFv(int, int, const void *, const void *);

}

extern s32 TAdPsoPassSaveGC__data_805D6E80;

s32 TAdPsoPassSaveGC__sub_8032B584(void) {
    return TAdPsoPassSaveGC__data_805D6E80;
}

TAdEnterBaseGC::TAdEnterBaseGC(TObject *parent) : TObject(parent) {
    m_name = TAdEnterBaseGC__class_name;
    sub_8032B460(0);
}

TAdEnterBaseGC::~TAdEnterBaseGC() {
    if (*(void **)((s8 *)this + 0x2C) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x2C)))->queue_destruction(); *(s32 *)((s8 *)this + 0x2C) = 0; }
    if (*(void **)((s8 *)this + 0x30) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x30)))->queue_destruction(); this->m_30 = 0; }
    if (*(void **)((s8 *)this + 0x34) != NULL) { ((TObject *)(*(void **)((s8 *)this + 0x34)))->queue_destruction(); *(s32 *)((s8 *)this + 0x34) = 0; }
}


void TAdEnterBaseGC::sub_8032B460(int a1) { *(int *)&this->m_24 = 0; this->m_20 = 0; TAdEnterBaseGC__entry_mode = a1; *(int*)((char*)this + 0x38) = 0; *(int*)((char*)this + 0x3c) = 0; this->m_28 = 0; *(int *)&this->unk_2C = 0; this->m_30 = 0; *(int *)&this->unk_34 = 0; password_entry_keyboard_control = 0; }

void TAdEnterBaseGC::create_parts() {
    u32 temp_r3;
    u32 temp_r3_2;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 var_r0;
    u32 var_r0_2;
    temp_r3 = __nw__7TObjectFUl(0x24);
    if (temp_r3 != 0U) {
        __ct__9TAdBackGCFv(temp_r3, this);
    }
    temp_r3_2 = __nw__7TObjectFUl(0x28);
    if (temp_r3_2 != 0U) {
        __ct__12TAdBackTxtGCFv(temp_r3_2, this);
    }
    if ((s32) (*(s32 *)&TAdEnterBaseGC__entry_mode) == 3) {
        temp_r3_3 = __nw__7TObjectFUl(0x708);
        var_r0 = temp_r3_3;
        if (var_r0 != 0U) {
            var_r0 = __ct__14TAdSelectCurGCFv(temp_r3_3, tl_clipout, &lbl_80477198[2], &lbl_804771B8[1]);
        }
        *(u32 *)&this->unk_2C = var_r0;
        return;
    }
    temp_r3_4 = __nw__7TObjectFUl(0x708);
    var_r0_2 = temp_r3_4;
    if (var_r0_2 != 0U) {
        var_r0_2 = __ct__14TAdSelectCurGCFv(temp_r3_4, tl_clipout, lbl_80477198, lbl_804771B8);
    }
    *(u32 *)&this->unk_2C = var_r0_2;
}

void TAdEnterBaseGC::run_task() {  }


void TAdEnterBaseGC::fn_8032B318(Position *position) {
    u32 half_width = calc_text_width((char *)get_localized_text_entry(23, 4)) >> 1;
    f32 offset = half_width;
    f32 x = lbl_804771D8[0];
    offset = x - offset;
    position->x = offset;
    position->y = lbl_804771D8[1];
}

int TAdEnterSerialAccessGC::forward_input(void* p) { return ((int (*)(void *))validate_input__22TAdEnterSerialAccessGCFPviPv)(p); }

int validate_input__22TAdEnterSerialAccessGCFPviPv(void *arg0, s32 arg1, char *arg2) {
    s32 i;
    s32 n;

    Lim_8032B1A4 max = {10, 12, 8, 31};
    max.n[2] = strlen(arg2);
    max.n[3] = strlen(arg2);
    Lim_8032B1A4 min = {10, 12, 1, 0};
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

char *TAdEnterSerialAccessGC::serial_to_hex_string(int arg0) {
    u32 v = 0;
    sscanf(arg0, "%08X", &v);
    memset(serial_access_hex_string_buf, 0, 0x40);
    if (v != 0) {
        sprintf(serial_access_hex_string_buf, "%010lu", v);
    }
    return serial_access_hex_string_buf;
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

void clear_state(void) {
    u8 *instance;

    instance = (u8 *)TAdSinglePlyChrSelectGC::get_instance();
    if (instance != NULL) {
        memset(instance + 0x1152C, 0, 0x10);
        memset(instance + 0x1153C, 0, 0x10);
        memset(instance + 0x1154C, 0, 0x10);
    }
}


void TAdEnterSerialAccessGC::clear_serial_buffer() {
    u8 *instance;

    instance = (u8 *)TAdSinglePlyChrSelectGC::get_instance();
    if (instance != NULL) {
        memset(instance + 0x1154C, 0, 0x10);
    }
}

s32 has_serial_input__22TAdEnterSerialAccessGCFv(void) {
    return (s8) *((u8 *(*)(void))get_serial_text__22TAdEnterSerialAccessGCFii)() ? 1 : 0;
}

u8 *get_serial_text__22TAdEnterSerialAccessGCFii(s32 arg0, s32 arg1) {
    if (arg1 == 3) {
        return (u8 *)"";
    }
    if (arg1 == 2 && TAdPsoPassSaveGC__sub_8032B584() == 0) {
        return (u8 *)"";
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
    return (u8 *)"";
}

s32 TAdEnterSerialAccessGC::show_message_window(void *arg0, void *arg1) {
    s32 r = (s32)create_message_window_for_size((NJS_POINT2 *)lbl_80477178, (NJS_POINT2 *)lbl_80477180);
    ((TWindowMessage *)r)->append_line(get_localized_text_entry(0x17, (s32)arg1), 1);
    return r;
}

void TAdEnterSerialAccessGC::create_default_callback() {
    TAdEnterSerialAccessGC::create_callback((void *)lbl_80477188, (void *)lbl_80477190, (void *)fn_8032AC9C);
}

u32 TAdEnterSerialAccessGC::create_keyboard_control(s32 arg0, s32 arg1) {
    u8 *kb;
    if (arg1 < 0 || arg1 >= 4) {
        return 0;
    }
    B4_8032AD30 sp8 = serial_keyboard_mode_table;
    kb = (u8 *)new TKeyBoardControl((TObject *)arg0, serial_keyboard_field_width_table[arg1], 0, sp8.b[arg1], local_client_id);
    if (kb == NULL) {
        return 0;
    }
    ((TKeyBoardControl *)kb)->set_sub_position((u8 *)serial_keyboard_position_table[arg1]);
    if (((s32 (*)(s32, s32))has_serial_input__22TAdEnterSerialAccessGCFv)(arg0, arg1) != 0) {
        ((TKeyBoardControl *)kb)->set_text((char *)get_serial_text__22TAdEnterSerialAccessGCFii(arg0, arg1));
    }
    if (arg1 != 3) {
        update_chat_window(kb);
    }
    return (u32)kb;
}

void fn_8032AC9C(void *arg0, void *arg1) {
    draw_window_frame__11TWindowBaseFPv();
    TAdSubPlyItemGC::render_status_line(password_screen_status_line_position[0].x, password_screen_status_line_position[0].y, 0.8f, (const char *)get_localized_text_entry(0x17, 4), -1);
    switch (TAdEnterBaseGC__entry_mode) {
    case 0:
    case 1:
        fn_8032AC94();
        return;
    case 2:
        fn_8032AC24();
        return;
    case 3:
        draw_masked_password_field((s32)arg1);
        return;
    }
}


void TAdEnterBaseGC::render() {  }

void fn_8032AC94(void) {  }

void fn_8032AC24(void) {
    Plate_8032AC24 plate;
    Arg_8032AC24 p1;
    const f32 *src = entry_field_box_size;
    p1.x = src[0];
    p1.y = src[1];
    __ct__19TAdPlyChrSelPlateGCFv(&plate, tl_clipout, &p1);
    Word_8032AC24 w = entry_field_box_color;
    TAdEnterSerialAccessGC__sub_802C4B64(&plate, entry_field_box_pos, &w, 0);
    __dt__19TAdPlyChrSelPlateGCFv(&plate, -1);
}

void draw_masked_password_field(s32 arg0) {
    char buf[0x80];
    Plate_8032AACC plate;
    char *str;
    s32 len;
    s32 i;
    char *q;
    if (password_entry_keyboard_control != 0) {
        Arg_8032AACC p1;
        p1.x = password_field_box_size[0];
        p1.y = password_field_box_size[1];
        __ct__19TAdPlyChrSelPlateGCFv(&plate, tl_clipout, &p1);
        Word_8032AACC w = password_field_box_color;
        TAdEnterSerialAccessGC__sub_802C4B64(&plate, password_field_box_pos, &w, 0);
        str = ((TKeyBoardControl *)password_entry_keyboard_control)->realloc_buffer();
        len = strlen(str);
        mem_free(str);
        memset(buf, 0, 0x80);
        q = buf;
        for (i = 0; i < len; i++) {
            *q++ = '*';
        }
        buf[len] = 0;
        len = calc_text_width("*");
        ((TAdSinglePlyChrSelectGC *)buf)->render_status_disp(password_field_text_pos[0], password_field_text_pos[1]);
        NJS_POINT2 p2;
        p2.x = password_field_text_pos[0] + (f32) (len * ((TAdEnterSerialAccessGC *)password_entry_keyboard_control)->get_field20_state());
        p2.y = password_field_text_pos[1];
        fn_8025DE10((void *)arg0, &p2);
        __dt__19TAdPlyChrSelPlateGCFv(&plate, -1);
    }
}

#undef TOBJECT_OUT_OF_LINE_HELPERS
