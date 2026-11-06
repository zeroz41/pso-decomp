#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct RecoveredGlobal_8025A0A4_lbl_804CF9E0 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
f32 fabs_float(f32, f32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
}
extern s32 lbl_804CF9E0[];

#pragma fp_contract on

void TWindowSubStatusDisp::set_all_values(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) arg1;
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) arg1;
    *(s32 *)((s8 *)arg0 + 0x20) = arg1;
    *(f32 *)((s8 *)arg0 + 0x2C) = 0.0f;
}

void TWindowSubStatusDisp::set_animated_target(s32 arg1, f32 farg0) {
    f32 temp_f2;
    f32 var_f31;

    if (*(f32 *)((s8 *)this + 0x28) != (f32) arg1) {
        *(f32 *)((s8 *)this + 0x28) = (f32) arg1;
        temp_f2 = *(f32 *)((s8 *)this + 0x28);
        var_f31 = temp_f2 - *(f32 *)((s8 *)this + 0x24);
        var_f31 = var_f31 / farg0;
        if (fabs_float(var_f31, temp_f2) < 1.0f) {
            if (var_f31 > 0.0f) {
                var_f31 = 1.0f;
            } else {
                var_f31 = -1.0f;
            }
        }
        *(f32 *)((s8 *)this + 0x2C) = var_f31;
    }
}

void set_status_entry_target(void *arg0, s32 arg1) {
  f32 temp_f2;
  f32 var_f31;
  if ((*((f32 *) (((s8 *) arg0) + 0x28))) != ((f32) arg1))
  {
    *((f32 *) (((s8 *) arg0) + 0x28)) = (f32) arg1;
    temp_f2 = *((f32 *) (((s8 *) arg0) + 0x28));
    var_f31 = temp_f2 - (*((f32 *) (((s8 *) arg0) + 0x24)));
    var_f31 *= 0.0211f;
    if (fabs_float(var_f31, temp_f2) < 1.0f)
    {
      if (var_f31 > 0.0f)
      {
        var_f31 = 1.0f;
      }
      else
      {
        var_f31 = -1.0f;
      }
    }
    *((f32 *) (((s8 *) arg0) + 0x2C)) = var_f31;
  }
}

#pragma push
#pragma fp_contract on

void TWindowSubStatusDisp::update_pb_counter_approach() {
    f32 temp_f2;
    f32 temp_f30;
    if (*(f32 *)((s8 *)((u8 *)this) + 0x28) != *(f32 *)((s8 *)((u8 *)this) + 0x24)) {
        if (*(u16 *)((s8 *)((u8 *)this) + 0) & 8) {
            play_persistent_sound(0x44E03, (s32)this, 0, 0, 0);
        }
        temp_f2 = *(f32 *)((s8 *)((u8 *)this) + 0x28);
        temp_f30 = temp_f2 - *(f32 *)((s8 *)((u8 *)this) + 0x24);
        if (((f32 (*)(f32)) fabs_float)(temp_f30) < (fabs_float((f32) (*(f32 *)((s8 *)((u8 *)this) + 0x2C)), temp_f2))) {
            *(f32 *)((s8 *)((u8 *)this) + 0x24) = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x28);
        } else {
            *(f32 *)((s8 *)((u8 *)this) + 0x24) = (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x24) + *(f32 *)((s8 *)((u8 *)this) + 0x2C));
        }
        *(s32 *)((s8 *)((u8 *)this) + 0x20) = (s32) *(f32 *)((s8 *)((u8 *)this) + 0x24);
    }
}
#pragma pop

void *TWindowSubStatusDisp__sub_8025A04C(void *window_sub_status_disp, s16 arg1) {
    if (window_sub_status_disp != NULL) {
        *(s32 **)((s8 *)window_sub_status_disp + 4) = lbl_804CF9E0;
        TWindowSubStatusDisp__sub_80259CE4(window_sub_status_disp, (s16)((s16)(0)));
        if (arg1 > 0) {
            ::operator delete(window_sub_status_disp);
        }
    }
    return window_sub_status_disp;
}
typedef char RecoveredGlobal_8025A0A4_lbl_804CF9E0_size[sizeof(RecoveredGlobal_8025A0A4_lbl_804CF9E0) == 0x18 ? 1 : -1];
u8 *TWindowSubStatusDisp::init_layout_entry_scaled(u8 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    TWindowSubStatusDisp__sub_80259D3C(arg0, arg1, arg2);
    *(s32 **)((s8 *)arg0 + 4) = &(*(RecoveredGlobal_8025A0A4_lbl_804CF9E0 *)&lbl_804CF9E0).value;
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) *(s32 *)((s8 *)arg0 + 0x20);
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) *(s32 *)((s8 *)arg0 + 0x20);
    *(f32 *)((s8 *)arg0 + 0x2C) = 0.0f;
    return arg0;
}
