#include "pso/ui/window/WindowScrollBar.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/network/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/network/client_id.h"
#include "pso/ui/ItemListRow.h"
#include "pso/ui/window/TWindowSubItem.h"
#include "pso/unk/TWindowLayoutEntry.h"

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
        ((TWindowSubStatusDisp *)status_display)->forward_render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}

void TWindowCheckBox::run_task() {
    s32 temp_r31;
    uaddr temp_r3;
    WindowScrollBar *window_scroll_bar;
    ControllerInputContext *input;
    ControllerInputContext *temp_r29_2;
    ControllerInputContext *context;
    temp_r31 = is_player_input_active(((s32) this->client_index));
    if ((this->get_flag() == 0) && (this->is_decided() == 0) && (this->is_open_and_unblocked() != 0)) {
        if (state_flags & 0x10) {
            input = &controller_input_state.controllers[temp_r31];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        } else {
            temp_r29_2 = &controller_input_state.controllers[temp_r31];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command(temp_r29_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                this->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command(temp_r29_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                this->move_cursor_next();
            }
        }
        context = &controller_input_state.controllers[temp_r31];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            this->sync_level_field();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            this->set_flag4();
        }
    }
    this->center_list_selection();
    if ((f32)open_tick >= 7.5f) {
        temp_r3 = (uaddr)status_display;
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
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
    sub_80248B7C(client);
}

s32 ItemListRow::get_item() { return item; }

int TWindowLayoutEntry::is_flag_4_set() const { return flags & 0x4; }
int TWindowMenuIconLine::get_flag() { return (this->state_flags >> 6) & 0x1; }
