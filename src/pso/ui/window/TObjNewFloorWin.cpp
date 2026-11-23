#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TObjResultWin.h"
#include "pso/ui/window/TObjBagWarnWin_8006EF24.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/ui/window/TObjNewFloorWin.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowMenu.h"
#include "pso/ui/window/WindowMenuFactory.h"
#include "pso/ui/frontend/TAdChrSelASlotGC.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby.h"
#include <stdio.h>
#include "pso/ui/window/TWindowSubComCard_80265410.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/window/TWindowCtrlMain_8024CB7C.h"
#include "pso/player/PlayerSlots.h"
extern "C" { extern const char TObjNewFloorWin__class_name_string[16] = "TObjNewFloorWin"; }

struct TObjNewFloorWin_80073DCC { u8 pad[0x1C]; s32 state; void *window; s32 timer24; s32 timer28; };

extern "C" {
saddr get_window_layout_position(s32);

void TShopWindowBase::set_state(s32 v) { state = v; }

void TObjNewFloorWin::run_task() {
    TObjNewFloorWin_80073DCC *self = (TObjNewFloorWin_80073DCC *)this;
    switch (self->state) {
    case 0:
        if (self->window == NULL) {
            if (has_window_task_root() == 0) {
                if (--self->timer24 <= 0) {
                    ((TObject *)self)->queue_destruction();
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
                ((TWindowBase *)self->window)->close();
                self->window = NULL;
            }
            self->state = 2;
        }
        break;
    case 2:
        if (--self->timer28 <= 0) {
            ((TObject *)self)->queue_destruction();
        }
        break;
    }
}

void TObjNewFloorWin::open_window() {
    u8 *arg0 = (u8 *)this;
    s32 pos;
    pos = get_window_layout_position(0x3D);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x4C) < 0) {
        *(u32 *)((s8 *)arg0 + 0x20) = ((u32 (*)(s32, s32, s32)) create_window_menu_default)(pos, 1, *(s32 *)((s8 *)arg0 + 0x4C));
    } else {
        *(uaddr *)((s8 *)arg0 + 0x20) = (uaddr)create_window_menu((saddr)(pos), 1, *(s32 *)((s8 *)arg0 + 0x4C));
    }
    if ((u32) *(u32 *)((s8 *)arg0 + 0x20) != 0U) {
        sprintf((char *)arg0 + 0x2C, "%s %02d", get_message_text(0x67), TObjNewFloorWin__sub_8007410C());
        ((TWindowMenu *)(*(uaddr *)((s8 *)arg0 + 0x20)))->add_text_entry((saddr)(arg0 + 0x2C), 0, 0);
        ((TWindowMenu *)(*(uaddr *)((s8 *)arg0 + 0x20)))->calc_window_size();
        ((TWindowMenu *)(*(uaddr *)((s8 *)arg0 + 0x20)))->set_flag_40();
        fn_800740DC();
        TWindowCtrl::close_active_window();
        TWindowCtrl::ensure_initialized();
    }
}

}

TObjNewFloorWin::~TObjNewFloorWin() {}


extern "C" {
void *__ct__15TObjNewFloorWinFP7TObjectPv(void *arg0, void *arg1, void *arg2);

const char *TObjNewFloorWin__class_name = TObjNewFloorWin__class_name_string;

}
TObjNewFloorWin::TObjNewFloorWin(TObject *object, void *arg2) : TObject(object) {
    this->m_name = TObjNewFloorWin__class_name;
    *(void **)((s8 *)this + 0x4C) = arg2;
    *(u32 *)((s8 *)this + 0x20) = 0;
    *(u32 *)((s8 *)this + 0x24) = 450;
    *(u32 *)((s8 *)this + 0x28) = 150;
    *(u32 *)((s8 *)this + 0x1C) = 0;
}

u8 *TLobby::create_new_floor_windows() {
  uaddr i;
  u8 *temp_r3;
  u8 *temp_r3_2;
  u8 *var_r0;
  u8 *var_r0_2;
  u8 *var_r31;
    saddr arg0 = (saddr)this;
  if (is_split_screen() == 0)
  {
    temp_r3 = (u8 *) TObject::operator new(0x50);
    var_r0 = (u8 *) temp_r3;
    if (var_r0 != 0)
    {
      var_r0 = (u8 *) ((u8 *)__ct__15TObjNewFloorWinFP7TObjectPv((void *)temp_r3, (void *)arg0, (void *)(-1)));
    }
    return var_r0;
  }
  var_r31 = (u8 *) 0;
  i = 0;
  do
  {
    if (get_player_by_client_id(i) != NULL)
    {
      temp_r3_2 = (u8 *) TObject::operator new(0x50);
      var_r0_2 = (u8 *) temp_r3_2;
      if (var_r0_2 != 0)
      {
        var_r31 = ((u8 *)__ct__15TObjNewFloorWinFP7TObjectPv((void *)temp_r3_2, (void *)arg0, (void *)((saddr) i)));
        var_r0_2 = (u8 *) var_r31;
      }
      var_r31 = (u8 *) var_r0_2;
    }
    i += 1;
  }
  while (((s32) i) < 4);
  return var_r31;
}

void fn_800740DC(void) { TWindowCtrl::close_active_window(); }
