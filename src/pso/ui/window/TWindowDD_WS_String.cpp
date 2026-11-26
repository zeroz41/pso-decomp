#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowDD_WS_String.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowHelpItem.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/vector.h"
#include "pso/ui/window/WindowTextEntry.h"

#pragma readonly_strings on



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
        draw((saddr)entry, text_style, 0.0f);
    }
}

void TWindowDD_WS_String::run_task() {
    update_window();
    update_fade();
    update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(&entry_list));
}


extern const u32 lbl_805DFC18;

void TWindowDD_WS_String::move_to_start(s32 ticks) {
    copy_vec2(target_position, start_position);
    tween_ticks = ticks;
}

void TWindowDD_WS_String::update_position(s32 ticks) {
    copy_vec2(target_position, end_position);
    tween_ticks = ticks;
    if (end_position[0] < 0.0f) {
        target_position[0] -= target_size[0];
    }
    if (end_position[1] < 0.0f) {
        target_position[1] -= target_size[1];
    }
}

void TWindowDD_WS_String::fit_width_to_text() {
    WindowTextEntry *entry;
    entry = (WindowTextEntry *)get_array_entry(0);
    if (entry != NULL) {
        measure_message_text_width_default(entry);
        target_size[0] = (2.0f * window_dd_frame_margin) + entry->width;
    }
}

void TWindowDD_WS_String::set_first_entry_text(u32 str) {
    WindowTextEntry *entry;
    entry = (WindowTextEntry *)get_array_entry(0);
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

TWindowDD_WS_StringLayout lbl_804EFC00 = {
    1, 1,
    {3, {0.0f, 0.0f}, 0.2f, TWindowDD__data_805DFC14, 0x40, NULL},
};

// Size is written by TWindowDD_WS_String::create before each window is built.
WindowDescriptor word_select_string_descriptor = {
    {0.0f, 0.0f}, lbl_805DFC20, &lbl_804EFC00, 3,
};

TWindowDD_WS_String::~TWindowDD_WS_String() {}

TWindowDD_WS_String::TWindowDD_WS_String(f32 *pos, f32 *size, u32 str, s32 style)
    : TWindowBase((u8 *)&word_select_string_descriptor, 4, (u8 *)pos) {
    WindowTextEntry *entry;
    m_name = lbl_805D42D8;
    copy_vec2(start_position, pos);
    copy_vec2(end_position, size);
    text_style = style;
    entry = (WindowTextEntry *)get_array_entry(0);
    if (entry != NULL) {
        set_text_entry_string(entry, str, 0x80);
        entry->x = 0.0f;
        entry->y = 0.0f;
        measure_message_text_width_default(entry);
        ((TWindowHelpItem *)entry)->reset_float_field();
    }
    if ((text_style == 1) || (text_style == 3)) {
        entry->color = lbl_805DFC18;
    }
    open_tick = 0x01000000;
}

TWindowDD_WS_String *TWindowDD_WS_String::create(f32 width, f32 *pos, f32 *size, u32 str, s32 style) {
    word_select_string_descriptor.size[0] = width;
    word_select_string_descriptor.size[1] = window_dd_row_height;
    return new TWindowDD_WS_String(pos, size, str, style);
}

