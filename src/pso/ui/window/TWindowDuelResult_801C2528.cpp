#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_801C23A8.h"
#include "pso/unk/TUnk_804C3E60.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDuelResult.h"
#include "pso/player/TPlayerBattleCtrl4P_8031012C.h"
#include "pso/ui/window/TWindowDuelResult_801C2528.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TObject.h"

extern "C" {
u8 *__nw__7TObjectFUl(s32);
extern u8 *duel_result_window;
extern s32 tl_00;
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern s32 duel_result_window_dispatch_table[];

void show_duel_result_window(s32 arg0, s32 arg1) {
    u8 *window_duel_result;
    u8 *var_r0;
    if ((void *) duel_result_window != NULL) {
        *(s32 *)((s8 *)duel_result_window + 0x1C) = arg1;
        *(s32 *)((s8 *)duel_result_window + 0x20) = arg0;
        TLobby::set_and_notify(arg0);
        return;
    }
    window_duel_result = (u8 *)(__nw__7TObjectFUl(0x24));
    var_r0 = window_duel_result;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((TWindowDuelResult *)window_duel_result)->init((void *)tl_00, (void *)arg0, (void *)arg1));
    }
    duel_result_window = var_r0;
}

u8 *__dt__13TUnk_804C3E60Fv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = duel_result_window_dispatch_table;
        (*(s32 *)&duel_result_window) = 0;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv((s32) arg0);
        }
    }
    return arg0;
}

void TUnk_804C3E60::run_task() {
    u8 *arg0 = (u8 *)this;
  s32 temp_r0;
  s32 temp_r0_2;
  int new_var;
  temp_r0 = (*((s32 *) (((s8 *) arg0) + 0x1C))) - 1;
  *((s32 *) (((s8 *) arg0) + 0x1C)) = temp_r0;
  if (temp_r0 <= 0)
  {
    TLobby::set_and_notify(0);
    ((TObject *)arg0)->queue_destruction();
    return;
  }
  temp_r0_2 = *((s32 *) (((s8 *) arg0) + 0x1C));
  new_var = 0x20;
  if (temp_r0_2 <= 0xF)
  {
    TLobby::set_and_notify((s32) ((0.06666667f * ((f32) temp_r0_2)) * ((f32) (*((s32 *) (((s8 *) arg0) + new_var))))));
  }
}

}

struct RecoveredGlobal_801C257C_TLobby__data_80511C80 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {
extern RecoveredGlobal_801C257C_TLobby__data_80511C80 TLobby__duel_result_table;
void __ct__7TObjectFP7TObject(void *);

void *TWindowDuelResult::init(void *arg1, void *arg2, void *arg3) {
    __ct__7TObjectFP7TObject(this);
    *(s32 **)((s8 *)this + 0x18) = duel_result_window_dispatch_table;
    *(void * *)&this->_pad1C = arg3;
    *(void **)((s8 *)this + 0x20) = arg2;
    TLobby::set_and_notify((int)arg2);
    return this;
}
typedef char RecoveredGlobal_801C257C_TLobby__data_80511C80_size[sizeof(RecoveredGlobal_801C257C_TLobby__data_80511C80) == 0x20 ? 1 : -1];
s32 *TWindowDuelResult__sub_801C257C(void) {
    if (TRaderMapCore::is_not_split_screen() == 1) {
        return (long *) (get_split_screen_battle_rankings());
    }
    return &TLobby__duel_result_table.value;
}

}
