#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowChoiceSetting_80249240.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/window/TWindowAddition.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TUnk_804D0658.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_window_scrollbar(s32, s32, void *);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);


void render__20TWindowChoiceSettingFv(u8 *arg0) {
    s32 temp_r3;
    temp_r3 = get_draw_context__11TWindowBaseFPv();
    ((TWindowBase *)arg0)->draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(arg0, arg0 + 0x24, temp_r3);
    ((TUnk_804D0658 *)arg0)->draw_setting(temp_r3);
    if ((u32) ((TWindowChoiceSetting *)arg0)->m_78 != 0U) {
        forward_render__20TWindowSubStatusDispFv(((TWindowChoiceSetting *)arg0)->m_78, temp_r3);
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x7C) != 0U) {
        draw_window_scrollbar(*(u32 *)((s8 *)arg0 + 0x7C), temp_r3, arg0 + 0x68);
    }
}

void TWindowChoiceSetting::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r3;
    u32 temp_r3_2;
    u8 *input;
    u8 *temp_r30_2;
    u8 *context;
    if ((((TUnk_804D0658 *)arg0)->is_selected() == 0) && (((TUnk_804D0658 *)arg0)->is_open() == 0)) {
        if (this->m_70 & 0x10) {
            input = (u8 *)&controller_input_state + 0x20;
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        } else {
            temp_r30_2 = (u8 *)&controller_input_state + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r30_2, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r30_2, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        }
        context = (u8 *)&controller_input_state + 0x20;
        if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state + 0x160), 4) != 0)) {
            ((TUnk_804D0658 *)arg0)->draw();
        }
        if ((TWindowShortListCtrl__check_controller_button(context, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state + 0x160), 2) != 0)) {
            ((TUnk_804D0658 *)arg0)->request_close();
        }
    }
    if ((f32) this->m_5c >= 7.5f) {
        temp_r3 = this->m_78;
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
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
    ((TWindowBase *)arg0)->update_window_entry_list(arg0 + 0x24);
}

TWindowChoiceSetting::~TWindowChoiceSetting() {
}

extern "C" { extern char TWindowChoiceSetting__class_name_string[]; }
const char *lbl_805D38B8 = TWindowChoiceSetting__class_name_string;

TWindowChoiceSetting::TWindowChoiceSetting(void *parent, s32 rows) : TUnk_804D0658(parent, rows) {
    m_name = lbl_805D38B8;
    m_80 = 0;
}

}
