#include "pso/ui/charcreate/TChCrEffFade.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80293D84.h"

#include "types.h"
#include "pso/camera/TCameraCtrl.h"

extern "C" {

s32 TCameraCtrl__sub_80068EF0();
s32 draw_fade_strip__12TChCrEffFadeFf(void *, f32);

void TChCrEffFade::render() {
    f32 temp_f0;

    TCameraCtrl::restore_full_screen_view();
    switch (*(s32 *)((s8 *)this + 0x2C)) {
    case 0:
        draw_fade_strip__12TChCrEffFadeFf(this, *(f32 *)((s8 *)this + 0x28));
        break;
    case 1:
        fn_80293E58(this, *(f32 *)((s8 *)this + 0x28));
        temp_f0 = *(f32 *)((s8 *)this + 0x28);
        draw_fade_strip__12TChCrEffFadeFf(this, temp_f0 * temp_f0);
        break;
    }
    TCameraCtrl__sub_80068EF0();
}


void TChCrEffFade::update_fade() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r6;

    temp_r6 = *(s32 *)((s8 *)arg0 + 0x24);
    if (temp_r6 <= 3) {
        *(f32 *)((s8 *)arg0 + 0x28) = 1.0f;
        return;
    }
    *(f32 *)((s8 *)arg0 + 0x28) = (f32) (1.0f - ((temp_r6 - 3) / (f32) (*(s32 *)((s8 *)arg0 + 0x20) - 3)));
}

void TChCrEffFade::run_task() {
    s32 temp_r3;

    *(s32 *)((s8 *)this + 0x24) = (s32) (*(s32 *)((s8 *)this + 0x24) + *(s32 *)((s8 *)this + 0x1C));
    update_fade();
    temp_r3 = *(s32 *)((s8 *)this + 0x24);
    if ((temp_r3 <= 0) || (temp_r3 >= (s32) *(s32 *)((s8 *)this + 0x20))) {
        queue_destruction__7TObjectFv(this);
    }
}

extern s32 lbl_805D3CC0;
extern s32 tl_fade;

TChCrEffFade::~TChCrEffFade() {}
}
TChCrEffFade::TChCrEffFade(s32 arg1, s32 arg2, s32 arg3) : TObject((TObject *)tl_fade) {
    s32 temp_r0;
    s32 temp_r0_2;
    *(s32 *)((s8 *)this + 0) = (s32) lbl_805D3CC0;
    *(s32 *)((s8 *)this + 0x1C) = arg1;
    *(s32 *)((s8 *)this + 0x20) = (arg2 + 3);
    temp_r0 = *(s32 *)((s8 *)this + 0x20);
    if (temp_r0 < 4) {
        *(s32 *)((s8 *)this + 0x20) = 4;
    } else if (temp_r0 > 0x1C2) {
        *(s32 *)((s8 *)this + 0x20) = 0x1C2;
    }
    temp_r0_2 = *(s32 *)((s8 *)this + 0x1C);
    if (temp_r0_2 == 1) {
        *(s32 *)((s8 *)this + 0x24) = 0;
    } else if (temp_r0_2 == -1) {
        *(s32 *)((s8 *)this + 0x24) = (s32) *(s32 *)((s8 *)this + 0x20);
    } else {
        *(s32 *)((s8 *)this + 0x1C) = 1;
        *(s32 *)((s8 *)this + 0x24) = 0;
    }
    this->update_fade();
    *(s32 *)((s8 *)this + 0x2C) = arg3;
}
