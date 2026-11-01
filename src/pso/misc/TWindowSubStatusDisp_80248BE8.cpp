#include "types.h"
#include "pso/misc/TWindowCtrl_8024A054.h"
#include "pso/misc/TWindowSubStatusDisp_80248BE8.h"
#include "pso/misc/TWindowChoiceSetting.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowMenuIconLine.h"
#include "pso/misc/TUnk_804CE7E8.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"

struct RecoveredGlobal_80248CF4_lbl_8050E208 {
    s32 value;
    u8 remaining[0x1AC];
};

extern "C" {
u8 * fn_80249004(void *, s32, s32);
u8 *__nw__7TObjectFUl(s32);
s32 TShopJudgmentItemWindow__sub_80267F9C(void *, int);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(int, int);
extern RecoveredGlobal_80248CF4_lbl_8050E208 controller_input_state;
extern const f32 lbl_805DCBA8;
s32 get_draw_context__11TWindowBaseFPv();
s32 draw_visible_window_entries(void *, void *, s32);
s32 draw_window_scrollbar(s32, s32, void *);
void __dl__7TObjectFPv(void *);
s32 forward_render__20TWindowSubStatusDispFv(s32, s32);

extern s32 local_client_id;

u8 *TWindowSubStatusDisp__sub_80248BE8(s32 arg0, s32 arg1, s32 arg2) {
    u8 *temp_r3;
    u8 *var_r0;
    TShopJudgmentItemWindow__sub_80267F9C((void *)arg1, 0x5);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x8C));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(fn_80249004(temp_r3, arg0, arg2));
    }
    return var_r0;
}

void *TWindowSubStatusDisp::refresh_with_default_list(s32 a, s32 b) {
    return TWindowSubStatusDisp__sub_80248BE8(a, b, local_client_id);
}

void TWindowSubStatusDisp::render_status_and_children() {
    s32 temp_r3;

    temp_r3 = get_draw_context__11TWindowBaseFPv();
    draw_window_frame((void *)temp_r3);
    draw_visible_window_entries(this, ((u8 *)this) + 0x24, temp_r3);
    ((TWindowMenuIconLine *)((u8 *)this))->draw_selected_list_entry(temp_r3);
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x80) != 0U) {
        forward_render__20TWindowSubStatusDispFv(*(u32 *)((s8 *)((u8 *)this) + 0x80), temp_r3);
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x84) != 0U) {
        draw_window_scrollbar(*(u32 *)((s8 *)((u8 *)this) + 0x84), temp_r3, ((u8 *)this) + 0x68);
    }
}

extern s32 status_disp_window_dispatch_table[];

typedef char RecoveredGlobal_80248CF4_lbl_8050E208_size[sizeof(RecoveredGlobal_80248CF4_lbl_8050E208) == 0x1B0 ? 1 : -1];
void TWindowSubStatusDisp::handle_input() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    u32 temp_r3;
    u32 temp_r3_2;
    u8 *input;
    u8 *temp_r29_2;
    u8 *temp_r29_3;
    temp_r31 = is_player_input_active(((s32) this->m_20));
    if ((((TWindowMenuIconLine *)arg0)->get_flag() == 0) && (((TWindowMenuIconLine *)arg0)->is_decided() == 0) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        if (*(u16 *)((s8 *)arg0 + 0x70) & 0x10) {
            input = (u8 *)&controller_input_state.value + (temp_r31 * 0x50) + 0x20;
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor();
            }
            if ((TWindowChoiceSetting::apply_choice((s32)input, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor_next();
            }
        } else {
            temp_r29_2 = (u8 *)&controller_input_state.value + (temp_r31 * 0x50) + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x10, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x10, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((int)temp_r29_2, 0x20, 6, 1) != 0) || (TWindowChoiceSetting::apply_choice((s32)((void *) ((u8 *)&controller_input_state.value + 0x160)), 0x20, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor_next();
            }
        }
        temp_r29_3 = (u8 *)&controller_input_state.value + (temp_r31 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 4) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 4) != 0)) {
            ((TUnk_804CE7E8 *)arg0)->sync_level_field();
        }
        if ((TWindowShortListCtrl__check_controller_button((int)temp_r29_3, 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)&controller_input_state.value + 0x160), 2) != 0)) {
            ((TWindowMenuIconLine *)arg0)->set_flag4();
        }
    }
    ((TWindowMenuIconLine *)arg0)->center_list_selection();
    if ((f32) *(s32 *)&this->m_5c >= lbl_805DCBA8) {
        temp_r3 = *(u32 *)((s8 *)arg0 + 0x80);
        if (temp_r3 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3)->update_subwindow();
        }
        temp_r3_2 = *(u32 *)((s8 *)arg0 + 0x84);
        if (temp_r3_2 != 0U) {
            ((TWindowSubStatusDisp *)temp_r3_2)->increment_counter();
        }
    }
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list((u8 *)&this->m_24);
}

void *__dt__13TUnk_804CE7E8Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = status_disp_window_dispatch_table;
        ((TWindowSubStatusDisp *)arg0)->destroy_item_list_resources(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
