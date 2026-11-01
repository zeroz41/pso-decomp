#include "types.h"
#include "pso/misc/TWindowChoiceSetting_80249240.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowAddition.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TUnk_804D0658.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct RecoveredGlobal_802492C8_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_window_scrollbar(s32, s32, void *);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_802492C8_lbl_8050E208 controller_input_state;
extern const f32 lbl_805DCBC0;
void __dl__7TObjectFPv(void *);
void fn_80269004(void *);

extern s32 __vt__20TWindowChoiceSetting[];

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

typedef char RecoveredGlobal_802492C8_lbl_8050E208_size[sizeof(RecoveredGlobal_802492C8_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowChoiceSetting::run_task() {
    u8 *arg0 = (u8 *)this;
    u32 temp_r3;
    u32 temp_r3_2;
    u8 *input;
    u8 *temp_r30_2;
    u8 *temp_r30_3;
    if ((((TUnk_804D0658 *)arg0)->is_selected() == 0) && (((TUnk_804D0658 *)arg0)->is_open() == 0)) {
        if (this->m_70 & 0x10) {
            input = (u8 *)&controller_input_state.value + 0x20;
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        } else {
            temp_r30_2 = (u8 *)&controller_input_state.value + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r30_2, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_cursor_prev();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r30_2, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                ((TUnk_804D0658 *)arg0)->move_next_choice();
            }
        }
        temp_r30_3 = (u8 *)&controller_input_state.value + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_3, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            ((TUnk_804D0658 *)arg0)->draw();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r30_3, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            ((TUnk_804D0658 *)arg0)->request_close();
        }
    }
    if ((f32) this->m_5c >= lbl_805DCBC0) {
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

void *__dt__20TWindowChoiceSettingFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TWindowChoiceSetting;
        ((TUnk_804D0658 *)arg0)->destroy_children(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *lbl_805D38B8;

void *TWindowChoiceSetting__ct(void *window_choice_setting) {
    fn_80269004(window_choice_setting);
    *(s32 **)((s8 *)window_choice_setting + 0x18) = __vt__20TWindowChoiceSetting;
    *(void * *)&((TWindowChoiceSetting *)window_choice_setting)->m_name = lbl_805D38B8;
    ((TWindowChoiceSetting *)window_choice_setting)->m_80 = 0;
    return window_choice_setting;
}

}
