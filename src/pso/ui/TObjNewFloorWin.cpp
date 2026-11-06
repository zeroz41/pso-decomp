#include "pso/ui/TObjNewFloorWin.h"
#include "pso/misc/TLobby.h"

TObjNewFloorWin::~TObjNewFloorWin() {}

#include "types.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/ui/TAdChrSelASlotGC.h"

extern "C" {
s32 is_split_screen(void);
void *__ct__15TObjNewFloorWinFP7TObjectPv(void *arg0, void *arg1, void *arg2);
s32 get_player_by_client_id(u32);
u8 *__nw__7TObjectFUl(s32);

extern void *TObjNewFloorWin__class_name;

}
TObjNewFloorWin::TObjNewFloorWin(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = TObjNewFloorWin__class_name;
    *(void **)((s8 *)this + 0x4C) = arg2;
    *(u32 *)((s8 *)this + 0x20) = 0;
    *(u32 *)((s8 *)this + 0x24) = 450;
    *(u32 *)((s8 *)this + 0x28) = 150;
    *(u32 *)((s8 *)this + 0x1C) = 0;
}

u8 *TLobby::create_new_floor_windows() {
  u32 var_r30;
  u8 *temp_r3;
  u8 *temp_r3_2;
  u8 *var_r0;
  u8 *var_r0_2;
  u8 *var_r31;
    s32 arg0 = (s32)this;
  if (is_split_screen() == 0)
  {
    temp_r3 = (u8 *) __nw__7TObjectFUl(0x50);
    var_r0 = (u8 *) temp_r3;
    if (var_r0 != 0)
    {
      var_r0 = (u8 *) ((u8 *)__ct__15TObjNewFloorWinFP7TObjectPv((void *)temp_r3, (void *)arg0, (void *)(-1)));
    }
    return var_r0;
  }
  var_r31 = (u8 *) 0;
  var_r30 = 0;
  do
  {
    if (get_player_by_client_id(var_r30) != 0U)
    {
      temp_r3_2 = (u8 *) __nw__7TObjectFUl(0x50);
      var_r0_2 = (u8 *) temp_r3_2;
      if (var_r0_2 != 0)
      {
        var_r31 = ((u8 *)__ct__15TObjNewFloorWinFP7TObjectPv((void *)temp_r3_2, (void *)arg0, (void *)((s32) var_r30)));
        var_r0_2 = (u8 *) var_r31;
      }
      var_r31 = (u8 *) var_r0_2;
    }
    var_r30 += 1;
  }
  while (((s32) var_r30) < 4);
  return var_r31;
}

void fn_800740DC(void) { TWindowCtrl::close_active_window(); }
