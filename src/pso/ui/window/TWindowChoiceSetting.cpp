#include "pso/ui/window/WindowScrollBar.h"
#include "types.h"
#include "pso/unk/TWindowLayoutRect.h"
#include "pso/ui/window/WindowTextEntry.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowMenuInfomation.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/ControllerInput.h"
#include "pso/ui/window/HeadingEntry.h"

// One TU: the class-name string comes before
// update_scroll_tween's u32->f32 double and run_task's s32->f32 double
// in .rodata, so the name is defined ahead of the functions.
#pragma push
#pragma readonly_strings on
const char *TWindowChoiceSetting::class_name = "TWindowChoiceSetting";
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowChoiceSetting::update_scroll_tween() {
    f32 target;
    uaddr steps;
    TWindowLayoutRect *row;

    if (this->choice_flags & 1) {
        row = static_cast<TWindowLayoutRect *>(this->get_array_entry(this->get_field_74()));
        target = row->y;
    } else {
        target = 0.0f;
    }
    steps = this->tween_ticks;
    if (steps == 0) {
        scroll_offset[1] = target;
        return;
    }
    target += 0.5f * (this->target_size[1] - this->frame_size[1]);
    scroll_offset[1] += (target - scroll_offset[1]) / (f32)steps;
}
#pragma pop

void TWindowChoiceSetting::begin_scroll(f32 height) {
    u16 flags = choice_flags;
    if (flags & 1) {
        choice_flags = (u16)(flags & 0xFFFE);
        target_size[1] = height;
        tween_ticks = 3;
    }
}

void TWindowChoiceSetting::shrink_to_selected_entry() {
    u16 flags;
    WindowTextEntry *entry;
    flags = choice_flags;
    if (!(flags & 1)) {
        choice_flags = (u16)(flags | 1);
        entry = (WindowTextEntry *)get_array_entry(get_field_74());
        target_size[1] = 20.0f + entry->height;
        if (window_flags & 0x40) {
            target_size[1] += 6.0f;
        }
        tween_ticks = 3;
    }
}

TWindowChoiceSetting *TWindowChoiceSetting::create_choice_setting_window(
    const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 rows) {
    set_popup_size(extent, rows);
    return new TWindowChoiceSetting(const_cast<NJS_POINT2 *>(position), rows);
}

void TWindowChoiceSetting::set_popup_size(const NJS_POINT2 *extent, s32 rows) {
    set_choice_setting_popup_size(extent, rows);
}

void TWindowChoiceSetting::render() {
    WindowDrawContext *context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(
        this,
        &entry_list,
        context);
    draw_setting(context);
    if (heading != 0) {
        heading->render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}

void TWindowChoiceSetting::run_task() {
    WindowScrollBar *scroll;
    ControllerInputContext *input;
    ControllerInputContext *pad;
    ControllerInputContext *context;
    if ((is_selected() == 0) && (is_open() == 0)) {
        if (this->state_flags & 0x10) {
            input = &controller_input_state.controllers[0];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                move_next_choice();
            }
        } else {
            pad = &controller_input_state.controllers[0];
            if ((test_buttons_press_or_repeat_color(pad, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat_color(pad, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                move_next_choice();
            }
        }
        context = &controller_input_state.controllers[0];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            draw();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            request_close();
        }
    }
    if ((f32) this->open_tick >= 7.5f) {
        if (this->heading != 0) {
            this->heading->update();
        }
        scroll = scroll_bar;
        if (scroll != NULL) {
            scroll->increment_counter();
        }
    }
    update_window();
    update_scroll_tween();
    step_window_tween();
    update_scroll_offset();
    clamp_scroll();
    update_window_entry_list(&entry_list);
}

TWindowChoiceSetting::~TWindowChoiceSetting() {
}

TWindowChoiceSetting::TWindowChoiceSetting(void *parent, s32 rows) : TWindowMenuInfomation(parent, rows) {
    m_name = TWindowChoiceSetting::class_name;
    choice_flags = 0;
}
