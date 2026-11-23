#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include <stdio.h>
#include <string.h>
#include "pso/ui/window/TWindowMessage.h"
#include "pso/ui/window/ProgressMessageWindow.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/system/task/TMainTask.h"

#include "pso/unk/TLobby_80132ED0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdEnterBaseGC_8032B38C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"


#include <stddef.h>
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC_8032AD30.h"
struct Stack_803216C0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_803216C0_lbl_8047653C {
    s32 value;
    s32 remaining[2];
};

struct Stack_803217B8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_803217B8_lbl_80476524 {
    s32 value;
    s32 remaining[2];
};

struct RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 {
    s32 value;
    u8 remaining[0xC];
};

struct Stack_80321874 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_80321874_lbl_80476518 {
    s32 value;
    s32 remaining[2];
};

struct RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8
{
  s32 value;
  u8 remaining[0x8];
};

struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4
{
  s32 value;
  u8 remaining[0xC];
};

struct T_80321738 { s32 a; s32 b; s32 c; };

struct V_803212F8 { f32 a; f32 b; };

extern "C" {
extern RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 TAdEnterSerialAccessGC__access_key_input_buffer;
char lbl_80543010[0x40];
char lbl_80543050[0x40];
struct TAdEnterSerialAccessGCSerialBuffer { s32 value; u8 remaining[0x10]; };
TAdEnterSerialAccessGCSerialBuffer TAdEnterSerialAccessGC_serial_buffer;
struct RecoveredGlobal_lbl_805430A4 { s32 value; u8 remaining[0x14]; };
RecoveredGlobal_lbl_805430A4 lbl_805430A4;
u8 lbl_805430BC[0x14];
struct EnterSerialFormattedBuffer { s32 value; u8 remaining[0x14]; };
EnterSerialFormattedBuffer enter_serial_formatted_buffer;
extern RecoveredGlobal_lbl_805430A4 lbl_805430A4;
extern RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8 TAdEnterSerialAccessGC__raw_serial_buffer;
extern TAdEnterSerialAccessGCSerialBuffer TAdEnterSerialAccessGC_serial_buffer;
struct SerialAccessEnteredValueTable { s32 value; u8 remaining[0xC]; };
extern SerialAccessEnteredValueTable serial_access_entered_value_table;
s32 play_sound_effect(int, int, int, int);
uaddr TAdEnterSerialAccessGC__keyboard_control;
s32 TAdEnterSerialAccessGC__input_state;
extern u8 lbl_805430BC[];
extern char lbl_80543010[];
extern char lbl_80543050[];
void *__ct__14TAdSelectCurGCFv(void *, TObject *, void *, void *);
void fn_8025DE10(void *arg0, void *arg1);
extern V_803212F8 serial_entry_status_line_position[];

const NJS_COLOR serial_plate_color = { 0xFF };
const NJS_POINT2 lbl_804764C8 = { 46.0f, 110.0f };
const NJS_POINT2 lbl_804764D0 = { 548.0f, 120.0f };
const NJS_POINT2 lbl_804764D8 = { 85.0f, 220.0f };
const NJS_POINT2 lbl_804764E0 = { 470.0f, 60.0f };
const NJS_POINT2 TAdEnterSerialAccessGC__selection_positions[2] = { { 155.0f, 231.0f }, { 155.0f, 251.0f } };
const NJS_POINT2 lbl_804764F8 = { 330.0f, 20.0f };
const char *TAdEnterSerialAccessGC__name = "TAdEnterSerialAccessGC";
const RecoveredGlobal_80321874_lbl_80476518 lbl_80476518 = { 2, { 4, 4 } };
const RecoveredGlobal_803217B8_lbl_80476524 lbl_80476524 = { 4, { 4, 4 } };
const T_80321738 lbl_80476530 = { 2, 4, 4 };
const RecoveredGlobal_803216C0_lbl_8047653C lbl_8047653C = { 4, { 4, 4 } };
const NJS_POINT2 lbl_80476548[1] = { { 234.0f, 230.0f } };
const NJS_POINT2 serial_plate_position_table[3] = { { 258.0f, 230.0f }, { 293.0f, 230.0f }, { 352.0f, 230.0f } };
const f32 serial_char_row_x_table[2][13] = {
    { 258.0f, 270.0f, 293.0f, 305.0f, 317.0f, 329.0f, 352.0f, 364.0f, 376.0f, 388.0f, 400.0f, 0.0f, 0.0f },
    { 234.0f, 246.0f, 258.0f, 270.0f, 293.0f, 305.0f, 317.0f, 329.0f, 352.0f, 364.0f, 376.0f, 388.0f, 400.0f },
};

__declspec(section ".data") V_803212F8 serial_entry_status_line_position[1] = {{0.0f, 0.0f}};
__declspec(section ".data") RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8 TAdEnterSerialAccessGC__raw_serial_buffer = {0};
__declspec(section ".data") RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 TAdEnterSerialAccessGC__access_key_input_buffer = {0};

typedef struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8 RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8;
typedef struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4 RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4;
LAYOUT_ASSERT(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8_size, (sizeof(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8)) == 0xC);
LAYOUT_ASSERT(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4_size, (sizeof(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4)) == 0x10);
LAYOUT_ASSERT(RecoveredGlobal_803216C0_lbl_8047653C_size, sizeof(RecoveredGlobal_803216C0_lbl_8047653C) == 0xC);
LAYOUT_ASSERT(RecoveredGlobal_803217B8_lbl_80476524_size, sizeof(RecoveredGlobal_803217B8_lbl_80476524) == 0xC);
LAYOUT_ASSERT(RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4_size, sizeof(RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4) == 0x10);
LAYOUT_ASSERT(RecoveredGlobal_80321874_lbl_80476518_size, sizeof(RecoveredGlobal_80321874_lbl_80476518) == 0xC);
LAYOUT_ASSERT(RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8_size, sizeof(RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8) == 0xC);

void TAdSelectCurGC::request_navigation_unlock() { pending_command = 3; }

void TAdEnterSerialAccessGC__sub_80322418(s32 arg0, s32 arg1) {
    *(s32 *)((s8 *)((u8 *)&serial_access_entered_value_table.value + (arg1 * 4)) + 0) = arg0;
}

s32 TKeyBoardControl::get_cursor_position() {
    if (m_base == NULL) {
        return 0;
    }
    return m_base->get_state();
}

TAdEnterSerialAccessGC::TAdEnterSerialAccessGC(TObject *parent) : TAdEnterBaseGC(parent) {
    s8 flag[0x10];
    char sp8[0x10];
    void *p;
    m_name = TAdEnterSerialAccessGC__name;
    state_timer = 0;
    TAdEnterSerialAccessGC__input_state = 0;
    next_state = 0;
    serial_length = 0;
    input_valid = 0;
    prev_input_valid = 0;
    title = NULL;
    cursor = NULL;
    message_window = NULL;
    draw_window = NULL;
    TAdEnterSerialAccessGC__keyboard_control = 0;
    if (*(s8 *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1152C) != 0) {
        initialize_serial_input((const char *)TAdSinglePlyChrSelectGC::get_instance() + 0x1152C);
        TAdEnterSerialAccessGC__sub_8032190C((const char *)(TAdSinglePlyChrSelectGC::get_instance() + 0x1153C));
        TAdEnterSerialAccessGC::init_state();
        queue_destruction();
        return;
    }
    flag[0] = 0;
    if (((TAdSinglePlyChrSelectGC *)flag)->load_and_verify_character_save(sp8) != 0 && flag[0] != 0) {
        initialize_serial_input(reinterpret_cast<const char *>(flag));
        TAdEnterSerialAccessGC__sub_8032190C(sp8);
        TAdEnterSerialAccessGC__sub_80322418(get_field_118__22TAdEnterSerialAccessGCFv(), 1);
        TAdEnterSerialAccessGC__sub_80322418(get_field_118__22TAdEnterSerialAccessGCFv(), 0);
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    p = new TAdSelectCurGC(tl_clipout,
        reinterpret_cast<const NJS_POINT2 *>(&TAdEnterSerialAccessGC__selection_positions[0]),
        reinterpret_cast<const NJS_POINT2 *>(&lbl_804764F8));
    cursor = static_cast<TAdSelectCurGC *>(p);
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
    f32 w;

    w = 320.0f - (f32)(calc_text_width((char *)((void *)get_localized_text_entry(0x17, (saddr)((void *)4)))) >> 1);
    serial_entry_status_line_position[0].b = 250.0f;
    serial_entry_status_line_position[0].a = w;
    prev_state = TAdEnterSerialAccessGC__input_state;
    switch (TAdEnterSerialAccessGC__input_state) {
    case 0:
        TAdEnterSerialAccessGC__input_state = 1;
        break;
    case 1:
        input_valid = 0;
        title = new TAdTitleGC(this, 0xA);
        message_window = open_message_window(0);
        draw_window = create_draw_callback();
        if (cursor != NULL) {
            cursor->reset_entries();
            cursor->append_entry((void *)&TAdEnterSerialAccessGC__selection_positions[0]);
            cursor->lock_navigation();
        }
        TAdEnterSerialAccessGC__keyboard_control = TAdEnterSerialAccessGC::create_keyboard_control((saddr)this, 0);
        TAdEnterSerialAccessGC__input_state = 2;
        break;
    case 2:
        TAdEnterSerialAccessGC__sub_80321F3C(this);
        break;
    case 3:
        input_valid = 0;
        if (cursor != NULL) {
            cursor->reset_entries();
            cursor->append_entry((void *)&TAdEnterSerialAccessGC__selection_positions[0]);
            cursor->lock_navigation();
        }
        title = new TAdTitleGC(this, 0xB);
        message_window = open_message_window(1);
        draw_window = create_draw_callback();
        TAdEnterSerialAccessGC__keyboard_control = TAdEnterSerialAccessGC::create_keyboard_control((saddr)this, 1);
        TAdEnterSerialAccessGC__input_state = 4;
        break;
    case 4:
        TAdEnterSerialAccessGC__sub_80321F18(this);
        break;
    case 5:
        if ((f32)++state_timer > 4.5f) {
            TAdEnterSerialAccessGC__input_state = next_state;
        }
        break;
    case 6:
        if (cursor != NULL) {
            cursor->queue_destruction();
            cursor = NULL;
        }
        TAdMultiChgGameModeGC::request_transition();
        break;
    case 7:
        if (cursor != NULL) {
            cursor->queue_destruction();
            cursor = NULL;
        }
        TAdEnterSerialAccessGC::init_state();
        break;
    }
    if (prev_state != TAdEnterSerialAccessGC__input_state) {
        state_timer = 0;
    }
}

void TAdEnterSerialAccessGC__sub_80321F3C(void* p) { ((TAdEnterSerialAccessGC *)p)->sub_80321B28(0); }

void TAdEnterSerialAccessGC__sub_80321F18(void* p) { ((TAdEnterSerialAccessGC *)p)->sub_80321B28(1); }

void TAdEnterSerialAccessGC::sub_80321B28(s32 field) {
  saddr src;
  TWindowBase *window_base;
  TAdSelectCurGC *ad_select_cur_gc;
  TWindowBase *temp_r3_11;
  TWindowBase *temp_r3_12;
  TObject *object;
  TWindowBase *temp_r3_2;
  TObject *temp_r3_3;
  TWindowBase *temp_r3_4;
  TWindowBase *temp_r3_5;
  TAdSelectCurGC *temp_r3_6;
  TAdSelectCurGC *temp_r3_7;
  TAdSelectCurGC *temp_r3_9;
  src = (saddr)((TKeyBoardControl *)TAdEnterSerialAccessGC__keyboard_control)->realloc_buffer();
  if (((((int) (serial_length)) == 0) && (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0)) || ((((int) (serial_length)) == 0) && (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)))
  {
    switch ((int) TAdEnterSerialAccessGC__input_state)
    {
      case 3:
        break;
      case 2:
        window_base = message_window;
        if (window_base != NULL)
      {
        window_base->close();
        message_window = NULL;
      }
        temp_r3_2 = draw_window;
        if (temp_r3_2 != NULL)
      {
        temp_r3_2->close();
        draw_window = NULL;
      }
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        ((TObject *)TAdEnterSerialAccessGC__keyboard_control)->queue_destruction();
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        memset((void *) (&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value), 0, 0xB);
        next_state = 6;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
      case 4:
        temp_r3_3 = title;
        if (temp_r3_3 != NULL)
      {
        temp_r3_3->queue_destruction();
        title = NULL;
      }
        temp_r3_4 = message_window;
        if (temp_r3_4 != NULL)
      {
        temp_r3_4->close();
        message_window = NULL;
      }
        temp_r3_5 = draw_window;
        if (temp_r3_5 != NULL)
      {
        temp_r3_5->close();
        draw_window = NULL;
      }
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        ((TObject *)TAdEnterSerialAccessGC__keyboard_control)->queue_destruction();
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        cursor->reset_entries();
        memset((void *) (&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4 *)&TAdEnterSerialAccessGC__access_key_input_buffer).value), 0, 0xD);
        next_state = 1;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
    }
    mem_free((void *)src);
    return;
  }
  prev_input_valid = (int) (input_valid);
  if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
  {
    if (TAdEnterSerialAccessGC::forward_input(this, field, (const char *)src) != 0)
    {
      input_valid = 1;
      temp_r3_6 = cursor;
      if (temp_r3_6 != NULL)
      {
        temp_r3_6->request_navigation_unlock();
      }
    }
    else
    {
      input_valid = 0;
      temp_r3_7 = cursor;
      if (temp_r3_7 != NULL)
      {
        temp_r3_7->lock_navigation();
      }
    }
    if ((((TKeyBoardControl *)TAdEnterSerialAccessGC__keyboard_control)->is_confirmed() != 0) && (TAdEnterSerialAccessGC::forward_input(this, field, (const char *)src) == 0))
    {
      reinterpret_cast<TKeyBoardControl *>(TAdEnterSerialAccessGC__keyboard_control)->clear_keyboard_flag60_bit1();
      play_sound_effect(0x53F06, 0, 0, 0);
    }
  }
  if (prev_input_valid != input_valid)
  {
    if (input_valid)
    {
      temp_r3_9 = cursor;
      if (temp_r3_9 != NULL)
      {
        temp_r3_9->reset_entries();
        cursor->append_entry((void *)&TAdEnterSerialAccessGC__selection_positions[1]);
      }
    }
    else
    {
      ad_select_cur_gc = cursor;
      if (ad_select_cur_gc != NULL)
      {
        ad_select_cur_gc->reset_entries();
        cursor->append_entry((void *)&TAdEnterSerialAccessGC__selection_positions[0]);
      }
    }
  }
  if ((cursor->confirmation_result() == 1) && (TAdEnterSerialAccessGC::forward_input(this, field, (const char *)src) != 0))
  {
    temp_r3_11 = message_window;
    if (temp_r3_11 != NULL)
    {
      temp_r3_11->close();
      message_window = NULL;
    }
    temp_r3_12 = draw_window;
    if (temp_r3_12 != NULL)
    {
      temp_r3_12->close();
      draw_window = NULL;
    }
    switch (field)
    {
      case 0:
        object = title;
        if (object != NULL)
      {
        object->queue_destruction();
        title = NULL;
      }
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        ((TObject *)TAdEnterSerialAccessGC__keyboard_control)->queue_destruction();
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        strncpy((char *)(&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value), (const char *)src, 0xB);
        TAdEnterSerialAccessGC__sub_80322418((s32)((int) get_field_118__22TAdEnterSerialAccessGCFv()), 0);
        next_state = 3;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
      case 1:
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        ((TObject *)TAdEnterSerialAccessGC__keyboard_control)->queue_destruction();
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        strncpy((char *)(&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4 *)&TAdEnterSerialAccessGC__access_key_input_buffer).value), (const char *)src, 0xD);
        TAdEnterSerialAccessGC__sub_80322418((s32)((int) get_field_118__22TAdEnterSerialAccessGCFv()), 1);
        next_state = 7;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
    }
  }
  serial_length = strlen((const char *)src);
  mem_free((void *)src);
}

TWindowBase *TAdEnterSerialAccessGC::open_message_window(s32 text_index) {
    TWindowMessage *window = (TWindowMessage *)create_message_window_for_size((NJS_POINT2 *)&lbl_804764C8, (NJS_POINT2 *)&lbl_804764D0);
    window->append_line(get_localized_text_entry(0x17, text_index), 1);
    return window;
}

TWindowCallBack *TAdEnterSerialAccessGC::create_draw_callback() {
    return create_callback((void *)&lbl_804764D8, (void *)&lbl_804764E0, TAdEnterSerialAccessGC::draw_screen);
}

char *TAdEnterSerialAccessGC::hex_to_decimal_string(const char *serial) {
    s32 v = 0;
    sscanf(serial, "%lu", &v);
    memset(lbl_80543010, 0, 0x40);
    sprintf(lbl_80543010, "%08X", v);
    return lbl_80543010;
}

char *TAdEnterSerialAccessGC::convert_serial_hex_to_decimal(const char *serial) {
    u32 v = 0;
    sscanf(serial, "%08X", &v);
    memset(lbl_80543050, 0, 0x40);
    if (v != 0) {
        sprintf(lbl_80543050, "%010lu", v);
    }
    return lbl_80543050;
}

#pragma push
#pragma opt_common_subs off
LAYOUT_ASSERT(RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8_size, sizeof(RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8) == 0xC);
void TAdEnterSerialAccessGC__sub_8032195C(const char *serial) {
    memset((void *) (&(*(RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value), 0, 0xB);
    strncpy((char *)(&(*(RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value), serial, 0xB);
}
#pragma pop

void TAdEnterSerialAccessGC__sub_8032190C(const char *key) {
    memset(&TAdEnterSerialAccessGC__access_key_input_buffer.value, 0, 0xd);
    strncpy((char *)&TAdEnterSerialAccessGC__access_key_input_buffer.value, key, 0xd);
}

void initialize_serial_input(const char *serial) {
    TAdEnterSerialAccessGC__sub_8032195C(TAdEnterSerialAccessGC::serial_to_hex_string(serial));
}

s32 *TAdEnterSerialAccessGC__sub_80321874(void) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_80321874, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_80321874, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_80321874, sp10) == 0x8);
    Stack_80321874 stack;
    memset((void *)&TAdEnterSerialAccessGC_serial_buffer.value, 0, 0x14);
    stack.sp8 = *(s32 *)((s8 *)&lbl_80476518.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_80476518.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_80476518.value + 8);
    ((TAdEnterSerialAccessGC *)(&TAdEnterSerialAccessGC_serial_buffer.value))->format_dashed_serial((u8 *)((void *)&TAdEnterSerialAccessGC__raw_serial_buffer.value), (u32)(3), (u32 *)((void *)&stack.sp8));
    return &TAdEnterSerialAccessGC_serial_buffer.value;
}

s32 TAdEnterSerialAccessGC::parse_serial_value() {
    s32 sp8;
    sp8 = 0;
    sscanf((const char *)(TAdSinglePlyChrSelectGC::get_instance() + 0x1152C), "%08x", &sp8);
    return sp8;
}

s32 *TAdEnterSerialAccessGC__sub_803217B8(void) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_803217B8, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_803217B8, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_803217B8, sp10) == 0x8);
    Stack_803217B8 stack;
    memset((void *)&lbl_805430A4.value, 0, 0x18);
    stack.sp8 = *(s32 *)((s8 *)&lbl_80476524.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_80476524.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_80476524.value + 8);
    ((TAdEnterSerialAccessGC *)(&lbl_805430A4.value))->format_dashed_serial((u8 *)((void *) (&(*(RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 *)&TAdEnterSerialAccessGC__access_key_input_buffer).value)), (u32)(3), (u32 *)((void *)&stack.sp8));
    return &lbl_805430A4.value;
}

u8 *TAdEnterSerialAccessGC__sub_80321738(void) {
    memset(lbl_805430BC, 0, 0x14);
    T_80321738 t = lbl_80476530;
    ((TAdEnterSerialAccessGC *)lbl_805430BC)->format_dashed_serial((u8 *)TAdEnterSerialAccessGC::convert_serial_hex_to_decimal((const char *)(TAdSinglePlyChrSelectGC::get_instance() + 0x1152C)), (u32)(3), (u32 *)&t);
    return lbl_805430BC;
}

s32 *TAdEnterSerialAccessGC::get_formatted_serial() {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_803216C0, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_803216C0, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_803216C0, sp10) == 0x8);
    Stack_803216C0 stack;
    memset((void *)&enter_serial_formatted_buffer.value, 0, 0x18);
    stack.sp8 = *(s32 *)((s8 *)&lbl_8047653C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8047653C.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8047653C.value + 8);
    ((TAdEnterSerialAccessGC *)(&enter_serial_formatted_buffer.value))->format_dashed_serial((u8 *)((void *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1153C)), (u32)(3), (u32 *)((void *)&stack.sp8));
    return &enter_serial_formatted_buffer.value;
}

void TAdEnterSerialAccessGC::format_dashed_serial(u8 *src, u32 count, u32 *lens) {
    u8 *dst = (u8 *)this;
    u32 i;
    u32 j;
    for (i = 0; i < count; i++) {
        for (j = 0; j < lens[i]; j++) {
            *dst++ = *src++;
        }
        *dst++ = '-';
    }
    dst[-1] = 0;
}

#pragma push
#pragma fp_contract on
void TAdEnterSerialAccessGC::draw_serial_plates() {
    ChrSelPlateLayout pa;
    ChrSelPlateLayout pb;
    u32 i;
    pa.width = 48.0f;
    pa.height = 18.0f;
    TAdPlyChrSelPlateGC a(tl_clipout, &pa);
    pb.width = 24.0f;
    pb.height = 18.0f;
    TAdPlyChrSelPlateGC b(tl_clipout, &pb);
    {
        NJS_POINT2 pos = lbl_80476548[0];
        NJS_COLOR c = serial_plate_color;
        switch (TAdEnterSerialAccessGC__input_state) {
        case 3:
            break;
        case 2:
            draw_selection_plate(&b, const_cast<NJS_POINT2 *>(&serial_plate_position_table[0]), c, 0);
            for (i = 0; i < 2; i++) {
                draw_selection_plate(&a, const_cast<NJS_POINT2 *>(&serial_plate_position_table[i + 1]), c, 0);
            }
            TAdEnterSerialAccessGC::draw_serial_separators();
            break;
        case 4:
            for (i = 0; i < 3; i++) {
                pos.x = 59.0f * (f32)i + 234.0f;
                draw_selection_plate(&a, &pos, c, 0);
            }
            TAdEnterSerialAccessGC::draw_serial_separators();
            break;
        }
    }
}
#pragma pop

void TAdEnterSerialAccessGC::draw_serial_separators() {
    TAdSubPlyItemGC::render_status_line(281.0f, 230.0f, 0.8f, "-", -1);
    TAdSubPlyItemGC::render_status_line(340.0f, 230.0f, 0.8f, "-", -1);
}

void TAdEnterSerialAccessGC::draw_serial_chars(saddr arg0) {
    char text[0xFF];
    char buf[8];
    NJS_POINT2 pos;
    char *p;
    u32 n;
    const f32 *row;
    saddr str;
    u32 i;
    s32 r;
    if (TAdEnterSerialAccessGC__keyboard_control != 0) {
        str = (saddr)((TKeyBoardControl *)TAdEnterSerialAccessGC__keyboard_control)->realloc_buffer();
        memset(text, 0, 0xFF);
        strncpy((char *)text, (const char *)str, 0xFF);
        mem_free((void *)str);
        p = text;
        r = TAdEnterSerialAccessGC__input_state == 2 ? 0 : 1;
        row = serial_char_row_x_table[r];
        n = r * 2 + 10;
        for (i = 0; i < n; i++, p++) {
            memset(buf, 0, 8);
            sprintf(buf, "%c", *p);
            TAdSubPlyItemGC::render_status_line(row[i], 230.0f, 0.8f, buf, -1);
        }
        pos.x = row[((TKeyBoardControl *)TAdEnterSerialAccessGC__keyboard_control)->get_cursor_position()];
        pos.y = 230.0f;
        fn_8025DE10((void *)arg0, &pos);
    }
}

void TAdEnterSerialAccessGC::draw_screen(void *arg0, void *arg1) {
    ((TWindowBase *)arg0)->draw_window_frame(arg1);
    TAdSubPlyItemGC::render_status_line(serial_entry_status_line_position[0].a, serial_entry_status_line_position[0].b, 0.8f, (const char *)get_localized_text_entry(0x17, 4), -1);
    TAdEnterSerialAccessGC::draw_serial_plates();
    TAdEnterSerialAccessGC::draw_serial_chars((saddr)arg1);
}

void TAdEnterSerialAccessGC::render() {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

}
