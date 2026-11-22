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
s32 draw_window_scrollbar(s32, s32, void *);

extern s32 local_client_id;

u8 *TWindowSubStatusDisp__sub_80248BE8(saddr arg0, saddr arg1, s32 arg2) {
    TShopJudgmentItemWindow__sub_80267F9C((void *)arg1, 0x5);
    return (u8 *)new TWindowCheckBox((u8 *)arg0, arg2);
}

void *create_check_box_window_for_local_client(const NJS_POINT2 *layout_position, const void *position) {
    return TWindowSubStatusDisp__sub_80248BE8((saddr)layout_position, (saddr)position, local_client_id);
}

void TWindowCheckBox::render() {
    saddr draw_context;

    draw_context = reinterpret_cast<saddr>(get_draw_context());
    draw_window_frame((void *)draw_context);
    draw_visible_window_entries(
        this,
        reinterpret_cast<const WindowLayoutEntries *>(((u8 *)this) + 0x24),
        reinterpret_cast<WindowDrawContext *>(draw_context));
    ((TWindowMenuIconLine *)((u8 *)this))->draw_selected_list_entry(draw_context);
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x80) != 0U) {
        ((TWindowSubStatusDisp *)((void *)(*(uaddr *)((s8 *)((u8 *)this) + 0x80))))->forward_render((void *)(draw_context));
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x84) != 0U) {
        draw_window_scrollbar(*(u32 *)((s8 *)((u8 *)this) + 0x84), draw_context, ((u8 *)this) + 0x68);
    }
}

void TWindowCheckBox::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    uaddr temp_r3;
    uaddr temp_r3_2;
    u8 *input;
    u8 *temp_r29_2;
    u8 *context;
    temp_r31 = is_player_input_active(((s32) this->client_index));
    if ((((TWindowMenuIconLine *)arg0)->get_flag() == 0) && (((TWindowMenuIconLine *)arg0)->is_decided() == 0) && (((TWindowBase *)arg0)->sub_80244994() != 0)) {
        if (*(u16 *)((s8 *)arg0 + 0x70) & 0x10) {
            input = (u8 *)&controller_input_state + (temp_r31 * 0x50) + 0x20;
            if ((test_buttons_press_or_repeat((saddr)input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor();
            }
            if ((test_buttons_press_or_repeat((saddr)input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor_next();
            }
        } else {
            temp_r29_2 = (u8 *)&controller_input_state + (temp_r31 * 0x50) + 0x20;
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x10, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor();
            }
            if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)temp_r29_2, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat((saddr)((void *) ((u8 *)&controller_input_state + 0x160)), 0x20, 6, 1) != 0)) {
                ((TWindowMenuIconLine *)arg0)->move_cursor_next();
            }
        }
        context = (u8 *)&controller_input_state + (temp_r31 * 0x50) + 0x20;
        if ((TWindowShortListCtrl__check_controller_button(context, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
            ((TWindowCheckBox *)arg0)->sync_level_field();
        }
        if ((TWindowShortListCtrl__check_controller_button(context, 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
            ((TWindowMenuIconLine *)arg0)->set_flag4();
        }
    }
    ((TWindowMenuIconLine *)arg0)->center_list_selection();
    if ((f32) *(s32 *)&this->open_tick >= 7.5f) {
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
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>((u8 *)&(*(void * *)((u8 *)this + 0x24))));
}

}

TWindowCheckBox::~TWindowCheckBox() {}

TWindowCheckBox::TWindowCheckBox(u8 *parent, s32 client) : TWindowMenuIconLine(parent, 5, client) {
    sub_80248B7C(client);
}
