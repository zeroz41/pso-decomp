#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
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
#include "pso/system/vector.h"

#pragma readonly_strings on

extern "C" {


void TWindowDD_WS_String::render() {
    f32 y;
    u8 *entry;

    entry = reinterpret_cast<u8 *>(draw_default_entry());
    calc_inner_rect(reinterpret_cast<WindowDrawContext *>(entry));
    draw_entry_if_visible(entry);
    y = *(f32 *)((s8 *)entry + 0x14);
    *(f32 *)((s8 *)entry + 0x14) += 1.0f;
    draw_visible_window_entries(
        this,
        &entry_list,
        reinterpret_cast<WindowDrawContext *>(entry));
}

void TWindowDD_WS_String::draw_entry_if_visible(void *entry) {
    if (*(s32 *)((s8 *)entry + 0x30) >= 0) {
        draw((saddr)entry, pad_60, 0.0f);
    }
}

void TWindowDD_WS_String::run_task() {
    ((TWindowDD *)this)->initialize_subwindow();
    update_fade();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(&entry_list));
}

}

extern const f32 TWindowDD__data_805DFB58;
extern const u32 lbl_805DFC18;

void TWindowDD_WS_String::init_and_set_field50(void *arg1) {
    copy_vec2(target_position, pad_64);
    tween_ticks = (saddr)arg1;
}

void TWindowDD_WS_String::update_position(s32 arg1) {
    copy_vec2(target_position, pad_6C);
    tween_ticks = arg1;
    if (pad_6C[0] < 0.0f) {
        target_position[0] -= target_size[0];
    }
    if (pad_6C[1] < 0.0f) {
        target_position[1] -= target_size[1];
    }
}

void TWindowDD__sub_803412A0(TWindowDD_WS_String *self) {
    u8 *entry;
    entry = (u8 *)self->get_array_entry(0);
    if (entry != NULL) {
        measure_message_text_width_default(entry);
        self->target_size[0] = (2.0f * TWindowDD__data_805DFB58) + *(f32 *)((s8 *)entry + 0x10);
    }
}

void TWindowDD_WS_String::set_first_entry_text(u32 str) {
    u8 *entry;
    entry = (u8 *)get_array_entry(0);
    if (entry != NULL) {
        set_text_entry_string(entry, str, 0x80);
    }
}


const char *lbl_805D42D8 = "TWindowDD_WS_String";

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

TWindowDD_WS_String::~TWindowDD_WS_String() {}

extern "C" {
TWindowDD_WS_String::TWindowDD_WS_String(f32 *pos, f32 *size, u32 str, s32 style)
    : TWindowBase((u8 *)&TWindowDD__data_804EFC24, 4, (u8 *)pos) {
    u8 *entry;
    m_name = lbl_805D42D8;
    copy_vec2(pad_64, pos);
    copy_vec2(pad_6C, size);
    pad_60 = style;
    entry = (u8 *)get_array_entry(0);
    if (entry != NULL) {
        set_text_entry_string(entry, str, 0x80);
        *(f32 *)((s8 *)entry + 0x8) = 0.0f;
        *(f32 *)((s8 *)entry + 0xC) = 0.0f;
        measure_message_text_width_default(entry);
        ((TWindowHelpItem *)entry)->reset_float_field();
    }
    if ((pad_60 == 1) || (pad_60 == 3)) {
        *(s32 *)((s8 *)entry + 0x24) = lbl_805DFC18;
    }
    open_tick = 0x01000000;
}

TWindowDD_WS_String *TWindowDD__sub_8034146C(f32 *pos, f32 *size, u32 str, s32 style, f32 width) {
    TWindowDD__data_804EFC24.pad_00[0] = width;
    TWindowDD__data_804EFC24.pad_00[1] = TWindowDD__data_805DFB20;
    return new TWindowDD_WS_String(pos, size, str, style);
}

}
