// Emit the follower vtable before the status-icon jump table.
#pragma defer_codegen on

#include "pso/ui/window/WindowSpritePart.h"
#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/math/Vec2Constants.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/chat/TWindowChat.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/WindowLayoutEntries.h"


ComCardFollowerLayout com_card_follower_layout_entries = {
    1, 1,
    {6, {0.0f, 0.0f}, {32.0f, 28.0f}, 0.0f, 0.0f, 0.5f, -1, &hud_texlist, 1, 4},
};

WindowDescriptor com_card_follower_window_descriptor = {
    {32.0f, 28.0f}, 70050.0f, &com_card_follower_layout_entries, 0x82B,
};

void request_active_window_close(void) {
    if ((TWindowCtrl::instance != NULL) && (TWindowCtrl::instance->chat_window != NULL)) {
        TWindowCtrl::instance->chat_window->set_flag1e_bit8();
    }
}

void TWindowTradeRequest::close_request_window() {
    short_mail_flags &= 0xFFFFFFF7;
    TWindowCtrl *controller = reinterpret_cast<TWindowCtrl *>(TWindowCtrl::instance);
    if (controller != NULL) {
        TWindowTradeRequest *request = controller->trade_request;
        if (request != NULL) {
            request->queue_destruction();
            reinterpret_cast<TWindowCtrl *>(TWindowCtrl::instance)->trade_request = NULL;
        }
    }
}

#pragma push
#pragma fp_contract on
TWindowComCardFollower::TWindowComCardFollower(TWindowBase *parent, NJS_POINT2 *ofs, s32 col, s32 mode, s32 client)
    : TWindowBase((u8 *)&com_card_follower_window_descriptor, (s16)client, (u8 *)get_zero_vec2()) {
    parent_window = parent;
    offset.x = ofs->x;
    offset.y = ofs->y;
    card_column = col;
    help_mode = mode;
    target_position[0] = 16.0f * (f32)card_column + (parent_window->frame_position[0] + offset.x);
    target_position[1] = parent_window->frame_position[1] + offset.y;
    save_position();
    static_cast<WindowSpritePart *>(get_array_entry(0))->set_help_mode(mode);
}
#pragma pop

TWindowComCardFollower::~TWindowComCardFollower() {}

void TWindowComCardFollower::run_task() {
    target_position[1] = parent_window->frame_position[1] + offset.y;
    frame_position[1] = target_position[1];
    update_window();
    update_fade();
    update_window_entry_list(&entry_list);
}

void TWindowComCardFollower::render() {
    WindowDrawContext *context = draw_default_entry();
    draw_visible_window_entries(this, &entry_list, context);
}

#pragma push
#pragma fp_contract on
void TWindowComCardFollower::set_column(s32 column) {
    if (card_column != column) {
        card_column = column;
        target_position[0] = 16.0f * (f32)card_column + (parent_window->frame_position[0] + offset.x);
        tween_ticks = 0xF;
    }
}
#pragma pop

void TWindowComCardFollower::set_selected_index(s32 value) {
    if (help_mode != value) {
        help_mode = value;
        static_cast<WindowSpritePart *>(get_array_entry(0))->set_help_mode(help_mode);
    }
}

s32 get_status_effect_icon_index(u32 status) {
    switch (status) {
    case 3:
        return 1;
    case 9:
        return 6;
    case 10:
        return 8;
    case 11:
        return 7;
    case 12:
        return 9;
    case 15:
        return 3;
    case 16:
        return 4;
    case 17:
        return 5;
    case 18:
        return 0;
    case 2:
        return 2;
    default:
        return 0xE;
    }
}
