#include "types.h"
#include "pso/ui/window/TWindowSubEquipKind.h"
#include "pso/ui/window/TWindowSubStatusDisp_8024FBA8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80287570.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"

extern "C" {
typedef struct { f32 x, y; } V2_8027831C;

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
    s32 f80;
    u8 pad84[0x88 - 0x84];
    s16 f88;
    s16 f8A;
} Disp_8027831C;

s32 get_message_10__20TWindowSubStatusDispFl(s32);
u32 calc_text_width(void);
void draw_window_tab(Win_8027831C *, V2_8027831C *, u8, f32);
extern s32 status_disp_tab_label_message_ids[];
extern const u8 lbl_805DD5F8[4];
extern const f32 lbl_805DD5FC;
extern const f32 lbl_805DD600;
extern const f32 lbl_805DD604;
extern const f32 lbl_805DD608;
extern const f32 lbl_805DD60C;
extern const f32 lbl_805DD610;
extern const f32 lbl_805DD614;
extern const f32 lbl_805DD618;
void TWindowSubTradeMain::set_trade_state(s16 arg1) {
    this->m_88 = arg1;
    if ((s16) this->m_88 == 3) {
        *(s16 *)((s8 *)this + 0x8A) = 0x3C;
    }
}

#pragma push
#pragma fp_contract on
void TWindowSubEquipKind::draw_tab_label(void *win) {
    V2_8027831C pos;
    s32 msg;
    s16 fl;
    u8 col;

    if (((Win_8027831C *)win)->f30 >= 0) {
        pos.x = ((Win_8027831C *)win)->x + TWindowSubStatusDisp__sub_80287570((void *)((Disp_8027831C *)this)->f80);
        pos.y = ((Win_8027831C *)win)->y - lbl_805DD5FC;
        col = lbl_805DD5F8[((Disp_8027831C *)this)->f88];
        fl = ((Disp_8027831C *)this)->f8A;
        if (fl != 0) {
            if (fl & 4) {
                col = 1;
            } else {
                col = 2;
            }
        }
        draw_window_tab(((Win_8027831C *)win), &pos, col, lbl_805DD600);
        pos.x += lbl_805DD604;
        pos.y += lbl_805DD608;
        set_text_draw_params((s32)((Win_8027831C *)win), 0, 0, (f32)(lbl_805DD60C / (lbl_805DD610 + ((Win_8027831C *)win)->f38)), (f32)lbl_805DD614);
        msg = get_message_10__20TWindowSubStatusDispFl(status_disp_tab_label_message_ids[((Disp_8027831C *)this)->f88]);
        pos.x -= lbl_805DD618 * (f32)calc_text_width();
        draw_window_text((f32 *)&pos, (const char *)msg, (0xFF000000), 0, (f32)lbl_805DD614);
    }
}
#pragma pop

}
