#include "pso/ui/window/WindowScrollBar.h"
#include "types.h"
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

// One TU (.text 0x80249078-0x802495FC): the class-name string 0x8044EAF0 comes before
// sub_80249078's u32->f32 double (0x8044EB08) and run_task's s32->f32 double (0x8044EB10)
// in .rodata, so the name is defined ahead of the functions.
#pragma push
#pragma readonly_strings on
const char *TWindowChoiceSetting__name = "TWindowChoiceSetting";
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowChoiceSetting::sub_80249078() {
    f32 target;
    uaddr steps;

    if (this->m_80 & 1) {
        steps = reinterpret_cast<uaddr>(this->get_array_entry(this->get_field_74()));
        target = *(f32 *)(steps + 0xC);
    } else {
        target = 0.0f;
    }
    steps = *(u32 *)&this->tween_ticks;
    if (steps == 0) {
        scroll_offset[1] = target;
        return;
    }
    target += 0.5f * (this->target_size[1] - this->frame_size[1]);
    scroll_offset[1] += (target - scroll_offset[1]) / (f32)steps;
}
#pragma pop

extern "C" {

void TWindowChoiceSetting::begin_scroll(f32 height) {
    u16 flags = m_80;
    if (flags & 1) {
        m_80 = (u16)(flags & 0xFFFE);
        target_size[1] = height;
        tween_ticks = 3;
    }
}

void TWindowSubComCard__sub_80249144(void *window_choice_setting) {
    u16 temp_r4;
    void *e;
    temp_r4 = ((TWindowChoiceSetting *)window_choice_setting)->m_80;
    if (!(temp_r4 & 1)) {
        ((TWindowChoiceSetting *)window_choice_setting)->m_80 = (u16) (temp_r4 | 1);
        e = (void *)(((TWindowBase *)window_choice_setting)->get_array_entry((s32)((TWindowChoiceSetting *)window_choice_setting)->get_field_74()));
        ((TWindowChoiceSetting *)window_choice_setting)->target_size[1] = 20.0f + *(f32 *)((s8 *)e + 0x14);
        if (((TWindowChoiceSetting *)window_choice_setting)->window_flags & 0x40) {
            ((TWindowChoiceSetting *)window_choice_setting)->target_size[1] += 6.0f;
        }
        *(s32 *)((s8 *)window_choice_setting + 0x50) = 3;
    }
}

void TWindowSubComCard__sub_80249220(const NJS_POINT2 *extent, s32 rows);

TWindowChoiceSetting *create_choice_setting_window__17TWindowSubComCardFiii(
    const NJS_POINT2 *position, const NJS_POINT2 *extent, s32 rows) {
    TWindowSubComCard__sub_80249220(extent, rows);
    return new TWindowChoiceSetting(const_cast<NJS_POINT2 *>(position), rows);
}

void TWindowSubComCard__sub_80249220(const NJS_POINT2 *extent, s32 rows) {
    fn_80268C5C(extent, rows);
}

}

void TWindowChoiceSetting::render() {
    WindowDrawContext *context = get_draw_context();
    draw_window_frame(context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)this + 0x24),
        context);
    draw_setting(context);
    if (heading != 0) {
        ((TWindowSubStatusDisp *)((saddr)heading))->forward_render(context);
    }
    if (scroll_bar != NULL) {
        draw_window_scrollbar(scroll_bar, context, scroll_offset);
    }
}

void TWindowChoiceSetting::run_task() {
    u8 *arg0 = (u8 *)this;
    WindowScrollBar *temp_r3_2;
    ControllerInputContext *input;
    ControllerInputContext *temp_r30_2;
    ControllerInputContext *context;
    if ((((TWindowMenuInfomation *)arg0)->is_selected() == 0) && (((TWindowMenuInfomation *)arg0)->is_open() == 0)) {
        if (this->m_70 & 0x10) {
            input = &controller_input_state.controllers[0];
            if ((test_buttons_press_or_repeat(input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                ((TWindowMenuInfomation *)arg0)->move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat(input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                ((TWindowMenuInfomation *)arg0)->move_next_choice();
            }
        } else {
            temp_r30_2 = &controller_input_state.controllers[0];
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r30_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
                ((TWindowMenuInfomation *)arg0)->move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r30_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
                ((TWindowMenuInfomation *)arg0)->move_next_choice();
            }
        }
        context = &controller_input_state.controllers[0];
        if ((test_pressed_buttons_packed(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            ((TWindowMenuInfomation *)arg0)->draw();
        }
        if ((test_pressed_buttons_packed(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            ((TWindowMenuInfomation *)arg0)->request_close();
        }
    }
    if ((f32) this->open_tick >= 7.5f) {
        if (this->heading != 0) {
            this->heading->update_subwindow();
        }
        temp_r3_2 = scroll_bar;
        if (temp_r3_2 != NULL) {
            temp_r3_2->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowChoiceSetting *)arg0)->sub_80249078();
    ((TWindowAddition *)arg0)->step_window_tween();
    ((TWindowMenuInfomation *)arg0)->update_scroll_offset();
    ((TWindowMenuInfomation *)arg0)->clamp_scroll();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(arg0 + 0x24));
}

TWindowChoiceSetting::~TWindowChoiceSetting() {
}

TWindowChoiceSetting::TWindowChoiceSetting(void *parent, s32 rows) : TWindowMenuInfomation(parent, rows) {
    m_name = TWindowChoiceSetting__name;
    m_80 = 0;
}
