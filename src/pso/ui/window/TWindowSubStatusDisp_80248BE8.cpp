#include "pso/ui/window/WindowScrollBar.h"
#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuIconLine.h"
#include "pso/ui/window/TUnk_804CE7E8.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);

extern s32 local_client_id;

u8 *TWindowSubStatusDisp__sub_80248BE8(saddr parent, saddr size, s32 client) {
    TShopJudgmentItemWindow__sub_80267F9C((void *)size, 0x5);
    return (u8 *)new TWindowCheckBox((u8 *)parent, client);
}

void *create_check_box_window_for_local_client(const NJS_POINT2 *layout_position, const void *position) {
    return TWindowSubStatusDisp__sub_80248BE8((saddr)layout_position, (saddr)position, local_client_id);
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
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    uaddr temp_r3;
    WindowScrollBar *temp_r3_2;
    ControllerInputContext *input;
    ControllerInputContext *temp_r29_2;
    ControllerInputContext *context;
    temp_r31 = is_player_input_active(((s32) this->client_index));
    if ((((TWindowMenuIconLine *)arg0)->get_flag() == 0) && (((TWindowMenuIconLine *)arg0)->is_decided() == 0) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        if (state_flags & 0x10) {
            input = &controller_input_state.controllers[temp_r31];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor_next();
            }
        } else {
            temp_r29_2 = &controller_input_state.controllers[temp_r31];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor_next();
            }
        }
        context = &controller_input_state.controllers[temp_r31];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            ((TWindowCheckBox *)arg0)->sync_level_field();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            ((TWindowMenuIconLine *)arg0)->set_flag4();
        }
    }
    ((TWindowMenuIconLine *)arg0)->center_list_selection();
    if ((f32)open_tick >= 7.5f) {
        temp_r3 = (uaddr)status_display;
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
        }
        temp_r3_2 = scroll_bar;
        if (temp_r3_2 != NULL) {
            temp_r3_2->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    update_window_entry_list(&entry_list);
}

}

TWindowCheckBox::~TWindowCheckBox() {}

TWindowCheckBox::TWindowCheckBox(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 5, client) {
    sub_80248B7C(client);
}
