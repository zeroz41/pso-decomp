#include "types.h"
#include "pso/unk/TWindowLayoutNumber.h"
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
    TWindowLayoutCountingNumber *number = (TWindowLayoutCountingNumber *)this;
    number->target = (f32) meseta;
    number->current = (f32) meseta;
    number->value = meseta;
    number->step = 0.0f;
}

void TWindowSubStatusDisp::set_animated_target(s32 meseta, f32 frames) {
    TWindowLayoutCountingNumber *number = (TWindowLayoutCountingNumber *)this;
    f32 target;
    f32 delta;

    if (number->target != (f32) meseta) {
        number->target = (f32) meseta;
        target = number->target;
        delta = target - number->current;
        delta = delta / frames;
        if (fabs_float(delta, target) < 1.0f) {
            if (delta > 0.0f) {
                delta = 1.0f;
            } else {
                delta = -1.0f;
            }
        }
        number->step = delta;
    }
}

void set_status_entry_target(void *entry, s32 value) {
  TWindowLayoutCountingNumber *number = (TWindowLayoutCountingNumber *)entry;
  f32 target;
  f32 delta;
  if (number->target != ((f32) value))
  {
    number->target = (f32) value;
    target = number->target;
    delta = target - number->current;
    delta *= 0.0211f;
    if (fabs_float(delta, target) < 1.0f)
    {
      if (delta > 0.0f)
      {
        delta = 1.0f;
      }
      else
      {
        delta = -1.0f;
      }
    }
    number->step = delta;
  }
}

#pragma push
#pragma fp_contract on

void TWindowLayoutCountingNumber::update() {
    f32 target;
    f32 distance;
    if (this->target != this->current) {
        if (this->flags & 8) {
            play_persistent_sound(0x44E03, this, NULL, 0, 0);
        }
        target = this->target;
        distance = target - this->current;
        if (((f32 (*)(f32)) fabs_float)(distance) < (fabs_float(this->step, target))) {
            this->current = this->target;
        } else {
            this->current = this->current + this->step;
        }
        this->value = (s32)this->current;
    }
}
#pragma pop

TWindowLayoutCountingNumber::~TWindowLayoutCountingNumber() {}

TWindowLayoutCountingNumber::TWindowLayoutCountingNumber(u8 *rec, s32 m_2) : TWindowLayoutNumber(rec, m_2) {
    this->target = this->value;
    this->current = this->value;
    this->step = 0.0f;
}
