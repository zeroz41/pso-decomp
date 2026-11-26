#include "types.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/network/client_id.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"

s32 TWindowCheckBox::update_selected_item() {
    return static_cast<ItemListRow *>(get_array_entry(selected_index))->get_item();
}

void TWindowCheckBox::set_selected_index(s16 selected_index) {
    this->selected_index = selected_index;
    cursor = selected_index;
    refresh_selected_entry(0);
}

void TWindowCheckBox::sub_80248994(u32 color, s32 item) {
    s32 i;
    ItemListRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = static_cast<ItemListRow *>(get_array_entry(i));
        if (e != NULL && e->is_flag_4_set() != 0 && item == e->get_item()) {
            e->category_style = color;
            e->style = color;
        }
    }
}

void TWindowCheckBox::advance_matching_entries(s32 finalize, s32 item) {
    s32 i;
    ItemListRow *e;
    for (i = 0; i < entry_capacity; i++) {
        e = static_cast<ItemListRow *>(get_array_entry(i));
        if (e != NULL && e->is_flag_4_set() != 0 && item == e->get_item()) {
            if (finalize != 0) {
                e->finalize_state();
            } else {
                e->advance_state();
            }
        }
    }
}

void TWindowCheckBox::add_menu_item(s32 text, s32 item) {
    append_entry(0, text, item, 1, 0);
}

void TWindowCheckBox::draw_status(s32 text, s32 item) {
    append_entry(0, text, item, 0, 1);
}

void TWindowCheckBox::dispatch_without_flags(s32 text, s32 item) {
    append_entry(0, text, item, 0, 0);
}

void TWindowCheckBox::sync_level_field() {
    s16 cursor;

    if (selected_index != (cursor = this->cursor)) {
        selected_index = cursor;
        advance_all_entries(1);
    }
}

#pragma readonly_strings on


const char *TWindowCheckBox::class_name = "TWindowCheckBox";

void TWindowCheckBox::init_check_box(s32 client) {
    this->m_name = TWindowCheckBox::class_name;
    this->client_index = client;
}

TWindowCheckBox *create_check_box_window_on_layer(const NJS_POINT2 *position, s32 size, s32 client) {
    TWindowCheckBox *window;

    TAdVIConfigGC__sub_80267704(0x23);
    window = TWindowCheckBox::create(position, size, client);
    TAdVIConfigGC__sub_80267704(3);
    return window;
}

TWindowCheckBox *TWindowCheckBox::create(const NJS_POINT2 *position, saddr size, s32 client) {
    set_menu_icon_line_params((const NJS_POINT2 *)size, 0x5);
    return new TWindowCheckBox((u8 *)position, client);
}

TWindowCheckBox *create_check_box_window_for_local_client(const NJS_POINT2 *layout_position, const void *position) {
    return TWindowCheckBox::create(layout_position, (saddr)position, local_client_id);
}

void TWindowCheckBox::render() {
    WindowDrawContext *context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(this, &entry_list, context);
    draw_selected_list_entry(context);
    if (status_display != NULL) {
        status_display->render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}

void TWindowCheckBox::run_task() {
    s32 controller_index;
    WindowHeading *status;
    WindowScrollBar *window_scroll_bar;
    ControllerInputContext *input;
    ControllerInputContext *input2;
    ControllerInputContext *context;
    controller_index = is_player_input_active(((s32) this->client_index));
    if ((this->get_flag() == 0) && (this->is_decided() == 0) && (this->is_open_and_unblocked() != 0)) {
        if (state_flags & 0x10) {
            input = &controller_input_state.controllers[controller_index];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        } else {
            input2 = &controller_input_state.controllers[controller_index];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command(input2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command(input2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        }
        context = &controller_input_state.controllers[controller_index];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->sync_level_field();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->set_flag4();
        }
    }
    this->center_list_selection();
    if ((f32)open_tick >= 7.5f) {
        status = status_display;
        if (status != NULL) {
            status->update();
        }
        window_scroll_bar = scroll_bar;
        if (window_scroll_bar != NULL) {
            window_scroll_bar->increment_counter();
        }
    }
    update_window();
    this->update_fade();
    update_window_entry_list(&entry_list);
}

TWindowCheckBox::~TWindowCheckBox() {}

TWindowCheckBox::TWindowCheckBox(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 5, client) {
    init_check_box(client);
}

s32 ItemListRow::get_item() { return item; }

int TWindowLayoutEntry::is_flag_4_set() const { return flags & 0x4; }
int TWindowMenuIconLine::get_flag() { return (this->state_flags >> 6) & 0x1; }
