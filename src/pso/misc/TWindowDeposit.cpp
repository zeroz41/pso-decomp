#include "types.h"
#include "pso/misc/TWindowSubStatusDisp_80144B14.h"
#include "pso/misc/TWindowSubStatusDisp_8025A9B4.h"
#include "pso/misc/TWindowSubStatusDisp_80287570.h"
#include "pso/ui/TObjBagWarnWin_8006EF24.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TWindowMainMenu.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowDeposit.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubStatusDisp.h"

struct RecoveredGlobal_8024E548_lbl_804CEB70
{
  s32 value;
  u8 remaining[0x10];
};

struct RecoveredGlobal_8024E548___vt__14TWindowDeposit
{
  s32 value;
  u8 remaining[0x18];
};

extern "C" {
s32 draw_visible_window_entries(void *, void *, int);
s32 construct_base__9TWindowDDFPUcsPUc(void *, void *, void *, int);
s32 get_window_layout_position(int);
extern RecoveredGlobal_8024E548_lbl_804CEB70 window_deposit_layout;
extern s32 __vt__14TWindowDeposit[];
extern s32 TWindowDeposit__name;
extern const f32 lbl_805DCC60;
extern const f32 lbl_805DCC64;
extern const f32 lbl_805DCC68;
extern const f32 lbl_805DCC6C;
extern const f32 lbl_805DCC70;
s32 draw_window_tab(s32, s32, s32, f32);
void __dl__7TObjectFPv(void *);
int initialize_subwindow__9TWindowDDFv(void*);

void TWindowDeposit::render_status(s32 arg1) {
    draw_window_tab(arg1, arg1 + 0x10, 3, this->m_60);
}

void render__14TWindowDepositFv(s32 arg0) {
    s32 ctx;
    ctx = ((TWindowBase *)arg0)->setup_window_draw_context(arg0 + 0x64);
    ((TWindowDeposit *)arg0)->render_status(ctx);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)ctx);
}

void TWindowDeposit::run_task() { initialize_subwindow__9TWindowDDFv(this); update_window_entry_list((char*)this + 0x24); }

void *__dt__14TWindowDepositFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TWindowDeposit;
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
typedef struct RecoveredGlobal_8024E548___vt__14TWindowDeposit RecoveredGlobal_8024E548___vt__14TWindowDeposit;
typedef struct RecoveredGlobal_8024E548_lbl_804CEB70 RecoveredGlobal_8024E548_lbl_804CEB70;
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
u8 *TWindowDeposit__ct(u8 *arg0, s32 arg1) {
  u8 *temp_r30;
  u32 spC;
  s32 sp8;
  f32 temp_f31;
  s32 str;
  u32 temp_r3_2;
  u8 *temp_r31;
  construct_base__9TWindowDDFPUcsPUc((void *) arg0, &window_deposit_layout.value, (void *) arg1, (int) get_window_layout_position(0x29));
  *((s32 **) (((s8 *) arg0) + (((((0x18 & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu))) = &(*(RecoveredGlobal_8024E548___vt__14TWindowDeposit *)&__vt__14TWindowDeposit).value;
  *((s32 *) (((s8 *) arg0) + 0)) = (s32) TWindowDeposit__name;
  str = TQuestVmDownLoadServer__sub_8006EF6C(2);
  temp_r3_2 = calc_text_width((char *)str);
  spC = temp_r3_2;
  sp8 = 0x43300000;
  temp_f31 = (f32) temp_r3_2;
  ((TWindowDeposit *)arg0)->m_60 = TWindowSubStatusDisp__sub_802877A4(lbl_805DCC60 + (lbl_805DCC64 + temp_f31));
  temp_r30 = (u8 *) ((u8 *)((TWindowBase *)arg0)->get_array_entry(0));
  temp_r31 = (u8 *) ((u8 *)((TWindowBase *)arg0)->get_array_entry(1));
  set_text_entry_string(temp_r30, str, 0);
  *((f32 *) (((s8 *) temp_r31) + 8)) = (f32) (lbl_805DCC60 + (lbl_805DCC64 + (lbl_805DCC68 + temp_f31)));
  ((TWindowDeposit *)arg0)->m_38 = TWindowSubStatusDisp::get_base_y(((TWindowDeposit *)arg0)->m_60);
  ((TWindowBase *)arg0)->save_position();
  if (TCameraCtrl::get_camera_id() > 2)
  {
    *((f32 *) (((s8 *) arg0) + 0x64)) = (f32) lbl_805DCC6C;
    *((f32 *) (((s8 *) arg0) + 0x68)) = (f32) lbl_805DCC6C;
  }
  else
  {
    *((f32 *) (((s8 *) arg0) + 0x64)) = (f32) lbl_805DCC70;
    *((f32 *) (((s8 *) arg0) + 0x68)) = (f32) lbl_805DCC70;
  }
  return arg0;
}

}
