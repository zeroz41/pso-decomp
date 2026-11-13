#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/charcreate/TChCrEffFade.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80293D84.h"

#include "types.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"

extern "C" {

s32 TCameraCtrl__sub_80068EF0();
s32 draw_fade_strip__12TChCrEffFadeFf(void *, f32);

void TChCrEffFade::render() {
    f32 temp_f0;

    TCameraCtrl::restore_full_screen_view();
    switch (mode) {
    case 0:
        draw_fade_strip__12TChCrEffFadeFf(this, alpha);
        break;
    case 1:
        fn_80293E58(this, alpha);
        temp_f0 = alpha;
        draw_fade_strip__12TChCrEffFadeFf(this, temp_f0 * temp_f0);
        break;
    }
    TCameraCtrl__sub_80068EF0();
}


void TChCrEffFade::update_fade() {
    s32 temp_r6;

    temp_r6 = frame;
    if (temp_r6 <= 3) {
        alpha = 1.0f;
        return;
    }
    alpha = (f32) (1.0f - ((temp_r6 - 3) / (f32) (length - 3)));
}

void TChCrEffFade::run_task() {
    s32 temp_r3;

    frame = (s32) (frame + step);
    update_fade();
    temp_r3 = frame;
    if ((temp_r3 <= 0) || (temp_r3 >= (s32) length)) {
        queue_destruction();
    }
}

extern s32 lbl_805D3CC0;
extern s32 tl_fade;

TChCrEffFade::~TChCrEffFade() {}
}
TChCrEffFade::TChCrEffFade(s32 arg1, s32 arg2, s32 arg3) : TObject((TObject *)tl_fade) {
    s32 temp_r0;
    s32 temp_r0_2;
    m_name = (const char *)lbl_805D3CC0;
    step = arg1;
    length = (arg2 + 3);
    temp_r0 = length;
    if (temp_r0 < 4) {
        length = 4;
    } else if (temp_r0 > 0x1C2) {
        length = 0x1C2;
    }
    temp_r0_2 = step;
    if (temp_r0_2 == 1) {
        frame = 0;
    } else if (temp_r0_2 == -1) {
        frame = (s32) length;
    } else {
        step = 1;
        frame = 0;
    }
    this->update_fade();
    mode = arg3;
}
