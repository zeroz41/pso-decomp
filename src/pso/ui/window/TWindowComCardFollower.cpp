// Emit the follower vtable before the status-icon jump table.
#pragma defer_codegen on

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowComCard.h"
#include "pso/ui/window/TWindowComCardFollower.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/TWindowTradeRequest.h"
#include "pso/ui/window/WindowLayoutEntries.h"

extern "C" {
int initialize_subwindow__9TWindowDDFv(void*);
extern "C" u8 hud_texlist[];
extern void *lbl_804CE918[14];
void *lbl_804CE918[14] = {
    (void *)0x1, (void *)0x1, (void *)0x6, (void *)0x0,
    (void *)0x0, (void *)0x42000000, (void *)0x41e00000, (void *)0x0,
    (void *)0x0, (void *)0x3f000000, (void *)0xffffffff, (void *)&hud_texlist,
    (void *)0x1, (void *)0x4,
};
void *TWindowComCard__window_desc_b[5] = {
    (void *)0x42000000, (void *)0x41e00000, (void *)0x4788d100, (void *)&lbl_804CE918,
    (void *)0x82b,
};
}

TWindowCtrl *TWindowCtrl::instance;
u16 lbl_805D63FC;

extern "C" void request_active_window_close(void) {
    if ((TWindowCtrl::instance != NULL) && (TWindowCtrl::instance->m_38 != 0U)) {
        ((TWindowCtrl *)((void*)TWindowCtrl::instance->m_38))->set_flag1e_bit8();
    }
}

void TWindowTradeRequest::close_request_window() {
    lbl_805D63FC &= 0xFFFFFFF7;
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
    : TWindowBase((u8 *)TWindowComCard__window_desc_b, (s16)client, (u8 *)get_zero_vec2()) {
    parent_window = parent;
    offset.x = ofs->x;
    offset.y = ofs->y;
    card_column = col;
    help_mode = mode;
    target_position[0] = 16.0f * (f32)card_column + (parent_window->frame_position[0] + offset.x);
    target_position[1] = parent_window->frame_position[1] + offset.y;
    save_position();
    ((TWindowComCard *)get_array_entry(0))->set_help_mode(mode);
}
#pragma pop

TWindowComCardFollower::~TWindowComCardFollower() {}

void TWindowComCardFollower::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    u8 *temp_r4;
    temp_r4 = (unsigned char *) (this->parent_window);
    temp_f1 = parent_window->frame_position[1];
    this->target_position[1] = (f32) (temp_f1 + offset.y);
    this->frame_position[1] = (f32) this->target_position[1];
    ((s32 (*)(void *, int, f32))initialize_subwindow__9TWindowDDFv)((void *)arg0, (saddr)temp_r4, (f32)temp_f1);
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list(reinterpret_cast<const WindowLayoutEntries *>(arg0 + 0x24));
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
        ((TWindowComCard *)get_array_entry(0))->set_help_mode(help_mode);
    }
}

s32 get_status_effect_icon_index(u32 arg0) {
    switch (arg0) {
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
