#include "types.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/system/NinjaTypes.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#pragma readonly_strings on

const char *TWindowSubEquipKind__class_name = "TWindowSubEquipKind";

// Message ids of the four status-display tab labels, indexed by the selected tab (f88).
extern const s32 status_disp_tab_label_message_ids[4] = {0xE2, 0xE0, 0xE1, 0xF5};

extern "C" {

typedef struct {
    f32 x;
    f32 y;
    u8 pad08[0x30 - 0x08];
    s32 f30;
    u8 pad34[0x38 - 0x34];
    f32 f38;
} Win_8027831C;

typedef struct {
    u8 pad00[0x80];
    saddr f80;
    u8 pad84[0x88 - 0x84];
    s16 f88;
    s16 f8A;
} Disp_8027831C;

u32 calc_text_width(void);
static const u8 lbl_805DD5F8[4] = {1, 2, 2, 1};
void TWindowSubTradeMain::set_trade_state(s16 trade_state) {
    this->trade_state = trade_state;
    if ((s16) this->trade_state == 3) {
        *(s16 *)((s8 *)this + 0x8A) = 0x3C;
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubEquipKind::draw_tab_label(void *win) {
    NJS_POINT2 pos;
    saddr msg;
    s16 fl;
    u8 col;

    if (((Win_8027831C *)win)->f30 >= 0) {
        pos.x = ((Win_8027831C *)win)->x + TWindowSubStatusDisp__sub_80287570((void *)((Disp_8027831C *)this)->f80);
        pos.y = ((Win_8027831C *)win)->y - 13.0f;
        col = lbl_805DD5F8[((Disp_8027831C *)this)->f88];
        fl = ((Disp_8027831C *)this)->f8A;
        if (fl != 0) {
            if (fl & 4) {
                col = 1;
            } else {
                col = 2;
            }
        }
        draw_window_tab((WindowDrawContext *)win, &pos.x, col, 0.0f);
        pos.x += 80.0f;
        pos.y += 4.0f;
        set_text_draw_params(reinterpret_cast<WindowDrawContext *>(win), 0, 0, (f32)(-1.0f / (0.1794f + ((Win_8027831C *)win)->f38)), 100000.0f);
        msg = (saddr)TWindowSubStatusDisp::get_message_10(status_disp_tab_label_message_ids[((Disp_8027831C *)this)->f88]);
        pos.x -= 0.5f * (f32)calc_text_width();
        draw_window_text((f32 *)&pos, (const char *)msg, (0xFF000000), 0, 100000.0f);
    }
}
#pragma pop

}
