#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp_80144B14.h"
#include "pso/ui/window/TWindowTimer.h"
#include "pso/ui/window/TWindowBase.h"

#pragma readonly_strings on
struct Obj_80287BE8 { u8 pad[0x30]; f32 f30; f32 f34; u8 pad2[8]; f32 f40; f32 f44; };

typedef struct TWindowTimer_80287B60 {
    u8 pad[0x60];
    u32 flags;
} TWindowTimer_80287B60;

typedef struct TimerChild_80287B60 {
    u8 pad[8];
    f32 x;
} TimerChild_80287B60;

struct En_80287AD8 { u8 pad[8]; f32 f8; };

struct Wn_80287AD8 { u8 pad[0x60]; u32 f60; };

extern "C" {
TimerChild_80287B60 *get_array_entry__11TWindowBaseFi(void *, s32);
void init_timer_window_layout_alt(TWindowTimer_80287B60 *self);
void init_timer_window_layout(Wn_80287AD8 *arg0);

#pragma push
#pragma fp_contract on
void init_timer_window_layout(Wn_80287AD8 *arg0) {
    f32 temp_f31;
    En_80287AD8 *e;
    arg0->f60 |= 1;
    temp_f31 = (f32)calc_text_width("000:000");
    e = ((En_80287AD8 *)((TWindowBase *)arg0)->get_array_entry(0));
    e->f8 = 48.0f - 0.5f * temp_f31;
}
#pragma pop

#pragma push
#pragma fp_contract on
void init_timer_window_layout_alt(TWindowTimer_80287B60 *self) {
    f32 width;
    TimerChild_80287B60 *child;
    self->flags &= ~1;
    width = (f32)calc_text_width("0'00\"00");
    child = get_array_entry__11TWindowBaseFi(self, 0);
    child->x = 48.0f - 0.5f * width;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TWindowTimer::ease_window_timer_position() {
    Obj_80287BE8 *o = (Obj_80287BE8 *)this;
    o->f40 += 0.21f * (o->f30 - o->f40);
    o->f44 += 0.21f * (o->f34 - o->f44);
}
#pragma pop

}
