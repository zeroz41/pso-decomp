#include "pso/ui/window/WindowDrawContext.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/ui/window/TWindowRoom.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowBase.h"

#include "pso/ui/window/WindowLayoutRecord.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/WindowLayout.h"

RoomWindowLayout room_window_layout_entries = {
    1, 1,
    {3, {10.0f, 4.0f}, 0.7f, 0xFFFFFFFF, 0x40, NULL},
};

WindowDescriptor room_window_base_parameters = {
    {160.0f, 27.0f}, 37000.0f, &room_window_layout_entries, 0x82B,
};

const char *TWindowRoom::class_name = "TWindowRoom";


void *TWindowRoom::get_title_entry() {
    return (void *)this->get_array_entry(0);
}

void TWindowRoom::set_entry_display_value(const char *str) {
    set_text_entry_string((WindowTextEntry *)(get_array_entry(0)), str, 0x60);
}

void TWindowRoom::draw_tab(WindowDrawContext *context) {
    draw_window_tab(context, &context->inner_x, tabParameter, 3);
}

void TWindowRoom::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_tab(context);
    draw_visible_window_entries(this, &entry_list, context);
}
void TWindowRoom::run_task() { update_window(); update_window_entry_list(&entry_list); }

TWindowRoom::~TWindowRoom() {}

TWindowRoom::TWindowRoom(char *title)
    : TWindowBase((u8 *)&room_window_base_parameters, 4, (u8 *)get_window_layout_position(0xAF)) {
    WindowTextEntry *entry;
    m_name = TWindowRoom::class_name;
    entry = (WindowTextEntry *)this->get_array_entry(0);
    set_text_entry_string(entry, title, 0x60);
    measure_message_text_width_default(entry);
    target_size[0] = 10.0f + (entry->x + entry->width);
    target_position[0] -= target_size[0];
    this->save_position();
    tabParameter = calc_title_overflow_width(frame_size[0] - 16.0f);
}
