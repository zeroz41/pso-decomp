#include "types.h"
#include "pso/misc/TWindowMessage.h"
#include "pso/misc/TWindowBase.h"
#include "pso/TMainTask.h"
#include "pso/TObject.h"
#include "pso/misc/TLobby_80132ED0.h"
#include "pso/quest/TQuestThread.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowSubStatusDisp_80144B14.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/ui/TAdEnterBaseGC_8032B38C.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/ui/TAdEnterSerialAccessGC.h"
#pragma readonly_strings on

struct RecoveredGlobal_8032B904_lbl_80477278 { s32 value; u8 remaining[0xC]; };

struct RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20 {
    s32 value;
    u8 remaining[0x80];
};

struct RecoveredGlobal_8032BB34___vt__18TAdEnterPasswordGC {
    s32 value;
    u8 remaining[0x18];
};

#include <stddef.h>
#include "pso/TAdMultiChgGameModeGC.h"
#include "pso/TLevelSelect.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowKeyBoardSoft.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
struct Stack_803216C0 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_803216C0_lbl_8047653C {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_803216C0_lbl_805430D0 {
    s32 value;
    u8 remaining[0x14];
};

struct Stack_803217B8 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_803217B8_lbl_80476524 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_803217B8_lbl_805430A4 {
    s32 value;
    u8 remaining[0x14];
};

struct Stack_80321874 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_80321874_lbl_80476518 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80321874_lbl_80543090 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80322418_lbl_804ED9F8 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804764E8
{
  s32 value;
  u8 remaining[0xC];
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

struct RecoveredGlobal_80321B28_lbl_8050E208
{
  s32 value;
  u8 remaining[0x1AC];
};

struct RecoveredGlobal_80321B28_lbl_8050E3B8
{
  s32 value;
  u8 remaining[0x1AC];
};

struct T_80321738 { s32 a; s32 b; s32 c; };

struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804764E8;

typedef struct Plate_803214C4 { u8 pad[0x3B4]; } Plate_803214C4;

typedef struct Vec2_803214C4 { f32 x; f32 y; } Vec2_803214C4;

typedef struct Rect_803214C4 { f32 x; f32 y; f32 w; f32 h; } Rect_803214C4;

typedef struct Col_803214C4 { u32 v; } Col_803214C4;

struct Pos_80321358 { f32 x, y; };

struct V_803212F8 { f32 a; f32 b; };

extern "C" {
void strncpy(s32, s32, s32);
s32 memset(void *, int, int);
extern RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 TAdEnterSerialAccessGC__access_key_input_buffer;
extern RecoveredGlobal_803216C0_lbl_8047653C lbl_8047653C;
extern RecoveredGlobal_803216C0_lbl_805430D0 enter_serial_formatted_buffer;
extern RecoveredGlobal_803217B8_lbl_80476524 lbl_80476524;
extern RecoveredGlobal_803217B8_lbl_805430A4 lbl_805430A4;
extern RecoveredGlobal_80321874_lbl_80476518 lbl_80476518;
extern RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8 TAdEnterSerialAccessGC__raw_serial_buffer;
extern RecoveredGlobal_80321874_lbl_80543090 TAdEnterSerialAccessGC_serial_buffer;
extern RecoveredGlobal_80322418_lbl_804ED9F8 serial_access_entered_value_table;
int serial_to_hex_string__22TAdEnterSerialAccessGCFi(void);
void mem_free(void *p);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 play_sound_effect(int, int, int, int);
s32 forward_input__22TAdEnterSerialAccessGCFPv(void *, void *, int);
s32 strlen(int);
extern RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804764E8 TAdEnterSerialAccessGC__selection_positions;
extern RecoveredGlobal_80321B28_lbl_8050E208 controller_input_state;
extern RecoveredGlobal_80321B28_lbl_8050E3B8 controller_physical_port_bank;
extern u32 TAdEnterSerialAccessGC__keyboard_control;
extern s32 TAdEnterSerialAccessGC__input_state;
extern char lbl_804764D8[];
extern char lbl_804764E0[];
extern T_80321738 lbl_80476530;
extern u8 lbl_805430BC[];
int sprintf(char *, const char *, ...);
void sscanf(int, const char *, ...);
extern char lbl_80543010[];
extern const char serial_unsigned_decimal_scan_format[4] = "%lu";
extern char lbl_80543050[];
s32 update_window_mode_from_progress__6TLobbyFPv(void *, void *);
extern u8 lbl_804764C8[];
extern u8 lbl_804764D0[];
s32 load_and_verify_character_save__23TAdSinglePlyChrSelectGCFPc(void *, void *);
void *__nw__7TObjectFUl(int);
void __ct__9TAdBackGCFv(void *, void *);
void __ct__12TAdBackTxtGCFv(void *, void *);
void *__ct__14TAdSelectCurGCFv(void *, TObject *, void *, void *);
extern u8 lbl_804764F8[];
extern s32 __vt__22TAdEnterSerialAccessGC[];
extern s32 TAdEnterSerialAccessGC__name;
void TAdEnterSerialAccessGC__sub_802C4B64(void *, void *, Col_803214C4, int);
void __dt__19TAdPlyChrSelPlateGCFv(void *, int);
void *__ct__19TAdPlyChrSelPlateGCFv(void *, TObject *, void *);
extern Vec2_803214C4 lbl_80476548[];
extern Vec2_803214C4 serial_plate_position_table[];
extern Col_803214C4 lbl_805DF4D8;
extern const f32 lbl_805DF4F4;
extern const f32 lbl_805DF4F8;
extern const f32 lbl_805DF4FC;
extern const f32 lbl_805DF500;
extern const f32 lbl_805DF504;
s32 render_status_line__15TAdSubPlyItemGCFi(void *, int, f32, f32, f32);
void fn_8025DE10(void *arg0, void *arg1);
extern f32 serial_char_row_x_table[][13];
extern const f32 TAdEnterSerialAccessGC__data_805DF4DC;
extern char lbl_805DF4E0[4];
extern const f32 lbl_805DF4E4;
void draw_window_frame__11TWindowBaseFPv();
extern V_803212F8 serial_entry_status_line_position[];
void __dl__7TObjectFPv(void *);

extern const f32 lbl_805DF4E8;
extern s32 lbl_805DF4EC;
extern const f32 lbl_805DF4F0;

__declspec(section ".data") V_803212F8 serial_entry_status_line_position[1] = {{0.0f, 0.0f}};
__declspec(section ".data") RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8 TAdEnterSerialAccessGC__raw_serial_buffer = {0};
__declspec(section ".data") RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 TAdEnterSerialAccessGC__access_key_input_buffer = {0};
struct TAdEnterSerialAccessGC_80321F60;
void run_task__22TAdEnterSerialAccessGCFv(TAdEnterSerialAccessGC_80321F60 *);
void render_shadows__7TObjectFv(void *);
s32 __vt__22TAdEnterSerialAccessGC[6] = {
    0, 0, (s32)__dt__22TAdEnterSerialAccessGCFv,
    (s32)run_task__22TAdEnterSerialAccessGCFv,
    (s32)TAdEnterSerialAccessGC::render,
    (s32)render_shadows__7TObjectFv
};

void TAdEnterSerialAccessGC::render(void *self) {
    if (TMainTask::get_render_pass() == 1) { return;
    }
}

void TAdEnterSerialAccessGC::draw_screen(void *arg0, void *arg1) {
    draw_window_frame__11TWindowBaseFPv();
    render_status_line__15TAdSubPlyItemGCFi((void *)get_localized_text_entry(0x17, (s32)((void *)4)), -1, serial_entry_status_line_position[0].a, serial_entry_status_line_position[0].b, TAdEnterSerialAccessGC__data_805DF4DC);
    TAdEnterSerialAccessGC::draw_serial_plates();
    TAdEnterSerialAccessGC::draw_serial_chars((s32)arg1);
}

void TAdEnterSerialAccessGC::draw_serial_chars(s32 arg0) {
    char text[0xFF];
    char buf[8];
    Pos_80321358 pos;
    char *p;
    u32 n;
    f32 *row;
    s32 str;
    u32 i;
    s32 r;
    if (TAdEnterSerialAccessGC__keyboard_control != 0) {
        str = ((TWindowSubComCard *)TAdEnterSerialAccessGC__keyboard_control)->realloc_buffer();
        memset(text, 0, 0xFF);
        strncpy((s32) text, str, 0xFF);
        mem_free((void *)str);
        p = text;
        r = TAdEnterSerialAccessGC__input_state == 2 ? 0 : 1;
        row = serial_char_row_x_table[r];
        n = r * 2 + 10;
        for (i = 0; i < n; i++, p++) {
            memset(buf, 0, 8);
            sprintf(buf, lbl_805DF4E0, *p);
            render_status_line__15TAdSubPlyItemGCFi(buf, -1, row[i], lbl_805DF4E4, TAdEnterSerialAccessGC__data_805DF4DC);
        }
        pos.x = row[((TAdEnterSerialAccessGC *)TAdEnterSerialAccessGC__keyboard_control)->get_field20_state()];
        pos.y = lbl_805DF4E4;
        fn_8025DE10((void *)arg0, &pos);
    }
}

void TAdEnterSerialAccessGC::draw_serial_separators() {
    render_status_line__15TAdSubPlyItemGCFi(&lbl_805DF4EC, -1, lbl_805DF4E8, lbl_805DF4E4, TAdEnterSerialAccessGC__data_805DF4DC);
    render_status_line__15TAdSubPlyItemGCFi(&lbl_805DF4EC, -1, lbl_805DF4F0, lbl_805DF4E4, TAdEnterSerialAccessGC__data_805DF4DC);
}

typedef char RecoveredGlobal_803216C0_lbl_8047653C_size[sizeof(RecoveredGlobal_803216C0_lbl_8047653C) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_803216C0_lbl_805430D0_size[sizeof(RecoveredGlobal_803216C0_lbl_805430D0) == 0x18 ? 1 : -1];

#pragma push
#pragma fp_contract on
void TAdEnterSerialAccessGC::draw_serial_plates() {
    Plate_803214C4 a;
    Plate_803214C4 b;
    Rect_803214C4 pa;
    Rect_803214C4 pb;
    u32 i;
    pa.x = lbl_805DF4F4;
    pa.y = lbl_805DF4F8;
    __ct__19TAdPlyChrSelPlateGCFv(&a, tl_clipout, &pa);
    pb.x = lbl_805DF4FC;
    pb.y = lbl_805DF4F8;
    __ct__19TAdPlyChrSelPlateGCFv(&b, tl_clipout, &pb);
    {
        Vec2_803214C4 pos = lbl_80476548[0];
        Col_803214C4 c = lbl_805DF4D8;
        switch (TAdEnterSerialAccessGC__input_state) {
        case 3:
            break;
        case 2:
            TAdEnterSerialAccessGC__sub_802C4B64(&b, &serial_plate_position_table[0], c, 0);
            for (i = 0; i < 2; i++) {
                TAdEnterSerialAccessGC__sub_802C4B64(&a, &serial_plate_position_table[i + 1], c, 0);
            }
            TAdEnterSerialAccessGC::draw_serial_separators();
            break;
        case 4:
            for (i = 0; i < 3; i++) {
                pos.x = lbl_805DF504 * (f32)i + lbl_805DF500;
                TAdEnterSerialAccessGC__sub_802C4B64(&a, &pos, c, 0);
            }
            TAdEnterSerialAccessGC::draw_serial_separators();
            break;
        }
    }
    __dt__19TAdPlyChrSelPlateGCFv(&b, -1);
    __dt__19TAdPlyChrSelPlateGCFv(&a, -1);
}
#pragma pop

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

s32 *TAdEnterSerialAccessGC::get_formatted_serial() {
    typedef char sp8_offset[(offsetof(Stack_803216C0, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803216C0, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803216C0, sp10) == 0x8) ? 1 : -1];
    Stack_803216C0 stack;
    memset((void *)&enter_serial_formatted_buffer.value, 0, 0x18);
    stack.sp8 = *(s32 *)((s8 *)&lbl_8047653C.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_8047653C.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_8047653C.value + 8);
    ((TAdEnterSerialAccessGC *)(&enter_serial_formatted_buffer.value))->format_dashed_serial((u8 *)((void *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1153C)), (u32)(3), (u32 *)((void *)&stack.sp8));
    return &enter_serial_formatted_buffer.value;
}

typedef char RecoveredGlobal_803217B8_lbl_80476524_size[sizeof(RecoveredGlobal_803217B8_lbl_80476524) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4_size[sizeof(RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_803217B8_lbl_805430A4_size[sizeof(RecoveredGlobal_803217B8_lbl_805430A4) == 0x18 ? 1 : -1];

u8 *TAdEnterSerialAccessGC__sub_80321738(void) {
    memset(lbl_805430BC, 0, 0x14);
    T_80321738 t = lbl_80476530;
    ((TAdEnterSerialAccessGC *)lbl_805430BC)->format_dashed_serial((u8 *)((void *)((u32)TAdEnterSerialAccessGC::convert_serial_hex_to_decimal(TAdSinglePlyChrSelectGC::get_instance() + 0x1152C))), (u32)(3), (u32 *)&t);
    return lbl_805430BC;
}

s32 *TAdEnterSerialAccessGC__sub_803217B8(void) {
    typedef char sp8_offset[(offsetof(Stack_803217B8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_803217B8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_803217B8, sp10) == 0x8) ? 1 : -1];
    Stack_803217B8 stack;
    memset((void *)&lbl_805430A4.value, 0, 0x18);
    stack.sp8 = *(s32 *)((s8 *)&lbl_80476524.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_80476524.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_80476524.value + 8);
    ((TAdEnterSerialAccessGC *)(&lbl_805430A4.value))->format_dashed_serial((u8 *)((void *) (&(*(RecoveredGlobal_803217B8_TAdEnterSerialAccessGC__data_804EC9C4 *)&TAdEnterSerialAccessGC__access_key_input_buffer).value)), (u32)(3), (u32 *)((void *)&stack.sp8));
    return &lbl_805430A4.value;
}

typedef char RecoveredGlobal_80321874_lbl_80476518_size[sizeof(RecoveredGlobal_80321874_lbl_80476518) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8_size[sizeof(RecoveredGlobal_80321874_TAdEnterSerialAccessGC__data_804EC9B8) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80321874_lbl_80543090_size[sizeof(RecoveredGlobal_80321874_lbl_80543090) == 0x14 ? 1 : -1];

s32 TAdEnterSerialAccessGC::parse_serial_value() {
    s32 sp8;
    sp8 = 0;
    sscanf(TAdSinglePlyChrSelectGC::get_instance() + 0x1152C, "%08x", &sp8);
    return sp8;
}

s32 *TAdEnterSerialAccessGC__sub_80321874(void) {
    typedef char sp8_offset[(offsetof(Stack_80321874, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80321874, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80321874, sp10) == 0x8) ? 1 : -1];
    Stack_80321874 stack;
    memset((void *)&TAdEnterSerialAccessGC_serial_buffer.value, 0, 0x14);
    stack.sp8 = *(s32 *)((s8 *)&lbl_80476518.value + 0);
    stack.spC = *(s32 *)((s8 *)&lbl_80476518.value + 4);
    stack.sp10 = *(s32 *)((s8 *)&lbl_80476518.value + 8);
    ((TAdEnterSerialAccessGC *)(&TAdEnterSerialAccessGC_serial_buffer.value))->format_dashed_serial((u8 *)((void *)&TAdEnterSerialAccessGC__raw_serial_buffer.value), (u32)(3), (u32 *)((void *)&stack.sp8));
    return &TAdEnterSerialAccessGC_serial_buffer.value;
}

typedef char RecoveredGlobal_8032B904_lbl_80477278_size[sizeof(RecoveredGlobal_8032B904_lbl_80477278) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20_size[sizeof(RecoveredGlobal_8032BA8C_TAdEnterPasswordGC__data_804EDA20) == 0x84 ? 1 : -1];

void init__22TAdEnterSerialAccessGCFv(void) {
    TAdEnterSerialAccessGC__sub_8032195C(((s32)serial_to_hex_string__22TAdEnterSerialAccessGCFi()));
}

void TAdEnterSerialAccessGC__sub_8032190C(s32 arg0) {
    memset(&TAdEnterSerialAccessGC__access_key_input_buffer.value, 0, 0xd);
    strncpy((s32) &TAdEnterSerialAccessGC__access_key_input_buffer.value, arg0, 0xd);
}
typedef char RecoveredGlobal_8032BB34___vt__18TAdEnterPasswordGC_size[sizeof(RecoveredGlobal_8032BB34___vt__18TAdEnterPasswordGC) == 0x1C ? 1 : -1];

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8_size[sizeof(RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8) == 0xC ? 1 : -1];
void TAdEnterSerialAccessGC__sub_8032195C(s32 arg0) {
    memset((void *) (&(*(RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value), 0, 0xB);
    strncpy((s32)((void *) (&(*(RecoveredGlobal_8032195C_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value)), arg0, 0xB);
}
#pragma pop

typedef struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804764E8 RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804764E8;
typedef struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8 RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8;
typedef struct RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4 RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4;
typedef struct RecoveredGlobal_80321B28_lbl_8050E208 RecoveredGlobal_80321B28_lbl_8050E208;
typedef struct RecoveredGlobal_80321B28_lbl_8050E3B8 RecoveredGlobal_80321B28_lbl_8050E3B8;
typedef char RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804764E8_size[((sizeof(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804764E8)) == 0x10) ? (1) : (-1)];
typedef char RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8_size[((sizeof(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8)) == 0xC) ? (1) : (-1)];
typedef char RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4_size[((sizeof(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4)) == 0x10) ? (1) : (-1)];
typedef char RecoveredGlobal_80321B28_lbl_8050E208_size[((sizeof(RecoveredGlobal_80321B28_lbl_8050E208)) == 0x1B0) ? (1) : (-1)];
typedef char RecoveredGlobal_80321B28_lbl_8050E3B8_size[((sizeof(RecoveredGlobal_80321B28_lbl_8050E3B8)) == 0x1B0) ? (1) : (-1)];

char *TAdEnterSerialAccessGC::convert_serial_hex_to_decimal(int arg0) {
    u32 v = 0;
    sscanf(arg0, "%08X", &v);
    memset(lbl_80543050, 0, 0x40);
    if (v != 0) {
        sprintf(lbl_80543050, "%010lu", v);
    }
    return lbl_80543050;
}

char *TAdEnterSerialAccessGC::hex_to_decimal_string(int arg0) {
    s32 v = 0;
    sscanf(arg0, (const char *)&serial_unsigned_decimal_scan_format, &v);
    memset(lbl_80543010, 0, 0x40);
    sprintf(lbl_80543010, "%08X", v);
    return lbl_80543010;
}

void create_draw_callback__22TAdEnterSerialAccessGCFv(void) {
    TAdEnterSerialAccessGC::create_callback(lbl_804764D8, lbl_804764E0, (void *)TAdEnterSerialAccessGC::draw_screen);
}

s32 TAdEnterSerialAccessGC::open_message_window(void *arg0, void *arg1) {
    s32 r = update_window_mode_from_progress__6TLobbyFPv(lbl_804764C8, lbl_804764D0);
    ((TWindowMessage *)r)->append_line(get_localized_text_entry(0x17, (s32)arg1), 1);
    return r;
}

void TAdEnterSerialAccessGC__sub_80321B28(u8 *ad_enter_serial_access_gc, int arg1) {
  int temp_r30;
  int temp_r3_8;
  unsigned int temp_r3;
  unsigned int temp_r3_10;
  unsigned int temp_r3_11;
  unsigned int temp_r3_12;
  unsigned int temp_r3_13;
  unsigned int temp_r3_2;
  unsigned int temp_r3_3;
  unsigned int temp_r3_4;
  unsigned int temp_r3_5;
  unsigned int temp_r3_6;
  unsigned int temp_r3_7;
  unsigned int temp_r3_9;
  temp_r30 = ((TWindowSubComCard *)TAdEnterSerialAccessGC__keyboard_control)->realloc_buffer();
  if (((((int) (*(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_4c)) == 0) && (TWindowShortListCtrl__check_controller_button((void *) (((u8 *)&controller_physical_port_bank.value) + 0x20), 2) != 0)) || ((((int) (*(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_4c)) == 0) && (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) (((u8 *)&controller_input_state.value) + 0x160), 2) != 0)))
  {
    switch ((int) TAdEnterSerialAccessGC__input_state)
    {
      case 3:
        break;
      case 2:
        temp_r3 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_58;
        if (temp_r3 != 0U)
      {
        ((TWindowBase *)temp_r3)->close();
        *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_58 = 0U;
      }
        temp_r3_2 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_5c;
        if (temp_r3_2 != 0U)
      {
        ((TWindowBase *)temp_r3_2)->close();
        *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_5c = 0U;
      }
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        queue_destruction__7TObjectFv((void *)((int) TAdEnterSerialAccessGC__keyboard_control));
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        memset((void *) (&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value), 0, 0xB);
        *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_44 = 6;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
      case 4:
        temp_r3_3 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_50;
        if (temp_r3_3 != 0U)
      {
        queue_destruction__7TObjectFv((void *)((int) temp_r3_3));
        *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_50 = 0U;
      }
        temp_r3_4 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_58;
        if (temp_r3_4 != 0U)
      {
        ((TWindowBase *)temp_r3_4)->close();
        *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_58 = 0U;
      }
        temp_r3_5 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_5c;
        if (temp_r3_5 != 0U)
      {
        ((TWindowBase *)temp_r3_5)->close();
        *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_5c = 0U;
      }
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        queue_destruction__7TObjectFv((void *)((int) TAdEnterSerialAccessGC__keyboard_control));
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        ((TAdEnterSerialAccessGC *)(*(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54))->reset_input_state();
        memset((void *) (&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4 *)&TAdEnterSerialAccessGC__access_key_input_buffer).value), 0, 0xD);
        *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_44 = 1;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
    }
    mem_free((void *)temp_r30);
    return;
  }
  *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_64 = (int) (*(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_60);
  if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
  {
    if (forward_input__22TAdEnterSerialAccessGCFPv((void *) ad_enter_serial_access_gc, (void *) arg1, (int) temp_r30) != 0)
    {
      *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_60 = 1;
      temp_r3_6 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54;
      if (temp_r3_6 != 0U)
      {
        ((TAdEnterSerialAccessGC *)temp_r3_6)->set_state_3();
      }
    }
    else
    {
      *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_60 = 0;
      temp_r3_7 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54;
      if (temp_r3_7 != 0U)
      {
        ((TAdEnterSerialAccessGC *)temp_r3_7)->set_active();
      }
    }
    if ((((TWindowSubComCard *)TAdEnterSerialAccessGC__keyboard_control)->update_keyboard() != 0) && (forward_input__22TAdEnterSerialAccessGCFPv((void *) ad_enter_serial_access_gc, (void *) arg1, (int) temp_r30) == 0))
    {
      free_menu_object((void *)TAdEnterSerialAccessGC__keyboard_control);
      play_sound_effect(0x53F06, 0, 0, 0);
    }
  }
  temp_r3_8 = *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_60;
  if (((int) (*(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_64)) != (*(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_60))
  {
    if ((*(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_60) != 0)
    {
      temp_r3_9 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54;
      if (temp_r3_9 != 0U)
      {
        ((TAdEnterSerialAccessGC *)temp_r3_9)->reset_input_state();
        ((TLevelSelect *)(*(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54))->add_item_rect((void *) (((u8 *)&TAdEnterSerialAccessGC__selection_positions.value) + 8));
      }
    }
    else
    {
      temp_r3_10 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54;
      if (temp_r3_10 != 0U)
      {
        ((TAdEnterSerialAccessGC *)temp_r3_10)->reset_input_state();
        ((TLevelSelect *)(*(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54))->add_item_rect((void *)&TAdEnterSerialAccessGC__selection_positions.value);
      }
    }
  }
  if ((((TAdSinglePlyChrSelectGC *)(*(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_54))->get_selected_slot() == 1) && (forward_input__22TAdEnterSerialAccessGCFPv((void *) ad_enter_serial_access_gc, (void *) arg1, (int) temp_r30) != 0))
  {
    temp_r3_11 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_58;
    if (temp_r3_11 != 0U)
    {
      ((TWindowBase *)temp_r3_11)->close();
      *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_58 = 0U;
    }
    temp_r3_12 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_5c;
    if (temp_r3_12 != 0U)
    {
      ((TWindowBase *)temp_r3_12)->close();
      *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_5c = 0U;
    }
    switch (arg1)
    {
      case 0:
        temp_r3_13 = *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_50;
        if (temp_r3_13 != 0U)
      {
        queue_destruction__7TObjectFv((void *)((int) temp_r3_13));
        *(unsigned int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_50 = 0U;
      }
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        queue_destruction__7TObjectFv((void *)((int) TAdEnterSerialAccessGC__keyboard_control));
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        strncpy((s32)((void *) (&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9B8 *)&TAdEnterSerialAccessGC__raw_serial_buffer).value)), (s32)((int) temp_r30), 0xB);
        TAdEnterSerialAccessGC__sub_80322418((s32)((int) get_field_118__22TAdEnterSerialAccessGCFv()), 0);
        *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_44 = 3;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
      case 1:
        if (((unsigned int) TAdEnterSerialAccessGC__keyboard_control) != 0U)
      {
        queue_destruction__7TObjectFv((void *)((int) TAdEnterSerialAccessGC__keyboard_control));
        TAdEnterSerialAccessGC__keyboard_control = 0U;
      }
        strncpy((s32)((void *) (&(*(RecoveredGlobal_80321B28_TAdEnterSerialAccessGC__data_804EC9C4 *)&TAdEnterSerialAccessGC__access_key_input_buffer).value)), (s32)((int) temp_r30), 0xD);
        TAdEnterSerialAccessGC__sub_80322418((s32)((int) get_field_118__22TAdEnterSerialAccessGCFv()), 1);
        *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_44 = 7;
        TAdEnterSerialAccessGC__input_state = 5;
        break;
    }
  }
  *(int *)&((TAdEnterSerialAccessGC *)ad_enter_serial_access_gc)->m_4c = strlen((int) temp_r30);
  mem_free((void *)temp_r30);
}

void TAdEnterSerialAccessGC__sub_80321F18(void* p) { TAdEnterSerialAccessGC__sub_80321B28((u8 *)p, 1); }
void TAdEnterSerialAccessGC__sub_80321F3C(void* p) { TAdEnterSerialAccessGC__sub_80321B28((u8 *)p, 0); }

struct TAdEnterSerialAccessGC_80321F60 {
    u8 pad0[0x40];
    s32 field_40;
    s32 field_44;
    s32 field_48;
    u8 pad4C[0x4];
    void *field_50;
    void *field_54;
    s32 field_58;
    s32 field_5C;
    s32 field_60;
};
void *__ct__10TAdTitleGCFP7TObjectl(void *, void *, s32);
void TAdEnterSerialAccessGC::run_task() {
    void *p;
    f32 w;

    w = 320.0f - (f32)(calc_text_width((char *)((void *)get_localized_text_entry(0x17, (s32)((void *)4)))) >> 1);
    serial_entry_status_line_position[0].b = 250.0f;
    serial_entry_status_line_position[0].a = w;
    ((TAdEnterSerialAccessGC_80321F60 *)this)->field_40 = TAdEnterSerialAccessGC__input_state;
    switch (TAdEnterSerialAccessGC__input_state) {
    case 0:
        TAdEnterSerialAccessGC__input_state = 1;
        break;
    case 1:
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_60 = 0;
        p = __nw__7TObjectFUl(0x138);
        if (p != NULL) {
            p = __ct__10TAdTitleGCFP7TObjectl(p, this, 0xA);
        }
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_50 = p;
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_58 = TAdEnterSerialAccessGC::open_message_window(((TAdEnterSerialAccessGC_80321F60 *)this), (void *)0);
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_5C = ((s32 (*)(void *))create_draw_callback__22TAdEnterSerialAccessGCFv)(((TAdEnterSerialAccessGC_80321F60 *)this));
        if (((TAdEnterSerialAccessGC_80321F60 *)this)->field_54 != NULL) {
            ((TAdEnterSerialAccessGC *)((int)((TAdEnterSerialAccessGC_80321F60 *)this)->field_54))->reset_input_state();
            ((TLevelSelect *)((int)((TAdEnterSerialAccessGC_80321F60 *)this)->field_54))->add_item_rect(&TAdEnterSerialAccessGC__selection_positions);
            ((TAdEnterSerialAccessGC *)((int)((TAdEnterSerialAccessGC_80321F60 *)this)->field_54))->set_active();
        }
        TAdEnterSerialAccessGC__keyboard_control = TAdEnterSerialAccessGC::create_keyboard_control((s32)this, 0);
        TAdEnterSerialAccessGC__input_state = 2;
        break;
    case 2:
        TAdEnterSerialAccessGC__sub_80321F3C(this);
        break;
    case 3:
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_60 = 0;
        if (((TAdEnterSerialAccessGC_80321F60 *)this)->field_54 != NULL) {
            ((TAdEnterSerialAccessGC *)((int)((TAdEnterSerialAccessGC_80321F60 *)this)->field_54))->reset_input_state();
            ((TLevelSelect *)((int)((TAdEnterSerialAccessGC_80321F60 *)this)->field_54))->add_item_rect(&TAdEnterSerialAccessGC__selection_positions);
            ((TAdEnterSerialAccessGC *)((int)((TAdEnterSerialAccessGC_80321F60 *)this)->field_54))->set_active();
        }
        p = __nw__7TObjectFUl(0x138);
        if (p != NULL) {
            p = __ct__10TAdTitleGCFP7TObjectl(p, ((TAdEnterSerialAccessGC_80321F60 *)this), 0xB);
        }
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_50 = p;
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_58 = TAdEnterSerialAccessGC::open_message_window(((TAdEnterSerialAccessGC_80321F60 *)this), (void *)1);
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_5C = ((s32 (*)(void *))create_draw_callback__22TAdEnterSerialAccessGCFv)(((TAdEnterSerialAccessGC_80321F60 *)this));
        TAdEnterSerialAccessGC__keyboard_control = TAdEnterSerialAccessGC::create_keyboard_control((s32)((TAdEnterSerialAccessGC_80321F60 *)this), 1);
        TAdEnterSerialAccessGC__input_state = 4;
        break;
    case 4:
        TAdEnterSerialAccessGC__sub_80321F18(((TAdEnterSerialAccessGC_80321F60 *)this));
        break;
    case 5:
        if ((f32)++((TAdEnterSerialAccessGC_80321F60 *)this)->field_48 > 4.5f) {
            TAdEnterSerialAccessGC__input_state = ((TAdEnterSerialAccessGC_80321F60 *)this)->field_44;
        }
        break;
    case 6:
        if (((TAdEnterSerialAccessGC_80321F60 *)this)->field_54 != NULL) {
            queue_destruction__7TObjectFv(((TAdEnterSerialAccessGC_80321F60 *)this)->field_54);
            ((TAdEnterSerialAccessGC_80321F60 *)this)->field_54 = NULL;
        }
        TAdMultiChgGameModeGC::request_transition();
        break;
    case 7:
        if (((TAdEnterSerialAccessGC_80321F60 *)this)->field_54 != NULL) {
            queue_destruction__7TObjectFv(((TAdEnterSerialAccessGC_80321F60 *)this)->field_54);
            ((TAdEnterSerialAccessGC_80321F60 *)this)->field_54 = NULL;
        }
        TAdEnterSerialAccessGC::init_state();
        break;
    }
    if (((TAdEnterSerialAccessGC_80321F60 *)this)->field_40 != TAdEnterSerialAccessGC__input_state) {
        ((TAdEnterSerialAccessGC_80321F60 *)this)->field_48 = 0;
    }
}

void *__dt__22TAdEnterSerialAccessGCFv(TAdEnterSerialAccessGC *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TAdEnterSerialAccessGC;
        if (*(void **)((s8 *)arg0 + 0x58) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x58)); arg0->m_58 = 0; }
        if (*(void **)((s8 *)arg0 + 0x5C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x5C)); arg0->m_5c = 0; }
        if (*(void **)((s8 *)arg0 + 0x54) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x54)); arg0->m_54 = 0; }
        __dt__14TAdEnterBaseGCFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

u8 *TAdEnterSerialAccessGC__ct(TAdEnterSerialAccessGC *ad_enter_serial_access_gc) {
    s8 flag[0x10];
    u8 sp8[0x10];
    void *p;
    TAdEnterBaseGC__ct(ad_enter_serial_access_gc);
    *(s32 **)((s8 *)ad_enter_serial_access_gc + 0x18) = __vt__22TAdEnterSerialAccessGC;
    *(s32 *)((s8 *)ad_enter_serial_access_gc + 0) = TAdEnterSerialAccessGC__name;
    ad_enter_serial_access_gc->m_48 = 0;
    TAdEnterSerialAccessGC__input_state = 0;
    ad_enter_serial_access_gc->m_44 = 0;
    ad_enter_serial_access_gc->m_4c = 0;
    ad_enter_serial_access_gc->m_60 = 0;
    ad_enter_serial_access_gc->m_64 = 0;
    ad_enter_serial_access_gc->m_50 = 0;
    ad_enter_serial_access_gc->m_54 = 0;
    ad_enter_serial_access_gc->m_58 = 0;
    ad_enter_serial_access_gc->m_5c = 0;
    TAdEnterSerialAccessGC__keyboard_control = 0;
    if (*(s8 *) (TAdSinglePlyChrSelectGC::get_instance() + 0x1152C) != 0) {
        ((void (*)(s32)) init__22TAdEnterSerialAccessGCFv)(TAdSinglePlyChrSelectGC::get_instance() + 0x1152C);
        TAdEnterSerialAccessGC__sub_8032190C(TAdSinglePlyChrSelectGC::get_instance() + 0x1153C);
        TAdEnterSerialAccessGC::init_state();
        queue_destruction__7TObjectFv(ad_enter_serial_access_gc);
        return (u8 *)ad_enter_serial_access_gc;
    }
    flag[0] = 0;
    if (load_and_verify_character_save__23TAdSinglePlyChrSelectGCFPc(flag, sp8) != 0 && flag[0] != 0) {
        ((void (*)(s8 *)) init__22TAdEnterSerialAccessGCFv)(flag);
        TAdEnterSerialAccessGC__sub_8032190C((s32) sp8);
        TAdEnterSerialAccessGC__sub_80322418(get_field_118__22TAdEnterSerialAccessGCFv(), 1);
        TAdEnterSerialAccessGC__sub_80322418(get_field_118__22TAdEnterSerialAccessGCFv(), 0);
    }
    if ((p = __nw__7TObjectFUl(0x24)) != 0) {
        __ct__9TAdBackGCFv(p, ad_enter_serial_access_gc);
    }
    if ((p = __nw__7TObjectFUl(0x28)) != 0) {
        __ct__12TAdBackTxtGCFv(p, ad_enter_serial_access_gc);
    }
    p = __nw__7TObjectFUl(0x708);
    if (p != 0) {
        p = __ct__14TAdSelectCurGCFv(p, tl_clipout, &TAdEnterSerialAccessGC__selection_positions, lbl_804764F8);
    }
    *(void **)((s8 *)ad_enter_serial_access_gc + 0x54) = p;
    return (u8 *)ad_enter_serial_access_gc;
}

s32 TAdEnterSerialAccessGC::get_field20_state() {
    u32 temp_r3 = this->m_20;
    if (temp_r3 == 0U) {
        return 0;
    }
    return ((TWindowKeyBoardSoft *)temp_r3)->get_state();
}

typedef char RecoveredGlobal_80322418_lbl_804ED9F8_size[sizeof(RecoveredGlobal_80322418_lbl_804ED9F8) == 0x10 ? 1 : -1];
void TAdEnterSerialAccessGC__sub_80322418(s32 arg0, s32 arg1) {
    *(s32 *)((s8 *)((u8 *)&serial_access_entered_value_table.value + (arg1 * 4)) + 0) = arg0;
}

void TAdEnterSerialAccessGC::set_state_3() { *(s32*)((char*)this + 0x700) = 3; }

}
