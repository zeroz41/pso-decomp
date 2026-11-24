#include "types.h"
#include "pso/unk/TUnk_804CF9C8.h"
#include "pso/ui/window/TWindowSubStatusDisp_80259DB0.h"
#include "pso/ui/window/TWindowSubStatusDisp_802598E4.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/SoundEffect.h"

extern "C" {
f32 fabs_float(f32, f32);
}

#pragma fp_contract on

void TWindowSubStatusDisp::set_all_values(s32 meseta) {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) meseta;
    *(f32 *)((s8 *)arg0 + 0x24) = (f32) meseta;
    *(s32 *)((s8 *)arg0 + 0x20) = meseta;
    *(f32 *)((s8 *)arg0 + 0x2C) = 0.0f;
}

void TWindowSubStatusDisp::set_animated_target(s32 meseta, f32 farg0) {
    f32 temp_f2;
    f32 var_f31;

    if (*(f32 *)((s8 *)this + 0x28) != (f32) meseta) {
        *(f32 *)((s8 *)this + 0x28) = (f32) meseta;
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

void TUnk_804CF9E0::update() {
    f32 target;
    f32 temp_f30;
    if (this->target != this->current) {
        if (this->flags & 8) {
            play_persistent_sound(0x44E03, this, NULL, 0, 0);
        }
        target = this->target;
        temp_f30 = target - this->current;
        if (((f32 (*)(f32)) fabs_float)(temp_f30) < (fabs_float(this->step, target))) {
            this->current = this->target;
        } else {
            this->current = this->current + this->step;
        }
        this->value = (s32)this->current;
    }
}
#pragma pop

TUnk_804CF9E0::~TUnk_804CF9E0() {}

TUnk_804CF9E0::TUnk_804CF9E0(u8 *rec, s32 m_2) : TUnk_804CF9C8(rec, m_2) {
    this->target = this->value;
    this->current = this->value;
    this->step = 0.0f;
}
