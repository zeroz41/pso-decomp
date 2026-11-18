#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/TWindowRoom.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"

struct RoomTitleEntry {
    u8 unknown00[8];
    f32 positionX;
    u8 unknown0C[4];
    f32 width;
};

// inferred: room_window_layout_entries, the layout table room_window_base_parameters points at.
struct RoomWindowLayout {
    u32 cols;
    u32 rows;
    TextLayoutRecord rec_0;
};

RoomWindowLayout room_window_layout_entries = {
    1, 1,
    {3, {10.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0x40, NULL},
};

WindowDescriptor room_window_base_parameters = {
    {160.0f, 27.0f}, 37000.0f, &room_window_layout_entries, 0x82B,
};

extern "C" {
void refresh_status_display__9TWindowDDFv(void *);
s32 get_window_layout_position(int);
const char *TWindowRoom__class_name = "TWindowRoom";
s32 draw_visible_window_entries(s32, s32, s32);
s32 draw_window_tab(s32, s32, s32, f32);
s32 draw_default_entry__9TWindowDDFl();

}

void *TWindowRoom::get_title_entry() {
    return (void *)((TWindowBase *)this)->get_array_entry(0);
}

void TWindowSubStatusDisp::set_entry_display_value(s32 arg1) {
    set_text_entry_string((u8 *)(get_array_entry(0)), arg1, 0x60);
}

void TWindowRoom::draw_tab(void *context) {
    draw_window_tab((s32)context, (s32)((u8 *)context + 0x10), 3, tabParameter);
}

void TWindowRoom::render() {
    s32 temp_r3;
    s32 arg0 = (s32)this;

    temp_r3 = draw_default_entry__9TWindowDDFl();
    ((TWindowRoom *)arg0)->draw_tab((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
}
void TWindowRoom::run_task() { ((TWindowDD *)this)->initialize_subwindow(); ((TWindowBase *)this)->update_window_entry_list((char*)this + 0x24); }

TWindowRoom::~TWindowRoom() {}

TWindowRoom::TWindowRoom(char *title)
    : TWindowBase((u8 *)&room_window_base_parameters, 4, (u8 *)get_window_layout_position(0xAF)) {
    RoomTitleEntry *entry;
    m_name = TWindowRoom__class_name;
    entry = (RoomTitleEntry *)((TWindowBase *)this)->get_array_entry(0);
    set_text_entry_string((u8 *)entry, (u32)title, 0x60);
    refresh_status_display__9TWindowDDFv(entry);
    width = 10.0f + (entry->positionX + entry->width);
    positionX -= width;
    ((TWindowBase *)this)->save_position();
    tabParameter = TWindowSubStatusDisp__sub_802877A4(unknown48 - 16.0f);
}
