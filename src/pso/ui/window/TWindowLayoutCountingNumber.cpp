#include "pso/object/base/TObjCharaHelpers.h"
#include "types.h"
#include "pso/unk/TWindowLayoutNumber.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/system/memory.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/system/SoundEffect.h"


#pragma fp_contract on

void TWindowLayoutCountingNumber::set_all_values(s32 value) {
    this->target = (f32) value;
    this->current = (f32) value;
    this->value = value;
    this->step = 0.0f;
}

void TWindowLayoutCountingNumber::set_animated_target(s32 value, f32 frames) {
    f32 target;
    f32 delta;

    if (this->target != (f32) value) {
        this->target = (f32) value;
        target = this->target;
        delta = target - this->current;
        delta = delta / frames;
        if (fabs_float(delta) < 1.0f) {
            if (delta > 0.0f) {
                delta = 1.0f;
            } else {
                delta = -1.0f;
            }
        }
        this->step = delta;
    }
}

void TWindowLayoutCountingNumber::set_status_entry_target(s32 value) {
  f32 target;
  f32 delta;
  if (this->target != ((f32) value))
  {
    this->target = (f32) value;
    target = this->target;
    delta = target - this->current;
    delta *= 0.0211f;
    if (fabs_float(delta) < 1.0f)
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
    this->step = delta;
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
        if (fabs_float(distance) < fabs_float(this->step)) {
            this->current = this->target;
        } else {
            this->current = this->current + this->step;
        }
        this->value = (s32)this->current;
    }
}
#pragma pop

TWindowLayoutCountingNumber::~TWindowLayoutCountingNumber() {}

TWindowLayoutCountingNumber::TWindowLayoutCountingNumber(ValueLayoutRecord *rec, s32 client) : TWindowLayoutNumber(rec, client) {
    this->target = this->value;
    this->current = this->value;
    this->step = 0.0f;
}
