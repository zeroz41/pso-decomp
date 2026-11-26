#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/save/CharacterFile.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/MenuText.h"


char serial_hex_buffer[0x40];
char serial_decimal_buffer[0x40];
char TAdEnterSerialAccessGC_serial_buffer[0x14];
char access_key_dashed_buffer[0x18];
char stored_serial_dashed_buffer[0x14];
char enter_serial_formatted_buffer[0x18];
TKeyBoardControl *TAdEnterSerialAccessGC::keyboard_control;
s32 TAdEnterSerialAccessGC::input_state;

const NJS_POINT2 serial_message_window_position = { 46.0f, 110.0f };
const NJS_POINT2 serial_message_window_size = { 548.0f, 120.0f };
const NJS_POINT2 serial_draw_window_position = { 85.0f, 220.0f };
const NJS_POINT2 serial_draw_window_size = { 470.0f, 60.0f };
const NJS_POINT2 TAdEnterSerialAccessGC::selection_positions[2] = { { 155.0f, 231.0f }, { 155.0f, 251.0f } };
const NJS_POINT2 serial_access_cursor_size = { 330.0f, 20.0f };
const char *TAdEnterSerialAccessGC::name = "TAdEnterSerialAccessGC";

__declspec(section ".data") NJS_POINT2 serial_entry_status_line_position = { 0.0f, 0.0f };
__declspec(section ".data") char TAdEnterSerialAccessGC::raw_serial_buffer[0xC] = { 0 };
__declspec(section ".data") char TAdEnterSerialAccessGC::access_key_input_buffer[0x10] = { 0 };

void TAdSelectCurGC::request_navigation_unlock() { pending_command = 3; }

void TAdEnterSerialAccessGC::set_entered_value(u32 value, s32 field) {
    serial_access_entered_value_table[field] = value;
}

s32 TKeyBoardControl::get_cursor_position() {
    if (m_base == NULL) {
        return 0;
    }
    return m_base->get_state();
}

TAdEnterSerialAccessGC::TAdEnterSerialAccessGC(TObject *parent) : TAdEnterBaseGC(parent) {
    char serial[0x10];
    char access_key[0x10];
    m_name = TAdEnterSerialAccessGC::name;
    state_timer = 0;
    input_state = 0;
    next_state = 0;
    serial_length = 0;
    input_valid = 0;
    prev_input_valid = 0;
    title = NULL;
    cursor = NULL;
    message_window = NULL;
    draw_window = NULL;
    keyboard_control = NULL;
    if (TAdSinglePlyChrSelectGC::get_instance()->serial_number[0] != 0) {
        initialize_serial_input(TAdSinglePlyChrSelectGC::get_instance()->serial_number);
        set_access_key(TAdSinglePlyChrSelectGC::get_instance()->access_key);
        TAdMultiChgGameModeGC::open_enter_password_scene();
        queue_destruction();
        return;
    }
    serial[0] = 0;
    if (((TAdSinglePlyChrSelectGC *)serial)->load_and_verify_character_save(access_key) != 0 && serial[0] != 0) {
        initialize_serial_input(serial);
        set_access_key(access_key);
        set_entered_value(TAdEnterSerialAccessGC::get_serial_seed(), 1);
        set_entered_value(TAdEnterSerialAccessGC::get_serial_seed(), 0);
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    cursor = new TAdSelectCurGC(tl_clipout, &selection_positions[0], &serial_access_cursor_size);
}

TAdEnterSerialAccessGC::~TAdEnterSerialAccessGC() {
    if (message_window != NULL) {
        message_window->queue_destruction();
        message_window = NULL;
    }
    if (draw_window != NULL) {
        draw_window->queue_destruction();
        draw_window = NULL;
    }
    if (cursor != NULL) {
        cursor->queue_destruction();
        cursor = NULL;
    }
}

void TAdEnterSerialAccessGC::run_task() {
    f32 x = 320.0f - (f32)(calc_text_width(get_localized_text_entry(0x17, 4)) >> 1);
    serial_entry_status_line_position.y = 250.0f;
    serial_entry_status_line_position.x = x;
    prev_state = input_state;
    switch (input_state) {
    case 0:
        input_state = 1;
        break;
    case 1:
        input_valid = 0;
        title = new TAdTitleGC(this, 0xA);
        message_window = open_message_window(0);
        draw_window = create_draw_callback();
        if (cursor != NULL) {
            cursor->reset_entries();
            cursor->append_entry(&selection_positions[0]);
            cursor->lock_navigation();
        }
        keyboard_control = create_keyboard_control((saddr)this, 0);
        input_state = 2;
        break;
    case 2:
        update_serial_input();
        break;
    case 3:
        input_valid = 0;
        if (cursor != NULL) {
            cursor->reset_entries();
            cursor->append_entry(&selection_positions[0]);
            cursor->lock_navigation();
        }
        title = new TAdTitleGC(this, 0xB);
        message_window = open_message_window(1);
        draw_window = create_draw_callback();
        keyboard_control = create_keyboard_control((saddr)this, 1);
        input_state = 4;
        break;
    case 4:
        update_access_key_input();
        break;
    case 5:
        if ((f32)++state_timer > 4.5f) {
            input_state = next_state;
        }
        break;
    case 6:
        if (cursor != NULL) {
            cursor->queue_destruction();
            cursor = NULL;
        }
        TAdMultiChgGameModeGC::open_lic_agreement_scene();
        break;
    case 7:
        if (cursor != NULL) {
            cursor->queue_destruction();
            cursor = NULL;
        }
        TAdMultiChgGameModeGC::open_enter_password_scene();
        break;
    }
    if (prev_state != input_state) {
        state_timer = 0;
    }
}

void TAdEnterSerialAccessGC::update_serial_input() { update_text_input(0); }

void TAdEnterSerialAccessGC::update_access_key_input() { update_text_input(1); }

void TAdEnterSerialAccessGC::update_text_input(s32 field) {
    char *text = keyboard_control->realloc_buffer();
    if ((serial_length == 0 && test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) ||
        (serial_length == 0 && test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        switch (input_state) {
        case 3:
            break;
        case 2:
            if (message_window != NULL) {
                message_window->close();
                message_window = NULL;
            }
            if (draw_window != NULL) {
                draw_window->close();
                draw_window = NULL;
            }
            if (keyboard_control != NULL) {
                keyboard_control->queue_destruction();
                keyboard_control = NULL;
            }
            memset(raw_serial_buffer, 0, 0xB);
            next_state = 6;
            input_state = 5;
            break;
        case 4:
            if (title != NULL) {
                title->queue_destruction();
                title = NULL;
            }
            if (message_window != NULL) {
                message_window->close();
                message_window = NULL;
            }
            if (draw_window != NULL) {
                draw_window->close();
                draw_window = NULL;
            }
            if (keyboard_control != NULL) {
                keyboard_control->queue_destruction();
                keyboard_control = NULL;
            }
            cursor->reset_entries();
            memset(access_key_input_buffer, 0, 0xD);
            next_state = 1;
            input_state = 5;
            break;
        }
        mem_free(text);
        return;
    }
    prev_input_valid = input_valid;
    if (keyboard_control != NULL) {
        if (forward_input(this, field, text) != 0) {
            input_valid = 1;
            if (cursor != NULL) {
                cursor->request_navigation_unlock();
            }
        } else {
            input_valid = 0;
            if (cursor != NULL) {
                cursor->lock_navigation();
            }
        }
        if (keyboard_control->is_confirmed() != 0 && forward_input(this, field, text) == 0) {
            keyboard_control->clear_keyboard_flag60_bit1();
            play_sound_effect(0x53F06, 0, 0, 0);
        }
    }
    if (prev_input_valid != input_valid) {
        if (input_valid) {
            if (cursor != NULL) {
                cursor->reset_entries();
                cursor->append_entry(&selection_positions[1]);
            }
        } else {
            if (cursor != NULL) {
                cursor->reset_entries();
                cursor->append_entry(&selection_positions[0]);
            }
        }
    }
    if (cursor->confirmation_result() == 1 && forward_input(this, field, text) != 0) {
        if (message_window != NULL) {
            message_window->close();
            message_window = NULL;
        }
        if (draw_window != NULL) {
            draw_window->close();
            draw_window = NULL;
        }
        switch (field) {
        case 0:
            if (title != NULL) {
                title->queue_destruction();
                title = NULL;
            }
            if (keyboard_control != NULL) {
                keyboard_control->queue_destruction();
                keyboard_control = NULL;
            }
            strncpy(raw_serial_buffer, text, 0xB);
            set_entered_value(TAdEnterSerialAccessGC::get_serial_seed(), 0);
            next_state = 3;
            input_state = 5;
            break;
        case 1:
            if (keyboard_control != NULL) {
                keyboard_control->queue_destruction();
                keyboard_control = NULL;
            }
            strncpy(access_key_input_buffer, text, 0xD);
            set_entered_value(TAdEnterSerialAccessGC::get_serial_seed(), 1);
            next_state = 7;
            input_state = 5;
            break;
        }
    }
    serial_length = strlen(text);
    mem_free(text);
}

TWindowBase *TAdEnterSerialAccessGC::open_message_window(s32 text_index) {
    TWindowMessage *window = create_message_window_for_size(
        const_cast<NJS_POINT2 *>(&serial_message_window_position), const_cast<NJS_POINT2 *>(&serial_message_window_size));
    window->append_line(get_localized_text_entry(0x17, text_index), 1);
    return window;
}

TWindowCallBack *TAdEnterSerialAccessGC::create_draw_callback() {
    return create_callback((void *)&serial_draw_window_position, (void *)&serial_draw_window_size, draw_screen);
}

char *TAdEnterSerialAccessGC::hex_to_decimal_string(const char *serial) {
    s32 value = 0;
    sscanf(serial, "%lu", &value);
    memset(serial_hex_buffer, 0, 0x40);
    sprintf(serial_hex_buffer, "%08X", value);
    return serial_hex_buffer;
}

char *TAdEnterSerialAccessGC::convert_serial_hex_to_decimal(const char *serial) {
    u32 value = 0;
    sscanf(serial, "%08X", &value);
    memset(serial_decimal_buffer, 0, 0x40);
    if (value != 0) {
        sprintf(serial_decimal_buffer, "%010lu", value);
    }
    return serial_decimal_buffer;
}

#pragma push
#pragma opt_common_subs off
void TAdEnterSerialAccessGC::set_raw_serial(const char *serial) {
    memset(raw_serial_buffer, 0, 0xB);
    strncpy(raw_serial_buffer, serial, 0xB);
}
#pragma pop

void TAdEnterSerialAccessGC::set_access_key(const char *key) {
    memset(access_key_input_buffer, 0, 0xD);
    strncpy(access_key_input_buffer, key, 0xD);
}

void TAdEnterSerialAccessGC::initialize_serial_input(const char *serial) {
    set_raw_serial(serial_to_hex_string(serial));
}

char *format_entered_serial(void) {
    memset(TAdEnterSerialAccessGC_serial_buffer, 0, 0x14);
    u32 lengths[3] = { 2, 4, 4 };
    TAdEnterSerialAccessGC::format_dashed_serial(TAdEnterSerialAccessGC_serial_buffer,
        TAdEnterSerialAccessGC::raw_serial_buffer, 3, lengths);
    return TAdEnterSerialAccessGC_serial_buffer;
}

s32 TAdEnterSerialAccessGC::parse_serial_value() {
    s32 value = 0;
    sscanf(TAdSinglePlyChrSelectGC::get_instance()->serial_number, "%08x", &value);
    return value;
}

char *format_entered_access_key(void) {
    memset(access_key_dashed_buffer, 0, 0x18);
    u32 lengths[3] = { 4, 4, 4 };
    TAdEnterSerialAccessGC::format_dashed_serial(access_key_dashed_buffer, TAdEnterSerialAccessGC::access_key_input_buffer, 3, lengths);
    return access_key_dashed_buffer;
}

char *format_saved_serial(void) {
    memset(stored_serial_dashed_buffer, 0, 0x14);
    u32 lengths[3] = { 2, 4, 4 };
    TAdEnterSerialAccessGC::format_dashed_serial(stored_serial_dashed_buffer,
        TAdEnterSerialAccessGC::convert_serial_hex_to_decimal(TAdSinglePlyChrSelectGC::get_instance()->serial_number),
        3, lengths);
    return stored_serial_dashed_buffer;
}

char *TAdEnterSerialAccessGC::get_formatted_serial() {
    memset(enter_serial_formatted_buffer, 0, 0x18);
    u32 lengths[3] = { 4, 4, 4 };
    format_dashed_serial(enter_serial_formatted_buffer, TAdSinglePlyChrSelectGC::get_instance()->access_key,
        3, lengths);
    return enter_serial_formatted_buffer;
}

void TAdEnterSerialAccessGC::format_dashed_serial(char *dst, const char *src, u32 count, const u32 *lengths) {
    u32 i;
    u32 j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < lengths[i]; j++) {
            *dst++ = *src++;
        }
        *dst++ = '-';
    }
    dst[-1] = 0;
}

const NJS_COLOR serial_plate_color = { 0xFF };
const NJS_POINT2 serial_narrow_plate_position = { 234.0f, 230.0f };
const NJS_POINT2 serial_plate_position_table[3] = { { 258.0f, 230.0f }, { 293.0f, 230.0f }, { 352.0f, 230.0f } };

#pragma push
#pragma fp_contract on
void TAdEnterSerialAccessGC::draw_serial_plates() {
    ChrSelPlateLayout wide;
    ChrSelPlateLayout narrow;
    u32 i;
    wide.width = 48.0f;
    wide.height = 18.0f;
    TAdPlyChrSelPlateGC wide_plate(tl_clipout, &wide);
    narrow.width = 24.0f;
    narrow.height = 18.0f;
    TAdPlyChrSelPlateGC narrow_plate(tl_clipout, &narrow);
    {
        NJS_POINT2 pos = serial_narrow_plate_position;
        NJS_COLOR color = serial_plate_color;
        switch (input_state) {
        case 3:
            break;
        case 2:
            draw_selection_plate(&narrow_plate, const_cast<NJS_POINT2 *>(&serial_plate_position_table[0]), color, 0);
            for (i = 0; i < 2; i++) {
                draw_selection_plate(&wide_plate, const_cast<NJS_POINT2 *>(&serial_plate_position_table[i + 1]), color, 0);
            }
            draw_serial_separators();
            break;
        case 4:
            for (i = 0; i < 3; i++) {
                pos.x = 59.0f * (f32)i + 234.0f;
                draw_selection_plate(&wide_plate, &pos, color, 0);
            }
            draw_serial_separators();
            break;
        }
    }
}
#pragma pop

void TAdEnterSerialAccessGC::draw_serial_separators() {
    draw_menu_text_scaled(281.0f, 230.0f, 0.8f, "-", -1);
    draw_menu_text_scaled(340.0f, 230.0f, 0.8f, "-", -1);
}

const f32 serial_char_row_x_table[2][13] = {
    { 258.0f, 270.0f, 293.0f, 305.0f, 317.0f, 329.0f, 352.0f, 364.0f, 376.0f, 388.0f, 400.0f, 0.0f, 0.0f },
    { 234.0f, 246.0f, 258.0f, 270.0f, 293.0f, 305.0f, 317.0f, 329.0f, 352.0f, 364.0f, 376.0f, 388.0f, 400.0f },
};

void TAdEnterSerialAccessGC::draw_serial_chars(void *context) {
    char text[0xFF];
    char buf[8];
    NJS_POINT2 pos;
    char *p;
    u32 count;
    const f32 *row;
    char *input;
    u32 i;
    s32 field;
    if (keyboard_control != NULL) {
        input = keyboard_control->realloc_buffer();
        memset(text, 0, 0xFF);
        strncpy(text, input, 0xFF);
        mem_free(input);
        p = text;
        field = input_state == 2 ? 0 : 1;
        row = serial_char_row_x_table[field];
        count = field * 2 + 10;
        for (i = 0; i < count; i++, p++) {
            memset(buf, 0, 8);
            sprintf(buf, "%c", *p);
            draw_menu_text_scaled(row[i], 230.0f, 0.8f, buf, -1);
        }
        pos.x = row[keyboard_control->get_cursor_position()];
        pos.y = 230.0f;
        draw_text_cursor(static_cast<WindowDrawContext *>(context), &pos);
    }
}

void TAdEnterSerialAccessGC::draw_screen(void *window, void *context) {
    ((TWindowBase *)window)->draw_window_frame((WindowDrawContext *)context);
    draw_menu_text_scaled(serial_entry_status_line_position.x, serial_entry_status_line_position.y, 0.8f,
        get_localized_text_entry(0x17, 4), -1);
    draw_serial_plates();
    draw_serial_chars(context);
}

void TAdEnterSerialAccessGC::render() {
    if (TMainTask::get_render_pass() == 1) {
        return;
    }
}
