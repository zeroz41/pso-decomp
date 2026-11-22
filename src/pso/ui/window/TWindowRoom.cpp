#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/window/TWindowRoom.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/unk/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowLayout.h"

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
const char *TWindowRoom__class_name = "TWindowRoom";

}

void *TWindowRoom::get_title_entry() {
    return (void *)((TWindowBase *)this)->get_array_entry(0);
}

void TWindowSubStatusDisp::set_entry_display_value(s32 str) {
    set_text_entry_string((u8 *)(get_array_entry(0)), str, 0x60);
}

void TWindowRoom::draw_tab(WindowDrawContext *context) {
    draw_window_tab(context, &context->inner_x, 3, tabParameter);
}

void TWindowRoom::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_tab(context);
    draw_visible_window_entries(this, &entry_list, context);
}
void TWindowRoom::run_task() { ((TWindowDD *)this)->initialize_subwindow(); ((TWindowBase *)this)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((char*)this + 0x24)); }

TWindowRoom::~TWindowRoom() {}

TWindowRoom::TWindowRoom(char *title)
    : TWindowBase((u8 *)&room_window_base_parameters, 4, (u8 *)get_window_layout_position(0xAF)) {
    RoomTitleEntry *entry;
    m_name = TWindowRoom__class_name;
    entry = (RoomTitleEntry *)((TWindowBase *)this)->get_array_entry(0);
    set_text_entry_string((u8 *)entry, (uaddr)title, 0x60);
    measure_message_text_width_default(entry);
    target_size[0] = 10.0f + (entry->positionX + entry->width);
    target_position[0] -= target_size[0];
    ((TWindowBase *)this)->save_position();
    tabParameter = TWindowSubStatusDisp__sub_802877A4(frame_size[0] - 16.0f);
}
