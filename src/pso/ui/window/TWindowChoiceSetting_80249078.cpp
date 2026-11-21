#include "types.h"
#include "pso/ui/window/WindowLayoutEntries.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TUnk_804D0658.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"

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
int fn_80268C5C(void*);

void TWindowSubComCard::begin_scroll(f32 farg0) {
    u16 temp_r4;

    temp_r4 = *(u16 *)((s8 *)this + 0x80);
    if (temp_r4 & 1) {
        *(u16 *)((s8 *)this + 0x80) = (u16) (temp_r4 & 0xFFFE);
        *(f32 *)&this->unk_3C = farg0;
        this->m_50 = 3;
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

int TWindowSubComCard__sub_80249220(void *p, void *_w1);

s32 create_choice_setting_window__17TWindowSubComCardFiii(saddr parent, saddr arg1, saddr rows) {
    TWindowSubComCard__sub_80249220((void *)arg1, (void *)rows);
    return (saddr)new TWindowChoiceSetting((void *)parent, rows);
}

int TWindowSubComCard__sub_80249220(void* p, void * _w1) { return fn_80268C5C(p); }

s32 draw_window_scrollbar(s32, s32, void *);
}

void TWindowChoiceSetting::render() {
    saddr context = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>((u8 *)this + 0x24),
        reinterpret_cast<WindowDrawContext *>(context));
    draw_setting(context);
    if (heading != 0) {
        ((TWindowSubStatusDisp *)((saddr)heading))->forward_render((void *)(context));
    }
    if (*(u32 *)((u8 *)this + 0x7C) != 0U) {
        draw_window_scrollbar(*(u32 *)((u8 *)this + 0x7C), context, (u8 *)this + 0x68);
    }
}

void TWindowChoiceSetting::run_task() {
    u8 *arg0 = (u8 *)this;
    uaddr temp_r3_2;
    u8 *input;
    u8 *temp_r30_2;
    u8 *context;
    if ((((TUnk_804D0658 *)arg0)->is_selected() == 0) && (((TUnk_804D0658 *)arg0)->is_open() == 0)) {
        if (this->m_70 & 0x10) {
            input = (u8 *)&controller_input_state + 0x20;
            if ((test_buttons_press_or_repeat((saddr)input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((test_buttons_press_or_repeat((saddr)input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        } else {
            temp_r30_2 = (u8 *)&controller_input_state + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r30_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r30_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        }
        context = (u8 *)&controller_input_state + 0x20;
        if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            ((TUnk_804D0658 *)arg0)->draw();
        }
        if ((TWindowShortListCtrl__check_controller_button(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            ((TUnk_804D0658 *)arg0)->request_close();
        }
    }
    if ((f32) this->open_tick >= 7.5f) {
        if (this->heading != 0) {
            this->heading->update_subwindow();
        }
        temp_r3_2 = *(u32 *)&this->unk_7C;
        if (temp_r3_2 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3_2)->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowChoiceSetting *)arg0)->sub_80249078();
    ((TWindowAddition *)arg0)->step_window_tween();
    ((TUnk_804D0658 *)arg0)->update_scroll_offset();
    ((TUnk_804D0658 *)arg0)->clamp_scroll();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(arg0 + 0x24));
}

TWindowChoiceSetting::~TWindowChoiceSetting() {
}

TWindowChoiceSetting::TWindowChoiceSetting(void *parent, s32 rows) : TUnk_804D0658(parent, rows) {
    m_name = TWindowChoiceSetting__name;
    m_80 = 0;
}
