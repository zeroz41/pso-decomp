#include "types.h"
#include "pso/object/TObjResultWin.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/TShopWindowBase.h"
#include "pso/TObjNewFloorWin.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TWindowSubComCard.h"
#include "pso/ui/TAdChrSelASlotGC.h"

struct TObjNewFloorWin_80073DCC { u8 pad[0x1C]; s32 state; void *window; s32 timer24; s32 timer28; };

extern "C" {
s32 fn_800740DC();
int forward_trade_action_default__16TObjCityMainWarpFPviii(void *p, int a1, int a2, int a3);
s32 create_window_menu(s32 arg0, s32 arg1, s32 arg2);
u32 check_room_seq_4__16TAdChrSelASlotGCFl(s32);
s32 get_window_layout_position(s32);
s32 sprintf(void *, const char *, ...);
extern char lbl_80438660[];
void queue_destruction__7TObjectFv(void *);
void TWindow__close(void *);
s32 TWindowCtrlMain__sub_8024CE58();
void TShopWindowBase::set_field_20(s32 v) { *(s32 *)&(*(u32 *)((u8 *)this + 0x20)) = v; }

void TObjNewFloorWin::run_task() {
    TObjNewFloorWin_80073DCC *self = (TObjNewFloorWin_80073DCC *)this;
    switch (self->state) {
    case 0:
        if (self->window == NULL) {
            if (TWindowCtrlMain__sub_8024CE58() == 0) {
                if (--self->timer24 <= 0) {
                    queue_destruction__7TObjectFv(self);
                    return;
                }
                return;
            } else {
                open_window();
                self->state = 1;
            }
        }
        break;
    case 1:
        if (--self->timer28 == 0x3C) {
            if (self->window != NULL) {
                TWindow__close(self->window);
                self->window = NULL;
            }
            self->state = 2;
        }
        break;
    case 2:
        if (--self->timer28 <= 0) {
            queue_destruction__7TObjectFv(self);
        }
        break;
    }
}

void TObjNewFloorWin::open_window() {
    u8 *arg0 = (u8 *)this;
    s32 pos;
    pos = get_window_layout_position(0x3D);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x4C) < 0) {
        *(u32 *)((s8 *)arg0 + 0x20) = ((u32 (*)(s32, s32, s32)) check_room_seq_4__16TAdChrSelASlotGCFl)(pos, 1, *(s32 *)((s8 *)arg0 + 0x4C));
    } else {
        *(u32 *)((s8 *)arg0 + 0x20) = create_window_menu(pos, 1, *(s32 *)((s8 *)arg0 + 0x4C));
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x20) != 0U) {
        sprintf(arg0 + 0x2C, lbl_80438660, TQuestVmDownLoadServer__sub_8006EF6C(0x67), TObjNewFloorWin__sub_8007410C());
        forward_trade_action_default__16TObjCityMainWarpFPviii((void *)(*(u32 *)((s8 *)arg0 + 0x20)), (int)(arg0 + 0x2C), 0, 0);
        ((TWindowSubComCard *)(*(u32 *)((s8 *)arg0 + 0x20)))->calc_window_size();
        ((TAdChrSelASlotGC *)(*(u32 *)((s8 *)arg0 + 0x20)))->set_flag_40();
        fn_800740DC();
        TWindowCtrl::close_active_window();
        TWindowCtrl::ensure_initialized();
    }
}

}
