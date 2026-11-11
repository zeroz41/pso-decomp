#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_803411E8.h"
#include "pso/ui/window/TWindowDD_80341334.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/WindowLayoutRecord.h"

#pragma readonly_strings on

extern "C" {

s32 draw_visible_window_entries(void *, void *, void *, f32);
int update_window_entry_list__11TWindowBaseFPv(void*, void*);
void *draw_default_entry__9TWindowDDFl();
int update_fade__11TWindowBaseFv(void*);

void TWindowDD_WS_String::render() {
    f32 y;
    u8 *entry;

    entry = (u8 *)draw_default_entry__9TWindowDDFl();
    calc_inner_rect(entry);
    draw_entry_if_visible(entry);
    y = *(f32 *)((s8 *)entry + 0x14);
    *(f32 *)((s8 *)entry + 0x14) += 1.0f;
    draw_visible_window_entries(this, pad_24, entry, y);
}

void TWindowDD_WS_String::draw_entry_if_visible(void *entry) {
    if (*(s32 *)((s8 *)entry + 0x30) >= 0) {
        draw((s32)entry, pad_60, 0.0f);
    }
}

void TWindowDD_WS_String::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade__11TWindowBaseFv(this);
    update_window_entry_list__11TWindowBaseFPv(this, pad_24);
}

}

extern const f32 TWindowDD__data_805DFB58;
extern const u32 lbl_805DFC18;

void TWindowDD_WS_String::init_and_set_field50(void *arg1) {
    ((TWindowSubSymbolChatPartsSet *)pad_30)->copy_vec2(pad_64);
    pad_50 = (s32)arg1;
}

void TWindowDD_WS_String::update_position(s32 arg1) {
    ((TWindowSubSymbolChatPartsSet *)pad_30)->copy_vec2(pad_6C);
    pad_50 = arg1;
    if (pad_6C[0] < 0.0f) {
        pad_30[0] -= pad_38[0];
    }
    if (pad_6C[1] < 0.0f) {
        pad_30[1] -= pad_38[1];
    }
}

void TWindowDD__sub_803412A0(TWindowDD_WS_String *self) {
    u8 *entry;
    entry = (u8 *)self->get_array_entry(0);
    if (entry != NULL) {
        TWindowDD::refresh_status_display();
        self->pad_38[0] = (2.0f * TWindowDD__data_805DFB58) + *(f32 *)((s8 *)entry + 0x10);
    }
}

void TWindowDD_WS_String::set_first_entry_text(u32 str) {
    u8 *entry;
    entry = (u8 *)get_array_entry(0);
    if (entry != NULL) {
        set_text_entry_string(entry, str, 0x80);
    }
}

extern "C" {
const char *lbl_805D42D8 = "TWindowDD_WS_String";
}

// Entry layout table of the window: one column, one row, one text record (type 3).
struct TWindowDD_WS_StringLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};

extern const u32 TWindowDD__data_805DFC14;
extern const f32 lbl_805DFC20;
extern const f32 TWindowDD__data_805DFB20;

TWindowDD_WS_StringLayout lbl_804EFC00 = {
    1, 1,
    {3, {0.0f, 0.0f}, 0.2f, TWindowDD__data_805DFC14, 0x40, NULL},
};

// Size is written by TWindowDD__sub_8034146C before each window is built.
WindowDescriptor TWindowDD__data_804EFC24 = {
    {0.0f, 0.0f}, lbl_805DFC20, &lbl_804EFC00, 3,
};

extern "C" {
s32 refresh_status_display__9TWindowDDFv(int);
extern s32 lbl_804EFC38[];

void *__dt__19TWindowDD_WS_StringFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = lbl_804EFC38;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

TWindowDD_WS_String *TWindowDD__sub_8034138C(TWindowDD_WS_String *self, f32 *pos, f32 *size, u32 str, s32 style) {
    u8 *entry;
    ((TWindowDD *)self)->construct_base((u8 *)&TWindowDD__data_804EFC24, 4, (u8 *)pos);
    *(s32 **)((s8 *)self + 0x18) = lbl_804EFC38;
    self->m_name = lbl_805D42D8;
    ((TWindowSubSymbolChatPartsSet *)self->pad_64)->copy_vec2(pos);
    ((TWindowSubSymbolChatPartsSet *)self->pad_6C)->copy_vec2(size);
    self->pad_60 = style;
    entry = (u8 *)self->get_array_entry(0);
    if (entry != NULL) {
        set_text_entry_string(entry, str, 0x80);
        ((TWindowHelpItem *)entry)->m_8 = 0.0f;
        *(f32 *)((s8 *)entry + 0xC) = 0.0f;
        refresh_status_display__9TWindowDDFv((int)entry);
        ((TWindowHelpItem *)entry)->reset_float_field();
    }
    if ((self->pad_60 == 1) || (self->pad_60 == 3)) {
        *(s32 *)((s8 *)entry + 0x24) = lbl_805DFC18;
    }
    self->m_5c = 0x01000000;
    return self;
}

TWindowDD_WS_String *TWindowDD__sub_8034146C(f32 *pos, f32 *size, u32 str, s32 style, f32 width) {
    TWindowDD_WS_String *window;
    TWindowDD__data_804EFC24.pad_00[0] = width;
    TWindowDD__data_804EFC24.pad_00[1] = TWindowDD__data_805DFB20;
    window = (TWindowDD_WS_String *)TObject::operator new(sizeof(TWindowDD_WS_String));
    if (window != NULL) {
        window = TWindowDD__sub_8034138C(window, pos, size, str, style);
    }
    return window;
}

}
