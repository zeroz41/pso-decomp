#include "types.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/WindowTextDraw.h"
#include "pso/ui/window/HeadingEntry.h"
#include "pso/ui/window/WindowDrawContext.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/ui/window/WindowDrawContext.h"

#pragma readonly_strings on

const char *TWindowSubEquipKind::class_name = "TWindowSubEquipKind";

// Message ids of the four status-display tab labels, indexed by the selected tab (f88).
extern const s32 status_disp_tab_label_message_ids[4] = {0xE2, 0xE0, 0xE1, 0xF5};

extern "C" {

u32 calc_text_width(void);
static const u8 equip_kind_tab_label_colors[4] = {1, 2, 2, 1};
void TWindowSubEquipKind::set_trade_state(s16 trade_state) {
    this->trade_state = trade_state;
    if (this->trade_state == 3) {
        state_timer = 60;
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubEquipKind::draw_tab_label(WindowDrawContext *context) {
    NJS_POINT2 pos;
    saddr msg;
    s16 fl;
    u8 col;

    if (context->open_tick >= 0) {
        pos.x = context->x + get_heading_frame_width(status_display);
        pos.y = context->y - 13.0f;
        col = equip_kind_tab_label_colors[trade_state];
        fl = state_timer;
        if (fl != 0) {
            if (fl & 4) {
                col = 1;
            } else {
                col = 2;
            }
        }
        draw_window_tab(context, &pos.x, 0.0f, col);
        pos.x += 80.0f;
        pos.y += 4.0f;
        set_text_draw_params(context, 0, 0, (f32)(-1.0f / (0.1794f + context->depth)), 100000.0f);
        msg = (saddr)TWindowSubStatusDisp::get_message_10(status_disp_tab_label_message_ids[trade_state]);
        pos.x -= 0.5f * (f32)calc_text_width();
        draw_window_text((f32 *)&pos, (const char *)msg, (0xFF000000), 0, 100000.0f);
    }
}
#pragma pop

}
