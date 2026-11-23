#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 TWindowDD__sub_80342B5C(s32);
s32 TWindowDD__sub_803435A0(void *);
s32 TWindowDD__sub_80347C50();
s32 TWindowDD__sub_803482B0(void *);

void TWindowDD::update_dispatch() {
    saddr arg0 = (saddr)this;
    TWindowDD__sub_80347C50();
    if (((TWindowDD *)arg0)->test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        TWindowDD__sub_80342B5C(arg0);
        TWindowDD__sub_803435A0((void *)arg0);
        return;
    }
    if (TWindowDD__sub_803482B0((void *)arg0) != 0) {
        TWindowDD::play_sound();
        TWindowDD::apply_entry_layout((void *)arg0);
    }
}

void TWindowDD::update_layout() {
    this->update_selection_state();
    if (test_input_flag_4() != 0) {
        TWindowDD::play_sound();
        *(s32 *)((s8 *)this + 0xB4) = 0x14;
        this->m_8c = -0x3C;
        TWindowDD__sub_803435A0(this);
        return;
    }
    if (TWindowDD__sub_803482B0(this) != 0) {
        TWindowDD::play_se();
        TWindowDD::apply_entry_layout(this);
    }
}

}
