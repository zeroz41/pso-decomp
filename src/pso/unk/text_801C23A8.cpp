#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_801C23A8.h"
#include "pso/unk/TUnk_804C3E60.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowDuelResult.h"

struct RecoveredGlobal_801C241C_lbl_804C3E60 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
u8 *__nw__7TObjectFUl(s32);
extern u8 *duel_result_window;
extern s32 tl_00;
u8 * __dt__7TObjectFv(void *, s16);
void __dl__7TObjectFPv(s32);
extern RecoveredGlobal_801C241C_lbl_804C3E60 duel_result_window_dispatch_table;

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

typedef char RecoveredGlobal_801C241C_lbl_804C3E60_size[sizeof(RecoveredGlobal_801C241C_lbl_804C3E60) == 0x18 ? 1 : -1];
u8 *__dt__13TUnk_804C3E60Fv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = &duel_result_window_dispatch_table.value;
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
    queue_destruction__7TObjectFv(arg0);
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
