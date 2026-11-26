#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#define TOBJECT_OUT_OF_LINE_HELPERS

#include "types.h"
#include "pso/ui/frontend/TAdEndText.h"
#include "pso/ui/window/TWindowBase.h"
#include <stdio.h>
#include <string.h>
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"

#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/task/TObject.h"

#include "pso/ui/frontend/TAdEnterBaseGC.h"

#include "pso/ui/frontend/TAdPsoPassSaveGC.h"

#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"


#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/save/CharacterFile.h"

#include "pso/ui/frontend/TAdSubPlyItemGC.h"

#include "pso/ui/window/TWindowMakeTeam.h"

#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowCallBack.h"

#include "pso/ui/window/TWindowSubComCard_80265410.h"

#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"

#include "pso/network/TLobby.h"

#include "pso/unk/TLobby_80132ED0.h"


#include "pso/system/NinjaTypes.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/MenuText.h"

struct LengthLimits { u32 n[4]; };

struct KeyboardModes { u8 b[4]; };

// The TU's .rodata starts at 0x80477178, right after TAdMcSelectMcGC's int->float double; only this file uses these.
// show_message_window: position and size of the message window it opens.
const f32 enter_base_message_window_position[2] = {46.0f, 110.0f};

const f32 enter_base_message_window_size[2] = {548.0f, 120.0f};

// create_default_callback: the two rects passed to TAdEnterSerialAccessGC::create_callback.
const f32 enter_base_callback_position[2] = {73.0f, 220.0f};

const f32 enter_base_callback_size[2] = {494.0f, 60.0f};

// create_parts: TAdSelectCurGC rects; entry mode 3 starts at the third position and the second size.
const TAdEnterBaseGC::Position enter_base_cursor_positions[4] = {{155.0f, 231.0f}, {155.0f, 251.0f}, {87.0f, 231.0f}, {87.0f, 251.0f}};

const TAdEnterBaseGC::Position enter_base_cursor_sizes[2] = {{330.0f, 20.0f}, {466.0f, 18.0f}};

const s32 serial_keyboard_field_width_table[4] = {10, 12, 8, 31};

// fn_8032B318: anchor of the centred text.
const f32 enter_base_text_anchor[2] = {320.0f, 250.0f};

const f32 serial_keyboard_position_table[4][2] = {{234.0f, 500.0f}, {234.0f, 500.0f}, {256.0f, 230.0f}, {87.0f, 500.0f}};

// inferred: names follow the users. fn_8032AC24 and draw_masked_password_field each draw a box
// (TAdEnterSerialAccessGC__sub_802C4B64: position, 4-byte vertex color) on a TAdPlyChrSelPlateGC of the given size.
const NJS_POINT2 entry_field_box_pos = {256.0f, 230.0f};

const f32 entry_field_box_size[2] = {120.0f, 18.0f};

const NJS_POINT2 password_field_box_pos = {87.0f, 230.0f};

const f32 password_field_box_size[2] = {466.0f, 18.0f};

const f32 password_field_text_pos[2] = {87.0f, 230.0f};

const NJS_COLOR entry_field_box_color = {0xFF};

const NJS_COLOR password_field_box_color = {0xFF};

// inferred: per-field mode passed to the TKeyBoardControl ctor by create_keyboard_control.
const KeyboardModes serial_keyboard_mode_table = {3, 3, 2, 0};

const char *TAdEnterBaseGC::class_name = "TAdEnterBaseGC";

TAdEnterBaseGC::Position password_screen_status_line_position[1] = {0.0f, 0.0f};

u32 serial_access_entered_value_table[4] = {0};

// The TU's .sbss, in this order; TAdEnterPasswordGC and TAdEnterPPPPassGC share the first two.
TKeyBoardControl *password_entry_keyboard_control;

s32 password_entry_dispatch_state;

s32 TAdEnterBaseGC::entry_mode;

extern "C" {



extern char serial_access_hex_string_buf[];

u8 *get_access_key_input_buffer();

u8 *get_raw_serial_input_buffer();


}
extern s32 tl_clipout;
char serial_access_hex_string_buf[0x40];


s32 TAdPsoPassSaveGC__sub_8032B584(void) {
    return TAdPsoPassSaveGC__data_805D6E80;
}

TAdEnterBaseGC::TAdEnterBaseGC(TObject *parent) : TObject(parent) {
    m_name = TAdEnterBaseGC::class_name;
    sub_8032B460(0);
}

TAdEnterBaseGC::~TAdEnterBaseGC() {
    if (this->select_cursor != NULL) { ((TObject *)this->select_cursor)->queue_destruction(); *(s32 *)((s8 *)this + 0x2C) = 0; }
    if (prompt_window != NULL) { prompt_window->queue_destruction(); prompt_window = NULL; }
    if (callback_window != NULL) { callback_window->queue_destruction(); callback_window = NULL; }
}

void TAdEnterBaseGC::sub_8032B460(int a1) { this->close_delay_ticks = 0; this->pending_dispatch_state = 0; TAdEnterBaseGC::entry_mode = a1; *(int*)((char*)this + 0x38) = 0; *(int*)((char*)this + 0x3c) = 0; this->m_28 = 0; this->select_cursor = NULL; prompt_window = NULL; callback_window = NULL; password_entry_keyboard_control = 0; }

void TAdEnterBaseGC::create_parts() {
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    if (TAdEnterBaseGC::entry_mode == 3) {
        this->select_cursor = new TAdSelectCurGC(reinterpret_cast<TObject *>(tl_clipout),
            reinterpret_cast<const NJS_POINT2 *>(&enter_base_cursor_positions[2]),
            reinterpret_cast<const NJS_POINT2 *>(&enter_base_cursor_sizes[1]));
        return;
    }
    this->select_cursor = new TAdSelectCurGC(reinterpret_cast<TObject *>(tl_clipout),
        reinterpret_cast<const NJS_POINT2 *>(enter_base_cursor_positions),
        reinterpret_cast<const NJS_POINT2 *>(enter_base_cursor_sizes));
}

void TAdEnterBaseGC::run_task() {  }

void TAdEnterBaseGC::fn_8032B318(Position *position) {
    u32 half_width = calc_text_width((char *)get_localized_text_entry(23, 4)) >> 1;
    f32 offset = half_width;
    f32 x = enter_base_text_anchor[0];
    offset = x - offset;
    position->x = offset;
    position->y = enter_base_text_anchor[1];
}

int TAdEnterSerialAccessGC::forward_input(void *window, s32 mode, const char *buf) { return validate_input__22TAdEnterSerialAccessGCFPviPv(window, mode, buf); }

int validate_input__22TAdEnterSerialAccessGCFPviPv(void *window, s32 mode, const char *text) {
    s32 i;
    s32 n;

    LengthLimits max = {10, 12, 8, 31};
    max.n[2] = strlen(text);
    max.n[3] = strlen(text);
    LengthLimits min = {10, 12, 1, 0};
    if (strlen(text) < min.n[mode]) {
        return 0;
    }
    switch (mode) {
    case 0:
    case 1:
        n = max.n[mode];
        for (i = 0; i < n; i++, text++) {
            if (is_digit(*text) == 0) {
                return 0;
            }
        }
        break;
    case 2:
        n = max.n[mode];
        for (i = 0; i < n; i++, text++) {
            if (is_alnum(*text) == 0) {
                return 0;
            }
        }
        break;
    case 3:
        break;
    }
    return 1;
}

char *TAdEnterSerialAccessGC::serial_to_hex_string(const char *serial) {
    u32 v = 0;
    sscanf(serial, "%08X", &v);
    memset(serial_access_hex_string_buf, 0, 0x40);
    if (v != 0) {
        sprintf(serial_access_hex_string_buf, "%010lu", v);
    }
    return serial_access_hex_string_buf;
}

void TAdEnterSerialAccessGC::store_serial_access_key(saddr serial, saddr access_key, saddr password) {
    CharacterFile *instance;

    instance = TAdSinglePlyChrSelectGC::get_instance();
    if (instance != 0) {
        strncpy(instance->serial_number, (const char *)serial, 0xF);
        strncpy(instance->access_key, (const char *)access_key, 0xF);
        if (TAdPsoPassSaveGC__sub_8032B584() != 0) {
            strncpy(instance->password, (const char *)password, 0xF);
        }
    }
}

void clear_state(void) {
    CharacterFile *instance;

    instance = TAdSinglePlyChrSelectGC::get_instance();
    if (instance != NULL) {
        memset(instance->serial_number, 0, 0x10);
        memset(instance->access_key, 0, 0x10);
        memset(instance->password, 0, 0x10);
    }
}

void TAdEnterSerialAccessGC::clear_serial_buffer() {
    CharacterFile *instance;

    instance = TAdSinglePlyChrSelectGC::get_instance();
    if (instance != NULL) {
        memset(instance->password, 0, 0x10);
    }
}

s32 has_serial_input__22TAdEnterSerialAccessGCFv(s32 parent, s32 field) {
    return (s8)*get_serial_text__22TAdEnterSerialAccessGCFii(parent, field) ? 1 : 0;
}

u8 *get_serial_text__22TAdEnterSerialAccessGCFii(s32 owner, s32 field) {
    if (field == 3) {
        return (u8 *)"";
    }
    if (field == 2 && TAdPsoPassSaveGC__sub_8032B584() == 0) {
        return (u8 *)"";
    }
    if (TAdSinglePlyChrSelectGC::get_instance()->serial_number[0] != 0) {
        switch (field) {
        case 0:
            return (u8 *) TAdEnterSerialAccessGC::serial_to_hex_string(TAdSinglePlyChrSelectGC::get_instance()->serial_number);
        case 1:
            return (u8 *)TAdSinglePlyChrSelectGC::get_instance()->access_key;
        case 2:
            return (u8 *)TAdSinglePlyChrSelectGC::get_instance()->password;
        }
    } else if (serial_access_entered_value_table[field] == TAdEnterSerialAccessGC::get_serial_seed()) {
        switch (field) {
        case 0:
            return get_raw_serial_input_buffer();
        case 1:
            return get_access_key_input_buffer();
        case 2:
            return get_password_input_buffer();
        }
    }
    return (u8 *)"";
}

TWindowBase *TAdEnterSerialAccessGC::show_message_window(void *owner, void *message_index) {
    TWindowMessage *window = create_message_window_for_size((NJS_POINT2 *)enter_base_message_window_position, (NJS_POINT2 *)enter_base_message_window_size);
    window->append_line(get_localized_text_entry(0x17, (saddr)message_index), 1);
    return window;
}

TWindowCallBack *TAdEnterBaseGC::create_default_callback() {
    return TAdEnterSerialAccessGC::create_callback((void *)enter_base_callback_position, (void *)enter_base_callback_size, fn_8032AC9C);
}

TKeyBoardControl *TAdEnterSerialAccessGC::create_keyboard_control(saddr parent, s32 field) {
    TKeyBoardControl *kb;
    if (field < 0 || field >= 4) {
        return NULL;
    }
    KeyboardModes sp8 = serial_keyboard_mode_table;
    kb = new TKeyBoardControl((TObject *)parent, serial_keyboard_field_width_table[field], 0, sp8.b[field], local_client_id);
    if (kb == NULL) {
        return NULL;
    }
    kb->set_sub_position((u8 *)serial_keyboard_position_table[field]);
    if (has_serial_input__22TAdEnterSerialAccessGCFv(parent, field) != 0) {
        kb->set_text((char *)get_serial_text__22TAdEnterSerialAccessGCFii(parent, field));
    }
    if (field != 3) {
        kb->set_composer_flag62_bit4();
    }
    return kb;
}

void fn_8032AC9C(void *window, void *context) {
    ((TWindowBase *)window)->draw_window_frame((WindowDrawContext *)context);
    draw_menu_text_scaled(password_screen_status_line_position[0].x, password_screen_status_line_position[0].y, 0.8f, (const char *)get_localized_text_entry(0x17, 4), -1);
    switch (TAdEnterBaseGC::entry_mode) {
    case 0:
    case 1:
        fn_8032AC94();
        return;
    case 2:
        fn_8032AC24();
        return;
    case 3:
        draw_masked_password_field((saddr)context);
        return;
    }
}

void TAdEnterBaseGC::render() {  }

void fn_8032AC94(void) {  }

void fn_8032AC24(void) {
    ChrSelPlateLayout layout;
    const f32 *src = entry_field_box_size;
    layout.width = src[0];
    layout.height = src[1];
    TAdPlyChrSelPlateGC plate(reinterpret_cast<TObject *>(tl_clipout), &layout);
    NJS_COLOR w = entry_field_box_color;
    draw_selection_plate(&plate, const_cast<NJS_POINT2 *>(&entry_field_box_pos), w, 0);
}

void draw_masked_password_field(saddr context) {
    char buf[0x80];
    char *str;
    s32 len;
    s32 i;
    char *q;
    if (password_entry_keyboard_control != 0) {
        ChrSelPlateLayout layout;
        layout.width = password_field_box_size[0];
        layout.height = password_field_box_size[1];
        TAdPlyChrSelPlateGC plate(reinterpret_cast<TObject *>(tl_clipout), &layout);
        NJS_COLOR w = password_field_box_color;
        draw_selection_plate(&plate, const_cast<NJS_POINT2 *>(&password_field_box_pos), w, 0);
        str = password_entry_keyboard_control->realloc_buffer();
        len = strlen(str);
        mem_free(str);
        memset(buf, 0, 0x80);
        q = buf;
        for (i = 0; i < len; i++) {
            *q++ = '*';
        }
        buf[len] = 0;
        len = calc_text_width("*");
        draw_menu_font_string_white(buf, password_field_text_pos[0], password_field_text_pos[1]);
        NJS_POINT2 p2;
        p2.x = password_field_text_pos[0] + (f32) (len * password_entry_keyboard_control->get_cursor_position());
        p2.y = password_field_text_pos[1];
        draw_text_cursor((WindowDrawContext *)context, &p2);
    }
}

#undef TOBJECT_OUT_OF_LINE_HELPERS
